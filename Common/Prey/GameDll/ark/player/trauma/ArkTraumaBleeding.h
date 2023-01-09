// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>
#include <Prey/GameDll/ark/player/ArkAudioSwitch.h>

// ArkTraumaBleeding
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaBleeding.h
class ArkTraumaBleeding : public ArkTraumaBase
{ // Size=600 (0x258)
public:
	enum class EAudioBleed
	{
		off = 0,
		on = 1,
		count = 2,
	};

	ArkAutoResetTimer m_activeDrainTimer;
	EntityEffects::CEffectsController m_bleedParticleController;
	ArkEntityAttachmentEffect m_bleedParticle;
	ArkEntityPointerEffect m_screenParticle;
	ArkSimpleTimer m_screenParticleTimer;
	TArkAudioSwitch<enum ArkTraumaBleeding::EAudioBleed> m_stepSwitch;
	ArkAudioTrigger m_stackSFX;
	ArkAudioTrigger m_damageSFX;
	ArkAudioTrigger m_gruntSFX;

	ArkTraumaBleeding();
	virtual ~ArkTraumaBleeding();
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(float _frameTime);
	virtual void Activate(int _level);
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);
	static void UpdateHealthUI(float _bleedIndicator, float _maxHealth) { FUpdateHealthUI(_bleedIndicator, _maxHealth); }
	virtual float GetMinPostEffectParamValue() const;
	void PulseDamage() { FPulseDamage(this); }
	virtual void Stack();
	virtual void ApplyStatModifiers();
	virtual void ResumeStatModifiers();
	void StatModHelper(float _amount) { FStatModHelper(this, _amount); }

	static inline auto FArkTraumaBleedingOv1 = PreyFunction<void(ArkTraumaBleeding* const _this)>(0x132B790);
	static inline auto FSerialize = PreyFunction<void(ArkTraumaBleeding* const _this, TSerialize _ser)>(0x132BC00);
	static inline auto FPostSerialize = PreyFunction<void(ArkTraumaBleeding* const _this)>(0x132BB10);
	static inline auto FUpdate = PreyFunction<void(ArkTraumaBleeding* const _this, float _frameTime)>(0x132C010);
	static inline auto FActivate = PreyFunction<void(ArkTraumaBleeding* const _this, int _level)>(0x132BA10);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaBleeding* const _this, bool _bImmediate, bool _bFromSerialize)>(0x132C1A0);
	static inline auto FUpdateHealthUI = PreyFunction<void(float _bleedIndicator, float _maxHealth)>(0x132C0E0);
	static inline auto FGetMinPostEffectParamValue = PreyFunction<float(const ArkTraumaBleeding* const _this)>(0x132BB00);
	static inline auto FPulseDamage = PreyFunction<void(ArkTraumaBleeding* const _this)>(0x132BB70);
	static inline auto FStack = PreyFunction<void(ArkTraumaBleeding* const _this)>(0x132BE00);
	static inline auto FApplyStatModifiers = PreyFunction<void(ArkTraumaBleeding* const _this)>(0x132BAF0);
	static inline auto FResumeStatModifiers = PreyFunction<void(ArkTraumaBleeding* const _this)>(0x132BBF0);
	static inline auto FStatModHelper = PreyFunction<void(ArkTraumaBleeding* const _this, float _amount)>(0x132BE50);
};

