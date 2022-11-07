// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

// Include basic multithread primitives.
#include "CryAtomics.h"
#include <Prey/CryCore/BitFiddling.h>

#define THREAD_NAME_LENGTH_MAX 64

enum CryLockType
{
	CRYLOCK_FAST      = 1,  //!< A fast potentially (non-recursive) mutex.
	CRYLOCK_RECURSIVE = 2,  //!< A recursive mutex.
};

#define CRYLOCK_HAVE_FASTLOCK 1

void CryThreadSetName(threadID nThreadId, const char* sThreadName);
const char* CryThreadGetName(threadID nThreadId);

//! Primitive locks and conditions.
//! Primitive locks are represented by instance of class CryLockT<Type>.
template<CryLockType Type> class CryLockT
{
	/* Unsupported lock type. */
};

//////////////////////////////////////////////////////////////////////////

void CryYieldThread();

//////////////////////////////////////////////////////////////////////////
// Typedefs.
//////////////////////////////////////////////////////////////////////////
typedef CryLockT<CRYLOCK_RECURSIVE> CryCriticalSection;
typedef CryLockT<CRYLOCK_FAST>      CryCriticalSectionNonRecursive;

//////////////////////////////////////////////////////////////////////////
//! CryAutoCriticalSection implements a helper class to automatically.
//! lock critical section in constructor and release on destructor.
template<class LockClass> class CryAutoLock
{
private:
	LockClass* m_pLock;

	CryAutoLock();
	CryAutoLock(const CryAutoLock<LockClass>&);
	CryAutoLock<LockClass>& operator=(const CryAutoLock<LockClass>&);

public:
	CryAutoLock(LockClass& Lock) : m_pLock(&Lock) { m_pLock->Lock(); }
	CryAutoLock(const LockClass& Lock) : m_pLock(const_cast<LockClass*>(&Lock)) { m_pLock->Lock(); }
	~CryAutoLock() { m_pLock->Unlock(); }
};

//! CryOptionalAutoLock implements a helper class to automatically.
//! Lock critical section (if needed) in constructor and release on destructor.
template<class LockClass> class CryOptionalAutoLock
{
private:
	LockClass* m_Lock;
	bool       m_bLockAcquired;

	CryOptionalAutoLock();
	CryOptionalAutoLock(const CryOptionalAutoLock<LockClass>&);
	CryOptionalAutoLock<LockClass>& operator=(const CryOptionalAutoLock<LockClass>&);

public:
	CryOptionalAutoLock(LockClass& Lock, bool acquireLock) : m_Lock(&Lock), m_bLockAcquired(false)
	{
		if (acquireLock)
		{
			Acquire();
		}
	}
	~CryOptionalAutoLock()
	{
		Release();
	}
	void Release()
	{
		if (m_bLockAcquired)
		{
			m_Lock->Unlock();
			m_bLockAcquired = false;
		}
	}
	void Acquire()
	{
		if (!m_bLockAcquired)
		{
			m_Lock->Lock();
			m_bLockAcquired = true;
		}
	}
};

//! CryAutoSet implements a helper class to automatically.
//! set and reset value in constructor and release on destructor.
template<class ValueClass> class CryAutoSet
{
private:
	ValueClass* m_pValue;

	CryAutoSet();
	CryAutoSet(const CryAutoSet<ValueClass>&);
	CryAutoSet<ValueClass>& operator=(const CryAutoSet<ValueClass>&);

public:
	CryAutoSet(ValueClass& value) : m_pValue(&value) { *m_pValue = (ValueClass)1; }
	~CryAutoSet() { *m_pValue = (ValueClass)0; }
};

//! Auto critical section is the most commonly used type of auto lock.
typedef CryAutoLock<CryCriticalSection>             CryAutoCriticalSection;
typedef CryAutoLock<CryCriticalSectionNonRecursive> CryAutoCriticalSectionNoRecursive;

