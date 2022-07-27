// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class ArkInventory;
class ArkItemSystem;
class CArkItem;
class IArkInventory;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/arkinventoryui.h
class IArkInventoryUIOwner // Id=8016FF7 Size=8
{
public:
	virtual void UpdateInputPrompt(bool arg0) const = 0;
	virtual void OnDoubleClick(unsigned arg0);
	virtual void OnPickItem(unsigned _itemId);
	virtual void OnDragItem(unsigned arg0);
	virtual void OnPlaceItem(unsigned _itemId);
	virtual void OnTransferItem(CArkItem &_item, IArkInventory *_pSourceInventory, IArkInventory *_pTargetInventory);
	virtual void OnSwapItem(unsigned _placedItem, unsigned _swapToItem);
	virtual void OnSetHighlight(unsigned arg0);
	virtual void OnRightClick(unsigned _itemId);
	virtual bool CanLootItem(unsigned _itemId);
	virtual bool CanDragItem(unsigned arg0);
	virtual bool IsInDefaultMode() const;
	virtual bool CanCombine(unsigned arg0, unsigned arg1) const;
	virtual bool Combine(unsigned arg0, unsigned arg1);
	virtual void PlayErrorSound();
	virtual const char *GetHighlightFn() const;
	virtual const char *GetDetailsFn() const;
	virtual const char *GetStartMoveFn() const;
	virtual const char *GetMoveFn() const;
	virtual const char *GetMoveReleaseFn() const;
	virtual const char *GetClearFn() const;
	virtual const char *GetUpdateFn() const;
	virtual const char *GetAddItemFn() const;
	virtual const char *GetPickResultFn() const;
	virtual const char *GetDragReleaseFn() const;
	
	static inline auto FOnPickItem = PreyFunction<void(IArkInventoryUIOwner *const _this, unsigned _itemId)>(0xA13080);
	static inline auto FOnPlaceItem = PreyFunction<void(IArkInventoryUIOwner *const _this, unsigned _itemId)>(0xA13080);
	static inline auto FOnTransferItem = PreyFunction<void(IArkInventoryUIOwner *const _this, CArkItem &_item, IArkInventory *_pSourceInventory, IArkInventory *_pTargetInventory)>(0xA13080);
	static inline auto FOnSwapItem = PreyFunction<void(IArkInventoryUIOwner *const _this, unsigned _placedItem, unsigned _swapToItem)>(0xA13080);
	static inline auto FOnRightClick = PreyFunction<void(IArkInventoryUIOwner *const _this, unsigned _itemId)>(0xA13080);
	static inline auto FCanLootItem = PreyFunction<bool(IArkInventoryUIOwner *const _this, unsigned _itemId)>(0x15EE660);
	static inline auto FPlayErrorSound = PreyFunction<void(IArkInventoryUIOwner *const _this)>(0xA13080);
	static inline auto FGetHighlightFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEE00);
	static inline auto FGetDetailsFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEDE0);
	static inline auto FGetStartMoveFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEE40);
	static inline auto FGetMoveFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEE10);
	static inline auto FGetMoveReleaseFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEE20);
	static inline auto FGetClearFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEDD0);
	static inline auto FGetUpdateFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEE50);
	static inline auto FGetAddItemFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEDC0);
	static inline auto FGetPickResultFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEE30);
	static inline auto FGetDragReleaseFn = PreyFunction<const char *(IArkInventoryUIOwner const *const _this)>(0x15EEDF0);
};

// Header: FromCpp
// Prey/GameDll/ark/ui/arkinventoryui.h
class CArkInventoryUI : public ArkUIMenuBase<CArkInventoryUI> // Id=8016FFB Size=88
{
public:
	enum class EArkMoveDir
	{
		right = 0,
		left = 1,
		up = 2,
		down = 3,
	};

	struct SelectedWeaponInfo_ModInfo // Id=801701C Size=48
	{
		int m_currentLevel;
		int m_maxLevel;
		int m_prereqMetLevels;
		string m_name;
		string m_description;
		uint64_t m_modId;
		uint64_t m_prereq;
	};

	struct SelectedWeaponInfo // Id=801701D Size=40
	{
		bool m_bIsWeapon;
		bool m_bShowDurability;
		float m_durability;
		string m_updateInfo;
		std::vector<CArkInventoryUI::SelectedWeaponInfo_ModInfo> m_weaponMods;
	};

	struct SelectedItemInfo // Id=801701E Size=88
	{
		int m_id;
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		int m_dismantleCount;
		bool m_bConflicts;
		bool m_bCanQuickSelect;
		bool m_bIsTrash;
		bool m_bCanBeLooted;
		wstring m_name;
		wstring m_description;
		CArkInventoryUI::SelectedWeaponInfo m_weaponInfo;
	};

