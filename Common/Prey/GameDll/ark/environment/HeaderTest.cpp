// Header test file for path Prey/GameDll/ark/environment/ArkApexTentacle.h
#if 0
#include "ArkApexTentacle.h"
static_assert(sizeof(ArkApexTentacle) == 1264);
static_assert(sizeof(ArkApexTentacle::SegmentInfo) == 40);
static_assert(sizeof(ArkApexTentacle::HazardTarget) == 24);
static_assert(sizeof(ArkApexTentacle::Breadcrumb) == 24);

#include "ArkApexTentacleHead.h"
static_assert(sizeof(ArkApexTentacleHeadSignalReceiver) == 24);
static_assert(sizeof(ArkApexTentacleHead) == 96);

#include "ArkApexTentacleSpawner.h"
static_assert(sizeof(ArkApexTentacleSpawner) == 240);
static_assert(sizeof(ArkApexTentacleSpawner::TentaclesToPlace) == 16);
static_assert(sizeof(ArkApexTentacleSpawner::SpawnedTentacle) == 20);
static_assert(sizeof(ArkApexTentacleSpawner::RespawnData) == 16);
static_assert(sizeof(ArkApexTentacleSpawner::SpawnProbability) == 16);

#include "ArkAreaHazard.h"
static_assert(sizeof(ArkAreaHazard) == 352);

#include "ArkCargoContainer.h"
static_assert(sizeof(ArkCargoContainer) == 184);

#include "ArkChargeTrap.h"
static_assert(sizeof(ArkChargeTrap) == 304);

#include "ArkClock.h"
static_assert(sizeof(ArkClock) == 96);

#include "ArkElectricalBox.h"
static_assert(sizeof(ArkElectricalBox) == 1032);

#include "ArkEnvironmentalHazard.h"
static_assert(sizeof(ArkEnvironmentalHazard) == 168);

#include "ArkEnvironmentalObject.h"
static_assert(sizeof(ArkEnvironmentalObject) == 88);

#include "ArkEnvironmentalObjectSignalReceiver.h"
static_assert(sizeof(ArkEnvironmentalObjectSignalReceiver) == 24);

#include "ArkExplosiveTank.h"
static_assert(sizeof(ArkExplosiveTank) == 536);

#include "ArkLeakable.h"
static_assert(sizeof(ArkLeakable) == 376);
static_assert(sizeof(ArkLeakable::LeakInfo) == 44);

#include "ArkSurfaceHazard.h"
static_assert(sizeof(ArkSurfaceHazard) == 768);

#include "ArkTelescope.h"
static_assert(sizeof(ArkTelescope) == 160);

#include "ArkTrackingCamera.h"
static_assert(sizeof(ArkTrackingCamera) == 360);
#endif
