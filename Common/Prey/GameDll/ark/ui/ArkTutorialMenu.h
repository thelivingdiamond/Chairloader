// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class CCryName;
class IArkTutorialMenuListener;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/ArkTutorialMenu.h
class ArkTutorialMenu : public ArkUIMenuBase<ArkTutorialMenu>, public std::enable_shared_from_this<ArkTutorialMenu>, public IUIModule, public IUIGameEventSystem, public IBlockingActionListener, public IUIControlSchemeListener, public IArkActiveUserManagerListener // Id=8019219 Size=96
{
public:
	IArkTutorialMenuListener *m_pOpener;
	uint64_t m_currentTutorial;
	
	virtual ~ArkTutorialMenu();
	virtual const char *GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual bool OnAction(CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent);
	void Open(IArkTutorialMenuListener *_pListener) { FOpen(this,_pListener); }
	void Close() { FClose(this); }
	void OnTutorialSelected(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnTutorialSelected(this,_pSender,_event,_args); }
	void OnBackPressed(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnBackPressed(this,_pSender,_event,_args); }
	virtual void OnActiveUserIdChanged(unsigned platformUserId);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserSignedOut();
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	void OnTutorialCardClosed() { FOnTutorialCardClosed(this); }
	void UpdateInputPrompts() const { FUpdateInputPrompts(this); }
	virtual IUIElement *GetUIElement() const;
	
#if 0
	static const char *GetTypeNameS();
	bool IsOpen() const;
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkTutorialMenu const *const _this)>(0x134FC70);
	static inline auto FInitEventSystem = PreyFunction<void(ArkTutorialMenu *const _this)>(0x134FCA0);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkTutorialMenu *const _this)>(0x1350960);
	static inline auto FOnAction = PreyFunction<bool(ArkTutorialMenu *const _this, CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent)>(0x134FD10);
	static inline auto FOpen = PreyFunction<void(ArkTutorialMenu *const _this, IArkTutorialMenuListener *_pListener)>(0x1350480);
	static inline auto FClose = PreyFunction<void(ArkTutorialMenu *const _this)>(0x134FA60);
	static inline auto FOnTutorialSelected = PreyFunction<void(ArkTutorialMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1350220);
	static inline auto FOnBackPressed = PreyFunction<void(ArkTutorialMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x134FE80);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(ArkTutorialMenu *const _this, unsigned platformUserId)>(0xA13080);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(ArkTutorialMenu *const _this, bool _bControllerDisconnect)>(0x134FE20);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(ArkTutorialMenu *const _this)>(0xDD23F0);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(ArkTutorialMenu *const _this)>(0xA13080);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkTutorialMenu *const _this, EControlScheme _controlScheme)>(0x134FE90);
	static inline auto FOnTutorialCardClosed = PreyFunction<void(ArkTutorialMenu *const _this)>(0x13501E0);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkTutorialMenu const *const _this)>(0x13509F0);
	static inline auto FGetUIElement = PreyFunction<IUIElement *(ArkTutorialMenu const *const _this)>(0x134FC80);
};

