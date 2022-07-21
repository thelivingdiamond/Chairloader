#pragma once
#include "ArkEffect.h"
#include "ArkSpatial.h"
#include "IAttachment.h"
#include "Prey/CryCore/StdAfx.h"

class ArkNpc;
class ArkRobotLight;
class ArkNpcAbility;
struct AIObjectParams;
struct ICharacterInstance;

enum class EReactionThrowAtType {
	rail = 0,
	glass = 1,
	ledge = 2,
	breakable = 3
};
enum class ELookStyle : int32_t {
	LOOKSTYLE_DEFAULT = 0,
	LOOKSTYLE_HARD = 1,
	LOOKSTYLE_HARD_NOLOWER = 2,
	LOOKSTYLE_SOFT = 3,
	LOOKSTYLE_SOFT_NOLOWER = 4,
	LOOKSTYLE_COUNT = 5
};
enum class EBodyOrientationMode : int32_t {
	FullyTowardsMovementDirection = 0,
	FullyTowardsAimOrLook = 1,
	HalfwayTowardsAimOrLook = 2
};
enum class EFallingState : int32_t {
	notFalling = 0,
	maybeFalling = 1,
	falling = 2,
	fallingOutOfGravShaft = 3
};
class HitInfo {
public:
	uint32_t shooterId;
	uint32_t targetId;
	uint32_t weaponId;
	uint32_t projectileId;
	uint32_t uniqueId;
	uint32_t groupId;
	float damage;
	float impulseScale;
	float radius;
	float angle;
	int material;
	int type;
	int bulletType;
	float damageMin;
	int partId;
	Vec3_tpl<float> pos;
	Vec3_tpl<float> dir;
	Vec3_tpl<float> normal;
	unsigned short projectileClassId;
	unsigned short weaponClassId;
	bool remote;
	bool aimed;
	bool knocksDown;
	bool knocksDownLeg;
	bool hitViaProxy;
	bool explosion;
	bool forceLocalKill;
	bool critical;
	int penetrationCount;
};

class ArkCharacterEffectsManager {
public:
	IEntity* m_pEntity;
	std::vector < CryStringT<char>> m_attachmentsByType[64];
};
class ArkNpcAttentiveSubject {
public:
	char pad[32];
	ArkNpc* m_pNpc;
	float m_complexHearingGain,
		m_complexVisionGain;
	EArkNpcVisionDirection m_visionDirection;
	char pad2[4];
};
class ArkNpcAttentionObject {
public:
	char pad[24];
	ArkNpc* m_pNpc;
};
class CArkNpcLookAroundControl {
public:
	bool m_bSuspended,
		m_bStateChange,
		m_bEnabled[2];
	float m_idleTime;
	IAction* m_pLookAroundAction;
};
class ArkNpcCollisionObserver {
public:
	char pad[32];
};

class Fatality {
	float m_vulnerabilityHealthThreshold;
};


class Corruption {
public:
	bool m_bDeletedOnLevelLoadAndUncorrupted;
	bool m_bShouldGoUnconsciousOnUncorruption;
	bool m_bStartCorrupted;
	char* m_pMovementGlitchAttachmentName1;
	char* m_pMovementGlitchAttachmentName2;
	class ArkAudioTrigger m_becomeCorruptedAudioTrigger;
	uint64_t m_corruptedGameEffectId;
	uint64_t m_uncorruptedMetaTagId;
	IParticleEffect* m_pCorruptedMovementGlitchParticleEffect;
};

class Dodge {
public:
	bool m_bEnabled;
	float m_chance;
	float m_cooldown;
	uint64_t m_damagePackageId;
};

class PoltergeistEffects {
public:
	uint64_t m_invisibilityGameEffectId;
};

class RaiseFromCorpse {
public:
	uint64_t m_raiseFromCorpseGameEffectId;
};

class Stunned {
public:
	uint64_t m_stunnedGameEffectId;
};

class Dormant {
public:
	float m_hearingGainModifier;
	uint64_t m_signalModifierId;
};

class Glooed {
public:
	uint64_t m_glooGameEffectId;
	uint64_t m_onGlooedAbilityContextId;
};

class UnreachableTargeting {
public:
	float m_defaultCombatReachabilityCheckUp;
	float m_defaultCombatReachabilityCheckDown;
	float m_defaultCombatReachabilityCheckHorizontal;
	float m_startingTraceRadius;
	float m_startingMinSearchRadius;
	float m_chanceToSearchInReverseOrder;
	float m_horizontalOffsetStanding;
	float m_standardCombatHeight;
};

