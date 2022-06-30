#ifndef __CGAME_PLAYERINFO
#define __CGAME_PLAYERINFO

#include "CWanted.h"

#define FUNC_SetMaxWantedLevel					0x561E70
#define FUNC_FindPlayerCenterOfWorld			0x56E250
#define FUNC_CalcPlayerStat						0x559AF0
#define FUNC_GivePlayerHealth					0x56EAB0

#define VAR_MaxWantedLevel			*(int*)		0x8CDEE4
#define VAR_MaxWantedChaos			*(int*)		0x8CDEE8

class CPlayerCrosshair
{
public:
    BYTE bActivated;
    float TargetX, TargetY;   // -1 ... 1 on screen
};

class CPlayerData
{
private:
    CWanted* m_Wanted;											// 0x0
    void* m_pClothes;											// 0x4
    CPed* m_ArrestingOfficer;									// 0x8
    RwV2D m_vecFightMovement;									// 0xC
    float m_moveBlendRatio;										// 0x14
    float m_fSprintEnergy;										// 0x18
    float m_fSprintControlCounter;								// 0x1C
    BYTE m_nChosenWeapon;										// 0x20
    BYTE m_nCarDangerCounter;									// 0x21
    DWORD m_nStandStillTimer;									// 0x24
    DWORD m_nHitAnimDelayTimer;									// 0x28
    float m_fAttackButtonCounter;								// 0x2C
    void *m_pDangerCar;											// 0x30

    DWORD m_bStoppedMoving : 1;									// 0x34
    DWORD m_bAdrenaline : 1;
    DWORD m_bHaveTargetSelected : 1;
    DWORD m_bFreeAiming : 1;
    DWORD bCanBeDamaged : 1;
    DWORD bAllMeleeAttackPtsBlocked : 1;
    DWORD m_JustBeenSnacking : 1;
    DWORD m_bRequireHandleBreath : 1;
    
    DWORD m_GroupStuffDisabled : 1;								// 0x35
    DWORD m_GroupAlwaysFollow : 1;
    DWORD m_GroupNeverFollow : 1;
    DWORD m_bInVehicleDontAllowWeaponChange : 1;
    DWORD m_bRenderWeapon : 1;
	DWORD m_bUnused1 : 1;
	DWORD m_bUnused2 : 1;
	DWORD m_bUnused3 : 1;

	DWORD m_bUnk : 1;											// 0x36 //DWORD m_bCopMode : 1;

    DWORD m_PlayerGroup;										// 0x38

    DWORD m_AdrenalineEndTime;									// 0x3C
    BYTE m_nDrunkenness;										// 0x40
    BYTE m_bFadeDrunkenness;									// 0x41
    BYTE m_nDrugLevel;											// 0x42
    BYTE m_nScriptLimitToGangSize;								// 0x43
    float m_fBreath;											// 0x44
    DWORD m_MeleeWeaponAnimReferenced;							// 0x48
    DWORD m_MeleeWeaponAnimReferencedExtra;						// 0x4C
    float m_fFPSMoveHeading;									// 0x50
    float m_fLookPitch;											// 0x54
    float m_fSkateBoardSpeed;									// 0x58
    float m_fSkateBoardLean;									// 0x5C

    void *m_pSpecialAtomic;										// 0x60
    float m_fGunSpinSpeed;										// 0x64
    float m_fGunSpinAngle;										// 0x68

    DWORD m_LastTimeFiring;										// 0x6C
    DWORD m_nTargetBone;										// 0x70
    RwV3D m_vecTargetBoneOffset;								// 0x74
    DWORD m_busFaresCollected;									// 0x80
    BYTE m_bPlayerSprintDisabled;								// 0x84
    BYTE m_bDontAllowWeaponChange;								// 0x85
    BYTE m_bForceInteriorLighting;								// 0x86
    WORD m_DPadDownPressedInMilliseconds;						// 0x88
    WORD m_DPadUpPressedInMilliseconds;							// 0x8A
    BYTE m_wetness;												// 0x8C
    BYTE m_playersGangActive;									// 0x8D
    BYTE m_waterCoverPerc;										// 0x8E
    FLOAT m_waterHeight;										// 0x90
    DWORD m_FireHSMissilePressedTime;							// 0x94
    void* m_LastHSMissileTarget;
    DWORD m_nModelIndexOfLastBuildingShot;
    DWORD m_LastHSMissileLOSTime  :31;
    DWORD m_bLastHSMissileLOS     :1;
    void* m_pCurrentProstitutePed;
    void* m_pLastProstituteShagged;

public:
	CWanted				*	GetWanted()						{return m_Wanted;};
	float					GetBreath()						{return m_fBreath;};
	void					SetChosenWeapon(int weapon)		{m_nChosenWeapon = weapon;};
};

