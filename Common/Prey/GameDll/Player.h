// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedstring.h>
#include <Prey/CryAction/IAnimatedCharacter.h>
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryAction/IPlayerProfiles.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/GameDll/CryActor.h>
#include <Prey/GameDll/IKTorsoAim_Helper.h>
#include <Prey/GameDll/LookAim_Helper.h>
#include <Prey/GameDll/PlayerStateSwim_WaterTestProxy.h>
#include <Prey/GameDll/dualcharacterproxy.h>
#include <Prey/GameDll/state.h>
#include <_unknown/CCoherentValue.h>
#include <_unknown/CStateMachineRegistration.h>
#include <_unknown/ISerializableInfo.h>
#include <_unknown/SActorStats.h>
#include <_unknown/SAimAccelerationParams.h>
#include <_unknown/SAnimActionAIMovementSettings.h>
#include <_unknown/SFrameMovementModifiers.h>
#include <_unknown/SSpectatorInfo.h>

struct AnimEventInstance;
class CAIAnimationComponent;
class CPlayer;
class CPlayerRotation;
class CTagState;
enum EEntityAspects;
struct EventPhysCollision;
class IActionController;
struct IActor;
struct IActorMovementController;
struct IAttachment;
struct ICharacterInstance;
class ICrySizer;
struct IEntity;
struct IEntityClass;
struct IGameObject;
struct IInteractor;
struct IItem;
struct IItemParamsNode;
struct IMannequin;
struct INetAtSyncItem;
struct INetChannel;
struct IPhysicalEntity;
struct IPlayerEventListener;
struct IPlayerProfile;
struct IPlayerUpdateListener;
namespace PlayerActor::Stumble
{
struct StumbleParameters;
} // namespace PlayerActor::Stumble
struct RayCastResult;
struct SActorFrameMovementParams;
struct SActorGameParams;
struct SAnimatedCharacterParams;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
struct SGameObjectExtensionRMI;
struct SMannequinAIStateParams;
struct SMeleeHitParams;
struct SMicrowaveBeamParams;
struct SRagdollizeParams;
struct SStateEvent;
struct SViewParams;
class SmartScriptTable;
class XmlNodeRef;

// SDeferredFootstepImpulse
// Header:  Prey/GameDll/Player.h
struct SDeferredFootstepImpulse
{ // Size=16 (0x10)
	unsigned m_queuedRayId;
	Vec3 m_impulseAmount;

	~SDeferredFootstepImpulse();
	void OnRayCastDataReceived(const unsigned& rayID, const RayCastResult& result) { FOnRayCastDataReceived(this, rayID, result); }

#if 0
	SDeferredFootstepImpulse();
	void DoCollisionTest(const Vec3& _arg0_, const Vec3& _arg1_, float _arg2_, float _arg3_, IPhysicalEntity* _arg4_);
	void CancelPendingRay();
#endif

	static inline auto FBitNotSDeferredFootstepImpulse = PreyFunction<void(SDeferredFootstepImpulse* const _this)>(0x18BC640);
	static inline auto FOnRayCastDataReceived = PreyFunction<void(SDeferredFootstepImpulse* const _this, const unsigned& rayID, const RayCastResult& result)>(0x18C49A0);
};

// SNetPlayerProgression
// Header:  Prey/GameDll/Player.h
struct SNetPlayerProgression
{ // Size=16 (0x10)
	// SNetPlayerProgression::SSerVals
	// Header:  Prey/GameDll/Player.h
	struct SSerVals
	{ // Size=8 (0x8)
		uint16_t xp;
		int8_t rank;
		int8_t reincarnations;
		int8_t defaultMode;
		int8_t stealth;
		int8_t armour;
	};

	SNetPlayerProgression::SSerVals m_serVals;
	const CPlayer* m_player;

	void Serialize(TSerialize ser, EEntityAspects aspect) { FSerialize(this, ser, aspect); }

#if 0
	void Construct(CPlayer* _arg0_);
	void GetValues(int* _arg0_, int* _arg1_, int* _arg2_, int* _arg3_, int* _arg4_, int* _arg5_);
	void OwnClientConnected();
	void SetRandomValues();
	void SyncOnLocalPlayer(const bool _arg0_);
	void SetSerializedValues(int _arg0_, int _arg1_, int _arg2_, int _arg3_, int _arg4_, int _arg5_);
#endif

	static inline auto FSerialize = PreyFunction<void(SNetPlayerProgression* const _this, TSerialize ser, EEntityAspects aspect)>(0x18C8860);
};

// SPlayerRotationParams
// Header:  Prey/GameDll/Player.h
struct SPlayerRotationParams
{ // Size=504 (0x1F8)
	enum EAimType
	{
		EAimType_NORMAL = 0,
		EAimType_SNEAK = 1,
		EAimType_SLIDING = 2,
		EAimType_SPRINTING = 3,
		EAimType_SWIM = 4,
		EAimType_MOUNTED_GUN = 5,
		EAimType_ZEROG = 6,
		EAimType_TOTAL = 7,
	};

	SAimAccelerationParams m_horizontalAims[7];
	SAimAccelerationParams m_verticalAims[7];

	void ReadAimParams(const IItemParamsNode* pRootNode, const char* aimTypeName, SPlayerRotationParams::EAimType aimType) { FReadAimParams(this, pRootNode, aimTypeName, aimType); }
	void ReadAccelerationParams(const IItemParamsNode* pNode, SAimAccelerationParams* output) { FReadAccelerationParams(this, pNode, output); }

#if 0
	void Reset(const IItemParamsNode* _arg0_);
	const SAimAccelerationParams& GetHorizontalAimParams(SPlayerRotationParams::EAimType _arg0_) const;
	const SAimAccelerationParams& GetVerticalAimParams(SPlayerRotationParams::EAimType _arg0_) const;
#endif

	static inline auto FReadAimParams = PreyFunction<void(SPlayerRotationParams* const _this, const IItemParamsNode* pRootNode, const char* aimTypeName, SPlayerRotationParams::EAimType aimType)>(0x18C71E0);
	static inline auto FReadAccelerationParams = PreyFunction<void(SPlayerRotationParams* const _this, const IItemParamsNode* pNode, SAimAccelerationParams* output)>(0x18C70B0);
};

// SPlayerStats
// Header:  Prey/GameDll/Player.h
struct SPlayerStats : public SActorStats
{ // Size=184 (0xB8)
	enum ECinematicFlags
	{
		eCinematicFlag_HolsterWeapon = 1,
		eCinematicFlag_LowerWeapon = 2,
		eCinematicFlag_LowerWeaponMP = 4,
		eCinematicFlag_RestrictMovement = 8,
		eCinematicFlag_WalkOnly = 16,
	};

	enum EForceSTAP
	{
		eFS_None = 0,
		eFS_Off = 1,
		eFS_On = 2,
	};

	float flashBangStunMult;
	float flashBangStunTimer;
	float flashBangStunLength;
	float zeroVelocityForTime;
	float inMovement;
	float stuckTimeout;
	float partialCameraAnimFactor;
	float partialCameraAnimBlendRate;
	float partialCameraAnimTarget;
	float fallSpeed;
	float downwardsImpactVelocity;
	bool isThirdPerson;
	bool isInPickAndThrowMode;
	bool isScoped;
	bool bIsInSmoke;
	bool bIgnoreSprinting;
	bool bDisableTranslationPinning;
	SPlayerStats::EForceSTAP forceSTAP;
	unsigned animationControlledID;
	uint8_t cinematicFlags;
	uint8_t isAnimatedSlave;
	CCoherentValue<unsigned char> followCharacterHead;
	unsigned pickAndThrowEntity;
	unsigned prevPickAndThrowEntity;
	SSpectatorInfo spectatorInfo;
	unsigned recentKiller;
	unsigned lastAttacker;
	int killedByDamageType;
	float fInSmokeTime;

	SPlayerStats();
	void Serialize(TSerialize ser, EEntityAspects aspects) { FSerialize(this, ser, aspects); }

#if 0
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FSPlayerStatsOv2 = PreyFunction<void(SPlayerStats* const _this)>(0x18BBD60);
	static inline auto FSerialize = PreyFunction<void(SPlayerStats* const _this, TSerialize ser, EEntityAspects aspects)>(0x18C8AF0);
};

// SXPEvents
// Header:  Prey/GameDll/Player.h
struct SXPEvents
{ // Size=124 (0x7C)
	// SXPEvents::SEvent
	// Header:  Prey/GameDll/Player.h
	struct SEvent
	{ // Size=8 (0x8)
		int xpDelta;
		EXPReason xpReason;

	#if 0
		SEvent();
	#endif
	};

	SXPEvents::SEvent events[15];
	int numEvents;

	void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

#if 0
	SXPEvents();
#endif

	static inline auto FSerializeWith = PreyFunction<void(SXPEvents* const _this, TSerialize ser)>(0x18C91C0);
};

// CPlayer
// Header:  Prey/GameDll/Player.h
class CPlayer : public CCryActor, public IPlayerProfileListener
{ // Size=8128 (0x1FC0)
public:
	enum EPlayerSounds
	{
		ESound_Player_First = 0,
		ESound_Jump = 1,
		ESound_Fall_Drop = 2,
		ESound_ChargeMelee = 3,
		ESound_Breathing_UnderWater = 4,
		ESound_Gear_Walk = 5,
		ESound_Gear_Run = 6,
		ESound_Gear_Jump = 7,
		ESound_Gear_Land = 8,
		ESound_Gear_HeavyLand = 9,
		ESound_Gear_Water = 10,
		ESound_FootStep_Boot = 11,
		ESound_FootStep_Boot_Armor = 12,
		ESound_DiveIn = 13,
		ESound_DiveOut = 14,
		ESound_Underwater = 15,
		ESound_EnterMidHealth = 16,
		ESound_ExitMidHealth = 17,
		ESound_MedicalMonitorRegen = 18,
		ESound_ZeroG_Thrust_Forward = 19,
		ESound_ZeroG_Thrust_Back = 20,
		ESound_ZeroG_Thrust_Left = 21,
		ESound_ZeroG_Thrust_Right = 22,
		ESound_ZeroG_Thrust_Up = 23,
		ESound_ZeroG_Thrust_Down = 24,
		ESound_ZeroG_Thrust_Boost = 25,
		ESound_ZeroG_Breathing = 26,
		ESound_ZeroG_Ambient = 27,
		ESound_ZeroG_Rotate_Yaw = 28,
		ESound_ZeroG_Rotate_Pitch = 29,
		ESound_ZeroG_Rotate_Roll = 30,
		ESound_ZeroG_Brake = 31,
		ESound_ZeroG_Land = 32,
		ESound_ZeroG_Collision = 33,
		ESound_SneakIn = 34,
		ESound_SneakOut = 35,
		ESound_CrawlIn = 36,
		ESound_CrawlOut = 37,
		ESound_Player_Last = 38,
	};

	enum EClientSoundmoods
	{
		ESoundmood_Invalid = -1,
		ESoundmood_Alive = 0,
		ESoundmood_LowHealth = 1,
		ESoundmood_Dead = 2,
		ESoundmood_Killcam = 3,
		ESoundmood_KillcamSlow = 4,
		ESoundmood_Spectating = 5,
		ESoundmood_PreGame = 6,
		ESoundmood_PostGame = 7,
		ESoundmood_EMPBlasted = 8,
		ESoundmood_Last = 9,
	};

	enum EReactionOverlay
	{
		EReaction_None = 0,
		EReaction_SmokeEnter = 1,
		EReaction_SmokeLoop = 2,
		EReaction_SmokeExit = 3,
		EReaction_FlashEnter = 4,
		EReaction_FlashLoop = 5,
		EReaction_FlashExit = 6,
		EReaction_Total = 7,
	};

	enum EClientPostEffect
	{
		EEffect_ChromaShift = 1,
		EEffect_WaterDroplets = 2,
	};

	enum #unnamed_enum_eAF_NONE
	{
		eAF_NONE = 0,
		eAF_JUMP_QUICK = 1,
	};

