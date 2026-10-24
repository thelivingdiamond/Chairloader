// Header test file for path Prey/GameDll/ark/environment/

#include "ArkApexTentacle.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkApexTentacle) == 1264);
#else
static_assert(sizeof(ArkApexTentacle) == 1352);
#endif
static_assert(sizeof(ArkApexTentacle::SegmentInfo) == 40);
static_assert(sizeof(ArkApexTentacle::HazardTarget) == 24);
static_assert(sizeof(ArkApexTentacle::Breadcrumb) == 24);
#ifdef MOONCRASH
static_assert(sizeof(ArkApexTentacle::OverlapCheck) == 12);
#endif

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
#ifndef MOONCRASH
static_assert(sizeof(ArkAreaHazard) == 352);
#else
static_assert(sizeof(ArkAreaHazard) == 360);
#endif

#include "ArkCargoContainer.h"
static_assert(sizeof(ArkCargoContainer) == 184);

#include "ArkChargeTrap.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkChargeTrap) == 304);
#else
static_assert(sizeof(ArkChargeTrap) == 368);
#endif

#include "ArkClock.h"
static_assert(sizeof(ArkClock) == 96);

#include "ArkElectricalBox.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkElectricalBox) == 1032);
#else
static_assert(sizeof(ArkElectricalBox) == 1064);
#endif

#include "ArkEnvironmentalHazard.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkEnvironmentalHazard) == 168);
#else
static_assert(sizeof(ArkEnvironmentalHazard) == 176);
#endif

#include "ArkEnvironmentalObject.h"
static_assert(sizeof(ArkEnvironmentalObject) == 88);

#include "ArkEnvironmentalObjectSignalReceiver.h"
static_assert(sizeof(ArkEnvironmentalObjectSignalReceiver) == 24);

#include "ArkExplosiveTank.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkExplosiveTank) == 536);
#else
static_assert(sizeof(ArkExplosiveTank) == 544);
#endif

#include "ArkLeakable.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkLeakable) == 376);
#else
static_assert(sizeof(ArkLeakable) == 384);
#endif
static_assert(sizeof(ArkLeakable::LeakInfo) == 44);

#include "ArkSurfaceHazard.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkSurfaceHazard) == 768);
#else
static_assert(sizeof(ArkSurfaceHazard) == 792);
#endif

#include "ArkTelescope.h"
static_assert(sizeof(ArkTelescope) == 160);

#include "ArkTrackingCamera.h"
static_assert(sizeof(ArkTrackingCamera) == 360);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkApexTentacleNest.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkApexTentacleNest) == 632);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkApexTentaclePinholeSpawner.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkApexTentaclePinholeSpawner) == 736);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkApexTentacleSpawnerBase.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkApexTentacleSpawnerBase) == 120);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkCondenser.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkCondenser) == 264);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkCondenserCell.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkCondenserCell) == 688);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNavLinkOwner.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNavLinkOwner) == 136);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkSurfaceHazardLightManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkSurfaceHazardLightManager) == 192);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTyphonGate.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTyphonGate) == 968);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTyphonGateCap.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTyphonGateCap) == 648);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTyphonNest.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTyphonNest) == 512);
#endif
#endif
