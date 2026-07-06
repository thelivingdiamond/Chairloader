// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/CSchedulerActionPoolBase.h
class CSchedulerActionPoolBase // Id=8016CF3 Size=24
{
public:
	static CSchedulerActionPoolBase *s_poolListHead;
	CSchedulerActionPoolBase *m_pPrev;
	CSchedulerActionPoolBase *m_pNext;
	
	virtual ~CSchedulerActionPoolBase();
	virtual void Reset() = 0;
	
#if 0
	static void ResetAll();
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// CSchedulerActionPoolBase
// Header:  Prey/GameDll/ark/CSchedulerActionPoolBase.h
class CSchedulerActionPoolBase
{ // Size=24 (0x18)
public:
	static inline auto s_poolListHead = PreyGlobal<CSchedulerActionPoolBase*>(0x2D8E5C0);
	CSchedulerActionPoolBase* m_pPrev;
	CSchedulerActionPoolBase* m_pNext;

	virtual ~CSchedulerActionPoolBase();
	virtual void Reset() = 0;

#if 0
	static void ResetAll();
	CSchedulerActionPoolBase();
	CSchedulerActionPoolBase(const CSchedulerActionPoolBase& _arg0_);
	CSchedulerActionPoolBase& operator=(const CSchedulerActionPoolBase& _arg0_);
#endif
};
#endif // !MOONCRASH
