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

