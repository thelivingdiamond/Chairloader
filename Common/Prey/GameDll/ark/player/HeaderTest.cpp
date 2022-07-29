// Header test file for path Prey/GameDll/ark/player/ArkAimAssistComponent.h
#include "ArkAimAssistComponent.h"
static_assert(sizeof(ArkAimAssistComponent) == 232);
static_assert(sizeof(ArkAimAssistComponent::ArkAimAssistTarget) == 64);
static_assert(sizeof(ArkAimEntityDebug) == 56);

#include "ArkAimAssistConfig.h"
static_assert(sizeof(ArkAimAssistConfig) == 48);
static_assert(sizeof(ArkAimAssistConfig::ArkMagnetismProperty) == 32);
static_assert(sizeof(ArkAimAssistConfig::ArkSprintMagnetismProperty) == 32);
static_assert(sizeof(ArkAimAssistConfig::ArkCenteringProperty) == 32);
static_assert(sizeof(ArkAimAssistConfig::ArkSprintCenteringProperty) == 32);
static_assert(sizeof(ArkAimAssistConfig::ArkAimAssistDeadZoneProperty) == 32);
static_assert(sizeof(ArkAimAssistConfig::ArkEntitiesProperty) == 32);
static_assert(sizeof(ArkAimAssistShape) == 32);
static_assert(sizeof(ArkAimAssistShape::ArkPointsProperty) == 32);
static_assert(sizeof(ArkAimAssistShape::ArkInnerRadiusProperty) == 32);
static_assert(sizeof(ArkAimAssistShape::ArkOuterRadiusProperty) == 32);
static_assert(sizeof(ArkAimAssistEntity) == 40);
static_assert(sizeof(ArkAimAssistEntity::ArkNameProperty) == 32);
static_assert(sizeof(ArkAimAssistEntity::ArkShapeProperty) == 32);

#include "ArkAudioSwitch.h"
static_assert(sizeof(ArkAudioSwitch) == 4);

#include "ArkAudioSwitchState.h"
static_assert(sizeof(ArkAudioSwitchState) == 4);

#include "ArkExaminationMode.h"
static_assert(sizeof(ArkExaminationMode) == 280);

#include "ArkFocusModeComponent.h"
static_assert(sizeof(ArkFocusModeComponent) == 928);

#include "ArkFocusModeComponentProperties.h"
static_assert(sizeof(ArkFocusModeComponentProperties) == 192);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkMouseSensitivityProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkMouseRotationSpeedProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkMouseRotationDampingProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkControllerAbsoluteDeadzoneProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkControllerDeltaDeadzoneProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkControllerInactiveStickDeadzoneProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkDefaultPostProcessEffectProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkPsiPostProcessEffectProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkFocusParticleEffectPathProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkExitFromFocusParticleEffectPathProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkPsiParticleEffectPathProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkExitFromPsiParticleEffectPathProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkFocusToPsiParticleEffectPathProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkPsiToFocusParticleEffectPathProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkSelectPowerLegendProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkSelectWeaponLegendProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkNoPowersAudioTriggerProperty) == 32);
static_assert(sizeof(ArkFocusModeComponentProperties::ArkNoPowersStringsProperty) == 32);

#include "ArkFocusModeEffectsManager.h"
static_assert(sizeof(ArkFocusModeEffectsManager) == 672);

#include "ArkLevelMapComponent.h"
static_assert(sizeof(ArkLevelMapComponent) == 64);

#include "ArkMarkedEnemyComponent.h"
static_assert(sizeof(ArkMarkedEnemyComponent) == 96);
static_assert(sizeof(ArkMarkedEnemyComponent::ValidTarget) == 8);
static_assert(sizeof(ArkMarkedEnemyComponent::MarkedEnemy) == 12);
static_assert(sizeof(ArkMarkedEnemyComponent::PotentialTarget) == 16);

#include "ArkObjectiveComponent.h"
static_assert(sizeof(ArkObjectiveComponent) == 352);
static_assert(sizeof(ArkObjective) == 136);
static_assert(sizeof(ArkPathMapNode) == 16);

