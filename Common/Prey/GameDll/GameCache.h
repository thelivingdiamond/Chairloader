// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedstring.h>
#include <CryEngine/crycommon/ientitypoolmanager.h>
#include <_unknown/CryHashStringId.h>

struct IActorSystem;
struct ICharacterInstance;
class ICrySizer;
struct IEntityClass;
struct IMaterial;
struct IStatObj;
class ITexture;
struct SEntitySpawnParams;
struct SLuaCache_ActorGameParams;
struct SLuaCache_ActorPhysicsParams;
struct SLuaCache_ActorProperties;
class SmartScriptTable;
class XmlNodeRef;

// CGameCharacterDBAs
// Header:  Prey/GameDll/GameCache.h
class CGameCharacterDBAs
{ // Size=48 (0x30)
public:
	// CGameCharacterDBAs::SDBAGroup
	// Header:  Prey/GameDll/GameCache.h
	struct SDBAGroup
	{ // Size=32 (0x20)
		CryHashStringId m_groupId;
		int m_userCount;
		std::vector<string> m_dbas;

	#if 0
		SDBAGroup();
	#endif
	};

	// CGameCharacterDBAs::SDBAGroupUser
	// Header:  Prey/GameDll/GameCache.h
	struct SDBAGroupUser
	{ // Size=32 (0x20)
		unsigned m_userId;
		std::vector<int> m_dbaGroupIndices;

	#if 0
		SDBAGroupUser();
		bool operator==(const unsigned& _arg0_) const;
	#endif
	};

	using TCharacterDBAGroups = std::vector<CGameCharacterDBAs::SDBAGroup>;
	using TDBAGroupUsers = std::vector<CGameCharacterDBAs::SDBAGroupUser>;

	std::vector<CGameCharacterDBAs::SDBAGroupUser> m_dbaGroupUsers;
	std::vector<CGameCharacterDBAs::SDBAGroup> m_dbaGroups;

	bool AddUserToGroup(const unsigned userId, const std::vector<string>& dbaGroups) { return FAddUserToGroup(this, userId, dbaGroups); }
	void LoadXmlData() { FLoadXmlData(this); }

#if 0
	void RemoveUser(const unsigned _arg0_);
	void PreCacheForLevel();
	void Reset();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
	void Debug();
	bool IsEnabled() const;
	int GetGroupIndexByName(const char* _arg0_) const;
	CGameCharacterDBAs::SDBAGroup* GetGroupByIndex(int _arg0_);
	bool IsAlreadyRegistered(const unsigned _arg0_);
#endif

	static inline auto FAddUserToGroup = PreyFunction<bool(CGameCharacterDBAs* const _this, const unsigned userId, const std::vector<string>& dbaGroups)>(0x1809010);
	static inline auto FLoadXmlData = PreyFunction<void(CGameCharacterDBAs* const _this)>(0x180AE40);
};

// CGameCache
// Header:  Prey/GameDll/GameCache.h
class CGameCache : public IEntityPoolListener
{ // Size=200 (0xC8)
public:
	enum ECharacterFileModelCacheType
	{
		eCFMCache_Default = 0,
		eCFMCache_Client = 1,
		eCFMCache_Shadow = 2,
		eCFMCache_COUNT = 3,
	};

	// CGameCache::SActorClassLuaCache
	// Header:  Prey/GameDll/GameCache.h
	struct SActorClassLuaCache
	{ // Size=16 (0x10)
		_smart_ptr<SLuaCache_ActorPhysicsParams> pPhysicsParams;
		_smart_ptr<SLuaCache_ActorGameParams> pGameParams;
	};

	// CGameCache::SActorInstanceLuaCache
	// Header:  Prey/GameDll/GameCache.h
	struct SActorInstanceLuaCache
	{ // Size=8 (0x8)
		_smart_ptr<SLuaCache_ActorProperties> pProperties;
	};

	// CGameCache::STextureKey
	// Header:  Prey/GameDll/GameCache.h
	struct STextureKey
	{ // Size=8 (0x8)
		// CGameCache::STextureKey::compare
		// Header:  Prey/GameDll/GameCache.h
		struct compare
		{ // Size=1 (0x1)
		#if 0
			bool operator()(const CGameCache::STextureKey& _arg0_, const CGameCache::STextureKey& _arg1_) const;
		#endif
		};

