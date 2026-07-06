// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsTargetInSyncedAnimation
// Header:  Prey/GameDll/ark/npc/ability/prereq/istargetinsyncedanimation/ArkNpcAbilityPrereq_IsTargetInSyncedAnimation.h
class ArkNpcAbilityPrereq_IsTargetInSyncedAnimation : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsTargetInSyncedAnimation();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTargetInSyncedAnimation& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262880);
	static inline auto FArkNpcAbilityPrereq_IsTargetInSyncedAnimation = PreyFunction<void(ArkNpcAbilityPrereq_IsTargetInSyncedAnimation* const _this)>(0x1262850);
};
#endif // MOONCRASH
