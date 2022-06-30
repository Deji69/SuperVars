#ifndef __CENTITY
#define __CENTITY

/*#define FUNC_SetRwObjectAlpha                               0x5332C0
#define FUNC_SetOrientation                                 0x439A80

#define FUNC_CMatrix__ConvertToEulerAngles                   0x59A840
#define FUNC_CMatrix__ConvertFromEulerAngles                0x59AA40

#define FUNC_IsOnScreen                                     0x534540
#define FUNC_IsVisible                                      0x536BC0*/

#define FUNC_GetDistanceFromCentreOfMassToBaseOfModel       0x536BE0

#define FUNC_GetHeading										0x441DB0
#define FUNC_SetHeading										0x43E0C0

#define FUNC_CEntity__UpdateRw								0x446F90		// ?
#define FUNC_CMatrix__UpdateRw								0x446F90
#define FUNC_UpdateRwFrame									0x532B00

#define FUNC_CEntity__SetAsLod								0x533150

enum eEntityType
{
    ENTITY_TYPE_NOTHING,
    ENTITY_TYPE_BUILDING,
    ENTITY_TYPE_VEHICLE,
    ENTITY_TYPE_PED,
    ENTITY_TYPE_OBJECT,
    ENTITY_TYPE_DUMMY,
    ENTITY_TYPE_NOTINPOOLS
};

enum eEntityStatus
{
    STATUS_PLAYER,
    STATUS_PLAYER_PLAYBACKFROMBUFFER,
    STATUS_SIMPLE,
    STATUS_PHYSICS,
    STATUS_ABANDONED,
    STATUS_WRECKED,
    STATUS_TRAIN_MOVING,
    STATUS_TRAIN_NOT_MOVING,
    STATUS_HELI,
    STATUS_PLANE,
    STATUS_PLAYER_REMOTE,
    STATUS_PLAYER_DISABLED,
    STATUS_TRAILER,
    STATUS_SIMPLE_TRAILER
};

class CEntity;

class CEntityVTBL
{
public:
    void(__thiscall *SCALAR_DELETING_DESTRUCTOR)(CEntity *, char bRemoveFromPool);		// 0x0
    void(__thiscall *Add_CRect)(CEntity *, CRect *out);									// 0x4
	void(__thiscall *Add)(CEntity *);													// 0x8
    void(__thiscall *Remove)(CEntity *) ;												// 0xC
    void(__thiscall *SetIsStatic)(CEntity *, bool);										// 0x10
	void(__thiscall *SetModelIndex)(CEntity *, WORD model);								// 0x14
	void(__thiscall *SetModelIndexNoCreate)(CEntity *, WORD model);						// 0x18
    DWORD CreateRwObject;																// 0x1C
    DWORD DeleteRwObject;																// 0x20
    DWORD GetBoundRect;																	// 0x24
    DWORD ProcessControl;																// 0x28
    DWORD ProcessCollision;																// 0x2C
    DWORD ProcessShift;																	// 0x30
    DWORD TestCollision;																// 0x34
    DWORD Teleport;																		// 0x38
    DWORD SpecialEntityPreCollisionStuff;												// 0x3C
    DWORD SpecialEntityCalcCollisionSteps;												// 0x40
    DWORD PreRender;																	// 0x44
    DWORD Render;																		// 0x48
    DWORD SetupLighting;																// 0x4C
    DWORD RemoveLighting;																// 0x50
    void(__thiscall *FlagToDestroyWhenNextProcessed)(CEntity *);						// 0x54
};

class CReferences
{
public:
    CEntity *pEntity;
};

class CMatrix
{
public:
	RwMatrix matrix;
	RwMatrix *pMatrix;
	DWORD haveRwMatrix;

	void				UpdateRw();
	void				SetRotate(float x, float y, float z);
	void				RotateAroundZ(float heading);
	static		RwV3D	*OpMulMatrixVector(RwV3D *out, CMatrix *m, RwV3D *in);
};

class CSimpleTransform
{
public:
    CVector							m_translate;
	float							m_heading;
};

class CPlaceable
{
public:
    CEntityVTBL *vtbl;
    CSimpleTransform				m_transform;		// 'placement'
    CMatrix							*matrix;			// 'm_pCoords'
	
	void			SetXYZ(float x, float y, float z);
	RwV3D			GetPos();
	RwV3D			GetPos(float x, float y, float z);
	double			GetHeading();
	void			SetHeading(float rotZ);
	void			SetOrientation(float rotX, float rotY, float rotZ);
};

