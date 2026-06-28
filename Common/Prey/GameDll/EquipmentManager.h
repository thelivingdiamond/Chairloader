// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/EquipmentManager.h>
#include <Prey/CryAction/IItemSystem.h>

class ICrySizer;
struct IEquipmentPackPreCacheCallback;
class XmlNodeRef;

// CEquipmentManager
// Header:  Prey/GameDll/EquipmentManager.h
// Include: Prey/CryAction/EquipmentManager.h
class CEquipmentManager : public IEquipmentManager
{ // Size=32 (0x20)
public:
	// CEquipmentManager::SEquipmentPack
	// Header:  Prey/GameDll/EquipmentManager.h
	struct SEquipmentPack
	{ // Size=56 (0x38)
		string m_name;
		string m_primaryItem;
		std::vector<SEquipmentItem> m_items;
		std::map<string, int> m_ammoCount;

	#if 0
		void Init(const char* _arg0_);
		void PrepareForItems(uint64_t _arg0_);
		bool AddItem(const char* _arg0_, const char* _arg1_, const char* _arg2_, const int _arg3_);
		bool HasItem(const char* _arg0_) const;
		int NumItems() const;
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	using TEquipmentPackVec = std::vector<CEquipmentManager::SEquipmentPack*>;

	std::vector<CEquipmentManager::SEquipmentPack*> m_equipmentPacks;

	CEquipmentManager();
	virtual ~CEquipmentManager();
	virtual void DeleteAllEquipmentPacks();
	virtual void LoadEquipmentPacks(const XmlNodeRef& rootNode);
	virtual void LoadEquipmentPacksFromPath(const char* path);
	virtual bool LoadEquipmentPack(const XmlNodeRef& rootNode, bool bOverrideExisting);
	virtual bool GiveEquipmentPack(const char* _packName, bool _bAdd, bool _bSelectPrimary);
	virtual void PreCacheEquipmentPackResources(const char* packName, IEquipmentPackPreCacheCallback& preCacheCallback);
	CEquipmentManager::SEquipmentPack* GetPack(const char* packName) const { return FGetPack(this, packName); }

#if 0
	void DumpPacks();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FCEquipmentManagerOv1 = PreyFunction<void(CEquipmentManager* const _this)>(0x17E13D0);
	static inline auto FDeleteAllEquipmentPacks = PreyFunction<void(CEquipmentManager* const _this)>(0x17E14D0);
	static inline auto FLoadEquipmentPacks = PreyFunction<void(CEquipmentManager* const _this, const XmlNodeRef& rootNode)>(0x17E1F80);
	static inline auto FLoadEquipmentPacksFromPath = PreyFunction<void(CEquipmentManager* const _this, const char* path)>(0x17E2020);
	static inline auto FLoadEquipmentPack = PreyFunction<bool(CEquipmentManager* const _this, const XmlNodeRef& rootNode, bool bOverrideExisting)>(0x17E17F0);
	static inline auto FGiveEquipmentPack = PreyFunction<bool(CEquipmentManager* const _this, const char* _packName, bool _bAdd, bool _bSelectPrimary)>(0x17E1630);
	static inline auto FPreCacheEquipmentPackResources = PreyFunction<void(CEquipmentManager* const _this, const char* packName, IEquipmentPackPreCacheCallback& preCacheCallback)>(0x17E2330);
	static inline auto FGetPack = PreyFunction<CEquipmentManager::SEquipmentPack* (const CEquipmentManager* const _this, const char* packName)>(0x17E15C0);
};
#endif // MOONCRASH
