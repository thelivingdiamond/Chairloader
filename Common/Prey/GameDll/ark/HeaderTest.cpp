// Header test file for path Prey/GameDll/ark/

#include "ArkAirJetManager.h"
static_assert(sizeof(ArkAirJet) == 16);
static_assert(sizeof(ArkAirJetManager) == 48);

#include "arkanglerotationcomponent.h"
static_assert(sizeof(CArkAngleRotationComponent) == 352);

#include "ArkApexVolume.h"
static_assert(sizeof(ArkApexVolume) == 64);

#include "ArkApexVolumeManager.h"
static_assert(sizeof(ArkApexVolumeManager) == 96);

#include "arkareacontainer.h"
static_assert(sizeof(CArkAreaContainer) == 88);

#include "ArkAudioEnvironment.h"
static_assert(sizeof(ArkAudioEnvironment) == 4);

#include "ArkAuxiliaryInventory.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkAuxiliaryInventory) == 136);
#else
static_assert(sizeof(ArkAuxiliaryInventory) == 128);
#endif

#include "ArkBlackListItem.h"
static_assert(sizeof(ArkBlackListItem) == 16);

#include "arkbreakable.h"
static_assert(sizeof(CArkBreakable) == 376);

#include "ArkBreakableGlass.h"
static_assert(sizeof(ArkBreakableGlass) == 64);

#include "ArkCaptureVolume.h"
static_assert(sizeof(ArkCaptureVolume) == 64);

#include "ArkCharacterEffectsManager.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkCharacterEffectsManager) == 1544);
#else
static_assert(sizeof(ArkCharacterEffectsManager) == 1832);
#endif

#include "ArkCharacterManager.h"
static_assert(sizeof(ArkCharacterManager) == 64);

#include "arkcornersmoother3d.h"
static_assert(sizeof(CArkCornerSmoother3D) == 2440);
static_assert(sizeof(CArkCornerSmoother3D::SCurveSettings) == 24);
static_assert(sizeof(CArkCornerSmoother3D::SPredictionSettings) == 64);
static_assert(sizeof(CArkCornerSmoother3D::SPrediction) == 1204);

#include "ArkCraftingIngredient.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkCraftingIngredient) == 416);
#else
static_assert(sizeof(ArkCraftingIngredient) == 440);
#endif

#include "ArkDataComponentBase.h"
static_assert(sizeof(ArkDataComponentBase) == 32);

#include "ArkDifficultyComponent.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkDifficultyComponent) == 32);
#else
static_assert(sizeof(ArkDifficultyComponent) == 24);
#endif
static_assert(sizeof(ArkDifficultyLevel) == 32);
static_assert(sizeof(ArkDifficultyLevel::ArkLevelProperty) == 32);
static_assert(sizeof(ArkDifficultyLevel::ArkVisualAttentionScalarProperty) == 32);
static_assert(sizeof(ArkDifficultyLevel::ArkModifiersProperty) == 32);
static_assert(sizeof(ArkDifficultyLevels) == 32);
static_assert(sizeof(ArkDifficultyLevels::ArkLevelsProperty) == 32);

#include "ArkDisruptable.h"
static_assert(sizeof(ArkDisruptable) == 152);

#include "ArkDisruptableSignalReceiver.h"
static_assert(sizeof(ArkDisruptableSignalReceiver) == 24);

#include "ArkDistractionManager.h"
static_assert(sizeof(ArkDistractionManager) == 200);

#include "ArkDoor.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkDoor) == 688);
#else
static_assert(sizeof(ArkDoor) == 1008);
#endif

#include "ArkEffectParameters.h"
static_assert(sizeof(ArkEffectParameters) == 40);

#include "arkeffectutils.h"
static_assert(sizeof(ArkEffectBase) == 64);
static_assert(sizeof(ArkLooseEffect) == 112);
static_assert(sizeof(ArkFireAndForgetEffect) == 64);
static_assert(sizeof(ArkEntityEffectBase) == 128);
static_assert(sizeof(ArkEntityEffect) == 136);
static_assert(sizeof(ArkEntityPointerEffect) == 136);
static_assert(sizeof(ArkEntityAttachmentEffect) == 88);
#ifdef MOONCRASH
static_assert(sizeof(ArkCharacterAttachmentEffect) == 88);
static_assert(sizeof(EntityEffects::ArkEffectsCharacterController) == 40);
#endif

