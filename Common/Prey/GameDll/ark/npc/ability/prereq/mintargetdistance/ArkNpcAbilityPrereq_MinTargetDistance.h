// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MinTargetDistance
// Header:  Prey/GameDll/ark/npc/ability/prereq/mintargetdistance/ArkNpcAbilityPrereq_MinTargetDistance.h
class ArkNpcAbilityPrereq_MinTargetDistance : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_distance;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MinTargetDistance();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MinTargetDistance& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132FB70);
	static inline auto FArkNpcAbilityPrereq_MinTargetDistance = PreyFunction<void(ArkNpcAbilityPrereq_MinTargetDistance* const _this)>(0x132FA60);
};
#endif // MOONCRASH
