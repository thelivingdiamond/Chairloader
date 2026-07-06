// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_AbilityCooldown;

// ArkNpcAbilityPrereq_AbilityCooldown
// Header:  Prey/GameDll/ark/npc/ability/prereq/abilitycooldown/ArkNpcAbilityPrereq_AbilityCooldown.h
class ArkNpcAbilityPrereq_AbilityCooldown : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	uint64_t m_abilityId;
	ArkInterval<float> m_cooldownInterval;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_AbilityCooldown();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_AbilityCooldown& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E2E0);
	static inline auto FArkNpcAbilityPrereq_AbilityCooldown = PreyFunction<void(ArkNpcAbilityPrereq_AbilityCooldown* const _this)>(0x125E2B0);
};
#endif // MOONCRASH
