#include "StdAfx.h"
#include "SuperVars.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	if(reason==DLL_PROCESS_ATTACH)
	{
		//ClearJumpTable
		ADDR_JT = read_jmp(0x469F9E);
		patch(0x469F9D, 0xE9, 1);
		jmpTo(0x469F9D, &HOOK_ClearJT);

		//CollectParameters
		patch(0x4640B9, &SV_CollectParamsTable, 4);
		patch(0x4640AF, sizeof(SV_CollectParamsTable) / 4 - 1, 1);

		//CollectParametersWithoutIncreasingPC
		patch(0x464273, &SV_CollectNoIncTable, 4);
		patch(0x464266, sizeof(SV_CollectNoIncTable) / 4 - 1, 1);

		//CollectParametersForScript
		patch(0x464530, &SV_CollectParamsForScriptTable, 4);
		patch(0x464526, sizeof(SV_CollectParamsForScriptTable) / 4 - 1, 1);

		//StoreParameters
		patch(0x4643AB, &SV_StoreParamsTable, 4);
		patch(0x4643A1, sizeof(SV_StoreParamsTable) / 4 - 1, 1);

		//GetPointerToScriptVariable
		patch(0x4647B7, &SV_GetScriptVarPtrTable, 4);
		patch(0x4648CF, sizeof(SV_GetScriptVarPtrTable) / 4 - 1, 1);

		//GetStringPointer
		patch(0x464064, &HOOK_CollectString, 4);
		
		//Ninject(0x46419C, &HOOK_CollectParams);
	}
	return TRUE;
}

DWORD * GetSuperVarPointerV2(CRunningScript *pScript, BYTE *pSize)
{
	BYTE type;
	WORD flags;
	int offset;
	type = pScript->ReadDataByte();
	flags = pScript->ReadDataWord();

	switch(type)
	{
	case SV_TYPE_INT_PTR:
	case SV_TYPE_FLOAT_PTR:
		offset = pScript->ReadDataInt();
	}
}

DWORD * GetSuperVarPointer(CRunningScript *pScript, BYTE *pSize)
{
	int index, offset, indexVar;
	WORD offsetVar;
	DWORD base, *ptr;

	BYTE size, flags;

	offsetVar	= pScript->ReadDataArrayOffset();
	indexVar	= pScript->ReadDataArrayIndex();
	size		= pScript->ReadDataArraySize();
	flags		= pScript->ReadDataArrayFlags();

	*pSize = size;

	// >=0@: read var for offset -- <0@: use var offset
	if(offsetVar >= 0) offset = pScript->GetLocalVarVal(offsetVar);
	else offset = (DWORD)pScript->GetLocalVarPtr(-(offsetVar));

	// Use default behaviour for global var indexes.
	if(flags >> 4 == 0)
	{
		// 20@(20@,4s): SUPERVAR[0]
		if(indexVar == offsetVar) index = 0;
		else
		{
			// 0@(1@,4s): SUPERVAR[1@] -- 0@(-3@,4s): SUPERVAR[3]
			if(indexVar >= 0) index = pScript->GetLocalVarVal(indexVar);
			else index = -(indexVar);
		}
	}
	else index = pScript->GetGlobalVarVal(indexVar);

	switch(flags & 0xF)
	{
	default:
		// Failsafe?
		ptr = (DWORD*)pScript->GetLocalVarPtr(index);
		break;

	case ARRAYFLAG_SuperVar:
		// A base address can't be negative, use as label offset
		if(offset <= 0) base = (DWORD)pScript->GetLabelPointer(offset);
		else base = offset;

		ptr = (DWORD*)(base + index * size);
		break;
	}

	return ptr;
}

void __declspec(naked) HOOK_ClearJT()
{
	_asm
	{
		or [esi+0xD5], 2
		call ADDR_JT
		mov eax, 0x469FA2
		jmp eax
	}
}

DWORD __declspec(naked) SV_GetArrayPtr()
{
	CRunningScript *pScript;
	DWORD *result;
	BYTE size;

	_asm
	{
		push ebp
		mov ebp, esp
		sub esp, __LOCAL_SIZE
		push ebx
		push ecx
		mov pScript, ecx
	}

	result = GetSuperVarPointer(pScript, &size);
	
	_asm
	{
		mov eax, result
		pop ecx
		pop ebx
		mov esp, ebp
		pop ebp
		ret
	}
}

DWORD __declspec(naked) SV_GetArrayVal()
{
	CRunningScript *pScript;
	DWORD result, *ptr;
	BYTE size;

	_asm
	{
		push ebp
		mov ebp, esp
		sub esp, __LOCAL_SIZE
		push ebx
		push ecx
		mov pScript, ecx
	}

	ptr = GetSuperVarPointer(pScript, &size);
	
	switch(size)
	{
	case 1:
		result = *(BYTE*)ptr;
		break;
	case 2:
		result = *(WORD*)ptr;
		break;
	default:
		result = *(DWORD*)ptr;
		break;
	}

	_asm
	{
		mov eax, result
		pop ecx
		pop ebx
		mov esp, ebp
		pop ebp
		ret
	}
}

