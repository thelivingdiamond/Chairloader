// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_LastAbilityContextPerformed
// Header:  Prey/GameDll/ark/npc/ability/prereq/lastabilitycontextperformed/ArkNpcAbilityPrereq_LastAbilityContextPerformed.h
class ArkNpcAbilityPrereq_LastAbilityContextPerformed : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	uint64_t m_contextId;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_LastAbilityContextPerformed();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_LastAbilityContextPerformed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132F720);
	static inline auto FArkNpcAbilityPrereq_LastAbilityContextPerformed = PreyFunction<void(ArkNpcAbilityPrereq_LastAbilityContextPerformed* const _this)>(0x132F680);
};
#endif // MOONCRASH
