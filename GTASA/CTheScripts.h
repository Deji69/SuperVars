#ifndef __CTHESCRIPTS
#define __CTHESCRIPTS

#include "CGame.h"

#define FUNC_GetNumberParams									0x464080
#define FUNC_SetNumberParams									0x464370
#define FUNC_RemoveFromQueue									0x464BD0
#define FUNC_AddToQueue											0x464C00
#define FUNC_NewScript											0x464C20
#define FUNC_FindScriptByScmIndex								0x470810
#define FUNC_EndThread											0x465AA0
#define FUNC_GetStringParam										0x463D50
#define FUNC_AddBriefEntry										0x69DD50
#define FUNC_GetTextFromEntry									0x6A0050

#define VAR_CommandParameters			(int*)					0xA43C78
#define INT_CommandParameters									0xA43C78
#define VAR_CleanupNeedsToRestorePlay	*(char*)				0xA4448A
#define VAR_CommandsExecuted			*(WORD*)				0xA447F4
#define VAR_MissionLocals				(int*)					0xA48960
#define INT_MissionLocals										0xA48960
#define VAR_ScmBlock					(char*)					0xA49960
#define INT_ScmBlock											0xA49960
#define VAR_InactiveThreadQueue			 (CRunningScript **)	0xA8B428
#define VAR_ActiveThreadQueue			 (CRunningScript **)	0xA8B42C
#define VAR_ExternalScripts				 (CExternalScripts *)	0xA47B60

union SCRIPT_VAR
{
	DWORD	dwParam;
	WORD	wParam;
	BYTE	bParam;
	float	fParam;
	void*	pParam;
	char*	pcParam;
};

enum eDataType			// TODO: completely change, one day
{
	DATA_TYPE_DWORD = 1,
	DATA_TYPE_GVAR,
	DATA_TYPE_LVAR,
	DATA_TYPE_BYTE,
	DATA_TYPE_WORD,
	DATA_TYPE_FLOAT,
	DATA_TYPE_GARRAY,
	DATA_TYPE_LARRAY,
	DATA_TYPE_STRING,
	DATA_TYPE_GSTRINGVAR,
	DATA_TYPE_LSTRINGVAR,
	DATA_TYPE_GSTRINGARRAY,
	DATA_TYPE_LSTRINGARRAY,
	DATA_TYPE_VARLENSTRING,
	DATA_TYPE_LONGSTRING,		// (the 16 byte ones)
	DATA_TYPE_GVARLENSTRING,
	DATA_TYPE_LVARLENSTRING,
	DATA_TYPE_GVARLENSTRINGARRAY,		// ugly long capitalised names :)
	DATA_TYPE_LVARLENSTRINGARRAY
};

class CRunningScript;
class CExternalScripts;
class CExternalScriptInfo;

class CTheScripts
{
protected:
	static	CExternalScripts	*	externalScripts;
	static	int					*	commandParams;
	static	int					*	missionLocals;
	static	char				*	scmBlock;

public:
	CTheScripts();

	static	CRunningScript		*	New(void *ip);

	inline	CExternalScripts	*	GetExternalScripts()					{return externalScripts;};
	inline	int					*	GetCommandParamPointer(int i=0)			{return &commandParams[i];};
	inline	int						GetCommandParamInt(int i=0)				{return commandParams[i];};
	inline	bool					IsCommandParamSet(int i=0)				{return commandParams[i] != 0;};
	inline	int						GetMissionLocal(int i=0)				{return missionLocals[i];};
	inline	int					*	GetMissionLocalPtr(int i=0)				{return &missionLocals[i];};
	inline	char				*	GetScmBlock()							{return scmBlock;};
	inline	int						GetGlobalVarVal(int i)					{return *(int*)&scmBlock[i];};
	inline	void					SetCommandParamInt(int i, int v)		{commandParams[i] = v;};
	inline	void					SetCommandParamFloat(int i, float v)	{*(float*)&commandParams[i] = v;};
	static	void					AddBriefEntry(char *pStr);
};

