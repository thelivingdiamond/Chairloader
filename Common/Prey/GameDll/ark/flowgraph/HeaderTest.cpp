// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/flowgraph/
#include "ArkFlowAngleRotation.h"
static_assert(sizeof(CArkFlowAngleRotation) == 24);

#include "ArkFlowConsoleEvent.h"
static_assert(sizeof(CArkFlowConsoleEvent) == 40);

#include "ArkFlowGraphManager.h"
static_assert(sizeof(CArkFlowGraphManager) == 136);
static_assert(sizeof(CArkFlowGraphManager::ConsoleEvent) == 8);

#include "ArkFlowInhibitJump.h"
static_assert(sizeof(ArkFlowInhibitJump) == 16);

#include "ArkFlowNightmareManagerEnable.h"
static_assert(sizeof(ArkFlowNightmareManagerEnable) == 16);

#include "ArkFlowNightmareManagerOnNightmareSpawned.h"
static_assert(sizeof(ArkFlowNightmareManagerOnNightmareSpawned) == 72);

#include "ArkFlowNodeAttentionLevelChanged.h"
static_assert(sizeof(ArkFlowNodeAttentionLevelChanged) == 48);

#include "ArkFlowNodeCarry.h"
static_assert(sizeof(ArkFlowNodeCarry) == 64);

#include "ArkFlowNodeClearAttention.h"
static_assert(sizeof(ArkFlowNodeClearAttention) == 16);

#include "ArkFlowNodeCreatePhantom.h"
static_assert(sizeof(ArkFlowNodeCreatePhantom) == 72);

#include "ArkFlowNodeDoomClock.h"
static_assert(sizeof(ArkFlowNodeDoomClock) == 16);
static_assert(sizeof(ArkFlowNodeDoomClockListener) == 72);
static_assert(sizeof(ArkFlowNodeDoomClockProfile) == 16);
static_assert(sizeof(ArkFlowNodeEnableDoomClock) == 16);
static_assert(sizeof(ArkFlowNodeGetDoomClockLevel) == 16);

#include "ArkFlowNodeEnablePatrolPath.h"
static_assert(sizeof(ArkFlowNodeEnablePatrolPath) == 16);

#include "ArkFlowNodeEntityLink.h"
static_assert(sizeof(CArkFlowNodeEntityLink) == 16);

#include "ArkFlowNodeFactionwideAttention.h"
static_assert(sizeof(ArkFlowNodeFactionwideAttention) == 80);

#include "ArkFlowNodeGate.h"
static_assert(sizeof(CArkFlowNodeGate) == 24);

#include "ArkFlowNodeGetAttention.h"
static_assert(sizeof(ArkFlowNodeGetAttention) == 16);

#include "ArkFlowNodeGetObjectiveState.h"
static_assert(sizeof(CArkFlowNodeGetObjectiveState) == 16);

#include "ArkFlowNodeGetPlayerCombatState.h"
static_assert(sizeof(ArkFlowNodeGetPlayerCombatState) == 16);

#include "ArkFlowNodeGetPsiPoints.h"
static_assert(sizeof(CArkFlowNodeGetPsiPoints) == 16);

#include "ArkFlowNodeGetTaskState.h"
static_assert(sizeof(CArkFlowNodeGetTaskState) == 16);

#include "ArkFlowNodeHelmet.h"
static_assert(sizeof(CArkFlowNodeChangeHelmet) == 16);
static_assert(sizeof(CArkFlowNodeHelmet) == 16);

#include "ArkFlowNodeMakeAiNoise.h"
static_assert(sizeof(ArkFlowNodeMakeAiNoise) == 16);

#include "ArkFlowNodeNpcAiDumb.h"
static_assert(sizeof(ArkFlowNodeNpcAiDumb) == 16);

#include "ArkFlowNodeNpcCreatePhantomInstant.h"
static_assert(sizeof(ArkFlowNodeNpcCreatePhantomInstant) == 16);

#include "ArkFlowNodeNpcCreatePhantomRequest.h"
static_assert(sizeof(ArkFlowNodeNpcCreatePhantomRequest) == 88);

#include "ArkFlowNodeNpcDeactivateCombatIntensity.h"
static_assert(sizeof(CArkFlowNodeNpcDeactivateCombatIntensity) == 16);

