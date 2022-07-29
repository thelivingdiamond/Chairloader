// Header test file for path Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h
#include "ArkBinkPlayerHandle.h"
static_assert(sizeof(ArkBinkPlayerHandle) == 8);

#include "ArkBrightnessMenu.h"
static_assert(sizeof(ArkBrightnessMenu) == 112);

#include "ArkButtonPrompt.h"
static_assert(sizeof(ArkButtonPrompt) == 56);

#include "ArkButtonPromptCollection.h"
static_assert(sizeof(ArkButtonPromptCollection) == 584);

#include "arkexternalinventoryui.h"
static_assert(sizeof(CArkExternalInventoryUI) == 112);
static_assert(sizeof(CArkExternalInventoryUI::TransferNotification) == 40);

#include "ArkFocusModeUIComponent.h"
static_assert(sizeof(ArkFocusModeUIComponent) == 168);

#include "ArkGenderSelectMenu.h"
//static_assert(sizeof(ArkFlowNodeGenderSelectMenu) == 16);
static_assert(sizeof(ArkGenderSelectMenu) == 104);

#include "ArkHackingUI.h"
static_assert(sizeof(ArkHackingUI) == 536);
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
static_assert(sizeof(ArkInputLegend) == 32);
static_assert(sizeof(ArkInputLegend::ArkActionMapProperty) == 32);
static_assert(sizeof(ArkInputLegend::ArkItemsProperty) == 32);
static_assert(sizeof(ArkInputLegendItem) == 80);
static_assert(sizeof(ArkInputLegendItem::ArkActionProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkActionMapProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkLabelProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkHoldProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkComboStringProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkActionListProperty) == 32);
static_assert(sizeof(ArkInputLegendItem::ArkControlSchemeProperty) == 32);

#include "ArkInputLegendHandler.h"
static_assert(sizeof(ArkInputLegendHandler) == 4);

#include "ArkInventoryPreview.h"
static_assert(sizeof(ArkInventoryPreview) == 648);

#include "arkinventoryui.h"
static_assert(sizeof(IArkInventoryUIOwner) == 8);
static_assert(sizeof(CArkInventoryUI) == 88);
static_assert(sizeof(CArkInventoryUI::SelectedWeaponInfo_ModInfo) == 48);
static_assert(sizeof(CArkInventoryUI::SelectedWeaponInfo) == 40);
static_assert(sizeof(CArkInventoryUI::SelectedItemInfo) == 88);

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
static_assert(sizeof(ArkNoteUI) == 656);

#include "ArkOptionDropDownBase.h"
static_assert(sizeof(ArkOptionDropDownBase) == 8);

#include "ArkOptionLayout.h"
static_assert(sizeof(DistractionEvent) == 8);
static_assert(sizeof(DistractionEvent::ArkEventProperty) == 32);
//static_assert(sizeof(ArkAimAssistPoint) == 8);
//static_assert(sizeof(ArkAimAssistPoint::ArkAttachmentNameProperty) == 32);
static_assert(sizeof(ArkOptionLayoutPage) == 32);
static_assert(sizeof(ArkOptionLayoutPage::ArkLabelProperty) == 32);
static_assert(sizeof(ArkOptionLayoutPage::ArkSubPagesProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage) == 64);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkLabelProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkLabelPS4Property) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkAttributesProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkKeybindsProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkPlatformProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkWriteConfigFileProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkRequiresApplyProperty) == 32);
static_assert(sizeof(ArkOptionLayoutSubPage::ArkWarningProperty) == 32);
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
static_assert(sizeof(ArkOptionSubAction) == 8);
static_assert(sizeof(ArkOptionSubAction::ArkActionProperty) == 32);
static_assert(sizeof(ArkOptionWidgetBase) == 8);
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
static_assert(sizeof(ArkOption) == 56);
static_assert(sizeof(ArkOption::ArkLabelProperty) == 32);
static_assert(sizeof(ArkOption::ArkValueProperty) == 32);
static_assert(sizeof(ArkOption::ArkHiddenProperty) == 32);
static_assert(sizeof(ArkOption::ArkSubactionsProperty) == 32);
static_assert(sizeof(ArkDifficultyOption) == 56);
static_assert(sizeof(ArkOptionToggle) == 120);
static_assert(sizeof(ArkOptionToggle::ArkOption0Property) == 32);
static_assert(sizeof(ArkOptionToggle::ArkOption1Property) == 32);
static_assert(sizeof(ArkOptionLayout) == 24);
static_assert(sizeof(ArkOptionLayout::ArkPagesProperty) == 32);
static_assert(sizeof(ArkOptionDropDown) == 32);
static_assert(sizeof(ArkOptionDropDown::ArkOptionsProperty) == 32);
static_assert(sizeof(ArkOptionMonitor) == 32);
static_assert(sizeof(ArkOptionResolution) == 40);
static_assert(sizeof(ArkOptionLanguageBase) == 32);
static_assert(sizeof(ArkOptionAudioLanguage) == 32);
static_assert(sizeof(ArkOptionTextLanguage) == 32);

