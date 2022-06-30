#ifndef __CWEAPON
#define __CWEAPON

#define FUNC_GetWeaponInfo								0x743C60

class CWeapon	// sizeof=0x1C
{
public:
	int type;
	int state;
	int ammoInClip;
	int ammoRemaining;
	DWORD reloadFinishTime;
	int unk;
	DWORD pParticle;
};

class CWeaponInfo
{
public:
	int weaponType;					// 0x0
	int targetRange;				// 0x4
	int weaponRange;				// 0x8
	int dwModelId;					// 0xC
	int dwModelId2;					// 0x10
	int nSlot;						// 0x14
	int hexFlags;					// 0x18
	int animStyle;					// 0x1C
	WORD ammoClip;					// 0x20
	RwV3D fireOffset;				// 0x24
	int skillLevel;
	int reqStatLevel;
	int accuracy;
	int moveSpeed;
	float animLoopStart;
	float animLoopEnd;
	float animLoopFire;
	float animLoop2Start;
	float animLoop2End;
	float animLoop2Fire;
	int breakoutTime;
	int speed;
	int radius;
	int lifespan;
	int spread;
	int animStyle2;

	static	CWeaponInfo		*	GetWeaponInfo(int iType, char skillLevel);
};

#endif