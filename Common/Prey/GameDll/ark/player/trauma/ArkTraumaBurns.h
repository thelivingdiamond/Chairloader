// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaBurns
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaBurns.h
class ArkTraumaBurns : public ArkTraumaBase
{ // Size=512 (0x200)
public:
	ArkEntityAttachmentEffect m_smokeVFXRight;
	ArkEntityAttachmentEffect m_smokeVFXLeft;
	EntityEffects::CEffectsController m_smokeVFXController;

	ArkTraumaBurns();
	virtual void Accumulate(float _damage);
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);
	virtual void Stack();
	virtual void ApplyStatModifiers();
	virtual bool ShowDamageIndicator() const;

#if 0
	float ModifyDamage(float _arg0_) const;
#endif

	static inline auto FArkTraumaBurnsOv2 = PreyFunction<void(ArkTraumaBurns* const _this)>(0x15B0F90);
	static inline auto FAccumulate = PreyFunction<void(ArkTraumaBurns* const _this, float _damage)>(0x15B10F0);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaBurns* const _this, bool _bImmediate, bool _bFromSerialize)>(0x15B13A0);
	static inline auto FStack = PreyFunction<void(ArkTraumaBurns* const _this)>(0x15B1370);
	static inline auto FApplyStatModifiers = PreyFunction<void(ArkTraumaBurns* const _this)>(0x15B1200);
	static inline auto FShowDamageIndicator = PreyFunction<bool(const ArkTraumaBurns* const _this)>(0x1B933B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaBurns
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaBurns.h
class ArkTraumaBurns : public ArkTraumaBase
{ // Size=544 (0x220)
public:
	ArkEntityAttachmentEffect m_smokeVFXRight;
	ArkEntityAttachmentEffect m_smokeVFXLeft;
	EntityEffects::CEffectsController m_smokeVFXController;

	ArkTraumaBurns();
	virtual void Accumulate(float _damage);
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);
	virtual void Stack();
	virtual void ApplyStatModifiers();
	virtual bool ShowDamageIndicator() const;

#if 0
	float ModifyDamage(float _arg0_) const;
#endif

	static inline auto FArkTraumaBurnsOv2 = PreyFunction<void(ArkTraumaBurns* const _this)>(0x16D5330);
	static inline auto FAccumulate = PreyFunction<void(ArkTraumaBurns* const _this, float _damage)>(0x16D5490);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaBurns* const _this, bool _bImmediate, bool _bFromSerialize)>(0x16D5740);
	static inline auto FStack = PreyFunction<void(ArkTraumaBurns* const _this)>(0x16D5710);
	static inline auto FApplyStatModifiers = PreyFunction<void(ArkTraumaBurns* const _this)>(0x16D55A0);
	static inline auto FShowDamageIndicator = PreyFunction<bool(const ArkTraumaBurns* const _this)>(0x1A302A0);
};
#endif // !MOONCRASH
