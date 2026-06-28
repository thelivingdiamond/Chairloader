// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MaxTargetDistance
// Header:  Prey/GameDll/ark/npc/ability/prereq/maxtargetdistance/ArkNpcAbilityPrereq_MaxTargetDistance.h
class ArkNpcAbilityPrereq_MaxTargetDistance : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_distance;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MaxTargetDistance();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxTargetDistance& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	float GetDistance() const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132F970);
	static inline auto FArkNpcAbilityPrereq_MaxTargetDistance = PreyFunction<void(ArkNpcAbilityPrereq_MaxTargetDistance* const _this)>(0x132F940);
};
#endif // MOONCRASH
