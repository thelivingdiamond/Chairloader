//
// Created by theli on 8/1/2022.
//

#include <iostream>
#include <Windows.h>
#include <sstream>
#include "ModLoader.h"


static std::string ErrorMessage;
static bool showErrorPopup = false;
static bool showDemo = false;

void ModLoader::Draw() {
    if(ImGui::BeginMenuBar()){
        if(ImGui::BeginMenu("Files", true)){
            if(ImGui::MenuItem("Install Mod")){
                ImGuiFileDialog::Instance()->OpenModal("ChooseModFile", "Choose Mod File", "Mod Archive (*.zip *.7z){.zip,.7z}", modToLoadPath.string(), 1, nullptr);
            }
#ifdef _DEBUG
            ImGui::Separator();
            ImGui::MenuItem("Show Demo Window", nullptr, &showDemo);
            ImGui::EndMenu();
#endif
        }
        //Create a menu for mod list
        if(ImGui::BeginMenu("Mods", true)) {
            //Load Mod List
            if(ImGui::MenuItem("Load Mod List")){
                loadModInfoFiles();
            }
            // Save Config
            if(ImGui::MenuItem("Save Config")){
                overlayLog(severityLevel::info, "Mod list saved");
                saveChairloaderConfigFile();
            }
            ImGui::EndMenu();
        }
        // Print test overlay log messages for each severity level
//        if(ImGui::BeginMenu("Log", true)){
//            if(ImGui::MenuItem("Info")){
//                overlayLog(severityLevel::info, "Info");
//            }
//            if(ImGui::MenuItem("Warning")){
//                overlayLog(severityLevel::warning, "Warning");
//            }
//            if(ImGui::MenuItem("Error")){
//                overlayLog(severityLevel::error, "Error");
//            }
//            if(ImGui::MenuItem("Trace")){
//                overlayLog(severityLevel::trace, "Trace");
//            }
//            ImGui::EndMenu();
//        }

        ImGui::EndMenuBar();

    }
    if(ImGui::BeginTabBar("##Mod Tab Bar")) {
        DrawModList();
        //TODO: figure out if these will do anything
//        DrawDeploySettings();
//        DrawDLLSettings();
        DrawXMLSettings();
        DrawLog();
        ImGui::EndTabBar();
        if(showErrorPopup) {
            ImGui::OpenPopup("Error");
            showErrorPopup = false;
        }
        if (ImGui::BeginPopupModal("Error", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize)) {
            ImGui::Text("%s", ErrorMessage.c_str());
            if(ImGui::Button("Close")){
                ImGui::CloseCurrentPopup();
            }
            ImGui::EndPopup();
        }
    }
    DrawOverlayLog();
    if(showDemo){
        ImGui::ShowDemoWindow(&showDemo);
    }
    std::sort(ModList.begin(), ModList.end());
}


