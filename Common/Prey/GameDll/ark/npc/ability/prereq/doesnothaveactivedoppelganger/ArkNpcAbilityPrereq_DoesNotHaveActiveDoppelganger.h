// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger
// Header:  Prey/GameDll/ark/npc/ability/prereq/doesnothaveactivedoppelganger/ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger.h
class ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=24 (0x18)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132CC30);
	static inline auto FArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger = PreyFunction<void(ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger* const _this)>(0x132CC00);
};
#endif // MOONCRASH
