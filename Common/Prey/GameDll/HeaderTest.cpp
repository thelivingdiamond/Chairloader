// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/actordefinitions.h
#include "ArkInventory.h"
static_assert(sizeof(ArkInventory) == 136);
static_assert(sizeof(ArkInventory::StorageCell) == 20);

#include "arkitem.h"
static_assert(sizeof(CArkItem) == 360);

#include "IGameRules.h"
static_assert(sizeof(IGameRules) == 64);
static_assert(sizeof(IGameRules::SGameCollision) == 40);

#include "itemstring.h"
static_assert(sizeof(SharedString::CSharedString) == 8);

#include "SGameWeaponSwayParams.h"
static_assert(sizeof(SGameWeaponSwayParams) == 48);

#include "weaponbumpoffset.h"
static_assert(sizeof(CBumpOffset) == 44);

#include "weaponlookoffset.h"
static_assert(sizeof(SStaticWeaponSwayParams) == 108);
static_assert(sizeof(CLookOffset) == 168);

#include "weaponoffset.h"
static_assert(sizeof(SWeaponOffset) == 24);
static_assert(sizeof(CWeaponOffsetState) == 56);
static_assert(sizeof(CWeaponOffsetStack) == 88);
static_assert(sizeof(CWeaponOffsetStack::SWeaponOffsetLayer) == 32);

#include "weaponoffsetinput.h"
static_assert(sizeof(CWeaponOffsetInput) == 80);

#include "weaponrecoiloffset.h"
static_assert(sizeof(SStaticWeaponRecoilParams) == 24);
static_assert(sizeof(CRecoilOffset) == 80);

#include "weaponstrafeoffset.h"
static_assert(sizeof(CStrafeOffset) == 200);

#include "weaponzoomoffset.h"
static_assert(sizeof(CWeaponZoomOffset) == 208);
#else // MOONCRASH
// Header test file for path Prey/GameDll/
#include "ActorImpulseHandler.h"
static_assert(sizeof(CActorImpulseHandler) == 880);
static_assert(sizeof(CActorImpulseHandler::QueuedDeathImpulse) == 112);
static_assert(sizeof(CActorImpulseHandler::SFindMatchingSet) == 8);
static_assert(sizeof(CActorImpulseHandler::SImpulseSet) == 104);
static_assert(sizeof(CActorImpulseHandler::SImpulseSet::SImpulse) == 24);
static_assert(sizeof(CActorImpulseHandler::SSharedImpulseHandlerParams) == 40);

#include "ActorManager.h"
static_assert(sizeof(CActorManager) == 72);

#include "AnimActionAIAimPose.h"
static_assert(sizeof(CAnimActionAIAimPose) == 136);
static_assert(sizeof(SMannequinAiAimPoseUserParams) == 16);
static_assert(sizeof(SMannequinAiAimPoseUserParams::FragmentIDs) == 4);

#include "AnimActionAIAiming.h"
static_assert(sizeof(CAnimActionAIAiming) == 128);
static_assert(sizeof(SMannequinAiAimingUserParams) == 16);
static_assert(sizeof(SMannequinAiAimingUserParams::FragmentIDs) == 4);

#include "AnimActionAIDetail.h"
static_assert(sizeof(CAnimActionAIDetail) == 232);
static_assert(sizeof(SMannequinAIDetailParams) == 24);
static_assert(sizeof(SMannequinAIDetailParams::FragmentIDs) == 16);

#include "AnimActionAILookPose.h"
static_assert(sizeof(CAnimActionAILookPose) == 128);
static_assert(sizeof(CAnimActionAILookPoseEyes) == 128);
static_assert(sizeof(CAnimActionAILookPoseHead) == 128);
static_assert(sizeof(SMannequinAiLookPoseEyesUserParams) == 16);
static_assert(sizeof(SMannequinAiLookPoseEyesUserParams::FragmentIDs) == 4);
static_assert(sizeof(SMannequinAiLookPoseHeadUserParams) == 16);
static_assert(sizeof(SMannequinAiLookPoseHeadUserParams::FragmentIDs) == 4);
static_assert(sizeof(SMannequinAiLookPoseUserParams) == 16);
static_assert(sizeof(SMannequinAiLookPoseUserParams::FragmentIDs) == 4);

#include "AnimActionAILooking.h"
static_assert(sizeof(CAnimActionAILooking) == 128);
static_assert(sizeof(SMannequinAiLookingUserParams) == 16);
static_assert(sizeof(SMannequinAiLookingUserParams::FragmentIDs) == 4);

#include "AnimActionAIMovement.h"
static_assert(sizeof(CAnimActionAIMovement) == 336);
static_assert(sizeof(CAnimActionAIMovement::SStateInfo) == 12);
static_assert(sizeof(SMannequinAIMovementParams) == 40);
static_assert(sizeof(SMannequinAIMovementParams::FragmentIDs) == 20);
static_assert(sizeof(SMannequinAIMovementParams::ScopeIDs) == 4);
static_assert(sizeof(SMannequinAIMovementParams::TagIDs) == 4);

#include "AnimActionAIStance.h"
static_assert(sizeof(CAnimActionAIStance) == 144);
static_assert(sizeof(SMannequinAiStanceUserParams) == 88);
static_assert(sizeof(SMannequinAiStanceUserParams::Fragments) == 72);
static_assert(sizeof(SMannequinAiStanceUserParams::Fragments::SCODE_AI_ChangeStance) == 72);
static_assert(sizeof(SMannequinAiStanceUserParams::Fragments::SCODE_AI_ChangeStance::FragmentTagIDs) == 60);
static_assert(sizeof(SMannequinAiStanceUserParams::ScopeIDs) == 4);

#include "AnimActionBlendFromRagdoll.h"
static_assert(sizeof(CAnimActionBlendFromRagdoll) == 208);
static_assert(sizeof(CAnimActionBlendFromRagdollSleep) == 264);
static_assert(sizeof(SMannequinFallAndPlayParams) == 16);
static_assert(sizeof(SMannequinFallAndPlayParams::FragmentIDs) == 4);

#include "ArkFlowNodeClearAllTaskMarkers.h"
static_assert(sizeof(CArkFlowNodeClearAllTaskMarkers) == 16);

#include "ArkInventory.h"
static_assert(sizeof(ArkInventory) == 128);
static_assert(sizeof(ArkInventory::StorageCell) == 20);

#include "ArkItem.h"
static_assert(sizeof(CArkItem) == 384);

#include "BasicEventListener.h"
static_assert(sizeof(CBasicEventListener) == 16);
static_assert(sizeof(IBasicEventListener) == 8);

#include "BodyManagerCVars.h"
static_assert(sizeof(CBodyManagerCVars) == 1);

