// Header file automatically created from a PDB.

#pragma once
//#include <CryEngine/cryanimation/facialanimation/faceeffector.h>
//#include <CryEngine/renderdll/common/rendelements/imagespaceshafts.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CryAction/IActorSystem.h>
#include <Prey/GameDll/ark/ArkGroundColliderComponent.h>
#include <Prey/GameDll/ark/ArkMaterialAnimationManager.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ArkStatsComponent.h>
#include <Prey/GameDll/ark/player/ArkExaminationMode.h>
#include <Prey/GameDll/ark/player/ArkPlayerAudio.h>
#include <Prey/GameDll/ark/player/ArkPlayerCamera.h>
#include <Prey/GameDll/ark/player/ArkPlayerFlashlight.h>
#include <Prey/GameDll/ark/player/ArkPlayerHelmet.h>
#include <Prey/GameDll/ark/player/ArkPlayerInput.h>
#include <Prey/GameDll/ark/player/ArkPlayerInteraction.h>
#include <Prey/GameDll/ark/player/ArkPlayerMovementFSM.h>
#include <Prey/GameDll/ark/player/ArkPlayerMovementController.h>
#include <Prey/GameDll/ark/player/ArkPlayerWeaponComponent.h>
#include <Prey/GameDll/ark/player/ArkPlayerZoomManager.h>
#include <Prey/GameDll/ark/player/IArkPlayer.h>
#include <Prey/GameDll/ark/player/IArkPlayerCombatListener.h>
#include <Prey/GameDll/ark/player/pda/ArkEquipmentModComponent.h>
#include <Prey/GameDll/ark/player/StanceInfo.h>

class ArkInventory;
class ArkPsiPowerComponent;
class CTagDefinition;
struct IAnimatedCharacter;
struct IAnimationGraphState;
class IArkSpeaker;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IInventory;
struct IItem;
struct IMovementController;
struct IPlayerEventListener;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
struct SMFXRunTimeEffectParams;
class StanceInfo;
class XmlNodeRef;

// Header: Exact
// Prey/GameDll/ark/player/ArkPlayer.h
class ArkPlayer : public CGameObjectExtensionHelper<ArkPlayer,CActor>, public IArkPlayer, public IArkPlayerCombatListener, public ISystemEventListener // Id=8016E5C Size=6968
{
public:
	enum class EArkPlayerCharacterSlot
	{
		model = 0,
		shadow = 5,
		bleed = 6,
		zerog = 7,
	};

	enum class EArkPlayerMovementState
	{
		idle = 0,
		movement = 1,
		inAir = 2,
		last = 3,
	};

	using FragmentIdsArray = std::array<int,3>;
	using RotationModifier = Functor2<Ang3_tpl<float> &,float>;
	
	ArkPlayerMovementFSM m_movementFSM;
	ArkPlayerComponent m_playerComponent;
	ArkStatsComponent m_statsComponent;
	ArkEquipmentModComponent m_suitChipsetComponent;
	ArkEquipmentModComponent m_scopeChipsetComponent;
	ArkPlayerInput m_input;
	ArkExaminationMode m_examinationMode;
	ArkPlayerInteraction m_interaction;
	ArkGroundColliderComponent m_groundColliderComponent;
	ArkPlayerFlashlight m_flashlight;
	ArkPlayerAudio m_audio;
	ArkPlayerCamera m_camera;
	ArkPlayerHelmet m_helmet;
	ArkPlayerWeaponComponent m_weaponComponent;
	std::vector<IPlayerEventListener *> m_playerEventListeners;
	std::vector<std::pair<string,unsigned int>> m_attachmentFlags;
	std::vector<unsigned __int64> m_learnedNames;
	std::vector<unsigned __int64> m_criticalHitMetaTags;
	std::vector<string> m_animationTagsSetFromFG;
	std::array<StanceInfo,18> m_stanceInfos;
	string m_modelName;
	Vec3 m_serializedVelocity;
	Vec3 m_cachedReticlePos;
	Vec3 m_cachedReticleDir;
	Vec2 m_reticlePos;
	_smart_ptr<IAction> m_pHeadBobbingAction;
	std::unique_ptr<ArkPlayerMovementController> m_pMovementController;
	IAnimatedCharacter *m_pAnimatedCharacter;
	ArkInventory *m_pInventory;
	std::unique_ptr<CFragmentCache> m_pFragmentCache;
	uint64_t m_coralSignalPackageId;
	ArkSimpleTimer m_coralInteractionTimer;
	float m_knockdownLoopDuration;
	float m_idleFragmentSpeedThreshold;
	EStance m_stance;
	ArkPlayerAttentionObject m_attentionObject;
	float m_fearNoiseAmplitude;
	float m_autoSaveHealthThreshold;
	float m_autoSaveOxygenThreshold;
	float m_attackTargetPosHeightPercent;
	float m_lookAtFarRange;
	bool m_bInTrackview;
	bool m_bInAir;
	bool m_bShowArmor;
	bool m_bShowHealth;
	bool m_bAllowIdleBreak;
	bool m_bJustPhysicalized;
	bool m_bShowContinuePrompt;
	bool m_bReceivedStartLevelEvent;
	bool m_bReticleViewPositionValid;
	ArkSimpleTimer m_autoSaveBlockedBySignalTimer;
	ArkPlayerZoomManager m_zoomManager;
	unsigned m_rotationModifierHandleGenerator;
	std::vector<std::pair<unsigned int,Functor2<Ang3_tpl<float> &,float>>> m_rotationModifiers;
	unsigned m_mimicGrabSequenceEntityId;
	ArkMaterialAnimationManager m_materialAnimationManager;
	
