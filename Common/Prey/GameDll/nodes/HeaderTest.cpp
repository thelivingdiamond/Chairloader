// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/nodes/
#include "AchievementNode.h"
static_assert(sizeof(CAchievementNode) == 16);

#include "FlowConvoyNode.h"
static_assert(sizeof(CConvoyPath) == 32);
static_assert(sizeof(CConvoyPath::SConvoyPathNode) == 20);
static_assert(sizeof(CFlowConvoyNode) == 144);
static_assert(sizeof(CFlowConvoyNode::SConvoyCoach) == 72);

#include "FlowFadeNode.h"
static_assert(sizeof(CFlowFadeNode) == 40);
static_assert(sizeof(CHUDFader) == 96);
static_assert(sizeof(CMasterFader) == 80);

#include "FlowPlayerStagingNode.h"
static_assert(sizeof(CFlowPlayerLinkNode) == 16);
static_assert(sizeof(CFlowPlayerStagingNode) == 16);

#include "PressureWaveNode.h"
static_assert(sizeof(CPressureWaveNode) == 120);

#include "TacticalScanNode.h"
static_assert(sizeof(CTacticalScanCompleteNode) == 80);
static_assert(sizeof(CTacticalScanCurrentControlNode) == 16);
static_assert(sizeof(CTacticalScanNode) == 80);
static_assert(sizeof(CTacticalScanStartNode) == 80);

#include "colorgradientnode.h"
static_assert(sizeof(CFlowNode_ColorGradient) == 24);

#include "flowactornodes.h"
static_assert(sizeof(CFlowNode_AIBodyCount) == 80);
static_assert(sizeof(CFlowNode_ActorSetPlayerModel) == 24);
static_assert(sizeof(CFlowNode_GetNearestActor) == 16);
static_assert(sizeof(CFlowNode_PlayerCinematicControl) == 16);
static_assert(sizeof(CFlowNode_PlayerLookAt) == 16);

#include "flowactorsensor.h"
static_assert(sizeof(CFlowNode_ActorSensor) == 104);
static_assert(sizeof(CFlowNode_OverrideFOV) == 32);

#include "flowcheckareanode.h"
static_assert(sizeof(CFlowNode_CheckArea) == 80);

#include "flownodesinput.h"
static_assert(sizeof(CG4FlowNode_XBoxAnalog) == 80);
static_assert(sizeof(CG4FlowNode_XBoxKey) == 80);

#include "flowpostfxnodes.h"
static_assert(sizeof(CFlowControlPlayerHealthEffect) == 16);
static_assert(sizeof(CFlowFXNode<FXParamsBloodSplats>) == 16);
static_assert(sizeof(CFlowFXNode<FXParamsGlittering>) == 16);
static_assert(sizeof(CFlowFXNode<FXParamsGlobal>) == 16);
static_assert(sizeof(CFlowFXNode<FXParamsGlow>) == 16);
static_assert(sizeof(CFlowFXNode<FXParamsScreenFrost>) == 16);
static_assert(sizeof(CFlowFXNode<FXParamsWaterDroplets>) == 16);
static_assert(sizeof(FXParamsBloodSplats) == 1);
static_assert(sizeof(FXParamsGlittering) == 1);
static_assert(sizeof(FXParamsGlobal) == 1);
static_assert(sizeof(FXParamsGlow) == 1);
static_assert(sizeof(FXParamsScreenFrost) == 1);
static_assert(sizeof(FXParamsWaterDroplets) == 1);

#include "flowvideoplayernodes.h"
static_assert(sizeof(CFlowFlashVideoPlayerNode) == 104);

