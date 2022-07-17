#pragma once

#include "ArkHud.h"
#include "ArkPlayerLight.h"
#include "ArkMetaTag.h"
#include "ArkStats.h"

class ArkPsiPowerSmokeForm {
public:
	static inline auto Exit = PreyFunction<void(ArkPsiPowerSmokeForm* _this)> (0x15A49E0);
	static inline auto TryMorphOut = PreyFunction<char(ArkPsiPowerSmokeForm* _this)>(0x15A5940);
	static inline auto Stop = PreyFunction<char(ArkPsiPowerSmokeForm* _this)>(0x15A5940);
};

class IArkPsiPower
{
public:
	virtual ~IArkPsiPower() = 0;
	virtual const char* GetDescription() = 0;
	virtual int SetLevel(const int) = 0;
	virtual int GetLevel() = 0;
	virtual int GetMaxLevel() = 0;
	virtual bool GetCanCancel() = 0;
	virtual void ProcessInput(const CCryName*, int, float) = 0;
	virtual void ProcessInputForTargeting(const CCryName*, int, float) = 0;
	virtual void RefreshTargets() = 0;
	virtual void Update(const float) = 0;
	virtual void UpdateTargeting(const float) = 0;
	virtual std::vector<IEntity*>* GetSelectedTargets(std::vector<IEntity*>* result) = 0;
	virtual std::vector<IEntity*>* GetUnselectedTargets(std::vector<IEntity*>* result) = 0;
	virtual void Cancel() = 0;
	virtual EArkPsiPowerError GetExecutionError() = 0;
	virtual bool StartTargeting() = 0;
	virtual void OnReset() = 0;
	virtual const char* GetHelpText() = 0;
	virtual const ArkInputLegend* GetTargetingLegend() = 0;
	virtual const ArkInputLegend* GetModalLegend() = 0;
	virtual EArkPsiPowers GetEnum() = 0;
	virtual void Serialize(CSerializeWrapper<ISerialize>) = 0;
	virtual void PostSerialize() = 0;
	virtual CryStringT<wchar_t>* GetTextForEntity(CryStringT<wchar_t>* result, const IEntity*) = 0;
	virtual bool ShowTextWhileTargeting() = 0;
	virtual bool Start() = 0;
	virtual bool InterruptsMimicGrabSequence() = 0;
	virtual bool Stop() = 0;
	virtual int GetCost() = 0;
	virtual const char* GetDisplayName() = 0;
	virtual float GetZoomDuration() = 0;
	virtual Vec3_tpl<float>* GetTargetPosition(Vec3_tpl<float>* result) = 0;
	virtual const std::vector<enum EArkPsiPowers>* GetBlacklistedPowers() = 0;
	virtual unsigned __int64 GetPersistentPostEffectId() = 0;
	virtual Color_tpl<float>* GetTargetHighlightColor(Color_tpl<float>* result) = 0;
	virtual float UpdateCooldownTimer(const float) = 0;
	virtual const ArkSimpleTimer* GetCooldownTimer() = 0;
	virtual bool CanEnterFocusMode(const EArkPsiPowers*) = 0;
	virtual const char* GetErrorString() = 0;
	virtual const char* GetTargetingErrorString() = 0;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() = 0;
	virtual bool ShouldGenerateGameNoises() = 0;
	virtual void EmitNoise() = 0;


};
template <typename _Ty> class CArkPsiPower : IArkPsiPower {
	ArkSimpleTimer m_cooldownTimer;
	std::vector<EArkPsiPowers> m_blacklist;
	uint32_t m_level;
	undefined pad[4];
	uint64_t m_properties;
	uint64_t m_pExecutionPlayerEffect;
};
class ArkPsiPowerTargetingComponentProperties : ArkReflectedObject
{
public:
	float m_MinRange;
	float m_MaxRange;
	CryStringT<char> m_TargetParticleEffect;
	CryStringT<char> m_TargetParticleEffectAttachment;
	CryStringT<char> m_TargetParticleLightEffect;
	std::vector<CryStringT<char>> m_ValidTargetClasses;
	std::vector<unsigned __int64> m_ValidTargetMetaTags;
};
class ArkPsiPowerTargetingComponent
{
public:
	virtual ~ArkPsiPowerTargetingComponent() = 0;
	virtual bool Start() = 0;
	virtual void Stop() = 0;


