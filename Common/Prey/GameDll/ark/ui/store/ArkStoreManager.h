// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/store/ArkFakeCatalogLoader.h>
#include <Prey/GameDll/ark/ui/store/ArkStoreCatalog.h>
#include <_unknown/ArkCommerceItem.h>
#include <_unknown/SItemEntry.h>

class ArkStoreUI;
class XmlNodeRef;

// ArkStoreManager
// Header:  Prey/GameDll/ark/ui/store/ArkStoreManager.h
class ArkStoreManager
{ // Size=112 (0x70)
public:
	enum class ERequestState
	{
		none = 0,
		init = 1,
		items_loading = 2,
		items_details = 3,
		success = 4,
		fail = 5,
	};

	ArkStoreCatalog m_catalog;
	ArkStoreUI& m_storeUI;
	ArkFakeCatalogLoader m_loader;
	std::unordered_map<uint64_t, SItemEntry> m_itemPricesById;
	ArkStoreManager::ERequestState m_requestState;
	bool m_bLoaded;

	ArkStoreManager(ArkStoreUI& _storeUI);
	~ArkStoreManager();
	void Update(float _fDelta) { FUpdate(this, _fDelta); }
	void ClearStore() { FClearStore(this); }
	const SItemEntry* GetPurchaseInfo(uint64_t _itemId) const { return FGetPurchaseInfo(this, _itemId); }
	void ResolveCatalogPricing(const std::vector<ArkCommerceItem>* _commerceItems) { FResolveCatalogPricing(this, _commerceItems); }

#if 0
	bool RequestCatalog();
	bool IsLoaded() const;
	const ArkStoreCatalog& GetCatalog() const;
	bool ReadStoreItemsCatalog(XmlNodeRef _arg0_);
#endif

	static inline auto FArkStoreManagerOv1 = PreyFunction<void(ArkStoreManager* const _this, ArkStoreUI& _storeUI)>(0x142E230);
	static inline auto FBitNotArkStoreManager = PreyFunction<void(ArkStoreManager* const _this)>(0x142E390);
	static inline auto FUpdate = PreyFunction<void(ArkStoreManager* const _this, float _fDelta)>(0x142E7C0);
	static inline auto FClearStore = PreyFunction<void(ArkStoreManager* const _this)>(0x142E3D0);
	static inline auto FGetPurchaseInfo = PreyFunction<const SItemEntry* (const ArkStoreManager* const _this, uint64_t _itemId)>(0x142E410);
	static inline auto FResolveCatalogPricing = PreyFunction<void(ArkStoreManager* const _this, const std::vector<ArkCommerceItem>* _commerceItems)>(0x142E510);
};
#endif // MOONCRASH
