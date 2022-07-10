#pragma once
#include <array>
#include <utility>
#include <functional>
#include <Prey/CryCore/functor.h>
#include <Prey/CryMath/Cry_Math.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryAction/IMovementController.h>
#include "preyDllObjects.h"

struct ArkPlayer;
struct IAnimationGraphState;
struct IItem;
struct HitInfo;
class CFragmentCache;

struct IInventoryListener
{
public:
	virtual ~IInventoryListener() = 0;
	virtual void OnAddItem(unsigned int) = 0;
	virtual void OnRemoveItem(unsigned int) = 0;
	virtual void OnSetAmmoCount(const IEntityClass*) = 0;
	virtual void OnClearInventory() = 0;


};

struct IInventory : public IGameObjectExtension {
	enum EArkInventorySizes
	{
		smallExternal = 1,
		mediumExternal = 2,
		largeExternal = 3,
		player = 4
	};
	enum EInventorySlots
	{
		eInventorySlot_Weapon = 0,
		eInventorySlot_Explosives = 1,
		eInventorySlot_Grenades = 2,
		eInventorySlot_Special = 3,
		eInventorySlot_Last = 4
	};
	virtual bool AddItem(unsigned int) = 0;
	virtual void RemoveItem(const IEntityClass* const, CCryName, int) = 0;
	virtual bool RemoveItem(unsigned int, int) = 0;
	virtual bool RemoveItemStack(unsigned int) = 0;
	virtual void RemoveAllItems(bool) = 0;
	virtual void Destroy() = 0;
	virtual void Clear(bool) = 0;
	virtual int GetCount() = 0;
	virtual int GetCountOfClass(const char*) = 0;
	virtual int GetCountOfClass(const char*, const CCryName) = 0;
	virtual int GetCountOfCategory(const char*) = 0;
	virtual int GetCountOfUniqueId(unsigned __int8) = 0;
	virtual std::pair<int, int>* GetLocationOfItem(std::pair<int, int>* result, unsigned int) = 0;
	virtual unsigned int GetItemAtLocation(int, int) = 0;
	virtual bool SetItemLocation(unsigned int, int, int) = 0;
	virtual bool PlaceItem(unsigned int) = 0;
	virtual std::vector<unsigned int>* GetItemOverlap(std::vector<unsigned int>* result, int, int, int, int) = 0;
	virtual int GetMaxInventoryWidth() = 0;
	virtual int GetMaxInventoryHeight() = 0;
	virtual IInventory::EArkInventorySizes GetSize() = 0;
	virtual bool CanPlaceItem(unsigned int, int, int, bool) = 0;
	virtual const char* GetIcon(unsigned int) = 0;
	virtual int GetSlotCount(int) = 0;
	virtual IScriptTable* GetAllItems(const char*) = 0;
	virtual unsigned int GetItem(int) = 0;
	virtual const char* GetItemString(int) = 0;
	virtual unsigned int GetItemByClass(const IEntityClass*, CCryName) = 0;
	virtual IItem* GetItemByName(const char*) = 0;
	virtual IArkItem* GetArkItemByName(const char*) = 0;
	virtual IArkItem* GetSmallestStack(const IEntityClass*, CCryName, int) = 0;
	virtual IArkItem* GetLargestStack(const IEntityClass*, CCryName, int) = 0;
	virtual bool ConsumeArkItem(const char*, int) = 0;
	virtual bool ConsumeArkItem(const IEntityClass*, int) = 0;
	virtual int FindItem(unsigned int) = 0;
	virtual int FindNext(const IEntityClass*, const char*, int, bool) = 0;
	virtual int FindPrev(const IEntityClass*, const char*, int, bool) = 0;
	virtual unsigned int GetCurrentItem() = 0;
	virtual unsigned int GetHolsteredItem() = 0;
	virtual void SetCurrentItem(unsigned int) = 0;
	virtual void SetHolsteredItem(unsigned int) = 0;
	virtual void SetLastItem(unsigned int) = 0;
	virtual unsigned int GetLastItem() = 0;
	virtual unsigned int GetLastSelectedInSlot(IInventory::EInventorySlots) = 0;
	virtual void HolsterItem(bool) = 0;
	virtual void SerializeInventoryForLevelChange(CSerializeWrapper<ISerialize>) = 0;
	virtual bool IsSerializingForLevelChange() = 0;
	virtual int GetAmmoCount(const IEntityClass*) = 0;
	virtual void GiveAmmo(const IEntityClass*, int) = 0;
	virtual void RemoveAmmo(const IEntityClass*, int) = 0;
	virtual bool CanGiveAmmo(const IEntityClass*) = 0;
	virtual IActor* GetActor() = 0;
	virtual void SetInventorySlotCapacity(IInventory::EInventorySlots, unsigned int) = 0;
	virtual void AssociateItemCategoryToSlot(const char*, IInventory::EInventorySlots) = 0;
	virtual bool IsAvailableSlotForItemClass(const char*) = 0;
	virtual bool IsAvailableSlotForItemCategory(const char*) = 0;
	virtual bool AreItemsInSameSlot(const char*, const char*) = 0;
	virtual IInventory::EInventorySlots GetSlotForItemCategory(const char*) = 0;
	virtual void AddListener(IInventoryListener*) = 0;
	virtual void RemoveListener(IInventoryListener*) = 0;
};

