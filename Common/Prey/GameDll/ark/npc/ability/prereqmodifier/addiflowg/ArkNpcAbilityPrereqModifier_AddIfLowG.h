// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereqmodifier/arknpcabilityprereqmodifiertemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;

// ArkNpcAbilityPrereqModifier_AddIfLowG
// Header:  Prey/GameDll/ark/npc/ability/prereqmodifier/addiflowg/ArkNpcAbilityPrereqModifier_AddIfLowG.h
class ArkNpcAbilityPrereqModifier_AddIfLowG : public ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfLowG,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>
{ // Size=16 (0x10)
public:
	static const char* ClassName() { return FClassName(); }
	float GetValue() const { return FGetValue(this); }
	void SetValue(const float _value) { FSetValue(this, _value); }
	float GetModifier() const { return FGetModifier(this); }
	void SetModifier(const float _modifier) { FSetModifier(this, _modifier); }
	float GetConditionalValue(const ArkNpc& _npc, const ArkNpcAbilityParams& _params) const { return FGetConditionalValue(this, _npc, _params); }

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E1F0);
	static inline auto FGetValue = PreyFunction<float(const ArkNpcAbilityPrereqModifier_AddIfLowG* const _this)>(0x15887B0);
	static inline auto FSetValue = PreyFunction<void(ArkNpcAbilityPrereqModifier_AddIfLowG* const _this, const float _value)>(0x1396E40);
	static inline auto FGetModifier = PreyFunction<float(const ArkNpcAbilityPrereqModifier_AddIfLowG* const _this)>(0x138B7A0);
	static inline auto FSetModifier = PreyFunction<void(ArkNpcAbilityPrereqModifier_AddIfLowG* const _this, const float _modifier)>(0x1396E30);
	static inline auto FGetConditionalValue = PreyFunction<float(const ArkNpcAbilityPrereqModifier_AddIfLowG* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params)>(0x125E200);
};
#endif // MOONCRASH
