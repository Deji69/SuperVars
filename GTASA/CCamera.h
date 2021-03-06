#ifndef __CCAMERA
#define __CCAMERA

enum eCamMode 
{ 
    MODE_NONE = 0, 
    MODE_TOPDOWN, //=1, 
    MODE_GTACLASSIC,// =2, 
    MODE_BEHINDCAR, //=3, 
    MODE_FOLLOWPED, //=4, 
    MODE_AIMING, //=5, 
    MODE_DEBUG, //=6, 
    MODE_SNIPER, //=7, 
    MODE_ROCKETLAUNCHER, //=8,   
    MODE_MODELVIEW, //=9, 
    MODE_BILL, //=10, 
    MODE_SYPHON, //=11, 
    MODE_CIRCLE, //=12, 
    MODE_CHEESYZOOM, //=13, 
    MODE_WHEELCAM, //=14, 
    MODE_FIXED, //=15, 
    MODE_1STPERSON, //=16, 
    MODE_FLYBY, //=17, 
    MODE_CAM_ON_A_STRING, //=18,  
    MODE_REACTION, //=19, 
    MODE_FOLLOW_PED_WITH_BIND, //=20, 
    MODE_CHRIS, //21
    MODE_BEHINDBOAT, //=22, 
    MODE_PLAYER_FALLEN_WATER, //=23, 
    MODE_CAM_ON_TRAIN_ROOF, //=24, 
    MODE_CAM_RUNNING_SIDE_TRAIN, //=25,  
    MODE_BLOOD_ON_THE_TRACKS, //=26, 
    MODE_IM_THE_PASSENGER_WOOWOO, //=27, 
    MODE_SYPHON_CRIM_IN_FRONT,// =28, 
    MODE_PED_DEAD_BABY, //=29, 
    MODE_PILLOWS_PAPS, //=30, 
    MODE_LOOK_AT_CARS, //=31, 
    MODE_ARRESTCAM_ONE, //=32, 
    MODE_ARRESTCAM_TWO, //=33, 
    MODE_M16_1STPERSON, //=34, 
    MODE_SPECIAL_FIXED_FOR_SYPHON, //=35, 
    MODE_FIGHT_CAM, //=36, 
    MODE_TOP_DOWN_PED, //=37,
    MODE_LIGHTHOUSE, //=38
    ///all 1rst person run ablout run about modes now
    MODE_SNIPER_RUNABOUT, //=39, 
    MODE_ROCKETLAUNCHER_RUNABOUT, //=40,  
    MODE_1STPERSON_RUNABOUT, //=41,
    MODE_M16_1STPERSON_RUNABOUT, //=42,
    MODE_FIGHT_CAM_RUNABOUT, //=43,
    MODE_EDITOR, //=44,
    MODE_HELICANNON_1STPERSON, //= 45
    MODE_CAMERA, //46
    MODE_ATTACHCAM,  //47
    MODE_TWOPLAYER,
    MODE_TWOPLAYER_IN_CAR_AND_SHOOTING,
    MODE_TWOPLAYER_SEPARATE_CARS,   //50
    MODE_ROCKETLAUNCHER_HS, 
    MODE_ROCKETLAUNCHER_RUNABOUT_HS,
    MODE_AIMWEAPON,
    MODE_TWOPLAYER_SEPARATE_CARS_TOPDOWN,
    MODE_AIMWEAPON_FROMCAR, //55
    MODE_DW_HELI_CHASE,
    MODE_DW_CAM_MAN,
    MODE_DW_BIRDY,
    MODE_DW_PLANE_SPOTTER,
    MODE_DW_DOG_FIGHT, //60
    MODE_DW_FISH,
    MODE_DW_PLANECAM1,
    MODE_DW_PLANECAM2,
    MODE_DW_PLANECAM3,
    MODE_AIMWEAPON_ATTACHED //65
};

enum eVehicleCamMode
{
    MODE_BUMPER,
    MODE_CLOSE_EXTERNAL,
    MODE_MIDDLE_EXTERNAL,
    MODE_FAR_EXTERNAL,
    MODE_LOW_EXTERNAL,
    MODE_CINEMATIC
};

enum {FADE_OUT=0, FADE_IN};

#define FUNC_GetFadeStage					0x50AE20