#include "CorpseManager.h"
static_assert(sizeof(CCorpseManager) == 696);
static_assert(sizeof(CCorpseManager::SCorpseInfo) == 28);

#include "CryActor.h"
static_assert(sizeof(CCryActor) == 6008);
static_assert(sizeof(CCryActor::AttachmentsParams) == 144);
static_assert(sizeof(CCryActor::AttachmentsParams::SWeaponAttachment) == 4);
static_assert(sizeof(CCryActor::DropItemParams) == 8);
static_assert(sizeof(CCryActor::ExchangeItemParams) == 8);
static_assert(sizeof(CCryActor::ItemIdParam) == 8);
static_assert(sizeof(CCryActor::KillCamFPData) == 64);
static_assert(sizeof(CCryActor::KillParams) == 68);
static_assert(sizeof(CCryActor::MethodInfo_ClAssignWeaponAttachments) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClClearInventory) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClDrop) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClKill) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClKillFPCamData) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClMoveTo) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClPickUp) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClRevive) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClSimpleKill) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClStartUse) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClStopUse) == 8);
static_assert(sizeof(CCryActor::MethodInfo_ClUseRequestProcessed) == 8);
static_assert(sizeof(CCryActor::MethodInfo_SvKillFPCamData) == 8);
static_assert(sizeof(CCryActor::MethodInfo_SvRequestDropItem) == 8);
static_assert(sizeof(CCryActor::MethodInfo_SvRequestExchangeItem) == 8);
static_assert(sizeof(CCryActor::MethodInfo_SvRequestPickUpItem) == 8);
static_assert(sizeof(CCryActor::MethodInfo_SvRequestUseItem) == 8);
static_assert(sizeof(CCryActor::MoveParams) == 28);
static_assert(sizeof(CCryActor::NoParams) == 1);
static_assert(sizeof(CCryActor::Params_ClAssignWeaponAttachments) == 144);
static_assert(sizeof(CCryActor::Params_ClClearInventory) == 1);
static_assert(sizeof(CCryActor::Params_ClDrop) == 8);
static_assert(sizeof(CCryActor::Params_ClKill) == 68);
static_assert(sizeof(CCryActor::Params_ClKillFPCamData) == 64);
static_assert(sizeof(CCryActor::Params_ClMoveTo) == 28);
static_assert(sizeof(CCryActor::Params_ClPickUp) == 8);
static_assert(sizeof(CCryActor::Params_ClRevive) == 8);
static_assert(sizeof(CCryActor::Params_ClSimpleKill) == 1);
static_assert(sizeof(CCryActor::Params_ClStartUse) == 8);
static_assert(sizeof(CCryActor::Params_ClStopUse) == 8);
static_assert(sizeof(CCryActor::Params_ClUseRequestProcessed) == 1);
static_assert(sizeof(CCryActor::Params_SvKillFPCamData) == 64);
static_assert(sizeof(CCryActor::Params_SvRequestDropItem) == 8);
static_assert(sizeof(CCryActor::Params_SvRequestExchangeItem) == 8);
static_assert(sizeof(CCryActor::Params_SvRequestPickUpItem) == 8);
static_assert(sizeof(CCryActor::Params_SvRequestUseItem) == 8);
static_assert(sizeof(CCryActor::PickItemParams) == 8);
static_assert(sizeof(CCryActor::ReviveParams) == 8);
static_assert(sizeof(CCryActor::SBlendRagdollParams) == 24);
static_assert(sizeof(SActorAnimationEvents) == 112);
static_assert(sizeof(SActorPhysics) == 112);
static_assert(sizeof(SIKLimb) == 156);
static_assert(sizeof(SLinkStats) == 8);

#include "CustomReactionFunctions.h"
static_assert(sizeof(CCustomReactionFunctions) == 136);

#include "DLCManager.h"
static_assert(sizeof(CDLCManager) == 71112);

#include "DataPatchDownloader.h"
static_assert(sizeof(CDataPatchDownloader) == 48);

#include "DownloadMgr.h"
static_assert(sizeof(CDownloadMgr) == 56);
static_assert(sizeof(CDownloadableResource) == 632);
static_assert(sizeof(IDataListener) == 8);

#include "EquipmentManager.h"
static_assert(sizeof(CEquipmentManager) == 32);
static_assert(sizeof(CEquipmentManager::SEquipmentPack) == 56);

#include "ExactPositioning.h"
static_assert(sizeof(CExactPositioning) == 256);
static_assert(sizeof(CExactPositioning::SStateMachineEvent) == 4);

#include "ExactPositioningTrigger.h"
static_assert(sizeof(CExactPositioningTrigger) == 108);

#include "FragmentVariationHelper.h"
static_assert(sizeof(CFragmentVariationHelper) == 88);

#include "Game.h"
static_assert(sizeof(BufferUtil) == 24);
static_assert(sizeof(CGame) == 1136);
static_assert(sizeof(CGame::CDifficultyConfigSink) == 16);
static_assert(sizeof(CGame::CMPConfigSink) == 8);
static_assert(sizeof(CGame::IRenderSceneListener) == 8);
static_assert(sizeof(CGame::SDedicatedConfigSink) == 8);
static_assert(sizeof(CGame::SInviteAcceptedData) == 32);
static_assert(sizeof(CGame::SPlatformInfo) == 8);

#include "GameActions.h"
static_assert(sizeof(CGameActions) == 4032);

#include "GameCVars.h"
static_assert(sizeof(SAICollisions) == 16);
static_assert(sizeof(SAIPerceptionCVars) == 32);
static_assert(sizeof(SAIThreatModifierCVars) == 72);
static_assert(sizeof(SAltNormalization) == 12);
static_assert(sizeof(SCVars) == 3680);
static_assert(sizeof(SCaptureTheFlagParams) == 4);
static_assert(sizeof(SDeathCamSPParams) == 28);
static_assert(sizeof(SExtractionParams) == 12);
static_assert(sizeof(SJumpAirControl) == 12);
static_assert(sizeof(SPlayerEnemyRamming) == 28);
static_assert(sizeof(SPlayerHealth) == 100);
static_assert(sizeof(SPlayerLadder) == 8);
static_assert(sizeof(SPlayerLedgeClamber) == 12);
static_assert(sizeof(SPlayerMelee) == 88);
static_assert(sizeof(SPlayerMovement) == 56);
static_assert(sizeof(SPlayerPickAndThrow) == 180);
static_assert(sizeof(SPlayerSlideControl) == 24);
static_assert(sizeof(SPostEffect) == 52);
static_assert(sizeof(SPredatorParams) == 8);
static_assert(sizeof(SSpectacularKillCVars) == 28);

