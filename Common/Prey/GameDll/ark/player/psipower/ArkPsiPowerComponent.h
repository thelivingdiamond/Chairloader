// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>

class ArkAbility;
class CCryName;
class IArkPsiPower;
struct IParticleEffect;
class XmlNodeRef;

// ArkPsiTargetingData
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerComponent.h
class ArkPsiTargetingData
{ // Size=72 (0x48)
public:
	float m_targetDepth;
	string m_targetAttachmentName;
	float m_depthControlSpeed;
	float m_collisionRadius;
	float m_individualTargetingAngle;
	float m_minSizeForCrosshair;
	float m_audioTriggerCooldownSec;
	bool m_bShowHudTargetInfo;
	IParticleEffect* m_pParticleEffect;
	IParticleEffect* m_pCrosshairEffect;
	IParticleEffect* m_pTargetParticleEffect;
	ArkAudioTrigger m_triggerCycleTarget;

	void Initialize(const XmlNodeRef _root) { FInitialize(this, _root); }

#if 0
	ArkPsiTargetingData();
#endif

	static inline auto FInitialize = PreyFunction<void(ArkPsiTargetingData* const _this, const XmlNodeRef _root)>(0x158B2F0);
};

// ArkPsiPowerComponent
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerComponent.h
class ArkPsiPowerComponent : public IArkStatsListener
{ // Size=648 (0x288)
public:
	ArkSimpleTimer m_jumpTimer;
	ArkSimpleTimer m_sneakTimer;
	CTimeValue m_selectAudioTriggerTimeStamp;
	CTimeValue m_unselectAudioTriggerTimeStamp;
	ArkAudioTrigger m_startLoopSoundTrigger;
	ArkAudioTrigger m_stopLoopSoundTrigger;
	ArkAudioTrigger m_selectTargetTrigger;
	ArkAudioTrigger m_unselectTargetTrigger;
	ArkAudioTrigger m_cooldownFinishedTrigger;
	ArkAudioTrigger m_activatePowerFailTrigger;
	std::array<std::unique_ptr<IArkPsiPower,std::default_delete<IArkPsiPower> >,16> m_powers;
	std::unordered_map<unsigned int, int> m_selectedUITargetIds;
	std::unordered_map<unsigned int, int> m_unselectedUITargetIds;
	ArkInputLegend m_targetingLegend;
	ArkInputLegend m_mimicTargetingLegend;
	ArkInputLegend m_targetingLegendZeroG;
	ArkInputLegend m_mimicTargetingLegendZeroG;
	ArkInputLegendHandler m_targetingHandler;
	ArkInputLegendHandler m_modalHandler;
	ArkPsiTargetingData m_targetingData;
	string m_selectionHelpText;
	string m_selectedUIFormat;
	string m_unselectedUIFormat;
	string m_playerParticleEffectPath;
	EArkPsiPowers m_selectedPower;
	EArkPsiPowers m_equippedPower;
	EArkPsiPowers m_modalLegendPower;
	std::vector<enum::EArkPsiPowers> m_latentPowers;
	bool m_bPreventWeaponFireOnHold;
	bool m_bTargetedPowersDisabled;
	bool m_bEnabled;
	int m_inputHandle;
	float m_zoomMinDepth;
	float m_zoomMaxDepth;
	float m_zoomMinHFOV;
	float m_zoomMaxHFOV;
	float m_zoomInterpTime;
	float m_zoomTimer;
	float m_cooldownScale;
	int m_zoomHandle;
	int m_enablePlayerPsiModeMaterialCount;