#include "arkelevatorcollisiondetector.h"
static_assert(sizeof(CArkElevatorCollisionDetector) == 104);

#include "ArkEmissiveComponent.h"
static_assert(sizeof(ArkParamOverride) == 8);
static_assert(sizeof(ArkEmissiveComponent) == 64);

#include "ArkEmotionExtension.h"
static_assert(sizeof(ArkEmotionExtension) == 80);

#include "ArkEntityGrabber.h"
static_assert(sizeof(ArkEntityGrabber) == 40);

#include "ArkEquipmentMod.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkEquipmentMod) == 416);
#endif

#include "arkethericdoppelganger.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkEthericDoppelganger) == 768);
#else
static_assert(sizeof(CArkEthericDoppelganger) == 776);
#endif

#include "arkethericfogentity.h"
static_assert(sizeof(CArkEthericFogEntity) == 384);

#include "ArkEthericFogManager.h"
static_assert(sizeof(ArkEthericFogManager) == 40);
static_assert(sizeof(ArkEthericFogManager::EthericFogInfo) == 8);

// Disabled: base build fails inside this header (C1083: Cannot open include file: 'Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h': No such file or d)
//#include "ArkEventScheduler.h"
//static_assert(sizeof(ArkEventScheduler) == 40);
//static_assert(sizeof(ArkEventScheduler::TimeEventInfo) == 32);
//static_assert(sizeof(ArkFlowNodeTimeEventBase) == 64);
//static_assert(sizeof(ArkFlowNodeAbsoluteTimeEvent) == 64);
//static_assert(sizeof(ArkFlowNodeRelativeTimeEvent) == 64);
//static_assert(sizeof(ArkFlowNodeGetGameTime) == 16);
//static_assert(sizeof(ArkFlowNodeSetGameTime) == 16);

#include "ArkExclusiveActionFilter.h"
static_assert(sizeof(ArkExclusiveActionFilter) == 88);

#include "ArkFabricationPlanIngredients.h"
static_assert(sizeof(ArkFabricationPlanIngredients) == 20);

#include "ArkFabricator.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkFabricator) == 1960);
#else
static_assert(sizeof(ArkFabricator) == 1984);
#endif

#include "ArkFactionLink.h"
static_assert(sizeof(ArkFactionLink) == 24);

#include "ArkFactionManager.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkFactionManager) == 472);
#endif

// Disabled: base build fails inside this header (C1083: Cannot open include file: 'Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h': No such file or d)
//#include "ArkFlowNodeDissipateNightmare.h"
//#ifndef MOONCRASH
//static_assert(sizeof(ArkFlowNodeDissipateNightmare) == 16);
//#endif

// Disabled: base build cannot reach this header (gamedll/ark/arkflownodenpcmakeconscious.h -> Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h)
//#include "ArkFlowNodeNpcMakeConscious.h"
//static_assert(sizeof(ArkFlowNodeNpcMakeConscious) == 16);

// Disabled: base build cannot reach this header (gamedll/ark/arkflownodenpctrackview_getstartpos.h -> Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h)
//#include "ArkFlowNodeNpcTrackView_GetStartPos.h"
//static_assert(sizeof(ArkFlowNodeNpcTrackView_GetStartPos) == 16);

// Disabled: base build cannot reach this header (gamedll/ark/arkflownodenpctrackview_setdynamicentity.h -> Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h)
//#include "arkflownodenpctrackview_setdynamicentity.h"
//static_assert(sizeof(ArkFlowNodeNpcTrackView_SetDynamicNode) == 16);

#include "ArkGame.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkGame) == 472);
#else
static_assert(sizeof(ArkGame) == 464);
#endif
static_assert(sizeof(ArkGame::ScreenBlackFadeInfo) == 8);

#include "ArkGameDataManager.h"
static_assert(sizeof(ArkGameDataManager) == 64);

#include "ArkGameMetricsComponent.h"
static_assert(sizeof(ArkGameMetricsComponent) == 64);
static_assert(sizeof(ArkGameMetricsComponent::ArkGameMetricValue) == 24);

#include "ArkGameModeManager.h"
static_assert(sizeof(ArkGameModeManager) == 80);

#include "ArkGameRules.h"
static_assert(sizeof(ArkGameRules) == 160);

#include "ArkGameStateConditionManager.h"
static_assert(sizeof(ArkGameStateConditionManager) == 200);
static_assert(sizeof(ArkGameStateConditionManager::DelayedResultEntry) == 24);

