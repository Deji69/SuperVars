#ifndef __CVEHICLE
#define __CVEHICLE

#include "CEntity.h"
#include "CPed.h"
#include "CPhysical.h"

#define NUM_RAILTRACKS 4
#define MAX_PASSENGERS 8
#define MAX_UPGRADES_ATTACHED 15

typedef struct
{
    short sX;               // x coordinate times 8
    short sY;               // y coordinate times 8
    short sZ;               // z coordinate times 8
    WORD  sRailDistance;    // on-rail distance times 3
    WORD  padding;
} SRailNodeSA;

struct CVehicleFlags
{
	//0x428
    unsigned char bIsLawEnforcer: 1; // Is this guy chasing the player at the moment
    unsigned char bIsAmbulanceOnDuty: 1; // Ambulance trying to get to an accident
    unsigned char bIsFireTruckOnDuty: 1; // Firetruck trying to get to a fire
    unsigned char bIsLocked: 1; // Is this guy locked by the script (cannot be removed)
    unsigned char bEngineOn: 1; // For sound purposes. Parked cars have their engines switched off (so do destroyed cars)
    unsigned char bIsHandbrakeOn: 1; // How's the handbrake doing ?
    unsigned char bLightsOn: 1; // Are the lights switched on ?
    unsigned char bFreebies: 1; // Any freebies left in this vehicle ?

	//0x429
    unsigned char bIsVan: 1; // Is this vehicle a van (doors at back of vehicle)
    unsigned char bIsBus: 1; // Is this vehicle a bus
    unsigned char bIsBig: 1; // Is this vehicle big
    unsigned char bLowVehicle: 1; // Need this for sporty type cars to use low getting-in/out anims
    unsigned char bComedyControls: 1; // Will make the car hard to control (hopefully in a funny way)
    unsigned char bWarnedPeds: 1; // Has scan and warn peds of danger been processed?
    unsigned char bCraneMessageDone: 1; // A crane message has been printed for this car allready
    // unsigned char bExtendedRange: 1; // This vehicle needs to be a bit further away to get deleted
    unsigned char bTakeLessDamage: 1; // This vehicle is stronger (takes about 1/4 of damage)

    //0x42A
    unsigned char bIsDamaged: 1; // This vehicle has been damaged and is displaying all its components
    unsigned char bHasBeenOwnedByPlayer : 1;// To work out whether stealing it is a crime
    unsigned char bFadeOut: 1; // Fade vehicle out
    unsigned char bIsBeingCarJacked: 1;
    unsigned char bCreateRoadBlockPeds : 1;// If this vehicle gets close enough we will create peds (coppers or gang members) round it
    unsigned char bCanBeDamaged: 1; // Set to FALSE during cut scenes to avoid explosions
    // unsigned char bUsingSpecialColModel : 1;
    // Is player vehicle using special collision model, stored in player strucure
    unsigned char bOccupantsHaveBeenGenerated : 1; // Is true if the occupants have already been generated. (Shouldn't happen again)
    unsigned char bGunSwitchedOff: 1; // Level designers can use this to switch off guns on boats
    
	//0x42B
    unsigned char bVehicleColProcessed : 1;// Has ProcessEntityCollision been processed for this car?
    unsigned char bIsCarParkVehicle: 1; // Car has been created using the special CAR_PARK script command
    unsigned char bHasAlreadyBeenRecorded : 1; // Used for replays
    unsigned char bPartOfConvoy: 1;
    unsigned char bHeliMinimumTilt: 1; // This heli should have almost no tilt really
    unsigned char bAudioChangingGear: 1; // sounds like vehicle is changing gear
    unsigned char bIsDrowning: 1; // is vehicle occupants taking damage in water (i.e. vehicle is dead in water)
    unsigned char bTyresDontBurst: 1; // If this is set the tyres are invincible

    //0x42C
    unsigned char bCreatedAsPoliceVehicle : 1;// True if this guy was created as a police vehicle (enforcer, policecar, miamivice car etc)
    unsigned char bRestingOnPhysical: 1; // Dont go static cause car is sitting on a physical object that might get removed
        unsigned char      bParking                    : 1;
        unsigned char      bCanPark                    : 1;
    unsigned char bFireGun: 1; // Does the ai of this vehicle want to fire it's gun?
    unsigned char bDriverLastFrame: 1; // Was there a driver present last frame ?
    unsigned char bNeverUseSmallerRemovalRange: 1;// Some vehicles (like planes) we don't want to remove just behind the camera.
    unsigned char bIsRCVehicle: 1; // Is this a remote controlled (small) vehicle. True whether the player or AI controls it.

    //0x42D
    unsigned char bAlwaysSkidMarks: 1; // This vehicle leaves skidmarks regardless of the wheels' states.
    unsigned char bEngineBroken: 1; // Engine doesn't work. Player can get in but the vehicle won't drive
    unsigned char bVehicleCanBeTargetted : 1;// The ped driving this vehicle can be targetted, (for Torenos plane mission)
    unsigned char bPartOfAttackWave: 1; // This car is used in an attack during a gang war
    unsigned char bWinchCanPickMeUp: 1; // This car cannot be picked up by any ropes.
    unsigned char bImpounded: 1; // Has this vehicle been in a police impounding garage
    unsigned char bVehicleCanBeTargettedByHS  : 1;// Heat seeking missiles will not target this vehicle.
    unsigned char bSirenOrAlarm: 1; // Set to TRUE if siren or alarm active, else FALSE

