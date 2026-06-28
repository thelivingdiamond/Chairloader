// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsOnSlope
// Header:  Prey/GameDll/ark/npc/ability/prereq/isonslope/ArkNpcAbilityPrereq_IsOnSlope.h
class ArkNpcAbilityPrereq_IsOnSlope : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_minDegree;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsOnSlope();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsOnSlope& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12625C0);
	static inline auto FArkNpcAbilityPrereq_IsOnSlope = PreyFunction<void(ArkNpcAbilityPrereq_IsOnSlope* const _this)>(0x1262590);
};
#endif // MOONCRASH