		unsigned nameHash;
		int textureFlags;

	#if 0
		STextureKey();
		STextureKey(const unsigned& _arg0_, const int _arg1_);
	#endif
	};

	using TCachedModelName = CryFixedStringT<256>;
	using TActorClassLuaCacheMap = std::map<IEntityClass*, CGameCache::SActorClassLuaCache>;
	using TActorInstanceLuaCacheMap = std::map<unsigned int, CGameCache::SActorInstanceLuaCache>;
	using TCharacterInstancePtr = _smart_ptr<ICharacterInstance>;
	using TEditorCharacterFileModelCache = std::map<unsigned int, _smart_ptr<ICharacterInstance>>;
	using TTextureSmartPtr = _smart_ptr<ITexture>;
	using TGameTextureCacheMap = std::map<CGameCache::STextureKey, _smart_ptr<ITexture>, CGameCache::STextureKey::compare>;
	using TStaticObjectSmartPtr = _smart_ptr<IStatObj>;
	using TGameStaticObjectCacheMap = std::map<unsigned int, _smart_ptr<IStatObj>>;
	using TMaterialSmartPtr = _smart_ptr<IMaterial>;
	using TGameMaterialCacheMap = std::map<unsigned int, _smart_ptr<IMaterial>>;

	std::map<IEntityClass*, CGameCache::SActorClassLuaCache> m_ActorClassLuaCache;
	std::map<unsigned int, CGameCache::SActorInstanceLuaCache> m_ActorInstanceLuaCache;
	CGameCache::SActorInstanceLuaCache m_PlayerInstanceLuaCache;
	std::map<unsigned int, _smart_ptr<ICharacterInstance>> m_editorCharacterFileModelCache[3];
	std::map<CGameCache::STextureKey, _smart_ptr<ITexture>, CGameCache::STextureKey::compare> m_textureCache;
	std::map<unsigned int, _smart_ptr<IMaterial>> m_materialCache;
	std::map<unsigned int, _smart_ptr<IStatObj>> m_statiObjectCache;
	CGameCharacterDBAs m_characterDBAs;
	IActorSystem* m_pActorSystem;

