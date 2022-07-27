// Header test file for path Prey/Ark/ArkAbility.h
#include "ArkAbility.h"
static_assert(sizeof(ArkAbility) == 160);
static_assert(sizeof(ArkAbility::ArkIDProperty) == 32);
static_assert(sizeof(ArkAbility::ArkIconProperty) == 32);
static_assert(sizeof(ArkAbility::ArkNameProperty) == 32);
static_assert(sizeof(ArkAbility::ArkLabelProperty) == 32);
static_assert(sizeof(ArkAbility::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkAbility::ArkTierProperty) == 32);
static_assert(sizeof(ArkAbility::ArkNightmareHeatProperty) == 32);
static_assert(sizeof(ArkAbility::ArkCostProperty) == 32);
static_assert(sizeof(ArkAbility::ArkRequireScannerProperty) == 32);
static_assert(sizeof(ArkAbility::ArkPrereqsProperty) == 32);
static_assert(sizeof(ArkAbility::ArkPowerProperty) == 32);
static_assert(sizeof(ArkAbility::ArkPowerLevelProperty) == 32);
static_assert(sizeof(ArkAbility::ArkSignalModifiersProperty) == 32);
static_assert(sizeof(ArkAbility::ArkStatModifiersProperty) == 32);
static_assert(sizeof(ArkAbility::ArkTutorialProperty) == 32);
static_assert(sizeof(ArkAbility::ArkTutorialPCProperty) == 32);
static_assert(sizeof(ArkAbility::ArkTutorialImageProperty) == 32);
static_assert(sizeof(ArkSignalModifer) == 16);
static_assert(sizeof(ArkSignalModifer::ArkIsInboundProperty) == 32);
static_assert(sizeof(ArkSignalModifer::ArkModifierIdProperty) == 32);
static_assert(sizeof(ArkStatModifier) == 16);
static_assert(sizeof(ArkStatModifier::ArkStatNameProperty) == 32);
static_assert(sizeof(ArkStatModifier::ArkModifierProperty) == 32);
static_assert(sizeof(ArkAbilities) == 32);
static_assert(sizeof(ArkAbilities::ArkAbilitiesProperty) == 32);

#include "arkaudiolog.h"
static_assert(sizeof(ArkAudioLogCollection) == 56);
static_assert(sizeof(ArkAudioLogCollection::ArkIDProperty) == 32);
static_assert(sizeof(ArkAudioLogCollection::ArkNameProperty) == 32);
static_assert(sizeof(ArkAudioLogCollection::ArkOwnerProperty) == 32);
static_assert(sizeof(ArkAudioLogCollection::ArkPlotCriticalProperty) == 32);
static_assert(sizeof(ArkAudioLogCollection::ArkLinkedAudioLogsProperty) == 32);
static_assert(sizeof(ArkAudioLogLibrary) == 56);
static_assert(sizeof(ArkAudioLogLibrary::ArkAudioLogsProperty) == 32);
static_assert(sizeof(ArkAudioLogLibrary::ArkAudioLogCollectionsProperty) == 32);
static_assert(sizeof(ArkSecurityStation) == 112);
static_assert(sizeof(ArkSecurityStation::ArkIDProperty) == 32);
static_assert(sizeof(ArkSecurityStation::ArkNameProperty) == 32);
static_assert(sizeof(ArkSecurityStation::ArkUserProperty) == 32);
static_assert(sizeof(ArkSecurityStation::ArkLocationProperty) == 32);
static_assert(sizeof(ArkSecurityStation::ArkEmailsProperty) == 32);
static_assert(sizeof(ArkSecurityStation::ArkPersonnelProperty) == 32);
static_assert(sizeof(ArkSecurityStation::ArkUtilitiesProperty) == 32);
static_assert(sizeof(ArkSecurityStation::ArkPersonnelTitleProperty) == 32);

#include "ArkAudioUtil.h"
static_assert(sizeof(ArkAudioControl) == 4);
static_assert(sizeof(ArkAudioTrigger) == 4);
static_assert(sizeof(ArkAudioRtpc) == 4);

#include "ArkBuildInfo.h"
static_assert(sizeof(ArkBuildInfo) == 144);

#include "ArkCameraShake.h"
static_assert(sizeof(ArkCameraShake) == 80);
static_assert(sizeof(ArkCameraShake::ArkIDProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkNameProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkChannelProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkInnerRadiusProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkOuterRadiusProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkUIHorizontalAmplitudeProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkUIVerticalAmplitudeProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkRampInDurationProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkHoldDurationProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkRampOutDurationProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkVerticalFrequencyProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkHorizontalFrequencyProperty) == 32);
static_assert(sizeof(ArkCameraShake::ArkForceFeedbackProperty) == 32);
static_assert(sizeof(ArkCameraShake_Procedural) == 88);
static_assert(sizeof(ArkCameraShake_Procedural::ArkPitchAmplitudeProperty) == 32);
static_assert(sizeof(ArkCameraShake_Procedural::ArkYawAmplitudeProperty) == 32);
static_assert(sizeof(ArkCameraShake_Animated) == 88);
static_assert(sizeof(ArkCameraShake_Animated::ArkAnimationProperty) == 32);
static_assert(sizeof(ArkCameraShakeLibrary) == 56);
static_assert(sizeof(ArkCameraShakeLibrary::ArkCameraShakesProperty) == 32);
static_assert(sizeof(ArkCameraShakeLibrary::ArkChannelsProperty) == 32);

#include "ArkCharacter.h"
static_assert(sizeof(ArkCharacterGroup) == 24);
static_assert(sizeof(ArkCharacterGroup::ArkIDProperty) == 32);
static_assert(sizeof(ArkCharacterGroup::ArkNameProperty) == 32);
static_assert(sizeof(ArkCharacterGroup::ArkNotesProperty) == 32);
static_assert(sizeof(ArkCharacterGroups) == 32);
static_assert(sizeof(ArkCharacterGroups::ArkGroupsProperty) == 32);
static_assert(sizeof(ArkCharacter) == 88);
static_assert(sizeof(ArkCharacter::ArkIDProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkNameProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkLabelProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkPortraitProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkPasswordProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkJobTitleProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkGroupProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkVoiceProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkLocationProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkVitalSignsProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkIsAliveProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkHasTrackingChipProperty) == 32);
static_assert(sizeof(ArkCharacter::ArkRosterLocationProperty) == 32);
static_assert(sizeof(ArkCharacters) == 96);
static_assert(sizeof(ArkCharacters::ArkCharactersProperty) == 32);
static_assert(sizeof(ArkNote) == 72);
static_assert(sizeof(ArkNote::ArkIDProperty) == 32);
static_assert(sizeof(ArkNote::ArkNameProperty) == 32);
static_assert(sizeof(ArkNote::ArkPlotCriticalProperty) == 32);
static_assert(sizeof(ArkNote::ArkSubjectProperty) == 32);
static_assert(sizeof(ArkNote::ArkContentProperty) == 32);
static_assert(sizeof(ArkNote::ArkKeyCodeProperty) == 32);
static_assert(sizeof(ArkNote::ArkLocationProperty) == 32);
static_assert(sizeof(ArkNote::ArkPasswordProperty) == 32);
static_assert(sizeof(ArkNote::ArkImageNameProperty) == 32);

