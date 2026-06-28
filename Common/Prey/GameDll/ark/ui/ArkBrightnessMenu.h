// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/ui/IUIModule.h>

class ArkOptionMenu;
class CCryName;
struct ICVar;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/ArkBrightnessMenu.h
class ArkBrightnessMenu : public ArkUIMenuBase<ArkBrightnessMenu>, public std::enable_shared_from_this<ArkBrightnessMenu>, public IBlockingActionListener, public IUIGameEventSystem, public IUIControlSchemeListener, public IUIModule, public IArkActiveUserManagerListener // Id=801B925 Size=112
{
public:
	IUIElement *m_pUIElement;
	ArkOptionMenu *m_pOptionMenu;
	ICVar *m_pBrightnessCVar;
	float m_fInitialBrightness;
	int m_brightness;
	
	virtual const char *GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void Init();
	virtual void UpdateModule(float _fDelta);
	virtual void OnSetVisible(IUIElement *pSender, bool bVisible);
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual bool OnAction(CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent);
	virtual void OnActiveUserIdChanged(unsigned );
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserSignedOut();
	void ShowMenu(ArkOptionMenu *_pOptionMenu) { FShowMenu(this,_pOptionMenu); }
	void ApplyBrightnessUI(const float _fBrightness) const { FApplyBrightnessUI(this,_fBrightness); }
	static void OnSetBrightness(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event) { FOnSetBrightness(__this,_pSender,_event); }
	static void OnCloseMenu(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event) { FOnCloseMenu(__this,_pSender,_event); }
	static void OnMenuTransitionOut(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event) { FOnMenuTransitionOut(__this,_pSender,_event); }
	static void OnButtonPress(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event) { FOnButtonPress(__this,_pSender,_event); }
	static void OnPressBack(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event) { FOnPressBack(__this,_pSender,_event); }
	virtual ~ArkBrightnessMenu();
	
#if 0
	static const char *GetTypeNameS();
	void ResetAndExit();
	void ExitMenu();
	void HideMenu();
	void UpdateBrightness(const float arg0);
	void UpdateInputPrompts() const;
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkBrightnessMenu const *const _this)>(0x1344CA0);
	static inline auto FInitEventSystem = PreyFunction<void(ArkBrightnessMenu *const _this)>(0x1344D00);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkBrightnessMenu *const _this)>(0x1345C50);
	static inline auto FInit = PreyFunction<void(ArkBrightnessMenu *const _this)>(0x1344CB0);
	static inline auto FUpdateModule = PreyFunction<void(ArkBrightnessMenu *const _this, float _fDelta)>(0x1345CF0);
	static inline auto FOnSetVisible = PreyFunction<void(ArkBrightnessMenu *const _this, IUIElement *pSender, bool bVisible)>(0x1345620);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkBrightnessMenu *const _this, EControlScheme _controlScheme)>(0x1345130);
	static inline auto FOnAction = PreyFunction<bool(ArkBrightnessMenu *const _this, CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent)>(0x1344D90);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(ArkBrightnessMenu *const _this, unsigned )>(0xA13080);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(ArkBrightnessMenu *const _this, bool _bControllerDisconnect)>(0x1344E90);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(ArkBrightnessMenu *const _this)>(0x1344F80);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(ArkBrightnessMenu *const _this)>(0xA13080);
	static inline auto FShowMenu = PreyFunction<void(ArkBrightnessMenu *const _this, ArkOptionMenu *_pOptionMenu)>(0x13457C0);
	static inline auto FApplyBrightnessUI = PreyFunction<void(ArkBrightnessMenu const *const _this, const float _fBrightness)>(0x1344B40);
	static inline auto FOnSetBrightness = PreyFunction<void(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event)>(0x1345560);
	static inline auto FOnCloseMenu = PreyFunction<void(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event)>(0x1345550);
	static inline auto FOnMenuTransitionOut = PreyFunction<void(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event)>(0x1345540);
	static inline auto FOnButtonPress = PreyFunction<void(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event)>(0x1345060);
	static inline auto FOnPressBack = PreyFunction<void(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event)>(0x1345550);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class ArkOptionMenu;
