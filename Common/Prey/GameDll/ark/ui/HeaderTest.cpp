// Header test file for path Prey/GameDll/ark/ui/

#include "ArkBinkPlayerHandle.h"
static_assert(sizeof(ArkBinkPlayerHandle) == 8);

#include "ArkBrightnessMenu.h"
static_assert(sizeof(ArkBrightnessMenu) == 112);

#include "ArkButtonPrompt.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkButtonPrompt) == 56);
#else
static_assert(sizeof(ArkButtonPrompt) == 88);
#endif

#include "ArkButtonPromptCollection.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkButtonPromptCollection) == 584);
#else
static_assert(sizeof(ArkButtonPromptCollection) == 840);
#endif

#include "arkexternalinventoryui.h"
static_assert(sizeof(CArkExternalInventoryUI) == 112);
#ifndef MOONCRASH
static_assert(sizeof(CArkExternalInventoryUI::TransferNotification) == 40);
#else
static_assert(sizeof(CArkExternalInventoryUI::TransferNotification) == 48);
#endif

#include "ArkFocusModeUIComponent.h"
static_assert(sizeof(ArkFocusModeUIComponent) == 168);

#include "ArkGenderSelectMenu.h"
static_assert(sizeof(ArkGenderSelectMenu) == 104);

#include "ArkHackingUI.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkHackingUI) == 536);
#else
static_assert(sizeof(ArkHackingUI) == 544);
#endif
static_assert(sizeof(ArkHackingUI::SKeyInputPressed) == 4);
static_assert(sizeof(ArkHackingUI::HackingCircle) == 8);
static_assert(sizeof(ArkHackingUI::ObstacleSpawnDesc) == 20);
static_assert(sizeof(ArkHackingUI::Obstacle) == 20);
static_assert(sizeof(ArkHackingUI::HackingDifficultyLevel) == 24);
static_assert(sizeof(ArkHackingUI::ArkHackingPuzzle) == 56);

#include "ArkHitDamageInfo.h"
static_assert(sizeof(ArkHitDamageInfo) == 48);

#include "ArkHitDamageUI.h"
static_assert(sizeof(ArkHitDamageUI) == 416);

#include "ArkIndicatorIconManager.h"
static_assert(sizeof(ArkIndicatorIconManager) == 56);
static_assert(sizeof(ArkIndicatorIconManager::IndicatorIcon) == 24);

#include "ArkInputLegend.h"
static_assert(sizeof(ArkInputLegendItem) == 80);
static_assert(sizeof(ArkInputLegendItem::ArkActionProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkActionMapProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkLabelProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkHoldProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkComboStringProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkActionListProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkControlSchemeProperty) == 32);
static_assert(sizeof(ArkInputLegend) == 32);
static_assert(sizeof(ArkInputLegend::ArkActionMapProperty) == 32);
static_assert(sizeof(ArkInputLegend::ArkItemsProperty) == 32);
#ifdef MOONCRASH
static_assert(sizeof(ArkInputAction) == 16);
static_assert(sizeof(ArkInputAction::ArkActionProperty) == 32);
static_assert(sizeof(ArkInputAction::ArkActionMapProperty) == 32);
#endif

#include "ArkInputLegendHandler.h"
static_assert(sizeof(ArkInputLegendHandler) == 4);

#include "ArkInventoryPreview.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkInventoryPreview) == 648);
#else
static_assert(sizeof(ArkInventoryPreview) == 904);
#endif

#include "arkinventoryui.h"
static_assert(sizeof(IArkInventoryUIOwner) == 8);
static_assert(sizeof(CArkInventoryUI) == 88);
static_assert(sizeof(CArkInventoryUI::SelectedWeaponInfo_ModInfo) == 48);
#ifndef MOONCRASH
static_assert(sizeof(CArkInventoryUI::SelectedWeaponInfo) == 40);
static_assert(sizeof(CArkInventoryUI::SelectedItemInfo) == 88);
#else
static_assert(sizeof(CArkInventoryUI::SelectedWeaponInfo) == 48);
static_assert(sizeof(CArkInventoryUI::SelectedItemInfo) == 96);
#endif

