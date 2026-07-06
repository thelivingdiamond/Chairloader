// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/ui/IArkPauseMenuListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkinventoryui.h>

class ArkInventory;
class CArkInventoryUI;
class CArkItem;
class CCryName;
class IArkInventory;
struct IUIElement;

// Header: Exact
// Prey/GameDll/ark/ui/arkexternalinventoryui.h
class CArkExternalInventoryUI : public IUIControlSchemeListener, public IArkInventoryUIOwner, public IArkPauseMenuListener // Id=8016FF6 Size=112
{
public:
	std::unique_ptr<CArkInventoryUI> m_pInventoryUI;
	static const char *k_UIElement;
	ArkAudioTrigger m_takeItemTrigger;
	ArkAudioTrigger m_storeItemTrigger;
	ArkAudioTrigger m_takeAllTrigger;
	ArkAudioTrigger m_inventoryFullTrigger;
	ArkAudioTrigger m_inventoryErrorTrigger;
	bool m_bIsOpen;
	
	enum class ViewState
	{
		Default = 0,
		Stack = 1,
	};

	CArkExternalInventoryUI::ViewState m_viewState;
	
	class TransferNotification // Id=8017020 Size=40
	{
	public:
		unsigned m_itemId;
		uint64_t m_archetypeId;
		string m_displayName;
		string m_icon;
		bool m_bImportant;
		int m_count;
		
#if 0
		bool operator==(const unsigned arg0) const;
#endif
	};

	std::vector<CArkExternalInventoryUI::TransferNotification> m_transferNotifications;
	std::vector<unsigned int> m_untransferredItems;
	
