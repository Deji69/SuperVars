#ifndef __CAUTOMOBILE
#define __CAUTOMOBILE

#include "CDamageManager.h"
#include "CDoor.h"
#include "CVehicle.h"

#define CAutomobile_VTBL							0x871120
#define FUNC_CAutomobile_BurstTyre                  0x6A32B0
#define FUNC_CAutomobile_BreakTowLink               0x6A4400
#define FUNC_CAutomobile_BlowUpCar                  0x6B3780
#define FUNC_CAutomobile_BlowUpCarsInPath           0x6AF110
#define FUNC_CAutomobile_CloseAllDoors              0x6A4520
#define FUNC_CAutomobile_CloseBoot                  0x6AFA20
#define FUNC_CAutomobile_FindWheelWidth             0x6A6090
#define FUNC_CAutomobile_Fix                        0x6A3440
#define FUNC_CAutomobile_FixDoor                    0x6A35A0
#define FUNC_CAutomobile_FixPanel                   0x6A3670
#define FUNC_CAutomobile_GetAllWheelsOffGround      0x6A2F70
#define FUNC_CAutomobile_GetCarPitch                0x6A6050
#define FUNC_CAutomobile_GetCarRoll                 0x6A6010
#define FUNC_CAutomobile_GetComponentWorldPosition  0x6A2210
#define FUNC_CAutomobile_GetHeightAboveRoad         0x6A62B0
#define FUNC_CAutomobile_GetNumContactWheels        0x6A62A0
#define FUNC_CAutomobile_GetRearHeightAboveRoad     0x6A0610
#define FUNC_CAutomobile_IsComponentPresent         0x6A2250
#define FUNC_CAutomobile_IsDoorClosed               0x6A2310
#define FUNC_CAutomobile_IsDoorFullyOpen            0x6A22D0
#define FUNC_CAutomobile_IsDoorMissing              0x6A2330
#define FUNC_CAutomobile_IsDoorReady                0x6A2290
#define FUNC_CAutomobile_IsInAir                    0x6A6140
#define FUNC_CAutomobile_IsOpenTopCar               0x6A2350
#define FUNC_CAutomobile_PlaceOnRoadProperly        0x6AF420
#define FUNC_CAutomobile_PlayCarHorn                0x6A3770
#define FUNC_CAutomobile_PopBoot                    0x6AF910
#define FUNC_CAutomobile_PopBootUsingPhysics        0x6A44D0
#define FUNC_CAutomobile_PopDoor                    0x6ADEF0
#define FUNC_CAutomobile_PopPanel                   0x6ADF80
#define FUNC_CAutomobile_ProcessCombine				0x6A9680
#define FUNC_CAutomobile_ResetSuspension            0x6A2AE0
#define FUNC_CAutomobile_SetRandomDamage            0x6A2530
#define FUNC_CAutomobile_SetTaxiLight               0x6A3740
#define FUNC_CAutomobile_SetTotalDamage             0x6A27F0
#define FUNC_CAutomobile_SpawnFlyingComponent       0x6A8580

#if SA_VER & GAMEVER_STEAM
	#define CAutomobile_VTBL							0x8C0484
#endif

#define MAX_PASSENGER_COUNT     8
#define MAX_DOORS               6

// this is collision data (confirmed)
class CAutomobileSAUnknownInterface // sizeof: 0x28
{
    FLOAT       detachablesPosX;    // 996
    FLOAT       detachablesPosY;    // 1000
    FLOAT       detachablesPosZ;    // 1004
    FLOAT       Unknown187; // 1008
    FLOAT       Unknown188; // 1012
    FLOAT       Unknown189; // 1016
    FLOAT       Unknown190; // 1020
    FLOAT       Unknown191; // 1024
    DWORD       Unknown192; // 1028
    FLOAT       Unknown193; // 1032
};

