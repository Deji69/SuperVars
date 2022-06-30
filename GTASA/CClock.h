#ifndef __CGAME_CCLOCK
#define __CGAME_CCLOCK

#define VAR_TimeMins				*(BYTE*)	0xB70152
#define VAR_TimeHours				*(BYTE*)	0xB70153
#define VAR_GameClockDay			*(char*)	0xB70154
#define VAR_GameClockMonth			*(char*)	0xB70155
#define VAR_GameSecondInMS			*(DWORD*)	0xB7015C
//#define VAR_DaysInMonth				(char*)		0x8CCF23

class CClock
{
public:
	static bool			GetIsTimeInRange(BYTE hourA, BYTE hourB);
};

#endif