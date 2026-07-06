// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsUsingUnreachableTargeting
// Header:  Prey/GameDll/ark/npc/ability/prereq/isusingunreachabletargeting/ArkNpcAbilityPrereq_IsUsingUnreachableTargeting.h
class ArkNpcAbilityPrereq_IsUsingUnreachableTargeting : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bShouldBeInUnreachableTargeting;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsUsingUnreachableTargeting();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsUsingUnreachableTargeting& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262A00);
	static inline auto FArkNpcAbilityPrereq_IsUsingUnreachableTargeting = PreyFunction<void(ArkNpcAbilityPrereq_IsUsingUnreachableTargeting* const _this)>(0x12629D0);
};
#endif // MOONCRASH
