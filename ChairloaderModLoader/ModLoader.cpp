//
// Created by theli on 8/1/2022.
//

#include <iostream>
#include <Windows.h>
#include "ModLoader.h"



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
        DrawDLLSettings();
        DrawXMLSettings();
        DrawDeploySettings();
        DrawLog();
        ImGui::EndTabBar();
    }
    if(showDemo){
        ImGui::ShowDemoWindow(&showDemo);
    }
    std::sort(ModList.begin(), ModList.end());
}

void ModLoader::DrawModList() {
    static std::string selectedMod;
    if(ImGui::BeginTabItem("Mod List")) {
        if (ImGui::BeginChild("Mod List", ImVec2(ImGui::GetContentRegionAvail().x * 0.8f, 0))) {

            if (ImGui::BeginTable("Mod List", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_SizingStretchProp |
                                                 ImGuiTableFlags_NoBordersInBody)) {
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
                    if (ImGui::Selectable(ModEntry.modName.c_str(), selectedMod == ModEntry.modName, 0,
                                          ImVec2(0, 28)))
                        selectedMod = ModEntry.modName;
//                if (ImGui::IsItemActive() && !ImGui::IsItemHovered())
//                {
//                    int n_next = i + (ImGui::GetMouseDragDelta(0, 28.0f).y < 0.f ? -1 : 1);
//                    if (n_next >= 0 && n_next < ModList.size())
//                    {
//                        std::swap(ModList.at(i), ModList.at(n_next));
//                        ImGui::ResetMouseDragDelta();
//                    }
//                }


                    ImGui::TableNextColumn();
                    ImGui::Text("%s", ModEntry.version.c_str());
                    ImGui::TableNextColumn();
                    ImGui::Text("%i", i);

                    ImGui::TableNextColumn();
                    if (selectedMod == ModEntry.modName) {
                        try {
                            if (i > 0) {
                                if (ImGui::ArrowButton(("##" + ModEntry.modName + "Up").c_str(), ImGuiDir_Up)) {
                                    //TODO: switch elements in the vector
                                    std::swap(ModList.at(i - 1), ModList.at(i));
                                }
                                ImGui::SameLine();
                            }
                            if (i < ModList.size() - 1) {
                                if (ImGui::ArrowButton(("##" + ModEntry.modName + "Down").c_str(), ImGuiDir_Down)) {
                                    //TODO: switch elements in the vector
                                    std::swap(ModList.at(i), ModList.at(i + 1));
                                }
                            }
                        } catch (const std::exception &exc) {
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
                ImGui::Text("%s", ModSelect->modName.c_str());
//                    ImGui::Text("%s", ModSelect->version.c_str());
                ImGui::Checkbox("Load DLL", &ModSelect->DLLEnable);
                ImGui::Checkbox("Load XML", &ModSelect->XMLEnable);
                if(ImGui::Button("Save")){
                    SaveMod(&*ModSelect);
                }
            }
        }
        ImGui::EndChild();
        ImGui::EndTabItem();
    }
}

void ModLoader::DrawDLLSettings() {
    if(ImGui::BeginTabItem("DLL Settings")){

        ImGui::EndTabItem();
    }
}

void ModLoader::DrawXMLSettings() {
    if(ImGui::BeginTabItem("Asset Settings")){
        if(ImGui::BeginChild("Asset List", ImVec2(ImGui::GetContentRegionAvail().x * 0.8f, 0), true)) {
            for (auto &mod: ModList)
                if (ImGui::TreeNode(mod.modName.c_str())) {
                    ImGui::Text("Version: %s", mod.version.c_str());
                    TreeNodeWalkDirectory(fs::path(PreyPath.string() + "/Mods/" + mod.modName + "/Data"), mod.modName);
                    ImGui::TreePop();
                }
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
        //TODO: add automatic version checking against the stored version
        if(!modName.empty()) {
            mod->modName = modName;
            mod->version =   result.child("Mod").attribute("version").as_string();
            mod->infoFile = result.child("Mod");
            log(severityLevel::info, "ModInfo.xml Loaded: '%s'", modName.c_str());
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


void ModLoader::loadModInfoFiles() {
    //TODO: check mod list first in order to get previous mod order
    ModList.clear();
    // load previously loaded (assumedly) valid config
    //TODO: validate load order and uniqueness of previous config
    for(auto &PrevMod : ModListNode){
        fs::path modPath = PreyPath.string() + "/Mods/" + PrevMod.child("modName").text().as_string();
        auto mod = new Mod;
        if(LoadModInfoFile(modPath, mod)) {
            FindMod(mod);
            ModList.emplace_back(*mod);
        }
    }
    for(auto &directory : fs::directory_iterator(fs::path(PreyPath.string() + "/Mods/"))){
        if(directory.path().string() != PreyPath.string() + "/Mods/config") {
            auto mod = new Mod;
            if(LoadModInfoFile(directory.path(), mod)) {
                FindMod(mod);
                if (std::find(ModList.begin(), ModList.end(), mod->modName) == ModList.end())
                    ModList.emplace_back(*mod);
            }
        }
    }
}

ModLoader::ModLoader() {
    if(!ChairloaderConfigFile.load_file((PreyPath.string() + "/Mods/config/Chairloader.xml").c_str())){
        log(severityLevel::fatal, "Chairloader config file not found");
        MessageBox(nullptr,"Chairloader config file not found:\nPlease verify the Chairloader installation", "Error", MB_OK);
        exit(-1);
    }
    log(severityLevel::info, "Chairloader Config File Loaded");
    ModListNode = ChairloaderConfigFile.child("Chairloader").child("ModList");
    std::string foundMods = "Previously Loaded Mods Found:";
    for(auto &foundMod : ModListNode){
        foundMods += std::string(" ") + foundMod.name() + ",";
    }
    log(severityLevel::info, "%s", foundMods);
//    fs::remove("ChairloaderModLoader.log");
    std::ofstream ofs("ChairloaderModLoader.log", std::fstream::out | std::fstream::trunc);
    ofs.close();
    //DO something
    loadModInfoFiles();
}



void ModLoader::FindMod(Mod* modEntry) {
//    auto ModListNode = ChairloaderConfigFile.child("Chairloader").child("ModList");
    if(std::find(ModList.begin(), ModList.end(),modEntry->modName) != ModList.end()) {
        if (ModListNode.child(modEntry->modName.c_str())) {
            auto modNode = ModListNode.child(modEntry->modName.c_str());
            modEntry->XMLEnable = modNode.child("XMLLoadEnable").text().as_bool();
            modEntry->DLLEnable = modNode.child("DLLLoadEnable").text().as_bool();
            modEntry->loadOrder = modNode.child("loadOrder").text().as_int();
            if(modEntry->version != modNode.child("version").text().as_string()){
                log(severityLevel::warning, "%s: config version mismatch, TODO: fix this automatically", modEntry->modName);
            }
            // TODO: check version
            // TODO: handle configs
        } else {
            modEntry->XMLEnable = true;
            modEntry->DLLEnable = true;
            modEntry->loadOrder = 0;
            // TODO: copy default config

        }
    }
    //TODO: find existing load order in the chairloader config file, or return next available order
    //TODO: keep track of next available position

}

void ModLoader::SaveMod(ModLoader::Mod *modEntry) {
    if(modEntry == nullptr)
        return;
    auto modNode = ModListNode.child(modEntry->modName.c_str());
    if(modNode){
        modNode.child("modName").text().set(modEntry->modName.c_str());
        modNode.child("loadOrder").text().set(modEntry->loadOrder);
        modNode.child("version").text().set(modEntry->version.c_str());
        modNode.child("DLLLoadEnable").text().set(modEntry->DLLEnable);
        modNode.child("XMLLoadEnable").text().set(modEntry->XMLEnable);
    } else {
        ModListNode.append_child(modEntry->modName.c_str());
            modNode = ModListNode.child(modEntry->modName.c_str());
            modNode.append_attribute("type").set_value("xmlnode");
            //modName
            auto node = modNode.append_child("modName");
            node.append_attribute("type").set_value("string");
            node.text().set(modEntry->modName.c_str());
            //loadOrder
            node = modNode.append_child("loadOrder");
            node.append_attribute("type").set_value("int");
            node.text().set(modEntry->loadOrder);
            //DLLLoad
            node = modNode.append_child("DLLLoadEnable");
            node.append_attribute("type").set_value("bool");
            node.text().set(modEntry->DLLEnable);
            //XMLLoad
            node = modNode.append_child("XMLLoadEnable");
            node.append_attribute("type").set_value("bool");
            node.text().set(modEntry->XMLEnable);
            //Version
            node = modNode.append_child("version");
            node.append_attribute("type").set_value("string");
            node.text().set(modEntry->version.c_str());
        //TODO: append
    }
    //TODO: save the config file in the right format
    ChairloaderConfigFile.save_file((PreyPath.string() + "/Mods/config/Chairloader.xml").c_str());
}

void ModLoader::LoadModsFromConfig() {
    for(auto &modEntry: ModListNode){
        if(std::find(ModList.begin(), ModList.end(),modEntry.child("modName").text().as_string()) == ModList.end()){
            Mod newMod;
            newMod.modName = modEntry.child("modName").text().as_string();
        }
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


