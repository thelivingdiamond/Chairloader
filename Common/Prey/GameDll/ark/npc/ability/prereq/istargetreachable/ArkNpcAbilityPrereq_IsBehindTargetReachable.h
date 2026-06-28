// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsBehindTargetReachable
// Header:  Prey/GameDll/ark/npc/ability/prereq/istargetreachable/ArkNpcAbilityPrereq_IsBehindTargetReachable.h
class ArkNpcAbilityPrereq_IsBehindTargetReachable : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_distanceBehindTarget;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsBehindTargetReachable();
	bool Evaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const { return FEvaluate(this, _npc, _params, _prereqInstance); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsBehindTargetReachable& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132F320);
	static inline auto FArkNpcAbilityPrereq_IsBehindTargetReachable = PreyFunction<void(ArkNpcAbilityPrereq_IsBehindTargetReachable* const _this)>(0x132F2E0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereq_IsBehindTargetReachable* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F330);
};
#endif // MOONCRASH
