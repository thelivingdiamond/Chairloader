// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereqmodifier/arknpcabilityprereqmodifiertemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;

// ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual
// Header:  Prey/GameDll/ark/npc/ability/prereqmodifier/addifdoomclocklevelequal/ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual.h
class ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual : public ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>
{ // Size=16 (0x10)
public:
	static const char* ClassName() { return FClassName(); }
	float GetValue() const { return FGetValue(this); }
	void SetValue(const float _value) { FSetValue(this, _value); }
	float GetModifier() const { return FGetModifier(this); }
	void SetModifier(const float _modifier) { FSetModifier(this, _modifier); }
	float GetConditionalValue(const ArkNpc& _npc, const ArkNpcAbilityParams& _params) const { return FGetConditionalValue(this, _npc, _params); }

	static inline auto FClassName = PreyFunction<const char* ()>(0x125E190);
	static inline auto FGetValue = PreyFunction<float(const ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual* const _this)>(0x15887B0);
	static inline auto FSetValue = PreyFunction<void(ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual* const _this, const float _value)>(0x1396E40);
	static inline auto FGetModifier = PreyFunction<float(const ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual* const _this)>(0x138B7A0);
	static inline auto FSetModifier = PreyFunction<void(ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual* const _this, const float _modifier)>(0x1396E30);
	static inline auto FGetConditionalValue = PreyFunction<float(const ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params)>(0x125E1A0);
};
#endif // MOONCRASH
