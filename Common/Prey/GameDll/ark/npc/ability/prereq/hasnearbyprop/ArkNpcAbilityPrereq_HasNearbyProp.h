// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasNearbyProp
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasnearbyprop/ArkNpcAbilityPrereq_HasNearbyProp.h
class ArkNpcAbilityPrereq_HasNearbyProp : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=64 (0x40)
public:
	float m_maxDistanceFromTarget;
	float m_minDistanceFromTarget;
	float m_minHeight;
	float m_maxHeight;
	float m_minMass;
	float m_maxMass;
	float m_clusterMaxDistance;
	float m_clusterMaxMass;
	float m_clusterMaxMassDifference;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasNearbyProp();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasNearbyProp& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132E740);
	static inline auto FArkNpcAbilityPrereq_HasNearbyProp = PreyFunction<void(ArkNpcAbilityPrereq_HasNearbyProp* const _this)>(0x132E550);
};
#endif // MOONCRASH
