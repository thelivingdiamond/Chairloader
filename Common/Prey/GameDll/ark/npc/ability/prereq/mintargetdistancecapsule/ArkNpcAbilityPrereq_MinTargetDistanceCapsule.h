// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MinTargetDistanceCapsule
// Header:  Prey/GameDll/ark/npc/ability/prereq/mintargetdistancecapsule/ArkNpcAbilityPrereq_MinTargetDistanceCapsule.h
class ArkNpcAbilityPrereq_MinTargetDistanceCapsule : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_distance;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MinTargetDistanceCapsule();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MinTargetDistanceCapsule& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1263280);
	static inline auto FArkNpcAbilityPrereq_MinTargetDistanceCapsule = PreyFunction<void(ArkNpcAbilityPrereq_MinTargetDistanceCapsule* const _this)>(0x1263250);
};
#endif // MOONCRASH