#include "GameCache.h"
static_assert(sizeof(CGameCache) == 200);
static_assert(sizeof(CGameCache::SActorClassLuaCache) == 16);
static_assert(sizeof(CGameCache::SActorInstanceLuaCache) == 8);
static_assert(sizeof(CGameCache::STextureKey) == 8);
static_assert(sizeof(CGameCache::STextureKey::compare) == 1);
static_assert(sizeof(CGameCharacterDBAs) == 48);
static_assert(sizeof(CGameCharacterDBAs::SDBAGroup) == 32);
static_assert(sizeof(CGameCharacterDBAs::SDBAGroupUser) == 32);

#include "GameLocalizationManager.h"
static_assert(sizeof(CGameLocalizationManager) == 32);

#include "GamePhysicsSettings.h"
static_assert(sizeof(CGamePhysicsSettings) == 288);

#include "GameRules.h"
static_assert(sizeof(CGameRules) == 14056);
static_assert(sizeof(CGameRules::ActivateHitIndicatorParams) == 12);
static_assert(sizeof(CGameRules::ChangeTeamParams) == 12);
static_assert(sizeof(CGameRules::ChatMessageParams) == 32);
static_assert(sizeof(CGameRules::EHitType) == 1);
static_assert(sizeof(CGameRules::EHitTypeFlag) == 1);
static_assert(sizeof(CGameRules::EntityParams) == 4);
static_assert(sizeof(CGameRules::EquipmentLoadoutParams) == 16);
static_assert(sizeof(CGameRules::ForbiddenAreaWarningParams) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClActivateHitIndicator) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClAddPoints) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClAfterMatchAwards) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClEnteredGame) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClExplosion) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClHostMigrationFinished) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClHostMigrationPlayerJoined) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClMidMigrationJoin) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClModuleRMIDoubleEntity) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClModuleRMIEntityWithTime) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClModuleRMISingleEntity) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClNetConsoleCommand) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClPathFollowingAttachToPath) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClPostInit) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClPredictionFailed) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClProcessHit) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClProjectileExplosion) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClProjectileExplosion_Impact) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClRenameEntity) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClSetGameStartTimer) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClSetGameStartedTime) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClSetTeam) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClStartingPrematchCountDown) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClTaggedEntity) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClTeamFull) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClTextMessage) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClTrackViewSynchAnimations) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClUpdateRespawnData) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClVictoryPlayer) == 8);
static_assert(sizeof(CGameRules::MethodInfo_ClVictoryTeam) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvAfterMatchAwardsWorking) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvHostMigrationRequestSetup) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvModuleRMIOnAction) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvModuleRMISingleEntity) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvRequestChangeTeam) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvRequestHit) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvRequestRename) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvRequestRevive) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvRequestSpectatorMode) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvRequestTagEntity) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvSetEquipmentLoadout) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvSuccessfulFlashBang) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvTrackViewRequestAnimation) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvVote) == 8);
static_assert(sizeof(CGameRules::MethodInfo_SvVoteNo) == 8);
static_assert(sizeof(CGameRules::NetConsoleCommandParams) == 8);
static_assert(sizeof(CGameRules::NoParams) == 1);
static_assert(sizeof(CGameRules::Params_ClActivateHitIndicator) == 12);
static_assert(sizeof(CGameRules::Params_ClAddPoints) == 16);
static_assert(sizeof(CGameRules::Params_ClAfterMatchAwards) == 65);
static_assert(sizeof(CGameRules::Params_ClEnteredGame) == 1);
static_assert(sizeof(CGameRules::Params_ClHostMigrationFinished) == 1);
static_assert(sizeof(CGameRules::Params_ClHostMigrationPlayerJoined) == 4);
static_assert(sizeof(CGameRules::Params_ClMidMigrationJoin) == 8);
static_assert(sizeof(CGameRules::Params_ClModuleRMIDoubleEntity) == 16);
static_assert(sizeof(CGameRules::Params_ClModuleRMIEntityWithTime) == 24);
static_assert(sizeof(CGameRules::Params_ClModuleRMISingleEntity) == 12);
static_assert(sizeof(CGameRules::Params_ClNetConsoleCommand) == 8);
static_assert(sizeof(CGameRules::Params_ClPostInit) == 12);
static_assert(sizeof(CGameRules::Params_ClPredictionFailed) == 4);
static_assert(sizeof(CGameRules::Params_ClProcessHit) == 28);
static_assert(sizeof(CGameRules::Params_ClRenameEntity) == 16);
static_assert(sizeof(CGameRules::Params_ClSetGameStartTimer) == 8);
static_assert(sizeof(CGameRules::Params_ClSetGameStartedTime) == 8);
static_assert(sizeof(CGameRules::Params_ClSetTeam) == 8);
static_assert(sizeof(CGameRules::Params_ClStartingPrematchCountDown) == 4);
static_assert(sizeof(CGameRules::Params_ClTaggedEntity) == 16);
static_assert(sizeof(CGameRules::Params_ClTeamFull) == 1);
static_assert(sizeof(CGameRules::Params_ClTextMessage) == 56);
static_assert(sizeof(CGameRules::Params_ClTrackViewSynchAnimations) == 136);
static_assert(sizeof(CGameRules::Params_ClUpdateRespawnData) == 8);
static_assert(sizeof(CGameRules::Params_ClVictoryPlayer) == 276);
static_assert(sizeof(CGameRules::Params_ClVictoryTeam) == 464);
static_assert(sizeof(CGameRules::Params_SvAfterMatchAwardsWorking) == 808);
static_assert(sizeof(CGameRules::Params_SvHostMigrationRequestSetup) == 44);
static_assert(sizeof(CGameRules::Params_SvModuleRMIOnAction) == 12);
static_assert(sizeof(CGameRules::Params_SvModuleRMISingleEntity) == 12);
static_assert(sizeof(CGameRules::Params_SvRequestChangeTeam) == 12);
static_assert(sizeof(CGameRules::Params_SvRequestRename) == 16);
static_assert(sizeof(CGameRules::Params_SvRequestRevive) == 8);
static_assert(sizeof(CGameRules::Params_SvRequestSpectatorMode) == 16);
static_assert(sizeof(CGameRules::Params_SvRequestTagEntity) == 16);
static_assert(sizeof(CGameRules::Params_SvSetEquipmentLoadout) == 16);
static_assert(sizeof(CGameRules::Params_SvSuccessfulFlashBang) == 12);
static_assert(sizeof(CGameRules::Params_SvTrackViewRequestAnimation) == 4);
static_assert(sizeof(CGameRules::Params_SvVote) == 1);
static_assert(sizeof(CGameRules::Params_SvVoteNo) == 1);
static_assert(sizeof(CGameRules::PostInitParams) == 12);
static_assert(sizeof(CGameRules::ProcessHitParams) == 28);
static_assert(sizeof(CGameRules::RenameEntityParams) == 16);
static_assert(sizeof(CGameRules::SAfterMatchAwardWorkingsParams) == 808);
static_assert(sizeof(CGameRules::SAfterMatchAwardWorkingsParams::SWorkingValue) == 8);
static_assert(sizeof(CGameRules::SAfterMatchAwardsParams) == 65);
static_assert(sizeof(CGameRules::SCollisionHitInfo) == 88);
static_assert(sizeof(CGameRules::SEntityRemovalData) == 12);
static_assert(sizeof(CGameRules::SEntityRespawn) == 8);
static_assert(sizeof(CGameRules::SEntityRespawnData) == 80);
static_assert(sizeof(CGameRules::SEquipmentLoadOutPreCacheCallback) == 8);
static_assert(sizeof(CGameRules::SForbiddenAreaHelper) == 12);
static_assert(sizeof(CGameRules::SHostMigrationClientControlledParams) == 96);
static_assert(sizeof(CGameRules::SHostMigrationClientControlledParams::SAmmoParams) == 16);
static_assert(sizeof(CGameRules::SHostMigrationClientRequestParams) == 44);
static_assert(sizeof(CGameRules::SMidMigrationJoinParams) == 8);
static_assert(sizeof(CGameRules::SMigratingPlayerInfo) == 72);
static_assert(sizeof(CGameRules::SModuleRMIEntityParams) == 12);
static_assert(sizeof(CGameRules::SModuleRMIEntityTimeParams) == 24);
static_assert(sizeof(CGameRules::SModuleRMISvClientActionParams) == 12);
static_assert(sizeof(CGameRules::SModuleRMISvClientActionParams::UActionData) == 4);
static_assert(sizeof(CGameRules::SModuleRMISvClientActionParams::UActionData::SHelperCarryPickup) == 4);
static_assert(sizeof(CGameRules::SModuleRMITwoEntityParams) == 16);
static_assert(sizeof(CGameRules::SPlayerEndGameStatsParams) == 260);
static_assert(sizeof(CGameRules::SPlayerEndGameStatsParams::SPlayerEndGameStats) == 16);
static_assert(sizeof(CGameRules::SPredictionParams) == 4);
static_assert(sizeof(CGameRules::SRespawnUpdateParams) == 8);
static_assert(sizeof(CGameRules::SSuccessfulFlashBangParams) == 12);
static_assert(sizeof(CGameRules::STeamScore) == 6);
static_assert(sizeof(CGameRules::STrackViewParameters) == 136);
static_assert(sizeof(CGameRules::STrackViewRequestParameters) == 4);
static_assert(sizeof(CGameRules::ScoreChangeParams) == 16);
static_assert(sizeof(CGameRules::ServerReviveParams) == 8);
static_assert(sizeof(CGameRules::ServerSpectatorParams) == 8);
static_assert(sizeof(CGameRules::SetGameTimeParams) == 8);
static_assert(sizeof(CGameRules::SetTeamParams) == 8);
static_assert(sizeof(CGameRules::SpawnGroupParams) == 4);
static_assert(sizeof(CGameRules::SpectatorModeParams) == 16);
static_assert(sizeof(CGameRules::StartingPrematchCountDownParams) == 4);
static_assert(sizeof(CGameRules::StringParams) == 8);
static_assert(sizeof(CGameRules::TFinishedOnLoadMoviesParams) == 24);
static_assert(sizeof(CGameRules::TSynqMoviesParams) == 24);
static_assert(sizeof(CGameRules::TSynqMoviesParams::TPlayingMovie) == 16);
static_assert(sizeof(CGameRules::TempRadarTaggingParams) == 16);
static_assert(sizeof(CGameRules::TextMessageParams) == 56);
static_assert(sizeof(CGameRules::TwoEntityParams) == 8);
static_assert(sizeof(CGameRules::UInt8Param) == 1);
static_assert(sizeof(CGameRules::VictoryPlayerParams) == 276);
static_assert(sizeof(CGameRules::VictoryTeamParams) == 464);
static_assert(sizeof(SDeferredMfxExplosion) == 24);
static_assert(sizeof(SPathFollowingAttachToPathParameters) == 36);
static_assert(sizeof(SProjectileExplosionParams) == 80);

