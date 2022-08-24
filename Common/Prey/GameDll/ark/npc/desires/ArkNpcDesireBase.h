// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/arkintrusivelist.h>

// Header: MadeUp
// _unknown/ArkNpcDesireBase_ArkNpcSpeedDesireManager,ArkNpcSpeedDesire,enum EArkNpcSpeedDesirePriority_.h
template<typename Manager ,typename Desire, typename PriorityEnum> class ArkNpcDesireBase // Id=8014135 Size=64
{
public:
    const char *m_dbgSource;

    struct Element : public ArkIntrusiveListElement<ArkNpcDesireBase::Element> // Id=8014147 Size=32
    {
        Desire *m_pDesire;
    };

    enum class EStatus
    {
        unfulfilled = 0,
        fulfilled = 1,
        failed = 2,
    };

    PriorityEnum m_priority;
    ArkNpcDesireBase::Element m_element;
    Manager *m_pManager;
    ArkNpcDesireBase::EStatus m_status;

#if 0
    EArkNpcSpeedDesirePriority GetPriority() const;
	bool IsManaged() const;
	bool IsActive() const;
	bool IsFulfilled() const;
	bool IsFailed() const;
	ArkNpcSpeedDesireManager &GetManager() const;
	void SetDebugDisplayName(const char *arg0);
	void SetPriority(EArkNpcSpeedDesirePriority arg0);
	void OnSetParams(bool arg0);
#endif
};

