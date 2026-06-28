// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/EntityTimeoutList.h>

struct ITimer;

// Header: FromCpp
// CryEngine/cryentitysystem/entitytimeoutlist.h
class CEntityTimeoutList // Id=800C735 Size=16
{
public:
	class CEntry // Id=800C737 Size=16
	{
	public:
		unsigned m_id;
		float m_time;
		int m_next;
		int m_prev;
	};

	using EntryContainer = DynArray<CEntityTimeoutList::CEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >;
	
	DynArray<CEntityTimeoutList::CEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_entries;
	ITimer *m_pTimer;
	
	CEntityTimeoutList(ITimer *pTimer);
	void ResetTimeout(unsigned id) { FResetTimeout(this,id); }
	unsigned PopTimeoutEntity(float timeout) { return FPopTimeoutEntity(this,timeout); }
	void Clear() { FClear(this); }
	
#if 0
	static CSaltHandle<unsigned short,unsigned short> IdToHandle(const unsigned arg0);
#endif
	
	static inline auto FResetTimeout = PreyFunction<void(CEntityTimeoutList *const _this, unsigned id)>(0x929D00);
	static inline auto FPopTimeoutEntity = PreyFunction<unsigned(CEntityTimeoutList *const _this, float timeout)>(0x929C40);
	static inline auto FClear = PreyFunction<void(CEntityTimeoutList *const _this)>(0x929C20);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/CSaltHandle.h>
#include <_unknown/DynArray.h>

struct ITimer;

// CEntityTimeoutList
// Header:  CryEngine/cryentitysystem/EntityTimeoutList.h
// Include: Prey/CryEntitySystem/EntityTimeoutList.h
class CEntityTimeoutList
{ // Size=16 (0x10)
public:
	// CEntityTimeoutList::CEntry
	// Header:  CryEngine/cryentitysystem/EntityTimeoutList.h
	class CEntry
	{ // Size=16 (0x10)
	public:
		unsigned m_id;
		float m_time;
		int m_next;
		int m_prev;

	#if 0
		CEntry();
	#endif
	};

	using EntryContainer = DynArray<CEntityTimeoutList::CEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >;

	DynArray<CEntityTimeoutList::CEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_entries;
	ITimer* m_pTimer;

	CEntityTimeoutList(ITimer* pTimer);
	void ResetTimeout(unsigned id) { FResetTimeout(this, id); }
	unsigned PopTimeoutEntity(float timeout) { return FPopTimeoutEntity(this, timeout); }
	void Clear() { FClear(this); }

#if 0
	static CSaltHandle<unsigned short,unsigned short> IdToHandle(const unsigned _arg0_);
#endif

	static inline auto FCEntityTimeoutListOv2 = PreyFunction<void(CEntityTimeoutList* const _this, ITimer* pTimer)>(0x946170);
	static inline auto FResetTimeout = PreyFunction<void(CEntityTimeoutList* const _this, unsigned id)>(0x9462B0);
	static inline auto FPopTimeoutEntity = PreyFunction<unsigned(CEntityTimeoutList* const _this, float timeout)>(0x9461F0);
	static inline auto FClear = PreyFunction<void(CEntityTimeoutList* const _this)>(0x9461D0);
};
#endif // !MOONCRASH
