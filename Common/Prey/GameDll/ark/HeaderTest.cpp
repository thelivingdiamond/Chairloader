// Header test file for path Prey/GameDll/ark/ArkAirJetManager.h
#include "ArkAirJetManager.h"
static_assert(sizeof(ArkAirJetManager) == 48);

#include "arkanglerotationcomponent.h"
static_assert(sizeof(CArkAngleRotationComponent) == 352);

#include "ArkApexVolume.h"
static_assert(sizeof(ArkApexVolume) == 64);

#include "ArkApexVolumeManager.h"
static_assert(sizeof(ArkApexVolumeManager) == 96);

#include "arkareacontainer.h"
static_assert(sizeof(CArkAreaContainer) == 88);

//#include "arkattachmentclipevent.h"
//static_assert(sizeof(CArkAttachmentClipEvent) == 72);
//tatic_assert(sizeof(CArkAttachmentEventParams) == 24);

#include "ArkAudioEnvironment.h"
static_assert(sizeof(ArkAudioEnvironment) == 4);

#include "ArkAuxiliaryInventory.h"
static_assert(sizeof(ArkAuxiliaryInventory) == 136);

#include "ArkBlackListItem.h"
static_assert(sizeof(ArkBlackListItem) == 16);

#include "arkbreakable.h"
static_assert(sizeof(CArkBreakable) == 376);

#include "ArkBreakableGlass.h"
static_assert(sizeof(ArkBreakableGlass) == 64);

//#include "arkcamerafovclipevent.h"
//static_assert(sizeof(CArkCameraFOVClipEventParams) == 16);
//static_assert(sizeof(CArkCameraFOVClipEvent) == 80);

//#include "arkcamerashakeclipevent.h"
//static_assert(sizeof(CArkCameraShakeClipEventParams) == 16);
//static_assert(sizeof(CArkCameraShakeClipEvent) == 56);

//#include "ArkCameraShakeManager.h"
//static_assert(sizeof(ArkCameraShakeManager) == 56);
//static_assert(sizeof(ArkCameraShakeManager::CameraShakeEntry) == 64);
//static_assert(sizeof(ArkCameraShakeManager::ChannelEntry) == 16);

#include "ArkCaptureVolume.h"
static_assert(sizeof(ArkCaptureVolume) == 64);

#include "ArkCharacterEffectsManager.h"
static_assert(sizeof(ArkCharacterEffectsManager) == 1544);

#include "ArkCharacterManager.h"
static_assert(sizeof(ArkCharacterManager) == 64);

#include "arkcornersmoother3d.h"
static_assert(sizeof(CArkCornerSmoother3D) == 2440);
static_assert(sizeof(CArkCornerSmoother3D::SCurveSettings) == 24);
static_assert(sizeof(CArkCornerSmoother3D::SPredictionSettings) == 64);
static_assert(sizeof(CArkCornerSmoother3D::SPrediction) == 1204);

#include "ArkCraftingIngredient.h"
static_assert(sizeof(ArkCraftingIngredient) == 416);

#include "ArkDataComponentBase.h"
static_assert(sizeof(ArkDataComponentBase) == 32);

#include "ArkDifficultyComponent.h"
static_assert(sizeof(ArkDifficultyComponent) == 32);
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

//#include "ArkDistractionInstance.h"
//static_assert(sizeof(ArkDistractionInstance) == 40);
//static_assert(sizeof(ArkDistractionInstance::ObstacleCheckState) == 16);

#include "ArkDistractionManager.h"
static_assert(sizeof(ArkDistractionManager) == 200);

#include "ArkDoor.h"
#if 0
static_assert(sizeof(ArkNpcMovementDesire) == 240);
static_assert(sizeof(ArkNpcMovementDesire::DestinationParam) == 8);
static_assert(sizeof(ArkNpcMovementDesire::EnableNavMeshQueryParam) == 12);
static_assert(sizeof(ArkNpcMovementDesire::DisableNavMeshQueryParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ForcePathParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ForceGoToNavMeshParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::StanceParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::SpeedLiteralParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::AccelLiteralParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::DecelLiteralParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::StopDistanceParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::UseExactPositionParam) == 20);
static_assert(sizeof(ArkNpcMovementDesire::ShiftParam) == 24);
static_assert(sizeof(ArkNpcMovementDesire::JumpParam) == 16);
static_assert(sizeof(ArkNpcMovementDesire::HoverParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::ContinueMovingParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ScriptMoveParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ObstacleAvoidanceParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::ErrorParam) == 1);
#endif
static_assert(sizeof(ArkDoor) == 688);

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

#include "arkelevatorcollisiondetector.h"
static_assert(sizeof(CArkElevatorCollisionDetector) == 104);