class CPlayerInfo
{
private:
	CPed *pPed;											// 0x0
	CPlayerData data;									// 0x4
	CVehicle *pVehicle;									// 0xB0
	CVehicle *pSpecCar;									// 0xB4
	DWORD Score;										// 0xB8
	DWORD DisplayedScore;								// 0xBC
	DWORD CollectablesPickedUp;							// 0xC0
	DWORD TotalNumCollectables;							// 0xC4
	DWORD nLastBumpedTimer;								// 0xC8
	DWORD TimeHasHadPassengerInTaxi;					// 0xCC
	DWORD VehicleTimeCounter;							// 0xD0
	BYTE bKeepTaxiTimerScore;							// 0xD4
	BYTE PlayerTryingToExitCar;							// 0xD5
	void *pLastTargetVehicle;							// 0xD8
	BYTE isWastedBusted;								// 0xDC
	BYTE bAfterRemoteVehicleExplosion;					// 0xDD
	BYTE bCreateRemoteVehicleExplosion;					// 0xDE
	BYTE bFadeAfterRemoteVehicleExplosion;				// 0xDF
	DWORD TimeOfRemoteVehicleExplosion;					// 0xE0
	DWORD LastTimeEnergyLost;							// 0xE4
	DWORD LastTimeArmourLost;							// 0xE8
	DWORD LastTimeBigGunFired;							// 0xEC
	DWORD TimesUpsideDownInARow;						// 0xF0
	DWORD TimesStuckInARow;								// 0xF4
	DWORD nCarTwoWheelCounter;							// 0xF8
	float fCarTwoWheelDist;								// 0xFC
	DWORD nCarLess3WheelCounter;						// 0x100
	DWORD nBikeRearWheelCounter;						// 0x104
	float fBikeRearWheelDist;							// 0x108
	DWORD nBikeFrontWheelCounter;						// 0x10C
	float fBikeFrontWheelDist;							// 0x110
	DWORD nTempBufferCounter;							// 0x114
	DWORD nBestCarTwoWheelsTimeMs;						// 0x118
	float fBestCarTwoWheelsDistM;						// 0x11C
	DWORD nBestBikeWheelieTimeMs;						// 0x120
	float fBestBikeWheelieDistM;						// 0x124
	DWORD nBestBikeStoppieTimeMs;						// 0x128
	float fBestBikeStoppieDistM;						// 0x12C
	WORD CarDensityForCurrentZone;						// 0x130
	float RoadDensityAroundPlayer;						// 0x134
	DWORD TimeOfLastCarExplosionCaused;					// 0x138
	DWORD ExplosionMultiplier;							// 0x13C
	DWORD HavocCaused;									// 0x140
	WORD TimeLastEaten;									// 0x144
	float fCurrentChaseRating;							// 0x148
	BYTE InfiniteSprint;								// 0x14C
	BYTE FastReload;									// 0x14D
	BYTE FireProof;										// 0x14E
	BYTE MaxHealth;										// 0x14F
	BYTE MaxArmour;										// 0x150
	BYTE GetOutOfJailFree;								// 0x151
	BYTE FreeHealthCare;								// 0x152
	BYTE CanDoDriveBy;									// 0x153
	BYTE BustedAudioStatus;								// 0x154
	BYTE LastBustMessageNumber;							// 0x155
	CPlayerCrosshair Crosshair;							// 0x156
	char m_skinName[32];								// 0x164
	char *m_pSkinTexture;								// 0x184
	BYTE m_bParachuteReferenced;						// 0x188
	DWORD m_nRequireParachuteTimer;						// 0x18C

public:
	inline CPed				*	GetPed()							{return pPed;};
	inline CPlayerData		*	GetData()							{return &data;};
	
	inline float				GetMaxHealth()						{return MaxHealth;};

	static	float			CalcPlayerStat(int statID);
	static	CVector		*	FindPlayerCenterOfWorld(int playerID);
	void					SetMaxWantedLevel(int level);
	void					GiveHealth(int hp);
	
	bool					IsWastedBusted()					{return isWastedBusted != 0;};
};

#endif