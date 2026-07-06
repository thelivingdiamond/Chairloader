// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/ArkInventoryUI.h>
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

enum class ArkPDAPage;
class CArkInventoryUI;
class CArkItem;
class CCryName;
enum EControlScheme;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// CArkPDAPageInventory
// Header:  Prey/GameDll/ark/ui/ArkPDAPageInventory.h
class CArkPDAPageInventory
	: public ArkUIMenuBase<CArkPDAPageInventory>
	, public IArkPDAPage
	, public IArkInventoryUIOwner
	, public IUIControlSchemeListener
{ // Size=1000 (0x3E8)
public:
	enum class PopUpSelectOption
	{
		Invalid = 0,
		Repair = 1,
		ReverseEngineer = 2,
		Dismantle = 3,
		QuickSelect = 4,
		Favorite = 5,
		Split = 6,
		SwapSkin = 7,
		Last = 7,
	};

	enum class EArkCombineAction
	{
		none = 0,
		repair = 1,
		stack = 2,
	};

	enum class ViewState
	{
		Default = 0,
		PopUp = 1,
		QuickSelect = 2,
		Stack = 3,
		WeaponSkin = 4,
		Store = 5,
	};

	std::unique_ptr<CArkInventoryUI> m_pArkInventoryUI;
	CArkPDAPageInventory::ViewState m_viewState;
	CArkPDAPageInventory::ViewState m_prevViewState;
	std::array<enum::CArkPDAPageInventory::PopUpSelectOption, 8> m_popUpSelections;
	int m_popUpIndex;
	int m_numPopupSelections;
	std::vector<uint64_t> m_weaponSkins;
	int m_skinIndex;
	ArkSimpleTimer m_promptTimer;
	ArkButtonPromptCollection m_itemPrompts;
	bool m_bPromptsShown;
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
	virtual bool OnControlSchemeChanged(const EControlScheme controlScheme);
	void OnPressBack() { FOnPressBack(this); }
	void OnPressConfirm() { FOnPressConfirm(this); }
	void OnPressAutosort() { FOnPressAutosort(this); }
	void OnPressUse() { FOnPressUse(this); }
	void OnPressExamine() { FOnPressExamine(this); }
	void OnPressDrop() { FOnPressDrop(this); }
	virtual void Open();
	virtual void Close();
	virtual bool ProcessInput(const CCryName& _rActionId, const int _activationMode, const float _fValue);
	virtual void Update(float _frametime);
	void ResetUI() { FResetUI(this); }
	void MoveHighlight(const CArkInventoryUI::EArkMoveDir _moveDir) { FMoveHighlight(this, _moveDir); }
	virtual bool ManagesInputPrompts() const;
	virtual void SetupInputPrompts();
	void EquipUseItem(unsigned _id) const { FEquipUseItem(this, _id); }
	const char* GetUseActionName(unsigned _id) const { return FGetUseActionName(this, _id); }
	void ShowRepairConfirmDialog() { FShowRepairConfirmDialog(this); }
	void RepairWeapon() { FRepairWeapon(this); }
	void RepairWeaponAll() { FRepairWeaponAll(this); }
	void RepairCondenserCell() { FRepairCondenserCell(this); }
	void WeaponRepairHelper(bool _bRepairAll) { FWeaponRepairHelper(this, _bRepairAll); }
	const CArkItem* GetCurrentRepairableObject() const { return FGetCurrentRepairableObject(this); }
	void ReverseEngineerItem() { FReverseEngineerItem(this); }
	void DismantleItem() { FDismantleItem(this); }
	void CloseQuickSelect() { FCloseQuickSelect(this); }
	void ConfirmSplit() { FConfirmSplit(this); }
	void CancelStackMode() { FCancelStackMode(this); }
	void OpenPopUpMenu(unsigned _itemId) { FOpenPopUpMenu(this, _itemId); }
	void ClosePopUpMenu() { FClosePopUpMenu(this); }
	bool ShouldOpenPopUpMenu() const { return FShouldOpenPopUpMenu(this); }
	void RefreshPopUpOption(unsigned _itemId, CArkPDAPageInventory::PopUpSelectOption _option) { FRefreshPopUpOption(this, _itemId, _option); }
	void UpdateItemPrompts() { FUpdateItemPrompts(this); }
	void CloseItemPrompts() { FCloseItemPrompts(this); }
	void UpdateDimmed(unsigned _itemId) const { FUpdateDimmed(this, _itemId); }
	void OnCombine(const CArkItem& _movingItem, const CArkItem& _overlappedItem) { FOnCombine(this, _movingItem, _overlappedItem); }
	CArkPDAPageInventory::EArkCombineAction GetCombineAction(const unsigned _selectedId) const { return FGetCombineActionOv1(this, _selectedId); }
	CArkPDAPageInventory::EArkCombineAction GetCombineAction(const unsigned _selectedId, const unsigned _overId) const { return FGetCombineActionOv0(this, _selectedId, _overId); }
	bool ShouldShowPopUpSelection(CArkPDAPageInventory::PopUpSelectOption _selection, unsigned _itemId) const { return FShouldShowPopUpSelection(this, _selection, _itemId); }
	bool CanPerformPopUpSelection(CArkPDAPageInventory::PopUpSelectOption _selection, unsigned _itemId) const { return FCanPerformPopUpSelection(this, _selection, _itemId); }
	const char* GetPopUpSelectionName(CArkPDAPageInventory::PopUpSelectOption _selection) const { return FGetPopUpSelectionName(this, _selection); }
	void ConfirmPopUpSelection(CArkPDAPageInventory::PopUpSelectOption _selection) { FConfirmPopUpSelection(this, _selection); }
	void OnPromptSelectInventory(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPromptSelectInventory(this, _pSender, _event, _args); }
	void OnPopUpSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPopUpSelect(this, _pSender, _event, _args); }
	virtual void OnRightClick(unsigned _itemId);
	void UpdateRepairDialog() { FUpdateRepairDialog(this); }
	void CloseRepairDialog() { FCloseRepairDialog(this); }
	void OpenWeaponSkinMenu() { FOpenWeaponSkinMenu(this); }
	void UpdateWeaponSkinHighlight(int _index) { FUpdateWeaponSkinHighlight(this, _index); }
	void OnWeaponSkinMenuClose(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnWeaponSkinMenuClose(this, _pSender, _event, _args); }
	void OnWeaponSkinMenuSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnWeaponSkinMenuSelect(this, _pSender, _event, _args); }
	void OnWeaponSkinMenuDoubleClick(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnWeaponSkinMenuDoubleClick(this, _pSender, _event, _args); }
	void ApplyWeaponSkin(int _skinIndex) { FApplyWeaponSkin(this, _skinIndex); }
	void ApplyWeaponSkinToArchetype() { FApplyWeaponSkinToArchetype(this); }