class OperatorEffects {
public:
	float m_airJetToggleOffTime;
	float m_maxAirJetToggleOnTime;
	float m_minAirJetToggleOnTime;
	uint64_t m_operatorArmRetractedGameEffectId;
	IParticleEffect* m_pAirJetParticleEffect;
};

class CorruptNpc {
public:
	bool m_bReleaseCorruptionOnDeath;
};

class Mimicry {
public:
	int m_morphInSlot;
	int m_morphOutSlot;
	float m_defaultMass;
	float m_impulseMultiplier;
	float m_impulsePointHorizontalRatio;
	float m_impulsePointVerticalRatio;
	float m_startCharacterMorphOutTime;
	float m_startGeometryMorphInTime;
	float m_stopCharacterMorphInTime;
	float m_stopGeometryMorphOutTime;
	CryStringT<char> m_MorphOutBamfBoneName;
	uint64_t m_signalModifierId;
	IParticleEffect* m_pMorphInParticlefEffect;
	IParticleEffect* m_pMorphOutBamParticlefEffect;
	IParticleEffect* m_pMorphOutParticlefEffect;
	class ArkAudioTrigger m_startTickingAudioTrigger;
	class ArkAudioTrigger m_stopTickingAudioTrigger;
	class ArkAudioTrigger m_unmorphAudioTrigger;
};

class TurretWeapon {
public:
	IEntityArchetype* m_pLootAmmoLaserArchetype;
	IEntityArchetype* m_pLootAmmoStunArchetype;
};


class RaisePhantom {
public:
	bool m_bCanBeRaisedPhantom;
	int m_maxAllowedRaisedPhantoms;
};

class IParticleEffect {
public:
	void* ptr1;
	void* ptr2;
};

class ControlTurrets {
public:
	uint64_t m_controlTurretsGameEffectId;
};

class OnDeath {
public:
	float m_aoeDeathRadius;
	float m_aoeDeathSignalScale;
	uint64_t m_aoeDeathSignal;
	IParticleEffect* m_pFearAoeParticleEffect;
};

class NoiseStates {
public:
	ArkAudioTrigger m_combatStateAudioTrigger;
	ArkAudioTrigger m_idleStateAudioTrigger;
	ArkAudioTrigger m_noticeStateAudioTrigger;
	ArkAudioTrigger m_searchStateAudioTrigger;
	ArkAudioTrigger m_stareStateAudioTrigger;
};

class DamageStates {
public:
	bool m_bHasDamageStates;
	float m_healthThresholdDamage;
	float m_healthThresholdDisabled;
	float m_destroyedExplosionRadius;
	float m_destroyedExplosionImpulse;
	float m_destroyedExplosionDelay;
	float m_destroyedHeightOffset;
	float m_disabledRepeatDialogCD;
	float m_disabledFlickerDuration;
	char* m_pUndamagedAttachmentName;
	char* m_pDamagedAttachmentName;
	char* m_pDisabledAttachmentName;
	char* m_pChassisModelName;
	char* m_pChassisUndamagedAttachmentName;
	char* m_pChassisDestroyedAttachmentName;
	ArkAudioTrigger m_becomeUndamagedAudioTrigger;
	ArkAudioTrigger m_becomeDamagedAudioTrigger;
	ArkAudioTrigger m_becomeDisabledAudioTrigger;
	uint64_t m_destroyedExplosionPackageId;
	uint64_t m_destroyedExplosionCameraShakeId;
};

class CallForHelp {
public:
	uint64_t m_onAttackNoiseLoudness;
	uint64_t m_onAttackNoiseType;
	uint64_t m_onNewCombatAttentionNoiseLoudness;
	uint64_t m_onNewCombatAttentionNoiseType;
};

class Ability {
public:
	uint64_t m_abilityContextProfileId;
};

class Shift {
public:
	uint64_t m_shiftingSignalModifierId;
};

class Hack {
public:
	bool m_bStartHacked;
	uint64_t m_hackedGameEffectId;
};

class Character {
public:
	uint64_t m_characterId;
};

class HitReaction {
public:
	uint64_t m_hitReactionMaterialAnimationGameEffectId;
};

class HumanArmed {
public:
	bool m_bIsArmed;
	int m_magSize;
	char* m_pGunAttachmentName;
	IEntityArchetype* m_pLootWeaponEntityArchetype;
};

class AttentionFacing {
public:
	bool m_bUsesAttentionFacing;
	bool m_bUsesAttentionLook;
};

