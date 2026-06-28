// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_CanCorrupt
// Header:  Prey/GameDll/ark/npc/ability/prereq/cancorrupt/ArkNpcAbilityPrereq_CanCorrupt.h
class ArkNpcAbilityPrereq_CanCorrupt : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=24 (0x18)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_CanCorrupt();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_CanCorrupt& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E620);
	static inline auto FArkNpcAbilityPrereq_CanCorrupt = PreyFunction<void(ArkNpcAbilityPrereq_CanCorrupt* const _this)>(0x125E5F0);
};
#endif // MOONCRASH
