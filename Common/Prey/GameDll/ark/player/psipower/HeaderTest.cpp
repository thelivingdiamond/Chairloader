// Header test file for path Prey/GameDll/ark/player/psipower/
#include "ArkEtherDuplicate.h"
static_assert(sizeof(ArkEtherDuplicate) == 48);

#include "ArkEtherDuplicateAction.h"
static_assert(sizeof(ArkEtherDuplicateAction) == 168);
static_assert(sizeof(ArkEtherDuplicateMaterialAnimation) == 24);

#include "ArkPlayerLiftEntity.h"
static_assert(sizeof(ArkPlayerLiftEntity) == 16);
static_assert(sizeof(ArkPlayerLiftEntitySpawner) == 8);

#include "ArkPlayerLiftEntityZeroG.h"
static_assert(sizeof(ArkPlayerLiftEntityZeroG) == 12);
static_assert(sizeof(ArkPlayerLiftEntityZeroGSpawner) == 4);

#include "ArkPlayerMimicAction.h"
static_assert(sizeof(ArkPlayerMimicAction) == 168);

#include "ArkPlayerMimicEngineeringOperatorCamera.h"
static_assert(sizeof(ArkPlayerMimicEngineeringOperatorCamera) == 128);

#include "ArkPlayerMimicEngineeringOperatorController.h"
static_assert(sizeof(ArkPlayerMimicEngineeringOperatorController) == 184);

#include "ArkPlayerMimicEngineeringOperatorRotationController.h"
static_assert(sizeof(ArkPlayerMimicEngineeringOperatorRotationController) == 48);

#include "ArkPlayerMimicMedicalOperatorController.h"
//static_assert(sizeof(ArkPlayerMimicMedicalOperatorController) == 456);

#include "ArkPlayerMimicMilitaryOperatorCamera.h"
//static_assert(sizeof(ArkPlayerMimicMilitaryOperatorCamera) == 104);

#include "ArkPlayerMimicMilitaryOperatorController.h"
static_assert(sizeof(ArkPlayerMimicMilitaryOperatorController) == 1016);

#include "ArkPlayerMimicMilitaryOperatorRotationController.h"
static_assert(sizeof(ArkPlayerMimicMilitaryOperatorRotationController) == 296);

#include "ArkPlayerMimicOperatorCamera.h"
static_assert(sizeof(ArkPlayerMimicOperatorCamera) == 4);

#include "ArkPlayerMimicOperatorEntity.h"
static_assert(sizeof(ArkPlayerMimicOperatorEntity) == 4);

#include "ArkPlayerMimicRigidCamera.h"
static_assert(sizeof(ArkMimicCameraCylinder) == 20);
static_assert(sizeof(ArkMimicCameraPathFinder) == 24);
static_assert(sizeof(ArkMimicCameraPathFinder::PathNode) == 12);
static_assert(sizeof(ArkPlayerMimicRigidCamera) == 408);

#include "ArkPlayerMimicRigidController.h"
static_assert(sizeof(ArkPlayerMimicRigidController) == 56);

#include "ArkPlayerMimicRigidEntity.h"
static_assert(sizeof(ArkPlayerMimicRigidEntity) == 152);
static_assert(sizeof(ArkPlayerMimicRigidEntity::SignalGroup) == 40);

#include "ArkPlayerMimicScienceOperatorCamera.h"
static_assert(sizeof(ArkPlayerMimicScienceOperatorCamera) == 144);

#include "ArkPlayerMimicScienceOperatorController.h"
static_assert(sizeof(ArkPlayerMimicScienceOperatorController) == 456);

#include "ArkPlayerMimicScienceOperatorRotationController.h"
static_assert(sizeof(ArkPlayerMimicScienceOperatorRotationController) == 264);

#include "ArkPlayerMimicSpawner.h"
static_assert(sizeof(ArkPlayerMimicSpawner) == 1);

#include "ArkPlayerMimicTurretCamera.h"
static_assert(sizeof(ArkPlayerMimicTurretCamera) == 72);

#include "ArkPlayerMimicTurretController.h"
static_assert(sizeof(ArkPlayerMimicTurretController) == 48);

#include "ArkPlayerMimicTurretEntity.h"
static_assert(sizeof(ArkPlayerMimicTurretEntity) == 4);

#include "ArkPlayerSmokeFormAction.h"
static_assert(sizeof(ArkPlayerSmokeFormAction) == 128);

#include "ArkPsiCorpsePhantom.h"
static_assert(sizeof(ArkPsiCorpsePhantom) == 72);

