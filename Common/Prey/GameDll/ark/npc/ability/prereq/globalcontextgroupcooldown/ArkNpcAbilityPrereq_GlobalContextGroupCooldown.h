// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown;

// ArkNpcAbilityPrereq_GlobalContextGroupCooldown
// Header:  Prey/GameDll/ark/npc/ability/prereq/globalcontextgroupcooldown/ArkNpcAbilityPrereq_GlobalContextGroupCooldown.h
class ArkNpcAbilityPrereq_GlobalContextGroupCooldown : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>
{ // Size=56 (0x38)
public:
	using ContextIdVector = std::vector<uint64_t>;

	std::vector<uint64_t> m_contextIds;
	ArkInterval<float> m_cooldownInterval;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_GlobalContextGroupCooldown();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_GlobalContextGroupCooldown& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125F060);
	static inline auto FArkNpcAbilityPrereq_GlobalContextGroupCooldown = PreyFunction<void(ArkNpcAbilityPrereq_GlobalContextGroupCooldown* const _this)>(0x125F020);
};
#endif // MOONCRASH