#define AUTO_LOCK_T(Type, lock) PREFAST_SUPPRESS_WARNING(6246); CryAutoLock<Type> __AutoLock(lock)
#define AUTO_LOCK(lock)         AUTO_LOCK_T(CryCriticalSection, lock)
#define AUTO_LOCK_CS(csLock)    CryAutoCriticalSection __AL__ ## csLock(csLock)

/////////////////////////////////////////////////////////////////////////////
//
// Threads.

// Base class for runnable objects.
//
// A runnable is an object with a Run() and a Cancel() method.  The Run()
// method should perform the runnable's job.  The Cancel() method may be
// called by another thread requesting early termination of the Run() method.
// The runnable may ignore the Cancel() call, the default implementation of
// Cancel() does nothing.
class CryRunnable
{
public:
	virtual ~CryRunnable() { }
	virtual void Run() = 0;
	virtual void Cancel() { }
};

// Class holding information about a thread.
//
// A reference to the thread information can be obtained by calling GetInfo()
// on the CrySimpleThread (or derived class) instance.
//
// NOTE:
// If the code is compiled with NO_THREADINFO defined, then the GetInfo()
// method will return a reference to a static dummy instance of this
// structure.  It is currently undecided if NO_THREADINFO will be defined for
// release builds!
//
// PS3 NOTE: Make sure the same NO_THREADINFO setting is used on SPU and PPU.
// On SPU the 'm_Name' field is replaced by a dummy field.
struct CryThreadInfo
{
	// The symbolic name of the thread.
	//
	// You may set this name directly or through the SetName() method of
	// CrySimpleThread (or derived class).
	string m_Name;

	// A thread identification number.
	// The number is unique but architecture specific.  Do not assume anything
	// about that number except for being unique.
	//
	// This field is filled when the thread is started (i.e. before the Run()
	// method or thread routine is called).  It is advised that you do not
	// change this number manually.
	uint32 m_ID;
};

// Simple thread class.
//
// CrySimpleThread is a simple wrapper around a system thread providing
// nothing but system-level functionality of a thread.  There are two typical
// ways to use a simple thread:
//
// 1. Derive from the CrySimpleThread class and provide an implementation of
//    the Run() (and optionally Cancel()) methods.
// 2. Specify a runnable object when the thread is started.  The default
//    runnable type is CryRunnable.
//
// The Runnable class specfied as the template argument must provide Run()
// and Cancel() methods compatible with the following signatures:
//
//   void Runnable::Run();
//   void Runnable::Cancel();
//
// If the Runnable does not support cancellation, then the Cancel() method
// should do nothing.
//
// The same instance of CrySimpleThread may be used for multiple thread
// executions /in sequence/, i.e. it is valid to re-start the thread by
// calling Start() after the thread has been joined by calling WaitForThread().
template<class Runnable = CryRunnable> class CrySimpleThread;

// Standard thread class.
//
// The class provides a lock (mutex) and an associated condition variable.  If
// you don't need the lock, then you should used CrySimpleThread instead of
// CryThread.
template<class Runnable = CryRunnable> class CryThread;

///////////////////////////////////////////////////////////////////////////////
//! Base class for lockless Producer/Consumer queue, due platforms specific they are implemented in CryThead_platform.h.
namespace CryMT {
namespace detail {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class SingleProducerSingleConsumerQueueBase
{
public:
	SingleProducerSingleConsumerQueueBase()
	{}