struct IArkPlayer
{
public:
	virtual std::pair<Vec3, Vec3> GetReticleViewPositionAndDir() = 0;
	virtual void EnableIdleBreak(const bool) = 0;
	virtual void InhibitRotation(const bool) = 0;
};

class IArkPlayerCombatListener
{
public:
	virtual void OnCombatChange(bool) = 0;
	virtual void OnGrenadeThrown(IEntity *const) = 0;
};

class IArkInventoryListener
{
public:
	virtual void OnItemAdded(unsigned int, unsigned int) = 0;
	virtual void OnItemRemoved(unsigned int) = 0;
	virtual void OnItemCountChanged(unsigned int) = 0;
};

class IArkAbilityListener
{
public:
	virtual void OnAbilityAdded(unsigned __int64) = 0;
	virtual void OnBecomeAlien() = 0;
};

struct IActor : public IGameObjectExtension
{
	struct TrackviewLookPoseData;

	virtual void SetHealth(float) = 0;
	virtual float GetHealth() = 0;
	virtual int GetHealthAsRoundedPercentage() = 0;
	virtual void SetMaxHealth(float) = 0;
	virtual float GetMaxHealth() = 0;
	virtual int GetArmor() = 0;
	virtual int GetMaxArmor() = 0;
	virtual int GetTeamId() = 0;
	virtual bool IsFallen() = 0;
	virtual bool IsDead() = 0;
	virtual int IsGod() = 0;
	virtual void Fall(Vec3_tpl<float>) = 0;
	virtual bool AllowLandingBob() = 0;
	virtual EStance GetLockedStance() = 0;
	virtual EStance GetStance() = 0;
	virtual void PlayAction(const char *, const char *, bool) = 0;
	virtual IAnimationGraphState *GetAnimationGraphState() = 0;
	virtual void ResetAnimationState() = 0;
	virtual void CreateScriptEvent(const char *, float, const char *) = 0;
	virtual bool BecomeAggressiveToAgent(unsigned int) = 0;
	virtual void SetFacialAlertnessLevel(int) = 0;
	virtual void RequestFacialExpression(const char *, float *) = 0;
	virtual void PrecacheFacialExpression(const char *) = 0;
	virtual unsigned int GetGrabbedEntityId() = 0;
	virtual void HideAllAttachments(bool) = 0;
	virtual void SetIKPos(const char *, const Vec3_tpl<float> *, int) = 0;
	virtual void SetViewRotation(const Quat_tpl<float> *) = 0;
	virtual Quat_tpl<float> *GetViewRotation(Quat_tpl<float> *result) = 0;
	virtual bool IsFriendlyEntity(unsigned int, bool) = 0;
	virtual Vec3_tpl<float> GetLocalEyePos() = 0;
	virtual void CameraShake(float, float, float, float, Vec3_tpl<float>, int, const char *) = 0;
	virtual IItem *GetHolsteredItem() = 0;
	virtual void HolsterItem(bool, bool, float, bool) = 0;
	virtual IItem *GetCurrentItem() = 0;
	virtual bool DropItem(unsigned int, float, bool, bool) = 0;
	virtual IInventory *GetInventory() = 0;
	virtual void NotifyCurrentItemChanged(IItem *) = 0;
	virtual IMovementController *GetMovementController() = 0;
	virtual IEntity *GetLinkedEntity() = 0;
	virtual unsigned __int8 GetSpectatorMode() = 0;
	virtual bool IsThirdPerson() = 0;
	virtual void ToggleThirdPerson() = 0;
	virtual bool IsStillWaitingOnServerUseResponse() = 0;
	virtual void SetStillWaitingOnServerUseResponse(bool) = 0;
	virtual void SetFlyMode(unsigned __int8, const float) = 0;
	virtual unsigned __int8 GetFlyMode() = 0;
	virtual bool IsPlayer() = 0;
	virtual bool IsClient() = 0;
	virtual bool IsMigrating() = 0;
	virtual void SetMigrating(bool) = 0;
	virtual void InitLocalPlayer() = 0;
	virtual const char *GetActorClassName() = 0;
	virtual int GetActorClass() = 0;
	virtual const char *GetEntityClassName() = 0;
	virtual void SerializeXML(XmlNodeRef *, bool) = 0;
	virtual void SerializeLevelToLevel(CSerializeWrapper<ISerialize> *) = 0;
	virtual IAnimatedCharacter *GetAnimatedCharacter() = 0;
	virtual const IAnimatedCharacter *GetAnimatedCharacter() const = 0;
	virtual void PlayExactPositioningAnimation(const char *, bool, const Vec3_tpl<float> *, const Vec3_tpl<float> *, float, float, float) = 0;
	virtual void CancelExactPositioningAnimation() = 0;
	virtual void PlayAnimation(const char *, bool) = 0;
	virtual void SetTrackviewArkLookAt(IEntity *, const IActor::TrackviewLookPoseData *, const IActor::TrackviewLookPoseData *, const IActor::TrackviewLookPoseData *) = 0;
	virtual void SetTrackviewArkAimAt(IEntity *, const IActor::TrackviewLookPoseData *) = 0;
	virtual IArkSpeaker *GetArkSpeaker() = 0;
	virtual bool Respawn() = 0;
	virtual void ResetToSpawnLocation() = 0;
	virtual bool CanBreakGlass() = 0;
	virtual bool MustBreakGlass() = 0;
	virtual void EnableTimeDemo(bool) = 0;
	virtual void SwitchDemoModeSpectator(bool) = 0;
	virtual void SetCustomHead(const char *) = 0;
	virtual void OnAIProxyEnabled(bool) = 0;
	virtual void OnReturnedToPool() = 0;
	virtual void OnPreparedFromPool() = 0;
	virtual bool MountedGunControllerEnabled() = 0;
	virtual void MountedGunControllerEnabled(bool) = 0;
	virtual bool ShouldMuteWeaponSoundStimulus() = 0;
	virtual int GetPhysicalSkipEntities(IPhysicalEntity **, const int) = 0;
	virtual void OnReused(IEntity *, SEntitySpawnParams *) = 0;
	virtual void OnFakeHitToHitReactions(const HitInfo *) = 0;
	virtual Vec3_tpl<float> *GetAttackTargetPos(Vec3_tpl<float> *result) = 0;
	virtual bool IsArkNpcPlayer() = 0;
	virtual void IgnoreCollisionSignals(unsigned int, float) = 0;
	virtual bool IsIgnoringCollisionSignals(unsigned int) = 0;
	virtual bool IsZeroG() = 0;
};

