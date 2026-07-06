// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_IsInEtherForm
// Header:  Prey/GameDll/ark/npc/ability/prereq/isinetherform/ArkNpcAbilityPrereq_IsInEtherForm.h
class ArkNpcAbilityPrereq_IsInEtherForm : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_IsInEtherForm();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInEtherForm& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262320);
	static inline auto FArkNpcAbilityPrereq_IsInEtherForm = PreyFunction<void(ArkNpcAbilityPrereq_IsInEtherForm* const _this)>(0x12622F0);
};
#endif // MOONCRASH