void ModLoader::DrawModList() {
    static std::string selectedMod;
    static bool showDeleteConfirmation;
    if(ImGui::BeginTabItem("Mod List")) {
        if (ImGui::BeginChild("Mod List", ImVec2(ImGui::GetContentRegionAvail().x * 0.7f, 0))) {

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
                if(selectedMod.empty() && !ModList.empty()){
                    selectedMod = ModList.at(0).modName;
                }
                int i = 0;
                for (auto &ModEntry: ModList) {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    if(ModEntry.installed) {
                        ImGui::Checkbox(("##" + ModEntry.modName + "Enable").c_str(), &ModEntry.enabled);
                    } else {
                        ImGui::BeginDisabled();
                        ImGui::Checkbox(("##" + ModEntry.modName + "Enable").c_str(), &ModEntry.enabled);
                        ImGui::EndDisabled();
                    }
                    ImGui::TableNextColumn();
                    ImVec2 SelectableSize = {0, /*ImGui::GetTextLineHeightWithSpacing() + 4.0f*/0};
//                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 4.0f);


//                    ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, ImColor(0,0,0,0).operator ImU32());
                    auto storedpos = ImGui::GetCursorPosY() + 4;
                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3.5);
                    if(ImGui::Selectable(("##Selectable" + ModEntry.modName).c_str(), selectedMod == ModEntry.modName, 0, ImVec2{ImGui::GetColumnWidth(), 27.0f}))
                        selectedMod = ModEntry.modName;
                    if(ImGui::IsItemClicked(ImGuiMouseButton_Right)){
                        ImGui::OpenPopup((ModEntry.modName + " Mod Actions").c_str());
                    }
                    ImGui::SetCursorPosY(storedpos);
                    if(ModEntry.installed) {
                        if(ModEntry.enabled) {
                            ImGui::TextColored(ImGui::GetStyleColorVec4(ImGuiCol_Text), "%s", ModEntry.modName.c_str());
//                            if (ImGui::Selectable(ModEntry.modName.c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
//                                selectedMod = ModEntry.modName;
                        } else {
//                            ImGui::PushStyleColor(ImGuiCol_Text,ImColor(180,180,180).operator ImU32());
//                            if (ImGui::Selectable(ModEntry.modName.c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
//                                selectedMod = ModEntry.modName;
//                            ImGui::PopStyleColor();
                            ImGui::TextColored(ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled), "%s", ModEntry.modName.c_str());
                            if(ImGui::IsItemHovered()){
                                ImGui::BeginTooltip();
                                ImGui::Text("Mod is not enabled");
                                ImGui::EndTooltip();
                            }
                        }
                    } else {
//                        ImGui::PushStyleColor(ImGuiCol_Text,ImColor(245,100,100).operator ImU32());
//                        if (ImGui::Selectable((ModEntry.modName + " *").c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
//                            selectedMod = ModEntry.modName;
//                        ImGui::PopStyleColor();
                        ImGui::TextColored(ImColor(245,100,100), "%s *", ModEntry.modName.c_str());
                        if(ImGui::IsItemHovered()){
                            ImGui::BeginTooltip();
                            ImGui::Text("Mod is not installed. Please install it before you can enable it");
                            ImGui::EndTooltip();
                        }

                    }
                    if(ImGui::BeginPopup((ModEntry.modName + " Mod Actions").c_str())){
                        ImGui::Text("%s:", ModEntry.modName.c_str());
                        ImGui::BeginDisabled();
                        ImGui::Checkbox("Has DLL", &ModEntry.hasDLL);
                        ImGui::SameLine();
                        ImGui::Checkbox("Has XML", &ModEntry.hasXML);
                        ImGui::EndDisabled();
                        if(ModEntry.installed) {
                            if(ImGui::Button(("Uninstall" + std::string("##") + ModEntry.modName).c_str())){
                                UninstallMod(ModEntry.modName);
                            }
                            if(ModEntry.enabled){
                                if(ImGui::Button("Disable"))
                                    EnableMod(ModEntry.modName, false);
                            } else {
                                if(ImGui::Button("Enable"))
                                    EnableMod(ModEntry.modName, true);
                            }
                        } else {
                            if(ImGui::Button(("Install" + std::string("##") + ModEntry.modName).c_str())) {
                                InstallMod(ModEntry.modName);
                            }
                            if(ImGui::Button(("Delete" + std::string("##") + ModEntry.modName).c_str())){
                                showDeleteConfirmation = true;
                            }
                        }
                        ImGui::EndPopup();
                    }
                    if(showDeleteConfirmation){
                        ImGui::OpenPopup(("Delete Confirmation"+ std::string("##") + ModEntry.modName).c_str());
                        showDeleteConfirmation = false;
                    }

                    if(ImGui::BeginPopupModal(("Delete Confirmation"+ std::string("##") + ModEntry.modName).c_str())){
                        ImGui::Text("Are you sure you want to delete %s?\nConfig data will be preserved.", ModEntry.modName.c_str());
                        if(ImGui::Button("Delete")){
                            if(!ModEntry.modName.empty()) {
                                log(severityLevel::info, "Deleting %s/Mods/%s/", PreyPath.string(), ModEntry.modName);
                                fs::remove_all(PreyPath.string() + "/Mods/" + ModEntry.modName + "/");
                                ModList.erase(std::find(ModList.begin(), ModList.end(),ModEntry.modName));

                            }
                            ImGui::CloseCurrentPopup();
                        }
                        ImGui::SameLine();
                        if(ImGui::Button("Cancel")){
                            ImGui::CloseCurrentPopup();
                        }
                        ImGui::EndPopup();
                    }
                    ImGui::TableNextColumn();
                    ImGui::Text("%s", ModEntry.version.c_str());
                    ImGui::TableNextColumn();
                    ImGui::Text("%i", ModEntry.loadOrder);

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
                                if (ImGui::ArrowButton(("##" + ModEntry.modName + "Down").c_str(), ImGuiDir_Down)) {
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
                ImGui::EndTable();
            }
        }
        ImGui::EndChild();
        ImGui::SameLine();
        if (ImGui::BeginChild("Controls")) {
            if (ImGui::Button("Load Mod List")) {
                loadModInfoFiles();
                selectedMod.clear();
            }
            auto ModSelect = std::find(ModList.begin(), ModList.end(), selectedMod);
            ImGui::Separator();
            if(ModSelect != ModList.end()){
                if(!ModSelect->installed)
                    ImGui::BeginDisabled();
                ImGui::Text("%s", ModSelect->modName.c_str());
                ImGui::Text("By: %s", ModSelect->author.c_str());
                if(!ModSelect->installed) {
                    ImGui::EndDisabled();
                    if(ImGui::Button("Install")) {
                        InstallMod(ModSelect->modName);
                    }
                }
            }
            ImGui::SetCursorPosY(ImGui::GetWindowSize().y -100);
            if(ImGui::Button("Save Mod List")){
                SaveAllMods();
                overlayLog(severityLevel::info, "Mod list saved");
            }
            if(ImGui::Button("Deploy Mods")){
                if(DeployMods())
                    overlayLog(severityLevel::info, "Mods deployed");
            }
            ImGui::Separator();
            if(ImGui::Button("Install Mod")){
                ImGuiFileDialog::Instance()->OpenModal("ChooseModFile", "Choose Mod File", "Mod Archive (*.zip *.7z){.zip,.7z}", modToLoadPath.string(), 1, nullptr);
            }
        }
        ImGui::EndChild();
        //TODO: get display size (currently broken)
        ImVec2 maxSize = {1920, 1080};
        ImVec2 minSize = {maxSize.x * 0.5f, maxSize.y * 0.5f};
        if(ImGuiFileDialog::Instance()->Display("ChooseModFile", ImGuiWindowFlags_None, minSize, maxSize)){
            // action if OK
            if (ImGuiFileDialog::Instance()->IsOk())
            {
                try {
                    modToLoadPath = ImGuiFileDialog::Instance()->GetCurrentPath();
                    fileToLoad = ImGuiFileDialog::Instance()->GetFilePathName();
                    log(severityLevel::trace, "File To Load: %s", modToLoadPath.string() + fileToLoad);
                    if (!(modToLoadPath.string() + fileToLoad).empty()) {
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
    if(ImGui::BeginTabItem("DLL Settings")){

        ImGui::EndTabItem();
    }
}

void ModLoader::DrawXMLSettings() {
    if(ImGui::BeginTabItem("Asset View")){
        if(ImGui::BeginChild("Asset List", ImVec2(ImGui::GetContentRegionAvail().x * 0.8f, 0), true)) {
            for (auto &mod: ModList)
                TreeNodeWalkDirectory(fs::path(PreyPath.string() + "/Mods/" + mod.modName), mod.modName);
//                if (ImGui::TreeNode(mod.modName.c_str())) {
//                    ImGui::Text("Version: %s", mod.version.c_str());
//                    TreeNodeWalkDirectory(fs::path(PreyPath.string() + "/Mods/" + mod.modName + "/Data"), mod.modName);
//                    ImGui::TreePop();
//                }
        }
        ImGui::EndChild();
        ImGui::SameLine();
        if(ImGui::BeginChild("Selected File Window")){
            if(ImGui::Button("Deselect")){
                selectedFile.clear();
            }
            if(!selectedFile.empty()){
                ImGui::Text("%s", selectedFile.filename().string().c_str());
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
            log(severityLevel::debug, "base: %s", baseResult.description());
            log(severityLevel::debug, "override: %s", overrideResult.description());
            log(severityLevel::debug, "original: %s", originalResult.description());
        }
        if(ImGui::Button("Test Merge")) {
            mergeXMLDocument(BasePath, OverridePath, OriginalPath, std::string());
        }
        if(ImGui::Button("Save Copy")){
            log(severityLevel::debug, "Save Result: %i", BaseDoc.save_file(R"(C:\Program Files (x86)\Steam\steamapps\common\Prey\Mods\ExampleMod\MergeTest_NEW.xml)"));
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
                                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(200, 200, 200).operator ImU32());
                                break;
                            default:
                            case severityLevel::info:
                                level = "info";
                                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 255, 255).operator ImU32());
                                break;
                            case severityLevel::warning:
                                level = "warning";
                                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 255, 0).operator ImU32());
                                break;
                            case severityLevel::error:
                                level = "error";
                                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 0, 0).operator ImU32());
                                break;
                            case severityLevel::fatal:
                                level = "fatal";
                                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 0, 0).operator ImU32());
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
}



