// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MaxAngleToTarget
// Header:  Prey/GameDll/ark/npc/ability/prereq/maxangletotarget/ArkNpcAbilityPrereq_MaxAngleToTarget.h
class ArkNpcAbilityPrereq_MaxAngleToTarget : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_angle;
	bool m_bUseHeadDirection;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MaxAngleToTarget();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxAngleToTarget& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132F820);
	static inline auto FArkNpcAbilityPrereq_MaxAngleToTarget = PreyFunction<void(ArkNpcAbilityPrereq_MaxAngleToTarget* const _this)>(0x132F7F0);
};
#endif // MOONCRASH
