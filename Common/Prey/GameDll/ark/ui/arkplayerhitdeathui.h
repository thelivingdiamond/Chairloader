// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/ui/IArkSaveLoadMenuListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/IUIEventListener.h>

struct IUIElement;
struct IUIEventSystem;
struct SUIEvent;

// Header: Exact
// Prey/GameDll/ark/ui/arkplayerhitdeathui.h
class CArkPlayerHitDeathUI : public IUIEventListener, public IUIGameEventSystem, public ISystemEventListener, public IArkSaveLoadMenuListener, public IUIControlSchemeListener, public IUIElementEventListener // Id=801BBBC Size=176
{
public:
	enum EUIEvent
	{
		eDeathScreenTipEvent = 0,
	};

	IUIElement *m_pUIElement;
	unsigned m_systemReloadEventId;
	unsigned m_systemRestartEventId;
	unsigned m_systemOpenDeathScreenEditorEventId;
	unsigned m_systemOpenDeathScreenLauncherEventId;
	unsigned m_systemCloseDeathScreenEventId;
	unsigned m_systemUnloadDeathScreenEventId;
	unsigned m_systemTipEventId;
	IUIEventSystem *m_pUIToSystemEventSystem;
	IUIEventSystem *m_pSystemToUIEventSystem;
	SUIEventReceiverDispatcher<CArkPlayerHitDeathUI> m_eventDispatcher;
	SUIEventSenderDispatcher<enum CArkPlayerHitDeathUI::EUIEvent> m_eventSender;
	int m_inputHandle;
	bool m_bPauseOnClose;
	
	virtual ~CArkPlayerHitDeathUI();
	virtual const char *GetTypeName() const;
	virtual SUIArguments OnEvent(SUIEvent const &_event);
	virtual void OnEventSystemDestroyed(IUIEventSystem *_pEventSystem);
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	virtual void OnSaveLoadMenuClose(EArkSaveLoadMode _mode, bool _bLoading);
	virtual void OnLoadingStart();
	virtual void OnLoadSuccess();
	virtual bool OnLoadFail();
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual void OnSetVisible(IUIElement *_pSender, bool _bVisible);
	void HandleOpenDeathScreen() { FHandleOpenDeathScreen(this); }
	void HandleDeathScreenQuit() { FHandleDeathScreenQuit(this); }
	void HandleDeathScreenReload() { FHandleDeathScreenReload(this); }
	void HandleDeathScreenRestart() { FHandleDeathScreenRestart(this); }
	void HandleDeathScreenRevivePlayer() { FHandleDeathScreenRevivePlayer(this); }
	void HandleDeathScreenLoadGame() { FHandleDeathScreenLoadGame(this); }
	void HandleStartClosingDeathScreen() { FHandleStartClosingDeathScreen(this); }
	void InvokeUIEvent(SUIEvent const &_event) const { FInvokeUIEvent(this,_event); }
	void OnDeathScreenCloseCompleted() { FOnDeathScreenCloseCompleted(this); }
	void UpdateInputPrompts() const { FUpdateInputPrompts(this); }
	void ShowLoadGameError(const char *_errorText) const { FShowLoadGameError(this,_errorText); }
	
#if 0
	static const char *GetTypeNameS();
	bool IsOpen();
	void SetPauseOnClose();
	static const char *UIToSystemEventSystemName();
	static const char *SystemToUIEventSystemName();
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(CArkPlayerHitDeathUI const *const _this)>(0x162D930);
	static inline auto FOnEvent = PreyFunction<SUIArguments(CArkPlayerHitDeathUI *const _this, SUIEvent const &_event)>(0x162F450);
	static inline auto FOnEventSystemDestroyed = PreyFunction<void(CArkPlayerHitDeathUI *const _this, IUIEventSystem *_pEventSystem)>(0x162F480);
	static inline auto FInitEventSystem = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162E280);
	static inline auto FUnloadEventSystem = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162F940);
	static inline auto FOnSystemEvent = PreyFunction<void(CArkPlayerHitDeathUI *const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x162F790);
	static inline auto FOnSaveLoadMenuClose = PreyFunction<void(CArkPlayerHitDeathUI *const _this, EArkSaveLoadMode _mode, bool _bLoading)>(0x162F6C0);
	static inline auto FOnLoadingStart = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162F620);
	static inline auto FOnLoadSuccess = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162F4D0);
	static inline auto FOnLoadFail = PreyFunction<bool(CArkPlayerHitDeathUI *const _this)>(0x162F4A0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(CArkPlayerHitDeathUI *const _this, EControlScheme _controlScheme)>(0x162F390);
	static inline auto FOnSetVisible = PreyFunction<void(CArkPlayerHitDeathUI *const _this, IUIElement *_pSender, bool _bVisible)>(0x162F720);
	static inline auto FHandleOpenDeathScreen = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162DF50);
	static inline auto FHandleDeathScreenQuit = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162DA40);
	static inline auto FHandleDeathScreenReload = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162DB30);
	static inline auto FHandleDeathScreenRestart = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162DD00);
	static inline auto FHandleDeathScreenRevivePlayer = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162DF00);
	static inline auto FHandleDeathScreenLoadGame = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162D940);
	static inline auto FHandleStartClosingDeathScreen = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162E220);
	static inline auto FInvokeUIEvent = PreyFunction<void(CArkPlayerHitDeathUI const *const _this, SUIEvent const &_event)>(0x162F2F0);
	static inline auto FOnDeathScreenCloseCompleted = PreyFunction<void(CArkPlayerHitDeathUI *const _this)>(0x162F3F0);
	static inline auto FUpdateInputPrompts = PreyFunction<void(CArkPlayerHitDeathUI const *const _this)>(0x162F980);
	static inline auto FShowLoadGameError = PreyFunction<void(CArkPlayerHitDeathUI const *const _this, const char *_errorText)>(0x162F840);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/IFlashUI.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/IArkSaveLoadMenuListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <_unknown/SUIEventSenderDispatcher.h>