#include "ArkFlowNodeNpcDestroy.h"
static_assert(sizeof(CArkFlowNodeNpcDestroy) == 16);

#include "ArkFlowNodeNpcDialog.h"
static_assert(sizeof(ArkFlowNodeNpcDialog) == 16);

#include "ArkFlowNodeNpcDistractRequest.h"
static_assert(sizeof(ArkFlowNodeNpcDistractRequest) == 64);

#include "ArkFlowNodeNpcEnableAI.h"
static_assert(sizeof(ArkFlowNodeNpcEnableAI) == 16);

#include "ArkFlowNodeNpcEnableDistraction.h"
static_assert(sizeof(ArkFlowNodeNpcEnableDistraction) == 16);

#include "ArkFlowNodeNpcEnableWander.h"
static_assert(sizeof(ArkFlowNodeNpcEnableWander) == 16);
static_assert(sizeof(ArkFlowNodeNpcEncounterEnableWander) == 16);

#include "ArkFlowNodeNpcFaceEntity.h"
static_assert(sizeof(ArkFlowNodeNpcFaceEntity) == 184);

#include "ArkFlowNodeNpcFacePosition.h"
static_assert(sizeof(ArkFlowNodeNpcFacePosition) == 184);

#include "ArkFlowNodeNpcGetCountInVolume.h"
static_assert(sizeof(ArkFlowNodeNpcGetCountInVolume) == 16);

#include "ArkFlowNodeNpcGetHealth.h"
static_assert(sizeof(ArkFlowNodeNpcGetHealth) == 16);

#include "ArkFlowNodeNpcGodMode.h"
static_assert(sizeof(ArkFlowNodeNpcGodMode) == 16);
static_assert(sizeof(ArkFlowNodeNpcGodModeAll) == 16);

#include "ArkFlowNodeNpcGuardRequest.h"
static_assert(sizeof(ArkFlowNodeNpcGuardRequest) == 88);
static_assert(sizeof(ArkFlowNodeNpcGuardRequest::NpcRequest) == 28);

#include "ArkFlowNodeNpcHasAllTags.h"
static_assert(sizeof(ArkFlowNodeNpcHasAllTags) == 16);

#include "ArkFlowNodeNpcHasAnyTags.h"
static_assert(sizeof(ArkFlowNodeNpcHasAnyTags) == 16);

#include "ArkFlowNodeNpcIgnoreDistract.h"
static_assert(sizeof(ArkFlowNodeNpcEncounterIgnoreDistract) == 16);
static_assert(sizeof(ArkFlowNodeNpcIgnoreDistract) == 16);

#include "ArkFlowNodeNpcJumpRequest.h"
static_assert(sizeof(ArkFlowNodeNpcJumpRequest) == 328);

#include "ArkFlowNodeNpcKill.h"
static_assert(sizeof(CArkFlowNodeNpcKill) == 16);

#include "ArkFlowNodeNpcKillByTag.h"
static_assert(sizeof(CArkFlowNodeNpcKillByTag) == 16);

#include "ArkFlowNodeNpcLockBurrow.h"
static_assert(sizeof(ArkFlowNodeNpcLockBurrow) == 16);

#include "ArkFlowNodeNpcLockMimicry.h"
static_assert(sizeof(ArkFlowNodeNpcLockMimicry) == 16);

#include "ArkFlowNodeNpcLockStance.h"
static_assert(sizeof(ArkFlowNodeNpcLockStance) == 16);

#include "ArkFlowNodeNpcLockUnburrow.h"
static_assert(sizeof(ArkFlowNodeNpcLockUnburrow) == 16);

#include "ArkFlowNodeNpcLookAtEntity.h"
static_assert(sizeof(ArkFlowNodeNpcLookAtEntity) == 240);
static_assert(sizeof(ArkFlowNodeNpcLookAtEntityCustom) == 240);

#include "ArkFlowNodeNpcLookAtPosition.h"
static_assert(sizeof(ArkFlowNodeNpcLookAtPosition) == 240);

#include "ArkFlowNodeNpcMovementRequest.h"
static_assert(sizeof(CArkFlowNodeNpcMovementRequest) == 832);

#include "ArkFlowNodeNpcMovementTrackview.h"
static_assert(sizeof(CArkFlowNodeNpcMovementTrackview) == 640);