class Nullwave {
public:
	uint64_t m_nullwavedSignalModifierId;
};

class Sound {
public:
	NoiseStates m_noiseStates;
	ArkAudioTrigger m_deathAudioTrigger;
	ArkAudioTrigger m_startAmbientLivingAudioTrigger;
	ArkAudioTrigger m_stopAmbientLivingAudioTrigger;
};

class CombatRoleInfo {
public:
	bool m_bCanGetStaleInMeleeRole;
	bool m_bUsesCombatRoles;
	float m_meleeRoleCost;
	float m_meleeRolePreference;
	float m_meleeRoleScoreBias;
	float m_minDistanceToAllowRangeRoleSwitchSq;
};

class OnFire {
public:
	uint64_t m_onFireGameEffectId;
};

class Surprise {
public:
	uint64_t m_noiseLoudnessId;
	uint64_t m_noiseTypeId;
};

class MimicJumpAttack {
public:
	uint64_t m_mimicJumpAttackPackageId;
	IParticleEffect* m_pMimicAttackEffect;
};

class Hypnotize {
	float m_timeBetweenHypnotize;
};

class Energized {
public:
	uint64_t m_energizedGameEffectId;
};

class MimicReorient {
public:
	bool m_bSupportsReorientation;
	float m_mimicGlitchRandTimeMax;
	float m_mimicGlitchRandTimeMin;
};

class Fear {
public:
	uint64_t m_fearedGameEffectId;
	uint64_t m_fearedSignalModifierId;
};

class EntityFactionModifier {
public:
	uint64_t m_hositleToFactionId;
};

class Mannequin {
public:
	char* m_pLifetimeTag;
};

class PlayerControlled {
public:
	uint64_t m_playerControlledGameEffectId;
};

class Laser {
public:
	int m_laserHitTypeId;
	float m_beamEndJumpDistanceSq;
	float m_materialEffectCooldown;
	float m_maxLaserLength;
	float m_maxThickness;
	float m_minThickness;
	uint64_t m_laserPackageId;
	int m_customSurfaceTypeId;
	char* m_pBeamEndEffectName;
	char* m_pLaserGeometryName;
	char* m_pLaserMaterialEffectName;
	char* m_pReflectionGeometryName;
	IEntityArchetype* m_pLootAmmoLaserArchetype;
	IEntityArchetype* m_pLootAmmoStunArchetype;
};

class MindControl {
public:
	uint64_t m_mindControlGameEffectId;
};

class Audio {
public:
	char* m_pDistanceToPlayerParam;
};

