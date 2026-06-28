// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsRegainingLoS
// Header:  Prey/GameDll/ark/npc/ability/prereq/isregaininglos/ArkNpcAbilityPrereq_IsRegainingLoS.h
class ArkNpcAbilityPrereq_IsRegainingLoS : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=24 (0x18)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsRegainingLoS();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsRegainingLoS& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262760);
	static inline auto FArkNpcAbilityPrereq_IsRegainingLoS = PreyFunction<void(ArkNpcAbilityPrereq_IsRegainingLoS* const _this)>(0x1262730);
};
#endif // MOONCRASH
