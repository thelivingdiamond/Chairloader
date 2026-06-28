// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

enum class ArkHighlightsReturnCode;
class CCryName;
enum EControlScheme;
enum ESystemEvent;
class Functor0;
class IArkReadyRoomMetaUI;
class IArkReadyRoomUI;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// ArkReadyRoomManager
// Header:  Prey/GameDll/ark/ui/readyroom/ArkReadyRoomManager.h
class ArkReadyRoomManager
	: public IUIGameEventSystem
	, public ArkUIMenuBase<ArkReadyRoomManager>
	, public IUIControlSchemeListener
	, public ISystemEventListener
	, public IArkActiveUserManagerListener
{ // Size=1048 (0x418)
public:
	enum class EArkReadyRoomMetaPage
	{
		scorecard = 0,
		progress = 1,
		_count = 2,
	};

	enum class ECloseEvent
	{
		none = 0,
		launch = 1,
		reset = 2,
		satellite = 3,
	};

	ArkButtonPromptCollection m_inputPrompts;
	std::array<std::unique_ptr<IArkReadyRoomUI>, 4> m_pages;
	std::array<std::unique_ptr<IArkReadyRoomMetaUI>, 2> m_metaPages;
	EArkReadyRoomPage m_currentPage;
	ArkReadyRoomManager::EArkReadyRoomMetaPage m_currentMetaPage;
	IUIElement* m_pUIElement;
	QuatT m_characterLocation;
	QuatT m_cameraLocation;
	unsigned m_lightEntity;
	ArkReadyRoomManager::ECloseEvent m_closeEvent;
	float m_cryptoCurrency;
	int m_inputMode;
	int m_timeScaleHandle;
	int m_zoomHandle;
	bool m_bPromptsDirty;
	bool m_bCanViewProgress;
	bool m_bResetting;
	bool m_bClosing;
	int m_unloadTicks;

	ArkReadyRoomManager();
	virtual ~ArkReadyRoomManager();
	virtual const char* GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnUpdate(float _fDelta);
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	void Open(bool _bOpenScorecard, const QuatT& _characterLocation, unsigned _lightEntity, const QuatT& _cameraLocation) { FOpen(this, _bOpenScorecard, _characterLocation, _lightEntity, _cameraLocation); }
	void ProcessInput(CCryName _actionId, int _activationMode, float _fValue) { FProcessInput(this, _actionId, _activationMode, _fValue); }
	void Close(ArkReadyRoomManager::ECloseEvent _event, bool _bImmediate) { FClose(this, _event, _bImmediate); }
	bool IsOpen() const { return FIsOpen(this); }
	bool CanResetSimulation() const { return FCanResetSimulation(this); }
	void ResetSimulation() { FResetSimulation(this); }
	void AdjustCryptoCurrency(float _amount) { FAdjustCryptoCurrency(this, _amount); }
	void ReturnToSatellite() { FReturnToSatellite(this); }
	void QuitChallengeMode() { FQuitChallengeMode(this); }
	void GoForward() { FGoForward(this); }
	void Launch() { FLaunch(this); }
	void SetInputPrompt(const int _index, const bool _bVisible, const CCryName _actionId, const string& _label, const bool _bUseHoldTriggerDelay, const bool _bEnabled, Functor0 _callback) { FSetInputPrompt(this, _index, _bVisible, _actionId, _label, _bUseHoldTriggerDelay, _bEnabled, _callback); }
	void UpdateTabs() const { FUpdateTabs(this); }
	void UpdateInputPrompts(bool _bForceUIUpdate) { FUpdateInputPrompts(this, _bForceUIUpdate); }
	void UpdateCheckoutTally() const { FUpdateCheckoutTally(this); }
	void CloseMetaPage() { FCloseMetaPage(this); }
	void ConfirmResetSimulation() { FConfirmResetSimulation(this); }
	void CheckForForcedActions() { FCheckForForcedActions(this); }
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	virtual void OnActiveUserIdChanged(unsigned platformUserId);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserPostReengaged();
	virtual void OnActiveUserSignedOut();
	void OnResetSimulation(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnResetSimulation(this, _pSender, _event, _args); }
	void OnPromptSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPromptSelect(this, _pSender, _event, _args); }
	void OnCloseFinished(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnCloseFinished(this, _pSender, _event, _args); }
	void OnConfirmExitShell() const { FOnConfirmExitShell(this); }
	void OnConfirmExitDesktop() const { FOnConfirmExitDesktop(this); }
	void ConfirmQuitToMainMenu() { FConfirmQuitToMainMenu(this); }
	void ConfirmSaveAndExit() { FConfirmSaveAndExit(this); }
	void OpenProgressMenu() { FOpenProgressMenu(this); }
	void ToggleMetaPage() { FToggleMetaPage(this); }
	void GotoPage(const EArkReadyRoomPage _page) { FGotoPage(this, _page); }
	void FinishClosing() { FFinishClosing(this); }
	void OnPressNext() { FOnPressNext(this); }
	void OnPressBack() { FOnPressBack(this); }

