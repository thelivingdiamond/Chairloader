// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsHitReacting
// Header:  Prey/GameDll/ark/npc/ability/prereq/ishitreacting/ArkNpcAbilityPrereq_IsHitReacting.h
class ArkNpcAbilityPrereq_IsHitReacting : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=24 (0x18)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsHitReacting();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsHitReacting& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132F1F0);
	static inline auto FArkNpcAbilityPrereq_IsHitReacting = PreyFunction<void(ArkNpcAbilityPrereq_IsHitReacting* const _this)>(0x132F1C0);
};
#endif // MOONCRASH
