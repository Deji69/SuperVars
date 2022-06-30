#ifndef __CWANTED
#define __CWANTED

#include "Common.h"

#define MAX_CRIMES_QD       16
#define MAX_COPS_PURSUIT    10
#define MAX_COP_CARS_PURSUIT 3

class CCrimeBeingQd
{
	friend class CWanted;

protected:
    DWORD       CrimeType;
    long        CrimeID;
    DWORD       TimeOfQing;
    CVector		Coors;
    bool        bAlreadyReported;
    bool        bPoliceDontReallyCare;
};

class CWanted
{
protected:
	int m_nChaos;								// 0x0
	int m_WantedLevelBeforeParole;				// 0x4
	DWORD m_LastTimeWantedLevelDecreased;		// 0x8
	DWORD m_LastTimeWantedLevelChanged;			// 0xC
	DWORD m_TimeOfParole;						// 0x10
	float m_fMultiplier;						// 0x14
	BYTE m_nCopsInPursuit;						// 0x18
	BYTE m_nMaxCopsInPursuit;					// 0x19
	BYTE m_nMaxCopCarsInPursuit;				// 0x1A
	BYTE m_nCopsBeatingSuspect;					// 0x1B
	BYTE m_nChanceOfRoadblock;					// 0x1C
	
	char m_PoliceBackOff : 1;					// 0x1D
	char m_PoliceBackOffGarage : 1;
	char m_EverybodyBackOff : 1;
	char m_SwatRequired : 1;
	char m_FbiRequired : 1;
	char m_ArmyRequired : 1;

	DWORD m_nCurrentChaseTime;					// 0x20
	DWORD m_nCurrentChaseTimeCounter;

	BYTE m_bTimeCounting;

	eWantedLevelSA m_nWantedLevel;
	eWantedLevelSA m_nWantedLevelBeforeParole;

	CCrimeBeingQd	CrimesBeingQd[MAX_CRIMES_QD];

	CPed * m_pCopsInPursuit[MAX_COPS_PURSUIT];

	DWORD m_PoliceScannerAudioEntity; // was CAEPoliceScannerAudioEntity

public:
    inline char		GetWantedLevel()								{return m_nWantedLevel;};
	inline char		GetWantedLevelBeforeParole()					{return m_nWantedLevelBeforeParole;};
	void			Recalc();
    void            SetMaximumWantedLevel(DWORD dwWantedLevel);
    void            SetWantedLevel(DWORD dwWantedLevel);
    void            SetWantedLevelNoDrop(DWORD dwWantedLevel);
    void            SetWantedLevelNoFlash(DWORD dwWantedLevel);
	bool			IsOver3()										{return m_nWantedLevel >= 3;};
	bool			IsSwatRequired()								{return m_nWantedLevel == 4 || m_SwatRequired;};
	bool			IsFbiRequired()									{return m_nWantedLevel == 5 || m_FbiRequired;};
	bool			IsArmyRequired()								{return m_nWantedLevel == 6 || m_ArmyRequired;};
	int				GetNumHelisRequired();
	void			ClearQdCrimes();
};

#endif