#include "ArkPharmaComponent.h"
static_assert(sizeof(ArkPharmaComponent) == 40);
static_assert(sizeof(ArkPharmaComponent::ActivePharma) == 56);

#include "ArkPlayer.h"
static_assert(sizeof(ArkPlayer) == 6968);

#include "ArkPlayerAchievementComponent.h"
static_assert(sizeof(ArkPlayerAchievementComponent) == 128);
static_assert(sizeof(ArkPlayerAchievementComponent::TimerWindowCount) == 16);

#include "ArkPlayerAction.h"
static_assert(sizeof(ArkPlayerAction) == 128);

#include "ArkPlayerAudio.h"
static_assert(sizeof(ArkPlayerAudio) == 80);

#include "ArkPlayerAwarenessComponent.h"
static_assert(sizeof(ArkPlayerAwarenessComponent) == 64);
static_assert(sizeof(ArkPlayerAwarenessComponent::AwarenessState) == 24);

#include "ArkPlayerCamera.h"
static_assert(sizeof(ArkPlayerCamera) == 456);

#include "ArkPlayerCarry.h"
static_assert(sizeof(ArkPlayerCarry) == 256);

#include "ArkPlayerComponent.h"
static_assert(sizeof(ArkPlayerComponent) == 328);
static_assert(sizeof(ClimbPosInfo) == 16);

#include "ArkPlayerEntitlementComponent.h"
static_assert(sizeof(ArkPlayerEntitlementComponent) == 128);
static_assert(sizeof(ArkPlayerEntitlementComponent::OverflowItem) == 24);

#include "ArkPlayerFatigueComponent.h"
static_assert(sizeof(ArkPlayerFatigueComponent) == 56);

#include "ArkPlayerFlashlight.h"
static_assert(sizeof(ArkPlayerFlashlight) == 144);
static_assert(sizeof(ArkPlayerFlashlight::DimRange) == 8);
//static_assert(sizeof(ArkFlowNodeFlashlight) == 16);

#include "ArkPlayerFXComponent.h"
static_assert(sizeof(ArkPlayerFXComponent) == 160);
static_assert(sizeof(ArkPlayerFXComponent::FXTimerData) == 16);
static_assert(sizeof(ArkPlayerFXComponent::ArkPlayerEffect) == 136);
static_assert(sizeof(ArkSignalFXSignalEntry) == 16);
static_assert(sizeof(ArkSignalFXSignalEntry::ArkSignalProperty) == 32);
static_assert(sizeof(ArkSignalFXSignalEntry::ArkValueThresholdProperty) == 32);
static_assert(sizeof(ArkSignalFX) == 104);
static_assert(sizeof(ArkSignalFX::ArkIDProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkNameProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkSignalsProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkPostEffectProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkPostEffectLoopDurationProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkParticleEffectProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkParticleLoopDurationProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkAudioTriggerStartProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkAudioTriggerStopProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkLoopDurationProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkCooldownProperty) == 32);
static_assert(sizeof(ArkSignalFX::ArkForceFeedbackProperty) == 32);
static_assert(sizeof(ArkSignalFXLibrary) == 32);
static_assert(sizeof(ArkSignalFXLibrary::ArkFXProperty) == 32);

#include "arkplayergroundstate.h"
static_assert(sizeof(ArkPlayerMovementStates::Ground) == 488);
static_assert(sizeof(ArkPlayerMovementStates::Ground::ArkGroundColliderParameters) == 12);

#include "arkplayerhealthcomponent.h"
static_assert(sizeof(ArkPlayerHealthFeedback) == 72);

#include "ArkPlayerHelmet.h"
static_assert(sizeof(ArkPlayerHelmet) == 80);

#include "ArkPlayerInput.h"
static_assert(sizeof(ArkPlayerInput) == 208);
static_assert(sizeof(ArkPlayerInput::ModeAndHandle) == 8);
static_assert(sizeof(ArkPlayerInput::MovementButtonPressInfo) == 4);

