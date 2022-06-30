#ifndef __COBJECT
#define __COBJECT

#include "StdInc.h"
#include "CPools.h"

#define COBJECT_SIZE	0x19C

#define FUNC_GetObjectByIndex								0x404870
#define FUNC_GetObjectHandle								0x465070
#define FUNC_CObject_Operator_New							0x5A1C20
#define FUNC_CObject_Constructor							0x5A1D10
#define FUNC_CObject_Constructor2							0x5A1D70
#define FUNC_Object_DuplicateConstructor					0x5A1DF0
#define FUNC_CreateObject									0x5A1F60
#define FUNC_CObject_ScalarDestuctor						0x5A2BD0
#define FUNC_CPhysical_Remove								0x5424C0
#define FUNC_CPhysical_Add									0x544A30
#define FUNC_LockDoorObject									0x59F5C0

#define VAR_NumObjectsToDelete					*(int*)		0xBB4A70

class CObject : public CPhysical		// TODO: Finish and make constructor independant.
{
public:
	DWORD unk1;
	BYTE ownerType;						// 2 == SCRIPT, 6 == EXTERNAL SCRIPT
	BYTE pickupMonetaryValue;

	DWORD bUnkFlag1						: 1;
	DWORD bHasBeenPhotographed			: 1;
	DWORD bIsTargetable					: 1;
	DWORD bUnkIsBroken					: 1;
	DWORD bIsStealable					: 1;
	DWORD bAttractedToMagnet			: 1;
	DWORD bIsColliding					: 1;
	DWORD bWaitingForScriptBrainToLoad	: 1;
	DWORD bHasScriptBrain				: 1;
	DWORD bFadeOut						: 1;

	BYTE bColDamageEffect;

	DWORD unk2;
	DWORD unk3;
	DWORD timeToRemove;

	float fHealth;
	
	float unk4;

	float fScale;
	DWORD pObjectInfo;
	
public:
	CObject::CObject();
	CObject::CObject(WORD model, char bCreate);
	CObject::CObject(CObject *pObject);

	void * operator new( size_t num_bytes )
    {
		return CPools::GetObjectPool()->Allocate();
    }

	static	CObject			*	Create(WORD model);

	inline	void				SetScale(float fVal)		{fScale = fVal;};

	BYTE						GetOwner()					{return ownerType;};

	void						LockDoorObject();
};

#endif