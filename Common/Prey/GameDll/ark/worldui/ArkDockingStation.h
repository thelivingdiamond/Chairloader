// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/worldui/ArkInteractiveScreen.h>

class ArkCargoContainer;
struct ArkInteractionInfo;
struct ArkInteractionTestResult;
struct IEntity;
struct IUIElement;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/worldui/ArkDockingStation.h
class ArkDockingStation : public ArkInteractiveScreen, public ArkUIMenuBase<ArkDockingStation> // Id=801970A Size=568
{
public:
	unsigned m_cargoBay1Transition;
	unsigned m_cargoBay2Transition;
	std::vector<unsigned int> m_containers;
	ArkSimpleTimer m_searchingTimer;
	ArkSimpleTimer m_transitTimer;
	string m_currentCode;
	
	enum class EArkCurrentPage
	{
		keypad = 0,
		cargoBays = 1,
		help = 2,
	};

	ArkDockingStation::EArkCurrentPage m_currentPage;
	unsigned m_currentlySelectedContainer;
	ArkAudioTrigger m_triggerPowerLoop;
	_smart_ptr<IMaterial> m_pScreensaverMaterial;
	_smart_ptr<IMaterial> m_pPowerOffMaterial;
	
	ArkDockingStation();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual void SetupStaticMaterial();
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement *_pUIInstance);
	virtual bool OnWorldUIBack();
	bool KeypadButtonPressed(string const &_buttonName) { return FKeypadButtonPressed(this,_buttonName); }
	void ContainerTransitFinished(EArkDockingBay _dockedBay) { FContainerTransitFinished(this,_dockedBay); }
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void OnEnabledChanged(bool _bForce);
	void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnButtonPress(this,_pSender,_event,_args); }
	void OnShowDetail(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnShowDetail(this,_pSender,_event,_args); }
	void OnKeypadPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnKeypadPress(this,_pSender,_event,_args); }
	void OnSoundEvent(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSoundEvent(this,_pSender,_event,_args); }
	void RefreshUI() { FRefreshUI(this); }
	void ClearKeypad() { FClearKeypad(this); }
	void ShowContainerControls() { FShowContainerControls(this); }
	void ShowSearchingProgress() { FShowSearchingProgress(this); }
	void ShowTransitProgress() { FShowTransitProgress(this); }
	void RefreshCargoBaysUI() { FRefreshCargoBaysUI(this); }
	bool CanUndockBay(EArkDockingBay _dockedBay) const { return FCanUndockBay(this,_dockedBay); }
	void UndockBay(EArkDockingBay _dockedBay) { FUndockBay(this,_dockedBay); }
	void BeginTransit(float _transitDuration) { FBeginTransit(this,_transitDuration); }
	virtual bool HasClock() const;
	
#if 0
	float GetElapsedTransitTime() const;
	void HandleScriptEvent(const char *arg0);
	ArkCargoContainer *GetContainerInBay(EArkDockingBay arg0) const;
#endif
	
	static inline auto FFullSerialize = PreyFunction<void(ArkDockingStation *const _this, TSerialize _ser)>(0x13945D0);
	static inline auto FPostSerialize = PreyFunction<void(ArkDockingStation *const _this)>(0x1395F70);
	static inline auto FProcessEvent = PreyFunction<void(ArkDockingStation *const _this, SEntityEvent &_event)>(0x1395F90);
	static inline auto FUpdate = PreyFunction<void(ArkDockingStation *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1396CD0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkDockingStation *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x13A8660);
	static inline auto FTestInteraction = PreyFunction<bool(ArkDockingStation const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x1396B70);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkDockingStation const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1395F10);
	static inline auto FSetupStaticMaterial = PreyFunction<void(ArkDockingStation *const _this)>(0x13968A0);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkDockingStation *const _this, IUIElement *_pUIInstance)>(0x1395EA0);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkDockingStation *const _this, IUIElement *_pUIInstance)>(0x139D8A0);
	static inline auto FOnWorldUIBack = PreyFunction<bool(ArkDockingStation *const _this)>(0x1395DB0);
	static inline auto FKeypadButtonPressed = PreyFunction<bool(ArkDockingStation *const _this, string const &_buttonName)>(0x1394950);
	static inline auto FContainerTransitFinished = PreyFunction<void(ArkDockingStation *const _this, EArkDockingBay _dockedBay)>(0x1394520);
	static inline auto FLoadProperties = PreyFunction<void(ArkDockingStation *const _this)>(0x1394C90);
	static inline auto FOnReset = PreyFunction<void(ArkDockingStation *const _this, bool _bEnteringGameMode)>(0x1395860);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkDockingStation *const _this, bool _bForce)>(0x1395540);
	static inline auto FOnButtonPress = PreyFunction<void(ArkDockingStation *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13951E0);
	static inline auto FOnShowDetail = PreyFunction<void(ArkDockingStation *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1395900);
	static inline auto FOnKeypadPress = PreyFunction<void(ArkDockingStation *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13957C0);
	static inline auto FOnSoundEvent = PreyFunction<void(ArkDockingStation *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x139D6D0);
	static inline auto FRefreshUI = PreyFunction<void(ArkDockingStation *const _this)>(0x1396340);
	static inline auto FClearKeypad = PreyFunction<void(ArkDockingStation *const _this)>(0x1394280);
	static inline auto FShowContainerControls = PreyFunction<void(ArkDockingStation *const _this)>(0x1396900);
	static inline auto FShowSearchingProgress = PreyFunction<void(ArkDockingStation *const _this)>(0x1396A10);
	static inline auto FShowTransitProgress = PreyFunction<void(ArkDockingStation *const _this)>(0x1396AA0);
	static inline auto FRefreshCargoBaysUI = PreyFunction<void(ArkDockingStation *const _this)>(0x1396200);
	static inline auto FCanUndockBay = PreyFunction<bool(ArkDockingStation const *const _this, EArkDockingBay _dockedBay)>(0x1394220);
	static inline auto FUndockBay = PreyFunction<void(ArkDockingStation *const _this, EArkDockingBay _dockedBay)>(0x1396BD0);
	static inline auto FBeginTransit = PreyFunction<void(ArkDockingStation *const _this, float _transitDuration)>(0x13941D0);
	static inline auto FHasClock = PreyFunction<bool(ArkDockingStation const *const _this)>(0x1B933B0);
};