#include "ArkEmissiveComponent.h"
static_assert(sizeof(ArkEmissiveComponent) == 64);
static_assert(sizeof(ArkParamOverride) == 8);

#include "ArkEmotionExtension.h"
static_assert(sizeof(ArkEmotionExtension) == 80);

#include "ArkEntityGrabber.h"
static_assert(sizeof(ArkEntityGrabber) == 40);

#include "ArkEquipmentMod.h"
static_assert(sizeof(ArkEquipmentMod) == 416);

#include "arkethericdoppelganger.h"
static_assert(sizeof(CArkEthericDoppelganger) == 768);

#include "arkethericfogentity.h"
static_assert(sizeof(CArkEthericFogEntity) == 384);

#include "ArkEthericFogManager.h"
static_assert(sizeof(ArkEthericFogManager) == 40);
static_assert(sizeof(ArkEthericFogManager::EthericFogInfo) == 8);

#if 0
#include "ArkEventScheduler.h"
static_assert(sizeof(ArkEventScheduler) == 40);
static_assert(sizeof(ArkEventScheduler::TimeEventInfo) == 32);
static_assert(sizeof(ArkFlowNodeTimeEventBase) == 64);
static_assert(sizeof(ArkFlowNodeAbsoluteTimeEvent) == 64);
static_assert(sizeof(ArkFlowNodeRelativeTimeEvent) == 64);
static_assert(sizeof(ArkFlowNodeGetGameTime) == 16);
static_assert(sizeof(ArkFlowNodeSetGameTime) == 16);
#endif

#include "ArkExclusiveActionFilter.h"
static_assert(sizeof(ArkExclusiveActionFilter) == 88);

#include "ArkFabricationPlanIngredients.h"
static_assert(sizeof(ArkFabricationPlanIngredients) == 20);

#include "ArkFabricator.h"
static_assert(sizeof(ArkFabricator) == 1960);

#include "ArkFactionLink.h"
static_assert(sizeof(ArkFactionLink) == 24);

#include "ArkFactionManager.h"
static_assert(sizeof(ArkFactionManager) == 472);

#if 0
#include "ArkFlowNodeDissipateNightmare.h"
static_assert(sizeof(ArkFlowNodeDissipateNightmare) == 16);

#include "ArkFlowNodeNpcMakeConscious.h"
static_assert(sizeof(ArkFlowNodeNpcMakeConscious) == 16);

#include "ArkFlowNodeNpcTrackView_GetStartPos.h"
static_assert(sizeof(ArkFlowNodeNpcTrackView_GetStartPos) == 16);

#include "arkflownodenpctrackview_setdynamicentity.h"
static_assert(sizeof(ArkFlowNodeNpcTrackView_SetDynamicNode) == 16);
#endif

#include "ArkGame.h"
static_assert(sizeof(ArkGame) == 472);
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
static_assert(sizeof(ArkGlooEffects) == 232);
static_assert(sizeof(ArkGlooEffectAccumulated) == 248);
static_assert(sizeof(ArkGlooEffectTimed) == 240);

#include "arkglooislandnavlinkmanager.h"
static_assert(sizeof(CArkGlooIslandNavLinkManager) == 80);
static_assert(sizeof(CArkGlooIslandNavLinkManager::GlooIsland) == 184);

#include "arkgravshaftentity.h"
static_assert(sizeof(CArkGravShaftEntity) == 568);
static_assert(sizeof(CArkGravShaftEntity::ArkContainedEntity) == 32);

#include "ArkGroundColliderComponent.h"
static_assert(sizeof(ArkGroundColliderComponent) == 16);

#include "ArkHealthExtension.h"
static_assert(sizeof(ArkHealthExtension) == 72);

#include "ArkInteractionInfo.h"
static_assert(sizeof(ArkInteractionInfo) == 24);

#include "ArkInteractionTestResult.h"
static_assert(sizeof(ArkInteractionTestResult) == 40);

#include "ArkInteractiveMachine.h"
static_assert(sizeof(ArkInteractiveMachine) == 760);

#include "arkinteractiveobject.h"
static_assert(sizeof(ArkInteractiveMachinePerceivable) == 16);
static_assert(sizeof(ArkInteractiveObjectPerceivable) == 16);

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
static_assert(sizeof(ArkListenerManager) == 1032);

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
static_assert(sizeof(ArkNeuromod) == 384);

#include "ArkNewGamePlus.h"
static_assert(sizeof(ArkNewGamePlus) == 64);
static_assert(sizeof(ArkNewGamePlus::ArkResearchSaveData) == 16);

#include "ArkOperatorDispenser.h"
static_assert(sizeof(ArkOperatorDispenser) == 2456);
static_assert(sizeof(ArkOperatorDispenser::SpawnedOperator) == 8);