#include "ArkFlowNodeNpcNightmareForceMode.h"
static_assert(sizeof(ArkFlowNodeNpcNightmareForceMode) == 16);

#include "ArkFlowNodeNpcOnFleeEvent.h"
static_assert(sizeof(ArkFlowNodeNpcOnFleeEvent) == 72);

#include "ArkFlowNodeNpcPatrolRequest.h"
static_assert(sizeof(ArkFlowNodeNpcEncounterPatrolRequest) == 16);
static_assert(sizeof(ArkFlowNodeNpcPatrolRequest) == 16);

#include "ArkFlowNodeNpcPoltergeistThrow.h"
static_assert(sizeof(ArkFlowNodeNpcPoltergeistThrow) == 16);

#include "ArkFlowNodeNpcRecycleAttack.h"
static_assert(sizeof(ArkFlowNodeNpcRecycleAttack) == 24);

#include "ArkFlowNodeNpcSetGooed.h"
static_assert(sizeof(CArkFlowNodeNpcSetGooed) == 32);

#include "ArkFlowNodeNpcShiftRequest.h"
static_assert(sizeof(CArkFlowNodeNpcShiftRequest) == 440);

#include "ArkFlowNodeNpcSpawnedEntityId.h"
static_assert(sizeof(ArkFlowNodeNpcSpawnedEntityId) == 80);

#include "ArkFlowNodeNpcStopLurking.h"
static_assert(sizeof(ArkFlowNodeNpcStopLurking) == 16);

#include "ArkFlowNodeNpcStopLurkingForEncounter.h"
static_assert(sizeof(ArkFlowNodeNpcStopLurkingForEncounter) == 16);

#include "ArkFlowNodeNpcStopMimicking.h"
static_assert(sizeof(ArkFlowNodeNpcStopMimicking) == 16);

#include "ArkFlowNodeNpcStopMimickingForEncounter.h"
static_assert(sizeof(ArkFlowNodeNpcStopMimickingForEncounter) == 16);

#include "ArkFlowNodeNpcTakenDamage.h"
static_assert(sizeof(ArkFlowNodeNpcTakenDamage) == 88);

#include "ArkFlowNodeNpcUnlockBurrow.h"
static_assert(sizeof(ArkFlowNodeNpcUnlockBurrow) == 16);

#include "ArkFlowNodeNpcUnlockMimicry.h"
static_assert(sizeof(ArkFlowNodeNpcUnlockMimicry) == 16);

#include "ArkFlowNodeNpcUnlockUnburrow.h"
static_assert(sizeof(ArkFlowNodeNpcUnlockUnburrow) == 16);

#include "ArkFlowNodeObjectiveNotification.h"
static_assert(sizeof(CArkFlowNodeObjectiveNotification) == 16);

#include "ArkFlowNodeObjectiveState.h"
static_assert(sizeof(ArkFlowNodeObjectiveState) == 64);

#include "ArkFlowNodeOverlappingGooHandler.h"
static_assert(sizeof(CArkFlowNodeOverlappingGooHandler) == 64);
static_assert(sizeof(CArkFlowNodeOverlappingGooHandler::CArkOverlappingGooListener) == 8);

#include "ArkFlowNodePlayerAnimation.h"
static_assert(sizeof(ArkFlowNodePlayerAnimation) == 72);
static_assert(sizeof(ArkFlowNodePlayerAnimation::Action) == 136);

#include "ArkFlowNodePlayerCinematic.h"
static_assert(sizeof(CArkFlowNodePlayerCinematic) == 16);

#include "ArkFlowNodePlayerCombatStateChanged.h"
static_assert(sizeof(ArkFlowNodePlayerCombatStateChanged) == 48);

#include "ArkFlowNodePlayerMimicEvent.h"
static_assert(sizeof(CArkFlowNodePlayerMimicEvent) == 96);

#include "ArkFlowNodePlayerMimicState.h"
static_assert(sizeof(CArkFlowNodePlayerMimicState) == 16);

#include "ArkFlowNodePsiScanning.h"
static_assert(sizeof(CArkFlowNodeEnableScope) == 16);
static_assert(sizeof(CArkFlowNodePsiScanning) == 16);

#include "ArkFlowNodeQueryPsiPower.h"
static_assert(sizeof(CArkFlowNodeQueryPsiPower) == 16);

