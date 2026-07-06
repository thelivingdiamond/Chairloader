// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkEmailListener.h>
#include <Prey/GameDll/ark/iface/IArkUtilityListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/worldui/ArkInteractiveScreen.h>
#include <Prey/GameDll/ark/ArkPasswordProtected.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
class ArkUtility;
class ArkUtilityButton;
class CArkFlowNodeWorkstationPopup;
class CArkFlowNodeWorkstationResult;
struct IEntity;
struct IGameObject;
struct IUIElement;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/worldui/ArkStationWorldUI.h
class ArkStationWorldUI : public ArkInteractiveScreen, public ArkUIMenuBase<ArkStationWorldUI>, public IArkEmailListener, public IArkUtilityListener // Id=801BCA1 Size=664
{
public:
	EArkStationWorldUIState m_state;
	bool m_bLocked;
	ArkSimpleTimer m_idleTimer;
	ArkPasswordProtected m_passwordProtected;
	uint64_t m_currentId;
	ArkSimpleTimer m_popUpTimeTimer;
	string m_currentCode;
	bool m_bShowingKeypad;
	bool m_bResultOpen;
	bool m_bResultError;
	bool m_bPopupOpen;
	bool m_bShowingPopupCancel;
	bool m_bShowingPopupConfirm;
	string m_resultTitle;
	string m_resultBody;
	string m_popupTitle;
	string m_popupBody;
	CArkFlowNodeWorkstationPopup *m_pPopupFlownode;
	CArkFlowNodeWorkstationResult *m_pResultFlownode;
	ArkAudioTrigger m_triggerPowerLoop;
	ArkAudioTrigger m_triggerPowerStop;
	_smart_ptr<IMaterial> m_pScreensaverMaterial;
	_smart_ptr<IMaterial> m_pPowerOffMaterial;
	bool m_bStartsUnlocked;
	int m_hackingLevel;
	
	struct FlowNodeSaveData // Id=801BCC3 Size=8
	{
		unsigned m_entityId;
		uint16_t m_flowNodeId;
		
		//void Populate(IFlowNode::SActivationInfo const &_actInfo) { FPopulate(this,_actInfo); }
		
#if 0
		void Serialize(TSerialize arg0);
		void Invalidate();
#endif
		
		//static inline auto FPopulate = PreyFunction<void(ArkStationWorldUI::FlowNodeSaveData *const _this, IFlowNode::SActivationInfo const &_actInfo)>(0x13A9560);
	};

	ArkStationWorldUI::FlowNodeSaveData m_popupFlowNodeSaveData;
	ArkStationWorldUI::FlowNodeSaveData m_resultFlowNodeSaveData;
	EArkStationWorldUIState m_serializeState;
	