#include "arkglassbreaker.h"
static_assert(sizeof(CArkGlassBreaker) == 72);

#include "ArkGlintConfigManager.h"
static_assert(sizeof(ArkGlintConfigManager) == 72);

#include "arkglooeffectutils.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkGlooEffects) == 232);
static_assert(sizeof(ArkGlooEffectAccumulated) == 248);
static_assert(sizeof(ArkGlooEffectTimed) == 240);
#else
static_assert(sizeof(ArkGlooEffects) == 240);
static_assert(sizeof(ArkGlooEffectAccumulated) == 256);
static_assert(sizeof(ArkGlooEffectTimed) == 248);
#endif

#include "arkglooislandnavlinkmanager.h"
static_assert(sizeof(CArkGlooIslandNavLinkManager) == 80);
static_assert(sizeof(CArkGlooIslandNavLinkManager::GlooIsland) == 184);

#include "arkgravshaftentity.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkGravShaftEntity) == 568);
#else
static_assert(sizeof(CArkGravShaftEntity) == 576);
#endif
static_assert(sizeof(CArkGravShaftEntity::ArkContainedEntity) == 32);

#include "ArkGroundColliderComponent.h"
static_assert(sizeof(ArkGroundColliderComponent) == 16);

#include "ArkHealthExtension.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkHealthExtension) == 72);
#else
static_assert(sizeof(ArkHealthExtension) == 80);
#endif

#include "ArkInteractionInfo.h"
static_assert(sizeof(ArkInteractionInfo) == 24);

#include "ArkInteractionTestResult.h"
static_assert(sizeof(ArkInteractionTestResult) == 40);

#include "ArkInteractiveMachine.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkInteractiveMachine) == 760);
#else
static_assert(sizeof(ArkInteractiveMachine) == 784);
#endif

#include "arkinteractiveobject.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkInteractiveMachinePerceivable) == 16);
static_assert(sizeof(ArkInteractiveObjectPerceivable) == 16);
#endif
#ifdef MOONCRASH
static_assert(sizeof(ArkInteractiveObject) == 848);
#endif

#include "ArkLaserTripline.h"
static_assert(sizeof(ArkLaserTripline) == 344);

#include "ArkLaserTriplineSignalReceiver.h"
static_assert(sizeof(ArkLaserTriplineSignalReceiver) == 24);

#include "ArkLatentRaycast.h"
static_assert(sizeof(ArkLatentRaycast) == 72);

#include "arklight.h"
static_assert(sizeof(ArkLightSignalReceiver) == 32);
static_assert(sizeof(CArkLight) == 3136);
static_assert(sizeof(CArkLight::LightData) == 712);
static_assert(sizeof(CArkLight::EmpLightData) == 640);

#include "ArkLightManager.h"
static_assert(sizeof(ArkLightManagerLightData) == 84);
static_assert(sizeof(ArkLightManagerLightData::SubLightData) == 16);
static_assert(sizeof(ArkLightManager) == 56);

#include "ArkLightManagerDisruptableData.h"
static_assert(sizeof(ArkLightManagerDisruptableData) == 16);

#include "ArkLightTimeManager.h"
static_assert(sizeof(ArkLightTimeManager) == 72);

#include "ArkListenerManager.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkListenerManager) == 1032);
#else
static_assert(sizeof(ArkListenerManager) == 1168);
#endif

#include "ArkLocationManager.h"
static_assert(sizeof(ArkLocationManager) == 88);
static_assert(sizeof(ArkLocationManager::LocationInfo) == 16);

#include "arkmapvolume.h"
static_assert(sizeof(ArkBitVector) == 32);
static_assert(sizeof(CArkVolume) == 32);
static_assert(sizeof(CArkMapVolume) == 176);

#include "ArkMaterialAnimationManager.h"
static_assert(sizeof(ArkMaterialAnimationManager) == 584);
static_assert(sizeof(ArkMaterialAnimationManager::ActiveAnimationData) == 24);
static_assert(sizeof(ArkMaterialAnimationManager::SAttachmentMaterials) == 32);
static_assert(sizeof(ArkMaterialAnimationManager::EnumClassHash) == 1);

#include "ArkMetaTagManager.h"
static_assert(sizeof(ArkMetaTagManager) == 176);
static_assert(sizeof(ArkMetaTagManager::ArchetypeTagInfo) == 8);

#include "arknavislandjumplink.h"
static_assert(sizeof(CArkNavIslandJumpLink) == 208);

