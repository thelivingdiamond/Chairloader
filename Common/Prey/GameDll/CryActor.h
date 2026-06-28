// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/actordefinitions.h>
#include <Prey/GameDll/bodydefinitions.h>
#include <_unknown/CCoherentValue.h>
#include <_unknown/CCryFlags.h>
#include <_unknown/CHealth.h>
#include <_unknown/CryFixedArray.h>
#include <_unknown/STagState.h>

class CCryName;
class CItem;
class CProceduralContextRagdoll;
class CScriptSetGetChain;
enum EBodyDamagePIDFlags;
enum EEntityAspects;
struct HitInfo;
struct IActorMovementController;
struct IAnimatedCharacter;
struct IAnimationGraphState;
class IArkSpeaker;
struct IAttachment;
struct IAttachmentManager;
struct ICharacterInstance;
class ICrySizer;
struct IEntity;
struct IEntityClass;
struct IGameFramework;
struct IGameObject;
struct IGameplayRecorder;
struct IInventory;
struct IItem;
struct IItemParamsNode;
struct IItemSystem;
struct IMovementController;
struct INetAtSyncItem;
struct INetChannel;
struct IPhysicalEntity;
namespace PlayerActor::Stumble
{
struct StumbleParameters;
} // namespace PlayerActor::Stumble
struct SActorFileModelInfo;
struct SActorGameParams;
struct SActorIKLimbInfo;
struct SActorStats;
struct SEntityEvent;
struct SEntityPhysicalizeParams;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
struct SGameObjectExtensionRMI;
struct SHitImpulse;
struct SLuaCache_ActorGameParams;
struct SLuaCache_ActorPhysicsParams;
struct SLuaCache_ActorProperties;
struct SViewParams;
class SmartScriptTable;
struct pe_params_rope;
struct pe_player_dimensions;
struct pe_player_dynamics;

// SActorAnimationEvents
// Header:  Prey/GameDll/CryActor.h
struct SActorAnimationEvents
{ // Size=112 (0x70)
	unsigned m_soundId;
	unsigned m_plugginTriggerId;
	unsigned m_footstepSignalId;
	unsigned m_foleySignalId;
	unsigned m_groundEffectId;
	unsigned m_swimmingStrokeId;
	unsigned m_footStepImpulseId;
	unsigned m_forceFeedbackId;
	unsigned m_grabObjectId;
	unsigned m_stowId;
	unsigned m_weaponLeftHandId;
	unsigned m_weaponRightHandId;
	unsigned m_deathReactionEndId;
	unsigned m_reactionOnCollision;
	unsigned m_forbidReactionsId;
	unsigned m_ragdollStartId;
	unsigned m_killId;
	unsigned m_deathBlow;
	unsigned m_startFire;
	unsigned m_stopFire;
	unsigned m_shootGrenade;
	unsigned m_meleeHitId;
	unsigned m_meleeStartDamagePhase;
	unsigned m_meleeEndDamagePhase;
	unsigned m_endReboundAnim;
	unsigned m_detachEnvironmentalWeapon;
	unsigned m_stealthMeleeDeath;
	bool m_initialized;

	void Init() { FInit(this); }

#if 0
	SActorAnimationEvents();
#endif

	static inline auto FInit = PreyFunction<void(SActorAnimationEvents* const _this)>(0x17C6040);
};

// SActorPhysics
// Header:  Prey/GameDll/CryActor.h
struct SActorPhysics
{ // Size=112 (0x70)
	enum EActorPhysicsFlags
	{
		EActorPhysicsFlags_Flying = 1,
		EActorPhysicsFlags_WasFlying = 2,
		EActorPhysicsFlags_Stuck = 4,
	};

	Vec3 angVelocity;
	Vec3 velocity;
	Vec3 velocityDelta;
	Vec3 velocityUnconstrained;
	Vec3 velocityUnconstrainedLast;
	Vec3 gravity;
	Vec3 groundNormal;
	float speed;
	float groundHeight;
	float mass;
	int lastFrameUpdate;
	int groundMaterialIdx;
	unsigned groundColliderId;
	CCryFlags<unsigned int> flags;

	void Serialize(TSerialize ser, EEntityAspects aspects) { FSerialize(this, ser, aspects); }

#if 0
	SActorPhysics();
#endif

	static inline auto FSerialize = PreyFunction<void(SActorPhysics* const _this, TSerialize ser, EEntityAspects aspects)>(0x17CE970);
};

// SIKLimb
// Header:  Prey/GameDll/CryActor.h
// Include: Prey/CryAction/VehicleSystem/VehicleSeatActionPassengerIK.h
struct SIKLimb
{ // Size=156 (0x9C)
	int flags;
	int rootBoneID;
	int endBoneID;
	int middleBoneID;
	Vec3 goalWPos;
	Vec3 currentWPos;
	Vec3 goalNormal;
	Vec3 lAnimPos;
	char name[64];
	float recoverTime;
	float recoverTimeMax;
	float blendTime;
	float invBlendTimeMax;
	int blendID;
	int characterSlot;
	bool keepGoalPos;

	void Update(IEntity* pOwner, float frameTime) { FUpdate(this, pOwner, frameTime); }

#if 0
	SIKLimb();
	void SetLimb(int _arg0_, const char* _arg1_, int _arg2_, int _arg3_, int _arg4_, int _arg5_);
	void SetWPos(IEntity* _arg0_, const Vec3& _arg1_, const Vec3& _arg2_, float _arg3_, float _arg4_, int _arg5_);
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FUpdate = PreyFunction<void(SIKLimb* const _this, IEntity* pOwner, float frameTime)>(0x17D17F0);
};

// SLinkStats
// Header:  Prey/GameDll/CryActor.h
struct SLinkStats
{ // Size=8 (0x8)
	enum class EFlags
	{
		LINKED_FREELOOK = 1,
	};

	unsigned linkID;
	unsigned flags;

	void Serialize(TSerialize ser) { FSerialize(this, ser); }

#if 0
	SLinkStats();
	SLinkStats(unsigned _arg0_, unsigned _arg1_);
	void UnLink();
	bool CanMove();
	bool CanDoIK();
	bool CanMoveCharacter();
	IEntity* GetLinked();
#endif

	static inline auto FSerialize = PreyFunction<void(SLinkStats* const _this, TSerialize ser)>(0x17CEA80);
};

