// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <CryEngine/crycommon/cryfixedstring.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ItemScheduler.h>
#include <Prey/GameDll/itemanimation.h>
#include <Prey/GameDll/itemdefinitions.h>
#include <Prey/GameDll/itemstring.h>
#include <_unknown/CryFixedArray.h>
#include <_unknown/SAccessoryParams.h>
#include <_unknown/SAttachmentHelper.h>
#include <_unknown/SItemAnimationEvents.h>

class CCryActor;
class CCryName;
class CItemSelectAction;
class CItemSharedParams;
class CPlayer;
class CTagDefinition;
class CTagState;
enum EEntityAspects;
enum class EStance;
namespace EntityEffects
{
struct SLightAttachParams;
} // namespace EntityEffects
class IAction;
class IActionController;
struct IActor;
struct IAttachment;
struct IAttachmentManager;
struct ICharacterInstance;
class ICrySizer;
struct IEntity;
struct IEntityAudioProxy;
struct IEntityClass;
struct IEntityPhysicalProxy;
struct IEntityRenderProxy;
struct IEntitySystem;
struct IGameFramework;
struct IGameObject;
struct IGameplayRecorder;
struct IInventory;
struct IItemParamsNode;
struct IItemSystem;
struct IMaterial;
struct INetAtSyncItem;
struct INetChannel;
struct IParticleEmitter;
struct IScriptTable;
struct ISerializableInfo;
struct IStatObj;
struct IWeapon;
struct RayCastResult;
struct SAnimationContext;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
struct SGameObjectExtensionRMI;
struct SMountParams;
struct SParams;
struct SViewParams;

// CItem
// Header:  Prey/GameDll/Item.h
class CItem : public CGameObjectExtensionHelper<CItem,IItem,39>, public IGameObjectProfileManager
{ // Size=728 (0x2D8)
public:
	enum ePhysicalization
	{
		eIPhys_PhysicalizedRigid = 0,
		eIPhys_PhysicalizedStatic = 1,
		eIPhys_NotPhysicalized = 2,
		eIPhys_Max = 3,
	};

	enum ETimer
	{
		eIT_Flying = 0,
		eIT_Last = 1,
	};

	enum ePlayActionFlags
	{
		eIPAF_Default = 0,
		eIPAF_ConcentratedFire = 33554432,
	};

	enum EItemFlags
	{
		eIF_None = 0,
		eIF_Modifying = 4,
		eIF_Transitioning = 8,
		eIF_Cloaked = 16,
		eIF_SerializeCloaked = 32,
		eIF_AccessoryAmmoAvailable = 64,
		eIF_NoDrop = 512,
		eIF_SerializeDestroyed = 1024,
		eIF_SerializeRigidPhysics = 2048,
		eIF_PostSerializeSelect = 4096,
		eIF_RegisteredAs1pUser = 16384,
		eIF_RegisteredAs3pUser = 32768,
		eIF_SelectGrabbingWeapon = 131072,
		eIF_Selecting = 262144,
		eIF_Unholstering = 524288,
		eIF_UnholsteringPlaySelect = 1048576,
		eIF_InformClientsAboutUse = 2097152,
		eIF_PlayFastSelect = 4194304,
		eIF_PlayFastSelectAsSpeedBias = 8388608,
		eIF_BlockActions = 16777216,
		eIF_ExchangeItemScheduled = 33554432,
		eIF_UseFastSelectTag = 67108864,
		eIF_UseAnimActionUnhide = 134217728,
	};

	enum eViewMode
	{
		eIVM_FirstPerson = 1,
		eIVM_ThirdPerson = 2,
	};

	enum eItemAttachment
	{
		eIA_None = 0,
		eIA_WeaponEntity = 1,
		eIA_WeaponCharacter = 2,
		eIA_StowPrimary = 3,
		eIA_StowSecondary = 4,
	};

	enum eItemLowerMode
	{
		eILM_Raised = 0,
		eILM_Lower = 1,
		eILM_Cinematic = 2,
	};

	// CItem::SelectAction
	// Header:  Prey/GameDll/Item.h
	struct SelectAction
	{ // Size=1 (0x1)
	#if 0
		void execute(CItem* _arg0_);
	#endif
	};

	// CItem::SwitchHandAction
	// Header:  Prey/GameDll/Item.h
	struct SwitchHandAction
	{ // Size=16 (0x10)
		CItem* item;
		int hand;

	#if 0
		SwitchHandAction(CItem* _arg0_, int _arg1_);
		void execute(CItem* _arg0_);
	#endif
	};

	// CItem::ExchangeToNextItem
	// Header:  Prey/GameDll/Item.h
	struct ExchangeToNextItem
	{ // Size=0 (0x0)
	};

	// CItem::SStats
	// Header:  Prey/GameDll/Item.h
	struct SStats
	{ // Size=44 (0x2C)
		Vec3 mount_dir;
		Vec3 mount_last_aimdir;
		int hand : 3;
		int viewmode : 3;
		float health;
		bool fp : 1;
		bool mounted : 1;
		bool pickable : 1;
		bool selected : 1;
		bool dropped : 1;
		bool detached : 1;
		bool brandnew : 1;
		bool flying : 1;
		bool used : 1;
		bool sound_enabled : 1;
		bool first_selection : 1;
		CItem::eItemAttachment attachment;
		eGeometrySlot physicalisedSlot;

		void Serialize(TSerialize& ser) { FSerialize(this, ser); }

	#if 0
		SStats();
	#endif

		static inline auto FSerialize = PreyFunction<void(CItem::SStats* const _this, TSerialize& ser)>(0x187F620);
	};

	// CItem::SEditorStats
	// Header:  Prey/GameDll/Item.h
	struct SEditorStats
	{ // Size=8 (0x8)
		unsigned ownerId;
		bool current;

	#if 0
		SEditorStats();
		SEditorStats(unsigned _arg0_, bool _arg1_);
	#endif
	};

	// CItem::SEntityProperties
	// Header:  Prey/GameDll/Item.h
	struct SEntityProperties
	{ // Size=32 (0x20)
		float mounted_min_pitch;
		float mounted_max_pitch;
		float mounted_yaw_range;
		CItem::ePhysicalization physics;
		int hitpoints;
		bool pickable;
		bool mounted;
		bool usable;
		bool specialSelect;
		string initialSetup;

	#if 0
		SEntityProperties();
		void GetMemoryStatistics(ICrySizer* _arg0_) const;
	#endif
	};

	// CItem::SRespawnProperties
	// Header:  Prey/GameDll/Item.h
	struct SRespawnProperties
	{ // Size=8 (0x8)
		float timer;
		bool unique;
		bool respawn;

	#if 0
		SRespawnProperties();
	#endif
	};

	// CItem::SAccessoryInfo
	// Header:  Prey/GameDll/Item.h
	struct SAccessoryInfo
	{ // Size=16 (0x10)
		IEntityClass* pClass;
		unsigned accessoryId;

	#if 0
		SAccessoryInfo();
		SAccessoryInfo(IEntityClass* _arg0_, unsigned _arg1_);
	#endif
	};

	// CItem::AccessoryParams
	// Header:  Prey/GameDll/Item.h
	struct AccessoryParams
	{ // Size=2 (0x2)
		uint16_t accessoryClassId;

