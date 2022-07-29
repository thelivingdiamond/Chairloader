// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/GameDll/ark/iface/IArkGameLoadSaveListener.h>
#include <Prey/GameDll/ark/player/IArkEntitlementListener.h>
#include <Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h>
#include <Prey/GameDll/ark/ui/IArkDebugMenuListener.h>
#include <Prey/GameDll/ark/ui/IArkOptionMenuListener.h>
#include <Prey/GameDll/ark/ui/IArkSaveLoadMenuListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/iface/ISaveGameEnumerator.h>

class ArkActiveUserManagerBase;
class CCryName;
struct IFlashPlayer;
struct ISaveGameEnumerator;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/ArkLauncherMenu.h
class ArkLauncherMenu : public ArkUIMenuBase<ArkLauncherMenu>, public std::enable_shared_from_this<ArkLauncherMenu>, public IBlockingActionListener, public IUIGameEventSystem, public IUIControlSchemeListener, public IUIModule, public IArkOptionMenuListener, public IInputEventListener, public IArkDebugMenuListener, public IArkSaveLoadMenuListener, public IArkGameLoadSaveListener, public IArkEntitlementListener // Id=80191F1 Size=152
{
public:
	enum class EArkShellMode
	{
		disabled = 0,
		hidden = 1,
		attract = 2,
		menu = 3,
		loadTransition = 4,
		store = 5,
	};

	enum class EArkLoadState
	{
		lastSave = 0,
		newGame = 1,
		stagingArea = 2,
		loadOnUpdate = 3,
	};

	IUIElement *m_pUIElement;
	ArkLauncherMenu::EArkShellMode m_mode;
	ArkLauncherMenu::EArkLoadState m_loadState;
	ArkBinkPlayerHandle m_binkHandle;
	EArkLoadDisconnectReason m_loadDisconnectReason;
	bool m_bShowAttract;
	bool m_bSendPreviewMetadata;
	
