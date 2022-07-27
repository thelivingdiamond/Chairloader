// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class ArkEquipmentModComponent;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapageequipmentmods.h
class CArkPDAPageEquipmentMods : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageEquipmentMods> // Id=801903D Size=152
{
public:
	const char *m_setLevelFn;
	const char *m_addItemFn;
	const char *m_startMoveFn;
	const char *m_moveFn;
	const char *m_releaseMoveFn;
	const char *m_clearItemsFn;
	const char *m_updateListFn;
	const char *m_fanfareFn;
	const char *m_updateSlotsFn;
	const char *m_highlightSlotFn;
	const char *m_setEquippedFn;
	const char *m_updateDisplayPaneFn;
	ArkAudioTrigger m_installTrigger;
	ArkAudioTrigger m_uninstallTrigger;
	int m_currentIndex;
	
	CArkPDAPageEquipmentMods();
	virtual ~CArkPDAPageEquipmentMods();
	virtual void SetupInputPrompts();
	virtual bool ManagesInputPrompts() const;
	virtual void Reset() = 0;
	virtual ArkEquipmentModComponent &GetChipsetComponent() const = 0;
	void OnOpen() { FOnOpen(this); }
	virtual int GetChipsetType() const = 0;
	virtual void Close();
	virtual void Refresh() const;
	virtual bool HasNew() const;
	void OnHighlightChipset(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnHighlightChipset(this,_pSender,_event,_args); }
	void OnHighlightSlot(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnHighlightSlot(this,_pSender,_event,_args); }
	void OnDoubleClick(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnDoubleClick(this,_pSender,_event,_args); }
	void OnSetEquipped(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSetEquipped(this,_pSender,_event,_args); }
	void SelectChipset(int _index) { FSelectChipset(this,_index); }
	void UpdateSlots() const { FUpdateSlots(this); }
	
	static inline auto FBitNotCArkPDAPageEquipmentMods = PreyFunction<void(CArkPDAPageEquipmentMods *const _this)>(0x1371A00);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageEquipmentMods *const _this)>(0x1372A50);
	static inline auto FManagesInputPrompts = PreyFunction<bool(CArkPDAPageEquipmentMods const *const _this)>(0x1B933B0);
	static inline auto FOnOpen = PreyFunction<void(CArkPDAPageEquipmentMods *const _this)>(0x1371E80);
	static inline auto FClose = PreyFunction<void(CArkPDAPageEquipmentMods *const _this)>(0x1628FA0);
	static inline auto FRefresh = PreyFunction<void(CArkPDAPageEquipmentMods const *const _this)>(0x13722F0);
	static inline auto FHasNew = PreyFunction<bool(CArkPDAPageEquipmentMods const *const _this)>(0x1371CC0);
	static inline auto FOnHighlightChipset = PreyFunction<void(CArkPDAPageEquipmentMods *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1371D30);
	static inline auto FOnHighlightSlot = PreyFunction<void(CArkPDAPageEquipmentMods *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1371DC0);
	static inline auto FOnDoubleClick = PreyFunction<void(CArkPDAPageEquipmentMods *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1371D20);
	static inline auto FOnSetEquipped = PreyFunction<void(CArkPDAPageEquipmentMods *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1371F30);
	static inline auto FSelectChipset = PreyFunction<void(CArkPDAPageEquipmentMods *const _this, int _index)>(0x1372590);
	static inline auto FUpdateSlots = PreyFunction<void(CArkPDAPageEquipmentMods const *const _this)>(0x1372CF0);
};