	enum #unnamed_enum_eLF_NONE
	{
		eLF_NONE = 0,
		eLF_FROM_ON_GROUND = 1,
		eLF_FROM_SPRINTING = 2,
	};

	// CPlayer::EntityParams
	// Header:  Prey/GameDll/Player.h
	struct EntityParams
	{ // Size=4 (0x4)
		unsigned entityId;

	#if 0
		EntityParams();
		EntityParams(unsigned _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::TwoEntityParams
	// Header:  Prey/GameDll/Player.h
	struct TwoEntityParams
	{ // Size=8 (0x8)
		unsigned entityA_Id;
		unsigned entityB_Id;

	#if 0
		TwoEntityParams();
		TwoEntityParams(unsigned _arg0_, unsigned _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::SStealthKillRequestParams
	// Header:  Prey/GameDll/Player.h
	struct SStealthKillRequestParams
	{ // Size=8 (0x8)
		unsigned victimId;
		unsigned animIndex;

	#if 0
		SStealthKillRequestParams();
		SStealthKillRequestParams(unsigned _arg0_, unsigned _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::SRequestUseLadderParams
	// Header:  Prey/GameDll/Player.h
	struct SRequestUseLadderParams
	{ // Size=8 (0x8)
		unsigned ladderId;
		float initialHeightFrac;

	#if 0
		SRequestUseLadderParams();
		SRequestUseLadderParams(unsigned _arg0_, float _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::SRequestLeaveLadderParams
	// Header:  Prey/GameDll/Player.h
	struct SRequestLeaveLadderParams
	{ // Size=4 (0x4)
		ELadderLeaveLocation leaveLocation;

	#if 0
		SRequestLeaveLadderParams();
		SRequestLeaveLadderParams(ELadderLeaveLocation _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::SPlayerMeleeImpulseParams
	// Header:  Prey/GameDll/Player.h
	struct SPlayerMeleeImpulseParams
	{ // Size=16 (0x10)
		Vec3 dir;
		float strength;

	#if 0
		SPlayerMeleeImpulseParams();
		SPlayerMeleeImpulseParams(Vec3 _arg0_, float _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::SIntStatParams
	// Header:  Prey/GameDll/Player.h
	struct SIntStatParams
	{ // Size=4 (0x4)
		int m_stat;

	#if 0
		SIntStatParams();
		SIntStatParams(int _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::MethodInfo_SvOnXPChanged
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_SvOnXPChanged
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvOnXPChanged(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const SXPEvents& _arg0_) const;
	#endif
	};

	// CPlayer::MethodInfo_ClDelayedDetonation
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_ClDelayedDetonation
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClDelayedDetonation(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CPlayer::EntityParams& _arg0_) const;
	#endif
	};

	// CPlayer::Params_ClDelayedDetonation
	// Header:  Prey/GameDll/Player.h
	struct Params_ClDelayedDetonation
	{ // Size=4 (0x4)
		unsigned entityId;

	#if 0
		void EntityParams();
		void EntityParams(unsigned _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::MethodInfo_SvRequestMicrowaveBeam
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_SvRequestMicrowaveBeam
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestMicrowaveBeam(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const SMicrowaveBeamParams& _arg0_) const;
	#endif
	};

	// CPlayer::MethodInfo_ClDeployMicrowaveBeam
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_ClDeployMicrowaveBeam
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClDeployMicrowaveBeam(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const SMicrowaveBeamParams& _arg0_) const;
	#endif
	};

	// CPlayer::MethodInfo_ClAbortStealthKill
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_ClAbortStealthKill
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClAbortStealthKill(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CPlayer::TwoEntityParams& _arg0_) const;
	#endif
	};

	// CPlayer::Params_ClAbortStealthKill
	// Header:  Prey/GameDll/Player.h
	struct Params_ClAbortStealthKill
	{ // Size=8 (0x8)
		unsigned entityA_Id;
		unsigned entityB_Id;

	#if 0
		void TwoEntityParams();
		void TwoEntityParams(unsigned _arg0_, unsigned _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::MethodInfo_ClApplyMeleeImpulse
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_ClApplyMeleeImpulse
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClApplyMeleeImpulse(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CPlayer::SPlayerMeleeImpulseParams& _arg0_) const;
	#endif
	};

	// CPlayer::Params_ClApplyMeleeImpulse
	// Header:  Prey/GameDll/Player.h
	struct Params_ClApplyMeleeImpulse
	{ // Size=16 (0x10)
		Vec3 dir;
		float strength;

	#if 0
		void SPlayerMeleeImpulseParams();
		void SPlayerMeleeImpulseParams(Vec3 _arg0_, float _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::MethodInfo_ClIncrementIntStat
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_ClIncrementIntStat
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClIncrementIntStat(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CPlayer::SIntStatParams& _arg0_) const;
	#endif
	};

	// CPlayer::Params_ClIncrementIntStat
	// Header:  Prey/GameDll/Player.h
	struct Params_ClIncrementIntStat
	{ // Size=4 (0x4)
		int m_stat;

	#if 0
		void SIntStatParams();
		void SIntStatParams(int _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::MethodInfo_SvRequestUseLadder
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_SvRequestUseLadder
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestUseLadder(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CPlayer::SRequestUseLadderParams& _arg0_) const;
	#endif
	};

	// CPlayer::Params_SvRequestUseLadder
	// Header:  Prey/GameDll/Player.h
	struct Params_SvRequestUseLadder
	{ // Size=8 (0x8)
		unsigned ladderId;
		float initialHeightFrac;

	#if 0
		void SRequestUseLadderParams();
		void SRequestUseLadderParams(unsigned _arg0_, float _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::MethodInfo_SvRequestLeaveFromLadder
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_SvRequestLeaveFromLadder
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestLeaveFromLadder(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CPlayer::SRequestLeaveLadderParams& _arg0_) const;
	#endif
	};

	// CPlayer::Params_SvRequestLeaveFromLadder
	// Header:  Prey/GameDll/Player.h
	struct Params_SvRequestLeaveFromLadder
	{ // Size=4 (0x4)
		ELadderLeaveLocation leaveLocation;

	#if 0
		void SRequestLeaveLadderParams();
		void SRequestLeaveLadderParams(ELadderLeaveLocation _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::MethodInfo_ClLeaveFromLadder
	// Header:  Prey/GameDll/Player.h
	struct MethodInfo_ClLeaveFromLadder
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClLeaveFromLadder(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CPlayer::SRequestLeaveLadderParams& _arg0_) const;
	#endif
	};

	// CPlayer::Params_ClLeaveFromLadder
	// Header:  Prey/GameDll/Player.h
	struct Params_ClLeaveFromLadder
	{ // Size=4 (0x4)
		ELadderLeaveLocation leaveLocation;

	#if 0
		void SRequestLeaveLadderParams();
		void SRequestLeaveLadderParams(ELadderLeaveLocation _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CPlayer::SStagingParams
	// Header:  Prey/GameDll/Player.h
	struct SStagingParams
	{ // Size=28 (0x1C)
		bool bActive;
		bool bLocked;
		Vec3 vLimitDir;
		float vLimitRangeH;
		float vLimitRangeV;
		EStance stance;

		void Serialize(TSerialize ser) { FSerialize(this, ser); }

	#if 0
		SStagingParams();
	#endif

		static inline auto FSerialize = PreyFunction<void(CPlayer::SStagingParams* const _this, TSerialize ser)>(0x18C8D10);
	};

	// CPlayer::SSound
	// Header:  Prey/GameDll/Player.h
	struct SSound
	{ // Size=1 (0x1)
		bool isRepeated;

	#if 0
		SSound();
	#endif
	};

	// CPlayer::SReactionAnim
	// Header:  Prey/GameDll/Player.h
	struct SReactionAnim
	{ // Size=24 (0x18)
		const char* name;
		int flags;
		float blend;
		int animID;
	};

	using inherited = CCryActor;
	using EActionFlags = uint8_t;
	using Params_SvOnXPChanged = SXPEvents;
	using Params_SvRequestMicrowaveBeam = SMicrowaveBeamParams;
	using Params_ClDeployMicrowaveBeam = SMicrowaveBeamParams;
	using TPlayerEventListeners = std::list<IPlayerEventListener *,std::allocator<IPlayerEventListener *> >;
	using TPlayerUpdateListeners = std::list<IPlayerUpdateListener *,std::allocator<IPlayerUpdateListener *> >;
	using ELedgeFlags = uint8_t;

	static inline auto s_pStateMachineRegistrationMovement = PreyGlobal<CStateMachineRegistration<CPlayer>*>(0x2D93038);
	CStateMachine<CPlayer> m_stateMachineMovement;
	static constexpr const unsigned ASPECT_HEALTH = 32;
	static constexpr const unsigned ASPECT_PLAYERSTATS_SERVER = 512;
	static constexpr const unsigned ASPECT_SPECTATOR = 8192;
	static constexpr const unsigned ASPECT_INPUT_CLIENT = 2147483648;
	static constexpr const unsigned ASPECT_INPUT_CLIENT_AUGMENTED = 67108864;
	static constexpr const unsigned ASPECT_CURRENTLYTARGETTING_CLIENT = 1024;
	static constexpr const unsigned ASPECT_BATTLECHATTER_CLIENT = 1024;
	static constexpr const unsigned ASPECT_LEDGEGRAB_CLIENT = 4096;
	static constexpr const unsigned ASPECT_LAST_MELEE_HIT = 16384;
	static constexpr const unsigned ASPECT_JUMPING_CLIENT = 32768;
	static constexpr const unsigned ASPECT_FLASHBANG_SHOOTER_CLIENT = 131072;
	static constexpr const unsigned ASPECT_SNAP_TARGET = 262144;
	static constexpr const unsigned ASPECT_RANK_CLIENT = 1048576;
	static constexpr const unsigned ASPECT_STEALTH_KILL = 268435456;
	static constexpr const unsigned ASPECT_INTERACTIVE_OBJECT = 4194304;
	static constexpr const unsigned ASPECT_CURRENT_ITEM = 16777216;
	static constexpr const unsigned ASPECT_LADDER_SERVER = 134217728;
	static constexpr const int MAX_NETWORKED_LEDGE_COUNT = 1024;
	static constexpr const int JUMP_COUNTER_MAX = 8;
	static constexpr const ERMIAttachmentType Attach_SvOnXPChanged = 2;
	static constexpr const bool ServerCall_SvOnXPChanged = 1;
	static constexpr const ENetReliabilityType Reliability_SvOnXPChanged = 0;
	static constexpr const bool LowDelay_SvOnXPChanged = 0;
	static inline auto m_infoSvOnXPChanged = PreyGlobal<CPlayer::MethodInfo_SvOnXPChanged>(0x2D93048);
	static constexpr const ERMIAttachmentType Attach_ClDelayedDetonation = 2;
	static constexpr const bool ServerCall_ClDelayedDetonation = 0;
	static constexpr const ENetReliabilityType Reliability_ClDelayedDetonation = 1;
	static constexpr const bool LowDelay_ClDelayedDetonation = 0;
	static inline auto m_infoClDelayedDetonation = PreyGlobal<CPlayer::MethodInfo_ClDelayedDetonation>(0x2D93050);
	static constexpr const ERMIAttachmentType Attach_SvRequestMicrowaveBeam = 4;
	static constexpr const bool ServerCall_SvRequestMicrowaveBeam = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestMicrowaveBeam = 1;
	static constexpr const bool LowDelay_SvRequestMicrowaveBeam = 0;
	static inline auto m_infoSvRequestMicrowaveBeam = PreyGlobal<CPlayer::MethodInfo_SvRequestMicrowaveBeam>(0x2D93060);
	static constexpr const ERMIAttachmentType Attach_ClDeployMicrowaveBeam = 4;
	static constexpr const bool ServerCall_ClDeployMicrowaveBeam = 0;
	static constexpr const ENetReliabilityType Reliability_ClDeployMicrowaveBeam = 1;
	static constexpr const bool LowDelay_ClDeployMicrowaveBeam = 0;
	static inline auto m_infoClDeployMicrowaveBeam = PreyGlobal<CPlayer::MethodInfo_ClDeployMicrowaveBeam>(0x2D93068);
	static constexpr const ERMIAttachmentType Attach_ClAbortStealthKill = 2;
	static constexpr const bool ServerCall_ClAbortStealthKill = 0;
	static constexpr const ENetReliabilityType Reliability_ClAbortStealthKill = 0;
	static constexpr const bool LowDelay_ClAbortStealthKill = 0;
	static inline auto m_infoClAbortStealthKill = PreyGlobal<CPlayer::MethodInfo_ClAbortStealthKill>(0x2D93058);
	static constexpr const ERMIAttachmentType Attach_ClApplyMeleeImpulse = 2;
	static constexpr const bool ServerCall_ClApplyMeleeImpulse = 0;
	static constexpr const ENetReliabilityType Reliability_ClApplyMeleeImpulse = 1;
	static constexpr const bool LowDelay_ClApplyMeleeImpulse = 0;
	static inline auto m_infoClApplyMeleeImpulse = PreyGlobal<CPlayer::MethodInfo_ClApplyMeleeImpulse>(0x2D93088);
	static constexpr const ERMIAttachmentType Attach_ClIncrementIntStat = 2;
	static constexpr const bool ServerCall_ClIncrementIntStat = 0;
	static constexpr const ENetReliabilityType Reliability_ClIncrementIntStat = 1;
	static constexpr const bool LowDelay_ClIncrementIntStat = 0;
	static inline auto m_infoClIncrementIntStat = PreyGlobal<CPlayer::MethodInfo_ClIncrementIntStat>(0x2D93090);
	static constexpr const ERMIAttachmentType Attach_SvRequestUseLadder = 2;
	static constexpr const bool ServerCall_SvRequestUseLadder = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestUseLadder = 0;
	static constexpr const bool LowDelay_SvRequestUseLadder = 0;
	static inline auto m_infoSvRequestUseLadder = PreyGlobal<CPlayer::MethodInfo_SvRequestUseLadder>(0x2D93070);
	static constexpr const ERMIAttachmentType Attach_SvRequestLeaveFromLadder = 2;
	static constexpr const bool ServerCall_SvRequestLeaveFromLadder = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestLeaveFromLadder = 0;
	static constexpr const bool LowDelay_SvRequestLeaveFromLadder = 0;
	static inline auto m_infoSvRequestLeaveFromLadder = PreyGlobal<CPlayer::MethodInfo_SvRequestLeaveFromLadder>(0x2D93078);
	static constexpr const ERMIAttachmentType Attach_ClLeaveFromLadder = 2;
	static constexpr const bool ServerCall_ClLeaveFromLadder = 0;
	static constexpr const ENetReliabilityType Reliability_ClLeaveFromLadder = 0;
	static constexpr const bool LowDelay_ClLeaveFromLadder = 0;
	static inline auto m_infoClLeaveFromLadder = PreyGlobal<CPlayer::MethodInfo_ClLeaveFromLadder>(0x2D93080);
	std::list<IPlayerEventListener *,std::allocator<IPlayerEventListener *> > m_playerEventListeners;
	std::list<IPlayerUpdateListener *,std::allocator<IPlayerUpdateListener *> > m_playerUpdateListeners;
	float m_timeOfLastHealthSync;
	CTimeValue m_lastTimeDamaged;
	CPlayerRotation* m_pPlayerRotation;
	Matrix34 m_clientViewMatrix;
	Vec3 m_eyeOffset;
	Vec3 m_weaponOffset;
	Vec3 m_lastRequestedVelocity;
	Vec3 m_lastKnownPosition;
	Vec3 m_lastSyncedWorldPosition;
	Vec3 m_forcedLookDir;
	unsigned m_forcedLookObjectId;
	unsigned m_lastFlashbangShooterId;
	float m_lastFlashbangTime;
	float m_lastZoomedTime;
	SPlayerStats m_stats;
	float m_fLastEffectFootStepTime;
	int m_actions;
	uint8_t m_actionFlags;
	bool m_isAIControlled;
	bool m_viewBlending;
	bool m_jumpButtonIsPressed;
	bool m_bSneakButtonIsPressed;
	bool m_bBrakeButtonIsPressed;
	bool m_timedemo;
	bool m_isInWater;
	bool m_isHeadUnderWater;
	float m_fOxygenLevel;
	float m_fDeathTime;
	bool m_sufferingHighLatency;
	CPlayer::SSound m_sounds[38];
	int m_footstepCounter;
	IInteractor* m_pInteractor;
	std::shared_ptr<IEntityAudioProxy> m_pIEntityAudioProxy;
	CPlayer::SStagingParams m_stagingParams;
	static constexpr const int k_maxActivePlayerPlugIns = 6;
	HitInfo m_stealthKillDelayedHit;
	int m_numActivePlayerPlugins;
	int m_pendingLoadoutGroup;
	float m_fScriptMovementSpeedModifier;
	SCharacterMoveRequest m_request;
	SPlayerRotationParams m_playerRotationParams;
	CPlayerStateSwim_WaterTestProxy m_playerStateSwim_WaterTestProxy;
	SFrameMovementModifiers m_frameMovementModifiers;
	float m_ragdollTime;
	bool m_netFlashBangStun;
	bool m_mountedGunControllerEnabled;
	uint8_t m_jumpCounter;
	Vec3 m_jumpVel;
	uint8_t m_mpModelIndex;
	uint8_t m_ledgeCounter;
	uint16_t m_ledgeID;
	unsigned m_ladderId;
	ELadderLeaveLocation m_lastLadderLeaveLoc;
	float m_ladderHeightFrac;
	float m_ladderHeightFracInterped;
	uint8_t m_ledgeFlags;
	CryFixedStringT<32> m_lastSuffix;
	CryFixedStringT<32> m_lastPose;
	CryFixedStringT<32> m_lastItemClass;
	SNetPlayerProgression m_netPlayerProgression;
	SXPEvents m_netXPEvents;
	CTimeValue m_netXPSendTime;
	std::shared_ptr<CHitDeathReactions> m_pHitDeathReactions;
	SDeferredFootstepImpulse m_deferredFootstepImpulse;
	float m_lastLedgeTime;
	unsigned m_stealthKilledById;
	unsigned m_carryObjId;
	bool m_pickingUpCarryObject;
	IAttachment* m_pIAttachmentGrab;
	CPlayer::EReactionOverlay m_reactionOverlay;
	float m_reactionTimer;
	float m_reactionFactor;
	int m_reactionOverlayAnimIDs[7];
	static inline auto m_reactionAnims = PreyGlobal<CPlayer::SReactionAnim [7]>(0x23F0F90);
	uint8_t m_meleeHitCounter;
	int m_xpBonusMultiplier;
	float m_timeFirstSpawned;
	float m_lastReloadTime;
	QuatT m_lastCameraLocation;
	CAnimationProxyDualCharacter m_animationProxy;
	CAnimationProxyDualCharacterUpper m_animationProxyUpper;
	CIKTorsoAim_Helper m_torsoAimIK;
	CLookAim_Helper m_lookAim;
	SAnimActionAIMovementSettings m_animActionAIMovementSettings;
	float m_logPingTimer;
	float m_deferredKnockDownImpulse;
	int m_teamWhenKilled;
	float m_moveScale;
	float m_aimLimit;
	bool m_fpCompleteBodyVisible;
	bool m_deferredKnockDownPending : 1;
	bool m_registeredOnHUD : 1;
	bool m_dropCorpseOnDeath : 1;
	bool m_hideOnDeath : 1;
	bool m_usingSpectatorPhysics : 1;
	bool m_inNetLimbo : 1;
	bool m_bCanTurnBody : 1;
	bool m_isControllingCamera : 1;
	bool m_bDontResetFXUntilNextSpawnRevive : 1;
	bool m_bMakeVisibleOnNextSpawn : 1;
	bool m_bHasAimLimit : 1;
	bool m_bPlayIntro : 1;
	int8_t m_lastCachedInteractionIndex;
	std::unique_ptr<CAIAnimationComponent> m_pAIAnimationComponent;

	static void RegisterState(CStateHierarchy<CPlayer>* (*createPtr)(CStateMachineRegistration<CPlayer>&), void (*deletePtr)(CStateHierarchy<CPlayer>* &), unsigned stateID) { FRegisterState(createPtr, deletePtr, stateID); }
	void StateMachineHandleEventMovement(const SStateEvent& event) { FStateMachineHandleEventMovement(this, event); }
	void StateMachineResetMovement() { FStateMachineResetMovement(this); }
	CPlayer();
	virtual ~CPlayer();
	virtual bool IsHeadUnderWater() const;
	virtual bool IsSwimming() const;
	virtual bool IsZeroG() const;
	virtual bool IsClimbing() const;
	virtual bool IsHovering() const;
	virtual void ProcessGlideJump() const;
	virtual boost::optional<Vec3_tpl<float> > GetViewOffsetOverride(float _frameTime) const;
	virtual bool IsSprinting() const;
	virtual bool CanFire() const;
	virtual bool Init(IGameObject* pGameObject);
	virtual void PostInit(IGameObject* pGameObject);
	void ReloadClientXmlData() { FReloadClientXmlData(this); }
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void ProcessEvent(SEntityEvent& event);
	virtual void SetAuthority(bool auth);
	virtual void SerializeXML(XmlNodeRef& node, bool bLoading);
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot);
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void UpdateAnimationState(const SActorFrameMovementParams& frameMovementParams);
	virtual void PrePhysicsUpdate();
	virtual void UpdateView(SViewParams& viewParams);
	virtual void PostUpdateView(SViewParams& viewParams);
	void OnFootStepImpulseAnimEvent(ICharacterInstance* pCharacter, const AnimEventInstance& event) { FOnFootStepImpulseAnimEvent(this, pCharacter, event); }
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual void OnFootStepAnimEvent(ICharacterInstance* pCharacter, const char* boneName);
	virtual void OnFoleyAnimEvent(ICharacterInstance* pCharacter, const char* CustomParameter, const char* boneName);
	void ExecuteFootStep(ICharacterInstance* pCharacter, const float frameTime, const int nFootJointID) { FExecuteFootStep(this, pCharacter, frameTime, nFootJointID); }
	void ExecuteFoleySignal(ICharacterInstance* pCharacter, const float frameTime, const char* sFoleyActionName, const int nBoneJointID) { FExecuteFoleySignal(this, pCharacter, frameTime, sFoleyActionName, nBoneJointID); }
	void ExecuteFootStepsAIStimulus(const float relativeSpeed, const float noiseSupression) { FExecuteFootStepsAIStimulus(this, relativeSpeed, noiseSupression); }
	void ExecuteGroundEffectAnimEvent(ICharacterInstance* pCharacter, const float frameTime, const char* szEffectName, const int nJointID) { FExecuteGroundEffectAnimEvent(this, pCharacter, frameTime, szEffectName, nJointID); }
	void OnKillAnimEvent(const AnimEventInstance& event) { FOnKillAnimEvent(this, event); }
	void UpdateClient(const float frameTime) { FUpdateClient(this, frameTime); }
	virtual bool CanBreakGlass() const;
	virtual bool MustBreakGlass() const;
	virtual void Physicalize(EStance stance);
	virtual bool SetActorModel(const char* modelName);
	virtual void SetChannelId(uint16_t id);
	virtual IEntity* LinkToEntity(unsigned entityId, bool bKeepTransformOnDetach);
	virtual void LinkToMountedWeapon(unsigned weaponId);
	virtual void StartInteractiveAction(unsigned entityId, int interactionIndex);
	virtual void StartInteractiveActionByName(const char* interaction, bool bUpdateVisibility, float actionSpeed);
	virtual bool IsInteractiveActionDone() const;
	void AnimationControlled(bool activate, bool bUpdateVisibility) { FAnimationControlled(this, activate, bUpdateVisibility); }
	void RefillAmmo() { FRefillAmmo(this); }
	virtual int GetPhysicalSkipEntities(IPhysicalEntity* * pSkipList, const int maxSkipSize) const;
	virtual void SupressViewBlending();
	bool IsMovingIgnoreHoverBob() const { return FIsMovingIgnoreHoverBob(this); }
	bool GetForcedLookDir(Vec3& vDir) const { return FGetForcedLookDir(this, vDir); }
	void SetForcedLookDir(const Vec3& vDir) { FSetForcedLookDir(this, vDir); }
	void ClearForcedLookDir() { FClearForcedLookDir(this); }
	void SetForcedLookObjectId(unsigned entityId) { FSetForcedLookObjectId(this, entityId); }
	void ClearForcedLookObjectId() { FClearForcedLookObjectId(this); }
	bool CanMove() const { return FCanMove(this); }
	virtual const char* GetActorClassName() const;
	virtual int GetActorClass() const;
	virtual unsigned GetGrabbedEntityId() const;
	virtual void UpdateMountedGunController(bool forceIKUpdate);
	bool IsJumping() const { return FIsJumping(this); }
	virtual void EnableStumbling(PlayerActor::Stumble::StumbleParameters* stumbleParameters);
	virtual void DisableStumbling();
	void SetAnimatedCharacterParams(const SAnimatedCharacterParams& params) { FSetAnimatedCharacterParams(this, params); }
	virtual void OnFakeHitToHitReactions(const HitInfo& _hitInfo);
	virtual IActorMovementController* CreateMovementController();
	void SetIK(const SActorFrameMovementParams& frameMovementParams) { FSetIK(this, frameMovementParams); }
	virtual void UpdatePlayerPlugins(const float dt);
	void UpdateFPIKTorso(float fFrameTime, IItem* pCurrentItem, const Vec3& cameraPosition) { FUpdateFPIKTorso(this, fFrameTime, pCurrentItem, cameraPosition); }
	virtual void OnChangeTeam();
	void UpdatePlayerCinematicStatus(uint8_t oldFlags, uint8_t newFlags) { FUpdatePlayerCinematicStatus(this, oldFlags, newFlags); }
	void CheckSendXPChanges() { FCheckSendXPChanges(this); }
	virtual void PostRagdollPhysicalized(SRagdollizeParams* _pRagdollParams);
	void OnBeginCutScene() { FOnBeginCutScene(this); }
	void OnEndCutScene() { FOnEndCutScene(this); }
	const Vec3 GetFPCameraPosition(bool worldSpace) const { alignas(const Vec3) std::byte _return_buf_[sizeof(const Vec3)]; return *FGetFPCameraPosition(this, reinterpret_cast<const Vec3*>(_return_buf_), worldSpace); }
	static INetAtSyncItem* Decode_SvOnXPChanged(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvOnXPChanged(ser, pID, pChannel); }
	bool Handle_SvOnXPChanged(const SXPEvents& params, INetChannel* pNetChannel) { return FHandle_SvOnXPChanged(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClDelayedDetonation(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClDelayedDetonation(ser, pID, pChannel); }
	bool Handle_ClDelayedDetonation(const CPlayer::EntityParams& params, INetChannel* pNetChannel) { return FHandle_ClDelayedDetonation(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestMicrowaveBeam(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestMicrowaveBeam(ser, pID, pChannel); }
	bool Handle_SvRequestMicrowaveBeam(const SMicrowaveBeamParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestMicrowaveBeam(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClDeployMicrowaveBeam(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClDeployMicrowaveBeam(ser, pID, pChannel); }
	bool Handle_ClDeployMicrowaveBeam(const SMicrowaveBeamParams& params, INetChannel* pNetChannel) { return FHandle_ClDeployMicrowaveBeam(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClAbortStealthKill(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClAbortStealthKill(ser, pID, pChannel); }
	bool Handle_ClAbortStealthKill(const CPlayer::TwoEntityParams& params, INetChannel* pNetChannel) { return FHandle_ClAbortStealthKill(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClApplyMeleeImpulse(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClApplyMeleeImpulse(ser, pID, pChannel); }
	bool Handle_ClApplyMeleeImpulse(const CPlayer::SPlayerMeleeImpulseParams& params, INetChannel* pNetChannel) { return FHandle_ClApplyMeleeImpulse(this, params, pNetChannel); }
	void ApplyMeleeImpulse(const Vec3& impulseDirection, float impulseStrength) { FApplyMeleeImpulse(this, impulseDirection, impulseStrength); }
	static INetAtSyncItem* Decode_ClIncrementIntStat(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClIncrementIntStat(ser, pID, pChannel); }
	bool Handle_ClIncrementIntStat(const CPlayer::SIntStatParams& params, INetChannel* pNetChannel) { return FHandle_ClIncrementIntStat(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestUseLadder(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestUseLadder(ser, pID, pChannel); }
	bool Handle_SvRequestUseLadder(const CPlayer::SRequestUseLadderParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestUseLadder(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestLeaveFromLadder(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestLeaveFromLadder(ser, pID, pChannel); }
	bool Handle_SvRequestLeaveFromLadder(const CPlayer::SRequestLeaveLadderParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestLeaveFromLadder(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClLeaveFromLadder(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClLeaveFromLadder(ser, pID, pChannel); }
	bool Handle_ClLeaveFromLadder(const CPlayer::SRequestLeaveLadderParams& params, INetChannel* pNetChannel) { return FHandle_ClLeaveFromLadder(this, params, pNetChannel); }
	virtual void SetStats(SmartScriptTable& rTable);
	virtual void UpdateStats(float frameTime);
	virtual void SetParamsFromLua(SmartScriptTable& rTable);
	virtual float CalculatePseudoSpeed(bool wantSprint, float speedOverride) const;
	virtual float GetStanceMaxSpeed(EStance stance) const;
	virtual void ToggleThirdPerson();
	virtual int IsGod();
	virtual void Revive(CCryActor::EReasonForRevive reasonForRevive);
	virtual void Kill();
	virtual void Reset(bool toGame);
	virtual void RequestFacialExpression(const char* pExpressionName, float* sequenceLength);
	Vec3 GetStanceViewOffset(EStance _stance, const float* pLeanAmt, bool withY, const bool useWhileLeanedOffsets) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetStanceViewOffset(this, reinterpret_cast<Vec3*>(_return_buf_), _stance, pLeanAmt, withY, useWhileLeanedOffsets); }
	virtual void SetStance(EStance desiredStance);
	virtual bool IsThirdPerson() const;
	virtual void OnStanceChanged(EStance newStance, EStance oldStance);
	virtual void OnTeleported();
	virtual void ResetAnimationState();
	float GetSprintStaminaLevel() const { return FGetSprintStaminaLevel(this); }
	virtual void SaveToProfile(IPlayerProfile* pProfile, bool online, unsigned reason);
	virtual void LoadFromProfile(IPlayerProfile* pProfile, bool online, unsigned reason);
	virtual void OnReturnedToPool();
	virtual void OnAIProxyEnabled(bool enabled);
	virtual uint8_t GetFlyMode() const;
	virtual void SetSpectatorState(uint8_t state);
	virtual CCryActor::EActorSpectatorState GetSpectatorState() const;
	virtual void SetSpectatorModeAndOtherEntId(const uint8_t _mode, const unsigned _othEntId, bool isSpawning);
	virtual uint8_t GetSpectatorMode() const;
	virtual void SetSpectatorTarget(unsigned targetId);
	virtual unsigned GetSpectatorTarget() const;
	virtual float GetSpectatorOrbitYawSpeed() const;
	virtual void SetSpectatorOrbitYawSpeed(float yawSpeed, bool singleFrame);
	virtual bool CanSpectatorOrbitYaw() const;
	virtual float GetSpectatorOrbitPitchSpeed() const;
	virtual void SetSpectatorOrbitPitchSpeed(float pitchSpeed, bool singleFrame);
	virtual bool CanSpectatorOrbitPitch() const;
	virtual void SetSpectatorFixedLocation(unsigned locId);
	virtual unsigned GetSpectatorFixedLocation() const;
	virtual void SetCloakLayer(bool set, CCryActor::eFadeRules config);
	virtual void SelectNextItem(int direction, bool keepHistory, int category);
	virtual void HolsterItem(bool holster, bool playSelect, float selectSpeedBias, bool hideLeftHandObject);
	virtual void SelectLastItem(bool keepHistory, bool forceNext);
	virtual void SelectItemByName(const char* name, bool keepHistory, bool forceFastSelect);
	virtual void SelectItem(unsigned itemId, bool keepHistory, bool forceSelect);
	virtual bool ScheduleItemSwitch(unsigned itemId, bool keepHistory, int category, bool forceFastSelect);
	virtual void NotifyCurrentItemChanged(IItem* newItem);
	virtual void RagDollize(bool fallAndPlay);
	virtual void HandleEvent(const SGameObjectEvent& event);
	virtual void PostUpdate(float frameTime);
	virtual void AnimationEvent(ICharacterInstance* pCharacter, const AnimEventInstance& event);
	virtual void SetViewRotation(const Quat& rotation);
	virtual Quat GetViewRotation() const;
	virtual void EnableTimeDemo(bool bTimeDemo);
	virtual void AddViewAngleOffsetForFrame(const Ang3& offset);
	virtual bool SetAspectProfile(EEntityAspects aspect, uint8_t profile);
	virtual void FullSerialize(TSerialize ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	void SetPlayerHealth(const float _health, const float _prevHealth) { FSetPlayerHealth(this, _health, _prevHealth); }
	virtual float GetHealth() const;
	virtual float GetMaxHealth() const;
	virtual void SetHealth(float health);
	virtual SPlayerStats* GetActorStats();
	virtual const SPlayerStats* GetActorStats() const;
	virtual void PostPhysicalize();
	virtual void CameraShake(float angle, float shift, float duration, float frequency, Vec3 pos, int ID, const char* source);
	virtual bool CreateCodeEvent(SmartScriptTable& rTable);
	virtual Matrix34 GetViewMatrix() const;
	virtual void AddAngularImpulse(const Ang3& angular, float deceleration, float duration);
	virtual void SetAngles(const Ang3& angles);
	virtual Ang3 GetAngles();
	virtual void PlayAction(const char* action, const char* extension, bool looping);
	virtual bool AllowLandingBob();
	bool IsPlayingSmartObjectAction() const { return FIsPlayingSmartObjectAction(this); }
	bool CanFall() const { return FCanFall(this); }
	virtual void KnockDown(float backwardsImpulse);
	virtual void SetLookAtTargetId(unsigned targetId, float interpolationTime);
	virtual void SetForceLookAtTargetId(unsigned targetId, float interpolationTime);
	virtual void DamageInfo(unsigned shooterID, unsigned weaponID, IEntityClass* pProjectileClass, float damage, int damageType, const Vec3 hitDirection);
	virtual void ResetAnimations();
	virtual void SwitchDemoModeSpectator(bool activate);
	void StopLoopingSounds() { FStopLoopingSounds(this); }
	void RegisterPlayerEventListener(IPlayerEventListener* pPlayerEventListener) { FRegisterPlayerEventListener(this, pPlayerEventListener); }
	void UnregisterPlayerEventListener(IPlayerEventListener* pPlayerEventListener) { FUnregisterPlayerEventListener(this, pPlayerEventListener); }
	bool IsOnGround() const { return FIsOnGround(this); }
	bool IsSliding() const { return FIsSliding(this); }
	bool IsInAir() const { return FIsInAir(this); }
	bool IsOnLedge() const { return FIsOnLedge(this); }
	bool HasHeavyWeaponEquipped() const { return FHasHeavyWeaponEquipped(this); }
	virtual bool UseItem(unsigned itemId);
	virtual bool PickUpItem(unsigned itemId, bool sound, bool select);
	virtual bool DropItem(unsigned itemId, float impulseScale, bool selectNext, bool byDeath);
	virtual void NetKill(const CCryActor::KillParams& killParams);
	void ResetFPView() { FResetFPView(this); }
	virtual const float GetCloakBlendSpeedScale();
	void OnPickedUpPickableAmmo(IEntityClass* pAmmoType, int count) { FOnPickedUpPickableAmmo(this, pAmmoType, count); }
	bool HasShadowCharacter() const { return FHasShadowCharacter(this); }
	ICharacterInstance* GetShadowCharacter() const { return FGetShadowCharacter(this); }
	virtual void ChangeCurrentFollowCameraSettings(bool increment);
	void UpdateFlashbangEffect(float frameTime) { FUpdateFlashbangEffect(this, frameTime); }
	void ExitPickAndThrow(bool forceInstantDrop) { FExitPickAndThrow(this, forceInstantDrop); }
	std::shared_ptr<CHitDeathReactions> GetHitDeathReactions() { alignas(std::shared_ptr<CHitDeathReactions>) std::byte _return_buf_[sizeof(std::shared_ptr<CHitDeathReactions>)]; return *FGetHitDeathReactionsOv1(this, reinterpret_cast<std::shared_ptr<CHitDeathReactions>*>(_return_buf_)); }
	void SpawnCorpse() { FSpawnCorpse(this); }
	void SetRagdollPhysicsParams(IPhysicalEntity* pPhysEnt, SRagdollizeParams* _pRagdollParams) { FSetRagdollPhysicsParams(this, pPhysEnt, _pRagdollParams); }
	void SetTagByCRC(unsigned tagCRC, bool enable) { FSetTagByCRC(this, tagCRC, enable); }
	virtual void BecomeRemotePlayer();
	virtual bool ShouldMuteWeaponSoundStimulus() const;
	void SetScriptMovementSpeedModifier(const float fFactor) { FSetScriptMovementSpeedModifier(this, fFactor); }
	void NetSerialize_Spectator(TSerialize ser, bool bReading) { FNetSerialize_Spectator(this, ser, bReading); }
	virtual void CreatePlayerInputClass();
	void CommitKnockDown() { FCommitKnockDown(this); }
	virtual void PrepareLuaCache();
	void UpdateThirdPersonState() { FUpdateThirdPersonState(this); }
	void HasJumped(const Vec3& jumpVel) { FHasJumped(this, jumpVel); }
	uint8_t GetJumpCounter() const { return FGetJumpCounter(this); }
	void SetJumpCounter(uint8_t counter) { FSetJumpCounter(this, counter); }
	uint8_t GetLedgeCounter() const { return FGetLedgeCounter(this); }
	void SetLedgeCounter(uint8_t counter) { FSetLedgeCounter(this, counter); }
	virtual void InitGameParams(const SActorGameParams& gameParams, const bool reloadCharacterSounds);
	virtual bool MountedGunControllerEnabled() const;
	virtual void MountedGunControllerEnabled(bool val);
	void UpdateAIAnimationState(const SActorFrameMovementParams& frameMovementParams, ICharacterInstance* pICharInst, IActionController* pActionController, IMannequin& mannequinSys) { FUpdateAIAnimationState(this, frameMovementParams, pICharInst, pActionController, mannequinSys); }
	void SetMultiplayerModelName() { FSetMultiplayerModelName(this); }
	virtual void ReadDataFromXML(bool isClientReloading);
	virtual void SetModelIndex(uint8_t modelIndex);
	void UpdateReactionOverlay(float frameTime) { FUpdateReactionOverlay(this, frameTime); }
	void SetReactionOverlay(CPlayer::EReactionOverlay overlay) { FSetReactionOverlay(this, overlay); }
	virtual void SetTurnAnimationParams(const float turnThresholdAngle, const float turnThresholdTime);

#if 0
	static void UnRegisterState(unsigned _arg0_);
	void StateMachineInitMovement();
	void StateMachineReleaseMovement();
	void StateMachineUpdateMovement(const float _arg0_, const bool _arg1_);
	void StateMachineSerializeMovement(const SStateEvent& _arg0_);
	void InitMannequinParams();
	bool CanMelee() const;
	void GetInternalMemoryUsage(ICrySizer* _arg0_) const;
	void OnSwimmingStrokeAnimEvent();
	bool ShouldUpdateNextFootStep() const;
	void OnGroundEffectAnimEvent(ICharacterInstance* _arg0_, const AnimEventInstance& _arg1_);
	void OnIntroSequenceFinished();
	bool IsWeaponUnderWater() const;
	void PartialAnimationControlled(bool _arg0_);
	void OnReceivingLoadout();
	void RefillAmmoDone();
	void HoldScreenEffectsUntilNextSpawnRevive();
	Vec3 GetLastRequestedVelocity() const;
	bool IsMoving() const;
	const QuatT& GetAnimationRelativeMovement(int _arg0_) const;
	void SetDeathTimer();
	float GetDeathTime() const;
	unsigned GetForcedLookObjectId() const;
	void SufferingHighLatency(bool _arg0_);
	static int GetActorClassType();
	IInteractor* GetInteractor();
	void UnlockInteractor(unsigned _arg0_);
	bool ShouldPlayIntro() const;
	void SetPlayIntro(bool _arg0_);
	unsigned GetInteractingEntityId() const;
	int GetLastInteractionIndex() const;
	void SetLastInteractionIndex(int _arg0_);
	void SetCinematicFlag(const SPlayerStats::ECinematicFlags _arg0_);
	void ResetCinematicFlags();
	bool IsCinematicFlagActive(const SPlayerStats::ECinematicFlags _arg0_) const;
	bool IsMovementRestricted() const;
	bool IsInCinematicMode() const;
	void SetBackToNormalWeapon(const bool _arg0_);
	bool IsOnLadder() const;
	void BlockMovementInputsForTime(float _arg0_);
	bool GetBlockMovementInputs() const;
	bool CanHandFire(int _arg0_) const;
	bool CanFireOrMelee(bool _arg0_) const;
	bool CanFire_AI() const;
	bool CanFire_DedicatedClient() const;
	void ResetInteractor();
	void LeaveAllPlayerPlugins();
	void UpdateSilentFeetSoundAdjustment();
	bool DoSTAPAiming() const;
	void UpdateFPAiming();
	void UpdatePartialCameraAnim(float _arg0_);
	const Vec3 GetFPCameraOffset() const;
	void OnLocalPlayerChangeTeam();
	void ResetCinematicStatus(uint8_t _arg0_);
	void UpdateSpectator(float _arg0_);
	void BlendPartialCameraAnim(float _arg0_, float _arg1_);
	static const CPlayer::MethodInfo_SvOnXPChanged& SvOnXPChanged();
	static const CPlayer::MethodInfo_ClDelayedDetonation& ClDelayedDetonation();
	static const CPlayer::MethodInfo_SvRequestMicrowaveBeam& SvRequestMicrowaveBeam();
	static const CPlayer::MethodInfo_ClDeployMicrowaveBeam& ClDeployMicrowaveBeam();
	void RequestMicrowaveBeam(const SMicrowaveBeamParams& _arg0_);
	void DeployMicrowaveBeam(const SMicrowaveBeamParams& _arg0_);
	static const CPlayer::MethodInfo_ClAbortStealthKill& ClAbortStealthKill();
	static const CPlayer::MethodInfo_ClApplyMeleeImpulse& ClApplyMeleeImpulse();
	static const CPlayer::MethodInfo_ClIncrementIntStat& ClIncrementIntStat();
	static const CPlayer::MethodInfo_SvRequestUseLadder& SvRequestUseLadder();
	static const CPlayer::MethodInfo_SvRequestLeaveFromLadder& SvRequestLeaveFromLadder();
	static const CPlayer::MethodInfo_ClLeaveFromLadder& ClLeaveFromLadder();
	void UpdateSwimStats(float _arg0_, const Matrix34& _arg1_);
	void UpdateBreathing(float _arg0_);
	void UpdateStumble(float _arg0_);
	void SetThirdPerson(bool _arg0_);
	void RestartMannequin();
	void SetStanceTag(EStance _arg0_, CTagState& _arg1_);
	void MoveToSpectatorTargetPosition();
	void SetRecentKiller(unsigned _arg0_, int _arg1_);
	unsigned GetLastAttacker();
	void HolsterItem_NoNetwork(bool _arg0_, bool _arg1_, float _arg2_, bool _arg3_);
	void UnRagdollize();
	void SetViewRotationAndKeepBaseOrientation(const Quat& _arg0_);
	void SetForceLookAt(const Vec3& _arg0_, const bool _arg1_);
	void AddViewAngles(const Ang3& _arg0_);
	void SetInNetLimbo(bool _arg0_);
	bool InNetLimbo() const;
	void SetMoveScale(float _arg0_);
	float GetMoveScale() const;
	void CaughtInStealthKill(unsigned _arg0_);
	void StoreDelayedKillingHitInfo(HitInfo _arg0_);
	HitInfo& GetDelayedKillingHitInfo();
	bool ShouldFilterOutHit(const HitInfo& _arg0_);
	bool ShouldFilterOutExplosion(const HitInfo& _arg0_);
	void OnStartRecordingPlayback();
	void OnStopRecordingPlayback();
	void OnRecordingPlaybackBulletTime(bool _arg0_);
	const Quat& GetBaseQuat() const;
	const Quat& GetViewQuat() const;
	const Quat& GetViewQuatFinal() const;
	bool IsTimeDemo() const;
	void RegisterPlayerUpdateListener(IPlayerUpdateListener* _arg0_);
	void UnregisterPlayerUpdateListener(IPlayerUpdateListener* _arg0_);
	bool CanTurnBody() const;
	void SetCanTurnBody(const bool _arg0_);
	void SetAimLimit(const float _arg0_);
	void ClearAimLimit();
	bool GetAimLimit(float& _arg0_) const;
	bool IsExitingSlide() const;
	bool CanDoSlideKick() const;
	bool IsPlayerOkToAction() const;
	bool HasBeenOffLedgeSince(float _arg0_) const;
	bool CanSwitchItems() const;
	const Vec3& GetEyeOffset() const;
	const Vec3& GetWeaponOffset() const;
	SCharacterMoveRequest& GetMoveRequest();
	void ResetScreenFX();
	void ForceRefreshStanceAndEyeOffsetNow();
	float GetLastDamageSeconds() const;
	float GetTimeEnteredLowHealth() const;
	const unsigned GetLastFlashbangShooterId() const;
	const float GetLastFlashbangTime() const;
	const float GetLastZoomedTime() const;
	void SetLastReloadTime(float _arg0_);
	float GetLastReloadTime() const;
	void AddXPBonusMultiplier(int _arg0_);
	int GetXPBonusModifiedXP(int _arg0_);
	float GetWeaponMovementFactor() const;
	float GetWeaponRotationFactor() const;
	float GetTotalSpeedMultiplier() const;
	void RegisterKill(IActor* _arg0_, int _arg1_);
	void NetSetInStealthKill(bool _arg0_, unsigned _arg1_, uint8_t _arg2_);
	void StopStealthKillTargetMovement(unsigned _arg0_);
	void StagePlayer(bool _arg0_, CPlayer::SStagingParams* _arg1_);
	void NotifyObjectGrabbed(bool _arg0_, unsigned _arg1_, bool _arg2_, bool _arg3_, float _arg4_);
	bool HasActiveNavPath() const;
	int GetShadowCharacterSlot() const;
	void UpdateVisibility();
	void RefreshVisibilityState();
	bool SetCurrentFollowCameraSettings(unsigned _arg0_);
	void StartFlashbangEffects(const float _arg0_, const unsigned _arg1_);
	void StopFlashbangEffects();
	void StartTinnitus();
	void UpdateTinnitus(float _arg0_);
	void StopTinnitus();
	void AttemptStealthKill(unsigned _arg0_);
	void FailedStealthKill();
	void EnterLargeObjectInteraction(unsigned _arg0_, const bool _arg1_);
	void RequestEnterPickAndThrow(unsigned _arg0_);
	void EnterPickAndThrow(unsigned _arg0_, bool _arg1_, bool _arg2_);
	bool IsInPickAndThrowMode() const;
	unsigned GetPickAndThrowEntity() const;
	unsigned GetPrevPickAndThrowEntity() const;
	std::shared_ptr<const CHitDeathReactions> GetHitDeathReactions() const;
	void InitHitDeathReactions();
	void GetPlayerProgressions(int* _arg0_, int* _arg1_, int* _arg2_, int* _arg3_, int* _arg4_, int* _arg5_);
	void TriggerMeleeReaction();
	void ReloadPickAndThrowProxy();
	void OnCollision(EventPhysCollision* _arg0_);
	void SetClientSoundmood(CPlayer::EClientSoundmoods _arg0_);
	CPlayer::EClientSoundmoods FindClientSoundmoodBestFit() const;
	void LogXPChangeToTelemetry(int _arg0_, EXPReason _arg1_);
	void PostProcessAnimation(ICharacterInstance* _arg0_);
	void StealthKillInterrupted(unsigned _arg0_);
	void SetStealthKilledBy(unsigned _arg0_);
	unsigned GetStealthKilledBy() const;
	SPlayerRotationParams::EAimType GetCurrentAimType() const;
	const SPlayerRotationParams& GetPlayerRotationParams() const;
	void OnMeleeHit(const SMeleeHitParams& _arg0_);
	bool IsInFreeFallDeath() const;
	void CreateInputClass(bool _arg0_);
	void SetLastTimeInLedge(float _arg0_);
	void DeselectWeapon();
	CAIAnimationComponent* GetAIAnimationComponent();
	const CAIAnimationComponent* GetAIAnimationComponent() const;
	bool WasFriendlyWhenKilled(unsigned _arg0_) const;
	int GetTeamWhenKilled() const;
	uint8_t GetMPModelIndex() const;
	void OnUseLadder(unsigned _arg0_, float _arg1_);
	void OnLeaveLadder(ELadderLeaveLocation _arg0_);
	void OnLadderPositionUpdated(float _arg0_);
	void InterpLadderPosition(float _arg0_);
	void RemoveScriptMovementSpeedModifier();
	bool IsJumpButtonPressed() const;
	void NetSerialize_Health(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_CurrentItem(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_StealthKill(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_InteractiveObject(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_InputClient(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_InputClient_Aug(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_FlashBang(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_Jumping(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_LedgeGrab(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_Melee(TSerialize _arg0_, bool _arg1_);
	void NetSerialize_Ladder(TSerialize _arg0_, bool _arg1_);
	void DoMeleeMaterialEffect(const SMeleeHitParams& _arg0_);
	bool ShouldUsePhysicsMovement();
	void InformHealthHasBeenReduced();
	void OnRagdollize();
	void OnLocalSpectatorStateSerialize(CCryActor::EActorSpectatorState _arg0_, CCryActor::EActorSpectatorState _arg1_);
	void UpdateHealthRegeneration(float _arg0_, float _arg1_);
	float GetRegenerationAmount(float _arg0_);
	void HandleMPPreRevive();
	void UpdateCrouchAndLeanReferencePoints();
	static void StrikeTargetPosition(const int _arg0_, const int _arg1_, Vec3& _arg2_);
	void HasClimbedLedge(const uint16_t _arg0_, bool _arg1_, bool _arg2_);
	void SetupAimIKProperties();
	void SelectMovementHierarchy();
	bool IsAIControlled() const;
	void UpdateAITagsFromAG(CTagState* _arg0_, const SMannequinAIStateParams* _arg1_);
	void AddClientSoundmood(CPlayer::EClientSoundmoods _arg0_);
	void RemoveClientSoundmood(CPlayer::EClientSoundmoods _arg0_);
	void StatsPopulateAngVelAndMass(const IPhysicalEntity& _arg0_);
	void StatsPopulateMovingAndRestTime(float _arg0_);
	const char* GetFootstepEffectName() const;
	void OnRayCastBottomLevelDataReceived(const unsigned& _arg0_, const RayCastResult& _arg1_);
	float GetTimeFirstSpawned() const;
#endif

	static inline auto FRegisterState = PreyFunction<void(CStateHierarchy<CPlayer>* (*createPtr)(CStateMachineRegistration<CPlayer>&), void (*deletePtr)(CStateHierarchy<CPlayer>* &), unsigned stateID)>(0x18C7870);
	static inline auto FStateMachineHandleEventMovement = PreyFunction<void(CPlayer* const _this, const SStateEvent& event)>(0x18CBB30);
	static inline auto FStateMachineResetMovement = PreyFunction<void(CPlayer* const _this)>(0x18CBB50);
	static inline auto FCPlayer = PreyFunction<void(CPlayer* const _this)>(0x18BB0E0);
	static inline auto FBitNotCPlayer = PreyFunction<void(CPlayer* const _this)>(0x18BC200);
	static inline auto FIsHeadUnderWater = PreyFunction<bool(const CPlayer* const _this)>(0x1614A10);
	static inline auto FIsSwimming = PreyFunction<bool(const CPlayer* const _this)>(0x18C2FA0);
	static inline auto FIsZeroG = PreyFunction<bool(const CPlayer* const _this)>(0x18C2FD0);
	static inline auto FIsClimbing = PreyFunction<bool(const CPlayer* const _this)>(0x13B0900);
	static inline auto FIsHovering = PreyFunction<bool(const CPlayer* const _this)>(0x13B0900);
	static inline auto FProcessGlideJump = PreyFunction<void(const CPlayer* const _this)>(0x1333E90);
	static inline auto FGetViewOffsetOverride = PreyFunction<boost::optional<Vec3_tpl<float> >*(const CPlayer* const _this, boost::optional<Vec3_tpl<float> >* _return_value_, float _frameTime)>(0x162BB30);
	static inline auto FIsSprinting = PreyFunction<bool(const CPlayer* const _this)>(0x18C2F60);
	static inline auto FCanFire = PreyFunction<bool(const CPlayer* const _this)>(0x18BD790);
	static inline auto FInit = PreyFunction<bool(CPlayer* const _this, IGameObject* pGameObject)>(0x18C28E0);
	static inline auto FPostInit = PreyFunction<void(CPlayer* const _this, IGameObject* pGameObject)>(0x18C4F90);
	static inline auto FReloadClientXmlData = PreyFunction<void(CPlayer* const _this)>(0x18C7920);
	static inline auto FReloadExtension = PreyFunction<bool(CPlayer* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x18C7930);
	static inline auto FPostReloadExtension = PreyFunction<void(CPlayer* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x18C5600);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CPlayer* const _this, TSerialize signature)>(0x18C15C0);
	static inline auto FProcessEvent = PreyFunction<void(CPlayer* const _this, SEntityEvent& event)>(0x18C6A20);
	static inline auto FSetAuthority = PreyFunction<void(CPlayer* const _this, bool auth)>(0x18C98F0);
	static inline auto FSerializeXML = PreyFunction<void(CPlayer* const _this, XmlNodeRef& node, bool bLoading)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CPlayer* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x18CC930);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CPlayer* const _this, TSerialize ser)>(0x18C9010);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CPlayer* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x18C1AF0);
	static inline auto FUpdateAnimationState = PreyFunction<void(CPlayer* const _this, const SActorFrameMovementParams& frameMovementParams)>(0x18CCC20);
	static inline auto FPrePhysicsUpdate = PreyFunction<void(CPlayer* const _this)>(0x18C6280);
	static inline auto FUpdateView = PreyFunction<void(IGameObjectView* const _this, SViewParams& viewParams)>(0x18CD3A0);
	static inline auto FPostUpdateView = PreyFunction<void(IGameObjectView* const _this, SViewParams& viewParams)>(0x18C5BD0);
	static inline auto FOnFootStepImpulseAnimEvent = PreyFunction<void(CPlayer* const _this, ICharacterInstance* pCharacter, const AnimEventInstance& event)>(0x18C4400);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CPlayer* const _this, ICrySizer* pSizer)>(0x18C1A10);
	static inline auto FOnFootStepAnimEvent = PreyFunction<void(CPlayer* const _this, ICharacterInstance* pCharacter, const char* boneName)>(0x18C4340);
	static inline auto FOnFoleyAnimEvent = PreyFunction<void(CPlayer* const _this, ICharacterInstance* pCharacter, const char* CustomParameter, const char* boneName)>(0x18C4290);
	static inline auto FExecuteFootStep = PreyFunction<void(CPlayer* const _this, ICharacterInstance* pCharacter, const float frameTime, const int nFootJointID)>(0x18BF9B0);
	static inline auto FExecuteFoleySignal = PreyFunction<void(CPlayer* const _this, ICharacterInstance* pCharacter, const float frameTime, const char* sFoleyActionName, const int nBoneJointID)>(0x18BF110);
	static inline auto FExecuteFootStepsAIStimulus = PreyFunction<void(CPlayer* const _this, const float relativeSpeed, const float noiseSupression)>(0x18C0580);
	static inline auto FExecuteGroundEffectAnimEvent = PreyFunction<void(CPlayer* const _this, ICharacterInstance* pCharacter, const float frameTime, const char* szEffectName, const int nJointID)>(0x18C0610);
	static inline auto FOnKillAnimEvent = PreyFunction<void(CPlayer* const _this, const AnimEventInstance& event)>(0x18C47C0);
	static inline auto FUpdateClient = PreyFunction<void(CPlayer* const _this, const float frameTime)>(0x1333E90);
	static inline auto FCanBreakGlass = PreyFunction<bool(const CPlayer* const _this)>(0x18BD580);
	static inline auto FMustBreakGlass = PreyFunction<bool(const CPlayer* const _this)>(0x18C3160);
	static inline auto FPhysicalize = PreyFunction<void(CPlayer* const _this, EStance stance)>(0x18C4BB0);
	static inline auto FSetActorModel = PreyFunction<bool(CPlayer* const _this, const char* modelName)>(0x18C9280);
	static inline auto FSetChannelId = PreyFunction<void(CPlayer* const _this, uint16_t id)>(0x18C9930);
	static inline auto FLinkToEntity = PreyFunction<IEntity* (CPlayer* const _this, unsigned entityId, bool bKeepTransformOnDetach)>(0x18C30F0);
	static inline auto FLinkToMountedWeapon = PreyFunction<void(CPlayer* const _this, unsigned weaponId)>(0x18C3150);
	static inline auto FStartInteractiveAction = PreyFunction<void(CPlayer* const _this, unsigned entityId, int interactionIndex)>(0x18CB510);
	static inline auto FStartInteractiveActionByName = PreyFunction<void(CPlayer* const _this, const char* interaction, bool bUpdateVisibility, float actionSpeed)>(0x18CB5E0);
	static inline auto FIsInteractiveActionDone = PreyFunction<bool(const CPlayer* const _this)>(0x18C2E00);
	static inline auto FAnimationControlled = PreyFunction<void(CPlayer* const _this, bool activate, bool bUpdateVisibility)>(0x18BCBE0);
	static inline auto FRefillAmmo = PreyFunction<void(CPlayer* const _this)>(0x18C76E0);
	static inline auto FGetPhysicalSkipEntities = PreyFunction<int(const CPlayer* const _this, IPhysicalEntity* * pSkipList, const int maxSkipSize)>(0x18C1A60);
	static inline auto FSupressViewBlending = PreyFunction<void(CPlayer* const _this)>(0x1632260);
	static inline auto FIsMovingIgnoreHoverBob = PreyFunction<bool(const CPlayer* const _this)>(0x18C2E30);
	static inline auto FGetForcedLookDir = PreyFunction<bool(const CPlayer* const _this, Vec3& vDir)>(0x18C1830);
	static inline auto FSetForcedLookDir = PreyFunction<void(CPlayer* const _this, const Vec3& vDir)>(0x18C9940);
	static inline auto FClearForcedLookDir = PreyFunction<void(CPlayer* const _this)>(0x18BDAB0);
	static inline auto FSetForcedLookObjectId = PreyFunction<void(CPlayer* const _this, unsigned entityId)>(0x18C9960);
	static inline auto FClearForcedLookObjectId = PreyFunction<void(CPlayer* const _this)>(0x18BDAC0);
	static inline auto FCanMove = PreyFunction<bool(const CPlayer* const _this)>(0x18BD7D0);
	static inline auto FGetActorClassName = PreyFunction<const char* (const CPlayer* const _this)>(0x18C13F0);
	static inline auto FGetActorClass = PreyFunction<int(const CPlayer* const _this)>(0x1948930);
	static inline auto FGetGrabbedEntityId = PreyFunction<unsigned(const CPlayer* const _this)>(0x162B110);
	static inline auto FUpdateMountedGunController = PreyFunction<void(CPlayer* const _this, bool forceIKUpdate)>(0x1333E90);
	static inline auto FIsJumping = PreyFunction<bool(const CPlayer* const _this)>(0x18C2E20);
	static inline auto FEnableStumbling = PreyFunction<void(CPlayer* const _this, PlayerActor::Stumble::StumbleParameters* stumbleParameters)>(0x1333E90);
	static inline auto FDisableStumbling = PreyFunction<void(CPlayer* const _this)>(0x1333E90);
	static inline auto FSetAnimatedCharacterParams = PreyFunction<void(CPlayer* const _this, const SAnimatedCharacterParams& params)>(0x18C9520);
	static inline auto FOnFakeHitToHitReactions = PreyFunction<void(CPlayer* const _this, const HitInfo& _hitInfo)>(0x18C41F0);
	static inline auto FCreateMovementController = PreyFunction<IActorMovementController* (CPlayer* const _this)>(0x18BDF20);
	static inline auto FSetIK = PreyFunction<void(CPlayer* const _this, const SActorFrameMovementParams& frameMovementParams)>(0x18C9AC0);
	static inline auto FUpdatePlayerPlugins = PreyFunction<void(CPlayer* const _this, const float dt)>(0x1333E90);
	static inline auto FUpdateFPIKTorso = PreyFunction<void(CPlayer* const _this, float fFrameTime, IItem* pCurrentItem, const Vec3& cameraPosition)>(0x1333E90);
	static inline auto FOnChangeTeam = PreyFunction<void(CPlayer* const _this)>(0x1333E90);
	static inline auto FUpdatePlayerCinematicStatus = PreyFunction<void(CPlayer* const _this, uint8_t oldFlags, uint8_t newFlags)>(0x18CCEE0);
	static inline auto FCheckSendXPChanges = PreyFunction<void(CPlayer* const _this)>(0x18BD830);
	static inline auto FPostRagdollPhysicalized = PreyFunction<void(CPlayer* const _this, SRagdollizeParams* _pRagdollParams)>(0x18C5510);
	static inline auto FOnBeginCutScene = PreyFunction<void(CPlayer* const _this)>(0x18C3EE0);
	static inline auto FOnEndCutScene = PreyFunction<void(CPlayer* const _this)>(0x18C3FD0);
	static inline auto FGetFPCameraPosition = PreyFunction<const Vec3*(const CPlayer* const _this, const Vec3* _return_value_, bool worldSpace)>(0x18C1610);
	static inline auto FDecode_SvOnXPChanged = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BE8A0);
	static inline auto FHandle_SvOnXPChanged = PreyFunction<bool(CPlayer* const _this, const SXPEvents& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClDelayedDetonation = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BE2A0);
	static inline auto FHandle_ClDelayedDetonation = PreyFunction<bool(CPlayer* const _this, const CPlayer::EntityParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_SvRequestMicrowaveBeam = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BEC80);
	static inline auto FHandle_SvRequestMicrowaveBeam = PreyFunction<bool(CPlayer* const _this, const SMicrowaveBeamParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClDeployMicrowaveBeam = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BE400);
	static inline auto FHandle_ClDeployMicrowaveBeam = PreyFunction<bool(CPlayer* const _this, const SMicrowaveBeamParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClAbortStealthKill = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BDF60);
	static inline auto FHandle_ClAbortStealthKill = PreyFunction<bool(CPlayer* const _this, const CPlayer::TwoEntityParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClApplyMeleeImpulse = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BE0E0);
	static inline auto FHandle_ClApplyMeleeImpulse = PreyFunction<bool(CPlayer* const _this, const CPlayer::SPlayerMeleeImpulseParams& params, INetChannel* pNetChannel)>(0x18C2520);
	static inline auto FApplyMeleeImpulse = PreyFunction<void(CPlayer* const _this, const Vec3& impulseDirection, float impulseStrength)>(0x18BD0F0);
	static inline auto FDecode_ClIncrementIntStat = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BE5D0);
	static inline auto FHandle_ClIncrementIntStat = PreyFunction<bool(CPlayer* const _this, const CPlayer::SIntStatParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_SvRequestUseLadder = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BEE50);
	static inline auto FHandle_SvRequestUseLadder = PreyFunction<bool(CPlayer* const _this, const CPlayer::SRequestUseLadderParams& params, INetChannel* pNetChannel)>(0x18C25C0);
	static inline auto FDecode_SvRequestLeaveFromLadder = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BEB10);
	static inline auto FHandle_SvRequestLeaveFromLadder = PreyFunction<bool(CPlayer* const _this, const CPlayer::SRequestLeaveLadderParams& params, INetChannel* pNetChannel)>(0x18C2540);
	static inline auto FDecode_ClLeaveFromLadder = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18BE730);
	static inline auto FHandle_ClLeaveFromLadder = PreyFunction<bool(CPlayer* const _this, const CPlayer::SRequestLeaveLadderParams& params, INetChannel* pNetChannel)>(0x18C2540);
	static inline auto FSetStats = PreyFunction<void(CPlayer* const _this, SmartScriptTable& rTable)>(0x18CAA70);
	static inline auto FUpdateStats = PreyFunction<void(CPlayer* const _this, float frameTime)>(0x18CD240);
	static inline auto FSetParamsFromLua = PreyFunction<void(CPlayer* const _this, SmartScriptTable& rTable)>(0x18CA280);
	static inline auto FCalculatePseudoSpeed = PreyFunction<float(const CPlayer* const _this, bool wantSprint, float speedOverride)>(0x18BD2E0);
	static inline auto FGetStanceMaxSpeed = PreyFunction<float(const CPlayer* const _this, EStance stance)>(0x18C1BE0);
	static inline auto FToggleThirdPerson = PreyFunction<void(CPlayer* const _this)>(0x18CC680);
	static inline auto FIsGod = PreyFunction<int(CPlayer* const _this)>(0x18C2D30);
	static inline auto FRevive = PreyFunction<void(CPlayer* const _this, CCryActor::EReasonForRevive reasonForRevive)>(0x18C7CA0);
	static inline auto FKill = PreyFunction<void(CPlayer* const _this)>(0x18C2FE0);
	static inline auto FReset = PreyFunction<void(CPlayer* const _this, bool toGame)>(0x18C7A60);
	static inline auto FRequestFacialExpression = PreyFunction<void(CPlayer* const _this, const char* pExpressionName, float* sequenceLength)>(0x18C7A40);
	static inline auto FGetStanceViewOffset = PreyFunction<Vec3*(const CPlayer* const _this, Vec3* _return_value_, EStance _stance, const float* pLeanAmt, bool withY, const bool useWhileLeanedOffsets)>(0x18C1C20);
	static inline auto FSetStance = PreyFunction<void(CPlayer* const _this, EStance desiredStance)>(0x18CAA10);
	static inline auto FIsThirdPerson = PreyFunction<bool(const CPlayer* const _this)>(0x18C2FB0);
	static inline auto FOnStanceChanged = PreyFunction<void(CPlayer* const _this, EStance newStance, EStance oldStance)>(0x18C4AE0);
	static inline auto FOnTeleported = PreyFunction<void(CPlayer* const _this)>(0x18C4B50);
	static inline auto FResetAnimationState = PreyFunction<void(CPlayer* const _this)>(0x18C7B50);
	static inline auto FGetSprintStaminaLevel = PreyFunction<float(const CPlayer* const _this)>(0x1AE7A80);
	static inline auto FSaveToProfile = PreyFunction<void(IPlayerProfileListener* const _this, IPlayerProfile* pProfile, bool online, unsigned reason)>(0x1333E90);
	static inline auto FLoadFromProfile = PreyFunction<void(IPlayerProfileListener* const _this, IPlayerProfile* pProfile, bool online, unsigned reason)>(0x1333E90);
	static inline auto FOnReturnedToPool = PreyFunction<void(CPlayer* const _this)>(0x18C4AC0);
	static inline auto FOnAIProxyEnabled = PreyFunction<void(CPlayer* const _this, bool enabled)>(0x18C3E90);
	static inline auto FGetFlyMode = PreyFunction<uint8_t(const CPlayer* const _this)>(0x13B0900);
	static inline auto FSetSpectatorState = PreyFunction<void(CPlayer* const _this, uint8_t state)>(0x18CA8E0);
	static inline auto FGetSpectatorState = PreyFunction<CCryActor::EActorSpectatorState(const CPlayer* const _this)>(0x162BA80);
	static inline auto FSetSpectatorModeAndOtherEntId = PreyFunction<void(CPlayer* const _this, const uint8_t _mode, const unsigned _othEntId, bool isSpawning)>(0x1333E90);
	static inline auto FGetSpectatorMode = PreyFunction<uint8_t(const CPlayer* const _this)>(0x162BA70);
	static inline auto FSetSpectatorTarget = PreyFunction<void(CPlayer* const _this, unsigned targetId)>(0x18CA960);
	static inline auto FGetSpectatorTarget = PreyFunction<unsigned(const CPlayer* const _this)>(0x162BA60);
	static inline auto FGetSpectatorOrbitYawSpeed = PreyFunction<float(const CPlayer* const _this)>(0x18C1BD0);
	static inline auto FSetSpectatorOrbitYawSpeed = PreyFunction<void(CPlayer* const _this, float yawSpeed, bool singleFrame)>(0x18CA8D0);
	static inline auto FCanSpectatorOrbitYaw = PreyFunction<bool(const CPlayer* const _this)>(0x13B0900);
	static inline auto FGetSpectatorOrbitPitchSpeed = PreyFunction<float(const CPlayer* const _this)>(0x18C1BC0);
	static inline auto FSetSpectatorOrbitPitchSpeed = PreyFunction<void(CPlayer* const _this, float pitchSpeed, bool singleFrame)>(0x18CA8C0);
	static inline auto FCanSpectatorOrbitPitch = PreyFunction<bool(const CPlayer* const _this)>(0x13B0900);
	static inline auto FSetSpectatorFixedLocation = PreyFunction<void(CPlayer* const _this, unsigned locId)>(0x18CA830);
	static inline auto FGetSpectatorFixedLocation = PreyFunction<unsigned(const CPlayer* const _this)>(0x162BA60);
	static inline auto FSetCloakLayer = PreyFunction<void(CPlayer* const _this, bool set, CCryActor::eFadeRules config)>(0x18C9930);
	static inline auto FSelectNextItem = PreyFunction<void(CPlayer* const _this, int direction, bool keepHistory, int category)>(0x18C86C0);
	static inline auto FHolsterItem = PreyFunction<void(CPlayer* const _this, bool holster, bool playSelect, float selectSpeedBias, bool hideLeftHandObject)>(0x18C28B0);
	static inline auto FSelectLastItem = PreyFunction<void(CPlayer* const _this, bool keepHistory, bool forceNext)>(0x18C86B0);
	static inline auto FSelectItemByName = PreyFunction<void(CPlayer* const _this, const char* name, bool keepHistory, bool forceFastSelect)>(0x18C86A0);
	static inline auto FSelectItem = PreyFunction<void(CPlayer* const _this, unsigned itemId, bool keepHistory, bool forceSelect)>(0x18C85E0);
	static inline auto FScheduleItemSwitch = PreyFunction<bool(CPlayer* const _this, unsigned itemId, bool keepHistory, int category, bool forceFastSelect)>(0x18C85A0);
	static inline auto FNotifyCurrentItemChanged = PreyFunction<void(CPlayer* const _this, IItem* newItem)>(0x18C3E30);
	static inline auto FRagDollize = PreyFunction<void(CPlayer* const _this, bool fallAndPlay)>(0x18C6E90);
	static inline auto FHandleEvent = PreyFunction<void(CPlayer* const _this, const SGameObjectEvent& event)>(0x18C1F20);
	static inline auto FPostUpdate = PreyFunction<void(CPlayer* const _this, float frameTime)>(0x18C58B0);
	static inline auto FAnimationEvent = PreyFunction<void(CPlayer* const _this, ICharacterInstance* pCharacter, const AnimEventInstance& event)>(0x18BCC90);
	static inline auto FSetViewRotation = PreyFunction<void(CPlayer* const _this, const Quat& rotation)>(0x18CAC10);
	static inline auto FGetViewRotation = PreyFunction<Quat*(const CPlayer* const _this, Quat* _return_value_)>(0x18C1EF0);
	static inline auto FEnableTimeDemo = PreyFunction<void(CPlayer* const _this, bool bTimeDemo)>(0x18BF100);
	static inline auto FAddViewAngleOffsetForFrame = PreyFunction<void(CPlayer* const _this, const Ang3& offset)>(0x18BCB80);
	static inline auto FSetAspectProfile = PreyFunction<bool(IGameObjectProfileManager* const _this, EEntityAspects aspect, uint8_t profile)>(0x18C95A0);
	static inline auto FFullSerialize = PreyFunction<void(CPlayer* const _this, TSerialize ser)>(0x18C0FD0);
	static inline auto FNetSerialize = PreyFunction<bool(CPlayer* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x18C3370);
	static inline auto FPostSerialize = PreyFunction<void(CPlayer* const _this)>(0x18C5730);
	static inline auto FSetPlayerHealth = PreyFunction<void(CPlayer* const _this, const float _health, const float _prevHealth)>(0x18CA340);
	static inline auto FGetHealth = PreyFunction<float(const CPlayer* const _this)>(0x18C19D0);
	static inline auto FGetMaxHealth = PreyFunction<float(const CPlayer* const _this)>(0x17C40D0);
	static inline auto FSetHealth = PreyFunction<void(CPlayer* const _this, float health)>(0x18C9980);
	static inline auto FGetActorStatsOv1 = PreyFunction<SPlayerStats* (CPlayer* const _this)>(0x162AD50);
	static inline auto FGetActorStatsOv0 = PreyFunction<const SPlayerStats* (const CPlayer* const _this)>(0x162AD50);
	static inline auto FPostPhysicalize = PreyFunction<void(CPlayer* const _this)>(0x18C50C0);
	static inline auto FCameraShake = PreyFunction<void(CPlayer* const _this, float angle, float shift, float duration, float frequency, Vec3 pos, int ID, const char* source)>(0x18BD380);
	static inline auto FCreateCodeEvent = PreyFunction<bool(CPlayer* const _this, SmartScriptTable& rTable)>(0x18BDF10);
	static inline auto FGetViewMatrix = PreyFunction<Matrix34*(const CPlayer* const _this, Matrix34* _return_value_)>(0x162BAC0);
	static inline auto FAddAngularImpulse = PreyFunction<void(CPlayer* const _this, const Ang3& angular, float deceleration, float duration)>(0x18BCB70);
	static inline auto FSetAngles = PreyFunction<void(CPlayer* const _this, const Ang3& angles)>(0x18C9350);
	static inline auto FGetAngles = PreyFunction<Ang3*(CPlayer* const _this, Ang3* _return_value_)>(0x18C1400);
	static inline auto FPlayAction = PreyFunction<void(CPlayer* const _this, const char* action, const char* extension, bool looping)>(0x18C4F20);
	static inline auto FAllowLandingBob = PreyFunction<bool(CPlayer* const _this)>(0x1A302A0);
	static inline auto FIsPlayingSmartObjectAction = PreyFunction<bool(const CPlayer* const _this)>(0x18CFC10);
	static inline auto FCanFall = PreyFunction<bool(const CPlayer* const _this)>(0x18BD600);
	static inline auto FKnockDown = PreyFunction<void(CPlayer* const _this, float backwardsImpulse)>(0x18C30C0);
	static inline auto FSetLookAtTargetId = PreyFunction<void(CPlayer* const _this, unsigned targetId, float interpolationTime)>(0x1333E90);
	static inline auto FSetForceLookAtTargetId = PreyFunction<void(CPlayer* const _this, unsigned targetId, float interpolationTime)>(0x1333E90);
	static inline auto FDamageInfo = PreyFunction<void(CPlayer* const _this, unsigned shooterID, unsigned weaponID, IEntityClass* pProjectileClass, float damage, int damageType, const Vec3 hitDirection)>(0x18BDF50);
	static inline auto FResetAnimations = PreyFunction<void(CPlayer* const _this)>(0x18C7B80);
	static inline auto FSwitchDemoModeSpectator = PreyFunction<void(CPlayer* const _this, bool activate)>(0x18CC1F0);
	static inline auto FStopLoopingSounds = PreyFunction<void(CPlayer* const _this)>(0x1333E90);
	static inline auto FRegisterPlayerEventListener = PreyFunction<void(CPlayer* const _this, IPlayerEventListener* pPlayerEventListener)>(0x18C77D0);
	static inline auto FUnregisterPlayerEventListener = PreyFunction<void(CPlayer* const _this, IPlayerEventListener* pPlayerEventListener)>(0x18CC8E0);
	static inline auto FIsOnGround = PreyFunction<bool(const CPlayer* const _this)>(0x18C2F30);
	static inline auto FIsSliding = PreyFunction<bool(const CPlayer* const _this)>(0x18C2F50);
	static inline auto FIsInAir = PreyFunction<bool(const CPlayer* const _this)>(0x18C2DF0);
	static inline auto FIsOnLedge = PreyFunction<bool(const CPlayer* const _this)>(0x18C2F40);
	static inline auto FHasHeavyWeaponEquipped = PreyFunction<bool(const CPlayer* const _this)>(0x18C2760);
	static inline auto FUseItem = PreyFunction<bool(CPlayer* const _this, unsigned itemId)>(0x18CD5E0);
	static inline auto FPickUpItem = PreyFunction<bool(CPlayer* const _this, unsigned itemId, bool sound, bool select)>(0x18C4DC0);
	static inline auto FDropItem = PreyFunction<bool(CPlayer* const _this, unsigned itemId, float impulseScale, bool selectNext, bool byDeath)>(0x18BF060);
	static inline auto FNetKill = PreyFunction<void(CPlayer* const _this, const CCryActor::KillParams& killParams)>(0x18C31B0);
	static inline auto FResetFPView = PreyFunction<void(CPlayer* const _this)>(0x18C7C40);
	static inline auto FGetCloakBlendSpeedScale = PreyFunction<const float(CPlayer* const _this)>(0x18C15B0);
	static inline auto FOnPickedUpPickableAmmo = PreyFunction<void(CPlayer* const _this, IEntityClass* pAmmoType, int count)>(0x18C4920);
	static inline auto FHasShadowCharacter = PreyFunction<bool(const CPlayer* const _this)>(0x18C2880);
	static inline auto FGetShadowCharacter = PreyFunction<ICharacterInstance* (const CPlayer* const _this)>(0x18C1AC0);
	static inline auto FChangeCurrentFollowCameraSettings = PreyFunction<void(CPlayer* const _this, bool increment)>(0x1333E90);
	static inline auto FUpdateFlashbangEffect = PreyFunction<void(CPlayer* const _this, float frameTime)>(0x18CCCA0);
	static inline auto FExitPickAndThrow = PreyFunction<void(CPlayer* const _this, bool forceInstantDrop)>(0x18C0F60);
	static inline auto FGetHitDeathReactionsOv1 = PreyFunction<std::shared_ptr<CHitDeathReactions>*(CPlayer* const _this, std::shared_ptr<CHitDeathReactions>* _return_value_)>(0x162B1A0);
	static inline auto FSpawnCorpse = PreyFunction<void(CPlayer* const _this)>(0x18CB010);
	static inline auto FSetRagdollPhysicsParams = PreyFunction<void(CPlayer* const _this, IPhysicalEntity* pPhysEnt, SRagdollizeParams* _pRagdollParams)>(0x18CA470);
	static inline auto FSetTagByCRC = PreyFunction<void(CPlayer* const _this, unsigned tagCRC, bool enable)>(0x18CAAA0);
	static inline auto FBecomeRemotePlayer = PreyFunction<void(CPlayer* const _this)>(0x18BD2D0);
	static inline auto FShouldMuteWeaponSoundStimulus = PreyFunction<bool(const CPlayer* const _this)>(0x13B0900);
	static inline auto FSetScriptMovementSpeedModifier = PreyFunction<void(CPlayer* const _this, const float fFactor)>(0x18CA820);
	static inline auto FNetSerialize_Spectator = PreyFunction<void(CPlayer* const _this, TSerialize ser, bool bReading)>(0x18C3C10);
	static inline auto FCreatePlayerInputClass = PreyFunction<void(CPlayer* const _this)>(0x1333E90);
	static inline auto FCommitKnockDown = PreyFunction<void(CPlayer* const _this)>(0x18BDAD0);
	static inline auto FPrepareLuaCache = PreyFunction<void(CPlayer* const _this)>(0x18C67F0);
	static inline auto FUpdateThirdPersonState = PreyFunction<void(CPlayer* const _this)>(0x18CD2B0);
	static inline auto FHasJumped = PreyFunction<void(CPlayer* const _this, const Vec3& jumpVel)>(0x18C2770);
	static inline auto FGetJumpCounter = PreyFunction<uint8_t(const CPlayer* const _this)>(0x18C19F0);
	static inline auto FSetJumpCounter = PreyFunction<void(CPlayer* const _this, uint8_t counter)>(0x18C9F90);
	static inline auto FGetLedgeCounter = PreyFunction<uint8_t(const CPlayer* const _this)>(0x18C1A00);
	static inline auto FSetLedgeCounter = PreyFunction<void(CPlayer* const _this, uint8_t counter)>(0x1333E90);
	static inline auto FInitGameParams = PreyFunction<void(CPlayer* const _this, const SActorGameParams& gameParams, const bool reloadCharacterSounds)>(0x18C2D20);
	static inline auto FMountedGunControllerEnabledOv1 = PreyFunction<bool(const CPlayer* const _this)>(0x162E1B0);
	static inline auto FMountedGunControllerEnabledOv0 = PreyFunction<void(CPlayer* const _this, bool val)>(0x162E1A0);
	static inline auto FUpdateAIAnimationState = PreyFunction<void(CPlayer* const _this, const SActorFrameMovementParams& frameMovementParams, ICharacterInstance* pICharInst, IActionController* pActionController, IMannequin& mannequinSys)>(0x18CFFE0);
	static inline auto FSetMultiplayerModelName = PreyFunction<void(CPlayer* const _this)>(0x18CA080);
	static inline auto FReadDataFromXML = PreyFunction<void(CPlayer* const _this, bool isClientReloading)>(0x18C7290);
	static inline auto FSetModelIndex = PreyFunction<void(CPlayer* const _this, uint8_t modelIndex)>(0x1630940);
	static inline auto FUpdateReactionOverlay = PreyFunction<void(CPlayer* const _this, float frameTime)>(0x18CD090);
	static inline auto FSetReactionOverlay = PreyFunction<void(CPlayer* const _this, CPlayer::EReactionOverlay overlay)>(0x18CA6A0);
	static inline auto FSetTurnAnimationParams = PreyFunction<void(CPlayer* const _this, const float turnThresholdAngle, const float turnThresholdTime)>(0x18CABE0);
};

namespace CPlayerGetSpawnInfo
{

// CPlayerGetSpawnInfo::SInfo
// Header:  Prey/GameDll/Player.h
struct SInfo : public ISerializableInfo
{ // Size=32 (0x20)
	int teamId;
	uint8_t netPhysCounter;
	uint8_t modelIndex;
	bool bShowIntro;

	virtual void SerializeWith(TSerialize ser);

	static inline auto FSerializeWith = PreyFunction<void(ISerializable* const _this, TSerialize ser)>(0x18C9130);
};


} // namespace CPlayerGetSpawnInfo
#endif // MOONCRASH
