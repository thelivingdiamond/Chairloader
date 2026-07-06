// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsTargetPlayer
// Header:  Prey/GameDll/ark/npc/ability/prereq/istargetplayer/ArkNpcAbilityPrereq_IsTargetPlayer.h
class ArkNpcAbilityPrereq_IsTargetPlayer : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsTargetPlayer();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTargetPlayer& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262950);
	static inline auto FArkNpcAbilityPrereq_IsTargetPlayer = PreyFunction<void(ArkNpcAbilityPrereq_IsTargetPlayer* const _this)>(0x12628F0);
};
#endif // MOONCRASH
