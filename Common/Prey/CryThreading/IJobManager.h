#pragma once
#include <functional>

class CTimeValue;

namespace JobManager {

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
struct SJobFinishedConditionVariable;

class IJobManager
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

}