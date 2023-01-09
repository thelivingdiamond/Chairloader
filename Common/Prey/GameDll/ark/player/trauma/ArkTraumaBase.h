// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/ArkTraumas.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

struct IMaterial;

// ArkTraumaBase
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaBase.h
class ArkTraumaBase
{ // Size=296 (0x128)
public:
	using TActiveModifier = std::pair<unsigned int, bool>;

	const uint64_t m_id;
	const EArkPlayerStatus m_status;
	bool m_bIsSuspended;
	float m_currentAmount;
	float m_prevActivationAmount;
	int m_currentLevel;
	ArkSimpleTimer m_hudIconTimer;
	ArkTrauma m_desc;
	float m_maxAccumulation;
	ArkAudioTrigger m_traumaSFX;
	ArkAudioTrigger m_traumaStopSFX;
	ArkRandomizedAutoResetTimer m_repeatTimer;
	ArkSimpleTimer m_traumaTimer;
	IMaterial* m_pBlendMaterial;
	std::vector<std::pair<unsigned int, bool>> m_activeStatModifiers;
	const CCryName m_activationChanceStat;

	ArkTraumaBase(uint64_t _id, EArkPlayerStatus _status);
	virtual ~ArkTraumaBase();
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(float _frameTime);
	virtual void Accumulate(float _damage);
	bool CanActivate(int _level) const { return FCanActivate(this, _level); }
	virtual void Activate(int _level);
	virtual void ForceRemove(bool _bImmediate);
	virtual void ReduceAccumulation(float _amount, bool _bImmediate);
	virtual void Suspend();
	virtual void Resume();
	bool IsSuspended() const { return FIsSuspended(this); }
	virtual void Reset();
	float GetPercent() const { return FGetPercent(this); }
	virtual bool IsHarmful() const;
	virtual bool IsMedical() const;
	virtual bool ShowDamageIndicator() const;
	void PlayPostEffect(float _param, bool _bFromSerialize) const { FPlayPostEffect(this, _param, _bFromSerialize); }
	virtual float GetMinPostEffectParamValue() const;
	virtual bool IsEnabled() const;
	virtual bool CanStack(float _amount) const;
	virtual void ReevaluatePhase(bool _bImmediate);
	void RemovePhase(int _phase) { FRemovePhase(this, _phase); }
	void CleanUp(bool _bSilent) { FCleanUp(this, _bSilent); }
	void ApplyTraumaEffects(bool _bFromSerialize) { FApplyTraumaEffects(this, _bFromSerialize); }
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);
	void RemoveHudIcon(int _phase) { FRemoveHudIcon(this, _phase); }
	void UpdateHudIcon() { FUpdateHudIcon(this); }
	void LoadConfig() { FLoadConfig(this); }
	virtual void ApplyStatModifiers();
	virtual void ResumeStatModifiers();
	void ApplySignalModifiers() { FApplySignalModifiers(this); }
	virtual void Stack();
	virtual void RepeatEffect();

#if 0
	EArkPlayerStatus GetStatus() const;
	const ArkTrauma& GetDesc() const;
	float GetCurrentAmount() const;
	int GetCurrentLevel() const;
	bool IsActive() const;
	void DisablePostEffect(bool _arg0_);
	void SetAnimationTag();