#include "ArkNeuromod.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNeuromod) == 384);
#else
static_assert(sizeof(ArkNeuromod) == 408);
#endif

#include "ArkNewGamePlus.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNewGamePlus) == 64);
static_assert(sizeof(ArkNewGamePlus::ArkResearchSaveData) == 16);
#endif

#include "ArkOperatorDispenser.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkOperatorDispenser) == 2456);
#else
static_assert(sizeof(ArkOperatorDispenser) == 2488);
#endif
static_assert(sizeof(ArkOperatorDispenser::SpawnedOperator) == 8);

#include "ArkOverlappingGooHandler.h"
static_assert(sizeof(ArkOverlappingGooHandler) == 32);

#include "ArkPasswordProtected.h"
static_assert(sizeof(ArkPasswordProtected) == 16);

#include "ArkPostEffectManager.h"
static_assert(sizeof(ArkPostEffect) == 96);
static_assert(sizeof(ArkPostEffectManager) == 256);
static_assert(sizeof(ArkPostEffectManager::SBlendOutInfo) == 16);
#ifdef MOONCRASH
static_assert(sizeof(SPostEffectCurve) == 16);
static_assert(sizeof(SPostEffectCurveParam) == 72);
static_assert(sizeof(ArkPostEffectOverrideParam) == 160);
#endif

#include "arkprojectilegoonetworkmanager.h"
static_assert(sizeof(CArkProjectileGooNetworkManager) == 88);
static_assert(sizeof(CArkProjectileGooNetworkManager::GooNetwork) == 88);

#include "arkprojectilegoophysicsmanager.h"
static_assert(sizeof(CArkProjectileGooPhysicsManager) == 256);
static_assert(sizeof(CArkProjectileGooPhysicsManager::DynamicEntity_GooInfo) == 64);

#include "arkprojectilepoolmanager.h"
static_assert(sizeof(CArkProjectilePoolManager) == 24);
static_assert(sizeof(CArkProjectilePoolManager::SProjectilePoolDesc) == 72);

#include "ArkRecycler.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkRecycler) == 1248);
#else
static_assert(sizeof(ArkRecycler) == 1280);
#endif
static_assert(sizeof(ArkRecycler::RecycleData) == 24);

#include "ArkRecycleUtils.h"
static_assert(sizeof(ArkRecycleUtils) == 1);

#include "ArkRepairable.h"
static_assert(sizeof(ArkRepairableLite) == 48);
static_assert(sizeof(ArkRepairable) == 160);

#include "ArkRepairableObject.h"
static_assert(sizeof(ArkRepairableObject) == 368);

#include "ArkRobotLight.h"
static_assert(sizeof(ArkRobotLight) == 96);

#include "ArkRoomPath.h"
static_assert(sizeof(ArkRoomPath) == 56);

#include "arkroomvolume.h"
static_assert(sizeof(CArkRoomVolume) == 128);

#include "arkroomvolumemanager.h"
static_assert(sizeof(ArkRoomPathNode) == 8);
static_assert(sizeof(ArkRoomPathNodePair) == 16);
static_assert(sizeof(CArkRoomVolumeManager) == 328);
static_assert(sizeof(CArkRoomVolumeManager::VolumeData) == 72);
static_assert(sizeof(CArkRoomVolumeManager::PortalData) == 96);

#include "ArkSaveMetaData.h"
static_assert(sizeof(ArkSaveMetaData) == 24);

#include "ArkSceneWindow.h"
static_assert(sizeof(ArkSceneWindow) == 64);

#include "ArkSignalDispositionModifier.h"
static_assert(sizeof(ArkSignalDispositionModifier) == 320);

#include "ArkSignalModifer.h"
static_assert(sizeof(ArkSignalModifer) == 16);
static_assert(sizeof(ArkSignalModifer::ArkIsInboundProperty) == 32);
static_assert(sizeof(ArkSignalModifer::ArkModifierIdProperty) == 32);

#include "ArkSimpleCharge.h"
static_assert(sizeof(ArkChargeAmount) == 8);
static_assert(sizeof(ArkSimpleCharge) == 20);

#include "ArkSimpleTimer.h"
static_assert(sizeof(ArkTimeRemaining) == 4);
static_assert(sizeof(ArkSimpleTimer) == 8);
static_assert(sizeof(ArkAutoResetTimer) == 8);
static_assert(sizeof(ArkRandomizedTimer) == 12);
static_assert(sizeof(ArkRandomizedAutoResetTimer) == 12);
static_assert(sizeof(ArkComplexVisionInput) == 8);

