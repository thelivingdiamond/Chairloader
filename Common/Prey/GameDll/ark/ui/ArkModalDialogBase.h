// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class CCryName;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkModalDialogBase.h
class ArkModalDialogBase : public ArkUIMenuBase<ArkModalDialogBase>, public IUIGameEventSystem, public IUIControlSchemeListener, public IBlockingActionListener, public std::enable_shared_from_this<ArkModalDialogBase>, public ISystemEventListener, public IArkActiveUserManagerListener // Id=801B6BF Size=224
{
public:
	using ButtonCallback = Functor0;
	
	class ButtonAction // Id=801B6E4 Size=48
	{
	public:
		const char *m_label;
		CCryName m_actionId;
		Functor0 m_callback;
		
#if 0
		const char *GetLabel() const;
		CCryName const &GetActionId() const;
		Functor0 const &GetCallback() const;
#endif
	};

	std::vector<ArkModalDialogBase::ButtonAction> m_buttons;
	wstring m_label;
	wstring m_message;
	IUIElement *m_pUIElement;
	Functor0 m_activeCallback;
	bool m_bHiding;
	bool m_bAllowInput;
	bool m_bDialogOpen;
	bool m_bSpinner;
	int m_inputHandle;
	Vec2 m_screenRotate;
	ArkSimpleTimer m_timer;
	Functor0 m_timerCallback;
	EControlScheme m_currentControlScheme;
	
	ArkModalDialogBase();
	void SetContent(const char *_label, const char *_message, bool _bSpinner) { FSetContentOv1(this,_label,_message,_bSpinner); }
	void SetContent(wstring const &_label, wstring const &_message, bool _bSpinner) { FSetContentOv0(this,_label,_message,_bSpinner); }
	void AddButton(const char *_label, CCryName const &_actionId, Functor0 _callback) { FAddButton(this,_label,_actionId,_callback); }
	void SetTimer(float _time, Functor0 _callback) { FSetTimer(this,_time,_callback); }
	void Show() { FShow(this); }
	void RequestHide() { FRequestHide(this); }
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnUpdate(float fDelta);
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual bool OnAction(CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent);
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual void OnActiveUserIdChanged(unsigned );
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual void OnActiveUserSignedOut();
	virtual IUIElement *GetUIElement() const = 0;
	virtual const char *GetDialogClassName() const = 0;
	virtual void SetContents() const;
	static void OnButtonPress(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event) { FOnButtonPress(__this,_pSender,_event); }
	int GetNumButtons() const { return FGetNumButtons(this); }
	ArkModalDialogBase::ButtonAction GetButton(int _index) { return FGetButton(this,_index); }
	static void OnShow(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event) { FOnShow(__this,_pSender,_event); }
	static void OnHide(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event) { FOnHide(__this,_pSender,_event); }
	void SetActionManagerState(bool _bEnable) { FSetActionManagerState(this,_bEnable); }
	void UpdateButtons(EControlScheme _controlScheme, bool _bForce) { FUpdateButtons(this,_controlScheme,_bForce); }
	void Close() { FClose(this); }
	virtual ~ArkModalDialogBase();
	
#if 0
	bool IsVisible() const;
	bool IsInputEnabled() const;
	bool IsOpen() const;
	wstring GetLabel() const;
	wstring GetMessageA() const;
	void DisableInput();
#endif
	
