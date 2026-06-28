// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_AbilityGroupCooldown;

// ArkNpcAbilityPrereq_AbilityGroupCooldown
// Header:  Prey/GameDll/ark/npc/ability/prereq/abilitygroupcooldown/ArkNpcAbilityPrereq_AbilityGroupCooldown.h
class ArkNpcAbilityPrereq_AbilityGroupCooldown : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=56 (0x38)
public:
	using AbilityIdVector = std::vector<uint64_t>;

	std::vector<uint64_t> m_abilityIds;
	ArkInterval<float> m_cooldownInterval;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_AbilityGroupCooldown();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_AbilityGroupCooldown& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E3F0);
	static inline auto FArkNpcAbilityPrereq_AbilityGroupCooldown = PreyFunction<void(ArkNpcAbilityPrereq_AbilityGroupCooldown* const _this)>(0x125E3B0);
};
#endif // MOONCRASH
