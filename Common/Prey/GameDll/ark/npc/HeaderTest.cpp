// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/arkaliengiblet.h
#include "ArkNpcSpawnedState.h"
static_assert(sizeof(ArkNpcSpawnedState_Alive) == 1);
static_assert(sizeof(ArkNpcSpawnedState_Alert) == 1);
static_assert(sizeof(ArkNpcSpawnedState_Broken) == 16);
static_assert(sizeof(ArkNpcSpawnedState_Dormant) == 32);
static_assert(sizeof(ArkNpcSpawnedState_Dead) == 1);

#include "ArkNpcSpawnManager.h"
static_assert(sizeof(ArkNpcSpawnManager) == 24);
static_assert(sizeof(ArkNpcSpawnManager::SpawnRequest) == 32);

#include "ArkNpc.h"
static_assert(sizeof(ArkNpc) == 7512);
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/
#include "ArkAlienGiblet.h"
static_assert(sizeof(CArkAlienGiblet) == 448);

#include "ArkAttractionManager.h"
static_assert(sizeof(ArkAttractionManager) == 88);

#include "ArkDistractionEntitySink.h"
static_assert(sizeof(ArkDistractionEntitySink) == 208);
static_assert(sizeof(ArkDistractionEntitySink::DistractionInfo) == 16);
static_assert(sizeof(ArkDistractionEntitySink::EntityClassDistractionInfo) == 24);

#include "ArkDynamicCalledMimicManager.h"
static_assert(sizeof(ArkDynamicCalledMimicManager) == 72);

#include "ArkDynamicCorpseManager.h"
static_assert(sizeof(ArkDynamicCorpseManager) == 96);

#include "ArkEncounter.h"
static_assert(sizeof(ArkEncounter) == 64);

#include "ArkEncounterManager.h"
static_assert(sizeof(ArkEncounterManager) == 152);

#include "ArkEncounterProfile.h"
static_assert(sizeof(ArkEncounterProfile) == 48);

#include "ArkFlowNodeNpcSetWanderContainer.h"
static_assert(sizeof(ArkFlowNodeNpcEncounterSetWanderContainer) == 16);
static_assert(sizeof(ArkFlowNodeNpcSetWanderContainer) == 16);

#include "ArkHumanRandomSpawner.h"
static_assert(sizeof(CArkHumanRandomSpawner) == 152);
static_assert(sizeof(CArkHumanRandomSpawner::HumanDefinition) == 4);

#include "ArkLurkManager.h"
static_assert(sizeof(ArkLurkManager) == 24);
static_assert(sizeof(ArkLurkManager::LurkPointInfo) == 16);
static_assert(sizeof(ArkLurkManager::LurkPointInfoContainsLurkPoint) == 4);

#include "ArkLurkPoint.h"
static_assert(sizeof(CArkLurkPoint) == 72);

#include "ArkNightmareEtherformManager.h"
static_assert(sizeof(ArkNightmareEtherformManager) == 80);
static_assert(sizeof(ArkNightmareEtherformManager::EtherFormTrackTime) == 16);

#include "ArkNightmareSpawnManager.h"
static_assert(sizeof(ArkNightmareSpawnManager) == 312);
static_assert(sizeof(ArkNightmareSpawnManager::NightmareInfo) == 16);

#include "ArkNightmareSpawnerFsm.h"
static_assert(sizeof(ArkNightmareSpawnerFsm) == 240);
static_assert(sizeof(ArkNightmareSpawnerState_SpawnNightmare) == 8);

#include "ArkNpc.h"
static_assert(sizeof(ArkNpc) == 8160);
static_assert(sizeof(ArkNpc::LiftEntitySpawner) == 8);
static_assert(sizeof(ArkNpc::SetSpawnedStateVisitor) == 8);

#include "ArkNpcAnimActionObserver.h"
static_assert(sizeof(ArkNpcAnimActionObserver) == 32);

#include "ArkNpcAreaManager.h"
static_assert(sizeof(ArkNpcAreaManager) == 184);
static_assert(sizeof(ArkNpcAreaManager::AreaInfo) == 64);

#include "ArkNpcBody.h"
static_assert(sizeof(ArkNpcBody) == 6344);

