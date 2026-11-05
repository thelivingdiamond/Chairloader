// Header test file for path Prey/GameDll/ark/worldui/

#include "ArkDockingStation.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkDockingStation) == 568);
#else
static_assert(sizeof(ArkDockingStation) == 592);
#endif

#include "ArkGenericElevatorKiosk.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkGenericElevatorKiosk) == 600);
#else
static_assert(sizeof(ArkGenericElevatorKiosk) == 624);
#endif
static_assert(sizeof(ArkGenericElevatorKiosk::ArkElevatorKioskButton) == 24);

#include "ArkInteractiveScreen.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkInteractiveScreen) == 456);
#else
static_assert(sizeof(ArkInteractiveScreen) == 480);
#endif
#ifndef MOONCRASH
static_assert(sizeof(ArkWorldUI) == 64);
#endif

#include "ArkKeycardReader.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkKeycardReader) == 576);
#else
static_assert(sizeof(ArkKeycardReader) == 608);
#endif

#include "ArkKeypad.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkKeypad) == 600);
#else
static_assert(sizeof(ArkKeypad) == 632);
#endif

#include "ArkKeyWorldUI.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkKeyWorldUI) == 536);
#else
static_assert(sizeof(ArkKeyWorldUI) == 560);
#endif

#include "ArkKiosk.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkKiosk) == 600);
#else
static_assert(sizeof(ArkKiosk) == 624);
#endif
static_assert(sizeof(ArkKiosk::ArkKioskButton) == 24);

#include "ArkKioskBase.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkKioskBase) == 488);
#else
static_assert(sizeof(ArkKioskBase) == 512);
#endif

#include "ArkLevelTransitionDoor.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkLevelTransitionDoor) == 632);
#else
static_assert(sizeof(ArkLevelTransitionDoor) == 664);
#endif

#include "ArkMultipleChoiceKiosk.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkMultipleChoiceKiosk) == 552);
#else
static_assert(sizeof(ArkMultipleChoiceKiosk) == 576);
#endif

#include "ArkSecurityStationScreen.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkSecurityStationScreen) == 688);
#else
static_assert(sizeof(ArkSecurityStationScreen) == 776);
#endif

#include "ArkStationWorldUI.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkStationWorldUI) == 664);
#else
static_assert(sizeof(ArkStationWorldUI) == 744);
#endif
static_assert(sizeof(ArkStationWorldUI::FlowNodeSaveData) == 8);

#include "ArkWorkstationScreen.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkWorkstationScreen) == 680);
#else
static_assert(sizeof(ArkWorkstationScreen) == 768);
#endif

#include "ArkWorldUIOwner.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkWorldUIOwner) == 144);
#else
static_assert(sizeof(ArkWorldUIOwner) == 168);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTyphonGateScreen.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTyphonGateScreen) == 528);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkWorldUI.h"
#endif
