// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/PlatformOS/PlatformOS_PC.h>
#ifndef MOONCRASH
#include <Prey/CryThreading/IJobManager.h>
#include <Prey/GameDll/ark/ArkNewGamePlus.h>
#endif
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/iface/ISaveGameEnumerator.h>
#include <Prey/GameDll/ark/ui/IArkDebugMenuListener.h>
#include <Prey/GameDll/ark/ui/IHUDEventListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIModule.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class CCryName;
enum class EArkDifficultyLevel;
enum EControlScheme;
enum ESystemEvent;
class IArkSaveLoadMenuListener;
struct IFlashPlayer;
struct IUIElement;
struct SHUDEvent;
struct SInputEvent;
struct SUIArguments;
struct SUIEventDesc;

// ArkSaveLoadMenu
// Header:  Prey/GameDll/ark/ui/ArkSaveLoadMenu.h
class ArkSaveLoadMenu
	: public ArkUIMenuBase<ArkSaveLoadMenu>
	, public std::enable_shared_from_this<ArkSaveLoadMenu>
	, public IBlockingActionListener
	, public IUIGameEventSystem
	, public IUIControlSchemeListener
	, public IUIModule
	, public IArkDebugMenuListener
	, public IHUDEventListener
	, public IPlatformOS::IPlatformListener
	, public IArkActiveUserManagerListener
#ifdef MOONCRASH
	, public ISystemEventListener
#endif
{ // Size=272 (0x110) PreyDll, 216 (0xD8) Mooncrash
public:
	enum class EArkLoadState
	{
		none = 0,
		loadSlot = 1,
		newGame = 2,
	};

	IUIElement* m_pUIElement;
	IArkSaveLoadMenuListener* m_pOpener;
	EArkSaveLoadMode m_mode;
	EArkSaveLoadMode m_baseMode;
	ArkSaveLoadMenu::EArkLoadState m_loadState;
#ifndef MOONCRASH
	std::array<bool, 3> m_availableTabs;
	std::array<std::unique_ptr<ArkNewGamePlus>, 3> m_availableNewGamePlus;
#else
	std::array<bool, 1> m_availableTabs;
#endif
	std::vector<unsigned int> m_saveOrder;
	std::vector<unsigned int> m_needsMetadata;
#ifndef MOONCRASH
	JobManager::SJobState m_newGamePlusJobState;
#endif
	int m_loadSlot;
	int m_highlightIndex;
	int m_highlightTab;
	bool m_bInGame;
	bool m_bOverwrite;
	bool m_bStartGameAfterDelete;
	bool m_bSaveListDirty;
	bool m_bCampaignListDirty;
	bool m_bCloseWhenSaveFinished;
#ifndef MOONCRASH
	bool m_bWaitingForNewGamePlusData;
#endif

	ArkSaveLoadMenu();
#ifdef MOONCRASH
	virtual ~ArkSaveLoadMenu();
#endif
	virtual const char* GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnUpdate(float _delta);
	virtual void OnInit(IUIElement* _pSender, IFlashPlayer* _pFlashPlayer);
	virtual void OnUnload(IUIElement* _pSender);
#ifdef MOONCRASH
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
#endif
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	virtual bool OnAction(const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent);
	virtual void OnToggleDebugMenu(bool _bEnable);
	virtual void OnHUDEvent(const SHUDEvent& _event);
	virtual void OnPlatformEvent(const IPlatformOS::SPlatformEvent& _event);
	virtual void OnActiveUserIdChanged(unsigned __unnamed1);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserSignedOut();
	void Open(IArkSaveLoadMenuListener& _opener, EArkSaveLoadMode _mode, bool _bInGame) { FOpen(this, _opener, _mode, _bInGame); }
	void Close(bool _bLoading) { FClose(this, _bLoading); }
	void OnGenderSelectClosed() { FOnGenderSelectClosed(this); }
	static void ReadProfileCampaign() { FReadProfileCampaign(); }
	// SUIArguments is only forward-declared in the tree, so these cannot be inline wrappers.
	static SUIArguments GetUISaveArguments(const ISaveGameEnumerator::SGameDescription& _desc, int _index);
	static SUIArguments GetUISaveMetadata(const ISaveGameEnumerator::SGameDescription& _desc, int _index);
	void OnSaveDeletedBySystem() { FOnSaveDeletedBySystem(this); }
#ifndef MOONCRASH
	void LoadNewGamePlus_Job() { FLoadNewGamePlus_Job(this); }
#endif
	void SetMode(EArkSaveLoadMode _nextMode) { FSetMode(this, _nextMode); }
	void OnCampaignHighlight(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnCampaignHighlight(this, _pSender, _event, _args); }
	void OnCampaignSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnCampaignSelect(this, _pSender, _event, _args); }
	void OnCampaignDelete(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnCampaignDelete(this, _pSender, _event, _args); }
	void OnSaveLoadSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnSaveLoadSelect(this, _pSender, _event, _args); }
	void OnShowDetails(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnShowDetails(this, _pSender, _event, _args); }
	void OnLoadTransitionComplete(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnLoadTransitionComplete(this, _pSender, _event, _args); }
	void OnPressBack(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPressBack(this, _pSender, _event, _args); }