#if 0
	static const char* GetTypeNameS();
	bool IsResetting() const;
	IUIElement* GetUIElement();
	float GetCryptoCurrency() const;
	void GoBack();
	IArkReadyRoomUI* GetPage(EArkReadyRoomPage _arg0_);
	IArkReadyRoomMetaUI* GetMetaPage(ArkReadyRoomManager::EArkReadyRoomMetaPage _arg0_);
	EArkReadyRoomPage GetCurrentPage() const;
	unsigned GetLightEntity() const;
	const QuatT& GetCharacterLocation() const;
	void GotoMetaPage(ArkReadyRoomManager::EArkReadyRoomMetaPage _arg0_);
	void ShowHighlightsUi();
	void ConfirmReturnToSatellite();
	void EnableActionMap(const bool _arg0_);
	bool CanGoBack() const;
	int FindPreviousAvailablePageIndex(const int _arg0_) const;
	bool IsMetaPageOpen();
	bool IsClosing() const;
	bool CheckForForcedSimulationReset();
	bool CheckForForcedReturnToSatellite();
	void OnHighlightsUiClosed(ArkHighlightsReturnCode _arg0_);
#endif

	static inline auto FArkReadyRoomManager = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x14730F0);
	static inline auto FGetTypeName = PreyFunction<const char* (const ArkReadyRoomManager* const _this)>(0x1474550);
	static inline auto FInitEventSystem = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x14748A0);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1476AE0);
	static inline auto FOnUpdate = PreyFunction<void(ArkReadyRoomManager* const _this, float _fDelta)>(0x14751E0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x1474B60);
	static inline auto FOpen = PreyFunction<void(ArkReadyRoomManager* const _this, bool _bOpenScorecard, const QuatT& _characterLocation, unsigned _lightEntity, const QuatT& _cameraLocation)>(0x1475380);
	static inline auto FProcessInput = PreyFunction<void(ArkReadyRoomManager* const _this, CCryName _actionId, int _activationMode, float _fValue)>(0x14762A0);
	static inline auto FClose = PreyFunction<void(ArkReadyRoomManager* const _this, ArkReadyRoomManager::ECloseEvent _event, bool _bImmediate)>(0x1473D30);
	static inline auto FIsOpen = PreyFunction<bool(const ArkReadyRoomManager* const _this)>(0x14748E0);
	static inline auto FCanResetSimulation = PreyFunction<bool(const ArkReadyRoomManager* const _this)>(0x1473A00);
	static inline auto FResetSimulation = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1476670);
	static inline auto FAdjustCryptoCurrency = PreyFunction<void(ArkReadyRoomManager* const _this, float _amount)>(0x14739E0);
	static inline auto FReturnToSatellite = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1476750);
	static inline auto FQuitChallengeMode = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1476640);
	static inline auto FGoForward = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1474560);
	static inline auto FLaunch = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1474910);
	static inline auto FSetInputPrompt = PreyFunction<void(ArkReadyRoomManager* const _this, const int _index, const bool _bVisible, const CCryName _actionId, const string& _label, const bool _bUseHoldTriggerDelay, const bool _bEnabled, Functor0 _callback)>(0x14767A0);
	static inline auto FUpdateTabs = PreyFunction<void(const ArkReadyRoomManager* const _this)>(0x1477A50);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkReadyRoomManager* const _this, bool _bForceUIUpdate)>(0x1476FA0);
	static inline auto FUpdateCheckoutTally = PreyFunction<void(const ArkReadyRoomManager* const _this)>(0x1476B20);
	static inline auto FCloseMetaPage = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1473E80);
	static inline auto FConfirmResetSimulation = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1474000);
	static inline auto FCheckForForcedActions = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1473A80);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x14751B0);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(IArkActiveUserManagerListener* const _this, unsigned platformUserId)>(0x1333E90);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(IArkActiveUserManagerListener* const _this, bool _bControllerDisconnect)>(0x1333E90);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(IArkActiveUserManagerListener* const _this)>(0x13B0900);
	static inline auto FOnActiveUserPostReengaged = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x14749E0);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x1333E90);
	static inline auto FOnResetSimulation = PreyFunction<void(ArkReadyRoomManager* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1475080);
	static inline auto FOnPromptSelect = PreyFunction<void(ArkReadyRoomManager* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1474FD0);
	static inline auto FOnCloseFinished = PreyFunction<void(ArkReadyRoomManager* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1474A40);
	static inline auto FOnConfirmExitShell = PreyFunction<void(const ArkReadyRoomManager* const _this)>(0x1474A80);
	static inline auto FOnConfirmExitDesktop = PreyFunction<void(const ArkReadyRoomManager* const _this)>(0x1474A50);
	static inline auto FConfirmQuitToMainMenu = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1473EE0);
	static inline auto FConfirmSaveAndExit = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1474120);
	static inline auto FOpenProgressMenu = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x14761E0);
	static inline auto FToggleMetaPage = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1476A40);
	static inline auto FGotoPage = PreyFunction<void(ArkReadyRoomManager* const _this, const EArkReadyRoomPage _page)>(0x1474600);
	static inline auto FFinishClosing = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x14742B0);
	static inline auto FOnPressNext = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1474D60);
	static inline auto FOnPressBack = PreyFunction<void(ArkReadyRoomManager* const _this)>(0x1474CC0);
};
#endif // MOONCRASH
