//
// Created by theli on 8/1/2022.
//

#include <iostream>
#include <sstream>
#include "ModLoader.h"
#include "UI.h"
#include "GamePathDialog.h"
#include "GameVersion.h"
#include "PathUtils.h"
#include "winver.h"
#include "ChairInstallWizard.h"
#include "ChairUninstallWizard.h"
#include "../ChairLoader/GUIUtils.h"
#include "BinaryVersionCheck.h"

static std::string ErrorMessage;
static bool showErrorPopup = false;
static bool showDemo = false;

static const char* MAIN_WINDOW_NAME = "Chairloader Mod Manager";

void ModLoader::Draw() {
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
    default:
        assert(!("Invalid UI state"));
        std::abort();
        break;
    }

    if (!bDraw)
        UI::RequestExit();
}


void ModLoader::LoadModLoaderConfig()
{
    if (ChairloaderModLoaderConfigFile.load_file(ChairloaderModLoaderConfigPath.wstring().c_str())) {
        if (ChairloaderModLoaderConfigFile.first_child().child("PreyPath")) {
            fs::path path(ChairloaderModLoaderConfigFile.first_child().child("PreyPath").text().as_string());

            if (PathUtils::ValidateGamePath(path))
            {
                SetGamePath(path);
            }
        }
    }
    else {
        log(severityLevel::error, "ChairloaderModLoader config file not found, creating new");
        ChairloaderModLoaderConfigFile.reset();
        ChairloaderModLoaderConfigFile.append_child("ChairloaderModLoader");
        ChairloaderModLoaderConfigFile.first_child().append_child("PreyPath").text().set(PreyPath.wstring().c_str());
        ChairloaderModLoaderConfigFile.save_file(ChairloaderModLoaderConfigPath.wstring().c_str());
    }
    log(severityLevel::info, "Chairloader Mod Loader Config File Loaded");
}

void ModLoader::SetGamePath(const fs::path& path)
{
    assert(path.empty() || PathUtils::ValidateGamePath(path));

    PreyPath = path;
    m_PreyPathString = path.u8string();
    pugi::xml_node cfg = ChairloaderModLoaderConfigFile.first_child();

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

void ModLoader::SwitchToGameSelectionDialog(const fs::path& gamePath)
{
    m_State = State::LocateGameDir;
    m_pGamePathDialog = std::make_unique<GamePathDialog>();
    m_pGamePathDialog->SetGamePath(gamePath);
}

void ModLoader::DrawGamePathSelectionDialog(bool* pbIsOpen)
{
    GamePathDialog::Result result = m_pGamePathDialog->ShowDialog(MAIN_WINDOW_NAME, pbIsOpen);

    if (result == GamePathDialog::Result::Ok)
    {
        log(severityLevel::info, "User selected game path: %s", m_pGamePathDialog->GetGamePath().u8string().c_str());
        SetGamePath(m_pGamePathDialog->GetGamePath());
        saveModLoaderConfigFile();
        m_pGamePathDialog.reset();
        SwitchToInstallWizard();
    }
    else if (result == GamePathDialog::Result::Cancel)
    {
        *pbIsOpen = false;
        m_pGamePathDialog.reset();
    }
}

void ModLoader::SwitchToInstallWizard()
{
    if (!verifyChairloaderInstalled())
    {
        log(severityLevel::info, "Chairloader not found, starting the wizard");
        m_State = State::InstallWizard;
    }
#ifndef _DEBUG
    else if(VersionCheck::getInstalledChairloaderVersion() < VersionCheck::getPackagedChairloaderVersion()) {
        log(severityLevel::info, "Chairloader version mismatch, running install wizard");
        m_State = State::InstallWizard;
    }
#endif
    else
    {
        log(severityLevel::info, "Chairloader version %s found, %s is packaged with this installer",
            VersionCheck::getInstalledChairloaderVersion().String().c_str(),
            VersionCheck::getPackagedChairloaderVersion().String().c_str());
        m_State = State::MainWindow;
    }
}

void ModLoader::DrawInstallWizard(bool* pbIsOpen)
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

void ModLoader::DrawMainWindow(bool* pbIsOpen)
{
    static bool m_bShowUpdatePopup;
    m_pGameVersion->Update();

    ImGuiWindowFlags windowFlags =
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_MenuBar;

    ImGui::SetNextWindowSize({ 800, 500 });
    ImGui::SetNextWindowBgAlpha(1.0f);
    // ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    // ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));
    if (!ImGui::Begin(MAIN_WINDOW_NAME, pbIsOpen, windowFlags))
    {
        ImGui::End();
    }

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Files", true)) {
            if (ImGui::MenuItem("Install Mod")) {
                ImGuiFileDialog::Instance()->OpenModal("ChooseModFile", "Choose Mod File", "Mod Archive (*.zip *.7z){.zip,.7z}", modToLoadPath.u8string(), 1, nullptr);
            }
            ImGui::Separator();
            if(ImGui::MenuItem("Uninstall Chairloader")){
                SwitchToUninstallWizard();
            }
#ifdef _DEBUG
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
                RunAsyncDeploy();
            }
            ImGui::EndMenu();
        }
        // Print test overlay log messages for each severity level
