// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasThermogenesisPosition
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasthermogenesisposition/ArkNpcAbilityPrereq_HasThermogenesisPosition.h
class ArkNpcAbilityPrereq_HasThermogenesisPosition : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	float m_downTraceCheckDistance;
	float m_spawnDistanceInFrontOfPlayer;
	float m_distanceFromObstacle;
	float m_aboveFloorDelta;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasThermogenesisPosition();
	bool Evaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const { return FEvaluate(this, _npc, _params, _prereqInstance); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasThermogenesisPosition& _arg0_) const;
	bool EqualTo(const ArkNpcAbilityPrereq_HasThermogenesisPosition& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132ED90);
	static inline auto FArkNpcAbilityPrereq_HasThermogenesisPosition = PreyFunction<void(ArkNpcAbilityPrereq_HasThermogenesisPosition* const _this)>(0x132ED50);
	static inline auto FEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereq_HasThermogenesisPosition* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132EE00);
};
#endif // MOONCRASH
