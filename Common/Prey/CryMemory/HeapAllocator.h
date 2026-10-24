// Based on CryEngine 5.2 CryCommon/CryMemory/HeapAllocator.h. Prey's FHeap has only PageSize /
// SinglePage / FreeWhenEmpty and there is no _pFreeList; the stack-dealloc options and helpers were dropped.
// Layout: sizeof(FHeap) == 16, sizeof(HeapAllocator<PSyncNone>) == 48.
#pragma once

#include <new>
#include <cstdlib>
#include <Prey/CryThreading/Synchronization.h>
#include <Prey/CryParticleSystem/Options.h>
#include <Prey/CryCore/MetaUtils.h>

namespace stl
{
class HeapSysAllocator
{
public:
	static void* SysAlloc(size_t nSize)
	{ return malloc(nSize); }
	static void  SysDealloc(void* ptr)
	{ free(ptr); }
};

class GlobalHeapSysAllocator
{
public:
	static void* SysAlloc(size_t nSize)
	{
		return malloc(nSize);
	}
	static void SysDealloc(void* ptr)
	{
		free(ptr);
	}
};

//! Round up to next multiple of nAlign. Handles any positive integer.
inline size_t RoundUpTo(size_t nSize, size_t nAlign)
{
	assert(nAlign > 0);
	nSize += nAlign - 1;
	return nSize - nSize % nAlign;
}

/*---------------------------------------------------------------------------
   HeapAllocator
   A memory pool that can allocate arbitrary amounts of memory of arbitrary size
   and alignment. The heap may be freed all at once. Individual block deallocation
   is not provided.

   Allocation details: Maintains a linked list of pages.
   All pages after first are in order of most free memory first.
   Allocations are from the smallest free page available.
   ---------------------------------------------------------------------------*/

struct SMemoryUsage
{
	size_t nAlloc, nUsed;

	SMemoryUsage(size_t _nAlloc = 0, size_t _nUsed = 0)
		: nAlloc(_nAlloc), nUsed(_nUsed)
	{
		Validate();
	}

	size_t nFree() const
	{
		return nAlloc - nUsed;
	}
	void Validate() const
	{
		assert(nUsed <= nAlloc);
	}
	void Clear()
	{
		nAlloc = nUsed = 0;
	}

	void operator+=(SMemoryUsage const& op)
	{
		nAlloc += op.nAlloc;
		nUsed += op.nUsed;
	}
};

//////////////////////////////////////////////////////////////////////////
struct FHeap
{
	OPT_STRUCT(FHeap)
	OPT_VAR_INIT(size_t, PageSize, 0x1000); //!< Pages allocated at this size, or multiple thereof if needed
	OPT_VAR(bool, SinglePage)               //!< Only 1 page allowed (fixed alloc)
	OPT_VAR(bool, FreeWhenEmpty)            //!< Release all memory when no longer used
};

// The system allocator is a type parameter (HeapSysAllocator in every game instantiation).
// Both allocators are plain malloc/free here.
template<typename L = PSyncMultiThread, typename A = HeapSysAllocator>
class HeapAllocator : public FHeap, public L, public A
{
public:

	typedef AutoLock<L> Lock;

private:

	struct PageNode
	{
		PageNode* pNext;
		char*     pEndAlloc;
		char*     pEndUsed;
		size_t    nUsed;

		char*     StartUsed() const
		{
			return (char*)(this + 1);
		}

		PageNode(size_t nAlloc)
		{
			pNext = 0;
			pEndAlloc = (char*)this + nAlloc;
			pEndUsed = StartUsed();
			nUsed = 0;
		}

		ILINE void* Allocate(size_t nSize, size_t nAlign)
		{
			// Align current mem.
			char* pNew = Align(pEndUsed, nAlign);
			if (pNew + nSize > pEndAlloc)
				return 0;
			pEndUsed = pNew + nSize;
			nUsed += nSize;
			return pNew;
		}

		ILINE bool Reallocate(void* ptr, size_t nOldSize, size_t nNewSize, size_t nAlign)
		{
			char* cptr = (char*)ptr;
			if (cptr + nOldSize <= pEndUsed && Align(cptr + nOldSize, nAlign) >= pEndUsed && cptr + nNewSize <= pEndAlloc)
			{
				// Last allocation chunk, can re-use
				assert(cptr >= StartUsed());
				pEndUsed = cptr + nNewSize;
				nUsed += nNewSize - nOldSize;
				return true;
			}
			return false;
		}