#ifndef MOONCRASH
	void OnNewGamePlusHighlight(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnNewGamePlusHighlight(this, _pSender, _event, _args); }
	void OnNewGamePlusSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnNewGamePlusSelect(this, _pSender, _event, _args); }
#endif
	void OnGameOptionHighlight(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnGameOptionHighlight(this, _pSender, _event, _args); }
	void OnGameOptionSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnGameOptionSelect(this, _pSender, _event, _args); }
	void OnGameOptionPrev(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnGameOptionPrev(this, _pSender, _event, _args); }
	void OnGameOptionNext(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnGameOptionNext(this, _pSender, _event, _args); }
	void UpdateInputPrompts() const { FUpdateInputPrompts(this); }
	void PopulateSaveList(bool _bSaving) { FPopulateSaveList(this, _bSaving); }
	void PopulateCampaignSlots(bool _bNewGame) { FPopulateCampaignSlots(this, _bNewGame); }
#ifndef MOONCRASH
	bool PopulateNewGamePlus() { return FPopulateNewGamePlus(this); }
#endif
	void PopulateGameOptions() const { FPopulateGameOptions(this); }
#ifndef MOONCRASH
	void UpdateGameDifficulty(EArkDifficultyLevel _difficultyLevel) const { FUpdateGameDifficulty(this, _difficultyLevel); }
	void UpdateSurvivalOptions() const { FUpdateSurvivalOptions(this); }
	void ToggleSurvivalMode() const { FToggleSurvivalMode(this); }
#endif
	void OnConfirmResetCampaign() { FOnConfirmResetCampaign(this); }
	void OnCancelResetCampaign() { FOnCancelResetCampaign(this); }
	void OnConfirmDeleteSave() { FOnConfirmDeleteSave(this); }
	void OnCancelDeleteSave() { FOnCancelDeleteSave(this); }
	void OnConfirmLoadSave() { FOnConfirmLoadSave(this); }
	void OnCancelLoadSave() { FOnCancelLoadSave(this); }
	void OnLoadFailure() { FOnLoadFailure(this); }
#ifndef MOONCRASH
	void OnNewGamePlusFailure() { FOnNewGamePlusFailure(this); }
#endif
	void OnConfirmMaxSavesReached() { FOnConfirmMaxSavesReached(this); }
	void ShowDeleteCampaignConfirmDialog(bool _bOverwrite) { FShowDeleteCampaignConfirmDialog(this, _bOverwrite); }
	void ShowDeleteSaveConfirmDialog(bool _bOverwrite) { FShowDeleteSaveConfirmDialog(this, _bOverwrite); }
	void SetCurrentCampaign(int _slot) { FSetCurrentCampaign(this, _slot); }
	void PopulateSaveGameEnumAndSort(unsigned _campaignSlot) { FPopulateSaveGameEnumAndSort(this, _campaignSlot); }
	void UpdateSaveGameMetadata() { FUpdateSaveGameMetadata(this); }

