//
// Created by theli on 8/1/2022.
//

#include <iostream>
#include <sstream>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <curlpp/cURLpp.hpp>
#include <Chairloader/SemanticVersion.h>
#include <ChairMerger/ChairMerger.h>
#include <ChairMerger/LegacyModConverter.h>
#include <ChairMerger/XMLMerger2.h>
#include <ChairMerger/ZipUtils.h>
#include <Manager/FileHistory.h>
#include <Manager/GamePath.h>
#include <Manager/PreditorFiles.h>
#include <Manager/ModInfo.h>
#include <boost/algorithm/string/predicate.hpp>
#include <WinShell/WinShell.h>
#include <GUIUtils.h>
#include "ChairManager.h"
#include "UI.h"
#include "ChairWizards/GamePathDialog.h"
#include "GameVersion.h"
#include "winver.h"
#include "ChairWizards/ChairUninstallWizard.h"
#include "ChairWizards/NewInstallWizard.h"
#include "BinaryVersionCheck.h"
#include "UpdateHandler.h"
#include "ChairWizards/ChairUpdateWizard.h"
#include "Paths.h"
#include "PreyFilesPatchProgressDialog.h"

static const boost::regex fileNameRegex(R"(^[\w\-. ]+$)");
static std::string ErrorMessage;
static bool showErrorPopup = false;
static bool showDemo = false;

static const char* MAIN_WINDOW_NAME = "Chairloader Mod Manager";

//! Path to the cinematics directory relative to game root.
constexpr char CINEMATICS_PATH[] = "GameSDK/Videos";

//! List of cinematic files.
constexpr const char* CINEMATICS_FILES[] =
{
    "ArkaneLogoAnim_Redux_1080p2997_ST-16LUFS.bk2",
    "Bethesda_logo_anim_white.bk2",
    "LegalScreens.bk2",
    "Ryzen_Bumper.bk2",
};

struct ChairManager::MergerTask
{
    std::unique_ptr<ChairMerger> pMerger;
    std::future<void> future;
};

void ChairManager::Draw() {
    bool bDraw = true;

    switch (m_State)
    {
    case State::MainWindow:
        if(!initialized)
            Init();
        DrawMainWindow(&bDraw);
        break;
    case State::InstallWizard:
        m_pInstallWizard->Update();

        if (m_pInstallWizard->IsFinished())
        {
            if (m_pInstallWizard->IsCancelled())
                bDraw = false;
            else
                OnInstallWizardFinished();
        }

        break;
    case State::UninstallWizard:
        DrawUninstallWizard(&m_bShowUninstallWizard);
        if(!m_bShowUninstallWizard)
            m_State = State::MainWindow;
        break;
    case State::Deploying:
        DrawDeployScreen(&bDraw);
        DrawMainWindow(&bDraw);
        break;
    case State::UpdateWizard:
        DrawUpdateWizard(nullptr);
        break;
    default:
        assert(!("Invalid UI state"));
        std::abort();
        break;
    }

    if (!bDraw)
        UI::RequestExit();
}


void ChairManager::LoadModManagerConfig()
{
    if (ChairManagerConfigFile.load_file(ChairManagerConfigPath.wstring().c_str())) {
        if (ChairManagerConfigFile.first_child().child("PreyPath")) {
            fs::path path(ChairManagerConfigFile.first_child().child("PreyPath").text().as_string());
            if (GamePath::ValidateGamePath(path))
            {
                SetGamePath(path);
            }
        }
        m_githubETag = ChairManagerConfigFile.first_child().child("ETag").text().as_string();
        if(!ChairManagerConfigFile.first_child().child("LaunchOptions"))
            ChairManagerConfigFile.first_child().append_child("LaunchOptions");
        auto launchOptionsNode = ChairManagerConfigFile.first_child().child("LaunchOptions");
        //LoadChairloader
        if(!launchOptionsNode.attribute("LoadChairloader"))
            launchOptionsNode.append_attribute("LoadChairloader").set_value(true);
        m_bLoadChairloader = launchOptionsNode.attribute("LoadChairloader").as_bool();
        //LoadEditor
        if(!launchOptionsNode.attribute("LoadEditor"))
            launchOptionsNode.append_attribute("LoadEditor").set_value(false);
        m_bLoadEditor = launchOptionsNode.attribute("LoadEditor").as_bool();
        //DevMode
        if(!launchOptionsNode.attribute("DevMode"))
            launchOptionsNode.append_attribute("DevMode").set_value(false);
        m_bDevMode = launchOptionsNode.attribute("DevMode").as_bool();
        //NoRandom
        if(!launchOptionsNode.attribute("NoRandom"))
            launchOptionsNode.append_attribute("NoRandom").set_value(false);
        m_bNoRandom = launchOptionsNode.attribute("NoRandom").as_bool();
        //Trainer
        if(!launchOptionsNode.attribute("Trainer"))
            launchOptionsNode.append_attribute("Trainer").set_value(false);
        m_bTrainer = launchOptionsNode.attribute("Trainer").as_bool();
    }
    else {
        log(severityLevel::error, "ChairManager config file not found, creating new");
        ChairManagerConfigFile.reset();
        ChairManagerConfigFile.append_child("ChairManager");
        ChairManagerConfigFile.first_child().append_child("PreyPath").text().set(GetGamePath().wstring().c_str());
        ChairManagerConfigFile.first_child().append_child("ETag").text().set(m_githubETag.c_str());
        auto launchOptionsNode = ChairManagerConfigFile.first_child().append_child("LaunchOptions");
        launchOptionsNode.append_attribute("LoadChairloader").set_value(true);
        launchOptionsNode.append_attribute("LoadEditor").set_value(false);
        launchOptionsNode.append_attribute("DevMode").set_value(true);
        launchOptionsNode.append_attribute("NoRandom").set_value(false);
        launchOptionsNode.append_attribute("AugGeom").set_value(false);
        launchOptionsNode.append_attribute("Trainer").set_value(false);
        ChairManagerConfigFile.save_file(ChairManagerConfigPath.wstring().c_str());
    }
    log(severityLevel::info, "ChairManager Config File Loaded");
}

void ChairManager::SetGamePath(const fs::path& path)
{
    CRY_ASSERT(path.empty() || ChairManager::Get().GetGamePathUtil().ValidateGamePath(path));

    m_GamePath.SetGamePath(path);
    pugi::xml_node cfg = ChairManagerConfigFile.first_child();

    if (!path.empty())
    {
        if (cfg.child("PreyPath"))
            cfg.child("PreyPath").text().set(path.u8string().c_str());
        else
            cfg.append_child("PreyPath").text().set(path.u8string().c_str());
    }
    else
    {
        cfg.remove_child("PreyPath");
    }
}

void ChairManager::SwitchToInstallWizard()
{
    CRY_ASSERT(!m_pInstallWizard);
    m_pInstallWizard = std::make_unique<NewInstallWizard>(this);
    m_State = State::InstallWizard;
}

void ChairManager::OnInstallWizardFinished()
{
    log(severityLevel::info, "Install wizard has finished");
    CRY_ASSERT(m_pInstallWizard);
    m_pInstallWizard.reset();

    log(severityLevel::info, "Chairloader version %s installed, %s is packaged with this installer, %s is the latest version on github",
        VersionCheck::getInstalledChairloaderVersion().String(),
        VersionCheck::getPackagedChairloaderVersion().String(),
        VersionCheck::getLatestChairloaderVersion().String());

    if (IsUpdateAvailable())
        m_bShowUpdatePopup = true;

    m_State = State::MainWindow;
}

void ChairManager::DrawMainWindow(bool* pbIsOpen)
{
    m_pGameVersion->Update();

    ImGuiWindowFlags windowFlags =
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_MenuBar;

    const ImVec2 mainWindowSize = {800, 500};
    ImGui::SetNextWindowSize({ mainWindowSize.x * dpiScale, mainWindowSize.y * dpiScale});
    ImGui::SetNextWindowBgAlpha(1.0f);
    // ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    // ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));
    if (!ImGui::Begin(MAIN_WINDOW_NAME, pbIsOpen, windowFlags))
    {
        ImGui::End();
    }
    auto temp = ImGui::GetWindowViewport()->DpiScale;
    if(ImGui::GetWindowViewport()->DpiScale != dpiScale){
        dpiScale = ImGui::GetWindowViewport()->DpiScale;
        updateDPIScaling = true;
    }

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Files", true)) {
            if (ImGui::MenuItem("Install Mod")) {
                OpenInstallModDialog();
            }
            ImGui::Separator();
            if(ImGui::MenuItem("Uninstall Chairloader")){
                SwitchToUninstallWizard();
            }
#ifdef DEBUG_BUILD
            ImGui::Separator();
            ImGui::MenuItem("Show Demo Window", nullptr, &showDemo);
#endif
            ImGui::EndMenu();
        }
        //Create a menu for mod list
        if (ImGui::BeginMenu("Mods", true)) {
            //Reload Mods
            if (ImGui::MenuItem("Reload Mods")) {
                LoadModInfoFiles();
            }
            // Save Config
            if (ImGui::MenuItem("Save Config")) {
                overlayLog(severityLevel::info, "Mod list saved");
                saveChairloaderConfigFile();
            }
            if(ImGui::MenuItem("Deploy Mods")){
                SwitchToDeployScreen();
            }
            ImGui::EndMenu();
        }
        // Print test overlay log messages for each severity level
#ifdef DEBUG_BUILD
        if (ImGui::BeginMenu("Log", true)) {
            if (ImGui::MenuItem("Info")) {
                overlayLog(severityLevel::info, "Info");
            }
            if (ImGui::MenuItem("Warning")) {
                overlayLog(severityLevel::warning, "Warning");
            }
            if (ImGui::MenuItem("Error")) {
                overlayLog(severityLevel::error, "Error");
            }
            if (ImGui::MenuItem("Trace")) {
                overlayLog(severityLevel::trace, "Trace");
            }
            ImGui::EndMenu();
        }
