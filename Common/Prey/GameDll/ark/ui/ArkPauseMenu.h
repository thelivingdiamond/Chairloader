// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/ui/IArkOptionMenuListener.h>
#include <Prey/GameDll/ark/ui/IArkSaveLoadMenuListener.h>
#include <Prey/GameDll/ark/ui/IArkTutorialMenuListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/ui/IUIModule.h>

class ArkClass;
class ArkReflectedObject;
class CCryName;
struct IFlashPlayer;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/arkpausemenu.h
class ArkScoreCard : public ArkReflectedLibrary // Id=8019240 Size=32
{
public:
	class ArkGameMetricsProperty : public ArkProperty // Id=8019241 Size=32
	{
	public:
		ArkGameMetricsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkScoreCard::ArkGameMetricsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x136D900);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkScoreCard::ArkGameMetricsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x136D930);
		static inline auto FIsArray = PreyFunction<bool(ArkScoreCard::ArkGameMetricsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkScoreCard::ArkGameMetricsProperty const *const _this, ArkReflectedObject *_pObject)>(0x136D970);
	};

	static ArkScoreCard::ArkGameMetricsProperty s_ArkGameMetricsProperty;
	std::vector<unsigned __int64> m_GameMetrics;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkScoreCard();
	
#if 0
	std::vector<unsigned __int64> &GetGameMetrics();
	std::vector<unsigned __int64> const &GetGameMetrics() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x136E940);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x136E9A0);
	static inline auto FInit = PreyFunction<bool(ArkScoreCard *const _this)>(0x136EB50);
};

// Header: Exact
// Prey/GameDll/ark/ui/ArkPauseMenu.h
class ArkPauseMenu : public ArkUIMenuBase<ArkPauseMenu>, public IActionListener, public IUIGameEventSystem, public IUIControlSchemeListener, public IUIModule, public IArkOptionMenuListener, public IArkSaveLoadMenuListener, public IArkTutorialMenuListener, public IInputEventListener, public ISystemEventListener // Id=8019244 Size=120
{
public:
	enum class EArkPauseMode
	{
		disabled = 0,
		hidden = 1,
		menu = 2,
		continuePrompt = 3,
		scoreCard = 4,
	};

	IUIElement *m_pUIElement;
	ArkPauseMenu::EArkPauseMode m_mode;
	ArkPauseMenu::EArkPauseMode m_pendingMode;
	int m_inputMode;
	bool m_bLoadAvailable;
	bool m_bClosing;
	bool m_bPreTextureStreamerRunning;
	bool m_bCanSave;
	
	virtual ~ArkPauseMenu();
	virtual const char *GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void UpdateModule(float fDelta);
	virtual void Init();
	virtual void OnInit(IUIElement *_pSender, IFlashPlayer *_pFlashPlayer);
	virtual void OnSetVisible(IUIElement *_pSender, bool _bVisible);
	virtual void OnUnload(IUIElement *_pSender);
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual void OnOptionMenuClose();
	virtual void OnAction(CCryName const &_action, int _activationMode, float _value);
	virtual bool OnInputEvent(SInputEvent const &event);
	virtual void OnSaveLoadMenuClose(EArkSaveLoadMode _mode, bool _bLoading);
	virtual void OnLoadingStart();
	virtual void OnLoadSuccess();
	virtual bool OnLoadFail();
	virtual void OnTutorialMenuClose();
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	void SetMode(ArkPauseMenu::EArkPauseMode _nextMode) { FSetMode(this,_nextMode); }
	void ShowMenu() { FShowMenu(this); }
	void CloseMenu() { FCloseMenu(this); }
	void CloseContinuePrompt() { FCloseContinuePrompt(this); }
	void ShowScoreCard() { FShowScoreCard(this); }
	void OnPauseSelect(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnPauseSelect(this,_pSender,_event,_args); }
	void OnSummaryClose(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSummaryClose(this,_pSender,_event,_args); }
	void OnConfirmQuickLoad() { FOnConfirmQuickLoad(this); }
	void OnCancelQuickLoad() { FOnCancelQuickLoad(this); }
	void OnConfirmQuickLoadFailed() { FOnConfirmQuickLoadFailed(this); }
	void OnConfirmExitShell() const { FOnConfirmExitShell(this); }
	void OnConfirmExitDesktop() const { FOnConfirmExitDesktop(this); }
	void OnCancelExit() { FOnCancelExit(this); }
	void OpenSaveLoadMenu(bool _bSave) { FOpenSaveLoadMenu(this,_bSave); }
	void UpdateInputPrompts() const { FUpdateInputPrompts(this); }
	
