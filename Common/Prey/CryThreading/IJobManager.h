#pragma once
#include <functional>
#include <Prey/CryThreading/CryThread.h>

class CTimeValue;

//! Implementation of mutex/condition variable.
//! Used in the job manager for yield waiting in corner cases like waiting for a job to finish/jobqueue full and so on.
class SJobFinishedConditionVariable
{
public:
	SJobFinishedConditionVariable() :
		m_nRefCounter(0),
		m_pOwner(NULL) {
		m_nFinished = 1;
	}

	void Acquire() {
		//wait for completion of the condition
		m_Notify.Lock();
		while (m_nFinished == 0)
			m_CondNotify.Wait(m_Notify);
		m_Notify.Unlock();
	}

	void Release() {
		m_Notify.Lock();
		m_nFinished = 1;
		m_CondNotify.Notify();
		m_Notify.Unlock();
	}

	void SetRunning() {
		m_nFinished = 0;
	}

	bool IsRunning() {
		return m_nFinished == 0;
	}

	void SetStopped() {
		m_nFinished = 1;
	}

	void SetOwner(volatile const void *pOwner) {
		if (m_pOwner != NULL)
			__debugbreak();
		m_pOwner = pOwner;
	}

	void ClearOwner(volatile const void *pOwner) {
		if (m_pOwner != pOwner)
			__debugbreak();

		m_pOwner = NULL;
	}

	bool AddRef(volatile const void *pOwner) {
		if (m_pOwner != pOwner)
			return false;

		++m_nRefCounter;
		return true;
	}
	uint32 DecRef(volatile const void *pOwner) {
		if (m_pOwner != pOwner)
			__debugbreak();

		return --m_nRefCounter;
	}

	bool HasOwner() const { return m_pOwner != NULL; }

private:
	CryConditionVariable::LockType m_Notify;
	CryConditionVariable m_CondNotify;
	volatile uint32      m_nFinished;
	volatile uint32      m_nRefCounter;
	volatile const void *m_pOwner;
};

namespace JobManager {

//! Type to reprensent a semaphore handle of the jobmanager.
typedef uint16 TSemaphoreHandle;

enum EBackEndType
{
	eBET_Thread = 0x0,
	eBET_Fallback = 0x1,
	eBET_Blocking = 0x2,
};

enum TPriorityLevel
{
	eHighPriority = 0x0,
	eRegularPriority = 0x1,
	eLowPriority = 0x2,
	eStreamPriority = 0x3,
	eNumPriorityLevel = 0x4,
};

class IBackend;
class CJobDelegator;
struct SJobStringHandle;
struct SJobState;
struct SJobProfilingData;
class CJobBase;

//! Special combination of a volatile spinning variable combined with a semaphore.
//! Used if the running state is not yet set to finish during waiting.
struct SJobSyncVariable
{
	SJobSyncVariable();

	bool IsRunning() const volatile;

	//! Interface, should only be used by the job manager or the job state classes.
	void Wait() volatile;
	void SetRunning() volatile;
	bool SetStopped(struct SJobStateBase *pPostCallback = nullptr) volatile;

private:
	friend class CJobManager;

	//! Union used to combine the semaphore and the running state in a single word.
	union SyncVar
	{
		volatile uint32 wordValue;
		struct
		{
			uint16           nRunningCounter;
			TSemaphoreHandle semaphoreHandle;
		};
	};

	SyncVar syncVar;      //!< Sync-variable which contain the running state or the used semaphore.
	char    padding[4];
};

//! Condition variable like struct to be used for polling if a job has been finished.
struct SJobStateBase
{
public:
	ILINE bool IsRunning() const { return syncVar.IsRunning(); }
	ILINE void SetRunning() {
		syncVar.SetRunning();
	}
	virtual bool SetStopped() {
		return syncVar.SetStopped(this);
	}
	virtual void AddPostJob() {};