#endif
        if(ImGui::BeginMenu("Utils")){
            if(ImGui::MenuItem("Remove Intro Videos")){
                removeStartupCinematics();
            }
            if(ImGui::MenuItem("Restore Intro Videos")){
                restoreStartupCinematics();
            }
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Help")){
            // Legacy Mods
            if(ImGui::BeginMenu("Help Information")) {
                ImGui::Text("Legacy Mods");
                ImGui::SameLine();
                ImGuiUtils::HelpMarker(
                        "Legacy mods are mods that weren't made for Chairloader, such as older mods that only had asset files. They do not have ModInfo.xml files and as such are not registered with the other mods.");
                //Load Order
                ImGui::Text("Load Order");
                ImGui::SameLine();
                ImGuiUtils::HelpMarker(
                        "The load order is the order in which the mods are loaded and their assets are merged. This means that mods with a higher load order will overwrite mods with a lower load order.");
                // Version Check
                ImGui::EndMenu();
            }
            ImGui::Separator();
            if(ImGui::MenuItem("Check for Updates")){
                m_bShowUpdatePopup = true;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    if(m_bShowUpdatePopup){
        ImGui::OpenPopup("Check for Updates");
        m_bShowUpdatePopup = false;
    }
    if(ImGui::BeginPopupModal("Check for Updates", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize)){
        if(IsUpdateAvailable()){
            ImGui::Text("Chairloader is out of date!");
            ImGui::Text("Installed: %s", VersionCheck::getInstalledChairloaderVersion().String().c_str());
            ImGui::Text("Latest: %s", VersionCheck::getLatestChairloaderVersion().String().c_str());
            ImGui::Text("Downloaded: %s", VersionCheck::getPackagedChairloaderVersion().String().c_str());
            if(ImGui::Button("Update Chairloader")){
                SwitchToUpdateWizard();
            }
        } else {
            ImGui::Text("Chairloader is up to date!");
            ImGui::Text("Installed: %s", VersionCheck::getInstalledChairloaderVersion().String().c_str());
            ImGui::Text("Latest: %s", VersionCheck::getLatestChairloaderVersion().String().c_str());
            ImGui::Text("Downloaded: %s", VersionCheck::getPackagedChairloaderVersion().String().c_str());
            if(ImGui::Button("Force Check For Update")){
                VersionCheck::fetchLatestVersion(true);
            }
        }
        if(ImGui::Button("Close")){
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
    if (ImGui::BeginTabBar("##Mod Tab Bar")) {
        DrawModList();
        //TODO: figure out if these will do anything
//        DrawDeploySettings();
//        DrawDLLSettings();
        m_ConfigManager.draw();
        DrawAssetView();
        DrawLog();
        DrawDLLSettings();
#ifdef DEBUG_BUILD
        DrawDebug();
#endif
        ImGui::EndTabBar();
        if (showErrorPopup) {
            ImGui::OpenPopup("Error");
            showErrorPopup = false;
        }
        if (ImGui::BeginPopupModal("Error", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize)) {
            ImGui::Text("%s", ErrorMessage.c_str());
            if (ImGui::Button("Close")) {
                ImGui::CloseCurrentPopup();
            }
            ImGui::EndPopup();
        }
    }
    DrawOverlayLog();
    if (showDemo) {
        ImGui::ShowDemoWindow(&showDemo);
    }

    UpdateModInstall();

    std::sort(ModList.begin(), ModList.end());
    ImGui::End();
}

void ChairManager::DrawModList() {
    static std::string selectedMod;
    static bool showDeleteConfirmation;

    bool sortModList = false; // If true, mod list will be sorted after iteration

    if (ImGui::BeginTabItem("Mod List")) {
        if (ImGui::BeginChild("Mod List", ImVec2(ImGui::GetContentRegionAvail().x * 0.65f, 0))) {
            float checkboxColumnSize = 0.0f;
            std::string modNameForDeletion; // If not empty, will be removed after all mods are displayed.

            if (ImGui::BeginTable("Mod List", 5, ImGuiTableFlags_Borders | ImGuiTableFlags_SizingStretchProp |
                ImGuiTableFlags_NoBordersInBody)) {
                ImGui::TableSetupColumn("##Enable/Disable", ImGuiTableColumnFlags_WidthFixed);
                ImGui::TableSetupColumn("Mod Name");
                ImGui::TableSetupColumn("Version", ImGuiTableColumnFlags_WidthFixed,
                    ImGui::CalcTextSize("Version").x + 16.0f);
                ImGui::TableSetupColumn("Order", ImGuiTableColumnFlags_WidthFixed,
                    ImGui::CalcTextSize("Order").x + 16.0f);
                ImGui::TableHeadersRow();
                if (selectedMod.empty() && !ModList.empty()) {
                    selectedMod = ModList.at(0).modName;
                }
                int i = 0;
                for (Mod& ModEntry : ModList) {
                    ImGui::PushID(&ModEntry);
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();

                    if (verifyDependenciesEnabled(ModEntry.modName)) {
                        ImGui::Checkbox("##Enable", &ModEntry.enabled);
                    }
                    checkboxColumnSize = ImGui::GetColumnWidth();
                    ImGui::TableNextColumn();
                    ImVec2 SelectableSize = { 0, /*ImGui::GetTextLineHeightWithSpacing() + 4.0f*/0 };
                    auto storedpos = ImGui::GetCursorPosY() + (4 * dpiScale);
                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - (3.5 * dpiScale));

                    if (ImGui::Selectable("##Selectable",
                        selectedMod == ModEntry.modName, 0,
                        ImVec2{ ImGui::GetColumnWidth(), ImGui::GetFrameHeight() - 2.0f * dpiScale }))
                    {
                        selectedMod = ModEntry.modName;
                        ModEntry.isNew = false;
                    }

                    if (ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
                        ImGui::OpenPopup("Mod Actions");
                    }
                    ImGui::SetCursorPosY(storedpos);
                    if (!verifyDependenciesEnabled(ModEntry.modName))
                        ModEntry.enabled = false;

                    if (ModEntry.enabled) {
                        ImGui::TextColored(ImGui::GetStyleColorVec4(ImGuiCol_Text), "%s",
                            ModEntry.displayName.c_str());
                        //                            if (ImGui::Selectable(ModEntry.modName.c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
                        //                                selectedMod = ModEntry.modName;
                    }
                    else {
                        //                            ImGui::PushStyleColor(ImGuiCol_Text,ImColor(180,180,180).operator ImU32());
                        //                            if (ImGui::Selectable(ModEntry.modName.c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
                        //                                selectedMod = ModEntry.modName;
                        //                            ImGui::PopStyleColor();
                        if (verifyDependencies(ModEntry.modName)) {
                            if (verifyDependenciesEnabled(ModEntry.modName)) {
                                ImGui::TextColored(ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled), "%s",
                                    ModEntry.displayName.c_str());
                                if (ImGui::IsItemHovered()) {
                                    ImGui::BeginTooltip();
                                    ImGui::Text("Mod is not enabled");
                                    ImGui::EndTooltip();
                                }
                            }
                            else {
                                ImGui::TextColored(warningColor, "%s",
                                    ModEntry.displayName.c_str());
                                if (ImGui::IsItemHovered()) {
                                    ImGui::BeginTooltip();
                                    ImGui::Text("Dependencies are installed, but not enabled");
                                    ImGui::EndTooltip();
                                }
                            }

                        }
                        else {
                            ImGui::TextColored(errorColor, "%s",
                                ModEntry.displayName.c_str());
                            if (ImGui::IsItemHovered()) {
                                ImGui::BeginTooltip();
                                ImGui::Text("Dependencies not found");
                                ImGui::EndTooltip();
                            }
                        }
                    }

                    if (ImGui::BeginPopup("Mod Actions")) {
                        ImGui::Text("%s:", ModEntry.displayName.c_str());
                        ImGui::BeginDisabled();
                        bool hasDll = !ModEntry.dllName.empty();
                        ImGui::Checkbox("Has DLL", &hasDll);
                        ImGui::SameLine();
                        ImGui::Checkbox("Has XML", &ModEntry.hasXML);
                        ImGui::EndDisabled();

                        if (ImGui::Button("Uninstall")) {
                            UninstallMod(ModEntry.modName);
                        }
                        if (ModEntry.enabled) {
                            if (ImGui::Button("Disable"))
                                EnableMod(ModEntry.modName, false);
                        }
                        else {
                            if (ImGui::Button("Enable"))
                                EnableMod(ModEntry.modName, true);
                        }

                        ImGui::EndPopup();
                    }
                    if (showDeleteConfirmation) {
                        ImGui::OpenPopup("Delete Confirmation");
                        showDeleteConfirmation = false;
                    }

                    if (ImGui::BeginPopupModal("Delete Confirmation")) {
                        ImGui::Text("Are you sure you want to delete %s?\nConfig data will be preserved.",
                            ModEntry.modName.c_str());
                        if (ImGui::Button("Delete")) {
                            if (!ModEntry.modName.empty()) {
                                modNameForDeletion = ModEntry.modName;
                            }
                            ImGui::CloseCurrentPopup();
                        }
                        ImGui::SameLine();
                        if (ImGui::Button("Cancel")) {
                            ImGui::CloseCurrentPopup();
                        }
                        ImGui::EndPopup();
                    }
                    ImGui::TableNextColumn();
                    ImGui::Text("%s", ModEntry.version.c_str());
                    ImGui::TableNextColumn();
                    ImGui::Text("%i", ModEntry.loadOrder + 1);

                    i++;

                    ImGui::PopID();
                }

                ImGui::EndTable();
            }

            if (!modNameForDeletion.empty())
            {
                log(severityLevel::info, "Deleting %s/Mods/%s/", GetGamePath().u8string(), modNameForDeletion);
                fs::remove_all(GetGamePath() / "Mods" / modNameForDeletion);
                ModList.erase(std::find(ModList.begin(), ModList.end(), modNameForDeletion));
                modNameForDeletion.clear();
            }
        }
        ImGui::EndChild();
        ImGui::SameLine();
        if (ImGui::BeginChild("Controls")) {
            if (ImGui::Button("Refresh Mod List")) {
                LoadModInfoFiles();
                selectedMod.clear();
                m_ConfigManager.saveDirtyConfigs();
                m_ConfigManager.init(this);
            }
            ImGui::SameLine();
            ImGuiUtils::HelpMarker("Loads mod list from the Chairloader config file. Also discovers new mods in the Mods/ folder.");
            ImGui::SameLine();
            if (ImGui::Button("Enable All")) {
                for (auto& mod : ModList) {
                    EnableMod(mod.modName);
                    // if dependencies aren't installed then those mods will disable themselves later
                }
            }
            ImGui::Separator();
            if (ImGui::BeginChild("Mod Info", { 0, ImGui::GetContentRegionAvail().y * 0.61f })) {
                auto ModSelect = std::find(ModList.begin(), ModList.end(), selectedMod);
                if (ModSelect != ModList.end()) {
                    ImGui::TextWrapped("%s", ModSelect->displayName.c_str());
                    ImGui::Text("By: %s", ModSelect->author.c_str());
                    //                    if(ImGui::Button("Config")){
                    //                        m_ConfigManager.showConfigPopup(ModSelect->modName);
                    //                    }

                    // Load order
                    {
                        ImGui::Separator();
                        ImGui::Text("Load Order:");
                        size_t selectedModIdx = ModSelect - ModList.begin();

                        ImGui::BeginDisabled(ModSelect->loadOrder <= 0);
                        if (ImGui::ArrowButton("##Up", ImGuiDir_Up)) {
                            std::swap(ModList.at(selectedModIdx - 1).loadOrder, ModList.at(selectedModIdx).loadOrder);
                            sortModList = true;
                        }
                        ImGui::EndDisabled();
                        ImGui::SameLine();

                        ImGui::BeginDisabled(ModSelect->loadOrder >= ModList.size());
                        if (ImGui::ArrowButton("##Down",
                            ImGuiDir_Down)) {
                            std::swap(ModList.at(selectedModIdx).loadOrder, ModList.at(selectedModIdx + 1).loadOrder);
                            sortModList = true;
                        }
                        ImGui::EndDisabled();
                    }

                    if (!ModSelect->dependencies.empty()) {
                        ImGui::Separator();
                        ImGui::Text("Dependencies:");
                        for (auto& dependency : ModSelect->dependencies) {
                            auto dependencySearch = std::find(ModList.begin(), ModList.end(), dependency);
                            if (dependencySearch == ModList.end())
                                ImGui::PushStyleColor(ImGuiCol_Text, errorColor.operator ImU32());
                            else if (!dependencySearch->enabled)
                                ImGui::PushStyleColor(ImGuiCol_Text, warningColor.operator ImU32());
                            if (ImGui::TreeNode(dependency.c_str())) {
                                if (dependencySearch != ModList.end()) {
                                    if (dependencySearch->enabled) {
                                        ImGui::Text("Version Installed: %s", dependencySearch->version.c_str());
                                    }
                                    else {
                                        ImGui::Text("Dependency not enabled");
                                    }
                                }
                                else {
                                    ImGui::Text("Dependency not found");
                                }
                                ImGui::TreePop();
                            }
                            if (dependencySearch == ModList.end())
                                ImGui::PopStyleColor();
                            else if (!dependencySearch->enabled)
                                ImGui::PopStyleColor();
                        }
                    }
                }
            }
            ImGui::EndChild();
            //            ImGui::SetCursorPosY(ImGui::GetWindowSize().y -100);
            if (ImGui::Button("Save Mod List")) {
                SaveAllMods();
                overlayLog(severityLevel::info, "Mod list saved");
            }
            ImGui::SameLine();
            ImGuiUtils::HelpMarker("Save the mod list to the chairloader.xml config file");
            if (ImGui::Button("Deploy Mods")) {
                SwitchToDeployScreen();
            }
            ImGui::SameLine();
            ImGuiUtils::HelpMarker("Merge, patch, and copy the files to the game directory.");
            ImGui::Separator();
            if (ImGui::Button("Install Mod From File")) {
                OpenInstallModDialog();
            }
            ImGui::Separator();
            if (ImGui::Button("Options")) {
                ImGui::OpenPopup("Launch Options");
            }
            ImGui::SameLine();
            if (ImGui::Button("Launch Prey")) {
                launchGame();
            }
        }
        if (ImGui::BeginPopupContextWindow("Launch Options")) {
            // bool m_bLoadChairloader,
            //        m_bLoadEditor,
            //        m_bDevMode,
            //        m_bNoRandom;
            if (ImGui::Checkbox("Load Chairloader", &m_bLoadChairloader)) {
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("LoadChairloader").set_value(m_bLoadChairloader);
                saveModManagerConfigFile();
            }
            if (ImGui::Checkbox("Load Trainers", &m_bTrainer)) {
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("Trainer").set_value(m_bTrainer);
                saveModManagerConfigFile();
            }
            if (ImGui::Checkbox("Load Editor", &m_bLoadEditor)) {
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("LoadEditor").set_value(m_bLoadEditor);
                saveModManagerConfigFile();
            }
            if (ImGui::Checkbox("Dev Mode", &m_bDevMode)) {
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("DevMode").set_value(m_bDevMode);
                saveModManagerConfigFile();
            }
            if (ImGui::Checkbox("No Random", &m_bNoRandom)) {
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("NoRandom").set_value(m_bNoRandom);
                saveModManagerConfigFile();
            }
            ImGui::InputText("Custom Launch Options", &m_customArgs);
            ImGui::EndPopup();
        }

        ImGui::EndChild();
        ImGui::EndTabItem();
    }

    if (sortModList)
    {
        std::sort(ModList.begin(), ModList.end());
    }
}

void ChairManager::DrawDLLSettings() {
    if(ImGui::BeginTabItem("Settings")){
        auto preyPathString = GetGamePath().u8string();
        ImGui::InputText("Prey Path", &preyPathString, ImGuiInputTextFlags_ReadOnly);

        if(ImGui::Button("Change Path")){
            SetGamePath(fs::path());
            SwitchToInstallWizard();
        }

        ImGui::PushID("GameVersion");
        m_pGameVersion->ShowInstalledVersion();
        ImGui::PopID();

        ImGui::BeginDisabled(m_pXmlPatchDialog != nullptr);
        if (ImGui::Button("Force-refresh base patches"))
        {
            m_pXmlPatchDialog = std::make_unique<PreyFilesPatchProgressDialog>(this);
            m_pXmlPatchDialog->Start();
            ImGui::OpenPopup("XML Patch Progress");
        }
        ImGui::EndDisabled();

        if (m_pXmlPatchDialog)
        {
            if (ImGui::BeginPopupModal("XML Patch Progress"))
            {
                if (!m_pXmlPatchDialog->ShowUI())
                    m_pXmlPatchDialog.reset();
                ImGui::EndPopup();
            }
        }

        ImGui::EndTabItem();
    }
}

void ChairManager::DrawAssetView() {
    if(ImGui::BeginTabItem("Asset View")){
        if(ImGui::BeginChild("Asset List", ImVec2(ImGui::GetContentRegionAvail().x * 0.65f, 0), false)) {
            if(ImGui::BeginTabBar("Mod Asset View")) {
                if(ImGui::BeginTabItem("Registered Mods")) {
                    if (ImGui::BeginChild("Registered Mods", ImVec2(0, 0), true)) {
                    ImGui::Text("Registered Mods");
                    ImGui::Separator();
                        if (ImGui::BeginTable("Registered Mod Tree Nodes", 1,
                                              ImGuiTableFlags_NoBordersInBody | ImGuiTableFlags_ScrollY)) {
                            for (auto &mod: ModList) {
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                TreeNodeWalkDirectory("", mod.modName, XMLFile::XMLType::Registered);
                            }
//                }
                            ImGui::EndTable();
                        }
                    }
                    ImGui::EndChild();
                    ImGui::EndTabItem();
                }

                if(ImGui::BeginTabItem("Base Assets")) {
                    if (ImGui::BeginChild("Base Assets", ImVec2(0, 0), true)) {
                        ImGui::Text("Base Assets");
                        ImGui::Separator();
                        TreeNodeWalkDirectory("", "Prey Files", XMLFile::XMLType::BaseGame);
                    }
                    ImGui::EndChild();
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
        }
        ImGui::EndChild();
        ImGui::SameLine();
        //TODO: figure out more things to do with selected files
        if(ImGui::BeginChild("Selected File Window")){
            if(ImGui::Button("Deselect")){
                selectedFile = {};
            }
            if(!selectedFile.empty()){
                ImGui::Text("%s", selectedFile.path.filename().u8string().c_str());
                if(selectedFile.path.extension() == ".xml"){
                    if(ImGui::BeginChild("XML File Properties"), ImVec2(ImGui::GetContentRegionAvail().y * 0.5f, 0), true){
                        ImGui::Text("XML Merging Policy:");
                        ImGui::Separator();
//                    ImGui::TextWrapped("%s", selectedFile.path.u8string().c_str());
                        // auto policy = m_pChairMerger->GetFileMergingPolicy(selectedFile.relativePath);
                        auto policy = MergingPolicy();
                        static pugi::xml_document doc;
                        pugi::xml_parse_result result = doc.load_file(selectedFile.path.u8string().c_str());
                        auto firstNode = doc.first_child();
                        XMLMerger2::ResolvePolicyPathWildcards(firstNode, policy.nodeStructure);
                        switch (policy.policy) {
                            case MergingPolicy::identification_policy::error:
                                ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Error");
                                break;
                            case MergingPolicy::identification_policy::unknown:
                                ImGui::Text("Unknown");
                                ImGui::SameLine();
                                ImGuiUtils::HelpMarker(
                                        "This file is not registered with the merging library. It will be copied to the output directory as-is. This file cannot be merged with other mods.");
                                break;
                            case MergingPolicy::identification_policy::overwrite:
                                ImGui::Text("Overwrite");
                                ImGui::SameLine();
                                ImGuiUtils::HelpMarker(
                                        "This file will overwrite the same file in the output directory. This file cannot be merged with other mods.");
                                break;
                            case MergingPolicy::identification_policy::match_tag:
                                ImGui::Text("Match Tag");
                                ImGui::SameLine();
                                ImGuiUtils::HelpMarker(
                                        "This file will be merged. The merging policy is based on the tag (name) of each node set to be merged");
                                displayXmlNode(policy.nodeStructure, 0);
                                break;
                            case MergingPolicy::identification_policy::match_attribute:
                                ImGui::Text("Match Attribute");
                                ImGui::SameLine();
                                ImGuiUtils::HelpMarker("This file will be merged. The merging policy is based on the value of specific attributes of each node set to be merged");
                                displayXmlNode(policy.nodeStructure, 0);
                                ImGui::Indent(10.0f);
                                if(ImGui::TreeNode("Attributes to Match")){
                                    for(auto &attribute: policy.attributeMatches){
                                        ImGui::Text("%s: %d", attribute.attribute_name.c_str(), attribute.priority);
                                    }
                                    ImGui::TreePop();
                                }
                                break;
                            case MergingPolicy::identification_policy::match_spreadsheet:
                                ImGui::Text("Match Spreadsheet");
                                ImGui::SameLine();
                                ImGuiUtils::HelpMarker(
                                        "This file will be merged. This is a special mode for Excel spreadsheet XML Files. They will be matched based on the first column of each row.");
                                break;
                            case MergingPolicy::identification_policy::match_contents:
                                ImGui::Text("Match Contents");
                                ImGui::SameLine();
                                ImGuiUtils::HelpMarker(
                                        "This file will be merged. The merging policy is based on the contents of each node set to be merged");
                                break;
                            default:
                                break;
                        }
                    }
                    ImGui::EndChild();
//                    ImGui::Text("%d", policy.policy);
                }
            }
        }
        ImGui::EndChild();
        ImGui::EndTabItem();
    }
}

void ChairManager::DrawDeploySettings() {
    if(ImGui::BeginTabItem("Deploy")){
        static std::string BasePath = R"(C:\Program Files (x86)\Steam\steamapps\common\Prey\Mods\ExampleMod\MergeTest.xml)";
        static std::string OverridePath = R"(C:\Program Files (x86)\Steam\steamapps\common\Prey\Mods\ExampleMod\MergeTestOverride.xml)";
        static std::string OriginalPath = R"(C:\Program Files (x86)\Steam\steamapps\common\Prey\Mods\ExampleMod\ArkOriginal.xml)";
        static pugi::xml_document BaseDoc;
        static pugi::xml_document OverrideDoc;
        static pugi::xml_document OriginalDoc;
        ImGui::InputText("Base Path", &BasePath);
        ImGui::InputText("Override Path", &OverridePath);
        ImGui::InputText("Original Path", &OriginalPath);
        if(ImGui::Button("Load Docs")) {
            auto baseResult = BaseDoc.load_file(BasePath.c_str());
            auto overrideResult = OverrideDoc.load_file(OverridePath.c_str());
            auto originalResult = OriginalDoc.load_file(OriginalPath.c_str());
//            log(severityLevel::debug, "base: %s", baseResult.description());
//            log(severityLevel::debug, "override: %s", overrideResult.description());
//            log(severityLevel::debug, "original: %s", originalResult.description());
        }
//        if(ImGui::Button("Test Merge")) {
//            mergeXMLDocument(BasePath, OverridePath, OriginalPath, std::string());
//        }
        if(ImGui::Button("Save Copy")){
//            log(severityLevel::debug, "Save Result: %i", BaseDoc.save_file(R"(C:\Program Files (x86)\Steam\steamapps\common\Prey\Mods\ExampleMod\MergeTest_NEW.xml)"));
        }
        ImGui::EndTabItem();
    }
}

void ChairManager::DrawLog() {
    logMutex.lock();
    static bool m_bAutoScroll = true;
    if(ImGui::BeginTabItem("Log")){
        static std::vector<std::string> filterNames = {"trace", "debug", "info", "warning", "error", "fatal"};
        ImGui::SetNextItemWidth(ImGui::GetWindowWidth() * 0.25f);
        if(ImGui::BeginCombo("Filter Level", filterNames.at((int)filterLevel).c_str())){
            int i = 0;
            for(auto & filter: filterNames){
                if(ImGui::Selectable(filter.c_str(), (int)filterLevel == i)){
                    filterLevel = (severityLevel)i;
                }
                i++;
            }
            ImGui::EndCombo();
        }
        ImGui::SameLine();
        if(ImGui::Button("Clear Log")){
            logRecord.clear();
        }
        ImGui::SameLine();
        ImGui::Checkbox("Auto Scroll", &m_bAutoScroll);
//        static int count = 0;
//        if(ImGui::Button("Test Overlay")){
//            std::string test;
//            if(count % 2 == 0) {
//                test = "Mod list saved";
//            } else {
//                 test = "Mod list loaded";
//            }
////            overlayQueue.emplace_back(LogEntry(test, severityLevel::info));
//            overlayLog(severityLevel::info, "%s", test);
//            count++;
//        }
//        ImGui::SameLine();
//        ImGui::Text("Overlay Queue: %llu", overlayQueue.size());
        if(ImGui::BeginChild("Log List", {0,0}, true))
        {
            if(ImGui::BeginTable("Log Record", 1, ImGuiTableFlags_NoBordersInBody)) {
                ImGui::TableSetupColumn("message");
                for (auto &entry: logRecord) {
                    if(entry.level >= filterLevel) {
                        std::string level;
                        switch (entry.level) {
                            case severityLevel::trace:
                                level = "trace";
                                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(150, 150, 150).operator ImU32());
                                break;
                            case severityLevel::debug:
                                level = "debug";
                                ImGui::PushStyleColor(ImGuiCol_Text, debugColor.operator ImU32());
                                break;
                            default:
                            case severityLevel::info:
                                level = "info";
                                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 255, 255).operator ImU32());
                                break;
                            case severityLevel::warning:
                                level = "warning";
                                ImGui::PushStyleColor(ImGuiCol_Text, warningColor.operator ImU32());
                                break;
                            case severityLevel::error:
                                level = "error";
                                ImGui::PushStyleColor(ImGuiCol_Text, errorColor.operator ImU32());
                                break;
                            case severityLevel::fatal:
                                level = "fatal";
                                ImGui::PushStyleColor(ImGuiCol_Text, errorColor.operator ImU32());
                                break;
                        }
                        ImGui::TableNextColumn();
                        ImGui::TextWrapped("%s: [%s] %s", entry.timeStamp.c_str(), level.c_str(), entry.message.c_str());
                        ImGui::PopStyleColor();
                        ImGui::TableNextRow();
                    }
                }
//                if(m_bAutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()){
//                    ImGui::SetScrollY(ImGui::GetScrollMaxY());
//                }
//                ImGui::SetScrollY(ImGui::GetScrollMaxY());
                if(m_bAutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
                    ImGui::SetScrollHereY(0.0f);
                ImGui::EndTable();
            }
        }
        ImGui::EndChild();
        ImGui::EndTabItem();
    }
    logMutex.unlock();
}



fs::path ChairManager::getConfigPath(std::string &modName) {
    return GetGamePath() / "Mods/config" / fs::u8path(modName + ".xml");
}

fs::path ChairManager::getDefaultConfigPath(std::string &modName) {
    return GetGamePath() / "Mods" / modName / fs::u8path(modName + "_default.xml");
}
bool ChairManager::LoadModInfoFile(fs::path directory, Mod *mod, bool allowDifferentDirectory) {
    std::string directoryName = directory.filename().u8string();
    pugi::xml_document result;
    auto loadResult  = result.load_file((directory / "ModInfo.xml").wstring().c_str());
    log(severityLevel::trace, "Mod Info File location: %s/ModInfo.xml", directory.u8string().c_str());
    if(loadResult){
        std::string modName = result.child("Mod").attribute("modName").as_string();
        if(!modName.empty()) {
            // Validate mod name
            for (char c : modName)
            {
                bool validChar = (c >= 'a' && c <= 'z') ||
                    (c >= 'A' && c <= 'Z') ||
                    (c >= '0' && c <= '9') ||
                    c == '.' || c == '_' || c == '-';
                if (!validChar)
                {
                    log(severityLevel::error, "%s: Invalid ModInfo.xml: Illegal chars in mod name '%s'", directoryName, modName);
                    return false;
                }
            }

            // Mod name must match its directory
            //! allowDifferentDirectory is only used for the install mod from file function
            if (directoryName != modName && !allowDifferentDirectory)
            {
                log(severityLevel::error, "%s: Mod name '%s' doesn't match directory name '%s'",
                    directoryName, modName, directoryName);
                return false;
            }

            mod->modName = modName;
            mod->displayName = result.child("Mod").attribute("displayName").as_string();

            if (mod->displayName.empty())
            {
                mod->displayName = modName;
                log(severityLevel::warning, "%s: Empty display name", modName.c_str());
            }

            mod->version = result.child("Mod").attribute("version").as_string();
            mod->author = result.child("Mod").attribute("author").as_string();
            mod->dllName = result.child("Mod").attribute("dllName").as_string();
            mod->hasXML = result.child("Mod").attribute("hasXML").as_bool();
            mod->hasLevelXML = result.child("Mod").attribute("hasLevelXML").as_bool();

            mod->path = directory;

            for(auto & dependency : result.child("Mod").child("Dependencies")){
                mod->dependencies.emplace_back(dependency.text().get());
            }
            return true;
        }
        else {
            log(severityLevel::error, "%s: - 'Invalid ModInfo.xml: Could not read Mod Name'", directoryName);

        }
    } else {
        log(severityLevel::warning, "ModInfo.xml failed to load in %s - Reason: %s", directoryName, loadResult.description());
    }
    return false;
}

void ChairManager::LoadModInfoFiles()
{
    ModList.clear();
    fs::path modsDir = GetGamePath() / "Mods";
    fs::path legacyModsDir = modsDir / "Legacy";

    // Add Chairloader modes
    if (fs::is_directory(modsDir))
    {
        for (auto& directory : fs::directory_iterator(modsDir))
        {
            if (!directory.is_directory())
                continue;

            fs::path modDirPath = directory.path();
            std::string modDirName = modDirPath.filename().u8string();

            try
            {

                // Skip non-mod directories
                if (boost::iequals(modDirName, "config") ||
                    boost::iequals(modDirName, ".temp") ||
                    boost::iequals(modDirName, "Legacy"))
                    continue;

                Mod mod;

                if (!LoadModInfoFile(directory.path(), &mod, false))
                {
                    log(severityLevel::error, "Failed to load mod %s", modDirName);
                    continue;
                }

                ModList.emplace_back(std::move(mod));
            }
            catch (const std::exception& e)
            {
                log(severityLevel::error, "Failed to load mod %s: %s", modDirName, e.what());
            }
        }
    }

    // Add Preditor projects
    if (fs::exists(PREDITOR_PROJECT_HISTORY_FILE_PATH))
    {
        std::vector<std::string> preditorHistory = FileHistory::ReadHistory(PREDITOR_PROJECT_HISTORY_FILE_PATH);

        for (const std::string& projectPathStr : preditorHistory)
        {
            Mod mod;
            fs::path projectPath = fs::u8path(projectPathStr);

            if (!fs::is_directory(projectPath))
                continue;

            try
            {

                if (!LoadModInfoFile(projectPath, &mod, true))
                {
                    log(severityLevel::info, "Invalid Preditor project: '%s'", projectPathStr);
                    continue;
                }

                // See if the same directory was already added
                bool foundDir = std::find_if(ModList.begin(), ModList.end(), [&](const Mod& i) { return fs::equivalent(i.path, projectPath); }) != ModList.end();
                if (foundDir)
                {
                    log(severityLevel::info, "Preditor project aready added: '%s'", projectPathStr);
                    continue;
                }

                // Add prefix to differentiate from actually installed mods
                mod.modName = PREDITOR_MOD_PREFIX + mod.modName;
                mod.displayName = "[Preditor] " + mod.displayName;
                mod.isPreditorProject = true;

                log(severityLevel::info, "Preditor project found: '%s' - '%s'", mod.modName, projectPathStr);
                ModList.emplace_back(std::move(mod));
            }
            catch (const std::exception& e)
            {
                log(severityLevel::error, "Failed to load Preditor project %s: %s", projectPath.u8string(), e.what());
            }
        }
    }

    // Add legacy mods
    if (fs::is_directory(legacyModsDir))
    {
        for (auto& directory : fs::directory_iterator(legacyModsDir))
        {
            if (!directory.is_directory())
                continue;

            fs::path modDirPath = directory.path();
            std::string modDirName = modDirPath.filename().u8string();

            try
            {
                log(severityLevel::info, "Legacy mod found: '%s'", modDirName);
                Mod mod;
                mod.modName = LEGACY_MOD_PREFIX + modDirName;
                mod.displayName = "[Legacy] " + modDirName;
                mod.version = "N/A";
                mod.author = "N/A";
                mod.path = modDirPath;
                mod.isLegacyMod = true;
                ModList.emplace_back(std::move(mod));
            }
            catch (const std::exception& e)
            {
                log(severityLevel::error, "Failed to load legacy mod %s: %s", modDirName, e.what());
            }
        }
    }

    // Read settings from the config
    for (Mod& mod : ModList)
    {
        // Find the mod in the config
        pugi::xml_node modNode;

        for (pugi::xml_node i : ModListNode.children("Mod"))
        {
            if (i.child("modName").text().as_string() == mod.modName)
            {
                modNode = i;
                break;
            }
        }

        // -- If in Chairloader.xml --
        if (modNode)
        {
            /* Load Previous Mod Config */
            mod.enabled = modNode.child("enabled").text().as_bool();
            mod.deployed = modNode.child("deployed").text().as_bool();

            /* Load Order*/
            int ModloadOrder = modNode.child("loadOrder").text().as_int();
            if (checkSafeLoadOrder(ModloadOrder))
            {
                incrementNextSafeLoadOrder(ModloadOrder);
                mod.loadOrder = ModloadOrder;
                loadOrder.insert(std::pair(mod.loadOrder, mod.modName));
                log(severityLevel::debug, "New Load Order Found = %i", mod.loadOrder);
            }
            else
            {
                mod.loadOrder = getNextSafeLoadOrder();
                loadOrder.insert(std::pair(mod.loadOrder, mod.modName));
                log(severityLevel::debug, "Non-unique load order found. Next safe = %i", mod.loadOrder);
            }

            /* Version Check */
            if (mod.version != modNode.child("version").text().as_string()) {
                log(severityLevel::warning, "%s: config version mismatch, TODO: fix this automatically", mod.modName);
            }
            // TODO: handle configs
        }
        else
        {
            // -- If New Mod --
            log(severityLevel::debug, "New Mod Found: %s", mod.modName);
            mod.deployed = false;
            mod.enabled = false;
            mod.loadOrder = getNextSafeLoadOrder();
            mod.isNew = true;
            loadOrder.insert(std::pair(mod.loadOrder, mod.modName));
        }
    }

    // Sort mods by load order
    std::sort(ModList.begin(), ModList.end());
    serializeLoadOrder();
}

ChairManager::ChairManager() {
    assert(!m_spInstance);
    m_spInstance = this;
    fs::create_directory(fs::current_path() / fs::path(RUNTIME_DATA_DIR));
    m_LogFilePath = fs::current_path() / fs::path(RUNTIME_DATA_DIR) / "ChairManager.log";
    ChairManagerConfigPath = fs::current_path() / fs::path(RUNTIME_DATA_DIR) / "ChairManagerConfig.xml";
    packagedChairloaderVersion = new SemanticVersion;
    *packagedChairloaderVersion = VersionCheck::getPackagedChairloaderVersion();
    cURLpp::initialize();
    LoadModManagerConfig();
    VersionCheck::fetchLatestVersion();
    SwitchToInstallWizard();
}

ChairManager::~ChairManager() {
    flushFileQueue();
    saveModManagerConfigFile();

    assert(m_spInstance == this);
    m_spInstance = nullptr;
}

void ChairManager::SaveMod(Mod *modEntry) {
    if(modEntry == nullptr) {
        log(severityLevel::error, "Cannot save mod, nullptr was passed");
        return;
    }

    // Find the mod in the config
    pugi::xml_node modNode;

    for (pugi::xml_node i : ModListNode.children("Mod"))
    {
        if (i.child("modName").text().as_string() == modEntry->modName)
        {
            modNode = i;
            break;
        }
    }

    if (modNode) {
        modNode.remove_children();
    } else {
        modNode = ModListNode.append_child("Mod");
        modNode.append_attribute("type").set_value("xmlnode");
    }

    //modName
    auto node = modNode.append_child("modName");
    node.append_attribute("type").set_value("string");
    node.text().set(modEntry->modName.c_str());
    //loadOrder
    node = modNode.append_child("loadOrder");
    node.append_attribute("type").set_value("int");
    node.text().set(modEntry->loadOrder);
    //enabled
    node = modNode.append_child("enabled");
    node.append_attribute("type").set_value("bool");
    node.text().set(modEntry->enabled);
    //deployed
    node = modNode.append_child("deployed");
    node.append_attribute("type").set_value("bool");
    node.text().set(modEntry->deployed);
    //Version
    node = modNode.append_child("version");
    node.append_attribute("type").set_value("string");
    node.text().set(modEntry->version.c_str());
    saveChairloaderConfigFile();
    //dllName
    if (!modEntry->dllName.empty())
    {
        node = modNode.append_child("dllName");
        node.append_attribute("type").set_value("string");
        node.text().set(modEntry->dllName.c_str());
    }
    saveChairloaderConfigFile();
    //hasXML
    node = modNode.append_child("hasXML");
    node.append_attribute("type").set_value("string");
    node.text().set(modEntry->hasXML);
    // fullPath
    if (modEntry->isPreditorProject)
    {
        node = modNode.append_child("fullPath");
        node.append_attribute("type").set_value("string");
        node.text().set(modEntry->path.u8string().c_str());
    }
    saveChairloaderConfigFile();
}


void ChairManager::flushFileQueue() {
    std::scoped_lock<std::mutex> lock(logMutex);
    std::ofstream fileStream;
    fileStream.open(m_LogFilePath, std::ios_base::app);
    if(fileStream.is_open()){
        for(auto & logEntry: fileQueue){
            std::string level;
            switch (logEntry.level) {
                case severityLevel::trace:
                    level = "trace";
                    break;
                case severityLevel::debug:
                    level = "debug";
                    break;
                default:
                case severityLevel::info:
                    level = "info";
                    break;
                case severityLevel::warning:
                    level = "warning";
                    break;
                case severityLevel::error:
                    level = "error";
                    break;
                case severityLevel::fatal:
                    level = "fatal";;
                    break;
            }
            std::string message = boost::str((boost::format("%s: [%s] %s") % logEntry.timeStamp % level % logEntry.message));
            fileStream << message << std::endl;
        }
        fileQueue.clear();
        fileStream.close();
    } else {
        log(severityLevel::error, "Error, could not open %s", m_LogFilePath.u8string().c_str());
    }
}

void ChairManager::Update() {
    static time_t lastFileTime;
    if(time(nullptr) - lastFileTime > 10){
        time(&lastFileTime);
        flushFileQueue();
    }
    //! log oversizing mitigation
    logMutex.lock();
    if(logRecord.size() > 2000){
        std::list<LogEntry> newLogRecord;
        for(auto& entry: logRecord){
            if(entry.level == severityLevel::trace || entry.level == severityLevel::debug){
                continue;
            }
            newLogRecord.emplace_back(entry);
        }
        if(newLogRecord.size() > 2000){
            // if you have 2000+ info messages, you're doing something wrong
            newLogRecord.clear();
        }
        logRecord = newLogRecord;
    }
    logMutex.unlock();
    m_ConfigManager.saveDirtyConfigs();
    if(updateDPIScaling){
        updateDPIScaling = false;
        ImGui::GetStyle().ScaleAllSizes(dpiScale / oldDpiScaling);
        OverlayElementWidth = OverlayElementWidth * (dpiScale / oldDpiScaling);
        OverlayElementHeight = OverlayElementHeight * (dpiScale / oldDpiScaling);
        oldDpiScaling = dpiScale;
        UI::ReloadFonts(dpiScale);
        ImGui::GetIO().Fonts->Build();
        UI::ResetDX11();
        log(severityLevel::trace, "DPI Scale Changed to %.2f", dpiScale);
    }
}

bool ChairManager::TreeNodeWalkDirectory(fs::path relativePath, std::string modName, XMLFile::XMLType type) {
    fs::path path;
    ImGuiTreeNodeFlags_ treeFlags = ImGuiTreeNodeFlags_None;
    switch(type) {
        case XMLFile::XMLType::Registered:
            path = GetGamePath() / "Mods" / modName / relativePath;
            break;
        case XMLFile::XMLType::Legacy:
            path = GetGamePath() / "Mods" / "Legacy" / modName / relativePath;
            break;
        case XMLFile::XMLType::BaseGame:
            path = fs::path("PreyFiles") / relativePath;
            break;
        default:
            break;
    }
    if (is_directory(path)) {
        std::string nodeName;
        if(relativePath.empty()){
            if(type == XMLFile::XMLType::BaseGame){
                treeFlags = ImGuiTreeNodeFlags_DefaultOpen;
            }
            nodeName = modName;
        } else {
            nodeName = relativePath.filename().u8string();
        }
        if (ImGui::TreeNodeEx(path.u8string().c_str(), treeFlags, "%s", nodeName.c_str())) {
            for (auto &childPath: fs::directory_iterator(path)) {
                fs::path childRelativePath;
                switch(type){
                    case XMLFile::XMLType::Registered:
                        childRelativePath = childPath.path().wstring().substr((GetGamePath() / "Mods" / modName).wstring().length() + 1, childPath.path().wstring().length());
                        break;
                    case XMLFile::XMLType::Legacy:
                        childRelativePath = childPath.path().wstring().substr((GetGamePath() / "Mods" / "Legacy" / modName).wstring().length() + 1, childPath.path().wstring().length());
                        break;
                    case XMLFile::XMLType::BaseGame:
                        childRelativePath = childPath.path().wstring().substr((fs::path("PreyFiles")).wstring().length() + 1, childPath.path().wstring().length());
                        break;
                    default:
                        break;
                }
                TreeNodeWalkDirectory(childRelativePath, modName, type);
            }
            ImGui::TreePop();
            return false;
        }
    } else if (is_regular_file(path)) {
        fs::path childRelativePath;
        fs::path rootDirectory;
        switch(type){
            case XMLFile::XMLType::Registered:
                childRelativePath = path.wstring().substr((GetGamePath() / "Mods" / modName).wstring().length() + 1, path.wstring().length());
                rootDirectory = *childRelativePath.begin();
                if(rootDirectory == "Data"){
                    childRelativePath = childRelativePath.wstring().substr(fs::path("Data/").wstring().length(), path.wstring().length());
                }

                break;
            case XMLFile::XMLType::Legacy:
                childRelativePath = path.wstring().substr((GetGamePath() / "Mods" / "Legacy" / modName).wstring().length() + 1, path.wstring().length());
                break;
            case XMLFile::XMLType::BaseGame:
                childRelativePath = path.wstring().substr((fs::path("PreyFiles")).wstring().length() + 1, path.wstring().length());
                break;
            default:
                break;
        }
        ImGui::PushID(path.u8string().c_str());
        if (ImGui::Selectable(path.filename().u8string().c_str(), selectedFile == path)) {
            selectedFile = {path, childRelativePath, type, modName};
        }
        ImGui::PopID();
        return true;
    }
    return false;
}

int ChairManager::getNextSafeLoadOrder() {
    nextSafeLoadOrder++;
    int safe = nextSafeLoadOrder;
    log(severityLevel::debug, "Next Safe Load Order: %i", nextSafeLoadOrder);
    return safe;
}

void ChairManager::incrementNextSafeLoadOrder(int loadOrder) {
    if(loadOrder <= nextSafeLoadOrder)
        nextSafeLoadOrder = loadOrder + 1;
    log(severityLevel::debug, "New Safe Load Order: %i", nextSafeLoadOrder);
}

bool ChairManager::checkSafeLoadOrder(int i) {
    return loadOrder.find(i) == loadOrder.end();
}

void ChairManager::serializeLoadOrder() {
    int i = 0;
    for(auto &mod : ModList){
        mod.loadOrder = i;
        i++;
    }
    nextSafeLoadOrder = i + 1;
}

void ChairManager::SaveAllMods() {
    for(auto &mod : ModList){
        ModListNode.remove_child(mod.modName.c_str());
        SaveMod(&mod);
    }
    saveChairloaderConfigFile();
}

void ChairManager::UninstallMod(std::string &modName) {
    auto mod = std::find(ModList.begin(), ModList.end(), modName);
    if(mod != ModList.end()){
        mod->enabled = false;
        mod->deployed = false;
        if(ModListNode.remove_child(modName.c_str())){
            log(severityLevel::info, "%s: uninstalled successfully", modName);
            saveChairloaderConfigFile();
        } else {
            log(severityLevel::error, "%s: uninstall failed: not found in Chairloader.xml");
        }
    } else {
        log(severityLevel::error, "Could not install %s: Not found in mod list", modName);
        ErrorMessage = "Could not uninstall" + modName + ": Not found in mod list";
        showErrorPopup = true;
    }

}

void ChairManager::InstallModFromState()
{
    using Manager::ModInfo;

    ModInstallState& state = m_ModInstallState;
    CRY_ASSERT(state.stage != EModInstallStage::None);
    fs::path tempDir = fs::current_path() / RUNTIME_DATA_DIR / "TempInstall";
    std::string modFileName = state.modFilePath.filename().u8string();

    try
    {
        fs::path modsDir = GetGamePath() / "Mods";

        if (fs::exists(tempDir))
            fs::remove_all(tempDir);

        fs::create_directories(tempDir);

        // Extract the mod to temp folder
        ZipUtils::ExtractFolder(state.modFilePath, tempDir);

        if (state.isLegacy)
        {
            // Analyze the mod folder
            LegacyModConverter::ModInfo legacyModInfo = LegacyModConverter::AnalyzeFolder(modFileName, tempDir);
            log(severityLevel::info, "Legacy mod relative path: %s", legacyModInfo.outputRelativePath.u8string());

            fs::path outModRootPath = modsDir / "Legacy" / fs::u8path(state.legacyModName);
            fs::create_directories(outModRootPath.parent_path());

            if (fs::exists(outModRootPath))
            {
                overlayLog(severityLevel::warning, "Mod '%s' already installed. It will be reinstalled.", state.legacyModName);
                fs::remove_all(outModRootPath);
            }

            // Copy the mod files
            fs::path outModPath = outModRootPath / legacyModInfo.outputRelativePath;
            fs::create_directories(outModPath);
            fs::copy(tempDir, outModPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);

            overlayLog(severityLevel::info, "Mod %s installed", state.legacyModName);
        }
        else
        {
            fs::path srcModRootDir;

            // See if the archive only contains a directory
            std::vector<fs::directory_entry> tempDirFileList;
            for (const auto& i : fs::directory_iterator(tempDir))
            {
                tempDirFileList.push_back(i);
            }

            if (tempDirFileList.size() == 1 && tempDirFileList[0].is_directory())
                srcModRootDir = tempDirFileList[0].path();
            else
                srcModRootDir = tempDir;

            // Read mod info
            if (!fs::exists(srcModRootDir / ModInfo::XML_FILE_NAME))
                throw std::runtime_error("ModInfo.xml not found in Chairloader mod");

            ModInfo modInfo;
            modInfo.LoadFile(srcModRootDir / ModInfo::XML_FILE_NAME);

            // Check if already installed
            fs::path outModPath = modsDir / fs::u8path(modInfo.modName);

            if (fs::exists(outModPath))
            {
                overlayLog(severityLevel::warning, "Mod '%s' already installed. It will be reinstalled.", modInfo.modName);
                fs::remove_all(outModPath);
            }

            // Copy the mod files
            fs::create_directories(outModPath);
            fs::copy(tempDir, outModPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);

            overlayLog(severityLevel::info, "Mod %s installed", modInfo.displayName);
        }

        LoadModInfoFiles();
    }
    catch (const std::exception& e)
    {
        log(severityLevel::error, "Failed to install %s: %s", modFileName, e.what());
        overlayLog(severityLevel::error, "Failed to install %s.\n%s\nCheck the log for details.", modFileName, e.what());
    }

    state.stage = EModInstallStage::None;
    fs::remove_all(tempDir);
}

void ChairManager::UpdateModInstall()
{
    switch (m_ModInstallState.stage)
    {
    case EModInstallStage::None:
        break;
    case EModInstallStage::SelectFile:
    {
        WinShell::DialogResult result;

        if (!WinShell::ImUpdateFileOpenDialog("ChooseModFile", &result))
            break;

        if (result.isOk)
        {
            m_ModInstallState.modFilePath = result.filePath;
            m_ModInstallState.isLegacy = boost::iequals(result.filePath.extension().u8string(), ".pak");

            if (m_ModInstallState.isLegacy)
            {
                // This is a legacy mod. Ask for name.
                ImGui::OpenPopup("LegacyModInstallName");
                m_ModInstallState.legacyModName = result.filePath.stem().u8string();
                m_ModInstallState.stage = EModInstallStage::LegacyModPopup;
            }
            else
            {
                // Native mod. Install it.
                InstallModFromState();
            }
        }
        else
        {
            m_ModInstallState.stage = EModInstallStage::None;
        }

        break;
    }
    case EModInstallStage::LegacyModPopup:
    {
        if (ImGui::BeginPopupModal("LegacyModInstallName"))
        {
            ImGui::Text("You are installing a legacy (pre-Chairloader) mod.");
            ImGui::Text("Please, enter the mod's name");
            ImGui::PushItemWidth(-1);
            ImGui::InputText("##modName", &m_ModInstallState.legacyModName);
            ImGui::PopItemWidth();

            bool isValid = false;

            if (!boost::regex_match(m_ModInstallState.legacyModName, fileNameRegex))
            {
                ImGui::TextColored(ImVec4(1, 0, 0, 1), "Name is not valid");
                isValid = false;
            }
            else
            {
                fs::path modsDir = GetGamePath() / "Mods";
                fs::path legacyModsDir = modsDir / "Legacy";
                fs::path outModPath = legacyModsDir / fs::u8path(m_ModInstallState.legacyModName);

                if (fs::exists(outModPath))
                {
                    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Mod with this name already exists. It will be reinstalled.");
                    isValid = true;
                }
                else
                {
                    ImGui::NewLine(); // Space for error text
                    isValid = true;
                }
            }

            ImGui::BeginDisabled(!isValid);
            if (ImGui::Button("Install"))
                InstallModFromState();
            ImGui::EndDisabled();

            ImGui::SameLine();

            if (ImGui::Button("Cancel"))
                m_ModInstallState.stage = EModInstallStage::None;

            ImGui::EndPopup();
        }
        break;
    }
    }
}

void ChairManager::EnableMod(std::string modName, bool enabled) {
    auto mod = std::find(ModList.begin(), ModList.end(),modName);
    if(mod != ModList.end()) {
        mod->enabled = enabled;
    }
}

float overlayLogPadding = 2.0f;
static std::string logEntryToDelete;
static float accumulatedHeight = 0.0f;
void ChairManager::DrawOverlayLog(){
    logMutex.lock();
    accumulatedHeight = 0.0f;
//    tm nowTime;
    time_t now = time(nullptr);
//    localtime_s(&nowTime,&now);
    const uint64_t fadeDuration = 500;
    const uint64_t totalElementTime = 4000;
    float y = 0.0f;

    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));
    ImGui::PushClipRect(ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x - OverlayElementWidth - 2*ImGui::GetStyle().FramePadding.x - 2 * overlayLogPadding, ImGui::GetWindowPos().y + + overlayLogPadding + 60.0f),
                                 ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x - 2 * overlayLogPadding, ImGui::GetWindowPos().y + 2 * OverlayElementHeight + (2 + 1) * overlayLogPadding + 60.0f),
                                 false);

    for(auto overlayEntry = overlayQueue.rbegin(); overlayEntry != overlayQueue.rend() && y < 6.0f; ++overlayEntry) {
        if(overlayEntry->level >= filterLevel) {
            auto currentMillis = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count();
            if (currentMillis - overlayEntry->fadeTime < totalElementTime) {
                float alpha = 1.0f;
                ImGui::SetNextWindowPos(ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x -
                                               ImGui::CalcTextSize(overlayEntry->message.c_str(), nullptr, false,
                                                                   OverlayElementWidth).x -
                                               ImGui::GetStyle().FramePadding.x * 2 - 2 * overlayLogPadding,
                                               ImGui::GetWindowPos().y + accumulatedHeight +
                                               (y + 1) * overlayLogPadding + 60.0f));
                if (currentMillis - overlayEntry->fadeTime > totalElementTime - fadeDuration) {
                    float currentFade = ((currentMillis - overlayEntry->fadeTime - (totalElementTime - fadeDuration)) /
                                         (fadeDuration * 1.0f - 20.0f));
                    alpha = 1.0f - currentFade;
                } else {
                    alpha = 1.0f;
                }
                ImGui::SetNextWindowBgAlpha(alpha);
                ImGui::PushStyleVar(ImGuiStyleVar_Alpha, alpha);
                OverlayLogElement(*overlayEntry);
                ImGui::PopStyleVar();
                y += 1.0f;
            }
        }

    }
    for(auto overlayEntry = overlayQueue.begin(); overlayEntry != overlayQueue.end(); ++overlayEntry){
        auto currentMillis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        if(currentMillis - overlayEntry->fadeTime > totalElementTime || overlayEntry->message == logEntryToDelete) {
            if(overlayEntry->message == logEntryToDelete) {
                logEntryToDelete.clear();
            }
            overlayQueue.erase(overlayEntry);
            break;
        }
    }
    ImGui::PopClipRect();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();
    logMutex.unlock();
}

