// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <CryEngine/crycommon/cryfixedarray.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/CCryFlags.h>

enum EEntityAspects;
struct IAttachment;
struct ICharacterInstance;
class ICrySizer;
struct IEntity;
struct IEntityClass;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CAICorpse
// Header:  Prey/GameDll/ai/AICorpse.h
class CAICorpse : public CGameObjectExtensionHelper<CAICorpse, IGameObjectExtension>
{ // Size=136 (0x88)
public:
	// CAICorpse::AttachedItem
	// Header:  Prey/GameDll/ai/AICorpse.h
	struct AttachedItem
	{ // Size=24 (0x18)
		enum class #unnamed_enum_MaxWeapons
		{
			MaxWeapons = 2,
		};

		unsigned id;
		IEntityClass* pClass;
		string attachmentName;

	#if 0
		AttachedItem();
	#endif
	};

	CryFixedArray<CAICorpse::AttachedItem,2> m_attachedItemsInfo;
	unsigned m_priority;

	CAICorpse();
	virtual ~CAICorpse();
	virtual bool Init(IGameObject* pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& ctx, int slot);
	virtual void HandleEvent(const SGameObjectEvent& gameObjectEvent);
	virtual void ProcessEvent(SEntityEvent& entityEvent);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	void SetupFromSource(IEntity& sourceEntity, ICharacterInstance& characterInstance, const unsigned priority) { FSetupFromSource(this, sourceEntity, characterInstance, priority); }
	void AboutToBeRemoved() { FAboutToBeRemoved(this); }
	unsigned CloneAttachedItem(const CAICorpse::AttachedItem& attachedItem, IAttachment* pAttachment) { return FCloneAttachedItem(this, attachedItem, pAttachment); }

#if 0
	unsigned GetPriority() const;
#endif

	static inline auto FCAICorpseOv1 = PreyFunction<void(CAICorpse* const _this)>(0x10C1750);
	static inline auto FInit = PreyFunction<bool(CAICorpse* const _this, IGameObject* pGameObject)>(0x10C2130);
	static inline auto FInitClient = PreyFunction<void(CAICorpse* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(CAICorpse* const _this, IGameObject* pGameObject)>(0x10C2180);
	static inline auto FPostInitClient = PreyFunction<void(CAICorpse* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CAICorpse* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x10C21E0);
	static inline auto FPostReloadExtension = PreyFunction<void(CAICorpse* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CAICorpse* const _this, TSerialize signature)>(0x1A302A0);
	static inline auto FRelease = PreyFunction<void(CAICorpse* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CAICorpse* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CAICorpse* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x13B0900);
	static inline auto FPostSerialize = PreyFunction<void(CAICorpse* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CAICorpse* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CAICorpse* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CAICorpse* const _this, SEntityUpdateContext& ctx, int slot)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CAICorpse* const _this, const SGameObjectEvent& gameObjectEvent)>(0x10C1FB0);
	static inline auto FProcessEvent = PreyFunction<void(CAICorpse* const _this, SEntityEvent& entityEvent)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(CAICorpse* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CAICorpse* const _this, bool auth)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(CAICorpse* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CAICorpse* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CAICorpse* const _this, ICrySizer* pSizer)>(0x1333E90);
	static inline auto FSetupFromSource = PreyFunction<void(CAICorpse* const _this, IEntity& sourceEntity, ICharacterInstance& characterInstance, const unsigned priority)>(0x10C2840);
	static inline auto FAboutToBeRemoved = PreyFunction<void(CAICorpse* const _this)>(0x10C1960);
	static inline auto FCloneAttachedItem = PreyFunction<unsigned(CAICorpse* const _this, const CAICorpse::AttachedItem& attachedItem, IAttachment* pAttachment)>(0x10C1B30);
};

