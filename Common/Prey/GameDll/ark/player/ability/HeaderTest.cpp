// Header test file for path Prey/GameDll/ark/player/ability/

#include "ArkAbilityComponent.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkAbilityComponent) == 72);
#else
static_assert(sizeof(ArkAbilityComponent) == 96);
#endif

#include "ArkAbilityData.h"
static_assert(sizeof(ArkAbilityData) == 112);
static_assert(sizeof(ArkResearchTopicData) == 40);

#include "ArkAbilityScanData.h"
static_assert(sizeof(ArkAbilityScanData) == 16);