class CCryName;
enum EControlScheme;
struct ICVar;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// ArkBrightnessMenu
// Header:  Prey/GameDll/ark/ui/ArkBrightnessMenu.h
class ArkBrightnessMenu
	: public ArkUIMenuBase<ArkBrightnessMenu>
	, public std::enable_shared_from_this<ArkBrightnessMenu>
	, public IBlockingActionListener
	, public IUIGameEventSystem
	, public IUIControlSchemeListener
	, public IUIModule
	, public IArkActiveUserManagerListener
{ // Size=112 (0x70)
public:
	IUIElement* m_pUIElement;
	ArkOptionMenu* m_pOptionMenu;
	ICVar* m_pBrightnessCVar;
	float m_fInitialBrightness;
	int m_brightness;

	virtual const char* GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void Init();
	virtual void UpdateModule(float _fDelta);
	virtual void OnSetVisible(IUIElement* pSender, bool bVisible);
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	virtual bool OnAction(const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent);
	virtual void OnActiveUserIdChanged(unsigned __unnamed1);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserSignedOut();
	void ShowMenu(ArkOptionMenu* _pOptionMenu) { FShowMenu(this, _pOptionMenu); }
	void ApplyBrightnessUI(const float _fBrightness) const { FApplyBrightnessUI(this, _fBrightness); }
	static void OnSetBrightness(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnSetBrightness(_pSender, _event, _args); }
	static void OnCloseMenu(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnCloseMenu(_pSender, _event, _args); }
	static void OnMenuTransitionOut(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnMenuTransitionOut(_pSender, _event, _args); }
	static void OnButtonPress(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnButtonPress(_pSender, _event, _args); }
	static void OnPressBack(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPressBack(_pSender, _event, _args); }

#if 0
	ArkBrightnessMenu();
	static const char* GetTypeNameS();
	void ResetAndExit();
	void ExitMenu();
	void HideMenu();
	void UpdateBrightness(const float _arg0_);
	void UpdateInputPrompts() const;
#endif

	static inline auto FGetTypeName = PreyFunction<const char* (const IUIGameEventSystem* const _this)>(0x1421030);
	static inline auto FInitEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x1421090);
	static inline auto FUnloadEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x1421FE0);
	static inline auto FInit = PreyFunction<void(IUIModule* const _this)>(0x1421040);
	static inline auto FUpdateModule = PreyFunction<void(IUIModule* const _this, float _fDelta)>(0x1422080);
	static inline auto FOnSetVisible = PreyFunction<void(ArkBrightnessMenu* const _this, IUIElement* pSender, bool bVisible)>(0x14219B0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x14214D0);
	static inline auto FOnAction = PreyFunction<bool(IBlockingActionListener* const _this, const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent)>(0x1421120);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(IArkActiveUserManagerListener* const _this, unsigned __unnamed1)>(0x1333E90);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(IArkActiveUserManagerListener* const _this, bool _bControllerDisconnect)>(0x1421220);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(IArkActiveUserManagerListener* const _this)>(0x1421310);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x1333E90);
	static inline auto FShowMenu = PreyFunction<void(ArkBrightnessMenu* const _this, ArkOptionMenu* _pOptionMenu)>(0x1421B50);
	static inline auto FApplyBrightnessUI = PreyFunction<void(const ArkBrightnessMenu* const _this, const float _fBrightness)>(0x1420ED0);
	static inline auto FOnSetBrightness = PreyFunction<void(ArkBrightnessMenu* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14218F0);
	static inline auto FOnCloseMenu = PreyFunction<void(ArkBrightnessMenu* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14214C0);
	static inline auto FOnMenuTransitionOut = PreyFunction<void(ArkBrightnessMenu* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14218E0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkBrightnessMenu* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14213F0);
	static inline auto FOnPressBack = PreyFunction<void(ArkBrightnessMenu* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14214C0);
};
#endif // !MOONCRASH
