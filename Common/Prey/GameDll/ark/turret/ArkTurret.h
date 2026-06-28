// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/ArkCommon/ArkUnanimous.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkCharacterEffectsManager.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/ArkRobotLight.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkglooeffectutils.h>
#include <Prey/GameDll/ark/attention/ArkTurretAttentiveSubject.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>
#include <Prey/GameDll/ark/player/IArkEtherDuplicateListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/turret/ArkTurretCharacter.h>
#include <Prey/GameDll/ark/turret/ArkTurretDialogSpeaker.h>
#include <Prey/GameDll/ark/turret/ArkTurretFsm.h>
#include <Prey/GameDll/ark/turret/ArkTurretProperties.h>
#include <Prey/GameDll/ark/turret/ArkTurretSignalReceiver.h>
#include <Prey/GameDll/ark/turret/turretdamagefsm/arkturretdamagefsm_fsm.h>
#include <Prey/GameDll/ark/weapons/IArkGlooEffectObserver.h>
#include <_unknown/ArkGenericAttentionObject.h>
#include <_unknown/ArkSpatialManagerEntry.h>

struct ArkInteractionTestResult;
class ArkSafeScriptTable;
class ArkTurretWeapon;
enum class EArkAttentionChangeReason;
enum class EArkAttentionLevel;
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum class EArkTurretSfx;
enum EEntityAspects;
struct EventPhysCollision;
struct HitInfo;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// ArkTurret
// Header:  Prey/GameDll/ark/turret/ArkTurret.h
class ArkTurret
	: public CGameObjectExtensionHelper<ArkTurret, IGameObjectExtension>
	, public IArkRepairableListener
	, public IArkPlayerInteractionListener
	, public IArkEtherDuplicateListener
	, public IArkGlooEffectObserver
{ // Size=3936 (0xF60)
public:
	using ArkTurretAttentionObject = ArkGenericAttentionObject<ArkTurret>;

	ArkTurretProperties m_properties;
	ArkTurretCharacter m_character;
	ArkTurretFsm m_fsm;
	ArkTurretDamageFsm::Fsm m_damageFsm;
	ArkTurretSignalReceiver m_signalReceiver;
	ArkTurretDialogSpeaker m_dialogSpeaker;
	ArkGenericAttentionObject<ArkTurret> m_attentionObject;
	ArkTurretAttentiveSubject m_attentiveSubject;
	ArkRepairable m_repairable;
	ArkRobotLight m_light;
	ArkCharacterEffectsManager m_characterEffectsManager;
	ArkGlooEffectTimed m_glooEffects;
	ArkUnanimous m_aiEnabled;
	ArkUnanimous m_attentionObjectEnabled;
	ArkUnanimous m_dialogEnabled;
	unsigned m_controllingTechnopathId;
	ArkSimpleTimer m_acquiredLineOfSightTimer;
	ArkSimpleTimer m_lostLineOfSightTimer;
	ArkSimpleTimer m_stunnedTimer;
	ArkSimpleTimer m_machineMindControlTimer;
	ArkSimpleTimer m_playerBumpTimer;
	ArkSimpleTimer m_holdUseTimer;
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Turret> m_spatialManagerEntry;
	float m_fallStartHeight;
	bool m_bUndeployedPickupMode;
	bool m_bAttentionObjectEnabled;
	bool m_bAiEnabled;
	bool m_bHacked;
	bool m_bIsMachineMinded;
	bool m_bIsStunned;
	bool m_bIsMimickedByPlayer;
	bool m_bIsFalling;
	bool m_bIsInZeroG;
	bool m_bRemoveNextFrameSet;

	ArkTurret();
	virtual ~ArkTurret();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& event);
	virtual void ProcessEvent(SEntityEvent& event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	void ClearAttention() { FClearAttention(this); }
	ArkTurretCharacter& GetCharacter() { return FGetCharacter(this); }
	const ArkTurretProperties& GetProperties() const { return FGetProperties(this); }
	ArkTurretFsm& GetFsm() { return FGetFsm(this); }
	ArkTurretDialogSpeaker& GetSpeaker() { return FGetSpeaker(this); }
	ArkRobotLight& GetLight() { return FGetLight(this); }
	ArkCharacterEffectsManager& GetCharacterEffectsManager() { return FGetCharacterEffectsManager(this); }
	ArkRepairable& GetRepairable() { return FGetRepairableOv1(this); }
	const ArkRepairable& GetRepairable() const { return FGetRepairableOv0(this); }
	ArkTurretAttentiveSubject& GetAttentiveSubject() { return FGetAttentiveSubject(this); }
	void StartFiring() { FStartFiring(this); }
	void StopFiring() { FStopFiring(this); }
	bool IsFiring() const { return FIsFiring(this); }
	void PlayUndeploy() { FPlayUndeploy(this); }
	void PlayDeploy() { FPlayDeploy(this); }
	void PlayBroken() { FPlayBroken(this); }
	void PlayRecoil(float _recoilLength) { FPlayRecoil(this, _recoilLength); }
	void PlayRecoilLooping() { FPlayRecoilLooping(this); }
	void StopRecoilLooping() { FStopRecoilLooping(this); }
	bool IsUndeployed() const { return FIsUndeployed(this); }
	bool IsDeployed() const { return FIsDeployed(this); }
	void OnModelChanged() { FOnModelChanged(this); }
	void OnDeployed() { FOnDeployed(this); }
	void OnUndeployed() { FOnUndeployed(this); }
	void OnWeaponWindup() { FOnWeaponWindup(this); }
	void OnWeaponCooldown() { FOnWeaponCooldown(this); }
	void PushDisableAi() { FPushDisableAi(this); }
	void PopDisableAi() { FPopDisableAi(this); }
	void PushDisableAttentionObject() { FPushDisableAttentionObject(this); }
	void PopDisableAttentionObject() { FPopDisableAttentionObject(this); }
	bool CanDeploy() const { return FCanDeploy(this); }
	bool CanShoot() const { return FCanShoot(this); }
	void DisableAiming() { FDisableAiming(this); }
	void StartStunned(const float _duration, const bool _bPostSerialize) { FStartStunned(this, _duration, _bPostSerialize); }
	void StopStunned() { FStopStunned(this); }
	bool IsStunned() const { return FIsStunned(this); }
	void StartMachineMindPower(const float _duration) { FStartMachineMindPower(this, _duration); }
	bool IsMachineMinded() const { return FIsMachineMinded(this); }
	void SetIsMimicByPlayer() { FSetIsMimicByPlayer(this); }
	bool IsMimickedByPlayer() const { return FIsMimickedByPlayer(this); }
	void StartBeingCarried() { FStartBeingCarried(this); }
	void StopBeingCarried() { FStopBeingCarried(this); }
	void StartUndeployed() { FStartUndeployed(this); }
	void StartPickupMode() { FStartPickupMode(this); }
	void StopPickupMode() { FStopPickupMode(this); }
	bool IsInPickupMode() const { return FIsInPickupMode(this); }
	void StartGlooEffects() { FStartGlooEffects(this); }
	void StopGlooEffects() { FStopGlooEffects(this); }
	void SetRemoveNextFrame() { FSetRemoveNextFrame(this); }
	void MakeBroken() { FMakeBroken(this); }
	bool IsBroken() const { return FIsBroken(this); }
	bool IsUpright() const { return FIsUpright(this); }
	void OnHit(const HitInfo& _hitInfo) { FOnHit(this, _hitInfo); }
	void SetToMaxHealth() { FSetToMaxHealth(this); }
	float GetHealth() const { return FGetHealth(this); }
	void PlaySFX(EArkTurretSfx _sfx) const { FPlaySFX(this, _sfx); }
	void SetControllingTechnopathId(const unsigned _controllingTechnopath, const bool _bPostSerialize) { FSetControllingTechnopathId(this, _controllingTechnopath, _bPostSerialize); }
	bool GetIsControlledByTechnopath() const { return FGetIsControlledByTechnopath(this); }
	unsigned GetControllingTechnopathId() const { return FGetControllingTechnopathId(this); }
	Vec3 GetGimbalPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetGimbalPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetMuzzlePosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetMuzzlePosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Quat GetMuzzleRotation() const { alignas(Quat) std::byte _return_buf_[sizeof(Quat)]; return *FGetMuzzleRotation(this, reinterpret_cast<Quat*>(_return_buf_)); }
	unsigned GetTargetId() const { return FGetTargetId(this); }
	void OnTargetChanged() { FOnTargetChanged(this); }
	Vec3 GetPosToLeadTarget(const unsigned _targetID, float _percentageHit) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosToLeadTarget(this, reinterpret_cast<Vec3*>(_return_buf_), _targetID, _percentageHit); }
	float GetDistanceToCurrentTarget() const { return FGetDistanceToCurrentTarget(this); }
	void OnHackSucceeded() { FOnHackSucceeded(this); }
	bool IsHacked() const { return FIsHacked(this); }
	void CallForHelp(const unsigned _targetEntityId) { FCallForHelp(this, _targetEntityId); }
	bool IsHostileTowards(unsigned _entityId) const { return FIsHostileTowards(this, _entityId); }
	void SpawnedByFabricator() { FSpawnedByFabricator(this); }
	bool HasFiringLineOfSight() { return FHasFiringLineOfSight(this); }
	ArkSafeScriptTable GetWeaponScriptTable() const { alignas(ArkSafeScriptTable) std::byte _return_buf_[sizeof(ArkSafeScriptTable)]; return *FGetWeaponScriptTable(this, reinterpret_cast<ArkSafeScriptTable*>(_return_buf_)); }
	static void ReevaluatePlayerDisposition() { FReevaluatePlayerDisposition(); }
	static void OnLevelTransitionFinished() { FOnLevelTransitionFinished(); }
	void InitializeTurret() { FInitializeTurret(this); }
	void ProcessDoneEvent() { FProcessDoneEvent(this); }
	void RemoveAIObject() { FRemoveAIObject(this); }
	void OnHealthChanged(bool _bFromDamage) { FOnHealthChanged(this, _bFromDamage); }
	void OnAiEnabled() { FOnAiEnabled(this); }
	void OnAiDisabled() { FOnAiDisabled(this); }
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual bool OnHoldToUseStopped(IEntity* const _pEntity);
	virtual void OnGlooHardenStart();
	virtual void OnGlooBroken();
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	virtual void OnFortified();
	virtual void OnEtherDuplicateCreated(const unsigned _etherDuplicate);

