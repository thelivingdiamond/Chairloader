// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/blackboard/ArkNpcBlackboardEntryTemplates.h>

class ArkNpcBlackboardEntryKey_EntityOccluded;
class ArkNpcBlackboardKey_EntityOccluded;

// ArkNpcBlackboardEntry_EntityOccluded
// Header:  Prey/GameDll/ark/npc/blackboard/entry/entityoccluded/ArkNpcBlackboardEntry_EntityOccluded.h
class ArkNpcBlackboardEntry_EntityOccluded : public ArkNpcBlackboardEntryTemplate_LazyGet<ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardEntryKey_EntityOccluded,ArkNpcBlackboardEntry_EntityOccluded,bool,bool>
{ // Size=2 (0x2)
public:
	bool m_bOccluded;

	ArkNpcBlackboardEntry_EntityOccluded();
	void Evaluate(const ArkNpcBlackboardKey_EntityOccluded& _blackboardKey) { FEvaluate(this, _blackboardKey); }
	bool Get() const { return FGet(this); }

#ifndef MOONCRASH
	static inline auto FArkNpcBlackboardEntry_EntityOccludedOv2 = PreyFunction<void(ArkNpcBlackboardEntry_EntityOccluded* const _this)>(0x12100D0);
	static inline auto FEvaluate = PreyFunction<void(ArkNpcBlackboardEntry_EntityOccluded* const _this, const ArkNpcBlackboardKey_EntityOccluded& _blackboardKey)>(0x12100E0);
	static inline auto FGet = PreyFunction<bool(const ArkNpcBlackboardEntry_EntityOccluded* const _this)>(0x1210460);
#else
	static inline auto FArkNpcBlackboardEntry_EntityOccludedOv2 = PreyFunction<void(ArkNpcBlackboardEntry_EntityOccluded* const _this)>(0x129F510);
	static inline auto FEvaluate = PreyFunction<void(ArkNpcBlackboardEntry_EntityOccluded* const _this, const ArkNpcBlackboardKey_EntityOccluded& _blackboardKey)>(0x129F240);
	static inline auto FGet = PreyFunction<bool(const ArkNpcBlackboardEntry_EntityOccluded* const _this)>(0x129F5D0);
#endif
};