#ifdef _DEBUG
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
        if(VersionCheck::getPackagedChairloaderVersion() > VersionCheck::getInstalledChairloaderVersion()){
            ImGui::Text("Chairloader is out of date!");
            ImGui::Text("Installed: %s", VersionCheck::getInstalledChairloaderVersion().String().c_str());
            ImGui::Text("Packaged: %s", VersionCheck::getPackagedChairloaderVersion().String().c_str());
            if(ImGui::Button("Update Chairloader")){
                SwitchToInstallWizard();
            }
        } else {
            ImGui::Text("Chairloader is up to date!");
            ImGui::Text("Installed: %s", VersionCheck::getInstalledChairloaderVersion().String().c_str());
            ImGui::Text("Packaged: %s", VersionCheck::getPackagedChairloaderVersion().String().c_str());
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
        DrawAssetView();
        DrawLog();
        DrawDLLSettings();
#ifdef _DEBUG
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

void ModLoader::DrawModList() {
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
                            auto storedpos = ImGui::GetCursorPosY() + 4;
                            ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3.5);
                            if (ImGui::Selectable(("##Selectable" + ModEntry.modName).c_str(),
                                                  selectedMod == ModEntry.modName, 0,
                                                  ImVec2{ImGui::GetColumnWidth(), 27.0f}))
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
                                        log(severityLevel::info, "Deleting %s/Mods/%s/", PreyPath.u8string(),
                                            ModEntry.modName);
                                        fs::remove_all(PreyPath / "Mods" / ModEntry.modName);
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
            if(ImGui::BeginChild("Mod Info", {0, 260})) {
                auto ModSelect = std::find(ModList.begin(), ModList.end(), selectedMod);
                if (ModSelect != ModList.end()) {
                    if (!ModSelect->installed)
                        ImGui::BeginDisabled();
                    ImGui::TextWrapped("%s", ModSelect->displayName.c_str());
                    ImGui::Text("By: %s", ModSelect->author.c_str());
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
                RunAsyncDeploy();
            }
            ImGui::SameLine();
            ImGuiUtils::HelpMarker("Merge, patch, and copy the files to the game directory.");
            ImGui::Separator();
            if(ImGui::Button("Install Mod From File")){
               ImGui::OpenPopup("Install Mod From File");
            }
        }
        if(ImGui::BeginPopupModal("Install Mod From File", nullptr, ImGuiWindowFlags_AlwaysAutoResize)){
            static int installType = 0;
            ImGui::RadioButton("Chairloader Mod (.zip, .7z)", &installType, 0);
            ImGui::RadioButton("Legacy Mod (.pak)", &installType, 1);

            if(ImGui::Button("Select File")){
                m_bInstallLegacyMod = installType == 1;
                if(!m_bInstallLegacyMod)
                    ImGuiFileDialog::Instance()->OpenModal("ChooseModFile", "Choose Mod File", "Mod Archive (*.zip *.7z){.zip,.7z}", fileToLoad.u8string(), 1, nullptr);
                else
                    ImGuiFileDialog::Instance()->OpenModal("ChooseModFile", "Choose Legacy Mod File", "Legacy Mod File (*.pak){.pak}", fileToLoad.u8string(), 1, nullptr);
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
        ImVec2 maxSize = {(float)GetSystemMetrics(SM_CXSCREEN), (float)GetSystemMetrics(SM_CYSCREEN)};
        ImVec2 minSize = {maxSize.x * 0.3f, maxSize.y * 0.3f};
        if(ImGuiFileDialog::Instance()->Display("ChooseModFile", ImGuiWindowFlags_None, minSize, maxSize)){
            // action if OK
            if (ImGuiFileDialog::Instance()->IsOk())
            {
                try {
                    modToLoadPath = ImGuiFileDialog::Instance()->GetCurrentPath();
                    fileToLoad = ImGuiFileDialog::Instance()->GetFilePathName();
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
            ImGuiFileDialog::Instance()->Close();
        }
        ImGui::EndTabItem();
    }
}

void ModLoader::DrawDLLSettings() {
    if(ImGui::BeginTabItem("Settings")){
        ImGui::InputText("Prey Path", &m_PreyPathString, ImGuiInputTextFlags_ReadOnly);

        if(ImGui::Button("Change Path")){
            m_pGamePathDialog = std::make_unique<GamePathDialog>();
            m_pGamePathDialog->SetGamePath(PreyPath);
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
                saveModLoaderConfigFile();
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

void ModLoader::DrawAssetView() {
    if(ImGui::BeginTabItem("Asset View")){
        if(ImGui::BeginChild("Asset List", ImVec2(ImGui::GetContentRegionAvail().x * 0.8f, 0), false)) {
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
                                TreeNodeWalkDirectory(fs::path(PreyPath / "Mods" / mod.modName), mod.modName);
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
                                TreeNodeWalkDirectory(fs::path(PreyPath / "Mods" / "Legacy" / mod), mod);
                            }
                            ImGui::EndTable();
                        }
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
                selectedFile.clear();
            }
            if(!selectedFile.empty()){
                ImGui::Text("%s", selectedFile.filename().u8string().c_str());
            }
        }
        ImGui::EndChild();
        ImGui::EndTabItem();
    }
}

void ModLoader::DrawDeploySettings() {
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
        if(ImGui::Button("Test Merge")) {
            mergeXMLDocument(BasePath, OverridePath, OriginalPath, std::string());
        }
        if(ImGui::Button("Save Copy")){
//            log(severityLevel::debug, "Save Result: %i", BaseDoc.save_file(R"(C:\Program Files (x86)\Steam\steamapps\common\Prey\Mods\ExampleMod\MergeTest_NEW.xml)"));
        }
        ImGui::EndTabItem();
        if(ImGui::Button("Merge XML Files")){
            mergeXMLFiles();
        }
        if(ImGui::Button("Pack Chairloader Patch")){
            packChairloaderPatch();
        }
        if(ImGui::Button("Copy Chairloader Patch")){
            copyChairloaderPatch();
        }
    }
}

void ModLoader::DrawLog() {
    logMutex.lock();
    if(ImGui::BeginTabItem("Log")){
        static std::vector<std::string> filterNames = {"trace", "debug", "info", "warning", "error", "fatal"};
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
                ImGui::EndTable();
            }
        }
        ImGui::EndChild();
        ImGui::EndTabItem();
    }
    logMutex.unlock();
}