    //0x42E
    unsigned char bHasGangLeaningOn: 1;
    unsigned char bGangMembersForRoadBlock : 1;// Will generate gang members if NumPedsForRoadBlock > 0
    unsigned char bDoesProvideCover: 1; // If this is false this particular vehicle can not be used to take cover behind.
    unsigned char bMadDriver: 1; // This vehicle is driving like a lunatic
    unsigned char bUpgradedStereo: 1; // This vehicle has an upgraded stereo
    unsigned char bConsideredByPlayer: 1; // This vehicle is considered by the player to enter
    unsigned char bPetrolTankIsWeakPoint : 1;// If false shootong the petrol tank will NOT Blow up the car
    unsigned char bDisableParticles: 1; // Disable particles from this car. Used in garage.

    //0x42F
    unsigned char bHasBeenResprayed: 1; // Has been resprayed in a respray garage. Reset after it has been checked.
    unsigned char bUseCarCheats: 1; // If this is true will set the car cheat stuff up in ProcessControl()
    unsigned char bDontSetColourWhenRemapping : 1;// If the texture gets remapped we don't want to change the colour with it.
    unsigned char bUsedForReplay: 1; // This car is controlled by replay and should be removed when replay is done.
};

struct CTrainFlags
{
    unsigned char unknown1 : 3;
    unsigned char bIsTheChainEngine : 1; // Only the first created train on the chain gets this set to true, others get it set to false.
    unsigned char unknown2 : 1; // This is always set to true in mission trains construction.
    unsigned char bIsAtNode : 1;
    unsigned char bDirection : 1;
    
	unsigned char unknown3 : 1; // If the mission train was placed at the node, this is set to false in construction.
    unsigned char bIsDerailed : 1;
    unsigned char unknown4 : 1 ;
    unsigned char bIsDrivenByBrownSteak : 1;

    unsigned char unknown5 : 5;
    unsigned char unknown6 : 8;
    unsigned char unknown7 : 8;
};

class CAEVehicleAudioEntity // sizeof: 0x9C
{
    BYTE pad1[154];
public:
    BYTE bCurrentRadioStation;
private:
    BYTE pad2;
};

class CAutoPilot // sizeof: 0x38
{
    BYTE pad[56];
};

class CWheelData	// sizeof: 0x2C
{
public:
	RwV3D		LastGroundPosition;
	DWORD		_f0c;					// 0xC
	DWORD		_f10;					// 0x10
	DWORD		_f14;					// 0x14
	DWORD		_f18;					// 0x18
	DWORD		_f1C;					// 0x1C
	DWORD		_f20;					// 0x20
	DWORD		_f24;					// 0x24
	DWORD		_f28;					// 0x28
};

class CVehicleVTBL : CPhysicalVTBL
{   
public:
	DWORD unk1;
	DWORD ProcessControlInput;
	DWORD GetComponentWorldPosition;
	DWORD IsComponentPresent;
	DWORD unk2;
	DWORD unk3;
	DWORD unk4;
	DWORD unk5;
	DWORD unk6;
	DWORD unk7;
	DWORD unk8;
	DWORD unk9;
	DWORD unk10;
	DWORD unk11;
	DWORD unk12;
	DWORD unk13;
	DWORD unk14;
	DWORD unk15;
	DWORD BlowUp;
	DWORD unk16;
	DWORD unk17;
	void(__thiscall *DeflateTyre)(CVehicle *, BYTE bTyre, char bFlag);
};

class CVehicle : public CPhysical // sizeof: 0x5A0
{
public:
    CAEVehicleAudioEntity m_VehicleAudioEntity;					// 0x138

    int padaudio[108];

    void* pVehicleHandling;										// 0x384
    DWORD pPlaneHandling;										// 0x388
    DWORD dwHandlingFlags;										// 0x38C
    char pad52321 [28];											// 0x390
	DWORD n_mDriveTaskStartTime;								// 0x3AC
	char pad53589 [9];											// 0x3B0
	BYTE trafficBehaviour;										// 0x3B9
	BYTE driverBehaviour;										// 0x3BA
	BYTE action;												// 0x3BB
	DWORD actionEndTime;										// 0x3BC
	char pad58022[36];											// 0x3C0
    DWORD dwUnknown1201;                                        // 0x3E4
    DWORD dwUnknown1202;                                        // 0x3E8
    unsigned int hFlagsLocal;									// 0x3EC

    CAutoPilot AutoPilot;										// 0x3F0
    CVehicleFlags m_nVehicleFlags;								// 0x428
    unsigned int m_TimeOfCreation;					// GetTimeInMilliseconds when this vehicle was created.

