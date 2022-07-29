// Header test file for path Prey/GameDll/ark/cystoid/ArkCystoid.h
#include "ArkCystoid.h"
static_assert(sizeof(ArkCystoid) == 568);

#include "ArkCystoidManager.h"
static_assert(sizeof(ArkCystoidManager) == 200);
static_assert(sizeof(ArkCystoidManager::LOSSource) == 24);
static_assert(sizeof(ArkCystoidManager::CystoidInfo) == 24);
static_assert(sizeof(ArkCystoidProperties) == 440);
static_assert(sizeof(ArkCystoidProperties::GravityDependentProperties) == 80);

#include "ArkCystoidNest.h"
static_assert(sizeof(ArkCystoidNest) == 536);

#include "ArkCystoidPotentialTarget.h"
static_assert(sizeof(ArkCystoidPotentialTarget) == 8);

#include "ArkCystoidSignalReceiver.h"
static_assert(sizeof(ArkCystoidSignalReceiver) == 24);