	ArkPlayer();
	virtual ~ArkPlayer();
	static ArkPlayer &GetInstance() { return FGetInstance(); }
	static ArkPlayer *GetInstancePtr() { return FGetInstancePtr(); }
	ArkPsiPowerComponent &GetPsiPowerComponent() { return FGetPsiPowerComponentOv1(this); }
	ArkPsiPowerComponent const &GetPsiPowerComponent() const { return FGetPsiPowerComponentOv0(this); }
	virtual EStance GetStance() const;
	virtual bool IsZeroG() const;
	virtual IInventory *GetInventory() const;
	virtual float GetHealth() const;
	virtual void SetHealth(float _health);
	void IncreaseHealth(float _increase) { FIncreaseHealth(this,_increase); }
	void TakeDamage(float _damage) { FTakeDamage(this,_damage); }
	virtual float GetMaxHealth() const;
	virtual void SetViewRotation(Quat const &_rotation);
	virtual Quat GetViewRotation() const;
	virtual void GetMemoryUsage(ICrySizer *_pSizer) const;
	virtual IItem *GetCurrentItem() const;
	virtual IEntity *GetLinkedEntity() const;
	virtual uint8_t GetSpectatorMode() const;
	virtual bool IsDead() const;
	virtual void Release();
	bool IsPsiTargeting() const { return FIsPsiTargeting(this); }
	virtual IAnimatedCharacter const *GetAnimatedCharacter() const;
	virtual IAnimatedCharacter *GetAnimatedCharacter();
	virtual Vec3 GetLocalEyePos() const;
	virtual IMovementController *GetMovementController() const;
	int GetGodMode() { return FGetGodMode(this); }
	virtual int IsGod();
	void SetCustomCameraUpdateFunction(std::function<Quat_tpl<float> __cdecl(float)> _function) { FSetCustomCameraUpdateFunction(this,_function); }
	void SetCustomViewFunction(std::function<void __cdecl(SViewParams &)> _function) { FSetCustomViewFunction(this,_function); }
	void SetStance(EStance _stance) { FSetStance(this,_stance); }
	void UpdatePropulsionPackVisibility() const { FUpdatePropulsionPackVisibility(this); }
	Ang3 GetScaledInputRotation(float _frameTime) { return FGetScaledInputRotation(this,_frameTime); }
	void Physicalize() { FPhysicalize(this); }
	void ResetReticle() { FResetReticle(this); }
	void Revive() { FRevive(this); }
	void SetAnimationTag(const char *_tagName, const bool _bTagState) const { FSetAnimationTag(this,_tagName,_bTagState); }
	void SetAnimationTagFromFG(const char *const _tagName, const bool _bTagState) { FSetAnimationTagFromFG(this,_tagName,_bTagState); }
	_smart_ptr<TAction<SAnimationContext> > PlayFragment(const char *_pName, IArkPlayer::EArkPlayerAnimationPriority _priority, const unsigned _flags) { return FPlayFragment(this,_pName,_priority,_flags); }
	void Stage(Vec3 _viewLimitDir, bool _bLocalSpace, float _viewLimitYaw, float _viewLimitPitch, bool _bLockPlayer, int _stance) { FStage(this,_viewLimitDir,_bLocalSpace,_viewLimitYaw,_viewLimitPitch,_bLockPlayer,_stance); }
	void ExecuteGroundMaterialEffectByName(const char *const _pName, SMFXRunTimeEffectParams &_params) const { FExecuteGroundMaterialEffectByName(this,_pName,_params); }
	void Hide(const bool _bHide) const { FHide(this,_bHide); }
	void OnJump() { FOnJump(this); }
	void ShowThirdPerson(const bool _bShow) const { FShowThirdPerson(this,_bShow); }
	void Ragdollize(const float _verticalSpeed) { FRagdollize(this,_verticalSpeed); }
	EPlayerSex GetSex() const { return FGetSex(this); }
	virtual IArkSpeaker *GetArkSpeaker();
	void PhysicalizeAndResetAnimatedCharacter() { FPhysicalizeAndResetAnimatedCharacter(this); }
	bool HasAbility(const uint64_t _abilityID) const { return FHasAbility(this,_abilityID); }
	void SetModel(const char *const _modelName) { FSetModel(this,_modelName); }
	bool IsInGravShaft() const { return FIsInGravShaft(this); }
	void LimitAttentionOnUnseenPlayer() const { FLimitAttentionOnUnseenPlayer(this); }
	void ReleaseAttentionLimitOnPlayer() const { FReleaseAttentionLimitOnPlayer(this); }
	bool IsInCombat() const { return FIsInCombat(this); }
	virtual void OnCombatChange(bool _bInCombat);
	void CompensateStanceHeightChange(EStance _oldStance, EStance _newStance) { FCompensateStanceHeightChange(this,_oldStance,_newStance); }
	virtual Vec3 GetAttackTargetPos() const;
	void UpdateCachedReticleViewPosAndDir() { FUpdateCachedReticleViewPosAndDir(this); }
	virtual std::pair<Vec3,Vec3> GetReticleViewPositionAndDir() const;
	void OnNewGame() { FOnNewGame(this); }
	Vec3 GetPlayerWorldEyePos() const { return FGetPlayerWorldEyePos(this); }
	CTagDefinition const *GetFragmentIds() const { return FGetFragmentIds(this); }
	void Knockdown() { FKnockdown(this); }
	void EnterMimicGrabSequence(IEntity const &_mimicEntity) { FEnterMimicGrabSequence(this,_mimicEntity); }
	void ExitMimicGrabSequence() { FExitMimicGrabSequence(this); }
	EArkSaveFailure IsSafeForAutoSave() const { return FIsSafeForAutoSave(this); }
	void SetRoomEntityId(unsigned _id) { FSetRoomEntityId(this,_id); }
	bool IsMimic() const { return FIsMimicOv1(this); }
	bool IsMimic(const unsigned _entityId) const { return FIsMimicOv0(this,_entityId); }
	IEntity const *GetMimicEntity() const { return FGetMimicEntity(this); }
	unsigned GetMimicEntityId() const { return FGetMimicEntityId(this); }
	bool IsAlternateForm() const { return FIsAlternateForm(this); }
	bool IsShifting() const { return FIsShifting(this); }
	void OnActivatePower() { FOnActivatePower(this); }
	void SetShowArmor(bool _bShowArmor, bool _bForce) { FSetShowArmor(this,_bShowArmor,_bForce); }
	void SetShowHealth(bool _bShowHealth, bool _bForce) { FSetShowHealth(this,_bShowHealth,_bForce); }
	virtual void EnableIdleBreak(const bool _bEnable);
	virtual void SerializeLevelToLevel(TSerialize &_ser);
	bool ShouldGenerateGameNoises() const { return FShouldGenerateGameNoises(this); }
	void UpdateShadow(bool _b3PShadow) const { FUpdateShadow(this,_b3PShadow); }
	void InitializePerception() { FInitializePerception(this); }
	void FinalizePerception() { FFinalizePerception(this); }
	void HideAttachment(const char *_attachmentName, bool _bHide) const { FHideAttachment(this,_attachmentName,_bHide); }
	void Reset() { FReset(this); }
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void InitLocalPlayer();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual void PostReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags);
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void SetAuthority(bool _auth);
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual int GetHealthAsRoundedPercentage() const;
	virtual void SetMaxHealth(float _maxHealth);
	virtual int GetArmor() const;
	virtual int GetMaxArmor() const;
	virtual bool IsFallen() const;
	virtual void Fall(Vec3 _hitPos);
	virtual bool AllowLandingBob();
	virtual void PlayAction(const char *_pAction, const char *_pExtension, bool _bLooping);
	virtual IAnimationGraphState *GetAnimationGraphState();
	virtual void ResetAnimationState();
	virtual void CreateScriptEvent(const char *_pEvent, float _value, const char *_pStr);
	virtual bool BecomeAggressiveToAgent(unsigned _entityID);
	virtual void SetFacialAlertnessLevel(int _alertness);
	virtual void PrecacheFacialExpression(const char *_pExpressionName);
	virtual unsigned GetGrabbedEntityId() const;
	virtual void HideAllAttachments(bool _bIsHiding);
	virtual void SetIKPos(const char *_pLimbName, Vec3 const &_goalPos, int _priority);
	virtual bool IsFriendlyEntity(unsigned _entityId, bool _bUsingAIIgnorePlayer) const;
	virtual void CameraShake(float _angle, float _shift, float _duration, float _frequency, Vec3 _pos, int _ID, const char *_pSource);
	virtual IItem *GetHolsteredItem() const;
	virtual void HolsterItem(bool _bHolster, bool _bPlaySelect, float _selectSpeedBias, bool _bHideLeftHandObject);
	virtual bool DropItem(unsigned _itemId, float _impulseScale, bool _bSelectNext, bool _bByDeath);
	virtual void NotifyCurrentItemChanged(IItem *_pNewItem);
	virtual bool IsThirdPerson() const;
	virtual void ToggleThirdPerson();
	virtual bool IsPlayer() const;
	virtual bool IsClient() const;
	virtual bool IsMigrating() const;
	virtual void SetMigrating(bool _bIsMigrating);
	virtual const char *GetActorClassName() const;
	virtual int GetActorClass() const;
	virtual void SerializeXML(XmlNodeRef &_node, bool _bLoading);
	virtual void PlayExactPositioningAnimation(const char *_pAnimationName, bool _bSignal, Vec3 const &_position, Vec3 const &_direction, float _startWidth, float _startArcAngle, float _directionTolerance);
	virtual void CancelExactPositioningAnimation();
	virtual void PlayAnimation(const char *_pAnimationName, bool _bSignal);
	virtual void EnableTimeDemo(bool _bTimeDemo);
	virtual void SwitchDemoModeSpectator(bool _bActivate);
	virtual void OnAIProxyEnabled(bool _bEnabled);
	virtual void OnReturnedToPool();
	virtual bool ShouldMuteWeaponSoundStimulus() const;
	virtual void OnReused(IEntity *_pEntity, SEntitySpawnParams &_params);
	virtual void RequestFacialExpression(const char *_pExpressionName, float *_pSequenceLength);
	virtual const char *GetEntityClassName() const;
	virtual void OnPreparedFromPool();
	virtual int GetEventPriority(const int _eventID) const;
	virtual int GetTeamId() const;
	virtual QuatT const &GetBoneTransform(int ID) const;
	virtual void InhibitRotation(const bool _bInhibit);
	void CheckForCoral() const { FCheckForCoral(this); }
	void SetFaction() { FSetFaction(this); }
	
