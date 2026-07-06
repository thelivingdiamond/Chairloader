// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_LostLineOfSight
// Header:  Prey/GameDll/ark/npc/ability/prereq/haslineofsight/ArkNpcAbilityPrereq_LostLineOfSight.h
class ArkNpcAbilityPrereq_LostLineOfSight : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_requiredTimeWithoutLoS;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_LostLineOfSight();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_LostLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12613D0);
	static inline auto FArkNpcAbilityPrereq_LostLineOfSight = PreyFunction<void(ArkNpcAbilityPrereq_LostLineOfSight* const _this)>(0x12613A0);
};
#endif // MOONCRASH
