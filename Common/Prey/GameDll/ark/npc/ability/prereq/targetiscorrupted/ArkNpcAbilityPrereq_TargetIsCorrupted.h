// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_TargetIsCorrupted
// Header:  Prey/GameDll/ark/npc/ability/prereq/targetiscorrupted/ArkNpcAbilityPrereq_TargetIsCorrupted.h
class ArkNpcAbilityPrereq_TargetIsCorrupted : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bShouldBeCorrupted;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_TargetIsCorrupted();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_TargetIsCorrupted& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132FDA0);
	static inline auto FArkNpcAbilityPrereq_TargetIsCorrupted = PreyFunction<void(ArkNpcAbilityPrereq_TargetIsCorrupted* const _this)>(0x132FD70);
};
#endif // MOONCRASH
