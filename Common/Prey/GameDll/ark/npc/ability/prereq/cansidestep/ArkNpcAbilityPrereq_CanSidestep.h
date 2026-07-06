// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_CanSidestep
// Header:  Prey/GameDll/ark/npc/ability/prereq/cansidestep/ArkNpcAbilityPrereq_CanSidestep.h
class ArkNpcAbilityPrereq_CanSidestep : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	float m_traceDistance;
	float m_traceHeightBias;
	float m_traceRadius;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_CanSidestep();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_CanSidestep& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E7F0);
	static inline auto FArkNpcAbilityPrereq_CanSidestep = PreyFunction<void(ArkNpcAbilityPrereq_CanSidestep* const _this)>(0x125E760);
};
#endif // MOONCRASH