#include "ArkCharacterEffects.h"
static_assert(sizeof(ArkAttachmentEffect) == 40);
static_assert(sizeof(ArkAttachmentEffect::ArkAttachmentProperty) == 32);
static_assert(sizeof(ArkAttachmentEffect::ArkParticleEffectProperty) == 32);
static_assert(sizeof(ArkAttachmentEffect::ArkPositionOffsetProperty) == 32);
static_assert(sizeof(ArkAttachmentEffect::ArkRotationOffsetProperty) == 32);
static_assert(sizeof(ArkCharacterEffect) == 40);
static_assert(sizeof(ArkCharacterEffect::ArkIdProperty) == 32);
static_assert(sizeof(ArkCharacterEffect::ArkNameProperty) == 32);
static_assert(sizeof(ArkCharacterEffect::ArkAttachEffectsProperty) == 32);
static_assert(sizeof(ArkCharacterEffects) == 32);
static_assert(sizeof(ArkCharacterEffects::ArkEffectsProperty) == 32);

#include "ArkDialogAudioTrigger.h"
static_assert(sizeof(ArkDialogAudioTrigger) == 104);

#include "ArkDialogVoice.h"
static_assert(sizeof(ArkDialogVoice) == 80);
static_assert(sizeof(ArkDialogVoice::ArkIDProperty) == 32);
static_assert(sizeof(ArkDialogVoice::ArkNameProperty) == 32);
static_assert(sizeof(ArkDialogVoice::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkDialogVoice::ArkAbstractProperty) == 32);
static_assert(sizeof(ArkDialogVoice::ArkFaceFXProperty) == 32);
static_assert(sizeof(ArkDialogVoice::ArkSexProperty) == 32);
static_assert(sizeof(ArkDialogVoice::ArkEffectProperty) == 32);
static_assert(sizeof(ArkDialogVoice::ArkVoicesProperty) == 32);
static_assert(sizeof(ArkDialogVoices) == 96);
static_assert(sizeof(ArkDialogVoices::ArkVoicesProperty) == 32);

#include "arkdistractiondata.h"
static_assert(sizeof(DistractionPositioning) == 36);
static_assert(sizeof(DistractionPositioning::ArkMinValidStandRadiusProperty) == 32);
static_assert(sizeof(DistractionPositioning::ArkMaxValidStandRadiusProperty) == 32);
static_assert(sizeof(DistractionPositioning::ArkPositionRelativePosXProperty) == 32);
static_assert(sizeof(DistractionPositioning::ArkPositionRelativePosYProperty) == 32);
static_assert(sizeof(DistractionPositioning::ArkPositionRelativePosZProperty) == 32);
static_assert(sizeof(DistractionPositioning::ArkValidStandAngleProperty) == 32);
static_assert(sizeof(DistractionPositioning::ArkAngleOffsetProperty) == 32);
static_assert(sizeof(DistractionPositioning::ArkModeProperty) == 32);
static_assert(sizeof(DistractionPositioning::ArkMoveSpeedProperty) == 32);
static_assert(sizeof(DistractionAnimation) == 24);
static_assert(sizeof(DistractionAnimation::ArkFragmentProperty) == 32);
static_assert(sizeof(DistractionAnimation::ArkLoopMinTimeProperty) == 32);
static_assert(sizeof(DistractionAnimation::ArkLoopMaxTimeProperty) == 32);
static_assert(sizeof(DistractionAnimation::ArkTypeProperty) == 32);
static_assert(sizeof(DistractionAnimation::ArkHoverAddRootMotionProperty) == 32);
static_assert(sizeof(Distraction) == 160);
static_assert(sizeof(Distraction::ArkIDProperty) == 32);
static_assert(sizeof(Distraction::ArkNameProperty) == 32);
static_assert(sizeof(Distraction::ArkDebugProperty) == 32);
static_assert(sizeof(Distraction::ArkIgnoreNpcFacingCheckProperty) == 32);
static_assert(sizeof(Distraction::ArkOnUseCooldownProperty) == 32);
static_assert(sizeof(Distraction::ArkCanBeUsedInZeroGProperty) == 32);
static_assert(sizeof(Distraction::ArkReusableProperty) == 32);
static_assert(sizeof(Distraction::ArkSkipMovementProperty) == 32);
static_assert(sizeof(Distraction::ArkCanBeSimultaneousProperty) == 32);
static_assert(sizeof(Distraction::ArkCanRetreatToProperty) == 32);
static_assert(sizeof(Distraction::ArkTriggersAreaCooldownProperty) == 32);
static_assert(sizeof(Distraction::ArkUsesAreaCooldownProperty) == 32);
static_assert(sizeof(Distraction::ArkUseableByTagProperty) == 32);
static_assert(sizeof(Distraction::ArkTryDistractRateSecProperty) == 32);
static_assert(sizeof(Distraction::ArkMaxDistractDistanceProperty) == 32);
static_assert(sizeof(Distraction::ArkMaxDistractDistanceVerticalProperty) == 32);
static_assert(sizeof(Distraction::ArkMaxDistractionAngleDegreesOffForwardProperty) == 32);
static_assert(sizeof(Distraction::ArkMinDurationProperty) == 32);
static_assert(sizeof(Distraction::ArkMaxDurationProperty) == 32);
static_assert(sizeof(Distraction::ArkNpcUseColdownProperty) == 32);
static_assert(sizeof(Distraction::ArkMinHeightDifferenceProperty) == 32);
static_assert(sizeof(Distraction::ArkMaxHeightDifferenceProperty) == 32);
static_assert(sizeof(Distraction::ArkDistractionLookAtProperty) == 32);
static_assert(sizeof(Distraction::ArkDistractionPositioningProperty) == 32);
static_assert(sizeof(Distraction::ArkDistractionAnimationProperty) == 32);
static_assert(sizeof(Distraction::ArkDistractionEventProperty) == 32);
static_assert(sizeof(ArkDistractions) == 32);
static_assert(sizeof(ArkDistractions::ArkDistractionsProperty) == 32);
static_assert(sizeof(ArkUtility) == 32);
static_assert(sizeof(ArkUtility::ArkIDProperty) == 32);
static_assert(sizeof(ArkUtility::ArkNameProperty) == 32);
static_assert(sizeof(ArkUtility::ArkLabelProperty) == 32);
static_assert(sizeof(ArkUtility::ArkTypeProperty) == 32);
static_assert(sizeof(ArkUtility::ArkEnabledProperty) == 32);
static_assert(sizeof(ArkUtility::ArkHiddenProperty) == 32);
static_assert(sizeof(ArkUtilityButton) == 32);
static_assert(sizeof(ArkUtilityButton::ArkIDProperty) == 32);
static_assert(sizeof(ArkUtilityButton::ArkNameProperty) == 32);
static_assert(sizeof(ArkUtilityButton::ArkLabelProperty) == 32);
static_assert(sizeof(ArkUtilityButton::ArkEnabledProperty) == 32);
static_assert(sizeof(ArkUtilityButton::ArkHiddenProperty) == 32);
static_assert(sizeof(ArkStationAirlock) == 24);
static_assert(sizeof(ArkStationAirlock::ArkIDProperty) == 32);
static_assert(sizeof(ArkStationAirlock::ArkLocationProperty) == 32);
static_assert(sizeof(ArkStationAirlock::ArkStartsLockedProperty) == 32);
static_assert(sizeof(ArkStationAirlock::ArkStartsHiddenProperty) == 32);