	virtual const char *GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void Init();
	virtual void UpdateModule(float _fDelta);
	virtual void OnInit(IUIElement *_pSender, IFlashPlayer *_pFlashPlayer);
	virtual void OnSetVisible(IUIElement *_pSender, bool _bVisible);
	virtual void OnUnload(IUIElement *_pSender);
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual void OnOptionMenuClose();
	virtual bool OnAction(CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent);
	virtual bool OnInputEvent(SInputEvent const &event);
	virtual void OnToggleDebugMenu(bool _bEnable);
	virtual void OnSaveLoadMenuClose(EArkSaveLoadMode _mode, bool _bLoading);
	virtual void OnLoadingStart();
	virtual void OnLoadSuccess();
	virtual bool OnLoadFail();
	virtual void OnLoadSaveError(ELoadGameResult _result);
	void StartBackgroundBink() { FStartBackgroundBink(this); }
	void StopBackgroundBink() { FStopBackgroundBink(this); }
	virtual void OnEntitlementChanged(uint64_t _entitlement, bool _bGranted);
	void SetMode(ArkLauncherMenu::EArkShellMode _nextMode) { FSetMode(this,_nextMode); }
	void ContinueLastSave() { FContinueLastSave(this); }
	void ShowMenu() { FShowMenu(this); }
	void UpdateAttractText() const { FUpdateAttractText(this); }
	void HideAttract() const { FHideAttract(this); }
	void SendPreviewMetadata(ISaveGameEnumerator::SGameDescription const &_desc, unsigned _campaignSlot) { FSendPreviewMetadata(this,_desc,_campaignSlot); }
	void OpenCampaignMenu(bool _bNewGame, bool _bNewGamePlus) { FOpenCampaignMenu(this,_bNewGame,_bNewGamePlus); }
	void OnMainMenuHighlight(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnMainMenuHighlight(this,_pSender,_event,_args); }
	void OnMainMenuSelect(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnMainMenuSelect(this,_pSender,_event,_args); }
	void OnSavePreviewSelect(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSavePreviewSelect(this,_pSender,_event,_args); }
	void OnLoadTransitionComplete(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnLoadTransitionComplete(this,_pSender,_event,_args); }
	void OnConfirmExit() const { FOnConfirmExit(this); }
	void OnCancelExit() { FOnCancelExit(this); }
	void OnCloseLoadErrorPopup() { FOnCloseLoadErrorPopup(this); }
	void OnCloseLoadErrorDisconnectPopup() { FOnCloseLoadErrorDisconnectPopup(this); }
	void OnReturnToMainMenu(const char *const _highlightID) { FOnReturnToMainMenu(this,_highlightID); }
	void SetMainMenuMode(const char *const _highlightID) { FSetMainMenuMode(this,_highlightID); }
	void UpdateInputPrompts() const { FUpdateInputPrompts(this); }
	virtual ~ArkLauncherMenu();
	
#if 0
	static const char *GetTypeNameS();
	void SetShowAttract(const bool arg0);
	void SetLoadDisconnectReason(EArkLoadDisconnectReason arg0);
	void OnActiveUserRemoved(ArkActiveUserManagerBase::EArkReason arg0);
	void OnReengagementComplete();
	bool IsVisible() const;
	void OnSaveDeletedBySystem();
	void LoadProfile() const;
	void EnableActionMap(bool arg0) const;
	void HideMenu();
	void ShowAttract() const;
	void ShowPreviewPane();
	void HidePreviewPane() const;
	void ShowLoadDisconnectError(EArkLoadDisconnectReason arg0);
	void OnCloseLoadDisconnectErrorPopup();
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkLauncherMenu const *const _this)>(0x135CBC0);
	static inline auto FInitEventSystem = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135CE50);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135F300);
	static inline auto FInit = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135CE00);
	static inline auto FUpdateModule = PreyFunction<void(ArkLauncherMenu *const _this, float _fDelta)>(0x135F870);
	static inline auto FOnInit = PreyFunction<void(ArkLauncherMenu *const _this, IUIElement *_pSender, IFlashPlayer *_pFlashPlayer)>(0x135D250);
	static inline auto FOnSetVisible = PreyFunction<void(ArkLauncherMenu *const _this, IUIElement *_pSender, bool _bVisible)>(0x135E000);
	static inline auto FOnUnload = PreyFunction<void(ArkLauncherMenu *const _this, IUIElement *_pSender)>(0x135E4A0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkLauncherMenu *const _this, EControlScheme _controlScheme)>(0x135D1B0);
	static inline auto FOnOptionMenuClose = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135DD20);
	static inline auto FOnAction = PreyFunction<bool(ArkLauncherMenu *const _this, CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent)>(0x135CEC0);
	static inline auto FOnInputEvent = PreyFunction<bool(ArkLauncherMenu *const _this, SInputEvent const &event)>(0x135D350);
	static inline auto FOnToggleDebugMenu = PreyFunction<void(ArkLauncherMenu *const _this, bool _bEnable)>(0x135E330);
	static inline auto FOnSaveLoadMenuClose = PreyFunction<void(ArkLauncherMenu *const _this, EArkSaveLoadMode _mode, bool _bLoading)>(0x135DEA0);
	static inline auto FOnLoadingStart = PreyFunction<void(ArkLauncherMenu *const _this)>(0xA13080);
	static inline auto FOnLoadSuccess = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135D500);
	static inline auto FOnLoadFail = PreyFunction<bool(ArkLauncherMenu *const _this)>(0x1B933B0);
	static inline auto FOnLoadSaveError = PreyFunction<void(ArkLauncherMenu *const _this, ELoadGameResult _result)>(0x135D380);
	static inline auto FStartBackgroundBink = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135F250);
	static inline auto FStopBackgroundBink = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135F2B0);
	static inline auto FOnEntitlementChanged = PreyFunction<void(ArkLauncherMenu *const _this, uint64_t _entitlement, bool _bGranted)>(0x135D230);
	static inline auto FSetMode = PreyFunction<void(ArkLauncherMenu *const _this, ArkLauncherMenu::EArkShellMode _nextMode)>(0x135EA20);
	static inline auto FContinueLastSave = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135CB10);
	static inline auto FShowMenu = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135EBB0);
	static inline auto FUpdateAttractText = PreyFunction<void(ArkLauncherMenu const *const _this)>(0x135F3A0);
	static inline auto FHideAttract = PreyFunction<void(ArkLauncherMenu const *const _this)>(0x135CBD0);
	static inline auto FSendPreviewMetadata = PreyFunction<void(ArkLauncherMenu *const _this, ISaveGameEnumerator::SGameDescription const &_desc, unsigned _campaignSlot)>(0x135E6F0);
	static inline auto FOpenCampaignMenu = PreyFunction<void(ArkLauncherMenu *const _this, bool _bNewGame, bool _bNewGamePlus)>(0x135E5E0);
	static inline auto FOnMainMenuHighlight = PreyFunction<void(ArkLauncherMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x135D610);
	static inline auto FOnMainMenuSelect = PreyFunction<void(ArkLauncherMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x135D810);
	static inline auto FOnSavePreviewSelect = PreyFunction<void(ArkLauncherMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x135DF20);
	static inline auto FOnLoadTransitionComplete = PreyFunction<void(ArkLauncherMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x135D540);
	static inline auto FOnConfirmExit = PreyFunction<void(ArkLauncherMenu const *const _this)>(0x17FADE0);
	static inline auto FOnCancelExit = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135D0B0);
	static inline auto FOnCloseLoadErrorPopup = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135D1A0);
	static inline auto FOnCloseLoadErrorDisconnectPopup = PreyFunction<void(ArkLauncherMenu *const _this)>(0x135D0C0);
	static inline auto FOnReturnToMainMenu = PreyFunction<void(ArkLauncherMenu *const _this, const char *const _highlightID)>(0x135DD80);
	static inline auto FSetMainMenuMode = PreyFunction<void(ArkLauncherMenu *const _this, const char *const _highlightID)>(0x135E7C0);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkLauncherMenu const *const _this)>(0x135F750);
};

