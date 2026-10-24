// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/CSchedulerActionPoolBase.h
class CSchedulerActionPoolBase // Id=8016CF3 Size=24
{
public:
#ifndef MOONCRASH
	static CSchedulerActionPoolBase *s_poolListHead;
#else
	static inline auto s_poolListHead = PreyGlobal<CSchedulerActionPoolBase*>(0x2D8E5C0);
#endif
	CSchedulerActionPoolBase *m_pPrev;
	CSchedulerActionPoolBase *m_pNext;
	
	virtual ~CSchedulerActionPoolBase();
	virtual void Reset() = 0;
	
#if 0
	static void ResetAll();
#endif
};
