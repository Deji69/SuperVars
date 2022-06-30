#ifndef __CSTREAMING
#define __CSTREAMING

#if SA_VER & GAMEVER_STEAM
	#define FUNC_RequestModel					0x408920
	#define FUNC_ReleaseModel					0x409E90
	#define FUNC_LoadRequestedModels			0x40EEA0
#else
	#define FUNC_RequestModel					0x4087E0
	#define FUNC_ReleaseModel					0x409C10
	#define FUNC_ReleaseSpecialModel			0x409C90
	#define FUNC_LoadRequestedModels			0x40EA10

	#define ARRAY_LoadedObjectInfo					((LoadedObjectInfo*)	0x8E4CC0)
#endif

#define MODELS_SCRIPT_OFFSET 26230

class CStreaming
{
public:
	void	static		RequestModel(int model, int flag);
	void	static		ReleaseModel(int model);
	void	static		ReleaseSpecialModel(int index);
	void	static		LoadRequestedModels(int flag);
};

class LoadedObjectInfo		// sizeof: 0x14
{
public:
	WORD nextIndex;
	WORD prevIndex;			// 0x2
	WORD f4;				// 0x4
	BYTE f6;				// 0x6
	BYTE f7;				// 0x7
	DWORD f8;				// 0x8
	DWORD fC;				// 0xC
	BYTE bLoaded;			// 0x10
};

#endif 