#include "ArkPlayerInteraction.h"
static_assert(sizeof(ArkPlayerInteraction) == 1768);

#include "ArkPlayerLight.h"
static_assert(sizeof(ArkPlayerLight) == 24);
static_assert(sizeof(ArkPlayerLightVFX) == 136);
static_assert(sizeof(ArkPlayerLightEntity) == 56);

#include "ArkPlayerLightManager.h"
static_assert(sizeof(ArkPlayerLightManager) == 40);

#include "ArkPlayerMovementAction.h"
static_assert(sizeof(ArkPlayerMovementAction) == 144);

#include "ArkPlayerMovementController.h"
static_assert(sizeof(ArkPlayerMovementController) == 8);

#include "ArkPlayerMovementStates.h"
static_assert(sizeof(ArkPlayerMovementStates::Base) == 1);
static_assert(sizeof(ArkPlayerMovementStates::Death) == 48);
static_assert(sizeof(ArkPlayerMovementStates::DeathByRecyclerGrenade) == 96);
static_assert(sizeof(ArkPlayerMovementStates::Jump) == 44);
static_assert(sizeof(ArkPlayerMovementStates::Fall) == 40);
static_assert(sizeof(ArkPlayerMovementStates::Climb) == 40);
static_assert(sizeof(ArkPlayerMovementStates::Fly) == 1);
static_assert(sizeof(ArkPlayerMovementStates::Smoke) == 12);
static_assert(sizeof(ArkPlayerMovementStates::ZeroG) == 392);
static_assert(sizeof(ArkPlayerMovementStates::ZeroG::ZeroGParams) == 56);
static_assert(sizeof(ArkPlayerMovementStates::ZeroG::RollParams) == 16);
static_assert(sizeof(ArkPlayerMovementStates::ZeroG::AlignParams) == 8);
static_assert(sizeof(ArkPlayerMovementStates::Cinematic) == 12);
static_assert(sizeof(ArkPlayerMovementStates::Slide) == 8);
static_assert(sizeof(ArkPlayerMovementStates::Mimic) == 1);
static_assert(sizeof(ArkPlayerMovementStates::GravShaft) == 16);
static_assert(sizeof(ArkPlayerMovementStates::GravShaftG) == 16);
static_assert(sizeof(ArkPlayerMovementStates::GravShaftToG) == 32);
static_assert(sizeof(ArkPlayerMovementStates::GravShaftZeroG) == 16);
static_assert(sizeof(ArkPlayerMovementStates::Lift) == 144);
static_assert(sizeof(ArkPlayerMovementStates::Shift) == 56);
static_assert(sizeof(PlayerCrawlRagdollAction) == 128);

#include "ArkPlayerOxygenComponent.h"
static_assert(sizeof(ArkPlayerOxygenComponent) == 88);
static_assert(sizeof(ArkPlayerOxygenComponent::OxygenAlarm) == 12);

#include "ArkPlayerPropulsionComponent.h"
static_assert(sizeof(ArkPlayerPropulsionComponent) == 88);

#include "ArkPlayerRadiationComponent.h"
static_assert(sizeof(ArkPlayerRadiationComponent) == 80);
static_assert(sizeof(ArkPlayerRadiationComponent::RadiationData) == 8);

#include "ArkPlayerScopeComponent.h"
static_assert(sizeof(ArkPlayerScopeComponent) == 128);
static_assert(sizeof(ArkPlayerScopeComponent::ArkPostProcessIdProperty) == 32);
static_assert(sizeof(ArkPlayerScopeComponent::ArkZoomDeltaProperty) == 32);
static_assert(sizeof(ArkPlayerScopeComponent::ArkFullyZoomedHFOVProperty) == 32);
static_assert(sizeof(ArkPlayerScopeComponent::ArkDefaultZoomHFOVProperty) == 32);
static_assert(sizeof(ArkPlayerScopeComponent::ArkDefaultZoomDurationProperty) == 32);
static_assert(sizeof(ArkPlayerScopeComponent::ArkZoomingInAudioTriggerNameProperty) == 32);
static_assert(sizeof(ArkPlayerScopeComponent::ArkZoomingOutAudioTriggerNameProperty) == 32);
static_assert(sizeof(ArkPlayerScopeComponent::ArkOpenAudioTriggerNameProperty) == 32);
static_assert(sizeof(ArkPlayerScopeComponent::ArkCloseAudioTriggerNameProperty) == 32);
static_assert(sizeof(ArkPlayerScopeComponent::ArkArkInputLegendProperty) == 32);

