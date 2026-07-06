// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsInLowG
// Header:  Prey/GameDll/ark/npc/ability/prereq/isinlowg/ArkNpcAbilityPrereq_IsInLowG.h
class ArkNpcAbilityPrereq_IsInLowG : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsInLowG();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInLowG& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262370);
	static inline auto FArkNpcAbilityPrereq_IsInLowG = PreyFunction<void(ArkNpcAbilityPrereq_IsInLowG* const _this)>(0x1262340);
};
#endif // MOONCRASH
