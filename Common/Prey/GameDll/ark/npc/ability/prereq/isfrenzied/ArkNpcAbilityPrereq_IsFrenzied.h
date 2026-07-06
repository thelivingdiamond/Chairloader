// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsFrenzied
// Header:  Prey/GameDll/ark/npc/ability/prereq/isfrenzied/ArkNpcAbilityPrereq_IsFrenzied.h
class ArkNpcAbilityPrereq_IsFrenzied : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsFrenzied();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsFrenzied& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12621B0);
	static inline auto FArkNpcAbilityPrereq_IsFrenzied = PreyFunction<void(ArkNpcAbilityPrereq_IsFrenzied* const _this)>(0x1262150);
};
#endif // MOONCRASH