#include "ArkEmotion.h"
static_assert(sizeof(ArkEmotion) == 32);
static_assert(sizeof(ArkEmotion::ArkIDProperty) == 32);
static_assert(sizeof(ArkEmotion::ArkNameProperty) == 32);
static_assert(sizeof(ArkEmotion::ArkAnimationProperty) == 32);
static_assert(sizeof(ArkEmotion::ArkBlendInProperty) == 32);
static_assert(sizeof(ArkEmotion::ArkBlendOutProperty) == 32);
static_assert(sizeof(ArkEmotions) == 32);
static_assert(sizeof(ArkEmotions::ArkEmotionsProperty) == 32);

#include "ArkEntitlement.h"
static_assert(sizeof(ArkEntitlement) == 32);
static_assert(sizeof(ArkEntitlement::ArkIDProperty) == 32);
static_assert(sizeof(ArkEntitlement::ArkNameProperty) == 32);
static_assert(sizeof(ArkEntitlement::ArkSteamDlcIDProperty) == 32);
static_assert(sizeof(ArkEntitlement::ArkXboxDlcIDProperty) == 32);
static_assert(sizeof(ArkEntitlement::ArkPlaystationDlcIDProperty) == 32);
static_assert(sizeof(ArkEntitlementLibrary) == 24);
static_assert(sizeof(ArkEntitlementLibrary::ArkEntitlementsProperty) == 32);

#include "ArkEntitlementUnlock.h"
static_assert(sizeof(ArkEntitlementUnlock_Item) == 16);
static_assert(sizeof(ArkEntitlementUnlock_Item::ArkArchetypeProperty) == 32);
static_assert(sizeof(ArkEntitlementUnlock_Item::ArkQuantityProperty) == 32);
static_assert(sizeof(ArkEntitlementUnlock) == 56);
static_assert(sizeof(ArkEntitlementUnlock::ArkIDProperty) == 32);
static_assert(sizeof(ArkEntitlementUnlock::ArkNameProperty) == 32);
static_assert(sizeof(ArkEntitlementUnlock::ArkEntitlementProperty) == 32);
static_assert(sizeof(ArkEntitlementUnlock::ArkTutorialProperty) == 32);
static_assert(sizeof(ArkEntitlementUnlock::ArkItemsProperty) == 32);
static_assert(sizeof(ArkEntitlementUnlockLibrary) == 32);
static_assert(sizeof(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty) == 32);

#include "arkenumstringimpl.h"
static_assert(sizeof(ArkComparison) == 1);

#include "ArkEventDrivenAchievement.h"
static_assert(sizeof(DistractionLookAt) == 16);
static_assert(sizeof(DistractionLookAt::ArkLookAtRelativePosXProperty) == 32);
static_assert(sizeof(DistractionLookAt::ArkLookAtRelativePosYProperty) == 32);
static_assert(sizeof(DistractionLookAt::ArkLookAtRelativePosZProperty) == 32);
static_assert(sizeof(DistractionLookAt::ArkModeProperty) == 32);
static_assert(sizeof(ArkMetricComparison) == 16);
static_assert(sizeof(ArkMetricComparison::ArkMetricProperty) == 32);
static_assert(sizeof(ArkMetricComparison::ArkComparisonTypeProperty) == 32);
static_assert(sizeof(ArkMetricComparison::ArkValueProperty) == 32);
static_assert(sizeof(ArkEventDrivenAchievement) == 48);
static_assert(sizeof(ArkEventDrivenAchievement::ArkIDProperty) == 32);
static_assert(sizeof(ArkEventDrivenAchievement::ArkNameProperty) == 32);
static_assert(sizeof(ArkEventDrivenAchievement::ArkRewardIDProperty) == 32);
static_assert(sizeof(ArkEventDrivenAchievement::ArkMetricComparisonsProperty) == 32);
static_assert(sizeof(ArkEventDrivenAchievementLibrary) == 32);
static_assert(sizeof(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty) == 32);

#include "ArkFabricationPlan.h"
static_assert(sizeof(ArkFabricationPlan) == 80);
static_assert(sizeof(ArkFabricationPlan::ArkIDProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkNameProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkArchetypeProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkOrganicCountProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkMineralCountProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkSyntheticCountProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkExoticCountProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkPositionOffsetProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkRotationOffsetProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkRawMaterialClassProperty) == 32);
static_assert(sizeof(ArkFabricationPlan::ArkUseShortAnimationProperty) == 32);
static_assert(sizeof(ArkFabricationPlans) == 128);
static_assert(sizeof(ArkFabricationPlans::ArkSmallRawMaterialModelProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkMediumRawMaterialModelProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkLargeRawMaterialModelProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkXLargeRawMaterialModelProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkSmallRawMaterialLongAnimProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkMediumRawMaterialLongAnimProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkLargeRawMaterialLongAnimProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkXLargeRawMaterialLongAnimProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkSmallRawMaterialShortAnimProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkMediumRawMaterialShortAnimProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkLargeRawMaterialShortAnimProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkXLargeRawMaterialShortAnimProperty) == 32);
static_assert(sizeof(ArkFabricationPlans::ArkFabricationPlansProperty) == 32);

#include "ArkFacingData.h"
static_assert(sizeof(ArkFacingData) == 44);

#include "arkgamemetrics.h"
static_assert(sizeof(ArkGameMetricProperties) == 40);
static_assert(sizeof(ArkGameMetricProperties::ArkIDProperty) == 32);
static_assert(sizeof(ArkGameMetricProperties::ArkNameProperty) == 32);
static_assert(sizeof(ArkGameMetricProperties::ArkLabelProperty) == 32);
static_assert(sizeof(ArkGameMetricProperties::ArkDefaultValueProperty) == 32);
static_assert(sizeof(ArkGameMetricProperties::ArkVisibilityThresholdProperty) == 32);
static_assert(sizeof(ArkGameMetricProperties::ArkHiddenFromUIProperty) == 32);
static_assert(sizeof(ArkGameMetricLibrary) == 32);
static_assert(sizeof(ArkGameMetricLibrary::ArkMetricsProperty) == 32);