	static inline auto FSetContentOv1 = PreyFunction<void(ArkModalDialogBase *const _this, const char *_label, const char *_message, bool _bSpinner)>(0x1604A90);
	static inline auto FSetContentOv0 = PreyFunction<void(ArkModalDialogBase *const _this, wstring const &_label, wstring const &_message, bool _bSpinner)>(0x1604A40);
	static inline auto FAddButton = PreyFunction<void(ArkModalDialogBase *const _this, const char *_label, CCryName const &_actionId, Functor0 _callback)>(0x1603DE0);
	static inline auto FSetTimer = PreyFunction<void(ArkModalDialogBase *const _this, float _time, Functor0 _callback)>(0x1604CD0);
	static inline auto FShow = PreyFunction<void(ArkModalDialogBase *const _this)>(0x1604D30);
	static inline auto FRequestHide = PreyFunction<void(ArkModalDialogBase *const _this)>(0x1604810);
	static inline auto FInitEventSystem = PreyFunction<void(ArkModalDialogBase *const _this)>(0x1604090);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkModalDialogBase *const _this)>(0x1604EB0);
	static inline auto FOnUpdate = PreyFunction<void(ArkModalDialogBase *const _this, float fDelta)>(0x16046C0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkModalDialogBase *const _this, EControlScheme _controlScheme)>(0x16045D0);
	static inline auto FOnAction = PreyFunction<bool(ArkModalDialogBase *const _this, CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent)>(0x1604190);
	static inline auto FOnSystemEvent = PreyFunction<void(ArkModalDialogBase *const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x1604670);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(ArkModalDialogBase *const _this, unsigned )>(0xA13080);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(ArkModalDialogBase *const _this, bool _bControllerDisconnect)>(0x1604480);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(ArkModalDialogBase *const _this)>(0xA13080);
	static inline auto FSetContents = PreyFunction<void(ArkModalDialogBase const *const _this)>(0x1604B20);
	static inline auto FOnButtonPress = PreyFunction<void(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event)>(0x16044F0);
	static inline auto FGetNumButtons = PreyFunction<int(ArkModalDialogBase const *const _this)>(0x1604060);
	static inline auto FGetButton = PreyFunction<ArkModalDialogBase::ButtonAction(ArkModalDialogBase *const _this, int _index)>(0x1604020);
	static inline auto FOnShow = PreyFunction<void(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event)>(0x1604660);
	static inline auto FOnHide = PreyFunction<void(IUIElement *__this, SUIEventDesc const &_pSender, SUIArguments const &_event)>(0x1604640);
	static inline auto FSetActionManagerState = PreyFunction<void(ArkModalDialogBase *const _this, bool _bEnable)>(0x1604860);
	static inline auto FUpdateButtons = PreyFunction<void(ArkModalDialogBase *const _this, EControlScheme _controlScheme, bool _bForce)>(0x1604F40);
	static inline auto FClose = PreyFunction<void(ArkModalDialogBase *const _this)>(0x1603F20);
	static inline auto FBitNotArkModalDialogBase = PreyFunction<void(ArkModalDialogBase *const _this)>(0x134AAF0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryString/CryName.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

enum ESystemEvent;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// ArkModalDialogBase
// Header:  Prey/GameDll/ark/ui/ArkModalDialogBase.h
class ArkModalDialogBase
	: public ArkUIMenuBase<ArkModalDialogBase>
	, public IUIGameEventSystem
	, public IUIControlSchemeListener
	, public IBlockingActionListener
	, public std::enable_shared_from_this<ArkModalDialogBase>
	, public ISystemEventListener
	, public IArkActiveUserManagerListener
{ // Size=224 (0xE0)
public:
	// ArkModalDialogBase::ButtonAction
	// Header:  Prey/GameDll/ark/ui/ArkModalDialogBase.h
	class ButtonAction
	{ // Size=48 (0x30)
	public:
		const char* m_label;
		CCryName m_actionId;
		Functor0 m_callback;

	#if 0
		ButtonAction(const char* _arg0_, CCryName _arg1_, Functor0 _arg2_);
		const char* GetLabel() const;
		const CCryName& GetActionId() const;
		const Functor0& GetCallback() const;
	#endif
	};

	using ButtonCallback = Functor0;

	std::vector<ArkModalDialogBase::ButtonAction> m_buttons;
	wstring m_label;
	wstring m_message;
	IUIElement* m_pUIElement;
	Functor0 m_activeCallback;
	bool m_bHiding;
	bool m_bAllowInput;
	bool m_bDialogOpen;
	bool m_bSpinner;
	int m_inputHandle;
	Vec2 m_screenRotate;
	ArkSimpleTimer m_timer;
	Functor0 m_timerCallback;
	EControlScheme m_currentControlScheme;

	ArkModalDialogBase();
	void SetContent(const char* _label, const char* _message, bool _bSpinner) { FSetContentOv1(this, _label, _message, _bSpinner); }
	void SetContent(const wstring& _label, const wstring& _message, bool _bSpinner) { FSetContentOv0(this, _label, _message, _bSpinner); }
	void AddButton(const char* _label, const CCryName& _actionId, Functor0 _callback) { FAddButton(this, _label, _actionId, _callback); }
	void SetTimer(float _time, Functor0 _callback) { FSetTimer(this, _time, _callback); }
	void Show() { FShow(this); }
	void RequestHide() { FRequestHide(this); }
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnUpdate(float fDelta);
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	virtual bool OnAction(const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent);
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual void OnActiveUserIdChanged(unsigned __unnamed1);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual void OnActiveUserSignedOut();
	virtual IUIElement* GetUIElement() const = 0;
	virtual const char* GetDialogClassName() const = 0;
	virtual void SetContents() const;
	static void OnButtonPress(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnButtonPress(_pSender, _event, _args); }
	int GetNumButtons() const { return FGetNumButtons(this); }
	ArkModalDialogBase::ButtonAction GetButton(int _index) { alignas(ArkModalDialogBase::ButtonAction) std::byte _return_buf_[sizeof(ArkModalDialogBase::ButtonAction)]; return *FGetButton(this, reinterpret_cast<ArkModalDialogBase::ButtonAction*>(_return_buf_), _index); }
	static void OnShow(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnShow(_pSender, _event, _args); }
	static void OnHide(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnHide(_pSender, _event, _args); }
	void SetActionManagerState(bool _bEnable) { FSetActionManagerState(this, _bEnable); }
	void UpdateButtons(EControlScheme _controlScheme, bool _bForce) { FUpdateButtons(this, _controlScheme, _bForce); }
	void Close() { FClose(this); }

#if 0
	bool IsVisible() const;
	bool IsInputEnabled() const;
	bool IsOpen() const;
	wstring GetLabel() const;
	wstring GetMessageA() const;
	void DisableInput();
#endif

	static inline auto FArkModalDialogBaseOv2 = PreyFunction<void(ArkModalDialogBase* const _this)>(0x1724C10);
	static inline auto FSetContentOv1 = PreyFunction<void(ArkModalDialogBase* const _this, const char* _label, const char* _message, bool _bSpinner)>(0x1725C20);
	static inline auto FSetContentOv0 = PreyFunction<void(ArkModalDialogBase* const _this, const wstring& _label, const wstring& _message, bool _bSpinner)>(0x1725BD0);
	static inline auto FAddButton = PreyFunction<void(ArkModalDialogBase* const _this, const char* _label, const CCryName& _actionId, Functor0 _callback)>(0x1724F70);
	static inline auto FSetTimer = PreyFunction<void(ArkModalDialogBase* const _this, float _time, Functor0 _callback)>(0x1725E60);
	static inline auto FShow = PreyFunction<void(ArkModalDialogBase* const _this)>(0x1725EC0);
	static inline auto FRequestHide = PreyFunction<void(ArkModalDialogBase* const _this)>(0x17259A0);
	static inline auto FInitEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x1725220);
	static inline auto FUnloadEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x1726040);
	static inline auto FOnUpdate = PreyFunction<void(IUIGameEventSystem* const _this, float fDelta)>(0x1725850);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x1725760);
	static inline auto FOnAction = PreyFunction<bool(IBlockingActionListener* const _this, const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent)>(0x1725320);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x1725800);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(IArkActiveUserManagerListener* const _this, unsigned __unnamed1)>(0x1333E90);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(IArkActiveUserManagerListener* const _this, bool _bControllerDisconnect)>(0x1725610);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x1333E90);
	static inline auto FSetContents = PreyFunction<void(const ArkModalDialogBase* const _this)>(0x1725CB0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkModalDialogBase* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1725680);
	static inline auto FGetNumButtons = PreyFunction<int(const ArkModalDialogBase* const _this)>(0x17251F0);
	static inline auto FGetButton = PreyFunction<ArkModalDialogBase::ButtonAction*(ArkModalDialogBase* const _this, ArkModalDialogBase::ButtonAction* _return_value_, int _index)>(0x17251B0);
	static inline auto FOnShow = PreyFunction<void(ArkModalDialogBase* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x17257F0);
	static inline auto FOnHide = PreyFunction<void(ArkModalDialogBase* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x17257D0);
	static inline auto FSetActionManagerState = PreyFunction<void(ArkModalDialogBase* const _this, bool _bEnable)>(0x17259F0);
	static inline auto FUpdateButtons = PreyFunction<void(ArkModalDialogBase* const _this, EControlScheme _controlScheme, bool _bForce)>(0x17260D0);
	static inline auto FClose = PreyFunction<void(ArkModalDialogBase* const _this)>(0x17250B0);
};
#endif // !MOONCRASH
