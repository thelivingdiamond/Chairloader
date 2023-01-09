// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/AreaProxy.h>
#include <Prey/GameDll/Ark/npc/desires/ArkNpcMovementDesireManager.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/ArkCommon/arkintrusivelist.h>
//#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryAISystem/MovementRequestID.h>
#include <Prey/CryAISystem/MovementStyle.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/GameDll/ark/ArkAirJetManager.h>
#include <Prey/GameDll/ark/ArkCharacterEffectsManager.h>
#include <Prey/ArkCommon/ArkDelegate.h>
#include <Prey/GameDll/ark/ArkFactionLink.h>
#include <Prey/GameDll/ark/ArkMaterialAnimationManager.h>
#include <Prey/GameDll/ark/ArkRobotLight.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkdoor.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/attention/ArkNpcAttentionObject.h>
#include <Prey/GameDll/ark/iface/IArkPsiPowerTargetingListener.h>
#include <Prey/GameDll/ark/npc/ArkNpcProperties.h>
#include <Prey/GameDll/ark/npc/ArkNpcLookaroundControl.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesireManager.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesireManager.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcNoiseStateDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcNoiseStateDesireManager.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesireManager.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/player/psipower/arkpsiliftvolume.h>
#include <Prey/GameDll/ark/player/psipower/arkpsiliftvolumemanager.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h>
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerEntry.h>
#include <Prey/GameDll/ark/ArkAiKnowledge.h>
#include <Prey/GameDLL/ark/perception/ArkAttentiveSubject.h>
#include <Prey/GameDll/ark/npc/IArkNpc.h>
#include <Chairloader/PreyFunction.h>
#include <Prey/ArkCommon/ArkUnanimous.h>
#include "Prey/GameDll/EntityUtility/EntityEffects.h"
#include "Prey/GameDll/ark/spatial/arkspatialmanagerentry_npc.h"
#include "Prey/ArkStubs.h"
#include "ArkNpcSpawnedState.h"

class ArkAiTreeInstanceNode;
class ArkGlooEffectAccumulated;
struct ArkInteractionInfo;
struct ArkInteractionTestResult;
class ArkNpcBodyStateObserver_Animated;
class ArkNpcBodyStateObserver_Busy;
class ArkNpcBodyStateObserver_Dissipate;
class ArkNpcCollisionObserver;
class ArkNpcSpeedDesire;
class ArkNpcAnimAction;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct EventPhysCollision;
struct IAnimSequence;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct IEntityClass;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
class ArkNpcLifecycle;
class ArkNpcBody;
class ArkNpcDamageFsm;
class ArkAiTree;
class ArkAiTreeInstance;


// Header: Exact
// Prey/GameDll/ark/npc/ArkNpc.h
class ArkNpc : public IArkNpc, public CGameObjectExtensionHelper<ArkNpc,IGameObjectExtension>, public IArkPlayerInteractionListener, public IArkPsiPowerTargetingListener // Id=801405D Size=7512
{
public:
	class LiftEntitySpawner // Id=801419F Size=8
	{
	public:
		ArkPsiPowerLiftUniqueProperties const &m_properties;
		
		LiftEntitySpawner();
		
#if 0
		ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity> Spawn(const unsigned arg0) const;
#endif
	};

	using LiftVolume = ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>;
	using LiftVolumeManager = ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >;
	
	std::vector<Vec3> m_cachedDoppelgangerCandidatePositions;
	std::vector<unsigned int> m_cachedNearbyNpcsForAbility;
	Vec3 m_cachedThermogenesisLocation;
	Vec3 m_cachedEMPBlastLocation;
	Vec3 m_cachedHitReactShiftLocation;
	
	enum class ECryAiSystemActiveState
	{
		unknown = -1,
		inactive = 0,
		active = 1,
	};

	using CollisionObserverList = ArkIntrusiveList<ArkNpcCollisionObserver>;
	using EntityClassVector = std::vector<IEntityClass const *>;
	using FleeStartFlowNodeCallback = ArkDelegate<void __cdecl(void)>;
	using FleeEndFlowNodeCallback = ArkDelegate<void __cdecl(void)>;
	using GuardInPositionFlowNodeCallback = ArkDelegate<void __cdecl(void)>;
	using CreatePhantomFlowNodeCallback = ArkDelegate<void __cdecl(unsigned int,unsigned int,bool)>;
	
	static std::vector<IEntityClass const *> s_mimicableEntityClasses;
	static ArkFactionLink s_playerAndPlayerControlledFactionLink[5];
	static bool s_bFactionLinkInitialized;
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Npc> m_spatialManagerEntry;
	uint64_t m_characterId;
	EntityEffects::CEffectsController m_effectController;
	ArkNpcFacingDesireManager m_facingDesireManager;
	ArkNpcLookDesireManager m_lookDesireManager;
	ArkNpcMovementDesireManager m_movementDesireManager;
	ArkNpcNoiseStateDesireManager m_noiseStateDesireManager;
	ArkNpcSpeedDesireManager m_speedDesireManager;
	ArkCharacterEffectsManager m_characterEffectsManager;
	ArkMaterialAnimationManager m_materialAnimationManager;
	ArkNpcAttentiveSubject m_attentiveSubject;
	ArkNpcAttentionObject m_attentionObject;
	CArkNpcLookAroundControl m_lookAround;
	ArkIntrusiveList<ArkNpcCollisionObserver> m_collisionObservers;
	ArkNpcProperties m_properties;
	boost::variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant> m_spawnedState;
	std::unique_ptr<ArkNpcLifecycle> m_pLifecycle;
	std::unique_ptr<ArkNpcBody> m_pBody;
	std::unique_ptr<ArkNpcDamageFsm> m_pDamageFsm;
	ArkNpcLookDesire m_attentionLookDesire;
	ArkNpcNoiseStateDesire m_attentionNoiseStateDesire;
	ArkNpcFacingDesire m_blendRagdollFacingDesire;
	ArkNpcLookDesire m_blendRagdollLookDesire;
	ArkNpcMovementDesire m_blendRagdollMovementDesire;
	ArkNpcFacingDesire m_conversationFaceDesire;
	ArkNpcLookDesire m_conversationLookDesire;
	ArkNpcMovementDesire m_conversationMovementDesire;
	ArkNpcFacingDesire m_trackViewFacingDesire;
	ArkNpcLookDesire m_trackViewLookingDesire;
	ArkNpc::ECryAiSystemActiveState m_cryAISystemState;
	ArkAiKnowledge m_aiKnowledge;
	string m_aiTreeFilePath;
	std::shared_ptr<ArkAiTree> m_pAiTree;
	std::unique_ptr<ArkAiTreeInstance> m_pAiTreeInstance;
	bool m_bUpdatingForStimuli;
	bool m_bSerializedUpdatingForStimuli;
	ArkUnanimous m_abilitiesEnabled;
	ArkUnanimous m_aiTreeEnabled;
	ArkUnanimous m_ambientSoundEnabled[2];
	ArkUnanimous m_attentionObjectEnabled;
	ArkUnanimous m_attentiveSubjectEnabled;
	ArkUnanimous m_audibleEnabled;
	ArkUnanimous m_combatIntensityEnabled;
	ArkUnanimous m_hearingEnabled;
	ArkUnanimous m_lifetimeEffectEnabled;
	ArkUnanimous m_operatorLevitatorsEffectEnabled;
	ArkUnanimous m_roomPerceiverEnabled;
	ArkUnanimous m_visibleEnabled;
	ArkUnanimous m_visionEnabled;
	uint64_t m_aiAlwaysUpdatePushCount;
	uint64_t m_aiTreeSuspendedCount;
	uint64_t m_disableDeathReactionsCount;
	uint64_t m_disableHitReactionsCount;
	uint64_t m_disableNpcHealthUiCount;
	uint64_t m_dumbedCount;
	uint64_t m_glassBreakingEnabledCount;
	uint64_t m_rigidOnGlooFrozenCount;
	bool m_bFlowGraphAiDisabled;
	bool m_bFlowGraphCanCorruptNpcs;
	bool m_bFlowGraphCombatIntensityDisabled;
	bool m_bFlowGraphDumbed;
	bool m_bFlowGraphIgnoreDistractions;
	bool m_bHasTimeToDeath;
	float m_timeToDeath;
	Vec3 m_headPosition;
	Vec3 m_headDirection;
	ArkAudioRtpc m_distanceToPlayerRtpc;
	unsigned m_wanderAreaContainerEntityId;
	bool m_bWanderDisabled;
	bool m_bCurrentlyWandering;
	bool m_bPushedAIAlwaysUpdateForPatrol;
	bool m_bCanBeDistracted;
	bool m_bIsDistracted;
	float m_usedDistractionCooldown;
	ArkUnanimous m_breakable;
	float m_transitionStateTagTimer;
	bool m_bShouldSkipNextCombatReaction;
	bool m_bAnimatedMovement;
	bool m_bAnimatedJump;
	bool m_bIsFrozenInGloo;
	bool m_bDeflectsGloo;
	unsigned m_breakGlooEntityId;
	ArkSimpleTimer m_playerBumpTimer;
	ArkSimpleTimer m_xRayVisionTimeOnPlayer;
	unsigned m_topAttentionTargetEntityId;
	ArkDelegate<void __cdecl(void)> m_fleeStartFlowNodeCallback;
	ArkDelegate<void __cdecl(void)> m_fleeEndFlowNodeCallback;
	ArkDelegate<void __cdecl(void)> m_guardInPositionFlowNodeCallback;
	ArkDelegate<void __cdecl(unsigned int,unsigned int,bool)> m_createPhantomFlowNodeCallback;
	bool m_bHasPerformedNotice;
	CTimeValue m_lastSearchAnimTime;
	bool m_bIsInCombat;
	bool m_bCombatIntensityIncreased;
	EArkCombatRole m_currentCombatRole;
	float m_combatReactionCooldownTimer;
	HitInfo m_lastDamagingHitInfo;
	uint64_t m_lastDamagingPackageId;
	int m_lastOnHitFrameId;
	CTimeValue m_damageAccumulationStartTime;
	float m_damageAccumulationFromPlayer;
	bool m_bIsIgnoringRangedAbilities;
	uint64_t m_lastAbilityContextIdPerformed;
	CTimeValue m_dodgeTimeStamp;
	CTimeValue m_knockDownTimeStamp;
	CTimeValue m_staggerTimeStamp;
	CTimeValue m_hypnotizeStartTimeStamp;
	bool m_bPsiSuppressed;
	bool m_bIsPrereqHitReacting;
	bool m_bIsTakingPrereqDamage;
	bool m_bPrereqIsRegainingLoS;
	bool m_bCanMimicSideStepLeft;
	bool m_bCanMimicSideStepRight;
	uint64_t m_animAttackPackageId;
	_smart_ptr<IAnimSequence> m_pTrackviewSequence;
	float m_mimicGlitchTimeNext;
	ArkEntityAttachmentEffect m_mimicMorphInEffect;
	ArkEntityAttachmentEffect m_mimicMorphOutEffect;
	std::vector<unsigned int> m_raisedPhantomIds;
	unsigned m_ethericDoppelgangerId;
	unsigned m_ethericDoppelgangerOwnerId;
	bool m_bIsEthericDoppelganger;
	std::unique_ptr<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>> m_pLiftVolumeManager;
	unsigned m_npcThatCorruptedMe;
	std::vector<unsigned int> m_npcsCorrupted;
	bool m_bCorruptedMovementDisabled;
	bool m_bWasUncorrupted;
	ArkEntityAttachmentEffect m_CorruptedMovementGlitchEffect1;
	ArkEntityAttachmentEffect m_CorruptedMovementGlitchEffect2;
	ArkAirJetManager m_operatorAirJetManager;
	ArkRobotLight m_robotLight;
	ArkFireAndForgetEffect m_aoeDeathEffect;
	Vec3 m_cachedThrowAtLocation;
	EReactionThrowAtType m_cachedThrowAtType;
	unsigned m_leaderEntityId;
	unsigned m_attachedPistolEntityId;
	int m_numAmmo;
	bool m_bInitiallyUpdateAi;
	bool m_bIsSerializingRead;
	bool m_bHasFullSerializeReadBeenCalled;
	bool m_bShuttingDown_Hack;
	
	class SetSpawnedStateVisitor : public boost::static_visitor<void> // Id=8014437 Size=8
	{
	public:
		ArkNpc &m_npc;
		
#if 0
		void operator()(ArkNpcSpawnedState_Alert const &arg0) const;
		void operator()(ArkNpcSpawnedState_Broken const &arg0) const;
		void operator()(ArkNpcSpawnedState_Dead const &arg0) const;
		void operator()(ArkNpcSpawnedState_Dormant const &arg0) const;
		void SetAliveSpawnedState(ArkNpcSpawnedState_Alive const &arg0) const;
#endif
	};

