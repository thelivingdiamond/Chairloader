// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasEnoughControlledTurrets
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasenoughcontrolledturrets/ArkNpcAbilityPrereq_HasEnoughControlledTurrets.h
class ArkNpcAbilityPrereq_HasEnoughControlledTurrets : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	int m_requiredNumTurretsInclusive;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasEnoughControlledTurrets();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEnoughControlledTurrets& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125FA40);
	static inline auto FArkNpcAbilityPrereq_HasEnoughControlledTurrets = PreyFunction<void(ArkNpcAbilityPrereq_HasEnoughControlledTurrets* const _this)>(0x125F9E0);
};
#endif // MOONCRASH