#include "ArkFlowNodeRelativeToSun.h"
static_assert(sizeof(CArkFlowNodeRelativeToSun) == 16);

#include "ArkFlowNodeRenderAlways.h"
static_assert(sizeof(CArkFlowNodeRenderAlways) == 16);

#include "ArkFlowNodeSetObjectiveDescription.h"
static_assert(sizeof(CArkFlowNodeSetObjectiveDescription) == 16);

#include "ArkFlowNodeSetPsiPoints.h"
static_assert(sizeof(CArkFlowNodeSetPsiPoints) == 16);

#include "ArkFlowNodeSetTaskMarker.h"
static_assert(sizeof(CArkFlowNodeSetTaskLocation) == 16);
static_assert(sizeof(CArkFlowNodeSetTaskMarker) == 16);
static_assert(sizeof(CArkFlowNodeSetTaskMarkerOverride) == 16);

#include "ArkFlowNodeSpawnAtTravelDest.h"
static_assert(sizeof(CArkFlowNodeSpawnAtTravelDest) == 16);

#include "ArkFlowNodeSpawnNpc.h"
static_assert(sizeof(ArkFlowNodeSpawnNpc) == 48);
static_assert(sizeof(ArkFlowNodeSpawnNpc::SpawnRequestInfo) == 56);

#include "ArkFlowNodeStartLurking.h"
static_assert(sizeof(ArkFlowNodeStartLurking) == 16);

#include "ArkFlowNodeTaskState.h"
static_assert(sizeof(ArkFlowNodeTaskState) == 64);

#include "ArkFlowNodeTrackviewPlaySequence.h"
static_assert(sizeof(CArkFlowNodeTrackviewPlaySequence) == 96);
static_assert(sizeof(CArkFlowNodeTrackviewPlaySequence::EntityInterpInfo) == 60);

#include "ArkFlowPlayerMannequinTag.h"
static_assert(sizeof(ArkFlowPlayerMannequinTag) == 16);

#include "ArkFlowResetGameToken.h"
static_assert(sizeof(ArkFlowResetGameToken) == 16);

#include "ArkFlowSendSignalPackage.h"
static_assert(sizeof(ArkFlowSendSignalPackage) == 16);
static_assert(sizeof(ArkFlowSendSignalPackageInArea) == 16);
static_assert(sizeof(ArkFlowSendSignalPackageToNpcsInVolume) == 16);

#include "ArkFlowSetEntityCollision.h"
static_assert(sizeof(ArkFlowSetEntityCollision) == 16);

#include "ArkFlowSignalAddModifier.h"
static_assert(sizeof(ArkFlowSignalAddModifier) == 16);

#include "ArkFlowSignalPackageReceiver.h"
static_assert(sizeof(ArkFlowSignalPackageReceiver) == 72);

#include "ArkFlowSignalReceiver.h"
static_assert(sizeof(ArkFlowSignalReceiver) == 88);

#include "ArkFlowSignalRemoveModifier.h"
static_assert(sizeof(ArkFlowSignalRemoveModifier) == 16);

#include "arkflowchecklocation.h"
static_assert(sizeof(ArkFlowNodeCheckLocation) == 16);

#include "arkflowenablerobotlight.h"
static_assert(sizeof(ArkFlowHideRobotLight) == 16);

#include "arkflownightmaremanagerdissipate.h"
static_assert(sizeof(ArkFlowNodeDissipateNightmare) == 16);

#include "arkflownodeabilities.h"
static_assert(sizeof(ArkFlowNeuromod) == 64);
static_assert(sizeof(ArkFlowNodePlayerAlien) == 72);
static_assert(sizeof(ArkFlowNodeScanAlienEvent) == 72);
static_assert(sizeof(ArkFlowNodeUnhideAbility) == 16);
static_assert(sizeof(CArkFlowNodeGiveAbility) == 16);
static_assert(sizeof(CArkFlowNodeHasAbility) == 80);
static_assert(sizeof(CArkFlowNodeLearnResearch) == 16);
static_assert(sizeof(CArkFlowNodePsiPowerActive) == 64);
static_assert(sizeof(CArkFlowNodePsiPowerMenuActive) == 64);
static_assert(sizeof(CArkFlowNodePsiPowerTargetingActive) == 64);
static_assert(sizeof(CArkFlowNodePurchaseRandomAbilities) == 16);