auto logElementFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse;

void ChairManager::OverlayLogElement(LogEntry entry) {
//    log(level, "%s", message);
    auto level = entry.level;
    auto message = entry.message;

        switch (level) {
            case severityLevel::trace:
                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(150, 150, 150).operator ImU32());
                break;
            case severityLevel::debug:
                ImGui::PushStyleColor(ImGuiCol_Text, debugColor.operator ImU32());
                break;
            default:
            case severityLevel::info:
                ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_Text));
                break;
            case severityLevel::warning:
                ImGui::PushStyleColor(ImGuiCol_Text, warningColor.operator ImU32());
                break;
            case severityLevel::error:
            case severityLevel::fatal:
                ImGui::PushStyleColor(ImGuiCol_Text, errorColor.operator ImU32());
                break;
        }
        auto messageSize = ImGui::CalcTextSize(message.c_str(), nullptr, false, OverlayElementWidth);
        float height = 0.0f;
        if(messageSize.y < OverlayElementHeight) {
            height = messageSize.y + 2 * ImGui::GetStyle().FramePadding.x;
        } else {
            height = OverlayElementHeight;
        }
        accumulatedHeight += height;
        if(ImGui::BeginChild((std::string("##OverlayLog") + message + std::to_string(entry.fadeTime)).c_str(), ImVec2(messageSize.x + ImGui::GetStyle().FramePadding.x * 2 ,height), true, logElementFlags)){
            ImGui::PushTextWrapPos(ImGui::CalcTextSize(message.c_str(), nullptr, false, OverlayElementWidth).x + ImGui::GetStyle().FramePadding.x * 2);
            ImGui::Text("%s", message.c_str());
            ImGui::PopTextWrapPos();
            if(ImGui::IsItemClicked()) {
                logEntryToDelete = message;
            }
            ImGui::SameLine();
            ImGui::SetCursorPosY(ImGui::GetCursorPosY() - ImGui::GetStyle().FramePadding.y);
        }
        ImGui::PopStyleColor();
        ImGui::EndChild();
}