#include "GameStartup.h"
static_assert(sizeof(CCVarsWhiteList) == 8);
static_assert(sizeof(CGameStartup) == 104);
static_assert(sizeof(GameStartupErrorObserver) == 8);

#include "GodMode.h"
static_assert(sizeof(CGodMode) == 60);

#include "HitDeathReactions.h"
static_assert(sizeof(CAnimActionRagdoll) == 144);
static_assert(sizeof(CHitDeathReactions) == 360);
static_assert(sizeof(CHitDeathReactions::SCustomAnim) == 16);
static_assert(sizeof(CHitDeathReactions::SPredFindValidReaction) == 32);
static_assert(sizeof(CHitDeathReactionsPhysics) == 48);
static_assert(sizeof(CHitDeathReactionsPhysics::SPrimitiveRequest) == 8);

#include "HitDeathReactionsSystem.h"
static_assert(sizeof(CHitDeathReactionsSystem) == 2752);
static_assert(sizeof(CHitDeathReactionsSystem::SFailSafeProfile) == 64);
static_assert(sizeof(CHitDeathReactionsSystem::SPredGetAnims) == 0);
static_assert(sizeof(CHitDeathReactionsSystem::SPredGetMemoryUsage) == 8);
static_assert(sizeof(CHitDeathReactionsSystem::SPredRequestAnims) == 32);
static_assert(sizeof(CHitDeathReactionsSystem::SReactionsProfile) == 96);
static_assert(sizeof(CHitDeathReactionsSystem::STagMappingHelper) == 56);

#include "IGameRules.h"
static_assert(sizeof(IGameRules) == 64);
static_assert(sizeof(IGameRules::SGameCollision) == 40);

#include "IKTorsoAim_Helper.h"
static_assert(sizeof(CIKTorsoAim_Helper) == 48);
static_assert(sizeof(CIKTorsoAim_Helper::SIKTorsoParams) == 88);

