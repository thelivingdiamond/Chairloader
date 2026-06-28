// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsTargetReachable
// Header:  Prey/GameDll/ark/npc/ability/prereq/istargetreachable/ArkNpcAbilityPrereq_IsTargetReachable.h
class ArkNpcAbilityPrereq_IsTargetReachable : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsTargetReachable();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTargetReachable& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132F670);
	static inline auto FArkNpcAbilityPrereq_IsTargetReachable = PreyFunction<void(ArkNpcAbilityPrereq_IsTargetReachable* const _this)>(0x132F600);
};
#endif // MOONCRASH
