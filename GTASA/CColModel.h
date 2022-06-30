#ifndef __CCOLMODEL
#define __CCOLMODEL

typedef struct
{
    char version[4];
    DWORD size;
    char name[0x18];
} ColModelFileHeader;

typedef struct
{
    DWORD                           pad0;
    WORD                            pad1;
    BYTE                            ucNumWheels;
    BYTE                            pad2;
    DWORD                           pad3;
    DWORD                           pad4;
    void*                           pSuspensionLines;
} CColData;

class CColModel
{
public:
	RwBBox							bbox;
	RwSphere						sphere;
	BYTE							pad0;
	BYTE							flags;
	WORD							pad1;
    CColData*						pColData;
};

#endif