#include "Item.h"
static_assert(sizeof(CItem) == 728);
static_assert(sizeof(CItem::AccessoryParams) == 2);
static_assert(sizeof(CItem::COwnerInfo) == 24);
static_assert(sizeof(CItem::EmptyParams) == 1);
static_assert(sizeof(CItem::ExchangeToNextItem) == 0);
static_assert(sizeof(CItem::MethodInfo_ClAttachAccessory) == 8);
static_assert(sizeof(CItem::MethodInfo_ClAttachInitialAccessory) == 8);
static_assert(sizeof(CItem::MethodInfo_ClDetachAccessory) == 8);
static_assert(sizeof(CItem::MethodInfo_ClEnterModify) == 8);
static_assert(sizeof(CItem::MethodInfo_ClLeaveModify) == 8);
static_assert(sizeof(CItem::MethodInfo_SvRequestAttachAccessory) == 8);
static_assert(sizeof(CItem::MethodInfo_SvRequestDetachAccessory) == 8);
static_assert(sizeof(CItem::MethodInfo_SvRequestEnterModify) == 8);
static_assert(sizeof(CItem::MethodInfo_SvRequestLeaveModify) == 8);
static_assert(sizeof(CItem::Params_ClAttachAccessory) == 2);
static_assert(sizeof(CItem::Params_ClAttachInitialAccessory) == 2);
static_assert(sizeof(CItem::Params_ClDetachAccessory) == 2);
static_assert(sizeof(CItem::Params_ClEnterModify) == 1);
static_assert(sizeof(CItem::Params_ClLeaveModify) == 1);
static_assert(sizeof(CItem::Params_SvRequestAttachAccessory) == 2);
static_assert(sizeof(CItem::Params_SvRequestDetachAccessory) == 2);
static_assert(sizeof(CItem::Params_SvRequestEnterModify) == 1);
static_assert(sizeof(CItem::Params_SvRequestLeaveModify) == 1);
static_assert(sizeof(CItem::SAccessoryInfo) == 16);
static_assert(sizeof(CItem::SEditorStats) == 8);
static_assert(sizeof(CItem::SEntityProperties) == 32);
static_assert(sizeof(CItem::SRespawnProperties) == 8);
static_assert(sizeof(CItem::SStats) == 44);
static_assert(sizeof(CItem::SelectAction) == 1);
static_assert(sizeof(CItem::SwitchHandAction) == 16);
static_assert(sizeof(SItemStrings) == 56);

#include "ItemScheduler.h"
static_assert(sizeof(CItemScheduler) == 104);
static_assert(sizeof(CItemScheduler::SScheduledAction) == 16);
static_assert(sizeof(CItemScheduler::STimerAction) == 16);
static_assert(sizeof(CItemScheduler::compare_timers) == 1);
static_assert(sizeof(CSchedulerAction<CItem::SelectAction>) == 16);
static_assert(sizeof(CSchedulerActionPool<CItem::SelectAction>) == 120);

#include "ItemSharedParams.h"
static_assert(sizeof(CItemSharedParams) == 960);
static_assert(sizeof(SAimAnimsBlock) == 128);
static_assert(sizeof(SLaserParams) == 48);
static_assert(sizeof(SParams) == 632);

#include "LookAim_Helper.h"
static_assert(sizeof(CLookAim_Helper) == 104);

#include "ModInfo.h"
static_assert(sizeof(ModInfo) == 1976);

#include "ModInfoManager.h"
static_assert(sizeof(CModInfoManager) == 56);

#include "MovementTransitions.h"
static_assert(sizeof(CMovementTransitions) == 48);
static_assert(sizeof(STransition) == 88);
static_assert(sizeof(STransitionSelectionParams) == 92);

#include "MovementTransitionsController.h"
static_assert(sizeof(CAnimActionMovementTransition) == 224);
static_assert(sizeof(CCornerSmoother) == 1640);
static_assert(sizeof(CCornerSmoother::SCurveSettings) == 24);
static_assert(sizeof(CCornerSmoother::SPrediction) == 804);
static_assert(sizeof(CCornerSmoother::SPredictionSettings) == 56);
static_assert(sizeof(CMovementTransitionsController) == 184);

#include "MovementTransitionsSystem.h"
static_assert(sizeof(CMovementTransitionsSystem) == 24);

#include "Player.h"
static_assert(sizeof(CPlayer) == 8128);
static_assert(sizeof(CPlayer::EntityParams) == 4);
static_assert(sizeof(CPlayer::MethodInfo_ClAbortStealthKill) == 8);
static_assert(sizeof(CPlayer::MethodInfo_ClApplyMeleeImpulse) == 8);
static_assert(sizeof(CPlayer::MethodInfo_ClDelayedDetonation) == 8);
static_assert(sizeof(CPlayer::MethodInfo_ClDeployMicrowaveBeam) == 8);
static_assert(sizeof(CPlayer::MethodInfo_ClIncrementIntStat) == 8);
static_assert(sizeof(CPlayer::MethodInfo_ClLeaveFromLadder) == 8);
static_assert(sizeof(CPlayer::MethodInfo_SvOnXPChanged) == 8);
static_assert(sizeof(CPlayer::MethodInfo_SvRequestLeaveFromLadder) == 8);
static_assert(sizeof(CPlayer::MethodInfo_SvRequestMicrowaveBeam) == 8);
static_assert(sizeof(CPlayer::MethodInfo_SvRequestUseLadder) == 8);
static_assert(sizeof(CPlayer::Params_ClAbortStealthKill) == 8);
static_assert(sizeof(CPlayer::Params_ClApplyMeleeImpulse) == 16);
static_assert(sizeof(CPlayer::Params_ClDelayedDetonation) == 4);
static_assert(sizeof(CPlayer::Params_ClIncrementIntStat) == 4);
static_assert(sizeof(CPlayer::Params_ClLeaveFromLadder) == 4);
static_assert(sizeof(CPlayer::Params_SvRequestLeaveFromLadder) == 4);
static_assert(sizeof(CPlayer::Params_SvRequestUseLadder) == 8);
static_assert(sizeof(CPlayer::SIntStatParams) == 4);
static_assert(sizeof(CPlayer::SPlayerMeleeImpulseParams) == 16);
static_assert(sizeof(CPlayer::SReactionAnim) == 24);
static_assert(sizeof(CPlayer::SRequestLeaveLadderParams) == 4);
static_assert(sizeof(CPlayer::SRequestUseLadderParams) == 8);
static_assert(sizeof(CPlayer::SSound) == 1);
static_assert(sizeof(CPlayer::SStagingParams) == 28);
static_assert(sizeof(CPlayer::SStealthKillRequestParams) == 8);
static_assert(sizeof(CPlayer::TwoEntityParams) == 8);
static_assert(sizeof(CPlayerGetSpawnInfo::SInfo) == 32);
static_assert(sizeof(SDeferredFootstepImpulse) == 16);
static_assert(sizeof(SNetPlayerProgression) == 16);
static_assert(sizeof(SNetPlayerProgression::SSerVals) == 8);
static_assert(sizeof(SPlayerRotationParams) == 504);
static_assert(sizeof(SPlayerStats) == 184);
static_assert(sizeof(SXPEvents) == 124);
static_assert(sizeof(SXPEvents::SEvent) == 8);

