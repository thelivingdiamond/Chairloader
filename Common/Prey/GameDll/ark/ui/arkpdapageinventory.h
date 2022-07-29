// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkinventoryui.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class CArkItem;
class CCryName;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/arkpdapageinventory.h
class CArkPDAPageInventory : public ArkUIMenuBase<CArkPDAPageInventory>, public IArkPDAPage, public IArkInventoryUIOwner, public IUIControlSchemeListener // Id=801BB23 Size=1320
{
public:
	enum class PopUpSelectOption
	{
		Invalid = 0,
		Repair = 1,
		Upgrade = 2,
		Dismantle = 3,
		QuickSelect = 4,
		Favorite = 5,
		Split = 6,
		Last = 6,
	};

	enum class EArkCombineAction
	{
		none = 0,
		repair = 1,
		upgrade = 2,
		stack = 3,
	};

	std::unique_ptr<CArkInventoryUI> m_pArkInventoryUI;
	
	enum class ViewState
	{
		Default = 0,
		PopUp = 1,
		Upgrade = 2,
		QuickSelect = 3,
		Stack = 4,
	};

	CArkPDAPageInventory::ViewState m_viewState;
	CArkPDAPageInventory::ViewState m_prevViewState;
	int m_currentMod;
	int m_currentModLevel;
	unsigned m_upgradeWeaponId;
	std::array<enum CArkPDAPageInventory::PopUpSelectOption,8> m_popUpSelections;
	int m_popUpIndex;
	int m_numPopupSelections;
	ArkSimpleTimer m_promptTimer;
	ArkButtonPromptCollection m_itemPrompts;
	bool m_bPromptsShown;
	ArkButtonPromptCollection m_upgradeInputPrompts;
	ArkAudioTrigger m_repairSFX;
	
	CArkPDAPageInventory();
	virtual ~CArkPDAPageInventory();
	virtual void UpdateInputPrompt(bool _bUpdateUI) const;
	virtual void OnDoubleClick(unsigned _itemId);
	virtual void OnPickItem(unsigned _itemId);
	virtual void OnPlaceItem(unsigned _itemId);
	virtual void OnSwapItem(unsigned _placedItem, unsigned _swapToItem);
	virtual void OnSetHighlight(unsigned _itemId);
	virtual bool CanCombine(unsigned _selectedId, unsigned _overId) const;
	virtual bool Combine(unsigned _selectedId, unsigned _overId);
	virtual bool IsInDefaultMode() const;
	virtual bool CanDragItem(unsigned _itemId);
	virtual void OnDragItem(unsigned _itemId);
	void SetInventory() { FSetInventory(this); }
	virtual bool OnControlSchemeChanged(EControlScheme controlScheme);
	virtual void Open();
	virtual void Close();
	virtual bool ProcessInput(CCryName const &_rActionId, const int _activationMode, const float _fValue);
	virtual void Update(float _frametime);
	void ResetUI() { FResetUI(this); }
	void MoveHighlight(CArkInventoryUI::EArkMoveDir _moveDir) { FMoveHighlight(this,_moveDir); }
	virtual bool ManagesInputPrompts() const;
	virtual void SetupInputPrompts();
	void EquipUseItem(unsigned _id) const { FEquipUseItem(this,_id); }
	const char *GetUseActionName(unsigned _id) const { return FGetUseActionName(this,_id); }
	void OpenUpgradeMenu(unsigned _weaponId) { FOpenUpgradeMenu(this,_weaponId); }
	void CloseUpgradeMenu() { FCloseUpgradeMenu(this); }
	void RefreshModHighlight() { FRefreshModHighlight(this); }
	void UpgradeCurrentMod() { FUpgradeCurrentMod(this); }
	uint64_t GetCurrentModId() const { return FGetCurrentModId(this); }
	void ShowUpgradeConfirmDialog() { FShowUpgradeConfirmDialog(this); }
	void ShowRepairConfirmDialog() { FShowRepairConfirmDialog(this); }
	void RepairWeapon() { FRepairWeapon(this); }
	void RepairWeaponAll() { FRepairWeaponAll(this); }
	void RepairHelper(bool _bRepairAll) { FRepairHelper(this,_bRepairAll); }
	void DismantleItem() { FDismantleItem(this); }
	void CloseQuickSelect() { FCloseQuickSelect(this); }
	void ConfirmSplit() { FConfirmSplit(this); }
	void CancelStackMode() { FCancelStackMode(this); }
	void OpenPopUpMenu(unsigned _itemId) { FOpenPopUpMenu(this,_itemId); }
	void ClosePopUpMenu() { FClosePopUpMenu(this); }
	bool ShouldOpenPopUpMenu() const { return FShouldOpenPopUpMenu(this); }
	void RefreshPopUpOption(unsigned _itemId, CArkPDAPageInventory::PopUpSelectOption _option) { FRefreshPopUpOption(this,_itemId,_option); }
	void UpdateItemPrompts() { FUpdateItemPrompts(this); }
	void CloseItemPrompts() { FCloseItemPrompts(this); }
	void UpdateDimmed(unsigned _itemId) const { FUpdateDimmed(this,_itemId); }
	void OnCombine(CArkItem const &_movingItem, CArkItem const &_overlappedItem) { FOnCombine(this,_movingItem,_overlappedItem); }
	CArkPDAPageInventory::EArkCombineAction GetCombineAction(const unsigned _selectedId) const { return FGetCombineActionOv1(this,_selectedId); }
	CArkPDAPageInventory::EArkCombineAction GetCombineAction(const unsigned _selectedId, const unsigned _overId) const { return FGetCombineActionOv0(this,_selectedId,_overId); }
	bool ShouldShowPopUpSelection(CArkPDAPageInventory::PopUpSelectOption _selection, unsigned _itemId) const { return FShouldShowPopUpSelection(this,_selection,_itemId); }
	bool CanPerformPopUpSelection(CArkPDAPageInventory::PopUpSelectOption _selection, unsigned _itemId) const { return FCanPerformPopUpSelection(this,_selection,_itemId); }
	const char *GetPopUpSelectionName(CArkPDAPageInventory::PopUpSelectOption _selection) const { return FGetPopUpSelectionName(this,_selection); }
	void ConfirmPopUpSelection(CArkPDAPageInventory::PopUpSelectOption _selection) { FConfirmPopUpSelection(this,_selection); }
	void OnPopUpSelect(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnPopUpSelect(this,_pSender,_event,_args); }
	void OnWeaponUpgrade(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnWeaponUpgrade(this,_pSender,_event,_args); }
	void OnWeaponUpgradeClose(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnWeaponUpgradeClose(this,_pSender,_event,_args); }
	void OnSetModHighlight(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSetModHighlight(this,_pSender,_event,_args); }
	virtual void OnRightClick(unsigned _itemId);
	void UpdateRepairDialog() { FUpdateRepairDialog(this); }
	void CloseRepairDialog() { FCloseRepairDialog(this); }
	
#if 0
	void PickItem(unsigned arg0);
	void ShowErrorMessage(wstring const &arg0);
	static ArkPDAPage GetPDAPage();
	void RefreshHighlight();
	void UpdateUpgradeInputPrompts();
	int GetNumUsableSpareParts() const;
	CArkItem *GetSparePart(unsigned arg0) const;
	void ShowDismantleConfirmDialog();
	void OpenQuickSelect();
	void TrySplitStack();
#endif
	
