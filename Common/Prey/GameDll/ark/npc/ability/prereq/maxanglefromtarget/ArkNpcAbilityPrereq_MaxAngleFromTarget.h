// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_MaxAngleFromTarget
// Header:  Prey/GameDll/ark/npc/ability/prereq/maxanglefromtarget/ArkNpcAbilityPrereq_MaxAngleFromTarget.h
class ArkNpcAbilityPrereq_MaxAngleFromTarget : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_angle;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_MaxAngleFromTarget();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxAngleFromTarget& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262C70);
	static inline auto FArkNpcAbilityPrereq_MaxAngleFromTarget = PreyFunction<void(ArkNpcAbilityPrereq_MaxAngleFromTarget* const _this)>(0x1262BE0);
};
#endif // MOONCRASH