class CEntity : public CPlaceable	// sizeof=0x44
{
public:
    RpClump		*m_pRpClump;							// 0x18

    /********** BEGIN CFLAGS (0x1C) **************/
    unsigned long bUsesCollision : 1;				// does entity use collision
    unsigned long bCollisionProcessed : 1;			// has object been processed by a ProcessEntityCollision function
    unsigned long bIsStatic : 1;					// is entity static
    unsigned long bHasContacted : 1;				// has entity processed some contact forces
    unsigned long bIsStuck : 1;						// is entity stuck
    unsigned long bIsInSafePosition : 1;			// is entity in a collision free safe position
    unsigned long bWasPostponed : 1;				// was entity control processing postponed
    unsigned long bIsVisible : 1;					//is the entity visible
    
    unsigned long bIsBIGBuilding : 1;				// Set if this entity is a big building
    unsigned long bRenderDamaged : 1;				// use damaged LOD models for objects with applicable damage
    unsigned long bStreamingDontDelete : 1;			// Dont let the streaming remove this 
    unsigned long bRemoveFromWorld : 1;				// remove this entity next time it should be processed
    unsigned long bHasHitWall : 1;					// has collided with a building (changes subsequent collisions)
    unsigned long bImBeingRendered : 1;				// don't delete me because I'm being rendered
    unsigned long bDrawLast :1;						// draw object last
    unsigned long bDistanceFade :1;					// Fade entity because it is far away
    
    unsigned long bDontCastShadowsOn : 1;			// Dont cast shadows on this object
    unsigned long bOffscreen : 1;					// offscreen flag. This can only be trusted when it is set to true
    unsigned long bIsStaticWaitingForCollision : 1; // this is used by script created entities - they are static until the collision is loaded below them
    unsigned long bDontStream : 1;					// tell the streaming not to stream me
    unsigned long bUnderwater : 1;					// this object is underwater change drawing order
    unsigned long bHasPreRenderEffects : 1;			// Object has a prerender effects attached to it
    unsigned long bIsTempBuilding : 1;				// whether or not the building is temporary (i.e. can be created and deleted more than once)
    unsigned long bDontUpdateHierarchy : 1;			// Don't update the aniamtion hierarchy this frame
    
    unsigned long bHasRoadsignText : 1;				// entity is roadsign and has some 2deffect text stuff to be rendered
    unsigned long bDisplayedSuperLowLOD : 1;
    unsigned long bIsProcObject : 1;				// set object has been generate by procedural object generator
    unsigned long bBackfaceCulled : 1;				// has backface culling on
    unsigned long bLightObject : 1;					// light object with directional lights
    unsigned long bUnimportantStream : 1;			// set that this object is unimportant, if streaming is having problems
    unsigned long bTunnel : 1;						// Is this model part of a tunnel
    unsigned long bTunnelTransition : 1;			// This model should be rendered from within and outside of the tunnel
    /********** END CFLAGS **************/

    WORD        RandomSeed;					// 0x20
    WORD        m_nModelIndex;				// 0x22
    CReferences *pReferences;				// 0x24
    DWORD       *m_pLastRenderedLink;		// 0x28
    WORD		m_nScanCode;				// 0x2C
    BYTE		m_iplIndex;					// 0x2E
    BYTE		m_areaCode;					// 0x2F
    CEntity		*m_pLod;					// 0x30
    BYTE		numLodChildren;				// 0x34
    char		numLodChildrenRendered;		// 0x35

    //********* BEGIN CEntityInfo **********//
    //BYTE nType : 3;							// what type is the entity	// 0x36 (2 == Vehicle)
	BYTE bTypeBuilding	: 1;
	BYTE bTypeVehicle	: 1;
	BYTE bTypeObject	: 1;
	BYTE bTypePed		: 1;
    BYTE nStatus		: 4;						// control status			// 0x36
    //********* END CEntityInfo ************//

    BYTE pad[8];							// 0x37
    BYTE nImmunities;						// 0x3F

	DWORD bUnkDoor : 1;						// 0x40
	DWORD pad1 : 1;		
	DWORD bLocked : 1;
	DWORD bLocked2 : 1;

public:
	void				UpdateRw();
	void				UpdateRwFrame();
	void				SetOrientation(float rotX, float rotY, float rotZ);
	void				SetPosition(float x, float y, float z);
	CVector		*		GetPosition();
	float				GetDistanceFromCenterOfMassToBaseOfModel();
	
	WORD				GetModelIndex()						{return m_nModelIndex;};
};

#endif