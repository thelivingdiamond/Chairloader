// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsInMeleeRole
// Header:  Prey/GameDll/ark/npc/ability/prereq/isinmeleerole/ArkNpcAbilityPrereq_IsInMeleeRole.h
class ArkNpcAbilityPrereq_IsInMeleeRole : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsInMeleeRole();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInMeleeRole& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12623E0);
	static inline auto FArkNpcAbilityPrereq_IsInMeleeRole = PreyFunction<void(ArkNpcAbilityPrereq_IsInMeleeRole* const _this)>(0x12623B0);
};
#endif // MOONCRASH