#if 0
	ArkPlayerComponent &GetPlayerComponent();
	ArkPlayerComponent const &GetPlayerComponent() const;
	ArkStatsComponent &GetStatsComponent();
	ArkStatsComponent const &GetStatsComponent() const;
	ArkEquipmentModComponent const &GetChipsetComponent(const bool arg0) const;
	ArkEquipmentModComponent &GetChipsetComponent(const bool arg0);
	ArkGroundColliderComponent const &GetGroundColliderComponent() const;
	void RequestStance(EStance arg0);
	ArkInventory &GetArkInventory() const;
	void SetViewCameraRotation(Quat const &arg0);
	StanceInfo const &GetStanceInfo(EStance arg0) const;
	bool IsJumpButtonPressed() const;
	void RemoveCustomCameraUpdateFunction(float arg0);
	void SetCustomCameraOffsetFunction(std::function<Vec3_tpl<float> __cdecl(float)> arg0);
	void RemoveCustomCameraOffsetFunction();
	void RemoveCustomViewFunction();
	void SetCameraAnimationControlled();
	ArkPlayerCamera::Mode GetCameraMode() const;
	ArkPlayerCamera &GetPlayerCamera();
	ArkPlayerCamera const &GetPlayerCamera() const;
	void HideLegs(bool arg0) const;
	void HideHead(bool arg0) const;
	StanceInfo const &GetCurrentStanceInfo() const;
	void RegisterPlayerEventListener(IPlayerEventListener &arg0);
	void UnregisterPlayerEventListener(IPlayerEventListener &arg0);
	void CenterReticle();
	void RestrictMovement(bool arg0);
	void EnterCinematicMode();
	void ExitCinematicMode();
	ArkPlayerAudio const &GetAudio() const;
	void OnFlyModeCommand();
	ArkPlayerMovementFSM &GetMovementFSM();
	ArkPlayerMovementFSM const &GetMovementFSM() const;
	void StopSneaking();
	ArkPlayerInput const &GetInput() const;
	ArkPlayerInput &GetInput();
	float GetLastRegisteredInputTime() const;
	ArkExaminationMode &GetExaminationMode();
	ArkExaminationMode const &GetExaminationMode() const;
	ArkPlayerInteraction &GetInteraction();
	ArkPlayerInteraction const &GetInteraction() const;
	Vec2 GetReticlePos() const;
	void UpdateReticleUI() const;
	void SyncEyeOffsetToStanceViewHeight();
	ArkPlayerFlashlight &GetFlashlight();
	ArkPlayerFlashlight const &GetFlashlight() const;
	ArkPlayerZoomManager &GetZoomManager();
	ArkPlayerZoomManager const &GetZoomManager() const;
	float GetIdleFragmentSpeedThreshold() const;
	void LookAtRagdoll(const bool arg0);
	void LearnNameForResearchTopic(const uint64_t arg0);
	bool HasLearnedNameForResearchTopic(const uint64_t arg0) const;
	std::vector<unsigned __int64> const &GetCriticalHitMetaTags() const;
	unsigned AddCameraRotationModifier(Functor2<Ang3_tpl<float> &,float> arg0);
	void RemoveCameraRotationModifier(unsigned arg0);
	bool IsInAir() const;
	void IncreaseCombatIntensity(const float arg0);
	void DecreaseCombatIntensity(const float arg0);
	float GetFearCameraNoiseAmplitude() const;
	ArkPlayerHelmet &GetHelmet();
	ArkPlayerWeaponComponent &GetWeaponComponent();
	ArkPlayerWeaponComponent const &GetWeaponComponent() const;
	void HideShadow() const;
	void ShowShadow() const;
	Vec3 GetReticleViewPosition() const;
	Vec2 GetReticleScreenPosition() const;
	bool IsReticleVewPositionValid() const;
	void OnSpawn(Vec3 arg0, Ang3 arg1);
	IEntity *GetMimicGrabSequenceEntity() const;
	float GetLookAtFarRange() const;
	bool IsInVacuum() const;
	EArkSaveFailure IsSafeForManualSave() const;
	void AutoSaveBlockedBySignal();
	bool HasReceivedStartLevelEvent() const;
	unsigned GetPsiScannerTarget() const;
	unsigned GetRoomEntityId() const;
	void UpdateHUDMarkerElements();
	bool IsSmoke() const;
	void StartMaterialAnimation(ArkMaterialAnimationType arg0);
	void UpdateMaterialAnimation(ArkMaterialAnimationType arg0, const float arg1, const float arg2);
	bool GetShowArmor() const;
	bool GetShowHealth() const;
	bool IsIdleBreakAllowed() const;
	bool HasJustBeenPhysicalized() const;
	unsigned GetPickedUpEntityId() const;
	void SetReticlePos(Vec2 arg0);