#include "g2flowbasenode.h"
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowEnablePlayerSimulationReset>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowForceSatellite>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowGetRandomValue>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowGetShuffledListValue>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowHideRobotLight>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowInhibitJump>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowLockRandomSeed>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNeuromod>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNightmareManagerEnable>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeAbsoluteTimeEvent>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeAttentionLevelChanged>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeAudioLogEvent>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeCarry>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearAttention>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityToFactionEntities>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionToFactionEntities>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeClearRelationshipFactionEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeCreatePhantom>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeDispositionSwitch>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeDissipateNightmare>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeDoomClock>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeDoomClockProfile>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_FactionToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeEnableDoomClock>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeEnablePatrolPath>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeFlashlight>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGenderSelectMenu>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGetAttention>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGetDoomClockLevel>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGetFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGetGameTime>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeGetPlayerCombatState>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeMakeAiNoise>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNPCCallMimicsTest>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcAiDumb>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcCreatePhantomInstant>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcEnableAI>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcEnableDistraction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcEnableWander>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterEnableWander>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterIgnoreDistract>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterPatrolRequest>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterSetWanderContainer>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcGodMode>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcGodModeAll>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcHasAllTags>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcHasAnyTags>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcIgnoreDistract>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcLockBurrow>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcLockMimicry>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcLockStance>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcLockUnburrow>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcLookAtEntityCustom>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcMakeConscious>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcNightmareForceMode>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequest>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequestClosest>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcPoltergeistThrow>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcSetWanderContainer>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurking>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurkingForEncounter>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimicking>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimickingForEncounter>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_GetStartPos>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_SetDynamicNode>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockBurrow>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockMimicry>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockUnburrow>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodePlayerAlien>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodePlayerCombatStateChanged>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeRelativeTimeEvent>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeRemoveLocationAlternateName>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeResetPDAData>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeScanAlienEvent>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetCharacterAlternateName>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityToFactionEntities>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionToFactionEntities>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetFaction>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetGameTime>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetLocationAlternateName>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeSetPortalOcclusion>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeStartLurking>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeStartMimicking>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNodeUnhideAbility>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_EnableEnemyHealthMeter>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_FabricationPlanAcquired>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_GetCharacterSpecialObjective>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_GetPlayableCharacter>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_ItemFabricated>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_ItemRecycled>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_KillLatentPowers>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_LearnNameForResearchTopic>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_PlayerCorpseCreated>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_PostEffect>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_PostEffectParameter>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_RestrictPlayerItems>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_SetFabricationPlanError>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_SetPlayableCharacter>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_SetStationAccess>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_SilenceTranscribe>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_TestDifficultyOption>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowNode_UpdatePlayableCharacterStatus>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowPlayerMannequinTag>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowReadyRoom>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowReadyRoomListener>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowReadyRoomRequest>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowResetGameToken>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowSendSignalPackage>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowSendSignalPackageInArea>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<ArkFlowSendSignalPackageToNpcsInVolume>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CAchievementNode>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeAddEncounter>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeAddEncounterProfile>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeAddEncounterSpawnInfo>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeAddToEncounter>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeChangeHelmet>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeCharacterLocatedEvent>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeCheckDownloadHidden>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonEnabled>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonHidden>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityEnabled>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityHidden>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeCompareUtility>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeCompareUtilityButton>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeConversationStatus>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeDiscoverLocation>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeDownloadAcquired>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeEliminateCurrentPopulation>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeEmailAcquired>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeEnableScope>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeEntityLink>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeFocusModeEnabled>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeGetEquippedItem>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeGetTaskState>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeGiveAbility>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeGiveNote>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeHasAbility>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeHasDiscoveredLocation>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeHasNote>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeHelmet>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeHideEmail>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeIncrementGameMetric>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeKeyCardAcquired>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeKeyCodeAcquired>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeLearnResearch>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeLocateCharacterObjectiveEvent>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeNpcDeactivateCombatIntensity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeNpcDestroy>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeNpcKill>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeNpcKillByTag>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodePlayerCinematic>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodePlayerMimicState>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodePsiPowerActive>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodePsiPowerMenuActive>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodePsiPowerTargetingActive>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodePsiScanning>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodePurchaseRandomAbilities>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeRefreshCurrentPopulation>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeRemoteEvent>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeRenderAlways>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSendEmail>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetDownloadHidden>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetEncounterProfile>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetEquippedItem>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetObjectiveDescription>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetSpawnerActiveForEncounters>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetTaskLocation>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarker>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarkerOverride>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonEnabled>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonHidden>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetUtilityEnabled>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSetUtilityHidden>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeSpawnAtTravelDest>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNodeUnequipItem>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_CheckArchetype>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_ClearLevelMapFog>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_ClosePDA>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_CollectAudioLog>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_CollectTutorialCard>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_CompleteChecklistEntry>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_CystoidManager>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_EnableChecklistEntry>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_EnableGameStateCondition>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_EnableHUDArmor>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_EnableHUDHealth>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_EnablePDADateAndTime>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_EnablePDAPage>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_EndGame>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_EntityControl>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_EntityRender>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_ExamineWorldUI>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_ForceStopCameraShakes>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_GameDisconnect>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_HasEntitlement>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_HideFailedAbilityInteractions>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_InterferenceGameEffect>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_IsArchetypeInWorld>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_IsInChallengeMode>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_KioskElevatorError>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_MimicMorphEffect>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_OnPlayerSpawned>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_OpenPDAPage>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_PopulateBonusContainer>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_PopulateEndGameUI>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_QueueTutorials>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_SetConsumingOxygen>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_SetPDAAccess>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_SetPlayerStance>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_SkipNextDeathDelay>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_TestChecklistEntry>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_TestFlashlight>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_TriggerCameraShake>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_UnlockTips>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_UsePlayerTimer>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CArkFlowNode_WhiplashPopup>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowControlPlayerHealthEffect>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowFXNode<FXParamsBloodSplats> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlittering> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlobal> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlow> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowFXNode<FXParamsScreenFrost> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowFXNode<FXParamsWaterDroplets> >) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_AddEquipmentPack>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_AddLoot>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_ArkPlayerWeaponSensor>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_GetNearestActor>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_InventoryAddItem>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_InventoryAddItemById>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_InventoryGetItemQuantity>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_InventoryRemoveAllItems>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_InventoryRemoveItem>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_OverrideFOV>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_PlayerCinematicControl>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_PlayerLookAt>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_SetPostEffectParam>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_SimulatePlayerInput>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowNode_SpawnItemArchetype>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowPlayerLinkNode>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CFlowPlayerStagingNode>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CTacticalScanCurrentControlNode>) == 32);
static_assert(sizeof(CG2AutoRegFlowNode<CTacticalScanNode>) == 32);
static_assert(sizeof(CG2AutoRegFlowNodeBase) == 24);

#include "g2flowentityelectricconnector.h"
static_assert(sizeof(CFlowEntityElectricConnector) == 96);

#include "g2flowentityvelocity.h"
static_assert(sizeof(CFlowEntityVelocity) == 72);

#include "g2flowyesnogesturenode.h"
static_assert(sizeof(CFlowYesNoGesture) == 192);

#include "gamenodes.h"
static_assert(sizeof(CFlowNode_SetPostEffectParam) == 16);
static_assert(sizeof(CFlowSaveGameNode) == 48);

#include "ownerangularinterpolatornode.h"
static_assert(sizeof(CFlowNode_RotateSpeed) == 80);
static_assert(sizeof(CRotateEntityToExNode) == 128);
static_assert(sizeof(CRotateEntityToExNode::CArkOverlappingGooListener) == 8);
static_assert(sizeof(CRotateEntityTo_Node) == 80);

#include "ownerlinearinterpolatornode.h"
static_assert(sizeof(CMoveEntityTo) == 128);
static_assert(sizeof(CMoveEntityTo::CArkOverlappingGooListener) == 8);

#include "simulateplayerinputnode.h"
static_assert(sizeof(CFlowNode_SimulatePlayerInput) == 16);
#endif // MOONCRASH