#if 0
	void PickItem(unsigned _arg0_);
	void ShowErrorMessage(const wstring& _arg0_);
	static ArkPDAPage GetPDAPage();
	uint64_t GetCurrentRequiredRepairAbility() const;
	int GetNumUsableSparePartsForWeapon() const;
	CArkItem* GetSparePart(unsigned _arg0_) const;
	void ShowReverseEngineerConfirmDialog();
	void ShowDismantleConfirmDialog();
	void OpenQuickSelect();
	void TrySplitStack();
	void CloseWeaponSkinMenu(bool _arg0_);
#endif

	static inline auto FCArkPDAPageInventory = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173D590);
	static inline auto FUpdateInputPrompt = PreyFunction<void(const IArkInventoryUIOwner* const _this, bool _bUpdateUI)>(0x1742520);
	static inline auto FOnDoubleClick = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x173F680);
	static inline auto FOnPickItem = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x173F8F0);
	static inline auto FOnPlaceItem = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x173F960);
	static inline auto FOnSwapItem = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _placedItem, unsigned _swapToItem)>(0x1740200);
	static inline auto FOnSetHighlight = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x1740140);
	static inline auto FCanCombine = PreyFunction<bool(const IArkInventoryUIOwner* const _this, unsigned _selectedId, unsigned _overId)>(0x173DFF0);
	static inline auto FCombine = PreyFunction<bool(IArkInventoryUIOwner* const _this, unsigned _selectedId, unsigned _overId)>(0x173E450);
	static inline auto FIsInDefaultMode = PreyFunction<bool(const IArkInventoryUIOwner* const _this)>(0x173F300);
	static inline auto FCanDragItem = PreyFunction<bool(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x173E010);
	static inline auto FOnDragItem = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x173F6D0);
	static inline auto FSetInventory = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x1741C30);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme controlScheme)>(0x173F620);
	static inline auto FOnPressBack = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173FB00);
	static inline auto FOnPressConfirm = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173FC60);
	static inline auto FOnPressAutosort = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173FAB0);
	static inline auto FOnPressUse = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173FE60);
	static inline auto FOnPressExamine = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173FE20);
	static inline auto FOnPressDrop = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173FDA0);
	static inline auto FOpen = PreyFunction<void(IArkPDAPage* const _this)>(0x1740430);
	static inline auto FClose = PreyFunction<void(IArkPDAPage* const _this)>(0x173E260);
	static inline auto FProcessInput = PreyFunction<bool(IArkPDAPage* const _this, const CCryName& _rActionId, const int _activationMode, const float _fValue)>(0x17410D0);
	static inline auto FUpdate = PreyFunction<void(IArkPDAPage* const _this, float _frametime)>(0x1742150);
	static inline auto FResetUI = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x17419F0);
	static inline auto FMoveHighlight = PreyFunction<void(CArkPDAPageInventory* const _this, const CArkInventoryUI::EArkMoveDir _moveDir)>(0x173F310);
	static inline auto FManagesInputPrompts = PreyFunction<bool(const IArkPDAPage* const _this)>(0x1A302A0);
	static inline auto FSetupInputPrompts = PreyFunction<void(IArkPDAPage* const _this)>(0x18F7090);
	static inline auto FEquipUseItem = PreyFunction<void(const CArkPDAPageInventory* const _this, unsigned _id)>(0x173EC70);
	static inline auto FGetUseActionName = PreyFunction<const char* (const CArkPDAPageInventory* const _this, unsigned _id)>(0x173F0F0);
	static inline auto FShowRepairConfirmDialog = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x1741F50);
	static inline auto FRepairWeapon = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x1741980);
	static inline auto FRepairWeaponAll = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x17419A0);
	static inline auto FRepairCondenserCell = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x1741770);
	static inline auto FWeaponRepairHelper = PreyFunction<void(CArkPDAPageInventory* const _this, bool _bRepairAll)>(0x1743BB0);
	static inline auto FGetCurrentRepairableObject = PreyFunction<const CArkItem* (const CArkPDAPageInventory* const _this)>(0x173EE70);
	static inline auto FReverseEngineerItem = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x1741A90);
	static inline auto FDismantleItem = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173EA30);
	static inline auto FCloseQuickSelect = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173E3B0);
	static inline auto FConfirmSplit = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173EA00);
	static inline auto FCancelStackMode = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173E210);
	static inline auto FOpenPopUpMenu = PreyFunction<void(CArkPDAPageInventory* const _this, unsigned _itemId)>(0x17407C0);
	static inline auto FClosePopUpMenu = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173E340);
	static inline auto FShouldOpenPopUpMenu = PreyFunction<bool(const CArkPDAPageInventory* const _this)>(0x1741CC0);
	static inline auto FRefreshPopUpOption = PreyFunction<void(CArkPDAPageInventory* const _this, unsigned _itemId, CArkPDAPageInventory::PopUpSelectOption _option)>(0x17416A0);
	static inline auto FUpdateItemPrompts = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x1742B50);
	static inline auto FCloseItemPrompts = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173E2E0);
	static inline auto FUpdateDimmed = PreyFunction<void(const CArkPDAPageInventory* const _this, unsigned _itemId)>(0x1742220);
	static inline auto FOnCombine = PreyFunction<void(CArkPDAPageInventory* const _this, const CArkItem& _movingItem, const CArkItem& _overlappedItem)>(0x173F370);
	static inline auto FGetCombineActionOv1 = PreyFunction<CArkPDAPageInventory::EArkCombineAction(const CArkPDAPageInventory* const _this, const unsigned _selectedId)>(0x173ED50);
	static inline auto FGetCombineActionOv0 = PreyFunction<CArkPDAPageInventory::EArkCombineAction(const CArkPDAPageInventory* const _this, const unsigned _selectedId, const unsigned _overId)>(0x173EDA0);
	static inline auto FShouldShowPopUpSelection = PreyFunction<bool(const CArkPDAPageInventory* const _this, CArkPDAPageInventory::PopUpSelectOption _selection, unsigned _itemId)>(0x1741D40);
	static inline auto FCanPerformPopUpSelection = PreyFunction<bool(const CArkPDAPageInventory* const _this, CArkPDAPageInventory::PopUpSelectOption _selection, unsigned _itemId)>(0x173E030);
	static inline auto FGetPopUpSelectionName = PreyFunction<const char* (const CArkPDAPageInventory* const _this, CArkPDAPageInventory::PopUpSelectOption _selection)>(0x173EF00);
	static inline auto FConfirmPopUpSelection = PreyFunction<void(CArkPDAPageInventory* const _this, CArkPDAPageInventory::PopUpSelectOption _selection)>(0x173E6E0);
	static inline auto FOnPromptSelectInventory = PreyFunction<void(CArkPDAPageInventory* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173FF80);
	static inline auto FOnPopUpSelect = PreyFunction<void(CArkPDAPageInventory* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F980);
	static inline auto FOnRightClick = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x1740000);
	static inline auto FUpdateRepairDialog = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x1743140);
	static inline auto FCloseRepairDialog = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173E410);
	static inline auto FOpenWeaponSkinMenu = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x1740B40);
	static inline auto FUpdateWeaponSkinHighlight = PreyFunction<void(CArkPDAPageInventory* const _this, int _index)>(0x1743760);
	static inline auto FOnWeaponSkinMenuClose = PreyFunction<void(CArkPDAPageInventory* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740300);
	static inline auto FOnWeaponSkinMenuSelect = PreyFunction<void(CArkPDAPageInventory* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x17403B0);
	static inline auto FOnWeaponSkinMenuDoubleClick = PreyFunction<void(CArkPDAPageInventory* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740330);
	static inline auto FApplyWeaponSkin = PreyFunction<void(CArkPDAPageInventory* const _this, int _skinIndex)>(0x173DE80);
	static inline auto FApplyWeaponSkinToArchetype = PreyFunction<void(CArkPDAPageInventory* const _this)>(0x173DF20);
};
#endif // !MOONCRASH
