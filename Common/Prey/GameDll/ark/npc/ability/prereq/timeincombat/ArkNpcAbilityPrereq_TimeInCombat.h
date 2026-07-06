// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_TimeInCombat
// Header:  Prey/GameDll/ark/npc/ability/prereq/timeincombat/ArkNpcAbilityPrereq_TimeInCombat.h
class ArkNpcAbilityPrereq_TimeInCombat : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_seconds;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_TimeInCombat();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_TimeInCombat& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1263A40);
	static inline auto FArkNpcAbilityPrereq_TimeInCombat = PreyFunction<void(ArkNpcAbilityPrereq_TimeInCombat* const _this)>(0x1263A10);
};
#endif // MOONCRASH
