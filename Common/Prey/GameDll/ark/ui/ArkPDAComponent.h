// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkexternalinventoryui.h>
#include <Prey/GameDll/ark/ui/IUIModule.h>

class ArkAuxiliaryInventory;
class ArkInventory;
class CCryName;
class IArkInventory;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkPDAComponent.h
class ArkPDAComponent : public ArkUIMenuBase<ArkPDAComponent>, public IUIControlSchemeListener, public IUIModule // Id=8016FCD Size=896
{
public:
	std::array<std::unique_ptr<IArkPDAPage>,16> m_PDAPages;
	std::array<ArkAudioTrigger,5> m_PDASounds;
	std::unique_ptr<CArkExternalInventoryUI> m_pExternalInventory;
	unsigned m_entityId;
	ArkPDAPage m_PDACurrentPage;
	bool m_bPDAOpened;
	bool m_bPDATransitioning;
	bool m_bResetPDA;
	bool m_bDisabled;
	bool m_bHideDateTime;
	int m_inputHandle;
	_smart_ptr<TAction<SAnimationContext> > m_pIdleAction;
	std::array<bool,16> m_aPDAPageEnabled;
	ArkButtonPromptCollection m_inputPrompts;
	bool m_bPromptsDirty;
	ArkPDAPage m_lastDataPage;
	ArkPDAPage m_pageToOpen;
	int m_timeHandle;
	std::vector<ArkMaterialParamOverride> m_originalDisruptionValues;
	ArkSimpleTimer m_errorTimer;
	ArkAuxiliaryInventory *m_pOverflowInventory;
	bool m_bIsOpeningExternalInventory;
	