#include "arkflownodearchetype.h"
static_assert(sizeof(CArkFlowNode_CheckArchetype) == 16);

#include "arkflownodeaudiolog.h"
static_assert(sizeof(ArkFlowNodeAudioLogEvent) == 64);
static_assert(sizeof(CArkFlowNode_CollectAudioLog) == 16);

#include "arkflownodeaudiopropagation.h"
static_assert(sizeof(ArkFlowNodeSetPortalOcclusion) == 16);

#include "arkflownodebink.h"
static_assert(sizeof(ArkFlowNode_BinkMovie) == 104);

#include "arkflownodecamera.h"
static_assert(sizeof(CArkFlowNode_ForceStopCameraShakes) == 16);
static_assert(sizeof(CArkFlowNode_TriggerCameraShake) == 16);

#include "arkflownodechallengemode.h"
static_assert(sizeof(CArkFlowNode_IsInChallengeMode) == 16);

#include "arkflownodecharacter.h"
static_assert(sizeof(ArkFlowNodeSetCharacterAlternateName) == 16);

#include "arkflownodecharacterstatus.h"
static_assert(sizeof(CArkFlowNodeCharacterLocatedEvent) == 64);
static_assert(sizeof(CArkFlowNodeGetCharacterIsAlive) == 1);
static_assert(sizeof(CArkFlowNodeGetCharacterIsLocated) == 1);
static_assert(sizeof(CArkFlowNodeGetCharacterLocation) == 1);
static_assert(sizeof(CArkFlowNodeGetCharacterVitalSigns) == 1);
static_assert(sizeof(CArkFlowNodeSetCharacterDiscovered) == 1);
static_assert(sizeof(CArkFlowNodeSetCharacterHasTrackingChip) == 1);
static_assert(sizeof(CArkFlowNodeSetCharacterIsAlive) == 1);
static_assert(sizeof(CArkFlowNodeSetCharacterLocation) == 1);
static_assert(sizeof(CArkFlowNodeSetCharacterVitalSigns) == 1);

#include "arkflownodechipsets.h"
static_assert(sizeof(ArkFlowNodeChipsetInstalled) == 72);

#include "arkflownodeconversation.h"
static_assert(sizeof(CArkFlowNodeConversationEvent) == 72);
static_assert(sizeof(CArkFlowNodeConversationStatus) == 16);
static_assert(sizeof(CArkFlowNodeConversationTrigger) == 96);

#include "arkflownodecystoidmanager.h"
static_assert(sizeof(CArkFlowNode_CystoidManager) == 16);

#include "arkflownodedifficulty.h"
static_assert(sizeof(ArkFlowNode_TestDifficultyOption) == 16);

#include "arkflownodedisclaimer.h"
static_assert(sizeof(CArkFlowNode_ShowDisclaimer) == 96);

#include "arkflownodedocking.h"
static_assert(sizeof(ArkFlowNode_UpdateDockingSequence) == 16);

#include "arkflownodeencounters.h"
static_assert(sizeof(CArkFlowNodeAddEncounter) == 16);
static_assert(sizeof(CArkFlowNodeAddEncounterProfile) == 16);
static_assert(sizeof(CArkFlowNodeAddEncounterSpawnInfo) == 16);
static_assert(sizeof(CArkFlowNodeAddToEncounter) == 16);
static_assert(sizeof(CArkFlowNodeEliminateCurrentPopulation) == 16);
static_assert(sizeof(CArkFlowNodeRefreshCurrentPopulation) == 16);
static_assert(sizeof(CArkFlowNodeSetEncounterProfile) == 16);
static_assert(sizeof(CArkFlowNodeSetSpawnerActiveForEncounters) == 16);

#include "arkflownodeentitlement.h"
static_assert(sizeof(CArkFlowNode_HasEntitlement) == 16);
static_assert(sizeof(CArkFlowNode_PopulateBonusContainer) == 16);

#include "arkflownodeentitycontrol.h"
static_assert(sizeof(CArkFlowNode_EntityControl) == 16);
static_assert(sizeof(CArkFlowNode_EntityRender) == 16);
static_assert(sizeof(CArkFlowNode_UsePlayerTimer) == 16);

