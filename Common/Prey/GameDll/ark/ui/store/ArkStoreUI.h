// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/player/IArkEntitlementListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/ui/store/ArkStoreManager.h>

class CCryName;
enum EControlScheme;
class IArkStoreUIListener;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// ArkStoreUI
// Header:  Prey/GameDll/ark/ui/store/ArkStoreUI.h
class ArkStoreUI
	: public ArkUIMenuBase<ArkStoreUI>
	, public std::enable_shared_from_this<ArkStoreUI>
	, public IUIGameEventSystem
	, public IBlockingActionListener
	, public IUIModule
	, public IUIControlSchemeListener
	, public IArkActiveUserManagerListener
	, public IArkEntitlementListener
{ // Size=240 (0xF0)
public:
	enum class Mode
	{
		closed = 0,
		loading = 1,
		open = 2,
		firstPartyStore = 3,
		popup = 4,
	};

	enum class RequestState
	{
		invalid = 0,
		success = 1,
		fail = 2,
	};

	ArkStoreManager m_storeManager;
	IUIElement* m_pUIElement;
	IArkStoreUIListener* m_pOpener;
	int m_inputHandle;
	bool m_bClose;
	ArkStoreUI::Mode m_mode;
	ArkStoreUI::RequestState m_requestState;
	uint64_t m_highlightId;

	virtual const char* GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void UpdateModule(float _fDelta);
	virtual bool OnAction(const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent);
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	virtual void OnActiveUserIdChanged(unsigned __unnamed1);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserSignedOut();
	virtual void OnEntitlementChanged(uint64_t _entitlement, bool _bGranted);
	void Refresh() { FRefresh(this); }
	void OnCatalogRequestComplete(bool _bResult) { FOnCatalogRequestComplete(this, _bResult); }
	void SetActionManagerState(bool _bEnable) { FSetActionManagerState(this, _bEnable); }
	void OnButtonPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnButtonPress(this, _pSender, _event, _args); }
	void OnHighlight(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnHighlight(this, _pSender, _event, _args); }
	void OnSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnSelect(this, _pSender, _event, _args); }
	void OnMenuTransition(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnMenuTransition(this, _pSender, _event, _args); }
	void OnErrorClose() { FOnErrorClose(this); }
	void Close(bool _bImmediate) { FClose(this, _bImmediate); }
	void FinishClose() { FFinishClose(this); }
	void UpdateInputPrompts() { FUpdateInputPrompts(this); }
	void HandleCatalogRequestComplete(bool _bSuccess) { FHandleCatalogRequestComplete(this, _bSuccess); }

#if 0
	ArkStoreUI();
	static const char* GetTypeNameS();
	void Open(IArkStoreUIListener* _arg0_);
	void SetMode(ArkStoreUI::Mode _arg0_);
#endif

	static inline auto FGetTypeName = PreyFunction<const char* (const IUIGameEventSystem* const _this)>(0x1430040);
	static inline auto FInitEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x1430150);
	static inline auto FUnloadEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x14313B0);
	static inline auto FUpdateModule = PreyFunction<void(IUIModule* const _this, float _fDelta)>(0x1431600);
	static inline auto FOnAction = PreyFunction<bool(IBlockingActionListener* const _this, const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent)>(0x14301C0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x14304E0);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(IArkActiveUserManagerListener* const _this, unsigned __unnamed1)>(0x1333E90);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(IArkActiveUserManagerListener* const _this, bool _bControllerDisconnect)>(0x1430310);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(IArkActiveUserManagerListener* const _this)>(0x1430370);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x1333E90);
	static inline auto FOnEntitlementChanged = PreyFunction<void(IArkEntitlementListener* const _this, uint64_t _entitlement, bool _bGranted)>(0x1430510);
	static inline auto FRefresh = PreyFunction<void(ArkStoreUI* const _this)>(0x1430830);
	static inline auto FOnCatalogRequestComplete = PreyFunction<void(ArkStoreUI* const _this, bool _bResult)>(0x1430450);
	static inline auto FSetActionManagerState = PreyFunction<void(ArkStoreUI* const _this, bool _bEnable)>(0x1431240);
	static inline auto FOnButtonPress = PreyFunction<void(ArkStoreUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14303E0);
	static inline auto FOnHighlight = PreyFunction<void(ArkStoreUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1430530);
	static inline auto FOnSelect = PreyFunction<void(ArkStoreUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1430770);
	static inline auto FOnMenuTransition = PreyFunction<void(ArkStoreUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1430760);
	static inline auto FOnErrorClose = PreyFunction<void(ArkStoreUI* const _this)>(0x14303E0);
	static inline auto FClose = PreyFunction<void(ArkStoreUI* const _this, bool _bImmediate)>(0x142FF10);
	static inline auto FFinishClose = PreyFunction<void(ArkStoreUI* const _this)>(0x142FFE0);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkStoreUI* const _this)>(0x1431430);
	static inline auto FHandleCatalogRequestComplete = PreyFunction<void(ArkStoreUI* const _this, bool _bSuccess)>(0x1430050);
};
#endif // MOONCRASH