bool ChairManager::verifyDependencies(std::string modName) {
    auto mod = std::find(ModList.begin(), ModList.end(),modName);
    if(mod != ModList.end()){
        for(auto& dependency: mod->dependencies){
            auto modSearch = std::find(ModList.begin(), ModList.end(),dependency);
            if(modSearch == ModList.end()){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool ChairManager::verifyDependenciesEnabled(std::string modName) {
    auto mod = std::find(ModList.begin(), ModList.end(),modName);
    if(mod != ModList.end()){
        for(auto& dependency: mod->dependencies){
            auto modSearch = std::find(ModList.begin(), ModList.end(),dependency);
            if(modSearch == ModList.end()){
                return false;
            }
            if(!modSearch->enabled){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool ChairManager::verifyChairloaderConfigFile() {
    try {
        return fs::exists(GetGamePath() / "Mods/config/Chairloader.xml");
    } catch (std::exception &exception) {
        overlayLog(severityLevel::error, "Exception while verifying chairloader.xml: %s", exception.what());
        return false;
    }
}
void ChairManager::createChairloaderConfigFile() {
    try {
        fs::copy("chairloader_default.xml", GetGamePath() / "Mods/config/Chairloader.xml", fs::copy_options::overwrite_existing);
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while creating chairloader config file: %s", exception.what());
    }
}

void ChairManager::createDefaultFileStructure() {
    try {
        for (const char* dirName : GetGamePathUtil().GetRequiredChairloaderDirs())
        {
            fs::create_directories(GetGamePath() / dirName);
        }
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while creating default file structure: %s", exception.what());
    }
}

void ChairManager::Init() {
    installedChairloaderVersion = new SemanticVersion;
    *installedChairloaderVersion = VersionCheck::getInstalledChairloaderVersion();
    createDefaultFileStructure();
    // Note: This method may be called mutiple times (e.g. after game path change)
    if (!verifyChairloaderConfigFile())
    {
        log(severityLevel::info, "Chairloader config file not found, creating default");
        createChairloaderConfigFile();
    }

    CRY_ASSERT(!m_pMergerTask);

    if (!ChairloaderConfigFile.load_file((GetGamePath() / "Mods/config/Chairloader.xml").c_str())) {
        throw std::runtime_error("Chairloader config file is corrupted or missing.");
    }

    log(severityLevel::info, "Chairloader Config File Loaded");
    ModListNode = ChairloaderConfigFile.child("Chairloader").child("ModList");
    std::string foundMods = "Previously Loaded Mods Found:";
    for(auto &foundMod : ModListNode){
        foundMods += std::string(" ") + foundMod.name() + ",";
    }
    log(severityLevel::info, "%s", foundMods);
    std::ofstream ofs(m_LogFilePath, std::fstream::out | std::fstream::trunc);
    ofs.close();
    LoadModInfoFiles();
    ModNameToDisplayName.clear();
    for(auto & mod: ModList){
        ModNameToDisplayName.insert(std::pair(mod.modName, mod.displayName));
    }
    m_pGameVersion = std::make_unique<GameVersion>();
    m_ConfigManager.init(this);
    initialized = true;
}

void ChairManager::DrawDebug() {
    if(ImGui::BeginTabItem("DEBUG")) {
        ImGui::Text("Draw Time: %.3f s", ImGui::GetTime());

        ImGui::Text("%.2f", ImGui::GetWindowViewport()->DpiScale);
        if(ImGui::Button("Scale 2x")){
            dpiScale = 2.0f;
            updateDPIScaling = true;
        }
        static std::string filePath, modName = "TestMod";
        ImGui::InputText("Mod Name", &modName);
        static MergingPolicy policy;
        static pugi::xml_document doc;
        if (ImGui::Button("Commit Persona 3"))
        {
            throw std::logic_error("Thou art I... And I am thou...\n"
                "Thou hast established a new error...\n\n"
                "It brings thee closer to the truth...\n\n"
                "Thou shalt be blessed when creating\n"
                "Exceptions of the Logic_Error Arcana...");
        }
        ImGui::SameLine();

        if (ImGui::Button("Commit Persona 3 FES"))
            throw "F-ing Exception String";
        ImGui::SameLine();

        if (ImGui::Button("Commit Persona 3 Portable"))
        {
            int* volatile ptr = nullptr;
            *ptr = 0x0451;
        }
        if(ImGui::CollapsingHeader("Config")){
            if(ImGui::Button("Copy Default Config File")){
                m_ConfigManager.copyDefaultConfig(modName);
            }
            ImGui::BeginDisabled();
            static bool configExists;
            configExists = m_ConfigManager.isConfigPresent(modName);
            ImGui::Checkbox("Config File Exists", &configExists);
            ImGui::EndDisabled();
        }
        if(ImGui::CollapsingHeader("Version Strings")){
            static SemanticVersion dllVersion;
            static std::string version, packagedVersion;
            if(ImGui::Button("Get Chairloader Version")){
                // get the version string from the chairloader dll
                version = VersionCheck::getInstalledChairloaderVersionString();
                dllVersion = VersionCheck::getInstalledChairloaderVersion();
            }
            ImGui::SameLine();
            ImGui::Text("Chairloader Version: %s", version.c_str());
            ImGui::Text("Chairloader Version: %s" , dllVersion.String().c_str());
            if(ImGui::Button("Get Packaged Game Version")){
                // get the version string from the game exe
                packagedVersion = VersionCheck::getPackagedChairloaderVersionString();
            }
            ImGui::SameLine();
            ImGui::Text("Packaged Game Version: %s", packagedVersion.c_str());
        }
        if(ImGui::CollapsingHeader("Updating")){
            if(ImGui::Button("Download Updates")){
                UpdateHandler::asyncDownloadUpdate();
            }

            ImGui::ProgressBar(UpdateHandler::getProgress() / UpdateHandler::getProgressTotal(), ImVec2(0.0f, 0.0f));
            ImGui::SameLine();
            // check if the total is MB or KB
            if(UpdateHandler::getProgressTotal() > 1000000){
                ImGui::Text("%.2f MB / %.2f MB", UpdateHandler::getProgress() / 1000000.0f, UpdateHandler::getProgressTotal() / 1000000.0f);
            } else {
                ImGui::Text("%.2f KB / %.2f KB", UpdateHandler::getProgress() / 1000.0f, UpdateHandler::getProgressTotal() / 1000.0f);
            }
            if(ImGui::Button("Install Updates")){
                UpdateHandler::asyncInstallUpdate();
            }
            static bool updateAvailable;
            if(ImGui::Button("Check for Updates")){
                updateAvailable = UpdateHandler::isUpdateAvailable();
            }
            ImGui::BeginDisabled();
            ImGui::Checkbox("Update Available", &updateAvailable);
            ImGui::EndDisabled();

            if(ImGui::Button("Switch to update wizard")){
                SwitchToUpdateWizard();
            }
            ImGui::Text("ETAG:");
            ImGui::Text("%s", m_githubETag.c_str());
            static std::string newETag;
            ImGui::InputText("New ETAG", &newETag);
            if(ImGui::Button("Set ETAG")){
                setETag(newETag);
            }
        }
        if(ImGui::CollapsingHeader("Multi Platform Support")){
            ImGui::Text("GAME BIN: %s", GetGamePathUtil().GetGameBinDir());
            ImGui::Text("GAME EXE: %s", GetGamePathUtil().GetGameExePath());
            ImGui::Text("GAME DLL: %s", GetGamePathUtil().GetGameDllPath());
            ImGui::Text("GAME PDB: %s", GetGamePathUtil().GetGameDllPDBPath());
            ImGui::Text("GAME BACKUP: %s", GetGamePathUtil().GetGameDllBackupPath());
        }
        ImGui::EndTabItem();

        if(ImGui::CollapsingHeader("Hashing Utilities")){
            if(ImGui::Button("Clear Output Dirs")){
                try{
                    fs::remove_all("Output");
                    fs::remove_all("LevelOutput");
                    fs::create_directory("Output");
                    fs::create_directory("LevelOutput");
                } catch (const fs::filesystem_error &e){
                    log(severityLevel::error, "Failed to clear output dir: %s", e.what());
                }
            }
            if(ImGui::Button("Copy Level Files to LevelOutput")){
                try{
                    fs::copy("PreyFiles/Levels", "Output/Levels", fs::copy_options::recursive);
                    fs::create_directories("./LevelOutput/Levels");
                    fs::copy("./Output/Levels", "./LevelOutput/Levels", fs::copy_options::recursive);
                } catch (const fs::filesystem_error &e){
                    log(severityLevel::error, "Failed to copy level files to output dir: %s", e.what());
                }
            }
        }
    }
}

void ChairManager::SwitchToDeployScreen() {
    modalInitPos = ImGui::GetWindowPos();
    modalInitPos.x -= (ImGui::GetWindowWidth() + 125);
    m_State = State::Deploying;
}

void ChairManager::DrawDeployScreen(bool *pbIsOpen) {
    ImGuiWindowFlags windowFlags =
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoResize;

    const ImVec2 deployScreenSize = {500, 300};
    ImGui::SetNextWindowSize({ deployScreenSize.x * dpiScale, deployScreenSize.y * dpiScale});
    ImGui::SetNextWindowBgAlpha(1.0f);
    ImGui::SetNextWindowPos(modalInitPos, ImGuiCond_Appearing);
    if(ImGui::BeginPopupModal("Deploying Mods", nullptr, windowFlags)) {
        CRY_ASSERT(m_pMergerTask);
        MergerTask& task = *m_pMergerTask;

        auto deployPhase = task.pMerger->GetDeployPhase();
        auto deployStep = task.pMerger->GetDeployStep();

        // RemovingOldOutput, CopyingBaseFiles, MergingLegacyMods, MergingMods, RemovingOldPatches, PackingLevelFiles, CopyingLevelFiles, PackingLocalization, PackingMainPatch, CopyingMainPatch, Done, Invalid
        ImGui::Text("Deploying Mods, Please Wait:");
        ImGui::Separator();
        if(!task.pMerger->DeployFailed())
            ImGui::Text("%s", ChairMerger::GetDeployPhaseString(deployPhase).c_str());
        else
            ImGui::TextColored(errorColor, "FAILED");
        ImVec2 childSize = ImGui::GetContentRegionAvail();
        if(task.pMerger->DeployFailed()){
            childSize.y -= ImGui::GetFrameHeightWithSpacing();
        }
        ImGui::BeginChild("Progress Steps", childSize);
        if(deployStep >= DeployStep::RemovingOldOutput){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::RemovingOldOutput).c_str());
        }
        if(deployStep >= DeployStep::LoadingPatchChecksums){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::LoadingPatchChecksums).c_str());
        }
        ImGui::BeginDisabled(m_MergerSettings.m_bForceVanillaPack);
        if(deployStep >= DeployStep::MergingMods){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::MergingMods).c_str());
        }
        ImGui::EndDisabled();
        if(deployStep >= DeployStep::PackingLevelPatches){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::PackingLevelPatches).c_str());
        }
        if(deployStep >= DeployStep::PackingLocalizationPatches){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::PackingLocalizationPatches).c_str());
        }
        if(deployStep >= DeployStep::PackingMainPatch){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::PackingMainPatch).c_str());
        }
        if(deployStep >= DeployStep::CleaningUp){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::CleaningUp).c_str());
        }
        if(deployStep >= DeployStep::Done){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::Done).c_str());
        }
        if(task.pMerger->DeployFailed()){
            ImGui::PushStyleColor(ImGuiCol_Text, errorColor.operator ImU32());
            ImGui::Text("Deploy Failed");
            ImGui::TextWrapped("%s", task.pMerger->GetDeployFailedMessage().c_str());
            ImGui::PopStyleColor();
        }
        ImGui::EndChild();
        if(task.pMerger->DeployFailed()){
            if(ImGui::Button("Close")){
                ImGui::CloseCurrentPopup();
                m_pMergerTask.reset();
                m_State = State::MainWindow;
            }
        }
        ImGui::EndPopup();
        initPosSet = true;
    }

    bool optionsOpen = true;
    ImGui::SetNextWindowSize({ deployScreenSize.x * dpiScale, deployScreenSize.y * dpiScale});
    ImGui::SetNextWindowBgAlpha(1.0f);
    ImGui::SetNextWindowPos(modalInitPos, ImGuiCond_Appearing);
    if(ImGui::BeginPopupModal("Deploy Options", &optionsOpen, windowFlags)){
        ImGui::Text("Deploy Options");
        ImGui::Separator();
        ImGui::Checkbox("Force Levels to be Repacked", &m_MergerSettings.m_bForceLevelPack);
        ImGui::SameLine();
        ImGuiUtils::HelpMarker("This will force all levels to be repacked, even if they haven't changed. This may be useful if you are having issues with levels not updating properly. (This will take longer to deploy)");
        ImGui::Checkbox("Force Localization to be Repacked", &m_MergerSettings.m_bForceLocalizationPack);
        ImGui::SameLine();
        ImGuiUtils::HelpMarker("This will force all localization files to be repacked, even if they haven't changed. This may be useful if you are having issues with localization not updating properly. (This will take longer to deploy)");
        ImGui::Checkbox("Force Main Patch to be Repacked", &m_MergerSettings.m_bForceMainPatchPack);
        ImGui::SameLine();
        ImGuiUtils::HelpMarker("This will force the main patch to be repacked, even if it hasn't changed. This may be useful if you are having issues with the main patch not updating properly. (This will take longer to deploy)");
        ImGui::Separator();
        ImGui::Checkbox("Pack only Vanilla Files (No Mods)", &m_MergerSettings.m_bForceVanillaPack);
        ImGui::SameLine();
        ImGuiUtils::HelpMarker("This will only pack vanilla files, and will not include any mod files. This will not disable dll mods, but will restore the game files to their original state.");

        // set buttons to bottom of the window
        ImGui::SetCursorPosY(ImGui::GetWindowHeight() - ImGui::GetFrameHeightWithSpacing());
        if(ImGui::Button("Deploy")){
            RunAsyncDeploy();
        }
        ImGui::SameLine();
        if(ImGui::Button("Cancel")){
            optionsOpen = false;
        }
        ImGui::EndPopup();
    }

    if(!optionsOpen){
        m_State = State::MainWindow;
        CRY_ASSERT(!m_pMergerTask);
    }

    if(!m_pMergerTask){
        ImGui::OpenPopup("Deploy Options");
    } else {
        ImGui::OpenPopup("Deploying Mods");
    }

    if (m_pMergerTask && IsFutureReady(m_pMergerTask->future))
    {
        m_pMergerTask->future.get();

        if(!m_pMergerTask->pMerger->DeployFailed()) {
            m_pMergerTask.reset();
            m_State = State::MainWindow;
        }

        return;
    }
}

