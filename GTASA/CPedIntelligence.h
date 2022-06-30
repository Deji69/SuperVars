#ifndef __CPEDINTELLIGENCE
#define __CPEDINTELLIGENCE

#include "CTask.h"

#define FUNC_GetPedGunTask							0x600F70
#define FUNC_SetTask								0x681AF0
#define FUNC_GetActiveTask              			0x681720
#define FUNC_GetSimplestActiveTask      			0x6819D0
//#define FUNC_GetSimplestTask          			0x681970 // static
#define FUNC_GetSimplestTask            			0x681A00
#define FUNC_FindActiveTaskByType       			0x681740
#define FUNC_FindTaskByType             			0x6817D0
#define FUNC_SetTaskSecondary           			0x681B60
#define FUNC_ClearTaskEventResponse     			0x681BD0
#define FUNC_HasTaskSecondary           			0x681820

enum 
{
    TASK_PRIORITY_PHYSICAL_RESPONSE=0,
    TASK_PRIORITY_EVENT_RESPONSE_TEMP,
    TASK_PRIORITY_EVENT_RESPONSE_NONTEMP,
    TASK_PRIORITY_PRIMARY,
    TASK_PRIORITY_DEFAULT,
    TASK_PRIORITY_MAX
};

enum
{
    TASK_SECONDARY_ATTACK=0,                // want duck to be after attack
    TASK_SECONDARY_DUCK,                    // because attack controls ducking movement
    TASK_SECONDARY_SAY,
    TASK_SECONDARY_FACIAL_COMPLEX,
    TASK_SECONDARY_PARTIAL_ANIM,
    TASK_SECONDARY_IK,
    TASK_SECONDARY_MAX
};

enum
{
    ABORT_PRIORITY_LEISURE=0,
    ABORT_PRIORITY_URGENT,
    ABORT_PRIORITY_IMMEDIATE
};

class CPed;

class CTaskManager
{
public:
	CTask	*	tasks[TASK_PRIORITY_MAX];
	CTask	*	tasksSecondary[TASK_SECONDARY_MAX];
	CPed	*	pPed;

	CTask	*	GetSimplestActiveTask();
};

class CPedIntelligence
{
public:
	CPed		*	pPed;
	CTaskManager	pedTasks;
	char			pad[0x25C];

	CTask		*	GetGunTask();
};

#endif