struct CActor : public IActor
{
};

struct ArkPlayerMovementFSM {
	static constexpr size_t OFFSET_m_groundState = 0x8; // ArkPlayerMovementStates::Ground
	static constexpr size_t OFFSET_Ground_m_requestedStance = 0x180; // EStance


	char pad[0x620];
};

class ArkPlayerComponent
{
public:
	std::unique_ptr<CArkPsiComponent> m_pPsiComponent;
	std::unique_ptr<ArkAbilityComponent> m_pAbilityComponent;
	std::unique_ptr<ArkAudioLogComponent> m_pAudioLogComponent;
	std::unique_ptr<ArkNoteComponent> m_pNoteComponent;
	std::unique_ptr<ArkKeyCodeComponent> m_pKeyCodeComponent;
	std::unique_ptr<ArkLocationComponent> m_pLocationComponent;
	std::unique_ptr<ArkLoreComponent> m_pLoreComponent;
	std::unique_ptr<ArkKeyCardComponent> m_pKeyCardComponent;
	std::unique_ptr<ArkEmailComponent> m_pEmailComponent;
	std::unique_ptr<ArkQuickSelectComponent> m_pQuickSelectComponent;
	std::unique_ptr<ArkRosterComponent> m_pRosterComponent;
	std::unique_ptr<ArkUtilityComponent> m_pUtilityComponent;
	std::unique_ptr<ArkPharmaComponent> m_pPharmaComponent;
	std::unique_ptr<ArkPDAComponent> m_pPDAComponent;
	std::unique_ptr<ArkPlayerAchievementComponent> m_pAchievementComponent;
	std::unique_ptr<ArkPlayerAwarenessComponent> m_pAwarenessComponent;
	std::unique_ptr<ArkPlayerEntitlementComponent> m_pEntitlementComponent;
	std::unique_ptr<ArkPlayerFatigueComponent> m_pFatigueComponent;
	std::unique_ptr<ArkPlayerHealthComponent> m_pHealthComponent;
	std::unique_ptr<ArkPlayerRadiationComponent> m_pRadiationComponent;
	std::unique_ptr<ArkPlayerLightManager> m_pLightManager;
	std::unique_ptr<ArkPlayerFXComponent> m_pFXComponent;
	std::unique_ptr<ArkPlayerUIComponent> m_pUIComponent;
	std::unique_ptr<ArkFabricationPlanComponent> m_pFabricationPlanComponent;
	std::unique_ptr<ArkPlayerStatusComponent> m_pStatusComponent;
	std::unique_ptr<ArkPlayerPropulsionComponent> m_pPropulsionComponent;
	std::unique_ptr<ArkPlayerSignalReceiver> m_pSignalReceiver;
	std::unique_ptr<ArkAimAssistComponent> m_pAimAssistComponent;
	std::unique_ptr<ArkMarkedEnemyComponent> m_pMarkedEnemyComponent;
	std::unique_ptr<ArkPlayerScopeComponent> m_pScopeComponent;
	std::unique_ptr<ArkSpeaker<ArkDialogPlayer>> m_pPlayerSpeaker;
	std::unique_ptr<ArkSpeaker<ArkDialogPlayer>> m_pSuitSpeaker;
	std::unique_ptr<ArkSpeaker<ArkDialogPlayer>> m_pDiscRifleSpeaker;
	std::unique_ptr<ArkSpeaker<ArkDialogPlayerTranscribe>> m_pTranscribeSpeaker;
	std::unique_ptr<ArkGameMetricsComponent> m_pGameMetricsComponent;
	std::unique_ptr<ArkFocusModeComponent> m_pFocusModeComponent;
	std::unique_ptr<ArkLiveTranscribeComponent> m_pLiveTranscribeComponent;
	std::unique_ptr<ArkStationAccessComponent> m_pStationAccessComponent;
	std::unique_ptr<ArkPOIComponent> m_pPOIComponent;
	float m_fShadowDissolveBlend;
	float m_fShadowDissolveTarget;
	float m_fShadowDissolveTimeScale;
	bool m_bItemsRestricted;
	bool m_bMarkerTextDisplayed;
};

