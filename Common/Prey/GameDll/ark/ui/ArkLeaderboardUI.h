// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class CCryName;
enum EControlScheme;
struct IUIElement;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// ArkLeaderboardUI
// Header:  Prey/GameDll/ark/ui/ArkLeaderboardUI.h
class ArkLeaderboardUI
	: public ArkUIMenuBase<ArkLeaderboardUI>
	, public std::enable_shared_from_this<ArkLeaderboardUI>
	, public IUIGameEventSystem
	, public IBlockingActionListener
	, public IUIControlSchemeListener
{ // Size=984 (0x3D8)
public:
	// ArkLeaderboardUI::ScorecardEntry
	// Header:  Prey/GameDll/ark/ui/ArkLeaderboardUI.h
	class ScorecardEntry
	{ // Size=24 (0x18)
	public:
		string m_label;
		float m_snapshotTotal;
		float m_currentTotal;
		float m_cryptoEarned;

	#if 0
		ScorecardEntry(string _arg0_, float _arg1_, float _arg2_, float _arg3_);
	#endif
	};

	bool m_bRequestingData;
	bool m_bPromptsDirty;
	int m_leaderboardPageNum;
	int m_leaderboardTotalPages;
	float m_totalScore;
	IUIElement* m_pUIElement;
	int m_inputHandle;
	int m_timeScaleHandle;
	EArkLeaderboardPage m_currentPage;
	EArkLeaderboardFilterType m_currentFilter;
	ArkButtonPromptCollection m_buttonPrompts;
	bool m_bAnimating;
	std::vector<ArkLeaderboardUI::ScorecardEntry> m_scorecardEntries;
	float m_currentRunningTotal;

	virtual const char* GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnUpdate(float _fDelta);
	virtual bool OnAction(const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent);
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	void Open() { FOpen(this); }
	void OnLeaderboardUp() { FOnLeaderboardUp(this); }
	void OnLeaderboardDown() { FOnLeaderboardDown(this); }
	void OnLeaderboardUse() { FOnLeaderboardUse(this); }
	void OnPressConfirm() { FOnPressConfirm(this); }
	void SetActionManagerState(bool _bEnable) { FSetActionManagerState(this, _bEnable); }
	void OnBackPressed(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnBackPressed(this, _pSender, _event, _args); }
	void OnButtonPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnButtonPress(this, _pSender, _event, _args); }
	void OnScoreAnimationComplete(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnScoreAnimationComplete(this, _pSender, _event, _args); }
	void OnScoreLineAnimated(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnScoreLineAnimated(this, _pSender, _event, _args); }
	void OnPromptSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPromptSelect(this, _pSender, _event, _args); }
	void Close() { FClose(this); }
	void UpdateInputPrompts() { FUpdateInputPrompts(this); }
	void SetPage(EArkLeaderboardPage _page) { FSetPage(this, _page); }

#if 0
	ArkLeaderboardUI();
	static const char* GetTypeNameS();
	bool IsOpen();
	static void OnLeaderboardDataLoaded(bool _arg0_);
	void RequestLeaderboardPage();
	void RefreshLeaderboardDisplay();
	void ShowError();
	void SetFilter(EArkLeaderboardFilterType _arg0_);
#endif

	static inline auto FGetTypeName = PreyFunction<const char* (const IUIGameEventSystem* const _this)>(0x14272B0);
	static inline auto FInitEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x14272C0);
	static inline auto FUnloadEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x1428580);
	static inline auto FOnUpdate = PreyFunction<void(IUIGameEventSystem* const _this, float _fDelta)>(0x1427750);
	static inline auto FOnAction = PreyFunction<bool(IBlockingActionListener* const _this, const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent)>(0x14272D0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x1427480);
	static inline auto FOpen = PreyFunction<void(ArkLeaderboardUI* const _this)>(0x1427790);
	static inline auto FOnLeaderboardUp = PreyFunction<void(ArkLeaderboardUI* const _this)>(0x14274D0);
	static inline auto FOnLeaderboardDown = PreyFunction<void(ArkLeaderboardUI* const _this)>(0x14274B0);
	static inline auto FOnLeaderboardUse = PreyFunction<void(ArkLeaderboardUI* const _this)>(0x14274F0);
	static inline auto FOnPressConfirm = PreyFunction<void(ArkLeaderboardUI* const _this)>(0x1427540);
	static inline auto FSetActionManagerState = PreyFunction<void(ArkLeaderboardUI* const _this, bool _bEnable)>(0x14278C0);
	static inline auto FOnBackPressed = PreyFunction<void(ArkLeaderboardUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1427460);
	static inline auto FOnButtonPress = PreyFunction<void(ArkLeaderboardUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1427470);
	static inline auto FOnScoreAnimationComplete = PreyFunction<void(ArkLeaderboardUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1427610);
	static inline auto FOnScoreLineAnimated = PreyFunction<void(ArkLeaderboardUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1427670);
	static inline auto FOnPromptSelect = PreyFunction<void(ArkLeaderboardUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1427590);
	static inline auto FClose = PreyFunction<void(ArkLeaderboardUI* const _this)>(0x1427210);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkLeaderboardUI* const _this)>(0x14285C0);
	static inline auto FSetPage = PreyFunction<void(ArkLeaderboardUI* const _this, EArkLeaderboardPage _page)>(0x1427A30);
};
#endif // MOONCRASH
