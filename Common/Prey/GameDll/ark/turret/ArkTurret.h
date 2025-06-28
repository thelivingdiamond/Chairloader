// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkCharacterEffectsManager.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/ArkRobotLight.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkglooeffectutils.h>
#include <Prey/GameDll/ark/attention/ArkTurretAttentiveSubject.h>
#include <Prey/GameDll/ark/attention/arkgenericattentionobject.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>
#include <Prey/GameDll/ark/player/IArkEtherDuplicateListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry.h>
#include <Prey/GameDll/ark/turret/ArkTurretDialogSpeaker.h>
#include <Prey/GameDll/ark/turret/ArkTurretFsm.h>
#include <Prey/GameDll/ark/turret/ArkTurretSignalReceiver.h>
#include <Prey/GameDll/ark/turret/ArkTurretUtils.h>
#include <Prey/GameDll/ark/turret/ArkTurretWeapon.h>
#include <Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_fsm.h>
#include <Prey/GameDll/ark/turret/turretdamagefsm/arkturretdamagefsm_fsm.h>
#include <Prey/GameDll/ark/weapons/IArkGlooEffectObserver.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
struct EventPhysCollision;
struct HitInfo;
class IAction;
class IActionController;
class IAnimationDatabase;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct SAnimationContext;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: Exact
// Prey/GameDll/ark/turret/ArkTurret.h
class ArkTurret : public CGameObjectExtensionHelper<ArkTurret,IGameObjectExtension>, public IArkRepairableListener, public IArkPlayerInteractionListener, public IArkEtherDuplicateListener, public IArkGlooEffectObserver // Id=80152A5 Size=3720
{
public:
	using ArkTurretAttentionObject = ArkGenericAttentionObject<ArkTurret>;
	
	ArkTurretFsm m_fsm;
	ArkTurretAnimFsm::Fsm m_animFsm;
	ArkTurretDamageFsm::Fsm m_damageFsm;
	ArkTurretSignalReceiver m_signalReceiver;
	ArkTurretDialogSpeaker m_dialogSpeaker;
	ArkTurretWeapon m_turretWeapon;
	ArkGenericAttentionObject<ArkTurret> m_attentionObject;
	ArkTurretAttentiveSubject m_attentiveSubject;
	ArkRobotLight m_light;
	ArkCharacterEffectsManager m_characterEffectsManager;
	ArkRepairable m_repairable;
	ArkGlooEffectTimed m_glooEffects;
	ArkUnanimous m_aiEnabled;
	ArkUnanimous m_attentionObjectEnabled;
	ArkUnanimous m_animationEnabled;
	ArkUnanimous m_dialogEnabled;
	ArkTurretUtils::TurretAngle m_curAngle;
	ArkTurretUtils::TurretAngle m_goalAngle;
	ArkTurretUtils::TurretAngle m_maxAcceleration;
	ArkTurretUtils::TurretAngle m_maxVelocity;
	ArkTurretUtils::TurretAngle m_velocity;
	float m_yawLimit;
	float m_pitchLowerLimit;
	float m_pitchUpperLimit;
	float m_angularVelDamp;
	unsigned m_controllingTechnopathId;
	unsigned m_flowgraphTargetId;
	Vec3 m_flowgraphTargetPos;
	Vec3 m_deployedBoundingBoxSize;
	unsigned m_turretDefaultFactionIndex;
	unsigned m_turretPlayerControlledFactionIndex;
	unsigned m_turretHackedFactionIndex;
	ArkAudioTrigger m_audioTriggers[12];
	IActionController *m_pActionController;
	SAnimationContext *m_pAnimContex;
	IAnimationDatabase const *m_pAnimationDB;
	std::shared_ptr<IAnimationOperatorQueue> m_pAimRotationModifier;
	ArkSimpleTimer m_acquiredLineOfSightTimer;
	ArkSimpleTimer m_lostLineOfSightTimer;
	ArkSimpleTimer m_stunnedTimer;
	ArkSimpleTimer m_machineMindControlTimer;
	ArkSimpleTimer m_playerBumpTimer;
	ArkSimpleTimer m_holdUseTimer;
	uint64_t m_technoControlledSignalModifier;
	uint64_t m_callForHelpNoiseType;
	uint64_t m_callForHelpLoudness;
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Turret> m_spatialManagerEntry;
	const char *m_pLootInteractionText;
	const char *m_pDeployInteractionText;
	const char *m_pCantDeployInteractionText;
	float m_deadCarryHoldUseDuration;
	float m_fCloseThresholdAutoDisable;
	uint64_t m_fallDamagePackageId;
	float m_fallStartHeight;
	float m_fallMinSpeedForFalling;
	float m_fallDistanceForDamage;
	float m_fallDamagePerMeter;
	int16_t m_gimbalYawJointID;
	int16_t m_gimbalPitchJointID;
	int16_t m_barrelEndJointID;
	int16_t m_barrelStockJointID;
	bool m_bIsFlowControlling;
	bool m_bHasFlowgraphTarget;
	bool m_bFlowgraphRequestShooting;
	bool m_bUndeployedPickupMode;
	bool m_bIsManuallyAiming;
	bool m_bIsActive;
	bool m_bAttentionObjectEnabled;
	bool m_bAnimationEnabled;
	bool m_bAiEnabled;
	bool m_bHacked;
	bool m_bIsMachineMinded;
	bool m_bIsStunned;
	bool m_bIsMimickedByPlayer;
	bool m_bIsFalling;
	bool m_bIsInZeroG;
	
