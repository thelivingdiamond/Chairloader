// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasHitReacted
// Header:  Prey/GameDll/ark/npc/ability/prereq/hashitreacted/ArkNpcAbilityPrereq_HasHitReacted.h
class ArkNpcAbilityPrereq_HasHitReacted : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_time;
	bool m_bStagger;
	bool m_bKnockDown;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasHitReacted();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasHitReacted& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132D270);
	static inline auto FArkNpcAbilityPrereq_HasHitReacted = PreyFunction<void(ArkNpcAbilityPrereq_HasHitReacted* const _this)>(0x132D230);
};
#endif // MOONCRASH
