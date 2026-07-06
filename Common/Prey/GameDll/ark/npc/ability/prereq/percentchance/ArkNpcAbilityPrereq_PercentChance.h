// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_PercentChance;

// ArkNpcAbilityPrereq_PercentChance
// Header:  Prey/GameDll/ark/npc/ability/prereq/percentchance/ArkNpcAbilityPrereq_PercentChance.h
class ArkNpcAbilityPrereq_PercentChance : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_percentChance;
	float m_retryPeriod;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_PercentChance();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_PercentChance& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_PercentChance& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_PercentChance& _arg2_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_PercentChance& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132FBB0);
	static inline auto FArkNpcAbilityPrereq_PercentChance = PreyFunction<void(ArkNpcAbilityPrereq_PercentChance* const _this)>(0x132FB80);
};
#endif // MOONCRASH