class CCamera
{
public:
	CPlaceable Placeable;
	bool    m_bAboveGroundTrainNodesLoaded;
	bool    m_bBelowGroundTrainNodesLoaded;
	bool    m_bCamDirectlyBehind;   
	bool    m_bCamDirectlyInFront;
	bool    m_bCameraJustRestored;
	bool    m_bcutsceneFinished;
	bool    m_bCullZoneChecksOn;
	bool    m_bFirstPersonBeingUsed; // To indicate if the m_bFirstPersonBeingUsed viewer is being used.
	bool    m_bJustJumpedOutOf1stPersonBecauseOfTarget;
	bool    m_bIdleOn;
	bool    m_bInATunnelAndABigVehicle;
	bool    m_bInitialNodeFound;
	bool    m_bInitialNoNodeStaticsSet;
	bool    m_bIgnoreFadingStuffForMusic;
	bool    m_bPlayerIsInGarage;
	bool    m_bPlayerWasOnBike;
	bool    m_bJustCameOutOfGarage;
	bool    m_bJustInitalised;//Just so the speed thingy doesn't go mad right at the start
	unsigned char   m_bJust_Switched;//Variable to indicate that we have jumped somewhere, Raymond needs this for the audio engine
	bool    m_bLookingAtPlayer;
	bool    m_bLookingAtVector;
	bool    m_bMoveCamToAvoidGeom;
	bool    m_bObbeCinematicPedCamOn;
	bool    m_bObbeCinematicCarCamOn;
	bool    m_bRestoreByJumpCut;
	bool    m_bUseNearClipScript;
	bool    m_bStartInterScript;
	unsigned char   m_bStartingSpline;
	bool    m_bTargetJustBeenOnTrain; //this variable is needed to be able to restore the camera
	bool    m_bTargetJustCameOffTrain;
	bool    m_bUseSpecialFovTrain;
	bool    m_bUseTransitionBeta;
	bool    m_bUseScriptZoomValuePed;
	bool    m_bUseScriptZoomValueCar;
	bool    m_bWaitForInterpolToFinish;
	bool    m_bItsOkToLookJustAtThePlayer; //Used when interpolating
	bool    m_bWantsToSwitchWidescreenOff;  
	bool    m_WideScreenOn; 
	bool    m_1rstPersonRunCloseToAWall;
	bool    m_bHeadBob;
	bool    m_bVehicleSuspenHigh;
	bool    m_bEnable1rstPersonCamCntrlsScript; 
	bool    m_bAllow1rstPersonWeaponsCamera;
	bool    m_bCooperativeCamMode;
	bool    m_bAllowShootingWith2PlayersInCar;
	bool    m_bDisableFirstPersonInCar;
	static bool m_bUseMouse3rdPerson;

	short   m_ModeForTwoPlayersSeparateCars;
	short   m_ModeForTwoPlayersSameCarShootingAllowed;
	short   m_ModeForTwoPlayersSameCarShootingNotAllowed;
	short   m_ModeForTwoPlayersNotBothInCar;

	bool    m_bGarageFixedCamPositionSet;
	bool    m_vecDoingSpecialInterPolation;
	bool    m_bScriptParametersSetForInterPol;


	bool    m_bFading;//to indicate that we are fading 
	bool    m_bMusicFading;
	bool    m_bMusicFadedOut;

	bool    m_bFailedCullZoneTestPreviously;
	bool    m_FadeTargetIsSplashScreen;//used as hack for fading 
	bool    WorldViewerBeingUsed; // To indicate if the world viewer is being used.                                      


	unsigned char   m_uiTransitionJUSTStarted;  // This is the first frame of a transition.
	unsigned char   m_uiTransitionState;        // 0:one mode 1:transition
	unsigned char   ActiveCam;              // Which one at the moment (0 or 1)
										// Their is a fudge at the end when the renderware matrix will receive either
										// the active camera or the worldviewer camera

	unsigned int    m_uiCamShakeStart;          // When did the camera shake start.
	unsigned int    m_uiFirstPersonCamLastInputTime;
	unsigned int    m_uiLongestTimeInMill;
	unsigned int    m_uiNumberOfTrainCamNodes;
	unsigned int    m_uiTimeLastChange;
	unsigned int    m_uiTimeWeLeftIdle_StillNoInput;
	unsigned int  m_uiTimeWeEnteredIdle;
	unsigned int    m_uiTimeTransitionStart;    // When was the transition started ?
	unsigned int    m_uiTransitionDuration;     // How long does the transition take ?
	unsigned int    m_uiTransitionDurationTargetCoors;
	int     m_BlurBlue;
	int     m_BlurGreen;
	int     m_BlurRed;
	int     m_BlurType;
	int     m_iWorkOutSpeedThisNumFrames;//duh  
	int     m_iNumFramesSoFar; //counter
	int     m_iCurrentTrainCamNode;//variable indicating which camera node we are at for the train
	int     m_motionBlur;//to indicate that we are fading