// CAICorpseManager
// Header:  Prey/GameDll/ai/AICorpse.h
class CAICorpseManager
{ // Size=32 (0x20)
public:
	// CAICorpseManager::CorpseInfo
	// Header:  Prey/GameDll/ai/AICorpse.h
	struct CorpseInfo
	{ // Size=8 (0x8)
		enum Flags
		{
			eFlag_PhysicsDisabled = 1,
			eFlag_FarAway = 2,
		};

		unsigned corpseId;
		CCryFlags<unsigned int> flags;

		CAICorpse* GetCorpse() { return FGetCorpse(this); }

	#if 0
		CorpseInfo(const unsigned _arg0_, const unsigned _arg1_);
		IEntity* GetCorpseEntity();
	#endif

		static inline auto FGetCorpse = PreyFunction<CAICorpse* (CAICorpseManager::CorpseInfo* const _this)>(0x10C1E30);
	};

	// CAICorpseManager::SCorpseParameters
	// Header:  Prey/GameDll/ai/AICorpse.h
	struct SCorpseParameters
	{ // Size=4 (0x4)
		enum Priority
		{
			ePriority_Normal = 0,
			ePriority_High = 1,
			ePriority_VeryHight = 2,
		};

		CAICorpseManager::SCorpseParameters::Priority priority;
	};

	using TCorpseArray = std::vector<CAICorpseManager::CorpseInfo>;

	std::vector<CAICorpseManager::CorpseInfo> m_corpsesArray;
	unsigned m_maxCorpses;
	unsigned m_lastUpdatedCorpseIdx;
	static inline auto s_pThis = PreyGlobal<CAICorpseManager*>(0x2D2A958);

	CAICorpseManager();
	~CAICorpseManager();
	void Reset() { FReset(this); }
	unsigned SpawnAICorpseFromEntity(IEntity& sourceEntity, const CAICorpseManager::SCorpseParameters& corpseParams) { return FSpawnAICorpseFromEntity(this, sourceEntity, corpseParams); }
	void Update(const float frameTime) { FUpdate(this, frameTime); }
	void RemoveAllCorpses(const char* requester) { FRemoveAllCorpses(this, requester); }
	static CAICorpseManager::SCorpseParameters::Priority GetPriorityForClass(const IEntityClass* pEntityClass) { return FGetPriorityForClass(pEntityClass); }
	void RemoveSomeCorpses() { FRemoveSomeCorpses(this); }

#if 0
	void RegisterAICorpse(const unsigned _arg0_, const unsigned _arg1_);
	void UnregisterAICorpse(const unsigned _arg0_);
	void DebugDraw();
	static CAICorpseManager* GetInstance();
	void RemoveCorpse(const unsigned _arg0_);
	CAICorpseManager::CorpseInfo* FindCorpseInfo(const unsigned _arg0_);
#endif

	static inline auto FCAICorpseManagerOv1 = PreyFunction<void(CAICorpseManager* const _this)>(0x10C1790);
	static inline auto FBitNotCAICorpseManager = PreyFunction<void(CAICorpseManager* const _this)>(0x10C1820);
	static inline auto FReset = PreyFunction<void(CAICorpseManager* const _this)>(0x10C27E0);
	static inline auto FSpawnAICorpseFromEntity = PreyFunction<unsigned(CAICorpseManager* const _this, IEntity& sourceEntity, const CAICorpseManager::SCorpseParameters& corpseParams)>(0x10C2C20);
	static inline auto FUpdate = PreyFunction<void(CAICorpseManager* const _this, const float frameTime)>(0x10C2F00);
	static inline auto FRemoveAllCorpses = PreyFunction<void(CAICorpseManager* const _this, const char* requester)>(0x10C2260);
	static inline auto FGetPriorityForClass = PreyFunction<CAICorpseManager::SCorpseParameters::Priority(const IEntityClass* pEntityClass)>(0x10C1EE0);
	static inline auto FRemoveSomeCorpses = PreyFunction<void(CAICorpseManager* const _this)>(0x10C2330);
};
#endif // MOONCRASH
