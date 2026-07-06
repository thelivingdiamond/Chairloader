// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/itemstring.h>

class CItemSharedParams;
struct ICharacterInstance;
class ICrySizer;
struct IMaterial;
struct IParticleEffect;
struct IStatObj;
class ITexture;
class XmlNodeRef;

// CItemAnimationDBAManager
// Header:  Prey/GameDll/itemresourcecache.h
class CItemAnimationDBAManager
{ // Size=48 (0x30)
public:
	// CItemAnimationDBAManager::SItemDBAInfo
	// Header:  Prey/GameDll/itemresourcecache.h
	struct SItemDBAInfo
	{ // Size=32 (0x20)
		int m_userCount;
		float m_requestedTime;
		std::vector<SharedString::CSharedString> m_dbas;

	#if 0
		SItemDBAInfo();
		void AddUser(const unsigned _arg0_);
		void RemoveUser(const unsigned _arg0_);
		int GetUserCount() const;
		void AddDbaPath(const SharedString::CSharedString& _arg0_);
		int GetDBACount() const;
		const char* GetDBA(int _arg0_) const;
		void SetRequestedTime(const float _arg0_);
		float GetRequestedTime() const;
	#endif
	};

	using TItemDBAPair = std::pair<SharedString::CSharedString, CItemAnimationDBAManager::SItemDBAInfo>;
	using TPreloadDBAArray = std::vector<std::pair<SharedString::CSharedString, CItemAnimationDBAManager::SItemDBAInfo>>;

	std::vector<std::pair<SharedString::CSharedString, CItemAnimationDBAManager::SItemDBAInfo>> m_inUseDBAs;
	std::vector<std::pair<SharedString::CSharedString, CItemAnimationDBAManager::SItemDBAInfo>> m_preloadedDBASlots;

	CItemAnimationDBAManager();
	void Reset() { FReset(this); }
	void AddDBAUser(const SharedString::CSharedString& animationGroup, const CItemSharedParams* pItemParams, const unsigned itemUserId) { FAddDBAUser(this, animationGroup, pItemParams, itemUserId); }
	void RemoveDBAUser(const SharedString::CSharedString& animationGroup, const unsigned itemUserId) { FRemoveDBAUser(this, animationGroup, itemUserId); }
	void Update(const float currentTime) { FUpdate(this, currentTime); }
	void Debug() { FDebug(this); }
	void GetMemoryStatistics(ICrySizer* s) { FGetMemoryStatistics(this, s); }
	void FreeSlotInPreloadListIfNeeded() { FFreeSlotInPreloadListIfNeeded(this); }

#if 0
	void RequestDBAPreLoad(const SharedString::CSharedString& _arg0_, const CItemSharedParams* _arg1_);
	bool IsValidDBAPath(const char* _arg0_) const;
	int IsDbaAlreadyInUse(const SharedString::CSharedString& _arg0_) const;
	CItemAnimationDBAManager::SItemDBAInfo& GetDbaInUse(const int _arg0_);
	int IsDbaAlreadyInPreloadList(const SharedString::CSharedString& _arg0_) const;
	CItemAnimationDBAManager::SItemDBAInfo& GetDbaInPreloadList(const int _arg0_);
	void RemoveFromPreloadListAndDoNotUnload(const SharedString::CSharedString& _arg0_);
	bool IsDbaManagementEnabled() const;
#endif

	static inline auto FCItemAnimationDBAManagerOv2 = PreyFunction<void(CItemAnimationDBAManager* const _this)>(0x188AF30);
	static inline auto FReset = PreyFunction<void(CItemAnimationDBAManager* const _this)>(0x188C650);
	static inline auto FAddDBAUser = PreyFunction<void(CItemAnimationDBAManager* const _this, const SharedString::CSharedString& animationGroup, const CItemSharedParams* pItemParams, const unsigned itemUserId)>(0x188B1B0);
	static inline auto FRemoveDBAUser = PreyFunction<void(CItemAnimationDBAManager* const _this, const SharedString::CSharedString& animationGroup, const unsigned itemUserId)>(0x188C490);
	static inline auto FUpdate = PreyFunction<void(CItemAnimationDBAManager* const _this, const float currentTime)>(0x188C8C0);
	static inline auto FDebug = PreyFunction<void(CItemAnimationDBAManager* const _this)>(0x188BC80);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CItemAnimationDBAManager* const _this, ICrySizer* s)>(0x188C340);
	static inline auto FFreeSlotInPreloadListIfNeeded = PreyFunction<void(CItemAnimationDBAManager* const _this)>(0x188C200);
};

// CItemGeometryCache
// Header:  Prey/GameDll/itemresourcecache.h
class CItemGeometryCache
{ // Size=32 (0x20)
public:
	using TCharacterInstancePtr = _smart_ptr<ICharacterInstance>;
	using TEditorCacheCharacterMap = std::map<unsigned int, _smart_ptr<ICharacterInstance>>;
	using TStatObjectPtr = _smart_ptr<IStatObj>;
	using TCacheStaticObjectMap = std::map<unsigned int, _smart_ptr<IStatObj>>;

	std::map<unsigned int, _smart_ptr<ICharacterInstance>> m_editorCachedCharacters;
	std::map<unsigned int, _smart_ptr<IStatObj>> m_cachedStaticObjects;

