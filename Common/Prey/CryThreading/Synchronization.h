// From CryEngine 5.2 CryCommon/CryThreading/Synchronization.h (include path adjusted).
// Synchronization policies (stl::PSyncNone / stl::PSyncMultiThread) used as template arguments by
// containers and allocators such as stl::HeapAllocator / stl::PoolAllocator.
#pragma once

#include <Prey/CryThreading/CryAtomics.h>

namespace stl
{
template<class Sync>
struct AutoLock
{
	ILINE AutoLock(Sync& sync)
		: _sync(sync)
	{
		sync.Lock();
	}
	ILINE ~AutoLock()
	{
		_sync.Unlock();
	}

private:
	Sync& _sync;
};

struct PSyncNone
{
	void Lock()   {}
	void Unlock() {}
};

struct PSyncMultiThread
{
	PSyncMultiThread()
		: _Semaphore(0) {}

	void Lock()
	{
		CryWriteLock(&_Semaphore);
	}
	void Unlock()
	{
		CryReleaseWriteLock(&_Semaphore);
	}
	int IsLocked() const volatile
	{
		return _Semaphore;
	}

private:
	volatile int _Semaphore;
};

#ifdef _DEBUG

struct PSyncDebug : public PSyncMultiThread
{
	void Lock()
	{
		assert(!IsLocked());
		PSyncMultiThread::Lock();
	}
};

#else

typedef PSyncNone PSyncDebug;

#endif

}
