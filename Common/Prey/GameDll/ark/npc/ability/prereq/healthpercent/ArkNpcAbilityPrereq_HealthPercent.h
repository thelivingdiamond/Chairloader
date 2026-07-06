// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HealthPercent
// Header:  Prey/GameDll/ark/npc/ability/prereq/healthpercent/ArkNpcAbilityPrereq_HealthPercent.h
class ArkNpcAbilityPrereq_HealthPercent : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_minHealthPercent;
	float m_maxHealthPercent;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HealthPercent();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HealthPercent& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12620C0);
	static inline auto FArkNpcAbilityPrereq_HealthPercent = PreyFunction<void(ArkNpcAbilityPrereq_HealthPercent* const _this)>(0x1261FE0);
};
#endif // MOONCRASH