		void Reset()
		{
			pEndUsed = StartUsed();
		}

		size_t GetMemoryAlloc() const
		{
			return pEndAlloc - (char*)this;
		}
		size_t GetMemoryUsed() const
		{
			assert(StartUsed() + nUsed <= pEndUsed);
			return nUsed;
		}
		size_t GetMemoryFree(size_t nAlign = 1) const
		{
			return pEndAlloc - Align(pEndUsed, nAlign);
		}
		SMemoryUsage GetMemoryUsage() const
		{
			return SMemoryUsage(GetMemoryAlloc(), GetMemoryUsed());
		}

		void Validate() const
		{
			assert(pEndAlloc >= (char*)this);
			assert(pEndUsed >= StartUsed() && pEndUsed <= pEndAlloc);
			assert(StartUsed() + nUsed <= pEndUsed);
		}

		bool CheckPtr(void* ptr, size_t nSize) const
		{
			return (char*)ptr >= StartUsed() && (char*)ptr + nSize <= pEndUsed;
		}
	};

public:

	HeapAllocator(FHeap opts = 0)
		: FHeap(opts)
		, _pPageList(0)
	{
	}

	~HeapAllocator()
	{
		Clear();
	}

	// Raw memory allocation.

	void* Allocate(const Lock& lock, size_t nSize, size_t nAlign)
	{
		for (;; )
		{
			// Try allocating from head page first.
			if (_pPageList)
			{
				if (void* ptr = _pPageList->Allocate(nSize, nAlign))
				{
					_TotalMem.nUsed += nSize;
					Validate(lock);
					return ptr;
				}

				if (_pPageList->pNext && _pPageList->pNext->GetMemoryFree() > _pPageList->GetMemoryFree())
				{
					SortPage(lock, _pPageList);
					Validate(lock);

					// Try allocating from new head, which has the most free memory.
					// If this fails, we know no further pages will succeed.
					if (void* ptr = _pPageList->Allocate(nSize, nAlign))
					{
						_TotalMem.nUsed += nSize;
						return ptr;
					}
				}
				if (SinglePage)
					return 0;
			}

			PageNode* pPageNode = 0;

			if (!pPageNode)
			{
				// Allocate the new page of the required size.
				size_t nAllocSize = Align(sizeof(PageNode), nAlign) + nSize;
				nAllocSize = RoundUpTo(nAllocSize, PageSize);

				void* pAlloc = A::SysAlloc(nAllocSize);
				pPageNode = new(pAlloc) PageNode(nAllocSize);

				_TotalMem.nAlloc += nAllocSize;
			}

			// Insert at head of list.
			pPageNode->pNext = _pPageList;
			_pPageList = pPageNode;
		}
	}

	bool Reallocate(const Lock& lock, void* ptr, size_t nOldSize, size_t nNewSize, size_t nAlign)
	{
		// Reallocate only if last allocated block in last page
		assert(ptr && nOldSize);
		assert(_pPageList);
		if (_pPageList->Reallocate(ptr, nOldSize, nNewSize, nAlign))
		{
			assert(_TotalMem.nUsed + nNewSize >= nOldSize);
			_TotalMem.nUsed += nNewSize - nOldSize;
			Validate(lock);
			return true;
		}
		return false;
	}

	bool Deallocate(const Lock& lock, void* ptr, size_t nSize, size_t nAlign)
	{
		assert(CheckPtr(lock, ptr, nSize));
		assert(_TotalMem.nUsed >= nSize);
		_TotalMem.nUsed -= nSize;
		Validate(lock);
		return true;
	}

	// Templated type allocation.

	template<typename T>
	T* New(size_t nAlign = 0)
	{
		void* pMemory = Allocate(Lock(*this), sizeof(T), nAlign ? nAlign : alignof(T));
		return pMemory ? new(pMemory) T : 0;
	}