#include "ArkOptionMenu.h"
static_assert(sizeof(ArkOptionMenu) == 328);
static_assert(sizeof(ArkOptionMenu::RingBuffer) == 68);

#include "ArkOptionMenuBase.h"
static_assert(sizeof(ArkOptionMenuBase) == 104);
static_assert(sizeof(ArkOptionMenuBase::SelectedOption) == 4);

#include "ArkPauseMenu.h"
static_assert(sizeof(ArkScoreCard) == 32);
static_assert(sizeof(ArkScoreCard::ArkGameMetricsProperty) == 32);
static_assert(sizeof(ArkPauseMenu) == 120);

#include "ArkPDAComponent.h"
static_assert(sizeof(ArkPDAComponent) == 896);

#include "arkpdapageabilities.h"
static_assert(sizeof(ArkAbilityCategory) == 64);
static_assert(sizeof(ArkAbilityCategory::ArkNameProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkLabelProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkIconProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkIsAlienProperty) == 32);
static_assert(sizeof(ArkAbilityCategory::ArkRowsProperty) == 32);
static_assert(sizeof(ArkAbilityPDA) == 24);
static_assert(sizeof(ArkAbilityPDA::ArkCategoriesProperty) == 32);
static_assert(sizeof(CArkPDAPageAbilities) == 112);

#include "arkpdapageaudiologs.h"
static_assert(sizeof(CArkPDAPageAudioLogs) == 64);

#include "arkpdapageemails.h"
static_assert(sizeof(CArkPDAPageEmails) == 40);

#include "arkpdapageequipmentmods.h"
static_assert(sizeof(CArkPDAPageEquipmentMods) == 152);

#include "arkpdapagefabricationplans.h"
static_assert(sizeof(CArkPDAFabricationPlans) == 48);

#include "arkpdapageinventory.h"
static_assert(sizeof(CArkPDAPageInventory) == 1320);

#include "arkpdapagekeycodes.h"
static_assert(sizeof(CArkPDAPageKeyCodes) == 16);

#include "arkpdapagelevelmap.h"
static_assert(sizeof(CArkPDAPageLevelMap) == 136);

#include "arkpdapagelore.h"
static_assert(sizeof(CArkPDAPageLore) == 40);

#include "arkpdapagemainmenu.h"
static_assert(sizeof(CArkPDAPageMainMenu) == 16);

#include "arkpdapagemetadata.h"
static_assert(sizeof(CArkPDAPageMetadata) == 40);

#include "arkpdapagenotes.h"
static_assert(sizeof(CArkPDAPageNotes) == 40);

#include "arkpdapageobjectives.h"
static_assert(sizeof(CArkPDAPageObjectives) == 64);

#include "arkpdapagescopechipsets.h"
static_assert(sizeof(CArkPDAPageScopeChipsets) == 152);

#include "arkpdapagestationmap.h"
static_assert(sizeof(CArkPDAPageStationMap) == 64);

#include "arkpdapagestatus.h"
static_assert(sizeof(CArkPDAPageStatus) == 40);

#include "arkpdapagesuitchipsets.h"
static_assert(sizeof(CArkPDAPageSuitChipsets) == 152);

#include "arkplayerhitdeathui.h"
static_assert(sizeof(CArkPlayerHitDeathUI) == 176);

#include "ArkSubtitleHandler.h"
static_assert(sizeof(ArkSubtitleHandler) == 200);
static_assert(sizeof(ArkSubtitleHandler::ArkBinkSubtitleEntry) == 24);

#include "ArkTutorialCardUI.h"
static_assert(sizeof(ArkTutorialCardUI) == 808);

#include "ArkTutorialMenu.h"
static_assert(sizeof(ArkTutorialMenu) == 96);

#include "arkuihud.h"
static_assert(sizeof(CArkUIHUD) == 936);
static_assert(sizeof(CArkUIHUD::VisibleLogEntry) == 64);

#include "ArkUIOptionMenu.h"
static_assert(sizeof(ArkUIOptionMenu) == 128);

#include "ArkUIOptionMenuBase.h"
static_assert(sizeof(ArkUIOptionMenuBase) == 120);

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
static_assert(sizeof(IUIGameEventSystem) == 8);

#include "IUIPseudoRTTI.h"
static_assert(sizeof(IUIPseudoRTTI) == 8);