	void Push(void* pObj, volatile uint32& rProducerIndex, volatile uint32& rConsumerIndex, uint32 nBufferSize, void* arrBuffer, uint32 nObjectSize);
	void Pop(void* pObj, volatile uint32& rProducerIndex, volatile uint32& rConsumerIndex, uint32 nBufferSize, void* arrBuffer, uint32 nObjectSize);
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class N_ProducerSingleConsumerQueueBase
{
public:
	N_ProducerSingleConsumerQueueBase()
	{
		CryInitializeSListHead(fallbackList);
	}

	void Push(void* pObj, volatile uint32& rProducerIndex, volatile uint32& rConsumerIndex, volatile uint32& rRunning, void* arrBuffer, uint32 nBufferSize, uint32 nObjectSize, volatile uint32* arrStates);
	bool Pop(void* pObj, volatile uint32& rProducerIndex, volatile uint32& rConsumerIndex, volatile uint32& rRunning, void* arrBuffer, uint32 nBufferSize, uint32 nObjectSize, volatile uint32* arrStates);

private:
	SLockFreeSingleLinkedListHeader fallbackList;
	struct SFallbackList
	{
		SLockFreeSingleLinkedListEntry nextEntry;
		char                           alignment_padding[128 - sizeof(SLockFreeSingleLinkedListEntry)];
		char                           object[1];         //!< Struct will be overallocated with enough memory for the object
	};
};

void CryMemoryBarrier();

} // namespace detail
} // namespace CryMT

// Include architecture specific code.
#if CRY_PLATFORM_WINAPI
	#include <Prey/CryThreading/CryThread_win32.h>
#elif CRY_PLATFORM_POSIX
	#include <CryThreading/CryThread_posix.h>
#else
// Put other platform specific includes here!
	#include <CryThreading/CryThread_dummy.h>
#endif

#if !defined _CRYTHREAD_CONDLOCK_GLITCH
typedef CryLockT<CRYLOCK_RECURSIVE> CryMutex;
#endif // !_CRYTHREAD_CONDLOCK_GLITCH

#if !defined _CRYTHREAD_HAVE_RWLOCK && !defined _CRYTHREAD_CONDLOCK_GLITCH
//! If the architecture specific code does not define a class CryRWLock, then
//! a default implementation is provided here.
class CryRWLock
{

	CryCriticalSection   m_lockExclusiveAccess;
	CryCriticalSection   m_lockSharedAccessComplete;
	CryConditionVariable m_condSharedAccessComplete;

	int                  m_nSharedAccessCount;
	int                  m_nCompletedSharedAccessCount;
	bool                 m_bExclusiveAccess;

	CryRWLock(const CryRWLock&);
	CryRWLock& operator=(const CryRWLock&);

	void       AdjustSharedAccessCount()
	{
		m_nSharedAccessCount -= m_nCompletedSharedAccessCount;
		m_nCompletedSharedAccessCount = 0;
	}

public:
	CryRWLock()
		: m_nSharedAccessCount(0),
		m_nCompletedSharedAccessCount(0),
		m_bExclusiveAccess(false)
	{}

	void RLock()
	{
		m_lockExclusiveAccess.Lock();
		if (++m_nSharedAccessCount == INT_MAX)
		{
			m_lockSharedAccessComplete.Lock();
			AdjustSharedAccessCount();
			m_lockSharedAccessComplete.Unlock();
		}
		m_lockExclusiveAccess.Unlock();
	}

	bool TryRLock()
	{
		if (!m_lockExclusiveAccess.TryLock())
			return false;
		if (++m_nSharedAccessCount == INT_MAX)
		{
			m_lockSharedAccessComplete.Lock();
			AdjustSharedAccessCount();
			m_lockSharedAccessComplete.Unlock();
		}
		m_lockExclusiveAccess.Unlock();
		return true;
	}

	void RUnlock()
	{
		Unlock();
	}

	void WLock()
	{
		m_lockExclusiveAccess.Lock();
		m_lockSharedAccessComplete.Lock();
		assert(!m_bExclusiveAccess);
		AdjustSharedAccessCount();
		if (m_nSharedAccessCount > 0)
		{
			m_nCompletedSharedAccessCount -= m_nSharedAccessCount;
			do
			{
				m_condSharedAccessComplete.Wait(m_lockSharedAccessComplete);
			}
			while (m_nCompletedSharedAccessCount < 0);
			m_nSharedAccessCount = 0;
		}
		m_bExclusiveAccess = true;
	}

