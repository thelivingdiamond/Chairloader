// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasCollisionCapsuleClearance
// Header:  Prey/GameDll/ark/npc/ability/prereq/hascollisioncapsuleclearance/ArkNpcAbilityPrereq_HasCollisionCapsuleClearance.h
class ArkNpcAbilityPrereq_HasCollisionCapsuleClearance : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=56 (0x38)
public:
	float m_capsuleDistance;
	float m_capsuleRadius;
	float m_startingHeight;
	float m_targetOffset;
	string m_jointName;
	bool m_bAllowRigidBody;
	bool m_bAllowBreakable;
	bool m_bAllowPermeable;
	bool m_bAllowTransparent;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasCollisionCapsuleClearance();
	bool Evaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const { return FEvaluate(this, _npc, _params, _prereqInstance); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasCollisionCapsuleClearance& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125F2F0);
	static inline auto FArkNpcAbilityPrereq_HasCollisionCapsuleClearance = PreyFunction<void(ArkNpcAbilityPrereq_HasCollisionCapsuleClearance* const _this)>(0x125F240);
	static inline auto FEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereq_HasCollisionCapsuleClearance* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125F400);
};
#endif // MOONCRASH