std::unique_ptr<ChairMerger> ChairManager::CreateChairMerger(bool forInstallWizard, ILogger* pLogger)
{
    fs::path chairManagerDir = fs::current_path();
    std::vector<ChairMerger::Mod> modsForMerging;

    // Chairloader patch
    {
        ChairMerger::Mod& patchMod = modsForMerging.emplace_back();
        patchMod.type = ChairMerger::EModType::Folder;
        patchMod.modName = "Chairloader";
        patchMod.dataPath = chairManagerDir / "ChairloaderPatch";
    }

    if (!forInstallWizard)
    {
        for (const Mod& mod : ModList)
        {
            if (!mod.enabled)
                continue;

            ChairMerger::Mod& mergedMod = modsForMerging.emplace_back();

            if (mod.isLegacyMod)
            {
                // Legacy mod
                mergedMod.type = ChairMerger::EModType::Legacy;
                mergedMod.modName = mod.modName;
                mergedMod.dataPath = mod.path;
            }
            else
            {
                // Native mod
                mergedMod.type = ChairMerger::EModType::Native;
                mergedMod.modName = mod.modName;
                mergedMod.dataPath = mod.path / "Data";

                ModConfig& modConfig = GetConfigManager()->getModConfig(mod.modName);

                // May be null if config fails to load
                if (modConfig.configDoc)
                    mergedMod.config.reset(*modConfig.configDoc);
                else
                    Log(severityLevel::error, "Mod '%s' config is null!", mod.modName);
            }
        }
    }

    std::unique_ptr<ChairMerger> pMerger = std::make_unique<ChairMerger>(
        chairManagerDir,
        chairManagerDir / "PreyFiles",
        chairManagerDir / RUNTIME_DATA_DIR / "TempMerger",
        GetGamePath(),
        pLogger ? pLogger : this
    );

    pMerger->SetMods(std::move(modsForMerging));

    if (forInstallWizard)
    {
        ChairMergerSettings settings;
        settings.m_bForceMainPatchPack = true;
        pMerger->SetSettings(settings);
    }
    else
    {
        pMerger->SetSettings(m_MergerSettings);
    }

    return pMerger;
}