	ArkPDAComponent();
	virtual ~ArkPDAComponent();
	void TogglePDA(const bool _bForceClose, bool _bFromPause) { FTogglePDA(this,_bForceClose,_bFromPause); }
	void ToggleInventory() { FToggleInventory(this); }
	void ToggleObjectives() { FToggleObjectives(this); }
	void ToggleAbilities() { FToggleAbilities(this); }
	void ToggleMap() { FToggleMap(this); }
	void ToggleData() { FToggleData(this); }
	void ToggleStatus() { FToggleStatus(this); }
	void ToggleSuitChipsets() { FToggleSuitChipsets(this); }
	void ToggleScopeChipsets() { FToggleScopeChipsets(this); }
	void OpenLore() { FOpenLore(this); }
	void OpenCodes() { FOpenCodes(this); }
	void OpenStationMap() { FOpenStationMap(this); }
	virtual void Reset();
	void ProcessInput(CCryName const &_rActionId, const int _activationMode, const float _fValue) { FProcessInput(this,_rActionId,_activationMode,_fValue); }
	void OpenExternalInventory(ArkInventory *_pInventory) { FOpenExternalInventory(this,_pInventory); }
	void OpenOverflowInventory(std::vector<unsigned int> const &_itemIds) { FOpenOverflowInventory(this,_itemIds); }
	void OnCloseExternalInventory() { FOnCloseExternalInventory(this); }
	void OpenObjective(const int64_t _objectiveId) { FOpenObjective(this,_objectiveId); }
	void EnableDisruption(bool _bEnable) { FEnableDisruption(this,_bEnable); }
	void ShowPDAErrorMessage(wstring const &_errorMsg) { FShowPDAErrorMessage(this,_errorMsg); }
	void SpawnTranscribe() { FSpawnTranscribe(this); }
	virtual void Init();
	void Release() { FRelease(this); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Open() { FOpen(this); }
	void Close() { FClose(this); }
	void ShowEntity() const { FShowEntity(this); }
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	void UpdateInputPrompts(const bool _bForceUIUpdate, IUIElement *const _pUIElement) { FUpdateInputPrompts(this,_bForceUIUpdate,_pUIElement); }
	void SetInputPrompt(const int _index, const bool _bVisible, CCryName const &_actionId, string const &_label, bool _bUseHoldTriggerDelay, bool _bEnabled) { FSetInputPrompt(this,_index,_bVisible,_actionId,_label,_bUseHoldTriggerDelay,_bEnabled); }
	void ClearRemainingInputPrompts(const int _startingIndex) { FClearRemainingInputPrompts(this,_startingIndex); }
	void EnablePDAPage(ArkPDAPage _page, bool _bEnable) { FEnablePDAPage(this,_page,_bEnable); }
	void PDASetAndOpenPage(ArkPDAPage _page) { FPDASetAndOpenPage(this,_page); }
	void PDASafeSetAndOpenPage(ArkPDAPage _page) { FPDASafeSetAndOpenPage(this,_page); }
	void PDASetTabAndToggle(ArkPDATab _tab) { FPDASetTabAndToggle(this,_tab); }
	void SetHealth(float _fHealth, float _fMaxHealth, float _unreducedMaxHealth) { FSetHealth(this,_fHealth,_fMaxHealth,_unreducedMaxHealth); }
	void SetPsi(float _psiPoints, float _maxPsiPoints, float _unreducedMaxPsiPoints, bool _bVisible) { FSetPsi(this,_psiPoints,_maxPsiPoints,_unreducedMaxPsiPoints,_bVisible); }
	void SetArmor(float _armor, float _max, bool _bVisible) { FSetArmor(this,_armor,_max,_bVisible); }
	virtual void UpdateModule(float _fDelta);
	virtual void Reload();
	void SetIdleAction(const char *const _idleFragmentName) { FSetIdleAction(this,_idleFragmentName); }
	void CloseTranscribe() { FCloseTranscribe(this); }
	void PrepareOpen() { FPrepareOpen(this); }
	bool IsTabAvailable(ArkPDATab _tab) const { return FIsTabAvailable(this,_tab); }
	void RefreshNew() const { FRefreshNew(this); }
	void Reset_Internal() { FReset_Internal(this); }
	void HideAttachment(const bool _bHide) const { FHideAttachment(this,_bHide); }
	void ToggleMenu(const bool _bOpen, const bool _bFromPause) { FToggleMenu(this,_bOpen,_bFromPause); }
	void SetupInputPrompts(const bool _bForceUIUpdate) { FSetupInputPrompts(this,_bForceUIUpdate); }
	void OnOpenPage(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnOpenPage(this,_pSender,_event,_args); }
	void OnOpenTab(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnOpenTab(this,_pSender,_event,_args); }
	void UpdateUIPageEnabled() const { FUpdateUIPageEnabled(this); }
	static const char *GetUIStringForPDAPage(ArkPDAPage _page) { return FGetUIStringForPDAPage(_page); }
	void CycleTabs(bool _bLeft) { FCycleTabs(this,_bLeft); }
	std::vector<enum ArkPDATab> GetAvailableTabs() const { return FGetAvailableTabs(this); }
	void OpenTabPage(ArkPDATab _tab) { FOpenTabPage(this,_tab); }
	void UpdateTabArray() { FUpdateTabArray(this); }
	
#if 0
	void RefreshPDA() const;
	void OpenNote(const uint64_t arg0);
	ArkPDAPage GetCurrentPage() const;
	static const char *GetPDAUIElementName();
	static IUIElement *GetPDAUIElement();
	void PlaySound(ArkPDASound arg0) const;
	void SetPDAOpened(bool arg0);
	bool IsPDAOpened() const;
	bool IsPDAOpening() const;
	bool IsPDAOpenOrOpening() const;
	bool IsExternalInventoryOpened() const;
	void HideDateAndTime(bool arg0);
	IArkInventory *GetOverflowInventory() const;
	void SetupDefaultInputPrompts();
	void SetDisabled(bool arg0);
	static bool ShouldSkipTransitionAnimation();
	bool LockTransition();
	void ClearTransitioning();
	bool IsPageEnabled(ArkPDAPage arg0) const;
	std::vector<enum ArkPDAPage> GetAvailablePages(ArkPDATab arg0) const;
	ArkPDAPage GetFirstTabPage(ArkPDATab arg0);
	ArkPDAPage GetSelectedTabPage(ArkPDATab arg0);
	ArkPDATab GetCurrentTab() const;
#endif
	
	static inline auto FTogglePDA = PreyFunction<void(ArkPDAComponent *const _this, const bool _bForceClose, bool _bFromPause)>(0x160FC30);
	static inline auto FToggleInventory = PreyFunction<void(ArkPDAComponent *const _this)>(0x160FA50);
	static inline auto FToggleObjectives = PreyFunction<void(ArkPDAComponent *const _this)>(0x160FC20);
	static inline auto FToggleAbilities = PreyFunction<void(ArkPDAComponent *const _this)>(0x160FA30);
	static inline auto FToggleMap = PreyFunction<void(ArkPDAComponent *const _this)>(0x160FA60);
	static inline auto FToggleData = PreyFunction<void(ArkPDAComponent *const _this)>(0x160FA40);
	static inline auto FToggleStatus = PreyFunction<void(ArkPDAComponent *const _this)>(0x1610070);
	static inline auto FToggleSuitChipsets = PreyFunction<void(ArkPDAComponent *const _this)>(0x1610080);
	static inline auto FToggleScopeChipsets = PreyFunction<void(ArkPDAComponent *const _this)>(0x1610060);
	static inline auto FOpenLore = PreyFunction<void(ArkPDAComponent *const _this)>(0x160D850);
	static inline auto FOpenCodes = PreyFunction<void(ArkPDAComponent *const _this)>(0x160D7D0);
	static inline auto FOpenStationMap = PreyFunction<void(ArkPDAComponent *const _this)>(0x160D9C0);
	static inline auto FReset = PreyFunction<void(ArkPDAComponent *const _this)>(0x160E8B0);
	static inline auto FProcessInput = PreyFunction<void(ArkPDAComponent *const _this, CCryName const &_rActionId, const int _activationMode, const float _fValue)>(0x160DE40);
	static inline auto FOpenExternalInventory = PreyFunction<void(ArkPDAComponent *const _this, ArkInventory *_pInventory)>(0x160D7E0);
	static inline auto FOpenOverflowInventory = PreyFunction<void(ArkPDAComponent *const _this, std::vector<unsigned int> const &_itemIds)>(0x160D890);
	static inline auto FOnCloseExternalInventory = PreyFunction<void(ArkPDAComponent *const _this)>(0x160CA10);
	static inline auto FOpenObjective = PreyFunction<void(ArkPDAComponent *const _this, const int64_t _objectiveId)>(0x160D860);
	static inline auto FEnableDisruption = PreyFunction<void(ArkPDAComponent *const _this, bool _bEnable)>(0x1609CF0);
	static inline auto FShowPDAErrorMessage = PreyFunction<void(ArkPDAComponent *const _this, wstring const &_errorMsg)>(0x160F800);
	static inline auto FSpawnTranscribe = PreyFunction<void(ArkPDAComponent *const _this)>(0x160F860);
	static inline auto FInit = PreyFunction<void(ArkPDAComponent *const _this)>(0x160A530);
	static inline auto FRelease = PreyFunction<void(ArkPDAComponent *const _this)>(0x160E870);
	static inline auto FSerialize = PreyFunction<void(ArkPDAComponent *const _this, TSerialize ser)>(0x160EB50);
	static inline auto FPostSerialize = PreyFunction<void(ArkPDAComponent *const _this)>(0x160DC60);
	static inline auto FOpen = PreyFunction<void(ArkPDAComponent *const _this)>(0x160D1C0);
	static inline auto FClose = PreyFunction<void(ArkPDAComponent *const _this)>(0x1609A20);
	static inline auto FShowEntity = PreyFunction<void(ArkPDAComponent const *const _this)>(0x160F7B0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkPDAComponent *const _this, EControlScheme _controlScheme)>(0x160CA40);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkPDAComponent *const _this, const bool _bForceUIUpdate, IUIElement *const _pUIElement)>(0x1610090);
	static inline auto FSetInputPrompt = PreyFunction<void(ArkPDAComponent *const _this, const int _index, const bool _bVisible, CCryName const &_actionId, string const &_label, bool _bUseHoldTriggerDelay, bool _bEnabled)>(0x160F230);
	static inline auto FClearRemainingInputPrompts = PreyFunction<void(ArkPDAComponent *const _this, const int _startingIndex)>(0x16099F0);
	static inline auto FEnablePDAPage = PreyFunction<void(ArkPDAComponent *const _this, ArkPDAPage _page, bool _bEnable)>(0x1609FD0);
	static inline auto FPDASetAndOpenPage = PreyFunction<void(ArkPDAComponent *const _this, ArkPDAPage _page)>(0x160DAB0);
	static inline auto FPDASafeSetAndOpenPage = PreyFunction<void(ArkPDAComponent *const _this, ArkPDAPage _page)>(0x160DA90);
	static inline auto FPDASetTabAndToggle = PreyFunction<void(ArkPDAComponent *const _this, ArkPDATab _tab)>(0x160DB40);
	static inline auto FSetHealth = PreyFunction<void(ArkPDAComponent *const _this, float _fHealth, float _fMaxHealth, float _unreducedMaxHealth)>(0x160EF60);
	static inline auto FSetPsi = PreyFunction<void(ArkPDAComponent *const _this, float _psiPoints, float _maxPsiPoints, float _unreducedMaxPsiPoints, bool _bVisible)>(0x160F470);
	static inline auto FSetArmor = PreyFunction<void(ArkPDAComponent *const _this, float _armor, float _max, bool _bVisible)>(0x160EDC0);
	static inline auto FUpdateModule = PreyFunction<void(ArkPDAComponent *const _this, float _fDelta)>(0x16100F0);
	static inline auto FReload = PreyFunction<void(ArkPDAComponent *const _this)>(0x160E8A0);
	static inline auto FSetIdleAction = PreyFunction<void(ArkPDAComponent *const _this, const char *const _idleFragmentName)>(0x160F140);
	static inline auto FCloseTranscribe = PreyFunction<void(ArkPDAComponent *const _this)>(0x1609B10);
	static inline auto FPrepareOpen = PreyFunction<void(ArkPDAComponent *const _this)>(0x160DC90);
	static inline auto FIsTabAvailable = PreyFunction<bool(ArkPDAComponent const *const _this, ArkPDATab _tab)>(0x160C9E0);
	static inline auto FRefreshNew = PreyFunction<void(ArkPDAComponent const *const _this)>(0x160E0A0);
	static inline auto FReset_Internal = PreyFunction<void(ArkPDAComponent *const _this)>(0x160E8E0);
	static inline auto FHideAttachment = PreyFunction<void(ArkPDAComponent const *const _this, const bool _bHide)>(0x160A4C0);
	static inline auto FToggleMenu = PreyFunction<void(ArkPDAComponent *const _this, const bool _bOpen, const bool _bFromPause)>(0x160FA70);
	static inline auto FSetupInputPrompts = PreyFunction<void(ArkPDAComponent *const _this, const bool _bForceUIUpdate)>(0x160F630);
	static inline auto FOnOpenPage = PreyFunction<void(ArkPDAComponent *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x160CCC0);
	static inline auto FOnOpenTab = PreyFunction<void(ArkPDAComponent *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x160D070);
	static inline auto FUpdateUIPageEnabled = PreyFunction<void(ArkPDAComponent const *const _this)>(0x1610970);
	static inline auto FGetUIStringForPDAPage = PreyFunction<const char *(ArkPDAPage _page)>(0x160A3D0);
	static inline auto FCycleTabs = PreyFunction<void(ArkPDAComponent *const _this, bool _bLeft)>(0x1609B60);
	static inline auto FGetAvailableTabs = PreyFunction<std::vector<enum ArkPDATab>(ArkPDAComponent const *const _this)>(0x160A2A0);
	static inline auto FOpenTabPage = PreyFunction<void(ArkPDAComponent *const _this, ArkPDATab _tab)>(0x160D9D0);
	static inline auto FUpdateTabArray = PreyFunction<void(ArkPDAComponent *const _this)>(0x1610280);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <CryEngine/crycommon/crystring.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <_unknown/ArkMaterialParamOverride.h>

class ArkAuxiliaryInventory;
class ArkInventory;
enum class ArkPDASound;
enum class ArkPDATab;
class CArkExternalInventoryUI;
class CCryName;
enum EControlScheme;
class Functor0;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// ArkPDAComponent
// Header:  Prey/GameDll/ark/ui/ArkPDAComponent.h
class ArkPDAComponent
	: public ArkUIMenuBase<ArkPDAComponent>
	, public IUIControlSchemeListener
	, public IUIModule
{ // Size=1152 (0x480)
public:
	std::array<std::unique_ptr<IArkPDAPage>, 16> m_PDAPages;
	std::array<ArkAudioTrigger, 5> m_PDASounds;
	std::unique_ptr<CArkExternalInventoryUI> m_pExternalInventory;
	unsigned m_entityId;
	ArkPDAPage m_PDACurrentPage;
	bool m_bPDAOpened;
	bool m_bPDATransitioning;
	bool m_bTransitioningOpen;
	bool m_bResetPDA;
	bool m_bDisabled;
	bool m_bViewedKasma;
	bool m_bHideDateTime;
	int m_inputHandle;
	_smart_ptr<TAction<SAnimationContext>> m_pIdleAction;
	std::array<bool, 16> m_aPDAPageEnabled;
	ArkButtonPromptCollection m_inputPrompts;
	bool m_bPromptsDirty;
	ArkPDAPage m_lastDataPage;
	ArkPDAPage m_pageToOpen;
	int m_timeHandle;
	std::vector<ArkMaterialParamOverride> m_originalDisruptionValues;
	ArkSimpleTimer m_errorTimer;
	ArkAuxiliaryInventory* m_pOverflowInventory;
	bool m_bIsOpeningExternalInventory;

	ArkPDAComponent();
	virtual ~ArkPDAComponent();
	void TogglePDA(const bool _bForceClose, bool _bFromPause) { FTogglePDA(this, _bForceClose, _bFromPause); }
	void ToggleInventory() { FToggleInventory(this); }
	void ToggleObjectives() { FToggleObjectives(this); }
	void ToggleAbilities() { FToggleAbilities(this); }
	void ToggleMap() { FToggleMap(this); }
	void ToggleData() { FToggleData(this); }
	void ToggleStatus() { FToggleStatus(this); }
	void ToggleChipsets() { FToggleChipsets(this); }
	void OpenLore() { FOpenLore(this); }
	void OpenCodes() { FOpenCodes(this); }
	void OpenProgressChecklist() { FOpenProgressChecklist(this); }
	virtual void Reset();
	void ProcessInput(const CCryName& _rActionId, const int _activationMode, const float _fValue) { FProcessInput(this, _rActionId, _activationMode, _fValue); }
	void OpenExternalInventory(ArkInventory* _pInventory) { FOpenExternalInventory(this, _pInventory); }
	void OpenOverflowInventory(const std::vector<unsigned int>& _itemIds) { FOpenOverflowInventory(this, _itemIds); }
	void OnCloseExternalInventory() { FOnCloseExternalInventory(this); }
	void OpenObjective(const uint64_t _objectiveId) { FOpenObjective(this, _objectiveId); }
	void EnableDisruption(bool _bEnable) { FEnableDisruption(this, _bEnable); }
	void ShowPDAErrorMessage(const wstring& _errorMsg) { FShowPDAErrorMessage(this, _errorMsg); }
	void SpawnTranscribe() { FSpawnTranscribe(this); }
	virtual void Init();
	void Release() { FRelease(this); }
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Open() { FOpen(this); }
	void Close() { FClose(this); }
	void ShowEntity() const { FShowEntity(this); }
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	void UpdateInputPrompts(const bool _bForceUIUpdate, IUIElement* const _pUIElement) { FUpdateInputPrompts(this, _bForceUIUpdate, _pUIElement); }
	void SetInputPrompt(const int _index, const bool _bVisible, const CCryName& _actionId, const string& _label, bool _bUseHoldTriggerDelay, bool _bEnabled, Functor0 _callback) { FSetInputPrompt(this, _index, _bVisible, _actionId, _label, _bUseHoldTriggerDelay, _bEnabled, _callback); }
	void ClearRemainingInputPrompts(const int _startingIndex) { FClearRemainingInputPrompts(this, _startingIndex); }
	void EnablePDAPage(ArkPDAPage _page, bool _bEnable) { FEnablePDAPage(this, _page, _bEnable); }
	void PDASetAndOpenPage(const ArkPDAPage _page) { FPDASetAndOpenPage(this, _page); }
	void PDASafeSetAndOpenPage(const ArkPDAPage _page) { FPDASafeSetAndOpenPage(this, _page); }
	void PDASetTabAndToggle(const ArkPDATab _tab) { FPDASetTabAndToggle(this, _tab); }
	void SetHealth(float _fHealth, float _fMaxHealth, float _unreducedMaxHealth) { FSetHealth(this, _fHealth, _fMaxHealth, _unreducedMaxHealth); }
	void SetPsi(float _psiPoints, float _maxPsiPoints, float _unreducedMaxPsiPoints, bool _bVisible) { FSetPsi(this, _psiPoints, _maxPsiPoints, _unreducedMaxPsiPoints, _bVisible); }
	void SetArmor(float _armor, float _max, bool _bVisible) { FSetArmor(this, _armor, _max, _bVisible); }
	void UpdateDoomClock() { FUpdateDoomClock(this); }
	virtual void UpdateModule(float _fDelta);
	virtual void Reload();
	void SetIdleAction(const char* const _idleFragmentName) { FSetIdleAction(this, _idleFragmentName); }
	void CloseTranscribe() { FCloseTranscribe(this); }
	void PrepareOpen() { FPrepareOpen(this); }
	void OnPressBack() { FOnPressBack(this); }
	void OnPressConfirm() { FOnPressConfirm(this); }
	bool IsTabAvailable(const ArkPDATab _tab) const { return FIsTabAvailable(this, _tab); }
	void RefreshNew() const { FRefreshNew(this); }
	void Reset_Internal() { FReset_Internal(this); }
	void HideAttachment(const bool _bHide) const { FHideAttachment(this, _bHide); }
	void ToggleMenu(const bool _bOpen, const bool _bFromPause) { FToggleMenu(this, _bOpen, _bFromPause); }
	void SetupInputPrompts(const bool _bForceUIUpdate) { FSetupInputPrompts(this, _bForceUIUpdate); }
	void OnOpenPage(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnOpenPage(this, _pSender, _event, _args); }
	void OnOpenTab(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnOpenTab(this, _pSender, _event, _args); }
	void OnPromptSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPromptSelect(this, _pSender, _event, _args); }
	void UpdateUIPageEnabled() const { FUpdateUIPageEnabled(this); }
	static const char* GetUIStringForPDAPage(ArkPDAPage _page) { return FGetUIStringForPDAPage(_page); }
	void CycleTabs(bool _bLeft) { FCycleTabs(this, _bLeft); }
	std::vector<enum::ArkPDATab> GetAvailableTabs() const { alignas(std::vector<enum::ArkPDATab>) std::byte _return_buf_[sizeof(std::vector<enum::ArkPDATab>)]; return *FGetAvailableTabs(this, reinterpret_cast<std::vector<enum::ArkPDATab>*>(_return_buf_)); }
	void OpenTabPage(ArkPDATab _tab) { FOpenTabPage(this, _tab); }
	void UpdateTabArray() { FUpdateTabArray(this); }

#if 0
	void OpenStationMap();
	void RefreshPDA() const;
	void OpenNote(const uint64_t _arg0_);
	ArkPDAPage GetCurrentPage() const;
	static const char* GetPDAUIElementName();
	static IUIElement* GetPDAUIElement();
	void PlaySound(const ArkPDASound _arg0_) const;
	void SetPDAOpened(bool _arg0_);
	bool IsPDAOpened() const;
	bool IsPDATransitioning() const;
	bool IsPDAOpening() const;
	bool IsPDAClosing() const;
	bool IsPDAOpenOrOpening() const;
	bool IsPDAOpenOrTransitioning() const;
	bool IsExternalInventoryOpened() const;
	void SetKasmaOrdersViewed();
	bool HasViewedKasmaOrders() const;
	void HideDateAndTime(bool _arg0_);
	ArkInventory* GetOverflowInventory() const;
	void SetupDefaultInputPrompts();
	void SetDisabled(bool _arg0_);
	bool IsDisabled() const;
	static bool ShouldSkipTransitionAnimation();
	bool LockTransition(bool _arg0_);
	void ClearTransitioning();
	bool IsPageEnabled(ArkPDAPage _arg0_) const;
	std::vector<enum::ArkPDAPage> GetAvailablePages(ArkPDATab _arg0_) const;
	ArkPDAPage GetFirstTabPage(ArkPDATab _arg0_);
	ArkPDAPage GetSelectedTabPage(ArkPDATab _arg0_);
	ArkPDATab GetCurrentTab() const;
#endif

