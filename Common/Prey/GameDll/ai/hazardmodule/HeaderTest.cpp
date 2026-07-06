// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ai/hazardmodule/
#include "HazardModule.h"
static_assert(sizeof(HazardSystem::HazardModule) == 112);

#include "hazard.h"
static_assert(sizeof(HazardSystem::HazardCollisionResult) == 16);
static_assert(sizeof(HazardSystem::HazardData) == 24);

#include "hazardprojectile.h"
static_assert(sizeof(HazardSystem::HazardDataProjectile) == 104);

#include "hazardraycast.h"
static_assert(sizeof(HazardSystem::HazardDataRayCast) == 56);

#include "hazardsphere.h"
static_assert(sizeof(HazardSystem::HazardDataSphere) == 48);
#endif // MOONCRASH
