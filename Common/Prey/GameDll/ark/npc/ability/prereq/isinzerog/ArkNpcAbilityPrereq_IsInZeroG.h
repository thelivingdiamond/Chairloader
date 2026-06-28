// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsInZeroG
// Header:  Prey/GameDll/ark/npc/ability/prereq/isinzerog/ArkNpcAbilityPrereq_IsInZeroG.h
class ArkNpcAbilityPrereq_IsInZeroG : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsInZeroG();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInZeroG& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12624C0);
	static inline auto FArkNpcAbilityPrereq_IsInZeroG = PreyFunction<void(ArkNpcAbilityPrereq_IsInZeroG* const _this)>(0x1262490);
};
#endif // MOONCRASH
