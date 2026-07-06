// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MinNumberOfCombatants
// Header:  Prey/GameDll/ark/npc/ability/prereq/minnumberofcombatants/ArkNpcAbilityPrereq_MinNumberOfCombatants.h
class ArkNpcAbilityPrereq_MinNumberOfCombatants : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	unsigned m_minNumberOfCombatants;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MinNumberOfCombatants();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MinNumberOfCombatants& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12630E0);
	static inline auto FArkNpcAbilityPrereq_MinNumberOfCombatants = PreyFunction<void(ArkNpcAbilityPrereq_MinNumberOfCombatants* const _this)>(0x1263050);
};
#endif // MOONCRASH