	const IArkPsiPower* m_pPower;
	ArkPlayerLightVFX m_playerLight;
	IParticleEffect* m_pTargetParticleEffect;
	std::vector<IEntityClass const*> m_validClasses;
	std::vector<unsigned __int64> m_validMetaTags;
	const ArkPsiPowerTargetingComponentProperties* m_pProperties;
};
class ArkPsiTargetingData
{
public:
	float m_targetDepth;
	CryStringT<char> m_targetAttachmentName;
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
};
class ArkPsiPowerComponent : IArkStatsListener
{
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
	std::array<std::unique_ptr<IArkPsiPower>, 16> m_powers;
	std::unordered_map<unsigned int, int> m_selectedUITargetIds;
	std::unordered_map<unsigned int, int> m_unselectedUITargetIds;
	ArkInputLegend m_targetingLegend;
	ArkInputLegend m_mimicTargetingLegend;
	ArkInputLegend m_targetingLegendZeroG;
	ArkInputLegend m_mimicTargetingLegendZeroG;
	ArkInputLegendHandler m_targetingHandler;
	ArkInputLegendHandler m_modalHandler;
	ArkPsiTargetingData m_targetingData;
	CryStringT<char> m_selectionHelpText;
	CryStringT<char> m_selectedUIFormat;
	CryStringT<char> m_unselectedUIFormat;
	CryStringT<char> m_playerParticleEffectPath;
	EArkPsiPowers m_selectedPower;
	EArkPsiPowers m_equippedPower;
	EArkPsiPowers m_modalLegendPower;
	std::vector<EArkPsiPowers> m_latentPowers;
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

	//functions
	static inline auto ActivateLatentPower = PreyFunction<void(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x1588cb0);
	static inline auto ActivateSelectedPower = PreyFunction<bool(ArkPsiPowerComponent* _this)>(0x1588d20);
	static inline auto CanEnterFocusMode = PreyFunction<bool(ArkPsiPowerComponent* _this, bool param_1)>(0x15891d0);
	static inline auto ClearEquippedPower = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x1589320);
	static inline auto ClearSelectedPower = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x1589520);
	static inline auto ClearUITargets = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x1589740);
	static inline auto CreatePowers = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x15897b0);
	static inline auto DeactivateLatentPower = PreyFunction<void(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158a7a0);
	static inline auto DisableTargetedPowers = PreyFunction<void(ArkPsiPowerComponent* _this, bool param_1)>(0x158a820);
	static inline auto EquipPower = PreyFunction<bool(ArkPsiPowerComponent* _this, EArkPsiPowers* param_1)>(0x158a8b0);
	static inline auto GetAbilityForPower = PreyFunction<ArkAbility* (ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158aae0);
	static inline auto GetIArkPsiPower = PreyFunction<IArkPsiPower* (ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158af10);
	static inline auto GetIconForPower = PreyFunction<CryStringT<char>(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158af30);
	static inline auto GetPowerLevel = PreyFunction<int(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158b020);
	static inline auto GetUnlockedPowers = PreyFunction<std::vector<EArkPsiPowers, std::allocator<EArkPsiPowers>>(ArkPsiPowerComponent* _this)>(0x158b110);
	static inline auto HandleBlacklist = PreyFunction<bool(ArkPsiPowerComponent* _this, IArkPsiPower* param_1)>(0x158b190);
	static inline auto IsPowerActive = PreyFunction<bool(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158b540);
	static inline auto IsPowerLocked = PreyFunction<bool(ArkPsiPowerComponent* _this, EArkPsiPowers param_1, int param_2)>(0x158b570);
	static inline auto IsPowerTargeting = PreyFunction<bool(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158b5b0);
	static inline auto LockPower = PreyFunction<void(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158b5e0);
	static inline auto NotifyActionFailed = PreyFunction<void(ArkPsiPowerComponent* _this, const char* param_1)>(0x158b6b0);
	static inline auto OnLevelToLevelTransition = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x158b850);
	static inline auto OnStatChange = PreyFunction<void(ArkPsiPowerComponent* _this, unsigned int param_1, CCryName* param_2, float param_3, float param_4)>(0x158b890);
	static inline auto PostSerialize = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x158b9a0);
	static inline auto ProcessInput = PreyFunction<void(ArkPsiPowerComponent* _this, CCryName* param_1, int param_2, float param_3)>(0x158ba20);
	static inline auto RefreshTargetingHandler = PreyFunction<void(ArkPsiPowerComponent* _this, bool param_1)>(0x158bb80);
	static inline auto RegisterLatentPower = PreyFunction<void(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158bc70);
	static inline auto Reset = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x158bcc0);
	static inline auto ResetJumpTimer = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x158bda0);
	static inline auto ResetSneakTimer = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x158bdb0);
	static inline auto SelectPower = PreyFunction<bool(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158bdc0);
	static inline auto Serialize = PreyFunction<void(ArkPsiPowerComponent* _this, CSerializeWrapper<ISerialize> param_1)>(0x158cdc0);
	static inline auto ShouldGenerateGameNoises = PreyFunction<bool(ArkPsiPowerComponent* _this)>(0x158d3e0);
	static inline auto StartTargeting = PreyFunction<void(ArkPsiPowerComponent* _this, IArkPsiPower* param_1)>(0x158dad0);
	static inline auto Stop = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x158E170);
	static inline auto StopLatentPowers = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x158E200);
	static inline auto UnlockPower = PreyFunction<bool(ArkPsiPowerComponent* _this, EArkPsiPowers param_1, int param_2)>(0x158E300);
	static inline auto UnregisterLatentPower = PreyFunction<void(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x158e5d0);
	static inline auto Update = PreyFunction<void(ArkPsiPowerComponent* _this, float param_1)>(0x158f8b0);
	static inline auto UpdateEquippedPowerUI = PreyFunction<void(ArkPsiPowerComponent* _this, bool param_1)>(0x158fca0);
	static inline auto UpdateHUDMarkerElements = PreyFunction<void(ArkPsiPowerComponent* _this)>(0x158ff90);
	static inline auto UpdateInputLegend = PreyFunction<void(ArkPsiPowerComponent* _this, EArkPsiPowers param_1)>(0x15904a0);
};
class IArkPsiScanningComponentListener
{
public:
	virtual ~IArkPsiScanningComponentListener() = 0;
	virtual void OnLockTargetReticle(const unsigned int) = 0;
	virtual void OnUnlockTargetReticle(const unsigned int) = 0;
	virtual void OnUpdateTargetReticle(const unsigned int, const bool, const float) = 0;


};
class ArkScanState
{
	unsigned int m_entityId;
	unsigned __int64 m_locationId;
};
class ArkPsiScanningComponent : IArkStatsListener, IArkHUDListener, IEntitySystemSink, IArkMetaTagListener
{
public:
	virtual void OnStatChange(IArkStatsListener* _this, const unsigned int, const CCryName*, const float, const float) {};
	bool OnBeforeSpawn(SEntitySpawnParams& params) override;
	void OnSpawn(IEntity* pEntity, SEntitySpawnParams& params) override;
	bool OnRemove(IEntity* pEntity) override;
	void OnReused(IEntity* pEntity, SEntitySpawnParams& params) override;
	void OnEvent(IEntity* pEntity, SEntityEvent& event) override;
	void OnEntityUnderReticleChanged(const unsigned, const unsigned) override;
	void OnMetaTagAdded(unsigned, const unsigned long long) override;
	void OnMetaTagRemoved(unsigned, const unsigned long long) override;
	void OnMetaTagsAdded(unsigned) override;
	void OnAllDynamicMetaTagsRemoved(unsigned) override;