class ArkNpcProperties {
public:
	Ability m_ability;
	AttentionFacing m_attentionFacing;
	Audio m_audio;
	CallForHelp m_callForHelp;
	Character m_character;
	CombatRoleInfo m_combatRoleInfo;
	ControlTurrets m_controlTurrets;
	CorruptNpc m_corruptNpc;
	Corruption m_corruption;
	DamageStates m_damageStates;
	Dodge m_dodge;
	Dormant m_dormant;
	Energized m_energized;
	EntityFactionModifier m_entityFactionModifier;
	Fatality m_fatality;
	Fear m_fear;
	Glooed m_glooed;
	Hack m_hack;
	HitReaction m_hitReaction;
	HumanArmed m_humanArmed;
	Hypnotize m_hypnotize;
	Laser m_laser;
	Mannequin m_mannequin;
	MimicJumpAttack m_mimicJumpAttack;
	MimicReorient m_mimicReorient;
	Mimicry m_mimicry;
	MindControl m_mindControl;
	Nullwave m_nullwave;
	OnDeath m_onDeath;
	OnFire m_onFire;
	OperatorEffects m_operatorEffects;
	PlayerControlled m_playerControlled;
	PoltergeistEffects m_poltergeistEffects;
	RaiseFromCorpse m_raiseFromCorpse;
	RaisePhantom m_raisePhantom;
	Shift m_shift;
	Sound m_sound;
	Stunned m_stunned;
	Surprise m_surprise;
	TurretWeapon m_turretWeapon;
	UnreachableTargeting m_unreachableTargeting;
	bool m_bCanFall;
	bool m_bCanRagdoll;
	bool m_bSupportsLookAt;
	int m_playerPowerTierTriggerThreshold;
	int m_npcManagerCombatPoints;
	float m_combatIntensityContribution;
	float m_combatIntensityRange;
	float m_fallDamagePerMeter;
	float m_fallDistanceForDamage;
	float m_fallDistanceForDialog;
	float m_fallDistanceForFallAnim;
	float m_fallDistanceForGlooBreak;
	float m_fallDistanceForLandAnim;
	float m_forceResistScrunchDistance;
	char* m_pAiTreeFilePath;
	char* m_pFaction;
	uint64_t m_fallDamagePackage;
	uint64_t m_ragdollSignalModifierId;
	EArkAttentionLevel m_abortTrackviewOnHostileAttention;
	EArkNpcVisionDirection m_visionDirection;
};
class ArkNpcSpawnedState_Alive
{
	bool m_bAlwaysUpdate = true;
};
class ArkNpcSpawnedState_Alert : ArkNpcSpawnedState_Alive {
	
};
class ArkNpcSpawnedState_Broken : ArkNpcSpawnedState_Alive
{
	const char* m_pPoseAnimName;
};
class ArkNpcSpawnedState_Dead
{
};
class ArkNpcSpawnedState_Dormant : ArkNpcSpawnedState_Alive
{
	Vec3_tpl<float> m_position;
	Quat_tpl<float> m_rotation;
};
// template<typename a, typename b, typename c, typename d> class variant {
// public:
// 	int32_t which_;
// 	a A;
// 	b B;
// 	c C;
// 	d D;
// 	std::aligned_storage<32, 8> storage_;
// };
class AkrNpcLifecycleFsm {
public:
	char pad[712];
};
class ArkNpcLifecycle {
public:
	ArkNpc* m_pNpc;
	AkrNpcLifecycleFsm m_fsm;
};
class ArkNpcBodyFsm {
public:
	char pad[6072];
};
class ArkNpcBody {
public:
	char pad[24];
	ArkNpc* m_pNpc;
	ArkNpcBodyFsm m_fsm;
	float m_jumpStartZ;
	bool m_bCanFallFromJump;
	char pad2[3];
	EFallingState m_FallingState;
	float m_fallingStartZ;
	uint64_t m_liftCount;
};
class ArkNpcDamageFsm {
public:
	char pad[56];
	bool m_bCanBeDisabled;
	bool m_bShouldInstantlyDie;
	char pad2[2];
};

class ArkNpcDesireTarget {
public:
	char pad[36];
	//
	//variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<10>,ArkNpcNoDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<9>,ArkNpcPositionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<8>,ArkNpcEntityDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<7>,ArkNpcEntityBoneDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<6>,ArkNpcEntityOffsetTargetImpl,boost::mpl::l_item<boost::mpl::long_<5>,ArkNpcEntityBoundsCenterTargetImpl,boost::mpl::l_item<boost::mpl::long_<4>,ArkNpcAttentionProxyDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<3>,ArkNpcCameraDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<2>,ArkNpcDirectionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<1>,ArkNpcAttackPositionDesireTargetImpl,boost::mpl::l_end>>>>>>>>>>>>
};
template<typename T> class ArkDelegate {
public:
	T* m_pObject;
	void* m_pCaller;
};
class LookPoseParam {
public:
	float m_torso,
		m_head,
		m_eyes,
		m_aim;
};
class ArkNpcLookDesire {
public:
	char pad[64];
	ArkNpcDesireTarget m_target;
	bool m_bUseAim,
		m_bAllowLowerBodyTurn;
	char pad2[2];
	ELookStyle m_style;
	EBodyOrientationMode m_orientMode;
	EArkNpcSpeedType m_minSpeed;
	LookPoseParam m_blendInTime,
		m_smoothTime,
		m_blendOutTime,
		m_maxAngleRadiansPitch,
		m_maxAngleRadiansYaw;
	float m_polarOffsetX,
		m_polarOffsetY;
	char pad3[4];
	ArkDelegate<void __cdecl(EArkNpcLookDesireCallbackEvent)> m_callback;
};
class ArkNpcNoiseStateDesire {
public:
	char pad[64];
	EArkNpcNoiseState m_noiseState;
	char pad2[4];
};
enum class TurnState : int32_t {
	None = 0,
	TurnLeft = 1,
	TurnRight = 2
};
class ArkNpcFacingDesire {
public:
	char pad[64];
	TurnState m_turnState;
	ArkNpcDesireTarget m_target,
		m_turnAlignTarget;
	float m_resumeAngle;
	EArkNpcSpeedType m_minSpeed;
	char pad2[4];
	ArkDelegate<void __cdecl(EArkNpcFacingDesireCallbackEvent)> m_callback;
};
enum class ShiftAnimation : int32_t {
	None = 0,
	ShiftInAndOut = 1,
	ShiftInOnly = 2,
	ShiftOutOnly = 3,
	Attack = 4
};

