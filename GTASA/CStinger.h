#ifndef __CSTINGER
#define __CSTINGER

class CStinger
{
public:
	CObject			*		pObject;
	DWORD					dwTimeCreated;
	BYTE					nScore;
	BYTE					nNumCarsGot;
	bool					bPlayerOwned;
};

#endif