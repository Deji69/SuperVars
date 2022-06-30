#ifndef __CPAD
#define __CPAD

class CControllerState
{
public:
	WORD LEFTSTICKX;
	WORD LEFTSTICKY;
	WORD RIGHTSTICKX;
	WORD RIGHTSTICKY;
	WORD LEFTSHOULDER1;
	WORD LEFTSHOULDER2;
	WORD RIGHTSHOULDER1;
	WORD RIGHTSHOULDER2;
	WORD DPADUP;
	WORD DPADDOWN;
	WORD DPADLEFT;
	WORD DPADRIGHT;
	WORD START;
	WORD SELECT;
	WORD SQUARE;
	WORD TRIANGLE;
	WORD CROSS;
	WORD CIRCLE;
	WORD LEFTSHOCK;
	WORD RIGHTSHOCK;
	WORD NETWORK_TALK;			// UNUSED
	WORD WALK;
	WORD MOUSELOOK;
	WORD UTRACKSKIP;
};

class CPad
{
public:
	CControllerState	NewState;
	CControllerState	OldState;
	WORD				SteeringLeftRightBuffer[10];
	DWORD				DrunkDrivingBufferUsed;
	CControllerState	PCTempKeyState;
	CControllerState	PCTempJoyState;
	CControllerState	PCTempMouseState;
	BYTE				Phase;
	WORD				Mode;
	WORD				ShakeDur;
	WORD				DisablePlayerControls;
	BYTE				ShakeFreq;
	BYTE				bHornHistory[5];
	BYTE				iCurrHornHistory;
	BYTE				JustOutOfFrontEnd;
	BYTE				bApplyBrakes;
	BYTE				bDisablePlayerEnterCar;
	BYTE				bDisablePlayerDuck;
	BYTE				bDisablePlayerFireWeapon;
	BYTE				bDisablePlayerFireWeaponWithL1;
	BYTE				bDisablePlayerCycleWeapon;
	BYTE				bDisablePlayerJump;
	BYTE				bDisablePlayerDisplayVitalStats;
	DWORD				LastTimeTouched;
	DWORD				AverageWeapon;
	DWORD				AverageEntries;
	DWORD				NoShakeBeforeThis;
	BYTE				NoShakeFreq;

	bool			IsCircleJustDown(){return this->NewState.CIRCLE && !this->OldState.CIRCLE;};
	bool			IsLeftShoulder1JustDown(){return this->NewState.LEFTSHOULDER1 && !this->OldState.LEFTSHOULDER1;};
};

#endif