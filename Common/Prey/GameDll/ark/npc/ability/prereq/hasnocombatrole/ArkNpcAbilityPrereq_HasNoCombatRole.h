// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasNoCombatRole
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasnocombatrole/ArkNpcAbilityPrereq_HasNoCombatRole.h
class ArkNpcAbilityPrereq_HasNoCombatRole : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasNoCombatRole();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasNoCombatRole& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1261570);
	static inline auto FArkNpcAbilityPrereq_HasNoCombatRole = PreyFunction<void(ArkNpcAbilityPrereq_HasNoCombatRole* const _this)>(0x1261540);
};
#endif // MOONCRASH