void ChairManager::RunAsyncDeploy() {
    if (m_pMergerTask)
    {
        overlayLog(severityLevel::error, "Mods are already being deployed");
        return;
    }

    m_pMergerTask = std::make_unique<MergerTask>();
    m_pMergerTask->pMerger = CreateChairMerger(false);
    m_pMergerTask->future = m_pMergerTask->pMerger->DeployAsync();
}

void ChairManager::OpenInstallModDialog()
{
    WinShell::DialogOptions fileDialogOpts;
    fileDialogOpts.title = "Choose Mod File...";
    fileDialogOpts.fileTypes.push_back({ "Mod Archive (*.zip, *.pak)", "*.zip;*.pak" });

    WinShell::ImShowFileOpenDialog("ChooseModFile", fileDialogOpts);
    m_ModInstallState.stage = EModInstallStage::SelectFile;
}

bool ChairManager::IsUpdateAvailable()
{
    return VersionCheck::getLatestChairloaderVersion() > VersionCheck::getInstalledChairloaderVersion();
}

void ChairManager::SwitchToUninstallWizard() {
    log(severityLevel::info, "Switching to uninstall wizard");
    m_State = State::UninstallWizard;
}

void ChairManager::DrawUninstallWizard(bool *pbIsOpen) {
    if (!m_pUninstallWizard)
    {
        m_pUninstallWizard = std::make_unique<ChairUninstallWizard>();
    }
    if (m_pUninstallWizard->Show("Chairloader Uninstaller", pbIsOpen))
    {
        m_pUninstallWizard.reset();
        m_State = State::MainWindow;
        std::exit(0);
    }

}


