// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsInRangedRole
// Header:  Prey/GameDll/ark/npc/ability/prereq/isinrangedrole/ArkNpcAbilityPrereq_IsInRangedRole.h
class ArkNpcAbilityPrereq_IsInRangedRole : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsInRangedRole();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInRangedRole& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262480);
	static inline auto FArkNpcAbilityPrereq_IsInRangedRole = PreyFunction<void(ArkNpcAbilityPrereq_IsInRangedRole* const _this)>(0x1262420);
};
#endif // MOONCRASH