enum class EArkSaveLoadMode;
enum EControlScheme;
enum ESystemEvent;
struct IUIElement;
struct IUIEventSystem;
struct SUIArguments;
struct SUIEvent;

// CArkPlayerHitDeathUI
// Header:  Prey/GameDll/ark/ui/ArkPlayerHitDeathUI.h
class CArkPlayerHitDeathUI
	: public IUIEventListener
	, public IUIGameEventSystem
	, public ISystemEventListener
	, public IArkSaveLoadMenuListener
	, public IUIControlSchemeListener
	, public IUIElementEventListener
{ // Size=176 (0xB0)
public:
	enum EUIEvent
	{
		eDeathScreenTipEvent = 0,
	};

	IUIElement* m_pUIElement;
	unsigned m_systemReloadEventId;
	unsigned m_systemRestartEventId;
	unsigned m_systemOpenDeathScreenEditorEventId;
	unsigned m_systemOpenDeathScreenLauncherEventId;
	unsigned m_systemCloseDeathScreenEventId;
	unsigned m_systemUnloadDeathScreenEventId;
	unsigned m_systemTipEventId;
	IUIEventSystem* m_pUIToSystemEventSystem;
	IUIEventSystem* m_pSystemToUIEventSystem;
	SUIEventReceiverDispatcher<CArkPlayerHitDeathUI> m_eventDispatcher;
	SUIEventSenderDispatcher<enum CArkPlayerHitDeathUI::EUIEvent> m_eventSender;
	int m_inputHandle;
	bool m_bPauseOnClose;

	virtual ~CArkPlayerHitDeathUI();
	virtual const char* GetTypeName() const;
	virtual SUIArguments OnEvent(const SUIEvent& _event);
	virtual void OnEventSystemDestroyed(IUIEventSystem* _pEventSystem);
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	virtual void OnSaveLoadMenuClose(EArkSaveLoadMode _mode, bool _bLoading);
	virtual void OnLoadingStart();
	virtual void OnLoadSuccess();
	virtual bool OnLoadFail();
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	virtual void OnSetVisible(IUIElement* _pSender, bool _bVisible);
	void HandleOpenDeathScreen() { FHandleOpenDeathScreen(this); }
	void HandleDeathScreenQuit() { FHandleDeathScreenQuit(this); }
	void HandleDeathScreenReload() { FHandleDeathScreenReload(this); }
	void HandleDeathScreenRestart() { FHandleDeathScreenRestart(this); }
	void HandleDeathScreenRevivePlayer() { FHandleDeathScreenRevivePlayer(this); }
	void HandleDeathScreenLoadGame() { FHandleDeathScreenLoadGame(this); }
	void HandleStartClosingDeathScreen() { FHandleStartClosingDeathScreen(this); }
	void InvokeUIEvent(const SUIEvent& _event) const { FInvokeUIEvent(this, _event); }
	void OnDeathScreenCloseCompleted() { FOnDeathScreenCloseCompleted(this); }
	void UpdateInputPrompts() const { FUpdateInputPrompts(this); }
	void ShowLoadGameError(const char* _errorText) const { FShowLoadGameError(this, _errorText); }

#if 0
	CArkPlayerHitDeathUI();
	static const char* GetTypeNameS();
	bool IsOpen();
	void SetPauseOnClose();
	static const char* UIToSystemEventSystemName();
	static const char* SystemToUIEventSystemName();
#endif

	static inline auto FGetTypeName = PreyFunction<const char* (const IUIGameEventSystem* const _this)>(0x17500A0);
	static inline auto FOnEvent = PreyFunction<SUIArguments*(CArkPlayerHitDeathUI* const _this, SUIArguments* _return_value_, const SUIEvent& _event)>(0x1751BD0);
	static inline auto FOnEventSystemDestroyed = PreyFunction<void(CArkPlayerHitDeathUI* const _this, IUIEventSystem* _pEventSystem)>(0x1751C00);
	static inline auto FInitEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x1750A00);
	static inline auto FUnloadEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x17520C0);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x1751F10);
	static inline auto FOnSaveLoadMenuClose = PreyFunction<void(IArkSaveLoadMenuListener* const _this, EArkSaveLoadMode _mode, bool _bLoading)>(0x1751E40);
	static inline auto FOnLoadingStart = PreyFunction<void(IArkSaveLoadMenuListener* const _this)>(0x1751DA0);
	static inline auto FOnLoadSuccess = PreyFunction<void(IArkSaveLoadMenuListener* const _this)>(0x1751C50);
	static inline auto FOnLoadFail = PreyFunction<bool(IArkSaveLoadMenuListener* const _this)>(0x1751C20);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x1751B10);
	static inline auto FOnSetVisible = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* _pSender, bool _bVisible)>(0x1751EA0);
	static inline auto FHandleOpenDeathScreen = PreyFunction<void(CArkPlayerHitDeathUI* const _this)>(0x17506C0);
	static inline auto FHandleDeathScreenQuit = PreyFunction<void(CArkPlayerHitDeathUI* const _this)>(0x17501B0);
	static inline auto FHandleDeathScreenReload = PreyFunction<void(CArkPlayerHitDeathUI* const _this)>(0x17502A0);
	static inline auto FHandleDeathScreenRestart = PreyFunction<void(CArkPlayerHitDeathUI* const _this)>(0x1750470);
	static inline auto FHandleDeathScreenRevivePlayer = PreyFunction<void(CArkPlayerHitDeathUI* const _this)>(0x1750670);
	static inline auto FHandleDeathScreenLoadGame = PreyFunction<void(CArkPlayerHitDeathUI* const _this)>(0x17500B0);
	static inline auto FHandleStartClosingDeathScreen = PreyFunction<void(CArkPlayerHitDeathUI* const _this)>(0x17509A0);
	static inline auto FInvokeUIEvent = PreyFunction<void(const CArkPlayerHitDeathUI* const _this, const SUIEvent& _event)>(0x1751A70);
	static inline auto FOnDeathScreenCloseCompleted = PreyFunction<void(CArkPlayerHitDeathUI* const _this)>(0x1751B70);
	static inline auto FUpdateInputPrompts = PreyFunction<void(const CArkPlayerHitDeathUI* const _this)>(0x1752100);
	static inline auto FShowLoadGameError = PreyFunction<void(const CArkPlayerHitDeathUI* const _this, const char* _errorText)>(0x1751FC0);
};
#endif // !MOONCRASH
