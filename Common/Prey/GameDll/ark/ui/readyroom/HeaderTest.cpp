// Header test file for path Prey/GameDll/ark/ui/readyroom/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkCharacterSelect.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkCharacterSelect) == 136);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkChipsetStore.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkChipsetStore) == 72);
static_assert(sizeof(ArkChipsetStore::ChipsetEntry) == 48);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkFlowReadyRoom.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkFlowEnablePlayerSimulationReset) == 16);
static_assert(sizeof(ArkFlowForceSatellite) == 16);
static_assert(sizeof(ArkFlowReadyRoom) == 16);
static_assert(sizeof(ArkFlowReadyRoomListener) == 64);
static_assert(sizeof(ArkFlowReadyRoomRequest) == 64);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkInventoryStore.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkInventoryStore) == 224);
static_assert(sizeof(ArkInventoryStore::ItemForSale) == 80);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkProgressPage.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkProgressPage) == 40);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkReadyRoomManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkReadyRoomManager) == 1048);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkScorecard.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkScorecard) == 88);
static_assert(sizeof(ArkScorecard::ScorecardEntry) == 24);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkSimulationLaunchPage.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkSimulationLaunchPage) == 40);
#endif
#endif
