// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/ark/worldui/ArkDockingStation.h
#include "ArkDockingStation.h"
static_assert(sizeof(ArkDockingStation) == 568);

#include "ArkGenericElevatorKiosk.h"
static_assert(sizeof(ArkGenericElevatorKiosk) == 600);
static_assert(sizeof(ArkGenericElevatorKiosk::ArkElevatorKioskButton) == 24);

#include "ArkInteractiveScreen.h"
static_assert(sizeof(ArkInteractiveScreen) == 456);
static_assert(sizeof(ArkWorldUI) == 64);

#include "ArkKeycardReader.h"
static_assert(sizeof(ArkKeycardReader) == 576);

#include "ArkKeypad.h"
static_assert(sizeof(ArkKeypad) == 600);

#include "ArkKeyWorldUI.h"
static_assert(sizeof(ArkKeyWorldUI) == 536);

#include "ArkKiosk.h"
static_assert(sizeof(ArkKiosk) == 600);
static_assert(sizeof(ArkKiosk::ArkKioskButton) == 24);

#include "ArkKioskBase.h"
static_assert(sizeof(ArkKioskBase) == 488);

#include "ArkLevelTransitionDoor.h"
static_assert(sizeof(ArkLevelTransitionDoor) == 632);

#include "ArkMultipleChoiceKiosk.h"
static_assert(sizeof(ArkMultipleChoiceKiosk) == 552);

#include "ArkSecurityStationScreen.h"
static_assert(sizeof(ArkSecurityStationScreen) == 688);

#include "ArkStationWorldUI.h"
static_assert(sizeof(ArkStationWorldUI) == 664);
static_assert(sizeof(ArkStationWorldUI::FlowNodeSaveData) == 8);

#include "ArkWorkstationScreen.h"
static_assert(sizeof(ArkWorkstationScreen) == 680);

#include "ArkWorldUIOwner.h"
static_assert(sizeof(ArkWorldUIOwner) == 144);
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/worldui/
#include "ArkDockingStation.h"
static_assert(sizeof(ArkDockingStation) == 592);

#include "ArkGenericElevatorKiosk.h"
static_assert(sizeof(ArkGenericElevatorKiosk) == 624);
static_assert(sizeof(ArkGenericElevatorKiosk::ArkElevatorKioskButton) == 24);

#include "ArkInteractiveScreen.h"
static_assert(sizeof(ArkInteractiveScreen) == 480);

#include "ArkKeyWorldUI.h"
static_assert(sizeof(ArkKeyWorldUI) == 560);

#include "ArkKeycardReader.h"
static_assert(sizeof(ArkKeycardReader) == 608);

#include "ArkKeypad.h"
static_assert(sizeof(ArkKeypad) == 632);

#include "ArkKiosk.h"
static_assert(sizeof(ArkKiosk) == 624);
static_assert(sizeof(ArkKiosk::ArkKioskButton) == 24);

#include "ArkKioskBase.h"
static_assert(sizeof(ArkKioskBase) == 512);

#include "ArkLevelTransitionDoor.h"
static_assert(sizeof(ArkLevelTransitionDoor) == 664);

#include "ArkMultipleChoiceKiosk.h"
static_assert(sizeof(ArkMultipleChoiceKiosk) == 576);

#include "ArkSecurityStationScreen.h"
static_assert(sizeof(ArkSecurityStationScreen) == 776);

#include "ArkStationWorldUI.h"
static_assert(sizeof(ArkStationWorldUI) == 744);
static_assert(sizeof(ArkStationWorldUI::FlowNodeSaveData) == 8);

#include "ArkTyphonGateScreen.h"
static_assert(sizeof(ArkTyphonGateScreen) == 528);

#include "ArkWorkstationScreen.h"
static_assert(sizeof(ArkWorkstationScreen) == 768);

#include "ArkWorldUI.h"
static_assert(sizeof(ArkWorldUI) == 64);

#include "ArkWorldUIManager.h"
static_assert(sizeof(ArkWorldUIManager) == 280);

#include "ArkWorldUIOwner.h"
static_assert(sizeof(ArkWorldUIOwner) == 168);
#endif // !MOONCRASH
