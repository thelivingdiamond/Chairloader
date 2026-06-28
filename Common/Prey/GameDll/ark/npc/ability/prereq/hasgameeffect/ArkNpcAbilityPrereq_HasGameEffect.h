// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasGameEffect
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasgameeffect/ArkNpcAbilityPrereq_HasGameEffect.h
class ArkNpcAbilityPrereq_HasGameEffect : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	bool m_bShouldHaveGameEffect;
	uint64_t m_requiredGameEffectId;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasGameEffect();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasGameEffect& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1260AB0);
	static inline auto FArkNpcAbilityPrereq_HasGameEffect = PreyFunction<void(ArkNpcAbilityPrereq_HasGameEffect* const _this)>(0x1260A30);
};
#endif // MOONCRASH