#if 0
	void ClearAttentionTo(unsigned _arg0_);
	void MaximizeAttentionTo(unsigned _arg0_, EArkAttentionChangeReason _arg1_);
	void SetAttentionTo(unsigned _arg0_, EArkAttentionChangeReason _arg1_, EArkAttentionLevel _arg2_);
	EArkAttentionLevel GetAttentionLevelTo(unsigned _arg0_);
	void OnAttentionLevelChanged(const unsigned _arg0_, const EArkAttentionLevel _arg1_, const EArkAttentionLevel _arg2_, const EArkAttentionChangeReason _arg3_, const bool _arg4_);
	void PlaySearching();
	bool IsSearching() const;
	void PushEnableAi();
	void PopEnableAi();
	void PushEnableAttentionObject();
	void PopEnableAttentionObject();
	void PushEnableAnimation();
	void PopEnableAnimation();
	void PushDisableAnimation();
	void PopDisableAnimation();
	bool IsAnimationEnabled() const;
	void PushEnableDialog();
	void PopEnableDialog();
	void PushDisableDialog();
	void PopDisableDialog();
	void EnableAiming();
	bool IsAiming() const;
	void UpdateStunned(float _arg0_);
	void UpdateMachineMindPower(const float _arg0_);
	void StopMachineMindPower();
	bool IsBeingCarried() const;
	void UpdateGlooEffects(const float _arg0_);
	bool IsGlooFrozen() const;
	void SetHealth(float _arg0_);
	Vec3 GetAttackTargetPos(const unsigned _arg0_) const;
	void OnHackFailed();
	bool IsFortified() const;
	bool IsInZeroG() const;
	void EnableGlassBreaking();
	void DisableGlassBreaking();
	ArkTurretWeapon* GetWeapon() const;
	void LoadProperties();
	void Physicallize();
	void CreateWeapon();
	void DestroyWeapon();
	void CreateAIObject();
	void EventOnCollision(const EventPhysCollision* const _arg0_);
	void HandleScriptEvent(const char* _arg0_);
	void EnableAttentionObject();
	void DisableAttentionObject();
	void EnableAttentiveSubject();
	void DisableAttentiveSubject();
	void OnDialogEnabled();
	void OnDialogDisabled();
	void UpdateAi(const float _arg0_);
	void UpdateFalling();
	void TryFinishFall();
	float GetFallingSpeed() const;
	void UpdateHoldToDeploy(const float _arg0_);
	void OnHoldToDeployComplete();
	void StopAllAudioTriggers();
