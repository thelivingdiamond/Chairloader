// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_AreaHasMaxNumCystoids
// Header:  Prey/GameDll/ark/npc/ability/prereq/areahasmaxnumcystoids/ArkNpcAbilityPrereq_AreaHasMaxNumCystoids.h
class ArkNpcAbilityPrereq_AreaHasMaxNumCystoids : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_AreaHasMaxNumCystoids();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_AreaHasMaxNumCystoids& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E570);
	static inline auto FArkNpcAbilityPrereq_AreaHasMaxNumCystoids = PreyFunction<void(ArkNpcAbilityPrereq_AreaHasMaxNumCystoids* const _this)>(0x125E540);
};
#endif // MOONCRASH