#include "ArkGameMode.h"
static_assert(sizeof(ArkGameMode) == 24);
static_assert(sizeof(ArkGameMode::ArkNameProperty) == 32);
static_assert(sizeof(ArkGameMode::ArkMappedPathOverrideProperty) == 32);
static_assert(sizeof(ArkGameMode::ArkEntitlementProperty) == 32);
static_assert(sizeof(ArkGameModes) == 24);
static_assert(sizeof(ArkGameModes::ArkGameModesProperty) == 32);

#include "arkgamenoise.h"
static_assert(sizeof(ArkGameNoiseLoudness) == 24);
static_assert(sizeof(ArkGameNoiseLoudness::ArkIDProperty) == 32);
static_assert(sizeof(ArkGameNoiseLoudness::ArkNameProperty) == 32);
static_assert(sizeof(ArkGameNoiseLoudness::ArkRadiusProperty) == 32);
static_assert(sizeof(ArkGameNoiseType) == 16);
static_assert(sizeof(ArkGameNoiseType::ArkIDProperty) == 32);
static_assert(sizeof(ArkGameNoiseType::ArkNameProperty) == 32);
static_assert(sizeof(ArkGameNoises) == 48);
static_assert(sizeof(ArkGameNoises::ArkTypesProperty) == 32);
static_assert(sizeof(ArkGameNoises::ArkLoudnessesProperty) == 32);
static_assert(sizeof(ArkInputAction) == 16);
static_assert(sizeof(ArkInputAction::ArkActionProperty) == 32);
static_assert(sizeof(ArkInputAction::ArkActionMapProperty) == 32);

#include "ArkGameStateCondition.h"
static_assert(sizeof(ArkCondition) == 8);
static_assert(sizeof(ArkConditionGroup) == 40);
static_assert(sizeof(ArkConditionGroup::ArkAndProperty) == 32);
static_assert(sizeof(ArkConditionGroup::ArkConditionsProperty) == 32);
static_assert(sizeof(ArkNotCondition) == 48);
static_assert(sizeof(ArkNotCondition::ArkConditionGroupProperty) == 32);
static_assert(sizeof(ArkGameStateCondition) == 88);
static_assert(sizeof(ArkGameStateCondition::ArkIDProperty) == 32);
static_assert(sizeof(ArkGameStateCondition::ArkNameProperty) == 32);
static_assert(sizeof(ArkGameStateCondition::ArkEnabledProperty) == 32);
static_assert(sizeof(ArkGameStateCondition::ArkConditionGroupProperty) == 32);
static_assert(sizeof(ArkGameStateCondition::ArkResultsProperty) == 32);
static_assert(sizeof(ArkItemCondition) == 48);
static_assert(sizeof(ArkItemCondition::ArkArchetypeProperty) == 32);
static_assert(sizeof(ArkItemCondition::ArkMetaTagsProperty) == 32);
static_assert(sizeof(ArkItemCondition::ArkQuantityProperty) == 32);
static_assert(sizeof(ArkItemCondition::ArkComparisonTypeProperty) == 32);
static_assert(sizeof(ArkHasItemCondition) == 48);
static_assert(sizeof(ArkGainedItemCondition) == 48);
static_assert(sizeof(ArkLostItemCondition) == 48);
static_assert(sizeof(ArkAcquiredChipsetCondition) == 8);
static_assert(sizeof(ArkHealthAmountCondition) == 16);
static_assert(sizeof(ArkHealthAmountCondition::ArkAmountProperty) == 32);
static_assert(sizeof(ArkHealthAmountCondition::ArkComparisonTypeProperty) == 32);
static_assert(sizeof(ArkPsiAmountCondition) == 16);
static_assert(sizeof(ArkPsiAmountCondition::ArkAmountProperty) == 32);
static_assert(sizeof(ArkPsiAmountCondition::ArkComparisonTypeProperty) == 32);
static_assert(sizeof(ArkObjectiveCondition) == 24);
static_assert(sizeof(ArkObjectiveCondition::ArkObjectiveProperty) == 32);
static_assert(sizeof(ArkObjectiveCondition::ArkStateProperty) == 32);
static_assert(sizeof(ArkObjectiveTaskCondition) == 24);
static_assert(sizeof(ArkObjectiveTaskCondition::ArkTaskProperty) == 32);
static_assert(sizeof(ArkObjectiveTaskCondition::ArkStateProperty) == 32);
static_assert(sizeof(ArkInteractedWithCondition) == 40);
static_assert(sizeof(ArkInteractedWithCondition::ArkArchetypeProperty) == 32);
static_assert(sizeof(ArkInteractedWithCondition::ArkMetaTagsProperty) == 32);
static_assert(sizeof(ArkLookingAtCondition) == 48);
static_assert(sizeof(ArkLookingAtCondition::ArkArchetypeProperty) == 32);
static_assert(sizeof(ArkLookingAtCondition::ArkMetaTagsProperty) == 32);
static_assert(sizeof(ArkLookingAtCondition::ArkCheckIsAliveProperty) == 32);
static_assert(sizeof(ArkLookingAtNearCondition) == 48);
static_assert(sizeof(ArkLookingAtFarCondition) == 48);
static_assert(sizeof(ArkAbilityAcquiredCondition) == 16);
static_assert(sizeof(ArkAbilityAcquiredCondition::ArkAbilityProperty) == 32);
static_assert(sizeof(ArkTutorialOnCooldownCondition) == 16);
static_assert(sizeof(ArkTutorialOnCooldownCondition::ArkTutorialProperty) == 32);
static_assert(sizeof(ArkConditionExecutedCondition) == 24);
static_assert(sizeof(ArkConditionExecutedCondition::ArkGameStateConditionProperty) == 32);
static_assert(sizeof(ArkConditionExecutedCondition::ArkCountProperty) == 32);
static_assert(sizeof(ArkConditionExecutedCondition::ArkComparisonTypeProperty) == 32);
static_assert(sizeof(ArkFlashlightOnCondition) == 8);
static_assert(sizeof(ArkWeaponDurabilityCondition) == 16);
static_assert(sizeof(ArkWeaponDurabilityCondition::ArkAmountProperty) == 32);
static_assert(sizeof(ArkWeaponDurabilityCondition::ArkComparisonTypeProperty) == 32);
static_assert(sizeof(ArkGameMetricCondition) == 24);
static_assert(sizeof(ArkGameMetricCondition::ArkGameMetricProperty) == 32);
static_assert(sizeof(ArkGameMetricCondition::ArkValueProperty) == 32);
static_assert(sizeof(ArkGameMetricCondition::ArkComparisonTypeProperty) == 32);
static_assert(sizeof(ArkTraumaActiveCondition) == 16);
static_assert(sizeof(ArkTraumaActiveCondition::ArkTraumaProperty) == 32);
static_assert(sizeof(ArkPlayerInCombatCondition) == 8);
static_assert(sizeof(ArkDifficultyOptionCondition) == 16);
static_assert(sizeof(ArkDifficultyOptionCondition::ArkDifficultyOptionProperty) == 32);
static_assert(sizeof(ArkConditionResult) == 8);
static_assert(sizeof(ArkAutoSaveResult) == 8);
static_assert(sizeof(ArkDisplayTutorialResult) == 16);
static_assert(sizeof(ArkDisplayTutorialResult::ArkTutorialProperty) == 32);
static_assert(sizeof(ArkCollectTutorialResult) == 16);
static_assert(sizeof(ArkCollectTutorialResult::ArkTutorialProperty) == 32);
static_assert(sizeof(ArkDisplayPromptTutorialCallbackResult) == 24);
static_assert(sizeof(ArkDisplayPromptTutorialCallbackResult::ArkPromptTutorialProperty) == 32);
static_assert(sizeof(ArkDisplayPromptTutorialCallbackResult::ArkCardTutorialProperty) == 32);
static_assert(sizeof(ArkEnableGameStateConditionResult) == 24);
static_assert(sizeof(ArkEnableGameStateConditionResult::ArkGameStateConditionProperty) == 32);
static_assert(sizeof(ArkEnableGameStateConditionResult::ArkEnableProperty) == 32);
static_assert(sizeof(ArkDelayedResult) == 40);
static_assert(sizeof(ArkDelayedResult::ArkDelayProperty) == 32);
static_assert(sizeof(ArkDelayedResult::ArkResultsProperty) == 32);
static_assert(sizeof(ArkLockTipResult) == 24);
static_assert(sizeof(ArkLockTipResult::ArkTipLockProperty) == 32);
static_assert(sizeof(ArkLockTipResult::ArkLockedProperty) == 32);
static_assert(sizeof(ArkGameStateConditionLibrary) == 32);
static_assert(sizeof(ArkGameStateConditionLibrary::ArkGameStateConditionsProperty) == 32);