fs::path ModLoader::getConfigPath(std::string &modName) {
    return fs::path{ (PreyPath.string() + "/Mods/config/" + modName + ".xml").c_str() };
}

fs::path ModLoader::getDefaultConfigPath(std::string &modName) {
    return fs::path{ (PreyPath.string() + "/Mods/" + modName + "/" + modName + "_default.xml").c_str() };
}
bool ModLoader::LoadModInfoFile(fs::path directory, Mod *mod) {
    pugi::xml_document result;
    auto loadResult  = result.load_file((directory.string() + "/ModInfo.xml").c_str());
    log(severityLevel::debug, "%s/ModInfo.xml", directory.string().c_str());
    if(loadResult){
        std::string modName = result.child("Mod").attribute("modName").as_string();
        if(!modName.empty()) {
            mod->modName = modName;
            mod->version = result.child("Mod").attribute("version").as_string();
            mod->author = result.child("Mod").attribute("author").as_string();
            mod->infoFile = result.child("Mod");
            mod->hasDLL = result.child("Mod").attribute("hasDLL").as_bool();
            mod->hasXML = result.child("Mod").attribute("hasXML").as_bool();
            return true;
        }
        else {
            log(severityLevel::error, "%s: - 'Invalid ModInfo.xml: Could not read Mod Name'", directory.string());

        }
    } else {
        log(severityLevel::warning, "ModInfo.xml failed to load in %s - Reason: %s", directory.string(), loadResult.description());
    }
    return false;
}