#include "arkflownodefabrication.h"
static_assert(sizeof(ArkFlowNode_FabricationPlanAcquired) == 64);
static_assert(sizeof(ArkFlowNode_ItemFabricated) == 64);
static_assert(sizeof(ArkFlowNode_ReverseEngineeredPlan) == 72);
static_assert(sizeof(ArkFlowNode_SetFabricationPlanError) == 64);

#include "arkflownodefocusmode.h"
static_assert(sizeof(CArkFlowNodeFocusModeEnabled) == 64);

#include "arkflownodegame.h"
static_assert(sizeof(CArkFlowNode_EndGame) == 16);
static_assert(sizeof(CArkFlowNode_PopulateEndGameUI) == 16);

#include "arkflownodegamedisconnect.h"
static_assert(sizeof(CArkFlowNode_GameDisconnect) == 16);

#include "arkflownodegamemetrics.h"
static_assert(sizeof(CArkFlowNodeGameMetric) == 64);
static_assert(sizeof(CArkFlowNodeIncrementGameMetric) == 16);

#include "arkflownodegravshaft.h"
static_assert(sizeof(CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate>) == 48);
static_assert(sizeof(CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate>) == 48);
static_assert(sizeof(IArkFlowNodeGravShaft) == 8);

#include "arkflownodehelpers.h"
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns>) == 24);
static_assert(sizeof(CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue>) == 24);

#include "arkflownodehud.h"
static_assert(sizeof(CArkFlowNode_EnableHUDArmor) == 16);
static_assert(sizeof(CArkFlowNode_EnableHUDHealth) == 16);

#include "arkflownodeinterferencegameeffect.h"
static_assert(sizeof(CArkFlowNode_InterferenceGameEffect) == 16);

#include "arkflownodeinventory.h"
static_assert(sizeof(CFlowNode_AddEquipmentPack) == 16);
static_assert(sizeof(CFlowNode_AddLoot) == 16);
static_assert(sizeof(CFlowNode_InventoryAddItem) == 24);
static_assert(sizeof(CFlowNode_InventoryAddItemById) == 24);
static_assert(sizeof(CFlowNode_InventoryGetItemQuantity) == 16);
static_assert(sizeof(CFlowNode_InventoryHasItem) == 80);
static_assert(sizeof(CFlowNode_InventoryItemListener) == 80);
static_assert(sizeof(CFlowNode_InventoryRemoveAllItems) == 16);
static_assert(sizeof(CFlowNode_InventoryRemoveItem) == 16);
static_assert(sizeof(CFlowNode_SpawnItemArchetype) == 16);

#include "arkflownodeisarchetypeinworld.h"
static_assert(sizeof(CArkFlowNode_IsArchetypeInWorld) == 16);

#include "arkflownodekeycard.h"
static_assert(sizeof(CArkFlowNodeGiveKeyCard) == 16);
static_assert(sizeof(CArkFlowNodeHasKeyCard) == 16);
static_assert(sizeof(CArkFlowNodeKeyCardAcquired) == 64);

#include "arkflownodekeycode.h"
static_assert(sizeof(CArkFlowNodeGiveKeyCode) == 16);
static_assert(sizeof(CArkFlowNodeHasKeyCode) == 16);
static_assert(sizeof(CArkFlowNodeKeyCodeAcquired) == 64);

#include "arkflownodelocation.h"
static_assert(sizeof(ArkFlowNodeRemoveLocationAlternateName) == 16);
static_assert(sizeof(ArkFlowNodeSetLocationAlternateName) == 16);
static_assert(sizeof(CArkFlowNodeDiscoverLocation) == 16);
static_assert(sizeof(CArkFlowNodeHasDiscoveredLocation) == 16);

#include "arkflownodemimicmorpheffect.h"
static_assert(sizeof(CArkFlowNode_MimicMorphEffect) == 16);

#include "arkflownodenote.h"
static_assert(sizeof(CArkFlowNodeGiveNote) == 16);
static_assert(sizeof(CArkFlowNodeHasNote) == 16);

#include "arkflownodenpcincombat.h"
static_assert(sizeof(ArkFlowNodeInCombat) == 16);

#include "arkflownodenpcpatrolrequestany.h"
static_assert(sizeof(ArkFlowNodeNpcPatrolRequestClosest) == 16);

