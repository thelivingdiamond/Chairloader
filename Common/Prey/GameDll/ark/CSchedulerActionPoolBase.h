// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/CSchedulerActionPoolBase.h
class CSchedulerActionPoolBase // Id=8016CF3 Size=24
{
public:
	static CSchedulerActionPoolBase *s_poolListHead;
	CSchedulerActionPoolBase *m_pPrev;
	CSchedulerActionPoolBase *m_pNext;
	
	virtual void Reset() = 0;
	
#if 0
	static void ResetAll();
#endif
};

