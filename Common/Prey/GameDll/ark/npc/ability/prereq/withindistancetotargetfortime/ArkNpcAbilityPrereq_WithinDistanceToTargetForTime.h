// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime;

// ArkNpcAbilityPrereq_WithinDistanceToTargetForTime
// Header:  Prey/GameDll/ark/npc/ability/prereq/withindistancetotargetfortime/ArkNpcAbilityPrereq_WithinDistanceToTargetForTime.h
class ArkNpcAbilityPrereq_WithinDistanceToTargetForTime : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_requriedDistance;
	float m_requiredTime;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_WithinDistanceToTargetForTime();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_WithinDistanceToTargetForTime& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime& _arg2_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12640F0);
	static inline auto FArkNpcAbilityPrereq_WithinDistanceToTargetForTime = PreyFunction<void(ArkNpcAbilityPrereq_WithinDistanceToTargetForTime* const _this)>(0x12640C0);
};
#endif // MOONCRASH
