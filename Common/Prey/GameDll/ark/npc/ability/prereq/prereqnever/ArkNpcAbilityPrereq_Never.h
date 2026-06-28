// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkNpcAbilityPrereqTemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_Never
// Header:  Prey/GameDll/ark/npc/ability/prereq/prereqnever/ArkNpcAbilityPrereq_Never.h
class ArkNpcAbilityPrereq_Never : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_Never,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=24 (0x18)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_Never();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_Never& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132FCA0);
	static inline auto FArkNpcAbilityPrereq_Never = PreyFunction<void(ArkNpcAbilityPrereq_Never* const _this)>(0x132FC70);
};
#endif // MOONCRASH
