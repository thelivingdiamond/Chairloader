// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class ArkChipsetComponent;
enum EControlScheme;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// CArkPDAPageChipsets
// Header:  Prey/GameDll/ark/ui/ArkPDAPageChipsets.h
class CArkPDAPageChipsets
	: public IArkPDAPage
	, public ArkUIMenuBase<CArkPDAPageChipsets>
	, public IUIControlSchemeListener
{ // Size=64 (0x40)
public:
	ArkAudioTrigger m_installTrigger;
	ArkAudioTrigger m_uninstallTrigger;
	int m_currentIndex;

	CArkPDAPageChipsets();
	virtual ~CArkPDAPageChipsets();
	virtual void SetupInputPrompts();
	virtual bool ManagesInputPrompts() const;
	void Reset() { FReset(this); }
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	virtual bool HasNew() const;
	void OnHighlightChipset(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnHighlightChipset(this, _pSender, _event, _args); }
	void OnHighlightSlot(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnHighlightSlot(this, _pSender, _event, _args); }
	void OnDoubleClick(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnDoubleClick(this, _pSender, _event, _args); }
	void OnSetEquipped(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnSetEquipped(this, _pSender, _event, _args); }
	void SelectChipset(int _index) { FSelectChipset(this, _index); }
	void UpdateSlots() const { FUpdateSlots(this); }

#if 0
	ArkChipsetComponent& GetChipsetComponent() const;
	int GetChipsetType() const;
#endif

	static inline auto FCArkPDAPageChipsetsOv1 = PreyFunction<void(CArkPDAPageChipsets* const _this)>(0x1454010);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageChipsets* const _this)>(0x1455AD0);
	static inline auto FManagesInputPrompts = PreyFunction<bool(const CArkPDAPageChipsets* const _this)>(0x1A302A0);
	static inline auto FReset = PreyFunction<void(CArkPDAPageChipsets* const _this)>(0x14556D0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x1454AF0);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageChipsets* const _this)>(0x14552E0);
	static inline auto FClose = PreyFunction<void(CArkPDAPageChipsets* const _this)>(0x1454A10);
	static inline auto FRefresh = PreyFunction<void(const CArkPDAPageChipsets* const _this)>(0x14553F0);
	static inline auto FHasNew = PreyFunction<bool(const CArkPDAPageChipsets* const _this)>(0x1454A80);
	static inline auto FOnHighlightChipset = PreyFunction<void(CArkPDAPageChipsets* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1454B20);
	static inline auto FOnHighlightSlot = PreyFunction<void(CArkPDAPageChipsets* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1454BA0);
	static inline auto FOnDoubleClick = PreyFunction<void(CArkPDAPageChipsets* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1454B10);
	static inline auto FOnSetEquipped = PreyFunction<void(CArkPDAPageChipsets* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1454C80);
	static inline auto FSelectChipset = PreyFunction<void(CArkPDAPageChipsets* const _this, int _index)>(0x1455720);
	static inline auto FUpdateSlots = PreyFunction<void(const CArkPDAPageChipsets* const _this)>(0x1455E20);
};
#endif // MOONCRASH