#include "ArkPlayerSignalReceiver.h"
static_assert(sizeof(ArkPlayerSignalReceiver) == 488);
static_assert(sizeof(ArkPlayerSignalReceiver::SignalAction) == 16);

#include "arkplayerstatehover.h"
static_assert(sizeof(CArkPlayerStateHover) == 160);

#include "ArkPlayerStatusComponent.h"
static_assert(sizeof(ArkPlayerStatusComponent) == 96);
static_assert(sizeof(ArkPlayerStatusComponent::TArmMaterial) == 16);

#include "ArkPlayerStatusUIInfo.h"
static_assert(sizeof(ArkPlayerStatusUIInfo) == 48);

#include "ArkPlayerTargetSelector.h"
static_assert(sizeof(ArkPlayerTargetSelector) == 72);
static_assert(sizeof(ArkPlayerTargetSelector::ArkPlayerTarget) == 112);
static_assert(sizeof(ArkPlayerTargetSelector::IntersectResult) == 8);

#include "ArkPlayerUIComponent.h"
static_assert(sizeof(ArkPlayerUIComponent) == 136);
static_assert(sizeof(ArkPlayerUIComponent::MarkerEntry) == 20);
static_assert(sizeof(ArkPlayerUIComponent::DamageIndicator) == 12);

#include "ArkPlayerUpperBodyAction.h"
static_assert(sizeof(ArkPlayerUpperBodyAction) == 152);

#include "ArkPlayerWeaponComponent.h"
static_assert(sizeof(ArkPlayerWeaponComponent) == 224);
static_assert(sizeof(ArkPlayerWeaponComponent::GameLogData) == 8);

#include "ArkPlayerZoomManager.h"
static_assert(sizeof(ArkPlayerZoomManager) == 48);
static_assert(sizeof(ArkPlayerZoomManager::ZoomData) == 12);

#include "ArkPOIComponent.h"
static_assert(sizeof(ArkPOIComponent) == 96);
static_assert(sizeof(ArkPOIComponent::SEntityPOI) == 24);

#include "arkpsicomponent.h"
static_assert(sizeof(CArkPsiComponent) == 1040);