#include "ArkPsiLift.h"
static_assert(sizeof(ArkPsiLift) == 56);

#include "ArkPsiLiftVolume.h"
//static_assert(sizeof(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>) == 112);
static_assert(sizeof(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>) == 112);
static_assert(sizeof(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>) == 112);
static_assert(sizeof(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>) == 20);
static_assert(sizeof(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>) == 16);

#include "ArkPsiPower3DTargetingComponent.h"
static_assert(sizeof(CArkPsiPower3DTargetingComponent) == 464);

#include "ArkPsiPowerAlienTargetingComponent.h"
static_assert(sizeof(CArkPsiPowerAlienTargetingComponent) == 464);

#include "ArkPsiPowerCombatFocus.h"
static_assert(sizeof(ArkPsiPowerCombatFocusProperties) == 72);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkActiveAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkDurationProperty) == 32);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkInactiveAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkOutboundSignalModifierProperty) == 32);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkPlayerTimeScaleProperty) == 32);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkStatPackageProperty) == 32);
static_assert(sizeof(ArkPsiPowerCombatFocusProperties::ArkTimeScaleProperty) == 32);
static_assert(sizeof(CArkPsiPowerCombatFocus) == 112);
static_assert(sizeof(CombatFocusPowerProperties) == 248);
static_assert(sizeof(CombatFocusPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(CombatFocusPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(CombatFocusPowerProperties::ArkUniqueProperty) == 32);

#include "ArkPsiPowerComponent.h"
static_assert(sizeof(ArkPsiPowerComponent) == 648);
static_assert(sizeof(ArkPsiTargetingData) == 72);

#include "ArkPsiPowerCreatePhantom.h"
static_assert(sizeof(ArkPsiPowerCreatePhantom) == 800);
static_assert(sizeof(ArkPsiPowerCreatePhantomCommonProperties) == 40);
static_assert(sizeof(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseDampingProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseGravityProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectAttachmentProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseDurationProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseHeightProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseSpeedProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomProperties) == 128);
static_assert(sizeof(ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerCreatePhantomProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(CreatePhantomPowerProperties) == 280);
static_assert(sizeof(CreatePhantomPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(CreatePhantomPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(CreatePhantomPowerProperties::ArkUniqueProperty) == 32);

#include "ArkPsiPowerEmpty.h"
static_assert(sizeof(ArkPsiPowerEmpty) == 8);

#include "ArkPsiPowerIndividualTargetingComponent.h"
static_assert(sizeof(ArkPsiPowerIndividualTargetingComponent) == 616);

#include "ArkPsiPowerKineticShield.h"
static_assert(sizeof(ArkPsiPowerKineticShieldProperties) == 168);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkChargeCountProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkDisableAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkDisableParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkEnableAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkEnableParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkFirstTimeoutWarningAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkHitImpactAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkReflectDamageAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkReflectDamageParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkReflectedDamageSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkReflectedSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkSecondTimeoutWarningAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkTimeoutParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticShieldProperties::ArkWarningDurationSecProperty) == 32);
static_assert(sizeof(CArkPsiPowerKineticShield) == 712);
static_assert(sizeof(KineticShieldPowerProperties) == 248);
static_assert(sizeof(KineticShieldPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(KineticShieldPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(KineticShieldPowerProperties::ArkUniqueProperty) == 32);

#include "ArkPsiPowerLift.h"
static_assert(sizeof(CArkPsiPowerLift) == 368);

#include "ArkPsiPowerMimic.h"
static_assert(sizeof(CArkPsiPowerMimic) == 808);

#include "ArkPsiPowerMimicTargetingComponent.h"
static_assert(sizeof(ArkPsiPowerMimicTargetingComponent) == 616);

#include "ArkPsiPowerMimicUI.h"
static_assert(sizeof(CArkPsiPowerMimicUI) == 32);

#include "ArkPsiPowerMindBlast.h"
static_assert(sizeof(ArkPsiPowerMindBlastProperties) == 120);
static_assert(sizeof(ArkPsiPowerMindBlastProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerMindBlastProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerMindBlastProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerMindBlastProperties::ArkExecuteOnTargetParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerMindBlastProperties::ArkSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerMindBlastProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiPowerMindBlast) == 680);
static_assert(sizeof(MindBlastPowerProperties) == 248);
static_assert(sizeof(MindBlastPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(MindBlastPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(MindBlastPowerProperties::ArkUniqueProperty) == 32);

#include "ArkPsiPowerRemoteManipulation.h"
static_assert(sizeof(ArkPsiPowerRemoteManipulationCostOverride) == 16);
static_assert(sizeof(ArkPsiPowerRemoteManipulationCostOverride::ArkOverrideClassProperty) == 32);
static_assert(sizeof(ArkPsiPowerRemoteManipulationCostOverride::ArkPsiCostProperty) == 32);
static_assert(sizeof(ArkPsiPowerRemoteManipulationLevelProperties) == 112);
static_assert(sizeof(ArkPsiPowerRemoteManipulationLevelProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerRemoteManipulationLevelProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerRemoteManipulationLevelProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerRemoteManipulationLevelProperties::ArkNpcSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerRemoteManipulationLevelProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerRemoteManipulationUniqueProperties) == 40);
static_assert(sizeof(ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty) == 32);
static_assert(sizeof(ArkPsiPowerRemoteManipulationUniqueProperties::ArkUsePowerAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerRemoteManipulationUniqueProperties::ArkWorldUIPostProcessVFXProperty) == 32);
static_assert(sizeof(CArkPsiPowerRemoteManipulation) == 752);
static_assert(sizeof(RemoteManipulationPowerProperties) == 280);
static_assert(sizeof(RemoteManipulationPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(RemoteManipulationPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(RemoteManipulationPowerProperties::ArkUniqueProperty) == 32);

#include "ArkPsiPowerShift.h"
static_assert(sizeof(ArkPsiPowerShift) == 136);
static_assert(sizeof(ArkPsiPowerShiftLevelProperties) == 40);
static_assert(sizeof(ArkPsiPowerShiftLevelProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerShiftLevelProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerShiftLevelProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerShiftLevelProperties::ArkDuplicateDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerShiftLevelProperties::ArkOmniDirectionalProperty) == 32);
static_assert(sizeof(ArkPsiPowerShiftLevelProperties::ArkShiftDelaySecProperty) == 32);
static_assert(sizeof(ArkPsiPowerShiftLevelProperties::ArkShiftDistanceProperty) == 32);
static_assert(sizeof(ArkPsiPowerShiftUniqueProperties) == 24);
static_assert(sizeof(ArkPsiPowerShiftUniqueProperties::ArkDestroyDuplicateParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerShiftUniqueProperties::ArkDuplicateParticleEffectAttachmentProperty) == 32);
static_assert(sizeof(ArkPsiPowerShiftUniqueProperties::ArkSpawnDuplicateParticleEffectProperty) == 32);
static_assert(sizeof(ShiftPowerProperties) == 264);
static_assert(sizeof(ShiftPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(ShiftPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(ShiftPowerProperties::ArkUniqueProperty) == 32);

#include "ArkPsiPowerSmokeForm.h"
static_assert(sizeof(ArkPsiPowerSmokeForm) == 104);
static_assert(sizeof(ArkPsiPowerSmokeFormLevelProperties) == 32);
static_assert(sizeof(ArkPsiPowerSmokeFormLevelProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerSmokeFormLevelProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerSmokeFormLevelProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerSmokeFormLevelProperties::ArkMaxHeightProperty) == 32);
static_assert(sizeof(ArkPsiPowerSmokeFormLevelProperties::ArkPsiCostPerSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerSmokeFormUniqueProperties) == 40);
static_assert(sizeof(ArkPsiPowerSmokeFormUniqueProperties::ArkObjectFadeDistanceProperty) == 32);
static_assert(sizeof(ArkPsiPowerSmokeFormUniqueProperties::ArkPostProcessEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty) == 32);
static_assert(sizeof(SmokeFormPowerProperties) == 280);
static_assert(sizeof(SmokeFormPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(SmokeFormPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(SmokeFormPowerProperties::ArkUniqueProperty) == 32);

#include "ArkPsiPowerTargetingComponent.h"
static_assert(sizeof(ArkPsiPowerTargetingComponent) == 216);
static_assert(sizeof(ArkPsiPowerTargetingComponentProperties) == 80);
static_assert(sizeof(ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty) == 32);
static_assert(sizeof(ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty) == 32);
static_assert(sizeof(ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty) == 32);
static_assert(sizeof(ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty) == 32);
static_assert(sizeof(ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty) == 32);

#include "ArkPsiPowerThermalBlast.h"
static_assert(sizeof(ArkPsiPowerThermalBlastProperties) == 248);
static_assert(sizeof(ArkPsiPowerThermalBlastProperties::ArkBlastTypePropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerThermalBlastProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerThermalBlastProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerThermalBlastProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerThermalBlastProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiPowerThermalBlast) == 696);
static_assert(sizeof(ThermalBlastPowerProperties) == 248);
static_assert(sizeof(ThermalBlastPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(ThermalBlastPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(ThermalBlastPowerProperties::ArkUniqueProperty) == 32);

#include "IArkPlayerMimic.h"
static_assert(sizeof(IArkPlayerMimic) == 8);

#include "IArkPsiPower.h"
static_assert(sizeof(IArkPsiPower) == 8);

#if 0
#include "arkplayermimic.h"
static_assert(sizeof(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>) == 336);
static_assert(sizeof(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>) == 1144);
static_assert(sizeof(ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>) == 632);
static_assert(sizeof(ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>) == 144);
#endif

#include "arkplayermimicoperatorcontroller.h"
static_assert(sizeof(ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>) == 64);
static_assert(sizeof(ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>) == 64);
static_assert(sizeof(ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>) == 64);

#include "arkplayermimicoperatormovementcontroller.h"
static_assert(sizeof(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>) == 40);
static_assert(sizeof(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>) == 40);
static_assert(sizeof(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>) == 40);

#include "arkpsiliftvolumemanager.h"
//static_assert(sizeof(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >) == 32);
static_assert(sizeof(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >) == 32);
static_assert(sizeof(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >) == 32);

#include "arkpsipowercyberkinesis.h"
static_assert(sizeof(ArkPsiPowerCyberkinesisProperties) == 112);
static_assert(sizeof(ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(CyberkinesisPowerProperties) == 248);
static_assert(sizeof(CyberkinesisPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(CyberkinesisPowerProperties::ArkFactionProperty) == 32);
static_assert(sizeof(CyberkinesisPowerProperties::ArkLevelsProperty) == 32);

#include "arkpsipowerelectrostaticburst.h"
static_assert(sizeof(ArkPsiPowerElectrostaticBurstProperties) == 248);
static_assert(sizeof(ArkPsiPowerElectrostaticBurstProperties::ArkBlastTypePropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerElectrostaticBurstProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerElectrostaticBurstProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerElectrostaticBurstProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerElectrostaticBurstProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(ElectrostaticBurstPowerProperties) == 248);
static_assert(sizeof(ElectrostaticBurstPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(ElectrostaticBurstPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(ElectrostaticBurstPowerProperties::ArkUniqueProperty) == 32);

#include "arkpsipowerfaction.h"
static_assert(sizeof(ArkPsiPowerFactionProperties) == 8);
static_assert(sizeof(ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty) == 32);

#include "arkpsipowerfear.h"
static_assert(sizeof(ArkPsiPowerFearProperties) == 248);
static_assert(sizeof(ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerFearProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerFearProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(FearPowerProperties) == 248);
static_assert(sizeof(FearPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(FearPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(FearPowerProperties::ArkUniqueProperty) == 32);

#include "arkpsipowerhypnosis.h"
static_assert(sizeof(ArkPsiPowerHypnosisProperties) == 112);
static_assert(sizeof(ArkPsiPowerHypnosisProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerHypnosisProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerHypnosisProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerHypnosisProperties::ArkSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerHypnosisProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(HypnosisPowerProperties) == 248);
static_assert(sizeof(HypnosisPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(HypnosisPowerProperties::ArkFactionProperty) == 32);
static_assert(sizeof(HypnosisPowerProperties::ArkLevelsProperty) == 32);

#include "arkpsipowerkineticblast.h"
static_assert(sizeof(ArkPsiPowerKineticBlastProperties) == 248);
static_assert(sizeof(ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(KineticBlastPowerProperties) == 248);
static_assert(sizeof(KineticBlastPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(KineticBlastPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(KineticBlastPowerProperties::ArkUniqueProperty) == 32);

#include "arkpsipowerliftproperties.h"
static_assert(sizeof(ArkPsiLiftProperties) == 8);
static_assert(sizeof(ArkPsiLiftProperties::ArkDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiLiftProperties::ArkMaxHeightProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftLevelProperties) == 32);
static_assert(sizeof(ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties) == 104);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkGravityProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty) == 32);
static_assert(sizeof(LiftPowerProperties) == 344);
static_assert(sizeof(LiftPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(LiftPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(LiftPowerProperties::ArkUniqueProperty) == 32);

#include "arkpsipowermimicproperties.h"
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties) == 176);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraZeroGOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkAttackSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkAttackTurnSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraZeroGOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkDefaultTurnSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkMoveSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkRollSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkSafeCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkSprintSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicEngineeringOperatorProperties::ArkSwitchCameraInputLegendItemProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties) == 84);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraZeroGOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkAttackTurnSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraZeroGOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkDefaultTurnSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkLaserDamageProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkMoveSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkRollSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkSafeCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicMilitaryOperatorProperties::ArkSprintSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicOperatorProperties) == 64);
static_assert(sizeof(ArkPsiMimicOperatorProperties::ArkModalLegendProperty) == 32);
static_assert(sizeof(ArkPsiMimicOperatorProperties::ArkModalLegendZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties) == 144);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkAirControlScaleProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkDamageSignalGroupIdProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkJumpHeightProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkLiftMaxAngularSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkLoudnessIdProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkModalLegendProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkModalLegendZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkMoveSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkMoveSpeedZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkNoiseIdProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkNoiseIntervalProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkPenetratingJumpHeightProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkRollSpeedZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkSprintSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkSprintSpeedZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkTumbleSpeedLinearThresholdProperty) == 32);
static_assert(sizeof(ArkPsiMimicRigidProperties::ArkTumbleSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties) == 176);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkAttackCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkAttackCameraZeroGOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkAttackSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkAttackTurnSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraZeroGOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkDefaultTurnSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkMaxTargetAngleProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkMaxTargetDistanceProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkMoveSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkRollSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkSafeCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkSprintSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty) == 32);
static_assert(sizeof(ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties) == 96);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkAimSpeedProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkAimSpeedZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkAttackCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkModalLegendProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkMoveSpeedZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkRecoilForceZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkRollSpeedZeroGProperty) == 32);
static_assert(sizeof(ArkPsiMimicTurretProperties::ArkSprintSpeedZeroGProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties) == 64);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicLevelProperties) == 104);
static_assert(sizeof(ArkPsiPowerMimicLevelProperties::ArkCooldownDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicLevelProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicLevelProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicLevelProperties::ArkPsiCostPerSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicLevelProperties::ArkTargetingPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties) == 872);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkAutoFallbackRangeProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkClipOpacityProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkEffectsPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkEngineeringOperatorPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkForceMorphOutDelaySecProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkGameNoiseDelaySecProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkMilitaryOperatorPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkOperatorPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkRigidPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkScienceOperatorPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicUniqueProperties::ArkTurretPropertiesProperty) == 32);
static_assert(sizeof(MimicPowerProperties) == 1112);
static_assert(sizeof(MimicPowerProperties::ArkCommonProperty) == 32);
static_assert(sizeof(MimicPowerProperties::ArkLevelsProperty) == 32);
static_assert(sizeof(MimicPowerProperties::ArkUniqueProperty) == 32);

#include "arkpsitethermanager.h"
static_assert(sizeof(ArkPsiTetherProperties) == 56);
static_assert(sizeof(ArkPsiTetherProperties::ArkBreakDistanceProperty) == 32);
static_assert(sizeof(ArkPsiTetherProperties::ArkDrainAudioRtpcProperty) == 32);
static_assert(sizeof(ArkPsiTetherProperties::ArkLightningMaterialProperty) == 32);
static_assert(sizeof(ArkPsiTetherProperties::ArkLightningPresetProperty) == 32);
static_assert(sizeof(ArkPsiTetherProperties::ArkMaxDistanceProperty) == 32);
static_assert(sizeof(ArkPsiTetherProperties::ArkMaxTethersProperty) == 32);
static_assert(sizeof(ArkPsiTetherProperties::ArkMinDistanceProperty) == 32);
static_assert(sizeof(ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty) == 32);

#include "carkpsipower.h"
static_assert(sizeof(CArkPsiPower<CombatFocusPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<CreatePhantomPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<CyberkinesisPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<ElectrostaticBurstPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<FearPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<HypnosisPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<KineticBlastPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<KineticShieldPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<LiftPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<MimicPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<MindBlastPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<RemoteManipulationPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<ShiftPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<SmokeFormPowerProperties>) == 64);
static_assert(sizeof(CArkPsiPower<ThermalBlastPowerProperties>) == 64);

#include "arkpsipowerblast.h"
static_assert(sizeof(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent, CArkPsiElectrostaticBurst, ElectrostaticBurstPowerProperties, 0>) == 696);
static_assert(sizeof(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent, CArkPsiKineticBlast, KineticBlastPowerProperties, 3>) == 696);
static_assert(sizeof(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent, CArkPsiThermalBlast, ThermalBlastPowerProperties, 1>) == 696);
static_assert(sizeof(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent, CArkPsiFearBlast, FearPowerProperties, 8>) == 696);