#include "ArkNpcConeDamageDealer.h"
static_assert(sizeof(ArkNpcConeDamageDealer) == 112);

#include "ArkNpcDialogSpeaker.h"
static_assert(sizeof(ArkNpcDialogSpeaker) == 656);

#include "ArkNpcLifecycle.h"
static_assert(sizeof(ArkNpcLifecycle) == 728);

#include "ArkNpcLookAroundControl.h"
static_assert(sizeof(CArkAnimActionLookAround) == 128);
static_assert(sizeof(CArkNpcLookAroundControl) == 16);
static_assert(sizeof(SMannequinNpcLookAroundParams) == 16);
static_assert(sizeof(SMannequinNpcLookAroundParams::FragmentIDs) == 4);

#include "ArkNpcManager.h"
static_assert(sizeof(ArkNpcManager) == 1056);
static_assert(sizeof(ArkNpcManager::ArkNpcManagerValidationChangeInfo) == 24);

#include "ArkNpcMeleeDamageDealer.h"
static_assert(sizeof(ArkNpcMeleeDamageDealer) == 88);

#include "ArkNpcPlayer.h"
static_assert(sizeof(ArkNpcPlayer) == 9448);
static_assert(sizeof(ArkNpcPlayer::ArkWeaponImpulseSettings) == 36);

#include "ArkNpcProperties.h"
static_assert(sizeof(ArkNpcProperties) == 1120);
static_assert(sizeof(ArkNpcProperties::Ability) == 8);
static_assert(sizeof(ArkNpcProperties::AttentionFacing) == 2);
static_assert(sizeof(ArkNpcProperties::Audio) == 8);
static_assert(sizeof(ArkNpcProperties::Blind) == 8);
static_assert(sizeof(ArkNpcProperties::CallForHelp) == 32);
static_assert(sizeof(ArkNpcProperties::Character) == 8);
static_assert(sizeof(ArkNpcProperties::CombatRoleInfo) == 20);
static_assert(sizeof(ArkNpcProperties::ControlTurrets) == 8);
static_assert(sizeof(ArkNpcProperties::CorruptNpc) == 1);
static_assert(sizeof(ArkNpcProperties::Corruption) == 56);
static_assert(sizeof(ArkNpcProperties::DamageStates) == 128);
static_assert(sizeof(ArkNpcProperties::Dodge) == 24);
static_assert(sizeof(ArkNpcProperties::Dormant) == 16);
static_assert(sizeof(ArkNpcProperties::Energized) == 8);
static_assert(sizeof(ArkNpcProperties::EntityFactionModifier) == 8);
static_assert(sizeof(ArkNpcProperties::Fatality) == 4);
static_assert(sizeof(ArkNpcProperties::Fear) == 16);
static_assert(sizeof(ArkNpcProperties::Frenzied) == 8);
static_assert(sizeof(ArkNpcProperties::Glooed) == 24);
static_assert(sizeof(ArkNpcProperties::Hack) == 16);
static_assert(sizeof(ArkNpcProperties::HitReaction) == 8);
static_assert(sizeof(ArkNpcProperties::HumanArmed) == 24);
static_assert(sizeof(ArkNpcProperties::Hypnotize) == 4);
static_assert(sizeof(ArkNpcProperties::Laser) == 88);
static_assert(sizeof(ArkNpcProperties::Mannequin) == 8);
static_assert(sizeof(ArkNpcProperties::MimicJumpAttack) == 16);
static_assert(sizeof(ArkNpcProperties::MimicReorient) == 12);
static_assert(sizeof(ArkNpcProperties::Mimicry) == 96);
static_assert(sizeof(ArkNpcProperties::MindControl) == 8);
static_assert(sizeof(ArkNpcProperties::Nullwave) == 8);
static_assert(sizeof(ArkNpcProperties::OnDeath) == 24);
static_assert(sizeof(ArkNpcProperties::OnFire) == 8);
static_assert(sizeof(ArkNpcProperties::OperatorEffects) == 32);
static_assert(sizeof(ArkNpcProperties::Pet) == 16);
static_assert(sizeof(ArkNpcProperties::PlayerControlled) == 8);
static_assert(sizeof(ArkNpcProperties::PoltergeistEffects) == 8);
static_assert(sizeof(ArkNpcProperties::RaiseFromCorpse) == 8);
static_assert(sizeof(ArkNpcProperties::RaisePhantom) == 1);
static_assert(sizeof(ArkNpcProperties::Shift) == 8);
static_assert(sizeof(ArkNpcProperties::Size) == 8);
static_assert(sizeof(ArkNpcProperties::Sound) == 36);
static_assert(sizeof(ArkNpcProperties::Sound::NoiseStates) == 24);
static_assert(sizeof(ArkNpcProperties::Stunned) == 8);
static_assert(sizeof(ArkNpcProperties::Surprise) == 16);
static_assert(sizeof(ArkNpcProperties::TurretWeapon) == 16);
static_assert(sizeof(ArkNpcProperties::Underground) == 16);
static_assert(sizeof(ArkNpcProperties::UnreachableTargeting) == 40);

