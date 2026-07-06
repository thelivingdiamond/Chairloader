// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_LastAbilityPerformed
// Header:  Prey/GameDll/ark/npc/ability/prereq/lastabilityperformed/ArkNpcAbilityPrereq_LastAbilityPerformed.h
class ArkNpcAbilityPrereq_LastAbilityPerformed : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	uint64_t m_abilityId;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_LastAbilityPerformed();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_LastAbilityPerformed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132F7E0);
	static inline auto FArkNpcAbilityPrereq_LastAbilityPerformed = PreyFunction<void(ArkNpcAbilityPrereq_LastAbilityPerformed* const _this)>(0x132F740);
};
#endif // MOONCRASH
