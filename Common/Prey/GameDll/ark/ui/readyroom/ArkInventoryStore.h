// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>
#include <Prey/GameDll/ark/ui/ArkInventoryUI.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <_unknown/IArkReadyRoomUI.h>

class ArkAuxiliaryInventory;
class ArkFabricationPlan;
class ArkReadyRoomManager;
class CArkItem;
class CCryName;
enum class EArkCanAdvanceResult;
enum class EArkReadyRoomPage;
struct IEntity;
struct IUIElement;
struct SEntityEvent;
struct SUIArguments;
struct SUIEventDesc;

// ArkInventoryStore
// Header:  Prey/GameDll/ark/ui/readyroom/ArkInventoryStore.h
class ArkInventoryStore
	: public ArkUIMenuBase<ArkInventoryStore>
	, public IArkReadyRoomUI
	, public IArkInventoryUIOwner
	, public IEntityEventListener
{ // Size=224 (0xE0)
public:
	enum class EFocus
	{
		list = 1,
		cart = 2,
		none = 3,
	};

	// ArkInventoryStore::ItemForSale
	// Header:  Prey/GameDll/ark/ui/readyroom/ArkInventoryStore.h
	class ItemForSale
	{ // Size=80 (0x50)
	public:
		uint64_t m_fabPlanId;
		const ArkFabricationPlan* m_pData;
		uint64_t m_categoryId;
		int m_categoryIndex;
		uint64_t m_archetype;
		IArkItem::EArkQualityTier m_qualityTier;
		wstring m_name;
		wstring m_description;
		string m_icon;
		int m_stackCount;
		bool m_bNew;

		ItemForSale(const ArkFabricationPlan* const _pFabPlan, bool _bNew);

	#if 0
		bool operator==(uint64_t _arg0_) const;
		bool operator<(const ArkInventoryStore::ItemForSale& _arg0_) const;
	#endif

		static inline auto FItemForSaleOv2 = PreyFunction<void(ArkInventoryStore::ItemForSale* const _this, const ArkFabricationPlan* const _pFabPlan, bool _bNew)>(0x146D7D0);
	};

	std::vector<ArkInventoryStore::ItemForSale> m_itemsForSale;
	ArkReadyRoomManager& m_readyRoomManager;
	ArkAuxiliaryInventory* m_pCartInventory;
	std::vector<CArkItem*> m_hiddenItems;
	CArkInventoryUI m_cartUI;
	int m_numPurchased;
	int m_totalCost;
	ArkInventoryStore::EFocus m_currentFocus;
	int m_currentListPos;
	unsigned m_highlightedCartItem;

	ArkInventoryStore(ArkReadyRoomManager& _readyRoomManager);
	virtual ~ArkInventoryStore();
	virtual unsigned SetupInputPrompts(unsigned _startingIndex);
	virtual bool IsAvailable() const;
	virtual void Open();
	virtual bool ProcessInput(CCryName _action, int _activationMode, float _value);
	virtual EArkCanAdvanceResult CanAdvance() const;
	virtual void Close(bool _bImmediate, bool _bExitReadyRoom);
	virtual void Cleanup();
	virtual void Reset();
	virtual void OnLaunch();
	virtual const char* GetLabel() const;
	float GetTotalCost() const { return FGetTotalCost(this); }
	int GetNumPurchases() const { return FGetNumPurchases(this); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	void ResetCart() { FResetCart(this); }
	void OnCartItemSelected(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnCartItemSelected(this, _pSender, _event, _args); }
	void OnListItemSelected(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnListItemSelected(this, _pSender, _event, _args); }
	void OnSaleItemDoubleClick(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnSaleItemDoubleClick(this, _pSender, _event, _args); }
	void OnSetFocus(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnSetFocus(this, _pSender, _event, _args); }
	void PopulateSaleItems() { FPopulateSaleItems(this); }
	void AddToCart(uint64_t _fabPlanId) { FAddToCart(this, _fabPlanId); }
	void AddCurrentItemToCart() { FAddCurrentItemToCart(this); }
	void RefundCurrentItem() { FRefundCurrentItem(this); }
	virtual void UpdateInputPrompt(bool _bUpdateUI) const;
	void ConfirmReset() { FConfirmReset(this); }
	void OnConfirmReset() { FOnConfirmReset(this); }
	virtual const char* GetClearFn() const;
	virtual const char* GetAddItemFn() const;
	virtual const char* GetUpdateFn() const;
	void ItemAddedToCartInventory(unsigned _itemId) { FItemAddedToCartInventory(this, _itemId); }
	void ItemRemovedFromCartInventory(unsigned _itemId, bool _bLastOfType) { FItemRemovedFromCartInventory(this, _itemId, _bLastOfType); }
	bool IsUnderLimit(const ArkInventoryStore::ItemForSale& _item) const { return FIsUnderLimit(this, _item); }
	bool CanPurchase(const ArkInventoryStore::ItemForSale& _item) const { return FCanPurchase(this, _item); }
	void MoveHighlight(CArkInventoryUI::EArkMoveDir _moveDir) { FMoveHighlight(this, _moveDir); }

#if 0
	static EArkReadyRoomPage GetID();
	void Init();
	bool IsCartEmpty();
	void ResetSaleItems();
	float GetCost(uint64_t _arg0_) const;
	const ArkInventoryStore::ItemForSale* GetSaleItem(uint64_t _arg0_) const;
	ArkInventoryStore::ItemForSale* GetSaleItem(uint64_t _arg0_);
	const ArkInventoryStore::ItemForSale* GetSaleItem(uint64_t _arg0_, IArkItem::EArkQualityTier _arg1_) const;
	bool CanAfford(const ArkInventoryStore::ItemForSale& _arg0_) const;
	bool CanFit(const ArkInventoryStore::ItemForSale& _arg0_) const;
	bool CanRefundCurrentItem() const;
#endif

	static inline auto FArkInventoryStoreOv1 = PreyFunction<void(ArkInventoryStore* const _this, ArkReadyRoomManager& _readyRoomManager)>(0x146D620);
	static inline auto FSetupInputPrompts = PreyFunction<unsigned(IArkReadyRoomUI* const _this, unsigned _startingIndex)>(0x1471240);
	static inline auto FIsAvailable = PreyFunction<bool(const IArkReadyRoomUI* const _this)>(0x146EEF0);
	static inline auto FOpen = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x146FB80);
	static inline auto FProcessInput = PreyFunction<bool(IArkReadyRoomUI* const _this, CCryName _action, int _activationMode, float _value)>(0x14707D0);
	static inline auto FCanAdvance = PreyFunction<EArkCanAdvanceResult(const IArkReadyRoomUI* const _this)>(0x146EB40);
	static inline auto FClose = PreyFunction<void(IArkReadyRoomUI* const _this, bool _bImmediate, bool _bExitReadyRoom)>(0x146EC80);
	static inline auto FCleanup = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x146EC70);
	static inline auto FReset = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x1470C60);
	static inline auto FOnLaunch = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x146F6D0);
	static inline auto FGetLabel = PreyFunction<const char* (const IArkReadyRoomUI* const _this)>(0x146EE70);
	static inline auto FGetTotalCost = PreyFunction<float(const ArkInventoryStore* const _this)>(0x146EEC0);
	static inline auto FGetNumPurchases = PreyFunction<int(const ArkInventoryStore* const _this)>(0x316A60);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x146F6C0);
	static inline auto FResetCart = PreyFunction<void(ArkInventoryStore* const _this)>(0x1470CE0);
	static inline auto FOnCartItemSelected = PreyFunction<void(ArkInventoryStore* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x146F470);
	static inline auto FOnListItemSelected = PreyFunction<void(ArkInventoryStore* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x146F860);
	static inline auto FOnSaleItemDoubleClick = PreyFunction<void(ArkInventoryStore* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x146FA10);
	static inline auto FOnSetFocus = PreyFunction<void(ArkInventoryStore* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x146FB00);
	static inline auto FPopulateSaleItems = PreyFunction<void(ArkInventoryStore* const _this)>(0x146FCA0);
	static inline auto FAddToCart = PreyFunction<void(ArkInventoryStore* const _this, uint64_t _fabPlanId)>(0x146E6B0);
	static inline auto FAddCurrentItemToCart = PreyFunction<void(ArkInventoryStore* const _this)>(0x146E540);
	static inline auto FRefundCurrentItem = PreyFunction<void(ArkInventoryStore* const _this)>(0x14709E0);
	static inline auto FUpdateInputPrompt = PreyFunction<void(const IArkInventoryUIOwner* const _this, bool _bUpdateUI)>(0x1471670);
	static inline auto FConfirmReset = PreyFunction<void(ArkInventoryStore* const _this)>(0x146ECE0);
	static inline auto FOnConfirmReset = PreyFunction<void(ArkInventoryStore* const _this)>(0x146F680);
	static inline auto FGetClearFn = PreyFunction<const char* (const IArkInventoryUIOwner* const _this)>(0x146EE20);
	static inline auto FGetAddItemFn = PreyFunction<const char* (const IArkInventoryUIOwner* const _this)>(0x146EE00);
	static inline auto FGetUpdateFn = PreyFunction<const char* (const IArkInventoryUIOwner* const _this)>(0x146EED0);
	static inline auto FItemAddedToCartInventory = PreyFunction<void(ArkInventoryStore* const _this, unsigned _itemId)>(0x146F030);
	static inline auto FItemRemovedFromCartInventory = PreyFunction<void(ArkInventoryStore* const _this, unsigned _itemId, bool _bLastOfType)>(0x146F130);
	static inline auto FIsUnderLimit = PreyFunction<bool(const ArkInventoryStore* const _this, const ArkInventoryStore::ItemForSale& _item)>(0x146EF20);
	static inline auto FCanPurchase = PreyFunction<bool(const ArkInventoryStore* const _this, const ArkInventoryStore::ItemForSale& _item)>(0x146EBF0);
	static inline auto FMoveHighlight = PreyFunction<void(ArkInventoryStore* const _this, CArkInventoryUI::EArkMoveDir _moveDir)>(0x146F230);
};
#endif // MOONCRASH