#include "ArkLauncherMenu.h"
static_assert(sizeof(ArkLauncherMenu) == 152);

#include "ArkModalDialogBase.h"
static_assert(sizeof(ArkModalDialogBase) == 224);
static_assert(sizeof(ArkModalDialogBase::ButtonAction) == 48);

#include "ArkModalDialogInGame.h"
static_assert(sizeof(ArkModalDialogInGame) == 224);

#include "ArkModalDialogMetaGame.h"
static_assert(sizeof(ArkModalDialogMetaGame) == 224);

#include "ArkModalDialogRepair.h"
static_assert(sizeof(ArkModalDialogRepair) == 232);

#include "ArkNoteUI.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNoteUI) == 656);
#else
static_assert(sizeof(ArkNoteUI) == 912);
#endif

#include "ArkOptionDropDownBase.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkOptionDropDownBase) == 8);
#endif

#include "ArkOptionLayout.h"
#ifndef MOONCRASH
static_assert(sizeof(DistractionEvent) == 8);
static_assert(sizeof(DistractionEvent::ArkEventProperty) == 32);
static_assert(sizeof(ArkOptionSubAction) == 8);
static_assert(sizeof(ArkOptionSubAction::ArkActionProperty) == 32);
#endif
static_assert(sizeof(ArkOption) == 56);
static_assert(sizeof(ArkOption::ArkLabelProperty) == 32);
static_assert(sizeof(ArkOption::ArkValueProperty) == 32);
static_assert(sizeof(ArkOption::ArkHiddenProperty) == 32);
static_assert(sizeof(ArkOption::ArkSubactionsProperty) == 32);
static_assert(sizeof(ArkOptionWidgetBase) == 8);
static_assert(sizeof(ArkOptionAttribute) == 88);
static_assert(sizeof(ArkOptionAttribute::ArkActionProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkLabelProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkSetOnChangeProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkHideOnFrontendProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkHideInGameProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkCloseMenuProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkDefaultProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkHideFromProfileProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkHiddenProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkPlatformProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkSubactionsProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkWidgetProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkWaitForTextureReloadProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkWriteConfigFileProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkHideForSteamControllerProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkHideOnQuasimodoProperty) == 32);
static_assert(sizeof(ArkOptionAttribute::ArkHideOnPCProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage) == 64);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkLabelProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkLabelPS4Property) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkAttributesProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkKeybindsProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkPlatformProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkWriteConfigFileProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkRequiresApplyProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkWarningProperty) == 32);
static_assert(sizeof(ArkOptionLayoutPage) == 32);
static_assert(sizeof(ArkOptionLayoutPage::ArkLabelProperty) == 32);
static_assert(sizeof(ArkOptionLayoutPage::ArkSubPagesProperty) == 32);
static_assert(sizeof(ArkOptionSlider) == 32);
static_assert(sizeof(ArkOptionSlider::ArkMinProperty) == 32);
static_assert(sizeof(ArkOptionSlider::ArkMaxProperty) == 32);
static_assert(sizeof(ArkOptionSlider::ArkDecimalsProperty) == 32);
static_assert(sizeof(ArkOptionSlider::ArkUnitProperty) == 32);
static_assert(sizeof(ArkOptionSlider::ArkNormalizeProperty) == 32);
static_assert(sizeof(ArkOptionList) == 32);
static_assert(sizeof(ArkOptionList::ArkOptionsProperty) == 32);
static_assert(sizeof(ArkOptionDataList) == 40);
static_assert(sizeof(ArkOptionDataList::ArkPathProperty) == 32);
static_assert(sizeof(ArkOptionDataList::ArkXPathProperty) == 32);
static_assert(sizeof(ArkOptionDataList::ArkIDProperty) == 32);
static_assert(sizeof(ArkOptionDataList::ArkLabelProperty) == 32);
static_assert(sizeof(ArkOptionButton) == 16);
static_assert(sizeof(ArkOptionButton::ArkMenuProperty) == 32);
static_assert(sizeof(ArkOptionControlMap) == 8);
#ifndef MOONCRASH
static_assert(sizeof(ArkDifficultyOption) == 56);
#endif
static_assert(sizeof(ArkOptionToggle) == 120);
static_assert(sizeof(ArkOptionToggle::ArkOption0Property) == 32);
static_assert(sizeof(ArkOptionToggle::ArkOption1Property) == 32);
static_assert(sizeof(ArkOptionLayout) == 24);
static_assert(sizeof(ArkOptionLayout::ArkPagesProperty) == 32);
#ifndef MOONCRASH
static_assert(sizeof(ArkOptionDropDownBase) == 8);
#endif
static_assert(sizeof(ArkOptionDropDown) == 32);
static_assert(sizeof(ArkOptionDropDown::ArkOptionsProperty) == 32);
static_assert(sizeof(ArkOptionMonitor) == 32);
static_assert(sizeof(ArkOptionResolution) == 40);
static_assert(sizeof(ArkOptionLanguageBase) == 32);
static_assert(sizeof(ArkOptionAudioLanguage) == 32);
static_assert(sizeof(ArkOptionTextLanguage) == 32);

