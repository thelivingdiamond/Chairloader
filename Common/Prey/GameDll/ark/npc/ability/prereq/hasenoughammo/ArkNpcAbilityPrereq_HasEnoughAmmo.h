// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasEnoughAmmo
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasenoughammo/ArkNpcAbilityPrereq_HasEnoughAmmo.h
class ArkNpcAbilityPrereq_HasEnoughAmmo : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	unsigned m_requiredAmmo;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasEnoughAmmo();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEnoughAmmo& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125F9D0);
	static inline auto FArkNpcAbilityPrereq_HasEnoughAmmo = PreyFunction<void(ArkNpcAbilityPrereq_HasEnoughAmmo* const _this)>(0x125F940);
};
#endif // MOONCRASH