enum class ShiftType : int32_t {
	Normal = 0,
	Lurk = 1
};

enum class JumpStyle : int32_t {
	None = 0,
	ForwardJump = 1,
	WallJump = 2,
	AnyJump = 3
};

enum class JumpGoal : int32_t {
	FromStart = 0,
	FromStartImmediate = 1,
	ToEnd = 2,
	ToEndImmediate = 3
};

enum class HoverStyle : int32_t {
	MaintainFloorHeight = 0,
	MaintainCurrentHeight = 1,
	IgnoreHeight = 2
};
enum class FailureReason : int32_t {
	NoReason = 0,
	CouldNotFindValidStart = 1,
	CouldNotFindValidDestination = 2,
	CouldNotFindPathToRequestedDestination = 3,
	CouldNotMoveAlongDesignerDesignedPath = 4,
	FailedToProduceSuccessfulPlanAfterMaximumNumberOfAttempts = 5,
	CouldNotFindPathAroundObstacles = 6,
	FailedShift = 7,
	PathingModeForced = 8,
	FacingRestricted = 9,
	StuckOnObstacle = 10,
	StuckOnNpc = 11,
	StuckOnGloo = 12
};

enum class LightMode : int32_t {
	friendly = 0,
	hostile = 1,
	hacked = 2
};
class ArkNpcMovementDesire {
public:
	char pad[64];
	ArkNpcDesireTarget m_destination;
	bool m_bQueryNavSystem;
	char pad2[3];
	float m_navQueryHorizontalRadius,
		m_navQueryBelowThreshold,
		m_navQueryAboveThreshold;
	bool m_bForcePath,
		m_bForceGoToNavMesh;
	char pad3[2];
	int32_t m_stance;
	float m_speedLiteral,
		m_accelLiteral,
		m_decelLiteral,
		m_stopDistance,
		m_resumeDistance;
	bool m_bUseExactPosition;
	char pad4[3];
	float m_exacRotationStartDist;
	Vec3 m_exactDirection;
	bool m_bShift;
	char pad5[3];
	float m_shiftDistBefore,
		m_shiftDistAfter,
		m_shiftTelegraphTime;
	ShiftAnimation m_shiftAnims;
	ShiftType m_shiftType;
	JumpStyle m_jumpStyle;
	JumpGoal m_jumpGoal;
	float m_jumpDist,
		m_jumpGoalPathDist;
	HoverStyle m_hoverStyle;
	EArkObstacleAvoidanceUrgency m_obstacleAvoidUrgency;
	bool m_bContinueMoving,
		m_bScriptMove,
		m_bAllowTeleportToNavMesh;
	char pad6;
	FailureReason m_lastFailure;
	char pad7[4];
	ArkDelegate<void __cdecl(EArkNpcMovementDesireCallbackEvent)> m_callback;
};

class ArkNpcFacingDesireManager {
public:
	char pad[48];
};
class ArkNpcLookDesireManager {
public:
	char pad[48];
	EArkNpcSpeedType m_speed;
	LookPoseParam m_defaultBlendInTime,
		m_defaultSmoothTime,
		m_defaultBlendOutTime,
		m_defaultMaxYaw,
		m_defaultMaxPitch;
	float m_speedMultiplierFastHead,
		m_speedMultiplierFastestHead,
		m_speedMultiplierFastTorso,
		m_speedMultiplierFastestTorso,
		m_speedScale;
};
typedef uint32_t MovementRequestID;
class ArkNpcMovementDesireManager {
public:
	char pad[48];
	MovementRequestID m_movementRequestID,
		m_stopRequestId;
	ArkNpcFacingDesire m_facingDesire;
	bool m_bNeedsStop;
	bool m_bNeedsNavMeshReturn;
	char pad2[6];
};
class ArkNpcNoiseStateDesireManager {
public:
	char pad[48];
	ArkAudioTrigger m_audioTriggers[5];
	OPTIONAL EArkNpcNoiseState m_currentNoiseState;
	char pad2[4];
};

class ArkNpcSpeedDesireManager {
public:
	char pad[48];
	float m_deltaAngleRateNormal,
		m_deltaAngleRateFast,
		m_deltaAngleRateFastest;
	bool m_bSmoothedZTurning;
	char pad2[3];
};

