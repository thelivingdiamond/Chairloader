// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget;

// ArkNpcAbilityPrereq_PercentChanceFromBehindTarget
// Header:  Prey/GameDll/ark/npc/ability/prereq/percentchancefrombehindtarget/ArkNpcAbilityPrereq_PercentChanceFromBehindTarget.h
class ArkNpcAbilityPrereq_PercentChanceFromBehindTarget : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	float m_thresholdAngle;
	float m_percentChance;
	float m_percentChanceVsNpc;
	float m_retryPeriod;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_PercentChanceFromBehindTarget();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_PercentChanceFromBehindTarget& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget& _arg2_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1263820);
	static inline auto FArkNpcAbilityPrereq_PercentChanceFromBehindTarget = PreyFunction<void(ArkNpcAbilityPrereq_PercentChanceFromBehindTarget* const _this)>(0x12637C0);
};
#endif // MOONCRASH