	ArkNpc();
    virtual ~ArkNpc() = 0;
    ArkNpcProperties const &GetProperties() const { return FGetProperties(this); }
	void AddCollisionObserver(ArkNpcCollisionObserver &_observer) { FAddCollisionObserver(this,_observer); }
	void RemoveCollisionObserver(ArkNpcCollisionObserver &_observer) { FRemoveCollisionObserver(this,_observer); }
	bool OnWrenchAttack(const float _swipeDirection) { return FOnWrenchAttack(this,_swipeDirection); }
	void OnHealthChanged(float _newHealth, bool _bTakingDamage) { FOnHealthChanged(this,_newHealth,_bTakingDamage); }
	void RemoveInboundModifier(uint64_t _modifierId) { FRemoveInboundModifier(this,_modifierId); }
	void AddInboundModifier(uint64_t _modifierId, bool _bModifierShouldBeUnique) { FAddInboundModifier(this,_modifierId,_bModifierShouldBeUnique); }
	void AddLookDesire(ArkNpcLookDesire &_desire) { FAddLookDesire(this,_desire); }
	void RemoveLookDesire(ArkNpcLookDesire &_desire) { FRemoveLookDesire(this,_desire); }
	bool HasLookDesire(ArkNpcLookDesire const &_desire) const { return FHasLookDesire(this,_desire); }
	void ScaleLookDesireSpeed(float _scale) { FScaleLookDesireSpeed(this,_scale); }
	void AddFacingDesire(ArkNpcFacingDesire &_desire) { FAddFacingDesire(this,_desire); }
	void RemoveFacingDesire(ArkNpcFacingDesire &_desire) { FRemoveFacingDesire(this,_desire); }
	bool HasFacingDesire(ArkNpcFacingDesire const &_desire) const { return FHasFacingDesire(this,_desire); }
	void AddMovementDesire(ArkNpcMovementDesire &_desire) { FAddMovementDesire(this,_desire); }
	void RemoveMovementDesire(ArkNpcMovementDesire &_desire) { FRemoveMovementDesire(this,_desire); }
	bool HasMovementDesire(ArkNpcMovementDesire const &_desire) const { return FHasMovementDesire(this,_desire); }
	bool IsMovementDesireExecuting(ArkNpcMovementDesire const &_desire) const { return FIsMovementDesireExecuting(this,_desire); }
	EArkNpcSpeedType GetDesiredSpeed() const { return FGetDesiredSpeed(this); }
	void AddSpeedDesire(ArkNpcSpeedDesire &_desire) { FAddSpeedDesire(this,_desire); }
	void RemoveSpeedDesire(ArkNpcSpeedDesire &_desire) { FRemoveSpeedDesire(this,_desire); }
	bool HasSpeedDesire(ArkNpcSpeedDesire const &_desire) const { return FHasSpeedDesire(this,_desire); }
	void AddNoiseStateDesire(ArkNpcNoiseStateDesire &_desire) { FAddNoiseStateDesire(this,_desire); }
	void RemoveNoiseStateDesire(ArkNpcNoiseStateDesire &_desire) { FRemoveNoiseStateDesire(this,_desire); }
	bool HasMovementRequest() const { return FHasMovementRequest(this); }
	MovementRequestID GetMovementRequestId() const { return FGetMovementRequestId(this); }
    bool IsMovementInterruptible() const { return FIsMovementInterruptible(this); }
	bool IsShifting() const { return FIsShifting(this); }
	bool IsJumping() const { return FIsJumping(this); }
	bool CanJump() const { return FCanJump(this); }
	void RequestLurk(const unsigned _lurkPointEntityId, const unsigned _lurkTargetId, const bool _bShouldMoveInstantly, const bool _bShouldMatchPointRotation) { FRequestLurk(this,_lurkPointEntityId,_lurkTargetId,_bShouldMoveInstantly,_bShouldMatchPointRotation); }
	void RequestStopLurk() { FRequestStopLurk(this); }
	bool IsLurking() const { return FIsLurking(this); }
	bool BeginLurking(ArkNpcBodyStateObserver_Animated &_observer) { return FBeginLurking(this,_observer); }
	bool EndLurking() { return FEndLurking(this); }
	bool TryPerformAnyAbility(unsigned _targetId) { return FTryPerformAnyAbility(this,_targetId); }
	bool IsEthericDoppelganger() const { return FIsEthericDoppelganger(this); }
	unsigned GetEthericDoppelgangerOwnerId() const { return FGetEthericDoppelgangerOwnerId(this); }
	bool HasActiveEthericDoppelganger() const { return FHasActiveEthericDoppelganger(this); }
	unsigned GetActiveEthericDoppelgangerId() const { return FGetActiveEthericDoppelgangerId(this); }
	void SetTimeUntilDeath(float _timeUntilDeath) { FSetTimeUntilDeath(this,_timeUntilDeath); }
	void SetEthericDoppelgangerId(unsigned _doppelgangerId) { FSetEthericDoppelgangerId(this,_doppelgangerId); }
	void SetEthericDoppengangerOwnerId(unsigned _doppelgangerOwnerId) { FSetEthericDoppengangerOwnerId(this,_doppelgangerOwnerId); }
	void SetIsEthericDoppelganger(bool _bIsEthericDoppelganger) { FSetIsEthericDoppelganger(this,_bIsEthericDoppelganger); }
	void SetStance(EStance _stance) { FSetStance(this,_stance); }
		bool IsAlert() const { return FIsAlert(this); }
	bool CanSee(IEntity const &_entity) const { return FCanSee(this,_entity); }
	void OnAttentionProxyUpdated(unsigned _attentionObjectEntityId) { FOnAttentionProxyUpdated(this,_attentionObjectEntityId); }
		void OnLostAttentionTarget(unsigned _targetEntityId, bool _bDelayed) { FOnLostAttentionTarget(this,_targetEntityId,_bDelayed); }
	void OnHitFloor(float _fallDistance) { FOnHitFloor(this,_fallDistance); }
	void OnHit(HitInfo const &_hitInfo, ArkSignalSystem::Package const *_pPackage) { FOnHit(this,_hitInfo,_pPackage); }
	void OnZeroDamageHit(HitInfo const &_hitInfo) { FOnZeroDamageHit(this,_hitInfo); }
	void OnCollisionSignal(unsigned _collisionInstigatorId) { FOnCollisionSignal(this,_collisionInstigatorId); }
	void OnKill(bool _bPostSerializeKill) { FOnKill(this,_bPostSerializeKill); }
	void FearAOEOnPlayerKill(HitInfo const &_hitInfo) const { FFearAOEOnPlayerKill(this,_hitInfo); }
		bool PushIndefiniteRagdoll() { return FPushIndefiniteRagdoll(this); }
	bool PopIndefiniteRagdoll() { return FPopIndefiniteRagdoll(this); }
	bool Ragdoll(ArkInterval<float> const &_ragdollInterval) { return FRagdoll(this,_ragdollInterval); }
	bool IsRagdolled() const { return FIsRagdolled(this); }
	bool IsStandingUp() const { return FIsStandingUp(this); }
	void OverrideCharacterId(const uint64_t _overrideId) { FOverrideCharacterId(this,_overrideId); }
	void FlowgraphDisableCombatIntensity() { FFlowgraphDisableCombatIntensity(this); }
	void FlowgraphEnableCombatIntensity() { FFlowgraphEnableCombatIntensity(this); }
	void CallForHelp(unsigned _referenceEntityId, Vec3 const &_reeferencePos, uint64_t _noiseType, uint64_t _loudness) const { FCallForHelp(this,_referenceEntityId,_reeferencePos,_noiseType,_loudness); }
	void OnReactionComplete() { FOnReactionComplete(this); }
	void OnDeathReactionComplete() { FOnDeathReactionComplete(this); }
	void OnStartFlareHypnotize(unsigned _flareEntityId) { FOnStartFlareHypnotize(this,_flareEntityId); }
	void OnStopFlareHypnotize() { FOnStopFlareHypnotize(this); }
	void OnStartScriptMove() { FOnStartScriptMove(this); }
	void OnStopScriptMove() { FOnStopScriptMove(this); }
	bool Hypnotize(unsigned _flareEntityId) { return FHypnotize(this,_flareEntityId); }
	bool HypnotizeInterrupted() { return FHypnotizeInterrupted(this); }
	bool IsLureFlareValid(unsigned _flareEntityId) const { return FIsLureFlareValid(this,_flareEntityId); }
	void OnWanderWaiting() { FOnWanderWaiting(this); }
	void OnWanderBecomeActive() { FOnWanderBecomeActive(this); }
	void OnWanderBecomeInactive() { FOnWanderBecomeInactive(this); }
	void OnPatrolRequestClosest(int _movementStyleSpeed, bool _bOffNavMesh) { FOnPatrolRequestClosest(this,_movementStyleSpeed,_bOffNavMesh); }
	bool OnPatrolRequest(unsigned _patrolIndex, int _pointIndex, int _movementStyleSpeed, bool _bOffNavMesh) { return FOnPatrolRequest(this,_patrolIndex,_pointIndex,_movementStyleSpeed,_bOffNavMesh); }
	void OnPatrolRequestUpdate(unsigned _patrolIndex, int _pointIndex, int _movementStyleSpeed, bool _bOffNavMesh) { FOnPatrolRequestUpdate(this,_patrolIndex,_pointIndex,_movementStyleSpeed,_bOffNavMesh); }
	void OnPatrolCancel() { FOnPatrolCancel(this); }
	void PushAIAlwaysUpdateForPatrol() { FPushAIAlwaysUpdateForPatrol(this); }
	void OnPatrolBegin() { FOnPatrolBegin(this); }
	void OnPatrolEnd() { FOnPatrolEnd(this); }
	void OnCorruptNpcRequest(const unsigned _entityIdToCorrupt, bool _bFromCombat) { FOnCorruptNpcRequest(this,_entityIdToCorrupt,_bFromCombat); }
	void OnEnteredTrackviewBodyState() { FOnEnteredTrackviewBodyState(this); }
	void OnTrackviewStateExit() { FOnTrackviewStateExit(this); }
	bool InTrackviewSequence() const { return FInTrackviewSequence(this); }
	void OnStartedMimicking(IEntity const &_targetEntity, EArkNpcMimicryReason _reason) { FOnStartedMimicking(this,_targetEntity,_reason); }
	void OnStoppedMimicking() { FOnStoppedMimicking(this); }
	void PushDisableNpcHealthUI() { FPushDisableNpcHealthUI(this); }
	void PopDisableNpcHealthUI() { FPopDisableNpcHealthUI(this); }
	bool IsNpcHealthUIDisabled() const { return FIsNpcHealthUIDisabled(this); }
	void PushDisableDeathReactions() { FPushDisableDeathReactions(this); }
	bool OnKnockdownHitReaction(_smart_ptr<ArkNpcAnimAction> const &_pKnockdownAnim) { return FOnKnockdownHitReaction(this,_pKnockdownAnim); }
	bool OnStaggerHitReaction(_smart_ptr<ArkNpcAnimAction> const &_pStaggerAnim) { return FOnStaggerHitReaction(this,_pStaggerAnim); }
	bool OnSmallHitReaction(bool _bAdditive, _smart_ptr<ArkNpcAnimAction> const &_pSmallHitAnim) { return FOnSmallHitReaction(this,_bAdditive,_pSmallHitAnim); }
	bool OnKillHitReaction(_smart_ptr<ArkNpcAnimAction> const &_pKillAnim) { return FOnKillHitReaction(this,_pKillAnim); }
	bool OverrideHitReactAnimation(HitInfo const &_hitInfo) { return FOverrideHitReactAnimation(this,_hitInfo); }
	bool CanHitReact(HitInfo const &_hitInfo, bool _bIsBigHit) const { return FCanHitReact(this,_hitInfo,_bIsBigHit); }
	bool CanDeathReact() const { return FCanDeathReact(this); }
	bool ShouldMimicRebound(IEntity const *_pHitEntity, Vec3 const &_hitNormal) const { return FShouldMimicRebound(this,_pHitEntity,_hitNormal); }
	bool MimicCollisionRebound(EventPhysCollision const &_collisionEvent) { return FMimicCollisionRebound(this,_collisionEvent); }
	int GetNumControlledTurrets() const { return FGetNumControlledTurrets(this); }
	void PushFear(unsigned _instigator, bool _bManualPop, bool _bFromAccumulator, bool _bPlayFearVFX) { FPushFear(this,_instigator,_bManualPop,_bFromAccumulator,_bPlayFearVFX); }
	void PopFear(bool _bFromAccumulator) { FPopFear(this,_bFromAccumulator); }
	void ClearFear() { FClearFear(this); }
	void SetFearFromHostileDamage(bool _bFleeFromDamage) const { FSetFearFromHostileDamage(this,_bFleeFromDamage); }
	void OnFearedStarted(unsigned _instigator) { FOnFearedStarted(this,_instigator); }
	void OnFearedRefreshed(unsigned _instigator) { FOnFearedRefreshed(this,_instigator); }
	void OnFearStopped() { FOnFearStopped(this); }
	void RegisterOnFleeNodeCallsbacks(ArkDelegate<void __cdecl(void)> _fleeStartflowNodeCallback, ArkDelegate<void __cdecl(void)> _fleeEndflowNodeCallback) { FRegisterOnFleeNodeCallsbacks(this,_fleeStartflowNodeCallback,_fleeEndflowNodeCallback); }
	void OnChargeTarget(unsigned _chargeTargetId) { FOnChargeTarget(this,_chargeTargetId); }
	void OnRecycled(unsigned _instigatorId) { FOnRecycled(this,_instigatorId); }
	void OnCreatePhantomRequest(unsigned _corpseId, unsigned _phantomTargetId, bool _bRequestedFromCombat, ArkDelegate<void __cdecl(unsigned int,unsigned int,bool)> _flowNodeCallback, IEntityArchetype *_pPhantomArchetype, bool bIgnoreMovement, bool bIsScripted) { FOnCreatePhantomRequest(this,_corpseId,_phantomTargetId,_bRequestedFromCombat,_flowNodeCallback,_pPhantomArchetype,bIgnoreMovement,bIsScripted); }
	void OnCreatePhantomSuccess(unsigned _createdPhantomId) { FOnCreatePhantomSuccess(this,_createdPhantomId); }
	void OnCreatePhantomFail() { FOnCreatePhantomFail(this); }
	void OnCreatePhantomCancel() { FOnCreatePhantomCancel(this); }
	void OnAttack(unsigned _targetId) { FOnAttack(this,_targetId); }
	void OnUsePower() { FOnUsePower(this); }
	void CorruptedMovementGlitch() { FCorruptedMovementGlitch(this); }
	EArkCombatRole GetCurrentCombatRole() const { return FGetCurrentCombatRole(this); }
	void SetCurrentCombatRole(EArkCombatRole _newRole) { FSetCurrentCombatRole(this,_newRole); }
	void OnDesiredRoleChanged(EArkCombatRole _newDesiredRole) { FOnDesiredRoleChanged(this,_newDesiredRole); }
	bool PerformCombatReaction() { return FPerformCombatReaction(this); }
	bool CanMimicSideStepRight() const { return FCanMimicSideStepRight(this); }
	bool CanMimicSideStepLeft() const { return FCanMimicSideStepLeft(this); }
	bool CalcHasSpaceToMimicSideStep(Vec2 _directionToTarget, float _traceDistance, float _traceHeightBias, float _traceRadius) const { return FCalcHasSpaceToMimicSideStep(this,_directionToTarget,_traceDistance,_traceHeightBias,_traceRadius); }
	Vec3 GetHeadDirection() const { return FGetHeadDirection(this); }
	Vec3 GetHeadPosition() const { return FGetHeadPosition(this); }
	unsigned GetAttachedPistolId() const { return FGetAttachedPistolId(this); }
	void AttachPistol() { FAttachPistol(this); }
	void SetPistolHidden(bool _bHidden) const { FSetPistolHidden(this,_bHidden); }
	bool IsIgnoringRangedAbilities() const { return FIsIgnoringRangedAbilities(this); }
	void SetIsIgnoringRangedAbilities(bool _bIsIgnoringRangedAbilities) { FSetIsIgnoringRangedAbilities(this,_bIsIgnoringRangedAbilities); }
	void SetAnimTag(const char *const _pTagName, bool _bTagEnabled) { FSetAnimTag(this,_pTagName,_bTagEnabled); }
	void SetTransitionStateTag(const char *const _pTagName) { FSetTransitionStateTag(this,_pTagName); }
	bool PerformWanderIdle() { return FPerformWanderIdle(this); }
	bool PerformReorientation(Vec2 const &_targetDirection) { return FPerformReorientation(this,_targetDirection); }
	bool MimicEntity(IEntity const &_targetEntity, EArkNpcMimicryReason _reason, bool _bIgnorePsi) { return FMimicEntity(this,_targetEntity,_reason,_bIgnorePsi); }
	bool MimicAndReplaceEntity(IEntity &_targetEntity, EArkNpcMimicryReason _reason) { return FMimicAndReplaceEntity(this,_targetEntity,_reason); }
	bool EndMimicry() { return FEndMimicry(this); }
	bool LockMimicry() { return FLockMimicry(this); }
	bool UnlockMimicry() { return FUnlockMimicry(this); }
	void MakePoltergeistAppear() { FMakePoltergeistAppear(this); }
	void MakePoltergeistDisapear() { FMakePoltergeistDisapear(this); }
	bool IsVisible() const { return FIsVisible(this); }
	void InitLiftVolumeManager() { FInitLiftVolumeManager(this); }
	void StartXRayVisionOn(unsigned _targetId, float _xRayTime) { FStartXRayVisionOn(this,_targetId,_xRayTime); }
	bool IsXRayTrackingTarget(unsigned _targetId) const { return FIsXRayTrackingTarget(this,_targetId); }
	void StopXRayVisionOn(unsigned _targetId) { FStopXRayVisionOn(this,_targetId); }
	bool IsPerformingAbility() const { return FIsPerformingAbility(this); }
	bool CanPerformAnimatedAbility() const { return FCanPerformAnimatedAbility(this); }
	bool PerformAnimatedAbility(_smart_ptr<ArkNpcAnimAction> const &_pAnimAction, ArkNpcBodyStateObserver_Animated &_observer) { return FPerformAnimatedAbility(this,_pAnimAction,_observer); }
	bool CanPerformUnanimatedAbility() const { return FCanPerformUnanimatedAbility(this); }
	bool PerformUnanimatedAbility(ArkNpcBodyStateObserver_Busy &_observer) { return FPerformUnanimatedAbility(this,_observer); }
	bool InterruptUnanimatedAbility() { return FInterruptUnanimatedAbility(this); }
	bool CanPerformHitReactShift() const { return FCanPerformHitReactShift(this); }
	bool PerformHitReactShift(ArkNpcBodyStateObserver_Busy &_observer) { return FPerformHitReactShift(this,_observer); }
	bool InterruptHitReactShift() { return FInterruptHitReactShift(this); }
	bool InterruptAbility() { return FInterruptAbility(this); }
	bool IsDissipating() const { return FIsDissipating(this); }
	bool Dissipate(ArkNpcBodyStateObserver_Dissipate &_observer) { return FDissipate(this,_observer); }
	bool BeginAnimatedDistraction(_smart_ptr<ArkNpcAnimAction> const &_pAnimAction, ArkNpcBodyStateObserver_Animated &_observer) { return FBeginAnimatedDistraction(this,_pAnimAction,_observer); }
	bool EndAnimatedDistraction() { return FEndAnimatedDistraction(this); }
	void PerformScan() { FPerformScan(this); }
	void DoCorruptExplode(uint64_t _damagePackageId, Vec3 const &_damageSourcePos, float _damageRadius, float _damageImpulse, float _damageMinimumDistanceScaleAmount, uint64_t _cameraShakeId) { FDoCorruptExplode(this,_damagePackageId,_damageSourcePos,_damageRadius,_damageImpulse,_damageMinimumDistanceScaleAmount,_cameraShakeId); }
	bool PerformPatrolIdle(ArkNpcBodyStateObserver_Animated &_observer) { return FPerformPatrolIdle(this,_observer); }
	void PerformMindControlled() { FPerformMindControlled(this); }
	bool IsMindControlled() const { return FIsMindControlled(this); }
	void PerformStopMindControlled() { FPerformStopMindControlled(this); }
	bool IsFeared() const { return FIsFeared(this); }
	bool FindNearestValidPoint(Vec3 const &_position, float _horizontalSearchRadius, float _downSearchRadius, float _upSearchRadius, Vec3 &_nearestPoint) const { return FFindNearestValidPoint(this,_position,_horizontalSearchRadius,_downSearchRadius,_upSearchRadius,_nearestPoint); }
	bool FindNearestReachablePoint(Vec3 const &_position, float _horizontalSearchRadius, float _downSearchRadius, float _upSearchRadius, Vec3 &_nearestPoint) const { return FFindNearestReachablePoint(this,_position,_horizontalSearchRadius,_downSearchRadius,_upSearchRadius,_nearestPoint); }
	bool IsDead() const { return FIsDead(this); }
	bool IsBroken() const { return FIsBroken(this); }
	void BecomeBroken() { FBecomeBroken(this); }
	bool IsDestroyed() const { return FIsDestroyed(this); }
	bool IsPermanentlyStunned() const { return FIsPermanentlyStunned(this); }
	bool IsMimic() const { return FIsMimic(this); }
	bool IsMimicking() const { return FIsMimicking(this); }
	unsigned GetMimicingEntityId() const { return FGetMimicingEntityId(this); }
	EArkNpcMimicryReason GetMimicryReason() const { return FGetMimicryReason(this); }
	bool CanSpeak() const { return FCanSpeak(this); }
	void Hack() { FHack(this); }
	bool IsHacked() const { return FIsHacked(this); }
	bool IsUnconscious() const { return FIsUnconscious(this); }
	void MakeUnconscious() { FMakeUnconscious(this); }
	void MakeConscious() { FMakeConscious(this); }
	void CorruptNpc(ArkNpc &_npc, bool _bPlayCorruptAnim) { FCorruptNpc(this,_npc,_bPlayCorruptAnim); }
	bool Corrupt(bool _bPlayCorruptAnim, unsigned _corruptionOwner) { return FCorrupt(this,_bPlayCorruptAnim,_corruptionOwner); }
	void UnCorrupt(bool _bOnOwnerDeath) { FUnCorrupt(this,_bOnOwnerDeath); }
	void OnUnCorrupted() { FOnUnCorrupted(this); }
	void NotifyCorruptedOwnerOfUncorruption() { FNotifyCorruptedOwnerOfUncorruption(this); }
	bool IsCorrupted() const { return FIsCorrupted(this); }
	int GetNumCorruptedNpcs() const { return FGetNumCorruptedNpcs(this); }
	bool CanRaiseAnotherPhantom() { return FCanRaiseAnotherPhantom(this); }
	void RemoveHead() { FRemoveHead(this); }
	bool HasHead() const { return FHasHead(this); }
	unsigned GetDefaultFaction() const { return FGetDefaultFaction(this); }
	void PushEnabledAmbientSound(EArkNpcAmbientSoundId _soundId) { FPushEnabledAmbientSound(this,_soundId); }
	void PopEnabledAmbientSound(EArkNpcAmbientSoundId _soundId) { FPopEnabledAmbientSound(this,_soundId); }
	void BeginUndamagedAudio() const { FBeginUndamagedAudio(this); }
	void BeginDamagedAudio() const { FBeginDamagedAudio(this); }
	void BeginDisabledAudio() const { FBeginDisabledAudio(this); }
	void PushEnableAiTree() { FPushEnableAiTree(this); }
	void PopEnableAiTree() { FPopEnableAiTree(this); }
	void PushDisableAiTree() { FPushDisableAiTree(this); }
	void PopDisableAiTree() { FPopDisableAiTree(this); }
	void FlowGraphDisableAi(bool _bValue) { FFlowGraphDisableAi(this,_bValue); }
	void QueueStimulus_CallForHelp(IEntity const &_callerEntity, IEntity const &_targetEntity) { FQueueStimulus_CallForHelp(this,_callerEntity,_targetEntity); }
	void QueueStimulus_Diagnose() { FQueueStimulus_Diagnose(this); }
	void QueueStimulus_Escape() { FQueueStimulus_Escape(this); }
	void QueueStimulus_FrightfulNoise(IEntity const &_noisemakerEntity, Vec3 const &_noisePosition, float _noiseMagnitude) { FQueueStimulus_FrightfulNoise(this,_noisemakerEntity,_noisePosition,_noiseMagnitude); }
	void QueueStimulus_MovementEvent(ArkAiTreeInstanceNode const &_instanceNode, EArkNpcMovementDesireCallbackEvent _event) { FQueueStimulus_MovementEvent(this,_instanceNode,_event); }
	bool ShouldBecomeRigidOnGloo() const { return FShouldBecomeRigidOnGloo(this); }
	void PushForceRigidOnGloo() { FPushForceRigidOnGloo(this); }
	void PopForceRigidOnGloo() { FPopForceRigidOnGloo(this); }
	void ChangeAiTree(const char *const _pAiTreePath) { FChangeAiTree(this,_pAiTreePath); }
	void ClearAttentionOnPlayer() { FClearAttentionOnPlayer(this); }
	void ClearAllAttention() { FClearAllAttention(this); }
	bool IsAttentionProxyFollowing(const unsigned _proxyTargetId) const { return FIsAttentionProxyFollowing(this,_proxyTargetId); }
	void LockKnownAttentionOnTarget(const unsigned _targetId) { FLockKnownAttentionOnTarget(this,_targetId); }
	void PushAttentionDrainLockOnTarget(unsigned _targetId) { FPushAttentionDrainLockOnTarget(this,_targetId); }
	void PopAttentionDrainLockOnTarget(unsigned _targetId) { FPopAttentionDrainLockOnTarget(this,_targetId); }
	void PushDumbed() { FPushDumbed(this); }
	void PopDumbed() { FPopDumbed(this); }
	void FlowGraphSetDumbed(bool _bValue) { FFlowGraphSetDumbed(this,_bValue); }
	void SetIsPlayerControlled() { FSetIsPlayerControlled(this); }
	bool IsPlayerControlled() const { return FIsPlayerControlled(this); }
	void StartRaiseFromCorpse(bool _bPlayLookAroundAnim) { FStartRaiseFromCorpse(this,_bPlayLookAroundAnim); }
	void InterruptRaiseFromCorpse() { FInterruptRaiseFromCorpse(this); }
	void FinishRaiseFromCorpse() { FFinishRaiseFromCorpse(this); }
	void StartRaisePhantomCast() { FStartRaisePhantomCast(this); }
	void SetWanderAreaContainerEntity(const unsigned _roomContainerId) { FSetWanderAreaContainerEntity(this,_roomContainerId); }
	void RequestDistraction(unsigned _distractionEntityId, uint64_t _distractionInstanceIndex) { FRequestDistraction(this,_distractionEntityId,_distractionInstanceIndex); }
	bool CanBeDistracted() const { return FCanBeDistracted(this); }
	void FlowGraphIgnoreDistractions(bool _bIgnore, bool _bForceStopCurrent) { FFlowGraphIgnoreDistractions(this,_bIgnore,_bForceStopCurrent); }
	void ForceStopDistraction() { FForceStopDistraction(this); }
	bool IsWithinCameraViewCone(float _coneAngleRadians) const { return FIsWithinCameraViewCone(this,_coneAngleRadians); }
	void StartPsiSuppressed() { FStartPsiSuppressed(this); }
	void EndPsiSuppressed() { FEndPsiSuppressed(this); }
	bool IsPsiSuppressed() const { return FIsPsiSuppressed(this); }
	void OnCallMimicsReceived(unsigned _callerId) { FOnCallMimicsReceived(this,_callerId); }
	void OnCallNpcsReceived(unsigned _callerId) { FOnCallNpcsReceived(this,_callerId); }
	void OnCallNpcsEnded() { FOnCallNpcsEnded(this); }
	void OnCallNpcsCallerDead(unsigned _deadCallerId) { FOnCallNpcsCallerDead(this,_deadCallerId); }
	void StartAttackJitter() { FStartAttackJitter(this); }
	void StartAttackGlow() { FStartAttackGlow(this); }
	void PlayMimicHitEffect() { FPlayMimicHitEffect(this); }
	void StartOnFireEffect() { FStartOnFireEffect(this); }
	void StopOnFireEffect() { FStopOnFireEffect(this); }
	bool StartCowering() { return FStartCowering(this); }
	bool StopCowering() { return FStopCowering(this); }
	void StartGlooEffects(bool _bSkipSlow) { FStartGlooEffects(this,_bSkipSlow); }
	void IncreaseGloo(float _amount) { FIncreaseGloo(this,_amount); }
	void StopGlooEffects() { FStopGlooEffects(this); }
	void OnGlooFrozen() { FOnGlooFrozen(this); }
	void OnGlooBroken() { FOnGlooBroken(this); }
	bool IsGoingToFreezeInGloo() const { return FIsGoingToFreezeInGloo(this); }
	void PerformPassiveGlooBreak() { FPerformPassiveGlooBreak(this); }
	bool PerformPostSerializeGloodPose(int _optionIndex) { return FPerformPostSerializeGloodPose(this,_optionIndex); }
	ArkGlooEffectAccumulated *GetGlooEffect() const { return FGetGlooEffect(this); }
	bool CanAttachGloo() const { return FCanAttachGloo(this); }
	void BreakNearbyGloo() const { FBreakNearbyGloo(this); }
	bool CanInstigate() const { return FCanInstigate(this); }
	void StartInstantDeath() { FStartInstantDeath(this); }
	void StartEnergizedDeath() { FStartEnergizedDeath(this); }
	void OnEnergizedExplosion() { FOnEnergizedExplosion(this); }
	float GetEnergizedAmount() const { return FGetEnergizedAmount(this); }
	void LightOnFire() { FLightOnFire(this); }
	void ForceDesperationMimicryInPlace() { FForceDesperationMimicryInPlace(this); }
	void PushEnableGlassBreaking() { FPushEnableGlassBreaking(this); }
	void PopEnableGlassBreaking() { FPopEnableGlassBreaking(this); }
	void OnStartConversation() { FOnStartConversation(this); }
	void OnStopConversation() { FOnStopConversation(this); }
	void SetConversationLookTarget(unsigned _targetEntityId, bool _bHeadOnly) { FSetConversationLookTarget(this,_targetEntityId,_bHeadOnly); }
	void ClearConversationLookTarget() { FClearConversationLookTarget(this); }
	void SetConversationFacingTarget(unsigned _targetEntityId) { FSetConversationFacingTarget(this,_targetEntityId); }
	void ClearConversationFacingTarget() { FClearConversationFacingTarget(this); }
	void ActivateWander() { FActivateWander(this); }
	void DeactivateWander() { FDeactivateWander(this); }
	void SetWanderFollowEntityId(unsigned _wanderFollow) { FSetWanderFollowEntityId(this,_wanderFollow); }
	bool IsFollowingPlayer() const { return FIsFollowingPlayer(this); }
	void FollowLeaderEntity(unsigned _leaderId) { FFollowLeaderEntity(this,_leaderId); }
	void OnLeaderDamaged(unsigned _damageInstigator) { FOnLeaderDamaged(this,_damageInstigator); }
	bool HasPerformedNotice() { return FHasPerformedNotice(this); }
	void SetHasPerformedNotice(bool _bHasPerformedNotice) { FSetHasPerformedNotice(this,_bHasPerformedNotice); }
	int GetAmmoCount() const { return FGetAmmoCount(this); }
	bool HasMaxAmmo() const { return FHasMaxAmmo(this); }
	bool OutOfAmmo() const { return FOutOfAmmo(this); }
	void ReloadAmmo() { FReloadAmmo(this); }
	void RemoveAmmoAmount(unsigned _amountToRemove) { FRemoveAmmoAmount(this,_amountToRemove); }
	void SetShouldSkipNextCombatReaction(bool _bShouldSkipNextCombatReact) { FSetShouldSkipNextCombatReaction(this,_bShouldSkipNextCombatReact); }
	static bool IsEntityMimicable(IEntity const &_entity) { return FIsEntityMimicable(_entity); }
	static void InitMimicableClasses() { FInitMimicableClasses(); }
	bool GetIsShuttingDown_Hack() const { return FGetIsShuttingDown_Hack(this); }
	bool OnGravShaftEnter() { return FOnGravShaftEnter(this); }
	void OnGravShaftExit(bool _bFailed) { FOnGravShaftExit(this,_bFailed); }
	bool IsPsiLifted() const { return FIsPsiLifted(this); }
	void OnPsiLiftedBegin() { FOnPsiLiftedBegin(this); }
	void OnPsiLiftedEnd() { FOnPsiLiftedEnd(this); }
	void SetIsRegainingLoSPrereqFlag(bool _bPrereqIsRegainingLoS) { FSetIsRegainingLoSPrereqFlag(this,_bPrereqIsRegainingLoS); }
	bool GetIsRegainingLosPrereqFlag() const { return FGetIsRegainingLosPrereqFlag(this); }
	bool GetIsTakingDamagePrereqFlag() const { return FGetIsTakingDamagePrereqFlag(this); }
	void SetIsHitReactingPrereqFlag(bool _bPrereqIsHitReacting) { FSetIsHitReactingPrereqFlag(this,_bPrereqIsHitReacting); }
	bool GetIsHitReactingPrereqFlag() const { return FGetIsHitReactingPrereqFlag(this); }
	CTimeValue GetHitReactStaggerTimeStamp() const { return FGetHitReactStaggerTimeStamp(this); }
	CTimeValue GetHitReactKnockDownTimeStamp() const { return FGetHitReactKnockDownTimeStamp(this); }
	CTimeValue GetDodgeTimeStamp() const { return FGetDodgeTimeStamp(this); }
	void SetHypnotizeStartTimeStamp() { FSetHypnotizeStartTimeStamp(this); }
	bool CanBeHypnotized() const { return FCanBeHypnotized(this); }
	void OnDealtDamage(unsigned _damagedEntityId) { FOnDealtDamage(this,_damagedEntityId); }
	void OnTargetStartedMimicry(unsigned _targetId, bool _bSawMimicHappen) { FOnTargetStartedMimicry(this,_targetId,_bSawMimicHappen); }
	void OnTargetStoppedMimicry(unsigned _targetId) { FOnTargetStoppedMimicry(this,_targetId); }
	bool CanPerformFatality() const { return FCanPerformFatality(this); }
	bool PerformFatality(_smart_ptr<ArkNpcAnimAction> const &_pAction) { return FPerformFatality(this,_pAction); }
	bool WaitForAnimatedStunned() const { return FWaitForAnimatedStunned(this); }
	bool BeginAnimatedStunned() { return FBeginAnimatedStunned(this); }
	void EndAnimatedStunned() { FEndAnimatedStunned(this); }
	void StartStun(unsigned _instigatorId, float _duration) { FStartStun(this,_instigatorId,_duration); }
	void StopStun() { FStopStun(this); }
	bool IsStunned() const { return FIsStunned(this); }
	bool Resist(Vec3 const &_forcePosition, float _duration) { return FResist(this,_forcePosition,_duration); }
	bool IsResisting() const { return FIsResisting(this); }
	bool IsScrunched() const { return FIsScrunched(this); }
	bool NoticeTargetPosition(Vec3 const &_targetPosition, EArkAiTreeSearchReason _searchReason) { return FNoticeTargetPosition(this,_targetPosition,_searchReason); }
	bool RefreshNotice(Vec3 const &_targetPosition, ArkInterval<float> const &_interruptDistance, ArkInterval<float> const &_interruptTime) { return FRefreshNotice(this,_targetPosition,_interruptDistance,_interruptTime); }
	bool GiveUpSearch() { return FGiveUpSearch(this); }
	bool BeginSearchExamine(float _minTime) { return FBeginSearchExamine(this,_minTime); }
	void EndSearchExamine() { FEndSearchExamine(this); }
	void OnSearchExamineFinished() { FOnSearchExamineFinished(this); }
	void PushEnableAbilities() { FPushEnableAbilities(this); }
	void PopEnableAbilities() { FPopEnableAbilities(this); }
	bool CanPerformAbilityContext(uint64_t _contextId) const { return FCanPerformAbilityContext(this,_contextId); }
	bool TryPerformAbilityContext(uint64_t _contextId) { return FTryPerformAbilityContextOv3(this,_contextId); }
	bool TryPerformAbilityContext(uint64_t _contextId, IEntity const &_targetEntity) { return FTryPerformAbilityContextOv2(this,_contextId,_targetEntity); }
	bool TryPerformAbilityContext(uint64_t _contextId, IEntity const &_targetEntity, IEntity const &_useEntity) { return FTryPerformAbilityContextOv1(this,_contextId,_targetEntity,_useEntity); }
	bool TryPerformAbilityContext(uint64_t _contextId, IEntity const *_pTargetEntity, IEntity const *_pUseEntity) { return FTryPerformAbilityContextOv0(this,_contextId,_pTargetEntity,_pUseEntity); }
	bool TryEvaluateAndPerformAbilityContext(uint64_t _contextId, IEntity const &_targetEntity) { return FTryEvaluateAndPerformAbilityContextOv0(this,_contextId,_targetEntity); }
	bool TryEvaluateAbilityContext(uint64_t _contextId, IEntity const &_targetEntity) { return FTryEvaluateAbilityContext(this,_contextId,_targetEntity); }
	uint64_t GetCurrentAbilityContextId() const { return FGetCurrentAbilityContextId(this); }
	uint64_t GetLastPerformedContextId() const { return FGetLastPerformedContextId(this); }
	bool IsVulnerable() const { return FIsVulnerable(this); }
	void StartOperatorArmIdle() { FStartOperatorArmIdle(this); }
	void StopOperatorArmIdle() { FStopOperatorArmIdle(this); }
	void StartCharacterEffect(ArkCharacterEffectType _effectType) { FStartCharacterEffect(this,_effectType); }
	void StopCharacterEffect(ArkCharacterEffectType _effectType) { FStopCharacterEffect(this,_effectType); }
	void ForceStopCharacterEffect(ArkCharacterEffectType _effectType) { FForceStopCharacterEffect(this,_effectType); }
	bool IsCharacterEffectEnabled(ArkCharacterEffectType _effectType) const { return FIsCharacterEffectEnabled(this,_effectType); }
	void StartMaterialAnimation(ArkMaterialAnimationType _materialAnimationType, float _blendInTime) { FStartMaterialAnimation(this,_materialAnimationType,_blendInTime); }
	bool UpdateMaterialAnimation(ArkMaterialAnimationType _materialAnimationType, float _currentTime, float _elapsedTime) { return FUpdateMaterialAnimation(this,_materialAnimationType,_currentTime,_elapsedTime); }
	float GetMaterialAnimationDuration(ArkMaterialAnimationType _materialAnimationType) const { return FGetMaterialAnimationDuration(this,_materialAnimationType); }
	ArkCharacterEffectsManager &GetCharacterEffectsManager() { return FGetCharacterEffectsManager(this); }
	ArkMaterialAnimationManager &GetMaterialAnimationManager() { return FGetMaterialAnimationManager(this); }
	void OnCombatBegin() { FOnCombatBegin(this); }
	void OnCombatEnd() { FOnCombatEnd(this); }
	void OnStartedMusicInactiveBehavior() const { FOnStartedMusicInactiveBehavior(this); }
	void OnStoppedMusicInactiveBehavior() const { FOnStoppedMusicInactiveBehavior(this); }
	bool IsInRaiseFromCorpseAnim() const { return FIsInRaiseFromCorpseAnim(this); }
	unsigned GetLeaderId() const { return FGetLeaderId(this); }
	bool IsCowering() const { return FIsCowering(this); }
	bool IsDormant() const { return FIsDormant(this); }
	void PushDisableBreakable() { FPushDisableBreakable(this); }
	void PopDisableBreakable() { FPopDisableBreakable(this); }
	bool IsBreakable() const { return FIsBreakable(this); }
	void PushEnableLifetimeEffect() { FPushEnableLifetimeEffect(this); }
	void PopEnableLifetimeEffect() { FPopEnableLifetimeEffect(this); }
	void PushDisableLifetimeEffect() { FPushDisableLifetimeEffect(this); }
	void PopDisableLifetimeEffect() { FPopDisableLifetimeEffect(this); }
	void PushEnableOperatorLevitatorsEffect() { FPushEnableOperatorLevitatorsEffect(this); }
	void PopEnableOperatorLevitatorsEffect() { FPopEnableOperatorLevitatorsEffect(this); }
	void PushDisableOperatorLevitatorsEffect() { FPushDisableOperatorLevitatorsEffect(this); }
	void PopDisableOperatorLevitatorsEffect() { FPopDisableOperatorLevitatorsEffect(this); }
	void OnRequestGuard(Vec3 const &_location, Ang3 const &_rotation, ArkDelegate<void __cdecl(void)> _flowNodeCallback) { FOnRequestGuard(this,_location,_rotation,_flowNodeCallback); }
	void OnCancelGuard() { FOnCancelGuard(this); }
	void OnGuardInPosition() { FOnGuardInPosition(this); }
	void PushEnableAttentiveSubject() { FPushEnableAttentiveSubject(this); }
	void PopEnableAttentiveSubject() { FPopEnableAttentiveSubject(this); }
	void PushEnableAttentionObject() { FPushEnableAttentionObject(this); }
	void PopEnableAttentionObject() { FPopEnableAttentionObject(this); }
	void PushEnableVision() { FPushEnableVision(this); }
	void PopEnableVision() { FPopEnableVision(this); }
	void PushEnableVisible() { FPushEnableVisible(this); }
	void PopEnableVisible() { FPopEnableVisible(this); }
	void PushEnableHearing() { FPushEnableHearing(this); }
	void PopEnableHearing() { FPopEnableHearing(this); }
	void PushEnableAudible() { FPushEnableAudible(this); }
	void PopEnableAudible() { FPopEnableAudible(this); }
	void PushEnableRoomPerceiver() { FPushEnableRoomPerceiver(this); }
	void PopEnableRoomPerceiver() { FPopEnableRoomPerceiver(this); }
	void PushDisableVision() { FPushDisableVision(this); }
	void PopDisableVision() { FPopDisableVision(this); }
	void PushDisableVisible() { FPushDisableVisible(this); }
	void PopDisableVisible() { FPopDisableVisible(this); }
	void PushDisableHearing() { FPushDisableHearing(this); }
	void PopDisableHearing() { FPopDisableHearing(this); }
	void PushDisableAudible() { FPushDisableAudible(this); }
	void PopDisableAudible() { FPopDisableAudible(this); }
	void PushDisableAttentionAndSenses() { FPushDisableAttentionAndSenses(this); }
	void PopDisableAttentionAndSenses() { FPopDisableAttentionAndSenses(this); }
	void PushDisableSenses() { FPushDisableSenses(this); }
	void PopDisableSenses() { FPopDisableSenses(this); }
	void PushDisableAttentionObjectAndPerceivables() { FPushDisableAttentionObjectAndPerceivables(this); }
	void PopDisableAttentionObjectAndPerceivables() { FPopDisableAttentionObjectAndPerceivables(this); }
	void BecomeActive() { FBecomeActive(this); }
	void BecomeInactive() { FBecomeInactive(this); }
	void ForceDownToSearchAttentionLevel(unsigned _targetToSearchFor) { FForceDownToSearchAttentionLevel(this,_targetToSearchFor); }
	void SetComplexHearingGain(float _gain) { FSetComplexHearingGain(this,_gain); }
	float GetComplexHearingGain() const { return FGetComplexHearingGain(this); }
	void SetComplexVisionGain(float _gain) { FSetComplexVisionGain(this,_gain); }
	float GetComplexVisionGain() const { return FGetComplexVisionGain(this); }
	void SetSpawnedState(boost::variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant> const &_spawnedState) { FSetSpawnedState(this,_spawnedState); }
	void OnScriptWakeFromDormant() { FOnScriptWakeFromDormant(this); }
	bool EndDormant() { return FEndDormant(this); }
	void OnBeginDormant(_smart_ptr<ArkNpcAnimAction> const &_animAction) { FOnBeginDormant(this,_animAction); }
	void OnEndDormant() { FOnEndDormant(this); }
	void OnSurprised(unsigned _surpriserId) { FOnSurprised(this,_surpriserId); }
	void OnScriptGoToSleep() { FOnScriptGoToSleep(this); }
	bool IsAsleep() const { return FIsAsleep(this); }
	void PlayMimicryMorphInEffect() { FPlayMimicryMorphInEffect(this); }
	void PlayMimicryMorphOutEffect() { FPlayMimicryMorphOutEffect(this); }
	void OnBreakMimicrySignal() { FOnBreakMimicrySignal(this); }
	void ResetPlayerBumpTimer() { FResetPlayerBumpTimer(this); }
	int GetNpcManagerCombatPoints() const { return FGetNpcManagerCombatPoints(this); }
	static unsigned FindDeathInstigator(HitInfo const &_hitInfo) { return FFindDeathInstigator(_hitInfo); }
	static void Precache() { FPrecache(); }
	static void ClearPrecache() { FClearPrecache(); }
	void SetCachedThrowAtLocation(Vec3 const &_throwAtLocation, EReactionThrowAtType _type) { FSetCachedThrowAtLocation(this,_throwAtLocation,_type); }
	Vec3 const &GetCachedThrowAtLocation() const { return FGetCachedThrowAtLocation(this); }
	EReactionThrowAtType GetCachedThrowAtType() const { return FGetCachedThrowAtType(this); }
	void InitializeNpc() { FInitializeNpc(this); }
	void LoadScriptVariables() { FLoadScriptVariables(this); }
	void CreateAiTree(const char *const _pTreeFileName) { FCreateAiTree(this,_pTreeFileName); }
	void DestroyAiTree() { FDestroyAiTree(this); }
	void ProcessDoneEvent(SEntityEvent &_event) { FProcessDoneEvent(this,_event); }
	void ProcessStartGameEvent(SEntityEvent &_event) { FProcessStartGameEvent(this,_event); }
	void RefreshCombatIntensity(bool _bInRange) { FRefreshCombatIntensity(this,_bInRange); }
	bool TryDodge(const float _swipeDirection) { return FTryDodge(this,_swipeDirection); }
	void UpdateFactions(unsigned _attackerId, float damage) { FUpdateFactions(this,_attackerId,damage); }
	void SpawnLootOnDeath() { FSpawnLootOnDeath(this); }
	void PushDisableAllAmbientSounds() { FPushDisableAllAmbientSounds(this); }
	void PopDisableAllAmbientSounds() { FPopDisableAllAmbientSounds(this); }
	void StartAmbientSound(EArkNpcAmbientSoundId _soundId) const { FStartAmbientSound(this,_soundId); }
	
#if 0
	bool HasInboundModifier(uint64_t arg0) const;
	bool HasNoiseStateDesire(ArkNpcNoiseStateDesire const &arg0) const;
	void PerformLurkOut();
	void OnSwitchToNewAttentionTarget(unsigned arg0, unsigned arg1, EArkAttentionLevel arg2);
	void OnAttentionLevelChanged(unsigned arg0, EArkAttentionLevel arg1, EArkAttentionLevel arg2, EArkAttentionChangeReason arg3, bool arg4, bool arg5, unsigned arg6);
	uint64_t GetCharacterId() const;
	void PushEnableCombatIntensity();
	void PopEnableCombatIntensity();
	void PushDisableCombatIntensity();
	void PopDisableCombatIntensity();
	void OnHitByFlashlight(unsigned arg0) const;
	void CallForHelp_OnAttack(unsigned arg0, Vec3 const &arg1) const;
	void CallForHelp_NewCombatAttention(unsigned arg0, Vec3 const &arg1) const;
	void OnDeathClearEffectAttachments();
	bool IsWanderActive() const;
	void FlowGraphCanCorruptNpcs(bool arg0);
	bool CanCorruptNpcs() const;
	unsigned GetEntityThatCorruptedMe() const;
	void OnTrackviewSequenceStarted(IAnimSequence &arg0, bool arg1, bool arg2, bool arg3);
	void OnTrackviewSequenceStopped(IAnimSequence &arg0);
	void AbortTrackviewSequence();
	const char *GetTrackviewSequenceName() const;
	ArkNpcFacingDesire &GetTrackviewFacingDesire();
	ArkNpcLookDesire &GetTrackviewLookDesire();
	void PopDisableDeathReactions();
	void SpawnPistol();
	void UpdateMimicGlitch(float arg0);
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> > *GetLiftVolumeManager();
	void UpdateXRayVisionTracking(float arg0);
	void ClearAllXRayVisionTracking();
	bool InterruptAnimatedAbility();
	void OnNightmareEtherFormTransform(bool arg0);
	void OnNightmareLargeFormTransform(bool arg0);
	bool IsEtherform() const;
	void LeaveEtherform();
	uint64_t GetAnimAttackPackageId() const;
	void SetAnimAttackPackageId(uint64_t arg0);
	void PerformGetCorrupted();
	bool WasUncorrupted() const;
	void AddRaisedPhantom(unsigned arg0);
	void SetCorruptedMovementDisabled(bool arg0);
	bool IsCorruptedMovementDisabled() const;
	void PushDisableAmbientSound(EArkNpcAmbientSoundId arg0);
	void PopDisableAmbientSound(EArkNpcAmbientSoundId arg0);
	void BeginCorruptedAudio() const;
	EArkAttentionLevel GetAttentionOnPlayer() const;
	float GetAttentionProxyFollowingTimer(const unsigned arg0) const;
	CArkNpcLookAroundControl &GetLookAroundControl();
	bool IsDumbed() const;
	unsigned GetWanderAreaContainerEntityId() const;
	void SetCanBeDistracted(const bool arg0);
	void SetIsDistracted(const bool arg0);
	bool IsDistracted() const;
	void SetDistractionCooldown(const float arg0);
	bool IsWithinCameraViewCone2D(float arg0) const;
	ArkRobotLight &GetRobotLight();
	bool DeflectsGloo() const;
	void SetDeflectsGloo(bool arg0);
	bool IsGlooFrozen() const;
	void OnRaisedByPlayer();
	void StopFollowingLeaderEntity();
	void SetLastSearchAnimTime();
	bool SearchAnimTimerExpired(float arg0);
	HitInfo const &GetLastDamagingHitInfo() const;
	uint64_t GetLastDamagingPackageId() const;
	ArkAiKnowledge const &GetKnowledge() const;
	static bool IsEntityClassMimicable(IEntityClass const *const arg0);
	static void ClearMimicableClasses();
	void SetIsTakingDamagePrereqFlag(bool arg0);
	bool IsHitReacting() const;
	void SetHitReactStaggerTimeStamp();
	void SetHitReactKnockDownTimeStamp();
	void SetDodgeTimeStamp();
	void ResetNotice();
	void PushDisableAbilities();
	void PopDisableAbilities();
	bool TryEvaluateAndPerformAbilityContext(uint64_t arg0);
	void SetCharacterEffectOrientation(ArkCharacterEffectType arg0, Vec3 arg1) const;
	bool IsInCombat() const;
	void PushDisableAttentiveSubject();
	void PopDisableAttentiveSubject();
	void PushDisableAttentionObject();
	void PopDisableAttentionObject();
	void PushDisableRoomPerceiver();
	void PopDisableRoomPerceiver();
	void PushDisablePerceivables();
	void PopDisablePerceivables();
	bool BeginDormant(Vec3 const &arg0, Quat const &arg1);
	ArkSimpleTimer const &GetPlayerBumpTimer() const;
	ArkCharacterEffectType UseCharacterEffect(ArkCharacterEffectType arg0) const;
	void ProcessStartLevelEvent(SEntityEvent &arg0);
	void ProcessEndLevelEvent(SEntityEvent &arg0);
	void StartHitMaterialAnimation();
	void CalcHeadDirection();
	void CalcHeadPosition();
	void StopAmbientSound(EArkNpcAmbientSoundId arg0) const;
#endif
	
