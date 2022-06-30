#ifndef __CHUD
#define __CHUD

#define FUNC_ReloadSprites						0x5827D0
#define FUNC_CleanSprites						0x585940
#define FUNC_LoadHudTextures					0x5BA850

#define FUNC_DrawRadioName						0x4E9E50	// CMusicManager

#define FUNC_SetZoneName						0x588BB0
#define FUNC_SetHelpMessage						0x588BE0
#define FUNC_SetVehicleName						0x588F50
#define FUNC_SetBigMessage						0x588FC0

#define FUNC_PrintArmourForPlayer				0x5890A0
#define FUNC_PrintBreathForPlayer				0x589190
#define FUNC_PrintHealthForPlayer				0x589270
#define FUNC_DrawAmmo							0x5893B0
#define FUNC_DrawVitalStats						0x589650
#define FUNC_DrawRadar							0x58A330
#define FUNC_DrawAreaName						0x58AA50
#define FUNC_DrawVehicleName					0x58AEA0
#define FUNC_DrawHelpText						0x58B6E0
#define FUNC_DrawWeaponIcon						0x58D7D0
#define FUNC_DrawWantedLevel					0x58D9A0
#define FUNC_Draw								0x58FAE0

#define FUNC_CalcScreenCoors					0x70CE30	// CSprite
#define FUNC_DrawBox							0x727B60
#define FUNC_Draw2DPolygon						0x7285B0
#define FUNC_DrawBarChart						0x728640

#define VAR_CashTextFormat			 (char*)	0x866C94
#define VAR_DebtTextFormat			 (char*)	0x866C8C
#define VAR_EnableHud				*(char*)	0xA444A0
#define VAR_RadarGray				*(char*)	0xA444A4
#define VAR_FlashingHudTimer		*(DWORD*)	0xB7CB4C
#define VAR_UnkHudAlpha_BAA3E0		*(float*)	0xBAA3E0
#define VAR_UnkHudAlpha_BAA3E4		*(float*)	0xBAA3E4
#define VAR_DisableAreaText			*(char*)	0xBAA3F8
#define VAR_DisableCarNameText		*(char*)	0xBAA3F9
#define VAR_EnableStatusTexts		*(char*)	0xBAA3FA
#define VAR_DisableRadar			*(bool*)	0xBAA3FB
#define VAR_EnableClock				*(DWORD*)	0xBAA400
#define VAR_CarNameCurrent			*(char**)	0xBAA444
#define VAR_DrawCarNameStage		*(DWORD*)	0xBAA448
#define VAR_DrawCarNameFadeTime		*(int*)		0xBAA44C
#define VAR_DrawCarNameTime			*(DWORD*)	0xBAA450
#define VAR_CarNameOld				*(char**)	0xBAA454
#define VAR_CarName					*(char**)	0xBAA458
#define VAR_DrawZoneNameStage		*(DWORD*)	0xBAA930
#define VAR_DrawZoneNameFadeTime	*(int*)		0xBAA934
#define VAR_DrawZoneNameTime		*(DWORD*)	0xBAA938
#define VAR_PriorityText			(char*)		0xBAB040
#define VAR_BigText1				(char*)		0xBAACC0
#define VAR_BigText2				(char*)		0xBAAD40
#define VAR_BigText3				(char*)		0xBAADC0
#define VAR_BigText4				(char*)		0xBAAE40
#define VAR_BigText5				(char*)		0xBAAEC0
#define VAR_BigText6				(char*)		0xBAAF40
#define VAR_ZoneNameOld				*(char**)	0xBAB1D4
#define VAR_ZoneNamePtr				 (char**)	0xBAB1D8
#define VAR_ZoneName				*(char**)	0xBAB1D8
#define VAR_FlashingHudID			*(WORD*)	0xBAB1DC

#define VAR_RadarSpriteList			*(char***)		0x8D0720
#define VAR_RadarSprites			*(RwTexture***)	0xBAA250
#define VAR_CHud_HudTextures		*(RwTexture***)	0xBAB1FC

#define VAR_DisableHud				*(bool*)	0xC8A7C1

#define VAR_PlayerEnexEntryStage	*(int*)		0x96A7CC		// wrong

#define CHud_MAX_HUD_TEXTURES					6

class CHud
{
public:
	static void		ReloadSprites();
	static void		LoadHudTextures();
	static void		ReleaseTextures();
	static void		DrawBox(RwRect2D *dimensions, RwRGBA *rgba);
	static void		DrawBarChart(float fX,float fY,DWORD dwWidth,DWORD dwHeight,float fPercentage,DWORD dwForeColor,DWORD dwBorderColor);
	static void		Draw2DPolygon(float fX1,float fY1,float fX2,float fY2,float fX3,float fY3,float fX4,float fY4,DWORD dwColor);
};

#endif