static_assert(sizeof(ArkPlayerComponent) == 0x148);

struct ArkEquipmentModComponent
{
	const bool m_bSuitMods;
	std::vector<unsigned int> m_ownedChipsets;
	std::array<unsigned int, 8> m_installedChipsets;
};

struct ArkPlayerInput : public IActionListener, public IActionMapEventListener {
	typedef IInventory::EArkInventorySizes Mode;

	enum class CinematicMode
	{
		off = 0x0,
		allowLook = 0x1,
		complete = 0x2,
	};

	struct ModeAndHandle
	{
		Mode m_mode;
		int m_handle;
	};

	struct MovementButtonPressInfo
	{
		bool bForward;
		bool bBack;
		bool bLeft;
		bool bRight;
	};

	std::vector<ModeAndHandle> m_modeStack;
	TActionHandler<ArkPlayerInput> m_actionHandler;
	Ang3 m_deltaRotation;
	Ang3 m_gamePadRotation;
	Ang3 m_adjustedGamePadRotation;
	Vec2 m_movement;
	Vec2 m_reticleMovement;
	MovementButtonPressInfo m_movementButtonPressInfo;
	ArkPlayer *m_player;
	float m_debugTimeScale;
	float m_lean;
	float m_rawLean;
	float m_lastRegisteredInputTime;
	float m_currentGamePadRotationSpeed;
	int m_mashesRemaining;
	int m_mimicGrabMashesRequired;
	CinematicMode m_cinematicMode;
	float m_sprintCameraRotationRateScale;
	float m_zoomCameraRotationRateScale;
	float m_sprintCancelForwardThreshold;
	float m_sprintCancelBackwardThreshold;
	float m_sprintCancelStrafeThreshold;
	bool m_bSprint;
	bool m_bUseHeld;
	bool m_bTriggeredUse;
	bool m_bTriggeredHoldUse;
	bool m_bTriggeredSpecialUse;
	bool m_bZeroGBraking;
	bool m_bSprintInhibited;
	bool m_bJumpInhibited;
	bool m_bRotationInhibited;
	bool m_bLeftLean;
	bool m_bRightLean;
	float m_deadzone;
	float m_curvePercentTurnSpeed;
	float m_accelerationThreshold;
	float m_accelerationRate;
	float m_accelerationMaxTurnSpeed;
	Mode m_disabledMode;