#include "arkflownodenpcsendcallmimics.h"
static_assert(sizeof(ArkFlowNodeNPCCallMimicsTest) == 16);

#include "arkflownodenpcstartmimicking.h"
static_assert(sizeof(ArkFlowNodeStartMimicking) == 16);

#include "arkflownodeobjective.h"
static_assert(sizeof(CArkFlowNodeCheckLocateCharacterObjectiveTarget) == 1);
static_assert(sizeof(CArkFlowNodeEnableBounties) == 1);
static_assert(sizeof(CArkFlowNodeGiveLocateCharacterTask) == 1);
static_assert(sizeof(CArkFlowNodeLocateCharacterObjectiveEvent) == 72);
static_assert(sizeof(CArkFlowNodeShowObjectiveClue) == 1);

#include "arkflownodeoxygen.h"
static_assert(sizeof(CArkFlowNode_SetConsumingOxygen) == 16);

#include "arkflownodepda.h"
static_assert(sizeof(ArkFlowNodeResetPDAData) == 16);
static_assert(sizeof(ArkFlowNode_SetStationAccess) == 16);
static_assert(sizeof(CArkFlowNode_ClearLevelMapFog) == 16);
static_assert(sizeof(CArkFlowNode_ClosePDA) == 16);
static_assert(sizeof(CArkFlowNode_EnablePDADateAndTime) == 16);
static_assert(sizeof(CArkFlowNode_EnablePDAPage) == 16);
static_assert(sizeof(CArkFlowNode_OpenPDAPage) == 16);
static_assert(sizeof(CArkFlowNode_SetPDAAccess) == 16);

#include "arkflownodeplayer.h"
static_assert(sizeof(ArkFlowNode_EnableEnemyHealthMeter) == 16);
static_assert(sizeof(ArkFlowNode_GetCharacterSpecialObjective) == 16);
static_assert(sizeof(ArkFlowNode_GetPlayableCharacter) == 16);
static_assert(sizeof(ArkFlowNode_ItemRecycled) == 64);
static_assert(sizeof(ArkFlowNode_KillLatentPowers) == 16);
static_assert(sizeof(ArkFlowNode_LearnNameForResearchTopic) == 16);
static_assert(sizeof(ArkFlowNode_PlayerCorpseCreated) == 64);
static_assert(sizeof(ArkFlowNode_RestrictPlayerItems) == 16);
static_assert(sizeof(ArkFlowNode_SetPlayableCharacter) == 16);
static_assert(sizeof(ArkFlowNode_UpdatePlayableCharacterStatus) == 16);
static_assert(sizeof(CArkFlowNode_HideFailedAbilityInteractions) == 16);
static_assert(sizeof(CArkFlowNode_OnPlayerSpawned) == 16);
static_assert(sizeof(CArkFlowNode_SetPlayerStance) == 16);
static_assert(sizeof(CArkFlowNode_SkipNextDeathDelay) == 16);
static_assert(sizeof(CArkFlowNode_TestFlashlight) == 16);

#include "arkflownodeplayerequip.h"
static_assert(sizeof(CArkFlowNodeGetEquippedItem) == 16);
static_assert(sizeof(CArkFlowNodeSetEquippedItem) == 16);
static_assert(sizeof(CArkFlowNodeUnequipItem) == 16);

#include "arkflownodeplayerstatus.h"
static_assert(sizeof(ArkFlowNodeNotifyTrauma) == 72);

#include "arkflownodepoi.h"
static_assert(sizeof(ArkFlowNode_SetPOIMarker) == 16);

#include "arkflownodeposteffect.h"
static_assert(sizeof(ArkFlowNode_PostEffect) == 16);
static_assert(sizeof(ArkFlowNode_PostEffectParameter) == 16);

#include "arkflownodeprogress.h"
static_assert(sizeof(CArkFlowNode_CompleteChecklistEntry) == 16);
static_assert(sizeof(CArkFlowNode_EnableChecklistEntry) == 16);
static_assert(sizeof(CArkFlowNode_OnChecklistItemCompleted) == 72);
static_assert(sizeof(CArkFlowNode_TestChecklistEntry) == 16);