	int     m_imotionBlurAddAlpha;
	int     m_iCheckCullZoneThisNumFrames; 
	int     m_iZoneCullFrameNumWereAt;
	int     WhoIsInControlOfTheCamera; //to discern between obbe and scripts

	int		m_nCarZoom;                 // store zoom index
	float   m_fCarZoomBase;             // store base zoom distance from index
	float   m_fCarZoomTotal;            // store total zoom after modded by camera modes
	float   m_fCarZoomSmoothed;         // buffered version of the var above
	float   m_fCarZoomValueScript;
	int     m_nPedZoom;                 // store zoom index
	float   m_fPedZoomBase;             // store base zoom distance from index
	float   m_fPedZoomTotal;            // store total zoom after modded by camera modes
	float   m_fPedZoomSmoothed;         // buffered version of the var above
	float   m_fPedZoomValueScript;

	float   CamFrontXNorm, CamFrontYNorm;
	float   DistanceToWater;
	float   HeightOfNearestWater;
	float   FOVDuringInter;
	float   LODDistMultiplier;  // This takes into account the FOV and the standard LOD multiplier Smaller aperture->bigger LOD multipliers.
	float   GenerationDistMultiplier;   // This takes into account the FOV but noy the standard LOD multiplier

	float   m_fAlphaSpeedAtStartInter;
	float   m_fAlphaWhenInterPol;
	float   m_fAlphaDuringInterPol;
	float   m_fBetaDuringInterPol;
	float   m_fBetaSpeedAtStartInter;
	float   m_fBetaWhenInterPol;
	float   m_fFOVWhenInterPol;
	float   m_fFOVSpeedAtStartInter;
	float   m_fStartingBetaForInterPol;
	float   m_fStartingAlphaForInterPol;
	float   m_PedOrientForBehindOrInFront;

	float   m_CameraAverageSpeed; //this is an average depending on how many frames we work it out
	float   m_CameraSpeedSoFar; //this is a running total
	float   m_fCamShakeForce;           // How severe is the camera shake.
	float   m_fFovForTrain;
	float   m_fFOV_Wide_Screen;

	float   m_fNearClipScript;
	float   m_fOldBetaDiff;         // Needed for interpolation between 2 modes
	float   m_fPositionAlongSpline;//Variable used to indicate how far along the spline we are 0-1 for started to completed respectively
	float   m_ScreenReductionPercentage;
	float   m_ScreenReductionSpeed;
	float   m_AlphaForPlayerAnim1rstPerson;

	float   Orientation;            // The orientation of the camera. Used for peds walking.
	float   PlayerExhaustion;       // How tired is player (inaccurate sniping) 0.0f-1.0f
					// The following things are used by the sound code to
					// play reverb depending on the surroundings. From a point
					// in front of the camera the disance is measured to the
					// nearest obstacle (building)
	float   SoundDistUp; //, SoundDistLeft, SoundDistRight;     // These ones are buffered and should be used by the audio
	float   SoundDistUpAsRead; //, SoundDistLeftAsRead, SoundDistRightAsRead;
	float   SoundDistUpAsReadOld; //, SoundDistLeftAsReadOld, SoundDistRightAsReadOld;
					// Very rough distance to the nearest water for the sound to use
					// Front vector X&Y normalised to 1. Used by loads of stuff.


	float   m_fAvoidTheGeometryProbsTimer;
	short   m_nAvoidTheGeometryProbsDirn;

	float   m_fWideScreenReductionAmount;//0 for not reduced 1 for fully reduced (Variable for Les)
	float   m_fStartingFOVForInterPol;

	// These ones are static so that they don't get cleared in CCamera::Init()
	static  float m_fMouseAccelHorzntl;// acceleration multiplier for 1st person controls
	static  float m_fMouseAccelVertical;// acceleration multiplier for 1st person controls
	static  float m_f3rdPersonCHairMultX;
	static  float m_f3rdPersonCHairMultY;

	CCam	Cams[3];

	void	*pGarageWeAreIn;
	void	*pToGarageWeAreInForHackAvoidFirstPerson;

	bool						GetFading(){return this->m_bFading;};
	int							GetFadeStage();
};

#endif