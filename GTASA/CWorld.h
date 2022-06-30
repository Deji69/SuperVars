#ifndef __CWORLD
#define __CWORLD

#define FUNC_Add                                            0x563220
#define FUNC_Remove                                         0x563280
#define FUNC_ProcessLineOfSight                             0x56BA00
#define FUNC_FindGroundZFor3DCoord                          0x5696C0
#define FUNC_FindGroundZForCoord                            0x569660
#define FUNC_CTimer_Stop                                    0x561AA0
#define FUNC_CTimer_Update                                  0x561B10
#define FUNC_CRenderer_RequestObjectsInDirection            0x555CB0
#define FUNC_CStreaming_LoadScene                           0x40EB70
#define FUNC_IsLineOfSightClear                             0x56A490
#define FUNC_HasCollisionBeenLoaded                         0x410CE0
#define FUNC_RemoveBuildingsNotInArea                       0x4094B0
#define FUNC_RemoveReferencesToDeletedObject                0x565510

#define FUNC_CColLine_Constructor                           0x40EF50
#define FUNC_CColSphere_Set                                 0x40FD10

#define VAR_IgnoredEntity                                   0xB7CD68
#define VAR_currArea                                        0xB72914
#define ARRAY_StreamSectors                                 0xB7D0B8
#define NUM_StreamSectorRows                                120
#define NUM_StreamSectorCols                                120
#define ARRAY_StreamRepeatSectors                           0xB992B8
#define NUM_StreamRepeatSectorRows                          16
#define NUM_StreamRepeatSectorCols                          16
#define VAR_fJetpackMaxHeight                               0x8703D8
#define VAR_fAircraftMaxHeight                              0x8594DC

struct SLineOfSightFlags
{
    SLineOfSightFlags ( void )
        : bCheckBuildings ( true )
        , bCheckVehicles ( true )
        , bCheckPeds ( true )
        , bCheckObjects ( true )
        , bCheckDummies ( true )
        , bSeeThroughStuff ( false )
        , bIgnoreSomeObjectsForCamera ( false )
        , bShootThroughStuff ( false )
    {}
    bool bCheckBuildings;
    bool bCheckVehicles;
    bool bCheckPeds;
    bool bCheckObjects;
    bool bCheckDummies;
    bool bSeeThroughStuff;
    bool bIgnoreSomeObjectsForCamera;
    bool bShootThroughStuff;            // not used for IsLineOfSightClear
};

struct SLineOfSightBuildingResult
{
    SLineOfSightBuildingResult ( void )
        : bValid ( false )
    {}
    bool bValid;
    WORD usModelID;
    CVector vecPosition;
    CVector vecRotation;
};


class CWorld
{
public:
	static void			Add(CEntity *entity);
	static void			Remove(CEntity *entity);
    static float		FindGroundZForPosition(float fX,float fY,float fZ);
};

#endif