#include "arkflownoderoster.h"
static_assert(sizeof(CArkFlowNodeCharacterPasswordAcquired) == 64);
static_assert(sizeof(CArkFlowNodeGiveCharacterInfo) == 16);
static_assert(sizeof(CArkFlowNodeGiveCharacterPassword) == 16);
static_assert(sizeof(CArkFlowNodeHasCharacterPassword) == 16);

#include "arkflownodesetcurrentobjective.h"
static_assert(sizeof(CArkFlowNodeSetObjectiveTracked) == 16);

#include "arkflownodestat.h"
static_assert(sizeof(CArkFlowNodeStatChanged) == 80);
static_assert(sizeof(CArkFlowNodeStatModifierPackage) == 24);

#include "arkflownodesundisabler.h"
static_assert(sizeof(ArkFlowNode_SunDisabler) == 24);

#include "arkflownodetip.h"
static_assert(sizeof(CArkFlowNode_UnlockTips) == 16);

#include "arkflownodetranscribe.h"
static_assert(sizeof(ArkFlowNode_SilenceTranscribe) == 16);

#include "arkflownodetutorial.h"
static_assert(sizeof(CArkFlowNode_CollectTutorialCard) == 16);
static_assert(sizeof(CArkFlowNode_DisplayTutorial) == 64);
static_assert(sizeof(CArkFlowNode_EnableGameStateCondition) == 16);
static_assert(sizeof(CArkFlowNode_QueueTutorials) == 16);

#include "arkflownodeweapon.h"
static_assert(sizeof(CArkFlowNodeSpawnProjectile) == 16);

#include "arkflownodeworkstation.h"
static_assert(sizeof(CArkFlowNodeCheckDownloadHidden) == 16);
static_assert(sizeof(CArkFlowNodeCheckUtilityButtonEnabled) == 16);
static_assert(sizeof(CArkFlowNodeCheckUtilityButtonHidden) == 16);
static_assert(sizeof(CArkFlowNodeCheckUtilityEnabled) == 16);
static_assert(sizeof(CArkFlowNodeCheckUtilityHidden) == 16);
static_assert(sizeof(CArkFlowNodeCompareUtility) == 16);
static_assert(sizeof(CArkFlowNodeCompareUtilityButton) == 16);
static_assert(sizeof(CArkFlowNodeDownloadAcquired) == 64);
static_assert(sizeof(CArkFlowNodeEmailAcquired) == 64);
static_assert(sizeof(CArkFlowNodeHasDownload) == 16);
static_assert(sizeof(CArkFlowNodeHasEmail) == 16);
static_assert(sizeof(CArkFlowNodeHideEmail) == 16);
static_assert(sizeof(CArkFlowNodeSendEmail) == 16);
static_assert(sizeof(CArkFlowNodeSetDownloadHidden) == 16);
static_assert(sizeof(CArkFlowNodeSetUtilityButtonEnabled) == 16);
static_assert(sizeof(CArkFlowNodeSetUtilityButtonHidden) == 16);
static_assert(sizeof(CArkFlowNodeSetUtilityEnabled) == 16);
static_assert(sizeof(CArkFlowNodeSetUtilityHidden) == 16);
static_assert(sizeof(CArkFlowNodeWorkstationPopup) == 64);
static_assert(sizeof(CArkFlowNodeWorkstationResult) == 64);
static_assert(sizeof(CArkFlowNode_WhiplashPopup) == 16);

#include "arkflownodeworldui.h"
static_assert(sizeof(CArkFlowNode_ExamineWorldUI) == 16);
static_assert(sizeof(CArkFlowNode_KioskElevatorError) == 16);

#include "arkflowplayerweaponidlebreak.h"
static_assert(sizeof(CFlowNode_ArkPlayerWeaponIdleBreak) == 16);

#include "arkflowplayerweaponsensor.h"
static_assert(sizeof(CFlowNode_ArkPlayerWeaponSensor) == 72);

#include "arkflowrandomvaluenodes.h"
static_assert(sizeof(ArkFlowGetRandomValue) == 16);
static_assert(sizeof(ArkFlowGetShuffledListValue) == 16);
static_assert(sizeof(ArkFlowLockRandomSeed) == 16);

#include "arkflowremoteevent.h"
static_assert(sizeof(CArkFlowNodeRemoteEvent) == 72);
static_assert(sizeof(CArkFlowNodeSendRemoteEvent) == 16);
#endif // MOONCRASH