	ArkStationWorldUI();
	virtual ~ArkStationWorldUI();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	virtual void SetupStaticMaterial();
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement *_pUIInstance);
	virtual bool OnWorldUIBack();
	virtual void OnEmailSentChanged(const uint64_t _id);
	virtual void OnEmailRead(const uint64_t _id);
	virtual void OnUtilityStateChanged(const uint64_t _id);
	virtual void OnUtilityHiddenChanged(const uint64_t _id);
	virtual void OnUtilityButtonStateChanged(const uint64_t _id);
	virtual void OnUtilityButtonHiddenChanged(const uint64_t _id);
	bool SetLockedFromScript(bool _bLocked) { return FSetLockedFromScript(this,_bLocked); }
	void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnButtonPress(this,_pSender,_event,_args); }
	void OnPasswordSuccess(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnPasswordSuccess(this,_pSender,_event,_args); }
	void OnSoundEvent(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSoundEvent(this,_pSender,_event,_args); }
	void OnKeypadPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnKeypadPress(this,_pSender,_event,_args); }
	void OnShowDetail(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnShowDetail(this,_pSender,_event,_args); }
	virtual void OnSelectPersonnel(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	void OnHackingFinished(bool _bSuccess) { FOnHackingFinished(this,_bSuccess); }
	bool KeypadButtonPressed(string const &_buttonName) { return FKeypadButtonPressed(this,_buttonName); }
	void OpenResultScreen(string const &_title, string const &_body, bool _bError, CArkFlowNodeWorkstationResult *_pFlowNode) { FOpenResultScreen(this,_title,_body,_bError,_pFlowNode); }
	void CloseResultScreen() { FCloseResultScreen(this); }
	void OpenPopupScreen(string const &_title, string const &_body, float _duration, float _progress, bool _bShowConfirm, bool _bShowCancel, CArkFlowNodeWorkstationPopup *_pFlowNode) { FOpenPopupScreen(this,_title,_body,_duration,_progress,_bShowConfirm,_bShowCancel,_pFlowNode); }
	void ClosePopupScreen() { FClosePopupScreen(this); }
	void ClearKeypad() { FClearKeypad(this); }
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void OnEnabledChanged(bool _bForce);
	std::pair<int,int> CountEmails(std::vector<unsigned __int64> const &_emailIds) const { return FCountEmails(this,_emailIds); }
	void SetState(EArkStationWorldUIState _state, bool _bForce) { FSetState(this,_state,_bForce); }
	virtual EArkStationWorldUIState GetUnlockedState() const;
	void RefreshUI(bool _bReinit, bool _bAnimateIn) { FRefreshUI(this,_bReinit,_bAnimateIn); }
	void RefreshEmailUI() { FRefreshEmailUI(this); }
	void RefreshEmailDetailUI() { FRefreshEmailDetailUI(this); }
	virtual void RefreshChildDefinedUI(bool arg0) = 0;
	virtual void RefreshChildDefinedDetailUI();
	void RefreshUtilityUI() { FRefreshUtilityUI(this); }
	void RefreshUtilityDetailUI() { FRefreshUtilityDetailUI(this); }
	virtual void RefreshRootMenu();
	virtual const char *GetStationTitle() const = 0;
	virtual const char *GetUtilitiesTitle() const = 0;
	virtual const char *GetLoginPageType() const;
	virtual bool IsSecurity() const = 0;
	virtual bool CanEnterState(EArkStationWorldUIState arg0) const = 0;
	virtual void EnterChildDefinedState();
	virtual void SubPageButtonPressed(string const &_buttonName);
	virtual std::vector<unsigned __int64> const &GetEmails() const = 0;
	virtual std::vector<std::shared_ptr<ArkUtility>> const &GetUtilities() const = 0;
	int CountUtilities(std::vector<std::shared_ptr<ArkUtility>> const &_utilities) const { return FCountUtilities(this,_utilities); }
	virtual ArkUtility const *FindUtility(const uint64_t arg0) const = 0;
	virtual ArkUtilityButton const *FindUtilityButton(const uint64_t arg0) const = 0;
	virtual uint64_t GetUtilityButtonOwner(const uint64_t arg0) const = 0;
	virtual bool CanClosePopup() const;
	virtual bool HasClock() const;
	
#if 0
	bool SetLocked(bool arg0, bool arg1);
	void ExitState(EArkStationWorldUIState arg0);
#endif
	
	static inline auto FBitNotArkStationWorldUI = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13A63E0);
	static inline auto FPostInit = PreyFunction<void(ArkStationWorldUI *const _this, IGameObject *_pGameObject)>(0x13A95D0);
	static inline auto FFullSerialize = PreyFunction<void(ArkStationWorldUI *const _this, TSerialize _ser)>(0x13A6D20);
	static inline auto FPostSerialize = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13A9640);
	static inline auto FUpdate = PreyFunction<void(ArkStationWorldUI *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x13AB130);
	static inline auto FProcessEvent = PreyFunction<void(ArkStationWorldUI *const _this, SEntityEvent &_event)>(0x13A97C0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkStationWorldUI *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x13A8660);
	static inline auto FTestInteraction = PreyFunction<bool(ArkStationWorldUI const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x1396B70);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkStationWorldUI const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x13A2150);
	static inline auto FOnStartLookingAt = PreyFunction<void(ArkStationWorldUI *const _this, unsigned _targetId)>(0x13A89E0);
	static inline auto FOnStopLookingAt = PreyFunction<void(ArkStationWorldUI *const _this, unsigned _targetId)>(0x13A8AA0);
	static inline auto FSetupStaticMaterial = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13AB0D0);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkStationWorldUI *const _this, IUIElement *_pUIInstance)>(0x13A9100);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkStationWorldUI *const _this, IUIElement *_pUIInstance)>(0x13A9180);
	static inline auto FOnWorldUIBack = PreyFunction<bool(ArkStationWorldUI *const _this)>(0x13A8E90);
	static inline auto FOnEmailSentChanged = PreyFunction<void(ArkStationWorldUI *const _this, const uint64_t _id)>(0x13A84C0);
	static inline auto FOnEmailRead = PreyFunction<void(ArkStationWorldUI *const _this, const uint64_t _id)>(0x13A8140);
	static inline auto FOnUtilityStateChanged = PreyFunction<void(ArkStationWorldUI *const _this, const uint64_t _id)>(0x13A8C80);
	static inline auto FOnUtilityHiddenChanged = PreyFunction<void(ArkStationWorldUI *const _this, const uint64_t _id)>(0x13A8B40);
	static inline auto FOnUtilityButtonStateChanged = PreyFunction<void(ArkStationWorldUI *const _this, const uint64_t _id)>(0x13A8AF0);
	static inline auto FOnUtilityButtonHiddenChanged = PreyFunction<void(ArkStationWorldUI *const _this, const uint64_t _id)>(0x13A8AF0);
	static inline auto FSetLockedFromScript = PreyFunction<bool(ArkStationWorldUI *const _this, bool _bLocked)>(0x13AAF00);
	static inline auto FOnButtonPress = PreyFunction<void(ArkStationWorldUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13A7AC0);
	static inline auto FOnPasswordSuccess = PreyFunction<void(ArkStationWorldUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13A8780);
	static inline auto FOnSoundEvent = PreyFunction<void(ArkStationWorldUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x139D6D0);
	static inline auto FOnKeypadPress = PreyFunction<void(ArkStationWorldUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13A86E0);
	static inline auto FOnShowDetail = PreyFunction<void(ArkStationWorldUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13A88A0);
	static inline auto FOnSelectPersonnel = PreyFunction<void(ArkStationWorldUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0xA13080);
	static inline auto FOnHackingFinished = PreyFunction<void(ArkStationWorldUI *const _this, bool _bSuccess)>(0x13A85E0);
	static inline auto FKeypadButtonPressed = PreyFunction<bool(ArkStationWorldUI *const _this, string const &_buttonName)>(0x13A7130);
	static inline auto FOpenResultScreen = PreyFunction<void(ArkStationWorldUI *const _this, string const &_title, string const &_body, bool _bError, CArkFlowNodeWorkstationResult *_pFlowNode)>(0x13A9410);
	static inline auto FCloseResultScreen = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13A6B00);
	static inline auto FOpenPopupScreen = PreyFunction<void(ArkStationWorldUI *const _this, string const &_title, string const &_body, float _duration, float _progress, bool _bShowConfirm, bool _bShowCancel, CArkFlowNodeWorkstationPopup *_pFlowNode)>(0x13A91E0);
	static inline auto FClosePopupScreen = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13A6AB0);
	static inline auto FClearKeypad = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13A6810);
	static inline auto FLoadProperties = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13A7470);
	static inline auto FOnReset = PreyFunction<void(ArkStationWorldUI *const _this, bool _bEnteringGameMode)>(0x13A87E0);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkStationWorldUI *const _this, bool _bForce)>(0x13A84F0);
	static inline auto FCountEmails = PreyFunction<std::pair<int,int>(ArkStationWorldUI const *const _this, std::vector<unsigned __int64> const &_emailIds)>(0x13A6B80);
	static inline auto FSetState = PreyFunction<void(ArkStationWorldUI *const _this, EArkStationWorldUIState _state, bool _bForce)>(0x13AAFD0);
	static inline auto FGetUnlockedState = PreyFunction<EArkStationWorldUIState(ArkStationWorldUI const *const _this)>(0x1A42CE0);
	static inline auto FRefreshUI = PreyFunction<void(ArkStationWorldUI *const _this, bool _bReinit, bool _bAnimateIn)>(0x13A9E50);
	static inline auto FRefreshEmailUI = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13A9A20);
	static inline auto FRefreshEmailDetailUI = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13A9850);
	static inline auto FRefreshChildDefinedDetailUI = PreyFunction<void(ArkStationWorldUI *const _this)>(0xA13080);
	static inline auto FRefreshUtilityUI = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13AAC00);
	static inline auto FRefreshUtilityDetailUI = PreyFunction<void(ArkStationWorldUI *const _this)>(0x13AA860);
	static inline auto FRefreshRootMenu = PreyFunction<void(ArkStationWorldUI *const _this)>(0xA13080);
	static inline auto FGetLoginPageType = PreyFunction<const char *(ArkStationWorldUI const *const _this)>(0x13A4DB0);
	static inline auto FEnterChildDefinedState = PreyFunction<void(ArkStationWorldUI *const _this)>(0xA13080);
	static inline auto FSubPageButtonPressed = PreyFunction<void(ArkStationWorldUI *const _this, string const &_buttonName)>(0xA13080);
	static inline auto FCountUtilities = PreyFunction<int(ArkStationWorldUI const *const _this, std::vector<std::shared_ptr<ArkUtility>> const &_utilities)>(0x13A6C40);
	static inline auto FCanClosePopup = PreyFunction<bool(ArkStationWorldUI const *const _this)>(0x1B933B0);
	static inline auto FHasClock = PreyFunction<bool(ArkStationWorldUI const *const _this)>(0x1B933B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkPasswordProtected.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkEmailListener.h>
#include <Prey/GameDll/ark/iface/IArkUtilityListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/worldui/ArkInteractiveScreen.h>
#include <_unknown/IArkDoomClockListener.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

struct ArkInteractionTestResult;
class ArkUtility;
class ArkUtilityButton;
class CArkFlowNodeWorkstationPopup;
class CArkFlowNodeWorkstationResult;
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum class EArkStationType;
struct IEntity;
struct IGameObject;
struct IMaterial;
struct IUIElement;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// ArkStationWorldUI
// Header:  Prey/GameDll/ark/worldui/ArkStationWorldUI.h
class ArkStationWorldUI
	: public ArkInteractiveScreen
	, public ArkUIMenuBase<ArkStationWorldUI>
	, public IArkEmailListener
	, public IArkUtilityListener
	, public IArkDoomClockListener
{ // Size=744 (0x2E8)
public:
	// ArkStationWorldUI::FlowNodeSaveData
	// Header:  Prey/GameDll/ark/worldui/ArkStationWorldUI.h
	struct FlowNodeSaveData
	{ // Size=8 (0x8)
		unsigned m_entityId;
		uint16_t m_flowNodeId;

		void Populate(const IFlowNode::SActivationInfo& _actInfo) { FPopulate(this, _actInfo); }

	#if 0
		FlowNodeSaveData();
		void Serialize(TSerialize _arg0_);
		void Invalidate();
	#endif

		static inline auto FPopulate = PreyFunction<void(ArkStationWorldUI::FlowNodeSaveData* const _this, const IFlowNode::SActivationInfo& _actInfo)>(0x14B42E0);
	};

	EArkStationWorldUIState m_state;
	bool m_bLocked;
	ArkSimpleTimer m_idleTimer;
	ArkPasswordProtected m_passwordProtected;
	uint64_t m_currentId;
	ArkSimpleTimer m_popUpTimeTimer;
	string m_currentCode;
	bool m_bShowingKeypad;
	bool m_bResultOpen;
	bool m_bResultError;
	bool m_bPopupOpen;
	bool m_bShowingPopupCancel;
	bool m_bShowingPopupConfirm;
	string m_resultTitle;
	string m_resultBody;
	string m_popupTitle;
	string m_popupBody;
	int m_whiplashPopupValueCrater;
	int m_whiplashPopupValueLabs;
	int m_whiplashPopupValueMoonworks;
	int m_whiplashPopupValueCrew;
	string m_whiplashPopupLocKey0;
	string m_whiplashPopupLocKey1;
	string m_whiplashPopupLocKey2;
	wstring m_popupBodyWide;
	CArkFlowNodeWorkstationPopup* m_pPopupFlownode;
	CArkFlowNodeWorkstationResult* m_pResultFlownode;
	ArkAudioTrigger m_triggerPowerLoop;
	ArkAudioTrigger m_triggerPowerStop;
	_smart_ptr<IMaterial> m_pScreensaverMaterial;
	_smart_ptr<IMaterial> m_pPowerOffMaterial;
	bool m_bStartsUnlocked;
	int m_baseHackingLevel;
	int m_hackingLevel;
	ArkStationWorldUI::FlowNodeSaveData m_popupFlowNodeSaveData;
	ArkStationWorldUI::FlowNodeSaveData m_resultFlowNodeSaveData;
	EArkStationWorldUIState m_serializeState;

	ArkStationWorldUI();
	virtual ~ArkStationWorldUI();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	virtual void SetupStaticMaterial();
	virtual void OnWorldUIInstanceGranted(IUIElement* _pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement* _pUIInstance);
	virtual bool OnWorldUIBack();
	virtual void OnEmailSentChanged(const uint64_t _id);
	virtual void OnEmailRead(const uint64_t _id);
	virtual void OnUtilityStateChanged(const uint64_t _id);
	virtual void OnUtilityHiddenChanged(const uint64_t _id);
	virtual void OnUtilityButtonStateChanged(const uint64_t _id);
	virtual void OnUtilityButtonHiddenChanged(const uint64_t _id);
	virtual void OnDoomClockEnabled(bool _bEnabled);
	virtual void OnDoomClockPreIncrement(int _level);
	virtual void OnDoomClockIncrement(int _level);
	bool SetLockedFromScript(bool _bLocked) { return FSetLockedFromScript(this, _bLocked); }
	void OnButtonPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnButtonPress(this, _pSender, _event, _args); }
	void OnPasswordSuccess(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPasswordSuccess(this, _pSender, _event, _args); }
	void OnSoundEvent(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnSoundEvent(this, _pSender, _event, _args); }
	void OnKeypadPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnKeypadPress(this, _pSender, _event, _args); }
	void OnShowDetail(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnShowDetail(this, _pSender, _event, _args); }
	virtual void OnSelectPersonnel(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void OnHackingFinished(bool _bSuccess) { FOnHackingFinished(this, _bSuccess); }
	bool KeypadButtonPressed(const string& _buttonName) { return FKeypadButtonPressed(this, _buttonName); }
	void OpenResultScreen(const string& _title, const string& _body, bool _bError, CArkFlowNodeWorkstationResult* _pFlowNode) { FOpenResultScreen(this, _title, _body, _bError, _pFlowNode); }
	void CloseResultScreen() { FCloseResultScreen(this); }
	void OpenPopupScreen(const string& _title, const string& _body, float _duration, float _progress, bool _bShowConfirm, bool _bShowCancel, CArkFlowNodeWorkstationPopup* _pFlowNode) { FOpenPopupScreen(this, _title, _body, _duration, _progress, _bShowConfirm, _bShowCancel, _pFlowNode); }
	void ClosePopupScreen() { FClosePopupScreen(this); }
	void SetWhiplashPopup(int _valueCrater, int _valueLabs, int _valueMoonworks, int _valueCrew, const string& _locKey0, const string& _locKey1, const string& _locKey2) { FSetWhiplashPopup(this, _valueCrater, _valueLabs, _valueMoonworks, _valueCrew, _locKey0, _locKey1, _locKey2); }
	void ClearKeypad() { FClearKeypad(this); }
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void OnEnabledChanged(bool _bForce);
	std::pair<int, int> CountEmails(const std::vector<uint64_t>& _emailIds) const { alignas(std::pair<int, int>) std::byte _return_buf_[sizeof(std::pair<int, int>)]; return *FCountEmails(this, reinterpret_cast<std::pair<int, int>*>(_return_buf_), _emailIds); }
	void SetState(EArkStationWorldUIState _state, bool _bForce) { FSetState(this, _state, _bForce); }
	virtual EArkStationWorldUIState GetUnlockedState() const;
	void RefreshUI(bool _bReinit, bool _bAnimateIn) { FRefreshUI(this, _bReinit, _bAnimateIn); }
	void RefreshEmailUI() { FRefreshEmailUI(this); }
	void RefreshEmailDetailUI() { FRefreshEmailDetailUI(this); }
	virtual void RefreshChildDefinedUI(bool _bAnimateIn) = 0;
	virtual void RefreshChildDefinedDetailUI();
	void RefreshUtilityUI() { FRefreshUtilityUI(this); }
	void RefreshUtilityDetailUI() { FRefreshUtilityDetailUI(this); }
	virtual void RefreshRootMenu();
	virtual const char* GetStationTitle() const = 0;
	virtual const char* GetUtilitiesTitle() const = 0;
	virtual const char* GetLoginPageType() const;
	virtual EArkStationType GetStationType() const = 0;
	virtual bool CanEnterState(EArkStationWorldUIState _state) const = 0;
	virtual void EnterChildDefinedState();
	virtual void SubPageButtonPressed(const string& _buttonName);
	virtual const std::vector<uint64_t>& GetEmails() const = 0;
	virtual const std::vector<std::shared_ptr<ArkUtility>>& GetUtilities() const = 0;
	int CountUtilities(const std::vector<std::shared_ptr<ArkUtility>>& _utilities) const { return FCountUtilities(this, _utilities); }
	virtual const ArkUtility* FindUtility(const uint64_t _id) const = 0;
	virtual const ArkUtilityButton* FindUtilityButton(const uint64_t _id) const = 0;
	virtual uint64_t GetUtilityButtonOwner(const uint64_t _id) const = 0;
	virtual bool CanClosePopup() const;
	virtual bool HasClock() const;
	void BuildWhiplashPopupString() { FBuildWhiplashPopupString(this); }

#if 0
	bool SetLocked(bool _arg0_, bool _arg1_);
	bool IsSecurity() const;
	void ExitState(EArkStationWorldUIState _arg0_);
#endif

	static inline auto FArkStationWorldUIOv1 = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B0A40);
	static inline auto FBitNotArkStationWorldUI = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B0D90);
	static inline auto FPostInit = PreyFunction<void(ArkStationWorldUI* const _this, IGameObject* _pGameObject)>(0x14B43F0);
	static inline auto FFullSerialize = PreyFunction<void(ArkStationWorldUI* const _this, TSerialize _ser)>(0x14B1A60);
	static inline auto FPostSerialize = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B4460);
	static inline auto FUpdate = PreyFunction<void(ArkStationWorldUI* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x14B5FE0);
	static inline auto FProcessEvent = PreyFunction<void(ArkStationWorldUI* const _this, SEntityEvent& _event)>(0x14B4600);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x149FC10);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x14B5F80);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x14B4350);
	static inline auto FOnStartLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0x14B36F0);
	static inline auto FOnStopLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0x14B37B0);
	static inline auto FSetupStaticMaterial = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B5F20);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkStationWorldUI* const _this, IUIElement* _pUIInstance)>(0x14B3E10);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkStationWorldUI* const _this, IUIElement* _pUIInstance)>(0x14B3E90);
	static inline auto FOnWorldUIBack = PreyFunction<bool(ArkStationWorldUI* const _this)>(0x14B3BA0);
	static inline auto FOnEmailSentChanged = PreyFunction<void(IArkEmailListener* const _this, const uint64_t _id)>(0x14B3210);
	static inline auto FOnEmailRead = PreyFunction<void(IArkEmailListener* const _this, const uint64_t _id)>(0x14B2FB0);
	static inline auto FOnUtilityStateChanged = PreyFunction<void(IArkUtilityListener* const _this, const uint64_t _id)>(0x14B3990);
	static inline auto FOnUtilityHiddenChanged = PreyFunction<void(IArkUtilityListener* const _this, const uint64_t _id)>(0x14B3850);
	static inline auto FOnUtilityButtonStateChanged = PreyFunction<void(IArkUtilityListener* const _this, const uint64_t _id)>(0x14B3800);
	static inline auto FOnUtilityButtonHiddenChanged = PreyFunction<void(IArkUtilityListener* const _this, const uint64_t _id)>(0x14B3800);
	static inline auto FOnDoomClockEnabled = PreyFunction<void(IArkDoomClockListener* const _this, bool _bEnabled)>(0x1333E90);
	static inline auto FOnDoomClockPreIncrement = PreyFunction<void(IArkDoomClockListener* const _this, int _level)>(0x1333E90);
	static inline auto FOnDoomClockIncrement = PreyFunction<void(IArkDoomClockListener* const _this, int _level)>(0x14B2F80);
	static inline auto FSetLockedFromScript = PreyFunction<bool(ArkStationWorldUI* const _this, bool _bLocked)>(0x14B5C60);
	static inline auto FOnButtonPress = PreyFunction<void(ArkStationWorldUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14B28F0);
	static inline auto FOnPasswordSuccess = PreyFunction<void(ArkStationWorldUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14B3450);
	static inline auto FOnSoundEvent = PreyFunction<void(ArkStationWorldUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14A0180);
	static inline auto FOnKeypadPress = PreyFunction<void(ArkStationWorldUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14B33B0);
	static inline auto FOnShowDetail = PreyFunction<void(ArkStationWorldUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14B35A0);
	static inline auto FOnSelectPersonnel = PreyFunction<void(ArkStationWorldUI* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1333E90);
	static inline auto FOnHackingFinished = PreyFunction<void(ArkStationWorldUI* const _this, bool _bSuccess)>(0x14B3330);
	static inline auto FKeypadButtonPressed = PreyFunction<bool(ArkStationWorldUI* const _this, const string& _buttonName)>(0x14B1F50);
	static inline auto FOpenResultScreen = PreyFunction<void(ArkStationWorldUI* const _this, const string& _title, const string& _body, bool _bError, CArkFlowNodeWorkstationResult* _pFlowNode)>(0x14B4190);
	static inline auto FCloseResultScreen = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B1840);
	static inline auto FOpenPopupScreen = PreyFunction<void(ArkStationWorldUI* const _this, const string& _title, const string& _body, float _duration, float _progress, bool _bShowConfirm, bool _bShowCancel, CArkFlowNodeWorkstationPopup* _pFlowNode)>(0x14B3EF0);
	static inline auto FClosePopupScreen = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B1780);
	static inline auto FSetWhiplashPopup = PreyFunction<void(ArkStationWorldUI* const _this, int _valueCrater, int _valueLabs, int _valueMoonworks, int _valueCrew, const string& _locKey0, const string& _locKey1, const string& _locKey2)>(0x14B5E30);
	static inline auto FClearKeypad = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B14E0);
	static inline auto FLoadProperties = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B2290);
	static inline auto FOnReset = PreyFunction<void(ArkStationWorldUI* const _this, bool _bEnteringGameMode)>(0x14B34E0);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkStationWorldUI* const _this, bool _bForce)>(0x14B3240);
	static inline auto FCountEmails = PreyFunction<std::pair<int, int>*(const ArkStationWorldUI* const _this, std::pair<int, int>* _return_value_, const std::vector<uint64_t>& _emailIds)>(0x14B18C0);
	static inline auto FSetState = PreyFunction<void(ArkStationWorldUI* const _this, EArkStationWorldUIState _state, bool _bForce)>(0x14B5D30);
	static inline auto FGetUnlockedState = PreyFunction<EArkStationWorldUIState(const ArkStationWorldUI* const _this)>(0x4FD7F0);
	static inline auto FRefreshUI = PreyFunction<void(ArkStationWorldUI* const _this, bool _bReinit, bool _bAnimateIn)>(0x14B4BB0);
	static inline auto FRefreshEmailUI = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B4860);
	static inline auto FRefreshEmailDetailUI = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B4690);
	static inline auto FRefreshChildDefinedDetailUI = PreyFunction<void(ArkStationWorldUI* const _this)>(0x1333E90);
	static inline auto FRefreshUtilityUI = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B5960);
	static inline auto FRefreshUtilityDetailUI = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B55C0);
	static inline auto FRefreshRootMenu = PreyFunction<void(ArkStationWorldUI* const _this)>(0x1333E90);
	static inline auto FGetLoginPageType = PreyFunction<const char* (const ArkStationWorldUI* const _this)>(0x14AF2B0);
	static inline auto FEnterChildDefinedState = PreyFunction<void(ArkStationWorldUI* const _this)>(0x1333E90);
	static inline auto FSubPageButtonPressed = PreyFunction<void(ArkStationWorldUI* const _this, const string& _buttonName)>(0x1333E90);
	static inline auto FCountUtilities = PreyFunction<int(const ArkStationWorldUI* const _this, const std::vector<std::shared_ptr<ArkUtility>>& _utilities)>(0x14B1980);
	static inline auto FCanClosePopup = PreyFunction<bool(const ArkStationWorldUI* const _this)>(0x1A302A0);
	static inline auto FHasClock = PreyFunction<bool(const ArkStationWorldUI* const _this)>(0x1A302A0);
	static inline auto FBuildWhiplashPopupString = PreyFunction<void(ArkStationWorldUI* const _this)>(0x14B13B0);
};
#endif // !MOONCRASH
