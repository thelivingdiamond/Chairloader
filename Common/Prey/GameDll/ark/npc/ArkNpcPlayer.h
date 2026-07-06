// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/iactorsystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/Player.h>
#include <Prey/GameDll/ark/ArkGroundColliderComponent.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/npc/ArkNpcDialogSpeaker.h>
#include <Prey/GameDll/ark/npc/ArkNpcSignalAccumulatorManager.h>
#include <Prey/GameDll/ark/npc/ArkNpcSignalReceiver.h>
#include <_unknown/IArkAIActor.h>

class ArkNpcAnimAction;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class CArkAlienGiblet;
enum class EArkGibletType;
enum class EStance;
struct HitInfo;
class IArkSpeaker;
struct ICharacterInstance;
struct IEntity;
struct IEntityClass;
struct IGameObject;
struct IParticleEffect;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SGameObjectEvent;
struct SRagdollizeParams;
struct pe_action_arkimpulse;

// ArkNpcPlayer
// Header:  Prey/GameDll/ark/npc/ArkNpcPlayer.h
class ArkNpcPlayer : public CPlayer
{ // Size=9448 (0x24E8)
public:
	enum class ERagdollInitializeState
	{
		None = 0,
		ReadyToInitialize = 1,
		Initialized = 2,
		Sync = 3,
	};

	// ArkNpcPlayer::ArkWeaponImpulseSettings
	// Header:  Prey/GameDll/ark/npc/ArkNpcPlayer.h
	struct ArkWeaponImpulseSettings
	{ // Size=36 (0x24)
		float m_scale;
		float m_min;
		float m_max;
		float m_applyTimeMin;
		float m_applyTimeMax;
		float m_falloffTime;
		float m_falloffFactor;
		float m_rampTime;
		float m_rampFactor;

	#if 0
		ArkWeaponImpulseSettings();
	#endif
	};

	ArkNpcDialogSpeaker m_arkNpcDialogSpeaker;
	ArkNpcSignalReceiver m_signalReceiver;
	ArkNpcSignalAccumulatorManager m_signalAccumulator;
	ArkGroundColliderComponent m_groundColliderComponent;
	bool m_bDeathReactionCompleted;
	bool m_bGibsOnDeath;
	bool m_bKilledFromExplosionReact;
	bool m_bKilledWhileMimicking;
	bool m_bDeathIsFatality;
	bool m_bDestroyGloo;
	float m_minGibFlingAngle;
	float m_gibFlingSpreadAngle;
	float m_fatalityFlingForce;
	float m_minFlingForceCalcDamage;
	float m_maxFlingForceCalcDamage;
	float m_minFlingForce;
	float m_maxFlingForce;
	float m_minExplosionGibFlingForce;
	float m_maxExplosionGibFlingForce;
	float m_lastDamageAmountTaken;
	float m_rigorMortisTime;
	ArkNpcCustomHitReaction::Type m_deathReactionType;
	bool m_bGibsInheritVelocity;
	float m_gibsInheritVelocityScalar;
	bool m_bExplodesOnContact;
	float m_timeUntilGibExplosion;
	ArkSimpleTimer m_gibExplosionTimer;
	uint64_t m_disintegrationGameEffectId;
	uint64_t m_smallHitSignalId;
	uint64_t m_staggerAccumulatorSignalGroupId;
	uint64_t m_knockdownAccumulatorSignalGroupId;
	uint64_t m_gooAccumulatorSignalGroupId;
	uint64_t m_breakGooAccumulatorSignalGroupId;
	uint64_t m_fearAccumulatorSignalGroupId;
	ArkNpcPlayer::ArkWeaponImpulseSettings m_weaponImpulseNormalG;
	ArkNpcPlayer::ArkWeaponImpulseSettings m_weaponImpulseLowG;
	ArkNpcPlayer::ArkWeaponImpulseSettings m_weaponImpulseZeroG;
	float m_arkWeaponImpulseDuration;
	float m_arkWeaponImpulseTimer;
	bool m_bArkWeaponImpulseHasPos;
	Vec3 m_arkWeaponImpulseCur;
	Vec3 m_arkWeaponImpulseRate;
	Vec3 m_arkWeaponImpulseDir;
	Vec3 m_arkWeaponImpulseAng;
	Vec3 m_arkWeaponImpulsePos;
	ArkSimpleTimer m_smallHitCooldown;
	bool m_bStartDisintegrationTimerFromDeath;
	bool m_bStartGibExplosionTimerFromDeath;
	bool m_bCorpseOrGibsVisible;
	bool m_bNightmare;
	bool m_bCanHover;
	bool m_bHasStartedDisintegration;
	bool m_bHasStartedGibDeath;
	bool m_bKilledWithHitInfo;
	bool m_bKillFromRecycling;
	bool m_bRigorMortis;
	bool m_bZeroG;
	EArkGravity m_gravitySetting;
	bool m_bHover;
	bool m_bInGravShaft;
	bool m_bSkipPrePhysicsUpdate;
	bool m_bForcingSingleFrameCorpseUpdatePostSerialize;
	_smart_ptr<IParticleEffect> m_pDeathGibParticleEffect;
	std::vector<ArkEntityAttachmentEffect> m_deathGibAttachmentEffects;
	EntityEffects::CEffectsController m_deathGibParticleController;
	ArkNpcPlayer::ERagdollInitializeState m_ragdollInitializeState;
	float m_minDamageForSmallHitReaction;
	EReactionHitType m_smallHitType;
	float m_footstepMinTime;
	IArkAIActor::PushObstacleParams m_footstepImpulse;
	ArkFireAndForgetEffect m_footstepParticleEffect;
	uint64_t m_footstepCameraShakeId;
	string m_animPose;
	std::map<unsigned int, float> m_ignoreEntityCollisionTimers;