void __declspec(naked) SV_SetArrayVal()
{
	CRunningScript *pScript;
	DWORD *val, *ptr;
	BYTE size;

	_asm
	{
		push ebp
		mov ebp, esp
		sub esp, __LOCAL_SIZE
		push ebx
		push ecx
		mov pScript, ecx
		mov val, ebx
	}

	ptr = GetSuperVarPointer(pScript, &size);
	
	switch(size)
	{
	case 1:
		*(BYTE*)ptr = *(BYTE*)val;
		break;
	case 2:
		*(WORD*)ptr = *(WORD*)val;
		break;
	default:
		*(DWORD*)ptr = *(DWORD*)val;
		break;
	}

	_asm
	{
		pop ecx
		pop ebx
		mov esp, ebp
		pop ebp
		ret
	}
}

void __declspec(naked) HOOK_CollectParams()
{
	_asm
	{
		mov al, byte ptr [ecx+0xD5]
		test al, 1
		mov eax, [ecx+0x14]
		jz END
		call SV_GetArrayVal
		mov [ebx], eax
END:
		mov eax, 0x464210
		jmp eax
	}
}

void __declspec(naked) HOOK_CollectParamsNoInc()
{
	_asm
	{
		mov al, byte ptr [ecx+0xD5]
		test al, 1
		mov eax, [ecx+0x14]
		jz END
		push edi
		call SV_GetArrayVal
		pop edi
END:
		mov esi, 0x464345
		jmp esi
	}
}

void __declspec(naked) HOOK_CollectParamsForScript()
{
	_asm
	{
		// ebx == dest script storage
		mov al, byte ptr [ecx+0xD5]
		test al, 1
		mov eax, [ecx+0x14]
		jz END
		push ebx
		call SV_GetArrayVal
		pop ebx
		mov [ebx], eax
END:
		mov eax, 0x464687
		jmp eax
	}
}

void __declspec(naked) HOOK_StoreParams()
{
	_asm
	{
		mov al, byte ptr [ecx+0xD5]
		test al, 1
		mov eax, [ecx+0x14]
		jz END
		call SV_SetArrayVal
END:
		mov eax, 0x4644C9
		jmp eax
	}
}

void __declspec(naked) HOOK_GetScriptVarPtr()
{
	_asm
	{
		mov al, byte ptr [ecx+0xD5]
		test al, 1
		jnz END
		mov eax, 0x46486B
		jmp eax
END:
		call SV_GetArrayPtr
		pop ebx
		add esp, 8
		retn 4
	}
}

void __declspec(naked) HOOK_CollectString()
{
	_asm
	{
		mov al, byte ptr [ecx+0xD5]
		test al, 1
		jnz END
		mov eax, 0x463E71
		jmp eax
END:
		call SV_GetArrayPtr
		mov ecx, [esp+0x14+0x4]
		mov edx, [esp+0x14+0x8]
		push edx
		push eax
		push ecx
		mov eax, 0x821F40
		call eax
		add esp, 0xC
		pop edi
		pop esi
		pop ebx
		add esp, 0x8
		retn 8
	}
}

void _Ninject(DWORD pAddress, DWORD pDest)
{
	#ifndef GLOBAL_UNPROTECT
		DWORD dwProtect[2];
		VirtualProtect((void*)pAddress, 5, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
	#endif
	*(BYTE*)pAddress = 0xE9;
	*(DWORD*)(pAddress + 1) = pDest - (pAddress+5);
	*(BYTE*)(pAddress + 5) = 0x61;
	#ifndef GLOBAL_UNPROTECT
		VirtualProtect((void*)pAddress, 5, dwProtect[0], &dwProtect[1]);
	#endif
}
void _patch(void *pAddress, DWORD data, DWORD iSize)
{
	#ifndef GLOBAL_UNPROTECT
		unsigned long dwProtect[2];
		VirtualProtect(pAddress, iSize, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
	#endif
	switch(iSize)
	{
		case 1: *(BYTE*)pAddress = (BYTE)data; break;
		case 2: *(WORD*)pAddress = (WORD)data; break;
		case 4: *(DWORD*)pAddress = (DWORD)data; break;
		default: memset(pAddress, data, iSize); break;
	}
	#ifndef GLOBAL_UNPROTECT
		VirtualProtect(pAddress, iSize, dwProtect[0], &dwProtect[1]);
	#endif
}
int _read(void *pAddress, DWORD iSize)
{
	#ifndef GLOBAL_UNPROTECT
		unsigned long dwProtect[2];
		VirtualProtect(pAddress, iSize, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
	#endif
	int nResult;
	switch(iSize)
	{
		case 1:
			nResult = *(BYTE*)pAddress;
			break;
		case 2: 
			nResult = *(WORD*)pAddress;
			break;
		default:
			nResult = *(DWORD*)pAddress;
	}
	#ifndef GLOBAL_UNPROTECT
		VirtualProtect(pAddress, iSize, dwProtect[0], &dwProtect[1]);
	#endif
	return nResult;
}
void _jmpTo(BYTE *pAddress, DWORD data)
{
	#ifndef GLOBAL_UNPROTECT
	unsigned long dwProtect[2];
	VirtualProtect(pAddress, 5, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
	#endif
	*pAddress = 0xE9;
	pAddress++;
	*(DWORD*)(pAddress) = data - ((DWORD)pAddress + 4);
	#ifndef GLOBAL_UNPROTECT
	VirtualProtect(pAddress, 5, dwProtect[0], &dwProtect[1]);
	#endif
}