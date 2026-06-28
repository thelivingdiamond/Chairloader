// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown;

// ArkNpcAbilityPrereq_GlobalAbilityCooldown
// Header:  Prey/GameDll/ark/npc/ability/prereq/globalabilitycooldown/ArkNpcAbilityPrereq_GlobalAbilityCooldown.h
class ArkNpcAbilityPrereq_GlobalAbilityCooldown : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>
{ // Size=40 (0x28)
public:
	uint64_t m_abilityId;
	ArkInterval<float> m_cooldownInterval;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_GlobalAbilityCooldown();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_GlobalAbilityCooldown& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125ECE0);
	static inline auto FArkNpcAbilityPrereq_GlobalAbilityCooldown = PreyFunction<void(ArkNpcAbilityPrereq_GlobalAbilityCooldown* const _this)>(0x125ECB0);
};
#endif // MOONCRASH
