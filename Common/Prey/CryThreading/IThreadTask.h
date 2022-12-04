#pragma once
#include <Prey/CryCore/smartptr.h>

typedef int	ThreadPoolHandle;

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

// Might be changed to uint64 etc in the future
typedef uint32 ThreadPoolAffinityMask;
#define INVALID_AFFINITY 0

//////////////////////////////////////////////////////////////////////////
// Description of thread pool to create
//////////////////////////////////////////////////////////////////////////
struct ThreadPoolDesc
{
	ThreadPoolAffinityMask	AffinityMask;		// number of bits means number of threads. affinity overlapping is prohibited
	string					sPoolName;
	int32					nThreadPriority;
	int32					nThreadStackSizeKB;

	ThreadPoolDesc() : AffinityMask(INVALID_AFFINITY), sPoolName("UnnamedPool"), nThreadPriority(-1), nThreadStackSizeKB(-1) { }

	ILINE bool CreateThread(ThreadPoolAffinityMask affinityMask)
	{
		if (this->AffinityMask & affinityMask)
			return false;

		this->AffinityMask |= affinityMask;
		return true;
	}

	ILINE uint32 GetThreadCount() const
	{
		return CountBits(AffinityMask);
	}
};

//////////////////////////////////////////////////////////////////////////
// Task manager.
//////////////////////////////////////////////////////////////////////////
struct IThreadTaskManager
{
	// <interfuscator:shuffle>
	virtual ~IThreadTaskManager() {}
	// Register new task to the manager.
	virtual void RegisterTask(IThreadTask* pTask, const SThreadTaskParams& options) = 0;
	virtual void UnregisterTask(IThreadTask* pTask) = 0;

	// Limit number of threads to this amount.
	virtual void SetMaxThreadCount(int nMaxThreads) = 0;

	// Create a pool of threads
	virtual ThreadPoolHandle CreateThreadsPool(const ThreadPoolDesc& desc) = 0;
	virtual const bool DestroyThreadsPool(const ThreadPoolHandle& handle) = 0;
	virtual const bool GetThreadsPoolDesc(const ThreadPoolHandle handle, ThreadPoolDesc* pDesc) const = 0;
	virtual const bool SetThreadsPoolAffinity(const ThreadPoolHandle handle, const ThreadPoolAffinityMask AffinityMask) = 0;

	virtual void SetThreadName(threadID dwThreadId, const char* sThreadName) = 0;
	virtual const char* GetThreadName(threadID dwThreadId) = 0;

	// Return thread handle by thread name
	virtual threadID GetThreadByName(const char* sThreadName) = 0;

	// if bMark=true the calling thread will dump its stack during crashes
	virtual void MarkThisThreadForDebugging(const char* name, bool bDump) = 0;
	// </interfuscator:shuffle>
};
