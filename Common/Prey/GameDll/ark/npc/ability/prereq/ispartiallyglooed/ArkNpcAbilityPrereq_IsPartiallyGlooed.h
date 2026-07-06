// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsPartiallyGlooed
// Header:  Prey/GameDll/ark/npc/ability/prereq/ispartiallyglooed/ArkNpcAbilityPrereq_IsPartiallyGlooed.h
class ArkNpcAbilityPrereq_IsPartiallyGlooed : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_precentageGlooed;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsPartiallyGlooed();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsPartiallyGlooed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12626B0);
	static inline auto FArkNpcAbilityPrereq_IsPartiallyGlooed = PreyFunction<void(ArkNpcAbilityPrereq_IsPartiallyGlooed* const _this)>(0x1262630);
};
#endif // MOONCRASH