class CRunningScript : public CTheScripts
{
protected:
	CRunningScript *Previous;			// +0x0
	CRunningScript *Next;				// +0x4
	char Name[8];						// +0x8
	void *BaseIP;						// +0x10
	BYTE *CurrentIP;					// +0x14
	DWORD Stack[8];						// +0x18
	WORD SP;							// +0x38
	SCRIPT_VAR LocalVar[34];			// +0x3C
	BYTE bIsActive;						// +0xC4
	BYTE bCondResult;					// +0xC5
	BYTE bUseMissionCleanup;			// +0xC6
	BYTE bIsExternal;					// +0xC7
	BYTE bTextBlockOverride;			// +0xC8
	BYTE bExternalType;					// +0xC9
	DWORD WakeTime;						// +0xCC
	WORD LogicalOp;						// +0xD0
	BYTE NotFlag;						// +0xD2
	BYTE bWastedBustedCheck;			// +0xD3
	BYTE bWastedOrBusted;				// +0xD4
	void *SceneSkipIP;					// +0xD8
	BYTE bIsMission;					// +0xDC

public:
	inline	char				IsActive()							{return bIsActive;};
	inline	char				IsExternal()						{return bIsExternal;};
	inline	char				IsMission()							{return bIsMission;};
	inline	char			*	GetBasePointer()					{return (char*)BaseIP;};
	inline	char			*	GetLabelPointer(int label)			{return (char*)BaseIP - label;};
	inline	char			*	GetBytePointer(int offset=0)		{return (char*)&CurrentIP[offset];};
	inline	void				SetIp(void *ip)						{CurrentIP = (BYTE*)ip;};
	inline	void				SetBaseIp(void *ip)					{BaseIP = ip;};
	inline	CRunningScript	*	GetNext()							{return Next;};
	inline	CRunningScript	*	GetPrev()							{return Previous;};
	inline	void				SetIsExternal(bool b)				{bIsExternal = b;};
	inline	void				SetActive(bool b)					{bIsActive = b;};
	inline	void				SetNext(CRunningScript *v)			{Next = v;};
	inline	void				SetPrev(CRunningScript *v)			{Previous = v;};
	inline	int				*	GetIntVarPtr(int i)					{return (int*)&LocalVar[i].dwParam;};
	inline	int					GetIntVar(int i)					{return LocalVar[i].dwParam;};
	inline	void				SetIntVar(int i, int v)				{LocalVar[i].dwParam = v;};
	inline	void				SetFloatVar(int i, float v)			{LocalVar[i].fParam = v;};
	inline	char				GetByteVar(int i)					{return LocalVar[i].bParam;};
	inline	bool				GetConditionResult()				{return bCondResult != 0;};

	inline	int			GetLocalVarVal(int i)	{return IsMission() ? GetMissionLocal(i) : GetIntVar(i);};
	inline	int		*	GetLocalVarPtr(int i)	{return IsMission() ? GetMissionLocalPtr(i) : GetIntVarPtr(i);};

	inline	char		ReadDataType()								{return ReadDataByte();};
	inline	short		ReadDataVarIndex()							{return ReadDataWord();};
	inline	short		ReadDataArrayOffset()						{return ReadDataWord();};
	inline	short		ReadDataArrayIndex()						{return ReadDataWord();};
	inline	char		ReadDataArraySize()							{return ReadDataByte();};
	inline	char		ReadDataArrayFlags()						{return ReadDataByte();};

	inline	int			ReadDataGlobalIntVal()
	{
		short i = ReadDataVarIndex();
		return GetGlobalVarVal(i);
	};

	inline	int			ReadDataLocalIntVal()
	{
		short i = ReadDataVarIndex();
		return IsMission() ? GetMissionLocal(i) : GetIntVar(i);
	};

	inline	int			ReadDataGlobalArrayIntVal()
	{
		short	offset	= ReadDataArrayOffset(),
				index	= ReadDataArrayIndex(),
				size	= ReadDataArraySize(),
				flags	= ReadDataArrayFlags(),
				indexVal;
		
		if(flags >= 0x80) indexVal = GetLocalVarVal(index);
		else indexVal = GetGlobalVarVal(index);

		return GetGlobalVarVal(indexVal + offset);
	};

	inline	int			ReadDataLocalArrayIntVal()
	{
		short	offset	= ReadDataArrayOffset(),
				index	= ReadDataArrayIndex(),
				size	= ReadDataArraySize(),
				flags	= ReadDataArrayFlags(),
				indexVal;
		
		if(flags >= 0x80) indexVal = GetLocalVarVal(index);
		else indexVal = GetGlobalVarVal(index);

		return GetLocalVarVal(indexVal + offset);
	};

	inline	int			ReadDataByte()
	{
		char b = *CurrentIP;
		++CurrentIP;
		return b;
	};

	inline	short		ReadDataWord()
	{
		short v = *(short*)CurrentIP;
		CurrentIP += 2;
		return v;
	};

	inline	int			ReadDataInt()
	{
		int i = *(int*)CurrentIP;
		CurrentIP += 4;
		return i;
	};

	void						Start();
	void						CollectParameters(WORD numParams);
	char					*	GetStringParam(char *pOut, DWORD dwSize);
	void						SetNumberParams(WORD numParams);
	void						SetConditionResult(BYTE result);
	void						End();
};

class CExternalScriptInfo
{
public:
	void *data;
	BYTE numScriptsRunning;
	BYTE _f5;
	WORD wScmIndex;
	char name[20];
	DWORD size;
};

class CExternalScripts
{
public:
	CExternalScriptInfo scripts[82];
	DWORD _fA40;
	WORD _loadedScripts;

	static	bool				LoadScript(int script);
	CRunningScript			*	StartScript(int script);
};

#endif