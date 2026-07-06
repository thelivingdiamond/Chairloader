// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_CanJump
// Header:  Prey/GameDll/ark/npc/ability/prereq/canjump/ArkNpcAbilityPrereq_CanJump.h
class ArkNpcAbilityPrereq_CanJump : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=24 (0x18)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_CanJump();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_CanJump& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E6F0);
	static inline auto FArkNpcAbilityPrereq_CanJump = PreyFunction<void(ArkNpcAbilityPrereq_CanJump* const _this)>(0x125E6C0);
};
#endif // MOONCRASH
