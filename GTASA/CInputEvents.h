#ifndef __CINPUTEVENTS
#define __CINPUTEVENTS

struct DIJOYSTATE2
{
	BYTE pad[0x110];
};

class CInputEvents__Event
{
public:
	DWORD keycode;
	DWORD priority;
};

class CInputEvents
{
public:
	DWORD pad;
	DIJOYSTATE2 prevPadState;
	DIJOYSTATE2 currPadState;
	char eventNames[40][59];
	BYTE pad2[20];
	CInputEvents__Event events[4][59];

	// there are 4 slots for each one - one of the used slots will be set to 1 when the joystick is released
	BYTE leftStickXAxisUsed[4];
	BYTE leftStickYAxisUsed[4];
	BYTE rightStickXAxisUsed[4];
	BYTE rightStickYAxisUsed[4];

	char *CInputEvents::GetDefinedKeyByGxtName(unsigned __int16 event, const char *out, __int16 size);
};

#endif