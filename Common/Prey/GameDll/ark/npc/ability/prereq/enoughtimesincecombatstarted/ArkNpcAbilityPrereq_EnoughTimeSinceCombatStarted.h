// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted
// Header:  Prey/GameDll/ark/npc/ability/prereq/enoughtimesincecombatstarted/ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted.h
class ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_requiredTimeSinceCombatStarted;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125EC20);
	static inline auto FArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted = PreyFunction<void(ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted* const _this)>(0x125EBF0);
};
#endif // MOONCRASH
