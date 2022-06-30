#ifndef __CPOOL
#define __CPOOL

#include "StdInc.h"

#define FUNC_CPool_Allocate						0x5A1C20
#define FUNC_ObjectPool_Allocate				0x5A1EE0
#define FUNC_GetVehicleHandle					0x424160
#define FUNC_GetVehicleByIndex					0x41CC10

#define VAR_PedPool					((CPool**)	0xB74490)
#define VAR_VehiclePool				((CPool**)	0xB74494)
#define VAR_BuildingPool			((CPool**)	0xB74498)
#define VAR_ObjectPool				((CPool**)	0xB7449C)
#define VAR_DummyPool				((CPool**)	0xB744A0)

class CPool;
class CPed;
class CVehicle;
class CObject;

class CPools
{
private:
	static CPool			**	m_pPedPool;
	static CPool			**	m_pVehiclePool;
	static CPool			**	m_pObjectPool;
	static CPool			**	m_pDummyPool;
	static CPool			**	m_pBuildingPool;
	static CPool			**	m_pTreadablePool;
	static CPool			**	m_pEntryInfoNodePool;

public:
	CPools();

	static inline CPool		*	GetPedPool()		{return *m_pPedPool;};
	static inline CPool		*	GetVehiclePool()	{return *m_pVehiclePool;};
	static inline CPool		*	GetBuildingPool()	{return *m_pBuildingPool;};
	static inline CPool		*	GetObjectPool()		{return *m_pObjectPool;};
	static inline CPool		*	GetDummyPool()		{return *m_pDummyPool;};
};

class CPool
{
private:
	DWORD objects;
	BYTE *flags;
	DWORD size;
	DWORD top;
	BYTE initialized;
	BYTE unkPoolLock;
	BYTE _pad;

public:
	void			*	Allocate();

	bool				IsVehiclePointerValid(CVehicle *pVehicle);
	CVehicle		*	GetVehicleByIndex(int index);
	CObject			*	GetObjectByIndex(int index);
	CObject			*	GetObjectAtHandle(DWORD hObject);
	CVehicle		*	GetVehicleAtHandle(DWORD hVehicle);
	DWORD				GetVehicleHandle(CVehicle *pVehicle);
	DWORD				GetObjectHandle(CObject *pObject);
	DWORD				GetPedHandle(CPed *pPed);
	DWORD				GetVehicleIndex(CVehicle *pVehicle);

	inline	DWORD		GetObjects()			{return objects;};
	inline	DWORD		GetSize()				{return size;};
	inline	void		SetPoolLock(char bLock)	{unkPoolLock = bLock;};
};

#endif