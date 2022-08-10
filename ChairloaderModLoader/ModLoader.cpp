//
// Created by theli on 8/1/2022.
//

#include <iostream>
#include <Windows.h>
#include "ModLoader.h"


static std::string ErrorMessage;
static bool showErrorPopup = false;
static bool showDemo = true;

void ModLoader::Draw() {
    if(ImGui::BeginMenuBar()){
        if(ImGui::BeginMenu("Files", true)){
            ImGui::MenuItem("Show Demo Window", nullptr, &showDemo);
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    if(ImGui::BeginTabBar("##Mod Tab Bar")) {
        DrawModList();
        DrawDeploySettings();
        DrawDLLSettings();
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
    if(showDemo){
        ImGui::ShowDemoWindow(&showDemo);
    }
    std::sort(ModList.begin(), ModList.end());
}
void ModLoader::DrawModList() {
    static std::string selectedMod;
    static bool showDeleteConfirmation;
    if(ImGui::BeginTabItem("Mod List")) {
        if (ImGui::BeginChild("Mod List", ImVec2(ImGui::GetContentRegionAvail().x * 0.8f, 0))) {

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
                            ImGui::TextColored(ImColor(255,255,255), "%s", ModEntry.modName.c_str());
//                            if (ImGui::Selectable(ModEntry.modName.c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
//                                selectedMod = ModEntry.modName;
                        } else {
//                            ImGui::PushStyleColor(ImGuiCol_Text,ImColor(180,180,180).operator ImU32());
//                            if (ImGui::Selectable(ModEntry.modName.c_str(), selectedMod == ModEntry.modName, 0, SelectableSize))
//                                selectedMod = ModEntry.modName;
//                            ImGui::PopStyleColor();
                            ImGui::TextColored(ImColor(180,180,180), "%s", ModEntry.modName.c_str());
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
                //TODO: switch to install/enabled/deploy
//                ImGui::Checkbox("Load DLL", &ModSelect->DLLEnable);
//                ImGui::Checkbox("Load XML", &ModSelect->XMLEnable);
//                if(ImGui::Button("Save")){
//                    if(ModSelect->installed) {
//                        SaveMod(&*ModSelect);
//                    } else {
//                        log(severityLevel::warning, "Mod is not installed");
//                        ErrorMessage = "Mod is not installed, please install mod first";
//                        showErrorPopup = true;
//                    }
//                }
                if(!ModSelect->installed) {
                    ImGui::EndDisabled();
                    if(ImGui::Button("Install")) {
                        InstallMod(ModSelect->modName);
                    }
                }
            }
//            for(auto &order : loadOrder){
//                ImGui::Text("%s: %i", order.second.c_str(), order.first);
//            }
            ImGui::SetCursorPosY(ImGui::GetWindowSize().y -75);
            if(ImGui::Button("Save Mod List")){
                SaveAllMods();
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
        static std::string OverridePath = R"(C:\Program Files (x86)\Steam\steamapps\common\Prey\Mods\ExampleMod\MergeTest2.xml)";
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
            mergeXMLDocument(BaseDoc, OverrideDoc, OriginalDoc);
        }
        ImGui::EndTabItem();
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




//TODO: save mods in order with ability to delete and reorder the mod list in the file
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

void ModLoader::DeployMods() {
    //TODO: merge xml files into one .pak file
    //TODO: handle legacy mods

}

pugi::xml_document ModLoader::mergeXMLDocument(pugi::xml_document &base, pugi::xml_document &override, pugi::xml_document &ArkOriginal) {
    auto baseRootNode = base.root();
    auto overrideRootNode = override.root();
    auto originalRootNode = ArkOriginal.root();
    log(severityLevel::debug, "Base Root Node: %s\nOverride Root Node: %s\nOriginal Root Node: %s", baseRootNode.name(), overrideRootNode.name(), originalRootNode.name());
    return pugi::xml_document();
}

pugi::xml_node ModLoader::mergeXMLNode(pugi::xml_node &base, pugi::xml_node &override, pugi::xml_node ArkOriginal) {

    return pugi::xml_node();
}



