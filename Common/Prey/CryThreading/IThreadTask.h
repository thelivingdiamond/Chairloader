#pragma once
#include <Prey/CryCore/smartptr.h>

struct IThreadTask;
struct IThreadTask_Thread;

struct SThreadTaskParams
{
	unsigned int nFlags;
	
	union
	{
		int nPreferedThread;
		int nThreadsGroupId;
	};

	int16 nPriorityOff;
	int16 nStackSizeKB;
	const char *name;
};

struct SThreadTaskInfo : CMultiThreadRefCount
{
	IThreadTask_Thread *m_pThread;
	IThreadTask *m_pTask;
	SThreadTaskParams m_params;
};

struct IThreadTask
{
	virtual void OnUpdate() = 0;
	virtual void Stop() = 0;
	virtual SThreadTaskInfo *GetTaskInfo() = 0;
	virtual ~IThreadTask() = 0;
};

struct IThreadTask_Thread
{
	virtual ~IThreadTask_Thread() = 0;
	virtual void AddTask(SThreadTaskInfo &task) = 0;
	virtual void RemoveTask(SThreadTaskInfo &task) = 0;
	virtual void RemoveAllTasks() = 0;
	virtual void SingleUpdate() = 0;
};