	ArkNpcPlayer();
	virtual ~ArkNpcPlayer();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Release();
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot);
	virtual void OnFootStepAnimEvent(ICharacterInstance* pCharacter, const char* boneName);
	virtual void FullSerialize(TSerialize ser);
	virtual void PostSerialize();
	virtual bool TrySetStance(EStance stance);
	virtual void OnStanceChanged(EStance newStance, EStance oldStance);
	bool IsCorrupted() const { return FIsCorrupted(this); }
	virtual bool IsNormalG() const;
	virtual bool IsLowG() const;
	virtual bool IsZeroG() const;
	virtual bool IsHovering() const;
	void SetHovering(bool _bHover) { FSetHovering(this, _bHover); }
	void OnHit(const HitInfo& _hitInfo, const ArkSignalSystem::Package* _pPackage) { FOnHitOv1(this, _hitInfo, _pPackage); }
	void OnHit(const HitInfo& _hitInfo, const uint64_t& _packageId) { FOnHitOv0(this, _hitInfo, _packageId); }
	void OnHitNoDamage(const HitInfo& _hitInfo, const ArkSignalSystem::Package* _pPackage) { FOnHitNoDamage(this, _hitInfo, _pPackage); }
	void DelayedKill(int _delayMs) { FDelayedKill(this, _delayMs); }
	virtual void Kill();
	void Kill(const HitInfo& _hitInfo, const ArkSignalSystem::Package* _pPackage, bool _bPlayDeathReaction, ArkNpcCustomHitReaction::Type _customType) { FKillOv1(this, _hitInfo, _pPackage, _bPlayDeathReaction, _customType); }
	void Kill(const HitInfo& _hitInfo, const uint64_t& _packageId, bool _bPlayDeathReaction, ArkNpcCustomHitReaction::Type _customType) { FKillOv0(this, _hitInfo, _packageId, _bPlayDeathReaction, _customType); }
	virtual void PostPhysicalize();
	virtual void Fall(const HitInfo& hitInfo);
	virtual void RagDollize(bool _bFallAndPlay);
	virtual void StandUp();
	void UpdateDeathMetrics(const HitInfo& _hitInfo, const uint64_t& _packageId) const { FUpdateDeathMetrics(this, _hitInfo, _packageId); }
	virtual IArkSpeaker* GetArkSpeaker();
	void SetTrackviewArkFacing(IEntity* _pTargetEntity, const IActor::TrackviewLookPoseData& _facing) { FSetTrackviewArkFacing(this, _pTargetEntity, _facing); }
	virtual void SetTrackviewArkLookAt(IEntity* _pTargetEntity, const IActor::TrackviewLookPoseData& _torso, const IActor::TrackviewLookPoseData& _head, const IActor::TrackviewLookPoseData& _eyes);
	virtual void SetTrackviewArkAimAt(IEntity* _pTargetEntity, const IActor::TrackviewLookPoseData& _aim);
	void ApplyHitImpulse(const Vec3& _impulseDir, float _magnitude) { FApplyHitImpulseOv1(this, _impulseDir, _magnitude); }
	void ApplyHitImpulse(const Vec3& _impulsePos, const Vec3& _impulseDir, float _magnitude) { FApplyHitImpulseOv0(this, _impulsePos, _impulseDir, _magnitude); }
	bool OnKnockdownHitReaction(const HitInfo& _hitInfo, const _smart_ptr<ArkNpcAnimAction>& _pKnockdownAnim) { return FOnKnockdownHitReaction(this, _hitInfo, _pKnockdownAnim); }
	bool OnStaggerHitReaction(const HitInfo& _hitInfo, const _smart_ptr<ArkNpcAnimAction>& _pKnockdownAnim) { return FOnStaggerHitReaction(this, _hitInfo, _pKnockdownAnim); }
	bool OnSmallHitReaction(const HitInfo& _hitInfo, bool _bAdditive, const _smart_ptr<ArkNpcAnimAction>& _pKnockdownAnim) { return FOnSmallHitReaction(this, _hitInfo, _bAdditive, _pKnockdownAnim); }
	bool OnKillHitReaction(const HitInfo& _hitInfo, const _smart_ptr<ArkNpcAnimAction>& _pKillAnim) { return FOnKillHitReaction(this, _hitInfo, _pKillAnim); }
	void OnDeathReactionComplete() { FOnDeathReactionComplete(this); }
	bool IsInReaction() const { return FIsInReaction(this); }
	virtual void DamageInfo(unsigned shooterID, unsigned weaponID, IEntityClass* pProjectileClass, float damage, int damageType, const Vec3 hitDirection);
	virtual bool IsDead() const;
	virtual float GetHealth() const;
	virtual float GetMaxHealth() const;
	float GetHealthPercent() const { return FGetHealthPercent(this); }
	void SetHealth(float _health, bool _bTakingDamage) { FSetHealthOv1(this, _health, _bTakingDamage); }
	virtual void SetHealth(float _health);
	void OnImpulse() { FOnImpulse(this); }
	void SetCorpsePose(const string& _animPose, bool _bRigorMortis) { FSetCorpsePose(this, _animPose, _bRigorMortis); }
	void ClearRigorMortis() { FClearRigorMortis(this); }
	virtual void PostRagdollPhysicalized(SRagdollizeParams* _pRagdollParams);
	const ArkGroundColliderComponent& GetGroundColliderComponent() const { return FGetGroundColliderComponent(this); }
	bool StartDeathBlendToGibs() { return FStartDeathBlendToGibs(this); }
	void StartFatalityDeath() { FStartFatalityDeath(this); }
	bool IsInvulnerable() const { return FIsInvulnerable(this); }
	bool IsCantDieSet() const { return FIsCantDieSet(this); }
	void SetKilledFromExplosionReact(bool _bKilledFromExplosionReact) { FSetKilledFromExplosionReact(this, _bKilledFromExplosionReact); }
	bool CanSpeak() const { return FCanSpeak(this); }
	bool GibsOnDeath() const { return FGibsOnDeath(this); }
	virtual bool IsArkNpcPlayer();
	virtual void IgnoreCollisionSignals(unsigned _entityId, float _timeOut);
	virtual bool IsIgnoringCollisionSignals(unsigned _entityId) const;
	void ApplyOnRagdollPhysicalizedImpulse(const HitInfo& _info) { FApplyOnRagdollPhysicalizedImpulseOv2(this, _info); }
	void ApplyOnRagdollPhysicalizedImpulse(const Vec3& _impulse) { FApplyOnRagdollPhysicalizedImpulseOv1(this, _impulse); }
	void HideNpc(bool _bFlushActions) { FHideNpc(this, _bFlushActions); }
	void SetDesiredZeroGPitchRoll(float _pitch, float _roll) { FSetDesiredZeroGPitchRoll(this, _pitch, _roll); }
	void ClearDesiredZeroGPitchRoll() { FClearDesiredZeroGPitchRoll(this); }
	void OnCharacterSlotChanged() { FOnCharacterSlotChanged(this); }
	bool OnGravShaftEnter() { return FOnGravShaftEnter(this); }
	void OnGravShaftExit(bool _bFailure) { FOnGravShaftExit(this, _bFailure); }
	void CancelCurrentFearAccumulation() { FCancelCurrentFearAccumulation(this); }
	void StartCarry() { FStartCarry(this); }
	void StopCarry() { FStopCarry(this); }
	void SetUpRagdollCollisionFlags(IEntity& _entity, const bool _bIsInZeroG) { FSetUpRagdollCollisionFlags(this, _entity, _bIsInZeroG); }
	void DoHitImpulse() { FDoHitImpulse(this); }
	bool TrySetStanceHelper(EStance stance) { return FTrySetStanceHelper(this, stance); }
	void LoadScriptData() { FLoadScriptData(this); }
	void StartDisintegration() { FStartDisintegration(this); }
	void DoDisintegration() { FDoDisintegration(this); }
	void DoGibDeath() { FDoGibDeath(this); }
	void DoInstaGibDeath() { FDoInstaGibDeath(this); }
	void SynchronizeWithRagdoll() { FSynchronizeWithRagdoll(this); }
	std::vector<CArkAlienGiblet*> SpawnGibEntitiesOfType(const char* const _pGibClass, const char* const _pAttachmentSubStr, int _maxNumGibs, float _flingForce, const Vec3 _flingDir, EArkGibletType _gibletType) const { alignas(std::vector<CArkAlienGiblet*>) std::byte _return_buf_[sizeof(std::vector<CArkAlienGiblet*>)]; return *FSpawnGibEntitiesOfType(this, reinterpret_cast<std::vector<CArkAlienGiblet*>*>(_return_buf_), _pGibClass, _pAttachmentSubStr, _maxNumGibs, _flingForce, _flingDir, _gibletType); }
	void SpawnGibParticles(const char* const _pAttachmentSubStr, int _maxNumGibs, const Vec3& _flingDir) { FSpawnGibParticles(this, _pAttachmentSubStr, _maxNumGibs, _flingDir); }
	virtual Vec3 GetAttackTargetPos() const;
	virtual void SetMaxHealth(float _maxHealth);
	void OnFearAccumulationBegin(const ArkSignalSystem::Package* _pPackage, const HitInfo* _hitInfo) { FOnFearAccumulationBegin(this, _pPackage, _hitInfo); }
	void OnFearAccumulationEnd() { FOnFearAccumulationEnd(this); }
	void OnPsiSuppressingBegin(const ArkSignalSystem::Package* _pPackage, const HitInfo* _hitInfo) { FOnPsiSuppressingBegin(this, _pPackage, _hitInfo); }
	void OnPsiSuppressingEnd() { FOnPsiSuppressingEnd(this); }
	void OnStartGloo(const ArkSignalSystem::Package* _pPackage, const HitInfo* _hitInfo) { FOnStartGloo(this, _pPackage, _hitInfo); }
	void OnStopGloo(const ArkSignalSystem::Package* _pPackage, const HitInfo* _hitInfo) { FOnStopGlooOv1(this, _pPackage, _hitInfo); }
	void OnStopGloo() { FOnStopGlooOv0(this); }
	void OnStaggerOverThreshold(const ArkSignalSystem::Package* _pPackage, const HitInfo* _pHitInfo) { FOnStaggerOverThreshold(this, _pPackage, _pHitInfo); }
	void OnKnockdownOverThreshold(const ArkSignalSystem::Package* _pPackage, const HitInfo* _pHitInfo) { FOnKnockdownOverThreshold(this, _pPackage, _pHitInfo); }
	void OnHitReactionOverThresholdCommon(const uint64_t& _signalGroupId, EReactionHitType _hitType, const ArkSignalSystem::Package* _pPackage, const HitInfo* _pHitInfo) { FOnHitReactionOverThresholdCommon(this, _signalGroupId, _hitType, _pPackage, _pHitInfo); }
	void TrySmallHitReaction(const HitInfo& _hitInfo, const ArkSignalSystem::Package* _pPackage) { FTrySmallHitReaction(this, _hitInfo, _pPackage); }
	void RegisterAccumulatorNativeCallbacks() { FRegisterAccumulatorNativeCallbacks(this); }
	int GetMimicFootJointId(ICharacterInstance* pCharacter) { return FGetMimicFootJointId(this, pCharacter); }
	void StartOptimizedDeadUpdates() { FStartOptimizedDeadUpdates(this); }