void ModLoader::LoadModsFromConfig() {
    for(auto &PrevMod : ModListNode){
        fs::path modPath = PreyPath.string() + "/Mods/" + PrevMod.child("modName").text().as_string();
        Mod mod;
        if(LoadModInfoFile(modPath, &mod)) {
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
    for(auto &directory : fs::directory_iterator(fs::path(PreyPath.string() + "/Mods/"))){
        if(directory.path().string() != PreyPath.string() + "/Mods/config") {
            Mod mod;
            if(LoadModInfoFile(directory.path(), &mod)) {
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
    // load previously loaded (assumedly) valid config
    LoadModsFromConfig();
    DetectNewMods();
    overlayLog(severityLevel::info, "Loaded %i mods", ModList.size());
    //TODO: Handle dependencies
//    serializeLoadOrder();
}

ModLoader::ModLoader() {
    if(!ChairloaderConfigFile.load_file((PreyPath.string() + "/Mods/config/Chairloader.xml").c_str())){
        log(severityLevel::fatal, "Chairloader config file not found");
        MessageBoxA(nullptr,"Chairloader config file not found:\nPlease verify the Chairloader installation", "Error", MB_OK);
        exit(-1);
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
        //hasDLL
        node = modNode.append_child("hasDLL");
        node.append_attribute("type").set_value("string");
        node.text().set(modEntry->hasDLL);
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

}

void ModLoader::Update() {
    static time_t lastFileTime;
    if(time(nullptr) - lastFileTime > 10){
        time(&lastFileTime);
        flushFileQueue();
    }
    //TODO: automatic saving of the file
}

ModLoader::~ModLoader() {
    flushFileQueue();
}

bool ModLoader::TreeNodeWalkDirectory(fs::path path, std::string modName) {
    if(is_directory(path)){
        if(ImGui::TreeNode(path.string().c_str(), "%s", path.filename().string().c_str())){
            for(auto&childPath: fs::directory_iterator(path)) {
                TreeNodeWalkDirectory(childPath.path(), modName);
            }
            ImGui::TreePop();
            return false;
        }
    } else if(is_regular_file(path)){
        ImGui::PushID(path.string().c_str());
        if(ImGui::Selectable(path.filename().string().c_str(), path == selectedFile)){
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

void ModLoader::InstallModFromFile(fs::path path, std::string fileName) {
    char shortPath[MAX_PATH];
    GetShortPathNameA(fileName.c_str(), shortPath, MAX_PATH);
    std::string commandArgs = "7za.exe x ";
    commandArgs +=  shortPath;
    commandArgs += " -otemp";
    log(severityLevel::trace, "%s", commandArgs);
    //TODO: move to CreateProcessA instead of system()
//    auto si = new STARTUPINFOA;
//    auto pi = new PROCESS_INFORMATION;
//    LPSTR cmdList[] = {TEXT("x"), TEXT((char*)fileName.c_str()), TEXT("-otemp")};
//    if(CreateProcessA(nullptr, args, nullptr, nullptr, true, 0, nullptr, nullptr, si, pi))
//        WaitForSingleObject(pi->hProcess, INFINITE);
    if(system(commandArgs.c_str())) {
        log(severityLevel::error, "Mod Installation Failed: could not decompress %s", fileName);
        return;
    } else
        log(severityLevel::debug, "7Zip operation successful");
//        log(severityLevel::error, "Error, 7za.exe failed to execute %i", GetLastError());
    if(exists(fs::path("./temp/ModInfo.xml"))){
        auto mod = new Mod;
        if(LoadModInfoFile(fs::path("./temp"), mod)){
            try {
                fs::copy("./temp/", PreyPath.string() + "/Mods/" + mod->modName, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                log(severityLevel::info, "Mod Installation Succeeded: %s loaded", mod->modName);
                DetectNewMods();
                InstallMod(mod->modName);
            } catch (std::exception &exc){
                std::cerr << exc.what() << std::endl;
                log(severityLevel::error, "Mod Installation Failed: %s", exc.what());
            }
        }
    } else {
        log(severityLevel::error, "Mod Installation Failed: No ModInfo.xml file found");
    }
    fs::remove_all("./temp/");
}

void ModLoader::EnableMod(std::string modName, bool enabled) {
    if(std::find(ModList.begin(), ModList.end(),modName) != ModList.end())
        std::find(ModList.begin(), ModList.end(),modName)->enabled = enabled;
}

bool ModLoader::DeployMods() {
    //TODO: handle legacy mods
    mergeXMLFiles();
    saveChairloaderConfigFile();
    if(packChairloaderPatch()){
        if(copyChairloaderPatch()){
            return true;
        }
    }
    return false;
}



pugi::xml_document
ModLoader::mergeXMLDocument(fs::path basePath, fs::path overridePath, fs::path originalPath, std::string modName) {
    pugi::xml_document modFile;
    pugi::xml_document originalFile;
    pugi::xml_document outputFile;
    auto modResult = modFile.load_file(overridePath.string().c_str());
    auto originalResult = originalFile.load_file(originalPath.string().c_str());
    auto outputResult = outputFile.load_file(basePath.string().c_str());
    auto baseRootNode = outputFile.first_child();
    auto overrideRootNode = modFile.first_child();
    auto originalRootNode = originalFile.first_child();
    baseRootNode.append_child(pugi::node_comment).set_value(("Mod: " + modName).c_str());
    log(severityLevel::debug, "Base Root Node: %s\nOverride Root Node: %s\nOriginal Root Node: %s", baseRootNode.name(), overrideRootNode.name(), originalRootNode.name());
    if(overrideRootNode != nullptr) {
        for (auto &overrideNode: overrideRootNode) {
            //Case: Overwrite
            auto baseNode = baseRootNode.find_child_by_attribute("Name", overrideNode.attribute("Name").value());
            auto originalNode = originalRootNode.find_child_by_attribute("Name", overrideNode.attribute("Name").value());
            if (!mergeXMLNode(baseNode, overrideNode, originalNode)) {
                baseRootNode.append_copy(overrideNode);
            }
        }
    }
    outputFile.save_file(basePath.string().c_str());
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
            }
        // default overwrite
        } else {
            log(severityLevel::trace, "Overwriting original node %s", overrideNode.attribute("Name").value());
            baseNode.text().set(overrideNode.text().get());
        }
    } else {
        //Case: Add
        log(severityLevel::trace, "Adding node %s", overrideNode.attribute("Name").value());
        return false;
    }
    return true;
}

void ModLoader::mergeXMLFiles() {
    fs::remove_all("./Output/");
    fs::create_directory("./Output/");
    for(auto &mod : ModList) {
        if (mod.installed && mod.enabled) {
            mergeDirectory("", mod.modName);
            ModListNode.child(mod.modName.c_str()).child("deployed").text().set(true);
        }
    }

}

float overlayLogPadding = 2.0f;
static std::string logEntryToDelete;
static float accumulatedHeight = 0.0f;
void ModLoader::DrawOverlayLog(){
    accumulatedHeight = 0.0f;
//    tm nowTime;
    time_t now = time(nullptr);
//    localtime_s(&nowTime,&now);
    const uint64_t fadeDuration = 500;
    const uint64_t totalElementTime = 2000;
    float y = 0.0f;

    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));
    ImGui::PushClipRect(ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x - OverlayElementWidth - 2 * overlayLogPadding, ImGui::GetWindowPos().y + + overlayLogPadding + 60.0f),
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
                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(200, 200, 200).operator ImU32());
                break;
            default:
            case severityLevel::info:
                ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_Text));
                break;
            case severityLevel::warning:
                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 255, 0).operator ImU32());
                break;
            case severityLevel::error:
            case severityLevel::fatal:
                ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 0, 0).operator ImU32());
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