	#if 0
		AccessoryParams();
		AccessoryParams(uint16_t _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CItem::EmptyParams
	// Header:  Prey/GameDll/Item.h
	struct EmptyParams
	{ // Size=1 (0x1)
	#if 0
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CItem::MethodInfo_SvRequestAttachAccessory
	// Header:  Prey/GameDll/Item.h
	struct MethodInfo_SvRequestAttachAccessory
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestAttachAccessory(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CItem::AccessoryParams& _arg0_) const;
	#endif
	};

	// CItem::Params_SvRequestAttachAccessory
	// Header:  Prey/GameDll/Item.h
	struct Params_SvRequestAttachAccessory
	{ // Size=2 (0x2)
		uint16_t accessoryClassId;

	#if 0
		void AccessoryParams();
		void AccessoryParams(uint16_t _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CItem::MethodInfo_ClAttachAccessory
	// Header:  Prey/GameDll/Item.h
	struct MethodInfo_ClAttachAccessory
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClAttachAccessory(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CItem::AccessoryParams& _arg0_) const;
	#endif
	};

	// CItem::Params_ClAttachAccessory
	// Header:  Prey/GameDll/Item.h
	struct Params_ClAttachAccessory
	{ // Size=2 (0x2)
		uint16_t accessoryClassId;

	#if 0
		void AccessoryParams();
		void AccessoryParams(uint16_t _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CItem::MethodInfo_ClAttachInitialAccessory
	// Header:  Prey/GameDll/Item.h
	struct MethodInfo_ClAttachInitialAccessory
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClAttachInitialAccessory(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CItem::AccessoryParams& _arg0_) const;
	#endif
	};

	// CItem::Params_ClAttachInitialAccessory
	// Header:  Prey/GameDll/Item.h
	struct Params_ClAttachInitialAccessory
	{ // Size=2 (0x2)
		uint16_t accessoryClassId;

	#if 0
		void AccessoryParams();
		void AccessoryParams(uint16_t _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CItem::MethodInfo_SvRequestDetachAccessory
	// Header:  Prey/GameDll/Item.h
	struct MethodInfo_SvRequestDetachAccessory
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestDetachAccessory(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CItem::AccessoryParams& _arg0_) const;
	#endif
	};

	// CItem::Params_SvRequestDetachAccessory
	// Header:  Prey/GameDll/Item.h
	struct Params_SvRequestDetachAccessory
	{ // Size=2 (0x2)
		uint16_t accessoryClassId;

	#if 0
		void AccessoryParams();
		void AccessoryParams(uint16_t _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CItem::MethodInfo_ClDetachAccessory
	// Header:  Prey/GameDll/Item.h
	struct MethodInfo_ClDetachAccessory
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClDetachAccessory(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CItem::AccessoryParams& _arg0_) const;
	#endif
	};

	// CItem::Params_ClDetachAccessory
	// Header:  Prey/GameDll/Item.h
	struct Params_ClDetachAccessory
	{ // Size=2 (0x2)
		uint16_t accessoryClassId;

	#if 0
		void AccessoryParams();
		void AccessoryParams(uint16_t _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CItem::MethodInfo_SvRequestEnterModify
	// Header:  Prey/GameDll/Item.h
	struct MethodInfo_SvRequestEnterModify
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestEnterModify(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CItem::EmptyParams& _arg0_) const;
	#endif
	};

	// CItem::Params_SvRequestEnterModify
	// Header:  Prey/GameDll/Item.h
	struct Params_SvRequestEnterModify
	{ // Size=1 (0x1)
	#if 0
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CItem::MethodInfo_SvRequestLeaveModify
	// Header:  Prey/GameDll/Item.h
	struct MethodInfo_SvRequestLeaveModify
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestLeaveModify(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CItem::EmptyParams& _arg0_) const;
	#endif
	};

	// CItem::Params_SvRequestLeaveModify
	// Header:  Prey/GameDll/Item.h
	struct Params_SvRequestLeaveModify
	{ // Size=1 (0x1)
	#if 0
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CItem::MethodInfo_ClEnterModify
	// Header:  Prey/GameDll/Item.h
	struct MethodInfo_ClEnterModify
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClEnterModify(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CItem::EmptyParams& _arg0_) const;
	#endif
	};

	// CItem::Params_ClEnterModify
	// Header:  Prey/GameDll/Item.h
	struct Params_ClEnterModify
	{ // Size=1 (0x1)
	#if 0
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CItem::MethodInfo_ClLeaveModify
	// Header:  Prey/GameDll/Item.h
	struct MethodInfo_ClLeaveModify
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClLeaveModify(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CItem::EmptyParams& _arg0_) const;
	#endif
	};

	// CItem::Params_ClLeaveModify
	// Header:  Prey/GameDll/Item.h
	struct Params_ClLeaveModify
	{ // Size=1 (0x1)
	#if 0
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CItem::COwnerInfo
	// Header:  Prey/GameDll/Item.h
	class COwnerInfo
	{ // Size=24 (0x18)
	public:
		unsigned m_id;
		std::weak_ptr<CCryActor> m_pActor;

	#if 0
		COwnerInfo();
		unsigned GetId() const;
		const std::weak_ptr<CCryActor>& GetActorWeakPtr() const;
		void Set(unsigned _arg0_, const std::weak_ptr<CCryActor>& _arg1_);
		void Reset();
	#endif
	};

	using TItemFlags = unsigned;
	using TempAGInputName = CryFixedStringT<32>;
	using TAccessoryArray = CryFixedArray<CItem::SAccessoryInfo,4>;

	static constexpr const ERMIAttachmentType Attach_SvRequestAttachAccessory = 2;
	static constexpr const bool ServerCall_SvRequestAttachAccessory = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestAttachAccessory = 1;
	static constexpr const bool LowDelay_SvRequestAttachAccessory = 0;
	static inline auto m_infoSvRequestAttachAccessory = PreyGlobal<CItem::MethodInfo_SvRequestAttachAccessory>(0x2D8E548);
	static constexpr const ERMIAttachmentType Attach_ClAttachAccessory = 2;
	static constexpr const bool ServerCall_ClAttachAccessory = 0;
	static constexpr const ENetReliabilityType Reliability_ClAttachAccessory = 1;
	static constexpr const bool LowDelay_ClAttachAccessory = 0;
	static inline auto m_infoClAttachAccessory = PreyGlobal<CItem::MethodInfo_ClAttachAccessory>(0x2D8E550);
	static constexpr const ERMIAttachmentType Attach_ClAttachInitialAccessory = 2;
	static constexpr const bool ServerCall_ClAttachInitialAccessory = 0;
	static constexpr const ENetReliabilityType Reliability_ClAttachInitialAccessory = 1;
	static constexpr const bool LowDelay_ClAttachInitialAccessory = 0;
	static inline auto m_infoClAttachInitialAccessory = PreyGlobal<CItem::MethodInfo_ClAttachInitialAccessory>(0x2D8E558);
	static constexpr const ERMIAttachmentType Attach_SvRequestDetachAccessory = 2;
	static constexpr const bool ServerCall_SvRequestDetachAccessory = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestDetachAccessory = 1;
	static constexpr const bool LowDelay_SvRequestDetachAccessory = 0;
	static inline auto m_infoSvRequestDetachAccessory = PreyGlobal<CItem::MethodInfo_SvRequestDetachAccessory>(0x2D8E560);
	static constexpr const ERMIAttachmentType Attach_ClDetachAccessory = 2;
	static constexpr const bool ServerCall_ClDetachAccessory = 0;
	static constexpr const ENetReliabilityType Reliability_ClDetachAccessory = 1;
	static constexpr const bool LowDelay_ClDetachAccessory = 0;
	static inline auto m_infoClDetachAccessory = PreyGlobal<CItem::MethodInfo_ClDetachAccessory>(0x2D8E568);
	static constexpr const ERMIAttachmentType Attach_SvRequestEnterModify = 2;
	static constexpr const bool ServerCall_SvRequestEnterModify = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestEnterModify = 1;
	static constexpr const bool LowDelay_SvRequestEnterModify = 0;
	static inline auto m_infoSvRequestEnterModify = PreyGlobal<CItem::MethodInfo_SvRequestEnterModify>(0x2D8E570);
	static constexpr const ERMIAttachmentType Attach_SvRequestLeaveModify = 2;
	static constexpr const bool ServerCall_SvRequestLeaveModify = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestLeaveModify = 1;
	static constexpr const bool LowDelay_SvRequestLeaveModify = 0;
	static inline auto m_infoSvRequestLeaveModify = PreyGlobal<CItem::MethodInfo_SvRequestLeaveModify>(0x2D8E578);
	static constexpr const ERMIAttachmentType Attach_ClEnterModify = 2;
	static constexpr const bool ServerCall_ClEnterModify = 0;
	static constexpr const ENetReliabilityType Reliability_ClEnterModify = 1;
	static constexpr const bool LowDelay_ClEnterModify = 0;
	static inline auto m_infoClEnterModify = PreyGlobal<CItem::MethodInfo_ClEnterModify>(0x2D8E580);
	static constexpr const ERMIAttachmentType Attach_ClLeaveModify = 2;
	static constexpr const bool ServerCall_ClLeaveModify = 0;
	static constexpr const ENetReliabilityType Reliability_ClLeaveModify = 1;
	static constexpr const bool LowDelay_ClLeaveModify = 0;
	static inline auto m_infoClLeaveModify = PreyGlobal<CItem::MethodInfo_ClLeaveModify>(0x2D8E588);
	_smart_ptr<CItemSharedParams> m_sharedparams;
	unsigned m_itemFlags;
	unsigned m_dropRayId;
	Vec3 m_dropPosition;
	Vec3 m_dropImpulse;
	CItem::SStats m_stats;
	CItem::SEditorStats m_editorstats;
	CryFixedArray<CItem::SAccessoryInfo,4> m_accessories;
	std::vector<unsigned int> m_damageLevelEffects;
	CryFixedArray<IEntityClass *,4> m_initialSetup;
	EntityEffects::CEffectsController m_effectsController;
	CItemScheduler m_scheduler;
	CItem::COwnerInfo m_owner;
	unsigned m_parentId;
	unsigned m_animationTime[9];
	CItem::SRespawnProperties m_respawnprops;
	CItem::SEntityProperties m_properties;
	unsigned m_hostId;
	unsigned m_postSerializeMountedOwner;
	SAnimationContext* m_pItemAnimationContext;
	IActionController* m_pItemActionController;
	IActionController* m_pCurrentActionController;
	const SMannequinItemParams* m_pCurrentManItemParams;
	static inline auto sNullManItemParams = PreyGlobal<SMannequinItemParams>(0x2D8E320);
	static inline auto s_animationEventsTable = PreyGlobal<SItemAnimationEvents>(0x2D8E530);
	static inline auto m_pEntitySystem = PreyGlobal<IEntitySystem*>(0x2D8E228);
	static inline auto m_pItemSystem = PreyGlobal<IItemSystem*>(0x2D8E230);
	static inline auto m_pGameFramework = PreyGlobal<IGameFramework*>(0x2D8E238);
	static inline auto m_pGameplayRecorder = PreyGlobal<IGameplayRecorder*>(0x2D8E240);
	_smart_ptr<CItemSelectAction> m_pSelectAction;
	CItem::ePhysicalization m_deferPhysicalization;
	SharedString::CSharedString m_geometry[9];
	CItem::eItemLowerMode m_itemLowerMode;
	Vec3 m_serializeActivePhysics;
	float m_unholsteringSelectBiasTime;
	int m_delayedUnhideCntr;
	uint16_t m_attachedAccessoryHistory;
	int m_subContext;
	static inline auto sBinocularsClass = PreyGlobal<IEntityClass*>(0x2D8E248);
	static inline auto sDebugGunClass = PreyGlobal<IEntityClass*>(0x2D8E250);
	static inline auto sRefWeaponClass = PreyGlobal<IEntityClass*>(0x2D8E258);
	static inline auto sLTagGrenade = PreyGlobal<IEntityClass*>(0x2D8E260);
	static inline auto sFragHandGrenadesClass = PreyGlobal<IEntityClass*>(0x2D8E268);
	static inline auto sNoWeaponClass = PreyGlobal<IEntityClass*>(0x2D8E270);
	static inline auto sWeaponMeleeClass = PreyGlobal<IEntityClass*>(0x2D8E278);
	static inline auto sBowClass = PreyGlobal<IEntityClass*>(0x2D8E280);
	static inline auto sSilencerPistolClass = PreyGlobal<IEntityClass*>(0x2D8E288);
	static inline auto sSilencerClass = PreyGlobal<IEntityClass*>(0x2D8E290);
	static inline auto sFragmentTagCRCs = PreyGlobal<SItemFragmentTagCRCs>(0x2D8E298);
	static inline auto sActionParamCRCs = PreyGlobal<SItemActionParamCRCs>(0x2D8E2D0);

	CItem();
	virtual ~CItem();
	virtual const char* GetType() const;
	virtual bool Init(IGameObject* pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInitClient(int channelId);
	virtual void PostInit(IGameObject* pGameObject);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags);
	virtual unsigned GetNetSerializeAspects();
	virtual void PostSerialize();
	virtual void SerializeLTL(TSerialize ser);
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& ctx, int slot);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& evt);
	virtual void ProcessEvent(SEntityEvent& event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void OnAction(unsigned actorId, const CCryName& actionId, int activationMode, float value);
	virtual void UpdateFPView(float frameTime);
	virtual bool FilterView(SViewParams& viewParams);
	virtual void PostFilterView(SViewParams& viewParams);
	virtual void GetFPOffset(QuatT& offset) const;
	virtual bool ShouldBindOnInit() const;
	virtual bool CheckAmmoRestrictions(IInventory* pInventory);
	virtual IWeapon* GetIWeapon();
	virtual const IWeapon* GetIWeapon() const;
	virtual bool IsAccessory();
	virtual void SetOwnerId(unsigned ownerId);
	virtual unsigned GetOwnerId() const;
	virtual void Reset();
	virtual void ResetOwner();
	virtual bool ResetParams();
	virtual void PreResetParams();
	virtual void RemoveEntity(bool force);
	virtual void SetParentId(unsigned parentId);
	virtual unsigned GetParentId() const;
	virtual void SetHand(int hand);
	void SwitchToHand(int hand) { FSwitchToHand(this, hand); }
	virtual void Use(unsigned userId);
	virtual void Select(bool select);
	virtual void Drop(float impulseScale, bool selectNext, bool byDeath);
	virtual bool PickUp(unsigned pickerId, bool sound, bool select, bool keepHistory, const char* setup, bool _bDropIfFull);
	virtual void Physicalize(bool enable, bool rigid);
	void Unholstering(bool playSelect, float biasSelectTime) { FUnholstering(this, playSelect, biasSelectTime); }
	virtual CItem::ePhysicalization FindPhysicalisationType(bool enable, bool rigid);
	void DeferPhysicalize(bool enable, bool rigid) { FDeferPhysicalize(this, enable, rigid); }
	virtual void Pickalize(bool enable, bool dropped);
	virtual void Impulse(const Vec3& position, const Vec3& direction, float impulse);
	virtual bool CanPickUp(unsigned userId) const;
	virtual bool CanDrop() const;
	virtual bool CanUse(unsigned userId) const;
	virtual bool IsMountable() const;
	virtual bool IsMounted() const;
	virtual bool IsRippedOff() const;
	virtual bool CanRipOff() const;
	virtual bool IsHeavyWeapon() const;
	virtual bool IsUsed() const;
	virtual bool IsPickable() const;
	virtual bool ShouldAttachWhenSelected();
	virtual bool InitRespawn();
	virtual void TriggerRespawn();
	void CloakEnable(bool enable, bool fade, float cloakBlendSpeedScale, bool bFadeByDistance, uint8_t colorChannel, bool bIgnoreCloakRefractionColor, unsigned syncedFromId) { FCloakEnable(this, enable, fade, cloakBlendSpeedScale, bFadeByDistance, colorChannel, bIgnoreCloakRefractionColor, syncedFromId); }
	void CloakSync(bool fade) { FCloakSync(this, fade); }
	virtual Vec3 GetMountedAngleLimits() const;
	virtual Vec3 GetMountedDir() const;
	virtual void SetMountedAngleLimits(float min_pitch, float max_pitch, float yaw_range);
	virtual bool CanSelect() const;
	virtual bool CanDeselect() const;
	virtual bool IsSelecting() const;
	virtual bool IsSelected() const;
	virtual void OnParentSelect(bool select);
	virtual void OnParentReloaded();
	virtual void SetAccessoryReloadTags(CTagState& fragTags);
	virtual void MountAt(const Vec3& pos);
	virtual void MountAtEntity(unsigned entityId, const Vec3& pos, const Ang3& angles);
	virtual void StartUse(unsigned userId);
	virtual void StopUse(unsigned userId);
	virtual void ApplyViewLimit(unsigned userId, bool apply);
	virtual void EnableSound(bool enable);
	virtual bool IsSoundEnabled() const;
	virtual bool IsModifying() const;
	virtual void PickUpAmmo(unsigned pickerId);
	virtual bool HasSomeAmmoToPickUp(unsigned pickerId) const;
	virtual bool SetAspectProfile(EEntityAspects aspect, uint8_t profile);
	virtual uint8_t GetDefaultProfile(EEntityAspects aspect);
	virtual unsigned StartDeselection(bool fastDeselect);
	virtual void CancelDeselection();
	virtual bool IsDeselecting() const;
	virtual void OnStartUsing();
	virtual void OnStopUsing();
	virtual void OnSelect(bool select);
	virtual void OnSelected(bool selected);
	virtual void OnReloaded();
	virtual void OnEnterFirstPerson();
	virtual void OnEnterThirdPerson();
	virtual void OnReset();
	virtual void OnPickedUp(unsigned actorId, bool destroyed);
	virtual void OnDropped(unsigned actorId, bool ownerWasAI);
	virtual void OnBeginCutScene();
	virtual void OnEndCutScene();
	virtual void OnOwnerActivated();
	virtual void OnOwnerDeactivated();
	virtual void OnOwnerStanceChanged(const EStance stance);
	virtual const CItem::SStats& GetStats() const;
	virtual const SParams& GetParams() const;
	virtual const SMountParams* GetMountedParams() const;
	virtual const CItem::SEntityProperties& GetProperties() const;
	virtual bool ReadItemParams(const IItemParamsNode* root);
	virtual void InitItemFromParams();
	virtual void InitGeometry();
	virtual void InitAccessories();
	virtual void InitDamageLevels();
	virtual void ReadProperties(IScriptTable* pProperties);
	virtual void RemoveAccessory(const SharedString::CSharedString& name);
	void RemoveAccessory(IEntityClass* pClass) { FRemoveAccessoryOv0(this, pClass); }
	virtual void RemoveAllAccessories();
	virtual void DetachAllAccessories();
	virtual void AttachAccessory(const SharedString::CSharedString& name, bool attach, bool noanim, bool force, bool firstTimeAttached, bool initialLoadoutSetup);
	virtual void AttachAccessory(IEntityClass* pAccessoryClass, bool attach, bool noanim, bool force, bool firstTimeAttached, bool initialLoadoutSetup);
	virtual CItem* GetAccessory(const SharedString::CSharedString& name);
	virtual bool IsFirstTimeAccessoryAttached(IEntityClass* pClass) const;
	void AccessoryDetachAction(CItem* pAccessory, const SAccessoryParams* params) { FAccessoryDetachAction(this, pAccessory, params); }
	void ShowAttachmentHelper(int slot, const char* name, bool show) { FShowAttachmentHelper(this, slot, name, show); }
	virtual const SAccessoryParams* GetAccessoryParams(const IEntityClass* pClass) const;
	virtual void InitialSetup();
	virtual void PatchInitialSetup();
	virtual void ReAttachAccessories();
	virtual void AccessoriesChanged(bool initialLoadoutSetup);
	virtual void FixAccessories(const SAccessoryParams* newParams, bool attach);
	virtual void ResetAccessoriesScreen(IActor* pOwner);
	virtual void RemoveOwnerAttachedAccessories();
	virtual void SwitchAccessory(const SharedString::CSharedString& accessory);
	virtual void DoSwitchAccessory(const SharedString::CSharedString& inAccessory, bool initialLoadoutSetup);
	virtual void DetachAccessory(const SharedString::CSharedString& accessory);
	const Matrix34 GetWorldTM() const { alignas(const Matrix34) std::byte _return_buf_[sizeof(const Matrix34)]; return *FGetWorldTM(this, reinterpret_cast<const Matrix34*>(_return_buf_)); }
	virtual void AddAccessoryAmmoToInventory(IEntityClass* pAmmoType, int count, IInventory* pOwnerInventory);
	virtual bool GivesAmmo();
	void ProcessAccessoryAmmo(IInventory* pOwnerInventory, IWeapon* pParentWeapon) { FProcessAccessoryAmmo(this, pOwnerInventory, pParentWeapon); }
	virtual const SAccessoryParams* GetSecondaryFiremodeAccessory() const;
	virtual const SAccessoryParams* GetDefaultOverrideAccessory() const;
	CItem* AddAccessory(IEntityClass* pClass) { return FAddAccessory(this, pClass); }
	bool HasAccessory(const SharedString::CSharedString& name) { return FHasAccessoryOv1(this, name); }
	unsigned AttachEffect(int slot, bool attachToAccessory, const char* effectName, const char* helper, const Vec3& offset, const Vec3& dir, float scale, bool prime) { return FAttachEffect(this, slot, attachToAccessory, effectName, helper, offset, dir, scale, prime); }
	void DetachEffect(unsigned id) { FDetachEffect(this, id); }
	virtual bool AttachToHand(bool attach, bool checkAttachment);
	virtual bool AttachToBack(bool attach);
	CItem::eItemAttachment ChooseAttachmentPoint(bool attach, IAttachment* * attachmentPt) const { return FChooseAttachmentPoint(this, attach, attachmentPt); }
	virtual void EnableUpdate(bool enable, int slot);
	virtual void RequireUpdate(int slot);
	void Hide(bool hide, bool remoteUpdate) { FHide(this, hide, remoteUpdate); }
	virtual void HideItem(bool hide);
	virtual void SetBusy(bool busy);
	virtual bool IsBusy() const;
	IEntity* GetOwner() const { return FGetOwner(this); }
	CCryActor* GetOwnerActor() const { return FGetOwnerActor(this); }
	static IInventory* GetOwnerInventory(unsigned _id) { return FGetOwnerInventory(_id); }
	virtual const char* GetDisplayName() const;
	virtual const char* GetIcon() const;
	virtual void GetInventoryDimensions(int& width, int& height) const;
	virtual const char* GetDescription() const;
	virtual void ForcePendingActions(uint8_t blockedActions);
	virtual bool HasFastSelect(unsigned nextItemId) const;
	virtual bool ShouldPlaySelectAction() const;
	virtual void RegisterFPWeaponForRenderingAlways(bool registerRenderAlways);
	bool IsOwnerFP() { return FIsOwnerFP(this); }
	virtual void UpdateMounted(float frameTime);
	void CheckViewChange() { FCheckViewChange(this); }
	virtual void SetViewMode(int mode);
	void AttachToShadowHand(bool attach) { FAttachToShadowHand(this, attach); }
	void CopyRenderFlags(IEntity* pOwner) { FCopyRenderFlags(this, pOwner); }
	virtual void UpdateIKMounted(IActor* pActor, const Vec3& vGunXAxis);
	void ResetCharacterAttachment(int slot, const char* name, bool owner, unsigned attachedEntID) { FResetCharacterAttachment(this, slot, name, owner, attachedEntID); }
	void SetCharacterAttachment(int slot, const char* name, IEntity* pEntity, int objSlot, bool owner) { FSetCharacterAttachmentOv0(this, slot, name, pEntity, objSlot, owner); }
	virtual void SetCharacterAttachmentLocalTM(int slot, const char* name, const Matrix34& tm);
	virtual void OnHit(float damage, int hitType);
	virtual void OnDestroyed();
	virtual void OnRepaired();
	virtual void DestroyedGeometry(bool use);
	virtual void UpdateDamageLevel();
	virtual bool SetGeometry(int slot, const SharedString::CSharedString& name, const SharedString::CSharedString& material, bool useParentMaterial, const Vec3& poffset, const Ang3& aoffset, float scale, bool forceReload);
	_smart_ptr<IAction> PlayAction(int action, int layer, bool loop, unsigned flags, float speedOverride, float animWeigth, float ffeedbackWeight) { alignas(_smart_ptr<IAction>) std::byte _return_buf_[sizeof(_smart_ptr<IAction>)]; return *FPlayAction(this, reinterpret_cast<_smart_ptr<IAction>*>(_return_buf_), action, layer, loop, flags, speedOverride, animWeigth, ffeedbackWeight); }
	bool PlayFragment(IAction* pAction, float speedOverride, float timeOverride, float animWeight, float ffeedbackWeight, bool concentratedFire) { return FPlayFragment(this, pAction, speedOverride, timeOverride, animWeight, ffeedbackWeight, concentratedFire); }
	virtual void SetFragmentTags(CTagState& fragTags);
	unsigned GetCurrentAnimationTime(int slot) { return FGetCurrentAnimationTime(this, slot); }
	void DrawSlot(int slot, bool bDraw, bool bNear) { FDrawSlot(this, slot, bDraw, bNear); }
	Vec3 GetSlotHelperPos(int slot, const char* helper, bool worldSpace, bool relative) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetSlotHelperPos(this, reinterpret_cast<Vec3*>(_return_buf_), slot, helper, worldSpace, relative); }
	const Matrix33& GetSlotHelperRotation(int slot, const char* helper, bool worldSpace, bool relative) { return FGetSlotHelperRotation(this, slot, helper, worldSpace, relative); }
	void Quiet() { FQuiet(this); }
	virtual void OnAttach(bool attach);
	IEntityRenderProxy* GetRenderProxy(bool create) { return FGetRenderProxy(this, create); }
	IEntityPhysicalProxy* GetPhysicalProxy(bool create) { return FGetPhysicalProxy(this, create); }
	static INetAtSyncItem* Decode_SvRequestAttachAccessory(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestAttachAccessory(ser, pID, pChannel); }
	bool Handle_SvRequestAttachAccessory(const CItem::AccessoryParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestAttachAccessory(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClAttachAccessory(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClAttachAccessory(ser, pID, pChannel); }
	bool Handle_ClAttachAccessory(const CItem::AccessoryParams& params, INetChannel* pNetChannel) { return FHandle_ClAttachAccessory(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClAttachInitialAccessory(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClAttachInitialAccessory(ser, pID, pChannel); }
	bool Handle_ClAttachInitialAccessory(const CItem::AccessoryParams& params, INetChannel* pNetChannel) { return FHandle_ClAttachInitialAccessory(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestDetachAccessory(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestDetachAccessory(ser, pID, pChannel); }
	bool Handle_SvRequestDetachAccessory(const CItem::AccessoryParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestDetachAccessory(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClDetachAccessory(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClDetachAccessory(ser, pID, pChannel); }
	bool Handle_ClDetachAccessory(const CItem::AccessoryParams& params, INetChannel* pNetChannel) { return FHandle_ClDetachAccessory(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestEnterModify(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestEnterModify(ser, pID, pChannel); }
	bool Handle_SvRequestEnterModify(const CItem::EmptyParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestEnterModify(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestLeaveModify(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestLeaveModify(ser, pID, pChannel); }
	bool Handle_SvRequestLeaveModify(const CItem::EmptyParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestLeaveModify(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClEnterModify(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClEnterModify(ser, pID, pChannel); }
	bool Handle_ClEnterModify(const CItem::EmptyParams& params, INetChannel* pNetChannel) { return FHandle_ClEnterModify(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClLeaveModify(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClLeaveModify(ser, pID, pChannel); }
	bool Handle_ClLeaveModify(const CItem::EmptyParams& params, INetChannel* pNetChannel) { return FHandle_ClLeaveModify(this, params, pNetChannel); }
	void DoSelectWeaponGrab() { FDoSelectWeaponGrab(this); }
	virtual bool IsRippingOrRippedOff() const;
	virtual void ForceRippingOff(bool ripOff);
	virtual void UpdateCurrentActionController();
	virtual void SetCurrentActionController(IActionController* pActionController);
	virtual void SetSubContextID(int subContext);
	virtual int GetSubContextID();
	virtual const string GetAttachedAccessoriesString(const char* separator);
	bool InitActionController(IEntity* pEntity) { return FInitActionController(this, pEntity); }
	virtual bool ShouldDoPostSerializeReset() const;
	void UpdateActionControllerSelection(bool bSelected) { FUpdateActionControllerSelection(this, bSelected); }
	void DropAfterRaycast(const unsigned& rayID, const RayCastResult& result) { FDropAfterRaycast(this, rayID, result); }
	void DetachItem(IEntity* pThisItemEntity, CCryActor* pOwnerActor, float impulseScale, Vec3 localDropDirection) { FDetachItem(this, pThisItemEntity, pOwnerActor, impulseScale, localDropDirection); }
	virtual float GetSelectSpeed(CCryActor* pOwnerActor);
	void RegisterAsUser() { FRegisterAsUser(this); }
	void UnRegisterAsUser() { FUnRegisterAsUser(this); }
	static void AudioCacheItem(const bool enable, const IEntityClass* pClass, const char* prefix, const char* postfix) { FAudioCacheItem(enable, pClass, prefix, postfix); }
	IAttachmentManager* GetOwnerAttachmentManager() const { return FGetOwnerAttachmentManager(this); }
	virtual void UpdateTags(const IActionController* pActionController, CTagState& tagState, bool selected) const;
	virtual void UpdateAccessoryTags(const SMannequinItemParams* pParams, CTagState& tagState, bool selected) const;
	virtual void UpdateMountedTags(const SMannequinItemParams* pParams, CTagState& tagState, bool selected) const;
	void UpdateScopeContexts(IActionController* pController, int nCharacterSlot) { FUpdateScopeContexts(this, pController, nCharacterSlot); }
	void ClearScopeContexts(IActionController* pController) { FClearScopeContexts(this, pController); }
	virtual void OnUnlowerItem();

#if 0
	static const char* GetWeaponComponentType();
	void GetInternalMemoryUsage(ICrySizer* _arg0_) const;
	void DisableCollisionWithPlayers();
	void LowerItem(CItem::eItemLowerMode _arg0_);
	void UnlowerItem();
	bool IsLowered() const;
	CItem::eItemLowerMode GetLowerMode() const;
	bool CanFireUnderWater() const;
	bool IsDestroyed() const;
	void PickUpAccessories(unsigned _arg0_);
	void ReadMountedProperties(IScriptTable* _arg0_);
	CItem* GetAccessory(IEntityClass* _arg0_);
	void AccessoryAttachAction(CItem* _arg0_, const SAccessoryParams* _arg1_, bool _arg2_);
	bool IsAccessoryHelperFree(const SharedString::CSharedString& _arg0_);
	const Vec3 GetWorldPos() const;
	void GetRelativeLocation(QuatT& _arg0_) const;
	bool IsAttachedToBack() const;
	bool IsAttachedToHand() const;
	void ProcessAccessoryAmmoCapacities(IInventory* _arg0_, bool _arg1_);
	const CryFixedArray<CItem::SAccessoryInfo,4>& GetAccessories() const;
	const std::vector<SAccessoryParams>& GetAccessoriesParamsVector() const;
	bool HasAccessory(IEntityClass* _arg0_);
	void ReAttachAccessory(IEntityClass* _arg0_);
	void RemoveAccessoryOnCategory(const SharedString::CSharedString& _arg0_);
	unsigned AttachLight(int _arg0_, const char* _arg1_, const EntityEffects::SLightAttachParams& _arg2_);
	IParticleEmitter* GetEffectEmitter(unsigned _arg0_) const;
	CItemScheduler* GetScheduler();
	IItemSystem* GetIItemSystem();
	CPlayer* GetOwnerPlayer() const;
	CItem* GetActorItem(IActor* _arg0_) const;
	bool ShouldNotDrop() const;
	bool CreateCharacterAttachment(int _arg0_, const char* _arg1_, int _arg2_, const char* _arg3_);
	void DestroyCharacterAttachment(int _arg0_, const char* _arg1_);
	ICharacterInstance* GetAppropriateCharacter(int _arg0_, bool _arg1_);
	IMaterial* GetCharacterAttachmentMaterial(int _arg0_, const char* _arg1_, bool _arg2_);
	const char* GetCharacterAttachmentBone(int _arg0_, const char* _arg1_);
	void SetCharacterAttachment(int _arg0_, const char* _arg1_, IEntity* _arg2_, bool _arg3_);
	void SetCharacterAttachment(int _arg0_, const char* _arg1_, IStatObj* _arg2_, bool _arg3_);
	void SetCharacterAttachment(int _arg0_, const char* _arg1_, ICharacterInstance* _arg2_, bool _arg3_);
	void SetCharacterAttachmentWorldTM(int _arg0_, const char* _arg1_, const Matrix34& _arg2_);
	Matrix34 GetCharacterAttachmentLocalTM(int _arg0_, const char* _arg1_);
	Matrix34 GetCharacterAttachmentWorldTM(int _arg0_, const char* _arg1_);
	void HideCharacterAttachment(int _arg0_, const char* _arg1_, bool _arg2_);
	void HideCharacterAttachmentMaster(int _arg0_, const char* _arg1_, bool _arg2_);
	void CreateAttachmentHelpers(int _arg0_);
	void DestroyAttachmentHelpers(int _arg0_);
	const std::vector<SAttachmentHelper>& GetAttachmentHelpers();
	int GetFragmentID(const char* _arg0_, const CTagDefinition* * _arg1_);
	IEntityAudioProxy* GetAudioProxy(bool _arg0_);
	unsigned NetGetOwnerId() const;
	void NetSetOwnerId(unsigned _arg0_);
	bool IsAutoDroppable() const;
	bool CanPickUpAutomatically() const;
	bool IsIdentical(CItem* _arg0_) const;
	static const CItem::MethodInfo_SvRequestAttachAccessory& SvRequestAttachAccessory();
	static const CItem::MethodInfo_ClAttachAccessory& ClAttachAccessory();
	static const CItem::MethodInfo_ClAttachInitialAccessory& ClAttachInitialAccessory();
	static const CItem::MethodInfo_SvRequestDetachAccessory& SvRequestDetachAccessory();
	static const CItem::MethodInfo_ClDetachAccessory& ClDetachAccessory();
	static const CItem::MethodInfo_SvRequestEnterModify& SvRequestEnterModify();
	static const CItem::MethodInfo_SvRequestLeaveModify& SvRequestLeaveModify();
	static const CItem::MethodInfo_ClEnterModify& ClEnterModify();
	static const CItem::MethodInfo_ClLeaveModify& ClLeaveModify();
	void SetItemFlags(unsigned _arg0_);
	void ClearItemFlags(unsigned _arg0_);
	void SetItemFlag(unsigned _arg0_, bool _arg1_);
	bool AreAnyItemFlagsSet(unsigned _arg0_) const;
	bool IsServer();
	bool IsClient();
	bool IsSelectGrabbingWeapon() const;
	void Prepare1pAnimationDbas();
	void Prepare1pChrs();
	const CItemSharedParams* GetSharedItemParams() const;
	IActionController* GetActionController() const;
	const SMannequinItemParams& GetMannequinItemParams() const;
	const SMannequinItemParams::FragmentIDs& GetFragmentIds() const;
	void OnItemSelectActionComplete();
	void ForceSelectActionComplete();
	IAttachment* GetCharacterAttachment(ICharacterInstance* _arg0_, const char* _arg1_) const;
	void UpdateLowerItem(CPlayer* _arg0_);
	void RegisterAs1pDbaUser();
	void UnRegisterAs1pDbaUser();
	void RegisterAs1pChrUser();
	void UnRegisterAs1pChrUser();
	void RegisterAs1pAudioCacheUser();
	void UnRegisterAs1pAudioCacheUser();
	void RegisterAs3pAudioCacheUser();
	void UnRegisterAs3pAudioCacheUser();
	void AudioCacheItemAndAccessories(const bool _arg0_, const char* _arg1_);
	bool IsAudioCached(const IEntityClass* _arg0_, const char* _arg1_);
	void AttachDefaultAttachment(IEntityClass* _arg0_);
#endif

	static inline auto FCItemOv1 = PreyFunction<void(CItem* const _this)>(0x1878BF0);
	static inline auto FBitNotCItem = PreyFunction<void(CItem* const _this)>(0x1879050);
	static inline auto FGetType = PreyFunction<const char* (const CItem* const _this)>(0x187C2F0);
	static inline auto FInit = PreyFunction<bool(CItem* const _this, IGameObject* pGameObject)>(0x187C990);
	static inline auto FInitClient = PreyFunction<void(CItem* const _this, int channelId)>(0x1885220);
	static inline auto FPostInitClient = PreyFunction<void(CItem* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(CItem* const _this, IGameObject* pGameObject)>(0x187DAD0);
	static inline auto FReloadExtension = PreyFunction<bool(CItem* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x187E5E0);
	static inline auto FPostReloadExtension = PreyFunction<void(CItem* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CItem* const _this, TSerialize signature)>(0x1A302A0);
	static inline auto FRelease = PreyFunction<void(CItem* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CItem* const _this, TSerialize ser)>(0x187B5F0);
	static inline auto FNetSerialize = PreyFunction<bool(CItem* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags)>(0x187D860);
	static inline auto FGetNetSerializeAspects = PreyFunction<unsigned(CItem* const _this)>(0x114BBC0);
	static inline auto FPostSerialize = PreyFunction<void(CItem* const _this)>(0x187DB60);
	static inline auto FSerializeLTL = PreyFunction<void(CItem* const _this, TSerialize ser)>(0x187F8E0);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CItem* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CItem* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CItem* const _this, SEntityUpdateContext& ctx, int slot)>(0x18805A0);
	static inline auto FPostUpdate = PreyFunction<void(CItem* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CItem* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CItem* const _this, const SGameObjectEvent& evt)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CItem* const _this, SEntityEvent& event)>(0x187E300);
	static inline auto FSetChannelId = PreyFunction<void(CItem* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CItem* const _this, bool auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CItem* const _this, ICrySizer* s)>(0x187BFF0);
	static inline auto FOnAction = PreyFunction<void(CItem* const _this, unsigned actorId, const CCryName& actionId, int activationMode, float value)>(0x1333E90);
	static inline auto FUpdateFPView = PreyFunction<void(CItem* const _this, float frameTime)>(0x1890D60);
	static inline auto FFilterView = PreyFunction<bool(CItem* const _this, SViewParams& viewParams)>(0x13B0900);
	static inline auto FPostFilterView = PreyFunction<void(CItem* const _this, SViewParams& viewParams)>(0x1333E90);
	static inline auto FGetFPOffset = PreyFunction<void(const CItem* const _this, QuatT& offset)>(0x187BF60);
	static inline auto FShouldBindOnInit = PreyFunction<bool(const CItem* const _this)>(0x1A302A0);
	static inline auto FCheckAmmoRestrictions = PreyFunction<bool(CItem* const _this, IInventory* pInventory)>(0x187A0E0);
	static inline auto FGetIWeaponOv1 = PreyFunction<IWeapon* (CItem* const _this)>(0x1CBB0B0);
	static inline auto FGetIWeaponOv0 = PreyFunction<const IWeapon* (const CItem* const _this)>(0x1CBB0B0);
	static inline auto FIsAccessory = PreyFunction<bool(CItem* const _this)>(0x13B0900);
	static inline auto FSetOwnerId = PreyFunction<void(CItem* const _this, unsigned ownerId)>(0x1333E90);
	static inline auto FGetOwnerId = PreyFunction<unsigned(const CItem* const _this)>(0x187C1E0);
	static inline auto FReset = PreyFunction<void(CItem* const _this)>(0x187E690);
	static inline auto FResetOwner = PreyFunction<void(CItem* const _this)>(0x187E990);
	static inline auto FResetParams = PreyFunction<bool(CItem* const _this)>(0x187EA30);
	static inline auto FPreResetParams = PreyFunction<void(CItem* const _this)>(0x1333E90);
	static inline auto FRemoveEntity = PreyFunction<void(CItem* const _this, bool force)>(0x18891E0);
	static inline auto FSetParentId = PreyFunction<void(CItem* const _this, unsigned parentId)>(0x1880100);
	static inline auto FGetParentId = PreyFunction<unsigned(const CItem* const _this)>(0x187C2B0);
	static inline auto FSetHand = PreyFunction<void(CItem* const _this, int hand)>(0x187FFE0);
	static inline auto FSwitchToHand = PreyFunction<void(CItem* const _this, int hand)>(0x18803F0);
	static inline auto FUse = PreyFunction<void(CItem* const _this, unsigned userId)>(0x1881270);
	static inline auto FSelect = PreyFunction<void(CItem* const _this, bool select)>(0x187EAF0);
	static inline auto FDrop = PreyFunction<void(CItem* const _this, float impulseScale, bool selectNext, bool byDeath)>(0x187ADE0);
	static inline auto FPickUp = PreyFunction<bool(CItem* const _this, unsigned pickerId, bool sound, bool select, bool keepHistory, const char* setup, bool _bDropIfFull)>(0x1A302A0);
	static inline auto FPhysicalize = PreyFunction<void(CItem* const _this, bool enable, bool rigid)>(0x187D980);
	static inline auto FUnholstering = PreyFunction<void(CItem* const _this, bool playSelect, float biasSelectTime)>(0x1880570);
	static inline auto FFindPhysicalisationType = PreyFunction<CItem::ePhysicalization(CItem* const _this, bool enable, bool rigid)>(0x187B5D0);
	static inline auto FDeferPhysicalize = PreyFunction<void(CItem* const _this, bool enable, bool rigid)>(0x187A530);
	static inline auto FPickalize = PreyFunction<void(CItem* const _this, bool enable, bool dropped)>(0x187D9F0);
	static inline auto FImpulse = PreyFunction<void(CItem* const _this, const Vec3& position, const Vec3& direction, float impulse)>(0x187C850);
	static inline auto FCanPickUp = PreyFunction<bool(const CItem* const _this, unsigned userId)>(0x187A000);
	static inline auto FCanDrop = PreyFunction<bool(const CItem* const _this)>(0x1879FF0);
	static inline auto FCanUse = PreyFunction<bool(const CItem* const _this, unsigned userId)>(0x1A302A0);
	static inline auto FIsMountable = PreyFunction<bool(const CItem* const _this)>(0x187D320);
	static inline auto FIsMounted = PreyFunction<bool(const CItem* const _this)>(0x187D330);
	static inline auto FIsRippedOff = PreyFunction<bool(const CItem* const _this)>(0x13B0900);
	static inline auto FCanRipOff = PreyFunction<bool(const CItem* const _this)>(0x13B0900);
	static inline auto FIsHeavyWeapon = PreyFunction<bool(const CItem* const _this)>(0x13B0900);
	static inline auto FIsUsed = PreyFunction<bool(const CItem* const _this)>(0x187D3B0);
	static inline auto FIsPickable = PreyFunction<bool(const CItem* const _this)>(0x187D340);
	static inline auto FShouldAttachWhenSelected = PreyFunction<bool(CItem* const _this)>(0x1A302A0);
	static inline auto FInitRespawn = PreyFunction<bool(CItem* const _this)>(0x187D2B0);
	static inline auto FTriggerRespawn = PreyFunction<void(CItem* const _this)>(0x1880460);
	static inline auto FCloakEnable = PreyFunction<void(CItem* const _this, bool enable, bool fade, float cloakBlendSpeedScale, bool bFadeByDistance, uint8_t colorChannel, bool bIgnoreCloakRefractionColor, unsigned syncedFromId)>(0x1333E90);
	static inline auto FCloakSync = PreyFunction<void(CItem* const _this, bool fade)>(0x187A4C0);
	static inline auto FGetMountedAngleLimits = PreyFunction<Vec3*(const CItem* const _this, Vec3* _return_value_)>(0x187C060);
	static inline auto FGetMountedDir = PreyFunction<Vec3*(const CItem* const _this, Vec3* _return_value_)>(0x187C0A0);
	static inline auto FSetMountedAngleLimits = PreyFunction<void(CItem* const _this, float min_pitch, float max_pitch, float yaw_range)>(0x18800D0);
	static inline auto FCanSelect = PreyFunction<bool(const CItem* const _this)>(0x187A0D0);
	static inline auto FCanDeselect = PreyFunction<bool(const CItem* const _this)>(0x1879FD0);
	static inline auto FIsSelecting = PreyFunction<bool(const CItem* const _this)>(0x187D390);
	static inline auto FIsSelected = PreyFunction<bool(const CItem* const _this)>(0x187D380);
	static inline auto FOnParentSelect = PreyFunction<void(CItem* const _this, bool select)>(0x1333E90);
	static inline auto FOnParentReloaded = PreyFunction<void(CItem* const _this)>(0x1333E90);
	static inline auto FSetAccessoryReloadTags = PreyFunction<void(CItem* const _this, CTagState& fragTags)>(0x1333E90);
	static inline auto FMountAt = PreyFunction<void(CItem* const _this, const Vec3& pos)>(0x187D3C0);
	static inline auto FMountAtEntity = PreyFunction<void(CItem* const _this, unsigned entityId, const Vec3& pos, const Ang3& angles)>(0x187D4F0);
	static inline auto FStartUse = PreyFunction<void(CItem* const _this, unsigned userId)>(0x1880160);
	static inline auto FStopUse = PreyFunction<void(CItem* const _this, unsigned userId)>(0x18802B0);
	static inline auto FApplyViewLimit = PreyFunction<void(CItem* const _this, unsigned userId, bool apply)>(0x1333E90);
	static inline auto FEnableSound = PreyFunction<void(CItem* const _this, bool enable)>(0x187B510);
	static inline auto FIsSoundEnabled = PreyFunction<bool(const CItem* const _this)>(0x187D3A0);
	static inline auto FIsModifying = PreyFunction<bool(const CItem* const _this)>(0x187D310);
	static inline auto FPickUpAmmo = PreyFunction<void(CItem* const _this, unsigned pickerId)>(0x1333E90);
	static inline auto FHasSomeAmmoToPickUp = PreyFunction<bool(const CItem* const _this, unsigned pickerId)>(0x13B0900);
	static inline auto FSetAspectProfile = PreyFunction<bool(IGameObjectProfileManager* const _this, EEntityAspects aspect, uint8_t profile)>(0x187FC10);
	static inline auto FGetDefaultProfile = PreyFunction<uint8_t(IGameObjectProfileManager* const _this, EEntityAspects aspect)>(0x187BF30);
	static inline auto FStartDeselection = PreyFunction<unsigned(CItem* const _this, bool fastDeselect)>(0x1CBB0B0);
	static inline auto FCancelDeselection = PreyFunction<void(CItem* const _this)>(0x1333E90);
	static inline auto FIsDeselecting = PreyFunction<bool(const CItem* const _this)>(0x13B0900);
	static inline auto FOnStartUsing = PreyFunction<void(CItem* const _this)>(0x18869E0);
	static inline auto FOnStopUsing = PreyFunction<void(CItem* const _this)>(0x1333E90);
	static inline auto FOnSelect = PreyFunction<void(CItem* const _this, bool select)>(0x1333E90);
	static inline auto FOnSelected = PreyFunction<void(CItem* const _this, bool selected)>(0x1886930);
	static inline auto FOnReloaded = PreyFunction<void(CItem* const _this)>(0x1886670);
	static inline auto FOnEnterFirstPerson = PreyFunction<void(CItem* const _this)>(0x18862E0);
	static inline auto FOnEnterThirdPerson = PreyFunction<void(CItem* const _this)>(0x1886360);
	static inline auto FOnReset = PreyFunction<void(CItem* const _this)>(0x1886750);
	static inline auto FOnPickedUp = PreyFunction<void(CItem* const _this, unsigned actorId, bool destroyed)>(0x1333E90);
	static inline auto FOnDropped = PreyFunction<void(CItem* const _this, unsigned actorId, bool ownerWasAI)>(0x18862B0);
	static inline auto FOnBeginCutScene = PreyFunction<void(CItem* const _this)>(0x1333E90);
	static inline auto FOnEndCutScene = PreyFunction<void(CItem* const _this)>(0x1333E90);
	static inline auto FOnOwnerActivated = PreyFunction<void(CItem* const _this)>(0x1886650);
	static inline auto FOnOwnerDeactivated = PreyFunction<void(CItem* const _this)>(0x1886660);
	static inline auto FOnOwnerStanceChanged = PreyFunction<void(CItem* const _this, const EStance stance)>(0x1333E90);
	static inline auto FGetStats = PreyFunction<const CItem::SStats& (const CItem* const _this)>(0x9A1B10);
	static inline auto FGetParams = PreyFunction<const SParams& (const CItem* const _this)>(0x187C2A0);
	static inline auto FGetMountedParams = PreyFunction<const SMountParams* (const CItem* const _this)>(0x187C0D0);
	static inline auto FGetProperties = PreyFunction<const CItem::SEntityProperties& (const CItem* const _this)>(0x187C2C0);
	static inline auto FReadItemParams = PreyFunction<bool(CItem* const _this, const IItemParamsNode* root)>(0x1A302A0);
	static inline auto FInitItemFromParams = PreyFunction<void(CItem* const _this)>(0x18872C0);
	static inline auto FInitGeometry = PreyFunction<void(CItem* const _this)>(0x18872B0);
	static inline auto FInitAccessories = PreyFunction<void(CItem* const _this)>(0x18871F0);
	static inline auto FInitDamageLevels = PreyFunction<void(CItem* const _this)>(0x1887250);
	static inline auto FReadProperties = PreyFunction<void(CItem* const _this, IScriptTable* pProperties)>(0x18872F0);
	static inline auto FRemoveAccessoryOv1 = PreyFunction<void(CItem* const _this, const SharedString::CSharedString& name)>(0x1333E90);
	static inline auto FRemoveAccessoryOv0 = PreyFunction<void(CItem* const _this, IEntityClass* pClass)>(0x1882EE0);
	static inline auto FRemoveAllAccessories = PreyFunction<void(CItem* const _this)>(0x1883000);
	static inline auto FDetachAllAccessories = PreyFunction<void(CItem* const _this)>(0x18822A0);
	static inline auto FAttachAccessoryOv1 = PreyFunction<void(CItem* const _this, const SharedString::CSharedString& name, bool attach, bool noanim, bool force, bool firstTimeAttached, bool initialLoadoutSetup)>(0x1881860);
	static inline auto FAttachAccessoryOv0 = PreyFunction<void(CItem* const _this, IEntityClass* pAccessoryClass, bool attach, bool noanim, bool force, bool firstTimeAttached, bool initialLoadoutSetup)>(0x1881940);
	static inline auto FGetAccessoryOv1 = PreyFunction<CItem* (CItem* const _this, const SharedString::CSharedString& name)>(0x1882590);
	static inline auto FIsFirstTimeAccessoryAttached = PreyFunction<bool(const CItem* const _this, IEntityClass* pClass)>(0x18827D0);
	static inline auto FAccessoryDetachAction = PreyFunction<void(CItem* const _this, CItem* pAccessory, const SAccessoryParams* params)>(0x1881460);
	static inline auto FShowAttachmentHelper = PreyFunction<void(CItem* const _this, int slot, const char* name, bool show)>(0x1883220);
	static inline auto FGetAccessoryParams = PreyFunction<const SAccessoryParams* (const CItem* const _this, const IEntityClass* pClass)>(0x1882630);
	static inline auto FInitialSetup = PreyFunction<void(CItem* const _this)>(0x1882720);
	static inline auto FPatchInitialSetup = PreyFunction<void(CItem* const _this)>(0x1882840);
	static inline auto FReAttachAccessories = PreyFunction<void(CItem* const _this)>(0x1882C70);
	static inline auto FAccessoriesChanged = PreyFunction<void(CItem* const _this, bool initialLoadoutSetup)>(0x1881380);
	static inline auto FFixAccessories = PreyFunction<void(CItem* const _this, const SAccessoryParams* newParams, bool attach)>(0x1333E90);
	static inline auto FResetAccessoriesScreen = PreyFunction<void(CItem* const _this, IActor* pOwner)>(0x18831E0);
	static inline auto FRemoveOwnerAttachedAccessories = PreyFunction<void(CItem* const _this)>(0x18830D0);
	static inline auto FSwitchAccessory = PreyFunction<void(CItem* const _this, const SharedString::CSharedString& accessory)>(0x1883440);
	static inline auto FDoSwitchAccessory = PreyFunction<void(CItem* const _this, const SharedString::CSharedString& inAccessory, bool initialLoadoutSetup)>(0x18823E0);
	static inline auto FDetachAccessory = PreyFunction<void(CItem* const _this, const SharedString::CSharedString& accessory)>(0x18821F0);
	static inline auto FGetWorldTM = PreyFunction<const Matrix34*(const CItem* const _this, const Matrix34* _return_value_)>(0x187C300);
	static inline auto FAddAccessoryAmmoToInventory = PreyFunction<void(CItem* const _this, IEntityClass* pAmmoType, int count, IInventory* pOwnerInventory)>(0x18797D0);
	static inline auto FGivesAmmo = PreyFunction<bool(CItem* const _this)>(0x187C5D0);
	static inline auto FProcessAccessoryAmmo = PreyFunction<void(CItem* const _this, IInventory* pOwnerInventory, IWeapon* pParentWeapon)>(0x187E180);
	static inline auto FGetSecondaryFiremodeAccessory = PreyFunction<const SAccessoryParams* (const CItem* const _this)>(0x1CBB0B0);
	static inline auto FGetDefaultOverrideAccessory = PreyFunction<const SAccessoryParams* (const CItem* const _this)>(0x1CBB0B0);
	static inline auto FAddAccessory = PreyFunction<CItem* (CItem* const _this, IEntityClass* pClass)>(0x1881610);
	static inline auto FHasAccessoryOv1 = PreyFunction<bool(CItem* const _this, const SharedString::CSharedString& name)>(0x18826A0);
	static inline auto FAttachEffect = PreyFunction<unsigned(CItem* const _this, int slot, bool attachToAccessory, const char* effectName, const char* helper, const Vec3& offset, const Vec3& dir, float scale, bool prime)>(0x1885710);
	static inline auto FDetachEffect = PreyFunction<void(CItem* const _this, unsigned id)>(0x18861E0);
	static inline auto FAttachToHand = PreyFunction<bool(CItem* const _this, bool attach, bool checkAttachment)>(0x1879BB0);
	static inline auto FAttachToBack = PreyFunction<bool(CItem* const _this, bool attach)>(0x18797F0);
	static inline auto FChooseAttachmentPoint = PreyFunction<CItem::eItemAttachment(const CItem* const _this, bool attach, IAttachment* * attachmentPt)>(0x187A1E0);
	static inline auto FEnableUpdate = PreyFunction<void(CItem* const _this, bool enable, int slot)>(0x187B520);
	static inline auto FRequireUpdate = PreyFunction<void(CItem* const _this, int slot)>(0x187E630);
	static inline auto FHide = PreyFunction<void(CItem* const _this, bool hide, bool remoteUpdate)>(0x187C660);
	static inline auto FHideItem = PreyFunction<void(CItem* const _this, bool hide)>(0x187C710);
	static inline auto FSetBusy = PreyFunction<void(CItem* const _this, bool busy)>(0x187FF20);
	static inline auto FIsBusy = PreyFunction<bool(const CItem* const _this)>(0x187D300);
	static inline auto FGetOwner = PreyFunction<IEntity* (const CItem* const _this)>(0x187C0E0);
	static inline auto FGetOwnerActor = PreyFunction<CCryActor* (const CItem* const _this)>(0x187C100);
	static inline auto FGetOwnerInventory = PreyFunction<IInventory* (unsigned _id)>(0x187C1F0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CItem* const _this)>(0xDBE270);
	static inline auto FGetIcon = PreyFunction<const char* (const CItem* const _this)>(0x187BFB0);
	static inline auto FGetInventoryDimensions = PreyFunction<void(const CItem* const _this, int& width, int& height)>(0x187BFD0);
	static inline auto FGetDescription = PreyFunction<const char* (const CItem* const _this)>(0x187BF40);
	static inline auto FForcePendingActions = PreyFunction<void(CItem* const _this, uint8_t blockedActions)>(0x1333E90);
	static inline auto FHasFastSelect = PreyFunction<bool(const CItem* const _this, unsigned nextItemId)>(0x187C600);
	static inline auto FShouldPlaySelectAction = PreyFunction<bool(const CItem* const _this)>(0x1880130);
	static inline auto FRegisterFPWeaponForRenderingAlways = PreyFunction<void(CItem* const _this, bool registerRenderAlways)>(0x187E5A0);
	static inline auto FIsOwnerFP = PreyFunction<bool(CItem* const _this)>(0x1890A70);
	static inline auto FUpdateMounted = PreyFunction<void(CItem* const _this, float frameTime)>(0x1890EE0);
	static inline auto FCheckViewChange = PreyFunction<void(CItem* const _this)>(0x18907E0);
	static inline auto FSetViewMode = PreyFunction<void(CItem* const _this, int mode)>(0x1890AC0);
	static inline auto FAttachToShadowHand = PreyFunction<void(CItem* const _this, bool attach)>(0x1333E90);
	static inline auto FCopyRenderFlags = PreyFunction<void(CItem* const _this, IEntity* pOwner)>(0x18908E0);
	static inline auto FUpdateIKMounted = PreyFunction<void(CItem* const _this, IActor* pActor, const Vec3& vGunXAxis)>(0x1890D80);
	static inline auto FResetCharacterAttachment = PreyFunction<void(CItem* const _this, int slot, const char* name, bool owner, unsigned attachedEntID)>(0x1889210);
	static inline auto FSetCharacterAttachmentOv0 = PreyFunction<void(CItem* const _this, int slot, const char* name, IEntity* pEntity, int objSlot, bool owner)>(0x1889310);
	static inline auto FSetCharacterAttachmentLocalTM = PreyFunction<void(CItem* const _this, int slot, const char* name, const Matrix34& tm)>(0x1889580);
	static inline auto FOnHit = PreyFunction<void(CItem* const _this, float damage, int hitType)>(0x18863D0);
	static inline auto FOnDestroyed = PreyFunction<void(CItem* const _this)>(0x1886200);
	static inline auto FOnRepaired = PreyFunction<void(CItem* const _this)>(0x18866D0);
	static inline auto FDestroyedGeometry = PreyFunction<void(CItem* const _this, bool use)>(0x1887800);
	static inline auto FUpdateDamageLevel = PreyFunction<void(CItem* const _this)>(0x1886A20);
	static inline auto FSetGeometry = PreyFunction<bool(CItem* const _this, int slot, const SharedString::CSharedString& name, const SharedString::CSharedString& material, bool useParentMaterial, const Vec3& poffset, const Ang3& aoffset, float scale, bool forceReload)>(0x1889860);
	static inline auto FPlayAction = PreyFunction<_smart_ptr<IAction>*(CItem* const _this, _smart_ptr<IAction>* _return_value_, int action, int layer, bool loop, unsigned flags, float speedOverride, float animWeigth, float ffeedbackWeight)>(0x1888D20);
	static inline auto FPlayFragment = PreyFunction<bool(CItem* const _this, IAction* pAction, float speedOverride, float timeOverride, float animWeight, float ffeedbackWeight, bool concentratedFire)>(0x1889040);
	static inline auto FSetFragmentTags = PreyFunction<void(CItem* const _this, CTagState& fragTags)>(0x1333E90);
	static inline auto FGetCurrentAnimationTime = PreyFunction<unsigned(CItem* const _this, int slot)>(0x1887990);
	static inline auto FDrawSlot = PreyFunction<void(CItem* const _this, int slot, bool bDraw, bool bNear)>(0x1887910);
	static inline auto FGetSlotHelperPos = PreyFunction<Vec3*(const CItem* const _this, Vec3* _return_value_, int slot, const char* helper, bool worldSpace, bool relative)>(0x1887B60);
	static inline auto FGetSlotHelperRotation = PreyFunction<const Matrix33& (CItem* const _this, int slot, const char* helper, bool worldSpace, bool relative)>(0x1887F70);
	static inline auto FQuiet = PreyFunction<void(CItem* const _this)>(0x1333E90);
	static inline auto FOnAttach = PreyFunction<void(CItem* const _this, bool attach)>(0x1333E90);
	static inline auto FGetRenderProxy = PreyFunction<IEntityRenderProxy* (CItem* const _this, bool create)>(0x1887A80);
	static inline auto FGetPhysicalProxy = PreyFunction<IEntityPhysicalProxy* (CItem* const _this, bool create)>(0x18879A0);
	static inline auto FDecode_SvRequestAttachAccessory = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1884030);
	static inline auto FHandle_SvRequestAttachAccessory = PreyFunction<bool(CItem* const _this, const CItem::AccessoryParams& params, INetChannel* pNetChannel)>(0x1884C80);
	static inline auto FDecode_ClAttachAccessory = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1883990);
	static inline auto FHandle_ClAttachAccessory = PreyFunction<bool(CItem* const _this, const CItem::AccessoryParams& params, INetChannel* pNetChannel)>(0x18845A0);
	static inline auto FDecode_ClAttachInitialAccessory = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1883AF0);
	static inline auto FHandle_ClAttachInitialAccessory = PreyFunction<bool(CItem* const _this, const CItem::AccessoryParams& params, INetChannel* pNetChannel)>(0x1884790);
	static inline auto FDecode_SvRequestDetachAccessory = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1884190);
	static inline auto FHandle_SvRequestDetachAccessory = PreyFunction<bool(CItem* const _this, const CItem::AccessoryParams& params, INetChannel* pNetChannel)>(0x1884EA0);
	static inline auto FDecode_ClDetachAccessory = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1883C50);
	static inline auto FHandle_ClDetachAccessory = PreyFunction<bool(CItem* const _this, const CItem::AccessoryParams& params, INetChannel* pNetChannel)>(0x1884980);
	static inline auto FDecode_SvRequestEnterModify = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18842F0);
	static inline auto FHandle_SvRequestEnterModify = PreyFunction<bool(CItem* const _this, const CItem::EmptyParams& params, INetChannel* pNetChannel)>(0x1885100);
	static inline auto FDecode_SvRequestLeaveModify = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1884430);
	static inline auto FHandle_SvRequestLeaveModify = PreyFunction<bool(CItem* const _this, const CItem::EmptyParams& params, INetChannel* pNetChannel)>(0x1885190);
	static inline auto FDecode_ClEnterModify = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1883DB0);
	static inline auto FHandle_ClEnterModify = PreyFunction<bool(CItem* const _this, const CItem::EmptyParams& params, INetChannel* pNetChannel)>(0x1884B80);
	static inline auto FDecode_ClLeaveModify = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1883EF0);
	static inline auto FHandle_ClLeaveModify = PreyFunction<bool(CItem* const _this, const CItem::EmptyParams& params, INetChannel* pNetChannel)>(0x1884C00);
	static inline auto FDoSelectWeaponGrab = PreyFunction<void(CItem* const _this)>(0x187ADA0);
	static inline auto FIsRippingOrRippedOff = PreyFunction<bool(const CItem* const _this)>(0x13B0900);
	static inline auto FForceRippingOff = PreyFunction<void(CItem* const _this, bool ripOff)>(0x1333E90);
	static inline auto FUpdateCurrentActionController = PreyFunction<void(CItem* const _this)>(0x1880A50);
	static inline auto FSetCurrentActionController = PreyFunction<void(CItem* const _this, IActionController* pActionController)>(0x187FF30);
	static inline auto FSetSubContextID = PreyFunction<void(CItem* const _this, int subContext)>(0x1880110);
	static inline auto FGetSubContextID = PreyFunction<int(CItem* const _this)>(0x187C2E0);
	static inline auto FGetAttachedAccessoriesString = PreyFunction<const string*(CItem* const _this, const string* _return_value_, const char* separator)>(0x187BE10);
	static inline auto FInitActionController = PreyFunction<bool(CItem* const _this, IEntity* pEntity)>(0x187D040);
	static inline auto FShouldDoPostSerializeReset = PreyFunction<bool(const CItem* const _this)>(0x1880120);
	static inline auto FUpdateActionControllerSelection = PreyFunction<void(CItem* const _this, bool bSelected)>(0x1880980);
	static inline auto FDropAfterRaycast = PreyFunction<void(CItem* const _this, const unsigned& rayID, const RayCastResult& result)>(0x187B380);
	static inline auto FDetachItem = PreyFunction<void(CItem* const _this, IEntity* pThisItemEntity, CCryActor* pOwnerActor, float impulseScale, Vec3 localDropDirection)>(0x187A560);
	static inline auto FGetSelectSpeed = PreyFunction<float(CItem* const _this, CCryActor* pOwnerActor)>(0x1AE7A80);
	static inline auto FRegisterAsUser = PreyFunction<void(CItem* const _this)>(0x187E4C0);
	static inline auto FUnRegisterAsUser = PreyFunction<void(CItem* const _this)>(0x18804C0);
	static inline auto FAudioCacheItem = PreyFunction<void(const bool enable, const IEntityClass* pClass, const char* prefix, const char* postfix)>(0x1333E90);
	static inline auto FGetOwnerAttachmentManager = PreyFunction<IAttachmentManager* (const CItem* const _this)>(0x187C190);
	static inline auto FUpdateTags = PreyFunction<void(const CItem* const _this, const IActionController* pActionController, CTagState& tagState, bool selected)>(0x1880FC0);
	static inline auto FUpdateAccessoryTags = PreyFunction<void(const CItem* const _this, const SMannequinItemParams* pParams, CTagState& tagState, bool selected)>(0x1880730);
	static inline auto FUpdateMountedTags = PreyFunction<void(const CItem* const _this, const SMannequinItemParams* pParams, CTagState& tagState, bool selected)>(0x1880AF0);
	static inline auto FUpdateScopeContexts = PreyFunction<void(CItem* const _this, IActionController* pController, int nCharacterSlot)>(0x1880BE0);
	static inline auto FClearScopeContexts = PreyFunction<void(CItem* const _this, IActionController* pController)>(0x187A410);
	static inline auto FOnUnlowerItem = PreyFunction<void(CItem* const _this)>(0x1333E90);
};

// SItemStrings
// Header:  Prey/GameDll/Item.h
struct SItemStrings
{ // Size=56 (0x38)
	SharedString::CSharedString nw;
	SharedString::CSharedString left_item_attachment;
	SharedString::CSharedString right_item_attachment;
	SharedString::CSharedString bottom;
	SharedString::CSharedString barrel;
	SharedString::CSharedString scope;
	SharedString::CSharedString ammo;

	SItemStrings();
	~SItemStrings();

	static inline auto FSItemStringsOv1 = PreyFunction<void(SItemStrings* const _this)>(0x1878E30);
	static inline auto FBitNotSItemStrings = PreyFunction<void(SItemStrings* const _this)>(0x1879520);
};
#endif // MOONCRASH
