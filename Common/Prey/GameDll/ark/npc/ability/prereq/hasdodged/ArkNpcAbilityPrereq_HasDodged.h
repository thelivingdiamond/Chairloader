// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasDodged
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasdodged/ArkNpcAbilityPrereq_HasDodged.h
class ArkNpcAbilityPrereq_HasDodged : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_time;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasDodged();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasDodged& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125F930);
	static inline auto FArkNpcAbilityPrereq_HasDodged = PreyFunction<void(ArkNpcAbilityPrereq_HasDodged* const _this)>(0x125F890);
};
#endif // MOONCRASH