	Vec2i m_dragOffset;
	int m_x;
	int m_y;
	unsigned m_currentId;
	unsigned m_itemDetailId;
	unsigned m_stackId;
	bool m_bIsMoving;
	bool m_bDragging;
	bool m_bIsProcessingMouseInput;
	bool m_bQueueInventoryRefresh;
	const char *m_uiElementName;
	IArkInventory *m_pInventory;
	IArkInventory *m_pExternal;
	IArkInventoryUIOwner &m_owner;
	
	CArkInventoryUI(IArkInventoryUIOwner &_owner, const char *_uiElementName);
	virtual ~CArkInventoryUI();
	bool MoveHighlight(CArkInventoryUI::EArkMoveDir _moveDir) { return FMoveHighlight(this,_moveDir); }
	void SetHighlightToItem(unsigned _id) { FSetHighlightToItem(this,_id); }
	unsigned ResetPosition(bool _bExternal) { return FResetPosition(this,_bExternal); }
	void UpdateHighlight(CArkInventoryUI::SelectedItemInfo const &itemInfo) { FUpdateHighlight(this,itemInfo); }
	void SetInventory(IArkInventory &_inventory) { FSetInventory(this,_inventory); }
	void Open(IArkInventory *_pExternal) { FOpen(this,_pExternal); }
	void Close() { FClose(this); }
	void ForceClose() { FForceClose(this); }
	void Update(float _frametime) { FUpdate(this,_frametime); }
	unsigned PickItem(unsigned _itemId) { return FPickItemOv1(this,_itemId); }
	unsigned PickItem() { return FPickItemOv0(this); }
	std::pair<unsigned int,bool> PlaceItem() { return FPlaceItem(this); }
	bool CancelPickItem() { return FCancelPickItem(this); }
	bool SplitStack() { return FSplitStack(this); }
	void CancelSplit() { FCancelSplit(this); }
	bool CombineStacks() { return FCombineStacks(this); }
	bool UpdateStackCounts(bool _bToStack) { return FUpdateStackCounts(this,_bToStack); }
	void UpdateStackInputPrompts() const { FUpdateStackInputPrompts(this); }
	bool GiveItem(unsigned _id, bool _bToExternal) { return FGiveItem(this,_id,_bToExternal); }
	CArkInventoryUI::SelectedItemInfo GetSelectedItemInfo(unsigned _id) const { return FGetSelectedItemInfo(this,_id); }
	unsigned SelectEntityAtCurrentLocation() { return FSelectEntityAtCurrentLocation(this); }
	unsigned GetOverlappedItem() const { return FGetOverlappedItem(this); }
	std::vector<unsigned int> GetAllItems(bool _bExternal) const { return FGetAllItems(this,_bExternal); }
	void RefreshUI() { FRefreshUI(this); }
	void UIUpdateGrid() { FUIUpdateGrid(this); }
	void UISetCombinable(std::vector<unsigned int> const &_dimmedIds, std::vector<unsigned int> const &_flashIds) const { FUISetCombinable(this,_dimmedIds,_flashIds); }
	void UIItemDetails(CArkInventoryUI::SelectedItemInfo const &_paneInfo, bool _bForce) { FUIItemDetails(this,_paneInfo,_bForce); }
	void UIUpdateOne(CArkItem const &_item) const { FUIUpdateOne(this,_item); }
	void ReleaseEmpty(unsigned _itemId) { FReleaseEmpty(this,_itemId); }
	void Sort(ArkInventory &_inventory) { FSort(this,_inventory); }
	IArkInventory *GetCurrentInventory() const { return FGetCurrentInventory(this); }
	void AddItem(CArkItem const *const _pItem, std::pair<int,int> const &_location, bool _bEquipped) const { FAddItem(this,_pItem,_location,_bEquipped); }
	void FillInItems(IArkInventory const &_inventory, int _offset) const { FFillInItems(this,_inventory,_offset); }
	unsigned GetItemAtLocation(int _x, int _y, unsigned _ignoreId) const { return FGetItemAtLocation(this,_x,_y,_ignoreId); }
	std::pair<int,int> GetLocationOfItem(unsigned _id) const { return FGetLocationOfItem(this,_id); }
	bool CanPlaceItem(unsigned _id, int _x, int _y, bool _bCanDisplace) const { return FCanPlaceItem(this,_id,_x,_y,_bCanDisplace); }
	void UIItemNav(CArkInventoryUI::SelectedItemInfo const &_navInfo) const { FUIItemNav(this,_navInfo); }
	void UIReleaseMove(CArkInventoryUI::SelectedItemInfo const &_itemInfo) const { FUIReleaseMove(this,_itemInfo); }
	void UIMovingHelper(CArkInventoryUI::SelectedItemInfo const &_itemInfo, const char *functionName) const { FUIMovingHelper(this,_itemInfo,functionName); }
	void OnSetHighlight(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSetHighlight(this,_pSender,_event,_args); }
	void OnPickItem(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnPickItem(this,_pSender,_event,_args); }
	void OnPlaceItem(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnPlaceItem(this,_pSender,_event,_args); }
	void OnDragItem(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnDragItem(this,_pSender,_event,_args); }
	void OnDoubleClickItem(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnDoubleClickItem(this,_pSender,_event,_args); }
	void OnSetContainerFocus(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSetContainerFocus(this,_pSender,_event,_args); }
	void OnRightClick(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnRightClick(this,_pSender,_event,_args); }
	void OnInventoryOpen(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnInventoryOpen(this,_pSender,_event,_args); }
	void DoUpdateGrid(IUIElement *_pUIElement) { FDoUpdateGrid(this,_pUIElement); }
	
#if 0
	IArkInventory *GetInventory() const;
	IArkInventory *GetExternal() const;
	void Drop();
	bool IsMoving() const;
	void SetLocation(int arg0, int arg1);
	void SetLocationToFirstItem(bool arg0, bool arg1);
	unsigned GetEntityAtCurrentLocation(unsigned arg0);
	int GetMaxWidth() const;
	int GetMaxHeight() const;
	std::pair<int,int> GetCurrentLocation() const;
	unsigned SelectNextEntity(unsigned arg0, bool arg1);
	unsigned GetCurrentId() const;
	unsigned GetStackId() const;
	bool IsInExternal() const;
	bool IsDragging() const;
	void SetProcessingMouse(const bool arg0);
	static ArkItemSystem &GetArkItemSystem();
	IUIElement *GetUIElement() const;
	void UIStartMove(CArkInventoryUI::SelectedItemInfo const &arg0) const;
	void UIMoveItem(CArkInventoryUI::SelectedItemInfo const &arg0) const;
	void ReleaseMouseDrag(IUIElement *arg0);
#endif
	