#if 0
	bool CanHover() const;
	bool IsNightmare() const;
	void UpdateKilledByRecycling(const ArkSignalSystem::Package* _arg0_);
	ArkNpcDialogSpeaker& GetSpeaker();
	const ArkNpcDialogSpeaker& GetSpeaker() const;
	ArkNpcSignalAccumulatorManager& GetSignalAccumulator();
	const ArkNpcSignalAccumulatorManager& GetSignalAccumulator() const;
	bool HasHitImpulse() const;
	void ClearHitImpulses();
	void OnReactionComplete();
	void SetEtherformReceiver(bool _arg0_);
	ArkNpcSignalReceiver& GetSignalReceiver();
	void ApplyOnRagdollPhysicalizedImpulse(const pe_action_arkimpulse& _arg0_);
	void SetInvisible(bool _arg0_);
	const uint64_t& GetGooAccumulatorSignalGroupId() const;
	const uint64_t& GetBreakGooAccumulatorSignalGroupId() const;
	bool IsInGravShaft() const;
	void OnKilledByRecycling();
	void FlushActions();
	void CheckDeathCollisionExplosion(SEntityEvent& _arg0_);
	void HandleTimerEvent(int _arg0_);
	void PlayOnKillingBlowHitEffect(const HitInfo& _arg0_);
	void ResetDeadBodyData();
	void KillNpc();
	void StartGibDeath();
	IEntity* SpawnGib(IEntityClass* _arg0_, const Vec3& _arg1_, const Quat& _arg2_, EArkGibletType _arg3_) const;
	float CalcGibFlingForce() const;
	void PlayOnDeathParticleEffect() const;
	void PostSerializeKill();
	void InvalidateBoneIDs();