	void OnAction(const ActionId &action, int activationMode, float value) override { assert(false); }
	void AfterAction() override { assert(false); };
	void OnActionMapEvent(const SActionMapEvent &event) override { assert(false); }
};

static_assert(sizeof(ArkPlayerInput) == 0xD0);

struct ArkExaminationMode {
	char pad[0x118];
};

struct ArkPlayerInteraction {
	char pad[0x6E8];
};

struct ArkGroundColliderComponent
{
	const IEntity *m_pOwner;
	unsigned int m_groundEntity;
};

struct ArkPlayerFlashlight {
	char pad[0x90];
};

struct ArkPlayerAudio {
	char pad[0x50];
};

struct ArkPlayerCamera : public IGameObjectView {
	enum class Mode {
		playerControl,
		animation,
		custom,
		animationToPlayerControl,
		death,
		deathByRecycerGrenade,
		last
	};

	std::array<string, 17> m_boneNames;
	std::function<Quat(float)> m_customUpdateFunction;
	std::function<Vec3(float)> m_customOffsetFunction;
	std::function<void __cdecl(SViewParams &)> m_customViewFunction;
	Quat m_rotation;
	Vec2 m_recoilStep;
	float m_recoilTimeRemaining;
	float m_recoilDelayRemaining;
	float m_leanAmount;
	float m_leanAngle;
	float m_leanOffset;
	float m_eyeOffset;
	float m_transitionTime;
	float m_transitionTimeRemain;
	Quat m_transitionStartRot;
	Vec3 m_deathPos;
	ArkPlayerCamera::Mode m_mode;
	float m_bRecycleGrenadeDeathSpeed;
	Vec3 m_nonLeaningTargetPosition;
	float m_FPIKWeight;
	float m_FPIKWeightTarget;
	float m_stanceChangeInterSpeed;