#include "PlayerMovementController.h"
static_assert(sizeof(CPlayerMovementController) == 4984);

#include "PlayerRotation.h"
static_assert(sizeof(CPlayerRotation) == 328);
static_assert(sizeof(CPlayerRotation::SLeanAndPeekInfo) == 16);

#include "PlayerStateAIMovement.h"
static_assert(sizeof(CPlayerStateAIMovement) == 1024);

#include "PlayerStateAnimationControlled.h"
static_assert(sizeof(CPlayerStateAnimationControlled) == 496);

#include "PlayerStateDead.h"
static_assert(sizeof(CPlayerStateDead) == 8);
static_assert(sizeof(CPlayerStateDead::UpdateCtx) == 4);

#include "PlayerStateEntry.h"
static_assert(sizeof(CPlayerStateEntry) == 336);

#include "PlayerStateFly.h"
static_assert(sizeof(CPlayerStateFly) == 20);
static_assert(sizeof(CPlayerStateSpectate) == 40);

#include "PlayerStateGround.h"
static_assert(sizeof(CPlayerStateGround) == 1);

#include "PlayerStateJump.h"
static_assert(sizeof(CPlayerStateJump) == 40);

#include "PlayerStateLedge.h"
static_assert(sizeof(CPlayerStateLedge) == 104);
static_assert(sizeof(CPlayerStateLedge::SLedgeBlending) == 40);
static_assert(sizeof(CPlayerStateLedge::SLedgeBlendingParams) == 40);
static_assert(sizeof(CPlayerStateLedge::SLedgeGrabbingParams) == 396);
static_assert(sizeof(CPlayerStateLedge::SLedgeNearbyParams) == 24);

#include "PlayerStateLinked.h"
static_assert(sizeof(CPlayerStateLinked) == 416);

#include "PlayerStateMovement.h"
static_assert(sizeof(CPlayerStateMovement) == 1384);

#include "PlayerStateSwim.h"
static_assert(sizeof(CPlayerStateSwim) == 32);
static_assert(sizeof(CPlayerStateSwim::CSwimmingParams) == 28);

#include "PlayerStateSwim_WaterTestProxy.h"
static_assert(sizeof(CPlayerStateSwim_WaterTestProxy) == 68);

#include "PlayerStateUtil.h"
static_assert(sizeof(CPlayerStateUtil) == 1);

#include "PlayerVisTable.h"
static_assert(sizeof(CPlayerVisTable) == 1776);
static_assert(sizeof(CPlayerVisTable::SIgnoreEntity) == 8);
static_assert(sizeof(CPlayerVisTable::SVisibilityParams) == 12);
static_assert(sizeof(SDeferredLinetestReceiver) == 8);

#include "PrefabManager.h"
static_assert(sizeof(CryGame::CPrefab) == 200);
static_assert(sizeof(CryGame::CPrefabManager) == 72);

#include "ProceduralClipAimSmoothing.h"
static_assert(sizeof(CProceduralClipAimSmoothing) == 80);
static_assert(sizeof(SAimSmoothingParams) == 24);

#include "ProceduralClipAiming.h"
static_assert(sizeof(CProceduralClipAiming) == 56);

#include "ProceduralClipColliderMode.h"
static_assert(sizeof(CProceduralClipColliderMode) == 72);
static_assert(sizeof(SColliderModeParams) == 16);

#include "ProceduralClipCompromiseCover.h"
static_assert(sizeof(CProceduralClipCompromiseCover) == 48);

#include "ProceduralClipCopyNormalizedTime.h"
static_assert(sizeof(CProceduralClipCopyNormalizedTime) == 72);
static_assert(sizeof(SProceduralParamsCopyNormalizedTime) == 24);

#include "ProceduralClipFacialSequence.h"
static_assert(sizeof(CProceduralClipFacialSequence) == 80);
static_assert(sizeof(SProceduralClipFacialSequenceParams) == 24);

#include "ProceduralClipLooking.h"
static_assert(sizeof(CProceduralClipLooking) == 56);

#include "ProceduralClipMovementControlMethod.h"
static_assert(sizeof(CProceduralClipMovementControlMethod) == 72);
static_assert(sizeof(SProceduralClipMovementControlMethodParams) == 16);

#include "ProceduralClipRagdoll.h"
static_assert(sizeof(CProceduralClipRagdoll) == 80);
static_assert(sizeof(SRagdollParams) == 16);

#include "ProceduralClipSetStance.h"
static_assert(sizeof(CProceduralClipSetStance) == 56);
static_assert(sizeof(SSetStanceParams) == 16);

#include "ProceduralContextColliderMode.h"
static_assert(sizeof(CProceduralContextColliderMode) == 56);
static_assert(sizeof(CProceduralContextColliderMode::SColliderModeRequest) == 8);

#include "ProceduralContextLook.h"
static_assert(sizeof(CProceduralContextLook) == 56);
static_assert(sizeof(CProceduralContextLookEyes) == 56);
static_assert(sizeof(CProceduralContextLookHead) == 56);

#include "ProceduralContextMovementControlMethod.h"
static_assert(sizeof(CProceduralContextMovementControlMethod) == 56);
static_assert(sizeof(CProceduralContextMovementControlMethod::SMCMRequest) == 12);

#include "ProceduralContextRagdoll.h"
static_assert(sizeof(CProceduralContextRagdoll) == 48);

#include "ProceduralWeaponAnimation.h"
static_assert(sizeof(CProceduralWeaponAnimation) == 808);

#include "RevertibleConfigLoader.h"
static_assert(sizeof(CRevertibleConfigLoader) == 88);
static_assert(sizeof(CRevertibleConfigLoader::SSavedCVar) == 16);

#include "RuntimePrefab.h"
static_assert(sizeof(CryGame::CRuntimePrefab) == 136);

#include "SGameWeaponSwayParams.h"
static_assert(sizeof(SGameWeaponSwayParams) == 48);

#include "ScreenEffects.h"
static_assert(sizeof(CScreenEffects) == 72);

#include "ScriptBind_Actor.h"
static_assert(sizeof(CScriptBind_Actor) == 112);

#include "ScriptBind_ArkItem.h"
static_assert(sizeof(CScriptBind_ArkItem) == 128);

#include "ScriptBind_Game.h"
static_assert(sizeof(CScriptBind_Game) == 112);

#include "ScriptBind_GameRules.h"
static_assert(sizeof(CScriptBind_GameRules) == 152);

#include "ScriptBind_HitDeathReactions.h"
static_assert(sizeof(CScriptBind_HitDeathReactions) == 120);

#include "ScriptBind_Item.h"
static_assert(sizeof(CScriptBind_Item) == 128);

