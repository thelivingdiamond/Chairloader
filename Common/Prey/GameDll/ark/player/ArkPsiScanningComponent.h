// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkHUDListener.h>
#include <Prey/GameDll/ark/player/IArkMetaTagListener.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/arkplayerlight.h>
#include <Prey/GameDll/ark/player/arkpsiscanningcomponent.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>

class ArkClass;
class ArkReflectedObject;
class CCryName;
class IArkPsiScanningComponentListener;
struct IEntity;
struct IEntityClass;
struct SEntityEvent;
struct SEntitySpawnParams;

// Header: Override
// Prey/GameDll/ark/player/ArkPsiScanningComponent.h
class ArkScanState // Id=8016E6A Size=16
{
public:
	unsigned m_entityId;
	uint64_t m_locationId;

#if 0
	unsigned GetEntityId() const;
	uint64_t GetLocationId() const;
	bool operator==(ArkScanState const& arg0) const;
	void Serialize(TSerialize arg0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/player/ArkPsiScanningComponent.h
class ArkPsiScanningComponent : public IArkStatsListener, public IArkHUDListener, public IEntitySystemSink, public IArkMetaTagListener // Id=8016E66 Size=368
{
public:
	enum class ArkTargetingReticleState
	{
		None = 0,
		New = 1,
		Old = 2,
		Locked = 3,
	};

	enum class ArkLockedReticleState
	{
		None = 0,
		Locked = 1,
	};

	std::vector<unsigned int> m_validResearchSubjects;
	std::vector<unsigned int> m_fullyScannedResearchSubjects;
	std::unordered_set<ArkScanState> m_scanState;
	ArkPlayerLightEntity m_playerLight;
	unsigned m_lockedTarget;
	unsigned m_targetedTarget;
	wstring m_targetDisplayName;
	Vec2 m_targetingReticleDir;
	Vec2 m_targetingReticlePos;
	float m_lockonDurationSec;
	float m_lockonElapsedSec;
	float m_lockonTimeoutSec;
	float m_autoUnequipElapsedSec;
	int m_zoomHandle;
	int m_timeScaleHandle;
	uint64_t m_postProcessEffectId;
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
	std::vector<IArkPsiScanningComponentListener *> m_listeners;
	IEntityClass const *m_pPoltergeistClass;
	ArkInputLegendHandler m_inputLegendHandler;
	
	ArkPsiScanningComponent();
	virtual ~ArkPsiScanningComponent();
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void SetAvailable(bool _bValue) { FSetAvailable(this,_bValue); }
	void Update(const float _deltaTime) { FUpdate(this,_deltaTime); }
	void UpdateHUDMarkerElements() { FUpdateHUDMarkerElements(this); }
	void ProcessInput(CCryName const &_actionId, const int _activationMode, const float _value) { FProcessInput(this,_actionId,_activationMode,_value); }
	void LockTargetingReticle(const bool _bLock) { FLockTargetingReticle(this,_bLock); }
	void RegisterListener(IArkPsiScanningComponentListener *_pListener) { FRegisterListener(this,_pListener); }
	void UnregisterListener(IArkPsiScanningComponentListener *_pListener) { FUnregisterListener(this,_pListener); }
	static bool IsPositionInScannerScreen(Vec3 const &_pos) { return FIsPositionInScannerScreen(_pos); }
	static Vec3 GetTargetAttachmentPosition(IEntity const &_entity) { return FGetTargetAttachmentPosition(_entity); }
	bool HasScannedEntity(unsigned _target) const { return FHasScannedEntity(this,_target); }
	void SetDisrupted(bool _bDisrupted) { FSetDisrupted(this,_bDisrupted); }
	void EnablePsiMeter(const bool _bEnabled) { FEnablePsiMeter(this,_bEnabled); }
	void TurnOn() { FTurnOn(this); }
	void TurnOff() { FTurnOff(this); }
	void SetPaused(bool _bPaused) { FSetPaused(this,_bPaused); }
	void HideStatusBar() { FHideStatusBar(this); }
	void ShowScanningHud() { FShowScanningHud(this); }
	void HideScanningHud() { FHideScanningHud(this); }
	void UpdateTargetDetails() { FUpdateTargetDetails(this); }
	unsigned FindTarget(bool _bPreferUnresearched) { return FFindTarget(this,_bPreferUnresearched); }
	void SetLockedEntity(unsigned _target, bool _bForce) { FSetLockedEntity(this,_target,_bForce); }
	void SetTargetedEntity(unsigned _target) { FSetTargetedEntity(this,_target); }
	void TriggerResearchedFanfare() { FTriggerResearchedFanfare(this); }
	void ExitResearchedFanfare() { FExitResearchedFanfare(this); }
	void RefreshFocusTarget() { FRefreshFocusTarget(this); }
	virtual void OnMetaTagAdded(unsigned _entityId, const uint64_t _tag);
	virtual void OnMetaTagRemoved(unsigned _entityId, const uint64_t _tag);
	virtual void OnMetaTagsAdded(unsigned _entityId);
	virtual void OnAllDynamicMetaTagsRemoved(unsigned _entityId);
	void CheckIfTargetStillValid(unsigned _entityId) { FCheckIfTargetStillValid(this,_entityId); }
	virtual void OnEntityUnderReticleChanged(const unsigned _oldEntity, const unsigned _newEntity);
	virtual bool OnBeforeSpawn(SEntitySpawnParams &_params);
	virtual void OnSpawn(IEntity *const _pEntity, SEntitySpawnParams &params);
	virtual bool OnRemove(IEntity *const _pEntity);
	virtual void OnReused(IEntity *const _pEntity, SEntitySpawnParams &_params);
	virtual void OnEvent(IEntity *const _pEntity, SEntityEvent &_event);
	void UpdateTargetReticle(float _deltaTime) { FUpdateTargetReticle(this,_deltaTime); }
	void UpdateLockedReticle(float _deltaTime) { FUpdateLockedReticle(this,_deltaTime); }
	void FinishedScan(IEntity const *_pLockedEntity) { FFinishedScan(this,_pLockedEntity); }
	bool IsTargetValid(IEntity const *_pTarget, Vec3 const &_playerWorldPos, float _maxRangeSq, bool _bStrict, bool &_bPermanentlyInvalid, Vec2 &_entityScreenPos) const { return FIsTargetValid(this,_pTarget,_playerWorldPos,_maxRangeSq,_bStrict,_bPermanentlyInvalid,_entityScreenPos); }
	void InqTargetResearch(IEntity const &_target, int &_currentPips, int &_maxPips, string &_lore) const { FInqTargetResearch(this,_target,_currentPips,_maxPips,_lore); }
	void BuildSubjectLists() { FBuildSubjectLists(this); }
	void AddSubjectToList(IEntity *_pEntity) { FAddSubjectToList(this,_pEntity); }
	bool IsValidSubject(IEntity *_pEntity) const { return FIsValidSubject(this,_pEntity); }
	void PlayPsychoscopeAnimation(const char *const _animName) { FPlayPsychoscopeAnimation(this,_animName); }
	
#if 0
	bool IsEnabled() const;
	bool IsAvailable() const;
	unsigned GetTargetedTarget() const;
	unsigned GetPrimaryTarget() const;
	bool IsTargetResearched(unsigned arg0) const;
	bool CheckLineOfSight(IEntity const &arg0) const;
	void UpdateResearchedFanfare();
	bool IsTargetVisible(IEntity const &arg0) const;
	void RemoveSubjectFromLists(unsigned arg0);
#endif
	
	static inline auto FBitNotArkPsiScanningComponent = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15A7980);
	static inline auto FOnStatChange = PreyFunction<void(ArkPsiScanningComponent *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x15AB100);
	static inline auto FInit = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15A9DE0);
	static inline auto FReset = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15ABC00);
	static inline auto FSerialize = PreyFunction<void(ArkPsiScanningComponent *const _this, TSerialize _ser)>(0x15ABC60);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15AB270);
	static inline auto FSetAvailable = PreyFunction<void(ArkPsiScanningComponent *const _this, bool _bValue)>(0x15ABD20);
	static inline auto FUpdate = PreyFunction<void(ArkPsiScanningComponent *const _this, const float _deltaTime)>(0x15ACAA0);
	static inline auto FUpdateHUDMarkerElements = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15ACD10);
	static inline auto FProcessInput = PreyFunction<void(ArkPsiScanningComponent *const _this, CCryName const &_actionId, const int _activationMode, const float _value)>(0x15AB3B0);
	static inline auto FLockTargetingReticle = PreyFunction<void(ArkPsiScanningComponent *const _this, const bool _bLock)>(0x15AAC60);
	static inline auto FRegisterListener = PreyFunction<void(ArkPsiScanningComponent *const _this, IArkPsiScanningComponentListener *_pListener)>(0x15ABBB0);
	static inline auto FUnregisterListener = PreyFunction<void(ArkPsiScanningComponent *const _this, IArkPsiScanningComponentListener *_pListener)>(0x15ACA50);
	static inline auto FIsPositionInScannerScreen = PreyFunction<bool(Vec3 const &_pos)>(0x15AA520);
	static inline auto FGetTargetAttachmentPosition = PreyFunction<Vec3(IEntity const &_entity)>(0x15A9870);
	static inline auto FHasScannedEntity = PreyFunction<bool(ArkPsiScanningComponent const *const _this, unsigned _target)>(0x15A98E0);
	static inline auto FSetDisrupted = PreyFunction<void(ArkPsiScanningComponent *const _this, bool _bDisrupted)>(0x15ABD60);
	static inline auto FEnablePsiMeter = PreyFunction<void(ArkPsiScanningComponent *const _this, const bool _bEnabled)>(0x15A8A90);
	static inline auto FTurnOn = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15AC970);
	static inline auto FTurnOff = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15AC810);
	static inline auto FSetPaused = PreyFunction<void(ArkPsiScanningComponent *const _this, bool _bPaused)>(0x15AC170);
	static inline auto FHideStatusBar = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15A9BD0);
	static inline auto FShowScanningHud = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15AC2E0);
	static inline auto FHideScanningHud = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15A9A30);
	static inline auto FUpdateTargetDetails = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15AD380);
	static inline auto FFindTarget = PreyFunction<unsigned(ArkPsiScanningComponent *const _this, bool _bPreferUnresearched)>(0x15A8BC0);
	static inline auto FSetLockedEntity = PreyFunction<void(ArkPsiScanningComponent *const _this, unsigned _target, bool _bForce)>(0x15ABEC0);
	static inline auto FSetTargetedEntity = PreyFunction<void(ArkPsiScanningComponent *const _this, unsigned _target)>(0x15AC260);
	static inline auto FTriggerResearchedFanfare = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15AC510);
	static inline auto FExitResearchedFanfare = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15A8B10);
	static inline auto FRefreshFocusTarget = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15AB410);
	static inline auto FOnMetaTagAdded = PreyFunction<void(ArkPsiScanningComponent *const _this, unsigned _entityId, const uint64_t _tag)>(0x15AAEA0);
	static inline auto FOnMetaTagRemoved = PreyFunction<void(ArkPsiScanningComponent *const _this, unsigned _entityId, const uint64_t _tag)>(0x15AAEB0);
	static inline auto FOnMetaTagsAdded = PreyFunction<void(ArkPsiScanningComponent *const _this, unsigned _entityId)>(0x15AAEC0);
	static inline auto FOnAllDynamicMetaTagsRemoved = PreyFunction<void(ArkPsiScanningComponent *const _this, unsigned _entityId)>(0x15AAEB0);
	static inline auto FCheckIfTargetStillValid = PreyFunction<void(ArkPsiScanningComponent *const _this, unsigned _entityId)>(0x15A8840);
	static inline auto FOnEntityUnderReticleChanged = PreyFunction<void(ArkPsiScanningComponent *const _this, const unsigned _oldEntity, const unsigned _newEntity)>(0x15AAD40);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(ArkPsiScanningComponent *const _this, SEntitySpawnParams &_params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(ArkPsiScanningComponent *const _this, IEntity *const _pEntity, SEntitySpawnParams &params)>(0x15AB0F0);
	static inline auto FOnRemove = PreyFunction<bool(ArkPsiScanningComponent *const _this, IEntity *const _pEntity)>(0x15AAF30);
	static inline auto FOnReused = PreyFunction<void(ArkPsiScanningComponent *const _this, IEntity *const _pEntity, SEntitySpawnParams &_params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(ArkPsiScanningComponent *const _this, IEntity *const _pEntity, SEntityEvent &_event)>(0xA13080);
	static inline auto FUpdateTargetReticle = PreyFunction<void(ArkPsiScanningComponent *const _this, float _deltaTime)>(0x15AD850);
	static inline auto FUpdateLockedReticle = PreyFunction<void(ArkPsiScanningComponent *const _this, float _deltaTime)>(0x15ACD90);
	static inline auto FFinishedScan = PreyFunction<void(ArkPsiScanningComponent *const _this, IEntity const *_pLockedEntity)>(0x15A8ED0);
	static inline auto FIsTargetValid = PreyFunction<bool(ArkPsiScanningComponent const *const _this, IEntity const *_pTarget, Vec3 const &_playerWorldPos, float _maxRangeSq, bool _bStrict, bool &_bPermanentlyInvalid, Vec2 &_entityScreenPos)>(0x15AA8D0);
	static inline auto FInqTargetResearch = PreyFunction<void(ArkPsiScanningComponent const *const _this, IEntity const &_target, int &_currentPips, int &_maxPips, string &_lore)>(0x15AA160);
	static inline auto FBuildSubjectLists = PreyFunction<void(ArkPsiScanningComponent *const _this)>(0x15A87D0);
	static inline auto FAddSubjectToList = PreyFunction<void(ArkPsiScanningComponent *const _this, IEntity *_pEntity)>(0x15A8720);
	static inline auto FIsValidSubject = PreyFunction<bool(ArkPsiScanningComponent const *const _this, IEntity *_pEntity)>(0x15AABF0);
	static inline auto FPlayPsychoscopeAnimation = PreyFunction<void(ArkPsiScanningComponent *const _this, const char *const _animName)>(0x15AB130);
};

// Header: Exact
// Prey/GameDll/ark/player/arkpsiscanningcomponent.h
class ArkScanning : public ArkReflectedLibrary // Id=8019012 Size=168
{
public:
	class ArkEventBonusSecProperty : public ArkProperty // Id=8019013 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkEventBonusSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkEventBonusSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkScanning::ArkEventBonusSecProperty s_ArkEventBonusSecProperty;
	float m_EventBonusSec;
	
	class ArkLockonTimeSecProperty : public ArkProperty // Id=8019014 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkLockonTimeSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkLockonTimeSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6320);
	};

	static ArkScanning::ArkLockonTimeSecProperty s_ArkLockonTimeSecProperty;
	float m_LockonTimeSec;
	
	class ArkLockonTimeoutSecProperty : public ArkProperty // Id=8019015 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkLockonTimeoutSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkLockonTimeoutSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkScanning::ArkLockonTimeoutSecProperty s_ArkLockonTimeoutSecProperty;
	float m_LockonTimeoutSec;
	
	class ArkLockonTimeoutFlashingStartProperty : public ArkProperty // Id=8019016 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkLockonTimeoutFlashingStartProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkLockonTimeoutFlashingStartProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B00);
	};

	static ArkScanning::ArkLockonTimeoutFlashingStartProperty s_ArkLockonTimeoutFlashingStartProperty;
	float m_LockonTimeoutFlashingStart;
	
	class ArkLockonTimeoutFlashingFreqProperty : public ArkProperty // Id=8019017 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkLockonTimeoutFlashingFreqProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6340);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkLockonTimeoutFlashingFreqProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6360);
	};

	static ArkScanning::ArkLockonTimeoutFlashingFreqProperty s_ArkLockonTimeoutFlashingFreqProperty;
	float m_LockonTimeoutFlashingFreq;
	
	class ArkMaxDistanceScanRateMultiplierProperty : public ArkProperty // Id=8019018 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkMaxDistanceScanRateMultiplierProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221B20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkMaxDistanceScanRateMultiplierProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6380);
	};

	static ArkScanning::ArkMaxDistanceScanRateMultiplierProperty s_ArkMaxDistanceScanRateMultiplierProperty;
	float m_MaxDistanceScanRateMultiplier;
	
	class ArkAutoUnequipTimeoutSecProperty : public ArkProperty // Id=8019019 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkAutoUnequipTimeoutSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A63A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkAutoUnequipTimeoutSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360170);
	};

	static ArkScanning::ArkAutoUnequipTimeoutSecProperty s_ArkAutoUnequipTimeoutSecProperty;
	float m_AutoUnequipTimeoutSec;
	
	class ArkScanCompleteLockonTimeoutSecProperty : public ArkProperty // Id=801901A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkScanCompleteLockonTimeoutSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086230);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkScanCompleteLockonTimeoutSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A63C0);
	};

	static ArkScanning::ArkScanCompleteLockonTimeoutSecProperty s_ArkScanCompleteLockonTimeoutSecProperty;
	float m_ScanCompleteLockonTimeoutSec;
	
	class ArkLockonAttachmentProperty : public ArkProperty // Id=801901B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkLockonAttachmentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A63E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkLockonAttachmentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B60);
	};

	static ArkScanning::ArkLockonAttachmentProperty s_ArkLockonAttachmentProperty;
	string m_LockonAttachment;
	
	class ArkPostProcessEffectProperty : public ArkProperty // Id=801901C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkPostProcessEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkPostProcessEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105A980);
	};

	static ArkScanning::ArkPostProcessEffectProperty s_ArkPostProcessEffectProperty;
	string m_PostProcessEffect;
	
	class ArkEnableAutoUnequipProperty : public ArkProperty // Id=801901D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkEnableAutoUnequipProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6440);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkEnableAutoUnequipProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221C40);
	};

	static ArkScanning::ArkEnableAutoUnequipProperty s_ArkEnableAutoUnequipProperty;
	bool m_EnableAutoUnequip;
	
	class ArkScanFirstTargetOnEquipProperty : public ArkProperty // Id=801901E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkScanFirstTargetOnEquipProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6460);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkScanFirstTargetOnEquipProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6480);
	};

	static ArkScanning::ArkScanFirstTargetOnEquipProperty s_ArkScanFirstTargetOnEquipProperty;
	bool m_ScanFirstTargetOnEquip;
	
	class ArkFanfareZoomDurationProperty : public ArkProperty // Id=801901F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkFanfareZoomDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AA00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkFanfareZoomDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA20);
	};

	static ArkScanning::ArkFanfareZoomDurationProperty s_ArkFanfareZoomDurationProperty;
	float m_FanfareZoomDuration;
	
	class ArkFanfareZoomOutDurationProperty : public ArkProperty // Id=8019020 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkFanfareZoomOutDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AA40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkFanfareZoomOutDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA60);
	};

	static ArkScanning::ArkFanfareZoomOutDurationProperty s_ArkFanfareZoomOutDurationProperty;
	float m_FanfareZoomOutDuration;
	
	class ArkFanfareZoomHFOVProperty : public ArkProperty // Id=8019021 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkFanfareZoomHFOVProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A64A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkFanfareZoomHFOVProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A64C0);
	};

	static ArkScanning::ArkFanfareZoomHFOVProperty s_ArkFanfareZoomHFOVProperty;
	float m_FanfareZoomHFOV;
	
	class ArkFanfareCameraSpeedProperty : public ArkProperty // Id=8019022 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkFanfareCameraSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A64E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkFanfareCameraSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA80);
	};

	static ArkScanning::ArkFanfareCameraSpeedProperty s_ArkFanfareCameraSpeedProperty;
	float m_FanfareCameraSpeed;
	
	class ArkErrorMessageDurationProperty : public ArkProperty // Id=8019023 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkErrorMessageDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6500);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkErrorMessageDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6520);
	};

	static ArkScanning::ArkErrorMessageDurationProperty s_ArkErrorMessageDurationProperty;
	float m_ErrorMessageDuration;
	
	class ArkPsychoscopeHideTimeProperty : public ArkProperty // Id=8019024 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkPsychoscopeHideTimeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6540);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkPsychoscopeHideTimeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221D20);
	};

	static ArkScanning::ArkPsychoscopeHideTimeProperty s_ArkPsychoscopeHideTimeProperty;
	float m_PsychoscopeHideTime;
	
	class ArkReminderUIDelayProperty : public ArkProperty // Id=8019025 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkReminderUIDelayProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkReminderUIDelayProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6580);
	};

	static ArkScanning::ArkReminderUIDelayProperty s_ArkReminderUIDelayProperty;
	float m_ReminderUIDelay;
	
	class ArkReticleLerpSpeedProperty : public ArkProperty // Id=8019026 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkReticleLerpSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A65A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkReticleLerpSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221DA0);
	};

	static ArkScanning::ArkReticleLerpSpeedProperty s_ArkReticleLerpSpeedProperty;
	float m_ReticleLerpSpeed;
	
	class ArkLightArchetypeProperty : public ArkProperty // Id=8019027 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkLightArchetypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A5FF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkLightArchetypeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1066210);
	};

	static ArkScanning::ArkLightArchetypeProperty s_ArkLightArchetypeProperty;
	string m_LightArchetype;
	
	class ArkLightAttachmentProperty : public ArkProperty // Id=8019028 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkLightAttachmentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkLightAttachmentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A60B0);
	};

	static ArkScanning::ArkLightAttachmentProperty s_ArkLightAttachmentProperty;
	string m_LightAttachment;
	
	class ArkResearchRtpcProperty : public ArkProperty // Id=8019029 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkResearchRtpcProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A60D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkResearchRtpcProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6130);
	};

	static ArkScanning::ArkResearchRtpcProperty s_ArkResearchRtpcProperty;
	string m_ResearchRtpc;
	
	class ArkPauseResearchAudioTriggerProperty : public ArkProperty // Id=801902A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkPauseResearchAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkPauseResearchAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A61B0);
	};

	static ArkScanning::ArkPauseResearchAudioTriggerProperty s_ArkPauseResearchAudioTriggerProperty;
	string m_PauseResearchAudioTrigger;
	
	class ArkResumeResearchAudioTriggerProperty : public ArkProperty // Id=801902B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkResumeResearchAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A61D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkResumeResearchAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6230);
	};

	static ArkScanning::ArkResumeResearchAudioTriggerProperty s_ArkResumeResearchAudioTriggerProperty;
	string m_ResumeResearchAudioTrigger;
	
	class ArkFanfareInputLegendProperty : public ArkProperty // Id=801902C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScanning::ArkFanfareInputLegendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6250);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScanning::ArkFanfareInputLegendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6300);
	};

	static ArkScanning::ArkFanfareInputLegendProperty s_ArkFanfareInputLegendProperty;
	ArkInputLegend m_FanfareInputLegend;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkScanning();
	