	static inline const char* GetTypeNameS() { return "ArkPauseMenu"; }

#if 0
	void SetShowContinuePrompt(bool arg0);
	void SetShowScoreCard();
	bool IsOpen();
	void OnSaveDeletedBySystem();
	void QuickSave();
	void EnableActionMap(bool arg0);
	void HideMenu();
	void ShowContinuePrompt();
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkPauseMenu const *const _this)>(0x136EAF0);
	static inline auto FInitEventSystem = PreyFunction<void(ArkPauseMenu *const _this)>(0x136ED50);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkPauseMenu *const _this)>(0x1370F90);
	static inline auto FUpdateModule = PreyFunction<void(ArkPauseMenu *const _this, float fDelta)>(0x1371190);
	static inline auto FInit = PreyFunction<void(ArkPauseMenu *const _this)>(0x136EB00);
	static inline auto FOnInit = PreyFunction<void(ArkPauseMenu *const _this, IUIElement *_pSender, IFlashPlayer *_pFlashPlayer)>(0x136F600);
	static inline auto FOnSetVisible = PreyFunction<void(ArkPauseMenu *const _this, IUIElement *_pSender, bool _bVisible)>(0x136FF60);
	static inline auto FOnUnload = PreyFunction<void(ArkPauseMenu *const _this, IUIElement *_pSender)>(0x1370250);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkPauseMenu *const _this, EControlScheme _controlScheme)>(0x136F340);
	static inline auto FOnOptionMenuClose = PreyFunction<void(ArkPauseMenu *const _this)>(0x136F7D0);
	static inline auto FOnAction = PreyFunction<void(ArkPauseMenu *const _this, CCryName const &_action, int _activationMode, float _value)>(0x136EDF0);
	static inline auto FOnInputEvent = PreyFunction<bool(ArkPauseMenu *const _this, SInputEvent const &event)>(0x136F650);
	static inline auto FOnSaveLoadMenuClose = PreyFunction<void(ArkPauseMenu *const _this, EArkSaveLoadMode _mode, bool _bLoading)>(0x136FEA0);
	static inline auto FOnLoadingStart = PreyFunction<void(ArkPauseMenu *const _this)>(0x136F6D0);
	static inline auto FOnLoadSuccess = PreyFunction<void(ArkPauseMenu *const _this)>(0x136F680);
	static inline auto FOnLoadFail = PreyFunction<bool(ArkPauseMenu *const _this)>(0x162F4A0);
	static inline auto FOnTutorialMenuClose = PreyFunction<void(ArkPauseMenu *const _this)>(0x13701D0);
	static inline auto FOnSystemEvent = PreyFunction<void(ArkPauseMenu *const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x13701A0);
	static inline auto FSetMode = PreyFunction<void(ArkPauseMenu *const _this, ArkPauseMenu::EArkPauseMode _nextMode)>(0x13703A0);
	static inline auto FShowMenu = PreyFunction<void(ArkPauseMenu *const _this)>(0x1370560);
	static inline auto FCloseMenu = PreyFunction<void(ArkPauseMenu *const _this)>(0x136E8F0);
	static inline auto FCloseContinuePrompt = PreyFunction<void(ArkPauseMenu *const _this)>(0x136E7E0);
	static inline auto FShowScoreCard = PreyFunction<void(ArkPauseMenu *const _this)>(0x1370810);
	static inline auto FOnPauseSelect = PreyFunction<void(ArkPauseMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x136F8B0);
	static inline auto FOnSummaryClose = PreyFunction<void(ArkPauseMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1370140);
	static inline auto FOnConfirmQuickLoad = PreyFunction<void(ArkPauseMenu *const _this)>(0x136F150);
	static inline auto FOnCancelQuickLoad = PreyFunction<void(ArkPauseMenu *const _this)>(0x136EFA0);
	static inline auto FOnConfirmQuickLoadFailed = PreyFunction<void(ArkPauseMenu *const _this)>(0x136F2B0);
	static inline auto FOnConfirmExitShell = PreyFunction<void(ArkPauseMenu const *const _this)>(0x136F060);
	static inline auto FOnConfirmExitDesktop = PreyFunction<void(ArkPauseMenu const *const _this)>(0x136F020);
	static inline auto FOnCancelExit = PreyFunction<void(ArkPauseMenu *const _this)>(0x136EF20);
	static inline auto FOpenSaveLoadMenu = PreyFunction<void(ArkPauseMenu *const _this, bool _bSave)>(0x1370300);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkPauseMenu const *const _this)>(0x1371040);
};

