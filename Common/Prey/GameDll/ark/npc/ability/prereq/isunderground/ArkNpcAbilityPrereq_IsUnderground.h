// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsUnderground
// Header:  Prey/GameDll/ark/npc/ability/prereq/isunderground/ArkNpcAbilityPrereq_IsUnderground.h
class ArkNpcAbilityPrereq_IsUnderground : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsUnderground();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsUnderground& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262990);
	static inline auto FArkNpcAbilityPrereq_IsUnderground = PreyFunction<void(ArkNpcAbilityPrereq_IsUnderground* const _this)>(0x1262960);
};
#endif // MOONCRASH