#if 0
	void SetEventBonusSec(float arg0);
	const float &GetEventBonusSec() const;
	void SetLockonTimeSec(float arg0);
	const float &GetLockonTimeSec() const;
	void SetLockonTimeoutSec(float arg0);
	const float &GetLockonTimeoutSec() const;
	void SetLockonTimeoutFlashingStart(float arg0);
	const float &GetLockonTimeoutFlashingStart() const;
	void SetLockonTimeoutFlashingFreq(float arg0);
	const float &GetLockonTimeoutFlashingFreq() const;
	void SetMaxDistanceScanRateMultiplier(float arg0);
	const float &GetMaxDistanceScanRateMultiplier() const;
	void SetAutoUnequipTimeoutSec(float arg0);
	const float &GetAutoUnequipTimeoutSec() const;
	void SetScanCompleteLockonTimeoutSec(float arg0);
	const float &GetScanCompleteLockonTimeoutSec() const;
	void SetLockonAttachment(string arg0);
	string const &GetLockonAttachment() const;
	void SetPostProcessEffect(string arg0);
	string const &GetPostProcessEffect() const;
	void SetEnableAutoUnequip(bool arg0);
	const bool &GetEnableAutoUnequip() const;
	void SetScanFirstTargetOnEquip(bool arg0);
	const bool &GetScanFirstTargetOnEquip() const;
	void SetFanfareZoomDuration(float arg0);
	const float &GetFanfareZoomDuration() const;
	void SetFanfareZoomOutDuration(float arg0);
	const float &GetFanfareZoomOutDuration() const;
	void SetFanfareZoomHFOV(float arg0);
	const float &GetFanfareZoomHFOV() const;
	void SetFanfareCameraSpeed(float arg0);
	const float &GetFanfareCameraSpeed() const;
	void SetErrorMessageDuration(float arg0);
	const float &GetErrorMessageDuration() const;
	void SetPsychoscopeHideTime(float arg0);
	const float &GetPsychoscopeHideTime() const;
	void SetReminderUIDelay(float arg0);
	const float &GetReminderUIDelay() const;
	void SetReticleLerpSpeed(float arg0);
	const float &GetReticleLerpSpeed() const;
	void SetLightArchetype(string arg0);
	string const &GetLightArchetype() const;
	void SetLightAttachment(string arg0);
	string const &GetLightAttachment() const;
	void SetResearchRtpc(string arg0);
	string const &GetResearchRtpc() const;
	void SetPauseResearchAudioTrigger(string arg0);
	string const &GetPauseResearchAudioTrigger() const;
	void SetResumeResearchAudioTrigger(string arg0);
	string const &GetResumeResearchAudioTrigger() const;
	void SetFanfareInputLegend(ArkInputLegend arg0);
	ArkInputLegend const &GetFanfareInputLegend() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15A8A00);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15A9610);
	static inline auto FInit = PreyFunction<bool(ArkScanning *const _this)>(0x15A9F60);
	static inline auto FBitNotArkScanning = PreyFunction<void(ArkScanning *const _this)>(0x15A7AE0);
};