#if 0
	static const char* GetTypeNameS();
#ifdef MOONCRASH
	void UpdateGameDifficulty(EArkDifficultyLevel _arg0_) const;
	void UpdateSurvivalOptions() const;
#endif
	void HighlightNextAvailableCampaignTab();
	void HighlightPrevAvailableCampaignTab();
	void HighlightCampaignTab(const int _arg0_);
	void UpdateCampaignSlotMetadata();
#endif

#ifndef MOONCRASH
	static inline auto FArkSaveLoadMenuOv1 = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x1377D40);
	static inline auto FGetTypeName = PreyFunction<const char* (const IUIGameEventSystem* const _this)>(0x1378880);
	static inline auto FInitEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x1378C80);
	static inline auto FUnloadEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x137DBE0);
	static inline auto FOnUpdate = PreyFunction<void(IUIGameEventSystem* const _this, float _delta)>(0x137B4D0);
	static inline auto FOnInit = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* _pSender, IFlashPlayer* _pFlashPlayer)>(0x137A880);
	static inline auto FOnUnload = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* _pSender)>(0x137B390);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x137A000);
	static inline auto FOnAction = PreyFunction<bool(IBlockingActionListener* const _this, const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent)>(0x1378E40);
	static inline auto FOnToggleDebugMenu = PreyFunction<void(IArkDebugMenuListener* const _this, bool _bEnable)>(0x137B220);
	static inline auto FOnHUDEvent = PreyFunction<void(IHUDEventListener* const _this, const SHUDEvent& _event)>(0x137A850);
	static inline auto FOnPlatformEvent = PreyFunction<void(IPlatformOS::IPlatformListener* const _this, const IPlatformOS::SPlatformEvent& _event)>(0x137AC80);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(IArkActiveUserManagerListener* const _this, unsigned __unnamed1)>(0xA13080);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(IArkActiveUserManagerListener* const _this, bool _bControllerDisconnect)>(0x13792D0);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(IArkActiveUserManagerListener* const _this)>(0x13793A0);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0xA13080);
	static inline auto FOpen = PreyFunction<void(ArkSaveLoadMenu* const _this, IArkSaveLoadMenuListener& _opener, EArkSaveLoadMode _mode, bool _bInGame)>(0x137BC90);
	static inline auto FClose = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bLoading)>(0x1378750);
	static inline auto FOnGenderSelectClosed = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x137A7E0);
	static inline auto FReadProfileCampaign = PreyFunction<void()>(0x137CFF0);
	static inline auto FGetUISaveArguments = PreyFunction<SUIArguments(const ISaveGameEnumerator::SGameDescription& _desc, int _index)>(0x1378890);
	static inline auto FGetUISaveMetadata = PreyFunction<SUIArguments(const ISaveGameEnumerator::SGameDescription& _desc, int _index)>(0x1378B10);
	static inline auto FOnSaveDeletedBySystem = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x137AD30);
	static inline auto FLoadNewGamePlus_Job = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x1378D20);
	static inline auto FSetMode = PreyFunction<void(ArkSaveLoadMenu* const _this, EArkSaveLoadMode _nextMode)>(0x137D2C0);
	static inline auto FOnCampaignHighlight = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1379490);
	static inline auto FOnCampaignSelect = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1379550);
	static inline auto FOnCampaignDelete = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1379400);
	static inline auto FOnSaveLoadSelect = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137ADA0);
	static inline auto FOnShowDetails = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137B080);
	static inline auto FOnLoadTransitionComplete = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137A9D0);
	static inline auto FOnPressBack = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137ACC0);
	static inline auto FOnNewGamePlusHighlight = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137A9F0);
	static inline auto FOnNewGamePlusSelect = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137AAF0);
	static inline auto FOnGameOptionHighlight = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137A140);
	static inline auto FOnGameOptionSelect = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137A5C0);
	static inline auto FOnGameOptionPrev = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137A510);
	static inline auto FOnGameOptionNext = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x137A470);
	static inline auto FUpdateInputPrompts = PreyFunction<void(const ArkSaveLoadMenu* const _this)>(0x137DD50);
	static inline auto FPopulateSaveList = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bSaving)>(0x137CCC0);
	static inline auto FPopulateCampaignSlots = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bNewGame)>(0x137BEC0);
	static inline auto FPopulateNewGamePlus = PreyFunction<bool(ArkSaveLoadMenu* const _this)>(0x137C890);
	static inline auto FPopulateGameOptions = PreyFunction<void(const ArkSaveLoadMenu* const _this)>(0x137C430);
	static inline auto FUpdateGameDifficulty = PreyFunction<void(const ArkSaveLoadMenu* const _this, EArkDifficultyLevel _difficultyLevel)>(0x137DC80);
	static inline auto FUpdateSurvivalOptions = PreyFunction<void(const ArkSaveLoadMenu* const _this)>(0x137E470);
	static inline auto FToggleSurvivalMode = PreyFunction<void(const ArkSaveLoadMenu* const _this)>(0x137DB40);
	static inline auto FOnConfirmResetCampaign = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x1379C10);
	static inline auto FOnCancelResetCampaign = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x13797B0);
	static inline auto FOnConfirmDeleteSave = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x1379840);
	static inline auto FOnCancelDeleteSave = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x13797B0);
	static inline auto FOnConfirmLoadSave = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x1379A10);
	static inline auto FOnCancelLoadSave = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x13797F0);
	static inline auto FOnLoadFailure = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x137A930);
	static inline auto FOnNewGamePlusFailure = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x137A9E0);
	static inline auto FOnConfirmMaxSavesReached = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x1379AD0);
	static inline auto FShowDeleteCampaignConfirmDialog = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bOverwrite)>(0x137D7C0);
	static inline auto FShowDeleteSaveConfirmDialog = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bOverwrite)>(0x137D980);
	static inline auto FSetCurrentCampaign = PreyFunction<void(ArkSaveLoadMenu* const _this, int _slot)>(0x137D210);
	static inline auto FPopulateSaveGameEnumAndSort = PreyFunction<void(ArkSaveLoadMenu* const _this, unsigned _campaignSlot)>(0x137CB00);
	static inline auto FUpdateSaveGameMetadata = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x137E230);