	CGameCache();
	virtual ~CGameCache();
	void Init() { FInit(this); }
	void PrecacheLevel() { FPrecacheLevel(this); }
	void Reset() { FReset(this); }
	void ResetEntityInstanceProperties() { FResetEntityInstanceProperties(this); }
	void GetMemoryUsage(ICrySizer* s) const { FGetMemoryUsage(this, s); }
	static bool IsLuaCacheEnabled() { return FIsLuaCacheEnabled(); }
	virtual void OnPoolBookmarkCreated(unsigned entityId, const SEntitySpawnParams& params, XmlNodeRef entityNode);
	void CacheActorClass(IEntityClass* pClass, SmartScriptTable pEntityScript) { FCacheActorClass(this, pClass, pEntityScript); }
	void CacheActorInstance(unsigned entityId, SmartScriptTable pEntityScript, SmartScriptTable pPropertiesOverride, int modelVariation) { FCacheActorInstance(this, entityId, pEntityScript, pPropertiesOverride, modelVariation); }
	void RefreshActorInstance(unsigned entityId, SmartScriptTable pEntityScript, SmartScriptTable pPropertiesOverride) { FRefreshActorInstance(this, entityId, pEntityScript, pPropertiesOverride); }
	void CacheEntityArchetype(const char* archetypeName) { FCacheEntityArchetype(this, archetypeName); }
	void CacheArkItem(const char* _szArkItemArchetype) { FCacheArkItem(this, _szArkItemArchetype); }
	void CacheArkLootTable(uint64_t _lootTableId) { FCacheArkLootTable(this, _lootTableId); }
	_smart_ptr<SLuaCache_ActorPhysicsParams> GetActorPhysicsParams(IEntityClass* pClass) const { alignas(_smart_ptr<SLuaCache_ActorPhysicsParams>) std::byte _return_buf_[sizeof(_smart_ptr<SLuaCache_ActorPhysicsParams>)]; return *FGetActorPhysicsParams(this, reinterpret_cast<_smart_ptr<SLuaCache_ActorPhysicsParams>*>(_return_buf_), pClass); }
	_smart_ptr<SLuaCache_ActorGameParams> GetActorGameParams(IEntityClass* pClass) const { alignas(_smart_ptr<SLuaCache_ActorGameParams>) std::byte _return_buf_[sizeof(_smart_ptr<SLuaCache_ActorGameParams>)]; return *FGetActorGameParams(this, reinterpret_cast<_smart_ptr<SLuaCache_ActorGameParams>*>(_return_buf_), pClass); }
	_smart_ptr<SLuaCache_ActorProperties> GetActorProperties(unsigned entityId) const { alignas(_smart_ptr<SLuaCache_ActorProperties>) std::byte _return_buf_[sizeof(_smart_ptr<SLuaCache_ActorProperties>)]; return *FGetActorProperties(this, reinterpret_cast<_smart_ptr<SLuaCache_ActorProperties>*>(_return_buf_), entityId); }
	void CacheTexture(const char* textureFileName, const int textureFlags) { FCacheTexture(this, textureFileName, textureFlags); }
	void CacheGeometry(const char* geometryFileName) { FCacheGeometry(this, geometryFileName); }
	void CacheMaterial(const char* materialFileName) { FCacheMaterial(this, materialFileName); }
	bool PrepareDBAsFor(const unsigned userId, const std::vector<string>& dbaGroups) { return FPrepareDBAsFor(this, userId, dbaGroups); }
	void RemoveDBAUser(const unsigned userId) { FRemoveDBAUser(this, userId); }
	static SmartScriptTable GetProperties(SmartScriptTable pEntityScript, SmartScriptTable pPropertiesOverride) { return FGetProperties(pEntityScript, pPropertiesOverride); }
	void CreateActorClassLuaCache(IEntityClass* pClass, SmartScriptTable pEntityScript) { FCreateActorClassLuaCache(this, pClass, pEntityScript); }
	void UpdateActorInstanceCache(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,CGameCache::SActorInstanceLuaCache> > > > actorInstanceLuaCacheIt, SmartScriptTable pEntityScript, SmartScriptTable pProperties, int modelVariation) { FUpdateActorInstanceCacheOv1(this, actorInstanceLuaCacheIt, pEntityScript, pProperties, modelVariation); }
	bool UpdateActorInstanceCache(CGameCache::SActorInstanceLuaCache& actorInstanceLuaCache, SmartScriptTable pEntityScript, SmartScriptTable pProperties, int modelVariation) { return FUpdateActorInstanceCacheOv0(this, actorInstanceLuaCache, pEntityScript, pProperties, modelVariation); }
	void CacheAdditionalParams(SmartScriptTable pProperties) { FCacheAdditionalParams(this, pProperties); }

#if 0
	static bool IsCacheEnabled();
	void GetInstancePropertyValue(const char* _arg0_, CryStackStringT<char,512>& _arg1_, const XmlNodeRef& _arg2_, const SmartScriptTable& _arg3_, const SmartScriptTable& _arg4_);
	void Debug();
	static bool IsClient(unsigned _arg0_);
	const CGameCache::SActorClassLuaCache* GetActorClassLuaCache(IEntityClass* _arg0_) const;
	const CGameCache::SActorInstanceLuaCache* GetActorInstanceLuaCache(unsigned _arg0_) const;
	void CreateActorInstanceLuaCache(unsigned _arg0_, SmartScriptTable _arg1_, SmartScriptTable _arg2_, int _arg3_);
	void CacheFileModels(SmartScriptTable _arg0_);
	void CacheActorResources(SmartScriptTable _arg0_);
	void CacheCustomEntityResources(SmartScriptTable _arg0_);
	bool AddCachedCharacterFileModel(const CGameCache::ECharacterFileModelCacheType _arg0_, const char* _arg1_);
	bool IsCharacterFileModelCached(const char* _arg0_, unsigned& _arg1_) const;
#endif