fs::path ModLoader::getConfigPath(std::string &modName) {
    return fs::path{ (PreyPath / "Mods/config" / modName / ".xml").c_str() };
}

fs::path ModLoader::getDefaultConfigPath(std::string &modName) {
    return fs::path{ (PreyPath / "Mods" / modName / modName / "_default.xml").c_str() };
}
bool ModLoader::LoadModInfoFile(fs::path directory, Mod *mod, bool allowDifferentDirectory) {
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

void ModLoader::LoadModsFromConfig() {
    for(auto &PrevMod : ModListNode){
        fs::path modPath = PreyPath / "Mods" / PrevMod.name();
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
void ModLoader::DetectNewMods() {
    for(auto &directory : fs::directory_iterator(fs::path(PreyPath.u8string() + "/Mods/"))){
        if(directory.path() != PreyPath / "Mods/config" && directory.path() != PreyPath / "Mods/Legacy") {
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

void ModLoader::loadModInfoFiles() {
    ModList.clear();
    LegacyModList.clear();
    // load previously loaded (assumedly) valid config
    LoadModsFromConfig();
    DetectNewMods();
    overlayLog(severityLevel::info, "Loaded %i mods", ModList.size());
//    serializeLoadOrder();
    try {
        for (auto &directory: fs::directory_iterator(PreyPath / "Mods/Legacy")) {
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

ModLoader::ModLoader() {
    assert(!m_spInstance);
    m_spInstance = this;
    packagedChairloaderVersion = VersionCheck::getPackagedChairloaderVersion();
    LoadModLoaderConfig();

    if (PreyPath.empty() || !PathUtils::ValidateGamePath(PreyPath))
        SwitchToGameSelectionDialog(PreyPath);
    else
        SwitchToInstallWizard();
}

ModLoader::~ModLoader() {
    flushFileQueue();
    saveModLoaderConfigFile();

    assert(m_spInstance == this);
    m_spInstance = nullptr;
}


void ModLoader::FindMod(Mod* modEntry) {
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




void ModLoader::SaveMod(ModLoader::Mod *modEntry) {
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


void ModLoader::flushFileQueue() {
    logMutex.lock();
    std::ofstream fileStream;
    fileStream.open("ChairloaderModLoader.log", std::ios_base::app);
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
        log(severityLevel::error, "Error, could not open ChairloaderModLoader.log");
    }
    logMutex.unlock();
}

void ModLoader::Update() {
    static time_t lastFileTime;
    if(time(nullptr) - lastFileTime > 10){
        time(&lastFileTime);
        flushFileQueue();
    }
}

void ModLoader::DeployForInstallWizard()
{
    assert(m_DeployState == DeployState::Invalid);
    mergeXMLFiles(true);

    if (!packChairloaderPatch())
        throw std::runtime_error("Failed to pack patch_chairloader.pak");
    if (!copyChairloaderPatch())
        throw std::runtime_error("Failed to copy patch_chairloader.pak");

    m_DeployLogMutex.lock();
    m_DeployState = DeployState::Invalid;
    m_DeployLogMutex.unlock();
}

bool ModLoader::TreeNodeWalkDirectory(fs::path path, std::string modName) {
    if(is_directory(path)){
        if(ImGui::TreeNode(path.u8string().c_str(), "%s", path.filename().u8string().c_str())){
            for(auto&childPath: fs::directory_iterator(path)) {
                TreeNodeWalkDirectory(childPath.path(), modName);
            }
            ImGui::TreePop();
            return false;
        }
    } else if(is_regular_file(path)){
        ImGui::PushID(path.u8string().c_str());
        if(ImGui::Selectable(path.filename().u8string().c_str(), path == selectedFile)){
            selectedFile = path;
        }
        ImGui::PopID();
        return true;
    }
    return false;
}

int ModLoader::getNextSafeLoadOrder() {
    nextSafeLoadOrder++;
    int safe = nextSafeLoadOrder;
    log(severityLevel::debug, "Next Safe Load Order: %i", nextSafeLoadOrder);
    return safe;
}

void ModLoader::incrementNextSafeLoadOrder(int loadOrder) {
    if(loadOrder <= nextSafeLoadOrder)
        nextSafeLoadOrder = loadOrder + 1;
    log(severityLevel::debug, "New Safe Load Order: %i", nextSafeLoadOrder);
}

bool ModLoader::checkSafeLoadOrder(int i) {
    return loadOrder.find(i) == loadOrder.end();
}

void ModLoader::serializeLoadOrder() {
    int i = 0;
    for(auto &mod : ModList){
        mod.loadOrder = i;
        i++;
    }
    nextSafeLoadOrder = i + 1;
}

void ModLoader::SaveAllMods() {
    for(auto &mod : ModList){
        if(mod.installed) {
            ModListNode.remove_child(mod.modName.c_str());
            SaveMod(&mod);
        }
    }
    saveChairloaderConfigFile();
}

void ModLoader::InstallMod(std::string &modName) {
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

void ModLoader::UninstallMod(std::string &modName) {
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

void ModLoader::InstallModFromFile(fs::path path, fs::path fileName) {
//    char shortPath[MAX_PATH];
//    GetShortPathNameA(fileName.c_str(), shortPath, MAX_PATH);
    std::wstring commandArgs = L".\\7za.exe x \"";
//    commandArgs +=  path.wstring();
//    commandArgs += L"\\";
    commandArgs += fileName.wstring();
    commandArgs += L"\" -otemp -spe";
//    log(severityLevel::trace, "Command args: %s", commandArgs.c_str());
//    printf("Command args: %ls", commandArgs.c_str());
    STARTUPINFOW si = {sizeof(STARTUPINFO)};
    PROCESS_INFORMATION pi;
    //DONE: move to CreateProcessA instead of system()
//    auto si = new STARTUPINFOA;
//    auto pi = new PROCESS_INFORMATION;
//    LPSTR cmdList[] = {TEXT("x"), TEXT((char*)fileName.c_str()), TEXT("-otemp")};
//    if(CreateProcessA(nullptr, args, nullptr, nullptr, true, 0, nullptr, nullptr, si, pi))
//        WaitForSingleObject(pi->hProcess, INFINITE);
    commandArgs.resize(MAX_PATH);
    if(CreateProcessW(nullptr, &commandArgs[0], nullptr, nullptr, false, CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi)) {
        log(severityLevel::debug, "7Zip operation started");
        WaitForSingleObject(pi.hProcess, INFINITE);
        log(severityLevel::debug, "7Zip process finished");
        LPDWORD exitCode = new DWORD;
        GetExitCodeProcess(pi.hProcess, exitCode);
        log(severityLevel::trace, "7Zip exit code: %i", *exitCode);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        log(severityLevel::error, "Error, 7za.exe failed to execute %i", GetLastError());
        overlayLog(severityLevel::error, "Mod Installation Failed: could not decompress %s", fileName);
        return;
    }

    if(!m_bInstallLegacyMod) {
        if (exists(fs::path("./temp/ModInfo.xml"))) {
            auto mod = new Mod;
            if (LoadModInfoFile(fs::path("./temp"), mod, true)) {
                try {
                    fs::copy("./temp/", PreyPath / "Mods" / mod->modName,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                    log(severityLevel::info, "Mod Installation Succeeded: %s loaded", mod->modName);
                    DetectNewMods();
                    InstallMod(mod->modName);
                } catch (std::exception &exc) {
                    std::cerr << exc.what() << std::endl;
                    log(severityLevel::error, "Mod Installation Failed: %s", exc.what());
                }
            }
        } else {
            log(severityLevel::error, "Mod Installation Failed: No ModInfo.xml file found");
        }
    } else {
        if (exists(fs::path("./temp/"))) {
            try {
                auto BaseModFolder = fileName.filename().replace_extension("");
                log(severityLevel::info, "Installing Legacy Mod: %s", BaseModFolder.u8string().c_str());
                fs::copy("./temp/", PreyPath / "Mods" / "Legacy" / BaseModFolder,
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
    fs::remove_all("./temp/");
}

void ModLoader::EnableMod(std::string modName, bool enabled) {
    auto mod = std::find(ModList.begin(), ModList.end(),modName);
    if(mod != ModList.end()) {
        if(mod->installed)
            mod->enabled = enabled;
    }
}

bool ModLoader::DeployMods() {
    mergeXMLFiles();
    saveChairloaderConfigFile();
    if(packChairloaderPatch()){
        if(copyChairloaderPatch()){
            m_DeployLogMutex.lock();
            m_DeployState = DeployState::Done;
            m_DeployLogMutex.unlock();
            overlayLog(severityLevel::info, "Mods Deployed");
//            m_State = State::MainWindow;
            return true;
        }
    }
//    m_State = State::MainWindow;
    return false;
}


//FIXME: add support for merging localization files
pugi::xml_document
ModLoader::mergeXMLDocument(fs::path basePath, fs::path overridePath, fs::path originalPath, std::string modName) {
    pugi::xml_document modFile;
    pugi::xml_document originalFile;
    pugi::xml_document outputFile;
    auto modResult = modFile.load_file(overridePath.wstring().c_str());
    auto originalResult = originalFile.load_file(originalPath.wstring().c_str());
    auto outputResult = outputFile.load_file(basePath.wstring().c_str());
    auto baseRootNode = outputFile.first_child();
    auto overrideRootNode = modFile.first_child();
    auto originalRootNode = originalFile.first_child();
    baseRootNode.append_child(pugi::node_comment).set_value(("Mod: " + modName).c_str());
#ifdef _DEBUG
    log(severityLevel::debug, "Library Root Nodes:\nBase Root Node: %s\nOverride Root Node: %s\nOriginal Root Node: %s", baseRootNode.name(), overrideRootNode.name(), originalRootNode.name());
#endif
    if(overrideRootNode) {
        for (auto &overrideNode: overrideRootNode) {
            //Case: Overwrite
            auto baseNode = baseRootNode.find_child_by_attribute("Name", overrideNode.attribute("Name").value());
            auto originalNode = originalRootNode.find_child_by_attribute("Name", overrideNode.attribute("Name").value());
            if (!mergeXMLNode(baseNode, overrideNode, originalNode)) {
                baseRootNode.append_copy(overrideNode);
            }
        }
    }
    outputFile.save_file(basePath.wstring().c_str());
    return {};
}

bool ModLoader::mergeXMLNode(pugi::xml_node &baseNode, pugi::xml_node &overrideNode, pugi::xml_node originalNode) {
    if (baseNode) {
        //Now compare the content of override against the content of arkOriginal
        if(originalNode) {
            std::stringstream originalContent, overrideContent;
            originalNode.print(originalContent);
            overrideNode.print(overrideContent);
            log(severityLevel::debug, "Original Content: %s\nOverride Content: %s", originalContent.str().c_str(), overrideContent.str().c_str());
            if(std::string(originalContent.str()) == std::string(overrideContent.str())) {
                log(severityLevel::trace, "Node %s is identical to Ark Original", overrideNode.attribute("Name").value());
                //DO NOT OVERWRITE
            } else {
                log(severityLevel::trace, "Node %s is different from Ark Original", overrideNode.attribute("Name").value());
                baseNode.text().set(overrideNode.text().get());
                for(auto & attribute : overrideNode.attributes()){
                    log(severityLevel::trace, "Overwriting attribute %s", attribute.name());
                    if(baseNode.attribute(attribute.name()))
                        baseNode.attribute(attribute.name()).set_value(attribute.value());
                    else
                        baseNode.append_attribute(attribute.name()).set_value(attribute.value());
                }
            }
        // default overwrite
        } else {
            log(severityLevel::trace, "Overwriting original node %s", overrideNode.attribute("Name").value());
            baseNode.text().set(overrideNode.text().get());
            for(auto & attribute : overrideNode){
                if(baseNode.attribute(attribute.name()))
                    baseNode.attribute(attribute.name()).set_value(attribute.value());
                else
                    baseNode.append_attribute(attribute.name()).set_value(attribute.value());
            }
        }
    } else {
        //Case: Add
        log(severityLevel::trace, "Adding node %s", overrideNode.attribute("Name").value());
        return false;
    }
    return true;
}

void ModLoader::mergeXMLFiles(bool onlyChairPatch) {
    // Remove old output files
    m_DeployLogMutex.lock();
    m_DeployState = DeployState::RemovingOldOutput;
    m_DeployLogMutex.unlock();
    fs::remove_all("./Output/");
    fs::create_directory("./Output/");

    // Copy Base Files
    m_DeployLogMutex.lock();
    m_DeployState = DeployState::CopyingBaseFiles;
    m_DeployLogMutex.unlock();

    bool doLevelPatches = false;
    for (Mod& mod : ModList) {
        if (mod.enabled && mod.hasLevelXML)
        {
            doLevelPatches = true;
            break;
        }
    }
    if (doLevelPatches) {
        try {
            fs::copy(".\\PreyFiles\\Levels", ".\\Output\\Levels", fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        } catch (std::exception &exc) {
            std::cerr << exc.what() << std::endl;
            overlayLog(severityLevel::error, "Could not copy Levels folder: %s", exc.what());
            return;
        }
    }
    try {
        fs::create_directories("./Output/Localization/English_xml");
        fs::copy("./PreyFiles/Localization/English_xml_patch/", "./Output/Localization/English_xml/",
                 fs::copy_options::recursive | fs::copy_options::overwrite_existing);
    } catch (std::exception &exc) {
        std::cerr << exc.what() << std::endl;
        overlayLog(severityLevel::error, "Could not copy Localization folder: %s", exc.what());
        return;
    }
    //Chairloader Patch
    try{
        fs::copy("./ChairloaderPatch/", "./Output/", fs::copy_options::recursive | fs::copy_options::overwrite_existing);
    } catch(std::exception &exc) {
        std::cerr << exc.what() << std::endl;
        overlayLog(severityLevel::error, "Error copying base files: %s", exc.what());
        return;
    }

    if (!onlyChairPatch)
    {
        //merge legacy mods
        m_DeployLogMutex.lock();
        m_DeployState = DeployState::MergingLegacyMods;
        m_DeployLogMutex.unlock();
        for (auto& directory : fs::directory_iterator(PreyPath / "Mods/Legacy")) {
            if (fs::is_directory(directory)) {
                log(severityLevel::trace, "Merging Legacy Mod %s", directory.path().u8string().c_str());
                mergeDirectory("", directory.path().filename().u8string(), true);
            }
        }
        //registered mods
        m_DeployLogMutex.lock();
        m_DeployState = DeployState::MergingMods;
        m_DeployLogMutex.unlock();
        for (auto& mod : ModList) {
            if (mod.installed && mod.enabled && verifyDependenciesEnabled(mod.modName)) {
                mergeDirectory("", mod.modName);
                ModListNode.child(mod.modName.c_str()).child("deployed").text().set(true);
            }
        }
    }
}

float overlayLogPadding = 2.0f;
static std::string logEntryToDelete;
static float accumulatedHeight = 0.0f;
void ModLoader::DrawOverlayLog(){
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

void ModLoader::OverlayLogElement(LogEntry entry) {
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

void ModLoader::mergeDirectory(fs::path path, std::string modName, bool legacyMod) {
    fs::path modPath;
    if(legacyMod) {
        modPath = PreyPath / "Mods/Legacy" / modName / path;
    } else {
        modPath = PreyPath / "Mods" / modName / "Data" / path.u8string();
    }
    fs::path originalPath = "./PreyFiles" / path;
    fs::path outputPath = "./Output" / path;
    try {
        // merge level files anyway
        if (is_directory(modPath)/* && modPath != PreyPath.u8string() + "/Mods/" + modName + "/Data/Levels"*/) {
            log(severityLevel::trace, "Exploring directory %s", modPath.u8string().c_str());
            if(!fs::exists(outputPath)) {
                fs::create_directories(outputPath);
            }
            for (auto directory: fs::directory_iterator(modPath)) {
                mergeDirectory(path / directory.path().filename(), modName, legacyMod);
            }
        } else if (is_regular_file(modPath)) {
            if(modPath.extension() == ".xml") {
                if (!fs::exists(outputPath) && fs::exists(originalPath)) {
                    fs::copy_file(originalPath, outputPath);
                }
                log(severityLevel::trace, "Merging %s", modPath.u8string().c_str());
                mergeXMLDocument(outputPath, modPath, originalPath, modName);
            } else {
                log(severityLevel::trace, "Copying %s", modPath.u8string().c_str());
                fs::copy_file(modPath, outputPath, fs::copy_options::overwrite_existing);
            }
        }
    } catch (std::exception & exception){
        log(severityLevel::error, "Exception while merging %s: %s", modPath.u8string().c_str(), exception.what());
    }
}




bool ModLoader::packChairloaderPatch() {
    // Remove Old Patches
    m_DeployLogMutex.lock();
    m_DeployState = DeployState::RemovingOldPatches;
    m_DeployLogMutex.unlock();
    try {
        fs::remove("patch_chairloader.pak");
        fs::remove_all("./LevelOutput");
        fs::remove("English_xml_patch.pak");
    } catch (std::exception & exception) {
        overlayLog(severityLevel::error, "Error: %s", exception.what());
        return false;
    }

    // See if any mods have level patches
    bool doLevelPatches = false;
    for (Mod& mod : ModList) {
        if (mod.enabled && mod.hasLevelXML)
        {
            doLevelPatches = true;
            break;
        }
    }

    if (doLevelPatches)
    {
        // packing level files
        m_DeployLogMutex.lock();
        m_DeployState = DeployState::PackingLevelFiles;
        m_DeployLogMutex.unlock();
        auto levelDirectories = exploreLevelDirectory(".\\Output\\Levels");
        try {
            fs::create_directories("./LevelOutput/Levels");
            fs::copy("./Output/Levels", "./LevelOutput/Levels", fs::copy_options::recursive);
        } catch (std::exception & exception) {
            overlayLog(severityLevel::error, "Error Copying level directory: %s", exception.what());
            return false;
        }
        std::vector<PROCESS_INFORMATION> processes;
        processes.clear();
        for(auto &levelDirectory: levelDirectories){
            auto processInfo = packLevel(levelDirectory);
            if(processInfo.hProcess != nullptr) {
                processes.push_back(processInfo);
            }
        }
        for(auto & processInfo: processes){
            WaitForSingleObject(processInfo.hProcess, INFINITE);
            CloseHandle(processInfo.hProcess);
            CloseHandle(processInfo.hThread);
        }
        // Copying Level Files
        m_DeployLogMutex.lock();
        m_DeployState = DeployState::CopyingLevelFiles;
        m_DeployLogMutex.unlock();
        try {
            for (auto &levelDirectory: levelDirectories) {
                fs::path basePath = levelDirectory.wstring().substr(std::string("./Output/").size(), levelDirectory.wstring().size() - 1);
                log(severityLevel::trace, "Packing level %s", levelDirectory.u8string().c_str());
                if(fs::exists("./LevelOutput" / basePath / "level.pak")) {
                    fs::remove_all("./LevelOutput" / basePath / "level/");
                    log(severityLevel::trace, "Removing level directory %s", "./LevelOutput" / basePath / "level/");
                    fs::copy("./LevelOutput" / basePath, PreyPath / "GameSDK" / basePath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                    log(severityLevel::trace, "Copying Level files from %s to %s", "./LevelOutput/" + basePath.u8string(), PreyPath.u8string() + "/GameSDK/" + basePath.u8string());
                } else {
                    log(severityLevel::error, "Level %s not packed", basePath.u8string().c_str());
                }
            }
            fs::remove_all("./Output/Levels");
        } catch (std::exception & exception) {
            overlayLog(severityLevel::error, "Error packing level: %s", exception.what());
            return false;
        }
    }

    // Pack Localization Patch
    m_DeployLogMutex.lock();
    m_DeployState = DeployState::PackingLocalization;
    m_DeployLogMutex.unlock();

    STARTUPINFOW LocalizationStartupInfo = {sizeof(LocalizationStartupInfo)};
    PROCESS_INFORMATION LocalizationProcessInfo;
    log(severityLevel::trace, "Packing localization patch");
    auto command = fs::path(R"(.\7za.exe a English_xml_patch.pak -tzip .\Output\Localization\English_xml\*)").wstring();
    command.resize(MAX_PATH);
    if(CreateProcessW(nullptr, &command[0], nullptr, nullptr, false, CREATE_NO_WINDOW, nullptr, nullptr, &LocalizationStartupInfo, &LocalizationProcessInfo)){
        WaitForSingleObject(LocalizationProcessInfo.hProcess, INFINITE);
        CloseHandle(LocalizationProcessInfo.hProcess);
        CloseHandle(LocalizationProcessInfo.hThread);
    } else {
        log(severityLevel::error, "Error packing localization patch: %d", GetLastError());
        return false;
    }

    if(!fs::exists("./English_xml_patch.pak")) {
        overlayLog(severityLevel::error, "Error packing localization patch");
        return false;
    } else {
        try {
            fs::remove_all("./Output/Localization/");
            fs::copy_file("./English_xml_patch.pak", PreyPath / "Localization/English_xml_patch.pak", fs::copy_options::overwrite_existing);
        } catch (std::exception &exception) {
            overlayLog(severityLevel::error, "Error removing localization patch files: %s", exception.what());
            return false;
        }
    }

    // pack chairloader patch
    m_DeployLogMutex.lock();
    m_DeployState = DeployState::PackingMainPatch;
    m_DeployLogMutex.unlock();
    STARTUPINFOW ChairloaderStartupInfo = {sizeof(ChairloaderStartupInfo)};
    PROCESS_INFORMATION ChairloaderProcessInfo;
    auto commandChairloader = fs::path(R"(.\7za.exe a patch_chairloader.pak -tzip .\Output\*)").wstring();
    commandChairloader.resize(MAX_PATH);
    if(CreateProcessW(nullptr, &commandChairloader[0], nullptr, nullptr, false, CREATE_NO_WINDOW, nullptr, nullptr, &ChairloaderStartupInfo, &ChairloaderProcessInfo)){
        WaitForSingleObject(ChairloaderProcessInfo.hProcess, INFINITE);
        CloseHandle(ChairloaderProcessInfo.hProcess);
        CloseHandle(ChairloaderProcessInfo.hThread);
    } else {
        log(severityLevel::error, "Error packing chairloader patch: %d", GetLastError());
        return false;
    }
//    system(R"(.\7za.exe a patch_chairloader.pak -tzip .\Output\*)");
    if(!fs::exists("patch_chairloader.pak")) {
        overlayLog(severityLevel::error, "Failed to pack patch_chairloader.pak");
        return false;
    } else {
        log(severityLevel::info, "Packed patch_chairloader.pak");
        return true;
    }
}

bool ModLoader::copyChairloaderPatch() {
    // copy chairloader patch
    m_DeployLogMutex.lock();
    m_DeployState = DeployState::CopyingMainPatch;
    m_DeployLogMutex.unlock();
    try {
        fs::copy("patch_chairloader.pak", PreyPath / "GameSDK/Precache",
                 fs::copy_options::overwrite_existing);
        return true;
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while copying patch_chairloader.pak: %s", exception.what());
        return false;
    }
}

std::vector<fs::path> ModLoader::exploreLevelDirectory(fs::path pathToExplore) {
    std::vector<fs::path> levelPaths;
    for(auto &directory: fs::directory_iterator(pathToExplore)) {
        if(fs::exists(directory.path() / "level/")){
            levelPaths.emplace_back(directory.path());
        } else {
            auto childrenPaths = exploreLevelDirectory(directory.path());
            for(auto &childPath: childrenPaths) {
                levelPaths.emplace_back(childPath);
            }
        }
    }
    return levelPaths;
}

PROCESS_INFORMATION ModLoader::packLevel(fs::path path) {
    try {
        STARTUPINFOW startupInfo = {sizeof(startupInfo)};
        PROCESS_INFORMATION processInfo;
        fs::path basePath = path.wstring().substr(std::string(".\\Output\\").size(), path.wstring().size() - 1);
//        fs::path tempPath = basePath;
//        std::replace(tempPath.wstring().begin(), tempPath.wstring().end(), '/', '\\');
        auto command = (R"(.\7za.exe a .\LevelOutput)" /  basePath / "level.pak -tzip ").wstring() + (path / "level\\*").wstring();
        command.resize(MAX_PATH);
        if(CreateProcessW(nullptr, &command[0], nullptr, nullptr, false, CREATE_NO_WINDOW, nullptr, nullptr, &startupInfo, &processInfo)){
            log(severityLevel::trace, "Packed level %s", basePath.u8string().c_str());
            return processInfo;
        } else {
            log(severityLevel::error, "Failed to pack level %s: %d", basePath.u8string().c_str(), GetLastError());
            return {};
        }
    } catch (std::exception & exception){
        log(severityLevel::error, "Exception while packing level %s: %s", path.u8string().c_str(), exception.what());
        return {};
    }
    return {};
}

bool ModLoader::verifyDependencies(std::string modName) {
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

bool ModLoader::verifyDependenciesEnabled(std::string modName) {
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

bool ModLoader::copyLocalizationPatch() {
    return false;
}
bool ModLoader::verifyChairloaderConfigFile() {
    try {
        return fs::exists(PreyPath / "Mods/config/Chairloader.xml");
    } catch (std::exception &exception) {
        overlayLog(severityLevel::error, "Exception while verifying chairloader.xml: %s", exception.what());
        return false;
    }
}
void ModLoader::createChairloaderConfigFile() {
    try {
        fs::copy("chairloader_default.xml", PreyPath / "Mods/config/Chairloader.xml", fs::copy_options::overwrite_existing);
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while creating chairloader config file: %s", exception.what());
    }
}

bool ModLoader::verifyChairloaderInstalled() {
    try{
        for (const char* fileName : PathUtils::REQUIRED_CHAIRLOADER_BINARIES)
        {
            if (!fs::exists(PreyPath / PathUtils::GAME_BIN_DIR / fileName))
                return false;
        }

        return true;
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while verifying chairloader: %s", exception.what());
        return false;
    }
}

bool ModLoader::verifyDefaultFileStructure() {
    try {
        for (const char* dirName : PathUtils::REQUIRED_CHAIRLOADER_DIRS)
        {
            if (!fs::is_directory(PreyPath / dirName))
                return false;
        }

        return true;
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while verifying default file structure: %s", exception.what());
        return false;
    }
}

void ModLoader::createDefaultFileStructure() {
    try {
        for (const char* dirName : PathUtils::REQUIRED_CHAIRLOADER_DIRS)
        {
            fs::create_directories(PreyPath / dirName);
        }
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while creating default file structure: %s", exception.what());
    }
}

void ModLoader::Init() {
    installedChairloaderVersion = VersionCheck::getInstalledChairloaderVersion();
    createDefaultFileStructure();
    // Note: This method may be called mutiple times (e.g. after game path change)
    if (!verifyChairloaderConfigFile())
    {
        log(severityLevel::info, "Chairloader config file not found, creating default");
        createChairloaderConfigFile();
    }


    if (!ChairloaderConfigFile.load_file((PreyPath / "Mods/config/Chairloader.xml").c_str())) {
        throw std::runtime_error("Chairloader config file is corrupted.");
    }

    log(severityLevel::info, "Chairloader Config File Loaded");
    ModListNode = ChairloaderConfigFile.child("Chairloader").child("ModList");
    std::string foundMods = "Previously Loaded Mods Found:";
    for(auto &foundMod : ModListNode){
        foundMods += std::string(" ") + foundMod.name() + ",";
    }
    log(severityLevel::info, "%s", foundMods);
    std::ofstream ofs("ChairloaderModLoader.log", std::fstream::out | std::fstream::trunc);
    ofs.close();
    loadModInfoFiles();

    m_pGameVersion = std::make_unique<GameVersion>();
    initialized = true;
}

void ModLoader::DrawDebug() {
    if(ImGui::BeginTabItem("DEBUG")) {
        if (ImGui::Button("Test create process")) {
            STARTUPINFOW info={sizeof(info)};
            PROCESS_INFORMATION processInfo;
            LPSTR currentDir = new char[MAX_PATH];
            GetCurrentDirectory(MAX_PATH, currentDir);
            log(severityLevel::debug, "Current directory: %s", currentDir);
            auto command = fs::path(R"(.\7za.exe a English_xml_patch.pak -tzip .\Output\Localization\English_xml\*)").wstring();
            command.resize(MAX_PATH);
//            auto command = const_cast<LPTSTR>(commandArgs.c_str());
            if (CreateProcessW(nullptr, &command[0], nullptr, nullptr, true, CREATE_NO_WINDOW, nullptr, nullptr, &info, &processInfo)) {
                overlayLog(severityLevel::debug, "CREATE PROCESS SUCCESS");
                WaitForSingleObject(processInfo.hProcess, INFINITE);
                CloseHandle(processInfo.hProcess);
                CloseHandle(processInfo.hThread);
            } else {
                overlayLog(severityLevel::error, "CREATE PROCESS FAILED: %d", GetLastError());
            }

        }
        if (ImGui::Button("Test Filename extension removal")){
            auto BaseModFolder = modToLoadPath.filename().wstring();
            auto filenamePosition = BaseModFolder.find_last_of(L'.');
            auto modFolder = BaseModFolder.substr(0, filenamePosition-1);
            overlayLog(severityLevel::debug, "Mod folder: %ls", modFolder.c_str());
        }
        if(ImGui::Button("Check Chairloader dll version")) {
            overlayLog(severityLevel::info, "%s", VersionCheck::getInstalledChairloaderVersion().String().c_str());
        }
        ImGui::EndTabItem();
    }
}

void ModLoader::SwitchToDeployScreen() {
    modalInitPos = ImGui::GetWindowPos();
    modalInitPos.x -= (ImGui::GetWindowWidth() + 125);
    initPosSet = false;
    m_State = State::Deploying;
}

void ModLoader::DrawDeployScreen(bool *pbIsOpen) {
    ImGuiWindowFlags windowFlags =
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoResize;

    ImGui::SetNextWindowSize({ 500, 300 });
    ImGui::SetNextWindowBgAlpha(1.0f);
//    ImGui::SetNextWindowPos({ (float) (GetSystemMetrics(SM_CXSCREEN) / 2 - 250), (float) (GetSystemMetrics(SM_CYSCREEN) / 2 - 150) });
    if(!initPosSet) {
        ImGui::SetNextWindowPos(modalInitPos);
    }
    if(ImGui::BeginPopupModal("Deploying Mods", nullptr, windowFlags)) {
        m_DeployLogMutex.lock();
        // RemovingOldOutput, CopyingBaseFiles, MergingLegacyMods, MergingMods, RemovingOldPatches, PackingLevelFiles, CopyingLevelFiles, PackingLocalization, PackingMainPatch, CopyingMainPatch, Done, Invalid
        ImGui::Text("Deploying Mods, Please Wait:");
        ImGui::Separator();
        if(m_DeployState >= DeployState::RemovingOldOutput){
            ImGui::Text("Removing old merge output files...");
        }
        if(m_DeployState >= DeployState::CopyingBaseFiles){
            ImGui::Text("Copying base files...");
        }
        if(m_DeployState >= DeployState::MergingLegacyMods){
            ImGui::Text("Merging legacy mods...");
        }
        if(m_DeployState >= DeployState::MergingMods){
            ImGui::Text("Merging registered mods...");
        }
        if(m_DeployState >= DeployState::RemovingOldPatches){
            ImGui::Text("Removing old patch files...");
        }
        if(m_DeployState >= DeployState::PackingLevelFiles){
            ImGui::Text("Packing level files...");
        }
        if(m_DeployState >= DeployState::CopyingLevelFiles){
            ImGui::Text("Copying level files...");
        }
        if(m_DeployState >= DeployState::PackingLocalization){
            ImGui::Text("Packing localization...");
        }
        if(m_DeployState >= DeployState::PackingMainPatch){
            ImGui::Text("Packing patch_chairloader.pak...");
        }
        if(m_DeployState >= DeployState::CopyingMainPatch){
            ImGui::Text("Copying patch_chairloader.pak...");
        }
        if(m_DeployState >= DeployState::Done){
            ImGui::Text("Done!");
        }
        m_DeployLogMutex.unlock();
//        ImGui::Text("Deploying Mods, Please Hold");
        ImGui::EndPopup();
        initPosSet = true;
    }
    ImGui::OpenPopup("Deploying Mods");
    if(IsFutureReady(m_DeployTaskFuture)){
        m_DeployTaskFuture.get();
        m_State = State::MainWindow;
        m_DeployState = DeployState::Invalid;
        ImGui::CloseCurrentPopup();
        return;
    }
}

void ModLoader::RunAsyncDeploy() {
    if(m_DeployState <= DeployState::Invalid) {
        SwitchToDeployScreen();
        m_DeployTaskFuture = std::async(std::launch::async, [&]() { DeployMods(); });
    } else {
        overlayLog(severityLevel::error, "Mods are already being deployed");
    }
}

void ModLoader::SwitchToUninstallWizard() {
    log(severityLevel::info, "Switching to uninstall wizard");
    m_State = State::UninstallWizard;
}

void ModLoader::DrawUninstallWizard(bool *pbIsOpen) {
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