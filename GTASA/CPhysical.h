#ifndef __CPHYSICAL
#define __CPHYSICAL

#define FUNC_GetMoveSpeed                       0x404460
#define FUNC_GetTurnSpeed                       0x470030
#define FUNC_ProcessCollision                   0x54DFB0
#define FUNC_AttachEntityToEntity               0x54D570
#define FUNC_DetatchEntityFromEntity            0x5442F0

class CPhysicalVTBL : public CEntityVTBL
{
public:
	DWORD		ProcessEntityCollision;
};

class CPhysical : public CEntity				// begin +0x44 (244 bytes total?)
{
public:
    CVector m_vVelocity;						// 0x44
    CVector m_vAngularVelocity;					// 0x50
    CVector m_vAcceleration;					// 0x5C
    CVector m_vAngularAcceleration;				// 0x68
    CVector m_vForce;							// 0x74
    CVector m_vTorque;							// 0x80
	float fMass;								// 0x8C
    float fTurnMass;							// 0x90
    float m_fVelocityFrequency;					// 0x94
    float m_fAirResistance;						// 0x98
    float m_fElasticity;						// 0x9C
    float m_fBuoyancyConstant;					// 0xA0

    CVector vecCenterOfMass;					// 0xA4
    DWORD dwUnk1;								// 0xB0
    DWORD *unkCPtrNodeDoubleLink;				// 0xB4
    BYTE byUnk: 8;								// 0xB8
    BYTE byCollisionRecords: 8;					// 0xB9
    BYTE byUnk2: 8;								// 0xBA (Baracus)
    BYTE byUnk3: 8;								// 0xBB

    float pad4[6];								// 0xBC

    float fDistanceTravelled;					// 0xD4
    float fDamageImpulseMagnitude;				// 0xD8
    CEntity *damageEntity;						// 0xDC
    BYTE pad2[28];								// 0xE0
    CEntity *pAttachedEntity;					// 0xFC
    CVector m_vAttachedPosition;				// 0x100
    CVector m_vAttachedRotation;				// 0x10C
    BYTE pad3[20];								// 0x118
    float fLighting;							// 0x12C col lighting? CPhysical::GetLightingFromCol
    float fLighting_2;							// 0x130 added to col lighting in CPhysical::GetTotalLighting
    BYTE pad3a[4];								// 0x134
};

#endif