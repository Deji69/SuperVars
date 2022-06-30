#ifndef __CENTRYDATA
#define __CENTRYDATA

#define WIN32_LEAN_AND_MEAN

class CEntryData
{
public:
	BYTE	action;
	char	description[8];
	BYTE	specialDescFlag;
	WORD	targetMenu;
	WORD	posX;
	WORD	posY;
	BYTE	align;
	BYTE	field_11;
};

#endif