	void UpdateView(SViewParams &params) override { assert(false); }
	void PostUpdateView(SViewParams &params) override { assert(false); }
};

static_assert(sizeof(ArkPlayerCamera) == 0x1C8);

struct ArkPlayerHelmet {
	char pad[0x50];
};

struct ArkPlayerWeaponComponent : public IArkInventoryListener, public IArkAbilityListener, public IEntityEventListener {
	struct GameLogData {
		unsigned int m_target;
		ArkTimeRemaining m_timer;
	};

	std::vector<unsigned int> m_weaponEntityIds;
	std::vector<unsigned int> m_specialWeaponIds;
	ArkPlayer *m_player;
	ArkAudioTrigger m_triggerSneakAttack;
	ArkAudioTrigger m_triggerCriticalHit;
	unsigned int m_equippedWeaponId;
	unsigned int m_lastEquippedWeaponId;
	unsigned int m_backupWeaponId;
	unsigned int m_toBeEquippedWeaponId;
	float m_weaponCameraSpeedMultiplierAcceleration;
	float m_weaponCameraSpeedMultiplier;
	float m_aimAssistTargetRangeSq;
	float m_gameLogReportWindow;
	bool m_bIsUnequipping;
	bool m_bCanEquip;
	std::vector<unsigned __int64> m_weaponTypesAcquired;
	std::vector<GameLogData> m_sneakAttackData;
	std::vector<GameLogData> m_criticalHitData;
	std::vector<GameLogData> m_mimicHitData;

	void OnItemAdded(unsigned int, unsigned int) override { assert(false); }
	void OnItemRemoved(unsigned int) override { assert(false); }
	void OnItemCountChanged(unsigned int) override { assert(false); }
	void OnAbilityAdded(unsigned __int64) override { assert(false); }
	void OnBecomeAlien() override { assert(false); }
	void OnEntityEvent(IEntity *pEntity, SEntityEvent &event) override { assert(false); }
};

static_assert(sizeof(ArkPlayerWeaponComponent) == 0xE0);

struct ArkPlayerMovementController : public IMovementController
{
};

struct ArkPlayer : public CGameObjectExtensionHelper<ArkPlayer, CActor>, public IArkPlayer,
	public IArkPlayerCombatListener, public ISystemEventListener
{
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
	std::vector<std::pair<string, unsigned int>> m_attachmentFlags;
	std::vector<unsigned __int64> m_learnedNames;
	std::vector<unsigned __int64> m_criticalHitMetaTags;
	std::vector<string> m_animationTagsSetFromFG;
	std::array<StanceInfo, 18> m_stanceInfos;
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
	unsigned __int64 m_coralSignalPackageId;
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
	unsigned int m_rotationModifierHandleGenerator;
	std::vector<std::pair<unsigned int, Functor2<Ang3 &, float> >> m_rotationModifiers;
	unsigned int m_mimicGrabSequenceEntityId;
	ArkMaterialAnimationManager m_materialAnimationManager;
};

static_assert(sizeof(ArkPlayer) == 0x1B38);
