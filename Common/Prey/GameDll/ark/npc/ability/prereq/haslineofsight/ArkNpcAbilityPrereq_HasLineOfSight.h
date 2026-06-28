// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasLineOfSight
// Header:  Prey/GameDll/ark/npc/ability/prereq/haslineofsight/ArkNpcAbilityPrereq_HasLineOfSight.h
class ArkNpcAbilityPrereq_HasLineOfSight : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_requiredTimeWithLineOfSight;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasLineOfSight();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132E430);
	static inline auto FArkNpcAbilityPrereq_HasLineOfSight = PreyFunction<void(ArkNpcAbilityPrereq_HasLineOfSight* const _this)>(0x132E350);
};
#endif // MOONCRASH
