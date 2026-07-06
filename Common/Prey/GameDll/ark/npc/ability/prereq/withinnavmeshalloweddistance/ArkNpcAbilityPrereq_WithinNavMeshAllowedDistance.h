// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance;

// ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance
// Header:  Prey/GameDll/ark/npc/ability/prereq/withinnavmeshalloweddistance/ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance.h
class ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_minDistance;
	float m_failRetryTime;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance();
	bool Evaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance& _prereqInstance) const { return FEvaluate(this, _npc, _params, _prereqInstance); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance& _arg0_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1264220);
	static inline auto FArkNpcAbilityPrereq_WithinNavMeshAllowedDistance = PreyFunction<void(ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance* const _this)>(0x12641F0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance& _prereqInstance)>(0x12642B0);
};
#endif // MOONCRASH
