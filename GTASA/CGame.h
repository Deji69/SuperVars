#ifndef __CGAME
#define __CGAME

#include "Common.h"

#define VAR_MaxWidth					*(DWORD*)			0xC17044
#define VAR_MaxHeight					*(DWORD*)			0xC17048

#define VAR_IsForegroundWindow			*(bool*)			0x8D621C
#define VAR_GamePaused					*(bool*)			0xB7CB49
#define VAR_FPS							*(float*)			0xB7CB50
#define VAR_OldTimeStep					*(float*)			0xB7CB54
#define VAR_TimeStep					*(float*)			0xB7CB5C
#define VAR_GameSpeed					*(float*)			0xB7CB64
#define VAR_GameTime					*(DWORD*)			0xB7CB84
#define VAR_IsAtMenu					*(BYTE*)			0xBA677B
#define VAR_Framelimiter				*(DWORD*)			0xC1704C
#define VAR_GameState					*(DWORD*)			0xC8D4C0

#define ARRAY_CGarages						0x96C048
#define CLASS_CFx							0xA9AE00
#define CLASS_CCamera						(CCamera *)			0xB6F028
//#define CLASS_RwCamera						0xB6F97C
#define ARRAY_CPad							(CPad *)			0xB73458
#define CLASS_CPlayerInfo					(CPlayerInfo *)		0xB7CD98
#define CLASS_CMenuManager					(CMenuManager *)	0xBA6748

#define ARRAY_WeaponInfo					0xC8AAB8
#define CLASSSIZE_WeaponInfo				112
#define NUM_WeaponInfosStdSkill				WEAPONTYPE_LAST_WEAPONTYPE
#define NUM_WeaponInfosOtherSkill			11
#define NUM_WeaponInfosTotal				(NUM_WeaponInfosStdSkill + (3 * NUM_WeaponInfosOtherSkill))

#define MODELINFO_LAST_PLAYER_ID			288
#define MODELINFO_MAX						65535

//#define GTA3
//#define GTA_VC
#define GTA_SA

enum eGameVersion 
{
	GAMEVER_1US = 1,
    GAMEVER_1EU = 2,
    GAMEVER_11 = 4,
    GAMEVER_2 = 8,
    GAMEVER_STEAM = 16,
	GAMEVER_COMPACT = 32,
	GAMEVER_1US2 = 64,
    GAMEVER_UNKNOWN = 255,
};

//#define SA_VER (GAMEVER_1US | GAMEVER_1EU | GAMEVER_COMPACT)

class CGame;

extern CGame			*	pGame;

#include "CTheScripts.h"

#include <windows.h>

class CGame
{
protected:
private:
public:
	CGame();
	~CGame();
	CTheScripts			* GetTheScripts()			{return m_pTheScripts;};

	inline char					*	GetReadLineBuffer()					{return ReadLineBuffer;};

	/*virtual DWORD               GetSystemTime (  )=0;
	virtual BOOL                IsAtMenu (  )=0;
	virtual BOOL                IsGameLoaded (  )=0;
	virtual VOID                StartGame (  )=0;
	virtual VOID                SetSystemState ( eSystemState State )=0;
	virtual eSystemState        GetSystemState (  )=0;
	virtual VOID                Pause ( bool bPaused )=0;
	virtual bool                IsPaused ( )=0;
	virtual bool                IsInForeground ( )=0;
	virtual VOID                DisableRenderer( bool bDisabled )=0;
	//virtual VOID                SetRenderHook ( InRenderer* pInRenderer )=0;
	virtual VOID                TakeScreenshot ( char * szFileName )=0;
	virtual DWORD               * GetMemoryValue ( DWORD dwOffset )=0;
	virtual void                SetTimeScale ( float fTimeScale )=0;
	virtual float               GetFPS ( void )=0;
	virtual float               GetTimeStep ( void )=0;
	virtual float               GetOldTimeStep ( void )=0;
	virtual float               GetTimeScale ( void )=0;

	virtual void                Initialize  ( void ) = 0;
	virtual void                Reset               ( void ) = 0;
	virtual void                Terminate ( void ) = 0;

	virtual BOOL                InitLocalPlayer(  )=0;

	virtual float               GetGravity ( void ) = 0;
	virtual void                SetGravity ( float fGravity ) = 0;

	virtual float               GetGameSpeed ( void ) = 0;
	virtual void                SetGameSpeed ( float fSpeed ) = 0;

	virtual unsigned long       GetMinuteDuration ( void ) = 0;
	virtual void                SetMinuteDuration ( unsigned long ulDelay ) = 0;

	virtual unsigned char       GetBlurLevel ( void ) = 0;
	virtual void                SetBlurLevel ( unsigned char ucLevel ) = 0;

	virtual eGameVersion        GetGameVersion ( void ) = 0;

	virtual bool                IsCheatEnabled              ( const char* szCheatName ) = 0;
	virtual bool                SetCheatEnabled             ( const char* szCheatName, bool bEnable ) = 0;
	virtual void                ResetCheats                 () = 0;

	virtual bool                VerifySADataFileNames       () = 0;
	virtual bool                PerformChecks               () = 0;
	virtual int&                GetCheckStatus              () = 0;

	virtual void                SetAsyncLoadingFromSettings     ( bool bSettingsDontUse, bool bSettingsEnabled ) = 0;
	virtual void                SetAsyncLoadingFromScript       ( bool bScriptEnabled, bool bScriptForced ) = 0;
	virtual void                SuspendASyncLoading             ( bool bSuspend ) = 0;
	virtual bool                IsASyncLoadingEnabled           ( bool bIgnoreSuspend = false ) = 0;

	virtual bool                HasCreditScreenFadedOut         ( void ) = 0;
	virtual void                FlushPendingRestreamIPL         ( void ) = 0;
	virtual void                DisableVSync                    ( void ) = 0;*/
private:
	CTheScripts					* m_pTheScripts;

	char							ReadLineBuffer[512];
};

#endif