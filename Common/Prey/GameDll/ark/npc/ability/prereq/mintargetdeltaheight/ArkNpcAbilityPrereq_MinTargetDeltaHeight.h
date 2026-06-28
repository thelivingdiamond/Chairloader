// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MinTargetDeltaHeight
// Header:  Prey/GameDll/ark/npc/ability/prereq/mintargetdeltaheight/ArkNpcAbilityPrereq_MinTargetDeltaHeight.h
class ArkNpcAbilityPrereq_MinTargetDeltaHeight : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=48 (0x30)
public:
	float m_deltaHeight;
	string m_sourceBoneName;
	bool m_bUseTargetAttackPos;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MinTargetDeltaHeight();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MinTargetDeltaHeight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1263140);
	static inline auto FArkNpcAbilityPrereq_MinTargetDeltaHeight = PreyFunction<void(ArkNpcAbilityPrereq_MinTargetDeltaHeight* const _this)>(0x1263100);
};
#endif // MOONCRASH
