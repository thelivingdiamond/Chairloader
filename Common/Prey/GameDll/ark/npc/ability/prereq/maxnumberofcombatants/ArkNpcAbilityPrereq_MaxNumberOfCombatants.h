// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MaxNumberOfCombatants
// Header:  Prey/GameDll/ark/npc/ability/prereq/maxnumberofcombatants/ArkNpcAbilityPrereq_MaxNumberOfCombatants.h
class ArkNpcAbilityPrereq_MaxNumberOfCombatants : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	unsigned m_maxNumberOfCombatants;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MaxNumberOfCombatants();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxNumberOfCombatants& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262CC0);
	static inline auto FArkNpcAbilityPrereq_MaxNumberOfCombatants = PreyFunction<void(ArkNpcAbilityPrereq_MaxNumberOfCombatants* const _this)>(0x1262C90);
};
#endif // MOONCRASH