void ModLoader::mergeDirectory(fs::path path, std::string modName) {
    fs::path modPath = PreyPath.string() + "/Mods/" + modName + "/Data" + path.string();
    fs::path originalPath = "./PreyFiles" + path.string();
    fs::path outputPath = "./Output" + path.string();
    try {
        if (is_directory(modPath) && modPath != PreyPath.string() + "/Mods/" + modName + "/Data/Levels") {
            log(severityLevel::trace, "Exploring directory %s", modPath.string().c_str());
            if(!fs::exists(outputPath)) {
                fs::create_directories(outputPath);
            }
            for (auto directory: fs::directory_iterator(modPath)) {
                mergeDirectory(path.string() + "/" + directory.path().filename().string(), modName);
            }
        } else if (is_regular_file(modPath)) {
            if(modPath.extension() == ".xml") {
                if (!fs::exists(outputPath) && fs::exists(originalPath)) {
                    fs::copy_file(originalPath, outputPath);
                }
                log(severityLevel::trace, "Merging %s", modPath.string().c_str());
                mergeXMLDocument(outputPath, modPath, originalPath, modName);
            } else {
                log(severityLevel::trace, "Copying %s", modPath.string().c_str());
                fs::copy_file(modPath, outputPath, fs::copy_options::overwrite_existing);
            }
        }
    } catch (std::exception & exception){
        log(severityLevel::error, "Exception while merging %s: %s", modPath.string().c_str(), exception.what());
    }
}

bool ModLoader::packChairloaderPatch() {
    try {
        fs::remove("patch_chairloader.pak");
    } catch (std::exception & exception) {
        overlayLog(severityLevel::error, "Could not remove patch_chairloader.pak: %s", exception.what());
        return false;
    }
    system(R"(.\7za.exe a patch_chairloader.pak -tzip .\Output\*)");
    if(!fs::exists("patch_chairloader.pak")) {
        overlayLog(severityLevel::error, "Failed to pack patch_chairloader.pak");
        return false;
    } else {
        log(severityLevel::info, "Packed patch_chairloader.pak");
        return true;
    }
}

bool ModLoader::copyChairloaderPatch() {
    try {
        fs::copy("patch_chairloader.pak", PreyPath.string() + "/GameSDK/Precache",
                 fs::copy_options::overwrite_existing);
        return true;
    } catch (std::exception & exception){
        overlayLog(severityLevel::error, "Exception while copying patch_chairloader.pak: %s", exception.what());
        return false;
    }
}


