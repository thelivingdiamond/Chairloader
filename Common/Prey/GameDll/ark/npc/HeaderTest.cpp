// Header test file for path Prey/GameDll/ark/npc/

#include "ArkNpcSpawnedState.h"
static_assert(sizeof(ArkNpcSpawnedState_Alive) == 1);
static_assert(sizeof(ArkNpcSpawnedState_Alert) == 1);
static_assert(sizeof(ArkNpcSpawnedState_Broken) == 16);
static_assert(sizeof(ArkNpcSpawnedState_Dormant) == 32);
static_assert(sizeof(ArkNpcSpawnedState_Dead) == 1);

#include "ArkNpcSpawnManager.h"
static_assert(sizeof(ArkNpcSpawnManager) == 24);
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcSpawnManager::SpawnRequest) == 32);
#else
static_assert(sizeof(ArkNpcSpawnManager::SpawnRequest) == 40);
#endif

#include "ArkNpc.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpc) == 7512);
#else
static_assert(sizeof(ArkNpc) == 8160);
#endif
static_assert(sizeof(ArkNpc::LiftEntitySpawner) == 8);
static_assert(sizeof(ArkNpc::SetSpawnedStateVisitor) == 8);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkAlienGiblet.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkAlienGiblet) == 136);
#else
static_assert(sizeof(CArkAlienGiblet) == 448);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkAttractionManager.h"
static_assert(sizeof(ArkAttractionManager) == 88);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkDistractionEntitySink.h"
static_assert(sizeof(ArkDistractionEntitySink) == 208);
static_assert(sizeof(ArkDistractionEntitySink::DistractionInfo) == 16);
static_assert(sizeof(ArkDistractionEntitySink::EntityClassDistractionInfo) == 24);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkDynamicCalledMimicManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkDynamicCalledMimicManager) == 72);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkDynamicCorpseManager.h"
static_assert(sizeof(ArkDynamicCorpseManager) == 96);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkEncounter.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkEncounter) == 56);
#else
static_assert(sizeof(ArkEncounter) == 64);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkEncounterManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkEncounterManager) == 152);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkEncounterProfile.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkEncounterProfile) == 96);
#else
static_assert(sizeof(ArkEncounterProfile) == 48);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkFlowNodeNpcSetWanderContainer.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkFlowNodeNpcEncounterSetWanderContainer) == 16);
static_assert(sizeof(ArkFlowNodeNpcSetWanderContainer) == 16);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkHumanRandomSpawner.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkHumanRandomSpawner) == 152);
static_assert(sizeof(CArkHumanRandomSpawner::HumanDefinition) == 4);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkLurkManager.h"
static_assert(sizeof(ArkLurkManager) == 24);
static_assert(sizeof(ArkLurkManager::LurkPointInfo) == 16);
static_assert(sizeof(ArkLurkManager::LurkPointInfoContainsLurkPoint) == 4);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkLurkPoint.h"
static_assert(sizeof(CArkLurkPoint) == 72);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNightmareEtherformManager.h"
static_assert(sizeof(ArkNightmareEtherformManager) == 80);
static_assert(sizeof(ArkNightmareEtherformManager::EtherFormTrackTime) == 16);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNightmareSpawnerFsm.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNightmareSpawnerFsm) == 240);
static_assert(sizeof(ArkNightmareSpawnerState_SpawnNightmare) == 8);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNightmareSpawnManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNightmareSpawnManager) == 312);
static_assert(sizeof(ArkNightmareSpawnManager::NightmareInfo) == 16);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcAreaManager.h"
static_assert(sizeof(ArkNpcAreaManager) == 184);
static_assert(sizeof(ArkNpcAreaManager::AreaInfo) == 64);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBody.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBody) == 6128);
#else
static_assert(sizeof(ArkNpcBody) == 6344);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcConeDamageDealer.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcConeDamageDealer) == 112);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcDialogSpeaker.h"
static_assert(sizeof(ArkNpcDialogSpeaker) == 656);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcLifecycle.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcLifecycle) == 720);
#else
static_assert(sizeof(ArkNpcLifecycle) == 728);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcManager) == 1056);
static_assert(sizeof(ArkNpcManager::ArkNpcManagerValidationChangeInfo) == 24);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcMeleeDamageDealer.h"
static_assert(sizeof(ArkNpcMeleeDamageDealer) == 88);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcPlayer.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcPlayer) == 9328);
#else
static_assert(sizeof(ArkNpcPlayer) == 9448);
#endif
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcPlayer::ArkWeaponImpulseSettings) == 36);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcSignalAccumulatorManager.h"
static_assert(sizeof(ArkNpcSignalAccumulator) == 88);
static_assert(sizeof(ArkNpcSignalAccumulatorManager) == 24);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcSignalReceiver.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcSignalReceiver) == 64);
static_assert(sizeof(ArkNpcSignalReceiver::SignalAccumulator) == 32);
static_assert(sizeof(ArkNpcSignalReceiver::SignalAccumulator::SAItem) == 176);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcSpawnCystoid.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkNpcSpawnCystoid) == 88);
#else
static_assert(sizeof(CArkNpcSpawnCystoid) == 96);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcSpawner.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkNpcSpawner) == 96);
#else
static_assert(sizeof(CArkNpcSpawner) == 120);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcSpawnGroup.h"
static_assert(sizeof(CArkNpcSpawnGroup) == 64);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcSpawnTyphonNest.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkNpcSpawnTyphonNest) == 96);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcStartFatalityDeathProcClip.h"
static_assert(sizeof(ArkNpcStartFatalityDeathProcClip) == 48);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcThrowPropManager.h"
static_assert(sizeof(ArkNpcThrowPropManager) == 112);
static_assert(sizeof(ArkNpcThrowPropManager::QueryParams) == 36);
static_assert(sizeof(ArkNpcThrowPropManager::DeferredRayCastImpl) == 8);
static_assert(sizeof(ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>) == 344);
static_assert(sizeof(ArkNpcThrowPropManager::PropData) == 392);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcUnreachableTargetingManager.h"
#ifndef MOONCRASH
static_assert(sizeof(UnreachableTargetingSearchArea) == 192);
static_assert(sizeof(ArkNpcUnreachableTargetingManager) == 1608);
#else
static_assert(sizeof(UnreachableTargetingSearchArea) == 200);
static_assert(sizeof(ArkNpcUnreachableTargetingManager) == 1672);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcWeapon.h"
static_assert(sizeof(CArkNpcWeapon) == 192);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkPatrolManager.h"
static_assert(sizeof(ArkPatrolManager) == 184);
static_assert(sizeof(ArkPatrolState) == 16);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkRetreatManager.h"
static_assert(sizeof(ArkRetreatManager) == 64);
static_assert(sizeof(ArkRetreatManager::RetreatEntityInfo) == 16);
static_assert(sizeof(ArkRetreatManager::RetreatEntityInfoContainsEntity) == 4);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkRetreatPoint.h"
static_assert(sizeof(CArkRetreatPoint) == 64);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "CArkAttraction.h"
static_assert(sizeof(CArkAttraction) == 96);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "CArkDistraction.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkDistraction) == 232);
#else
static_assert(sizeof(CArkDistraction) == 248);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNightmareSpawnerFsmBase.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNightmareSpawnerFsmBase_template_<void>) == 32);
static_assert(sizeof(ArkNightmareSpawnerState_NoNightmare) == 1);
static_assert(sizeof(ArkNightmareSpawnerState_SpawnNightmare) == 8);
static_assert(sizeof(ArkNightmareSpawnerState_SpawnEffects) == 12);
static_assert(sizeof(ArkNightmareSpawnerState_SpawnedNightmare) == 1);
#endif
#endif