	static inline auto FArkPDAComponent = PreyFunction<void(ArkPDAComponent* const _this)>(0x172A1B0);
	static inline auto FBitNotArkPDAComponent = PreyFunction<void(ArkPDAComponent* const _this)>(0x172ABB0);
	static inline auto FTogglePDA = PreyFunction<void(ArkPDAComponent* const _this, const bool _bForceClose, bool _bFromPause)>(0x1731730);
	static inline auto FToggleInventory = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731550);
	static inline auto FToggleObjectives = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731720);
	static inline auto FToggleAbilities = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731520);
	static inline auto FToggleMap = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731560);
	static inline auto FToggleData = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731540);
	static inline auto FToggleStatus = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731B80);
	static inline auto FToggleChipsets = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731530);
	static inline auto FOpenLore = PreyFunction<void(ArkPDAComponent* const _this)>(0x172F310);
	static inline auto FOpenCodes = PreyFunction<void(ArkPDAComponent* const _this)>(0x172F290);
	static inline auto FOpenProgressChecklist = PreyFunction<void(ArkPDAComponent* const _this)>(0x172F480);
	static inline auto FReset = PreyFunction<void(IUIModule* const _this)>(0x17302D0);
	static inline auto FProcessInput = PreyFunction<void(ArkPDAComponent* const _this, const CCryName& _rActionId, const int _activationMode, const float _fValue)>(0x172F910);
	static inline auto FOpenExternalInventory = PreyFunction<void(ArkPDAComponent* const _this, ArkInventory* _pInventory)>(0x172F2A0);
	static inline auto FOpenOverflowInventory = PreyFunction<void(ArkPDAComponent* const _this, const std::vector<unsigned int>& _itemIds)>(0x172F350);
	static inline auto FOnCloseExternalInventory = PreyFunction<void(ArkPDAComponent* const _this)>(0x172E180);
	static inline auto FOpenObjective = PreyFunction<void(ArkPDAComponent* const _this, const uint64_t _objectiveId)>(0x172F320);
	static inline auto FEnableDisruption = PreyFunction<void(ArkPDAComponent* const _this, bool _bEnable)>(0x172B450);
	static inline auto FShowPDAErrorMessage = PreyFunction<void(ArkPDAComponent* const _this, const wstring& _errorMsg)>(0x17312F0);
	static inline auto FSpawnTranscribe = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731350);
	static inline auto FInit = PreyFunction<void(IUIModule* const _this)>(0x172BCA0);
	static inline auto FRelease = PreyFunction<void(ArkPDAComponent* const _this)>(0x1730290);
	static inline auto FSerialize = PreyFunction<void(ArkPDAComponent* const _this, TSerialize ser)>(0x17305A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPDAComponent* const _this)>(0x172F720);
	static inline auto FOpen = PreyFunction<void(ArkPDAComponent* const _this)>(0x172EAC0);
	static inline auto FClose = PreyFunction<void(ArkPDAComponent* const _this)>(0x172B1C0);
	static inline auto FShowEntity = PreyFunction<void(const ArkPDAComponent* const _this)>(0x17312A0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x172E1B0);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkPDAComponent* const _this, const bool _bForceUIUpdate, IUIElement* const _pUIElement)>(0x1731DA0);
	static inline auto FSetInputPrompt = PreyFunction<void(ArkPDAComponent* const _this, const int _index, const bool _bVisible, const CCryName& _actionId, const string& _label, bool _bUseHoldTriggerDelay, bool _bEnabled, Functor0 _callback)>(0x1730C90);
	static inline auto FClearRemainingInputPrompts = PreyFunction<void(ArkPDAComponent* const _this, const int _startingIndex)>(0x172B190);
	static inline auto FEnablePDAPage = PreyFunction<void(ArkPDAComponent* const _this, ArkPDAPage _page, bool _bEnable)>(0x172B740);
	static inline auto FPDASetAndOpenPage = PreyFunction<void(ArkPDAComponent* const _this, const ArkPDAPage _page)>(0x172F570);
	static inline auto FPDASafeSetAndOpenPage = PreyFunction<void(ArkPDAComponent* const _this, const ArkPDAPage _page)>(0x172F550);
	static inline auto FPDASetTabAndToggle = PreyFunction<void(ArkPDAComponent* const _this, const ArkPDATab _tab)>(0x172F600);
	static inline auto FSetHealth = PreyFunction<void(ArkPDAComponent* const _this, float _fHealth, float _fMaxHealth, float _unreducedMaxHealth)>(0x17309C0);
	static inline auto FSetPsi = PreyFunction<void(ArkPDAComponent* const _this, float _psiPoints, float _maxPsiPoints, float _unreducedMaxPsiPoints, bool _bVisible)>(0x1730F00);
	static inline auto FSetArmor = PreyFunction<void(ArkPDAComponent* const _this, float _armor, float _max, bool _bVisible)>(0x1730820);
	static inline auto FUpdateDoomClock = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731B90);
	static inline auto FUpdateModule = PreyFunction<void(IUIModule* const _this, float _fDelta)>(0x1731E00);
	static inline auto FReload = PreyFunction<void(IUIModule* const _this)>(0x17302C0);
	static inline auto FSetIdleAction = PreyFunction<void(ArkPDAComponent* const _this, const char* const _idleFragmentName)>(0x1730BA0);
	static inline auto FCloseTranscribe = PreyFunction<void(ArkPDAComponent* const _this)>(0x172B270);
	static inline auto FPrepareOpen = PreyFunction<void(ArkPDAComponent* const _this)>(0x172F750);
	static inline auto FOnPressBack = PreyFunction<void(ArkPDAComponent* const _this)>(0x172E910);
	static inline auto FOnPressConfirm = PreyFunction<void(ArkPDAComponent* const _this)>(0x172E920);
	static inline auto FIsTabAvailable = PreyFunction<bool(const ArkPDAComponent* const _this, const ArkPDATab _tab)>(0x172E150);
	static inline auto FRefreshNew = PreyFunction<void(const ArkPDAComponent* const _this)>(0x172FB80);
	static inline auto FReset_Internal = PreyFunction<void(ArkPDAComponent* const _this)>(0x1730300);
	static inline auto FHideAttachment = PreyFunction<void(const ArkPDAComponent* const _this, const bool _bHide)>(0x172BC30);
	static inline auto FToggleMenu = PreyFunction<void(ArkPDAComponent* const _this, const bool _bOpen, const bool _bFromPause)>(0x1731570);
	static inline auto FSetupInputPrompts = PreyFunction<void(ArkPDAComponent* const _this, const bool _bForceUIUpdate)>(0x17310C0);
	static inline auto FOnOpenPage = PreyFunction<void(ArkPDAComponent* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E430);
	static inline auto FOnOpenTab = PreyFunction<void(ArkPDAComponent* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E7C0);
	static inline auto FOnPromptSelect = PreyFunction<void(ArkPDAComponent* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E950);
	static inline auto FUpdateUIPageEnabled = PreyFunction<void(const ArkPDAComponent* const _this)>(0x1732450);
	static inline auto FGetUIStringForPDAPage = PreyFunction<const char* (ArkPDAPage _page)>(0x172BB40);
	static inline auto FCycleTabs = PreyFunction<void(ArkPDAComponent* const _this, bool _bLeft)>(0x172B2C0);
	static inline auto FGetAvailableTabs = PreyFunction<std::vector<enum::ArkPDATab>*(const ArkPDAComponent* const _this, std::vector<enum::ArkPDATab>* _return_value_)>(0x172BA10);
	static inline auto FOpenTabPage = PreyFunction<void(ArkPDAComponent* const _this, ArkPDATab _tab)>(0x172F490);
	static inline auto FUpdateTabArray = PreyFunction<void(ArkPDAComponent* const _this)>(0x1731F80);
};
#endif // !MOONCRASH
