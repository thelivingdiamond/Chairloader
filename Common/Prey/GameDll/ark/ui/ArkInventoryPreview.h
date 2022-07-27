// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/arkinventoryui.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
class ArkInventory;
class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkInventoryPreview.h
class ArkInventoryPreview : public IArkInventoryListener, public IArkPlayerInteractionListener, private boost::noncopyable_::noncopyable // Id=8017485 Size=648
{
public:
	ArkInventory *m_pInventory;
	unsigned m_interactionEntityId;
	int m_x;
	int m_y;
	int m_startingRow;
	ArkAudioTrigger m_lootItemTrigger;
	ArkAudioTrigger m_lootFailedTrigger;
	ArkAudioTrigger m_inventoryFullTrigger;
	ArkButtonPromptCollection m_inputPrompts;
	ArkSimpleTimer m_errorTimer;
	
	ArkInventoryPreview();
	virtual ~ArkInventoryPreview();
	void Open(ArkInventory &_inventory, unsigned _interactionEntityId) { FOpen(this,_inventory,_interactionEntityId); }
	void Close() { FClose(this); }
	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void RefreshDisplay() { FRefreshDisplay(this); }
	bool ProcessInput(CCryName const &_actionId, const int _activationMode, const float _value) { return FProcessInput(this,_actionId,_activationMode,_value); }
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId);
	virtual void OnItemRemoved(unsigned _itemId);
	virtual void OnItemCountChanged(unsigned _itemId);
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	void Enable() { FEnable(this); }
	void Disable() { FDisable(this); }
	void UpdateGrid() { FUpdateGrid(this); }
	void MoveHighlight(CArkInventoryUI::EArkMoveDir _dir) { FMoveHighlight(this,_dir); }
	void SelectCurrent() { FSelectCurrent(this); }
	void UpdateInputPrompt() { FUpdateInputPrompt(this); }
	void CloseFeedback() { FCloseFeedback(this); }
	
#if 0
	bool IsOpen() const;
	unsigned GetInventoryId() const;
	std::pair<int,int> GetDimensions(int arg0, int arg1) const;
	void UpdateGridIfVisible(unsigned arg0);
	void UnregisterListeners();
	void ShowErrorMessage(wstring const &arg0);
#endif
	
	static inline auto FBitNotArkInventoryPreview = PreyFunction<void(ArkInventoryPreview *const _this)>(0x1358190);
	static inline auto FOpen = PreyFunction<void(ArkInventoryPreview *const _this, ArkInventory &_inventory, unsigned _interactionEntityId)>(0x1358AF0);
	static inline auto FClose = PreyFunction<void(ArkInventoryPreview *const _this)>(0x13582C0);
	static inline auto FReset = PreyFunction<void(ArkInventoryPreview *const _this)>(0x1359080);
	static inline auto FUpdate = PreyFunction<void(ArkInventoryPreview *const _this, float _frameTime)>(0x1359540);
	static inline auto FRefreshDisplay = PreyFunction<void(ArkInventoryPreview *const _this)>(0x1359060);
	static inline auto FProcessInput = PreyFunction<bool(ArkInventoryPreview *const _this, CCryName const &_actionId, const int _activationMode, const float _value)>(0x1358D80);
	static inline auto FOnItemAdded = PreyFunction<void(ArkInventoryPreview *const _this, unsigned _itemId, unsigned _originalId)>(0x1358AA0);
	static inline auto FOnItemRemoved = PreyFunction<void(ArkInventoryPreview *const _this, unsigned _itemId)>(0x1358AE0);
	static inline auto FOnItemCountChanged = PreyFunction<void(ArkInventoryPreview *const _this, unsigned _itemId)>(0x1358AA0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkInventoryPreview const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1358BE0);
	static inline auto FTestInteraction = PreyFunction<bool(ArkInventoryPreview const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x1359520);
	static inline auto FOnInteraction = PreyFunction<bool(ArkInventoryPreview *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x1358700);
	static inline auto FEnable = PreyFunction<void(ArkInventoryPreview *const _this)>(0x13583B0);
	static inline auto FDisable = PreyFunction<void(ArkInventoryPreview *const _this)>(0x13583A0);
	static inline auto FUpdateGrid = PreyFunction<void(ArkInventoryPreview *const _this)>(0x13595D0);
	static inline auto FMoveHighlight = PreyFunction<void(ArkInventoryPreview *const _this, CArkInventoryUI::EArkMoveDir _dir)>(0x13584A0);
	static inline auto FSelectCurrent = PreyFunction<void(ArkInventoryPreview *const _this)>(0x13590E0);
	static inline auto FUpdateInputPrompt = PreyFunction<void(ArkInventoryPreview *const _this)>(0x135A2A0);
	static inline auto FCloseFeedback = PreyFunction<void(ArkInventoryPreview *const _this)>(0x1358330);
};