#include "ArkKeyCard.h"
static_assert(sizeof(ArkKeyCard) == 32);
static_assert(sizeof(ArkKeyCard::ArkIDProperty) == 32);
static_assert(sizeof(ArkKeyCard::ArkNameProperty) == 32);
static_assert(sizeof(ArkKeyCard::ArkLabelProperty) == 32);
static_assert(sizeof(ArkKeyCard::ArkLocationProperty) == 32);
static_assert(sizeof(ArkKeyCards) == 32);
static_assert(sizeof(ArkKeyCards::ArkKeyCardsProperty) == 32);

#include "ArkKeyCode.h"
static_assert(sizeof(ArkKeyCode) == 40);
static_assert(sizeof(ArkKeyCode::ArkIDProperty) == 32);
static_assert(sizeof(ArkKeyCode::ArkNameProperty) == 32);
static_assert(sizeof(ArkKeyCode::ArkLabelProperty) == 32);
static_assert(sizeof(ArkKeyCode::ArkCodeProperty) == 32);
static_assert(sizeof(ArkKeyCode::ArkLocationProperty) == 32);
static_assert(sizeof(ArkKeyCodes) == 32);
static_assert(sizeof(ArkKeyCodes::ArkKeyCodesProperty) == 32);

#include "ArkLocation.h"
static_assert(sizeof(ArkMapFloor) == 16);
static_assert(sizeof(ArkMapFloor::ArkNameProperty) == 32);
static_assert(sizeof(ArkMapFloor::ArkLabelProperty) == 32);
static_assert(sizeof(ArkLocation) == 112);
static_assert(sizeof(ArkLocation::ArkIDProperty) == 32);
static_assert(sizeof(ArkLocation::ArkNameProperty) == 32);
static_assert(sizeof(ArkLocation::ArkLabelProperty) == 32);
static_assert(sizeof(ArkLocation::ArkStationMapIndexProperty) == 32);
static_assert(sizeof(ArkLocation::ArkCooldownProperty) == 32);
static_assert(sizeof(ArkLocation::ArkTipProperty) == 32);
static_assert(sizeof(ArkLocation::ArkFloorsProperty) == 32);
static_assert(sizeof(ArkLocation::ArkScreenshotPathProperty) == 32);
static_assert(sizeof(ArkLocation::ArkLevelNameProperty) == 32);
static_assert(sizeof(ArkLocation::ArkRichPresenceProperty) == 32);
static_assert(sizeof(ArkLocation::ArkTransitionsProperty) == 32);
static_assert(sizeof(ArkLocations) == 32);
static_assert(sizeof(ArkLocations::ArkLocationsProperty) == 32);

#include "ArkLootTable.h"
static_assert(sizeof(ArkLootItem) == 32);
static_assert(sizeof(ArkLootItem::ArkArchetypeProperty) == 32);
static_assert(sizeof(ArkLootItem::ArkCountMinProperty) == 32);
static_assert(sizeof(ArkLootItem::ArkCountMaxProperty) == 32);
static_assert(sizeof(ArkLootItem::ArkWeightProperty) == 32);
static_assert(sizeof(ArkLootItem::ArkLootRequirementProperty) == 32);
static_assert(sizeof(ArkLootSlot) == 32);
static_assert(sizeof(ArkLootSlot::ArkPercentProperty) == 32);
static_assert(sizeof(ArkLootSlot::ArkItemsProperty) == 32);
static_assert(sizeof(ArkLootTable) == 32);
static_assert(sizeof(ArkLootTable::ArkNameProperty) == 32);
static_assert(sizeof(ArkLootTable::ArkSlotsProperty) == 32);
static_assert(sizeof(ArkLootTables) == 32);
static_assert(sizeof(ArkLootTables::ArkTablesProperty) == 32);

#include "ArkLoreEntry.h"
static_assert(sizeof(ArkLoreEntry) == 64);
static_assert(sizeof(ArkLoreEntry::ArkIDProperty) == 32);
static_assert(sizeof(ArkLoreEntry::ArkNameProperty) == 32);
static_assert(sizeof(ArkLoreEntry::ArkSubjectProperty) == 32);
static_assert(sizeof(ArkLoreEntry::ArkShortFormTextProperty) == 32);
static_assert(sizeof(ArkLoreEntry::ArkShortFormImageProperty) == 32);
static_assert(sizeof(ArkLoreEntry::ArkLongFormTextProperty) == 32);
static_assert(sizeof(ArkLoreEntry::ArkLongFormImageProperty) == 32);
static_assert(sizeof(ArkLoreEntry::ArkScannerDataProperty) == 32);
static_assert(sizeof(ArkLoreLibrary) == 32);
static_assert(sizeof(ArkLoreLibrary::ArkEntriesProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties) == 64);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty) == 32);

