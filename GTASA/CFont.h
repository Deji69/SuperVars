#ifndef __CFONT
#define __CFONT

#define FUNC_SetTextLetterSize							0x719380
#define FUNC_SetTextLetterSizeWithLanguageScaling		0x7193A0
#define FUNC_SetTextResetSlantedTextPos					0x719400
#define FUNC_SetTextColour								0x719430
#define FUNC_SetTextFont								0x719490
#define FUNC_SetTextWrapX								0x7194F0
#define FUNC_SetTextBorderRGBA							0x719510
#define FUNC_SetTextShadow								0x719570
#define FUNC_SetTextOutline								0x719590
#define FUNC_SetTextUseProportionalValues				0x7195B0
#define FUNC_SetTextBackground							0x7195C0
#define FUNC_SetTextJustify								0x719600
#define FUNC_SetTextAlignment							0x719610
#define FUNC_PrintString								0x71A700
#define FUNC_UnkPrintString								0x71A820

#define VAR_TextUseBackground					*(bool*)	0xC71A7B
#define VAR_TextBackgroundType					*(bool*)	0xC71A7C
#define VAR_TextUseProportionalValues			*(bool*)	0xC71A7D
#define VAR_TextAlpha							*(float*)	0xC71A80
#define VAR_TextUseFont							*(char*)	0xC71A94
#define VAR_TextFont							*(char*)	0xC71A95
#define VAR_TextShadow							*(char*)	0xC71A96
#define VAR_TextOutline							*(char*)	0xC71A9B
#define VAR_TextOutline2						*(char*)	0xC71A9C
#define VAR_TextLetterSizeX						*(float*)	0xC71A64
#define VAR_TextLetterSizeY						*(float*)	0xC71A68
#define VAR_TextWrapX							*(float*)	0xC71A8C

class CFont
{
public:
	static void			PrintString(float fX,float fY,char *szString);
	static void			UnkPrintString(float fX,float fY,char *szString);
	static void			SetTextAlignment(char bAlignment);
	static void			SetTextAlpha(float fAlpha);
	static void			SetTextBackground(bool bEnable, bool bType);
	static void			SetTextBorderRGBA(DWORD dwColour);
	static void			SetTextColour(DWORD dwColour);
	static void			SetTextFont(char bFont);
	static void			SetTextLetterSize(float fX, float fY);
	static void			SetTextLetterSizeWithLanguageScaling(float fX, float fY);
	static void			SetTextShadow(char bWidth);
	static void			SetTextOutline(char bWidth);
	static void			SetTextUseProportionalValues(bool bEnable);
	static void			SetTextWrapX(float fWrapX);
	static void			Reset();
};

#endif