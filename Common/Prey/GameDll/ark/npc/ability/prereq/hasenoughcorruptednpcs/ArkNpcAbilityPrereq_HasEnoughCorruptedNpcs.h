// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasenoughcorruptednpcs/ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs.h
class ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	int m_requiredNumCorruptedNpcsInclusive;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125FAB0);
	static inline auto FArkNpcAbilityPrereq_HasEnoughCorruptedNpcs = PreyFunction<void(ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs* const _this)>(0x125FA50);
};
#endif // MOONCRASH