#include "ArkMaterialAnimations.h"
static_assert(sizeof(ArkMaterialAnimation) == 88);
static_assert(sizeof(ArkMaterialAnimation::ArkIdProperty) == 32);
static_assert(sizeof(ArkMaterialAnimation::ArkNameProperty) == 32);
static_assert(sizeof(ArkMaterialAnimation::ArkAttachmentNameProperty) == 32);
static_assert(sizeof(ArkMaterialAnimation::ArkMeshSlotProperty) == 32);
static_assert(sizeof(ArkMaterialAnimation::ArkMaterialReferenceProperty) == 32);
static_assert(sizeof(ArkMaterialAnimation::ArkSubMaterialsProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationRgbKeysArray) == 24);
static_assert(sizeof(ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationRgbKey) == 16);
static_assert(sizeof(ArkMaterialAnimationRgbKey::ArkTimeProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationRgbKey::ArkRedProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationRgbKey::ArkGreenProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationRgbKey::ArkBlueProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationKeysArray) == 24);
static_assert(sizeof(ArkMaterialAnimationKeysArray::ArkKeysProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData) == 200);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData::ArkSpecularProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData::ArkOpacityProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData::ArkAmbientProperty) == 32);
static_assert(sizeof(ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty) == 32);
static_assert(sizeof(ArkMaterialAnimations) == 32);
static_assert(sizeof(ArkMaterialAnimations::ArkAnimationsProperty) == 32);
static_assert(sizeof(ArkAbilityRow) == 24);
static_assert(sizeof(ArkAbilityRow::ArkAbilitiesProperty) == 32);

#include "arkmetatagdata.h"
static_assert(sizeof(ArkMetaTag) == 16);
static_assert(sizeof(ArkMetaTag::ArknameProperty) == 32);
static_assert(sizeof(ArkMetaTag::ArkidProperty) == 32);
static_assert(sizeof(ArkMetaTags) == 32);
static_assert(sizeof(ArkMetaTags::ArkMetaTagsProperty) == 32);

#include "arknote.h"
static_assert(sizeof(ArkNotes) == 32);
static_assert(sizeof(ArkNotes::ArkNotesProperty) == 32);

#include "arkobjectiveutils.h"
static_assert(sizeof(ArkObjectiveUtils::CArkObjectiveTaskData) == 72);
static_assert(sizeof(ArkObjectiveUtils::CArkObjectiveData) == 96);
static_assert(sizeof(ArkObjectiveUtils::CArkObjectiveLib) == 24);

#include "ArkPointOfInterest.h"
static_assert(sizeof(ArkPointOfInterest) == 24);
static_assert(sizeof(ArkPointOfInterest::ArkIDProperty) == 32);
static_assert(sizeof(ArkPointOfInterest::ArkNameProperty) == 32);
static_assert(sizeof(ArkPointOfInterest::ArkLabelProperty) == 32);
static_assert(sizeof(ArkPointOfInterestLibrary) == 32);
static_assert(sizeof(ArkPointOfInterestLibrary::ArkPOIsProperty) == 32);

#include "arkpropertyprofile.h"
static_assert(sizeof(ArkDisruptionProfile) == 72);
static_assert(sizeof(ArkDisruptionProfile::ArkIDProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkNameProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkDisruptThresholdProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkDisruptMaxAmountProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkDisruptDecayRateProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkDisruptSparkRateProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkDisruptSparkVariationProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkDisruptSignalProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkInterferenceThresholdProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkInterferenceMaxAmountProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkInterferenceDecayRateProperty) == 32);
static_assert(sizeof(ArkDisruptionProfile::ArkInterferenceSignalProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile) == 104);
static_assert(sizeof(ArkLightDisruptionProfile::ArkIDProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkNameProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkDisruptionBurstTransitionTimeProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkDisruptionBurstMultiplierProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceRampInProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceRampInVariationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceRampOutProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceRampOutVariationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceDarkDurationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceDarkDurationVariationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationVariationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceBrightDurationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceBrightDurationVariationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessVariationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceMinBrightnessProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceMinBrightnessVariationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessVariationProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferencePrimaryDarkWeightProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkWeightProperty) == 32);
static_assert(sizeof(ArkLightDisruptionProfile::ArkInterferenceVFXThresholdProperty) == 32);
static_assert(sizeof(ArkNagTutorial) == 64);
static_assert(sizeof(ArkNagTutorial::ArkDurationProperty) == 32);
static_assert(sizeof(ArkPropertyProfileLibrary) == 56);
static_assert(sizeof(ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty) == 32);
static_assert(sizeof(ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty) == 32);

#include "ArkPsiBlastProperties.h"
static_assert(sizeof(ArkPsiBlastProperties) == 144);
static_assert(sizeof(ArkPsiBlastProperties::ArkRadiusProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkTriggerRadiusProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkForceProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkFalloffScaleProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkFalloffRadiusProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkDelaySecProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkExplosionDelaySecProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkUpdateIntervalSecProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkMaxBlastCountProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkNoiseIdProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkLoudnessIdProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkExplosionParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiBlastProperties::ArkCameraShakeProperty) == 32);

#include "ArkPsiPowerCommonProperties.h"
static_assert(sizeof(ArkPsiPowerBlackListEntry) == 4);
static_assert(sizeof(ArkPsiPowerBlackListEntry::ArkPowerProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties) == 208);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkDisplayNameProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkPickerLabelProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkHelpTextProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkPsiCostProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkNoiseIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkLoudnessIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkModalLegendProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkTargetingLegendProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkPostProcessVFXProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkPersistentPostProcessVFXProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkTargetHighlightColorProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkTargetHighlightColorAlphaProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkExecutionPlayerEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkExecutionAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkCameraZoomDurationProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkInterruptsMimicGrabSequenceProperty) == 32);
static_assert(sizeof(ArkPsiPowerCommonProperties::ArkCostReductionStatProperty) == 32);

#include "ArkResearchTopic.h"
static_assert(sizeof(ArkResearchTopicAbilityGroup) == 32);
static_assert(sizeof(ArkResearchTopicAbilityGroup::ArkScansRequiredProperty) == 32);
static_assert(sizeof(ArkResearchTopicAbilityGroup::ArkAbilitiesProperty) == 32);
static_assert(sizeof(ArkResearchTopic) == 88);
static_assert(sizeof(ArkResearchTopic::ArkIDProperty) == 32);
static_assert(sizeof(ArkResearchTopic::ArkNameProperty) == 32);
static_assert(sizeof(ArkResearchTopic::ArkLoreScansRequiredProperty) == 32);
static_assert(sizeof(ArkResearchTopic::ArkLoreProperty) == 32);
static_assert(sizeof(ArkResearchTopic::ArkAbilityGroupsProperty) == 32);
static_assert(sizeof(ArkResearchTopic::ArkMetaTagsProperty) == 32);
static_assert(sizeof(ArkResearchTopics) == 32);
static_assert(sizeof(ArkResearchTopics::ArkTopicsProperty) == 32);

