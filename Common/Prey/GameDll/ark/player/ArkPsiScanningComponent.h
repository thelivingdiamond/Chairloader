// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/ArkPlayerLight.h>
#include <Prey/GameDll/ark/player/IArkHUDListener.h>
#include <Prey/GameDll/ark/player/IArkMetaTagListener.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>

class ArkClass;
class ArkReflectedObject;
class CCryName;
class IArkPsiScanningComponentListener;
class IArkValueBase;
struct IEntity;
struct IEntityClass;
struct SEntityEvent;
struct SEntitySpawnParams;

// ArkScanState
// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
class ArkScanState
{ // Size=16 (0x10)
public:
	unsigned m_entityId;
	uint64_t m_locationId;

#if 0
	ArkScanState();
	ArkScanState(unsigned _arg0_, uint64_t _arg1_);
	unsigned GetEntityId() const;
	uint64_t GetLocationId() const;
	bool operator==(const ArkScanState& _arg0_) const;
	void Serialize(TSerialize _arg0_);
#endif
};

// ArkPsiScanningComponent
// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
class ArkPsiScanningComponent
	: public IArkStatsListener
	, public IArkHUDListener
	, public IEntitySystemSink
	, public IArkMetaTagListener
{ // Size=368 (0x170)
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
	std::vector<IArkPsiScanningComponentListener*> m_listeners;
	const IEntityClass* m_pPoltergeistClass;
	ArkInputLegendHandler m_inputLegendHandler;

	ArkPsiScanningComponent();
	virtual ~ArkPsiScanningComponent();
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void SetAvailable(bool _bValue) { FSetAvailable(this, _bValue); }
	void Update(const float _deltaTime) { FUpdate(this, _deltaTime); }
	void UpdateHUDMarkerElements() { FUpdateHUDMarkerElements(this); }
	void ProcessInput(const CCryName& _actionId, const int _activationMode, const float _value) { FProcessInput(this, _actionId, _activationMode, _value); }
	void LockTargetingReticle(const bool _bLock) { FLockTargetingReticle(this, _bLock); }
	void RegisterListener(IArkPsiScanningComponentListener* _pListener) { FRegisterListener(this, _pListener); }
	void UnregisterListener(IArkPsiScanningComponentListener* _pListener) { FUnregisterListener(this, _pListener); }
	static bool IsPositionInScannerScreen(const Vec3& _pos) { return FIsPositionInScannerScreen(_pos); }
	static Vec3 GetTargetAttachmentPosition(const IEntity& _entity) { return FGetTargetAttachmentPosition(_entity); }
	bool HasScannedEntity(unsigned _target) const { return FHasScannedEntity(this, _target); }
	void SetDisrupted(bool _bDisrupted) { FSetDisrupted(this, _bDisrupted); }
	void EnablePsiMeter(const bool _bEnabled) { FEnablePsiMeter(this, _bEnabled); }
	void TurnOn() { FTurnOn(this); }
	void TurnOff() { FTurnOff(this); }
	void SetPaused(bool _bPaused) { FSetPaused(this, _bPaused); }
	void HideStatusBar() { FHideStatusBar(this); }
	void ShowScanningHud() { FShowScanningHud(this); }
	void HideScanningHud() { FHideScanningHud(this); }
	void UpdateTargetDetails() { FUpdateTargetDetails(this); }
	unsigned FindTarget(bool _bPreferUnresearched) { return FFindTarget(this, _bPreferUnresearched); }
	void SetLockedEntity(unsigned _target, bool _bForce) { FSetLockedEntity(this, _target, _bForce); }
	void SetTargetedEntity(unsigned _target) { FSetTargetedEntity(this, _target); }
	void TriggerResearchedFanfare() { FTriggerResearchedFanfare(this); }
	void ExitResearchedFanfare() { FExitResearchedFanfare(this); }
	void RefreshFocusTarget() { FRefreshFocusTarget(this); }
	virtual void OnMetaTagAdded(unsigned _entityId, const uint64_t _tag);
	virtual void OnMetaTagRemoved(unsigned _entityId, const uint64_t _tag);
	virtual void OnMetaTagsAdded(unsigned _entityId);
	virtual void OnAllDynamicMetaTagsRemoved(unsigned _entityId);
	void CheckIfTargetStillValid(unsigned _entityId) { FCheckIfTargetStillValid(this, _entityId); }
	virtual void OnEntityUnderReticleChanged(const unsigned _oldEntity, const unsigned _newEntity);
	virtual bool OnBeforeSpawn(SEntitySpawnParams& _params);
	virtual void OnSpawn(IEntity* const _pEntity, SEntitySpawnParams& params);
	virtual bool OnRemove(IEntity* const _pEntity);
	virtual void OnReused(IEntity* const _pEntity, SEntitySpawnParams& _params);
	virtual void OnEvent(IEntity* const _pEntity, SEntityEvent& _event);
	void UpdateTargetReticle(float _deltaTime) { FUpdateTargetReticle(this, _deltaTime); }
	void UpdateLockedReticle(float _deltaTime) { FUpdateLockedReticle(this, _deltaTime); }
	void FinishedScan(const IEntity* _pLockedEntity) { FFinishedScan(this, _pLockedEntity); }
	bool IsTargetValid(const IEntity* _pTarget, const Vec3& _playerWorldPos, float _maxRangeSq, bool _bStrict, bool& _bPermanentlyInvalid, Vec2& _entityScreenPos) const { return FIsTargetValid(this, _pTarget, _playerWorldPos, _maxRangeSq, _bStrict, _bPermanentlyInvalid, _entityScreenPos); }
	void InqTargetResearch(const IEntity& _target, int& _currentPips, int& _maxPips, string& _lore) const { FInqTargetResearch(this, _target, _currentPips, _maxPips, _lore); }
	void BuildSubjectLists() { FBuildSubjectLists(this); }
	void AddSubjectToList(IEntity* _pEntity) { FAddSubjectToList(this, _pEntity); }
	bool IsValidSubject(IEntity* _pEntity) const { return FIsValidSubject(this, _pEntity); }
	void PlayPsychoscopeAnimation(const char* const _animName) { FPlayPsychoscopeAnimation(this, _animName); }

#if 0
	bool IsEnabled() const;
	bool IsAvailable() const;
	unsigned GetTargetedTarget() const;
	unsigned GetPrimaryTarget() const;
	bool IsTargetResearched(unsigned _arg0_) const;
	bool CheckLineOfSight(const IEntity& _arg0_) const;
	void UpdateResearchedFanfare();
	bool IsTargetVisible(const IEntity& _arg0_) const;
	void RemoveSubjectFromLists(unsigned _arg0_);
#endif

	static inline auto FArkPsiScanningComponentOv1 = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15A7640);
	static inline auto FBitNotArkPsiScanningComponent = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15A7980);
	static inline auto FOnStatChange = PreyFunction<void(ArkPsiScanningComponent* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x15AB100);
	static inline auto FInit = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15A9DE0);
	static inline auto FReset = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15ABC00);
	static inline auto FSerialize = PreyFunction<void(ArkPsiScanningComponent* const _this, TSerialize _ser)>(0x15ABC60);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15AB270);
	static inline auto FSetAvailable = PreyFunction<void(ArkPsiScanningComponent* const _this, bool _bValue)>(0x15ABD20);
	static inline auto FUpdate = PreyFunction<void(ArkPsiScanningComponent* const _this, const float _deltaTime)>(0x15ACAA0);
	static inline auto FUpdateHUDMarkerElements = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15ACD10);
	static inline auto FProcessInput = PreyFunction<void(ArkPsiScanningComponent* const _this, const CCryName& _actionId, const int _activationMode, const float _value)>(0x15AB3B0);
	static inline auto FLockTargetingReticle = PreyFunction<void(ArkPsiScanningComponent* const _this, const bool _bLock)>(0x15AAC60);
	static inline auto FRegisterListener = PreyFunction<void(ArkPsiScanningComponent* const _this, IArkPsiScanningComponentListener* _pListener)>(0x15ABBB0);
	static inline auto FUnregisterListener = PreyFunction<void(ArkPsiScanningComponent* const _this, IArkPsiScanningComponentListener* _pListener)>(0x15ACA50);
	static inline auto FIsPositionInScannerScreen = PreyFunction<bool(const Vec3& _pos)>(0x15AA520);
	static inline auto FGetTargetAttachmentPosition = PreyFunction<Vec3(const IEntity& _entity)>(0x15A9870);
	static inline auto FHasScannedEntity = PreyFunction<bool(const ArkPsiScanningComponent* const _this, unsigned _target)>(0x15A98E0);
	static inline auto FSetDisrupted = PreyFunction<void(ArkPsiScanningComponent* const _this, bool _bDisrupted)>(0x15ABD60);
	static inline auto FEnablePsiMeter = PreyFunction<void(ArkPsiScanningComponent* const _this, const bool _bEnabled)>(0x15A8A90);
	static inline auto FTurnOn = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15AC970);
	static inline auto FTurnOff = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15AC810);
	static inline auto FSetPaused = PreyFunction<void(ArkPsiScanningComponent* const _this, bool _bPaused)>(0x15AC170);
	static inline auto FHideStatusBar = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15A9BD0);
	static inline auto FShowScanningHud = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15AC2E0);
	static inline auto FHideScanningHud = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15A9A30);
	static inline auto FUpdateTargetDetails = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15AD380);
	static inline auto FFindTarget = PreyFunction<unsigned(ArkPsiScanningComponent* const _this, bool _bPreferUnresearched)>(0x15A8BC0);
	static inline auto FSetLockedEntity = PreyFunction<void(ArkPsiScanningComponent* const _this, unsigned _target, bool _bForce)>(0x15ABEC0);
	static inline auto FSetTargetedEntity = PreyFunction<void(ArkPsiScanningComponent* const _this, unsigned _target)>(0x15AC260);
	static inline auto FTriggerResearchedFanfare = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15AC510);
	static inline auto FExitResearchedFanfare = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15A8B10);
	static inline auto FRefreshFocusTarget = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15AB410);
	static inline auto FOnMetaTagAdded = PreyFunction<void(IArkMetaTagListener* const _this, unsigned _entityId, const uint64_t _tag)>(0x15AAEA0);
	static inline auto FOnMetaTagRemoved = PreyFunction<void(IArkMetaTagListener* const _this, unsigned _entityId, const uint64_t _tag)>(0x15AAEB0);
	static inline auto FOnMetaTagsAdded = PreyFunction<void(IArkMetaTagListener* const _this, unsigned _entityId)>(0x15AAEC0);
	static inline auto FOnAllDynamicMetaTagsRemoved = PreyFunction<void(IArkMetaTagListener* const _this, unsigned _entityId)>(0x15AAEB0);
	static inline auto FCheckIfTargetStillValid = PreyFunction<void(ArkPsiScanningComponent* const _this, unsigned _entityId)>(0x15A8840);
	static inline auto FOnEntityUnderReticleChanged = PreyFunction<void(IArkHUDListener* const _this, const unsigned _oldEntity, const unsigned _newEntity)>(0x15AAD40);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(IEntitySystemSink* const _this, SEntitySpawnParams& _params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(IEntitySystemSink* const _this, IEntity* const _pEntity, SEntitySpawnParams& params)>(0x15AB0F0);
	static inline auto FOnRemove = PreyFunction<bool(IEntitySystemSink* const _this, IEntity* const _pEntity)>(0x15AAF30);
	static inline auto FOnReused = PreyFunction<void(IEntitySystemSink* const _this, IEntity* const _pEntity, SEntitySpawnParams& _params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(IEntitySystemSink* const _this, IEntity* const _pEntity, SEntityEvent& _event)>(0xA13080);
	static inline auto FUpdateTargetReticle = PreyFunction<void(ArkPsiScanningComponent* const _this, float _deltaTime)>(0x15AD850);
	static inline auto FUpdateLockedReticle = PreyFunction<void(ArkPsiScanningComponent* const _this, float _deltaTime)>(0x15ACD90);
	static inline auto FFinishedScan = PreyFunction<void(ArkPsiScanningComponent* const _this, const IEntity* _pLockedEntity)>(0x15A8ED0);
	static inline auto FIsTargetValid = PreyFunction<bool(const ArkPsiScanningComponent* const _this, const IEntity* _pTarget, const Vec3& _playerWorldPos, float _maxRangeSq, bool _bStrict, bool& _bPermanentlyInvalid, Vec2& _entityScreenPos)>(0x15AA8D0);
	static inline auto FInqTargetResearch = PreyFunction<void(const ArkPsiScanningComponent* const _this, const IEntity& _target, int& _currentPips, int& _maxPips, string& _lore)>(0x15AA160);
	static inline auto FBuildSubjectLists = PreyFunction<void(ArkPsiScanningComponent* const _this)>(0x15A87D0);
	static inline auto FAddSubjectToList = PreyFunction<void(ArkPsiScanningComponent* const _this, IEntity* _pEntity)>(0x15A8720);
	static inline auto FIsValidSubject = PreyFunction<bool(const ArkPsiScanningComponent* const _this, IEntity* _pEntity)>(0x15AABF0);
	static inline auto FPlayPsychoscopeAnimation = PreyFunction<void(ArkPsiScanningComponent* const _this, const char* const _animName)>(0x15AB130);
};

// ArkScanning
// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
class ArkScanning : public ArkReflectedLibrary
{ // Size=168 (0xA8)
public:
	// ArkScanning::ArkEventBonusSecProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkEventBonusSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEventBonusSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkEventBonusSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkEventBonusSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// ArkScanning::ArkLockonTimeSecProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkLockonTimeSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockonTimeSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkLockonTimeSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1360080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkLockonTimeSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6320);
	};

	// ArkScanning::ArkLockonTimeoutSecProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkLockonTimeoutSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockonTimeoutSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkLockonTimeoutSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1068E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkLockonTimeoutSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1068E60);
	};

	// ArkScanning::ArkLockonTimeoutFlashingStartProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkLockonTimeoutFlashingStartProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockonTimeoutFlashingStartProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkLockonTimeoutFlashingStartProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkLockonTimeoutFlashingStartProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221B00);
	};

	// ArkScanning::ArkLockonTimeoutFlashingFreqProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkLockonTimeoutFlashingFreqProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockonTimeoutFlashingFreqProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkLockonTimeoutFlashingFreqProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6340);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkLockonTimeoutFlashingFreqProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6360);
	};

	// ArkScanning::ArkMaxDistanceScanRateMultiplierProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkMaxDistanceScanRateMultiplierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxDistanceScanRateMultiplierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkMaxDistanceScanRateMultiplierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221B20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkMaxDistanceScanRateMultiplierProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6380);
	};

	// ArkScanning::ArkAutoUnequipTimeoutSecProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkAutoUnequipTimeoutSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAutoUnequipTimeoutSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkAutoUnequipTimeoutSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A63A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkAutoUnequipTimeoutSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1360170);
	};

	// ArkScanning::ArkScanCompleteLockonTimeoutSecProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkScanCompleteLockonTimeoutSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkScanCompleteLockonTimeoutSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkScanCompleteLockonTimeoutSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086230);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkScanCompleteLockonTimeoutSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A63C0);
	};

	// ArkScanning::ArkLockonAttachmentProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkLockonAttachmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockonAttachmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkLockonAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A63E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkLockonAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221B60);
	};

	// ArkScanning::ArkPostProcessEffectProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkPostProcessEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPostProcessEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkPostProcessEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkPostProcessEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x105A980);
	};

	// ArkScanning::ArkEnableAutoUnequipProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkEnableAutoUnequipProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEnableAutoUnequipProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkEnableAutoUnequipProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6440);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkEnableAutoUnequipProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221C40);
	};

	// ArkScanning::ArkScanFirstTargetOnEquipProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkScanFirstTargetOnEquipProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkScanFirstTargetOnEquipProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkScanFirstTargetOnEquipProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6460);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkScanFirstTargetOnEquipProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6480);
	};

	// ArkScanning::ArkFanfareZoomDurationProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkFanfareZoomDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFanfareZoomDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkFanfareZoomDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x105AA00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkFanfareZoomDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x105AA20);
	};

	// ArkScanning::ArkFanfareZoomOutDurationProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkFanfareZoomOutDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFanfareZoomOutDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkFanfareZoomOutDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x105AA40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkFanfareZoomOutDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x105AA60);
	};

	// ArkScanning::ArkFanfareZoomHFOVProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkFanfareZoomHFOVProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFanfareZoomHFOVProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkFanfareZoomHFOVProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A64A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkFanfareZoomHFOVProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A64C0);
	};

	// ArkScanning::ArkFanfareCameraSpeedProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkFanfareCameraSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFanfareCameraSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkFanfareCameraSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A64E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkFanfareCameraSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x105AA80);
	};

	// ArkScanning::ArkErrorMessageDurationProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkErrorMessageDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkErrorMessageDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkErrorMessageDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6500);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkErrorMessageDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6520);
	};

	// ArkScanning::ArkPsychoscopeHideTimeProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkPsychoscopeHideTimeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPsychoscopeHideTimeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkPsychoscopeHideTimeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6540);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkPsychoscopeHideTimeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221D20);
	};

	// ArkScanning::ArkReminderUIDelayProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkReminderUIDelayProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReminderUIDelayProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkReminderUIDelayProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkReminderUIDelayProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6580);
	};

	// ArkScanning::ArkReticleLerpSpeedProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkReticleLerpSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReticleLerpSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkReticleLerpSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A65A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkReticleLerpSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221DA0);
	};

	// ArkScanning::ArkLightArchetypeProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkLightArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLightArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkLightArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A5FF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkLightArchetypeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1066210);
	};

	// ArkScanning::ArkLightAttachmentProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkLightAttachmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLightAttachmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkLightAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkLightAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A60B0);
	};

	// ArkScanning::ArkResearchRtpcProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkResearchRtpcProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkResearchRtpcProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkResearchRtpcProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A60D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkResearchRtpcProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6130);
	};

	// ArkScanning::ArkPauseResearchAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkPauseResearchAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPauseResearchAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkPauseResearchAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkPauseResearchAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A61B0);
	};

	// ArkScanning::ArkResumeResearchAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkResumeResearchAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkResumeResearchAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkResumeResearchAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A61D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkResumeResearchAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6230);
	};

	// ArkScanning::ArkFanfareInputLegendProperty
	// Header:  Prey/GameDll/ark/player/ArkPsiScanningComponent.h
	class ArkFanfareInputLegendProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFanfareInputLegendProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkScanning::ArkFanfareInputLegendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6250);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkScanning::ArkFanfareInputLegendProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6300);
	};

	static inline auto s_ArkEventBonusSecProperty = PreyGlobal<ArkScanning::ArkEventBonusSecProperty>(0x2C04390);
	float m_EventBonusSec;
	static inline auto s_ArkLockonTimeSecProperty = PreyGlobal<ArkScanning::ArkLockonTimeSecProperty>(0x2C043B0);
	float m_LockonTimeSec;
	static inline auto s_ArkLockonTimeoutSecProperty = PreyGlobal<ArkScanning::ArkLockonTimeoutSecProperty>(0x2C043D0);
	float m_LockonTimeoutSec;
	static inline auto s_ArkLockonTimeoutFlashingStartProperty = PreyGlobal<ArkScanning::ArkLockonTimeoutFlashingStartProperty>(0x2C043F0);
	float m_LockonTimeoutFlashingStart;
	static inline auto s_ArkLockonTimeoutFlashingFreqProperty = PreyGlobal<ArkScanning::ArkLockonTimeoutFlashingFreqProperty>(0x2C04410);
	float m_LockonTimeoutFlashingFreq;
	static inline auto s_ArkMaxDistanceScanRateMultiplierProperty = PreyGlobal<ArkScanning::ArkMaxDistanceScanRateMultiplierProperty>(0x2C04430);
	float m_MaxDistanceScanRateMultiplier;
	static inline auto s_ArkAutoUnequipTimeoutSecProperty = PreyGlobal<ArkScanning::ArkAutoUnequipTimeoutSecProperty>(0x2C04450);
	float m_AutoUnequipTimeoutSec;
	static inline auto s_ArkScanCompleteLockonTimeoutSecProperty = PreyGlobal<ArkScanning::ArkScanCompleteLockonTimeoutSecProperty>(0x2C04470);
	float m_ScanCompleteLockonTimeoutSec;
	static inline auto s_ArkLockonAttachmentProperty = PreyGlobal<ArkScanning::ArkLockonAttachmentProperty>(0x2C04490);
	string m_LockonAttachment;
	static inline auto s_ArkPostProcessEffectProperty = PreyGlobal<ArkScanning::ArkPostProcessEffectProperty>(0x2C044B0);
	string m_PostProcessEffect;
	static inline auto s_ArkEnableAutoUnequipProperty = PreyGlobal<ArkScanning::ArkEnableAutoUnequipProperty>(0x2C044D0);
	bool m_EnableAutoUnequip;
	static inline auto s_ArkScanFirstTargetOnEquipProperty = PreyGlobal<ArkScanning::ArkScanFirstTargetOnEquipProperty>(0x2C044F0);
	bool m_ScanFirstTargetOnEquip;
	static inline auto s_ArkFanfareZoomDurationProperty = PreyGlobal<ArkScanning::ArkFanfareZoomDurationProperty>(0x2C04510);
	float m_FanfareZoomDuration;
	static inline auto s_ArkFanfareZoomOutDurationProperty = PreyGlobal<ArkScanning::ArkFanfareZoomOutDurationProperty>(0x2C04530);
	float m_FanfareZoomOutDuration;
	static inline auto s_ArkFanfareZoomHFOVProperty = PreyGlobal<ArkScanning::ArkFanfareZoomHFOVProperty>(0x2C04550);
	float m_FanfareZoomHFOV;
	static inline auto s_ArkFanfareCameraSpeedProperty = PreyGlobal<ArkScanning::ArkFanfareCameraSpeedProperty>(0x2C04570);
	float m_FanfareCameraSpeed;
	static inline auto s_ArkErrorMessageDurationProperty = PreyGlobal<ArkScanning::ArkErrorMessageDurationProperty>(0x2C04590);
	float m_ErrorMessageDuration;
	static inline auto s_ArkPsychoscopeHideTimeProperty = PreyGlobal<ArkScanning::ArkPsychoscopeHideTimeProperty>(0x2C045B0);
	float m_PsychoscopeHideTime;
	static inline auto s_ArkReminderUIDelayProperty = PreyGlobal<ArkScanning::ArkReminderUIDelayProperty>(0x2C045D0);
	float m_ReminderUIDelay;
	static inline auto s_ArkReticleLerpSpeedProperty = PreyGlobal<ArkScanning::ArkReticleLerpSpeedProperty>(0x2C045F0);
	float m_ReticleLerpSpeed;
	static inline auto s_ArkLightArchetypeProperty = PreyGlobal<ArkScanning::ArkLightArchetypeProperty>(0x2C04610);
	string m_LightArchetype;
	static inline auto s_ArkLightAttachmentProperty = PreyGlobal<ArkScanning::ArkLightAttachmentProperty>(0x2C04630);
	string m_LightAttachment;
	static inline auto s_ArkResearchRtpcProperty = PreyGlobal<ArkScanning::ArkResearchRtpcProperty>(0x2C04650);
	string m_ResearchRtpc;
	static inline auto s_ArkPauseResearchAudioTriggerProperty = PreyGlobal<ArkScanning::ArkPauseResearchAudioTriggerProperty>(0x2C04670);
	string m_PauseResearchAudioTrigger;
	static inline auto s_ArkResumeResearchAudioTriggerProperty = PreyGlobal<ArkScanning::ArkResumeResearchAudioTriggerProperty>(0x2C04690);
	string m_ResumeResearchAudioTrigger;
	static inline auto s_ArkFanfareInputLegendProperty = PreyGlobal<ArkScanning::ArkFanfareInputLegendProperty>(0x2C046B0);
	ArkInputLegend m_FanfareInputLegend;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetEventBonusSec(float _arg0_);
	const float& GetEventBonusSec() const;
	void SetLockonTimeSec(float _arg0_);
	const float& GetLockonTimeSec() const;
	void SetLockonTimeoutSec(float _arg0_);
	const float& GetLockonTimeoutSec() const;
	void SetLockonTimeoutFlashingStart(float _arg0_);
	const float& GetLockonTimeoutFlashingStart() const;
	void SetLockonTimeoutFlashingFreq(float _arg0_);
	const float& GetLockonTimeoutFlashingFreq() const;
	void SetMaxDistanceScanRateMultiplier(float _arg0_);
	const float& GetMaxDistanceScanRateMultiplier() const;
	void SetAutoUnequipTimeoutSec(float _arg0_);
	const float& GetAutoUnequipTimeoutSec() const;
	void SetScanCompleteLockonTimeoutSec(float _arg0_);
	const float& GetScanCompleteLockonTimeoutSec() const;
	void SetLockonAttachment(string _arg0_);
	const string& GetLockonAttachment() const;
	void SetPostProcessEffect(string _arg0_);
	const string& GetPostProcessEffect() const;
	void SetEnableAutoUnequip(bool _arg0_);
	const bool& GetEnableAutoUnequip() const;
	void SetScanFirstTargetOnEquip(bool _arg0_);
	const bool& GetScanFirstTargetOnEquip() const;
	void SetFanfareZoomDuration(float _arg0_);
	const float& GetFanfareZoomDuration() const;
	void SetFanfareZoomOutDuration(float _arg0_);
	const float& GetFanfareZoomOutDuration() const;
	void SetFanfareZoomHFOV(float _arg0_);
	const float& GetFanfareZoomHFOV() const;
	void SetFanfareCameraSpeed(float _arg0_);
	const float& GetFanfareCameraSpeed() const;
	void SetErrorMessageDuration(float _arg0_);
	const float& GetErrorMessageDuration() const;
	void SetPsychoscopeHideTime(float _arg0_);
	const float& GetPsychoscopeHideTime() const;
	void SetReminderUIDelay(float _arg0_);
	const float& GetReminderUIDelay() const;
	void SetReticleLerpSpeed(float _arg0_);
	const float& GetReticleLerpSpeed() const;
	void SetLightArchetype(string _arg0_);
	const string& GetLightArchetype() const;
	void SetLightAttachment(string _arg0_);
	const string& GetLightAttachment() const;
	void SetResearchRtpc(string _arg0_);
	const string& GetResearchRtpc() const;
	void SetPauseResearchAudioTrigger(string _arg0_);
	const string& GetPauseResearchAudioTrigger() const;
	void SetResumeResearchAudioTrigger(string _arg0_);
	const string& GetResumeResearchAudioTrigger() const;
	void SetFanfareInputLegend(ArkInputLegend _arg0_);
	const ArkInputLegend& GetFanfareInputLegend() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15A8A00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15A9610);
	static inline auto FInit = PreyFunction<bool(ArkScanning* const _this)>(0x15A9F60);
};