#include "ArkSpeakerExtension.h"
static_assert(sizeof(ArkSpeakerExtension) == 72);

#include "ArkStatsComponent.h"
static_assert(sizeof(ArkStatModifierPackage) == 40);
static_assert(sizeof(ArkStatModifierPackage::ArkIDProperty) == 32);
static_assert(sizeof(ArkStatModifierPackage::ArkNameProperty) == 32);
static_assert(sizeof(ArkStatModifierPackage::ArkModifiersProperty) == 32);
static_assert(sizeof(ArkStatModifierPackages) == 24);
static_assert(sizeof(ArkStatModifierPackages::ArkPackagesProperty) == 32);
static_assert(sizeof(ArkStatsComponent) == 160);
static_assert(sizeof(ArkStatsComponent::ArkModifier) == 8);
static_assert(sizeof(ArkStatsComponent::ArkStat) == 32);

#include "arktargetlerper.h"
static_assert(sizeof(CArkTargetLerper) == 120);

#include "ArkTimeScaleManager.h"
static_assert(sizeof(ArkTimeScaleManager) == 104);
static_assert(sizeof(ArkTimeScaleManager::TimeScaleInfo) == 8);

#include "ArkTimeScaler.h"
static_assert(sizeof(ArkTimeScaler) == 28);

#include "ArkTipComponent.h"
static_assert(sizeof(ArkTipComponent) == 112);

#include "ArkTurretCountArea.h"
static_assert(sizeof(ArkTurretCountArea) == 128);
static_assert(sizeof(ArkTurretCountArea::TurretEntry) == 8);

#include "ArkTutorialSystem.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTutorialSystem) == 744);
#else
static_assert(sizeof(ArkTutorialSystem) == 1680);
#endif
static_assert(sizeof(ArkTutorialSystem::ContextualPackage) == 64);
static_assert(sizeof(ArkTutorialSystem::ContextualEntry) == 160);
static_assert(sizeof(ArkTutorialSystem::CardEntry) == 40);
#ifdef MOONCRASH
static_assert(sizeof(ArkTutorialSystem::ReadyRoomEntry) == 64);
#endif

#include "CSchedulerActionPoolBase.h"
static_assert(sizeof(CSchedulerActionPoolBase) == 24);

#include "ISchedulerAction.h"
static_assert(sizeof(ISchedulerAction) == 8);

#include "playerIArkCombatFocusListener.h"
static_assert(sizeof(IArkCombatFocusListener) == 8);

#include "scriptbind_ark.h"
static_assert(sizeof(CScriptBind_Ark) == 112);

#include "scriptbind_arkbreakable.h"
static_assert(sizeof(CScriptBind_ArkBreakable) == 96);

#include "scriptbind_arkfaction.h"
static_assert(sizeof(CScriptBind_ArkFaction) == 96);

#include "scriptbind_arkkiosk.h"
static_assert(sizeof(CScriptBind_ArkKiosk) == 96);

#include "scriptbind_arknpc.h"
static_assert(sizeof(CScriptBind_ArkNpc) == 112);

#include "scriptbind_arkroster.h"
static_assert(sizeof(CScriptBind_ArkRoster) == 96);

// Disabled: base build cannot reach this header (gamedll/ark/scriptbind_inventory.h -> Prey/CryAction/ScriptBind_Inventory.h)
//#include "scriptbind_inventory.h"
//static_assert(sizeof(CScriptBind_Inventory) == 96);

// Disabled: base build cannot reach this header (gamedll/ark/scriptbind_itemsystem.h -> Prey/CryAction/ScriptBind_ItemSystem.h)
//#include "scriptbind_itemsystem.h"
//static_assert(sizeof(CScriptBind_ItemSystem) == 96);