#endif

	static inline auto FArkTraumaBaseOv1 = PreyFunction<void(ArkTraumaBase* const _this, uint64_t _id, EArkPlayerStatus _status)>(0x15AF070);
	static inline auto FBitNotArkTraumaBase = PreyFunction<void(ArkTraumaBase* const _this)>(0x12F6C30);
	static inline auto FSerialize = PreyFunction<void(ArkTraumaBase* const _this, TSerialize _ser)>(0x15B0620);
	static inline auto FPostSerialize = PreyFunction<void(ArkTraumaBase* const _this)>(0x15B00C0);
	static inline auto FUpdate = PreyFunction<void(ArkTraumaBase* const _this, float _frameTime)>(0x15B0A80);
	static inline auto FAccumulate = PreyFunction<void(ArkTraumaBase* const _this, float _damage)>(0x15AF390);
	static inline auto FCanActivate = PreyFunction<bool(const ArkTraumaBase* const _this, int _level)>(0x15AFA60);
	static inline auto FActivate = PreyFunction<void(ArkTraumaBase* const _this, int _level)>(0x15AF550);
	static inline auto FForceRemove = PreyFunction<void(ArkTraumaBase* const _this, bool _bImmediate)>(0x15AFBA0);
	static inline auto FReduceAccumulation = PreyFunction<void(ArkTraumaBase* const _this, float _amount, bool _bImmediate)>(0x15B0110);
	static inline auto FSuspend = PreyFunction<void(ArkTraumaBase* const _this)>(0x15B08A0);
	static inline auto FResume = PreyFunction<void(ArkTraumaBase* const _this)>(0x15B0410);
	static inline auto FIsSuspended = PreyFunction<bool(const ArkTraumaBase* const _this)>(0x1142110);
	static inline auto FReset = PreyFunction<void(ArkTraumaBase* const _this)>(0x15B03D0);
	static inline auto FGetPercent = PreyFunction<float(const ArkTraumaBase* const _this)>(0x15AFC10);
	static inline auto FIsHarmful = PreyFunction<bool(const ArkTraumaBase* const _this)>(0x1B933B0);
	static inline auto FIsMedical = PreyFunction<bool(const ArkTraumaBase* const _this)>(0x1B933B0);
	static inline auto FShowDamageIndicator = PreyFunction<bool(const ArkTraumaBase* const _this)>(0xDD23F0);
	static inline auto FPlayPostEffect = PreyFunction<void(const ArkTraumaBase* const _this, float _param, bool _bFromSerialize)>(0x15AFFB0);
	static inline auto FGetMinPostEffectParamValue = PreyFunction<float(const ArkTraumaBase* const _this)>(0x1734A90);
	static inline auto FIsEnabled = PreyFunction<bool(const ArkTraumaBase* const _this)>(0x15AFC80);
	static inline auto FCanStack = PreyFunction<bool(const ArkTraumaBase* const _this, float _amount)>(0x3A0320);
	static inline auto FReevaluatePhase = PreyFunction<void(ArkTraumaBase* const _this, bool _bImmediate)>(0x15B01A0);
	static inline auto FRemovePhase = PreyFunction<void(ArkTraumaBase* const _this, int _phase)>(0x15B02B0);
	static inline auto FCleanUp = PreyFunction<void(ArkTraumaBase* const _this, bool _bSilent)>(0x15AFAA0);
	static inline auto FApplyTraumaEffects = PreyFunction<void(ArkTraumaBase* const _this, bool _bFromSerialize)>(0x15AF980);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaBase* const _this, bool _bImmediate, bool _bFromSerialize)>(0x15B0DA0);
	static inline auto FRemoveHudIcon = PreyFunction<void(ArkTraumaBase* const _this, int _phase)>(0x15B0260);
	static inline auto FUpdateHudIcon = PreyFunction<void(ArkTraumaBase* const _this)>(0x15B0C00);
	static inline auto FLoadConfig = PreyFunction<void(ArkTraumaBase* const _this)>(0x15AFCE0);
	static inline auto FApplyStatModifiers = PreyFunction<void(ArkTraumaBase* const _this)>(0x15AF840);
	static inline auto FResumeStatModifiers = PreyFunction<void(ArkTraumaBase* const _this)>(0x15B04D0);
	static inline auto FApplySignalModifiers = PreyFunction<void(ArkTraumaBase* const _this)>(0x15AF7C0);
	static inline auto FStack = PreyFunction<void(ArkTraumaBase* const _this)>(0x15B0890);
	static inline auto FRepeatEffect = PreyFunction<void(ArkTraumaBase* const _this)>(0x15B03B0);
};

