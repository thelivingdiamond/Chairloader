// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_ContextCooldown;

// ArkNpcAbilityPrereq_ContextCooldown
// Header:  Prey/GameDll/ark/npc/ability/prereq/contextcooldown/ArkNpcAbilityPrereq_ContextCooldown.h
class ArkNpcAbilityPrereq_ContextCooldown : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	uint64_t m_contextId;
	ArkInterval<float> m_cooldownInterval;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_ContextCooldown();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_ContextCooldown& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132CB90);
	static inline auto FArkNpcAbilityPrereq_ContextCooldown = PreyFunction<void(ArkNpcAbilityPrereq_ContextCooldown* const _this)>(0x132CB60);
};
#endif // MOONCRASH
