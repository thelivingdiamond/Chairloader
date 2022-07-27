// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class ArkOptionMenuBase;
class CCryName;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkUIOptionMenuBase.h
class ArkUIOptionMenuBase : public ArkUIMenuBase<ArkUIOptionMenuBase>, public std::enable_shared_from_this<ArkUIOptionMenuBase>, public IUIModule, public IBlockingActionListener, public IUIControlSchemeListener, public IUIGameEventSystem, public IArkActiveUserManagerListener // Id=8019132 Size=120
{
public:
	std::unique_ptr<ArkOptionMenuBase> m_pOptionsMenu;
	IUIElement *m_pUIElement;
	string m_UIElementName;
	string m_ModuleName;
	bool m_bQueueHide;
	int m_inputHandle;
	
	ArkUIOptionMenuBase(ArkOptionMenuBase *const _pOptionsMenu, const char *_elementName, const char *_moduleName);
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnUpdate(float fDelta);
	virtual bool OnAction(CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent);
	virtual void OnActiveUserIdChanged(unsigned __formal);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserSignedOut();
	virtual void Reload() = 0;
	virtual void Hide();
	virtual void QueueHide();
	void SetActionManagerState(bool _bEnable) { FSetActionManagerState(this,_bEnable); }
	void ShowResetDefaultsPrompt() { FShowResetDefaultsPrompt(this); }
	void ShowApplyChangesPrompt() { FShowApplyChangesPrompt(this); }
	void WriteGameCfg() { FWriteGameCfg(this); }
	void ShowBase() { FShowBase(this); }
	void OnConfirmReset() { FOnConfirmReset(this); }
	void OnCancelReset() { FOnCancelReset(this); }
	void OnConfirmApply() { FOnConfirmApply(this); }
	void OnCancelApply() { FOnCancelApply(this); }
	void OnSelectPage(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSelectPage(this,_pSender,_event,_args); }
	void OnSelectSubPage(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSelectSubPage(this,_pSender,_event,_args); }
	void OnSetAttribute(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSetAttribute(this,_pSender,_event,_args); }
	void OnIncrementOption(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnIncrementOption(this,_pSender,_event,_args); }
	void OnDecrementOption(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnDecrementOption(this,_pSender,_event,_args); }
	void OnSetOptionValue(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSetOptionValue(this,_pSender,_event,_args); }
	void OnBackPressed(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnBackPressed(this,_pSender,_event,_args); }
	void OnDropDownOpen(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnDropDownOpen(this,_pSender,_event,_args); }
	void OnDropDownItemSelected(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnDropDownItemSelected(this,_pSender,_event,_args); }
	virtual void OnMenuClose(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual void OnClickAttribute(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual void OnPressButton(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual bool IsActive();
	virtual ~ArkUIOptionMenuBase();
	
#if 0
	IUIElement *GetUIElement();
	bool IsVisible();
	ArkOptionMenuBase *GetOptionMenu();
	const char *GetUIElementName() const;
	const char *GetUIModuleName() const;
#endif
	
	static inline auto FInitEventSystem = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163E1A0);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163FAB0);
	static inline auto FOnUpdate = PreyFunction<void(ArkUIOptionMenuBase *const _this, float fDelta)>(0x163F380);
	static inline auto FOnAction = PreyFunction<bool(ArkUIOptionMenuBase *const _this, CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent)>(0x163E740);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(ArkUIOptionMenuBase *const _this, unsigned __formal)>(0xA13080);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(ArkUIOptionMenuBase *const _this, bool _bControllerDisconnect)>(0x163EAB0);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(ArkUIOptionMenuBase *const _this)>(0x163EB10);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0xA13080);
	static inline auto FHide = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163E130);
	static inline auto FQueueHide = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163F3D0);
	static inline auto FSetActionManagerState = PreyFunction<void(ArkUIOptionMenuBase *const _this, bool _bEnable)>(0x163F3E0);
	static inline auto FShowResetDefaultsPrompt = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163F870);
	static inline auto FShowApplyChangesPrompt = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163F550);
	static inline auto FWriteGameCfg = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163FB50);
	static inline auto FShowBase = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163F690);
	static inline auto FOnConfirmReset = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163EBD0);
	static inline auto FOnCancelReset = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163EB90);
	static inline auto FOnConfirmApply = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163EBA0);
	static inline auto FOnCancelApply = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x163EB60);
	static inline auto FOnSelectPage = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163F080);
	static inline auto FOnSelectSubPage = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163F130);
	static inline auto FOnSetAttribute = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163F1E0);
	static inline auto FOnIncrementOption = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163EFF0);
	static inline auto FOnDecrementOption = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163EDE0);
	static inline auto FOnSetOptionValue = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163F260);
	static inline auto FOnBackPressed = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163EB50);
	static inline auto FOnDropDownOpen = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163EF70);
	static inline auto FOnDropDownItemSelected = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163EE70);
	static inline auto FOnMenuClose = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0xA13080);
	static inline auto FOnClickAttribute = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0xA13080);
	static inline auto FOnPressButton = PreyFunction<void(ArkUIOptionMenuBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0xA13080);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkUIOptionMenuBase *const _this, EControlScheme _controlScheme)>(0x163EC00);
	static inline auto FIsActive = PreyFunction<bool(ArkUIOptionMenuBase *const _this)>(0x1B933B0);
	static inline auto FBitNotArkUIOptionMenuBase = PreyFunction<void(ArkUIOptionMenuBase *const _this)>(0x1633BD0);
};

