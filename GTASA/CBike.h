#ifndef __CBIKE
#define __CBIKE

#include "CVehicle.h"

class CBike : public CVehicle
{
public:
	DWORD		Unknown200[20];						// 0x5A0
	DWORD		Unknown201[20];						// 0x5EC
	DWORD		Unknown202[7];						// 0x63C
	char		WheelStatus[2];						// 0x65C
	CWheelData	FrontWheelData;						// 0x660
    CWheelData	FrontWheelData2;					// 0x68C
    CWheelData	RearWheelData;						// 0x6B8
    CWheelData	RearWheelData2;						// 0x6E4
};

#endif