	bool TryWLock()
	{
		if (!m_lockExclusiveAccess.TryLock())
			return false;
		if (!m_lockSharedAccessComplete.TryLock())
		{
			m_lockExclusiveAccess.Unlock();
			return false;
		}
		assert(!m_bExclusiveAccess);
		AdjustSharedAccessCount();
		if (m_nSharedAccessCount > 0)
		{
			m_lockSharedAccessComplete.Unlock();
			m_lockExclusiveAccess.Unlock();
			return false;
		}
		else
			m_bExclusiveAccess = true;
		return true;
	}

	void WUnlock()
	{
		Unlock();
	}

	void Unlock()
	{
		if (!m_bExclusiveAccess)
		{
			m_lockSharedAccessComplete.Lock();
			if (++m_nCompletedSharedAccessCount == 0)
				m_condSharedAccessComplete.NotifySingle();
			m_lockSharedAccessComplete.Unlock();
		}
		else
		{
			m_bExclusiveAccess = false;
			m_lockSharedAccessComplete.Unlock();
			m_lockExclusiveAccess.Unlock();
		}
	}
};
#endif // !defined _CRYTHREAD_HAVE_RWLOCK

//! Sync primitive for multiple reads and exclusive locking change access.
//! Useful in case if you have rarely modified object that needs
//! to be read quite often from different threads but still
//! need to be exclusively modified sometimes.
//! Debug functionality:.
//! Can be used for debug-only lock calls, which verify that no
//! simultaneous access is attempted.
//! Use the bDebug argument of LockRead or LockModify,
//! or use the DEBUG_READLOCK or DEBUG_MODIFYLOCK macros.
//! There is no overhead in release builds, if you use the macros,
//! and the lock definition is inside #ifdef _DEBUG.
class CryReadModifyLock
{
public:
	CryReadModifyLock()
		: m_modifyCount(0), m_readCount(0)
	{
		SetDebugLocked(false);
	}

	bool LockRead(bool bTry = false, cstr strDebug = 0, bool bDebug = false) const
	{
		if (!WriteLock(bTry, bDebug, strDebug))     // wait until write unlocked
			return false;
		CryInterlockedIncrement(&m_readCount);      // increment read counter
		m_writeLock.Unlock();
		return true;
	}
	void UnlockRead() const
	{
		SetDebugLocked(false);
		const int counter = CryInterlockedDecrement(&m_readCount);     // release read
		assert(counter >= 0);
		if (m_writeLock.TryLock())
			m_writeLock.Unlock();
		else if (counter == 0 && m_modifyCount)
			m_ReadReleased.Set();                     // signal the final read released
	}
	bool LockModify(bool bTry = false, cstr strDebug = 0, bool bDebug = false) const
	{
		if (!WriteLock(bTry, bDebug, strDebug))
			return false;
		CryInterlockedIncrement(&m_modifyCount);    // increment write counter (counter is for nested cases)
		while (m_readCount)
			m_ReadReleased.Wait();                    // wait for all threads finish read operation
		return true;
	}
	void UnlockModify() const
	{
		SetDebugLocked(false);
		int counter = CryInterlockedDecrement(&m_modifyCount);    // decrement write counter
		assert(counter >= 0);
		m_writeLock.Unlock();                       // release exclusive lock
	}

protected:
	mutable volatile int       m_readCount;
	mutable volatile int       m_modifyCount;
	mutable CryEvent           m_ReadReleased;
	mutable CryCriticalSection m_writeLock;
	mutable bool               m_debugLocked;
	mutable const char*        m_debugLockStr;

	void SetDebugLocked(bool b, const char* str = 0) const
	{
#ifdef _DEBUG
		m_debugLocked = b;
		m_debugLockStr = str;
#endif
	}

