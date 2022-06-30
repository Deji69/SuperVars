#ifndef __CTASK
#define __CTASK

class TaskVTBL
{
public:
    DWORD DeletingDestructor;
    DWORD Clone;
    DWORD GetSubTask;
    DWORD IsSimpleTask;
    DWORD GetTaskType;
    DWORD StopTimer;
    DWORD MakeAbortable;
};

class TaskSimpleVTBL : public TaskVTBL
{
public:
    DWORD ProcessPed;
    DWORD SetPedPosition;
};

class TaskComplexVTBL : public TaskVTBL
{
public:
    DWORD SetSubTask; 
    DWORD CreateNextSubTask;
    DWORD CreateFirstSubTask;
    DWORD ControlSubTask;
};

class CTask
{
public:
	TaskVTBL	*	VTBL; // cast to either TaskSimpleVTBL or TaskComplexVTBL
    CTask		*	m_pParent;

	bool			IsSimpleTask(void);
	int				GetTaskType(void);
};

#endif