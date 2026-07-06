// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/environment/
#include "ArkApexTentacle.h"
static_assert(sizeof(ArkApexTentacle) == 1352);
static_assert(sizeof(ArkApexTentacle::Breadcrumb) == 24);
static_assert(sizeof(ArkApexTentacle::HazardTarget) == 24);
static_assert(sizeof(ArkApexTentacle::OverlapCheck) == 12);
static_assert(sizeof(ArkApexTentacle::SegmentInfo) == 40);

#include "ArkApexTentacleHead.h"
static_assert(sizeof(ArkApexTentacleHead) == 96);
static_assert(sizeof(ArkApexTentacleHeadSignalReceiver) == 24);

#include "ArkApexTentacleNest.h"
static_assert(sizeof(ArkApexTentacleNest) == 632);

#include "ArkApexTentaclePinholeSpawner.h"
static_assert(sizeof(ArkApexTentaclePinholeSpawner) == 736);

#include "ArkApexTentacleSpawner.h"
static_assert(sizeof(ArkApexTentacleSpawner) == 240);
static_assert(sizeof(ArkApexTentacleSpawner::RespawnData) == 16);
static_assert(sizeof(ArkApexTentacleSpawner::SpawnProbability) == 16);
static_assert(sizeof(ArkApexTentacleSpawner::SpawnedTentacle) == 20);
static_assert(sizeof(ArkApexTentacleSpawner::TentaclesToPlace) == 16);

#include "ArkApexTentacleSpawnerBase.h"
static_assert(sizeof(ArkApexTentacleSpawnerBase) == 120);

#include "ArkAreaHazard.h"
static_assert(sizeof(ArkAreaHazard) == 360);

#include "ArkCargoContainer.h"
static_assert(sizeof(ArkCargoContainer) == 184);

#include "ArkChargeTrap.h"
static_assert(sizeof(ArkChargeTrap) == 368);

#include "ArkClock.h"
static_assert(sizeof(ArkClock) == 96);

#include "ArkCondenser.h"
static_assert(sizeof(ArkCondenser) == 264);

#include "ArkCondenserCell.h"
static_assert(sizeof(ArkCondenserCell) == 688);

#include "ArkElectricalBox.h"
static_assert(sizeof(ArkElectricalBox) == 1064);

#include "ArkEnvironmentalHazard.h"
static_assert(sizeof(ArkEnvironmentalHazard) == 176);

#include "ArkEnvironmentalObject.h"
static_assert(sizeof(ArkEnvironmentalObject) == 88);

#include "ArkEnvironmentalObjectSignalReceiver.h"
static_assert(sizeof(ArkEnvironmentalObjectSignalReceiver) == 24);

#include "ArkExplosiveTank.h"
static_assert(sizeof(ArkExplosiveTank) == 544);

#include "ArkLeakable.h"
static_assert(sizeof(ArkLeakable) == 384);
static_assert(sizeof(ArkLeakable::LeakInfo) == 44);

#include "ArkNavLinkOwner.h"
static_assert(sizeof(ArkNavLinkOwner) == 136);

#include "ArkSurfaceHazard.h"
static_assert(sizeof(ArkSurfaceHazard) == 792);

#include "ArkSurfaceHazardLightManager.h"
static_assert(sizeof(ArkSurfaceHazardLightManager) == 192);

#include "ArkTelescope.h"
static_assert(sizeof(ArkTelescope) == 160);

#include "ArkTrackingCamera.h"
static_assert(sizeof(ArkTrackingCamera) == 360);

#include "ArkTyphonGate.h"
static_assert(sizeof(ArkTyphonGate) == 968);

#include "ArkTyphonGateCap.h"
static_assert(sizeof(ArkTyphonGateCap) == 648);

#include "ArkTyphonNest.h"
static_assert(sizeof(ArkTyphonNest) == 512);
#endif // !MOONCRASH