#include "ArkOverlappingGooHandler.h"
static_assert(sizeof(ArkOverlappingGooHandler) == 32);

#include "ArkPasswordProtected.h"
static_assert(sizeof(ArkPasswordProtected) == 16);

//#include "arkplayercameralockclipevent.h"
//static_assert(sizeof(CArkPlayerCameraLockClipEvent) == 48);

//#include "arkplayerdisablemovementclipevent.h"
//static_assert(sizeof(CArkPlayerDisableMovementClipEvent) == 48);

#include "ArkPostEffectManager.h"
static_assert(sizeof(ArkPostEffectManager) == 256);
static_assert(sizeof(ArkPostEffectManager::SBlendOutInfo) == 16);
//static_assert(sizeof(SPostEffectCurve) == 16);
//static_assert(sizeof(SPostEffectCurveParam) == 72);
//static_assert(sizeof(ArkPostEffectOverrideParam) == 160);
static_assert(sizeof(ArkPostEffect) == 96);

//#include "arkposteffectprocclip.h"
//static_assert(sizeof(CArkPostEffectClipEventParams) == 16);
//static_assert(sizeof(CArkEnablePostEffectClipEvent) == 56);
//static_assert(sizeof(CArkDisablePostEffectClipEvent) == 56);

#include "arkprojectilegoonetworkmanager.h"
static_assert(sizeof(CArkProjectileGooNetworkManager) == 88);
static_assert(sizeof(CArkProjectileGooNetworkManager::GooNetwork) == 88);

#include "arkprojectilegoophysicsmanager.h"
static_assert(sizeof(CArkProjectileGooPhysicsManager) == 256);
static_assert(sizeof(CArkProjectileGooPhysicsManager::DynamicEntity_GooInfo) == 64);

#include "arkprojectilepoolmanager.h"
static_assert(sizeof(CArkProjectilePoolManager) == 24);
static_assert(sizeof(CArkProjectilePoolManager::SProjectilePoolDesc) == 72);

//#include "arkpsipowermimicclipevent.h"
//static_assert(sizeof(CArkPsiPowerMimicMorphInObjectClipEvent) == 48);

//#include "arkpsipowersmokeformclipevent.h"
//static_assert(sizeof(CArkPsiPowerSmokeFormEnterClipEvent) == 48);
//static_assert(sizeof(CArkPsiPowerSmokeFormExitClipEvent) == 48);
//static_assert(sizeof(CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams) == 16);
//static_assert(sizeof(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent) == 56);
//static_assert(sizeof(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent) == 48);

#include "ArkRecycler.h"
static_assert(sizeof(ArkRecycler) == 1248);
static_assert(sizeof(ArkRecycler::RecycleData) == 24);

#include "ArkRecycleUtils.h"
static_assert(sizeof(ArkRecycleUtils) == 1);

//#include "arkreleaseslaveclipevent.h"
//static_assert(sizeof(CArkReleaseSlaveProceduralClipEvent) == 48);

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
static_assert(sizeof(ArkStatModifierPackages) == 24);
static_assert(sizeof(ArkStatModifierPackages::ArkPackagesProperty) == 32);
static_assert(sizeof(ArkStatsComponent) == 160);
static_assert(sizeof(ArkStatsComponent::ArkModifier) == 8);
static_assert(sizeof(ArkStatsComponent::ArkStat) == 32);
static_assert(sizeof(ArkStatModifierPackage) == 40);
static_assert(sizeof(ArkStatModifierPackage::ArkIDProperty) == 32);
static_assert(sizeof(ArkStatModifierPackage::ArkNameProperty) == 32);
static_assert(sizeof(ArkStatModifierPackage::ArkModifiersProperty) == 32);

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
static_assert(sizeof(ArkTutorialSystem) == 744);
static_assert(sizeof(ArkTutorialSystem::ContextualPackage) == 64);
static_assert(sizeof(ArkTutorialSystem::ContextualEntry) == 160);
static_assert(sizeof(ArkTutorialSystem::CardEntry) == 40);

#include "CSchedulerActionPoolBase.h"
static_assert(sizeof(CSchedulerActionPoolBase) == 24);

#include "ISchedulerAction.h"
static_assert(sizeof(ISchedulerAction) == 8);

#include "playerIArkCombatFocusListener.h"
static_assert(sizeof(IArkCombatFocusListener) == 8);

#if 0
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

#include "scriptbind_inventory.h"
static_assert(sizeof(CScriptBind_Inventory) == 96);

#include "scriptbind_itemsystem.h"
static_assert(sizeof(CScriptBind_ItemSystem) == 96);
#endif

#include "ScriptHandle.h"
static_assert(sizeof(ScriptHandle) == 8);