	static inline auto FCGameCacheOv1 = PreyFunction<void(CGameCache* const _this)>(0x1808760);
	static inline auto FInit = PreyFunction<void(CGameCache* const _this)>(0x180ADB0);
	static inline auto FPrecacheLevel = PreyFunction<void(CGameCache* const _this)>(0x180B440);
	static inline auto FReset = PreyFunction<void(CGameCache* const _this)>(0x180B9D0);
	static inline auto FResetEntityInstanceProperties = PreyFunction<void(CGameCache* const _this)>(0x180BB90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CGameCache* const _this, ICrySizer* s)>(0x180AAD0);
	static inline auto FIsLuaCacheEnabled = PreyFunction<bool()>(0x180AE20);
	static inline auto FOnPoolBookmarkCreated = PreyFunction<void(CGameCache* const _this, unsigned entityId, const SEntitySpawnParams& params, XmlNodeRef entityNode)>(0x180B2C0);
	static inline auto FCacheActorClass = PreyFunction<void(CGameCache* const _this, IEntityClass* pClass, SmartScriptTable pEntityScript)>(0x1809230);
	static inline auto FCacheActorInstance = PreyFunction<void(CGameCache* const _this, unsigned entityId, SmartScriptTable pEntityScript, SmartScriptTable pPropertiesOverride, int modelVariation)>(0x18092D0);
	static inline auto FRefreshActorInstance = PreyFunction<void(CGameCache* const _this, unsigned entityId, SmartScriptTable pEntityScript, SmartScriptTable pPropertiesOverride)>(0x180B650);
	static inline auto FCacheEntityArchetype = PreyFunction<void(CGameCache* const _this, const char* archetypeName)>(0x1809B60);
	static inline auto FCacheArkItem = PreyFunction<void(CGameCache* const _this, const char* _szArkItemArchetype)>(0x1809670);
	static inline auto FCacheArkLootTable = PreyFunction<void(CGameCache* const _this, uint64_t _lootTableId)>(0x18098F0);
	static inline auto FGetActorPhysicsParams = PreyFunction<_smart_ptr<SLuaCache_ActorPhysicsParams>*(const CGameCache* const _this, _smart_ptr<SLuaCache_ActorPhysicsParams>* _return_value_, IEntityClass* pClass)>(0x180A950);
	static inline auto FGetActorGameParams = PreyFunction<_smart_ptr<SLuaCache_ActorGameParams>*(const CGameCache* const _this, _smart_ptr<SLuaCache_ActorGameParams>* _return_value_, IEntityClass* pClass)>(0x180A890);
	static inline auto FGetActorProperties = PreyFunction<_smart_ptr<SLuaCache_ActorProperties>*(const CGameCache* const _this, _smart_ptr<SLuaCache_ActorProperties>* _return_value_, unsigned entityId)>(0x180AA10);
	static inline auto FCacheTexture = PreyFunction<void(CGameCache* const _this, const char* textureFileName, const int textureFlags)>(0x180A240);
	static inline auto FCacheGeometry = PreyFunction<void(CGameCache* const _this, const char* geometryFileName)>(0x1809E50);
	static inline auto FCacheMaterial = PreyFunction<void(CGameCache* const _this, const char* materialFileName)>(0x180A100);
	static inline auto FPrepareDBAsFor = PreyFunction<bool(CGameCache* const _this, const unsigned userId, const std::vector<string>& dbaGroups)>(0x180B640);
	static inline auto FRemoveDBAUser = PreyFunction<void(CGameCache* const _this, const unsigned userId)>(0x180B860);
	static inline auto FGetProperties = PreyFunction<SmartScriptTable(SmartScriptTable pEntityScript, SmartScriptTable pPropertiesOverride)>(0x180AC90);
	static inline auto FCreateActorClassLuaCache = PreyFunction<void(CGameCache* const _this, IEntityClass* pClass, SmartScriptTable pEntityScript)>(0x180A380);
	static inline auto FUpdateActorInstanceCacheOv1 = PreyFunction<void(CGameCache* const _this, std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,CGameCache::SActorInstanceLuaCache> > > > actorInstanceLuaCacheIt, SmartScriptTable pEntityScript, SmartScriptTable pProperties, int modelVariation)>(0x180BBD0);
	static inline auto FUpdateActorInstanceCacheOv0 = PreyFunction<bool(CGameCache* const _this, CGameCache::SActorInstanceLuaCache& actorInstanceLuaCache, SmartScriptTable pEntityScript, SmartScriptTable pProperties, int modelVariation)>(0x180BC80);
	static inline auto FCacheAdditionalParams = PreyFunction<void(CGameCache* const _this, SmartScriptTable pProperties)>(0x1809560);
};
#endif // MOONCRASH