	ArkPsiPowerComponent();
	virtual ~ArkPsiPowerComponent();
	void ProcessInput(const CCryName& _actionId, int _activationMode, float _value) { FProcessInput(this, _actionId, _activationMode, _value); }
	void Reset() { FReset(this); }
	void Update(const float _fFrameTime) { FUpdate(this, _fFrameTime); }
	void UpdateHUDMarkerElements() { FUpdateHUDMarkerElements(this); }
	void RegisterLatentPower(EArkPsiPowers _power) { FRegisterLatentPower(this, _power); }
	void UnregisterLatentPower(EArkPsiPowers _power) { FUnregisterLatentPower(this, _power); }
	bool UnlockPower(EArkPsiPowers _powerEnum, const int _level) { return FUnlockPower(this, _powerEnum, _level); }
	void LockPower(EArkPsiPowers _powerEnum) { FLockPower(this, _powerEnum); }
	int GetPowerLevel(const EArkPsiPowers _power) const { return FGetPowerLevel(this, _power); }
	bool IsPowerLocked(const EArkPsiPowers _power, const int _level) const { return FIsPowerLocked(this, _power, _level); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	IArkPsiPower* GetIArkPsiPower(const EArkPsiPowers _power) { return FGetIArkPsiPowerOv1(this, _power); }
	const IArkPsiPower* GetIArkPsiPower(const EArkPsiPowers _power) const { return FGetIArkPsiPowerOv0(this, _power); }
	bool IsPowerActive(const EArkPsiPowers _power) const { return FIsPowerActive(this, _power); }
	bool IsPowerTargeting(const EArkPsiPowers _power) const { return FIsPowerTargeting(this, _power); }
	string GetIconForPower(EArkPsiPowers _power) const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetIconForPower(this, reinterpret_cast<string*>(_return_buf_), _power); }
	void ClearSelectedPower() { FClearSelectedPower(this); }
	void ClearEquippedPower() { FClearEquippedPower(this); }
	bool SelectPower(const EArkPsiPowers _power) { return FSelectPower(this, _power); }
	bool ActivateSelectedPower() { return FActivateSelectedPower(this); }
	void StopLatentPowers() { FStopLatentPowers(this); }
	void OnLevelToLevelTransition() { FOnLevelToLevelTransition(this); }
	void DisableTargetedPowers(const bool _bDisable) { FDisableTargetedPowers(this, _bDisable); }
	void Stop() { FStop(this); }
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	std::vector<enum::EArkPsiPowers> GetUnlockedPowers() const { alignas(std::vector<enum::EArkPsiPowers>) std::byte _return_buf_[sizeof(std::vector<enum::EArkPsiPowers>)]; return *FGetUnlockedPowers(this, reinterpret_cast<std::vector<enum::EArkPsiPowers>*>(_return_buf_)); }
	void RefreshTargetingHandler(const bool _bZeroG) { FRefreshTargetingHandler(this, _bZeroG); }
	bool CanEnterFocusMode(bool _bOpenMenu) const { return FCanEnterFocusMode(this, _bOpenMenu); }
	bool EquipPower(const EArkPsiPowers& _power) { return FEquipPower(this, _power); }
	void ActivateLatentPower(const EArkPsiPowers _power) { FActivateLatentPower(this, _power); }
	const ArkAbility* GetAbilityForPower(EArkPsiPowers _power) const { return FGetAbilityForPower(this, _power); }
	bool HandleBlacklist(const IArkPsiPower& _power) { return FHandleBlacklist(this, _power); }
	void UpdateInputLegend(const EArkPsiPowers _power) { FUpdateInputLegend(this, _power); }
	void ResetJumpTimer() { FResetJumpTimer(this); }
	void ResetSneakTimer() { FResetSneakTimer(this); }
	bool ShouldGenerateGameNoises() const { return FShouldGenerateGameNoises(this); }
	void CreatePowers() { FCreatePowers(this); }
	void ClearUITargets() { FClearUITargets(this); }
	void StartTargeting(const IArkPsiPower& _power) { FStartTargeting(this, _power); }
	void DeactivateLatentPower(const EArkPsiPowers _power) { FDeactivateLatentPower(this, _power); }
	void UpdateEquippedPowerUI(const bool _bFinished) const { FUpdateEquippedPowerUI(this, _bFinished); }
	void NotifyActionFailed(const char* _pText) const { FNotifyActionFailed(this, _pText); }

#if 0
	void TogglePsiMode();
	void OnWeaponFirePress();
	bool ShouldPreventWeaponFireOnHold() const;
	void UnregisterLatentPowers();
	void UnlockAllPowers();
	void LockAllPowers();
	const IArkPsiPower* GetHighlightedPower() const;
	ArkPsiTargetingData& GetTargetingData();
	bool HasAnyUnlockedPowers() const;
	EArkPsiPowers GetEquippedPower() const;
	void UpdateCooldownTimers(const float _arg0_);
	bool HasPsiHypo() const;
	void ConsumePsiHypo() const;
	void TriggerActivationCamera(const IArkPsiPower& _arg0_);
	void StopTargeting(const IArkPsiPower& _arg0_);
	bool CanPowerBeCancelled(EArkPsiPowers _arg0_) const;
#endif

