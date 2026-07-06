// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/ark/player/ability/
#include "ArkAbilityComponent.h"
static_assert(sizeof(ArkAbilityComponent) == 72);

#include "ArkAbilityData.h"
static_assert(sizeof(ArkAbilityData) == 112);
static_assert(sizeof(ArkResearchTopicData) == 40);

#include "ArkAbilityScanData.h"
static_assert(sizeof(ArkAbilityScanData) == 16);
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/player/ability/
#include "ArkAbilityComponent.h"
static_assert(sizeof(ArkAbilityComponent) == 96);

#include "ArkAbilityData.h"
static_assert(sizeof(ArkAbilityData) == 112);
static_assert(sizeof(ArkResearchTopicData) == 40);

#include "ArkAbilityScanData.h"
static_assert(sizeof(ArkAbilityScanData) == 16);
#endif // !MOONCRASH