void ChairManager::DrawUpdateWizard(bool *pBoolean) {
    bool draw = true;
    if(!m_pUpdateWizard){
        m_pUpdateWizard = std::make_unique<ChairUpdateWizard>();
    }
    if(m_pUpdateWizard->Show("Chairloader Updater", &draw)){
        m_pUpdateWizard.reset();
        m_State = State::MainWindow;
    }
}

void ChairManager::SwitchToUpdateWizard() {
    log(severityLevel::info, "Switching to update wizard");
    m_State = State::UpdateWizard;
}

void ChairManager::displayXmlNode(pugi::xml_node node, int depth) {
    static float xmlDepthSpacing = 20.0f;
    if(node){
        //TODO: add way to edit style colors
        ImGui::SetCursorPosX((depth * xmlDepthSpacing) + 10.0f);
//        ImGui::PushStyleColor(ImGuiCol_Text, ImColor(107, 119, 255).operator ImVec4());
        bool nodeOpen = false;
        if(node.attribute("Name")){
            nodeOpen = ImGui::TreeNode((std::string(node.name()) + node.attribute("Name").as_string() + node.attribute("id").as_string()).c_str(), "<%s - %s>", node.name(), node.attribute("Name").as_string());
        }
        else {
            nodeOpen = ImGui::TreeNode((std::string(node.name()) + node.attribute("Name").as_string() + node.attribute("id").as_string()).c_str(), "<%s>", node.name());
        }
//        ImGui::PopStyleColor();
        if(nodeOpen) {
            for (auto attribute : node.attributes()) {
                ImGui::TextColored(ImColor(47, 239, 95), "%s", attribute.name());
                ImGui::SameLine();
                ImGui::TextColored(ImColor(255, 255, 255), "=");
                ImGui::SameLine();
                ImGui::TextColored(ImColor(221, 146, 33), "%s", attribute.as_string());
                if(ImGui::IsItemClicked()){
                    ImGui::SetClipboardText(attribute.as_string());
                }
            }
            if(!node.text().empty())
                ImGui::Text("%s", node.text().as_string());
            for(auto child : node.children()){
                displayXmlNode(child, depth + 1);
            }
//            if(strlen() != 0) {
//                ImGui::Text("%s", node->getContent());
//                for (int i = 0; i < node->getChildCount(); i++) {
//                    displayXmlNode(node->getChild(i), depth + 1);
//                }
//                ImGui::SetCursorPosX((depth * xmlDepthSpacing));
//            } else {
//                for (int i = 0; i < node->getChildCount(); i++) {
//                    displayXmlNode(node->getChild(i), depth + 1);
//                }
//            }
            ImGui::TreePop();
        }
    }

}