	std::vector<unsigned int> m_validResearchSubjects;
	std::vector<unsigned int> m_fullyScannedResearchSubjects;
	std::unordered_set<ArkScanState> m_scanState;
	ArkPlayerLightEntity m_playerLight;
	unsigned int m_lockedTarget;
	unsigned int m_targetedTarget;
	CryStringT<wchar_t> m_targetDisplayName;
	Vec2_tpl<float> m_targetingReticleDir;
	Vec2_tpl<float> m_targetingReticlePos;
	float m_lockonDurationSec;
	float m_lockonElapsedSec;
	float m_lockonTimeoutSec;
	float m_autoUnequipElapsedSec;
	int m_zoomHandle;
	int m_timeScaleHandle;
	unsigned __int64 m_postProcessEffectId;
	bool m_bPaused;
	bool m_bEnabled;
	bool m_bAvailable;
	bool m_bStatusBarVisible;
	bool m_bTargetNotScannable;
	bool m_bAutoUnequipEnabled;
	bool m_bTargetDetailsVisible;
	bool m_bResearchedFanfareMode;
	bool m_bDiscoveredLore;
	bool m_bLockTargetingReticle;
	bool m_bLerpingTargetingReticle;
	bool m_bLockTargetScanning;
	bool m_bDisrupted;
	bool m_bShowingReminder;
	bool m_bTargetReticleWasVisible;
	int m_targetReticleCurrentPips;
	int m_targetReticleMaxPips;
	int m_fanfareInputHandle;
	ArkAudioRtpc m_researchRtpc;
	ArkAudioTrigger m_pauseResearchTrigger;
	ArkAudioTrigger m_resumeResearchTrigger;
	ArkSimpleTimer m_errorFeedbackTimer;
	ArkSimpleTimer m_reminderUITimer;
	ArkSimpleTimer m_psychoscopeHideTimer;
	std::vector<IArkPsiScanningComponentListener*> m_listeners;
	const IEntityClass* m_pPoltergeistClass;
	ArkInputLegendHandler m_inputLegendHandler;
};

class CArkPsiComponent : IArkStatsListener
{
public:
	virtual void OnStatChange(IArkStatsListener* _this, const unsigned int, const CCryName*, const float, const float) = 0;
	virtual  ~CArkPsiComponent() = 0;
	static inline auto UpdateHUDMarkerElements = PreyFunction<void(CArkPsiComponent* _this)>(0x15806F0);
	ArkPsiPowerComponent m_powerComponent;
	ArkPsiScanningComponent m_scanningComponent;
	float m_points;
	float m_unreducedMaxPoints;
	float m_maxPoints;
	float m_errorMessageDuration;
};;
