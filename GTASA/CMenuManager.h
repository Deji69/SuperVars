#ifndef __CGAME_CMENUMANAGER
#define __CGAME_CMENUMANAGER

#define FUNC_CMenuManager__DrawPage							0x57B750

enum eMenuScreen
{
	MENUSCREEN_Stats = 0,
	MENUSCREEN_StartGame,
	MENUSCREEN_Brief,
	MENUSCREEN_AudioOtions,
	MENUSCREEN_DisplaySettings,
	MENUSCREEN_Map,
	MENUSCREEN_ConfirmStartNewGame,
	MENUSCREEN_GameSelect,
	MENUSCREEN_ConfirmLoadMissionPack,
	MENUSCREEN_LoadGame,
	MENUSCREEN_DeleteGame,
	MENUSCREEN_ConfirmLoadSaveGame,
	MENUSCREEN_ConfirmDeleteGame,
	MENUSCREEN_UnkLoadFirstSaveGame,
	MENUSCREEN_DeleteSuccess,
	MENUSCREEN_DeleteSuccess2,
	MENUSCREEN_SaveGame,
	MENUSCREEN_ConfirmSave,
	MENUSCREEN_SaveSuccess,
	MENUSCREEN_SaveSuccess2,
	MENUSCREEN_SaveGameOk,
	MENUSCREEN_LoadGameOk,
	MENUSCREEN_GameAffectedDoNotSave,
	MENUSCREEN_DisplayDefaultSettings,
	MENUSCREEN_AudioDefaultSettings,
	MENUSCREEN_ControllerDefaultSettings,
	MENUSCREEN_UserTrackOptions,
	MENUSCREEN_LanguageSelect = 28,
	MENUSCREEN_SaveGameOk2,
	MENUSCREEN_SaveGameFail,
	MENUSCREEN_LoadGameFail,
	MENUSCREEN_LoadGameFailFileCorrupt,
	MENUSCREEN_Options,
	MENUSCREEN_MainMenu,
	MENUSCREEN_QuitGame,
	MENUSCREEN_ControllerSetup,
	MENUSCREEN_RedefineControls,
	MENUSCREEN_FootOrVehicleControls,
	MENUSCREEN_MouseSettings,
	MENUSCREEN_JoypadSettings,
	MENUSCREEN_GameMenu,
	MENUSCREEN_QuitGame2,
	MENUSCREEN_Empty
};

class CMenuManager
{
private:
	BYTE bStatsScrollDirection;				// 0x0
	float fStatsScrollSpeed;				// 0x4
	BYTE unk1[25];
	BYTE bHudEnabled;						// 0x21
	BYTE unk2[2];
	BYTE bRadarMode;						// 0x24
	DWORD unk3;								// 0x28
	DWORD hWaypointBlip;					// 0x2C
	char bPanel;							// 0x30
	BYTE unk4;								// 0x31
	BYTE bExitMenu;							// 0x32
	BYTE bActivateMenu;						// 0x33
	BYTE bMenuAccessDuringWidescreen;		// 0x34
	DWORD unk5;								// 0x38
	float fBrightness;						// 0x3C
	float fDrawDistance;					// 0x40
	BYTE bSubtitlesOn;						// 0x44
	BYTE bDisplayLocationBlips;				// 0x45
	BYTE bDisplayContactBlips;				// 0x46
	BYTE bDisplayMissionBlips;				// 0x47
	BYTE bDisplayOtherBlips;				// 0x48
	BYTE bDisplayGangAreas;					// 0x49
	BYTE bLegend;							// 0x4A
	BYTE bWidescreen;						// 0x4B
	BYTE bFrameLimiter;						// 0x4C
	BYTE bRadioAutotune;					// 0x4D
	BYTE unk6;								// 0x4E
	BYTE bSfxVolume;						// 0x4F
	BYTE bRadioVolume;						// 0x50
	BYTE bRadioEq;							// 0x51
	BYTE bRadioStation;						// 0x52
	int iSelectedMenuItem;					// 0x54
	BYTE unk7;								// 0x58
	BYTE bDrawRadarOrMap;					// 0x59
	BYTE bLoadMapTextures;					// 0x5A
	BYTE bLoadingMapTextures;				// 0x5B
	BYTE bIsActive;							// 0x5C
	BYTE bUnkDoGameReload;					// 0x5D
	BYTE unk8;								// 0x5E
	BYTE bShowSaveScreen;					// 0x5F
	BYTE bMuteEnterExitMenuSound;			// 0x60
	float fMapZoom;							// 0x64
	float fMapScreenPosX;					// 0x68
	float fMapScreenPosY;					// 0x6C
	float fMapCursorPosX;					// 0x70
	float fMapCursorPosY;					// 0x74
	char bMapTexturesLoaded;				// 0x78
	int iTitleLanguage;						// 0x7C
	int iTextLanguage;						// 0x80
	char bCurrentLanguage;					// 0x84
	char bPreviousLanguage;					// 0x85
	// 0xC5 

public:
	inline	bool				IsRadarEnabled()			{return bRadarMode != 2;};
	inline	bool				IsExiting()					{return bExitMenu != 0;};
	inline	char				GetCurrentLanguage()		{return bCurrentLanguage;};

	CMenuManager();
	void	SetRenderState();
	void	DrawPage();
};

#endif