	ArkTurret();
	virtual ~ArkTurret();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject *pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual void PostReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &ctx, int updateSlot);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &event);
	virtual void ProcessEvent(SEntityEvent &event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool OnHoldToUseStopped(IEntity *const _pEntity);
	virtual void OnGlooHardenStart();
	virtual void OnGlooBroken();
	void ClearAttention() { FClearAttention(this); }
	void StartFiring() { FStartFiring(this); }
	void StopFiring() { FStopFiring(this); }
	bool IsFiring() const { return FIsFiring(this); }
	void PushDisableAi() { FPushDisableAi(this); }
	void PopDisableAi() { FPopDisableAi(this); }
	void PushDisableAttentionObject() { FPushDisableAttentionObject(this); }
	void PopDisableAttentionObject() { FPopDisableAttentionObject(this); }
	bool IsDeployed() const { return FIsDeployed(this); }
	bool CanDeploy() const { return FCanDeploy(this); }
	void StartStunned(const float _duration, const bool _bPostSerialize) { FStartStunned(this,_duration,_bPostSerialize); }
	void StopStunned() { FStopStunned(this); }
	bool IsStunned() const { return FIsStunned(this); }
	void StartMachineMindPower(const float _duration) { FStartMachineMindPower(this,_duration); }
	bool IsMachineMinded() const { return FIsMachineMinded(this); }
	void SetIsMimicByPlayer() { FSetIsMimicByPlayer(this); }
	bool IsMimickedByPlayer() const { return FIsMimickedByPlayer(this); }
	void StartBeingCarried() { FStartBeingCarried(this); }
	void StopBeingCarried() { FStopBeingCarried(this); }
	void StartPickupMode() { FStartPickupMode(this); }
	void StopPickupMode() { FStopPickupMode(this); }
	bool IsInPickupMode() const { return FIsInPickupMode(this); }
	void StartGlooEffects() { FStartGlooEffects(this); }
	void StopGlooEffects() { FStopGlooEffects(this); }
	bool IsBroken() const { return FIsBroken(this); }
	bool IsUpright() const { return FIsUpright(this); }
	void OnHit(HitInfo const &_hitInfo) { FOnHit(this,_hitInfo); }
	void SetHealth(float _health) { FSetHealth(this,_health); }
	void SetToMaxHealth() { FSetToMaxHealth(this); }
	float GetHealth() const { return FGetHealth(this); }
	IAction *StartFragmentByName(const char *_pName) { return FStartFragmentByName(this,_pName); }
	void PlayRecoil(float _recoilLength) { FPlayRecoil(this,_recoilLength); }
	void PlaySFX(EArkTurretSFX _sfx) const { FPlaySFX(this,_sfx); }
	void SetGoalLookAtPos(Vec3 const &_lookPosition) { FSetGoalLookAtPos(this,_lookPosition); }
	void SetGoalOrientation(const float _yaw, const float _pitch) { FSetGoalOrientation(this,_yaw,_pitch); }
	void SetGoalOrientationToCurrent() { FSetGoalOrientationToCurrent(this); }
	bool ArrivedAtGoalOrientation(const float _withinRadians) const { return FArrivedAtGoalOrientation(this,_withinRadians); }
	ArkTurretUtils::TurretAngle CalculateOrientationFromLookAtPos(Vec3 const &_lookPosition) const { return FCalculateOrientationFromLookAtPos(this,_lookPosition); }
	void ResetCurretOrientation() { FResetCurretOrientation(this); }
	void SetControllingTechnopathId(const unsigned _controllingTechnopath, const bool _bPostSerialize) { FSetControllingTechnopathId(this,_controllingTechnopath,_bPostSerialize); }
	bool GetIsControlledByTechnopath() const { return FGetIsControlledByTechnopath(this); }
	unsigned GetControllingTechnopathId() const { return FGetControllingTechnopathId(this); }
	Vec3 GetGimbalPosition() const { return FGetGimbalPosition(this); }
	Vec3 GetMuzzlePosition() const { return FGetMuzzlePosition(this); }
	Quat GetMuzzleRotation() const { return FGetMuzzleRotation(this); }
	QuatT GetViewTM(const float _viewConeHorizontalSemiangle, const float _viewConeUpSemiangle, const float _viewConeDownSemiangle) const { return FGetViewTM(this,_viewConeHorizontalSemiangle,_viewConeUpSemiangle,_viewConeDownSemiangle); }
	void OnTargetChanged() { FOnTargetChanged(this); }
	Vec3 GetPosToLeadTarget(const unsigned _targetID, float _percentageHit) const { return FGetPosToLeadTarget(this,_targetID,_percentageHit); }
	float GetDistanceToCurrentTarget() const { return FGetDistanceToCurrentTarget(this); }
	void OnHackSucceeded() { FOnHackSucceeded(this); }
	bool IsHacked() const { return FIsHacked(this); }
	void CallForHelp(const unsigned _targetEntityId) { FCallForHelp(this,_targetEntityId); }
	bool IsHostileTowards(unsigned _entityId) const { return FIsHostileTowards(this,_entityId); }
	void SpawnedByFabricator() { FSpawnedByFabricator(this); }
	bool HasFiringLineOfSight() { return FHasFiringLineOfSight(this); }
	static void OnNeuromodUsed() { FOnNeuromodUsed(); }
	static void OnLevelTransitionFinished() { FOnLevelTransitionFinished(); }
	void EnableFlowgraphControl() { FEnableFlowgraphControl(this); }
	void DisableFlowgraphControl() { FDisableFlowgraphControl(this); }
	void SetFlowgraphTarget(Vec3 const &_lookPosition) { FSetFlowgraphTargetOv1(this,_lookPosition); }
	void SetFlowgraphTarget(const unsigned _targetEntity) { FSetFlowgraphTargetOv0(this,_targetEntity); }
	void ClearFlowgraphTarget() { FClearFlowgraphTarget(this); }
	bool LoadCharacter(const char *const _pModelTableEntryName) { return FLoadCharacter(this,_pModelTableEntryName); }
	void InitMannequin() { FInitMannequin(this); }
	void ResetAll(bool _bPreSerialize) { FResetAll(this,_bPreSerialize); }
	void ResetGeneralProperties() { FResetGeneralProperties(this); }
	void Physicallize() { FPhysicallize(this); }
	void ResetSFX() { FResetSFX(this); }
	void RemoveAIObject() { FRemoveAIObject(this); }
	void OnHealthChanged(bool _bFromDamage) { FOnHealthChanged(this,_bFromDamage); }
	void DisableAttentionObject() { FDisableAttentionObject(this); }
	void DisableAttentiveSubject() { FDisableAttentiveSubject(this); }
	void OnAiEnabled() { FOnAiEnabled(this); }
	void OnAiDisabled() { FOnAiDisabled(this); }
	void UpdateAnimation(const float _frameTime) { FUpdateAnimation(this,_frameTime); }
	void UpdateGimbalAngle() { FUpdateGimbalAngle(this); }
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	virtual void OnFortified();
	virtual void OnEtherDuplicateCreated(const unsigned _etherDuplicate);
	
#if 0
	void ClearAttentionTo(unsigned arg0);
	void MaximizeAttentionTo(unsigned arg0, EArkAttentionChangeReason arg1);
	void SetAttentionTo(unsigned arg0, EArkAttentionChangeReason arg1, EArkAttentionLevel arg2);
	EArkAttentionLevel GetAttentionLevelTo(unsigned arg0);
	void OnAttentionLevelChanged(const unsigned arg0, EArkAttentionLevel arg1, EArkAttentionLevel arg2, EArkAttentionChangeReason arg3, const bool arg4);
	void Activate(const bool arg0);
	bool IsActive() const;
	void PushEnableAi();
	void PopEnableAi();
	void PushEnableAttentionObject();
	void PopEnableAttentionObject();
	void PushEnableAnimation();
	void PopEnableAnimation();
	void PushDisableAnimation();
	void PopDisableAnimation();
	void PushEnableDialog();
	void PopEnableDialog();
	void PushDisableDialog();
	void PopDisableDialog();
	bool LoadAliveModel();
	void UpdateStunned(float arg0);
	void UpdateMachineMindPower(const float arg0);
	void StopMachineMindPower();
	bool IsBeingCarried() const;
	void UpdateGlooEffects(const float arg0);
	void HealDamage(const float arg0);
	Ang3 GetGoalOrientation() const;
	ArkTurretUtils::TurretAngle const &GetCurrentOrientation() const;
	float GetYawLimit() const;
	float GetPitchLowerLimit() const;
	float GetPitchUpperLimit() const;
	bool CanReachLookAtPos(Vec3 const &arg0);
	bool CanReachOrientation(float arg0, float arg1);
	void SetIsManualAiming(bool arg0);
	bool IsManuallyAiming() const;
	Vec3 GetGimbalDirection() const;
	unsigned GetCurrentTargetId() const;
	ArkTurretFsm &GetFsm();
	ArkTurretAnimFsm::Fsm &GetAnimFsm();
	ArkTurretWeapon &GetTurretWeapon();
	ArkTurretDialogSpeaker &GetSpeaker();
	IActionController &GetActionController();
	ArkRobotLight &GetLight();
	ArkCharacterEffectsManager &GetCharacterEffectsManager();
	ArkRepairable &GetRepairable();
	ArkRepairable const &GetRepairable() const;
	void OnHackFailed();
	void OnFragmentComplete(IAction *arg0);
	bool IsFortified() const;
	bool IsInZeroG() const;
	void EnableGlassBreaking();
	void DisableGlassBreaking();
	bool IsControlledByFlowgraph() const;
	bool HasFlowgraphTarget() const;
	bool FlowgraphShootingRequested() const;
	unsigned GetFlowgraphTargetId() const;
	Vec3 const &GetFlowgraphTargetPos() const;
	void SetAnimTag(const char *const arg0, bool arg1);
	void CreateAIObject();
	void EventOnCollision(EventPhysCollision const *const arg0);
	IAction *StartFragment(const int &arg0);
	void HandleScriptEvent(const char *arg0);
	void EnableAttentionObject();
	void EnableAttentiveSubject();
	void OnDialogEnabled();
	void OnDialogDisabled();
	void UpdateAi(const float arg0);
	void OnAnimationEnabled();
	void OnAnimationDisabled();
	void UpdateCurrentAngle(const float arg0);
	void UpdateFalling();
	void TryFinishFall();
	float GetFallingSpeed() const;
	void UpdateHoldToDeploy(const float arg0);
	void OnHoldToDeployComplete();
	void StopAllAudioTriggers();
#endif
	
	static inline auto FBitNotArkTurret = PreyFunction<void(ArkTurret *const _this)>(0x15E09D0);
	static inline auto FInit = PreyFunction<bool(ArkTurret *const _this, IGameObject *_pGameObject)>(0x15E2890);
	static inline auto FInitClient = PreyFunction<void(ArkTurret *const _this, int channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(ArkTurret *const _this, IGameObject *pGameObject)>(0x15E4110);
	static inline auto FPostInitClient = PreyFunction<void(ArkTurret *const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkTurret *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkTurret *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkTurret *const _this, TSerialize signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(ArkTurret *const _this)>(0x15E4980);
	static inline auto FFullSerialize = PreyFunction<void(ArkTurret *const _this, TSerialize _ser)>(0x15E1780);
	static inline auto FNetSerialize = PreyFunction<bool(ArkTurret *const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkTurret *const _this)>(0x15E4200);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkTurret *const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkTurret *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkTurret *const _this, SEntityUpdateContext &ctx, int updateSlot)>(0x15E75F0);
	static inline auto FPostUpdate = PreyFunction<void(ArkTurret *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkTurret *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkTurret *const _this, SGameObjectEvent const &event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkTurret *const _this, SEntityEvent &event)>(0x15E43A0);
	static inline auto FSetChannelId = PreyFunction<void(ArkTurret *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkTurret *const _this, bool auth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkTurret const *const _this, ICrySizer *s)>(0x15E1E10);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkTurret const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x15E3D90);
	static inline auto FOnInteraction = PreyFunction<bool(ArkTurret *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x15E3650);
	static inline auto FTestInteraction = PreyFunction<bool(ArkTurret const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x15E75C0);
	static inline auto FOnHoldToUseStopped = PreyFunction<bool(ArkTurret *const _this, IEntity *const _pEntity)>(0x15E3630);
	static inline auto FOnGlooHardenStart = PreyFunction<void(ArkTurret *const _this)>(0x15E3370);
	static inline auto FOnGlooBroken = PreyFunction<void(ArkTurret *const _this)>(0x15E32E0);
	static inline auto FClearAttention = PreyFunction<void(ArkTurret *const _this)>(0x15E1630);
	static inline auto FStartFiring = PreyFunction<void(ArkTurret *const _this)>(0x15E70C0);
	static inline auto FStopFiring = PreyFunction<void(ArkTurret *const _this)>(0x15E7430);
	static inline auto FIsFiring = PreyFunction<bool(ArkTurret const *const _this)>(0x15E2C90);
	static inline auto FPushDisableAi = PreyFunction<void(ArkTurret *const _this)>(0x15E48E0);
	static inline auto FPopDisableAi = PreyFunction<void(ArkTurret *const _this)>(0x15E3CF0);
	static inline auto FPushDisableAttentionObject = PreyFunction<void(ArkTurret *const _this)>(0x15E4920);
	static inline auto FPopDisableAttentionObject = PreyFunction<void(ArkTurret *const _this)>(0x15E3D30);
	static inline auto FIsDeployed = PreyFunction<bool(ArkTurret const *const _this)>(0x15E2C80);
	static inline auto FCanDeploy = PreyFunction<bool(ArkTurret const *const _this)>(0x15E13A0);
	static inline auto FStartStunned = PreyFunction<void(ArkTurret *const _this, const float _duration, const bool _bPostSerialize)>(0x15E72D0);
	static inline auto FStopStunned = PreyFunction<void(ArkTurret *const _this)>(0x15E74F0);
	static inline auto FIsStunned = PreyFunction<bool(ArkTurret const *const _this)>(0x15E2D10);
	static inline auto FStartMachineMindPower = PreyFunction<void(ArkTurret *const _this, const float _duration)>(0x15E71D0);
	static inline auto FIsMachineMinded = PreyFunction<bool(ArkTurret const *const _this)>(0x15E2CF0);
	static inline auto FSetIsMimicByPlayer = PreyFunction<void(ArkTurret *const _this)>(0x15E6F60);
	static inline auto FIsMimickedByPlayer = PreyFunction<bool(ArkTurret const *const _this)>(0x15E2D00);
	static inline auto FStartBeingCarried = PreyFunction<void(ArkTurret *const _this)>(0x15E70B0);
	static inline auto FStopBeingCarried = PreyFunction<void(ArkTurret *const _this)>(0x15E7400);
	static inline auto FStartPickupMode = PreyFunction<void(ArkTurret *const _this)>(0x15E7250);
	static inline auto FStopPickupMode = PreyFunction<void(ArkTurret *const _this)>(0x15E7460);
	static inline auto FIsInPickupMode = PreyFunction<bool(ArkTurret const *const _this)>(0x15E2CE0);
	static inline auto FStartGlooEffects = PreyFunction<void(ArkTurret *const _this)>(0x15E71C0);
	static inline auto FStopGlooEffects = PreyFunction<void(ArkTurret *const _this)>(0x15E7440);
	static inline auto FIsBroken = PreyFunction<bool(ArkTurret const *const _this)>(0x15E2C70);
	static inline auto FIsUpright = PreyFunction<bool(ArkTurret const *const _this)>(0x15E2D20);
	static inline auto FOnHit = PreyFunction<void(ArkTurret *const _this, HitInfo const &_hitInfo)>(0x15E34F0);
	static inline auto FSetHealth = PreyFunction<void(ArkTurret *const _this, float _health)>(0x15E6F10);
	static inline auto FSetToMaxHealth = PreyFunction<void(ArkTurret *const _this)>(0x15E6FE0);
	static inline auto FGetHealth = PreyFunction<float(ArkTurret const *const _this)>(0x150D1F0);
	static inline auto FStartFragmentByName = PreyFunction<IAction *(ArkTurret *const _this, const char *_pName)>(0x15E70F0);
	static inline auto FPlayRecoil = PreyFunction<void(ArkTurret *const _this, float _recoilLength)>(0x15E3BF0);
	static inline auto FPlaySFX = PreyFunction<void(ArkTurret const *const _this, EArkTurretSFX _sfx)>(0x15E3CD0);
	static inline auto FSetGoalLookAtPos = PreyFunction<void(ArkTurret *const _this, Vec3 const &_lookPosition)>(0x15E6E90);
	static inline auto FSetGoalOrientation = PreyFunction<void(ArkTurret *const _this, const float _yaw, const float _pitch)>(0x15E6EC0);
	static inline auto FSetGoalOrientationToCurrent = PreyFunction<void(ArkTurret *const _this)>(0x15E6EE0);
	static inline auto FArrivedAtGoalOrientation = PreyFunction<bool(ArkTurret const *const _this, const float _withinRadians)>(0x15E0E40);
	static inline auto FCalculateOrientationFromLookAtPos = PreyFunction<ArkTurretUtils::TurretAngle(ArkTurret const *const _this, Vec3 const &_lookPosition)>(0x15E0E80);
	static inline auto FResetCurretOrientation = PreyFunction<void(ArkTurret *const _this)>(0x15E5200);
	static inline auto FSetControllingTechnopathId = PreyFunction<void(ArkTurret *const _this, const unsigned _controllingTechnopath, const bool _bPostSerialize)>(0x15E6C10);
	static inline auto FGetIsControlledByTechnopath = PreyFunction<bool(ArkTurret const *const _this)>(0x15E1E00);
	static inline auto FGetControllingTechnopathId = PreyFunction<unsigned(ArkTurret const *const _this)>(0x15E1D00);
	static inline auto FGetGimbalPosition = PreyFunction<Vec3(ArkTurret const *const _this)>(0x15E1DC0);
	static inline auto FGetMuzzlePosition = PreyFunction<Vec3(ArkTurret const *const _this)>(0x15E1E30);
	static inline auto FGetMuzzleRotation = PreyFunction<Quat(ArkTurret const *const _this)>(0x15E1E70);
	static inline auto FGetViewTM = PreyFunction<QuatT(ArkTurret const *const _this, const float _viewConeHorizontalSemiangle, const float _viewConeUpSemiangle, const float _viewConeDownSemiangle)>(0x15E2040);
	static inline auto FOnTargetChanged = PreyFunction<void(ArkTurret *const _this)>(0x15E3A00);
	static inline auto FGetPosToLeadTarget = PreyFunction<Vec3(ArkTurret const *const _this, const unsigned _targetID, float _percentageHit)>(0x15E1EC0);
	static inline auto FGetDistanceToCurrentTarget = PreyFunction<float(ArkTurret const *const _this)>(0x15E1D10);
	static inline auto FOnHackSucceeded = PreyFunction<void(ArkTurret *const _this)>(0x15E3400);
	static inline auto FIsHacked = PreyFunction<bool(ArkTurret const *const _this)>(0x15E2CA0);
	static inline auto FCallForHelp = PreyFunction<void(ArkTurret *const _this, const unsigned _targetEntityId)>(0x15E12E0);
	static inline auto FIsHostileTowards = PreyFunction<bool(ArkTurret const *const _this, unsigned _entityId)>(0x15E2CB0);
	static inline auto FSpawnedByFabricator = PreyFunction<void(ArkTurret *const _this)>(0x15E7040);
	static inline auto FHasFiringLineOfSight = PreyFunction<bool(ArkTurret *const _this)>(0x15E2600);
	static inline auto FOnNeuromodUsed = PreyFunction<void()>(0x15E3860);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void()>(0x15E36A0);
	static inline auto FEnableFlowgraphControl = PreyFunction<void(ArkTurret *const _this)>(0x15E1770);
	static inline auto FDisableFlowgraphControl = PreyFunction<void(ArkTurret *const _this)>(0x15E1730);
	static inline auto FSetFlowgraphTargetOv1 = PreyFunction<void(ArkTurret *const _this, Vec3 const &_lookPosition)>(0x15E6E50);
	static inline auto FSetFlowgraphTargetOv0 = PreyFunction<void(ArkTurret *const _this, const unsigned _targetEntity)>(0x15E6E80);
	static inline auto FClearFlowgraphTarget = PreyFunction<void(ArkTurret *const _this)>(0x15E1670);
	static inline auto FLoadCharacter = PreyFunction<bool(ArkTurret *const _this, const char *const _pModelTableEntryName)>(0x15E2D90);
	static inline auto FInitMannequin = PreyFunction<void(ArkTurret *const _this)>(0x15E2900);
	static inline auto FResetAll = PreyFunction<void(ArkTurret *const _this, bool _bPreSerialize)>(0x15E4B60);
	static inline auto FResetGeneralProperties = PreyFunction<void(ArkTurret *const _this)>(0x15E55D0);
	static inline auto FPhysicallize = PreyFunction<void(ArkTurret *const _this)>(0x15E3A50);
	static inline auto FResetSFX = PreyFunction<void(ArkTurret *const _this)>(0x15E6710);
	static inline auto FRemoveAIObject = PreyFunction<void(ArkTurret *const _this)>(0x15E4A90);
	static inline auto FOnHealthChanged = PreyFunction<void(ArkTurret *const _this, bool _bFromDamage)>(0x15E3460);
	static inline auto FDisableAttentionObject = PreyFunction<void(ArkTurret *const _this)>(0x15E1690);
	static inline auto FDisableAttentiveSubject = PreyFunction<void(ArkTurret *const _this)>(0x15E16D0);
	static inline auto FOnAiEnabled = PreyFunction<void(ArkTurret *const _this)>(0x15E3060);
	static inline auto FOnAiDisabled = PreyFunction<void(ArkTurret *const _this)>(0x15E3000);
	static inline auto FUpdateAnimation = PreyFunction<void(ArkTurret *const _this, const float _frameTime)>(0x15E79D0);
	static inline auto FUpdateGimbalAngle = PreyFunction<void(ArkTurret *const _this)>(0x15E7C20);
	static inline auto FOnBrokenChanged = PreyFunction<void(ArkTurret *const _this, bool _bBroken, bool _bWasForced)>(0x15E30E0);
	static inline auto FOnFortified = PreyFunction<void(ArkTurret *const _this)>(0x15E3170);
	static inline auto FOnEtherDuplicateCreated = PreyFunction<void(ArkTurret *const _this, const unsigned _etherDuplicate)>(0x15E3100);
};
