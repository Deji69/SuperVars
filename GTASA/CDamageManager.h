#ifndef __CDAMAGEMANAGER
#define __CDAMAGEMANAGER

#define FUNC_GetEngineStatus        0x6C22C0
#define FUNC_SetEngineStatus        0x6C22A0
#define FUNC_GetDoorStatus          0x6C2230
#define FUNC_SetDoorStatus          0x6C21C0
#define FUNC_GetTireStatus          0x6C21B0
#define FUNC_SetTireStatus          0x6C21A0
#define FUNC_GetPanelStatus         0x6C2180
#define FUNC_SetPanelStatus         0x6C2150
#define FUNC_SetLightStatus         0x6C2100
#define FUNC_GetLightStatus         0x6C2130
#define FUNC_SetAeroplaneCompStatus 0x6C22D0
#define FUNC_GetAeroplaneCompStatus 0x6C2300

//006c25d0      public: void __thiscall CDamageManager::FuckCarCompletely(bool)
#define FUNC_FuckCarCompletely      0x6C25D0

#define DT_ENGINE_OK                    (0)
#define DT_ENGINE_RADIATOR_BURST        (100)
#define DT_ENGINE_ENGINE_OVERHEAT       (150)
#define DT_ENGINE_ENGINE_PIPES_BURST    (200)
#define DT_ENGINE_ON_FIRE               (225)
#define DT_ENGINE_FUCKED                (250)

/*
const unsigned char DT_ENG_INOPERABLE = 0x01;
const unsigned char DT_ENG_EXHAUST_SMOKE = 0x02;
const unsigned char DT_ENG_RADIATOR_STEAM = 0x04;
const unsigned char DT_ENG_ON_FIRE = 0x08;
*/

enum eWheelStatus {
    DT_WHEEL_INTACT=0,
//  DT_WHEEL_CAP_MISSING,
//  DT_WHEEL_WARPED,
    DT_WHEEL_BURST,
    DT_WHEEL_MISSING,
};

enum eDoorStatus {
    DT_DOOR_INTACT=0,
    DT_DOOR_SWINGING_FREE,
    DT_DOOR_BASHED,
    DT_DOOR_BASHED_AND_SWINGING_FREE,
    DT_DOOR_MISSING
};

enum ePlaneComponentStatus 
{
    DT_PLANE_INTACT=0,
    DT_PLANE_BASHED,
//  DT_PLANE_BASHED2,
    DT_PLANE_MISSING
};

enum eComponentStatus 
{
    DT_PANEL_INTACT=0,
//  DT_PANEL_SHIFTED,
    DT_PANEL_BASHED,
    DT_PANEL_BASHED2,
    DT_PANEL_MISSING
};

enum eLightStatus 
{
    DT_LIGHT_OK=0,
    DT_LIGHT_SMASHED
};

enum eDoors
{
    BONNET = 0,
    BOOT,
    FRONT_LEFT_DOOR,
    FRONT_RIGHT_DOOR,
    REAR_LEFT_DOOR,
    REAR_RIGHT_DOOR,
    MAX_DOORS
};

enum eWheels
{
    FRONT_LEFT_WHEEL = 0,
    REAR_LEFT_WHEEL,
    FRONT_RIGHT_WHEEL,
    REAR_RIGHT_WHEEL,

    MAX_WHEELS

};

enum ePanels
{
    FRONT_LEFT_PANEL = 0,
    FRONT_RIGHT_PANEL,
    REAR_LEFT_PANEL,
    REAR_RIGHT_PANEL,
    WINDSCREEN_PANEL,   // needs to be in same order as in component.h
    FRONT_BUMPER,
    REAR_BUMPER,
    MAX_PANELS      // MUST BE 8 OR LESS
};

enum eLights
{
    // these have to correspond to their respective panels
    LEFT_HEADLIGHT = 0,
    RIGHT_HEADLIGHT,
    LEFT_TAIL_LIGHT,
    RIGHT_TAIL_LIGHT,
/*  LEFT_BRAKE_LIGHT,
    RIGHT_BRAKE_LIGHT,
    FRONT_LEFT_INDICATOR,
    FRONT_RIGHT_INDICATOR,
    REAR_LEFT_INDICATOR,
    REAR_RIGHT_INDICATOR,*/
    MAX_LIGHTS          // MUST BE 16 OR LESS
};

#define MAX_DOORS                   6   // also in CAutomobile
#define MAX_WHEELS                  4

class CDamageManager // sizeof: 0x18
{
public:
    FLOAT           fWheelDamageEffect;
    BYTE            bEngineStatus;			// old - wont be used
    BYTE            WheelStatus[MAX_WHEELS];
    BYTE            Door[MAX_DOORS];
    DWORD           Lights;					// 2 bits per light
    DWORD           Panels;					// 4 bits per panel

	void			SetLightStatus(BYTE bLight, BYTE bLightStatus);
	int				GetWheelStatus(char wheel)							{return WheelStatus[wheel];};
};

#endif