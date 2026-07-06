// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsTargetArmed
// Header:  Prey/GameDll/ark/npc/ability/prereq/istargetarmed/ArkNpcAbilityPrereq_IsTargetArmed.h
class ArkNpcAbilityPrereq_IsTargetArmed : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_minArmedTime;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsTargetArmed();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTargetArmed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12627B0);
	static inline auto FArkNpcAbilityPrereq_IsTargetArmed = PreyFunction<void(ArkNpcAbilityPrereq_IsTargetArmed* const _this)>(0x1262780);
};
#endif // MOONCRASH
