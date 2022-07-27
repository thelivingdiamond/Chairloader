// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/arkgenderselectmenu.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class CCryName;
class ICrySizer;
struct IFlashPlayer;
struct IUIElement;
struct SFlowNodeConfig;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkgenderselectmenu.h
class ArkFlowNodeGenderSelectMenu : public CFlowBaseNode<0> // Id=801BA41 Size=16
{
public:
	enum class InPort
	{
		trigger = 0,
	};

	enum class OutPort
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig &_config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	virtual ~ArkFlowNodeGenderSelectMenu();
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGenderSelectMenu *const _this, SFlowNodeConfig &_config)>(0x1347F90);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGenderSelectMenu *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x13481A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeGenderSelectMenu const *const _this, ICrySizer *_pS)>(0x44D760);
};

// Header: Exact
// Prey/GameDll/ark/ui/ArkGenderSelectMenu.h
class ArkGenderSelectMenu : public ArkUIMenuBase<ArkGenderSelectMenu>, public std::enable_shared_from_this<ArkGenderSelectMenu>, public IBlockingActionListener, public IUIGameEventSystem, public IUIControlSchemeListener, public IUIModule, public IArkActiveUserManagerListener // Id=801BA44 Size=104
{
public:
	IUIElement *m_pUIElement;
	ArkBinkPlayerHandle m_binkHandle;
	int m_selectedGender;
	bool m_bStartGame;
	
	virtual const char *GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void UpdateModule(float _delta);
	virtual void OnInit(IUIElement *_pSender, IFlashPlayer *_pFlashPlayer);
	virtual void OnUnload(IUIElement *_pSender);
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual bool OnAction(CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent);
	virtual void OnActiveUserIdChanged(unsigned __formal);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserSignedOut();
	void Open() { FOpen(this); }
	void OnGenderSelect(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnGenderSelect(this,_pSender,_event,_args); }
	void OnLoadTransitionComplete(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnLoadTransitionComplete(this,_pSender,_event,_args); }
	void OnBackPressed(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnBackPressed(this,_pSender,_event,_args); }
	void UpdateInputPrompts() const { FUpdateInputPrompts(this); }
	void OnGenderSelected() { FOnGenderSelected(this); }
	void StartExitTransition(bool _bStartGame) { FStartExitTransition(this,_bStartGame); }
	void Close() { FClose(this); }
	virtual ~ArkGenderSelectMenu();
	
#if 0
	static const char *GetTypeNameS();
	bool IsSelectedGenderFemale() const;
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkGenderSelectMenu const *const _this)>(0x1348960);
	static inline auto FInitEventSystem = PreyFunction<void(ArkGenderSelectMenu *const _this)>(0x1348970);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkGenderSelectMenu *const _this)>(0x1349360);
	static inline auto FUpdateModule = PreyFunction<void(ArkGenderSelectMenu *const _this, float _delta)>(0x13495F0);
	static inline auto FOnInit = PreyFunction<void(ArkGenderSelectMenu *const _this, IUIElement *_pSender, IFlashPlayer *_pFlashPlayer)>(0x1348EF0);
	static inline auto FOnUnload = PreyFunction<void(ArkGenderSelectMenu *const _this, IUIElement *_pSender)>(0x13490F0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkGenderSelectMenu *const _this, EControlScheme _controlScheme)>(0x1348DA0);
	static inline auto FOnAction = PreyFunction<bool(ArkGenderSelectMenu *const _this, CCryName const &_action, int _activationMode, float _value, SInputEvent const &_inputEvent)>(0x13489E0);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(ArkGenderSelectMenu *const _this, unsigned __formal)>(0xA13080);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(ArkGenderSelectMenu *const _this, bool _bControllerDisconnect)>(0x1348AB0);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(ArkGenderSelectMenu *const _this)>(0x1348C80);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(ArkGenderSelectMenu *const _this)>(0xA13080);
	static inline auto FOpen = PreyFunction<void(ArkGenderSelectMenu *const _this)>(0x13491F0);
	static inline auto FOnGenderSelect = PreyFunction<void(ArkGenderSelectMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1348DD0);
	static inline auto FOnLoadTransitionComplete = PreyFunction<void(ArkGenderSelectMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1345540);
	static inline auto FOnBackPressed = PreyFunction<void(ArkGenderSelectMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1348D90);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkGenderSelectMenu const *const _this)>(0x13493E0);
	static inline auto FOnGenderSelected = PreyFunction<void(ArkGenderSelectMenu *const _this)>(0x1348EC0);
	static inline auto FStartExitTransition = PreyFunction<void(ArkGenderSelectMenu *const _this, bool _bStartGame)>(0x1349280);
	static inline auto FClose = PreyFunction<void(ArkGenderSelectMenu *const _this)>(0x1348920);
};