	bool WriteLock(bool bTry, bool bDebug, const char* strDebug) const
	{
		if (!m_writeLock.TryLock())
		{
#ifdef _DEBUG
			assert(!m_debugLocked);
			assert(!bDebug);
#endif
			if (bTry)
				return false;
			m_writeLock.Lock();
		}
#ifdef _DEBUG
		if (!m_readCount && !m_modifyCount)         // not yet locked
			SetDebugLocked(bDebug, strDebug);
#endif
		return true;
	}
};

//! Auto-locking classes.
template<class T, bool bDEBUG = false>
class AutoLockRead
{
protected:
	const T& m_lock;
public:
	AutoLockRead(const T& lock, cstr strDebug = 0)
		: m_lock(lock) { m_lock.LockRead(bDEBUG, strDebug, bDEBUG); }
	~AutoLockRead()
	{ m_lock.UnlockRead(); }
};

template<class T, bool bDEBUG = false>
class AutoLockModify
{
protected:
	const T& m_lock;
public:
	AutoLockModify(const T& lock, cstr strDebug = 0)
		: m_lock(lock) { m_lock.LockModify(bDEBUG, strDebug, bDEBUG); }
	~AutoLockModify()
	{ m_lock.UnlockModify(); }
};

#define AUTO_READLOCK(p)      PREFAST_SUPPRESS_WARNING(6246) AutoLockRead<CryReadModifyLock> __readlock ## __LINE__(p, __FUNC__)
#define AUTO_READLOCK_PROT(p) PREFAST_SUPPRESS_WARNING(6246) AutoLockRead<CryReadModifyLock> __readlock_prot ## __LINE__(p, __FUNC__)
#define AUTO_MODIFYLOCK(p)    PREFAST_SUPPRESS_WARNING(6246) AutoLockModify<CryReadModifyLock> __modifylock ## __LINE__(p, __FUNC__)

#if defined(_DEBUG)
	#define DEBUG_READLOCK(p)   AutoLockRead<CryReadModifyLock> __readlock ## __LINE__(p, __FUNC__)
	#define DEBUG_MODIFYLOCK(p) AutoLockModify<CryReadModifyLock> __modifylock ## __LINE__(p, __FUNC__)
#else
	#define DEBUG_READLOCK(p)
	#define DEBUG_MODIFYLOCK(p)
#endif

///////////////////////////////////////////////////////////////////////////////
//! Base class for lockless Producer/Consumer queue, due platforms specific they are implemented in CryThead_platform.h.
namespace CryMT {
namespace detail {

///////////////////////////////////////////////////////////////////////////////
inline void SingleProducerSingleConsumerQueueBase::Push(void* pObj, volatile uint32& rProducerIndex, volatile uint32& rConsumerIndex, uint32 nBufferSize, void* arrBuffer, uint32 nObjectSize)
{
	// spin if queue is full
	CSimpleThreadBackOff backoff;
	while (rProducerIndex - rConsumerIndex == nBufferSize)
	{
		backoff.backoff();
	}

	CryMemoryBarrier();
	char* pBuffer = alias_cast<char*>(arrBuffer);
	uint32 nIndex = rProducerIndex % nBufferSize;

	memcpy(pBuffer + (nIndex * nObjectSize), pObj, nObjectSize);
	CryMemoryBarrier();
	rProducerIndex += 1;
	CryMemoryBarrier();
}

///////////////////////////////////////////////////////////////////////////////
inline  void SingleProducerSingleConsumerQueueBase::Pop(void* pObj, volatile uint32& rProducerIndex, volatile uint32& rConsumerIndex, uint32 nBufferSize, void* arrBuffer, uint32 nObjectSize)
{
	CryMemoryBarrier();
	// busy-loop if queue is empty
	CSimpleThreadBackOff backoff;
	while (rProducerIndex - rConsumerIndex == 0)
	{
		backoff.backoff();
	}

	char* pBuffer = alias_cast<char*>(arrBuffer);
	uint32 nIndex = rConsumerIndex % nBufferSize;

	memcpy(pObj, pBuffer + (nIndex * nObjectSize), nObjectSize);
	CryMemoryBarrier();
	rConsumerIndex += 1;
	CryMemoryBarrier();
}

///////////////////////////////////////////////////////////////////////////////
inline  void N_ProducerSingleConsumerQueueBase::Push(void* pObj, volatile uint32& rProducerIndex, volatile uint32& rConsumerIndex, volatile uint32& rRunning, void* arrBuffer, uint32 nBufferSize, uint32 nObjectSize, volatile uint32* arrStates)
{
	CryMemoryBarrier();
	uint32 nProducerIndex;
	uint32 nConsumerIndex;

	int iter = 0;
	CSimpleThreadBackOff backoff;
	do
	{
		nProducerIndex = rProducerIndex;
		nConsumerIndex = rConsumerIndex;

		if (nProducerIndex - nConsumerIndex == nBufferSize)
		{
			if (iter++ > CSimpleThreadBackOff::kHardYieldInterval)
			{
				uint32 nSizeToAlloc = sizeof(SFallbackList) + nObjectSize - 1;
				SFallbackList* pFallbackEntry = (SFallbackList*)CryModuleMemalign(nSizeToAlloc, 128);
				memcpy(pFallbackEntry->object, pObj, nObjectSize);
				CryMemoryBarrier();
				CryInterlockedPushEntrySList(fallbackList, pFallbackEntry->nextEntry);
				return;
			}
			backoff.backoff();
			continue;
		}

		if (CryInterlockedCompareExchange(alias_cast<volatile LONG*>(&rProducerIndex), nProducerIndex + 1, nProducerIndex) == nProducerIndex)
			break;
	}
	while (true);

	CryMemoryBarrier();
	char* pBuffer = alias_cast<char*>(arrBuffer);
	uint32 nIndex = nProducerIndex % nBufferSize;

	memcpy(pBuffer + (nIndex * nObjectSize), pObj, nObjectSize);
	CryMemoryBarrier();
	arrStates[nIndex] = 1;
	CryMemoryBarrier();
}

///////////////////////////////////////////////////////////////////////////////
inline  bool N_ProducerSingleConsumerQueueBase::Pop(void* pObj, volatile uint32& rProducerIndex, volatile uint32& rConsumerIndex, volatile uint32& rRunning, void* arrBuffer, uint32 nBufferSize, uint32 nObjectSize, volatile uint32* arrStates)
{
	CryMemoryBarrier();

	// busy-loop if queue is empty
	CSimpleThreadBackOff backoff;
	if (rRunning && rProducerIndex - rConsumerIndex == 0)
	{
		while (rRunning && rProducerIndex - rConsumerIndex == 0)
		{
			backoff.backoff();
		}
	}

	if (rRunning == 0 && rProducerIndex - rConsumerIndex == 0)
	{
		SFallbackList* pFallback = (SFallbackList*)CryInterlockedPopEntrySList(fallbackList);
		IF (pFallback, 0)
		{
			memcpy(pObj, pFallback->object, nObjectSize);
			CryModuleMemalignFree(pFallback);
			return true;
		}
		// if the queue was empty, make sure we really are empty
		return false;
	}

	backoff.reset();
	while (arrStates[rConsumerIndex % nBufferSize] == 0)
	{
		backoff.backoff();
	}

	char* pBuffer = alias_cast<char*>(arrBuffer);
	uint32 nIndex = rConsumerIndex % nBufferSize;

	memcpy(pObj, pBuffer + (nIndex * nObjectSize), nObjectSize);
	CryMemoryBarrier();
	arrStates[nIndex] = 0;
	CryMemoryBarrier();
	rConsumerIndex += 1;
	CryMemoryBarrier();

	return true;
}

} // namespace detail
} // namespace CryMT

// Include all multithreading containers.
//#include "MultiThread_Containers.h"
