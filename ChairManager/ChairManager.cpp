//
// Created by theli on 8/1/2022.
//

#include <iostream>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <Manager/GamePath.h>
#include <Manager/XMLMerger2.h>
#include <Manager/PreditorFiles.h>
#include <Merging/ChairMerger.h>
#include <boost/algorithm/string/predicate.hpp>
#include <WinShell/WinShell.h>
#include "ChairManager.h"
#include "UI.h"
#include "ChairWizards/GamePathDialog.h"
#include "GameVersion.h"
#include "winver.h"
#include "ChairWizards/ChairInstallWizard.h"
#include "ChairWizards/ChairUninstallWizard.h"
#include "../Chairloader/Common/GUIUtils.h" // TODO: That's horrible (TRUE LOL)
#include "BinaryVersionCheck.h"
#include "UpdateHandler.h"
#include "ChairWizards/ChairUpdateWizard.h"
#include "../Common/Chairloader/SemanticVersion.h"
#include "Merging/ZipUtils.h"
#include "Paths.h"

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

void ChairManager::Draw() {
    bool bDraw = true;

    switch (m_State)
    {
    case State::LocateGameDir:
        DrawGamePathSelectionDialog(&bDraw);
        break;
    case State::MainWindow:
        if(!initialized)
            Init();
        DrawMainWindow(&bDraw);
        break;
    case State::InstallWizard:
        DrawInstallWizard(&bDraw);
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
            if (ChairManager::Get().GetGamePathUtil()->ValidateGamePath(path))
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
    assert(path.empty() || ChairManager::Get().GetGamePathUtil()->ValidateGamePath(path));

    m_pGamePath->SetGamePath(path);
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

void ChairManager::SwitchToGameSelectionDialog(const fs::path& gamePath)
{
    m_State = State::LocateGameDir;
    m_pGamePathDialog = std::make_unique<GamePathDialog>();
    m_pGamePathDialog->SetGamePath(gamePath);
}

void ChairManager::DrawGamePathSelectionDialog(bool* pbIsOpen)
{
    GamePathDialog::Result result = m_pGamePathDialog->ShowDialog(MAIN_WINDOW_NAME, pbIsOpen);

    if (result == GamePathDialog::Result::Ok)
    {
        log(severityLevel::info, "User selected game path: %s", m_pGamePathDialog->GetGamePath().u8string().c_str());
        SetGamePath(m_pGamePathDialog->GetGamePath());
        m_pGamePath->SetGamePlatform(m_pGamePath->DeduceGamePlatform(GetGamePath()));
        log(severityLevel::info, "Game platform: %s", m_pGamePath->GetGamePlatformString());
        saveModManagerConfigFile();
        m_pGamePathDialog.reset();
        SwitchToInstallWizard();
    }
    else if (result == GamePathDialog::Result::Cancel)
    {
        *pbIsOpen = false;
        m_pGamePathDialog.reset();
    }
}

void ChairManager::SwitchToInstallWizard()
{
    if (!verifyChairloaderInstalled())
    {
        log(severityLevel::info, "Chairloader not found, starting the wizard");
        m_State = State::InstallWizard;
    }
#ifndef DEBUG_BUILD
    else if(VersionCheck::getInstalledChairloaderVersion() < VersionCheck::getPackagedChairloaderVersion()) {
        log(severityLevel::info, "Chairloader version mismatch, running install wizard");
        m_State = State::InstallWizard;
    }
#endif
    else
    {
        log(severityLevel::info, "Chairloader version %s installed, %s is packaged with this installer, %s is the latest version on github",
            VersionCheck::getInstalledChairloaderVersion().String().c_str(),
            VersionCheck::getPackagedChairloaderVersion().String().c_str(),
            VersionCheck::getLatestChairloaderVersion().String().c_str());
        m_State = State::MainWindow;
    }
}

void ChairManager::DrawInstallWizard(bool* pbIsOpen)
{
    if (!m_pInstallWizard)
    {
        m_pInstallWizard = std::make_unique<ChairInstallWizard>();
    }

    if (m_pInstallWizard->Show("Chairloader Installer", pbIsOpen))
    {
        m_pInstallWizard.reset();
        m_State = State::MainWindow;
    }
}

void ChairManager::DrawMainWindow(bool* pbIsOpen)
{
    static bool m_bShowUpdatePopup;
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
                OpenInstallModDialog(false);
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
            //Load Mod List
            if (ImGui::MenuItem("Load Mod List")) {
                loadModInfoFiles();
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
                        "Legacy mods are mods that weren't made for Chairloader, such as older mods that only had asset files. They do not have ModInfo.xml files and as such are not registered with the other mods.\n They are merged first, so registered mods will override legacy ones.");
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
        if(VersionCheck::getLatestChairloaderVersion() > VersionCheck::getInstalledChairloaderVersion()){
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
    std::sort(ModList.begin(), ModList.end());
    ImGui::End();
}

void ChairManager::DrawModList() {
    static std::string selectedMod;
    static bool showDeleteConfirmation;
    if(ImGui::BeginTabItem("Mod List")) {
        if (ImGui::BeginChild("Mod List", ImVec2(ImGui::GetContentRegionAvail().x * 0.65f, 0))) {
            if(ImGui::BeginTabBar("Mod List Bar")) {
                float checkboxColumnSize = 0.0f;
                if(ImGui::BeginTabItem("Mods")) {
                    if (ImGui::BeginTable("Mod List", 5, ImGuiTableFlags_Borders | ImGuiTableFlags_SizingStretchProp |
                                                         ImGuiTableFlags_NoBordersInBody)) {
                        ImGui::TableSetupColumn("##Enable/Disable", ImGuiTableColumnFlags_WidthFixed);
                        ImGui::TableSetupColumn("Mod Name");
                        ImGui::TableSetupColumn("Version", ImGuiTableColumnFlags_WidthFixed,
                                                ImGui::CalcTextSize("Version").x + 16.0f);
                        ImGui::TableSetupColumn("Order", ImGuiTableColumnFlags_WidthFixed,
                                                ImGui::CalcTextSize("Order").x + 16.0f);
                        ImGui::TableSetupColumn("##Buttons", ImGuiTableColumnFlags_WidthFixed);
                        ImGui::TableHeadersRow();
                        if (selectedMod.empty() && !ModList.empty()) {
                            selectedMod = ModList.at(0).modName;
                        }
                        int i = 0;
                        for (auto &ModEntry: ModList) {
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            if (ModEntry.installed && verifyDependenciesEnabled(ModEntry.modName)) {
                                ImGui::Checkbox(("##" + ModEntry.modName + "Enable").c_str(), &ModEntry.enabled);
                            } else {
                                ImGui::BeginDisabled();
                                ImGui::Checkbox(("##" + ModEntry.modName + "Enable").c_str(), &ModEntry.enabled);
                                ImGui::EndDisabled();
                            }
                            checkboxColumnSize = ImGui::GetColumnWidth();
                            ImGui::TableNextColumn();
                            ImVec2 SelectableSize = {0, /*ImGui::GetTextLineHeightWithSpacing() + 4.0f*/0};
//                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 4.0f);


//                    ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, ImColor(0,0,0,0).operator ImU32());
                            auto storedpos = ImGui::GetCursorPosY() + (4 * dpiScale);
                            ImGui::SetCursorPosY(ImGui::GetCursorPosY() - (3.5 * dpiScale));
                            if (ImGui::Selectable(("##Selectable" + ModEntry.modName).c_str(),
                                                  selectedMod == ModEntry.modName, 0,
                                                  ImVec2{ImGui::GetColumnWidth(), ImGui::GetFrameHeight() - 2.0f * dpiScale}))
                                selectedMod = ModEntry.modName;
                            if (ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
                                ImGui::OpenPopup((ModEntry.displayName + " Mod Actions##ModActions" + ModEntry.modName).c_str());
                            }
                            ImGui::SetCursorPosY(storedpos);
                            if(!verifyDependenciesEnabled(ModEntry.modName))
                                ModEntry.enabled = false;
                            if (ModEntry.installed) {
                                if (ModEntry.enabled) {
                                    ImGui::TextColored(ImGui::GetStyleColorVec4(ImGuiCol_Text), "%s",
                                                       ModEntry.displayName.c_str());
//                            if (ImGui::Selectable(ModEntry.modName.c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
//                                selectedMod = ModEntry.modName;
                                } else {
//                            ImGui::PushStyleColor(ImGuiCol_Text,ImColor(180,180,180).operator ImU32());
//                            if (ImGui::Selectable(ModEntry.modName.c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
//                                selectedMod = ModEntry.modName;
//                            ImGui::PopStyleColor();
                                    if(verifyDependencies(ModEntry.modName)) {
                                        if(verifyDependenciesEnabled(ModEntry.modName)){
                                            ImGui::TextColored(ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled), "%s",
                                                               ModEntry.displayName.c_str());
                                            if (ImGui::IsItemHovered()) {
                                                ImGui::BeginTooltip();
                                                ImGui::Text("Mod is not enabled");
                                                ImGui::EndTooltip();
                                            }
                                        } else {
                                            ImGui::TextColored (warningColor, "%s",
                                                               ModEntry.displayName.c_str());
                                            if (ImGui::IsItemHovered()) {
                                                ImGui::BeginTooltip();
                                                ImGui::Text("Dependencies are installed, but not enabled");
                                                ImGui::EndTooltip();
                                            }
                                        }

                                    } else {
                                        ImGui::TextColored(errorColor, "%s",
                                                           ModEntry.displayName.c_str());
                                        if (ImGui::IsItemHovered()) {
                                            ImGui::BeginTooltip();
                                            ImGui::Text("Dependencies not found");
                                            ImGui::EndTooltip();
                                        }
                                    }
                                }
                            } else {
//                        ImGui::PushStyleColor(ImGuiCol_Text,ImColor(245,100,100).operator ImU32());
//                        if (ImGui::Selectable((ModEntry.modName + " *").c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
//                            selectedMod = ModEntry.modName;
//                        ImGui::PopStyleColor();

                                ImGui::TextColored(errorColor, "%s *", ModEntry.displayName.c_str());
                                if (ImGui::IsItemHovered()) {
                                    ImGui::BeginTooltip();
                                    ImGui::Text("Mod is not installed. Please install it before you can enable it");
                                    ImGui::EndTooltip();
                                }

                            }
                            if (ImGui::BeginPopup((ModEntry.displayName + " Mod Actions##ModActions" + ModEntry.modName).c_str())) {
                                ImGui::Text("%s:", ModEntry.displayName.c_str());
                                ImGui::BeginDisabled();
                                bool hasDll = !ModEntry.dllName.empty();
                                ImGui::Checkbox("Has DLL", &hasDll);
                                ImGui::SameLine();
                                ImGui::Checkbox("Has XML", &ModEntry.hasXML);
                                ImGui::EndDisabled();
                                if (ModEntry.installed) {
                                    if (ImGui::Button(("Uninstall" + std::string("##") + ModEntry.modName).c_str())) {
                                        UninstallMod(ModEntry.modName);
                                    }
                                    if (ModEntry.enabled) {
                                        if (ImGui::Button("Disable"))
                                            EnableMod(ModEntry.modName, false);
                                    } else {
                                        if (ImGui::Button("Enable"))
                                            EnableMod(ModEntry.modName, true);
                                    }
                                } else {
                                    if (ImGui::Button(("Install" + std::string("##") + ModEntry.modName).c_str())) {
                                        InstallMod(ModEntry.modName);
                                    }
                                    if (ImGui::Button(("Delete" + std::string("##") + ModEntry.modName).c_str())) {
                                        showDeleteConfirmation = true;
                                    }
                                }
                                ImGui::EndPopup();
                            }
                            if (showDeleteConfirmation) {
                                ImGui::OpenPopup(
                                        ("Delete Confirmation" + std::string("##") + ModEntry.modName).c_str());
                                showDeleteConfirmation = false;
                            }

                            if (ImGui::BeginPopupModal(
                                    ("Delete Confirmation" + std::string("##") + ModEntry.modName).c_str())) {
                                ImGui::Text("Are you sure you want to delete %s?\nConfig data will be preserved.",
                                            ModEntry.modName.c_str());
                                if (ImGui::Button("Delete")) {
                                    if (!ModEntry.modName.empty()) {
                                        log(severityLevel::info, "Deleting %s/Mods/%s/", GetGamePath().u8string(),
                                            ModEntry.modName);
                                        fs::remove_all(GetGamePath() / "Mods" / ModEntry.modName);
                                        ModList.erase(std::find(ModList.begin(), ModList.end(), ModEntry.modName));

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

                            ImGui::TableNextColumn();
                            if (selectedMod == ModEntry.modName) {
                                try {
                                    if (ModEntry.loadOrder > 0) {
                                        if (ImGui::ArrowButton(("##" + ModEntry.modName + "Up").c_str(), ImGuiDir_Up)) {
                                            std::swap(ModList.at(i - 1).loadOrder, ModList.at(i).loadOrder);
                                            std::sort(ModList.begin(), ModList.end());
                                        }
                                        ImGui::SameLine();
                                    }
                                    if (ModEntry.loadOrder < ModList.size() - 1) {
                                        if (ImGui::ArrowButton(("##" + ModEntry.modName + "Down").c_str(),
                                                               ImGuiDir_Down)) {
                                            std::swap(ModList.at(i).loadOrder, ModList.at(i + 1).loadOrder);
                                            std::sort(ModList.begin(), ModList.end());
                                        }
                                    }
                                } catch (const std::exception &exc) {
                                    log(severityLevel::error, "%s", exc.what());
                                    std::cerr << exc.what() << std::endl;
                                }
                            }
                            i++;
                        }
                        //TODO: add ability to reorder legacy mods...
                        ImGui::EndTable();
                    }
                    ImGui::EndTabItem();
                }
                if (!LegacyModList.empty()) {
                    if(ImGui::BeginTabItem("Legacy Mods")) {
                        ImGui::TextDisabled("What's a legacy mod");
                        ImGui::SameLine();
                        ImGuiUtils::HelpMarker("Legacy mods are mods that weren't made for Chairloader, such as older mods that only had asset files. They do not have ModInfo.xml files and as such are not registered with the other mods.\n They are merged first, so registered mods will override legacy ones.");
                        if (ImGui::BeginTable("Legacy Mod List", 2,
                                              ImGuiTableFlags_Borders | ImGuiTableFlags_SizingStretchProp |
                                              ImGuiTableFlags_NoBordersInBody)) {

                            ImGui::TableSetupColumn("##Enable/Disable", ImGuiTableColumnFlags_WidthFixed,
                                                    28.0f);
                            ImGui::TableSetupColumn("Mod Name");
                            ImGui::TableNextRow();
                            ImGui::TableSetBgColor(ImGuiTableBgTarget_RowBg0, ImColor(40, 40, 40));
                            ImGui::TableSetColumnIndex(1);
//                    ImGui::Spacing();
//                    ImGui::Separator();
                            ImGui::Text("Legacy Mods");
                            for (auto &legacyMod: LegacyModList) {
                                ImGui::TableNextRow();
                                ImGui::TableSetColumnIndex(1);
                                ImGui::Text("%s", legacyMod.c_str());
                            }
                            ImGui::EndTable();
                        }
                        ImGui::EndTabItem();
                    }
                } else {
                    ImGui::BeginDisabled();
                    if(ImGui::BeginTabItem("Legacy Mods")){
                        ImGui::EndTabItem();
                    }
                    ImGui::EndDisabled();
                }
                ImGui::EndTabBar();
            }
        }
        ImGui::EndChild();
        ImGui::SameLine();
        if (ImGui::BeginChild("Controls")) {
            if (ImGui::Button("Refresh Mod List")) {
                loadModInfoFiles();
                selectedMod.clear();
                m_ConfigManager.saveDirtyConfigs();
                m_ConfigManager.init(this);
            }
            ImGui::SameLine();
            ImGuiUtils::HelpMarker("Loads mod list from the Chairloader config file. Also discovers new mods in the Mods/ folder.");
            ImGui::SameLine();
            if(ImGui::Button("Enable All")){
                for(auto& mod : ModList){
                    EnableMod(mod.modName);
                    // if dependencies aren't installed then those mods will disable themselves later
                }
            }
            ImGui::Separator();
            if(ImGui::BeginChild("Mod Info", {0, ImGui::GetContentRegionAvail().y * 0.61f})) {
                auto ModSelect = std::find(ModList.begin(), ModList.end(), selectedMod);
                if (ModSelect != ModList.end()) {
                    if (!ModSelect->installed)
                        ImGui::BeginDisabled();
                    ImGui::TextWrapped("%s", ModSelect->displayName.c_str());
                    ImGui::Text("By: %s", ModSelect->author.c_str());
//                    if(ImGui::Button("Config")){
//                        m_ConfigManager.showConfigPopup(ModSelect->modName);
//                    }
                    if(!ModSelect->dependencies.empty()){
                        ImGui::Separator();
                        ImGui::Text("Dependencies:");
                        for(auto & dependency : ModSelect->dependencies){
                            auto dependencySearch = std::find(ModList.begin(), ModList.end(), dependency);
                            if(dependencySearch == ModList.end())
                                ImGui::PushStyleColor(ImGuiCol_Text, errorColor.operator ImU32());
                            else if(!dependencySearch->enabled)
                                ImGui::PushStyleColor(ImGuiCol_Text, warningColor.operator ImU32());
                            if(ImGui::TreeNode(dependency.c_str())){
                                if(dependencySearch != ModList.end()){
                                    if(dependencySearch->enabled) {
                                        ImGui::Text("Version Installed: %s", dependencySearch->version.c_str());
                                    } else {
                                        ImGui::Text("Dependency not enabled");
                                    }
                                } else {
                                    ImGui::Text("Dependency not found");
                                }
                                ImGui::TreePop();
                            }
                            if(dependencySearch == ModList.end())
                                ImGui::PopStyleColor();
                            else if(!dependencySearch->enabled)
                                ImGui::PopStyleColor();
                        }
                    }
                    if (!ModSelect->installed) {
                        ImGui::EndDisabled();
                        if (ImGui::Button("Install")) {
                            InstallMod(ModSelect->modName);
                        }
                        ImGui::SameLine();
                        ImGuiUtils::HelpMarker("This will save the mod to the Mod List, meaning it will be remembered in the future, and can actually be loaded.");
                    }
                }
            }
            ImGui::EndChild();
//            ImGui::SetCursorPosY(ImGui::GetWindowSize().y -100);
            if(ImGui::Button("Save Mod List")){
                SaveAllMods();
                overlayLog(severityLevel::info, "Mod list saved");
            }
            ImGui::SameLine();
            ImGuiUtils::HelpMarker("Save the mod list to the chairloader.xml config file");
            if(ImGui::Button("Deploy Mods")){
                SwitchToDeployScreen();
            }
            ImGui::SameLine();
            ImGuiUtils::HelpMarker("Merge, patch, and copy the files to the game directory.");
            ImGui::Separator();
            if(ImGui::Button("Install Mod From File")){
               ImGui::OpenPopup("Install Mod From File");
            }
            ImGui::Separator();
            if(ImGui::Button("Options")){
                ImGui::OpenPopup("Launch Options");
            }
            ImGui::SameLine();
            if(ImGui::Button("Launch Prey")){
                launchGame();
            }
        }
        if(ImGui::BeginPopupContextWindow("Launch Options")){
            // bool m_bLoadChairloader,
            //        m_bLoadEditor,
            //        m_bDevMode,
            //        m_bNoRandom;
            if(ImGui::Checkbox("Load Chairloader", &m_bLoadChairloader)){
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("LoadChairloader").set_value(m_bLoadChairloader);
                saveModManagerConfigFile();
            }
            if(ImGui::Checkbox("Load Trainers", &m_bTrainer)) {
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("Trainer").set_value(m_bTrainer);
                saveModManagerConfigFile();
            }
            if(ImGui::Checkbox("Load Editor", &m_bLoadEditor)){
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("LoadEditor").set_value(m_bLoadEditor);
                saveModManagerConfigFile();
            }
            if(ImGui::Checkbox("Dev Mode", &m_bDevMode)){
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("DevMode").set_value(m_bDevMode);
                saveModManagerConfigFile();
            }
            if(ImGui::Checkbox("No Random", &m_bNoRandom)){
                ChairManagerConfigFile.first_child().child("LaunchOptions").attribute("NoRandom").set_value(m_bNoRandom);
                saveModManagerConfigFile();
            }
            ImGui::InputText("Custom Launch Options", &m_customArgs);
            ImGui::EndPopup();
        }
        if(ImGui::BeginPopupModal("Install Mod From File", nullptr, ImGuiWindowFlags_AlwaysAutoResize)){
            static int installType = 0;
            ImGui::RadioButton("Chairloader Mod (.zip, .7z)", &installType, 0);
            ImGui::RadioButton("Legacy Mod (.pak)", &installType, 1);

            if(ImGui::Button("Select File")){
                OpenInstallModDialog(installType == 1);
                ImGui::CloseCurrentPopup();
            }
            ImGui::SameLine();
            if(ImGui::Button("Cancel")){
                ImGui::CloseCurrentPopup();
                installType = 0;
            }
            ImGui::EndPopup();
        }
        ImGui::EndChild();

        WinShell::DialogResult result;

        if(WinShell::ImUpdateFileOpenDialog("ChooseModFile", &result)) {
            // action if OK
            if (result.isOk)
            {
                try {
                    // WTF?
                    modToLoadPath = result.filePath;
                    fileToLoad = modToLoadPath.filename();
                    modToLoadPath = modToLoadPath.parent_path();
                    log(severityLevel::trace, "File To Load: %s", fileToLoad.u8string());
                    if (!(fileToLoad).empty()) {
                        fs::remove_all("temp");
                        InstallModFromFile(modToLoadPath, fileToLoad);
                    }
                } catch(std::exception &exc) {
                    log(severityLevel::error, "%s", exc.what());
                    std::cerr << exc.what() << std::endl;
                }
            }
        }
        ImGui::EndTabItem();
    }
}

void ChairManager::DrawDLLSettings() {
    if(ImGui::BeginTabItem("Settings")){
        auto preyPathString = GetGamePath().u8string();
        ImGui::InputText("Prey Path", &preyPathString, ImGuiInputTextFlags_ReadOnly);

        if(ImGui::Button("Change Path")){
            m_pGamePathDialog = std::make_unique<GamePathDialog>();
            m_pGamePathDialog->SetGamePath(GetGamePath());
            ImGui::OpenPopup("Change Game Path");
        }

        ImGui::PushID("GameVersion");
        m_pGameVersion->ShowInstalledVersion();
        ImGui::PopID();

        if (m_pGamePathDialog)
        {
            GamePathDialog::Result result = m_pGamePathDialog->ShowModal("Change Game Path");

            if (result == GamePathDialog::Result::Ok)
            {
                log(severityLevel::info, "User selected game path: %s", m_pGamePathDialog->GetGamePath().u8string().c_str());
                SetGamePath(m_pGamePathDialog->GetGamePath());
                saveModManagerConfigFile();
                m_pGamePathDialog.reset();
                Init();
            }
            else if (result == GamePathDialog::Result::Cancel)
            {
                m_pGamePathDialog.reset();
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
                // Legacy Mods
                if(ImGui::BeginTabItem("Legacy Mods")) {
                    if (ImGui::BeginChild("Legacy Mods", ImVec2(0, 0), true)) {
                        ImGui::Text("Legacy Mods");
                        ImGui::Separator();
                        if(ImGui::BeginTable("Legacy Mod Tree Nodes", 1, ImGuiTableFlags_NoBordersInBody | ImGuiTableFlags_ScrollY)) {
                            for (auto &mod: LegacyModList) {
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                TreeNodeWalkDirectory("", mod, XMLFile::XMLType::Legacy);
                            }
                            ImGui::EndTable();
                        }
                    }
                    ImGui::EndChild();
                    ImGui::EndTabItem();
                    // base assets
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
                        auto policy = m_pChairMerger->GetFileMergingPolicy(selectedFile.relativePath, "PreyFiles");
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
    return fs::path{ (GetGamePath() / "Mods/config" / modName / ".xml").c_str() };
}

fs::path ChairManager::getDefaultConfigPath(std::string &modName) {
    return fs::path{ (GetGamePath() / "Mods" / modName / modName / "_default.xml").c_str() };
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
            mod->infoFile = result.child("Mod");
            mod->dllName = result.child("Mod").attribute("dllName").as_string();
            mod->hasXML = result.child("Mod").attribute("hasXML").as_bool();
            mod->hasLevelXML = result.child("Mod").attribute("hasLevelXML").as_bool();
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

void ChairManager::LoadModsFromConfig() {
    for(auto &PrevMod : ModListNode){
        fs::path modPath = GetGamePath() / "Mods" / PrevMod.name();
        Mod mod;
        if(LoadModInfoFile(modPath, &mod, false)) {
            FindMod(&mod);
            log(severityLevel::debug, "%s load order:%i", mod.modName, mod.loadOrder);
            log(severityLevel::info, "ModInfo.xml Loaded: '%s'", mod.modName.c_str());
            ModList.emplace_back(mod);
        } else {
            log(severityLevel::info, "%s not found, removing from config file", PrevMod.child("modName").text().as_string());
            ModListNode.remove_child(PrevMod.child("modName").text().as_string());
            saveChairloaderConfigFile();
        }
    }
    std::sort(ModList.begin(), ModList.end());
    serializeLoadOrder();
}
void ChairManager::DetectNewMods() {
    for(auto &directory : fs::directory_iterator(fs::path(GetGamePath().u8string() + "/Mods/"))){
        if(directory.path() != GetGamePath() / "Mods/config" && directory.path() != GetGamePath() / "Mods/Legacy" && directory.is_directory()) {
            Mod mod;
            if(LoadModInfoFile(directory.path(), &mod, false)) {
                if(std::find(ModList.begin(), ModList.end(), mod.modName) == ModList.end()) {
                    FindMod(&mod);
                    log(severityLevel::debug, "%s load order:%i", mod.modName, mod.loadOrder);
                    log(severityLevel::info, "ModInfo.xml Loaded: '%s'", mod.modName.c_str());
                    ModList.emplace_back(mod);
                }
            }
        }
    }
    std::sort(ModList.begin(), ModList.end());
    serializeLoadOrder();
}

void ChairManager::loadModInfoFiles() {
    ModList.clear();
    LegacyModList.clear();
    // load previously loaded (assumedly) valid config
    LoadModsFromConfig();
    DetectNewMods();
    overlayLog(severityLevel::info, "Loaded %i mods", ModList.size());
//    serializeLoadOrder();
    try {
        for (auto &directory: fs::directory_iterator(GetGamePath() / "Mods/Legacy")) {
            if (directory.is_directory()) {
                LegacyModList.emplace_back(directory.path().filename().u8string());
            }
        }
        if(LegacyModList.size() > 0) {
            if(LegacyModList.size() == 1) {
                log(severityLevel::info, "Found %i legacy mod", LegacyModList.size());
            } else {
                log(severityLevel::info, "Found %i legacy mods", LegacyModList.size());
            }
        }
    } catch (std::exception & exception) {
        log(severityLevel::debug, "%s", exception.what());
    }
    for(auto & mod : ModList){
        mod.enabled = mod.enabled && verifyDependencies(mod.modName);
    }
}

ChairManager::ChairManager() {
    assert(!m_spInstance);
    m_spInstance = this;
    packagedChairloaderVersion = new SemanticVersion;
    *packagedChairloaderVersion = VersionCheck::getPackagedChairloaderVersion();
    m_pGamePath = std::make_unique<GamePath>();
    cURLpp::initialize();
    LoadModManagerConfig();
    VersionCheck::fetchLatestVersion();

    if (GetGamePath().empty() || !ChairManager::Get().GetGamePathUtil()->ValidateGamePath(GetGamePath())){
        SwitchToGameSelectionDialog(GetGamePath());
    } else {
        m_pGamePath->SetGamePlatform(m_pGamePath->DeduceGamePlatform(GetGamePath()));
        log(severityLevel::info, "Game platform: %s", m_pGamePath->GetGamePlatformString());
        SwitchToInstallWizard();
    }
}

ChairManager::~ChairManager() {
    flushFileQueue();
    saveModManagerConfigFile();

    assert(m_spInstance == this);
    m_spInstance = nullptr;
}


void ChairManager::FindMod(Mod* modEntry) {
    /* Check if mod is in the config list */
    if(std::find(ModList.begin(), ModList.end(),modEntry->modName) == ModList.end()) {
        // -- If in Chairloader.xml --
        if (ModListNode.child(modEntry->modName.c_str())) {
            /* Load Previous Mod Config */
            auto modNode = ModListNode.child(modEntry->modName.c_str());
            modEntry->enabled = modNode.child("enabled").text().as_bool();
            modEntry->deployed = modNode.child("deployed").text().as_bool();
            modEntry->installed = true;
            /* Load Order*/
            int ModloadOrder = modNode.child("loadOrder").text().as_int();
            if(checkSafeLoadOrder(ModloadOrder)){
                incrementNextSafeLoadOrder(ModloadOrder);
                modEntry->loadOrder = ModloadOrder;
                loadOrder.insert(std::pair(modEntry->loadOrder, modEntry->modName));
                log(severityLevel::debug, "New Load Order Found = %i", modEntry->loadOrder);
            } else {
                modEntry->loadOrder = getNextSafeLoadOrder();
                loadOrder.insert(std::pair(modEntry->loadOrder, modEntry->modName));
                log(severityLevel::debug, "Non-unique load order found. Next safe = %i", modEntry->loadOrder);
            }

            /* Version Check */
            if(modEntry->version != modNode.child("version").text().as_string()){
                log(severityLevel::warning, "%s: config version mismatch, TODO: fix this automatically", modEntry->modName);
            }
            // TODO: handle configs
        // -- If New Mod --
        } else {
            log(severityLevel::debug, "New Mod Found: %s", modEntry->modName);
            modEntry->deployed = false;
            modEntry->enabled = false;
            modEntry->loadOrder = getNextSafeLoadOrder();
            loadOrder.insert(std::pair(modEntry->loadOrder, modEntry->modName));
        }
    } else {
        log(severityLevel::error, "%s already loaded", modEntry->modName);
    }

}




void ChairManager::SaveMod(Mod *modEntry) {
    if(modEntry == nullptr) {
        log(severityLevel::error, "Cannot save mod, nullptr was passed");
        return;
    }
    if(modEntry->installed) {
        auto modNode = ModListNode.child(modEntry->modName.c_str());
        if (modNode) {
            modNode.remove_children();
        } else {
            ModListNode.append_child(modEntry->modName.c_str()).append_attribute("type").set_value("xmlnode");;
        }
        modNode = ModListNode.child(modEntry->modName.c_str());
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
        saveChairloaderConfigFile();
    } else {
        log(severityLevel::error, "Cannot save mod %s: must be installed first", modEntry->modName);
        ErrorMessage =  "Cannot save mod " + modEntry->modName + ": must be installed first";
        showErrorPopup = true;
    }
}


void ChairManager::flushFileQueue() {
    std::scoped_lock<std::mutex> lock(logMutex);
    std::ofstream fileStream;
    fileStream.open("ChairManager.log", std::ios_base::app);
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
        log(severityLevel::error, "Error, could not open ChairManager.log");
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
        if(mod.installed) {
            ModListNode.remove_child(mod.modName.c_str());
            SaveMod(&mod);
        }
    }
    saveChairloaderConfigFile();
}

void ChairManager::InstallMod(std::string &modName) {
    auto mod = std::find(ModList.begin(), ModList.end(), modName);
    if(mod != ModList.end()){
        mod->installed = true;
        SaveMod(&(*mod));
        log(severityLevel::info, "%s: Installed successfully", modName);
    } else {
        log(severityLevel::error, "Could not install %s: Not found in mod list", modName);
        ErrorMessage = "Could not install" + modName + ": Not found in mod list";
        showErrorPopup = true;
    }
}

void ChairManager::UninstallMod(std::string &modName) {
    auto mod = std::find(ModList.begin(), ModList.end(), modName);
    if(mod != ModList.end()){
        mod->installed = false;
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

void ChairManager::InstallModFromFile(fs::path path, fs::path fileName) {
    fs::path tempDir = fs::absolute("./temp");
    fs::path outPath = tempDir;

    try {
        ZipUtils::ExtractFolder(path / fileName, outPath);
    }
    catch (std::exception &e) {
        overlayLog(severityLevel::error, "Could not extract %s: %s", fileName.u8string().c_str(), e.what());
        return;
    }

    // See if the archive only contains a directory
    std::vector<fs::directory_entry> outPathFileList;
    for (const auto& i : fs::directory_iterator(outPath))
    {
        outPathFileList.push_back(i);
    }

    if (outPathFileList.size() == 1 && outPathFileList[0].is_directory())
        outPath = outPathFileList[0].path();

    if(!m_bInstallLegacyMod) {
        if (exists(outPath / "ModInfo.xml")) {
            auto mod = new Mod;
            if (LoadModInfoFile(outPath, mod, true)) {
                try {
                    fs::copy(outPath, GetGamePath() / "Mods" / mod->modName,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                    log(severityLevel::info, "Mod Installation Succeeded: %s loaded", mod->modName);
                    DetectNewMods();
                    InstallMod(mod->modName);
                    m_ConfigManager.saveDirtyConfigs();
                    m_ConfigManager.init(this);
                } catch (std::exception &exc) {
                    std::cerr << exc.what() << std::endl;
                    log(severityLevel::error, "Mod Installation Failed: %s", exc.what());
                }
            }
        } else {
            log(severityLevel::error, "Mod Installation Failed: No ModInfo.xml file found");
        }
    } else {
        if (exists(outPath)) {
            try {
                auto BaseModFolder = fileName.filename().replace_extension("");
                log(severityLevel::info, "Installing Legacy Mod: %s", BaseModFolder.u8string().c_str());
                fs::copy(outPath, GetGamePath() / "Mods" / "Legacy" / BaseModFolder,
                         fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                log(severityLevel::info, "Mod Installation Succeeded: %s loaded", BaseModFolder.u8string().c_str());
                loadModInfoFiles();
            } catch (std::exception &exc) {
                std::cerr << exc.what() << std::endl;
                log(severityLevel::error, "Mod Installation Failed: %s", exc.what());
            }
        } else {
            log(severityLevel::error, "Mod Installation Failed: file not extracted");
        }
    }
    fs::remove_all(tempDir);
}

void ChairManager::EnableMod(std::string modName, bool enabled) {
    auto mod = std::find(ModList.begin(), ModList.end(),modName);
    if(mod != ModList.end()) {
        if(mod->installed)
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

bool ChairManager::verifyChairloaderInstalled() {
    try{
        // Check for installed Chairloader binaries
        for (const char* fileName : ChairManager::Get().GetGamePathUtil()->GetRequiredChairloaderBinaries())
        {
            if (!fs::exists(GetGamePath() / ChairManager::Get().GetGamePathUtil()->GetGameBinDir() / fileName))
                return false;
        }

        // Check for extracted PreyFiles
        // TODO 2023-08-30: Remove all hardcoded PreyFiles
        if (!fs::exists(fs::path("PreyFiles") / PREDITOR_FILES_EXTRACTED))
            return false;

        return true;
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while verifying chairloader: %s", exception.what());
        return false;
    }
}

bool ChairManager::verifyDefaultFileStructure() {
    try {
        for (const char* dirName : ChairManager::Get().GetGamePathUtil()->GetRequiredChairloaderDirs())
        {
            if (!fs::is_directory(GetGamePath() / dirName))
                return false;
        }

        return true;
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while verifying default file structure: %s", exception.what());
        return false;
    }
}

void ChairManager::createDefaultFileStructure() {
    try {
        for (const char* dirName : ChairManager::Get().GetGamePathUtil()->GetRequiredChairloaderDirs())
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
    m_pChairMerger.reset();

    fs::path chairManagerDir = fs::current_path();
    m_pChairMerger = std::make_unique<ChairMerger>(
        chairManagerDir,
        chairManagerDir / "PreyFiles",
        chairManagerDir / "ChairloaderPatch",
        chairManagerDir / RUNTIME_DATA_DIR / "TempMerger",
        GetGamePath()
    );

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
    std::ofstream ofs("ChairManager.log", std::fstream::out | std::fstream::trunc);
    ofs.close();
    loadModInfoFiles();
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
            static int i = 0;
            if(ImGui::RadioButton("Steam", &i, 0)){
                ChairManager::Get().GetGamePathUtil()->SetGamePlatform(GamePath::GamePlatform::Steam);
            }
            if(ImGui::RadioButton("GOG", &i, 1)){
                ChairManager::Get().GetGamePathUtil()->SetGamePlatform(GamePath::GamePlatform::Gog);
            }
            if(ImGui::RadioButton("Epic", &i, 2)){
                ChairManager::Get().GetGamePathUtil()->SetGamePlatform(GamePath::GamePlatform::Epic);
            }
            if(ImGui::RadioButton("Microsoft Store", &i, 3)){
                ChairManager::Get().GetGamePathUtil()->SetGamePlatform(GamePath::GamePlatform::Microsoft);
            }
            ImGui::Text("GAME BIN: %s", ChairManager::Get().GetGamePathUtil()->GetGameBinDir());
            ImGui::Text("GAME EXE: %s", ChairManager::Get().GetGamePathUtil()->GetGameExePath());
            ImGui::Text("GAME DLL: %s", ChairManager::Get().GetGamePathUtil()->GetGameDllPath());
            ImGui::Text("GAME PDB: %s", ChairManager::Get().GetGamePathUtil()->GetGameDllPDBPath());
            ImGui::Text("GAME BACKUP: %s", ChairManager::Get().GetGamePathUtil()->GetGameDllBackupPath());
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

        if(ImGui::CollapsingHeader("Merging V3")){
            ImGui::Checkbox("Force Level Pack", &m_pChairMerger->m_bForceLevelPack);
            ImGui::Checkbox("Force Localization Pack", &m_pChairMerger->m_bForceLocalizationPack);
            ImGui::Checkbox("Force Vanilla Pack", &m_pChairMerger->m_bForceVanillaPack);
            if(ImGui::Button("Pre Merge")){
                m_pChairMerger->PreMerge();
            }
            if(ImGui::Button("Merge")){
                m_pChairMerger->Merge();
            }
            if(ImGui::Button("Post Merge")){
                m_pChairMerger->PostMerge();
            }
            if(ImGui::BeginTable("Level Checksums Debug", 2, ImGuiTableFlags_ScrollY, ImVec2(0, 300))){
                ImGui::TableSetupScrollFreeze(0, 1);
                ImGui::TableSetupColumn("Level", ImGuiTableColumnFlags_WidthFixed);
                ImGui::TableSetupColumn("Checksum");
                ImGui::TableHeadersRow();
                for(auto &level: m_pChairMerger->m_LevelFileChecksums){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("%s", level.first.u8string().c_str());
                    ImGui::TableNextColumn();
                    ImGui::Text("%s", SHA256::toString(level.second.data()).c_str());
                }
                ImGui::EndTable();
            }
            static std::unordered_map<std::string, bool> modConfigNamespace;
            if(ImGui::BeginTable("Mod Configs", 2, ImGuiTableFlags_ScrollY, ImVec2(0, 300))){
                ImGui::TableSetupScrollFreeze(0, 1);
                ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
                ImGui::TableSetupColumn("Value");
                ImGui::TableHeadersRow();
                for(auto &variableName : modConfigNamespace){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("%s", variableName.first.c_str());
                    ImGui::TableNextColumn();
                    ImGui::Text("%s", variableName.second ? "true" : "false");
                }
                ImGui::EndTable();
            }
            static std::string modName = "TheChair.ExampleMod";
            ImGui::InputText("Mod Name", &modName);
            if(ImGui::Button("GetModConfigNamespace")){
                modConfigNamespace = m_ConfigManager.getModSpaceBooleanVariables(modName);
            }
        }
        if(ImGui::CollapsingHeader("ID Testing")){
            if(ImGui::Button("List All Files with id attribute by policy")){
                std::ofstream id_name_file("id_name_files.txt");
                std::ofstream id_file("id_files.txt");
                std::ofstream attribute_file("attribute_list.txt");
                std::set<std::string> allAttributeNames;
                for(auto & dir: fs::recursive_directory_iterator("PreyFiles")){
                    auto relativePath = fs::relative(dir, "PreyFiles");
                    auto policy = m_pChairMerger->GetFileMergingPolicy(relativePath, "");
                    if(policy.policy == MergingPolicy::identification_policy::match_attribute){
                        bool hasId = false, hasName = false;
                        for(auto & attributeMatch: policy.attributeMatches){
                            if(boost::iequals(attributeMatch.attribute_name, "id") || boost::iequals(attributeMatch.attribute_name, "ArchetypeId")){
                                hasId = true;
                            }
                            if(boost::iequals(attributeMatch.attribute_name, "name") || boost::iequals(attributeMatch.attribute_name, "ArchetypeName")){
                                hasName = true;
                            }
                            allAttributeNames.insert(attributeMatch.attribute_name);
                        }
                        if(hasId && hasName){
                            id_name_file << relativePath << std::endl;
                        }
                        if(hasId){
                            id_file << relativePath << std::endl;
                        }
                    }
                }
                for(auto & attribute: allAttributeNames){
                    attribute_file << attribute << std::endl;
                }
                id_name_file.close();
                id_file.close();
                attribute_file.close();
            }
            if(ImGui::Button("Load Id Name Map")){
                m_pChairMerger->LoadIdNameMap();
            }
            ImGui::Text("Id Name Map Size: %llu", m_pChairMerger->m_NameToIdMap.size());
            if(ImGui::BeginTable("Id Name Map", 2, ImGuiTableFlags_ScrollY | ImGuiTableFlags_Resizable, ImVec2(0, 300))){
                ImGui::TableSetupScrollFreeze(0, 1);
                ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
                ImGui::TableSetupColumn("Value");
                ImGui::TableHeadersRow();
                for(auto &variableName : m_pChairMerger->m_NameToIdMap){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("%s", variableName.first.c_str());
                    ImGui::TableNextColumn();
                    ImGui::Text("%llu", variableName.second);
                }
                ImGui::EndTable();
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
    auto deployPhase = m_pChairMerger->GetDeployPhase();
    auto deployStep = m_pChairMerger->GetDeployStep();

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
        // RemovingOldOutput, CopyingBaseFiles, MergingLegacyMods, MergingMods, RemovingOldPatches, PackingLevelFiles, CopyingLevelFiles, PackingLocalization, PackingMainPatch, CopyingMainPatch, Done, Invalid
        ImGui::Text("Deploying Mods, Please Wait:");
        ImGui::Separator();
        if(!m_pChairMerger->DeployFailed())
            ImGui::Text("%s", ChairMerger::GetDeployPhaseString(deployPhase).c_str());
        else
            ImGui::TextColored(errorColor, "FAILED");
        ImVec2 childSize = ImGui::GetContentRegionAvail();
        if(m_pChairMerger->DeployFailed()){
            childSize.y -= ImGui::GetFrameHeightWithSpacing();
        }
        ImGui::BeginChild("Progress Steps", childSize);
        if(deployStep >= DeployStep::RemovingOldOutput){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::RemovingOldOutput).c_str());
        }
        if(deployStep >= DeployStep::CopyingBaseFiles){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::CopyingBaseFiles).c_str());
        }
        if(deployStep >= DeployStep::LoadingPatchChecksums){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::LoadingPatchChecksums).c_str());
        }
        ImGui::BeginDisabled(m_pChairMerger->m_bForceVanillaPack);
        if(deployStep >= DeployStep::MergingLegacyMods){
            ImGui::Text("%s", ChairMerger::GetDeployStepString(DeployStep::MergingLegacyMods).c_str());
        }
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
        if(m_pChairMerger->DeployFailed()){
            ImGui::PushStyleColor(ImGuiCol_Text, errorColor.operator ImU32());
            ImGui::Text("Deploy Failed");
            ImGui::TextWrapped("%s", m_pChairMerger->GetDeployFailedMessage().c_str());
            ImGui::PopStyleColor();
        }
        ImGui::EndChild();
        if(m_pChairMerger->DeployFailed()){
            if(ImGui::Button("Close")){
                ImGui::CloseCurrentPopup();
                m_State = State::MainWindow;
                m_pChairMerger->m_DeployStep = DeployStep::Invalid;
                m_pChairMerger->m_DeployPhase = DeployPhase::Invalid;
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
        ImGui::Checkbox("Force Levels to be Repacked", &m_pChairMerger->m_bForceLevelPack);
        ImGui::SameLine();
        ImGuiUtils::HelpMarker("This will force all levels to be repacked, even if they haven't changed. This may be useful if you are having issues with levels not updating properly. (This will take longer to deploy)");
        ImGui::Checkbox("Force Localization to be Repacked", &m_pChairMerger->m_bForceLocalizationPack);
        ImGui::SameLine();
        ImGuiUtils::HelpMarker("This will force all localization files to be repacked, even if they haven't changed. This may be useful if you are having issues with localization not updating properly. (This will take longer to deploy)");
        ImGui::Checkbox("Force Main Patch to be Repacked", &m_pChairMerger->m_bForceMainPatchPack);
        ImGui::SameLine();
        ImGuiUtils::HelpMarker("This will force the main patch to be repacked, even if it hasn't changed. This may be useful if you are having issues with the main patch not updating properly. (This will take longer to deploy)");
        ImGui::Separator();
        ImGui::Checkbox("Pack only Vanilla Files (No Mods)", &m_pChairMerger->m_bForceVanillaPack);
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
    }
    if(deployStep <= DeployStep::Invalid){
        ImGui::OpenPopup("Deploy Options");
    } else {
        ImGui::OpenPopup("Deploying Mods");
    }

    if (IsFutureReady(m_DeployTaskFuture))
    {
        m_DeployTaskFuture.get();

        if(!m_pChairMerger->DeployFailed()) {
            m_State = State::MainWindow;
            m_pChairMerger->SetDeployStep(DeployStep::Invalid);
            m_pChairMerger->SetDeployPhase(DeployPhase::Invalid);
        }

        return;
    }
}

void ChairManager::RunAsyncDeploy() {
    if(m_pChairMerger->GetDeployStep() <= DeployStep::Invalid && m_pChairMerger->GetDeployPhase() <= DeployPhase::Invalid) {
        m_DeployTaskFuture = m_pChairMerger->LaunchAsyncDeploy();
    } else {
        overlayLog(severityLevel::error, "Mods are already being deployed");
    }
}

void ChairManager::OpenInstallModDialog(bool isLegacy)
{
    m_bInstallLegacyMod = isLegacy;
    WinShell::DialogOptions fileDialogOpts;

    if (!m_bInstallLegacyMod)
    {
        fileDialogOpts.title = "Choose Mod File...";
        fileDialogOpts.fileTypes.push_back({ "Mod Archive (*.zip; *.7z)", "*.zip;*.7z" });
    }
    else
    {
        fileDialogOpts.title = "Choose Legacy Mod File...";
        fileDialogOpts.fileTypes.push_back({ "Legacy Mod File (*.pak)", "*.pak" });
    }

    WinShell::ImShowFileOpenDialog("ChooseModFile", fileDialogOpts);
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

void ChairManager::launchGame() {
    log(severityLevel::info, "Launching game");
    fs::path exePath = GetGamePath() / ChairManager::Get().GetGamePathUtil()->GetGameExePath();
    m_chairloaderLaunchOptions = fs::path(m_customArgs + " ").wstring();
    // bool m_bLoadChairloader -nochair
    //        m_bLoadEditor -editor
    //        m_bDevMode -devmode
    //        m_bNoRandom -norandom
    if(!m_bLoadChairloader){
        m_chairloaderLaunchOptions += L" -nochair";
    }
    if(m_bLoadEditor){
        m_chairloaderLaunchOptions += L" -editor";
    }
    if(m_bDevMode){
        m_chairloaderLaunchOptions += L" -devmode";
    }
    if(m_bNoRandom){
        m_chairloaderLaunchOptions += L" -norandom";
    }
    if(m_bTrainer){
        m_chairloaderLaunchOptions += L" -trainer";
    }
    // launch the game
    fs::path command = exePath.wstring() + m_chairloaderLaunchOptions;
    log(severityLevel::trace, "Launching game with command: %s", command.u8string().c_str());
    STARTUPINFOW si = {sizeof(STARTUPINFO)};
    PROCESS_INFORMATION pi;
    if(CreateProcessW(nullptr, command.wstring().data(), nullptr, nullptr, false, DETACHED_PROCESS, nullptr, nullptr, &si, &pi)){
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
    return m_pGamePath->GetGamePath();
}

void ChairManager::GTestInit() {
    Init();
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

std::string ChairManager::GetModDisplayName(const std::string& modName)
{
    for (const auto& i : GetMods())
    {
        if (i.modName == modName)
            return i.displayName;
    }

    return std::string();
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
