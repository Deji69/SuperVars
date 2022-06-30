#include "StdInc.h"

CExternalScripts	*	CTheScripts::externalScripts;
int					*	CTheScripts::commandParams,
					*	CTheScripts::missionLocals;
char				*	CTheScripts::scmBlock;

CTheScripts::CTheScripts()
{
	externalScripts		= VAR_ExternalScripts;
	commandParams		= VAR_CommandParameters;
	missionLocals		= VAR_MissionLocals;
	scmBlock			= VAR_ScmBlock;
}

void CRunningScript::CollectParameters(WORD numParams)
{
	char bDataType;
	int *pParams;
	
	pParams = GetCommandParamPointer();

	if(numParams)
	{
		for(short i = numParams; i; i--)
		{
			bDataType = ReadDataType();

			if(bDataType - 1 <= DATA_TYPE_GARRAY)
			{
				switch(bDataType)
				{
					case DATA_TYPE_DWORD:
					case DATA_TYPE_FLOAT:
						*pParams = ReadDataInt();
						break;
					case DATA_TYPE_GVAR:
						*pParams = ReadDataGlobalIntVal();
						break;
					case DATA_TYPE_LVAR:
						*pParams = ReadDataLocalIntVal();
						break;
					case DATA_TYPE_BYTE:
						*pParams = ReadDataByte();
						break;
					case DATA_TYPE_WORD:
						*pParams = ReadDataWord();
						break;
					case DATA_TYPE_GARRAY:
						*pParams = ReadDataGlobalArrayIntVal();
						break;
					case DATA_TYPE_LARRAY:
						*pParams = ReadDataLocalArrayIntVal();
						break;
				}
			}

			++pParams;
		}
	}
}

char * CRunningScript::GetStringParam(char *pOut, DWORD dwSize)
{
	DWORD dwFunc = FUNC_GetStringParam;
	DWORD dwThis = (DWORD)this;
	_asm
	{
		push dwSize
		push pOut
		mov ecx, dwThis
		call dwFunc
	}
}

void CRunningScript::SetNumberParams(WORD numParams)
{
	DWORD dwFunc = FUNC_SetNumberParams;
	DWORD dwThis = (DWORD)this;
	_asm
	{
		mov ecx, dwThis
		push numParams
		call dwFunc
	}
}

void CRunningScript::SetConditionResult(BYTE result)
{
	BYTE scrResult;
	BYTE bOp;
	if(this->NotFlag) scrResult = result == 0;
	else scrResult = result;
	WORD op = this->LogicalOp;
	if(!op) this->bCondResult = scrResult;
	else
	{
		if(op >= 1 && op <= 8)
		{
			this->bCondResult &= scrResult;
			bOp = op == 1;
		}
		else if(op >= 0x15 && op <= 0x1C)
		{
			this->bCondResult |= scrResult;
			bOp = op == 21;
		}
		if(bOp) this->LogicalOp = 0;
		else this->LogicalOp = op - 1;
	}
}