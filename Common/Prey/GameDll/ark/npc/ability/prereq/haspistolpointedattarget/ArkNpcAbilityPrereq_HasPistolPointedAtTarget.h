// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasPistolPointedAtTarget
// Header:  Prey/GameDll/ark/npc/ability/prereq/haspistolpointedattarget/ArkNpcAbilityPrereq_HasPistolPointedAtTarget.h
class ArkNpcAbilityPrereq_HasPistolPointedAtTarget : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	float m_requiredAngle;
	string m_bulletSpawnAttachment;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasPistolPointedAtTarget();
	bool Evaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const { return FEvaluate(this, _npc, _params, _prereqInstance); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasPistolPointedAtTarget& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1261880);
	static inline auto FArkNpcAbilityPrereq_HasPistolPointedAtTarget = PreyFunction<void(ArkNpcAbilityPrereq_HasPistolPointedAtTarget* const _this)>(0x1261780);
	static inline auto FEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereq_HasPistolPointedAtTarget* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12618A0);
};
#endif // MOONCRASH