#include "ArkNpcSignalAccumulatorManager.h"
static_assert(sizeof(ArkNpcSignalAccumulator) == 88);
static_assert(sizeof(ArkNpcSignalAccumulatorManager) == 24);

#include "ArkNpcSignalReceiver.h"
static_assert(sizeof(ArkNpcSignalReceiver) == 64);
static_assert(sizeof(ArkNpcSignalReceiver::SignalAccumulator) == 32);
static_assert(sizeof(ArkNpcSignalReceiver::SignalAccumulator::SAItem) == 176);

#include "ArkNpcSpawnCystoid.h"
static_assert(sizeof(CArkNpcSpawnCystoid) == 96);

#include "ArkNpcSpawnGroup.h"
static_assert(sizeof(CArkNpcSpawnGroup) == 64);

#include "ArkNpcSpawnManager.h"
static_assert(sizeof(ArkNpcSpawnManager) == 24);
static_assert(sizeof(ArkNpcSpawnManager::SpawnRequest) == 40);

#include "ArkNpcSpawnTyphonNest.h"
static_assert(sizeof(CArkNpcSpawnTyphonNest) == 96);

#include "ArkNpcSpawnedState.h"
static_assert(sizeof(ArkNpcSpawnedState_Alert) == 1);
static_assert(sizeof(ArkNpcSpawnedState_Alive) == 1);
static_assert(sizeof(ArkNpcSpawnedState_Broken) == 16);
static_assert(sizeof(ArkNpcSpawnedState_Dead) == 1);
static_assert(sizeof(ArkNpcSpawnedState_Dormant) == 32);

#include "ArkNpcSpawner.h"
static_assert(sizeof(CArkNpcSpawner) == 120);

#include "ArkNpcStartFatalityDeathProcClip.h"
static_assert(sizeof(ArkNpcStartFatalityDeathProcClip) == 48);

#include "ArkNpcThrowPropManager.h"
static_assert(sizeof(ArkNpcThrowPropManager) == 112);
static_assert(sizeof(ArkNpcThrowPropManager::DeferredRayCastImpl) == 8);
static_assert(sizeof(ArkNpcThrowPropManager::PropData) == 392);
static_assert(sizeof(ArkNpcThrowPropManager::QueryParams) == 36);

#include "ArkNpcUnreachableTargetingManager.h"
static_assert(sizeof(ArkNpcUnreachableTargetingManager) == 1672);
static_assert(sizeof(UnreachableTargetingSearchArea) == 200);

#include "ArkNpcWeapon.h"
static_assert(sizeof(CArkNpcWeapon) == 192);

#include "ArkPatrolManager.h"
static_assert(sizeof(ArkPatrolManager) == 184);
static_assert(sizeof(ArkPatrolState) == 16);

#include "ArkRetreatManager.h"
static_assert(sizeof(ArkRetreatManager) == 64);
static_assert(sizeof(ArkRetreatManager::RetreatEntityInfo) == 16);
static_assert(sizeof(ArkRetreatManager::RetreatEntityInfoContainsEntity) == 4);

#include "ArkRetreatPoint.h"
static_assert(sizeof(CArkRetreatPoint) == 64);

#include "CArkAttraction.h"
static_assert(sizeof(CArkAttraction) == 96);

#include "CArkDistraction.h"
static_assert(sizeof(CArkDistraction) == 248);
#endif // !MOONCRASH