#include "ArkPsiScanningComponent.h"
static_assert(sizeof(ArkPsiScanningComponent) == 368);
static_assert(sizeof(ArkScanning) == 168);
static_assert(sizeof(ArkScanning::ArkEventBonusSecProperty) == 32);
static_assert(sizeof(ArkScanning::ArkLockonTimeSecProperty) == 32);
static_assert(sizeof(ArkScanning::ArkLockonTimeoutSecProperty) == 32);
static_assert(sizeof(ArkScanning::ArkLockonTimeoutFlashingStartProperty) == 32);
static_assert(sizeof(ArkScanning::ArkLockonTimeoutFlashingFreqProperty) == 32);
static_assert(sizeof(ArkScanning::ArkMaxDistanceScanRateMultiplierProperty) == 32);
static_assert(sizeof(ArkScanning::ArkAutoUnequipTimeoutSecProperty) == 32);
static_assert(sizeof(ArkScanning::ArkScanCompleteLockonTimeoutSecProperty) == 32);
static_assert(sizeof(ArkScanning::ArkLockonAttachmentProperty) == 32);
static_assert(sizeof(ArkScanning::ArkPostProcessEffectProperty) == 32);
static_assert(sizeof(ArkScanning::ArkEnableAutoUnequipProperty) == 32);
static_assert(sizeof(ArkScanning::ArkScanFirstTargetOnEquipProperty) == 32);
static_assert(sizeof(ArkScanning::ArkFanfareZoomDurationProperty) == 32);
static_assert(sizeof(ArkScanning::ArkFanfareZoomOutDurationProperty) == 32);
static_assert(sizeof(ArkScanning::ArkFanfareZoomHFOVProperty) == 32);
static_assert(sizeof(ArkScanning::ArkFanfareCameraSpeedProperty) == 32);
static_assert(sizeof(ArkScanning::ArkErrorMessageDurationProperty) == 32);
static_assert(sizeof(ArkScanning::ArkPsychoscopeHideTimeProperty) == 32);
static_assert(sizeof(ArkScanning::ArkReminderUIDelayProperty) == 32);
static_assert(sizeof(ArkScanning::ArkReticleLerpSpeedProperty) == 32);
static_assert(sizeof(ArkScanning::ArkLightArchetypeProperty) == 32);
static_assert(sizeof(ArkScanning::ArkLightAttachmentProperty) == 32);
static_assert(sizeof(ArkScanning::ArkResearchRtpcProperty) == 32);
static_assert(sizeof(ArkScanning::ArkPauseResearchAudioTriggerProperty) == 32);
static_assert(sizeof(ArkScanning::ArkResumeResearchAudioTriggerProperty) == 32);
static_assert(sizeof(ArkScanning::ArkFanfareInputLegendProperty) == 32);

#include "ArkQuickSelectComponent.h"
static_assert(sizeof(ArkQuickSelectComponent) == 408);
static_assert(sizeof(ArkQuickSelectComponent::QuickSelectId) == 24);

#include "ArkStationAccessComponent.h"
static_assert(sizeof(ArkStationAccessComponent) == 72);

#include "ArkUtilityComponent.h"
static_assert(sizeof(ArkUtilityComponent) == 256);

#include "IArkCharacterStatusListener.h"
static_assert(sizeof(IArkCharacterStatusListener) == 8);

#include "IArkEntitlementListener.h"
static_assert(sizeof(IArkEntitlementListener) == 8);

#include "IArkEtherDuplicateListener.h"
static_assert(sizeof(IArkEtherDuplicateListener) == 8);

#include "IArkHUDListener.h"
static_assert(sizeof(IArkHUDListener) == 8);

#include "IArkMetaTagListener.h"
static_assert(sizeof(IArkMetaTagListener) == 8);

#include "IArkPDAListener.h"
static_assert(sizeof(IArkPDAListener) == 8);

#include "IArkPlayer.h"
static_assert(sizeof(IArkPlayer) == 8);

#include "IArkPlayerCarryListener.h"
static_assert(sizeof(IArkPlayerCarryListener) == 8);

#include "IArkPlayerCombatListener.h"
static_assert(sizeof(IArkPlayerCombatListener) == 8);

#include "IArkPlayerHealthListener.h"
static_assert(sizeof(IArkPlayerHealthListener) == 8);

#include "IArkPlayerInteractionListener.h"
static_assert(sizeof(IArkPlayerInteractionListener) == 8);

#include "IArkPlayerLightOwner.h"
static_assert(sizeof(IArkPlayerLightOwner) == 8);

#include "IArkPlayerPsiListener.h"
static_assert(sizeof(IArkPlayerPsiListener) == 8);

#include "IArkPlayerStatusListener.h"
static_assert(sizeof(IArkPlayerStatusListener) == 8);

#include "IArkPsiPowerListener.h"
static_assert(sizeof(IArkPsiPowerListener) == 8);

#include "IArkPsiScanningComponentListener.h"
static_assert(sizeof(IArkPsiScanningComponentListener) == 8);

#include "IArkStatsListener.h"
static_assert(sizeof(IArkStatsListener) == 8);

//#include "scriptbind_arkplayer.h"
//static_assert(sizeof(CScriptBind_ArkPlayer) == 96);

#include "StanceInfo.h"
static_assert(sizeof(StanceInfo) == 24);
