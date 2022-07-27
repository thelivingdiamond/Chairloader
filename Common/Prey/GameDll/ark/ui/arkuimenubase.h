// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IUIElementEventListener.h>
//#include <Prey/CrySystem/Scaleform/IFlashUI.h>

class ArkBrightnessMenu;
class ArkDockingStation;
class ArkFabricator;
class ArkFocusModeUIComponent;
class ArkGenderSelectMenu;
class ArkKeyWorldUI;
class ArkKioskBase;
class ArkLauncherMenu;
class ArkModalDialogBase;
class ArkNoteUI;
class ArkOperatorDispenser;
class ArkPDAComponent;
class ArkPauseMenu;
class ArkPlayerUIComponent;
class ArkRecycler;
class ArkSaveLoadMenu;
class ArkStationWorldUI;
class ArkTutorialMenu;
class ArkUIOptionMenuBase;
class CArkInventoryUI;
class CArkPDAFabricationPlans;
class CArkPDAPageAbilities;
class CArkPDAPageAudioLogs;
class CArkPDAPageEmails;
class CArkPDAPageEquipmentMods;
class CArkPDAPageInventory;
class CArkPDAPageLevelMap;
class CArkPDAPageObjectives;
class CArkPDAPageStationMap;
class CArkUIHUD;
class CCryName;
struct IEntity;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/arkuimenubase.h
template <typename T>
class ArkUIMenuBase : public IUIElementEventListener // Id=8016FCE Size=24
{
public:
	using TUIEventHandler = void (*)(IUIElement *const , SUIEventDesc const &, SUIArguments const &);
	using TUIEventHandlers = std::map<CCryName, TUIEventHandler>;
	
	TUIEventHandlers m_handlers;
	
#if 0
	virtual void OnUIEvent(IUIElement *_pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	void AddHandler(CCryName arg0, void (*const arg1)(IUIElement *const , SUIEventDesc const &, SUIArguments const &));
	void AddHandler(const char *const _eventName, void (*const _handler)(IUIElement *const , SUIEventDesc const &, SUIArguments const &));
	static void PlayAudioTrigger(IEntity *const arg0, SUIArguments const &arg1);
	void OnForceFeedback(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
#endif
};

