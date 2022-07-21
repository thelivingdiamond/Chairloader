#pragma once
#include <array>
#include <utility>
#include <functional>
#include <boost/optional/optional.hpp>
#include <Prey/CryCore/functor.h>
#include <Prey/CryMath/Cry_Math.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryAction/IMovementController.h>

#include "ArkItemSystem.h"
#include "ArkPlayerComponent.h"
#include "ArkPlayerMovementStates.h"
#include "ArkPsiComponent.h"
#include "ArkSpeaker.h"
#include "EStance.h"
#include "IArkPlayer.h"

struct IActor;
struct ArkPlayer;
struct IAnimationGraphState;
struct IItem;
struct HitInfo;
class CFragmentCache;
class IAnimatedCharacter
{
public:
	char pad_0000[64]; //0x0000
}; //Size: 0x0040
struct IInventoryListener
{
public:
	virtual ~IInventoryListener() = 0;
	virtual void OnAddItem(unsigned int) = 0;
	virtual void OnRemoveItem(unsigned int) = 0;
	virtual void OnSetAmmoCount(const IEntityClass*) = 0;
	virtual void OnClearInventory() = 0;


};
enum EPlayerSex
{
	male = 0,
	female = 1,
	count = 2
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
template <typename T> class ArkPlayerMovementFsmBase_template_
{
public:
	EArkPlayerMovementStateId m_currentStateId;
	ArkPlayerMovementStates::Ground m_groundState;
	ArkPlayerMovementStates::Death m_deathState;
	ArkPlayerMovementStates::DeathByRecyclerGrenade m_deathByRecyclerGrenadeState;
	ArkPlayerMovementStates::Jump m_jumpState;
	ArkPlayerMovementStates::Fall m_fallState;
	ArkPlayerMovementStates::Climb m_climbState;
	ArkPlayerMovementStates::Fly m_flyState;
	ArkPlayerMovementStates::Smoke m_smokeState;
	ArkPlayerMovementStates::ZeroG m_zerogState;
	ArkPlayerMovementStates::Cinematic m_cinematicState;
	ArkPlayerMovementStates::Slide m_slideState;
	ArkPlayerMovementStates::Mimic m_mimicState;
	ArkPlayerMovementStates::GravShaftG m_gravShaftGState;
	ArkPlayerMovementStates::GravShaftToG m_gravShaftToGState;
	ArkPlayerMovementStates::GravShaftZeroG m_gravShaftZeroGState;
	ArkPlayerMovementStates::Lift m_liftState;
	ArkPlayerMovementStates::Shift m_shiftState;
};
static_assert(sizeof(ArkPlayerMovementFsmBase_template_<void>) == 0x5c0);

class ClimbPosInfo
{
public:
	Vec3 m_point; //0x0000
	EStance m_stance; //0x000C
}; //Size: 0x0010
class ArkPlayerMovementFSM : public ArkPlayerMovementFsmBase_template_<void>
{
public:
	class StagingInfo
	{
		Ang3_tpl<float> m_rotation;
		float m_yaw;
		float m_pitch;
	};
	enum class EArkFlyMode {
		off = 0,
		on = 1,
		onNoCollision = 2
	};
	boost::optional<ClimbPosInfo> m_climbPosInfo;
	ArkPlayerMovementFSM::StagingInfo m_stagingInfo;
	ArkPlayerMovementFSM::EArkFlyMode m_flyMode;
	float m_carrySpeedScale;
	float m_climbHorizontalFromEdgeProbeDistance;
	float m_climbVerticalReachDistance;
	float m_climbVerticalNormalMaxAngle;
	float m_cameraRoll;
	float m_cameraRollMaxAngle;
	float m_cameraRollIncreaseSpeed;
	float m_cameraRollRecoverySpeed;
	float m_airControl;
	bool m_bInputSneak;
	bool m_bInputJumpPressed;
	bool m_bJumpRequested;
	bool m_bMovementRestricted;
	float m_verticalSpeed;
	float m_jumpRequestedTime;
	static inline auto SetStateIfNotDead = PreyFunction<void(ArkPlayerMovementFSM* _this)>(0x156e0d0);
	static inline auto CanFit = PreyFunction<bool(Vec3_tpl<float>* param_1, EStance param_2, Vec3_tpl<float>* param_3, unsigned int param_4)>(0x156f150);
	static inline auto CheckZeroG = PreyFunction<bool(ArkPlayerMovementFSM* _this)>(0x156f3a0);
	static inline auto GetCameraRotationInfluence = PreyFunction<Ang3_tpl<float>* (ArkPlayerMovementFSM* _this, Ang3_tpl<float>* __return_storage_ptr__, float param_1)>(0x156f5e0);
	static inline auto GetCarrySpeedScale = PreyFunction<float(ArkPlayerMovementFSM* _this)>(0x156f870);
	static inline auto GetClimbPosInfo_Internal = PreyFunction<boost::optional<ClimbPosInfo>(ArkPlayerMovementFSM* _this)>(0x156f880);
	static inline auto GetLeanInput = PreyFunction<float(ArkPlayerMovementFSM* _this)>(0x156fb20);
	static inline auto GetMaxMovementSpeed = PreyFunction<float(ArkPlayerMovementFSM* _this, EStance param_1)>(0x156fba0);
	static inline auto GetMovementInput = PreyFunction<Vec2_tpl<float>(ArkPlayerMovementFSM* _this)>(0x156fc40);
	static inline auto GetNumPointsInZeroG = PreyFunction<int(void)>(0x156fd60);
	static inline auto GetTimeOfJumpRequest = PreyFunction<float(ArkPlayerMovementFSM* _this)>(0x156ff40);
	static inline auto GetViewHeightInterpolationSpeed = PreyFunction<float(ArkPlayerMovementFSM* _this)>(0x156ff50);
	static inline auto GetWindVelocity = PreyFunction<Vec3_tpl<float>* (Vec3_tpl<float>* __return_storage_ptr__)>(0x1570010);
	static inline auto GetWorldMovement = PreyFunction<Vec2_tpl<float>(ArkPlayerMovementFSM* _this)>(0x1570260);
	static inline auto IsInZeroG = PreyFunction<bool(ArkPlayerMovementFSM* _this)>(0x1570370);
	static inline auto IsInputJumpPressed = PreyFunction<bool(ArkPlayerMovementFSM* _this)>(0x1570550);
	static inline auto IsInputSneakPressed = PreyFunction<bool(ArkPlayerMovementFSM* _this)>(0x1570560);
	static inline auto IsJumpRequested = PreyFunction<bool(ArkPlayerMovementFSM* _this)>(0x1570570);
	static inline auto IsSprinting = PreyFunction<bool(ArkPlayerMovementFSM* _this)>(0x1570580);
	static inline auto LimitRotation = PreyFunction<void(ArkPlayerMovementFSM* _this, Quat_tpl<float>* param_1)>(0x1570600);
	static inline auto LoadConfig = PreyFunction<void(ArkPlayerMovementFSM* _this, XmlNodeRef* param_1)>(0x1570870);
	static inline auto OnFlyModePressed = PreyFunction<void(ArkPlayerMovementFSM* _this)>(0x15710E0);
	static inline auto PostSerialize = PreyFunction<void(ArkPlayerMovementFSM* _this)>(0x15711d0);
	static inline auto ProcessClimb = PreyFunction<bool(ArkPlayerMovementFSM* _this)>(0x15711f0);
	static inline auto ProcessRotation = PreyFunction<void(ArkPlayerMovementFSM* _this, Quat_tpl<float>* param_1, Ang3_tpl<float>* param_2)>(0x1571310);
	static inline auto RestrictMovement = PreyFunction<void(ArkPlayerMovementFSM* _this, bool param_1)>(0x15715d0);
	static inline auto Serialize = PreyFunction<void(ArkPlayerMovementFSM* _this, CSerializeWrapper<ISerialize> param_1)>(0x15715E0);
	static inline auto SetCarrySpeedScale = PreyFunction<void(ArkPlayerMovementFSM* _this, float param_1)>(0x15716f0);
	static inline auto SetInputJumpPressed = PreyFunction<void(ArkPlayerMovementFSM* _this, bool param_1)>(0x1571700);
	static inline auto SetInputSneak = PreyFunction<void(ArkPlayerMovementFSM* _this, bool param_1)>(0x1571710);
	static inline auto SetJumpRequested = PreyFunction<void(ArkPlayerMovementFSM* _this, bool param_1)>(0x15717a0);
	static inline auto SetMovementParameters = PreyFunction<void(ArkPlayerMovementFSM* _this, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters* param_1, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters* param_2)>(0x1571880);
	static inline auto SetRequestedStance = PreyFunction<void(ArkPlayerMovementFSM* _this, EStance param_1)>(0x15718b0);
	static inline auto SetStagingInfo = PreyFunction<void(ArkPlayerMovementFSM* _this, Ang3_tpl<float>* param_1, float param_2, float param_3, bool param_4, int param_5)>(0x15718d0);
	static inline auto TrySetStance = PreyFunction<bool(EStance param_1)>(0x1571980);
	static inline auto Update = PreyFunction<void(ArkPlayerMovementFSM* _this, float param_1)>(0x1571af0);

};
static_assert(sizeof(ArkPlayerMovementFSM) == 0x620);



struct ArkEquipmentModComponent
{
	const bool m_bSuitMods;
	std::vector<unsigned int> m_ownedChipsets;
	std::array<unsigned int, 8> m_installedChipsets;
};

struct ArkPlayerInput : public IActionListener, public IActionMapEventListener {
	enum Mode
	{
		player = 0,
		world_ui_examination = 1,
		examination = 2,
		menu = 3,
		flycam = 4,
		focusmode = 5,
		ether_duplicate = 6,
		hacking = 7,
		psi_scanning_fanfare = 8,
		mimic_grab = 9,
		_count = 10
	};

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
public:
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
	static inline auto CheckForCoral = PreyFunction<void(ArkPlayer* _this)>(0x154e570);
	static inline auto CompensateStanceHeightChange = PreyFunction<void(ArkPlayer* _this, EStance param_1, EStance param_2)>(0x154ea50);
	static inline auto EnableIdleBreak = PreyFunction<void(ArkPlayer* _this, bool param_1)>(0x154ebf0);
	static inline auto EnterMimicGrabSequence = PreyFunction<void(ArkPlayer* _this, IEntity* param_1)>(0x154ec00);
	static inline auto ExecuteGroundMaterialEffectByName = PreyFunction<void(ArkPlayer* _this, const char* param_1, SMFXRunTimeEffectParams* param_2)>(0x154f0f0);
	static inline auto ExitMimicGrabSequence = PreyFunction<void(ArkPlayer* _this)>(0x154f1a0);
	static inline auto FinalizePerception = PreyFunction<void(ArkPlayer* _this)>(0x154f210);
	static inline auto GetFragmentIds = PreyFunction<CTagDefinition* (ArkPlayer* _this)>(0x154f9e0);
	static inline auto GetGodMode = PreyFunction<int(ArkPlayer* _this)>(0x154fa20);
	static inline auto GetInstance = PreyFunction<ArkPlayer* (void)>(0x154fa60);
	static inline auto GetInstancePtr = PreyFunction<ArkPlayer* (void)>(0x154fa90);
	static inline auto GetMimicEntity = PreyFunction<IEntity* (ArkPlayer* _this)>(0x154fb80);
	static inline auto GetMimicEntityId = PreyFunction<uint(ArkPlayer* _this)>(0x154fbf0);
	static inline auto GetPsiPowerComponent = PreyFunction<ArkPsiPowerComponent* (ArkPlayer* _this)>(0x154fc50);
	static inline auto GetReticleViewPositionAndDir = PreyFunction<std::pair<Vec3_tpl<float>, Vec3_tpl<float>>(ArkPlayer* _this)>(0x154fc80);
	static inline auto GetScaledInputRotation = PreyFunction<Ang3_tpl<float>* (ArkPlayer* _this, Ang3_tpl<float>* __return_storage_ptr__, float param_1)>(0x154fcc0);
	static inline auto GetSex = PreyFunction<EPlayerSex(ArkPlayer* _this)>(0x154fe20);
	static inline auto HasAbility = PreyFunction<bool(ArkPlayer* _this, uint64_t param_1)>(0x1550330);
	static inline auto Hide = PreyFunction<void(ArkPlayer* _this, bool param_1)>(0x1550370);
	static inline auto HideAttachment = PreyFunction<void(ArkPlayer* _this, const char* param_1, bool param_2)>(0x15503b0);
	static inline auto IncreaseHealth = PreyFunction<void(ArkPlayer* _this, float param_1)>(0x1550430);
	static inline auto InhibitRotation = PreyFunction<void(ArkPlayer* _this, bool param_1)>(0x1550460);
	static inline auto InitializePerception = PreyFunction<void(ArkPlayer* _this)>(0x1551380);
	static inline auto IsAlternateForm = PreyFunction<bool(ArkPlayer* _this)>(0x15513f0);
	static inline auto IsInGravShaft = PreyFunction<bool(ArkPlayer* _this)>(0x15514c0);
	static inline auto IsMimic = PreyFunction<bool(ArkPlayer* _this, unsigned int param_1)>(0x15514d0);
	static inline auto IsMimic2 = PreyFunction<bool(ArkPlayer* _this)>(0x1551530);
	static inline auto IsPsiTargeting = PreyFunction<bool(ArkPlayer* _this)>(0x1551560);
	static inline auto IsSafeForAutoSave = PreyFunction<EArkSaveFailure(ArkPlayer* _this)>(0x1551580);
	static inline auto IsShifting = PreyFunction<bool(ArkPlayer* _this)>(0x1551650);
	static inline auto Knockdown = PreyFunction<void(ArkPlayer* _this)>(0x1551850);
	static inline auto LimitAttentionOnUnseenPlayer = PreyFunction<void(ArkPlayer* _this)>(0x15518d0);
	static inline auto OnActivatePower = PreyFunction<void(ArkPlayer* _this)>(0x1551970);
	static inline auto OnCombatChange = PreyFunction<void(ArkPlayer* _this, bool param_1)>(0x1551b30);
	static inline auto OnJump = PreyFunction<void(ArkPlayer* _this)>(0x1551b50);
	static inline auto OnNewGame = PreyFunction<void(ArkPlayer* _this)>(0x1551be0);
	static inline auto OnSystemEvent = PreyFunction<void(ArkPlayer* _this, ESystemEvent param_1, uint64_t param_2, uint64_t param_3)>(0x1551c80);
	static inline auto Physicalize = PreyFunction<void(ArkPlayer* _this)>(0x1551eb0);
	static inline auto PhysicalizeAndResetAnimatedCharacter = PreyFunction<void(ArkPlayer* _this)>(0x1553030);
	static inline auto PlayFragment = PreyFunction<_smart_ptr<TAction<SAnimationContext>>(ArkPlayer* _this, const char* param_1, EArkPlayerAnimationPriority param_2, unsigned int param_3)>(0x1553080);
	static inline auto ProcessEvent = PreyFunction<void(ArkPlayer* _this, SEntityEvent* param_1)>(0x15537b0);
	static inline auto Ragdollize = PreyFunction<void(ArkPlayer* _this, float param_1)>(0x1555000);
	static inline auto ReleaseAttentionLimitOnPlayer = PreyFunction<void(ArkPlayer* _this)>(0x1555980);
	static inline auto Reset = PreyFunction<void(ArkPlayer* _this)>(0x15559f0);
	static inline auto ResetReticle = PreyFunction<void(ArkPlayer* _this)>(0x1556b00);
	static inline auto Revive = PreyFunction<void(ArkPlayer* _this)>(0x1556b80);
	static inline auto SetAnimationTag = PreyFunction<void(ArkPlayer* _this, const char* param_1, bool param_2)>(0x1557020);
	static inline auto SetAnimationTagFromFG = PreyFunction<void(ArkPlayer* _this, const char* param_1, bool param_2)>(0x1557160);
	static inline auto SetFaction = PreyFunction<void(ArkPlayer* _this)>(0x15573b0);
	static inline auto SetModel = PreyFunction<void(ArkPlayer* _this, const char* param_1)>(0x15575f0);
	static inline auto SetRoomEntityId = PreyFunction<void(ArkPlayer* _this, unsigned int param_1)>(0x15577e0);
	static inline auto SetShowArmor = PreyFunction<void(ArkPlayer* _this, bool _bShowArmor, bool _bForce)>(0x15577f0);
	static inline auto SetShowHealth = PreyFunction<void(ArkPlayer* _this, bool param_1, bool param_2)>(0x1557950);
	static inline auto SetStance = PreyFunction<void(ArkPlayer* _this, EStance param_1)>(0x1557aa0);
	static inline auto ShouldGenerateGameNoises = PreyFunction<bool(ArkPlayer* _this)>(0x1557df0);
	static inline auto ShowThirdPerson = PreyFunction<void(ArkPlayer* _this, bool param_1)>(0x1557e20);
	static inline auto TakeDamage = PreyFunction<void(ArkPlayer* _this, float param_1)>(0x1557fa0);
	static inline auto UpdateCachedReticleViewPosAndDir = PreyFunction<void(ArkPlayer* _this)>(0x15583f0);
	static inline auto UpdatePropulsionPackVisibility = PreyFunction<void(ArkPlayer* _this)>(0x1558cb0);
	static inline auto UpdateShadow = PreyFunction<void(ArkPlayer* _this, bool param_1)>(0x1558d30);

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