	virtual ~SJobStateBase() {}

private:
	friend class CJobManager;

	JobManager::SJobSyncVariable syncVar;
};

//! For speed, use 16 byte aligned job state.
struct CRY_ALIGN(16) SJobState : SJobStateBase
{
	//! When profiling, intercept the SetRunning() and SetStopped() functions for profiling informations.
	ILINE SJobState()
		: m_pFollowUpJob(NULL)
#if defined(JOBMANAGER_SUPPORT_PROFILING)
		, nProfilerIndex(~0)
#endif
	{
	}

	ILINE void SetRunning();

	virtual void AddPostJob() override;

	ILINE void RegisterPostJob(CJobBase * pFollowUpJob) { m_pFollowUpJob = pFollowUpJob; }

	// Non blocking trying to stop state, and run post job.
	ILINE bool TryStopping()
	{
		if (IsRunning())
		{
			return SetStopped();
		}
		return true;
	}

	ILINE const bool Wait();

#if defined(JOBMANAGER_SUPPORT_PROFILING)
	uint16 nProfilerIndex;
#endif

	CJobBase* m_pFollowUpJob;
};

struct SJobStateLambda : public SJobState
{
	void RegisterPostJobCallback(const char* postJobName, const std::function<void()>& lambda, TPriorityLevel priority = eRegularPriority, SJobState* pJobState = 0)
	{
		m_callbackJobName = postJobName;
		m_callbackJobPriority = priority;
		m_callbackJobState = pJobState;
		m_callback = lambda;
	}
private:
	virtual void AddPostJob() override;
private:
	const char* m_callbackJobName;
	SJobState* m_callbackJobState;
	std::function<void()>          m_callback;
	TPriorityLevel                 m_callbackJobPriority;
	CryCriticalSectionNonRecursive m_stopLock;
};

struct IJobManager
{
public:
	static constexpr size_t VTBL_PushProfilingMarker = 17;
	static constexpr size_t VTBL_PopProfilingMarker = 18;

	virtual ~IJobManager() = 0;
	virtual void Init(unsigned int) = 0;
	virtual void AddJob(CJobDelegator *, SJobStringHandle *const) = 0;
	virtual void AddLambdaJob(const char *, const std::function<void __cdecl(void)> *, TPriorityLevel, SJobState *) = 0;
	virtual bool WaitForJob(SJobState *) = 0;
	virtual SJobStringHandle *GetJobHandle(const char *, void(void *)) = 0;
	virtual SJobStringHandle *GetJobHandle(const char *, const unsigned int, void(void *)) = 0;
	virtual void ShutDown() = 0;
	virtual IBackend *GetBackEnd(EBackEndType) = 0;
	virtual bool InvokeAsJob(SJobStringHandle *const) = 0;
	virtual bool InvokeAsJob(const char *) = 0;
	virtual void SetJobFilter(const char *) = 0;
	virtual void SetJobSystemEnabled(int) = 0;
	virtual unsigned int GetWorkerThreadId() = 0;
	virtual SJobProfilingData *GetProfilingData(unsigned __int16) = 0;
	virtual unsigned __int16 ReserveProfilingData() = 0;
	virtual void Update(int) = 0;
	virtual void PushProfilingMarker(const char *) = 0;
	virtual void PopProfilingMarker() = 0;
	virtual unsigned int GetNumWorkerThreads() = 0;
	virtual unsigned __int16 AllocateSemaphore(const volatile void *) = 0;
	virtual void DeallocateSemaphore(unsigned __int16, const volatile void *) = 0;
	virtual bool AddRefSemaphore(unsigned __int16, const volatile void *) = 0;
	virtual SJobFinishedConditionVariable *GetSemaphore(unsigned __int16, const volatile void *) = 0;
	virtual void DumpJobList() = 0;
	virtual void SetFrameStartTime(const CTimeValue *) = 0;
};

} // namespace JobManager