#include "ArkItemSystem.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkItemSystem) == 248);
#else
static_assert(sizeof(ArkItemSystem) == 232);
#endif
static_assert(sizeof(ArkItemSystem::IArkItemCreator) == 8);
class CArkItem;
static_assert(sizeof(ArkItemSystem::CArkItemCreator<CArkItem>) == 8);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkAvoidanceField.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkAvoidanceField) == 12);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkChallengeManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkChallengeManager) == 112);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkDoomClockManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkDoomClockGlobalData_ProfileElem) == 32);
static_assert(sizeof(ArkDoomClockGlobalData_ProfileElem::ArkDurationProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData_ProfileElem::ArkPreIncrementProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData_ProfileElem::ArkMaxSummonedPhantomsProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData_ProfileElem::ArkLabelProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData_ProfileElem::ArkCryptoMultiplierProperty) == 32);
static_assert(sizeof(ArkDoomClockEntityData_Level) == 8);
static_assert(sizeof(ArkDoomClockEntityData_Level::ArkHealthModifierProperty) == 32);
static_assert(sizeof(ArkDoomClockEntityData_Level::ArkDamageModifierProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData_Profile) == 32);
static_assert(sizeof(ArkDoomClockGlobalData_Profile::ArkNameProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData_Profile::ArkLevelsProperty) == 32);
static_assert(sizeof(ArkDoomClockLevelFanfare) == 24);
static_assert(sizeof(ArkDoomClockLevelFanfare::ArkVFXProperty) == 32);
static_assert(sizeof(ArkDoomClockLevelFanfare::ArkSFXProperty) == 32);
static_assert(sizeof(ArkDoomClockLevelFanfare::ArkPostFXProperty) == 32);
static_assert(sizeof(ArkDoomClockEntityData) == 32);
static_assert(sizeof(ArkDoomClockEntityData::ArkNameProperty) == 32);
static_assert(sizeof(ArkDoomClockEntityData::ArkLevelsProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData) == 72);
static_assert(sizeof(ArkDoomClockGlobalData::ArkMaxLevelProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData::ArkProfileProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData::ArkLevelFanfareProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData::ArkPreIncrementPostFXProperty) == 32);
static_assert(sizeof(ArkDoomClockGlobalData::ArkPreIncrementVFXProperty) == 32);
static_assert(sizeof(ArkDoomClockData) == 96);
static_assert(sizeof(ArkDoomClockData::ArkGlobalDataProperty) == 32);
static_assert(sizeof(ArkDoomClockData::ArkEntityDataProperty) == 32);
static_assert(sizeof(ArkDoomClockManager) == 144);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkDoorRNG.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkDoorRNG) == 16);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkFlowNodeNpcCorruptHuman.h"
static_assert(sizeof(ArkFlowNodeNpcCorruptHuman) == 16);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkFlowNodeNpcCorruptOperator.h"
static_assert(sizeof(ArkFlowNodeNpcCorruptOperator) == 16);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkFlowNodeNpcEnableAutoCorruption.h"
static_assert(sizeof(ArkFlowNodeNpcEnableAutoCorruption) == 16);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkFlowNodeNpcRequestCorruptNpc.h"
static_assert(sizeof(ArkFlowNodeNpcRequestCorruptNpc) == 16);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkFlowSetPlayerTimeDilation.h"
static_assert(sizeof(CArkFlowSetPlayerTimeDilation) == 24);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkFlowSetWorldTimeDilation.h"
static_assert(sizeof(CArkFlowSetWorldTimeDilation) == 24);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkMoonRockEntity.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkMoonRockEntity) == 352);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkMoonRockManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkMoonRockManager) == 168);
static_assert(sizeof(ArkMoonRockManager::DeferredRayCastImpl) == 48);
static_assert(sizeof(ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>) == 384);
static_assert(sizeof(ArkMoonRockManager::MoonRockTargetInfo) == 20);
static_assert(sizeof(ArkMoonRockManager::MoonRockInfo) == 36);
static_assert(sizeof(ArkMoonRockManager::MoonRockUserInfo) == 48);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNavLowGJumpLink.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkNavLowGJumpLink) == 256);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkPhantomGravityWarp.h"
static_assert(sizeof(CArkPhantomGravityWarp) == 168);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkPlayableCharacterManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkPlayableCharacterManager) == 264);
static_assert(sizeof(ArkPlayableCharacterManager::SDeathInfo) == 16);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkRandomValueManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkRandomValueManager) == 136);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkRecycleHelper.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkRecycleHelper) == 360);
static_assert(sizeof(ArkRecycleHelper::RecycleEntityInfo) == 3);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkRoomPortal.h"
static_assert(sizeof(CArkRoomPortal) == 128);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkSeededPickupSpawner.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkSeededPickupSpawner) == 64);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkSimulationManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkSimulationManager) == 5);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "IUIGameEventSystem.h"
static_assert(sizeof(IUIGameEventSystem) == 8);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ScriptHandle.h"
#endif