	template<typename T>
	T* NewArray(size_t nCount, size_t nAlign = 0)
	{
		void* pMemory = Allocate(Lock(*this), sizeof(T) * nCount, nAlign ? nAlign : alignof(T));
		return pMemory ? new(pMemory) T[nCount] : 0;
	}

	// Maintenance.

	SMemoryUsage GetTotalMemory(const Lock&)
	{
		return _TotalMem;
	}
	SMemoryUsage GetTotalMemory()
	{
		Lock lock(*this);
		return _TotalMem;
	}

	//! Facility to defer freeing of dead pages during memory release calls.
	struct FreeMemLock : Lock
	{
		struct PageNode* _pPageList;

		FreeMemLock(L& lock)
			: Lock(lock), _pPageList(0) {}

		~FreeMemLock()
		{
			while (_pPageList != 0)
			{
				// Read the "next" pointer before deleting.
				PageNode* pNext = _pPageList->pNext;

				// Delete the current page.
				A::SysDealloc(_pPageList);

				// Move to the next page in the list.
				_pPageList = pNext;
			}
		}
	};

	void Clear(FreeMemLock& lock)
	{
		// Remove the pages from the object.
		Validate(lock);
		lock._pPageList = _pPageList;
		_pPageList = 0;
		_TotalMem.Clear();
	}

	void Clear()
	{
		FreeMemLock lock(*this);
		Clear(lock);
	}

	void Reset(const Lock& lock)
	{
		// Reset all pages, allowing memory re-use.
		Validate(lock);
		size_t nPrevSize = ~0;
		for (PageNode** ppPage = &_pPageList; *ppPage; )
		{
			(*ppPage)->Reset();
			if ((*ppPage)->GetMemoryAlloc() > nPrevSize)
			{
				// Move page to sorted location near beginning.
				SortPage(lock, *ppPage);

				// ppPage is now next page, so continue loop.
				continue;
			}
			nPrevSize = (*ppPage)->GetMemoryAlloc();
			ppPage = &(*ppPage)->pNext;
		}
		_TotalMem.nUsed = 0;
		Validate(lock);
	}

	void Reset()
	{
		Reset(Lock(*this));
	}

	// Validation.

	bool CheckPtr(const Lock&, void* ptr, size_t size) const
	{
		assert(ptr || !size);
		if (!ptr)
			return true;
		for (PageNode* pNode = _pPageList; pNode; pNode = pNode->pNext)
		{
			if (pNode->CheckPtr(ptr, size))
				return true;
		}
		return false;
	}

	void Validate(const Lock&) const
	{
#if defined(_DEBUG)
		// Check page validity, and memory counts.
		SMemoryUsage MemCheck;

		for (PageNode* pPage = _pPageList; pPage; pPage = pPage->pNext)
		{
			pPage->Validate();
			MemCheck += pPage->GetMemoryUsage();
			if (pPage != _pPageList && pPage->pNext)
				assert(pPage->GetMemoryFree() >= pPage->pNext->GetMemoryFree());
		}
		assert(MemCheck.nAlloc == _TotalMem.nAlloc);
		assert(MemCheck.nUsed >= _TotalMem.nUsed);
#endif
	}

	//! TSizer is ICrySizer; templated so this header does not need CrySizer.h.
	template<typename TSizer>
	void GetMemoryUsage(TSizer* pSizer) const
	{
		Lock lock(non_const(*this));
		for (PageNode* pNode = _pPageList; pNode; pNode = pNode->pNext)
		{
			pSizer->AddObject(pNode, pNode->GetMemoryAlloc());
		}
	}

private:

	void SortPage(const Lock&, PageNode*& rpPage)
	{
		// Unlink rpPage.
		PageNode* pPage = rpPage;
		rpPage = pPage->pNext;

		// Insert into list based on free memory.
		PageNode** ppBefore = &_pPageList;
		while (*ppBefore && (*ppBefore)->GetMemoryFree() > pPage->GetMemoryFree())
			ppBefore = &(*ppBefore)->pNext;

		//! Link before rpList.
		pPage->pNext = *ppBefore;
		*ppBefore = pPage;
	}

	PageNode*    _pPageList; //<! Pages with current allocations
	SMemoryUsage _TotalMem;  //<! Track memory allocated and used
};
}