// CCryActor
// Header:  Prey/GameDll/CryActor.h
class CCryActor
	: public CGameObjectExtensionHelper<CCryActor,CActor,40>
	, public IGameObjectView
	, public IGameObjectProfileManager
{ // Size=6008 (0x1778)
public:
	enum EActorClass
	{
		eActorClass_Actor = 0,
		eActorClass_Player = 1,
	};

	enum class EReasonForRevive
	{
		kRFR_FromInit = 0,
		kRFR_StartSpectating = 1,
		kRFR_Spawn = 2,
		kRFR_ScriptBind = 3,
	};

	enum EActorSpectatorState
	{
		eASS_None = 0,
		eASS_Ingame = 1,
		eASS_ForcedEquipmentChange = 2,
		eASS_SpectatorMode = 3,
	};

	enum EActorSpectatorMode
	{
		eASM_None = 0,
		eASM_FirstMPMode = 1,
		eASM_Fixed = 1,
		eASM_Free = 2,
		eASM_Follow = 3,
		eASM_Killer = 4,
		eASM_LastMPMode = 4,
		eASM_Cutscene = 5,
	};

	enum eFadeRules
	{
		eAllowFades = 0,
		eDisallowFades = 1,
	};

	// CCryActor::ItemIdParam
	// Header:  Prey/GameDll/CryActor.h
	struct ItemIdParam
	{ // Size=8 (0x8)
		unsigned itemId;
		bool pickOnlyAmmo;
		bool select;

	#if 0
		ItemIdParam();
		ItemIdParam(unsigned _arg0_);
		ItemIdParam(unsigned _arg0_, bool _arg1_);
		ItemIdParam(unsigned _arg0_, bool _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::ExchangeItemParams
	// Header:  Prey/GameDll/CryActor.h
	struct ExchangeItemParams
	{ // Size=8 (0x8)
		unsigned dropItemId;
		unsigned pickUpItemId;

	#if 0
		ExchangeItemParams();
		ExchangeItemParams(unsigned _arg0_, unsigned _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::DropItemParams
	// Header:  Prey/GameDll/CryActor.h
	struct DropItemParams
	{ // Size=8 (0x8)
		unsigned itemId;
		bool selectNext;
		bool byDeath;

	#if 0
		DropItemParams();
		DropItemParams(unsigned _arg0_, bool _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::ReviveParams
	// Header:  Prey/GameDll/CryActor.h
	struct ReviveParams
	{ // Size=8 (0x8)
		int teamId;
		uint16_t spawnPointIdx;
		uint8_t physCounter;
		uint8_t modelIndex;

	#if 0
		ReviveParams();
		ReviveParams(uint8_t _arg0_, const uint16_t _arg1_, uint8_t _arg2_, uint8_t _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::KillParams
	// Header:  Prey/GameDll/CryActor.h
	struct KillParams
	{ // Size=68 (0x44)
		unsigned shooterId;
		unsigned targetId;
		unsigned weaponId;
		unsigned projectileId;
		unsigned itemIdToDrop;
		int weaponClassId;
		float damage;
		float impulseScale;
		Vec3 dir;
		int material;
		int hit_type;
		int targetTeam;
		uint16_t hit_joint;
		uint16_t projectileClassId;
		uint8_t penetration;
		bool ragdoll;
		bool winningKill;
		bool firstKill;
		bool bulletTimeReplay;
		bool killViaProxy;
		bool forceLocalKill;
		bool fromSerialize;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		KillParams();
		KillParams(const HitInfo& _arg0_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CCryActor::KillParams* const _this, TSerialize ser)>(0x17CF240);
	};

	// CCryActor::MoveParams
	// Header:  Prey/GameDll/CryActor.h
	struct MoveParams
	{ // Size=28 (0x1C)
		Vec3 pos;
		Quat rot;

	#if 0
		MoveParams();
		MoveParams(const Vec3& _arg0_, const Quat& _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::PickItemParams
	// Header:  Prey/GameDll/CryActor.h
	struct PickItemParams
	{ // Size=8 (0x8)
		unsigned itemId;
		bool select;
		bool sound;
		bool pickOnlyAmmo;

	#if 0
		PickItemParams();
		PickItemParams(unsigned _arg0_, bool _arg1_, bool _arg2_);
		PickItemParams(unsigned _arg0_, bool _arg1_, bool _arg2_, bool _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::NoParams
	// Header:  Prey/GameDll/CryActor.h
	struct NoParams
	{ // Size=1 (0x1)
	#if 0
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CCryActor::KillCamFPData
	// Header:  Prey/GameDll/CryActor.h
	struct KillCamFPData
	{ // Size=64 (0x40)
		static constexpr const int DATASIZE = 50;
		static constexpr const int UNIQPACKETIDS = 16;
		uint8_t m_data[50];
		uint16_t m_size;
		unsigned m_victim;
		uint8_t m_numPacket;
		uint8_t m_packetId;
		uint8_t m_packetType;
		bool m_bFinalPacket;
		bool m_bToEveryone;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		KillCamFPData();
		KillCamFPData(uint8_t _arg0_, uint8_t _arg1_, uint8_t _arg2_, unsigned _arg3_, unsigned _arg4_, void* _arg5_, bool _arg6_, bool _arg7_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CCryActor::KillCamFPData* const _this, TSerialize ser)>(0x17CF0F0);
	};

	// CCryActor::AttachmentsParams
	// Header:  Prey/GameDll/CryActor.h
	struct AttachmentsParams
	{ // Size=144 (0x90)
		// CCryActor::AttachmentsParams::SWeaponAttachment
		// Header:  Prey/GameDll/CryActor.h
		struct SWeaponAttachment
		{ // Size=4 (0x4)
			uint16_t m_classId;
			bool m_default;

		#if 0
			SWeaponAttachment();
			SWeaponAttachment(uint16_t _arg0_, bool _arg1_);
			void SerializeWith(TSerialize _arg0_);
		#endif
		};

		CryFixedArray<CCryActor::AttachmentsParams::SWeaponAttachment,31> m_attachments;
		uint8_t m_loadoutIdx;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		AttachmentsParams();
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CCryActor::AttachmentsParams* const _this, TSerialize ser)>(0x17CEF80);
	};

	// CCryActor::SBlendRagdollParams
	// Header:  Prey/GameDll/CryActor.h
	struct SBlendRagdollParams
	{ // Size=24 (0x18)
		STagState<12> m_blendInTagState;
		STagState<12> m_blendOutTagState;

	#if 0
		SBlendRagdollParams();
	#endif
	};

	// CCryActor::MethodInfo_SvRequestDropItem
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_SvRequestDropItem
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestDropItem(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::DropItemParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_SvRequestDropItem
	// Header:  Prey/GameDll/CryActor.h
	struct Params_SvRequestDropItem
	{ // Size=8 (0x8)
		unsigned itemId;
		bool selectNext;
		bool byDeath;

	#if 0
		void DropItemParams();
		void DropItemParams(unsigned _arg0_, bool _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_SvRequestPickUpItem
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_SvRequestPickUpItem
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestPickUpItem(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::ItemIdParam& _arg0_) const;
	#endif
	};

	// CCryActor::Params_SvRequestPickUpItem
	// Header:  Prey/GameDll/CryActor.h
	struct Params_SvRequestPickUpItem
	{ // Size=8 (0x8)
		unsigned itemId;
		bool pickOnlyAmmo;
		bool select;

	#if 0
		void ItemIdParam();
		void ItemIdParam(unsigned _arg0_);
		void ItemIdParam(unsigned _arg0_, bool _arg1_);
		void ItemIdParam(unsigned _arg0_, bool _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_SvRequestExchangeItem
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_SvRequestExchangeItem
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestExchangeItem(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::ExchangeItemParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_SvRequestExchangeItem
	// Header:  Prey/GameDll/CryActor.h
	struct Params_SvRequestExchangeItem
	{ // Size=8 (0x8)
		unsigned dropItemId;
		unsigned pickUpItemId;

	#if 0
		void ExchangeItemParams();
		void ExchangeItemParams(unsigned _arg0_, unsigned _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_SvRequestUseItem
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_SvRequestUseItem
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestUseItem(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::ItemIdParam& _arg0_) const;
	#endif
	};

	// CCryActor::Params_SvRequestUseItem
	// Header:  Prey/GameDll/CryActor.h
	struct Params_SvRequestUseItem
	{ // Size=8 (0x8)
		unsigned itemId;
		bool pickOnlyAmmo;
		bool select;

	#if 0
		void ItemIdParam();
		void ItemIdParam(unsigned _arg0_);
		void ItemIdParam(unsigned _arg0_, bool _arg1_);
		void ItemIdParam(unsigned _arg0_, bool _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_ClPickUp
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClPickUp
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClPickUp(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::PickItemParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClPickUp
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClPickUp
	{ // Size=8 (0x8)
		unsigned itemId;
		bool select;
		bool sound;
		bool pickOnlyAmmo;

	#if 0
		void PickItemParams();
		void PickItemParams(unsigned _arg0_, bool _arg1_, bool _arg2_);
		void PickItemParams(unsigned _arg0_, bool _arg1_, bool _arg2_, bool _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_ClClearInventory
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClClearInventory
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClClearInventory(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::NoParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClClearInventory
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClClearInventory
	{ // Size=1 (0x1)
	#if 0
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_ClDrop
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClDrop
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClDrop(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::DropItemParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClDrop
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClDrop
	{ // Size=8 (0x8)
		unsigned itemId;
		bool selectNext;
		bool byDeath;

	#if 0
		void DropItemParams();
		void DropItemParams(unsigned _arg0_, bool _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_ClStartUse
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClStartUse
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClStartUse(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::ItemIdParam& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClStartUse
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClStartUse
	{ // Size=8 (0x8)
		unsigned itemId;
		bool pickOnlyAmmo;
		bool select;

	#if 0
		void ItemIdParam();
		void ItemIdParam(unsigned _arg0_);
		void ItemIdParam(unsigned _arg0_, bool _arg1_);
		void ItemIdParam(unsigned _arg0_, bool _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_ClStopUse
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClStopUse
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClStopUse(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::ItemIdParam& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClStopUse
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClStopUse
	{ // Size=8 (0x8)
		unsigned itemId;
		bool pickOnlyAmmo;
		bool select;

	#if 0
		void ItemIdParam();
		void ItemIdParam(unsigned _arg0_);
		void ItemIdParam(unsigned _arg0_, bool _arg1_);
		void ItemIdParam(unsigned _arg0_, bool _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_ClUseRequestProcessed
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClUseRequestProcessed
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClUseRequestProcessed(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::NoParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClUseRequestProcessed
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClUseRequestProcessed
	{ // Size=1 (0x1)
	#if 0
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_ClRevive
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClRevive
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClRevive(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::ReviveParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClRevive
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClRevive
	{ // Size=8 (0x8)
		int teamId;
		uint16_t spawnPointIdx;
		uint8_t physCounter;
		uint8_t modelIndex;

	#if 0
		void ReviveParams();
		void ReviveParams(uint8_t _arg0_, const uint16_t _arg1_, uint8_t _arg2_, uint8_t _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_ClSimpleKill
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClSimpleKill
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClSimpleKill(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::NoParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClSimpleKill
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClSimpleKill
	{ // Size=1 (0x1)
	#if 0
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_ClKill
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClKill
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClKill(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::KillParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClKill
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClKill
	{ // Size=68 (0x44)
		unsigned shooterId;
		unsigned targetId;
		unsigned weaponId;
		unsigned projectileId;
		unsigned itemIdToDrop;
		int weaponClassId;
		float damage;
		float impulseScale;
		Vec3 dir;
		int material;
		int hit_type;
		int targetTeam;
		uint16_t hit_joint;
		uint16_t projectileClassId;
		uint8_t penetration;
		bool ragdoll;
		bool winningKill;
		bool firstKill;
		bool bulletTimeReplay;
		bool killViaProxy;
		bool forceLocalKill;
		bool fromSerialize;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void KillParams();
		void KillParams(const HitInfo& _arg0_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CCryActor::KillParams* const _this, TSerialize ser)>(0x17CF240);
	};

	// CCryActor::MethodInfo_ClMoveTo
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClMoveTo
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClMoveTo(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::MoveParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClMoveTo
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClMoveTo
	{ // Size=28 (0x1C)
		Vec3 pos;
		Quat rot;

	#if 0
		void MoveParams();
		void MoveParams(const Vec3& _arg0_, const Quat& _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CCryActor::MethodInfo_SvKillFPCamData
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_SvKillFPCamData
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvKillFPCamData(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::KillCamFPData& _arg0_) const;
	#endif
	};

	// CCryActor::Params_SvKillFPCamData
	// Header:  Prey/GameDll/CryActor.h
	struct Params_SvKillFPCamData
	{ // Size=64 (0x40)
		static constexpr const int DATASIZE = 50;
		static constexpr const int UNIQPACKETIDS = 16;
		uint8_t m_data[50];
		uint16_t m_size;
		unsigned m_victim;
		uint8_t m_numPacket;
		uint8_t m_packetId;
		uint8_t m_packetType;
		bool m_bFinalPacket;
		bool m_bToEveryone;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void KillCamFPData();
		void KillCamFPData(uint8_t _arg0_, uint8_t _arg1_, uint8_t _arg2_, unsigned _arg3_, unsigned _arg4_, void* _arg5_, bool _arg6_, bool _arg7_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CCryActor::KillCamFPData* const _this, TSerialize ser)>(0x17CF0F0);
	};

	// CCryActor::MethodInfo_ClKillFPCamData
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClKillFPCamData
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClKillFPCamData(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::KillCamFPData& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClKillFPCamData
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClKillFPCamData
	{ // Size=64 (0x40)
		static constexpr const int DATASIZE = 50;
		static constexpr const int UNIQPACKETIDS = 16;
		uint8_t m_data[50];
		uint16_t m_size;
		unsigned m_victim;
		uint8_t m_numPacket;
		uint8_t m_packetId;
		uint8_t m_packetType;
		bool m_bFinalPacket;
		bool m_bToEveryone;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void KillCamFPData();
		void KillCamFPData(uint8_t _arg0_, uint8_t _arg1_, uint8_t _arg2_, unsigned _arg3_, unsigned _arg4_, void* _arg5_, bool _arg6_, bool _arg7_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CCryActor::KillCamFPData* const _this, TSerialize ser)>(0x17CF0F0);
	};

	// CCryActor::MethodInfo_ClAssignWeaponAttachments
	// Header:  Prey/GameDll/CryActor.h
	struct MethodInfo_ClAssignWeaponAttachments
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClAssignWeaponAttachments(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CCryActor::AttachmentsParams& _arg0_) const;
	#endif
	};

	// CCryActor::Params_ClAssignWeaponAttachments
	// Header:  Prey/GameDll/CryActor.h
	struct Params_ClAssignWeaponAttachments
	{ // Size=144 (0x90)
		// CCryActor::AttachmentsParams::SWeaponAttachment
		// Header:  Prey/GameDll/CryActor.h
		struct SWeaponAttachment
		{ // Size=4 (0x4)
			uint16_t m_classId;
			bool m_default;

		#if 0
			SWeaponAttachment();
			SWeaponAttachment(uint16_t _arg0_, bool _arg1_);
			void SerializeWith(TSerialize _arg0_);
		#endif
		};

		CryFixedArray<CCryActor::AttachmentsParams::SWeaponAttachment,31> m_attachments;
		uint8_t m_loadoutIdx;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void AttachmentsParams();
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CCryActor::AttachmentsParams* const _this, TSerialize ser)>(0x17CEF80);
	};

	using TIKLimbs = std::vector<SIKLimb>;

	static constexpr const ERMIAttachmentType Attach_SvRequestDropItem = 2;
	static constexpr const bool ServerCall_SvRequestDropItem = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestDropItem = 0;
	static constexpr const bool LowDelay_SvRequestDropItem = 0;
	static inline auto m_infoSvRequestDropItem = PreyGlobal<CCryActor::MethodInfo_SvRequestDropItem>(0x2D82250);
	static constexpr const ERMIAttachmentType Attach_SvRequestPickUpItem = 2;
	static constexpr const bool ServerCall_SvRequestPickUpItem = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestPickUpItem = 0;
	static constexpr const bool LowDelay_SvRequestPickUpItem = 0;
	static inline auto m_infoSvRequestPickUpItem = PreyGlobal<CCryActor::MethodInfo_SvRequestPickUpItem>(0x2D82258);
	static constexpr const ERMIAttachmentType Attach_SvRequestExchangeItem = 2;
	static constexpr const bool ServerCall_SvRequestExchangeItem = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestExchangeItem = 0;
	static constexpr const bool LowDelay_SvRequestExchangeItem = 0;
	static inline auto m_infoSvRequestExchangeItem = PreyGlobal<CCryActor::MethodInfo_SvRequestExchangeItem>(0x2D82260);
	static constexpr const ERMIAttachmentType Attach_SvRequestUseItem = 3;
	static constexpr const bool ServerCall_SvRequestUseItem = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestUseItem = 0;
	static constexpr const bool LowDelay_SvRequestUseItem = 0;
	static inline auto m_infoSvRequestUseItem = PreyGlobal<CCryActor::MethodInfo_SvRequestUseItem>(0x2D82268);
	static constexpr const ERMIAttachmentType Attach_ClPickUp = 2;
	static constexpr const bool ServerCall_ClPickUp = 0;
	static constexpr const ENetReliabilityType Reliability_ClPickUp = 0;
	static constexpr const bool LowDelay_ClPickUp = 0;
	static inline auto m_infoClPickUp = PreyGlobal<CCryActor::MethodInfo_ClPickUp>(0x2D822A8);
	static constexpr const ERMIAttachmentType Attach_ClClearInventory = 2;
	static constexpr const bool ServerCall_ClClearInventory = 0;
	static constexpr const ENetReliabilityType Reliability_ClClearInventory = 0;
	static constexpr const bool LowDelay_ClClearInventory = 0;
	static inline auto m_infoClClearInventory = PreyGlobal<CCryActor::MethodInfo_ClClearInventory>(0x2D822B0);
	static constexpr const ERMIAttachmentType Attach_ClDrop = 2;
	static constexpr const bool ServerCall_ClDrop = 0;
	static constexpr const ENetReliabilityType Reliability_ClDrop = 0;
	static constexpr const bool LowDelay_ClDrop = 0;
	static inline auto m_infoClDrop = PreyGlobal<CCryActor::MethodInfo_ClDrop>(0x2D822B8);
	static constexpr const ERMIAttachmentType Attach_ClStartUse = 2;
	static constexpr const bool ServerCall_ClStartUse = 0;
	static constexpr const ENetReliabilityType Reliability_ClStartUse = 0;
	static constexpr const bool LowDelay_ClStartUse = 0;
	static inline auto m_infoClStartUse = PreyGlobal<CCryActor::MethodInfo_ClStartUse>(0x2D822C0);
	static constexpr const ERMIAttachmentType Attach_ClStopUse = 2;
	static constexpr const bool ServerCall_ClStopUse = 0;
	static constexpr const ENetReliabilityType Reliability_ClStopUse = 0;
	static constexpr const bool LowDelay_ClStopUse = 0;
	static inline auto m_infoClStopUse = PreyGlobal<CCryActor::MethodInfo_ClStopUse>(0x2D822C8);
	static constexpr const ERMIAttachmentType Attach_ClUseRequestProcessed = 2;
	static constexpr const bool ServerCall_ClUseRequestProcessed = 0;
	static constexpr const ENetReliabilityType Reliability_ClUseRequestProcessed = 0;
	static constexpr const bool LowDelay_ClUseRequestProcessed = 0;
	static inline auto m_infoClUseRequestProcessed = PreyGlobal<CCryActor::MethodInfo_ClUseRequestProcessed>(0x2D82270);
	static constexpr const ERMIAttachmentType Attach_ClRevive = 2;
	static constexpr const bool ServerCall_ClRevive = 0;
	static constexpr const ENetReliabilityType Reliability_ClRevive = 0;
	static constexpr const bool LowDelay_ClRevive = 0;
	static inline auto m_infoClRevive = PreyGlobal<CCryActor::MethodInfo_ClRevive>(0x2D82278);
	static constexpr const ERMIAttachmentType Attach_ClSimpleKill = 2;
	static constexpr const bool ServerCall_ClSimpleKill = 0;
	static constexpr const ENetReliabilityType Reliability_ClSimpleKill = 0;
	static constexpr const bool LowDelay_ClSimpleKill = 0;
	static inline auto m_infoClSimpleKill = PreyGlobal<CCryActor::MethodInfo_ClSimpleKill>(0x2D82298);
	static constexpr const ERMIAttachmentType Attach_ClKill = 3;
	static constexpr const bool ServerCall_ClKill = 0;
	static constexpr const ENetReliabilityType Reliability_ClKill = 0;
	static constexpr const bool LowDelay_ClKill = 0;
	static inline auto m_infoClKill = PreyGlobal<CCryActor::MethodInfo_ClKill>(0x2D82280);
	static constexpr const ERMIAttachmentType Attach_ClMoveTo = 2;
	static constexpr const bool ServerCall_ClMoveTo = 0;
	static constexpr const ENetReliabilityType Reliability_ClMoveTo = 0;
	static constexpr const bool LowDelay_ClMoveTo = 0;
	static inline auto m_infoClMoveTo = PreyGlobal<CCryActor::MethodInfo_ClMoveTo>(0x2D822A0);
	static constexpr const ERMIAttachmentType Attach_SvKillFPCamData = 2;
	static constexpr const bool ServerCall_SvKillFPCamData = 1;
	static constexpr const ENetReliabilityType Reliability_SvKillFPCamData = 1;
	static constexpr const bool LowDelay_SvKillFPCamData = 0;
	static inline auto m_infoSvKillFPCamData = PreyGlobal<CCryActor::MethodInfo_SvKillFPCamData>(0x2D82290);
	static constexpr const ERMIAttachmentType Attach_ClKillFPCamData = 2;
	static constexpr const bool ServerCall_ClKillFPCamData = 0;
	static constexpr const ENetReliabilityType Reliability_ClKillFPCamData = 1;
	static constexpr const bool LowDelay_ClKillFPCamData = 0;
	static inline auto m_infoClKillFPCamData = PreyGlobal<CCryActor::MethodInfo_ClKillFPCamData>(0x2D82288);
	static constexpr const ERMIAttachmentType Attach_ClAssignWeaponAttachments = 2;
	static constexpr const bool ServerCall_ClAssignWeaponAttachments = 0;
	static constexpr const ENetReliabilityType Reliability_ClAssignWeaponAttachments = 0;
	static constexpr const bool LowDelay_ClAssignWeaponAttachments = 0;
	static inline auto m_infoClAssignWeaponAttachments = PreyGlobal<CCryActor::MethodInfo_ClAssignWeaponAttachments>(0x2D822D0);
	static inline auto DEFAULT_ENTITY_CLASS_NAME = PreyGlobal<const char [0]>(0x1FB4AF0);
	static inline auto s_animationEventsTable = PreyGlobal<SActorAnimationEvents>(0x2D821E0);
	unsigned m_lastNetItemId;
	bool m_isClient;
	bool m_isPlayer;
	bool m_isMigrating;
	CHealth m_health;
	std::shared_ptr<CCryActor> m_pThis;
	IInventory* m_pInventory;
	CCoherentValue<enum EStance> m_internalStance;
	EStance m_desiredStance;
	static inline auto m_defaultStance = PreyGlobal<SStanceInfo>(0x23EF080);
	SStanceInfo m_stances[18];
	EStance m_lockedStance;
	SActorParams m_params;
	IAnimatedCharacter* m_pAnimatedCharacter;
	IActorMovementController* m_pMovementController;
	std::shared_ptr<CActorImpulseHandler> m_pImpulseHandler;
	static inline auto m_pItemSystem = PreyGlobal<IItemSystem*>(0x2D821C0);
	static inline auto m_pGameFramework = PreyGlobal<IGameFramework*>(0x2D821C8);
	static inline auto m_pGameplayRecorder = PreyGlobal<IGameplayRecorder*>(0x2D821D0);
	SLinkStats m_linkStats;
	std::vector<SIKLimb> m_IKLimbs;
	uint8_t m_currentPhysProfile;
	float m_airControl;
	float m_airResistance;
	float m_inertia;
	float m_inertiaAccel;
	float m_timeImpulseRecover;
	unsigned m_netLastSelectablePickedUp;
	unsigned m_pendingDropEntityId;
	string m_currModel;
	string m_currShadowModel;
	_smart_ptr<SLuaCache_ActorPhysicsParams> m_LuaCache_PhysicsParams;
	_smart_ptr<SLuaCache_ActorGameParams> m_LuaCache_GameParams;
	_smart_ptr<SLuaCache_ActorProperties> m_LuaCache_Properties;
	float m_lastUnCloakTime;
	float m_spectateSwitchTime;
	float m_fAwaitingServerUseResponse;
	int m_teamId;
	bool m_IsImmuneToForbiddenZone;
	bool m_enableSwitchingItems;
	bool m_enableIronSights;
	bool m_enablePickupItems;
	bool m_cloakLayerActive;
	uint8_t m_netPhysCounter;
	bool m_registeredAnimationDBAs;
	bool m_bAllowHitImpulses;
	bool m_bAwaitingServerUseResponse;
	bool m_shouldPlayHitReactions;
	int16_t m_boneIDs[17];
	QuatT m_boneTrans[17];
	SActorPhysics m_actorPhysics;
	CCryActor::SBlendRagdollParams m_blendRagdollParams;
	IPhysicalEntity* m_pLegsCollider[2];
	IPhysicalEntity* m_pLegsFrame;
	IPhysicalEntity* m_pLegsIgnoredCollider;
	int m_iboneLeg[2];
	Vec3 m_ptSample[2];
	char m_bLegActive[2];
	unsigned m_DefaultBodyDamageProfileId;
	CBodyDestrutibilityInstance m_bodyDestructionInstance;
	unsigned m_OverrideBodyDamageProfileId;
	string m_sLipSyncExtensionType;

	static INetAtSyncItem* Decode_SvRequestDropItem(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestDropItem(ser, pID, pChannel); }
	bool Handle_SvRequestDropItem(const CCryActor::DropItemParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestDropItem(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestPickUpItem(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestPickUpItem(ser, pID, pChannel); }
	bool Handle_SvRequestPickUpItem(const CCryActor::ItemIdParam& params, INetChannel* pNetChannel) { return FHandle_SvRequestPickUpItem(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestExchangeItem(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestExchangeItem(ser, pID, pChannel); }
	bool Handle_SvRequestExchangeItem(const CCryActor::ExchangeItemParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestExchangeItem(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestUseItem(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestUseItem(ser, pID, pChannel); }
	bool Handle_SvRequestUseItem(const CCryActor::ItemIdParam& params, INetChannel* pNetChannel) { return FHandle_SvRequestUseItem(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClPickUp(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClPickUp(ser, pID, pChannel); }
	bool Handle_ClPickUp(const CCryActor::PickItemParams& params, INetChannel* pNetChannel) { return FHandle_ClPickUp(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClClearInventory(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClClearInventory(ser, pID, pChannel); }
	bool Handle_ClClearInventory(const CCryActor::NoParams& params, INetChannel* pNetChannel) { return FHandle_ClClearInventory(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClDrop(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClDrop(ser, pID, pChannel); }
	bool Handle_ClDrop(const CCryActor::DropItemParams& params, INetChannel* pNetChannel) { return FHandle_ClDrop(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClStartUse(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClStartUse(ser, pID, pChannel); }
	bool Handle_ClStartUse(const CCryActor::ItemIdParam& params, INetChannel* pNetChannel) { return FHandle_ClStartUse(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClStopUse(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClStopUse(ser, pID, pChannel); }
	bool Handle_ClStopUse(const CCryActor::ItemIdParam& params, INetChannel* pNetChannel) { return FHandle_ClStopUse(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClUseRequestProcessed(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClUseRequestProcessed(ser, pID, pChannel); }
	bool Handle_ClUseRequestProcessed(const CCryActor::NoParams& params, INetChannel* pNetChannel) { return FHandle_ClUseRequestProcessed(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClRevive(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClRevive(ser, pID, pChannel); }
	bool Handle_ClRevive(const CCryActor::ReviveParams& params, INetChannel* pNetChannel) { return FHandle_ClRevive(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClSimpleKill(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClSimpleKill(ser, pID, pChannel); }
	bool Handle_ClSimpleKill(const CCryActor::NoParams& params, INetChannel* pNetChannel) { return FHandle_ClSimpleKill(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClKill(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClKill(ser, pID, pChannel); }
	bool Handle_ClKill(const CCryActor::KillParams& params, INetChannel* pNetChannel) { return FHandle_ClKill(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClMoveTo(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClMoveTo(ser, pID, pChannel); }
	bool Handle_ClMoveTo(const CCryActor::MoveParams& params, INetChannel* pNetChannel) { return FHandle_ClMoveTo(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvKillFPCamData(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvKillFPCamData(ser, pID, pChannel); }
	bool Handle_SvKillFPCamData(const CCryActor::KillCamFPData& params, INetChannel* pNetChannel) { return FHandle_SvKillFPCamData(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClKillFPCamData(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClKillFPCamData(ser, pID, pChannel); }
	bool Handle_ClKillFPCamData(const CCryActor::KillCamFPData& params, INetChannel* pNetChannel) { return FHandle_ClKillFPCamData(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClAssignWeaponAttachments(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClAssignWeaponAttachments(ser, pID, pChannel); }
	bool Handle_ClAssignWeaponAttachments(const CCryActor::AttachmentsParams& params, INetChannel* pNetChannel) { return FHandle_ClAssignWeaponAttachments(this, params, pNetChannel); }
	CItem* GetItem(unsigned itemId) const { return FGetItem(this, itemId); }
	void HideLeftHandObject(bool inHide) { FHideLeftHandObject(this, inHide); }
	unsigned ComputeNextItem(const int startSlot, const int category, const int delta, bool& inOutKeepHistory, IItem* pCurrentItem, const bool currWeaponExplosive) const { return FComputeNextItem(this, startSlot, category, delta, inOutKeepHistory, pCurrentItem, currWeaponExplosive); }
	virtual void SelectNextItem(int direction, bool keepHistory, int category);
	virtual void SwitchToWeaponWithAccessoryFireMode();
	virtual void HolsterItem(bool holster, bool playSelect, float selectSpeedBias, bool hideLeftHandObject);
	virtual void SelectLastItem(bool keepHistory, bool forceNext);
	virtual void SelectItemByName(const char* name, bool keepHistory, bool forceFastSelect);
	virtual void SelectItem(unsigned itemId, bool keepHistory, bool forceSelect);
	virtual bool ScheduleItemSwitch(unsigned itemId, bool keepHistory, int category, bool forceFastSelect);
	void ClearItemActionControllers() { FClearItemActionControllers(this); }
	virtual bool UseItem(unsigned itemId);
	virtual bool PickUpItem(unsigned itemId, bool sound, bool select);
	virtual bool DropItem(unsigned itemId, float impulseScale, bool selectNext, bool bydeath);
	virtual void DropAttachedItems();
	void ServerExchangeItem(CItem* pCurrentItem, CItem* pNewItem) { FServerExchangeItem(this, pCurrentItem, pNewItem); }
	void NetReviveAt(const Vec3& pos, const Quat& rot, int teamId, uint8_t modelIndex) { FNetReviveAt(this, pos, rot, teamId, modelIndex); }
	virtual void NetSimpleKill();
	virtual void NetKill(const CCryActor::KillParams& killParams);
	virtual bool CanRagDollize() const;
	virtual bool IsStillWaitingOnServerUseResponse() const;
	virtual void SetStillWaitingOnServerUseResponse(bool waiting);
	CCryActor();
	virtual ~CCryActor();
	virtual void ProcessEvent(SEntityEvent& event);
	virtual int GetEventPriority(const int eventID) const;
	virtual void Release();
	virtual void ResetAnimationState();
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags);
	virtual void PostSerialize();
	virtual void SetChannelId(uint16_t id);
	virtual void SerializeLevelToLevel(TSerialize& ser);
	virtual IInventory* GetInventory() const;
	virtual void NotifyCurrentItemChanged(IItem* newItem);
	virtual bool IsPlayer() const;
	virtual bool IsClient() const;
	virtual bool IsMigrating() const;
	virtual void SetMigrating(bool isMigrating);
	virtual bool Init(IGameObject* pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Update(SEntityUpdateContext& ctx, int slot);
	virtual void UpdateView(SViewParams& viewParams);
	virtual void PostUpdateView(SViewParams& viewParams);
	void UpdateBodyDestruction(float frameTime) { FUpdateBodyDestruction(this, frameTime); }
	virtual void ReadDataFromXML(bool isReloading);
	virtual void InitLocalPlayer();
	virtual void SetIKPos(const char* pLimbName, const Vec3& goalPos, int priority);
	virtual void HandleEvent(const SGameObjectEvent& event);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual bool IsThirdPerson() const;
	virtual void ToggleThirdPerson();
	virtual void RequestFacialExpression(const char* pExpressionName, float* sequenceLength);
	virtual void PrecacheFacialExpression(const char* pExpressionName);
	virtual void NotifyInventoryAmmoChange(IEntityClass* pAmmoClass, int amount);
	virtual unsigned GetGrabbedEntityId() const;
	virtual void HideAllAttachments(bool isHiding);
	virtual void OnAIProxyEnabled(bool enabled);
	virtual void OnReturnedToPool();
	virtual void OnPreparedFromPool();
	virtual void OnReused(IEntity* pEntity, SEntitySpawnParams& params);
	virtual bool SetAspectProfile(EEntityAspects aspect, uint8_t profile);
	virtual uint8_t GetDefaultProfile(EEntityAspects aspect);
	virtual void OnAction(const CCryName& actionId, int activationMode, float value);
	virtual void SetViewRotation(const Quat& rotation);
	virtual Quat GetViewRotation() const;
	virtual void EnableTimeDemo(bool bTimeDemo);
	virtual void AddViewAngleOffsetForFrame(const Ang3& offset);
	virtual void Revive(CCryActor::EReasonForRevive reasonForRevive);
	virtual void Reset(bool toGame);
	static bool LoadPhysicsParams(SmartScriptTable pEntityTable, const char* szEntityClassName, SEntityPhysicalizeParams& outPhysicsParams, pe_player_dimensions& outPlayerDim, pe_player_dynamics& outPlayerDyn) { return FLoadPhysicsParams(pEntityTable, szEntityClassName, outPhysicsParams, outPlayerDim, outPlayerDyn); }
	virtual void Physicalize(EStance stance);
	virtual void PostPhysicalize();
	virtual void RagDollize(bool fallAndPlay);
	void ShutDown() { FShutDown(this); }
	virtual int IsGod();
	virtual void OnTeleported();
	virtual void SetSpectatorState(uint8_t state);
	virtual CCryActor::EActorSpectatorState GetSpectatorState() const;
	virtual float GetSpectatorOrbitYawSpeed() const;
	virtual void SetSpectatorOrbitYawSpeed(float yawSpeed, bool singleFrame);
	virtual bool CanSpectatorOrbitYaw() const;
	virtual float GetSpectatorOrbitPitchSpeed() const;
	virtual void SetSpectatorOrbitPitchSpeed(float pitchSpeed, bool singleFrame);
	virtual bool CanSpectatorOrbitPitch() const;
	virtual void ChangeCurrentFollowCameraSettings(bool increment);
	virtual void SetSpectatorModeAndOtherEntId(const uint8_t _mode, const unsigned _othEntId, bool isSpawning);
	virtual uint8_t GetSpectatorMode() const;
	virtual void SetSpectatorTarget(unsigned targetId);
	virtual unsigned GetSpectatorTarget() const;
	virtual void SetSpectatorFixedLocation(unsigned locId);
	virtual unsigned GetSpectatorFixedLocation() const;
	virtual SActorStats* GetActorStats();
	virtual const SActorStats* GetActorStats() const;
	virtual void SetStats(SmartScriptTable& rTable);
	virtual ICharacterInstance* GetFPArms(int i) const;
	static bool LoadGameParams(SmartScriptTable pEntityTable, SActorGameParams& outGameParams) { return FLoadGameParams(pEntityTable, outGameParams); }
	static bool LoadDynamicAimPoseElement(CScriptSetGetChain& gameParamsTableChain, const char* szName, string& output) { return FLoadDynamicAimPoseElement(gameParamsTableChain, szName, output); }
	void InitGameParams() { FInitGameParamsOv1(this); }
	virtual void InitGameParams(const SActorGameParams& gameParams, const bool reloadCharacterSounds);
	virtual void SetParamsFromLua(SmartScriptTable& rTable);
	virtual void Freeze(bool freeze);
	virtual void Fall(Vec3 hitPos);
	virtual void Fall(const HitInfo& hitInfo);
	virtual void KnockDown(float backwardsImpulse);
	virtual void SetLookAtTargetId(unsigned targetIdsp, float interpolationTime);
	virtual void SetForceLookAtTargetId(unsigned targetId, float interpolationTime);
	virtual void StandUp();
	virtual bool IsFallen() const;
	virtual bool IsDead() const;
	virtual void LinkToMountedWeapon(unsigned weaponId);
	virtual IEntity* LinkToEntity(unsigned entityId, bool bKeepTransformOnDetach);
	virtual void StartInteractiveAction(unsigned entityId, int interactionIndex);
	virtual void StartInteractiveActionByName(const char* interaction, bool bUpdateVisibility, float actionSpeed);
	virtual void EndInteractiveAction(unsigned entityId);
	virtual bool AllowLandingBob();
	virtual IEntity* GetLinkedEntity() const;
	virtual void SupressViewBlending();
	virtual void PlayAction(const char* action, const char* extension, bool looping);
	virtual void SetMovementTarget(const Vec3& position, const Vec3& looktarget, const Vec3& up, float speed);
	virtual void CreateScriptEvent(const char* event, float value, const char* str);
	virtual bool CreateCodeEvent(SmartScriptTable& rTable);
	virtual void SetTurnAnimationParams(const float turnThresholdAngle, const float turnThresholdTime);
	virtual void CameraShake(float angle, float shift, float duration, float frequency, Vec3 pos, int ID, const char* source);
	virtual void SetAngles(const Ang3& angles);
	virtual Ang3 GetAngles();
	virtual void AddAngularImpulse(const Ang3& angular, float deceleration, float duration);
	virtual void SetViewLimits(Vec3 dir, float rangeH, float rangeV);
	virtual void DamageInfo(unsigned shooterID, unsigned weaponID, IEntityClass* pProjectileClass, float damage, int damageType, const Vec3 hitDirection);
	virtual IAnimatedCharacter* GetAnimatedCharacter();
	virtual const IAnimatedCharacter* GetAnimatedCharacter() const;
	virtual void PlayExactPositioningAnimation(const char* sAnimationName, bool bSignal, const Vec3& vPosition, const Vec3& vDirection, float startWidth, float startArcAngle, float directionTolerance);
	virtual void CancelExactPositioningAnimation();
	virtual void PlayAnimation(const char* sAnimationName, bool bSignal);
	virtual unsigned GetCurrentTargetEntityId() const;
	virtual const Vec3* GetCurrentTargetPos() const;
	virtual void SetMaxHealth(float maxHealth);
	virtual float GetMaxHealth() const;
	virtual void SetHealth(float health);
	virtual float GetHealth() const;
	virtual int GetHealthAsRoundedPercentage() const;
	virtual int GetArmor() const;
	virtual int GetMaxArmor() const;
	virtual int GetTeamId() const;
	virtual void Kill();
	virtual CCryActor* ToCryActor();
	const bool ImmuneToForbiddenZone() const { return FImmuneToForbiddenZoneOv0(this); }
	virtual bool IsSwimming() const;
	virtual bool IsHeadUnderWater() const;
	virtual bool IsSprinting() const;
	virtual bool CanFire() const;
	virtual EStance GetStance() const;
	virtual void SetLockedStance(EStance _stance);
	virtual EStance GetLockedStance();
	virtual void UnlockStance();
	void QueueAnimationState(const char* state) { FQueueAnimationState(this, state); }
	virtual const QuatT& GetBoneTransform(int ID) const;
	virtual Vec3 GetLocalEyePos() const;
	QuatT GetCameraTran() const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetCameraTran(this, reinterpret_cast<QuatT*>(_return_buf_)); }
	virtual void UpdateMountedGunController(bool forceIKUpdate);
	virtual void OnPhysicsPreStep(float frameTime);
	virtual bool CheckInventoryRestrictions(const char* itemClassName);
	void ProcessIKLimbs(float frameTime) { FProcessIKLimbs(this, frameTime); }
	void CreateIKLimb(const SActorIKLimbInfo& limbInfo) { FCreateIKLimb(this, limbInfo); }
	virtual IMovementController* GetMovementController() const;
	void OnSetStance(EStance desiredStance) { FOnSetStance(this, desiredStance); }
	virtual void SetStance(EStance desiredStance);
	virtual void OnStanceChanged(EStance newStance, EStance oldStance);
	virtual bool TrySetStance(EStance stance);
	virtual void SetCloakLayer(bool set, CCryActor::eFadeRules config);
	virtual IAnimationGraphState* GetAnimationGraphState();
	virtual void SetFacialAlertnessLevel(int alertness);
	virtual IItem* GetCurrentItem() const;
	unsigned GetCurrentItemId() const { return FGetCurrentItemId(this); }
	virtual IItem* GetHolsteredItem() const;
	unsigned NetGetCurrentItem() const { return FNetGetCurrentItem(this); }
	void NetSetCurrentItem(unsigned id, bool forceDeselect) { FNetSetCurrentItem(this, id, forceDeselect); }
	void NetSetScheduledItem(unsigned id) { FNetSetScheduledItem(this, id); }
	virtual void SwitchDemoModeSpectator(bool activate);
	void ReloadBodyDestruction() { FReloadBodyDestruction(this); }
	float GetBodyDamageMultiplier(const HitInfo& hitInfo) const { return FGetBodyDamageMultiplier(this, hitInfo); }
	float GetBodyExplosionDamageMultiplier(const HitInfo& hitInfo) const { return FGetBodyExplosionDamageMultiplier(this, hitInfo); }
	unsigned GetBodyDamagePartFlags(const int partID, const int materialID) const { return FGetBodyDamagePartFlags(this, partID, materialID); }
	unsigned GetBodyDamageProfileID(const char* bodyDamageFileName, const char* bodyDamagePartsFileName) const { return FGetBodyDamageProfileID(this, bodyDamageFileName, bodyDamagePartsFileName); }
	void OverrideBodyDamageProfileID(const unsigned profileID) { FOverrideBodyDamageProfileID(this, profileID); }
	void FillHitInfoFromKillParams(const CCryActor::KillParams& killParams, HitInfo& hitInfo) const { FFillHitInfoFromKillParams(this, killParams, hitInfo); }
	void ProcessDestructiblesHit(const HitInfo& hitInfo, const float previousHealth, const float newHealth) { FProcessDestructiblesHit(this, hitInfo, previousHealth, newHealth); }
	void ProcessDestructiblesOnExplosion(const HitInfo& hitInfo, const float previousHealth, const float newHealth) { FProcessDestructiblesOnExplosion(this, hitInfo, previousHealth, newHealth); }
	virtual const char* GetActorClassName() const;
	const IItemParamsNode* GetActorParamsNode() const { return FGetActorParamsNode(this); }
	virtual int GetActorClass() const;
	virtual const char* GetEntityClassName() const;
	bool IsPoolEntity() const { return FIsPoolEntity(this); }
	virtual void SetAnimTentacleParams(pe_params_rope& rope, float animBlend);
	virtual bool IsCloaked() const;
	virtual void DumpActorInfo();
	virtual bool IsFriendlyEntity(unsigned entityId, bool bUsingAIIgnorePlayer) const;
	virtual float GetReloadSpeedScale() const;
	virtual float GetOverchargeDamageScale() const;
	void EnableSwitchingItems(bool enable) { FEnableSwitchingItems(this, enable); }
	virtual void BecomeRemotePlayer();
	virtual bool BecomeAggressiveToAgent(unsigned agentID);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	void GetInternalMemoryUsage(ICrySizer* s) const { FGetInternalMemoryUsage(this, s); }
	static bool LoadFileModelInfo(SmartScriptTable pEntityTable, SmartScriptTable pProperties, SActorFileModelInfo& outFileModelInfo) { return FLoadFileModelInfo(pEntityTable, pProperties, outFileModelInfo); }
	virtual bool SetActorModel(const char* modelName);
	void UpdateActorModel() { FUpdateActorModel(this); }
	bool FullyUpdateActorModel() { return FFullyUpdateActorModel(this); }
	void InvalidateCurrentModelName() { FInvalidateCurrentModelName(this); }
	virtual void PrepareLuaCache();
	void LockInteractor(unsigned lockId, bool lock) { FLockInteractor(this, lockId, lock); }
	virtual bool IsRemote() const;
	virtual void EnableStumbling(PlayerActor::Stumble::StumbleParameters* stumbleParameters);
	virtual void DisableStumbling();
	virtual const float GetCloakBlendSpeedScale();
	unsigned SimpleFindItemIdInCategory(const char* category) const { return FSimpleFindItemIdInCategory(this, category); }
	void SetTag(int tagId, bool enable) { FSetTag(this, tagId, enable); }
	bool IsInMercyTime() const { return FIsInMercyTime(this); }
	void OnSpectateModeStatusChanged(bool spectate) { FOnSpectateModeStatusChanged(this, spectate); }
	virtual bool ShouldMuteWeaponSoundStimulus() const;
	void AcquireOrReleaseLipSyncExtension() { FAcquireOrReleaseLipSyncExtension(this); }
	virtual IArkSpeaker* GetArkSpeaker();
	void GenerateBlendRagdollTags() { FGenerateBlendRagdollTags(this); }
	void PhysicalizeLocalPlayerAdditionalParts() { FPhysicalizeLocalPlayerAdditionalParts(this); }
	bool SetActorModelFromScript() { return FSetActorModelFromScript(this); }
	bool SetActorModelInternal(const char* modelName) { return FSetActorModelInternalOv1(this, modelName); }
	bool SetActorModelInternal(const SActorFileModelInfo& fileModelInfo) { return FSetActorModelInternalOv0(this, fileModelInfo); }
	virtual IActorMovementController* CreateMovementController() = 0;
	void RegisterDBAGroups() { FRegisterDBAGroups(this); }
	virtual void SetModelIndex(uint8_t modelIndex);
	bool GetRagdollContext(CProceduralContextRagdoll* * ppRagdollContext) const { return FGetRagdollContext(this, ppRagdollContext); }
	void PhysicalizeBodyDamage() { FPhysicalizeBodyDamage(this); }
	void UpdateAutoDisablePhys(bool bRagdoll) { FUpdateAutoDisablePhys(this, bRagdoll); }
	virtual bool UpdateStance();
	void UpdateLegsColliders() { FUpdateLegsColliders(this); }
	void ReleaseLegsColliders() { FReleaseLegsColliders(this); }

#if 0
	static const CCryActor::MethodInfo_SvRequestDropItem& SvRequestDropItem();
	static const CCryActor::MethodInfo_SvRequestPickUpItem& SvRequestPickUpItem();
	static const CCryActor::MethodInfo_SvRequestExchangeItem& SvRequestExchangeItem();
	static const CCryActor::MethodInfo_SvRequestUseItem& SvRequestUseItem();
	static const CCryActor::MethodInfo_ClPickUp& ClPickUp();
	static const CCryActor::MethodInfo_ClClearInventory& ClClearInventory();
	static const CCryActor::MethodInfo_ClDrop& ClDrop();
	static const CCryActor::MethodInfo_ClStartUse& ClStartUse();
	static const CCryActor::MethodInfo_ClStopUse& ClStopUse();
	static const CCryActor::MethodInfo_ClUseRequestProcessed& ClUseRequestProcessed();
	static const CCryActor::MethodInfo_ClRevive& ClRevive();
	static const CCryActor::MethodInfo_ClSimpleKill& ClSimpleKill();
	static const CCryActor::MethodInfo_ClKill& ClKill();
	static const CCryActor::MethodInfo_ClMoveTo& ClMoveTo();
	static const CCryActor::MethodInfo_SvKillFPCamData& SvKillFPCamData();
	static const CCryActor::MethodInfo_ClKillFPCamData& ClKillFPCamData();
	static const CCryActor::MethodInfo_ClAssignWeaponAttachments& ClAssignWeaponAttachments();
	CItem* GetItemByClass(IEntityClass* _arg0_) const;
	void CancelScheduledSwitch();
	void ExchangeItem(CItem* _arg0_, CItem* _arg1_);
	bool PickUpItemAmmo(unsigned _arg0_);
	bool PickUpArkItem(unsigned _arg0_);
	bool DropArkItem(unsigned _arg0_);
	void ForceRagdollizeAndApplyImpulse(const HitInfo& _arg0_);
	void UpdateServerResponseTimeOut(const float _arg0_);
	void OnHostMigrationCompleted();
	void SetGrabbedByPlayer(IEntity* _arg0_, bool _arg1_);
	float GetAirControl() const;
	float GetAirResistance() const;
	float GetInertia() const;
	float GetInertiaAccel() const;
	float GetTimeImpulseRecover() const;
	SActorParams& GetActorParams();
	const SActorParams& GetActorParams() const;
	float GetSpeedMultiplier(SActorParams::ESpeedMultiplierReason _arg0_);
	void SetSpeedMultipler(SActorParams::ESpeedMultiplierReason _arg0_, float _arg1_);
	void MultSpeedMultiplier(SActorParams::ESpeedMultiplierReason _arg0_, float _arg1_);
	void SetStanceMaxSpeed(unsigned _arg0_, float _arg1_);
	float GetLookFOV(const SActorParams& _arg0_) const;
	unsigned GetAimIKLayer(const SActorParams& _arg0_) const;
	unsigned GetLookIKLayer(const SActorParams& _arg0_) const;
	Vec3 GetLBodyCenter();
	Vec3 GetWBodyCenter();
	void ImmuneToForbiddenZone(const bool _arg0_);
	void NotifyInventoryAboutOwnerActivation();
	void NotifyInventoryAboutOwnerDeactivation();
	const SStanceInfo* GetStanceInfo(EStance _arg0_) const;
	std::weak_ptr<CCryActor> GetWeakPtr() const;
	int GetBoneID(int _arg0_) const;
	bool HasBoneID(int _arg0_) const;
	QuatT GetHUDTran() const;
	static const SActorAnimationEvents& GetAnimationEventsTable();
	int GetIKLimbIndex(const char* _arg0_);
	SIKLimb* GetIKLimb(int _arg0_);
	std::shared_ptr<CActorImpulseHandler> GetImpulseHander();
	unsigned GetHolsteredItemId() const;
	void ProceduralRecoil(float _arg0_, float _arg1_, float _arg2_, int _arg3_);
	unsigned NetGetScheduledItem() const;
	unsigned GetCurrentBodyDamageProfileId() const;
	const CBodyDestrutibilityInstance& GetBodyDestructibilityInstance() const;
	bool IsHeadShot(const HitInfo& _arg0_) const;
	bool IsHelmetShot(const HitInfo& _arg0_) const;
	bool IsGroinShot(const HitInfo& _arg0_) const;
	bool IsFootShot(const HitInfo& _arg0_) const;
	bool IsKneeShot(const HitInfo& _arg0_) const;
	bool IsWeakSpotShot(const HitInfo& _arg0_) const;
	static int GetActorClassType();
	const IItemParamsNode* GetEntityClassParamsNode() const;
	bool AllowSwitchingItems();
	void EnableIronSights(bool _arg0_);
	void EnablePickingUpItems(bool _arg0_);
	bool CanUseIronSights() const;
	bool CanPickupItems() const;
	uint8_t GetNetPhysCounter();
	bool AllowPhysicsUpdate(uint8_t _arg0_) const;
	static bool AllowPhysicsUpdate(uint8_t _arg0_, uint8_t _arg1_);
	void AddLocalHitImpulse(const SHitImpulse& _arg0_);
	float GetLastUnCloakTime();
	const char* GetShadowFileModel();
	void CloakSyncAttachments(bool _arg0_);
	void CloakSyncEntity(unsigned _arg0_, bool _arg1_);
	void SetTagByCRC(unsigned _arg0_, bool _arg1_);
	const SActorPhysics& GetActorPhysics() const;
	bool CanSwitchSpectatorStatus() const;
	void OnFall(const HitInfo& _arg0_);
	const CCryActor::SBlendRagdollParams& GetBlendRagdollParams() const;
	void EnableHitReactions();
	void DisableHitReactions();
	bool ShouldPlayHitReactions() const;
	unsigned GetPendingDropEntityId() const;
	static IAttachment* GetOrCreateAttachment(IAttachmentManager* _arg0_, const char* _arg1_, const char* _arg2_);
	void CloakSyncAttachment(IAttachment* _arg0_, bool _arg1_);
	void RebindScript();
	void UnRegisterDBAGroups();
	CItem* StartRevive(int _arg0_);
	void FinishRevive(CItem* _arg0_);
	void SelectWeaponWithAmmo(unsigned _arg0_, bool _arg1_);
	void AttemptToRecycleAIActor();
	bool IsBodyDamageFlag(const HitInfo& _arg0_, EBodyDamagePIDFlags _arg1_) const;
	void SetupLocalPlayer();
	void RequestServerResync();
	unsigned GetLeftHandObject() const;
#endif

	static inline auto FDecode_SvRequestDropItem = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C2470);
	static inline auto FHandle_SvRequestDropItem = PreyFunction<bool(CCryActor* const _this, const CCryActor::DropItemParams& params, INetChannel* pNetChannel)>(0x17C5500);
	static inline auto FDecode_SvRequestPickUpItem = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C27A0);
	static inline auto FHandle_SvRequestPickUpItem = PreyFunction<bool(CCryActor* const _this, const CCryActor::ItemIdParam& params, INetChannel* pNetChannel)>(0x17C5630);
	static inline auto FDecode_SvRequestExchangeItem = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C2620);
	static inline auto FHandle_SvRequestExchangeItem = PreyFunction<bool(CCryActor* const _this, const CCryActor::ExchangeItemParams& params, INetChannel* pNetChannel)>(0x17C5560);
	static inline auto FDecode_SvRequestUseItem = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C2950);
	static inline auto FHandle_SvRequestUseItem = PreyFunction<bool(CCryActor* const _this, const CCryActor::ItemIdParam& params, INetChannel* pNetChannel)>(0x17C5750);
	static inline auto FDecode_ClPickUp = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C1960);
	static inline auto FHandle_ClPickUp = PreyFunction<bool(CCryActor* const _this, const CCryActor::PickItemParams& params, INetChannel* pNetChannel)>(0x17C4CF0);
	static inline auto FDecode_ClClearInventory = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C10D0);
	static inline auto FHandle_ClClearInventory = PreyFunction<bool(CCryActor* const _this, const CCryActor::NoParams& params, INetChannel* pNetChannel)>(0x17C4840);
	static inline auto FDecode_ClDrop = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C1210);
	static inline auto FHandle_ClDrop = PreyFunction<bool(CCryActor* const _this, const CCryActor::DropItemParams& params, INetChannel* pNetChannel)>(0x17C4870);
	static inline auto FDecode_ClStartUse = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C1E40);
	static inline auto FHandle_ClStartUse = PreyFunction<bool(CCryActor* const _this, const CCryActor::ItemIdParam& params, INetChannel* pNetChannel)>(0x17C5410);
	static inline auto FDecode_ClStopUse = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C1FF0);
	static inline auto FHandle_ClStopUse = PreyFunction<bool(CCryActor* const _this, const CCryActor::ItemIdParam& params, INetChannel* pNetChannel)>(0x17C5470);
	static inline auto FDecode_ClUseRequestProcessed = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C21A0);
	static inline auto FHandle_ClUseRequestProcessed = PreyFunction<bool(CCryActor* const _this, const CCryActor::NoParams& params, INetChannel* pNetChannel)>(0x17C54E0);
	static inline auto FDecode_ClRevive = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C1B30);
	static inline auto FHandle_ClRevive = PreyFunction<bool(CCryActor* const _this, const CCryActor::ReviveParams& params, INetChannel* pNetChannel)>(0x17C4DA0);
	static inline auto FDecode_ClSimpleKill = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C1D00);
	static inline auto FHandle_ClSimpleKill = PreyFunction<bool(CCryActor* const _this, const CCryActor::NoParams& params, INetChannel* pNetChannel)>(0x17C53F0);
	static inline auto FDecode_ClKill = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C13C0);
	static inline auto FHandle_ClKill = PreyFunction<bool(CCryActor* const _this, const CCryActor::KillParams& params, INetChannel* pNetChannel)>(0x17C4900);
	static inline auto FDecode_ClMoveTo = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C1790);
	static inline auto FHandle_ClMoveTo = PreyFunction<bool(CCryActor* const _this, const CCryActor::MoveParams& params, INetChannel* pNetChannel)>(0x17C4B20);
	static inline auto FDecode_SvKillFPCamData = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C22E0);
	static inline auto FHandle_SvKillFPCamData = PreyFunction<bool(CCryActor* const _this, const CCryActor::KillCamFPData& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClKillFPCamData = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C1600);
	static inline auto FHandle_ClKillFPCamData = PreyFunction<bool(CCryActor* const _this, const CCryActor::KillCamFPData& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClAssignWeaponAttachments = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x17C0EF0);
	static inline auto FHandle_ClAssignWeaponAttachments = PreyFunction<bool(CCryActor* const _this, const CCryActor::AttachmentsParams& params, INetChannel* pNetChannel)>(0x17C4750);
	static inline auto FGetItem = PreyFunction<CItem* (const CCryActor* const _this, unsigned itemId)>(0x17C3E90);
	static inline auto FHideLeftHandObject = PreyFunction<void(CCryActor* const _this, bool inHide)>(0x17C58E0);
	static inline auto FComputeNextItem = PreyFunction<unsigned(const CCryActor* const _this, const int startSlot, const int category, const int delta, bool& inOutKeepHistory, IItem* pCurrentItem, const bool currWeaponExplosive)>(0x17C0950);
	static inline auto FSelectNextItem = PreyFunction<void(CCryActor* const _this, int direction, bool keepHistory, int category)>(0x17CE750);
	static inline auto FSwitchToWeaponWithAccessoryFireMode = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FHolsterItem = PreyFunction<void(CCryActor* const _this, bool holster, bool playSelect, float selectSpeedBias, bool hideLeftHandObject)>(0x17C59B0);
	static inline auto FSelectLastItem = PreyFunction<void(CCryActor* const _this, bool keepHistory, bool forceNext)>(0x17CE680);
	static inline auto FSelectItemByName = PreyFunction<void(CCryActor* const _this, const char* name, bool keepHistory, bool forceFastSelect)>(0x17CE5B0);
	static inline auto FSelectItem = PreyFunction<void(CCryActor* const _this, unsigned itemId, bool keepHistory, bool forceSelect)>(0x17CE490);
	static inline auto FScheduleItemSwitch = PreyFunction<bool(CCryActor* const _this, unsigned itemId, bool keepHistory, int category, bool forceFastSelect)>(0x17CE2C0);
	static inline auto FClearItemActionControllers = PreyFunction<void(CCryActor* const _this)>(0x17C07E0);
	static inline auto FUseItem = PreyFunction<bool(CCryActor* const _this, unsigned itemId)>(0x17D34B0);
	static inline auto FPickUpItem = PreyFunction<bool(CCryActor* const _this, unsigned itemId, bool sound, bool select)>(0x17CC820);
	static inline auto FDropItem = PreyFunction<bool(CCryActor* const _this, unsigned itemId, float impulseScale, bool selectNext, bool bydeath)>(0x17C2D30);
	static inline auto FDropAttachedItems = PreyFunction<void(CCryActor* const _this)>(0x17C2B90);
	static inline auto FServerExchangeItem = PreyFunction<void(CCryActor* const _this, CItem* pCurrentItem, CItem* pNewItem)>(0x17CF4A0);
	static inline auto FNetReviveAt = PreyFunction<void(CCryActor* const _this, const Vec3& pos, const Quat& rot, int teamId, uint8_t modelIndex)>(0x17CB280);
	static inline auto FNetSimpleKill = PreyFunction<void(CCryActor* const _this)>(0x17CB7D0);
	static inline auto FNetKill = PreyFunction<void(CCryActor* const _this, const CCryActor::KillParams& killParams)>(0x17CAD10);
	static inline auto FCanRagDollize = PreyFunction<bool(const CCryActor* const _this)>(0x17C0770);
	static inline auto FIsStillWaitingOnServerUseResponse = PreyFunction<bool(const CCryActor* const _this)>(0x162C130);
	static inline auto FSetStillWaitingOnServerUseResponse = PreyFunction<void(CCryActor* const _this, bool waiting)>(0x17D0CB0);
	static inline auto FCCryActorOv1 = PreyFunction<void(CCryActor* const _this)>(0x17BEFB0);
	static inline auto FBitNotCCryActor = PreyFunction<void(CCryActor* const _this)>(0x17BF900);
	static inline auto FProcessEvent = PreyFunction<void(CCryActor* const _this, SEntityEvent& event)>(0x17CD1C0);
	static inline auto FGetEventPriority = PreyFunction<int(const CCryActor* const _this, const int eventID)>(0x17C3D70);
	static inline auto FRelease = PreyFunction<void(CCryActor* const _this)>(0x3E3960);
	static inline auto FResetAnimationState = PreyFunction<void(CCryActor* const _this)>(0x17CDDC0);
	static inline auto FNetSerialize = PreyFunction<bool(CCryActor* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags)>(0x17CB600);
	static inline auto FPostSerialize = PreyFunction<void(CCryActor* const _this)>(0x17CCEB0);
	static inline auto FSetChannelId = PreyFunction<void(CCryActor* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSerializeLevelToLevel = PreyFunction<void(CCryActor* const _this, TSerialize& ser)>(0x17CEB00);
	static inline auto FGetInventory = PreyFunction<IInventory* (const CCryActor* const _this)>(0x510580);
	static inline auto FNotifyCurrentItemChanged = PreyFunction<void(CCryActor* const _this, IItem* newItem)>(0x1333E90);
	static inline auto FIsPlayer = PreyFunction<bool(const CCryActor* const _this)>(0x17C7500);
	static inline auto FIsClient = PreyFunction<bool(const CCryActor* const _this)>(0x17C7340);
	static inline auto FIsMigrating = PreyFunction<bool(const CCryActor* const _this)>(0x162C110);
	static inline auto FSetMigrating = PreyFunction<void(CCryActor* const _this, bool isMigrating)>(0x1630930);
	static inline auto FInit = PreyFunction<bool(CCryActor* const _this, IGameObject* pGameObject)>(0x17C5B40);
	static inline auto FInitClient = PreyFunction<void(CCryActor* const _this, int channelId)>(0x17C68F0);
	static inline auto FPostInit = PreyFunction<void(CCryActor* const _this, IGameObject* pGameObject)>(0x17CC9E0);
	static inline auto FPostInitClient = PreyFunction<void(CCryActor* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CCryActor* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x17CDA60);
	static inline auto FPostReloadExtension = PreyFunction<void(CCryActor* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x17CCD80);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CCryActor* const _this, TSerialize signature)>(0x17C3D40);
	static inline auto FUpdate = PreyFunction<void(CCryActor* const _this, SEntityUpdateContext& ctx, int slot)>(0x17D1770);
	static inline auto FUpdateView = PreyFunction<void(IGameObjectView* const _this, SViewParams& viewParams)>(0x1333E90);
	static inline auto FPostUpdateView = PreyFunction<void(IGameObjectView* const _this, SViewParams& viewParams)>(0x1333E90);
	static inline auto FUpdateBodyDestruction = PreyFunction<void(CCryActor* const _this, float frameTime)>(0x17D1D30);
	static inline auto FReadDataFromXML = PreyFunction<void(CCryActor* const _this, bool isReloading)>(0x17CD880);
	static inline auto FInitLocalPlayer = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FSetIKPos = PreyFunction<void(CCryActor* const _this, const char* pLimbName, const Vec3& goalPos, int priority)>(0x17D0A40);
	static inline auto FHandleEvent = PreyFunction<void(CCryActor* const _this, const SGameObjectEvent& event)>(0x17C4300);
	static inline auto FPostUpdate = PreyFunction<void(CCryActor* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FIsThirdPerson = PreyFunction<bool(const CCryActor* const _this)>(0x1A302A0);
	static inline auto FToggleThirdPerson = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FRequestFacialExpression = PreyFunction<void(CCryActor* const _this, const char* pExpressionName, float* sequenceLength)>(0x17CDC50);
	static inline auto FPrecacheFacialExpression = PreyFunction<void(CCryActor* const _this, const char* pExpressionName)>(0x17CCF00);
	static inline auto FNotifyInventoryAmmoChange = PreyFunction<void(CCryActor* const _this, IEntityClass* pAmmoClass, int amount)>(0x1333E90);
	static inline auto FGetGrabbedEntityId = PreyFunction<unsigned(const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FHideAllAttachments = PreyFunction<void(CCryActor* const _this, bool isHiding)>(0x17C57F0);
	static inline auto FOnAIProxyEnabled = PreyFunction<void(CCryActor* const _this, bool enabled)>(0x17CB850);
	static inline auto FOnReturnedToPool = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FOnPreparedFromPool = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FOnReused = PreyFunction<void(CCryActor* const _this, IEntity* pEntity, SEntitySpawnParams& params)>(0x17CBA70);
	static inline auto FSetAspectProfile = PreyFunction<bool(IGameObjectProfileManager* const _this, EEntityAspects aspect, uint8_t profile)>(0x17CFF30);
	static inline auto FGetDefaultProfile = PreyFunction<uint8_t(IGameObjectProfileManager* const _this, EEntityAspects aspect)>(0x13B0900);
	static inline auto FOnAction = PreyFunction<void(CCryActor* const _this, const CCryName& actionId, int activationMode, float value)>(0x17CB9F0);
	static inline auto FSetViewRotation = PreyFunction<void(CCryActor* const _this, const Quat& rotation)>(0x1333E90);
	static inline auto FGetViewRotation = PreyFunction<Quat*(const CCryActor* const _this, Quat* _return_value_)>(0x17C42C0);
	static inline auto FEnableTimeDemo = PreyFunction<void(CCryActor* const _this, bool bTimeDemo)>(0x1333E90);
	static inline auto FAddViewAngleOffsetForFrame = PreyFunction<void(CCryActor* const _this, const Ang3& offset)>(0x1333E90);
	static inline auto FRevive = PreyFunction<void(CCryActor* const _this, CCryActor::EReasonForRevive reasonForRevive)>(0x17CDDD0);
	static inline auto FReset = PreyFunction<void(CCryActor* const _this, bool toGame)>(0x17CDD70);
	static inline auto FLoadPhysicsParams = PreyFunction<bool(SmartScriptTable pEntityTable, const char* szEntityClassName, SEntityPhysicalizeParams& outPhysicsParams, pe_player_dimensions& outPlayerDim, pe_player_dynamics& outPlayerDyn)>(0x17C9F60);
	static inline auto FPhysicalize = PreyFunction<void(CCryActor* const _this, EStance stance)>(0x17CBD20);
	static inline auto FPostPhysicalize = PreyFunction<void(CCryActor* const _this)>(0x17CCA60);
	static inline auto FRagDollize = PreyFunction<void(CCryActor* const _this, bool fallAndPlay)>(0x1333E90);
	static inline auto FShutDown = PreyFunction<void(CCryActor* const _this)>(0x17D0D50);
	static inline auto FIsGod = PreyFunction<int(CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FOnTeleported = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FSetSpectatorState = PreyFunction<void(CCryActor* const _this, uint8_t state)>(0x1333E90);
	static inline auto FGetSpectatorState = PreyFunction<CCryActor::EActorSpectatorState(const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FGetSpectatorOrbitYawSpeed = PreyFunction<float(const CCryActor* const _this)>(0x714650);
	static inline auto FSetSpectatorOrbitYawSpeed = PreyFunction<void(CCryActor* const _this, float yawSpeed, bool singleFrame)>(0x1333E90);
	static inline auto FCanSpectatorOrbitYaw = PreyFunction<bool(const CCryActor* const _this)>(0x13B0900);
	static inline auto FGetSpectatorOrbitPitchSpeed = PreyFunction<float(const CCryActor* const _this)>(0x714650);
	static inline auto FSetSpectatorOrbitPitchSpeed = PreyFunction<void(CCryActor* const _this, float pitchSpeed, bool singleFrame)>(0x1333E90);
	static inline auto FCanSpectatorOrbitPitch = PreyFunction<bool(const CCryActor* const _this)>(0x13B0900);
	static inline auto FChangeCurrentFollowCameraSettings = PreyFunction<void(CCryActor* const _this, bool increment)>(0x1333E90);
	static inline auto FSetSpectatorModeAndOtherEntId = PreyFunction<void(CCryActor* const _this, const uint8_t _mode, const unsigned _othEntId, bool isSpawning)>(0x1333E90);
	static inline auto FGetSpectatorMode = PreyFunction<uint8_t(const CCryActor* const _this)>(0x13B0900);
	static inline auto FSetSpectatorTarget = PreyFunction<void(CCryActor* const _this, unsigned targetId)>(0x1333E90);
	static inline auto FGetSpectatorTarget = PreyFunction<unsigned(const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FSetSpectatorFixedLocation = PreyFunction<void(CCryActor* const _this, unsigned locId)>(0x1333E90);
	static inline auto FGetSpectatorFixedLocation = PreyFunction<unsigned(const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FGetActorStatsOv1 = PreyFunction<SActorStats* (CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FGetActorStatsOv0 = PreyFunction<const SActorStats* (const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FSetStats = PreyFunction<void(CCryActor* const _this, SmartScriptTable& rTable)>(0x17D0C70);
	static inline auto FGetFPArms = PreyFunction<ICharacterInstance* (const CCryActor* const _this, int i)>(0x162B0F0);
	static inline auto FLoadGameParams = PreyFunction<bool(SmartScriptTable pEntityTable, SActorGameParams& outGameParams)>(0x17C81C0);
	static inline auto FLoadDynamicAimPoseElement = PreyFunction<bool(CScriptSetGetChain& gameParamsTableChain, const char* szName, string& output)>(0x17C7980);
	static inline auto FInitGameParamsOv1 = PreyFunction<void(CCryActor* const _this)>(0x17C6F90);
	static inline auto FInitGameParamsOv0 = PreyFunction<void(CCryActor* const _this, const SActorGameParams& gameParams, const bool reloadCharacterSounds)>(0x17C69A0);
	static inline auto FSetParamsFromLua = PreyFunction<void(CCryActor* const _this, SmartScriptTable& rTable)>(0x1333E90);
	static inline auto FFreeze = PreyFunction<void(CCryActor* const _this, bool freeze)>(0x1333E90);
	static inline auto FFallOv1 = PreyFunction<void(CCryActor* const _this, Vec3 hitPos)>(0x17C3390);
	static inline auto FFallOv0 = PreyFunction<void(CCryActor* const _this, const HitInfo& hitInfo)>(0x17C32C0);
	static inline auto FKnockDown = PreyFunction<void(CCryActor* const _this, float backwardsImpulse)>(0x1333E90);
	static inline auto FSetLookAtTargetId = PreyFunction<void(CCryActor* const _this, unsigned targetIdsp, float interpolationTime)>(0x1333E90);
	static inline auto FSetForceLookAtTargetId = PreyFunction<void(CCryActor* const _this, unsigned targetId, float interpolationTime)>(0x1333E90);
	static inline auto FStandUp = PreyFunction<void(CCryActor* const _this)>(0x17D0E80);
	static inline auto FIsFallen = PreyFunction<bool(const CCryActor* const _this)>(0x17C7380);
	static inline auto FIsDead = PreyFunction<bool(const CCryActor* const _this)>(0x17C7350);
	static inline auto FLinkToMountedWeapon = PreyFunction<void(CCryActor* const _this, unsigned weaponId)>(0x1333E90);
	static inline auto FLinkToEntity = PreyFunction<IEntity* (CCryActor* const _this, unsigned entityId, bool bKeepTransformOnDetach)>(0x17C7880);
	static inline auto FStartInteractiveAction = PreyFunction<void(CCryActor* const _this, unsigned entityId, int interactionIndex)>(0x1333E90);
	static inline auto FStartInteractiveActionByName = PreyFunction<void(CCryActor* const _this, const char* interaction, bool bUpdateVisibility, float actionSpeed)>(0x1333E90);
	static inline auto FEndInteractiveAction = PreyFunction<void(CCryActor* const _this, unsigned entityId)>(0x1333E90);
	static inline auto FAllowLandingBob = PreyFunction<bool(CCryActor* const _this)>(0x1A302A0);
	static inline auto FGetLinkedEntity = PreyFunction<IEntity* (const CCryActor* const _this)>(0x162B240);
	static inline auto FSupressViewBlending = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FPlayAction = PreyFunction<void(CCryActor* const _this, const char* action, const char* extension, bool looping)>(0x1333E90);
	static inline auto FSetMovementTarget = PreyFunction<void(CCryActor* const _this, const Vec3& position, const Vec3& looktarget, const Vec3& up, float speed)>(0x1333E90);
	static inline auto FCreateScriptEvent = PreyFunction<void(CCryActor* const _this, const char* event, float value, const char* str)>(0x17C0E80);
	static inline auto FCreateCodeEvent = PreyFunction<bool(CCryActor* const _this, SmartScriptTable& rTable)>(0x13B0900);
	static inline auto FSetTurnAnimationParams = PreyFunction<void(CCryActor* const _this, const float turnThresholdAngle, const float turnThresholdTime)>(0x17D0D30);
	static inline auto FCameraShake = PreyFunction<void(CCryActor* const _this, float angle, float shift, float duration, float frequency, Vec3 pos, int ID, const char* source)>(0x1333E90);
	static inline auto FSetAngles = PreyFunction<void(CCryActor* const _this, const Ang3& angles)>(0x1333E90);
	static inline auto FGetAngles = PreyFunction<Ang3*(CCryActor* const _this, Ang3* _return_value_)>(0x9F8FF0);
	static inline auto FAddAngularImpulse = PreyFunction<void(CCryActor* const _this, const Ang3& angular, float deceleration, float duration)>(0x1333E90);
	static inline auto FSetViewLimits = PreyFunction<void(CCryActor* const _this, Vec3 dir, float rangeH, float rangeV)>(0x1333E90);
	static inline auto FDamageInfo = PreyFunction<void(CCryActor* const _this, unsigned shooterID, unsigned weaponID, IEntityClass* pProjectileClass, float damage, int damageType, const Vec3 hitDirection)>(0x1333E90);
	static inline auto FGetAnimatedCharacterOv1 = PreyFunction<IAnimatedCharacter* (CCryActor* const _this)>(0x162AD60);
	static inline auto FGetAnimatedCharacterOv0 = PreyFunction<const IAnimatedCharacter* (const CCryActor* const _this)>(0x162AD60);
	static inline auto FPlayExactPositioningAnimation = PreyFunction<void(CCryActor* const _this, const char* sAnimationName, bool bSignal, const Vec3& vPosition, const Vec3& vDirection, float startWidth, float startArcAngle, float directionTolerance)>(0x1333E90);
	static inline auto FCancelExactPositioningAnimation = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FPlayAnimation = PreyFunction<void(CCryActor* const _this, const char* sAnimationName, bool bSignal)>(0x1333E90);
	static inline auto FGetCurrentTargetEntityId = PreyFunction<unsigned(const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FGetCurrentTargetPos = PreyFunction<const Vec3* (const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FSetMaxHealth = PreyFunction<void(CCryActor* const _this, float maxHealth)>(0x17D0BC0);
	static inline auto FGetMaxHealth = PreyFunction<float(const CCryActor* const _this)>(0x17C40D0);
	static inline auto FSetHealth = PreyFunction<void(CCryActor* const _this, float health)>(0x17D0860);
	static inline auto FGetHealth = PreyFunction<float(const CCryActor* const _this)>(0x18C19D0);
	static inline auto FGetHealthAsRoundedPercentage = PreyFunction<int(const CCryActor* const _this)>(0x162B150);
	static inline auto FGetArmor = PreyFunction<int(const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FGetMaxArmor = PreyFunction<int(const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FGetTeamId = PreyFunction<int(const CCryActor* const _this)>(0x162BAB0);
	static inline auto FKill = PreyFunction<void(CCryActor* const _this)>(0x17C7640);
	static inline auto FToCryActor = PreyFunction<CCryActor* (CCryActor* const _this)>(0x3DAC90);
	static inline auto FImmuneToForbiddenZoneOv0 = PreyFunction<const bool(const CCryActor* const _this)>(0x17C5B30);
	static inline auto FIsSwimming = PreyFunction<bool(const CCryActor* const _this)>(0x13B0900);
	static inline auto FIsHeadUnderWater = PreyFunction<bool(const CCryActor* const _this)>(0x13B0900);
	static inline auto FIsSprinting = PreyFunction<bool(const CCryActor* const _this)>(0x13B0900);
	static inline auto FCanFire = PreyFunction<bool(const CCryActor* const _this)>(0x1A302A0);
	static inline auto FGetStance = PreyFunction<EStance(const CCryActor* const _this)>(0x162BA90);
	static inline auto FSetLockedStance = PreyFunction<void(CCryActor* const _this, EStance _stance)>(0x16308B0);
	static inline auto FGetLockedStance = PreyFunction<EStance(CCryActor* const _this)>(0x162B280);
	static inline auto FUnlockStance = PreyFunction<void(CCryActor* const _this)>(0x1632790);
	static inline auto FQueueAnimationState = PreyFunction<void(CCryActor* const _this, const char* state)>(0x17CD860);
	static inline auto FGetBoneTransform = PreyFunction<const QuatT& (const CCryActor* const _this, int ID)>(0x162B0B0);
	static inline auto FGetLocalEyePos = PreyFunction<Vec3*(const CCryActor* const _this, Vec3* _return_value_)>(0x17C3EB0);
	static inline auto FGetCameraTran = PreyFunction<QuatT*(const CCryActor* const _this, QuatT* _return_value_)>(0x17C3C60);
	static inline auto FUpdateMountedGunController = PreyFunction<void(CCryActor* const _this, bool forceIKUpdate)>(0x1333E90);
	static inline auto FOnPhysicsPreStep = PreyFunction<void(CCryActor* const _this, float frameTime)>(0x1333E90);
	static inline auto FCheckInventoryRestrictions = PreyFunction<bool(CCryActor* const _this, const char* itemClassName)>(0x17C07B0);
	static inline auto FProcessIKLimbs = PreyFunction<void(CCryActor* const _this, float frameTime)>(0x17CD790);
	static inline auto FCreateIKLimb = PreyFunction<void(CCryActor* const _this, const SActorIKLimbInfo& limbInfo)>(0x17C0C60);
	static inline auto FGetMovementController = PreyFunction<IMovementController* (const CCryActor* const _this)>(0x162BA40);
	static inline auto FOnSetStance = PreyFunction<void(CCryActor* const _this, EStance desiredStance)>(0xA70400);
	static inline auto FSetStance = PreyFunction<void(CCryActor* const _this, EStance desiredStance)>(0xA70400);
	static inline auto FOnStanceChanged = PreyFunction<void(CCryActor* const _this, EStance newStance, EStance oldStance)>(0x17CBA90);
	static inline auto FTrySetStance = PreyFunction<bool(CCryActor* const _this, EStance stance)>(0x17D15D0);
	static inline auto FSetCloakLayer = PreyFunction<void(CCryActor* const _this, bool set, CCryActor::eFadeRules config)>(0x1333E90);
	static inline auto FGetAnimationGraphState = PreyFunction<IAnimationGraphState* (CCryActor* const _this)>(0x17C3AE0);
	static inline auto FSetFacialAlertnessLevel = PreyFunction<void(CCryActor* const _this, int alertness)>(0x17D0840);
	static inline auto FGetCurrentItem = PreyFunction<IItem* (const CCryActor* const _this)>(0x17C3CE0);
	static inline auto FGetCurrentItemId = PreyFunction<unsigned(const CCryActor* const _this)>(0x17C3D20);
	static inline auto FGetHolsteredItem = PreyFunction<IItem* (const CCryActor* const _this)>(0x17C3D90);
	static inline auto FNetGetCurrentItem = PreyFunction<unsigned(const CCryActor* const _this)>(0x17C3D20);
	static inline auto FNetSetCurrentItem = PreyFunction<void(CCryActor* const _this, unsigned id, bool forceDeselect)>(0x17CB6C0);
	static inline auto FNetSetScheduledItem = PreyFunction<void(CCryActor* const _this, unsigned id)>(0x17CB740);
	static inline auto FSwitchDemoModeSpectator = PreyFunction<void(CCryActor* const _this, bool activate)>(0x1333E90);
	static inline auto FReloadBodyDestruction = PreyFunction<void(CCryActor* const _this)>(0x17CDA30);
	static inline auto FGetBodyDamageMultiplier = PreyFunction<float(const CCryActor* const _this, const HitInfo& hitInfo)>(0x17C3B00);
	static inline auto FGetBodyExplosionDamageMultiplier = PreyFunction<float(const CCryActor* const _this, const HitInfo& hitInfo)>(0x17C3C20);
	static inline auto FGetBodyDamagePartFlags = PreyFunction<unsigned(const CCryActor* const _this, const int partID, const int materialID)>(0x17C3B40);
	static inline auto FGetBodyDamageProfileID = PreyFunction<unsigned(const CCryActor* const _this, const char* bodyDamageFileName, const char* bodyDamagePartsFileName)>(0x17C3C00);
	static inline auto FOverrideBodyDamageProfileID = PreyFunction<void(CCryActor* const _this, const unsigned profileID)>(0x17CBCA0);
	static inline auto FFillHitInfoFromKillParams = PreyFunction<void(const CCryActor* const _this, const CCryActor::KillParams& killParams, HitInfo& hitInfo)>(0x17C3420);
	static inline auto FProcessDestructiblesHit = PreyFunction<void(CCryActor* const _this, const HitInfo& hitInfo, const float previousHealth, const float newHealth)>(0x17CD140);
	static inline auto FProcessDestructiblesOnExplosion = PreyFunction<void(CCryActor* const _this, const HitInfo& hitInfo, const float previousHealth, const float newHealth)>(0x17CD180);
	static inline auto FGetActorClassName = PreyFunction<const char* (const CCryActor* const _this)>(0x17C3A70);
	static inline auto FGetActorParamsNode = PreyFunction<const IItemParamsNode* (const CCryActor* const _this)>(0x17C3A80);
	static inline auto FGetActorClass = PreyFunction<int(const CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FGetEntityClassName = PreyFunction<const char* (const CCryActor* const _this)>(0x162B0D0);
	static inline auto FIsPoolEntity = PreyFunction<bool(const CCryActor* const _this)>(0x17C7510);
	static inline auto FSetAnimTentacleParams = PreyFunction<void(CCryActor* const _this, pe_params_rope& rope, float animBlend)>(0x1333E90);
	static inline auto FIsCloaked = PreyFunction<bool(const CCryActor* const _this)>(0x162BE40);
	static inline auto FDumpActorInfo = PreyFunction<void(CCryActor* const _this)>(0x17C3000);
	static inline auto FIsFriendlyEntity = PreyFunction<bool(const CCryActor* const _this, unsigned entityId, bool bUsingAIIgnorePlayer)>(0x17C73A0);
	static inline auto FGetReloadSpeedScale = PreyFunction<float(const CCryActor* const _this)>(0x1AE7A80);
	static inline auto FGetOverchargeDamageScale = PreyFunction<float(const CCryActor* const _this)>(0x1AE7A80);
	static inline auto FEnableSwitchingItems = PreyFunction<void(CCryActor* const _this, bool enable)>(0x17C32B0);
	static inline auto FBecomeRemotePlayer = PreyFunction<void(CCryActor* const _this)>(0x17C0720);
	static inline auto FBecomeAggressiveToAgent = PreyFunction<bool(CCryActor* const _this, unsigned agentID)>(0x1A302A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CCryActor* const _this, ICrySizer* s)>(0x17C40E0);
	static inline auto FGetInternalMemoryUsage = PreyFunction<void(const CCryActor* const _this, ICrySizer* s)>(0x17C3DE0);
	static inline auto FLoadFileModelInfo = PreyFunction<bool(SmartScriptTable pEntityTable, SmartScriptTable pProperties, SActorFileModelInfo& outFileModelInfo)>(0x17C7A30);
	static inline auto FSetActorModel = PreyFunction<bool(CCryActor* const _this, const char* modelName)>(0x17CF580);
	static inline auto FUpdateActorModel = PreyFunction<void(CCryActor* const _this)>(0x17D1C10);
	static inline auto FFullyUpdateActorModel = PreyFunction<bool(CCryActor* const _this)>(0x17C3610);
	static inline auto FInvalidateCurrentModelName = PreyFunction<void(CCryActor* const _this)>(0x17C7280);
	static inline auto FPrepareLuaCache = PreyFunction<void(CCryActor* const _this)>(0x17CCF50);
	static inline auto FLockInteractor = PreyFunction<void(CCryActor* const _this, unsigned lockId, bool lock)>(0x17CAB50);
	static inline auto FIsRemote = PreyFunction<bool(const CCryActor* const _this)>(0x17C7540);
	static inline auto FEnableStumbling = PreyFunction<void(CCryActor* const _this, PlayerActor::Stumble::StumbleParameters* stumbleParameters)>(0x1333E90);
	static inline auto FDisableStumbling = PreyFunction<void(CCryActor* const _this)>(0x1333E90);
	static inline auto FGetCloakBlendSpeedScale = PreyFunction<const float(CCryActor* const _this)>(0x18C15B0);
	static inline auto FSimpleFindItemIdInCategory = PreyFunction<unsigned(const CCryActor* const _this, const char* category)>(0x17D0D60);
	static inline auto FSetTag = PreyFunction<void(CCryActor* const _this, int tagId, bool enable)>(0x17D0CD0);
	static inline auto FIsInMercyTime = PreyFunction<bool(const CCryActor* const _this)>(0x17C74A0);
	static inline auto FOnSpectateModeStatusChanged = PreyFunction<void(CCryActor* const _this, bool spectate)>(0x1333E90);
	static inline auto FShouldMuteWeaponSoundStimulus = PreyFunction<bool(const CCryActor* const _this)>(0x13B0900);
	static inline auto FAcquireOrReleaseLipSyncExtension = PreyFunction<void(CCryActor* const _this)>(0x17C0490);
	static inline auto FGetArkSpeaker = PreyFunction<IArkSpeaker* (CCryActor* const _this)>(0x1CBB0B0);
	static inline auto FGenerateBlendRagdollTags = PreyFunction<void(CCryActor* const _this)>(0x17C36B0);
	static inline auto FPhysicalizeLocalPlayerAdditionalParts = PreyFunction<void(CCryActor* const _this)>(0x17CC610);
	static inline auto FSetActorModelFromScript = PreyFunction<bool(CCryActor* const _this)>(0x17CF5E0);
	static inline auto FSetActorModelInternalOv1 = PreyFunction<bool(CCryActor* const _this, const char* modelName)>(0x17CFD10);
	static inline auto FSetActorModelInternalOv0 = PreyFunction<bool(CCryActor* const _this, const SActorFileModelInfo& fileModelInfo)>(0x17CF860);
	static inline auto FRegisterDBAGroups = PreyFunction<void(CCryActor* const _this)>(0x17CD910);
	static inline auto FSetModelIndex = PreyFunction<void(CCryActor* const _this, uint8_t modelIndex)>(0x1333E90);
	static inline auto FGetRagdollContext = PreyFunction<bool(const CCryActor* const _this, CProceduralContextRagdoll* * ppRagdollContext)>(0x17C41B0);
	static inline auto FPhysicalizeBodyDamage = PreyFunction<void(CCryActor* const _this)>(0x17CC5A0);
	static inline auto FUpdateAutoDisablePhys = PreyFunction<void(CCryActor* const _this, bool bRagdoll)>(0x17D1CE0);
	static inline auto FUpdateStance = PreyFunction<bool(CCryActor* const _this)>(0x17D3390);
	static inline auto FUpdateLegsColliders = PreyFunction<void(CCryActor* const _this)>(0x17D1D40);
	static inline auto FReleaseLegsColliders = PreyFunction<void(CCryActor* const _this)>(0x17CD990);
};
#endif // MOONCRASH
