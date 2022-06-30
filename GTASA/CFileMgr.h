#ifndef __CFILEMGR
#define __CFILEMGR

class CFileMgr
{
public:
	static	FILE			*	Open(const char *pFilePath, const char *pOpenMode);
	static	int					Close(FILE *hFile);
	static	char				GetLine(FILE *hFile, char *buff, int size);
	static	char			*	GetConfigLine(FILE *hFile);
};

#endif