// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsNotShifting
// Header:  Prey/GameDll/ark/npc/ability/prereq/isnotshifting/ArkNpcAbilityPrereq_IsNotShifting.h
class ArkNpcAbilityPrereq_IsNotShifting : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=24 (0x18)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsNotShifting();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsNotShifting& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132F240);
	static inline auto FArkNpcAbilityPrereq_IsNotShifting = PreyFunction<void(ArkNpcAbilityPrereq_IsNotShifting* const _this)>(0x132F210);
};
#endif // MOONCRASH
