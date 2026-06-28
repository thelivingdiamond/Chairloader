// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkNpcBlackboardEntryTemplate_LazyGet.h>

class ArkNpcBlackboardKey_EntityReachable;

// ArkNpcBlackboardEntry_EntityReachable
// Header:  Prey/GameDll/ark/npc/blackboard/entry/entityreachable/ArkNpcBlackboardEntry_EntityReachable.h
class ArkNpcBlackboardEntry_EntityReachable : public ArkNpcBlackboardEntryTemplate_LazyGet<ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardEntryKey_EntityReachable,ArkNpcBlackboardEntry_EntityReachable,bool,bool>
{ // Size=2 (0x2)
public:
	bool m_bReachable;

	ArkNpcBlackboardEntry_EntityReachable();
	void Evaluate(const ArkNpcBlackboardKey_EntityReachable& _blackboardKey) { FEvaluate(this, _blackboardKey); }
	bool Get() const { return FGet(this); }

	static inline auto FArkNpcBlackboardEntry_EntityReachableOv2 = PreyFunction<void(ArkNpcBlackboardEntry_EntityReachable* const _this)>(0x129F510);
	static inline auto FEvaluate = PreyFunction<void(ArkNpcBlackboardEntry_EntityReachable* const _this, const ArkNpcBlackboardKey_EntityReachable& _blackboardKey)>(0x129F520);
	static inline auto FGet = PreyFunction<bool(const ArkNpcBlackboardEntry_EntityReachable* const _this)>(0x129F5D0);
};
#endif // MOONCRASH
