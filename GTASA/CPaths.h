#ifndef __CPATHS
#define __CPATHS

#define FUNC_ReleasePath								0x45A0A0
#define VAR_PathCount						*(DWORD*)	0x97F630

class CPath
{
public:
	DWORD m_dwNumber;						// 0x0
	void *m_pPathData;						// 0x4
	DWORD m_dwPathSize;						// 0x8
	BYTE m_bTimesUsed;						// 0xC
	BYTE m_bIsCustomPath;					// 0xD

	static void			Release(int pathID);
};

#endif