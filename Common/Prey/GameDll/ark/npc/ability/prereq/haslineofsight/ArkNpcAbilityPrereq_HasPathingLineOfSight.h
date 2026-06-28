// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasPathingLineOfSight
// Header:  Prey/GameDll/ark/npc/ability/prereq/haslineofsight/ArkNpcAbilityPrereq_HasPathingLineOfSight.h
class ArkNpcAbilityPrereq_HasPathingLineOfSight : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasPathingLineOfSight();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasPathingLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132E470);
	static inline auto FArkNpcAbilityPrereq_HasPathingLineOfSight = PreyFunction<void(ArkNpcAbilityPrereq_HasPathingLineOfSight* const _this)>(0x132E440);
};
#endif // MOONCRASH