	static inline auto FUpdateInputPrompt = PreyFunction<void(CArkPDAPageInventory const *const _this, bool _bUpdateUI)>(0x1621500);
	static inline auto FOnDoubleClick = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _itemId)>(0x161E8E0);
	static inline auto FOnPickItem = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _itemId)>(0x161E970);
	static inline auto FOnPlaceItem = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _itemId)>(0x161E9D0);
	static inline auto FOnSwapItem = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _placedItem, unsigned _swapToItem)>(0x161EE30);
	static inline auto FOnSetHighlight = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _itemId)>(0x161EC50);
	static inline auto FCanCombine = PreyFunction<bool(CArkPDAPageInventory const *const _this, unsigned _selectedId, unsigned _overId)>(0x161D260);
	static inline auto FCombine = PreyFunction<bool(CArkPDAPageInventory *const _this, unsigned _selectedId, unsigned _overId)>(0x161D6E0);
	static inline auto FIsInDefaultMode = PreyFunction<bool(CArkPDAPageInventory const *const _this)>(0x161E530);
	static inline auto FCanDragItem = PreyFunction<bool(CArkPDAPageInventory *const _this, unsigned _itemId)>(0x161D280);
	static inline auto FOnDragItem = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _itemId)>(0x161E930);
	static inline auto FSetInventory = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1620B50);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(CArkPDAPageInventory *const _this, EControlScheme controlScheme)>(0x161E880);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161EE60);
	static inline auto FClose = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161D460);
	static inline auto FProcessInput = PreyFunction<bool(CArkPDAPageInventory *const _this, CCryName const &_rActionId, const int _activationMode, const float _fValue)>(0x161F9B0);
	static inline auto FUpdate = PreyFunction<void(CArkPDAPageInventory *const _this, float _frametime)>(0x16210C0);
	static inline auto FResetUI = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1620AA0);
	static inline auto FMoveHighlight = PreyFunction<void(CArkPDAPageInventory *const _this, CArkInventoryUI::EArkMoveDir _moveDir)>(0x161E540);
	static inline auto FManagesInputPrompts = PreyFunction<bool(CArkPDAPageInventory const *const _this)>(0x1B933B0);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1620BF0);
	static inline auto FEquipUseItem = PreyFunction<void(CArkPDAPageInventory const *const _this, unsigned _id)>(0x161DDE0);
	static inline auto FGetUseActionName = PreyFunction<const char *(CArkPDAPageInventory const *const _this, unsigned _id)>(0x161E220);
	static inline auto FOpenUpgradeMenu = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _weaponId)>(0x161F450);
	static inline auto FCloseUpgradeMenu = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161D660);
	static inline auto FRefreshModHighlight = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1620130);
	static inline auto FUpgradeCurrentMod = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1622060);
	static inline auto FGetCurrentModId = PreyFunction<uint64_t(CArkPDAPageInventory const *const _this)>(0x161E010);
	static inline auto FShowUpgradeConfirmDialog = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1620F90);
	static inline auto FShowRepairConfirmDialog = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1620E10);
	static inline auto FRepairWeapon = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1620A30);
	static inline auto FRepairWeaponAll = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1620A50);
	static inline auto FRepairHelper = PreyFunction<void(CArkPDAPageInventory *const _this, bool _bRepairAll)>(0x1620790);
	static inline auto FDismantleItem = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161DBB0);
	static inline auto FCloseQuickSelect = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161D5C0);
	static inline auto FConfirmSplit = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161DB80);
	static inline auto FCancelStackMode = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161D410);
	static inline auto FOpenPopUpMenu = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _itemId)>(0x161F0D0);
	static inline auto FClosePopUpMenu = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161D550);
	static inline auto FShouldOpenPopUpMenu = PreyFunction<bool(CArkPDAPageInventory const *const _this)>(0x1620C40);
	static inline auto FRefreshPopUpOption = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _itemId, CArkPDAPageInventory::PopUpSelectOption _option)>(0x16206C0);
	static inline auto FUpdateItemPrompts = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1621950);
	static inline auto FCloseItemPrompts = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161D4F0);
	static inline auto FUpdateDimmed = PreyFunction<void(CArkPDAPageInventory const *const _this, unsigned _itemId)>(0x1621170);
	static inline auto FOnCombine = PreyFunction<void(CArkPDAPageInventory *const _this, CArkItem const &_movingItem, CArkItem const &_overlappedItem)>(0x161E5D0);
	static inline auto FGetCombineActionOv1 = PreyFunction<CArkPDAPageInventory::EArkCombineAction(CArkPDAPageInventory const *const _this, const unsigned _selectedId)>(0x161DEC0);
	static inline auto FGetCombineActionOv0 = PreyFunction<CArkPDAPageInventory::EArkCombineAction(CArkPDAPageInventory const *const _this, const unsigned _selectedId, const unsigned _overId)>(0x161DF40);
	static inline auto FShouldShowPopUpSelection = PreyFunction<bool(CArkPDAPageInventory const *const _this, CArkPDAPageInventory::PopUpSelectOption _selection, unsigned _itemId)>(0x1620CC0);
	static inline auto FCanPerformPopUpSelection = PreyFunction<bool(CArkPDAPageInventory const *const _this, CArkPDAPageInventory::PopUpSelectOption _selection, unsigned _itemId)>(0x161D2A0);
	static inline auto FGetPopUpSelectionName = PreyFunction<const char *(CArkPDAPageInventory const *const _this, CArkPDAPageInventory::PopUpSelectOption _selection)>(0x161E0B0);
	static inline auto FConfirmPopUpSelection = PreyFunction<void(CArkPDAPageInventory *const _this, CArkPDAPageInventory::PopUpSelectOption _selection)>(0x161D880);
	static inline auto FOnPopUpSelect = PreyFunction<void(CArkPDAPageInventory *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x161E9F0);
	static inline auto FOnWeaponUpgrade = PreyFunction<void(CArkPDAPageInventory *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x161EE40);
	static inline auto FOnWeaponUpgradeClose = PreyFunction<void(CArkPDAPageInventory *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x161EE50);
	static inline auto FOnSetModHighlight = PreyFunction<void(CArkPDAPageInventory *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x161ED10);
	static inline auto FOnRightClick = PreyFunction<void(CArkPDAPageInventory *const _this, unsigned _itemId)>(0x161EB20);
	static inline auto FUpdateRepairDialog = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x1621E60);
	static inline auto FCloseRepairDialog = PreyFunction<void(CArkPDAPageInventory *const _this)>(0x161D620);
};