    unsigned char m_colour1, m_colour2, m_colour3, m_colour4;
    char m_comp1, m_comp2;
    short m_upgrades[MAX_UPGRADES_ATTACHED];					// 0x43A
    float m_wheelScale;											// 0x458

    unsigned short CarAlarmState;								// 0x45C
    unsigned short ForcedRandomSeed;				// if this is non-zero the random wander gets deterministic
    
    CPed *pDriver;
    CPed *pPassengers[MAX_PASSENGERS];
    unsigned char m_nNumPassengers;
    unsigned char m_nNumGettingIn;
    unsigned char m_nGettingInFlags;
    unsigned char m_nGettingOutFlags;
    unsigned char m_nMaxPassengers;
    unsigned char m_windowsOpenFlags;
    char m_nNitroBoosts;

    unsigned char m_nSpecialColModel;
    CEntity *pEntityWeAreOnForVisibilityCheck;
    void *m_pFire;

    float m_fSteerAngle;										// 0x494
    float m_f2ndSteerAngle;					// used for steering 2nd set of wheels or elevators etc.. // 0x498
    float m_fGasPedal;						// 0...1  // 0x49C
    float m_fBrakePedal;					// 0...1  // 0x4A0

    unsigned char VehicleCreatedBy; // Contains information on whether this vehicle can be deleted 
                            // or not. Probably only need this or IsLocked.
    short ExtendedRemovalRange;

    unsigned char BombOnBoard : 3; // 0 = None. 1 = Timed. 2 = On ignition, 3 = remotely set ? 4 = Timed Bomb has been activated. 5 = On ignition has been activated.
    unsigned char OverrideLights  : 2; // uses enum NO_CAR_LIGHT_OVERRIDE, FORCE_CAR_LIGHTS_OFF, FORCE_CAR_LIGHTS_ON
    unsigned char WinchType: 2; // Does this vehicle use a winch?
    unsigned char m_GunsCycleIndex : 2;// Cycle through alternate gun hardpoints on planes/helis
    unsigned char m_OrdnanceCycleIndex : 2; // Cycle through alternate ordnance hardpoints on planes/helis

    unsigned char nUsedForCover;// Has n number of cops hiding/attempting to hid behind it
    unsigned char AmmoInClip;// Used to make the guns on boat do a reload.
    unsigned char PacMansCollected;
    unsigned char PedsPositionForRoadBlock;
    unsigned char NumPedsForRoadBlock;

    //1200
    float nBodyDirtLevel; // Dirt level of vehicle body texture: 0.0f=fully clean, 15.0f=maximum dirt visible, it may be altered at any time while vehicle's cycle of lige

    // values used by transmission
    unsigned char m_nCurrentGear;
    BYTE bla[3];
    float m_fGearChangeCount;

    float m_fWheelSpinForAudio;

    float m_nHealth;					// 1000.0f = full health. 0 -> explode	// 0x4C0

	DWORD Padding4C4;															// 0x4C4
	CVehicle* m_pTrailer;														// 0x4C8
	DWORD Padding4CC[11];														// 0x4CC

    unsigned long ul_doorstate;													// 0x4F8

    DWORD Padding4FC[3];														// 0x4FC

	BYTE m_bDamageType;															// 0x508

	CEntity *m_pDamagingEntity;													// 0x50C

	DWORD Padding510;															// 0x510

    unsigned int m_isUsingHornOrSecondarySiren;									// 0x514

	DWORD Padding211[27];														// 0x518

	BYTE headAndTailLightFlags;													// 0x584

	DWORD Padding212;															// 0x588

	float fRightLeftSteeringThing;												// 0x58C
	int m_iVehicleType;															// 0x590
	
	DWORD Padding213[3];														// 0x594

    //0x5A0
    /*unsigned char m_ucTrackNodeID;  // Current node on train tracks
    BYTE Padding230[3];

    //1444
    float m_fTrainSpeed;           // Speed along rails
    //1448
    float m_fTrainRailDistance;    // Distance along rail starting from first rail node (determines train position when on rails)
    
    //1452
    float m_fDistanceToNextCarriage;
    DWORD padding240[2];

    //1464
    CTrainFlags trainFlags;

    //1468
    DWORD padding250[1];

    //
    BYTE m_ucRailTrackID;

    //1473
    BYTE padding260[15];

    //1488
    CVehicle* m_prevCarriage;
    CVehicle* m_nextCarriage;

    //1496
    BYTE padding270[116];

    // 1612
    void* pChassis;
    void* pWheelFrontRight;
    BYTE padding271[4];
    void* pWheelRearRight;
    void* pWheelFrontLeft;
    BYTE padding272[4];
    void* pWheelRearLeft;
    void* pDoors [ 4 ];
    void* pBumpers [ 2 ];
    BYTE padding273[8];
    void* pBonet;
    void* pBoot;
    void* pWindscreen;
    void* pExhaust;

    BYTE padding280[576];
    // 2276
    float m_fBurningTime;*/

public:
	void			Process();
	bool			IsPoliceVehicle();
	bool			IsEmergencyVehicle();
	bool			IsCarWashVehicle();
};

#endif