// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasEMPBlastPosition
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasempblastposition/ArkNpcAbilityPrereq_HasEMPBlastPosition.h
class ArkNpcAbilityPrereq_HasEMPBlastPosition : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	float m_zeroGUpAddition;
	float m_spawnDistanceInFrontOfPlayer;
	float m_distanceFromObstacle;
	bool m_bOnlyUseLastSeenTargetPos;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasEMPBlastPosition();
	bool Evaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const { return FEvaluate(this, _npc, _params, _prereqInstance); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEMPBlastPosition& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132CD20);
	static inline auto FArkNpcAbilityPrereq_HasEMPBlastPosition = PreyFunction<void(ArkNpcAbilityPrereq_HasEMPBlastPosition* const _this)>(0x132CCE0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereq_HasEMPBlastPosition* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132CD80);
};
#endif // MOONCRASH