	static inline auto FArkPsiPowerComponent = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x1587C70);
	static inline auto FBitNotArkPsiPowerComponent = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x1588040);
	static inline auto FProcessInput = PreyFunction<void(ArkPsiPowerComponent* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x158BA20);
	static inline auto FReset = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x158BCC0);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerComponent* const _this, const float _fFrameTime)>(0x158F8B0);
	static inline auto FUpdateHUDMarkerElements = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x158FF90);
	static inline auto FRegisterLatentPower = PreyFunction<void(ArkPsiPowerComponent* const _this, EArkPsiPowers _power)>(0x158BC70);
	static inline auto FUnregisterLatentPower = PreyFunction<void(ArkPsiPowerComponent* const _this, EArkPsiPowers _power)>(0x158E5D0);
	static inline auto FUnlockPower = PreyFunction<bool(ArkPsiPowerComponent* const _this, EArkPsiPowers _powerEnum, const int _level)>(0x158E300);
	static inline auto FLockPower = PreyFunction<void(ArkPsiPowerComponent* const _this, EArkPsiPowers _powerEnum)>(0x158B5E0);
	static inline auto FGetPowerLevel = PreyFunction<int(const ArkPsiPowerComponent* const _this, const EArkPsiPowers _power)>(0x158B020);
	static inline auto FIsPowerLocked = PreyFunction<bool(const ArkPsiPowerComponent* const _this, const EArkPsiPowers _power, const int _level)>(0x158B570);
	static inline auto FSerialize = PreyFunction<void(ArkPsiPowerComponent* const _this, TSerialize _ser)>(0x158CDC0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x158B9A0);
	static inline auto FGetIArkPsiPowerOv1 = PreyFunction<IArkPsiPower* (ArkPsiPowerComponent* const _this, const EArkPsiPowers _power)>(0x158AF10);
	static inline auto FGetIArkPsiPowerOv0 = PreyFunction<const IArkPsiPower* (const ArkPsiPowerComponent* const _this, const EArkPsiPowers _power)>(0x158AF10);
	static inline auto FIsPowerActive = PreyFunction<bool(const ArkPsiPowerComponent* const _this, const EArkPsiPowers _power)>(0x158B540);
	static inline auto FIsPowerTargeting = PreyFunction<bool(const ArkPsiPowerComponent* const _this, const EArkPsiPowers _power)>(0x158B5B0);
	static inline auto FGetIconForPower = PreyFunction<string*(const ArkPsiPowerComponent* const _this, string* _return_value_, EArkPsiPowers _power)>(0x158AF30);
	static inline auto FClearSelectedPower = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x1589520);
	static inline auto FClearEquippedPower = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x1589320);
	static inline auto FSelectPower = PreyFunction<bool(ArkPsiPowerComponent* const _this, const EArkPsiPowers _power)>(0x158BDC0);
	static inline auto FActivateSelectedPower = PreyFunction<bool(ArkPsiPowerComponent* const _this)>(0x1588D20);
	static inline auto FStopLatentPowers = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x158E200);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x158B850);
	static inline auto FDisableTargetedPowers = PreyFunction<void(ArkPsiPowerComponent* const _this, const bool _bDisable)>(0x158A820);
	static inline auto FStop = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x158E170);
	static inline auto FOnStatChange = PreyFunction<void(ArkPsiPowerComponent* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x158B890);
	static inline auto FGetUnlockedPowers = PreyFunction<std::vector<enum::EArkPsiPowers>*(const ArkPsiPowerComponent* const _this, std::vector<enum::EArkPsiPowers>* _return_value_)>(0x158B110);
	static inline auto FRefreshTargetingHandler = PreyFunction<void(ArkPsiPowerComponent* const _this, const bool _bZeroG)>(0x158BB80);
	static inline auto FCanEnterFocusMode = PreyFunction<bool(const ArkPsiPowerComponent* const _this, bool _bOpenMenu)>(0x15891D0);
	static inline auto FEquipPower = PreyFunction<bool(ArkPsiPowerComponent* const _this, const EArkPsiPowers& _power)>(0x158A8B0);
	static inline auto FActivateLatentPower = PreyFunction<void(ArkPsiPowerComponent* const _this, const EArkPsiPowers _power)>(0x1588CB0);
	static inline auto FGetAbilityForPower = PreyFunction<const ArkAbility* (const ArkPsiPowerComponent* const _this, EArkPsiPowers _power)>(0x158AAE0);
	static inline auto FHandleBlacklist = PreyFunction<bool(ArkPsiPowerComponent* const _this, const IArkPsiPower& _power)>(0x158B190);
	static inline auto FUpdateInputLegend = PreyFunction<void(ArkPsiPowerComponent* const _this, const EArkPsiPowers _power)>(0x15904A0);
	static inline auto FResetJumpTimer = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x158BDA0);
	static inline auto FResetSneakTimer = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x158BDB0);
	static inline auto FShouldGenerateGameNoises = PreyFunction<bool(const ArkPsiPowerComponent* const _this)>(0x158D3E0);
	static inline auto FCreatePowers = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x15897B0);
	static inline auto FClearUITargets = PreyFunction<void(ArkPsiPowerComponent* const _this)>(0x1589740);
	static inline auto FStartTargeting = PreyFunction<void(ArkPsiPowerComponent* const _this, const IArkPsiPower& _power)>(0x158DAD0);
	static inline auto FDeactivateLatentPower = PreyFunction<void(ArkPsiPowerComponent* const _this, const EArkPsiPowers _power)>(0x158A7A0);
	static inline auto FUpdateEquippedPowerUI = PreyFunction<void(const ArkPsiPowerComponent* const _this, const bool _bFinished)>(0x158FCA0);
	static inline auto FNotifyActionFailed = PreyFunction<void(const ArkPsiPowerComponent* const _this, const char* _pText)>(0x158B6B0);
};

