// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_CanEnterButtonMashSequence
// Header:  Prey/GameDll/ark/npc/ability/prereq/canenterbuttonmashsequence/ArkNpcAbilityPrereq_CanEnterButtonMashSequence.h
class ArkNpcAbilityPrereq_CanEnterButtonMashSequence : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_CanEnterButtonMashSequence();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_CanEnterButtonMashSequence& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E670);
	static inline auto FArkNpcAbilityPrereq_CanEnterButtonMashSequence = PreyFunction<void(ArkNpcAbilityPrereq_CanEnterButtonMashSequence* const _this)>(0x125E640);
};
#endif // MOONCRASH
