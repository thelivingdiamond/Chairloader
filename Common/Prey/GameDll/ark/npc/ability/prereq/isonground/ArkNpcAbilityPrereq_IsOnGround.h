// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsOnGround
// Header:  Prey/GameDll/ark/npc/ability/prereq/isonground/ArkNpcAbilityPrereq_IsOnGround.h
class ArkNpcAbilityPrereq_IsOnGround : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=24 (0x18)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsOnGround();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsOnGround& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262570);
	static inline auto FArkNpcAbilityPrereq_IsOnGround = PreyFunction<void(ArkNpcAbilityPrereq_IsOnGround* const _this)>(0x1262510);
};
#endif // MOONCRASH
