// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsTakingDamage
// Header:  Prey/GameDll/ark/npc/ability/prereq/istakingdamage/ArkNpcAbilityPrereq_IsTakingDamage.h
class ArkNpcAbilityPrereq_IsTakingDamage : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=24 (0x18)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsTakingDamage();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTakingDamage& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132F2D0);
	static inline auto FArkNpcAbilityPrereq_IsTakingDamage = PreyFunction<void(ArkNpcAbilityPrereq_IsTakingDamage* const _this)>(0x132F290);
};
#endif // MOONCRASH
