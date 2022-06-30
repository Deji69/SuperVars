#ifndef __RWENGINEINSTANCE
#define __RWENGINEINSTANCE

#define VAR_EngineInst						(*(RwEngineInstance**)	0xC97B24)

enum RwRenderState
{
	rwRENDERSTATENARENDERSTATE				= 0x0,
	rwRENDERSTATETEXTURERASTER				= 0x1,
	rwRENDERSTATETEXTUREADDRESS				= 0x2,
	rwRENDERSTATETEXTUREADDRESSU			= 0x3,
	rwRENDERSTATETEXTUREADDRESSV			= 0x4,
	rwRENDERSTATETEXTUREPERSPECTIVE			= 0x5,
	rwRENDERSTATEZTESTENABLE				= 0x6,
	rwRENDERSTATESHADEMODE					= 0x7,
	rwRENDERSTATEZWRITEENABLE				= 0x8,
	rwRENDERSTATETEXTUREFILTER				= 0x9,
	rwRENDERSTATESRCBLEND					= 0xA,
	rwRENDERSTATEDESTBLEND					= 0xB,
	rwRENDERSTATEVERTEXALPHAENABLE			= 0xC,
	rwRENDERSTATEBORDERCOLOR				= 0xD,
	rwRENDERSTATEFOGENABLE					= 0xE,
	rwRENDERSTATEFOGCOLOR					= 0xF,
	rwRENDERSTATEFOGTYPE					= 0x10,
	rwRENDERSTATEFOGDENSITY					= 0x11,
	rwRENDERSTATECULLMODE					= 0x14,
	rwRENDERSTATESTENCILENABLE				= 0x15,
	rwRENDERSTATESTENCILFAIL				= 0x16,
	rwRENDERSTATESTENCILZFAIL				= 0x17,
	rwRENDERSTATESTENCILPASS				= 0x18,
	rwRENDERSTATESTENCILFUNCTION			= 0x19,
	rwRENDERSTATESTENCILFUNCTIONREF			= 0x1A,
	rwRENDERSTATESTENCILFUNCTIONMASK		= 0x1B,
	rwRENDERSTATESTENCILFUNCTIONWRITEMASK	= 0x1C,
	rwRENDERSTATEALPHATESTFUNCTION			= 0x1D,
	rwRENDERSTATEALPHATESTFUNCTIONREF		= 0x1E
};

struct RwLLLink				// 0x8
{
	DWORD next;
	DWORD prev;
};

struct RwLinkList			// 0x8
{
	RwLLLink link;
};

struct RwFileFunction		// 0x2C
{
	DWORD rwCheckFileReadable;
	DWORD rwfopen;
	DWORD rwfclose;
	DWORD rwfread;
	DWORD rwfwrite;
	DWORD rwfgets;
	DWORD rwfputs;
	DWORD rwfeof;
	DWORD rwfseek;
	DWORD rwfflush;
	DWORD rwftell;
};

struct RwStringFunctions		// 0x44
{
	DWORD vecSprintf;
	DWORD vecVsprintf;
	DWORD vecStrcpy;
	DWORD vecStrncpy;
	DWORD vecStrcat;
	DWORD vecStrncat;
	DWORD vecStrrchr;
	DWORD vecStrchr;
	DWORD vecStrstr;
	DWORD vecStrcmp;
	DWORD vecStrncmp;
	DWORD vecStricmp;
	DWORD vecStrlen;
	DWORD vecStrupr;
	DWORD vecStrlwr;
	DWORD vecStrtok;
	DWORD vecSscanf;
};

struct RwMemoryFunctions		// 0x10
{
	DWORD rwmalloc;
	DWORD rwfree;
	DWORD rwrealloc;
	DWORD rwcalloc;
};

struct RwDevice					// 0x38
{
	DWORD gammaCorrection;
	DWORD fpSystem;
	DWORD zBufferNear;
	DWORD zBufferFar;
	void (__cdecl *fpRenderStateSet)(RwRenderState, int);
	int (__cdecl *fpRenderStateGet)(RwRenderState);
	DWORD fpIm2DRenderLine;
	DWORD fpIm2DRenderTriangle;
	DWORD fpIm2DRenderPrimitive;
	DWORD fpIm2DRenderIndexedPrimitive;
	DWORD fpIm3DRenderLine;
	DWORD fpIm3DRenderTriangle;
	DWORD fpIm3DRenderPrimitive;
	DWORD fpIm3DRenderIndexedPrimitive;
};

struct RwEngineInstance		// 0x158
{
	DWORD				curCamera;
	DWORD				curWorld;
	WORD				renderFrame;
	WORD				lightFrame;
	DWORD				pad;
	RwDevice			dOpenDevice;
	DWORD				field_48;
	DWORD				_cameraBeginUpdate;			// 1
	DWORD				_rgbToPixel;				// 2
	DWORD				_pixelToRgb;				// 3
	DWORD				_rasterCreate;				// 5
	DWORD				_rasterDestroy;				// 5
	DWORD				_getImageFromRaster;		// 6
	DWORD				_setRasterFromImage;		// 7
	DWORD				_textureSetRaster;			// 8
	DWORD				_findRasterFormat;			// 9
	DWORD				_cameraEndUpdate;			// 10
	DWORD				_setRasterContext;			// 11
	DWORD				_rasterSubraster;			// 12
	DWORD				_rasterClearRect;			// 13
	DWORD				_rasterClear;				// 14
	DWORD				_rasterLock;				// 15
	DWORD				_rasterUnlock;				// 16
	DWORD				_rasterRender;				// 17
	DWORD				_rasterRenderScaled;		// 18
	DWORD				_rasterRenderFast;			// 19
	DWORD				_rasterShowRaster;			// 20
	DWORD				_cameraClear;				// 21
	DWORD				_hintRenderF2B;				// 22
	DWORD				_rasterLockPalette;			// 23
	DWORD				_rasterUnlockPalette;		// 24
	DWORD				_nativeTextureGetSize;		// 25
	DWORD				_nativeTextureRead;			// 26
	DWORD				_nativeTextureWrite;		// 27
	DWORD				_rasterGetMipLevels;		// 28
	RwLinkList			dirtyFrameList;
	RwFileFunction		fileFuncs;
	RwStringFunctions	stringFuncs;
	RwMemoryFunctions	memoryFuncs;
	DWORD				memoryAlloc;
	DWORD				memoryFree;
	DWORD				metrics;
	DWORD				engineStatus;
	DWORD				resArenaSize;
};

#endif