#include "ArkOptionMenu.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkOptionMenu) == 328);
#else
static_assert(sizeof(ArkOptionMenu) == 1168);
#endif
static_assert(sizeof(ArkOptionMenu::RingBuffer) == 68);

#include "ArkOptionMenuBase.h"
static_assert(sizeof(ArkOptionMenuBase) == 104);
static_assert(sizeof(ArkOptionMenuBase::SelectedOption) == 4);

#include "ArkPauseMenu.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkScoreCard) == 32);
static_assert(sizeof(ArkScoreCard::ArkGameMetricsProperty) == 32);
#endif
#ifndef MOONCRASH
static_assert(sizeof(ArkPauseMenu) == 120);
#else
static_assert(sizeof(ArkPauseMenu) == 128);
#endif

#include "ArkPDAComponent.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkPDAComponent) == 896);
#else
static_assert(sizeof(ArkPDAComponent) == 1152);
#endif

#include "arkpdapageabilities.h"
static_assert(sizeof(ArkAbilityRow) == 24);
static_assert(sizeof(ArkAbilityRow::ArkAbilitiesProperty) == 32);
#ifndef MOONCRASH
static_assert(sizeof(ArkAbilityCategory) == 64);
static_assert(sizeof(ArkAbilityCategory::ArkNameProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkLabelProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkIconProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkIsAlienProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkRowsProperty) == 32);
static_assert(sizeof(ArkAbilityPDA) == 24);
static_assert(sizeof(ArkAbilityPDA::ArkCategoriesProperty) == 32);
#endif
#ifndef MOONCRASH
static_assert(sizeof(CArkPDAPageAbilities) == 112);
#else
static_assert(sizeof(CArkPDAPageAbilities) == 120);
#endif

#include "arkpdapageaudiologs.h"
static_assert(sizeof(CArkPDAPageAudioLogs) == 64);

#include "arkpdapageemails.h"
static_assert(sizeof(CArkPDAPageEmails) == 40);

#include "arkpdapageequipmentmods.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkPDAPageEquipmentMods) == 152);
#endif

#include "arkpdapagefabricationplans.h"
static_assert(sizeof(CArkPDAFabricationPlans) == 48);

#include "arkpdapageinventory.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkPDAPageInventory) == 1320);
#else
static_assert(sizeof(CArkPDAPageInventory) == 1000);
#endif

#include "arkpdapagekeycodes.h"
static_assert(sizeof(CArkPDAPageKeyCodes) == 16);

#include "arkpdapagelevelmap.h"
static_assert(sizeof(CArkPDAPageLevelMap) == 136);

#include "arkpdapagelore.h"
static_assert(sizeof(CArkPDAPageLore) == 40);

#include "arkpdapagemainmenu.h"
static_assert(sizeof(CArkPDAPageMainMenu) == 16);