#else
	static inline auto FArkSaveLoadMenuOv1 = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145B700);
	static inline auto FGetTypeName = PreyFunction<const char* (const IUIGameEventSystem* const _this)>(0x145C080);
	static inline auto FInitEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x145C480);
	static inline auto FUnloadEventSystem = PreyFunction<void(IUIGameEventSystem* const _this)>(0x1460200);
	static inline auto FOnUpdate = PreyFunction<void(IUIGameEventSystem* const _this, float _delta)>(0x145E5F0);
	static inline auto FOnInit = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* _pSender, IFlashPlayer* _pFlashPlayer)>(0x145DB00);
	static inline auto FOnUnload = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* _pSender)>(0x145E4F0);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x145E360);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x145D480);
	static inline auto FOnAction = PreyFunction<bool(IBlockingActionListener* const _this, const CCryName& _action, int _activationMode, float _value, const SInputEvent& _inputEvent)>(0x145C510);
	static inline auto FOnToggleDebugMenu = PreyFunction<void(IArkDebugMenuListener* const _this, bool _bEnable)>(0x145E380);
	static inline auto FOnHUDEvent = PreyFunction<void(IHUDEventListener* const _this, const SHUDEvent& _event)>(0x145DAD0);
	static inline auto FOnPlatformEvent = PreyFunction<void(IPlatformOS::IPlatformListener* const _this, const IPlatformOS::SPlatformEvent& _event)>(0x145DDE0);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(IArkActiveUserManagerListener* const _this, unsigned __unnamed1)>(0x1333E90);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(IArkActiveUserManagerListener* const _this, bool _bControllerDisconnect)>(0x145C8B0);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(IArkActiveUserManagerListener* const _this)>(0x145C910);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x1333E90);
	static inline auto FOpen = PreyFunction<void(ArkSaveLoadMenu* const _this, IArkSaveLoadMenuListener& _opener, EArkSaveLoadMode _mode, bool _bInGame)>(0x145EC00);
	static inline auto FClose = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bLoading)>(0x145BFB0);
	static inline auto FOnGenderSelectClosed = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145DA60);
	static inline auto FReadProfileCampaign = PreyFunction<void()>(0x145FAC0);
	static inline auto FGetUISaveArguments = PreyFunction<SUIArguments(const ISaveGameEnumerator::SGameDescription& _desc, int _index)>(0x145C090);
	static inline auto FGetUISaveMetadata = PreyFunction<SUIArguments(const ISaveGameEnumerator::SGameDescription& _desc, int _index)>(0x145C310);
	static inline auto FOnSaveDeletedBySystem = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145DEA0);
	static inline auto FSetMode = PreyFunction<void(ArkSaveLoadMenu* const _this, EArkSaveLoadMode _nextMode)>(0x145FC50);
	static inline auto FOnCampaignHighlight = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145CA00);
	static inline auto FOnCampaignSelect = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145CAC0);
	static inline auto FOnCampaignDelete = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145C970);
	static inline auto FOnSaveLoadSelect = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145DF20);
	static inline auto FOnShowDetails = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145E1C0);
	static inline auto FOnLoadTransitionComplete = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145DDD0);
	static inline auto FOnPressBack = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145DE20);
	static inline auto FOnGameOptionHighlight = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145D5C0);
	static inline auto FOnGameOptionSelect = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145D960);
	static inline auto FOnGameOptionPrev = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145D8B0);
	static inline auto FOnGameOptionNext = PreyFunction<void(ArkSaveLoadMenu* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x145D810);
	static inline auto FUpdateInputPrompts = PreyFunction<void(const ArkSaveLoadMenu* const _this)>(0x1460330);
	static inline auto FPopulateSaveList = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bSaving)>(0x145F6B0);
	static inline auto FPopulateCampaignSlots = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bNewGame)>(0x145EE10);
	static inline auto FPopulateGameOptions = PreyFunction<void(const ArkSaveLoadMenu* const _this)>(0x145F2A0);
	static inline auto FOnConfirmResetCampaign = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145D1D0);
	static inline auto FOnCancelResetCampaign = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145CC70);
	static inline auto FOnConfirmDeleteSave = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145CE90);
	static inline auto FOnCancelDeleteSave = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145CC70);
	static inline auto FOnConfirmLoadSave = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145D070);
	static inline auto FOnCancelLoadSave = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145CCC0);
	static inline auto FOnLoadFailure = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145DBB0);
	static inline auto FOnConfirmMaxSavesReached = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x145D0E0);
	static inline auto FShowDeleteCampaignConfirmDialog = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bOverwrite)>(0x145FF40);
	static inline auto FShowDeleteSaveConfirmDialog = PreyFunction<void(ArkSaveLoadMenu* const _this, bool _bOverwrite)>(0x14600A0);
	static inline auto FSetCurrentCampaign = PreyFunction<void(ArkSaveLoadMenu* const _this, int _slot)>(0x145FBA0);
	static inline auto FPopulateSaveGameEnumAndSort = PreyFunction<void(ArkSaveLoadMenu* const _this, unsigned _campaignSlot)>(0x145F4F0);
	static inline auto FUpdateSaveGameMetadata = PreyFunction<void(ArkSaveLoadMenu* const _this)>(0x1460780);
#endif
};