	static inline auto FMoveHighlight = PreyFunction<bool(CArkInventoryUI *const _this, CArkInventoryUI::EArkMoveDir _moveDir)>(0x15FF110);
	static inline auto FSetHighlightToItem = PreyFunction<void(CArkInventoryUI *const _this, unsigned _id)>(0x1601080);
	static inline auto FResetPosition = PreyFunction<unsigned(CArkInventoryUI *const _this, bool _bExternal)>(0x1600B30);
	static inline auto FUpdateHighlight = PreyFunction<void(CArkInventoryUI *const _this, CArkInventoryUI::SelectedItemInfo const &itemInfo)>(0x1602AE0);
	static inline auto FSetInventory = PreyFunction<void(CArkInventoryUI *const _this, IArkInventory &_inventory)>(0x16011D0);
	static inline auto FOpen = PreyFunction<void(CArkInventoryUI *const _this, IArkInventory *_pExternal)>(0x16002D0);
	static inline auto FClose = PreyFunction<void(CArkInventoryUI *const _this)>(0x15FE570);
	static inline auto FForceClose = PreyFunction<void(CArkInventoryUI *const _this)>(0x15FE8F0);
	static inline auto FUpdate = PreyFunction<void(CArkInventoryUI *const _this, float _frametime)>(0x1602A70);
	static inline auto FPickItemOv1 = PreyFunction<unsigned(CArkInventoryUI *const _this, unsigned _itemId)>(0x1600320);
	static inline auto FPickItemOv0 = PreyFunction<unsigned(CArkInventoryUI *const _this)>(0x16004D0);
	static inline auto FPlaceItem = PreyFunction<std::pair<unsigned int,bool>(CArkInventoryUI *const _this)>(0x1600500);
	static inline auto FCancelPickItem = PreyFunction<bool(CArkInventoryUI *const _this)>(0x15FE250);
	static inline auto FSplitStack = PreyFunction<bool(CArkInventoryUI *const _this)>(0x1601370);
	static inline auto FCancelSplit = PreyFunction<void(CArkInventoryUI *const _this)>(0x15FE4C0);
	static inline auto FCombineStacks = PreyFunction<bool(CArkInventoryUI *const _this)>(0x15FE5C0);
	static inline auto FUpdateStackCounts = PreyFunction<bool(CArkInventoryUI *const _this, bool _bToStack)>(0x1602C60);
	static inline auto FUpdateStackInputPrompts = PreyFunction<void(CArkInventoryUI const *const _this)>(0x1602D40);
	static inline auto FGiveItem = PreyFunction<bool(CArkInventoryUI *const _this, unsigned _id, bool _bToExternal)>(0x15FF010);
	static inline auto FGetSelectedItemInfo = PreyFunction<CArkInventoryUI::SelectedItemInfo(CArkInventoryUI const *const _this, unsigned _id)>(0x15FEDC0);
	static inline auto FSelectEntityAtCurrentLocation = PreyFunction<unsigned(CArkInventoryUI *const _this)>(0x1600FE0);
	static inline auto FGetOverlappedItem = PreyFunction<unsigned(CArkInventoryUI const *const _this)>(0x15FEB40);
	static inline auto FGetAllItems = PreyFunction<std::vector<unsigned int>(CArkInventoryUI const *const _this, bool _bExternal)>(0x15FE950);
	static inline auto FRefreshUI = PreyFunction<void(CArkInventoryUI *const _this)>(0x1600930);
	static inline auto FUIUpdateGrid = PreyFunction<void(CArkInventoryUI *const _this)>(0x16026B0);
	static inline auto FUISetCombinable = PreyFunction<void(CArkInventoryUI const *const _this, std::vector<unsigned int> const &_dimmedIds, std::vector<unsigned int> const &_flashIds)>(0x16021C0);
	static inline auto FUIItemDetails = PreyFunction<void(CArkInventoryUI *const _this, CArkInventoryUI::SelectedItemInfo const &_paneInfo, bool _bForce)>(0x16014C0);
	static inline auto FUIUpdateOne = PreyFunction<void(CArkInventoryUI const *const _this, CArkItem const &_item)>(0x1602770);
	static inline auto FReleaseEmpty = PreyFunction<void(CArkInventoryUI *const _this, unsigned _itemId)>(0x16009E0);
	static inline auto FSort = PreyFunction<void(CArkInventoryUI *const _this, ArkInventory &_inventory)>(0x16011E0);
	static inline auto FGetCurrentInventory = PreyFunction<IArkInventory *(CArkInventoryUI const *const _this)>(0x15FEA00);
	static inline auto FAddItem = PreyFunction<void(CArkInventoryUI const *const _this, CArkItem const *const _pItem, std::pair<int,int> const &_location, bool _bEquipped)>(0x15FDE50);
	static inline auto FFillInItems = PreyFunction<void(CArkInventoryUI const *const _this, IArkInventory const &_inventory, int _offset)>(0x15FE700);
	static inline auto FGetItemAtLocation = PreyFunction<unsigned(CArkInventoryUI const *const _this, int _x, int _y, unsigned _ignoreId)>(0x15FEA30);
	static inline auto FGetLocationOfItem = PreyFunction<std::pair<int,int>(CArkInventoryUI const *const _this, unsigned _id)>(0x15FEAB0);
	static inline auto FCanPlaceItem = PreyFunction<bool(CArkInventoryUI const *const _this, unsigned _id, int _x, int _y, bool _bCanDisplace)>(0x15FE150);
	static inline auto FUIItemNav = PreyFunction<void(CArkInventoryUI const *const _this, CArkInventoryUI::SelectedItemInfo const &_navInfo)>(0x1601DD0);
	static inline auto FUIReleaseMove = PreyFunction<void(CArkInventoryUI const *const _this, CArkInventoryUI::SelectedItemInfo const &_itemInfo)>(0x1602100);
	static inline auto FUIMovingHelper = PreyFunction<void(CArkInventoryUI const *const _this, CArkInventoryUI::SelectedItemInfo const &_itemInfo, const char *functionName)>(0x1601F90);
	static inline auto FOnSetHighlight = PreyFunction<void(CArkInventoryUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1600010);
	static inline auto FOnPickItem = PreyFunction<void(CArkInventoryUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15FF9F0);
	static inline auto FOnPlaceItem = PreyFunction<void(CArkInventoryUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15FFD40);
	static inline auto FOnDragItem = PreyFunction<void(CArkInventoryUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15FF580);
	static inline auto FOnDoubleClickItem = PreyFunction<void(CArkInventoryUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15FF4D0);
	static inline auto FOnSetContainerFocus = PreyFunction<void(CArkInventoryUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15FFF70);
	static inline auto FOnRightClick = PreyFunction<void(CArkInventoryUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15FFEF0);
	static inline auto FOnInventoryOpen = PreyFunction<void(CArkInventoryUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15FF9E0);
	static inline auto FDoUpdateGrid = PreyFunction<void(CArkInventoryUI *const _this, IUIElement *_pUIElement)>(0x15FE6C0);
};