#endif
	
	static inline auto FBitNotArkPlayer = PreyFunction<void(ArkPlayer *const _this)>(0x154DED0);
	static inline auto FGetInstance = PreyFunction<ArkPlayer &()>(0x154FA60);
	static inline auto FGetInstancePtr = PreyFunction<ArkPlayer *()>(0x154FA90);
	static inline auto FGetPsiPowerComponentOv1 = PreyFunction<ArkPsiPowerComponent &(ArkPlayer *const _this)>(0x154FC50);
	static inline auto FGetPsiPowerComponentOv0 = PreyFunction<ArkPsiPowerComponent const &(ArkPlayer const *const _this)>(0x154FC50);
	static inline auto FGetStance = PreyFunction<EStance(ArkPlayer const *const _this)>(0x154FF40);
	static inline auto FIsZeroG = PreyFunction<bool(ArkPlayer const *const _this)>(0x1551840);
	static inline auto FGetInventory = PreyFunction<IInventory *(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FGetHealth = PreyFunction<float(ArkPlayer const *const _this)>(0x154FA40);
	static inline auto FSetHealth = PreyFunction<void(ArkPlayer *const _this, float _health)>(0x15575C0);
	static inline auto FIncreaseHealth = PreyFunction<void(ArkPlayer *const _this, float _increase)>(0x1550430);
	static inline auto FTakeDamage = PreyFunction<void(ArkPlayer *const _this, float _damage)>(0x1557FA0);
	static inline auto FGetMaxHealth = PreyFunction<float(ArkPlayer const *const _this)>(0x154FB10);
	static inline auto FSetViewRotation = PreyFunction<void(ArkPlayer *const _this, Quat const &_rotation)>(0x1557D90);
	static inline auto FGetViewRotation = PreyFunction<Quat(ArkPlayer const *const _this)>(0x154FF50);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkPlayer const *const _this, ICrySizer *_pSizer)>(0x154FB30);
	static inline auto FGetCurrentItem = PreyFunction<IItem *(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FGetLinkedEntity = PreyFunction<IEntity *(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FGetSpectatorMode = PreyFunction<uint8_t(ArkPlayer const *const _this)>(0xDD23F0);
	static inline auto FIsDead = PreyFunction<bool(ArkPlayer const *const _this)>(0x1551450);
	static inline auto FRelease = PreyFunction<void(ArkPlayer *const _this)>(0xA97D40);
	static inline auto FIsPsiTargeting = PreyFunction<bool(ArkPlayer const *const _this)>(0x1551560);
	static inline auto FGetAnimatedCharacterOv1 = PreyFunction<IAnimatedCharacter const *(ArkPlayer const *const _this)>(0x154F7A0);
	static inline auto FGetAnimatedCharacterOv0 = PreyFunction<IAnimatedCharacter *(ArkPlayer *const _this)>(0x154F7A0);
	static inline auto FGetLocalEyePos = PreyFunction<Vec3(ArkPlayer const *const _this)>(0x154FAD0);
	static inline auto FGetMovementController = PreyFunction<IMovementController *(ArkPlayer const *const _this)>(0x154FC40);
	static inline auto FGetGodMode = PreyFunction<int(ArkPlayer *const _this)>(0x154FA20);
	static inline auto FIsGod = PreyFunction<int(ArkPlayer *const _this)>(0x1551470);
	static inline auto FSetCustomCameraUpdateFunction = PreyFunction<void(ArkPlayer *const _this, std::function<Quat_tpl<float> __cdecl(float)> _function)>(0x16D5D80);
	static inline auto FSetCustomViewFunction = PreyFunction<void(ArkPlayer *const _this, std::function<void __cdecl(SViewParams &)> _function)>(0x159D2F0);
	static inline auto FSetStance = PreyFunction<void(ArkPlayer *const _this, EStance _stance)>(0x1557AA0);
	static inline auto FUpdatePropulsionPackVisibility = PreyFunction<void(ArkPlayer const *const _this)>(0x1558CB0);
	static inline auto FGetScaledInputRotation = PreyFunction<Ang3(ArkPlayer *const _this, float _frameTime)>(0x154FCC0);
	static inline auto FPhysicalize = PreyFunction<void(ArkPlayer *const _this)>(0x1551EB0);
	static inline auto FResetReticle = PreyFunction<void(ArkPlayer *const _this)>(0x1556B00);
	static inline auto FRevive = PreyFunction<void(ArkPlayer *const _this)>(0x1556B80);
	static inline auto FSetAnimationTag = PreyFunction<void(ArkPlayer const *const _this, const char *_tagName, const bool _bTagState)>(0x1557020);
	static inline auto FSetAnimationTagFromFG = PreyFunction<void(ArkPlayer *const _this, const char *const _tagName, const bool _bTagState)>(0x1557160);
	static inline auto FPlayFragment = PreyFunction<_smart_ptr<TAction<SAnimationContext> >(ArkPlayer *const _this, const char *_pName, IArkPlayer::EArkPlayerAnimationPriority _priority, const unsigned _flags)>(0x1553080);
	static inline auto FStage = PreyFunction<void(ArkPlayer *const _this, Vec3 _viewLimitDir, bool _bLocalSpace, float _viewLimitYaw, float _viewLimitPitch, bool _bLockPlayer, int _stance)>(0x1781C50);
	static inline auto FExecuteGroundMaterialEffectByName = PreyFunction<void(ArkPlayer const *const _this, const char *const _pName, SMFXRunTimeEffectParams &_params)>(0x154F0F0);
	static inline auto FHide = PreyFunction<void(ArkPlayer const *const _this, const bool _bHide)>(0x1550370);
	static inline auto FOnJump = PreyFunction<void(ArkPlayer *const _this)>(0x1551B50);
	static inline auto FShowThirdPerson = PreyFunction<void(ArkPlayer const *const _this, const bool _bShow)>(0x1557E20);
	static inline auto FRagdollize = PreyFunction<void(ArkPlayer *const _this, const float _verticalSpeed)>(0x1555000);
	static inline auto FGetSex = PreyFunction<EPlayerSex(ArkPlayer const *const _this)>(0x154FE20);
	static inline auto FGetArkSpeaker = PreyFunction<IArkSpeaker *(ArkPlayer *const _this)>(0x154F7B0);
	static inline auto FPhysicalizeAndResetAnimatedCharacter = PreyFunction<void(ArkPlayer *const _this)>(0x1553030);
	static inline auto FHasAbility = PreyFunction<bool(ArkPlayer const *const _this, const uint64_t _abilityID)>(0x1550330);
	static inline auto FSetModel = PreyFunction<void(ArkPlayer *const _this, const char *const _modelName)>(0x15575F0);
	static inline auto FIsInGravShaft = PreyFunction<bool(ArkPlayer const *const _this)>(0x15514C0);
	static inline auto FLimitAttentionOnUnseenPlayer = PreyFunction<void(ArkPlayer const *const _this)>(0x15518D0);
	static inline auto FReleaseAttentionLimitOnPlayer = PreyFunction<void(ArkPlayer const *const _this)>(0x1555980);
	static inline auto FIsInCombat = PreyFunction<bool(ArkPlayer const *const _this)>(0x15514A0);
	static inline auto FOnCombatChange = PreyFunction<void(ArkPlayer *const _this, bool _bInCombat)>(0x1551B30);
	static inline auto FCompensateStanceHeightChange = PreyFunction<void(ArkPlayer *const _this, EStance _oldStance, EStance _newStance)>(0x154EA50);
	static inline auto FGetAttackTargetPos = PreyFunction<Vec3(ArkPlayer const *const _this)>(0x154F7C0);
	static inline auto FUpdateCachedReticleViewPosAndDir = PreyFunction<void(ArkPlayer *const _this)>(0x15583F0);
	static inline auto FGetReticleViewPositionAndDir = PreyFunction<std::pair<Vec3,Vec3>(ArkPlayer const *const _this)>(0x154FC80);
	static inline auto FOnNewGame = PreyFunction<void(ArkPlayer *const _this)>(0x1551BE0);
	static inline auto FGetPlayerWorldEyePos = PreyFunction<Vec3(ArkPlayer const *const _this)>(0x131F920);
	static inline auto FGetFragmentIds = PreyFunction<CTagDefinition const *(ArkPlayer const *const _this)>(0x154F9E0);
	static inline auto FKnockdown = PreyFunction<void(ArkPlayer *const _this)>(0x1551850);
	static inline auto FEnterMimicGrabSequence = PreyFunction<void(ArkPlayer *const _this, IEntity const &_mimicEntity)>(0x154EC00);
	static inline auto FExitMimicGrabSequence = PreyFunction<void(ArkPlayer *const _this)>(0x154F1A0);
	static inline auto FIsSafeForAutoSave = PreyFunction<EArkSaveFailure(ArkPlayer const *const _this)>(0x1551580);
	static inline auto FSetRoomEntityId = PreyFunction<void(ArkPlayer *const _this, unsigned _id)>(0x15577E0);
	static inline auto FIsMimicOv1 = PreyFunction<bool(ArkPlayer const *const _this)>(0x1551530);
	static inline auto FIsMimicOv0 = PreyFunction<bool(ArkPlayer const *const _this, const unsigned _entityId)>(0x15514D0);
	static inline auto FGetMimicEntity = PreyFunction<IEntity const *(ArkPlayer const *const _this)>(0x154FB80);
	static inline auto FGetMimicEntityId = PreyFunction<unsigned(ArkPlayer const *const _this)>(0x154FBF0);
	static inline auto FIsAlternateForm = PreyFunction<bool(ArkPlayer const *const _this)>(0x15513F0);
	static inline auto FIsShifting = PreyFunction<bool(ArkPlayer const *const _this)>(0x1551650);
	static inline auto FOnActivatePower = PreyFunction<void(ArkPlayer *const _this)>(0x1551970);
	static inline auto FSetShowArmor = PreyFunction<void(ArkPlayer *const _this, bool _bShowArmor, bool _bForce)>(0x15577F0);
	static inline auto FSetShowHealth = PreyFunction<void(ArkPlayer *const _this, bool _bShowHealth, bool _bForce)>(0x1557950);
	static inline auto FEnableIdleBreak = PreyFunction<void(ArkPlayer *const _this, const bool _bEnable)>(0x154EBF0);
	static inline auto FSerializeLevelToLevel = PreyFunction<void(ArkPlayer *const _this, TSerialize &_ser)>(0x1556C20);
	static inline auto FShouldGenerateGameNoises = PreyFunction<bool(ArkPlayer const *const _this)>(0x1557DF0);
	static inline auto FUpdateShadow = PreyFunction<void(ArkPlayer const *const _this, bool _b3PShadow)>(0x1558D30);
	static inline auto FInitializePerception = PreyFunction<void(ArkPlayer *const _this)>(0x1551380);
	static inline auto FFinalizePerception = PreyFunction<void(ArkPlayer *const _this)>(0x154F210);
	static inline auto FHideAttachment = PreyFunction<void(ArkPlayer const *const _this, const char *_attachmentName, bool _bHide)>(0x15503B0);
	static inline auto FReset = PreyFunction<void(ArkPlayer *const _this)>(0x15559F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkPlayer *const _this, SEntityEvent &_event)>(0x15537B0);
	static inline auto FOnSystemEvent = PreyFunction<void(ArkPlayer *const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x1551C80);
	static inline auto FUpdate = PreyFunction<void(ArkPlayer *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x15580B0);
	static inline auto FFullSerialize = PreyFunction<void(ArkPlayer *const _this, TSerialize _ser)>(0x154F280);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayer *const _this)>(0x1553390);
	static inline auto FInitLocalPlayer = PreyFunction<void(ArkPlayer *const _this)>(0xA13080);
	static inline auto FInit = PreyFunction<bool(ArkPlayer *const _this, IGameObject *_pGameObject)>(0x1550470);
	static inline auto FPostInit = PreyFunction<void(ArkPlayer *const _this, IGameObject *_pGameObject)>(0x1553250);
	static inline auto FInitClient = PreyFunction<void(ArkPlayer *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(ArkPlayer *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkPlayer *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkPlayer *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkPlayer *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkPlayer *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0xDD23F0);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkPlayer *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkPlayer *const _this)>(0x13883F0);
	static inline auto FHandleEvent = PreyFunction<void(ArkPlayer *const _this, SGameObjectEvent const &_event)>(0x154FF80);
	static inline auto FSetAuthority = PreyFunction<void(ArkPlayer *const _this, bool _auth)>(0xA13080);
	static inline auto FPostUpdate = PreyFunction<void(ArkPlayer *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkPlayer *const _this)>(0xA13080);
	static inline auto FGetHealthAsRoundedPercentage = PreyFunction<int(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FSetMaxHealth = PreyFunction<void(ArkPlayer *const _this, float _maxHealth)>(0xA13080);
	static inline auto FGetArmor = PreyFunction<int(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FGetMaxArmor = PreyFunction<int(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FIsFallen = PreyFunction<bool(ArkPlayer const *const _this)>(0xDD23F0);
	static inline auto FFall = PreyFunction<void(ArkPlayer *const _this, Vec3 _hitPos)>(0xA13080);
	static inline auto FAllowLandingBob = PreyFunction<bool(ArkPlayer *const _this)>(0xDD23F0);
	static inline auto FPlayAction = PreyFunction<void(ArkPlayer *const _this, const char *_pAction, const char *_pExtension, bool _bLooping)>(0xA13080);
	static inline auto FGetAnimationGraphState = PreyFunction<IAnimationGraphState *(ArkPlayer *const _this)>(0x158AEF0);
	static inline auto FResetAnimationState = PreyFunction<void(ArkPlayer *const _this)>(0xA13080);
	static inline auto FCreateScriptEvent = PreyFunction<void(ArkPlayer *const _this, const char *_pEvent, float _value, const char *_pStr)>(0xA13080);
	static inline auto FBecomeAggressiveToAgent = PreyFunction<bool(ArkPlayer *const _this, unsigned _entityID)>(0xDD23F0);
	static inline auto FSetFacialAlertnessLevel = PreyFunction<void(ArkPlayer *const _this, int _alertness)>(0xA13080);
	static inline auto FPrecacheFacialExpression = PreyFunction<void(ArkPlayer *const _this, const char *_pExpressionName)>(0xA13080);
	static inline auto FGetGrabbedEntityId = PreyFunction<unsigned(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FHideAllAttachments = PreyFunction<void(ArkPlayer *const _this, bool _bIsHiding)>(0xA13080);
	static inline auto FSetIKPos = PreyFunction<void(ArkPlayer *const _this, const char *_pLimbName, Vec3 const &_goalPos, int _priority)>(0xA13080);
	static inline auto FIsFriendlyEntity = PreyFunction<bool(ArkPlayer const *const _this, unsigned _entityId, bool _bUsingAIIgnorePlayer)>(0xDD23F0);
	static inline auto FCameraShake = PreyFunction<void(ArkPlayer *const _this, float _angle, float _shift, float _duration, float _frequency, Vec3 _pos, int _ID, const char *_pSource)>(0xA13080);
	static inline auto FGetHolsteredItem = PreyFunction<IItem *(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FHolsterItem = PreyFunction<void(ArkPlayer *const _this, bool _bHolster, bool _bPlaySelect, float _selectSpeedBias, bool _bHideLeftHandObject)>(0xA13080);
	static inline auto FDropItem = PreyFunction<bool(ArkPlayer *const _this, unsigned _itemId, float _impulseScale, bool _bSelectNext, bool _bByDeath)>(0xDD23F0);
	static inline auto FNotifyCurrentItemChanged = PreyFunction<void(ArkPlayer *const _this, IItem *_pNewItem)>(0xA13080);
	static inline auto FIsThirdPerson = PreyFunction<bool(ArkPlayer const *const _this)>(0xDD23F0);
	static inline auto FToggleThirdPerson = PreyFunction<void(ArkPlayer *const _this)>(0xA13080);
	static inline auto FIsPlayer = PreyFunction<bool(ArkPlayer const *const _this)>(0x1B933B0);
	static inline auto FIsClient = PreyFunction<bool(ArkPlayer const *const _this)>(0x1B933B0);
	static inline auto FIsMigrating = PreyFunction<bool(ArkPlayer const *const _this)>(0xDD23F0);
	static inline auto FSetMigrating = PreyFunction<void(ArkPlayer *const _this, bool _bIsMigrating)>(0xA13080);
	static inline auto FGetActorClassName = PreyFunction<const char *(ArkPlayer const *const _this)>(0x154F790);
	static inline auto FGetActorClass = PreyFunction<int(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FSerializeXML = PreyFunction<void(ArkPlayer *const _this, XmlNodeRef &_node, bool _bLoading)>(0xA13080);
	static inline auto FPlayExactPositioningAnimation = PreyFunction<void(ArkPlayer *const _this, const char *_pAnimationName, bool _bSignal, Vec3 const &_position, Vec3 const &_direction, float _startWidth, float _startArcAngle, float _directionTolerance)>(0xA13080);
	static inline auto FCancelExactPositioningAnimation = PreyFunction<void(ArkPlayer *const _this)>(0xA13080);
	static inline auto FPlayAnimation = PreyFunction<void(ArkPlayer *const _this, const char *_pAnimationName, bool _bSignal)>(0xA13080);
	static inline auto FEnableTimeDemo = PreyFunction<void(ArkPlayer *const _this, bool _bTimeDemo)>(0xA13080);
	static inline auto FSwitchDemoModeSpectator = PreyFunction<void(ArkPlayer *const _this, bool _bActivate)>(0xA13080);
	static inline auto FOnAIProxyEnabled = PreyFunction<void(ArkPlayer *const _this, bool _bEnabled)>(0xA13080);
	static inline auto FOnReturnedToPool = PreyFunction<void(ArkPlayer *const _this)>(0xA13080);
	static inline auto FShouldMuteWeaponSoundStimulus = PreyFunction<bool(ArkPlayer const *const _this)>(0xDD23F0);
	static inline auto FOnReused = PreyFunction<void(ArkPlayer *const _this, IEntity *_pEntity, SEntitySpawnParams &_params)>(0xA13080);
	static inline auto FRequestFacialExpression = PreyFunction<void(ArkPlayer *const _this, const char *_pExpressionName, float *_pSequenceLength)>(0xA13080);
	static inline auto FGetEntityClassName = PreyFunction<const char *(ArkPlayer const *const _this)>(0x154F9B0);
	static inline auto FOnPreparedFromPool = PreyFunction<void(ArkPlayer *const _this)>(0xA13080);
	static inline auto FGetEventPriority = PreyFunction<int(ArkPlayer const *const _this, const int _eventID)>(0x154F9C0);
	static inline auto FGetTeamId = PreyFunction<int(ArkPlayer const *const _this)>(0x158AEF0);
	static inline auto FGetBoneTransform = PreyFunction<QuatT const &(ArkPlayer const *const _this, int ID)>(0x154F910);
	static inline auto FInhibitRotation = PreyFunction<void(ArkPlayer *const _this, const bool _bInhibit)>(0x1550460);
	static inline auto FCheckForCoral = PreyFunction<void(ArkPlayer const *const _this)>(0x154E570);
	static inline auto FSetFaction = PreyFunction<void(ArkPlayer *const _this)>(0x15573B0);
};

