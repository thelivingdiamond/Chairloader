// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/ArkCommon/arkintrusivelist.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireBase.h>

class ArkNpc;
class ArkNpcFacingDesire;

// Header: MadeUp
// _unknown/ArkNpcDesireManagerBase_ArkNpcFacingDesireManager,ArkNpcFacingDesire_.h
template <typename manager, typename desire> class ArkNpcDesireManagerBase // Id=80140FE Size=48
{
public:
    bool m_bShutDown;

    struct DesireElement : public ArkIntrusiveListElement<desire> // Id=8014103 Size=32
    {
        desire *m_pDesire;

#if 0
        void Element(ArkNpcFacingDesire &arg0);
		void Element(ArkNpcDesireBase<ArkNpcFacingDesireManager,ArkNpcFacingDesire,enum EArkNpcFacingDesirePriority>::Element *arg0);
		~Element();
#endif
    };

    using DesireList = ArkIntrusiveList<desire>;

    ArkNpc *m_pArkNpc;
    DesireList m_desires;

#if 0
    ArkNpc &GetArkNpc() const;
	void AddDesire(ArkNpcFacingDesire &arg0);
	void RemoveDesire(ArkNpcFacingDesire &arg0);
	void RemoveAllDesires();
	bool HasDesire(ArkNpcFacingDesire const &arg0) const;
	bool HasActiveDesire() const;
	bool IsActiveDesire(ArkNpcFacingDesire const &arg0) const;
	ArkNpcFacingDesire &GetActiveDesire();
	ArkNpcFacingDesire const &GetActiveDesire() const;
	const char *GetActiveDesireName() const;
	void RemoveAllDesiresFromList();
#endif
};

