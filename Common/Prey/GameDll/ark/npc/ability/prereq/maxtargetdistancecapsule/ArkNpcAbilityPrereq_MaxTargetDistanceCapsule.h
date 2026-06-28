// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MaxTargetDistanceCapsule
// Header:  Prey/GameDll/ark/npc/ability/prereq/maxtargetdistancecapsule/ArkNpcAbilityPrereq_MaxTargetDistanceCapsule.h
class ArkNpcAbilityPrereq_MaxTargetDistanceCapsule : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_distance;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MaxTargetDistanceCapsule();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxTargetDistanceCapsule& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	float GetDistance() const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262FB0);
	static inline auto FArkNpcAbilityPrereq_MaxTargetDistanceCapsule = PreyFunction<void(ArkNpcAbilityPrereq_MaxTargetDistanceCapsule* const _this)>(0x1262F80);
};
#endif // MOONCRASH