#include "arksecuritystation.h"
static_assert(sizeof(ArkSecurityStations) == 32);
static_assert(sizeof(ArkSecurityStations::ArkSecurityStationsProperty) == 32);

#include "arksignalsystemdata.h"
static_assert(sizeof(ArkSignalSystem::Data) == 96);
static_assert(sizeof(ArkSignalSystem::Data::SignalGroupData) == 40);
static_assert(sizeof(ArkSignalSystem::Data::?$SortableData@VSignalGroupData@Data@ArkSignalSystem@@) == 8);
static_assert(sizeof(ArkSignalSystem::Data::PackageData) == 40);
static_assert(sizeof(ArkSignalSystem::Data::PackageData::SignalValueData) == 16);
static_assert(sizeof(ArkSignalSystem::Data::?$SortableData@VPackageData@Data@ArkSignalSystem@@) == 8);
static_assert(sizeof(ArkSignalSystem::Data::SignalData) == 16);
static_assert(sizeof(ArkSignalSystem::Data::?$SortableData@VSignalData@Data@ArkSignalSystem@@) == 8);
static_assert(sizeof(ArkSignalSystem::Data::ModifierData) == 40);
static_assert(sizeof(ArkSignalSystem::Data::ModifierData::RuleData) == 72);
static_assert(sizeof(ArkSignalSystem::Data::ModifierData::RuleData::FactorData) == 16);
static_assert(sizeof(ArkSignalSystem::Data::?$SortableData@VModifierData@Data@ArkSignalSystem@@) == 8);
static_assert(sizeof(ArkSignalSystem::Data::?$SortableData@VFactorData@RuleData@ModifierData@Data@ArkSignalSystem@@) == 8);

#include "ArkStationAccess.h"
static_assert(sizeof(ArkTransition) == 24);
static_assert(sizeof(ArkTransition::ArkConnectionAProperty) == 32);
static_assert(sizeof(ArkTransition::ArkConnectionBProperty) == 32);
static_assert(sizeof(ArkTransition::ArkCostProperty) == 32);
static_assert(sizeof(ArkStationPath) == 40);
static_assert(sizeof(ArkStationPath::ArkIDProperty) == 32);
static_assert(sizeof(ArkStationPath::ArkNameProperty) == 32);
static_assert(sizeof(ArkStationPath::ArkFlashIDProperty) == 32);
static_assert(sizeof(ArkStationPath::ArkLocationAProperty) == 32);
static_assert(sizeof(ArkStationPath::ArkLocationBProperty) == 32);
static_assert(sizeof(ArkStationAccess) == 56);
static_assert(sizeof(ArkStationAccess::ArkPathsProperty) == 32);
static_assert(sizeof(ArkStationAccess::ArkAirlocksProperty) == 32);

#include "ArkTip.h"
static_assert(sizeof(ArkTip) == 64);
static_assert(sizeof(ArkTip::ArkIDProperty) == 32);
static_assert(sizeof(ArkTip::ArkNameProperty) == 32);
static_assert(sizeof(ArkTip::ArkContentProperty) == 32);
static_assert(sizeof(ArkTip::ArkLocksProperty) == 32);
static_assert(sizeof(ArkTip::ArkSequenceProperty) == 32);
static_assert(sizeof(ArkTip::ArkHideOnDeathScreenProperty) == 32);
static_assert(sizeof(ArkTipLock) == 16);
static_assert(sizeof(ArkTipLock::ArkIDProperty) == 32);
static_assert(sizeof(ArkTipLock::ArkNameProperty) == 32);
static_assert(sizeof(ArkTipSequence) == 16);
static_assert(sizeof(ArkTipSequence::ArkIDProperty) == 32);
static_assert(sizeof(ArkTipSequence::ArkNameProperty) == 32);
static_assert(sizeof(ArkTipLibrary) == 80);
static_assert(sizeof(ArkTipLibrary::ArkTipsProperty) == 32);
static_assert(sizeof(ArkTipLibrary::ArkLocksProperty) == 32);
static_assert(sizeof(ArkTipLibrary::ArkSequencesProperty) == 32);

#include "ArkTraumas.h"
static_assert(sizeof(ArkTrauma) == 176);
static_assert(sizeof(ArkTrauma::ArkIDProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkNameProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkLabelProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkSurvivalModeProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkHowToRemoveProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkDoesStackProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkMaxAccumulationProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkDrainRateProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkRemoveOnDrainProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkFillHudIconProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkSuitVOProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkPlayerMaterialProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkPlayerMaterialPriorityProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkTraumaSFXProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkTraumaStopSFXProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkDurationProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkPostEffectProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkPostEffectParamProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkRepeatMinProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkRepeatMaxProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkTagStateProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkRemoveSignalProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkAccumulateSignalProperty) == 32);
static_assert(sizeof(ArkTrauma::ArkPhasesProperty) == 32);
static_assert(sizeof(ArkTraumaPhase) == 80);
static_assert(sizeof(ArkTraumaPhase::ArkDamageThresholdProperty) == 32);
static_assert(sizeof(ArkTraumaPhase::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkTraumaPhase::ArkAltOxygenDescriptionProperty) == 32);
static_assert(sizeof(ArkTraumaPhase::ArkHudIconProperty) == 32);
static_assert(sizeof(ArkTraumaPhase::ArkSignalModifiersProperty) == 32);
static_assert(sizeof(ArkTraumaPhase::ArkStatModifiersProperty) == 32);
static_assert(sizeof(ArkConditionalSignalModifier) == 24);
static_assert(sizeof(ArkConditionalSignalModifier::ArkIsActiveInAlternateFormProperty) == 32);
static_assert(sizeof(ArkConditionalStatModifier) == 24);
static_assert(sizeof(ArkConditionalStatModifier::ArkIsActiveInAlternateFormProperty) == 32);
static_assert(sizeof(ArkTraumas) == 32);
static_assert(sizeof(ArkTraumas::ArkTraumasProperty) == 32);

