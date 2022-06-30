#ifndef __CPANEL
#define __CPANEL

#define FUNC_GetCarcolIndexFromPanelRow						0x5822B0

class CPanel
{
public:
	static int			GetCarcolIndexFromPanelRow(int panel, int row);
};

#endif