class CAutomobile : public CVehicle
{
public:
    CDamageManager	damage;							// 0x5A0 :)
    DWORD       dwPadding;							// 0x5B8
    CDoor		doors[MAX_DOORS];					// 0x5BC
    DWORD       Unknown184a;						// 0x64C
    DWORD       Frontrightwheelmodel;				// 0x650
    DWORD       Middlerightdummywheelmodel; 		// 0x654
    DWORD       Backrightwheelmodel;				// 0x658
    DWORD       Frontleftwheelmodel;				// 0x65C
    DWORD       Middleleftdummywheelmodel;			// 0x660
    DWORD       Backleftwheelmodel;					// 0x664
    DWORD       Frontbumpermodel;					// 0x668
    DWORD       Rearbumpermodel;					// 0x66C
    DWORD       Frontrightwingmodel;				// 0x670
    DWORD       Unknown185;							// 0x674
    DWORD       Frontrightdoormodel;				// 0x678
    DWORD       Rearrightdoormodel;					// 0x67C
    DWORD       Frontleftwingmodel;					// 0x680
    DWORD       Unknown186;							// 0x684
    DWORD       Frontleftdoormodel;					// 0x688
    DWORD       Rearleftdoormodel;					// 0x68C
    DWORD       BonnetModel;						// 0x690
    DWORD       Bootmodel;							// 0x694
    DWORD       WindscreenModel;					// 0x698
	DWORD		Unknown69C;							// 0x69C
	DWORD		Unknown6A0;							// 0x6A0
	DWORD		Unknown6A4;							// 0x6A4
	DWORD		Unknown6A8;							// 0x6A8
	DWORD		Unknown6AC;							// 0x6AC
	DWORD		Unknown6B0;							// 0x6B0
	DWORD		Unknown6B4;							// 0x6B4
	DWORD		Unknown6B8;							// 0x6B8
	DWORD		Unknown6BC;							// 0x6BC
	DWORD		Unknown6C0;							// 0x6C0
	DWORD		Unknown6C4;							// 0x6C4
	DWORD		Unknown6C8;							// 0x6C8
	DWORD		Unknown6CC;							// 0x6CC
	DWORD		Unknown6D0;							// 0x6D0
	DWORD		Unknown6D4;							// 0x6D4
	DWORD		Unknown6D8;							// 0x6D8
	DWORD		Unknown6DC;							// 0x6DC
	DWORD		Unknown6E0;							// 0x6E0
	DWORD		Unknown6E4;							// 0x6E4
	DWORD		Unknown6E8;							// 0x6E8
	DWORD		Unknown6EC;							// 0x6EC
	DWORD		Unknown6F0;							// 0x6F0
	DWORD		Unknown6F4;							// 0x6F4
	DWORD		Unknown6F8;							// 0x6F8
	DWORD		Unknown6FC;							// 0x6FC
	DWORD		Unknown700;							// 0x700
	DWORD		Unknown704;							// 0x704
	DWORD		Unknown708;							// 0x708
	DWORD		Unknown70C;							// 0x70C
	DWORD		Unknown710;							// 0x710
	DWORD		Unknown714;							// 0x714
	DWORD		Unknown718;							// 0x718
	DWORD		Unknown71C;							// 0x71C
	DWORD		Unknown720;							// 0x720
	CWheelData	LeftFrontWheelData;					// 0x724
	CWheelData	LeftRearWheelData;					// 0x750
	CWheelData	RightFrontWheelData;				// 0x77C
	CWheelData	RightRearWheelData;					// 0x7A8
	FLOAT		unkCarTilt;							// 0x7D4
    FLOAT       WheelSuspensionStrength[4]; 		// 0x7D8
    FLOAT       Unknown227;							// 0x7E8
    FLOAT       Unknown228;							// 0x7EC
    FLOAT       Unknown229;							// 0x7F0
    FLOAT       Unknown230;							// 0x7F4
    FLOAT       Unknown231;							// 0x7F8
    FLOAT       AutomobileSpeed;					// 0x7FC
    FLOAT       Unknown232;							// 0x800
    FLOAT       Unknown233;							// 0x804
    FLOAT       Unknown234;							// 0x808
    FLOAT       Unknown235;							// 0x80C
    FLOAT       Unknown236;							// 0x810
    FLOAT       Unknown237;							// 0x814
    FLOAT       Unknown237a;						// 0x818
    FLOAT       UnknownWheelRelated[4];				// 0x81C
    FLOAT       Unknown241;							// 0x82C
    FLOAT       Unknown242;							// 0x830
    FLOAT       Unknown243;							// 0x834
    FLOAT       Unknown244;							// 0x838
    FLOAT       Unknown245;							// 0x83C
    FLOAT       Unknown246;							// 0x840
    FLOAT       Unknown247;							// 0x844
    FLOAT       Unknown248;							// 0x848
    FLOAT       Unknown249;							// 0x84C
    FLOAT       Unknown250;							// 0x850
    FLOAT       Unknown251;							// 0x854
    FLOAT       Unknown252;							// 0x858
    FLOAT       Unknown253;							// 0x85C
    FLOAT       Unknown254;							// 0x860
    FLOAT       Unknown255;							// 0x864
    FLOAT       WeaponHorizontalRotation;   		// 0x868
    FLOAT       WeaponVerticalRotation;				// 0x86C
    FLOAT       Unknown255a;						// 0x870
    FLOAT       Unknown255b;						// 0x874
    FLOAT       Unknown256;							// 0x878
    BYTE        Unknown256a;						// 0x87C
    BYTE        Unknown257;							// 0x87D
    BYTE        Unknown258;							// 0x87E
    BYTE        DriveWheelsOnGroundLastFrame;		// 0x87F
    FLOAT       GasPedalAudioRevs;  				// 0x880
    DWORD       m_aWheelState[4];   				// 0x884
	DWORD		Unknown259[20];						// 0x894
	DWORD		Unknown260[20];						// 0x8E4
	DWORD		Unknown261[19];						// 0x934
	BYTE		bCombineChewValue;					// 0x980	< this is correct ^ is not

	void		ProcessCombine();
};

#endif