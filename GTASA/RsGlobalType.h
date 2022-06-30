#ifndef __RSGLOBALTYPE
#define __RSGLOBALTYPE

struct PsGlobalType
{
	HWND		window;
	HINSTANCE	instance;
	DWORD		fullscreen;
	DWORD		lastMousePos_X;
	DWORD		lastMousePos_Y;
	DWORD		unk;
	DWORD		diInterface;
	DWORD		diMouse;
	void	*	diDevice1;
	void	*	diDevice2;
};

struct RsGlobalType
{
	DWORD			AppName;
	DWORD			MaximumWidth;
	DWORD			MaximumHeight;
	DWORD			frameLimit;
	DWORD			quit;
	PsGlobalType*	ps;
	void		*	keyboard;
	void		*	mouse;
	void		*	pad;
};

#endif