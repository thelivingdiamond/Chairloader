// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasMeleeLineOfSight
// Header:  Prey/GameDll/ark/npc/ability/prereq/haslineofsight/ArkNpcAbilityPrereq_HasMeleeLineOfSight.h
class ArkNpcAbilityPrereq_HasMeleeLineOfSight : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	string m_meleeStartAttachmentName;
	float m_requiredTimeWithLineOfSight;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasMeleeLineOfSight();
	bool Evaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const { return FEvaluate(this, _npc, _params, _prereqInstance); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasMeleeLineOfSight& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1260F50);
	static inline auto FArkNpcAbilityPrereq_HasMeleeLineOfSight = PreyFunction<void(ArkNpcAbilityPrereq_HasMeleeLineOfSight* const _this)>(0x1260F00);
	static inline auto FEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereq_HasMeleeLineOfSight* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1260F90);
};
#endif // MOONCRASH