#include "arkpdapagemetadata.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkPDAPageMetadata) == 40);
#else
static_assert(sizeof(CArkPDAPageMetadata) == 48);
#endif

#include "arkpdapagenotes.h"
static_assert(sizeof(CArkPDAPageNotes) == 40);

#include "arkpdapageobjectives.h"
static_assert(sizeof(CArkPDAPageObjectives) == 64);

#include "arkpdapagescopechipsets.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkPDAPageScopeChipsets) == 152);
#endif

#include "arkpdapagestationmap.h"
static_assert(sizeof(CArkPDAPageStationMap) == 64);

#include "arkpdapagestatus.h"
static_assert(sizeof(CArkPDAPageStatus) == 40);

#include "arkpdapagesuitchipsets.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkPDAPageSuitChipsets) == 152);
#endif

#include "arkplayerhitdeathui.h"
static_assert(sizeof(CArkPlayerHitDeathUI) == 176);

#include "ArkSubtitleHandler.h"
static_assert(sizeof(ArkSubtitleHandler) == 200);
static_assert(sizeof(ArkSubtitleHandler::ArkBinkSubtitleEntry) == 24);

#include "ArkTutorialCardUI.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTutorialCardUI) == 808);
#else
static_assert(sizeof(ArkTutorialCardUI) == 1064);
#endif

#include "ArkTutorialMenu.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTutorialMenu) == 96);
#else
static_assert(sizeof(ArkTutorialMenu) == 104);
#endif

#include "arkuihud.h"
static_assert(sizeof(ArkLogEntry) == 48);
#ifndef MOONCRASH
static_assert(sizeof(CArkUIHUD) == 936);
#else
static_assert(sizeof(CArkUIHUD) == 1000);
#endif
static_assert(sizeof(CArkUIHUD::VisibleLogEntry) == 64);

#include "ArkUIOptionMenu.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkUIOptionMenu) == 128);
#else
static_assert(sizeof(ArkUIOptionMenu) == 136);
#endif

#include "ArkUIOptionMenuBase.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkUIOptionMenuBase) == 120);
#else
static_assert(sizeof(ArkUIOptionMenuBase) == 128);
#endif

#include "arkuiutil.h"
static_assert(sizeof(UIUtil) == 1);

#include "IArkDebugMenuListener.h"
static_assert(sizeof(IArkDebugMenuListener) == 8);

#include "IArkOptionMenuListener.h"
static_assert(sizeof(IArkOptionMenuListener) == 8);

#include "IArkPauseMenuListener.h"
static_assert(sizeof(IArkPauseMenuListener) == 8);

#include "IArkPDAPage.h"
static_assert(sizeof(IArkPDAPage) == 16);

#include "IArkSaveLoadMenuListener.h"
static_assert(sizeof(IArkSaveLoadMenuListener) == 8);

#include "IArkTutorialMenuListener.h"
static_assert(sizeof(IArkTutorialMenuListener) == 8);

#include "IHUDEventListener.h"
static_assert(sizeof(IHUDEventListener) == 8);

#include "IUIControlSchemeListener.h"
static_assert(sizeof(IUIControlSchemeListener) == 8);

#include "IUIElementEventListener.h"
static_assert(sizeof(IUIElementEventListener) == 8);

#include "IUIEventSystemFactory.h"
static_assert(sizeof(IUIEventSystemFactory) == 16);

#include "IUIGameEventSystem.h"

#include "IUIPseudoRTTI.h"
static_assert(sizeof(IUIPseudoRTTI) == 8);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkActiveUserManagerBase.h"
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arkflownodedialog.h"
static_assert(sizeof(CArkFlowNodeConfirmDialog) == 64);
static_assert(sizeof(CArkFlowNodeNotificationDialog) == 64);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkLeaderboardUI.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkLeaderboardUI) == 984);
static_assert(sizeof(ArkLeaderboardUI::ScorecardEntry) == 24);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkPDAPageChipsets.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkPDAPageChipsets) == 64);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkPDAPageProgress.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkPDAPageProgress) == 40);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkSaveLoadMenu.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkSaveLoadMenu) == 216);
#endif
#endif
