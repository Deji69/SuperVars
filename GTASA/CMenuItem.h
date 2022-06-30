#ifndef __CMENUITEM
#define __CMENUITEM

#define WIN32_LEAN_AND_MEAN

class CMenuItem
{
public:
	char		name[8];
	BYTE		prevMenu;
	BYTE		field_9;
	CEntryData	entryList[12];
};

class CMenuItemFunc
{
public:
};

#endif