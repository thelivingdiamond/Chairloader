// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// Header: FromCpp
// Prey/GameDll/ark/player/trauma/ArkTraumaBurns.h
class ArkTraumaBurns : public ArkTraumaBase // Id=801C0B4 Size=512
{
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
	virtual ~ArkTraumaBurns();
	
#if 0
	float ModifyDamage(float arg0) const;
#endif
	
	static inline auto FAccumulate = PreyFunction<void(ArkTraumaBurns *const _this, float _damage)>(0x15B10F0);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaBurns *const _this, bool _bImmediate, bool _bFromSerialize)>(0x15B13A0);
	static inline auto FStack = PreyFunction<void(ArkTraumaBurns *const _this)>(0x15B1370);
	static inline auto FApplyStatModifiers = PreyFunction<void(ArkTraumaBurns *const _this)>(0x15B1200);
	static inline auto FShowDamageIndicator = PreyFunction<bool(ArkTraumaBurns const *const _this)>(0x1B933B0);
};