#include "ScriptBind_LightningArc.h"
static_assert(sizeof(CScriptBind_LightningArc) == 104);

#include "ScriptBind_ProtectedBinds.h"
static_assert(sizeof(CScriptBind_ProtectedBinds) == 112);

#include "ScriptControlledPhysics.h"
static_assert(sizeof(CScriptControlledPhysics) == 256);

#include "TelemetryCollector.h"
static_assert(sizeof(CTelemetryCollector) == 137544);
static_assert(sizeof(CTelemetryCollector::SLargeFileSubmitData) == 68664);
static_assert(sizeof(CTelemetryCollector::SQueuedProducer) == 40);
static_assert(sizeof(CTelemetryCompressor) == 40);
static_assert(sizeof(CTelemetryFileReader) == 296);
static_assert(sizeof(CTelemetryHTTPPostChunkSplitter) == 24);
static_assert(sizeof(CTelemetryMD5) == 112);

#include "TransformationPinning.h"
static_assert(sizeof(CTransformationPinning) == 48);
static_assert(sizeof(CTransformationPinning::TransformationPinJoint) == 1);

#include "WeaponOffsetInput.h"
static_assert(sizeof(CWeaponOffsetInput) == 80);

#include "WeaponZoomOffset.h"
static_assert(sizeof(CWeaponZoomOffset) == 208);

#include "WorldBuilder.h"
static_assert(sizeof(CWorldBuilder) == 80);

#include "actordefinitions.h"
static_assert(sizeof(SActorParams) == 352);
static_assert(sizeof(SActorParams::SDynamicAimPose) == 24);
static_assert(sizeof(SStanceInfo) == 248);

#include "actorluacache.h"
static_assert(sizeof(SLuaCache_ActorGameParams) == 5000);
static_assert(sizeof(SLuaCache_ActorPhysicsParams) == 320);
static_assert(sizeof(SLuaCache_ActorProperties) == 80);

#include "blendnode.h"
static_assert(sizeof(CBlendGroup) == 40);
static_assert(sizeof(CBlendJobNode) == 24);

#include "bodydamage.h"
static_assert(sizeof(CBodyDamageProfile) == 160);
static_assert(sizeof(CBodyDamageProfile::CEffectiveMaterials) == 80);
static_assert(sizeof(CBodyDamageProfile::CPart) == 32);
static_assert(sizeof(CBodyDamageProfile::CPartByNameFunctor) == 8);
static_assert(sizeof(CBodyDamageProfile::CPartInfo) == 16);
static_assert(sizeof(CBodyDamageProfile::JointId) == 4);
static_assert(sizeof(CBodyDamageProfile::MatMappingId) == 16);
static_assert(sizeof(CBodyDamageProfile::SBodyPartDamageMultiplier) == 40);
static_assert(sizeof(CBodyDamageProfile::SDefaultMultipliers) == 8);
static_assert(sizeof(CBodyDamageProfile::SMaterialMappingEntry) == 100);
static_assert(sizeof(CBodyDamageProfile::SProjectileMultiplier) == 12);

#include "bodydefinitions.h"
static_assert(sizeof(CBodyDestrutibilityInstance) == 144);
static_assert(sizeof(CBodyDestrutibilityInstance::SBodyDestructiblePartStatus) == 16);

#include "bodydestruction.h"
static_assert(sizeof(CBodyDestructibilityProfile) == 280);
static_assert(sizeof(CBodyDestructibilityProfile::SBodyHitType) == 16);
static_assert(sizeof(CBodyDestructibilityProfile::SBodyPartExplosion) == 32);
static_assert(sizeof(CBodyDestructibilityProfile::SBodyPartQueryResult) == 16);
static_assert(sizeof(CBodyDestructibilityProfile::SDestructibleBodyPart) == 56);
static_assert(sizeof(CBodyDestructibilityProfile::SDestructionEvent) == 144);
static_assert(sizeof(CBodyDestructibilityProfile::SExplosionDeathEvent) == 32);
static_assert(sizeof(CBodyDestructibilityProfile::SHealthRatioEvent) == 24);
static_assert(sizeof(CBodyDestructibilityProfile::SMikeDeath) == 48);
static_assert(sizeof(CBodyDestructibilityProfile::SParsingHelper) == 48);
static_assert(sizeof(CBodyDestructibilityProfile::compareHealthRatios) == 1);

#include "bodymanager.h"
static_assert(sizeof(CBodyDamageManager) == 136);

#include "cornersmoother.h"
static_assert(sizeof(CornerSmoothing::CCornerSmoother2) == 24);
static_assert(sizeof(CornerSmoothing::CStopPlan) == 8);
static_assert(sizeof(CornerSmoothing::CTakeCornerPlan) == 832);

#include "dualcharacterproxy.h"
static_assert(sizeof(CAnimationProxyDualCharacter) == 32);
static_assert(sizeof(CAnimationProxyDualCharacterBase) == 24);
static_assert(sizeof(CAnimationProxyDualCharacterBase::SPlayParams) == 16);
static_assert(sizeof(CAnimationProxyDualCharacterUpper) == 32);

#include "flowweaponcustomizationnodes.h"
static_assert(sizeof(CFlashUIGetCompatibleAccessoriesNode) == 16);
static_assert(sizeof(CFlashUIGetEquippedAccessoriesNode) == 16);
static_assert(sizeof(CFlashUIInventoryNode) == 16);

#include "gameconstantcvars.h"
static_assert(sizeof(SGameReleaseConstantCVars) == 1);

#include "gameparameters.h"
static_assert(sizeof(CGameSharedParametersStorage) == 56);

#include "gamerulestypes.h"
static_assert(sizeof(SDrawResolutionData) == 88);

#include "gametypeinfo.h"
static_assert(sizeof(CBase) == 8);
static_assert(sizeof(CType2) == 8);
static_assert(sizeof(CryGameTypeInfoTest::BadDownCast) == 88);
static_assert(sizeof(CryGameTypeInfoTest::BaseTypeNotCastableToSubType_BugFix) == 88);
static_assert(sizeof(CryGameTypeInfoTest::ConstBadDownCast) == 88);
static_assert(sizeof(CryGameTypeInfoTest::ConstGoodDownCast) == 88);
static_assert(sizeof(CryGameTypeInfoTest::ConstUpCast) == 88);
static_assert(sizeof(CryGameTypeInfoTest::FalseDownCastIsOf) == 88);
static_assert(sizeof(CryGameTypeInfoTest::GetName) == 88);
static_assert(sizeof(CryGameTypeInfoTest::GoodDownCast) == 88);
static_assert(sizeof(CryGameTypeInfoTest::SameCast) == 88);
static_assert(sizeof(CryGameTypeInfoTest::TrueDownCastIsOf) == 88);
static_assert(sizeof(CryGameTypeInfoTest::TrueUpCastIsOf) == 88);
static_assert(sizeof(CryGameTypeInfoTest::UpCast) == 88);

