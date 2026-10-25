// Header test file for path Prey/GameDll/ark/cystoid/

#include "ArkCystoid.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkCystoid) == 568);
#else
static_assert(sizeof(ArkCystoid) == 576);
#endif

#include "ArkCystoidManager.h"
static_assert(sizeof(ArkCystoidManager) == 200);
static_assert(sizeof(ArkCystoidManager::LOSSource) == 24);
static_assert(sizeof(ArkCystoidManager::CystoidInfo) == 24);
static_assert(sizeof(ArkCystoidProperties) == 440);
static_assert(sizeof(ArkCystoidProperties::GravityDependentProperties) == 80);

#include "ArkCystoidNest.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkCystoidNest) == 536);
#else
static_assert(sizeof(ArkCystoidNest) == 576);
#endif

#include "ArkCystoidPotentialTarget.h"
static_assert(sizeof(ArkCystoidPotentialTarget) == 8);

#include "ArkCystoidSignalReceiver.h"
static_assert(sizeof(ArkCystoidSignalReceiver) == 24);