class ArkAiKnowledge {
public:
	ArkNpc* m_npc;
};
class ArkAiTree {
public:
	char pad[8];
	ArkContiguousMemory m_nodes;
};
class ArkAiTreeNodeParent {
public:
	char pad[8];
};
class ArkAiTreeNode {
public:
	char pad[8];
	uint64_t m_traversalIndex;
	ArkAiTreeNodeParent* m_pParent;
	ArkAiTreeNode** m_ppChildrenBegin;
	ArkAiTreeNode** m_ppChildrenEnd;
};
class ArkAiTreeInstanceNodeParent {
public:
	unsigned char a;
};
class ArkAiTreeStatus {
public:
	EArkAiTreeStatusFlags m_statusFlags;
};
class ArkAiTreeInstanceNode {
public:
	char pad[8];
	ArkAiTreeInstanceNodeParent* m_pParent;
	ArkAiTreeInstanceNode** m_ppChildrenBegin;
	ArkAiTreeInstanceNode** m_ppChildrenEnd;
	ArkAiTreeStatus m_status;
};
class ArkAiTreeStimulusDelegate {
public:
	ArkAiTreeNode* m_pNode;
	ArkAiTreeInstanceNode* m_pInstanceNode;
	void* m_pCaller;
};
class ArkAiTreeInstance {
public:
	ArkContiguousMemory m_nodes;
	std::unordered_map<const ArkAiTreeNode*, std::unordered_map<const char*, ArkAiTreeStimulusDelegate, std::hash<const char*>, std::equal_to<const char*>, std::allocator<std::pair<const char* const, ArkAiTreeStimulusDelegate>>>, std::hash<const ArkAiTreeNode*>, std::equal_to<const ArkAiTreeNode*>, std::allocator<std::pair<const ArkAiTreeNode* const, std::unordered_map<const char*, ArkAiTreeStimulusDelegate, std::hash<const char*>, std::equal_to<const char*>, std::allocator<std::pair<const char* const, ArkAiTreeStimulusDelegate>>>>>> m_nodeStimulusDelegates;
};