	CArkExternalInventoryUI();
	void Reset() { FReset(this); }
	void Open(ArkInventory &_inventory) { FOpen(this,_inventory); }
	bool CloseOrCancel() { return FCloseOrCancel(this); }
	void CloseUI() { FCloseUI(this); }
	void ProcessInput(CCryName const &_actionId, const int _activationMode, const float _value) { FProcessInput(this,_actionId,_activationMode,_value); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual void UpdateInputPrompt(bool _bUpdateUI) const;
	virtual void OnDoubleClick(unsigned _itemId);
	virtual void OnTransferItem(CArkItem &_item, IArkInventory *_pSourceInventory, IArkInventory *_pTargetInventory);
	virtual void OnSetHighlight(unsigned _itemId);
	virtual bool CanLootItem(unsigned _itemId);
	virtual bool IsInDefaultMode() const;
	virtual void PlayErrorSound();
	virtual bool CanDragItem(unsigned _itemId);
	virtual void OnDragItem(unsigned _itemId);
	virtual void OnPauseMenuOpened();
	void Close() { FClose(this); }
	void TransferItem(unsigned _itemId) { FTransferItem(this,_itemId); }
	virtual bool CanCombine(unsigned _selectedId, unsigned _overId) const;
	virtual bool Combine(unsigned _selectedId, unsigned _overId);
	void UpdateDimmed(unsigned _itemId) { FUpdateDimmed(this,_itemId); }
	virtual ~CArkExternalInventoryUI();
	
#if 0
	void SetPlayerInventory();
	void ForceClose();
	bool IsOpen() const;
	static IUIElement *GetUIElement();
	void MoveHighlight(CArkInventoryUI::EArkMoveDir arg0);
	void ShowRequiresMessage(unsigned arg0);
	void TrySplitStack();
	void ConfirmSplit();
	void CancelStackMode();
#endif
	
	static inline auto FReset = PreyFunction<void(CArkExternalInventoryUI *const _this)>(0x15EFDB0);
	static inline auto FOpen = PreyFunction<void(CArkExternalInventoryUI *const _this, ArkInventory &_inventory)>(0x15EF290);
	static inline auto FCloseOrCancel = PreyFunction<bool(CArkExternalInventoryUI *const _this)>(0x15EEA80);
	static inline auto FCloseUI = PreyFunction<void(CArkExternalInventoryUI *const _this)>(0x15EEB00);
	static inline auto FProcessInput = PreyFunction<void(CArkExternalInventoryUI *const _this, CCryName const &_actionId, const int _activationMode, const float _value)>(0x15EF5F0);
	static inline auto FUpdate = PreyFunction<void(CArkExternalInventoryUI *const _this, float _frameTime)>(0x15F0070);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(CArkExternalInventoryUI *const _this, EControlScheme _controlScheme)>(0x15EEE70);
	static inline auto FUpdateInputPrompt = PreyFunction<void(CArkExternalInventoryUI const *const _this, bool _bUpdateUI)>(0x15F0390);
	static inline auto FOnDoubleClick = PreyFunction<void(CArkExternalInventoryUI *const _this, unsigned _itemId)>(0x15EEF50);
	static inline auto FOnTransferItem = PreyFunction<void(CArkExternalInventoryUI *const _this, CArkItem &_item, IArkInventory *_pSourceInventory, IArkInventory *_pTargetInventory)>(0x15EF040);
	static inline auto FOnSetHighlight = PreyFunction<void(CArkExternalInventoryUI *const _this, unsigned _itemId)>(0x15EEFD0);
	static inline auto FCanLootItem = PreyFunction<bool(CArkExternalInventoryUI *const _this, unsigned _itemId)>(0x15EE5C0);
	static inline auto FIsInDefaultMode = PreyFunction<bool(CArkExternalInventoryUI const *const _this)>(0x15EEE60);
	static inline auto FPlayErrorSound = PreyFunction<void(CArkExternalInventoryUI *const _this)>(0x15EF580);
	static inline auto FCanDragItem = PreyFunction<bool(CArkExternalInventoryUI *const _this, unsigned _itemId)>(0x1B3C9D0);
	static inline auto FOnDragItem = PreyFunction<void(CArkExternalInventoryUI *const _this, unsigned _itemId)>(0x15EEF60);
	static inline auto FOnPauseMenuOpened = PreyFunction<void(CArkExternalInventoryUI *const _this)>(0x15EEFA0);
	static inline auto FClose = PreyFunction<void(CArkExternalInventoryUI *const _this)>(0x15EE670);
	static inline auto FTransferItem = PreyFunction<void(CArkExternalInventoryUI *const _this, unsigned _itemId)>(0x15EFEF0);
	static inline auto FCanCombine = PreyFunction<bool(CArkExternalInventoryUI const *const _this, unsigned _selectedId, unsigned _overId)>(0x15EE560);
	static inline auto FCombine = PreyFunction<bool(CArkExternalInventoryUI *const _this, unsigned _selectedId, unsigned _overId)>(0x15EED80);
	static inline auto FUpdateDimmed = PreyFunction<void(CArkExternalInventoryUI *const _this, unsigned _itemId)>(0x15F0080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>
#include <Prey/GameDll/ark/ui/ArkInventoryUI.h>
#include <Prey/GameDll/ark/ui/IArkPauseMenuListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>

class ArkInventory;
class CArkInventoryUI;
class CArkItem;
class CCryName;
enum EControlScheme;
struct IUIElement;

// CArkExternalInventoryUI
// Header:  Prey/GameDll/ark/ui/ArkExternalInventoryUI.h
class CArkExternalInventoryUI
	: public IUIControlSchemeListener
	, public IArkInventoryUIOwner
	, public IArkPauseMenuListener
{ // Size=112 (0x70)
public:
	enum class ViewState
	{
		Default = 0,
		Stack = 1,
	};

	// CArkExternalInventoryUI::TransferNotification
	// Header:  Prey/GameDll/ark/ui/ArkExternalInventoryUI.h
	class TransferNotification
	{ // Size=48 (0x30)
	public:
		unsigned m_itemId;
		uint64_t m_archetypeId;
		string m_displayName;
		string m_icon;
		bool m_bImportant;
		int m_count;
		IArkItem::EArkQualityTier m_quality;

	#if 0
		TransferNotification(const unsigned _arg0_, const uint64_t _arg1_, const char* _arg2_, const char* _arg3_, const bool _arg4_, const int _arg5_, const IArkItem::EArkQualityTier _arg6_);
		bool operator==(const unsigned _arg0_) const;
	#endif
	};

	std::unique_ptr<CArkInventoryUI> m_pInventoryUI;
	static inline auto k_UIElement = PreyGlobal<const char*>(0x23EEC20);
	ArkAudioTrigger m_takeItemTrigger;
	ArkAudioTrigger m_storeItemTrigger;
	ArkAudioTrigger m_takeAllTrigger;
	ArkAudioTrigger m_inventoryFullTrigger;
	ArkAudioTrigger m_inventoryErrorTrigger;
	bool m_bIsOpen;
	CArkExternalInventoryUI::ViewState m_viewState;
	std::vector<CArkExternalInventoryUI::TransferNotification> m_transferNotifications;
	std::vector<unsigned int> m_untransferredItems;

	CArkExternalInventoryUI();
	void Reset() { FReset(this); }
	void Open(ArkInventory& _inventory) { FOpen(this, _inventory); }
	bool CloseOrCancel() { return FCloseOrCancel(this); }
	void CloseUI() { FCloseUI(this); }
	void ProcessInput(const CCryName& _actionId, const int _activationMode, const float _value) { FProcessInput(this, _actionId, _activationMode, _value); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	virtual void UpdateInputPrompt(bool _bUpdateUI) const;
	virtual void OnDoubleClick(unsigned _itemId);
	virtual void OnTransferItem(CArkItem& _item, ArkInventory* _pSourceInventory, ArkInventory* _pTargetInventory);
	virtual void OnSetHighlight(unsigned _itemId);
	virtual bool CanLootItem(unsigned _itemId);
	virtual bool IsInDefaultMode() const;
	virtual void PlayErrorSound();
	virtual bool CanDragItem(unsigned _itemId);
	virtual void OnDragItem(unsigned _itemId);
	void OnPressAutosort() { FOnPressAutosort(this); }
	void OnPressInventoryConfirm() { FOnPressInventoryConfirm(this); }
	void OnPressConsume() { FOnPressConsume(this); }
	void OnPressTakeAll() { FOnPressTakeAll(this); }
	void OnPressTakeStow() { FOnPressTakeStow(this); }
	virtual void OnPauseMenuOpened();
	void Close() { FClose(this); }
	void TransferItem(unsigned _itemId) { FTransferItem(this, _itemId); }
	void TrySplitStack() { FTrySplitStack(this); }
	virtual bool CanCombine(unsigned _selectedId, unsigned _overId) const;
	virtual bool Combine(unsigned _selectedId, unsigned _overId);
	void UpdateDimmed(unsigned _itemId) { FUpdateDimmed(this, _itemId); }

#if 0
	void SetPlayerInventory();
	void ForceClose();
	bool IsOpen() const;
	static IUIElement* GetUIElement();
	void MoveHighlight(const CArkInventoryUI::EArkMoveDir _arg0_);
	void ShowRequiresMessage(unsigned _arg0_);
	void ConfirmSplit();
	void CancelStackMode();
#endif

	static inline auto FCArkExternalInventoryUIOv1 = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x170E760);
	static inline auto FReset = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x1710490);
	static inline auto FOpen = PreyFunction<void(CArkExternalInventoryUI* const _this, ArkInventory& _inventory)>(0x170FEC0);
	static inline auto FCloseOrCancel = PreyFunction<bool(CArkExternalInventoryUI* const _this)>(0x170F0A0);
	static inline auto FCloseUI = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x170F120);
	static inline auto FProcessInput = PreyFunction<void(CArkExternalInventoryUI* const _this, const CCryName& _actionId, const int _activationMode, const float _value)>(0x1710210);
	static inline auto FUpdate = PreyFunction<void(CArkExternalInventoryUI* const _this, float _frameTime)>(0x1710730);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(CArkExternalInventoryUI* const _this, const EControlScheme _controlScheme)>(0x170F3F0);
	static inline auto FUpdateInputPrompt = PreyFunction<void(const IArkInventoryUIOwner* const _this, bool _bUpdateUI)>(0x1710A50);
	static inline auto FOnDoubleClick = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x170F4D0);
	static inline auto FOnTransferItem = PreyFunction<void(IArkInventoryUIOwner* const _this, CArkItem& _item, ArkInventory* _pSourceInventory, ArkInventory* _pTargetInventory)>(0x170FC60);
	static inline auto FOnSetHighlight = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x170FBF0);
	static inline auto FCanLootItem = PreyFunction<bool(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x170EB80);
	static inline auto FIsInDefaultMode = PreyFunction<bool(const IArkInventoryUIOwner* const _this)>(0x170F3E0);
	static inline auto FPlayErrorSound = PreyFunction<void(IArkInventoryUIOwner* const _this)>(0x17101A0);
	static inline auto FCanDragItem = PreyFunction<bool(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x18A63A0);
	static inline auto FOnDragItem = PreyFunction<void(IArkInventoryUIOwner* const _this, unsigned _itemId)>(0x170F4E0);
	static inline auto FOnPressAutosort = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x170F550);
	static inline auto FOnPressInventoryConfirm = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x170F610);
	static inline auto FOnPressConsume = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x170F590);
	static inline auto FOnPressTakeAll = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x170F890);
	static inline auto FOnPressTakeStow = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x170FB20);
	static inline auto FOnPauseMenuOpened = PreyFunction<void(IArkPauseMenuListener* const _this)>(0x170F520);
	static inline auto FClose = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x170EC20);
	static inline auto FTransferItem = PreyFunction<void(CArkExternalInventoryUI* const _this, unsigned _itemId)>(0x17105D0);
	static inline auto FTrySplitStack = PreyFunction<void(CArkExternalInventoryUI* const _this)>(0x17106F0);
	static inline auto FCanCombine = PreyFunction<bool(const IArkInventoryUIOwner* const _this, unsigned _selectedId, unsigned _overId)>(0x170EB20);
	static inline auto FCombine = PreyFunction<bool(IArkInventoryUIOwner* const _this, unsigned _selectedId, unsigned _overId)>(0x170F3A0);
	static inline auto FUpdateDimmed = PreyFunction<void(CArkExternalInventoryUI* const _this, unsigned _itemId)>(0x1710740);
};
#endif // !MOONCRASH
