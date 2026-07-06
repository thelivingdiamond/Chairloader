// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkNpc;
class ArkNpcAbilityParams;

// ArkNpcAbilityPrereqModifier
// Header:  Prey/GameDll/ark/npc/ability/prereqmodifier/ArkNpcAbilityPrereqModifier.h
class ArkNpcAbilityPrereqModifier
{ // Size=8 (0x8)
public:
	virtual ~ArkNpcAbilityPrereqModifier();
	bool SortsBefore(const ArkNpcAbilityPrereqModifier& _other) const { return FSortsBefore(this, _other); }
	float Modify(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value) const { return FModify(this, _npc, _params, _value); }
	virtual const char* DoGetClassName() const = 0;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereqModifier& _other) const = 0;
	virtual float DoModify(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value) const = 0;

#if 0
	const char* GetClassName() const;
	ArkNpcAbilityPrereqModifier();
#endif

	static inline auto FSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqModifier* const _this, const ArkNpcAbilityPrereqModifier& _other)>(0x125E240);
	static inline auto FModify = PreyFunction<float(const ArkNpcAbilityPrereqModifier* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value)>(0x1338520);
};
#endif // MOONCRASH