	void CacheGeometry(const char* objectFileName, bool useCgfStreaming, unsigned nLoadingFlags) { FCacheGeometry(this, objectFileName, useCgfStreaming, nLoadingFlags); }
	void GetMemoryStatistics(ICrySizer* s) { FGetMemoryStatistics(this, s); }

#if 0
	~CItemGeometryCache();
	void FlushCaches();
	void CacheGeometryFromXml(XmlNodeRef _arg0_, bool _arg1_, unsigned _arg2_);
	void CheckAndCacheGeometryFromXmlAttr(const char* _arg0_, bool _arg1_, unsigned _arg2_);
	bool IsCharacterCached(const unsigned _arg0_) const;
	bool IsStaticObjectCached(const unsigned _arg0_) const;
#endif

	static inline auto FCacheGeometry = PreyFunction<void(CItemGeometryCache* const _this, const char* objectFileName, bool useCgfStreaming, unsigned nLoadingFlags)>(0x188B550);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CItemGeometryCache* const _this, ICrySizer* s)>(0x188C3E0);
};

// CItemMaterialAndTextureCache
// Header:  Prey/GameDll/itemresourcecache.h
class CItemMaterialAndTextureCache
{ // Size=32 (0x20)
public:
	using TTexturePtr = _smart_ptr<ITexture>;
	using TCacheTextureMap = std::map<unsigned int, _smart_ptr<ITexture>>;
	using TMaterialPtr = _smart_ptr<IMaterial>;
	using TCacheMaterialMap = std::map<unsigned int, _smart_ptr<IMaterial>>;

	std::map<unsigned int, _smart_ptr<ITexture>> m_cachedTextures;
	std::map<unsigned int, _smart_ptr<IMaterial>> m_cachedMaterials;

	void FlushCaches() { FFlushCaches(this); }
	void CacheTexture(const char* textureFileName, bool noStreaming) { FCacheTexture(this, textureFileName, noStreaming); }
	void CacheMaterial(const char* materialFileName) { FCacheMaterial(this, materialFileName); }
	void GetMemoryStatistics(ICrySizer* s) { FGetMemoryStatistics(this, s); }

#if 0
	~CItemMaterialAndTextureCache();
	ITexture* GetCachedTexture(const char* _arg0_) const;
	bool IsTextureCached(const char* _arg0_) const;
	IMaterial* GetCachedMaterial(const char* _arg0_) const;
	bool IsMaterialCached(const char* _arg0_) const;
#endif

	static inline auto FFlushCaches = PreyFunction<void(CItemMaterialAndTextureCache* const _this)>(0x188C1E0);
	static inline auto FCacheTexture = PreyFunction<void(CItemMaterialAndTextureCache* const _this, const char* textureFileName, bool noStreaming)>(0x188BB40);
	static inline auto FCacheMaterial = PreyFunction<void(CItemMaterialAndTextureCache* const _this, const char* materialFileName)>(0x188B9F0);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CItemMaterialAndTextureCache* const _this, ICrySizer* s)>(0x188C3E0);
};

// CItemParticleEffectCache
// Header:  Prey/GameDll/itemresourcecache.h
class CItemParticleEffectCache
{ // Size=16 (0x10)
public:
	using TParticleEffectPtr = _smart_ptr<IParticleEffect>;
	using TCacheParticleMap = std::map<int, _smart_ptr<IParticleEffect>>;

	std::map<int, _smart_ptr<IParticleEffect>> m_cachedParticles;

	void GetMemoryStatistics(ICrySizer* s) { FGetMemoryStatistics(this, s); }

#if 0
	~CItemParticleEffectCache();
	void FlushCaches();
	void CacheParticle(const char* _arg0_);
	IParticleEffect* GetCachedParticle(const char* _arg0_) const;
	bool IsParticleCached(const char* _arg0_) const;
#endif

	static inline auto FGetMemoryStatistics = PreyFunction<void(CItemParticleEffectCache* const _this, ICrySizer* s)>(0x188C460);
};

// CItemPrefetchCHRManager
// Header:  Prey/GameDll/itemresourcecache.h
class CItemPrefetchCHRManager
{ // Size=32 (0x20)
public:
	// CItemPrefetchCHRManager::PrefetchSlot
	// Header:  Prey/GameDll/itemresourcecache.h
	struct PrefetchSlot
	{ // Size=16 (0x10)
		SharedString::CSharedString geomName;
		float requestTime;
	};

	using PrefetchSlotVec = std::vector<CItemPrefetchCHRManager::PrefetchSlot>;

	float m_fTimeout;
	std::vector<CItemPrefetchCHRManager::PrefetchSlot> m_prefetches;

	CItemPrefetchCHRManager();
	~CItemPrefetchCHRManager();
	void Reset() { FReset(this); }
	void Update(float fCurrTime) { FUpdate(this, fCurrTime); }

#if 0
	CItemPrefetchCHRManager(const CItemPrefetchCHRManager& _arg0_);
	void Prefetch(const SharedString::CSharedString& _arg0_);
	CItemPrefetchCHRManager& operator=(const CItemPrefetchCHRManager& _arg0_);
#endif

	static inline auto FCItemPrefetchCHRManagerOv1 = PreyFunction<void(CItemPrefetchCHRManager* const _this)>(0x188AFE0);
	static inline auto FBitNotCItemPrefetchCHRManager = PreyFunction<void(CItemPrefetchCHRManager* const _this)>(0x188B0C0);
	static inline auto FReset = PreyFunction<void(CItemPrefetchCHRManager* const _this)>(0x188C830);
	static inline auto FUpdate = PreyFunction<void(CItemPrefetchCHRManager* const _this, float fCurrTime)>(0x188CA70);
};
#endif // MOONCRASH