#endif

	static inline auto FArkNpcPlayer = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1627D90);
	static inline auto FInit = PreyFunction<bool(ArkNpcPlayer* const _this, IGameObject* _pGameObject)>(0x162BCF0);
	static inline auto FPostInit = PreyFunction<void(ArkNpcPlayer* const _this, IGameObject* _pGameObject)>(0x162EF40);
	static inline auto FRelease = PreyFunction<void(ArkNpcPlayer* const _this)>(0x16306E0);
	static inline auto FProcessEvent = PreyFunction<void(ArkNpcPlayer* const _this, SEntityEvent& _event)>(0x162F4E0);
	static inline auto FHandleEvent = PreyFunction<void(ArkNpcPlayer* const _this, const SGameObjectEvent& _event)>(0x162BB50);
	static inline auto FUpdate = PreyFunction<void(ArkNpcPlayer* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x16327A0);
	static inline auto FOnFootStepAnimEvent = PreyFunction<void(ArkNpcPlayer* const _this, ICharacterInstance* pCharacter, const char* boneName)>(0x162E3F0);
	static inline auto FFullSerialize = PreyFunction<void(ArkNpcPlayer* const _this, TSerialize ser)>(0x162AAF0);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162F210);
	static inline auto FTrySetStance = PreyFunction<bool(ArkNpcPlayer* const _this, EStance stance)>(0x1632330);
	static inline auto FOnStanceChanged = PreyFunction<void(ArkNpcPlayer* const _this, EStance newStance, EStance oldStance)>(0x162EF00);
	static inline auto FIsCorrupted = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x162BE50);
	static inline auto FIsNormalG = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x162C120);
	static inline auto FIsLowG = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x162C100);
	static inline auto FIsZeroG = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x162C140);
	static inline auto FIsHovering = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x162BEA0);
	static inline auto FSetHovering = PreyFunction<void(ArkNpcPlayer* const _this, bool _bHover)>(0x1630890);
	static inline auto FOnHitOv1 = PreyFunction<void(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const ArkSignalSystem::Package* _pPackage)>(0x162EB40);
	static inline auto FOnHitOv0 = PreyFunction<void(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const uint64_t& _packageId)>(0x162EA50);
	static inline auto FOnHitNoDamage = PreyFunction<void(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const ArkSignalSystem::Package* _pPackage)>(0x162EB90);
	static inline auto FDelayedKill = PreyFunction<void(ArkNpcPlayer* const _this, int _delayMs)>(0x1628E50);
	static inline auto FKillOv2 = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162C590);
	static inline auto FKillOv1 = PreyFunction<void(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const ArkSignalSystem::Package* _pPackage, bool _bPlayDeathReaction, ArkNpcCustomHitReaction::Type _customType)>(0x162C220);
	static inline auto FKillOv0 = PreyFunction<void(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const uint64_t& _packageId, bool _bPlayDeathReaction, ArkNpcCustomHitReaction::Type _customType)>(0x162C150);
	static inline auto FPostPhysicalize = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162EF80);
	static inline auto FFall = PreyFunction<void(ArkNpcPlayer* const _this, const HitInfo& hitInfo)>(0x162AA20);
	static inline auto FRagDollize = PreyFunction<void(ArkNpcPlayer* const _this, bool _bFallAndPlay)>(0x162FA30);
	static inline auto FStandUp = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1631E90);
	static inline auto FUpdateDeathMetrics = PreyFunction<void(const ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const uint64_t& _packageId)>(0x1632C80);
	static inline auto FGetArkSpeaker = PreyFunction<IArkSpeaker* (ArkNpcPlayer* const _this)>(0x162AFB0);
	static inline auto FSetTrackviewArkFacing = PreyFunction<void(ArkNpcPlayer* const _this, IEntity* _pTargetEntity, const IActor::TrackviewLookPoseData& _facing)>(0x1630B90);
	static inline auto FSetTrackviewArkLookAt = PreyFunction<void(ArkNpcPlayer* const _this, IEntity* _pTargetEntity, const IActor::TrackviewLookPoseData& _torso, const IActor::TrackviewLookPoseData& _head, const IActor::TrackviewLookPoseData& _eyes)>(0x1630C70);
	static inline auto FSetTrackviewArkAimAt = PreyFunction<void(ArkNpcPlayer* const _this, IEntity* _pTargetEntity, const IActor::TrackviewLookPoseData& _aim)>(0x1630950);
	static inline auto FApplyHitImpulseOv1 = PreyFunction<void(ArkNpcPlayer* const _this, const Vec3& _impulseDir, float _magnitude)>(0x1628740);
	static inline auto FApplyHitImpulseOv0 = PreyFunction<void(ArkNpcPlayer* const _this, const Vec3& _impulsePos, const Vec3& _impulseDir, float _magnitude)>(0x1628480);
	static inline auto FOnKnockdownHitReaction = PreyFunction<bool(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const _smart_ptr<ArkNpcAnimAction>& _pKnockdownAnim)>(0x162ED30);
	static inline auto FOnStaggerHitReaction = PreyFunction<bool(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const _smart_ptr<ArkNpcAnimAction>& _pKnockdownAnim)>(0x162EE80);
	static inline auto FOnSmallHitReaction = PreyFunction<bool(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, bool _bAdditive, const _smart_ptr<ArkNpcAnimAction>& _pKnockdownAnim)>(0x162EE20);
	static inline auto FOnKillHitReaction = PreyFunction<bool(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const _smart_ptr<ArkNpcAnimAction>& _pKillAnim)>(0x162ED00);
	static inline auto FOnDeathReactionComplete = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162E270);
	static inline auto FIsInReaction = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x162BF00);
	static inline auto FDamageInfo = PreyFunction<void(ArkNpcPlayer* const _this, unsigned shooterID, unsigned weaponID, IEntityClass* pProjectileClass, float damage, int damageType, const Vec3 hitDirection)>(0x1628D60);
	static inline auto FIsDead = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x162BE80);
	static inline auto FGetHealth = PreyFunction<float(const ArkNpcPlayer* const _this)>(0x162B130);
	static inline auto FGetMaxHealth = PreyFunction<float(const ArkNpcPlayer* const _this)>(0x162B290);
	static inline auto FGetHealthPercent = PreyFunction<float(const ArkNpcPlayer* const _this)>(0x162B160);
	static inline auto FSetHealthOv1 = PreyFunction<void(ArkNpcPlayer* const _this, float _health, bool _bTakingDamage)>(0x1630840);
	static inline auto FSetHealthOv0 = PreyFunction<void(ArkNpcPlayer* const _this, float _health)>(0x16307F0);
	static inline auto FOnImpulse = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1628C40);
	static inline auto FSetCorpsePose = PreyFunction<void(ArkNpcPlayer* const _this, const string& _animPose, bool _bRigorMortis)>(0x1630750);
	static inline auto FClearRigorMortis = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1628C40);
	static inline auto FPostRagdollPhysicalized = PreyFunction<void(ArkNpcPlayer* const _this, SRagdollizeParams* _pRagdollParams)>(0x162EFF0);
	static inline auto FGetGroundColliderComponent = PreyFunction<const ArkGroundColliderComponent& (const ArkNpcPlayer* const _this)>(0x162B120);
	static inline auto FStartDeathBlendToGibs = PreyFunction<bool(ArkNpcPlayer* const _this)>(0x1631FA0);
	static inline auto FStartFatalityDeath = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1632150);
	static inline auto FIsInvulnerable = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x162BFC0);
	static inline auto FIsCantDieSet = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x13B0900);
	static inline auto FSetKilledFromExplosionReact = PreyFunction<void(ArkNpcPlayer* const _this, bool _bKilledFromExplosionReact)>(0x16308A0);
	static inline auto FCanSpeak = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x1628BA0);
	static inline auto FGibsOnDeath = PreyFunction<bool(const ArkNpcPlayer* const _this)>(0x162BB40);
	static inline auto FIsArkNpcPlayer = PreyFunction<bool(ArkNpcPlayer* const _this)>(0x1A302A0);
	static inline auto FIgnoreCollisionSignals = PreyFunction<void(ArkNpcPlayer* const _this, unsigned _entityId, float _timeOut)>(0x162BC60);
	static inline auto FIsIgnoringCollisionSignals = PreyFunction<bool(const ArkNpcPlayer* const _this, unsigned _entityId)>(0x162BEB0);
	static inline auto FApplyOnRagdollPhysicalizedImpulseOv2 = PreyFunction<void(ArkNpcPlayer* const _this, const HitInfo& _info)>(0x1628AB0);
	static inline auto FApplyOnRagdollPhysicalizedImpulseOv1 = PreyFunction<void(ArkNpcPlayer* const _this, const Vec3& _impulse)>(0x16289E0);
	static inline auto FHideNpc = PreyFunction<void(ArkNpcPlayer* const _this, bool _bFlushActions)>(0x162BBA0);
	static inline auto FSetDesiredZeroGPitchRoll = PreyFunction<void(ArkNpcPlayer* const _this, float _pitch, float _roll)>(0x16307C0);
	static inline auto FClearDesiredZeroGPitchRoll = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1628C20);
	static inline auto FOnCharacterSlotChanged = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162E1C0);
	static inline auto FOnGravShaftEnter = PreyFunction<bool(ArkNpcPlayer* const _this)>(0x162E9D0);
	static inline auto FOnGravShaftExit = PreyFunction<void(ArkNpcPlayer* const _this, bool _bFailure)>(0x162EA10);
	static inline auto FCancelCurrentFearAccumulation = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1628BE0);
	static inline auto FStartCarry = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1631F60);
	static inline auto FStopCarry = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1632240);
	static inline auto FSetUpRagdollCollisionFlags = PreyFunction<void(ArkNpcPlayer* const _this, IEntity& _entity, const bool _bIsInZeroG)>(0x1630ED0);
	static inline auto FDoHitImpulse = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162A180);
	static inline auto FTrySetStanceHelper = PreyFunction<bool(ArkNpcPlayer* const _this, EStance stance)>(0x1632440);
	static inline auto FLoadScriptData = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162C8F0);
	static inline auto FStartDisintegration = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1632010);
	static inline auto FDoDisintegration = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1628E70);
	static inline auto FDoGibDeath = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1628F00);
	static inline auto FDoInstaGibDeath = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162A9E0);
	static inline auto FSynchronizeWithRagdoll = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1632270);
	static inline auto FSpawnGibEntitiesOfType = PreyFunction<std::vector<CArkAlienGiblet*>*(const ArkNpcPlayer* const _this, std::vector<CArkAlienGiblet*>* _return_value_, const char* const _pGibClass, const char* const _pAttachmentSubStr, int _maxNumGibs, float _flingForce, const Vec3 _flingDir, EArkGibletType _gibletType)>(0x1630FA0);
	static inline auto FSpawnGibParticles = PreyFunction<void(ArkNpcPlayer* const _this, const char* const _pAttachmentSubStr, int _maxNumGibs, const Vec3& _flingDir)>(0x1631A30);
	static inline auto FGetAttackTargetPos = PreyFunction<Vec3*(const ArkNpcPlayer* const _this, Vec3* _return_value_)>(0x162AFC0);
	static inline auto FSetMaxHealth = PreyFunction<void(ArkNpcPlayer* const _this, float _maxHealth)>(0x16308F0);
	static inline auto FOnFearAccumulationBegin = PreyFunction<void(ArkNpcPlayer* const _this, const ArkSignalSystem::Package* _pPackage, const HitInfo* _hitInfo)>(0x162E390);
	static inline auto FOnFearAccumulationEnd = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162E3D0);
	static inline auto FOnPsiSuppressingBegin = PreyFunction<void(ArkNpcPlayer* const _this, const ArkSignalSystem::Package* _pPackage, const HitInfo* _hitInfo)>(0x162EDA0);
	static inline auto FOnPsiSuppressingEnd = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162EDE0);
	static inline auto FOnStartGloo = PreyFunction<void(ArkNpcPlayer* const _this, const ArkSignalSystem::Package* _pPackage, const HitInfo* _hitInfo)>(0x162EF10);
	static inline auto FOnStopGlooOv1 = PreyFunction<void(ArkNpcPlayer* const _this, const ArkSignalSystem::Package* _pPackage, const HitInfo* _hitInfo)>(0x162EF20);
	static inline auto FOnStopGlooOv0 = PreyFunction<void(ArkNpcPlayer* const _this)>(0x162EF20);
	static inline auto FOnStaggerOverThreshold = PreyFunction<void(ArkNpcPlayer* const _this, const ArkSignalSystem::Package* _pPackage, const HitInfo* _pHitInfo)>(0x162EED0);
	static inline auto FOnKnockdownOverThreshold = PreyFunction<void(ArkNpcPlayer* const _this, const ArkSignalSystem::Package* _pPackage, const HitInfo* _pHitInfo)>(0x162ED80);
	static inline auto FOnHitReactionOverThresholdCommon = PreyFunction<void(ArkNpcPlayer* const _this, const uint64_t& _signalGroupId, EReactionHitType _hitType, const ArkSignalSystem::Package* _pPackage, const HitInfo* _pHitInfo)>(0x162EBE0);
	static inline auto FTrySmallHitReaction = PreyFunction<void(ArkNpcPlayer* const _this, const HitInfo& _hitInfo, const ArkSignalSystem::Package* _pPackage)>(0x1632610);
	static inline auto FRegisterAccumulatorNativeCallbacks = PreyFunction<void(ArkNpcPlayer* const _this)>(0x1630130);
	static inline auto FGetMimicFootJointId = PreyFunction<int(ArkNpcPlayer* const _this, ICharacterInstance* pCharacter)>(0x162B2B0);
	static inline auto FStartOptimizedDeadUpdates = PreyFunction<void(ArkNpcPlayer* const _this)>(0x16321D0);
};
#endif // MOONCRASH