class IAnimSequence {
public:
	char pad[16];
};
class ArkPsiLift {
public:
	Vec3 m_axis;
	Vec3 m_position;
	CryStringT<char> m_particleEffectName;
	uint32_t m_entityId,
		m_ownerid;
	int32_t m_particleEmitterSlot;
	float m_radius,
		m_height;
};
class ArkPlayerLiftEntity {
public:
	ArkSimpleTimer m_destroyGooTimer;
	float m_inwardLiftForce,
		m_upwardLiftForce;
};
class ArkPsiPowerLiftUniqueProperties {
public:
	float m_MinHeight,
		m_MaxRange,
		m_MaxRangeZeroG,
		m_Radius,
		m_Gravity,
		m_InwardLiftForce,
		m_UpwardLiftForce,
		m_LiftForceZeroG,
		m_HoverVelocityDamping,
		m_HoverVelocityFalloff,
		m_HoverFalloffDistance;
	CryStringT<char> m_ParticleEffect,
		m_TargetingParticleEffect,
		m_TargetingParticleEffectLight;
	uint64_t m_PlayerPostEffectId;
	CryStringT<char> m_PlayerEnterAudioTrigger,
		m_PlayerExitAudioTrigger;
	uint64_t m_EnterLiftSignalPackageId;
};
template<typename T> class ArkPsiLiftVolumeEntity {
public:
	T m_derived;
	uint32_t m_entityId;
};
template<typename T> class ArkPsiLiftVolume {
public:
	ArkPsiLift m_psLift;
	ArkSimpleTimer m_aliveTimer,
		m_queryTimer;
	T m_entitySpawner;
	std::vector<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>> m_containedEntities;
	float m_gravity;
};
template<typename T> class ArkPsiLiftVolumeManager {
public:
	char pad[8];
	std::vector<ArkPsiLiftVolume<T>> m_liftVolumes;

};
class ArkAirJet {
public:
	IAttachment* m_pAttachment;
	float m_toggleTimer;
};
class ArkAirJetManager {
public:
	std::vector<ArkAirJet> m_airJets;
	Vec3 m_prevForward;
	ArkInterval<float> m_airJetActiveToggleTime;
	float m_airJetOffTime;
};
class ArkDialogPlayerRobotLightExtension {
public:
	char pad[8];
	ArkRandomizedTimer m_brightnessTimer;
	char pad2[4];
	uint64_t m_lastDialogId;
	float m_minBrightness,
		m_maxBrightness;
	ArkRobotLight* m_light;
};
class ArkRobotLight {
public:
	IEntity* m_pEntity;
	uint32_t m_arkLightEntityId;
	LightMode m_lightMode;
	ArkDialogPlayerRobotLightExtension m_dialogExtension;
	ArkSimpleTimer m_lightFlickerDurationTimer,
		m_lightFlickerToggleTimer;
	float m_flickerToggleMaxTime,
		m_onBrightness;
	bool m_bActive,
		m_bGlowHidden,
		m_bEntityHidden,
		m_bIsOn,
		m_bScriptEnabled,
		m_bIsFlickering,
		m_bFlickeringForceOff,
		m_bRemoved;
};
class ArkNpcSpeedDesire {

};
class ArkNpcAnimAction {};
class ArkNpcBodyStateObserver_Animated {};
class ArkNpcBodyStateObserver_Dissipate {};
class ArkNpcBodyStateObserver_Busy {};
class ArkCharacterEffectType {};
class ArkGlooEffectAccumulated {};
class ArkNpc {
public:
	virtual void  InitializeTrackviewTempNpc() {}
	virtual void  OnAnimatedMovement_Start() {}
	virtual void  OnAnimatedMovement_Stop() {}
	virtual bool  IsMovementAnimated() {}
	virtual void  OnJumpAnimActionSequence_Start() {}
	virtual void  OnJumpAnimActionSequence_Stop() {}
	virtual void  OnJumpAnimAction_Fall() {}
	virtual void  OnMantleAnimAction_Start() {}
	virtual void  OnMantleAnimAction_Stop() {}
	virtual bool  PerformMimicReorientation(Vec2_tpl<float>* param_1) {}
	virtual void  PerformMimicGlitch() {}
	virtual void  StopMimicGlitch() {}
	virtual uint32_t  GetTopAttentionTargetEntityId() {}
	virtual void  OnTargetDead(uint32_t param_1) {}
	virtual void  ShiftTelegraph(ShiftType* param_1) {}
	virtual void  ShiftBegin(ShiftType* param_1) {}
	virtual void  ShiftEnd(ShiftType* param_1) {}
	virtual bool  SupportsLookAt() {}
	virtual bool  IsGlooSlow() {}
	virtual bool  IsFalling() {}
	virtual void  SetBreakGlooEntity(uint32_t param_1) {}
	virtual void  BreakGlooEntity() {}
	virtual void  ForceMovementReplan() {}
	virtual void  ForceReevaluateMovementAnimAction() {}
	virtual void  CancelMovement() {}
	virtual void  PushDisableHitReactions() {}
	virtual void  PopDisableHitReactions() {}
	virtual void  PushAIAlwaysUpdate() {}
	virtual void  PopAIAlwaysUpdate() {}
	virtual void  ResetAIAlwaysUpdate() {}
	virtual void  OnNewAttentionTarget(uint32_t param_1, bool param_2) {}
	class LiftEntitySpawner// Size=0x8 (Id=546837)
	{
	private:
		ArkPsiPowerLiftUniqueProperties& m_properties;// Offset=0x0 Size=0x8
	};
	enum ECryAiSystemActiveState
	{
		unknown = -1,
		inactive = 0,
		active = 1
	};
	class SetSpawnedStateVisitor : public boost::static_visitor<void>// Size=0x8 (Id=551294)
	{
	private:
		ArkNpc& m_npc;// Offset=0x0 Size=0x8
	};
	char pad[80];
	std::vector<Vec3> m_cachedDoppelgangerCandidatePositions;
	std::vector<uint32_t> m_cachedNearbyNpcsForAbility;
	Vec3 m_cachedThermogenesisLocation;
	Vec3 m_cachedEMPBlastLocation;
	Vec3 m_cachedHitReactShiftLocation;
	char pad2[4];
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
	boost::variant<ArkNpcSpawnedState_Alert, ArkNpcSpawnedState_Broken, ArkNpcSpawnedState_Dead, ArkNpcSpawnedState_Dormant> m_spawnedState;
	std::unique_ptr<ArkNpcLifecycle, std::default_delete<ArkNpcLifecycle>> m_pLifecycle;
	std::unique_ptr<ArkNpcBody, std::default_delete<ArkNpcBody>> m_pBody;
	std::unique_ptr<ArkNpcDamageFsm, std::default_delete<ArkNpcDamageFsm>> m_pDamageFsm;
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
	ECryAiSystemActiveState m_cryAISystemState;
	char pad3[4];
	ArkAiKnowledge m_aiKnowledge;
	CryStringT<char> m_aiTreeFilePath;
	std::shared_ptr<ArkAiTree> m_pAiTree;
	std::unique_ptr<ArkAiTreeInstance, std::default_delete<ArkAiTreeInstance>> m_pAiTreeInstance;
	bool m_bUpdatingForStimuli;
	bool m_bSerializedUpdatingForStimuli;
	char pad4[6];
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
	char pad5[2];
	float m_timeToDeath;
	Vec3_tpl<float> m_headPosition;
	Vec3_tpl<float> m_headDirection;
	ArkAudioRtpc m_distanceToPlayerRtpc;
	uint32_t m_wanderAreaContainerEntityId;
	bool m_bWanderDisabled;
	bool m_bCurrentlyWandering;
	bool m_bPushedAIAlwaysUpdateForPatrol;
	bool m_bCanBeDistracted;
	bool m_bIsDistracted;
	char pad6[3];
	float m_usedDistractionCooldown;
	ArkUnanimous m_breakable;
	float m_transitionStateTagTimer;
	bool m_bShouldSkipNextCombatReaction;
	bool m_bAnimatedMovement;
	bool m_bAnimatedJump;
	bool m_bIsFrozenInGloo;
	bool m_bDeflectsGloo;
	char pad7[3];
	ArkSimpleTimer m_playerBumpTimer;
	ArkSimpleTimer m_xRayVisionTimeOnPlayer;
	uint32_t m_topAttentionTargetEntityId;
	char pad8[4];
	ArkDelegate<void __cdecl(void)> m_fleeStartFlowNodeCallback;
	ArkDelegate<void __cdecl(void)> m_fleeEndFlowNodeCallback;
	ArkDelegate<void __cdecl(void)> m_guardInPositionFlowNodeCallback;
	ArkDelegate<void __cdecl(uint32_t, uint32_t, bool)> m_createPhantomFlowNodeCallback;
	bool m_bHasPerformedNotice;
	char padx[7];
	CTimeValue m_lastSearchAnimTime;
	bool m_bIsInCombat;
	bool m_bCombatIntensityIncreased;
	char pad9[2];
	enum EArkCombatRole m_currentCombatRole;
	float m_combatReactionCooldownTimer;
	HitInfo m_lastDamagingHitInfo;
	char pad10[4];
	uint64_t m_lastDamagingPackageId;
	int32_t m_lastOnHitFrameId;
	char pad11[4];
	CTimeValue m_damageAccumulationStartTime;
	float m_damageAccumulationFromPlayer;
	bool m_bIsIgnoringRangedAbilities;
	char pad12[3];
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
	char pad13[2];
	uint64_t m_animAttackPackageId;
	IAnimSequence* m_pTrackviewSequence;
	float m_mimicGlitchTimeNext;
	char pad15[4];
	ArkEntityAttachmentEffect m_mimicMorphInEffect;
	ArkEntityAttachmentEffect m_mimicMorphOutEffect;
	std::vector<uint32_t> m_raisedPhantomIds;
	uint32_t m_ethericDoppelgangerId;
	uint32_t m_ethericDoppelgangerOwnerId;
	bool m_bIsEthericDoppelganger;
	char pad16[7];
	std::unique_ptr<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<LiftEntitySpawner>>, std::default_delete<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<LiftEntitySpawner>>>> m_pLiftVolumeManager;
	uint32_t m_npcThatCorruptedMe;
	char pad17[4];
	std::vector<uint32_t> m_npcsCorrupted;
	bool m_bCorruptedMovementDisabled;
	bool m_bWasUncorrupted;
	char pad18[6];
	ArkEntityAttachmentEffect m_CorruptedMovementGlitchEffect1;
	ArkEntityAttachmentEffect m_CorruptedMovementGlitchEffect2;
	ArkAirJetManager m_operatorAirJetManager;
	ArkRobotLight m_robotLight;
	ArkFireAndForgetEffect m_aoeDeathEffect;
	Vec3_tpl<float> m_cachedThrowAtLocation;
	EReactionThrowAtType m_cachedThrowAtType; //enum
	uint32_t m_leaderEntityId;
	uint32_t m_attachedPistolEntityId;
	int32_t m_numAmmo;
	bool m_bInitiallyUpdateAi;
	bool m_bIsSerializingRead;
	bool m_bHasFullSerializeReadBeenCalled;
	bool m_bShuttingDown_Hack;
};
