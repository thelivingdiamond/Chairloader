// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/ui/readyroom/
#include "ArkCharacterSelect.h"
static_assert(sizeof(ArkCharacterSelect) == 136);

#include "ArkChipsetStore.h"
static_assert(sizeof(ArkChipsetStore) == 72);
static_assert(sizeof(ArkChipsetStore::ChipsetEntry) == 48);

#include "ArkFlowReadyRoom.h"
static_assert(sizeof(ArkFlowEnablePlayerSimulationReset) == 16);
static_assert(sizeof(ArkFlowForceSatellite) == 16);
static_assert(sizeof(ArkFlowReadyRoom) == 16);
static_assert(sizeof(ArkFlowReadyRoomListener) == 64);
static_assert(sizeof(ArkFlowReadyRoomRequest) == 64);

#include "ArkInventoryStore.h"
static_assert(sizeof(ArkInventoryStore) == 224);
static_assert(sizeof(ArkInventoryStore::ItemForSale) == 80);

#include "ArkProgressPage.h"
static_assert(sizeof(ArkProgressPage) == 40);

#include "ArkReadyRoomManager.h"
static_assert(sizeof(ArkReadyRoomManager) == 1048);

#include "ArkScorecard.h"
static_assert(sizeof(ArkScorecard) == 88);
static_assert(sizeof(ArkScorecard::ScorecardEntry) == 24);

#include "ArkSimulationLaunchPage.h"
static_assert(sizeof(ArkSimulationLaunchPage) == 40);
#endif // MOONCRASH
