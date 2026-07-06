// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsEtherFormRestricted
// Header:  Prey/GameDll/ark/npc/ability/prereq/isinetherform/ArkNpcAbilityPrereq_IsEtherFormRestricted.h
class ArkNpcAbilityPrereq_IsEtherFormRestricted : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsEtherFormRestricted();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsEtherFormRestricted& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12622C0);
	static inline auto FArkNpcAbilityPrereq_IsEtherFormRestricted = PreyFunction<void(ArkNpcAbilityPrereq_IsEtherFormRestricted* const _this)>(0x1262290);
};
#endif // MOONCRASH