	static inline auto FBitNotArkNpc = PreyFunction<void(ArkNpc *const _this)>(0x14F2A30);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkNpc const *const _this, ICrySizer *_pSizer)>(0xA13080);
	static inline auto FInit = PreyFunction<bool(ArkNpc *const _this, IGameObject *_pGameObject)>(0x14F7F20);
	static inline auto FPostInit = PreyFunction<void(ArkNpc *const _this, IGameObject *_pGameObject)>(0x1500090);
	static inline auto FInitClient = PreyFunction<void(ArkNpc *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(ArkNpc *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkNpc *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_rParams)>(0x1B933B0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkNpc *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_rParams)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkNpc *const _this, TSerialize _signature)>(0x14F7480);
	static inline auto FRelease = PreyFunction<void(ArkNpc *const _this)>(0x15028C0);
	static inline auto FFullSerialize = PreyFunction<void(ArkNpc *const _this, TSerialize _ser)>(0x14F67B0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkNpc *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t profile, int _pflags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpc *const _this)>(0x1500300);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkNpc *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkNpc *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkNpc *const _this, SEntityUpdateContext &_rCtx, int _updateSlot)>(0x1505D70);
	static inline auto FHandleEvent = PreyFunction<void(ArkNpc *const _this, SGameObjectEvent const &_event)>(0x14F7870);
	static inline auto FProcessEvent = PreyFunction<void(ArkNpc *const _this, SEntityEvent &_event)>(0x1500CF0);
	static inline auto FSetChannelId = PreyFunction<void(ArkNpc *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkNpc *const _this, bool _auth)>(0xA13080);
	static inline auto FPostUpdate = PreyFunction<void(ArkNpc *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkNpc *const _this)>(0xA13080);
	static inline auto FTestInteraction = PreyFunction<bool(ArkNpc const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x15050B0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkNpc const *const _this, IEntity const *_pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x14FFF80);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(ArkNpc const *const _this, IEntity const *_pEntity, ArkInteractionInfo &_interactionInfo)>(0x14FFFF0);
	static inline auto FHideDisplayName = PreyFunction<bool(ArkNpc const *const _this, IEntity const *const _pEntity)>(0x14F7BB0);
	static inline auto FOnStartLookingAt = PreyFunction<void(ArkNpc *const _this, unsigned _entity)>(0x14FD910);
	static inline auto FOnInteraction = PreyFunction<bool(ArkNpc *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x14FC3C0);
	static inline auto FGetProperties = PreyFunction<ArkNpcProperties const &(ArkNpc const *const _this)>(0x14F77B0);
	static inline auto FAddCollisionObserver = PreyFunction<void(ArkNpc *const _this, ArkNpcCollisionObserver &_observer)>(0x14F37A0);
	static inline auto FRemoveCollisionObserver = PreyFunction<void(ArkNpc *const _this, ArkNpcCollisionObserver &_observer)>(0x1502990);
	static inline auto FOnWrenchAttack = PreyFunction<bool(ArkNpc *const _this, const float _swipeDirection)>(0x14FE840);
	static inline auto FOnHealthChanged = PreyFunction<void(ArkNpc *const _this, float _newHealth, bool _bTakingDamage)>(0x14FBC60);
	static inline auto FRemoveInboundModifier = PreyFunction<void(ArkNpc *const _this, uint64_t _modifierId)>(0x1502B40);
	static inline auto FAddInboundModifier = PreyFunction<void(ArkNpc *const _this, uint64_t _modifierId, bool _bModifierShouldBeUnique)>(0x14F3950);
	static inline auto FAddLookDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcLookDesire &_desire)>(0x14F39C0);
	static inline auto FRemoveLookDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcLookDesire &_desire)>(0x1502B80);
	static inline auto FHasLookDesire = PreyFunction<bool(ArkNpc const *const _this, ArkNpcLookDesire const &_desire)>(0x14F7AA0);
	static inline auto FScaleLookDesireSpeed = PreyFunction<void(ArkNpc *const _this, float _scale)>(0x1503140);
	static inline auto FAddFacingDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcFacingDesire &_desire)>(0x14F3810);
	static inline auto FRemoveFacingDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcFacingDesire &_desire)>(0x15029D0);
	static inline auto FHasFacingDesire = PreyFunction<bool(ArkNpc const *const _this, ArkNpcFacingDesire const &_desire)>(0x14F7A30);
	static inline auto FAddMovementDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcMovementDesire &_desire)>(0x14F3B00);
	static inline auto FRemoveMovementDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcMovementDesire &_desire)>(0x1502C10);
	static inline auto FHasMovementDesire = PreyFunction<bool(ArkNpc const *const _this, ArkNpcMovementDesire const &_desire)>(0x14F7AC0);
	static inline auto FIsMovementDesireExecuting = PreyFunction<bool(ArkNpc const *const _this, ArkNpcMovementDesire const &_desire)>(0x14F8C20);
	static inline auto FGetDesiredSpeed = PreyFunction<EArkNpcSpeedType(ArkNpc const *const _this)>(0x14F73F0);
	static inline auto FAddSpeedDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcSpeedDesire &_desire)>(0x14F3D80);
	static inline auto FRemoveSpeedDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcSpeedDesire &_desire)>(0x1502D30);
	static inline auto FHasSpeedDesire = PreyFunction<bool(ArkNpc const *const _this, ArkNpcSpeedDesire const &_desire)>(0x14F7AF0);
	static inline auto FAddNoiseStateDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcNoiseStateDesire &_desire)>(0x14F3C40);
	static inline auto FRemoveNoiseStateDesire = PreyFunction<void(ArkNpc *const _this, ArkNpcNoiseStateDesire &_desire)>(0x1502CA0);
	static inline auto FHasMovementRequest = PreyFunction<bool(ArkNpc const *const _this)>(0x14F7AD0);
	static inline auto FGetMovementRequestId = PreyFunction<MovementRequestID(ArkNpc const *const _this)>(0x14F7630);
	static inline auto FInitializeTrackviewTempNpc = PreyFunction<void(ArkNpc *const _this)>(0x14F8340);
	static inline auto FIsMovementInterruptible = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8CE0);
	static inline auto FIsShifting = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8DC0);
	static inline auto FIsJumping = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8850);
	static inline auto FCanJump = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4C70);
	static inline auto FCancelMovement = PreyFunction<void(ArkNpc *const _this)>(0x14F5020);
	static inline auto FRequestLurk = PreyFunction<void(ArkNpc *const _this, const unsigned _lurkPointEntityId, const unsigned _lurkTargetId, const bool _bShouldMoveInstantly, const bool _bShouldMatchPointRotation)>(0x1502EA0);
	static inline auto FRequestStopLurk = PreyFunction<void(ArkNpc *const _this)>(0x1502F80);
	static inline auto FIsLurking = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8A70);
	static inline auto FBeginLurking = PreyFunction<bool(ArkNpc *const _this, ArkNpcBodyStateObserver_Animated &_observer)>(0x14F4100);
	static inline auto FEndLurking = PreyFunction<bool(ArkNpc *const _this)>(0x14F5A70);
	static inline auto FTryPerformAnyAbility = PreyFunction<bool(ArkNpc *const _this, unsigned _targetId)>(0x15056E0);
	static inline auto FIsEthericDoppelganger = PreyFunction<bool(ArkNpc const *const _this)>(0x14F86C0);
	static inline auto FGetEthericDoppelgangerOwnerId = PreyFunction<unsigned(ArkNpc const *const _this)>(0x14F74B0);
	static inline auto FHasActiveEthericDoppelganger = PreyFunction<bool(ArkNpc const *const _this)>(0x14F79F0);
	static inline auto FGetActiveEthericDoppelgangerId = PreyFunction<unsigned(ArkNpc const *const _this)>(0x14F71F0);
	static inline auto FSetTimeUntilDeath = PreyFunction<void(ArkNpc *const _this, float _timeUntilDeath)>(0x1503CD0);
	static inline auto FSetEthericDoppelgangerId = PreyFunction<void(ArkNpc *const _this, unsigned _doppelgangerId)>(0x15039E0);
	static inline auto FSetEthericDoppengangerOwnerId = PreyFunction<void(ArkNpc *const _this, unsigned _doppelgangerOwnerId)>(0x15039F0);
	static inline auto FSetIsEthericDoppelganger = PreyFunction<void(ArkNpc *const _this, bool _bIsEthericDoppelganger)>(0x1503AE0);
	static inline auto FSetStance = PreyFunction<void(ArkNpc *const _this, EStance _stance)>(0x1503C90);
	static inline auto FGetTopAttentionTargetEntityId = PreyFunction<unsigned(ArkNpc const *const _this)>(0x14F77E0);
	static inline auto FIsAlert = PreyFunction<bool(ArkNpc const *const _this)>(0x14F83E0);
	static inline auto FCanSee = PreyFunction<bool(ArkNpc const *const _this, IEntity const &_entity)>(0x14F4F40);
	static inline auto FOnAttentionProxyUpdated = PreyFunction<void(ArkNpc *const _this, unsigned _attentionObjectEntityId)>(0x14FA5E0);
	static inline auto FOnNewAttentionTarget = PreyFunction<void(ArkNpc *const _this, unsigned _targetEntityId, bool _bDelayed)>(0x14FCBF0);
	static inline auto FOnLostAttentionTarget = PreyFunction<void(ArkNpc *const _this, unsigned _targetEntityId, bool _bDelayed)>(0x14FC9C0);
	static inline auto FOnHitFloor = PreyFunction<void(ArkNpc *const _this, float _fallDistance)>(0x14FC120);
	static inline auto FOnHit = PreyFunction<void(ArkNpc *const _this, HitInfo const &_hitInfo, ArkSignalSystem::Package const *_pPackage)>(0x14FBCC0);
	static inline auto FOnZeroDamageHit = PreyFunction<void(ArkNpc *const _this, HitInfo const &_hitInfo)>(0x14FE850);
	static inline auto FOnCollisionSignal = PreyFunction<void(ArkNpc *const _this, unsigned _collisionInstigatorId)>(0x14FAC50);
	static inline auto FOnKill = PreyFunction<void(ArkNpc *const _this, bool _bPostSerializeKill)>(0x14FC520);
	static inline auto FFearAOEOnPlayerKill = PreyFunction<void(ArkNpc const *const _this, HitInfo const &_hitInfo)>(0x14F5B20);
	static inline auto FOnTargetDead = PreyFunction<void(ArkNpc *const _this, unsigned _targetEntityId)>(0x14FE390);
	static inline auto FPushIndefiniteRagdoll = PreyFunction<bool(ArkNpc *const _this)>(0x1502210);
	static inline auto FPopIndefiniteRagdoll = PreyFunction<bool(ArkNpc *const _this)>(0x14FFF70);
	static inline auto FRagdoll = PreyFunction<bool(ArkNpc *const _this, ArkInterval<float> const &_ragdollInterval)>(0x1502720);
	static inline auto FIsRagdolled = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8D90);
	static inline auto FIsStandingUp = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8DD0);
	static inline auto FOverrideCharacterId = PreyFunction<void(ArkNpc *const _this, const uint64_t _overrideId)>(0x14FE910);
	static inline auto FFlowgraphDisableCombatIntensity = PreyFunction<void(ArkNpc *const _this)>(0x14F6160);
	static inline auto FFlowgraphEnableCombatIntensity = PreyFunction<void(ArkNpc *const _this)>(0x14F61C0);
	static inline auto FCallForHelp = PreyFunction<void(ArkNpc const *const _this, unsigned _referenceEntityId, Vec3 const &_reeferencePos, uint64_t _noiseType, uint64_t _loudness)>(0x14F4940);
	static inline auto FOnReactionComplete = PreyFunction<void(ArkNpc *const _this)>(0x14FD180);
	static inline auto FOnDeathReactionComplete = PreyFunction<void(ArkNpc *const _this)>(0xA13080);
	static inline auto FOnStartFlareHypnotize = PreyFunction<void(ArkNpc *const _this, unsigned _flareEntityId)>(0x14FD760);
	static inline auto FOnStopFlareHypnotize = PreyFunction<void(ArkNpc *const _this)>(0x14FDE80);
	static inline auto FOnStartScriptMove = PreyFunction<void(ArkNpc *const _this)>(0x14FD970);
	static inline auto FOnStopScriptMove = PreyFunction<void(ArkNpc *const _this)>(0x14FDF60);
	static inline auto FHypnotize = PreyFunction<bool(ArkNpc *const _this, unsigned _flareEntityId)>(0x14F7BF0);
	static inline auto FHypnotizeInterrupted = PreyFunction<bool(ArkNpc *const _this)>(0x14F7C40);
	static inline auto FIsLureFlareValid = PreyFunction<bool(ArkNpc const *const _this, unsigned _flareEntityId)>(0x14F8860);
	static inline auto FOnWanderWaiting = PreyFunction<void(ArkNpc *const _this)>(0x14FE770);
	static inline auto FOnWanderBecomeActive = PreyFunction<void(ArkNpc *const _this)>(0x14FE750);
	static inline auto FOnWanderBecomeInactive = PreyFunction<void(ArkNpc *const _this)>(0x14FE760);
	static inline auto FOnPatrolRequestClosest = PreyFunction<void(ArkNpc *const _this, int _movementStyleSpeed, bool _bOffNavMesh)>(0x14FCF50);
	static inline auto FOnPatrolRequest = PreyFunction<bool(ArkNpc *const _this, unsigned _patrolIndex, int _pointIndex, int _movementStyleSpeed, bool _bOffNavMesh)>(0x14FCEA0);
	static inline auto FOnPatrolRequestUpdate = PreyFunction<void(ArkNpc *const _this, unsigned _patrolIndex, int _pointIndex, int _movementStyleSpeed, bool _bOffNavMesh)>(0x14FCFE0);
	static inline auto FOnPatrolCancel = PreyFunction<void(ArkNpc *const _this)>(0x14FCD70);
	static inline auto FPushAIAlwaysUpdateForPatrol = PreyFunction<void(ArkNpc *const _this)>(0x15017B0);
	static inline auto FOnPatrolBegin = PreyFunction<void(ArkNpc *const _this)>(0xA13080);
	static inline auto FOnPatrolEnd = PreyFunction<void(ArkNpc *const _this)>(0x14FCE60);
	static inline auto FOnCorruptNpcRequest = PreyFunction<void(ArkNpc *const _this, const unsigned _entityIdToCorrupt, bool _bFromCombat)>(0x14FAD10);
	static inline auto FOnEnteredTrackviewBodyState = PreyFunction<void(ArkNpc *const _this)>(0x14FB360);
	static inline auto FOnTrackviewStateExit = PreyFunction<void(ArkNpc *const _this)>(0x14FE670);
	static inline auto FInTrackviewSequence = PreyFunction<bool(ArkNpc const *const _this)>(0x14F7C50);
	static inline auto FSupportsLookAt = PreyFunction<bool(ArkNpc const *const _this)>(0x15050A0);
	static inline auto FOnStartedMimicking = PreyFunction<void(ArkNpc *const _this, IEntity const &_targetEntity, EArkNpcMimicryReason _reason)>(0x14FDA40);
	static inline auto FOnStoppedMimicking = PreyFunction<void(ArkNpc *const _this)>(0x14FE030);
	static inline auto FPushDisableNpcHealthUI = PreyFunction<void(ArkNpc *const _this)>(0x1501BE0);
	static inline auto FPopDisableNpcHealthUI = PreyFunction<void(ArkNpc *const _this)>(0x14FF940);
	static inline auto FIsNpcHealthUIDisabled = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8D20);
	static inline auto FPushDisableHitReactions = PreyFunction<void(ArkNpc *const _this)>(0x1501B80);
	static inline auto FPopDisableHitReactions = PreyFunction<void(ArkNpc *const _this)>(0x14FF8F0);
	static inline auto FPushDisableDeathReactions = PreyFunction<void(ArkNpc *const _this)>(0x1501B30);
	static inline auto FOnKnockdownHitReaction = PreyFunction<bool(ArkNpc *const _this, _smart_ptr<ArkNpcAnimAction> const &_pKnockdownAnim)>(0x14FC930);
	static inline auto FOnStaggerHitReaction = PreyFunction<bool(ArkNpc *const _this, _smart_ptr<ArkNpcAnimAction> const &_pStaggerAnim)>(0x14FD500);
	static inline auto FOnSmallHitReaction = PreyFunction<bool(ArkNpc *const _this, bool _bAdditive, _smart_ptr<ArkNpcAnimAction> const &_pSmallHitAnim)>(0x14FD450);
	static inline auto FOnKillHitReaction = PreyFunction<bool(ArkNpc *const _this, _smart_ptr<ArkNpcAnimAction> const &_pKillAnim)>(0x14FC8F0);
	static inline auto FOverrideHitReactAnimation = PreyFunction<bool(ArkNpc *const _this, HitInfo const &_hitInfo)>(0x14FEAA0);
	static inline auto FCanHitReact = PreyFunction<bool(ArkNpc const *const _this, HitInfo const &_hitInfo, bool _bIsBigHit)>(0x14F4B20);
	static inline auto FCanDeathReact = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4B10);
	static inline auto FShouldMimicRebound = PreyFunction<bool(ArkNpc const *const _this, IEntity const *_pHitEntity, Vec3 const &_hitNormal)>(0x15040C0);
	static inline auto FMimicCollisionRebound = PreyFunction<bool(ArkNpc *const _this, EventPhysCollision const &_collisionEvent)>(0x14F97F0);
	static inline auto FGetNumControlledTurrets = PreyFunction<int(ArkNpc const *const _this)>(0x14F7660);
	static inline auto FPushFear = PreyFunction<void(ArkNpc *const _this, unsigned _instigator, bool _bManualPop, bool _bFromAccumulator, bool _bPlayFearVFX)>(0x1502140);
	static inline auto FPopFear = PreyFunction<void(ArkNpc *const _this, bool _bFromAccumulator)>(0x14FFEE0);
	static inline auto FClearFear = PreyFunction<void(ArkNpc *const _this)>(0x14F5230);
	static inline auto FSetFearFromHostileDamage = PreyFunction<void(ArkNpc const *const _this, bool _bFleeFromDamage)>(0x1503A00);
	static inline auto FOnFearedStarted = PreyFunction<void(ArkNpc *const _this, unsigned _instigator)>(0x14FB800);
	static inline auto FOnFearedRefreshed = PreyFunction<void(ArkNpc *const _this, unsigned _instigator)>(0x14FB730);
	static inline auto FOnFearStopped = PreyFunction<void(ArkNpc *const _this)>(0x14FB620);
	static inline auto FRegisterOnFleeNodeCallsbacks = PreyFunction<void(ArkNpc *const _this, ArkDelegate<void __cdecl(void)> _fleeStartflowNodeCallback, ArkDelegate<void __cdecl(void)> _fleeEndflowNodeCallback)>(0x1502890);
	static inline auto FOnChargeTarget = PreyFunction<void(ArkNpc *const _this, unsigned _chargeTargetId)>(0x14FAB90);
	static inline auto FOnRecycled = PreyFunction<void(ArkNpc *const _this, unsigned _instigatorId)>(0x14FD190);
	static inline auto FOnCreatePhantomRequest = PreyFunction<void(ArkNpc *const _this, unsigned _corpseId, unsigned _phantomTargetId, bool _bRequestedFromCombat, ArkDelegate<void __cdecl(unsigned int,unsigned int,bool)> _flowNodeCallback, IEntityArchetype *_pPhantomArchetype, bool bIgnoreMovement, bool bIsScripted)>(0x14FAF10);
	static inline auto FOnCreatePhantomSuccess = PreyFunction<void(ArkNpc *const _this, unsigned _createdPhantomId)>(0x14FB030);
	static inline auto FOnCreatePhantomFail = PreyFunction<void(ArkNpc *const _this)>(0x14FAEC0);
	static inline auto FOnCreatePhantomCancel = PreyFunction<void(ArkNpc *const _this)>(0x14FADF0);
	static inline auto FOnAttack = PreyFunction<void(ArkNpc *const _this, unsigned _targetId)>(0x14F9D80);
	static inline auto FOnUsePower = PreyFunction<void(ArkNpc *const _this)>(0x14FE730);
	static inline auto FCorruptedMovementGlitch = PreyFunction<void(ArkNpc *const _this)>(0x14F53F0);
	static inline auto FForceMovementReplan = PreyFunction<void(ArkNpc *const _this)>(0x14F6690);
	static inline auto FForceReevaluateMovementAnimAction = PreyFunction<void(ArkNpc *const _this)>(0x14F66A0);
	static inline auto FGetCurrentCombatRole = PreyFunction<EArkCombatRole(ArkNpc const *const _this)>(0x14F7340);
	static inline auto FSetCurrentCombatRole = PreyFunction<void(ArkNpc *const _this, EArkCombatRole _newRole)>(0x1503900);
	static inline auto FOnDesiredRoleChanged = PreyFunction<void(ArkNpc *const _this, EArkCombatRole _newDesiredRole)>(0x14FB160);
	static inline auto FPerformCombatReaction = PreyFunction<bool(ArkNpc *const _this)>(0x14FEB10);
	static inline auto FCanMimicSideStepRight = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4D60);
	static inline auto FCanMimicSideStepLeft = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4D50);
	static inline auto FCalcHasSpaceToMimicSideStep = PreyFunction<bool(ArkNpc const *const _this, Vec2 _directionToTarget, float _traceDistance, float _traceHeightBias, float _traceRadius)>(0x14F4750);
	static inline auto FGetHeadDirection = PreyFunction<Vec3(ArkNpc const *const _this)>(0x14F7530);
	static inline auto FGetHeadPosition = PreyFunction<Vec3(ArkNpc const *const _this)>(0x14F7550);
	static inline auto FGetAttachedPistolId = PreyFunction<unsigned(ArkNpc const *const _this)>(0x14F7210);
	static inline auto FAttachPistol = PreyFunction<void(ArkNpc *const _this)>(0x14F3EC0);
	static inline auto FSetPistolHidden = PreyFunction<void(ArkNpc const *const _this, bool _bHidden)>(0x1503B90);
	static inline auto FIsIgnoringRangedAbilities = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8830);
	static inline auto FSetIsIgnoringRangedAbilities = PreyFunction<void(ArkNpc *const _this, bool _bIsIgnoringRangedAbilities)>(0x1503B00);
	static inline auto FOnAnimatedMovement_Start = PreyFunction<void(ArkNpc *const _this)>(0x14F9D60);
	static inline auto FOnAnimatedMovement_Stop = PreyFunction<void(ArkNpc *const _this)>(0x14F9D70);
	static inline auto FIsMovementAnimated = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8C10);
	static inline auto FOnJumpAnimActionSequence_Start = PreyFunction<void(ArkNpc *const _this)>(0x14FC430);
	static inline auto FOnJumpAnimActionSequence_Stop = PreyFunction<void(ArkNpc *const _this)>(0x14FC4A0);
	static inline auto FOnJumpAnimAction_Fall = PreyFunction<void(ArkNpc *const _this)>(0x14FC510);
	static inline auto FOnMantleAnimAction_Start = PreyFunction<void(ArkNpc *const _this)>(0x14FCBD0);
	static inline auto FOnMantleAnimAction_Stop = PreyFunction<void(ArkNpc *const _this)>(0x14FCBE0);
	static inline auto FShiftTelegraph = PreyFunction<void(ArkNpc *const _this, MovementStyle::ShiftType _shiftType)>(0x1504010);
	static inline auto FShiftBegin = PreyFunction<void(ArkNpc *const _this, MovementStyle::ShiftType _shiftType)>(0x1503ED0);
	static inline auto FShiftEnd = PreyFunction<void(ArkNpc *const _this, MovementStyle::ShiftType _shiftType)>(0x1503F90);
	static inline auto FSetAnimTag = PreyFunction<void(ArkNpc *const _this, const char *const _pTagName, bool _bTagEnabled)>(0x15034D0);
	static inline auto FSetTransitionStateTag = PreyFunction<void(ArkNpc *const _this, const char *const _pTagName)>(0x1503CE0);
	static inline auto FPerformWanderIdle = PreyFunction<bool(ArkNpc *const _this)>(0x14FF2B0);
	static inline auto FPerformReorientation = PreyFunction<bool(ArkNpc *const _this, Vec2 const &_targetDirection)>(0x14FEE40);
	static inline auto FPerformMimicReorientation = PreyFunction<bool(ArkNpc *const _this, Vec2 const &_targetDirection)>(0x14FEC20);
	static inline auto FPerformMimicGlitch = PreyFunction<void(ArkNpc *const _this)>(0x14FEBA0);
	static inline auto FStopMimicGlitch = PreyFunction<void(ArkNpc *const _this)>(0x1504F30);
	static inline auto FMimicEntity = PreyFunction<bool(ArkNpc *const _this, IEntity const &_targetEntity, EArkNpcMimicryReason _reason, bool _bIgnorePsi)>(0x14F9B90);
	static inline auto FMimicAndReplaceEntity = PreyFunction<bool(ArkNpc *const _this, IEntity &_targetEntity, EArkNpcMimicryReason _reason)>(0x14F97E0);
	static inline auto FEndMimicry = PreyFunction<bool(ArkNpc *const _this)>(0x14F5AB0);
	static inline auto FLockMimicry = PreyFunction<bool(ArkNpc *const _this)>(0x14F96E0);
	static inline auto FUnlockMimicry = PreyFunction<bool(ArkNpc *const _this)>(0x15057D0);
	static inline auto FMakePoltergeistAppear = PreyFunction<void(ArkNpc *const _this)>(0x14F9700);
	static inline auto FMakePoltergeistDisapear = PreyFunction<void(ArkNpc *const _this)>(0x14F9770);
	static inline auto FIsVisible = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8E00);
	static inline auto FInitLiftVolumeManager = PreyFunction<void(ArkNpc *const _this)>(0x14F7FC0);
	static inline auto FStartXRayVisionOn = PreyFunction<void(ArkNpc *const _this, unsigned _targetId, float _xRayTime)>(0x1504D30);
	static inline auto FIsXRayTrackingTarget = PreyFunction<bool(ArkNpc const *const _this, unsigned _targetId)>(0x14F9030);
	static inline auto FStopXRayVisionOn = PreyFunction<void(ArkNpc *const _this, unsigned _targetId)>(0x1504FF0);
	static inline auto FIsPerformingAbility = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8D30);
	static inline auto FCanPerformAnimatedAbility = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4E00);
	static inline auto FPerformAnimatedAbility = PreyFunction<bool(ArkNpc *const _this, _smart_ptr<ArkNpcAnimAction> const &_pAnimAction, ArkNpcBodyStateObserver_Animated &_observer)>(0x14FEB00);
	static inline auto FCanPerformUnanimatedAbility = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4E30);
	static inline auto FPerformUnanimatedAbility = PreyFunction<bool(ArkNpc *const _this, ArkNpcBodyStateObserver_Busy &_observer)>(0x14FF2A0);
	static inline auto FInterruptUnanimatedAbility = PreyFunction<bool(ArkNpc *const _this)>(0x14F83D0);
	static inline auto FCanPerformHitReactShift = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4E20);
	static inline auto FPerformHitReactShift = PreyFunction<bool(ArkNpc *const _this, ArkNpcBodyStateObserver_Busy &_observer)>(0x14FEB90);
	static inline auto FInterruptHitReactShift = PreyFunction<bool(ArkNpc *const _this)>(0x14F83B0);
	static inline auto FInterruptAbility = PreyFunction<bool(ArkNpc *const _this)>(0x14F8360);
	static inline auto FIsDissipating = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8520);
	static inline auto FDissipate = PreyFunction<bool(ArkNpc *const _this, ArkNpcBodyStateObserver_Dissipate &_observer)>(0x14F58C0);
	static inline auto FBeginAnimatedDistraction = PreyFunction<bool(ArkNpc *const _this, _smart_ptr<ArkNpcAnimAction> const &_pAnimAction, ArkNpcBodyStateObserver_Animated &_observer)>(0x14F40C0);
	static inline auto FEndAnimatedDistraction = PreyFunction<bool(ArkNpc *const _this)>(0x14F5A10);
	static inline auto FPerformScan = PreyFunction<void(ArkNpc *const _this)>(0x14FF280);
	static inline auto FDoCorruptExplode = PreyFunction<void(ArkNpc *const _this, uint64_t _damagePackageId, Vec3 const &_damageSourcePos, float _damageRadius, float _damageImpulse, float _damageMinimumDistanceScaleAmount, uint64_t _cameraShakeId)>(0x14F58D0);
	static inline auto FPerformPatrolIdle = PreyFunction<bool(ArkNpc *const _this, ArkNpcBodyStateObserver_Animated &_observer)>(0x14FEE20);
	static inline auto FPerformMindControlled = PreyFunction<void(ArkNpc *const _this)>(0x14FED40);
	static inline auto FIsMindControlled = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8BA0);
	static inline auto FPerformStopMindControlled = PreyFunction<void(ArkNpc *const _this)>(0x14FF290);
	static inline auto FIsFeared = PreyFunction<bool(ArkNpc const *const _this)>(0x14F86E0);
	static inline auto FFindNearestValidPoint = PreyFunction<bool(ArkNpc const *const _this, Vec3 const &_position, float _horizontalSearchRadius, float _downSearchRadius, float _upSearchRadius, Vec3 &_nearestPoint)>(0x14F5EA0);
	static inline auto FFindNearestReachablePoint = PreyFunction<bool(ArkNpc const *const _this, Vec3 const &_position, float _horizontalSearchRadius, float _downSearchRadius, float _upSearchRadius, Vec3 &_nearestPoint)>(0x14F5DF0);
	static inline auto FIsDead = PreyFunction<bool(ArkNpc const *const _this)>(0x14F84E0);
	static inline auto FIsBroken = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8490);
	static inline auto FBecomeBroken = PreyFunction<void(ArkNpc *const _this)>(0x14F4070);
	static inline auto FIsDestroyed = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8510);
	static inline auto FIsPermanentlyStunned = PreyFunction<bool(ArkNpc const *const _this)>(0xDD23F0);
	static inline auto FIsMimic = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8A80);
	static inline auto FIsMimicking = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8B90);
	static inline auto FGetMimicingEntityId = PreyFunction<unsigned(ArkNpc const *const _this)>(0x14F7610);
	static inline auto FGetMimicryReason = PreyFunction<EArkNpcMimicryReason(ArkNpc const *const _this)>(0x14F7620);
	static inline auto FCanSpeak = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4FE0);
	static inline auto FHack = PreyFunction<void(ArkNpc *const _this)>(0x14F7800);
	static inline auto FIsHacked = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8810);
	static inline auto FIsUnconscious = PreyFunction<bool(ArkNpc const *const _this)>(0x14F83F0);
	static inline auto FMakeUnconscious = PreyFunction<void(ArkNpc *const _this)>(0x14FD340);
	static inline auto FMakeConscious = PreyFunction<void(ArkNpc *const _this)>(0x14F96F0);
	static inline auto FCorruptNpc = PreyFunction<void(ArkNpc *const _this, ArkNpc &_npc, bool _bPlayCorruptAnim)>(0x14F5380);
	static inline auto FCorrupt = PreyFunction<bool(ArkNpc *const _this, bool _bPlayCorruptAnim, unsigned _corruptionOwner)>(0x14F52C0);
	static inline auto FUnCorrupt = PreyFunction<void(ArkNpc *const _this, bool _bOnOwnerDeath)>(0x1505780);
	static inline auto FOnUnCorrupted = PreyFunction<void(ArkNpc *const _this)>(0x14FE700);
	static inline auto FNotifyCorruptedOwnerOfUncorruption = PreyFunction<void(ArkNpc *const _this)>(0x14F9C50);
	static inline auto FIsCorrupted = PreyFunction<bool(ArkNpc const *const _this)>(0x14F84B0);
	static inline auto FGetNumCorruptedNpcs = PreyFunction<int(ArkNpc const *const _this)>(0x14F76E0);
	static inline auto FCanRaiseAnotherPhantom = PreyFunction<bool(ArkNpc *const _this)>(0x14F4E40);
	static inline auto FRemoveHead = PreyFunction<void(ArkNpc *const _this)>(0x1502A60);
	static inline auto FHasHead = PreyFunction<bool(ArkNpc const *const _this)>(0x14F7A40);
	static inline auto FGetDefaultFaction = PreyFunction<unsigned(ArkNpc const *const _this)>(0x14F7350);
	static inline auto FPushEnabledAmbientSound = PreyFunction<void(ArkNpc *const _this, EArkNpcAmbientSoundId _soundId)>(0x15020D0);
	static inline auto FPopEnabledAmbientSound = PreyFunction<void(ArkNpc *const _this, EArkNpcAmbientSoundId _soundId)>(0x14FFE50);
	static inline auto FBeginUndamagedAudio = PreyFunction<void(ArkNpc const *const _this)>(0x14F42A0);
	static inline auto FBeginDamagedAudio = PreyFunction<void(ArkNpc const *const _this)>(0x14F40E0);
	static inline auto FBeginDisabledAudio = PreyFunction<void(ArkNpc const *const _this)>(0x14F40F0);
	static inline auto FPushEnableAiTree = PreyFunction<void(ArkNpc *const _this)>(0x1501D70);
	static inline auto FPopEnableAiTree = PreyFunction<void(ArkNpc *const _this)>(0x14FFAE0);
	static inline auto FPushDisableAiTree = PreyFunction<void(ArkNpc *const _this)>(0x1501890);
	static inline auto FPopDisableAiTree = PreyFunction<void(ArkNpc *const _this)>(0x14FF5D0);
	static inline auto FFlowGraphDisableAi = PreyFunction<void(ArkNpc *const _this, bool _bValue)>(0x14F5F80);
	static inline auto FQueueStimulus_CallForHelp = PreyFunction<void(ArkNpc *const _this, IEntity const &_callerEntity, IEntity const &_targetEntity)>(0x15022E0);
	static inline auto FQueueStimulus_Diagnose = PreyFunction<void(ArkNpc *const _this)>(0x15023C0);
	static inline auto FQueueStimulus_Escape = PreyFunction<void(ArkNpc *const _this)>(0x1502490);
	static inline auto FQueueStimulus_FrightfulNoise = PreyFunction<void(ArkNpc *const _this, IEntity const &_noisemakerEntity, Vec3 const &_noisePosition, float _noiseMagnitude)>(0x1502560);
	static inline auto FQueueStimulus_MovementEvent = PreyFunction<void(ArkNpc *const _this, ArkAiTreeInstanceNode const &_instanceNode, EArkNpcMovementDesireCallbackEvent _event)>(0x1502640);
	static inline auto FShouldBecomeRigidOnGloo = PreyFunction<bool(ArkNpc const *const _this)>(0x15040B0);
	static inline auto FPushForceRigidOnGloo = PreyFunction<void(ArkNpc *const _this)>(0x1502200);
	static inline auto FPopForceRigidOnGloo = PreyFunction<void(ArkNpc *const _this)>(0x14FFF60);
	static inline auto FChangeAiTree = PreyFunction<void(ArkNpc *const _this, const char *const _pAiTreePath)>(0x14F5030);
	static inline auto FClearAttentionOnPlayer = PreyFunction<void(ArkNpc *const _this)>(0x14F5110);
	static inline auto FClearAllAttention = PreyFunction<void(ArkNpc *const _this)>(0x14F5080);
	static inline auto FIsAttentionProxyFollowing = PreyFunction<bool(ArkNpc const *const _this, const unsigned _proxyTargetId)>(0x14F8400);
	static inline auto FLockKnownAttentionOnTarget = PreyFunction<void(ArkNpc *const _this, const unsigned _targetId)>(0x14F9670);
	static inline auto FPushAttentionDrainLockOnTarget = PreyFunction<void(ArkNpc *const _this, unsigned _targetId)>(0x1501830);
	static inline auto FPopAttentionDrainLockOnTarget = PreyFunction<void(ArkNpc *const _this, unsigned _targetId)>(0x14FF560);
	static inline auto FPushDumbed = PreyFunction<void(ArkNpc *const _this)>(0x1501D40);
	static inline auto FPopDumbed = PreyFunction<void(ArkNpc *const _this)>(0x14FFAC0);
	static inline auto FFlowGraphSetDumbed = PreyFunction<void(ArkNpc *const _this, bool _bValue)>(0x14F60F0);
	static inline auto FSetIsPlayerControlled = PreyFunction<void(ArkNpc *const _this)>(0x1503B10);
	static inline auto FIsPlayerControlled = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8D50);
	static inline auto FStartRaiseFromCorpse = PreyFunction<void(ArkNpc *const _this, bool _bPlayLookAroundAnim)>(0x1504BD0);
	static inline auto FInterruptRaiseFromCorpse = PreyFunction<void(ArkNpc *const _this)>(0x14F83C0);
	static inline auto FFinishRaiseFromCorpse = PreyFunction<void(ArkNpc *const _this)>(0x14F5F50);
	static inline auto FStartRaisePhantomCast = PreyFunction<void(ArkNpc *const _this)>(0x1504C30);
	static inline auto FSetWanderAreaContainerEntity = PreyFunction<void(ArkNpc *const _this, const unsigned _roomContainerId)>(0x1503D10);
	static inline auto FRequestDistraction = PreyFunction<void(ArkNpc *const _this, unsigned _distractionEntityId, uint64_t _distractionInstanceIndex)>(0x1502DC0);
	static inline auto FCanBeDistracted = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4A40);
	static inline auto FFlowGraphIgnoreDistractions = PreyFunction<void(ArkNpc *const _this, bool _bIgnore, bool _bForceStopCurrent)>(0x14F6000);
	static inline auto FForceStopDistraction = PreyFunction<void(ArkNpc *const _this)>(0x14F66E0);
	static inline auto FIsWithinCameraViewCone = PreyFunction<bool(ArkNpc const *const _this, float _coneAngleRadians)>(0x14F8EE0);
	static inline auto FStartPsiSuppressed = PreyFunction<void(ArkNpc *const _this)>(0x1504B30);
	static inline auto FEndPsiSuppressed = PreyFunction<void(ArkNpc *const _this)>(0x14F5AC0);
	static inline auto FIsPsiSuppressed = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8D80);
	static inline auto FOnCallMimicsReceived = PreyFunction<void(ArkNpc *const _this, unsigned _callerId)>(0x14FA770);
	static inline auto FOnCallNpcsReceived = PreyFunction<void(ArkNpc *const _this, unsigned _callerId)>(0x14FA9F0);
	static inline auto FOnCallNpcsEnded = PreyFunction<void(ArkNpc *const _this)>(0x14FA920);
	static inline auto FOnCallNpcsCallerDead = PreyFunction<void(ArkNpc *const _this, unsigned _deadCallerId)>(0x14FA830);
	static inline auto FStartAttackJitter = PreyFunction<void(ArkNpc *const _this)>(0x15047C0);
	static inline auto FStartAttackGlow = PreyFunction<void(ArkNpc *const _this)>(0x15047B0);
	static inline auto FPlayMimicHitEffect = PreyFunction<void(ArkNpc *const _this)>(0x14FF2C0);
	static inline auto FStartOnFireEffect = PreyFunction<void(ArkNpc *const _this)>(0x1504AB0);
	static inline auto FStopOnFireEffect = PreyFunction<void(ArkNpc *const _this)>(0x1504F40);
	static inline auto FStartCowering = PreyFunction<bool(ArkNpc *const _this)>(0x15047E0);
	static inline auto FStopCowering = PreyFunction<bool(ArkNpc *const _this)>(0x1504E00);
	static inline auto FStartGlooEffects = PreyFunction<void(ArkNpc *const _this, bool _bSkipSlow)>(0x1504990);
	static inline auto FIncreaseGloo = PreyFunction<void(ArkNpc *const _this, float _amount)>(0x14F7E30);
	static inline auto FStopGlooEffects = PreyFunction<void(ArkNpc *const _this)>(0x1504E10);
	static inline auto FOnGlooFrozen = PreyFunction<void(ArkNpc *const _this)>(0x14FB9D0);
	static inline auto FOnGlooBroken = PreyFunction<void(ArkNpc *const _this)>(0x14FB970);
	static inline auto FIsGlooSlow = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8760);
	static inline auto FIsGoingToFreezeInGloo = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8780);
	static inline auto FPerformPassiveGlooBreak = PreyFunction<void(ArkNpc *const _this)>(0x14FEDF0);
	static inline auto FPerformPostSerializeGloodPose = PreyFunction<bool(ArkNpc *const _this, int _optionIndex)>(0x14FEE30);
	static inline auto FGetGlooEffect = PreyFunction<ArkGlooEffectAccumulated *(ArkNpc const *const _this)>(0x14F74C0);
	static inline auto FCanAttachGloo = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4A00);
	static inline auto FBreakNearbyGloo = PreyFunction<void(ArkNpc const *const _this)>(0x14F4330);
	static inline auto FSetBreakGlooEntity = PreyFunction<void(ArkNpc *const _this, unsigned _id)>(0x1503620);
	static inline auto FBreakGlooEntity = PreyFunction<void(ArkNpc *const _this)>(0x14F42B0);
	static inline auto FIsFalling = PreyFunction<bool(ArkNpc const *const _this)>(0x14F86D0);
	static inline auto FCanInstigate = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4C30);
	static inline auto FStartInstantDeath = PreyFunction<void(ArkNpc *const _this)>(0x1504A60);
	static inline auto FStartEnergizedDeath = PreyFunction<void(ArkNpc *const _this)>(0x1504820);
	static inline auto FOnEnergizedExplosion = PreyFunction<void(ArkNpc *const _this)>(0x14FB2F0);
	static inline auto FGetEnergizedAmount = PreyFunction<float(ArkNpc const *const _this)>(0x14F7410);
	static inline auto FLightOnFire = PreyFunction<void(ArkNpc *const _this)>(0x14F9060);
	static inline auto FForceDesperationMimicryInPlace = PreyFunction<void(ArkNpc *const _this)>(0x14F62B0);
	static inline auto FPushEnableGlassBreaking = PreyFunction<void(ArkNpc *const _this)>(0x1501EC0);
	static inline auto FPopEnableGlassBreaking = PreyFunction<void(ArkNpc *const _this)>(0x14FFC30);
	static inline auto FOnStartConversation = PreyFunction<void(ArkNpc *const _this)>(0x14FD570);
	static inline auto FOnStopConversation = PreyFunction<void(ArkNpc *const _this)>(0x14FDE10);
	static inline auto FSetConversationLookTarget = PreyFunction<void(ArkNpc *const _this, unsigned _targetEntityId, bool _bHeadOnly)>(0x1503780);
	static inline auto FClearConversationLookTarget = PreyFunction<void(ArkNpc *const _this)>(0x14F5210);
	static inline auto FSetConversationFacingTarget = PreyFunction<void(ArkNpc *const _this, unsigned _targetEntityId)>(0x1503670);
	static inline auto FClearConversationFacingTarget = PreyFunction<void(ArkNpc *const _this)>(0x14F51C0);
	static inline auto FActivateWander = PreyFunction<void(ArkNpc *const _this)>(0x14F36C0);
	static inline auto FDeactivateWander = PreyFunction<void(ArkNpc *const _this)>(0x14F5670);
	static inline auto FSetWanderFollowEntityId = PreyFunction<void(ArkNpc *const _this, unsigned _wanderFollow)>(0x1503E10);
	static inline auto FIsFollowingPlayer = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8750);
	static inline auto FFollowLeaderEntity = PreyFunction<void(ArkNpc *const _this, unsigned _leaderId)>(0x14F61E0);
	static inline auto FOnLeaderDamaged = PreyFunction<void(ArkNpc *const _this, unsigned _damageInstigator)>(0x14FC9A0);
	static inline auto FHasPerformedNotice = PreyFunction<bool(ArkNpc *const _this)>(0x14F7AE0);
	static inline auto FSetHasPerformedNotice = PreyFunction<void(ArkNpc *const _this, bool _bHasPerformedNotice)>(0x1503A70);
	static inline auto FGetAmmoCount = PreyFunction<int(ArkNpc const *const _this)>(0x14F7200);
	static inline auto FHasMaxAmmo = PreyFunction<bool(ArkNpc const *const _this)>(0x14F7AB0);
	static inline auto FOutOfAmmo = PreyFunction<bool(ArkNpc const *const _this)>(0x14FE900);
	static inline auto FReloadAmmo = PreyFunction<void(ArkNpc *const _this)>(0x1502970);
	static inline auto FRemoveAmmoAmount = PreyFunction<void(ArkNpc *const _this, unsigned _amountToRemove)>(0x1502980);
	static inline auto FSetShouldSkipNextCombatReaction = PreyFunction<void(ArkNpc *const _this, bool _bShouldSkipNextCombatReact)>(0x1503BD0);
	static inline auto FIsEntityMimicable = PreyFunction<bool(IEntity const &_entity)>(0x14F8540);
	static inline auto FInitMimicableClasses = PreyFunction<void()>(0x14F8050);
	static inline auto FGetIsShuttingDown_Hack = PreyFunction<bool(ArkNpc const *const _this)>(0x14F75B0);
	static inline auto FOnGravShaftEnter = PreyFunction<bool(ArkNpc *const _this)>(0x14FBAF0);
	static inline auto FOnGravShaftExit = PreyFunction<void(ArkNpc *const _this, bool _bFailed)>(0x14FBB40);
	static inline auto FIsPsiLifted = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8D70);
	static inline auto FOnPsiLiftedBegin = PreyFunction<void(ArkNpc *const _this)>(0x14FD060);
	static inline auto FOnPsiLiftedEnd = PreyFunction<void(ArkNpc *const _this)>(0x14FD070);
	static inline auto FSetIsRegainingLoSPrereqFlag = PreyFunction<void(ArkNpc *const _this, bool _bPrereqIsRegainingLoS)>(0x1503B80);
	static inline auto FGetIsRegainingLosPrereqFlag = PreyFunction<bool(ArkNpc const *const _this)>(0x14F75A0);
	static inline auto FGetIsTakingDamagePrereqFlag = PreyFunction<bool(ArkNpc const *const _this)>(0x14F75C0);
	static inline auto FSetIsHitReactingPrereqFlag = PreyFunction<void(ArkNpc *const _this, bool _bPrereqIsHitReacting)>(0x1503AF0);
	static inline auto FGetIsHitReactingPrereqFlag = PreyFunction<bool(ArkNpc const *const _this)>(0x14F7590);
	static inline auto FGetHitReactStaggerTimeStamp = PreyFunction<CTimeValue(ArkNpc const *const _this)>(0x14F7580);
	static inline auto FGetHitReactKnockDownTimeStamp = PreyFunction<CTimeValue(ArkNpc const *const _this)>(0x14F7570);
	static inline auto FGetDodgeTimeStamp = PreyFunction<CTimeValue(ArkNpc const *const _this)>(0x14F7400);
	static inline auto FSetHypnotizeStartTimeStamp = PreyFunction<void(ArkNpc *const _this)>(0x1503AB0);
	static inline auto FCanBeHypnotized = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4AC0);
	static inline auto FOnDealtDamage = PreyFunction<void(ArkNpc *const _this, unsigned _damagedEntityId)>(0x14FB0A0);
	static inline auto FOnTargetStartedMimicry = PreyFunction<void(ArkNpc *const _this, unsigned _targetId, bool _bSawMimicHappen)>(0x14FE4A0);
	static inline auto FOnTargetStoppedMimicry = PreyFunction<void(ArkNpc *const _this, unsigned _targetId)>(0x14FE5B0);
	static inline auto FCanPerformFatality = PreyFunction<bool(ArkNpc const *const _this)>(0x14F4E10);
	static inline auto FPerformFatality = PreyFunction<bool(ArkNpc *const _this, _smart_ptr<ArkNpcAnimAction> const &_pAction)>(0x14FEB80);
	static inline auto FWaitForAnimatedStunned = PreyFunction<bool(ArkNpc const *const _this)>(0x1506F60);
	static inline auto FBeginAnimatedStunned = PreyFunction<bool(ArkNpc *const _this)>(0x14F40D0);
	static inline auto FEndAnimatedStunned = PreyFunction<void(ArkNpc *const _this)>(0x14F5A20);
	static inline auto FStartStun = PreyFunction<void(ArkNpc *const _this, unsigned _instigatorId, float _duration)>(0x1504C40);
	static inline auto FStopStun = PreyFunction<void(ArkNpc *const _this)>(0x1504FA0);
	static inline auto FIsStunned = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8DE0);
	static inline auto FResist = PreyFunction<bool(ArkNpc *const _this, Vec3 const &_forcePosition, float _duration)>(0x15030C0);
	static inline auto FIsResisting = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8DA0);
	static inline auto FIsScrunched = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8DB0);
	static inline auto FNoticeTargetPosition = PreyFunction<bool(ArkNpc *const _this, Vec3 const &_targetPosition, EArkAiTreeSearchReason _searchReason)>(0x14F9BC0);
	static inline auto FRefreshNotice = PreyFunction<bool(ArkNpc *const _this, Vec3 const &_targetPosition, ArkInterval<float> const &_interruptDistance, ArkInterval<float> const &_interruptTime)>(0x1502880);
	static inline auto FGiveUpSearch = PreyFunction<bool(ArkNpc *const _this)>(0x14F77F0);
	static inline auto FBeginSearchExamine = PreyFunction<bool(ArkNpc *const _this, float _minTime)>(0x14F4150);
	static inline auto FEndSearchExamine = PreyFunction<void(ArkNpc *const _this)>(0x14F5B10);
	static inline auto FOnSearchExamineFinished = PreyFunction<void(ArkNpc *const _this)>(0x14FD380);
	static inline auto FPushEnableAbilities = PreyFunction<void(ArkNpc *const _this)>(0x1501D60);
	static inline auto FPopEnableAbilities = PreyFunction<void(ArkNpc *const _this)>(0x14FFAD0);
	static inline auto FCanPerformAbilityContext = PreyFunction<bool(ArkNpc const *const _this, uint64_t _contextId)>(0x14F4D70);
	static inline auto FTryPerformAbilityContextOv3 = PreyFunction<bool(ArkNpc *const _this, uint64_t _contextId)>(0x15056B0);
	static inline auto FTryPerformAbilityContextOv2 = PreyFunction<bool(ArkNpc *const _this, uint64_t _contextId, IEntity const &_targetEntity)>(0x15056D0);
	static inline auto FTryPerformAbilityContextOv1 = PreyFunction<bool(ArkNpc *const _this, uint64_t _contextId, IEntity const &_targetEntity, IEntity const &_useEntity)>(0x15056C0);
	static inline auto FTryPerformAbilityContextOv0 = PreyFunction<bool(ArkNpc *const _this, uint64_t _contextId, IEntity const *_pTargetEntity, IEntity const *_pUseEntity)>(0x15055B0);
	static inline auto FTryEvaluateAndPerformAbilityContextOv0 = PreyFunction<bool(ArkNpc *const _this, uint64_t _contextId, IEntity const &_targetEntity)>(0x1505510);
	static inline auto FTryEvaluateAbilityContext = PreyFunction<bool(ArkNpc *const _this, uint64_t _contextId, IEntity const &_targetEntity)>(0x1505490);
	static inline auto FGetCurrentAbilityContextId = PreyFunction<uint64_t(ArkNpc const *const _this)>(0x14F7320);
	static inline auto FGetLastPerformedContextId = PreyFunction<uint64_t(ArkNpc const *const _this)>(0x14F75D0);
	static inline auto FIsVulnerable = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8E80);
	static inline auto FStartOperatorArmIdle = PreyFunction<void(ArkNpc *const _this)>(0x1504AC0);
	static inline auto FStopOperatorArmIdle = PreyFunction<void(ArkNpc *const _this)>(0x1504F50);
	static inline auto FStartCharacterEffect = PreyFunction<void(ArkNpc *const _this, ArkCharacterEffectType _effectType)>(0x15047D0);
	static inline auto FStopCharacterEffect = PreyFunction<void(ArkNpc *const _this, ArkCharacterEffectType _effectType)>(0x1504DF0);
	static inline auto FForceStopCharacterEffect = PreyFunction<void(ArkNpc *const _this, ArkCharacterEffectType _effectType)>(0x14F66D0);
	static inline auto FIsCharacterEffectEnabled = PreyFunction<bool(ArkNpc const *const _this, ArkCharacterEffectType _effectType)>(0x14F84A0);
	static inline auto FStartMaterialAnimation = PreyFunction<void(ArkNpc *const _this, ArkMaterialAnimationType _materialAnimationType, float _blendInTime)>(0x1504AA0);
	static inline auto FUpdateMaterialAnimation = PreyFunction<bool(ArkNpc *const _this, ArkMaterialAnimationType _materialAnimationType, float _currentTime, float _elapsedTime)>(0x1506F50);
	static inline auto FGetMaterialAnimationDuration = PreyFunction<float(ArkNpc const *const _this, ArkMaterialAnimationType _materialAnimationType)>(0x14F75F0);
	static inline auto FGetCharacterEffectsManager = PreyFunction<ArkCharacterEffectsManager &(ArkNpc *const _this)>(0x14F72F0);
	static inline auto FGetMaterialAnimationManager = PreyFunction<ArkMaterialAnimationManager &(ArkNpc *const _this)>(0x14F7600);
	static inline auto FOnCombatBegin = PreyFunction<void(ArkNpc *const _this)>(0x14FAC70);
	static inline auto FOnCombatEnd = PreyFunction<void(ArkNpc *const _this)>(0x14FACA0);
	static inline auto FOnStartedMusicInactiveBehavior = PreyFunction<void(ArkNpc const *const _this)>(0x14FDD40);
	static inline auto FOnStoppedMusicInactiveBehavior = PreyFunction<void(ArkNpc const *const _this)>(0x14FE2B0);
	static inline auto FIsInRaiseFromCorpseAnim = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8840);
	static inline auto FGetLeaderId = PreyFunction<unsigned(ArkNpc const *const _this)>(0x14F75E0);
	static inline auto FIsCowering = PreyFunction<bool(ArkNpc const *const _this)>(0x14F84D0);
	static inline auto FIsDormant = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8530);
	static inline auto FPushDisableBreakable = PreyFunction<void(ArkNpc *const _this)>(0x1501B20);
	static inline auto FPopDisableBreakable = PreyFunction<void(ArkNpc *const _this)>(0x14FF8A0);
	static inline auto FIsBreakable = PreyFunction<bool(ArkNpc const *const _this)>(0x14F8470);
	static inline auto FPushEnableLifetimeEffect = PreyFunction<void(ArkNpc *const _this)>(0x1501F50);
	static inline auto FPopEnableLifetimeEffect = PreyFunction<void(ArkNpc *const _this)>(0x14FFCB0);
	static inline auto FPushDisableLifetimeEffect = PreyFunction<void(ArkNpc *const _this)>(0x1501B90);
	static inline auto FPopDisableLifetimeEffect = PreyFunction<void(ArkNpc *const _this)>(0x14FF900);
	static inline auto FPushEnableOperatorLevitatorsEffect = PreyFunction<void(ArkNpc *const _this)>(0x1501FB0);
	static inline auto FPopEnableOperatorLevitatorsEffect = PreyFunction<void(ArkNpc *const _this)>(0x14FFD10);
	static inline auto FPushDisableOperatorLevitatorsEffect = PreyFunction<void(ArkNpc *const _this)>(0x1501BF0);
	static inline auto FPopDisableOperatorLevitatorsEffect = PreyFunction<void(ArkNpc *const _this)>(0x14FF950);
	static inline auto FOnRequestGuard = PreyFunction<void(ArkNpc *const _this, Vec3 const &_location, Ang3 const &_rotation, ArkDelegate<void __cdecl(void)> _flowNodeCallback)>(0x14FD250);
	static inline auto FOnCancelGuard = PreyFunction<void(ArkNpc *const _this)>(0x14FAAB0);
	static inline auto FOnGuardInPosition = PreyFunction<void(ArkNpc *const _this)>(0x14FBC30);
	static inline auto FPushEnableAttentiveSubject = PreyFunction<void(ArkNpc *const _this)>(0x1501E40);
	static inline auto FPopEnableAttentiveSubject = PreyFunction<void(ArkNpc *const _this)>(0x14FFBB0);
	static inline auto FPushEnableAttentionObject = PreyFunction<void(ArkNpc *const _this)>(0x1501E00);
	static inline auto FPopEnableAttentionObject = PreyFunction<void(ArkNpc *const _this)>(0x14FFB70);
	static inline auto FPushEnableVision = PreyFunction<void(ArkNpc *const _this)>(0x1502090);
	static inline auto FPopEnableVision = PreyFunction<void(ArkNpc *const _this)>(0x14FFDF0);
	static inline auto FPushEnableVisible = PreyFunction<void(ArkNpc *const _this)>(0x1502050);
	static inline auto FPopEnableVisible = PreyFunction<void(ArkNpc *const _this)>(0x14FFDB0);
	static inline auto FPushEnableHearing = PreyFunction<void(ArkNpc *const _this)>(0x1501F10);
	static inline auto FPopEnableHearing = PreyFunction<void(ArkNpc *const _this)>(0x14FFC70);
	static inline auto FPushEnableAudible = PreyFunction<void(ArkNpc *const _this)>(0x1501E80);
	static inline auto FPopEnableAudible = PreyFunction<void(ArkNpc *const _this)>(0x14FFBF0);
	static inline auto FPushEnableRoomPerceiver = PreyFunction<void(ArkNpc *const _this)>(0x1502010);
	static inline auto FPopEnableRoomPerceiver = PreyFunction<void(ArkNpc *const _this)>(0x14FFD70);
	static inline auto FPushDisableVision = PreyFunction<void(ArkNpc *const _this)>(0x1501D00);
	static inline auto FPopDisableVision = PreyFunction<void(ArkNpc *const _this)>(0x14FFA80);
	static inline auto FPushDisableVisible = PreyFunction<void(ArkNpc *const _this)>(0x1501CC0);
	static inline auto FPopDisableVisible = PreyFunction<void(ArkNpc *const _this)>(0x14FFA40);
	static inline auto FPushDisableHearing = PreyFunction<void(ArkNpc *const _this)>(0x1501B40);
	static inline auto FPopDisableHearing = PreyFunction<void(ArkNpc *const _this)>(0x14FF8B0);
	static inline auto FPushDisableAudible = PreyFunction<void(ArkNpc *const _this)>(0x1501AE0);
	static inline auto FPopDisableAudible = PreyFunction<void(ArkNpc *const _this)>(0x14FF860);
	static inline auto FPushDisableAttentionAndSenses = PreyFunction<void(ArkNpc *const _this)>(0x15019C0);
	static inline auto FPopDisableAttentionAndSenses = PreyFunction<void(ArkNpc *const _this)>(0x14FF6E0);
	static inline auto FPushDisableSenses = PreyFunction<void(ArkNpc *const _this)>(0x1501C40);
	static inline auto FPopDisableSenses = PreyFunction<void(ArkNpc *const _this)>(0x14FF990);
	static inline auto FPushDisableAttentionObjectAndPerceivables = PreyFunction<void(ArkNpc *const _this)>(0x1501A60);
	static inline auto FPopDisableAttentionObjectAndPerceivables = PreyFunction<void(ArkNpc *const _this)>(0x14FF7B0);
	static inline auto FBecomeActive = PreyFunction<void(ArkNpc *const _this)>(0x14F3FE0);
	static inline auto FBecomeInactive = PreyFunction<void(ArkNpc *const _this)>(0x14F4080);
	static inline auto FForceDownToSearchAttentionLevel = PreyFunction<void(ArkNpc *const _this, unsigned _targetToSearchFor)>(0x14F64E0);
	static inline auto FSetComplexHearingGain = PreyFunction<void(ArkNpc *const _this, float _gain)>(0x1503650);
	static inline auto FGetComplexHearingGain = PreyFunction<float(ArkNpc const *const _this)>(0x14F7300);
	static inline auto FSetComplexVisionGain = PreyFunction<void(ArkNpc *const _this, float _gain)>(0x1503660);
	static inline auto FGetComplexVisionGain = PreyFunction<float(ArkNpc const *const _this)>(0x14F7310);
	static inline auto FSetSpawnedState = PreyFunction<void(ArkNpc *const _this, boost::variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant> const &_spawnedState)>(0x1503BE0);
	static inline auto FOnScriptWakeFromDormant = PreyFunction<void(ArkNpc *const _this)>(0x14FD350);
	static inline auto FEndDormant = PreyFunction<bool(ArkNpc *const _this)>(0x14F5A30);
	static inline auto FOnBeginDormant = PreyFunction<void(ArkNpc *const _this, _smart_ptr<ArkNpcAnimAction> const &_animAction)>(0x14FA6A0);
	static inline auto FOnEndDormant = PreyFunction<void(ArkNpc *const _this)>(0x14FB220);
	static inline auto FOnSurprised = PreyFunction<void(ArkNpc *const _this, unsigned _surpriserId)>(0x14FE380);
	static inline auto FOnScriptGoToSleep = PreyFunction<void(ArkNpc *const _this)>(0x14FD340);
	static inline auto FIsAsleep = PreyFunction<bool(ArkNpc const *const _this)>(0x14F83F0);
	static inline auto FPlayMimicryMorphInEffect = PreyFunction<void(ArkNpc *const _this)>(0x14FF460);
	static inline auto FPlayMimicryMorphOutEffect = PreyFunction<void(ArkNpc *const _this)>(0x14FF470);
	static inline auto FOnBreakMimicrySignal = PreyFunction<void(ArkNpc *const _this)>(0x14F5AB0);
	static inline auto FResetPlayerBumpTimer = PreyFunction<void(ArkNpc *const _this)>(0x15030B0);
	static inline auto FPushAIAlwaysUpdate = PreyFunction<void(ArkNpc *const _this)>(0x1501750);
	static inline auto FPopAIAlwaysUpdate = PreyFunction<void(ArkNpc *const _this)>(0x14FF4F0);
	static inline auto FResetAIAlwaysUpdate = PreyFunction<void(ArkNpc *const _this)>(0x1503050);
	static inline auto FGetNpcManagerCombatPoints = PreyFunction<int(ArkNpc const *const _this)>(0x14F7650);
	static inline auto FFindDeathInstigator = PreyFunction<unsigned(HitInfo const &_hitInfo)>(0x14F5D80);
	static inline auto FPrecache = PreyFunction<void()>(0x1500700);
	static inline auto FClearPrecache = PreyFunction<void()>(0x14F52A0);
	static inline auto FSetCachedThrowAtLocation = PreyFunction<void(ArkNpc *const _this, Vec3 const &_throwAtLocation, EReactionThrowAtType _type)>(0x1503630);
	static inline auto FGetCachedThrowAtLocation = PreyFunction<Vec3 const &(ArkNpc const *const _this)>(0x14F72D0);
	static inline auto FGetCachedThrowAtType = PreyFunction<EReactionThrowAtType(ArkNpc const *const _this)>(0x14F72E0);
	static inline auto FOnPsiTargetingStart = PreyFunction<void(ArkNpc *const _this, const unsigned _targetedEntity)>(0x14FD080);
	static inline auto FOnPsiTargetingStop = PreyFunction<void(ArkNpc *const _this, const unsigned _targetedEntity)>(0x14FD100);
	static inline auto FInitializeNpc = PreyFunction<void(ArkNpc *const _this)>(0x14F8290);
	static inline auto FLoadScriptVariables = PreyFunction<void(ArkNpc *const _this)>(0x14F90D0);
	static inline auto FCreateAiTree = PreyFunction<void(ArkNpc *const _this, const char *const _pTreeFileName)>(0x14F5430);
	static inline auto FDestroyAiTree = PreyFunction<void(ArkNpc *const _this)>(0x14F5750);
	static inline auto FProcessDoneEvent = PreyFunction<void(ArkNpc *const _this, SEntityEvent &_event)>(0x1500A60);
	static inline auto FProcessStartGameEvent = PreyFunction<void(ArkNpc *const _this, SEntityEvent &_event)>(0x1501430);
	static inline auto FRefreshCombatIntensity = PreyFunction<void(ArkNpc *const _this, bool _bInRange)>(0x15027F0);
	static inline auto FTryDodge = PreyFunction<bool(ArkNpc *const _this, const float _swipeDirection)>(0x1505210);
	static inline auto FUpdateFactions = PreyFunction<void(ArkNpc *const _this, unsigned _attackerId, float damage)>(0x15068B0);
	static inline auto FSpawnLootOnDeath = PreyFunction<void(ArkNpc *const _this)>(0x15041E0);
	static inline auto FPushDisableAllAmbientSounds = PreyFunction<void(ArkNpc *const _this)>(0x1501920);
	static inline auto FPopDisableAllAmbientSounds = PreyFunction<void(ArkNpc *const _this)>(0x14FF660);
	static inline auto FStartAmbientSound = PreyFunction<void(ArkNpc const *const _this, EArkNpcAmbientSoundId _soundId)>(0x15046F0);
};

static inline auto FSafeGetArkNpc = PreyFunction<ArkNpc *(IEntity const *)>(0x12AF240);