#include "ArkTutorial.h"
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties) == 104);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkGravityProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty) == 32);
static_assert(sizeof(ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty) == 32);
static_assert(sizeof(ArkTutorial) == 56);
static_assert(sizeof(ArkTutorial::ArkIDProperty) == 32);
static_assert(sizeof(ArkTutorial::ArkNameProperty) == 32);
static_assert(sizeof(ArkTutorial::ArkCooldownProperty) == 32);
static_assert(sizeof(ArkTutorial::ArkBodyProperty) == 32);
static_assert(sizeof(ArkTutorial::ArkBodyPCProperty) == 32);
static_assert(sizeof(ArkTutorial::ArkTypeProperty) == 32);
static_assert(sizeof(ArkTutorial::ArkAudioTriggerProperty) == 32);
static_assert(sizeof(ArkCardTutorial) == 88);
static_assert(sizeof(ArkCardTutorial::ArkTitleProperty) == 32);
static_assert(sizeof(ArkCardTutorial::ArkImageProperty) == 32);
static_assert(sizeof(ArkCardTutorial::ArkDialogProperty) == 32);
static_assert(sizeof(ArkCardTutorial::ArkDelayProperty) == 32);
static_assert(sizeof(ArkContextualTutorial) == 120);
static_assert(sizeof(ArkContextualTutorial::ArkActionMapProperty) == 32);
static_assert(sizeof(ArkContextualTutorial::ArkActionIdProperty) == 32);
static_assert(sizeof(ArkContextualTutorial::ArkActionIdPCProperty) == 32);
static_assert(sizeof(ArkContextualTutorial::ArkTutorialPromptProperty) == 32);
static_assert(sizeof(ArkTutorialLibrary) == 40);
static_assert(sizeof(ArkTutorialLibrary::ArkTutorialsProperty) == 32);
static_assert(sizeof(ArkTutorialLibrary::ArkContextualDisplayTimeProperty) == 32);
static_assert(sizeof(ArkTutorialLibrary::ArkNagDisplayTimeProperty) == 32);

#include "ArkUtils.h"
static_assert(sizeof(ArkUtils::ClassList) == 24);
static_assert(sizeof(ArkUtils::CollisionCache) == 24);
static_assert(sizeof(ArkUtils::CollisionCache::Collision) == 12);

#include "ArkWeaponModifier.h"
static_assert(sizeof(ArkWeaponModifier) == 72);
static_assert(sizeof(ArkWeaponModifier::ArkIDProperty) == 32);
static_assert(sizeof(ArkWeaponModifier::ArkNameProperty) == 32);
static_assert(sizeof(ArkWeaponModifier::ArkLabelProperty) == 32);
static_assert(sizeof(ArkWeaponModifier::ArkDefaultSummaryProperty) == 32);
static_assert(sizeof(ArkWeaponModifier::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkWeaponModifier::ArkInstallWeaponProperty) == 32);
static_assert(sizeof(ArkWeaponModifier::ArkWeaponModLevelsProperty) == 32);
static_assert(sizeof(ArkWeaponModLevel) == 88);
static_assert(sizeof(ArkWeaponModLevel::ArkLevelProperty) == 32);
static_assert(sizeof(ArkWeaponModLevel::ArkSummaryProperty) == 32);
static_assert(sizeof(ArkWeaponModLevel::ArkFanfareTextProperty) == 32);
static_assert(sizeof(ArkWeaponModLevel::ArkTagStateProperty) == 32);
static_assert(sizeof(ArkWeaponModLevel::ArkPrereqProperty) == 32);
static_assert(sizeof(ArkWeaponModLevel::ArkSignalModifiersProperty) == 32);
static_assert(sizeof(ArkWeaponModLevel::ArkStatModifiersProperty) == 32);
static_assert(sizeof(ArkWeaponModifiers) == 32);
static_assert(sizeof(ArkWeaponModifiers::ArkWeaponModifiersProperty) == 32);

#include "ArkWorkstation.h"
static_assert(sizeof(ArkDownload) == 40);
static_assert(sizeof(ArkDownload::ArkIDProperty) == 32);
static_assert(sizeof(ArkDownload::ArkNameProperty) == 32);
static_assert(sizeof(ArkDownload::ArkLabelProperty) == 32);
static_assert(sizeof(ArkDownload::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkDownload::ArkDurationProperty) == 32);
static_assert(sizeof(ArkDownload::ArkHiddenProperty) == 32);
static_assert(sizeof(ArkKeypadUtility) == 32);
static_assert(sizeof(ArkButtonUtility) == 72);
static_assert(sizeof(ArkButtonUtility::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkButtonUtility::ArkNoDefaultButtonProperty) == 32);
static_assert(sizeof(ArkButtonUtility::ArkButtonsProperty) == 32);
static_assert(sizeof(ArkEmail) == 120);
static_assert(sizeof(ArkEmail::ArkIDProperty) == 32);
static_assert(sizeof(ArkEmail::ArkNameProperty) == 32);
static_assert(sizeof(ArkEmail::ArkSubjectProperty) == 32);
static_assert(sizeof(ArkEmail::ArkBodyProperty) == 32);
static_assert(sizeof(ArkEmail::ArkDateProperty) == 32);
static_assert(sizeof(ArkEmail::ArkFromProperty) == 32);
static_assert(sizeof(ArkEmail::ArkToProperty) == 32);
static_assert(sizeof(ArkEmail::ArkCCProperty) == 32);
static_assert(sizeof(ArkEmail::ArkKeycodeProperty) == 32);
static_assert(sizeof(ArkEmail::ArkPasswordProperty) == 32);
static_assert(sizeof(ArkEmail::ArkSentProperty) == 32);
static_assert(sizeof(ArkEmail::ArkImportantProperty) == 32);
static_assert(sizeof(ArkWorkstation) == 120);
static_assert(sizeof(ArkWorkstation::ArkIDProperty) == 32);
static_assert(sizeof(ArkWorkstation::ArkNameProperty) == 32);
static_assert(sizeof(ArkWorkstation::ArkWorkstationTitleProperty) == 32);
static_assert(sizeof(ArkWorkstation::ArkUserProperty) == 32);
static_assert(sizeof(ArkWorkstation::ArkUseEmployeeModeProperty) == 32);
static_assert(sizeof(ArkWorkstation::ArkEmailsProperty) == 32);
static_assert(sizeof(ArkWorkstation::ArkDownloadsProperty) == 32);
static_assert(sizeof(ArkWorkstation::ArkUtilitiesProperty) == 32);
static_assert(sizeof(ArkWorkstation::ArkUtilitiesTitleProperty) == 32);
static_assert(sizeof(ArkWorkstations) == 32);
static_assert(sizeof(ArkWorkstations::ArkWorkstationsProperty) == 32);
static_assert(sizeof(ArkEmails) == 32);
static_assert(sizeof(ArkEmails::ArkEmailsProperty) == 32);

#include "IArkDialogLoadListener.h"
static_assert(sizeof(IArkDialogLoadListener) == 8);

#include "iarkposteffectmanager.h"
static_assert(sizeof(TArkPostEffectValue) == 24);
static_assert(sizeof(TArkPostEffectValue::ExtractType) == 1);
static_assert(sizeof(TArkPostEffectValue::IsEqual) == 1);

#include "iarkspacemanager.h"
static_assert(sizeof(ArkSpaceSettings) == 240);
