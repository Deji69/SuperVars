#ifndef __CTEXT
#define __CTEXT

#define CLASS_CText								(CText *)		0xC1B340

#define FUNC_GetTextFromEntry					0x6A0050

class CText
{
public:
	char	*	GetTextFromEntry(char*);
};

//char*(__thiscall *GetTextFromEntry)(void*,char*) = (char*(__thiscall*)(void*,char*))0x6A0050;
//void (*SetTextBackground)(BYTE,BYTE) = (void(*)(BYTE,BYTE))0x7195C0;
//void (*SetTextLetterSize)(float,float) = (void(*)(float,float))0x719380;
//void (*SetTextUseProportionalValues)(BYTE) = (void(*)(BYTE))0x7195B0;
//void (*SetTextFont)(BYTE) = (void(*)(BYTE))0x719490;
//void (*SetTextAlignment)(BYTE) = (void(*)(BYTE))0x719610;
//void (*SetTextUnknown_7194F0)(DWORD) = (void(*)(DWORD))0x7194F0;
//void (*SetTextOutline)(BYTE) = (void(*)(BYTE))0x719590;
//void (*SetBorderEffectRGBA)(DWORD) = (void(*)(DWORD))0x719510;
//void (*SetTextShadow)(BYTE) = (void(*)(BYTE))0x719570;
//void (*SetTextColour)(DWORD) = (void(*)(DWORD))0x719430;
//void (*DrawTextAt)(float,float,char*) = (void(*)(FLOAT,FLOAT,char*))0x71A700;

#endif