// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/iactionmapmanager.h>
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryCore/Platform/IPlatformOS.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <_unknown/SUIEventReceiverDispatcher.h>
#include <_unknown/SUIEventSenderDispatcher.h>

class CCryName;
enum ESystemEvent;
struct IUIEventSystem;
struct SInputEvent;

// CUIInput
// Header:  Prey/GameDll/ui/UIInput.h
class CUIInput
	: public IUIGameEventSystem
	, public IBlockingActionListener
	, public IVirtualKeyboardEvents
	, public std::enable_shared_from_this<CUIInput>
	, public ISystemEventListener
{ // Size=152 (0x98)
public:
	enum EUIEvent
	{
		eUIE_OnVirtKeyboardDone = 0,
		eUIE_OnVirtKeyboardCancelled = 1,
		eUIE_OnExclusiveControllerDisconnected = 2,
	};

	SUIEventReceiverDispatcher<CUIInput> m_eventDispatcher;
	SUIEventSenderDispatcher<enum CUIInput::EUIEvent> m_eventSender;
	IUIEventSystem* m_pUIEvents;
	IUIEventSystem* m_pUIFunctions;
	static inline auto s_actionHandler = PreyGlobal<TActionHandler<CUIInput>>(0x2D93990);
	std::map<enum::CUIInput::EUIEvent, unsigned int> m_eventMap;
	bool m_bHasFocus;
	static inline auto g_pauseOnLoseFocus = PreyGlobal<int>(0x23F2BF0);

	virtual ~CUIInput();
	static void Shutdown() { FShutdown(); }
	virtual const char* GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	virtual bool OnAction(const CCryName& action, int activationMode, float value, const SInputEvent& inputEvent);
	virtual void KeyboardCancelled();
	virtual void KeyboardFinished(const wchar_t* pInString);
	void OpenPauseMenu(bool _open) { FOpenPauseMenu(this, _open); }
	void OnDisplayVirtualKeyboard(const wchar_t* title, const wchar_t* initialStr, int maxchars) { FOnDisplayVirtualKeyboard(this, title, initialStr, maxchars); }
	bool OnActionTogglePause(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionTogglePause(this, entityId, actionId, activationMode, value); }
	bool OnActionStartPause(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionStartPause(this, entityId, actionId, activationMode, value); }
	bool OnActionUp(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionUp(this, entityId, actionId, activationMode, value); }
	bool OnActionDown(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionDown(this, entityId, actionId, activationMode, value); }
	bool OnActionLeft(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionLeft(this, entityId, actionId, activationMode, value); }
	bool OnActionRight(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionRight(this, entityId, actionId, activationMode, value); }
	bool OnActionClick(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionClick(this, entityId, actionId, activationMode, value); }
	bool OnActionBack(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionBack(this, entityId, actionId, activationMode, value); }
	bool OnActionConfirm(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionConfirm(this, entityId, actionId, activationMode, value); }
	bool OnActionReset(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionReset(this, entityId, actionId, activationMode, value); }
	bool OnActionToggleDebug(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionToggleDebug(this, entityId, actionId, activationMode, value); }
	bool OnActionEditorPause(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionEditorPause(this, entityId, actionId, activationMode, value); }
	bool OnActionEditorResume(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionEditorResume(this, entityId, actionId, activationMode, value); }
	bool OnActionReportBug(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionReportBug(this, entityId, actionId, activationMode, value); }
	bool OnActionOpenLog(unsigned entityId, const CCryName& actionId, int activationMode, float value) { return FOnActionOpenLog(this, entityId, actionId, activationMode, value); }

#if 0
	CUIInput();
	static const char* GetTypeNameS();
	void OnActionInput(const CCryName& _arg0_, int _arg1_, float _arg2_);
	void ExclusiveControllerDisconnected();
	bool HasFocus() const;
#endif

	static inline auto FShutdown = PreyFunction<void()>(0x1925140);
	static inline auto FGetTypeName = PreyFunction<const char* (const CUIInput* const _this)>(0x1923770);
	static inline auto FInitEventSystem = PreyFunction<void(CUIInput* const _this)>(0x1923780);
	static inline auto FUnloadEventSystem = PreyFunction<void(CUIInput* const _this)>(0x1925190);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x1924FA0);
	static inline auto FOnAction = PreyFunction<bool(IBlockingActionListener* const _this, const CCryName& action, int activationMode, float value, const SInputEvent& inputEvent)>(0x19249B0);
	static inline auto FKeyboardCancelled = PreyFunction<void(IVirtualKeyboardEvents* const _this)>(0x1924790);
	static inline auto FKeyboardFinished = PreyFunction<void(IVirtualKeyboardEvents* const _this, const wchar_t* pInString)>(0x1924890);
	static inline auto FOpenPauseMenu = PreyFunction<void(CUIInput* const _this, bool _open)>(0x19250C0);
	static inline auto FOnDisplayVirtualKeyboard = PreyFunction<void(CUIInput* const _this, const wchar_t* title, const wchar_t* initialStr, int maxchars)>(0x1924F50);
	static inline auto FOnActionTogglePause = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924E70);
	static inline auto FOnActionStartPause = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924DE0);
	static inline auto FOnActionUp = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924EE0);
	static inline auto FOnActionDown = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924B30);
	static inline auto FOnActionLeft = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924C40);
	static inline auto FOnActionRight = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924D70);
	static inline auto FOnActionClick = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924A50);
	static inline auto FOnActionBack = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x19249E0);
	static inline auto FOnActionConfirm = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924AC0);
	static inline auto FOnActionReset = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924D00);
	static inline auto FOnActionToggleDebug = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924E50);
	static inline auto FOnActionEditorPause = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924BA0);
	static inline auto FOnActionEditorResume = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924BF0);
	static inline auto FOnActionReportBug = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1A302A0);
	static inline auto FOnActionOpenLog = PreyFunction<bool(CUIInput* const _this, unsigned entityId, const CCryName& actionId, int activationMode, float value)>(0x1924CB0);
};
#endif // MOONCRASH
