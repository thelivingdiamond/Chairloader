// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_ContextGroupCooldown;

// ArkNpcAbilityPrereq_ContextGroupCooldown
// Header:  Prey/GameDll/ark/npc/ability/prereq/contextgroupcooldown/ArkNpcAbilityPrereq_ContextGroupCooldown.h
class ArkNpcAbilityPrereq_ContextGroupCooldown : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=56 (0x38)
public:
	using ContextIdVector = std::vector<uint64_t>;

	std::vector<uint64_t> m_contextIds;
	ArkInterval<float> m_cooldownInterval;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_ContextGroupCooldown();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_ContextGroupCooldown& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E900);
	static inline auto FArkNpcAbilityPrereq_ContextGroupCooldown = PreyFunction<void(ArkNpcAbilityPrereq_ContextGroupCooldown* const _this)>(0x125E800);
};
#endif // MOONCRASH