#include "hitdeathreactionsdefs.h"
static_assert(sizeof(SReactionParams) == 216);
static_assert(sizeof(SReactionParams::SAnimGraphReaction) == 32);
static_assert(sizeof(SReactionParams::SAnimGraphReaction::SVariationData) == 16);
static_assert(sizeof(SReactionParams::SMannequinData) == 72);
static_assert(sizeof(SReactionParams::SReactionAnim) == 56);
static_assert(sizeof(SReactionParams::SValidationParams) == 280);

#include "itemanimation.h"
static_assert(sizeof(CItemAction) == 128);
static_assert(sizeof(CItemSelectAction) == 136);
static_assert(sizeof(SMannequinItemParams) == 528);
static_assert(sizeof(SMannequinItemParams::ContextIDs) == 12);
static_assert(sizeof(SMannequinItemParams::FragmentIDs) == 444);
static_assert(sizeof(SMannequinItemParams::Fragments) == 32);
static_assert(sizeof(SMannequinItemParams::Fragments::SSelect) == 32);
static_assert(sizeof(SMannequinItemParams::Fragments::SSelect::FragmentTagIDs) == 20);
static_assert(sizeof(SMannequinItemParams::TagGroupIDs) == 16);
static_assert(sizeof(SMannequinItemParams::TagIDs) == 12);

#include "itemdefinitions.h"
static_assert(sizeof(SItemActionParamCRCs) == 68);
static_assert(sizeof(SItemFragmentTagCRCs) == 48);

#include "itemresourcecache.h"
static_assert(sizeof(CItemAnimationDBAManager) == 48);
static_assert(sizeof(CItemAnimationDBAManager::SItemDBAInfo) == 32);
static_assert(sizeof(CItemGeometryCache) == 32);
static_assert(sizeof(CItemMaterialAndTextureCache) == 32);
static_assert(sizeof(CItemParticleEffectCache) == 16);
static_assert(sizeof(CItemPrefetchCHRManager) == 32);
static_assert(sizeof(CItemPrefetchCHRManager::PrefetchSlot) == 16);

#include "itemstring.h"
static_assert(sizeof(SharedString::CSharedString) == 8);

#include "movementaction.h"
static_assert(sizeof(CPlayerJump) == 128);
static_assert(sizeof(CProceduralClipSwapHand) == 48);

#include "playerai.h"
static_assert(sizeof(CAIAnimationComponent) == 136);
static_assert(sizeof(CAIAnimationState) == 32);
static_assert(sizeof(SMannequinAIStateParams) == 208);
static_assert(sizeof(SMannequinAIStateParams::TagGroupIDs) == 40);
static_assert(sizeof(SMannequinAIStateParams::TagIDs) == 156);

#include "playeranimation.h"
static_assert(sizeof(SMannequinPlayerParams) == 432);
static_assert(sizeof(SMannequinPlayerParams::ContextIDs) == 28);
static_assert(sizeof(SMannequinPlayerParams::FragmentIDs) == 120);
static_assert(sizeof(SMannequinPlayerParams::Fragments) == 96);
static_assert(sizeof(SMannequinPlayerParams::Fragments::SLedge_Grab) == 56);
static_assert(sizeof(SMannequinPlayerParams::Fragments::SLedge_Grab::FragmentTagIDs) == 44);
static_assert(sizeof(SMannequinPlayerParams::Fragments::Smelee) == 16);
static_assert(sizeof(SMannequinPlayerParams::Fragments::Smelee::FragmentTagIDs) == 4);
static_assert(sizeof(SMannequinPlayerParams::Fragments::Smelee_multipart) == 24);
static_assert(sizeof(SMannequinPlayerParams::Fragments::Smelee_multipart::FragmentTagIDs) == 12);
static_assert(sizeof(SMannequinPlayerParams::ScopeIDs) == 40);
static_assert(sizeof(SMannequinPlayerParams::TagGroupIDs) == 52);
static_assert(sizeof(SMannequinPlayerParams::TagIDs) == 88);

#include "playerstateevents.h"
static_assert(sizeof(SStateEventJump) == 104);

#include "proceduralweaponclip.h"
static_assert(sizeof(CWeaponBumpOffset) == 72);
static_assert(sizeof(CWeaponPoseOffset) == 96);
static_assert(sizeof(CWeaponRecoilOffset) == 80);
static_assert(sizeof(CWeaponSwayOffset) == 280);
static_assert(sizeof(CWeaponWiggleOffset) == 80);
static_assert(sizeof(SWeaponProceduralClipParams<SStaticBumpParams>) == 24);
static_assert(sizeof(SWeaponProceduralClipParams<SStaticWeaponPoseParams>) == 40);
static_assert(sizeof(SWeaponProceduralClipParams<SStaticWeaponRecoilParams>) == 32);
static_assert(sizeof(SWeaponProceduralClipParams<SStaticWeaponSwayParams>) == 120);
static_assert(sizeof(SWeaponProceduralClipParams<SStaticWiggleParams>) == 16);

#include "proceduralweaponcontext.h"
static_assert(sizeof(CProceduralWeaponAnimationContext) == 888);
static_assert(sizeof(CProceduralWeaponAnimationContext::SParams) == 12);

#include "state.h"
static_assert(sizeof(CStateHelper<CPlayer,CStateHierarchy<CPlayer> >) == 1);
static_assert(sizeof(CStateHierarchy<CPlayer>) == 288);
static_assert(sizeof(CStateMachine<CPlayer>) == 56);
static_assert(sizeof(SStateEvent) == 104);
static_assert(sizeof(SStateIndex<CPlayer>) == 40);

#include "weaponbumpoffset.h"
static_assert(sizeof(CBumpOffset) == 44);

#include "weaponlookoffset.h"
static_assert(sizeof(CLookOffset) == 168);
static_assert(sizeof(SStaticWeaponSwayParams) == 108);

#include "weaponoffset.h"
static_assert(sizeof(CWeaponOffsetStack) == 88);
static_assert(sizeof(CWeaponOffsetStack::SWeaponOffsetLayer) == 32);
static_assert(sizeof(CWeaponOffsetState) == 56);
static_assert(sizeof(SWeaponOffset) == 24);

#include "weaponrecoiloffset.h"
static_assert(sizeof(CRecoilOffset) == 80);
static_assert(sizeof(SStaticWeaponRecoilParams) == 24);

#include "weaponstrafeoffset.h"
static_assert(sizeof(CStrafeOffset) == 200);
#endif // !MOONCRASH
