// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsIgnoringRangedAbilities
// Header:  Prey/GameDll/ark/npc/ability/prereq/isignoringrangedabilities/ArkNpcAbilityPrereq_IsIgnoringRangedAbilities.h
class ArkNpcAbilityPrereq_IsIgnoringRangedAbilities : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsIgnoringRangedAbilities();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsIgnoringRangedAbilities& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262280);
	static inline auto FArkNpcAbilityPrereq_IsIgnoringRangedAbilities = PreyFunction<void(ArkNpcAbilityPrereq_IsIgnoringRangedAbilities* const _this)>(0x1262220);
};
#endif // MOONCRASH