std::string ChairManager::GetDisplayName(std::string modName) {
    return ModNameToDisplayName.at(modName);
//    return std::string();
}

void ChairManager::SetGamePathFromWizard(const fs::path& gamePath)
{
    log(severityLevel::info, "User selected game path: %s", gamePath.u8string());
    SetGamePath(gamePath);
    log(severityLevel::info, "Game platform: %s", m_GamePath.GetGamePlatformString());
    saveModManagerConfigFile();
}

bool ChairManager::DeployForInstallWizard(const DeployLogCallback& logFunc, std::string& errorMessage) {
    // This is called from a worker thread.
    class CallbackLogger : public ILogger
    {
    public:
        CallbackLogger(const DeployLogCallback& callback)
        {
            m_fnCallback = callback;
        }

        // ILogger
        virtual void LogString(severityLevel level, std::string_view str) override
        {
            ChairManager::Get().LogString(level, str);

            if (level >= severityLevel::info)
                m_fnCallback(str);
        }

        virtual void OverlayLogString(severityLevel level, std::string_view str) override
        {
            // Not supported
            std::abort();
        }

    private:
        DeployLogCallback m_fnCallback;
    };

    CallbackLogger logger(logFunc);
    std::unique_ptr<ChairMerger> pMerger = CreateChairMerger(true, &logger);
    pMerger->Deploy();
    errorMessage = pMerger->GetDeployFailedMessage();
    return !pMerger->DeployFailed();
}

void ChairManager::launchGame() {
    log(severityLevel::info, "Launching game");

    // Collect arguments
    std::vector<std::wstring> args;

    if (!m_bLoadChairloader) {
        args.push_back(L"-nochair");
    }
    if (m_bLoadEditor) {
        args.push_back(L"-editor");
    }
    if (m_bDevMode) {
        args.push_back(L"-devmode");
    }
    if (m_bNoRandom) {
        args.push_back(L"-norandom");
    }
    if (m_bTrainer) {
        args.push_back(L"-trainer");
    }

    // Assemble command line
    fs::path exePath = GetGamePath() / GetGamePathUtil().GetGameExePath();
    std::wstring cmdLine = exePath.wstring();

    for (const std::wstring& i : args)
        cmdLine += L" " + i;

    if (!m_customArgs.empty())
    {
        std::wstring customArgsWide;
        Unicode::Convert(customArgsWide, m_customArgs);
        cmdLine += L" " + customArgsWide;
    }
    
    // Launch the game
    std::string cmdLineUtf8;
    Unicode::Convert(cmdLineUtf8, cmdLine);
    log(severityLevel::trace, "Launching game with command: %s", cmdLineUtf8.c_str());

    STARTUPINFOW si = {sizeof(STARTUPINFO)};
    PROCESS_INFORMATION pi;

    if(CreateProcessW(nullptr, cmdLine.data(), nullptr, nullptr, false, DETACHED_PROCESS, nullptr, nullptr, &si, &pi)){
        log(severityLevel::info, "Game launched successfully");
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        overlayLog(severityLevel::error, "Failed to launch game");
    }
}

void ChairManager::removeStartupCinematics() {
    log(severityLevel::info, "Removing startup cinematics");
    fs::path cinematicsPath = GetGamePath() / CINEMATICS_PATH;

    for (std::string fileName : CINEMATICS_FILES)
    {
        try
        {
            fs::path filePath = cinematicsPath / fileName;
            fs::path backupPath = cinematicsPath / (fileName + ".backup");

            if (fs::exists(filePath))
            {
                log(severityLevel::debug, "Backing up cinematic %s", fileName.c_str());
                fs::rename(filePath, backupPath);
            }
            else if (fs::exists(backupPath))
            {
                log(severityLevel::debug, "Cinematic already backed up: %s", fileName.c_str());
            }
            else
            {
                log(severityLevel::error, "Both cinematic and backup are missing! - %s", fileName.c_str());
            }
        }
        catch (const fs::filesystem_error& e)
        {
            log(severityLevel::error, "Failed to remove startup cinematic %s: %s", fileName.c_str(), e.what());
        }
    }
}

void ChairManager::restoreStartupCinematics() {
    log(severityLevel::info, "Restoring startup cinematics");
    fs::path cinematicsPath = GetGamePath() / CINEMATICS_PATH;

    for (std::string fileName : CINEMATICS_FILES)
    {
        try
        {
            fs::path filePath = cinematicsPath / fileName;
            fs::path backupPath = cinematicsPath / (fileName + ".backup");

            if (fs::exists(filePath))
            {
                log(severityLevel::debug, "Cinematic already exists: %s", fileName.c_str());
            }
            else if (fs::exists(backupPath))
            {
                log(severityLevel::debug, "Restoring cinematic %s", fileName.c_str());
                fs::rename(backupPath, filePath);
            }
            else
            {
                log(severityLevel::error, "Cinematic backup is missing! - %s", fileName.c_str());
            }
        }
        catch (const fs::filesystem_error& e)
        {
            log(severityLevel::error, "Failed to restore startup cinematic %s: %s", fileName.c_str(), e.what());
        }
    }
}

const fs::path &ChairManager::GetGamePath() {
    return m_GamePath.GetGamePath();
}

fs::path ChairManager::GetConfigPath()
{
    return GetGamePath() / "Mods/Config";
}

fs::path ChairManager::GetModPath(const std::string& modName)
{
    return GetGamePath() / "Mods" / fs::u8path(modName);
}

std::vector<std::string> ChairManager::GetModNames()
{
    std::vector<std::string> list;

    for (const auto& i : GetMods())
    {
        list.push_back(i.modName);
    }

    return list;
}

std::vector<std::string> ChairManager::GetLegacyModNames()
{
    std::vector<std::string> list;

    for (const Mod& mod : ModList)
    {
        if (mod.isLegacyMod)
            list.push_back(mod.modName);
    }

    return list;
}

const std::vector<Mod>& ChairManager::GetMods() const
{
    return ModList;
}

std::string ChairManager::GetModDisplayName(const std::string& modName)
{
    for (const auto& i : GetMods())
    {
        if (i.modName == modName)
            return i.displayName;
    }

    return std::string();
}

const ModConfig* ChairManager::GetModConfig(const std::string& modName) const
{
    return &const_cast<ConfigManager&>(m_ConfigManager).getModConfig(modName);
}

void ChairManager::LogString(severityLevel level, std::string_view str)
{
    // scope limiting for mutex
    {
        std::scoped_lock<std::mutex> lock(logMutex);
        logRecord.emplace_back(LogEntry(std::string(str), level));
        fileQueue.emplace_back(LogEntry(std::string(str), level));
    }

    if (level == severityLevel::fatal) {
        flushFileQueue();
        throw std::runtime_error(std::string(str));
    }
}

void ChairManager::OverlayLogString(severityLevel level, std::string_view str)
{
    // scope limiting for mutex
    {
        std::scoped_lock<std::mutex> lock(logMutex);
        logRecord.emplace_back(LogEntry(std::string(str), level));
        fileQueue.emplace_back(LogEntry(std::string(str), level));
        overlayQueue.emplace_back(LogEntry(std::string(str), level));
    }

    if (level == severityLevel::fatal) {
        flushFileQueue();
        throw std::runtime_error(std::string(str));
    }
}
