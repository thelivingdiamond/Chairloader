// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MaxTargetDeltaHeight
// Header:  Prey/GameDll/ark/npc/ability/prereq/maxtargetdeltaheight/ArkNpcAbilityPrereq_MaxTargetDeltaHeight.h
class ArkNpcAbilityPrereq_MaxTargetDeltaHeight : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=48 (0x30)
public:
	float m_deltaHeight;
	string m_sourceBoneName;
	bool m_bUseTargetAttackPos;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MaxTargetDeltaHeight();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxTargetDeltaHeight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262EE0);
	static inline auto FArkNpcAbilityPrereq_MaxTargetDeltaHeight = PreyFunction<void(ArkNpcAbilityPrereq_MaxTargetDeltaHeight* const _this)>(0x1262D40);
};
#endif // MOONCRASH