#endif

	static inline auto FArkTurret = PreyFunction<void(ArkTurret* const _this)>(0x1706FB0);
	static inline auto FInit = PreyFunction<bool(ArkTurret* const _this, IGameObject* _pGameObject)>(0x1708340);
	static inline auto FInitClient = PreyFunction<void(ArkTurret* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(ArkTurret* const _this, IGameObject* pGameObject)>(0x1709650);
	static inline auto FPostInitClient = PreyFunction<void(ArkTurret* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(ArkTurret* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkTurret* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkTurret* const _this, TSerialize signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(ArkTurret* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(ArkTurret* const _this, TSerialize _ser)>(0x17078B0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkTurret* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkTurret* const _this)>(0x1709840);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkTurret* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(ArkTurret* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(ArkTurret* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x170AC30);
	static inline auto FPostUpdate = PreyFunction<void(ArkTurret* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkTurret* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(ArkTurret* const _this, const SGameObjectEvent& event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(ArkTurret* const _this, SEntityEvent& event)>(0x1709BF0);
	static inline auto FSetChannelId = PreyFunction<void(ArkTurret* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(ArkTurret* const _this, bool auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTurret* const _this, ICrySizer* s)>(0x1707E60);
	static inline auto FClearAttention = PreyFunction<void(ArkTurret* const _this)>(0x1707860);
	static inline auto FGetCharacter = PreyFunction<ArkTurretCharacter& (ArkTurret* const _this)>(0x1707D10);
	static inline auto FGetProperties = PreyFunction<const ArkTurretProperties& (const ArkTurret* const _this)>(0x10ECF20);
	static inline auto FGetFsm = PreyFunction<ArkTurretFsm& (ArkTurret* const _this)>(0x1707DF0);
	static inline auto FGetSpeaker = PreyFunction<ArkTurretDialogSpeaker& (ArkTurret* const _this)>(0x5D8C90);
	static inline auto FGetLight = PreyFunction<ArkRobotLight& (ArkTurret* const _this)>(0x1707E50);
	static inline auto FGetCharacterEffectsManager = PreyFunction<ArkCharacterEffectsManager& (ArkTurret* const _this)>(0x1707D20);
	static inline auto FGetRepairableOv1 = PreyFunction<ArkRepairable& (ArkTurret* const _this)>(0x1707FD0);
	static inline auto FGetRepairableOv0 = PreyFunction<const ArkRepairable& (const ArkTurret* const _this)>(0x1707FD0);
	static inline auto FGetAttentiveSubject = PreyFunction<ArkTurretAttentiveSubject& (ArkTurret* const _this)>(0x1707D00);
	static inline auto FStartFiring = PreyFunction<void(ArkTurret* const _this)>(0x170A760);
	static inline auto FStopFiring = PreyFunction<void(ArkTurret* const _this)>(0x170AA40);
	static inline auto FIsFiring = PreyFunction<bool(const ArkTurret* const _this)>(0x1708700);
	static inline auto FPlayUndeploy = PreyFunction<void(ArkTurret* const _this)>(0x1709220);
	static inline auto FPlayDeploy = PreyFunction<void(ArkTurret* const _this)>(0x17091D0);
	static inline auto FPlayBroken = PreyFunction<void(ArkTurret* const _this)>(0x17091C0);
	static inline auto FPlayRecoil = PreyFunction<void(ArkTurret* const _this, float _recoilLength)>(0x17091E0);
	static inline auto FPlayRecoilLooping = PreyFunction<void(ArkTurret* const _this)>(0x17091F0);
	static inline auto FStopRecoilLooping = PreyFunction<void(ArkTurret* const _this)>(0x170AB50);
	static inline auto FIsUndeployed = PreyFunction<bool(const ArkTurret* const _this)>(0x17087D0);
	static inline auto FIsDeployed = PreyFunction<bool(const ArkTurret* const _this)>(0x17086F0);
	static inline auto FOnModelChanged = PreyFunction<void(ArkTurret* const _this)>(0x1708F70);
	static inline auto FOnDeployed = PreyFunction<void(ArkTurret* const _this)>(0x17089D0);
	static inline auto FOnUndeployed = PreyFunction<void(ArkTurret* const _this)>(0x17090D0);
	static inline auto FOnWeaponWindup = PreyFunction<void(ArkTurret* const _this)>(0x1709150);
	static inline auto FOnWeaponCooldown = PreyFunction<void(ArkTurret* const _this)>(0x17090E0);
	static inline auto FPushDisableAi = PreyFunction<void(ArkTurret* const _this)>(0x1709ED0);
	static inline auto FPopDisableAi = PreyFunction<void(ArkTurret* const _this)>(0x1709230);
	static inline auto FPushDisableAttentionObject = PreyFunction<void(ArkTurret* const _this)>(0x1709F10);
	static inline auto FPopDisableAttentionObject = PreyFunction<void(ArkTurret* const _this)>(0x1709270);
	static inline auto FCanDeploy = PreyFunction<bool(const ArkTurret* const _this)>(0x1707530);
	static inline auto FCanShoot = PreyFunction<bool(const ArkTurret* const _this)>(0x17077C0);
	static inline auto FDisableAiming = PreyFunction<void(ArkTurret* const _this)>(0x17078A0);
	static inline auto FStartStunned = PreyFunction<void(ArkTurret* const _this, const float _duration, const bool _bPostSerialize)>(0x170A900);
	static inline auto FStopStunned = PreyFunction<void(ArkTurret* const _this)>(0x170AB60);
	static inline auto FIsStunned = PreyFunction<bool(const ArkTurret* const _this)>(0x17087C0);
	static inline auto FStartMachineMindPower = PreyFunction<void(ArkTurret* const _this, const float _duration)>(0x170A7D0);
	static inline auto FIsMachineMinded = PreyFunction<bool(const ArkTurret* const _this)>(0x17087A0);
	static inline auto FSetIsMimicByPlayer = PreyFunction<void(ArkTurret* const _this)>(0x170A620);
	static inline auto FIsMimickedByPlayer = PreyFunction<bool(const ArkTurret* const _this)>(0x17087B0);
	static inline auto FStartBeingCarried = PreyFunction<void(ArkTurret* const _this)>(0x170A750);
	static inline auto FStopBeingCarried = PreyFunction<void(ArkTurret* const _this)>(0x170AA10);
	static inline auto FStartUndeployed = PreyFunction<void(ArkTurret* const _this)>(0x170AA00);
	static inline auto FStartPickupMode = PreyFunction<void(ArkTurret* const _this)>(0x170A880);
	static inline auto FStopPickupMode = PreyFunction<void(ArkTurret* const _this)>(0x170AAC0);
	static inline auto FIsInPickupMode = PreyFunction<bool(const ArkTurret* const _this)>(0x1708790);
	static inline auto FStartGlooEffects = PreyFunction<void(ArkTurret* const _this)>(0x170A7C0);
	static inline auto FStopGlooEffects = PreyFunction<void(ArkTurret* const _this)>(0x170AAA0);
	static inline auto FSetRemoveNextFrame = PreyFunction<void(ArkTurret* const _this)>(0x170A6B0);
	static inline auto FMakeBroken = PreyFunction<void(ArkTurret* const _this)>(0x1708850);
	static inline auto FIsBroken = PreyFunction<bool(const ArkTurret* const _this)>(0x17086E0);
	static inline auto FIsUpright = PreyFunction<bool(const ArkTurret* const _this)>(0x17087E0);
	static inline auto FOnHit = PreyFunction<void(ArkTurret* const _this, const HitInfo& _hitInfo)>(0x1708E30);
	static inline auto FSetToMaxHealth = PreyFunction<void(ArkTurret* const _this)>(0x170A6C0);
	static inline auto FGetHealth = PreyFunction<float(const ArkTurret* const _this)>(0x162B130);
	static inline auto FPlaySFX = PreyFunction<void(const ArkTurret* const _this, EArkTurretSfx _sfx)>(0x1709200);
	static inline auto FSetControllingTechnopathId = PreyFunction<void(ArkTurret* const _this, const unsigned _controllingTechnopath, const bool _bPostSerialize)>(0x170A4D0);
	static inline auto FGetIsControlledByTechnopath = PreyFunction<bool(const ArkTurret* const _this)>(0x1707E40);
	static inline auto FGetControllingTechnopathId = PreyFunction<unsigned(const ArkTurret* const _this)>(0x1707D30);
	static inline auto FGetGimbalPosition = PreyFunction<Vec3*(const ArkTurret* const _this, Vec3* _return_value_)>(0x1707E00);
	static inline auto FGetMuzzlePosition = PreyFunction<Vec3*(const ArkTurret* const _this, Vec3* _return_value_)>(0x1707E80);
	static inline auto FGetMuzzleRotation = PreyFunction<Quat*(const ArkTurret* const _this, Quat* _return_value_)>(0x1707EC0);
	static inline auto FGetTargetId = PreyFunction<unsigned(const ArkTurret* const _this)>(0x1707FE0);
	static inline auto FOnTargetChanged = PreyFunction<void(ArkTurret* const _this)>(0x1709080);
	static inline auto FGetPosToLeadTarget = PreyFunction<Vec3*(const ArkTurret* const _this, Vec3* _return_value_, const unsigned _targetID, float _percentageHit)>(0x1707F00);
	static inline auto FGetDistanceToCurrentTarget = PreyFunction<float(const ArkTurret* const _this)>(0x1707D40);
	static inline auto FOnHackSucceeded = PreyFunction<void(ArkTurret* const _this)>(0x1708D00);
	static inline auto FIsHacked = PreyFunction<bool(const ArkTurret* const _this)>(0x1708750);
	static inline auto FCallForHelp = PreyFunction<void(ArkTurret* const _this, const unsigned _targetEntityId)>(0x1707470);
	static inline auto FIsHostileTowards = PreyFunction<bool(const ArkTurret* const _this, unsigned _entityId)>(0x1708760);
	static inline auto FSpawnedByFabricator = PreyFunction<void(ArkTurret* const _this)>(0x170A720);
	static inline auto FHasFiringLineOfSight = PreyFunction<bool(ArkTurret* const _this)>(0x1708040);
	static inline auto FGetWeaponScriptTable = PreyFunction<ArkSafeScriptTable*(const ArkTurret* const _this, ArkSafeScriptTable* _return_value_)>(0x1707FF0);
	static inline auto FReevaluatePlayerDisposition = PreyFunction<void()>(0x1709F70);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void()>(0x1709F70);
	static inline auto FInitializeTurret = PreyFunction<void(ArkTurret* const _this)>(0x17083B0);
	static inline auto FProcessDoneEvent = PreyFunction<void(ArkTurret* const _this)>(0x17099E0);
	static inline auto FRemoveAIObject = PreyFunction<void(ArkTurret* const _this)>(0x170A110);
	static inline auto FOnHealthChanged = PreyFunction<void(ArkTurret* const _this, bool _bFromDamage)>(0x1708D90);
	static inline auto FOnAiEnabled = PreyFunction<void(ArkTurret* const _this)>(0x1708930);
	static inline auto FOnAiDisabled = PreyFunction<void(ArkTurret* const _this)>(0x17088A0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x17092D0);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x1708F20);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x170AC00);
	static inline auto FOnHoldToUseStopped = PreyFunction<bool(IArkPlayerInteractionListener* const _this, IEntity* const _pEntity)>(0x1708F00);
	static inline auto FOnGlooHardenStart = PreyFunction<void(IArkGlooEffectObserver* const _this)>(0x1708C90);
	static inline auto FOnGlooBroken = PreyFunction<void(IArkGlooEffectObserver* const _this)>(0x1708C20);
	static inline auto FOnBrokenChanged = PreyFunction<void(IArkRepairableListener* const _this, bool _bBroken, bool _bWasForced)>(0x17089B0);
	static inline auto FOnFortified = PreyFunction<void(IArkRepairableListener* const _this)>(0x1708A50);
	static inline auto FOnEtherDuplicateCreated = PreyFunction<void(IArkEtherDuplicateListener* const _this, const unsigned _etherDuplicate)>(0x17089E0);
};
#endif // !MOONCRASH
