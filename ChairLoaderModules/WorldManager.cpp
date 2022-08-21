//
// Created by theli on 7/31/2022.
//

#include "WorldManager.h"
#include "Prey/GameDll/ark/ArkGame.h"
#include "Prey/GameDll/ark/ArkLocationManager.h"
#include "Prey/CrySystem/ILocalizationManager.h"
#include "ChairLoader/IChairloader.h"
#include "Prey/CryGame/IGameFramework.h"
#include "Prey/ArkLocationLibrary.h"
#include "Prey/Cry3DEngine/I3DEngine.h"
#include "Prey/CryAction/ark/ArkSaveLoadSystem.h"
#include "Prey/CryAction/CryAction.h"
#include "Prey/CryAction/ILevelSystem.h"
#include "Prey/GameDll/ark/ArkGameStateConditionManager.h"
#include "Prey/GameDll/ark/player/ArkPlayer.h"
#include "Prey/GameDll/ark/player/ArkUtilityComponent.h"
#include "Prey/GameDll/ark/player/ArkStationAccessComponent.h"
#include "Prey/ArkKeycardLibrary.h"
#include "Prey/CrySystem/File/CryFile.h"
#include "Prey/CrySystem/File/ICryPak.h"

WorldManager::WorldManager(ChairloaderGlobalEnvironment* env) {
    gCLEnv = env;
    stationAccessLibrary = gEnv->pSystem->GetXmlUtils()->LoadBinaryXmlFile("Ark/Campaign/ArkStationAccessLibrary.xml");
}

void WorldManager::Draw() {
    DrawMenuBar();
    DrawLevelManagerWindow();
    DrawKeycardManagerWindow();
    DrawStationAccessManagerWindow();
}

void WorldManager::Update() {

}

std::string WorldManager::GetModuleName() {
    return std::string();
}

void WorldManager::DrawLevelManagerWindow() {
    if(showLevelManagerWindow) {
        if (ImGui::Begin("Level Manager", &showLevelManagerWindow)) {
            auto locationManager = ArkGame::GetArkGame()->GetArkLocationManager();
            wstring currentLocation;
            gEnv->pSystem->GetLocalizationManager()->LocalizeString(locationManager.GetLocationLabel(locationManager.GetCurrentLocation()), currentLocation);
            ImGui::Text("Current Map: %ls", currentLocation.c_str());
            std::string mapId = std::to_string(locationManager.GetCurrentLocation());
            if(ImGui::Selectable(mapId.c_str())){
                CryLog("%s", mapId.c_str());
            }
//            if(ImGui::BeginTable("Map List", 2, ImGuiTableFlags_Resizable)) {
//                ImGui::TableSetupColumn("Map Name");
//                ImGui::TableSetupColumn("Map ID");
//                ImGui::TableHeadersRow();
////                CryLog("%u", locationMap.size());
//                for(auto& map : locationMap){
//                    ImGui::TableNextRow();
//                    ImGui::TableNextColumn();
//                    ImGui::Text("%s", map.first.c_str());
//                    ImGui::TableNextColumn();
//                    if (ImGui::Selectable(locationManager.GetLocationLabel(map.second.name.c_str()))) {
//                        //FIXME: add a way to load maps from the table
////                        gCLEnv->cl->GetFramework()->ScheduleEndLevelNow(std::string(map.first).substr(std::string("@ui_").size(), std::string(map.first).size() - 1).c_str());
//                    }
//                }
//                ImGui::EndTable();
//            }
//            ImGui::Text("Is In Level Load: %u", gCLEnv->cl->GetFramework()->IsInLevelLoad());
            static std::string levelToLoad = "arboretum";
//            static std::string mission = "Mission0";
            ImGui::InputText("Level To Load", &levelToLoad);
//            ImGui::InputText("Mission", &mission);
            if(ImGui::Button("Load Level")){
//                gEnv->pConsole->ExecuteString(("map " + levelToLoad + " nb").c_str());
//                ArkGame::GetArkGame()->LoadLastSave(ArkGame::GetArkGame()->m_pLoadListener);
                gCLEnv->cl->GetFramework()->ScheduleEndLevelNow(levelToLoad.c_str());
//                auto &iarkSaveLoadSystem = gCLEnv->cl->GetFramework()->GetArkSaveLoadSystem();
//                auto arksaveload = (ArkSaveLoadSystem*)&iarkSaveLoadSystem;
            }
        }

        ImGui::End();
    }
}



void WorldManager::DrawMenuBar() {
    if(ImGui::BeginMainMenuBar()){
        if(ImGui::BeginMenu("Level Manager")){
            ImGui::MenuItem("Open Level Manager", nullptr, &showLevelManagerWindow);
            ImGui::MenuItem("Open Keycard Manager", nullptr, &showKeycardManagerWindow);
            ImGui::MenuItem("Open Station Access Manager", nullptr, &showStationAccessManagerWindow);
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();

    }

}

void WorldManager::DrawKeycardManagerWindow() {
    if(showKeycardManagerWindow){
        if(ImGui::Begin("Keycard Manager", &showKeycardManagerWindow, ImGuiWindowFlags_NoNavInputs)){
            ImGui::Text("Keycard Manager");
            if(ImGui::BeginTable("Keycard", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY, ImVec2{0,300})){
//                ArkPlayerComponent component;

                ImGui::TableSetupColumn("Keycard Name");
                ImGui::TableSetupColumn("Keycard ID");
                ImGui::TableSetupScrollFreeze(1, 1);
                ImGui::TableHeadersRow();
                for(auto& keycard : ArkKeycardLibrary){
                    auto keycardID = keycard.first;
                    if(gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
                        if (gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pKeyCardComponent->HasKeyCard(keycardID)) {
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            ImGui::TextDisabled("%s", keycard.second.c_str());
                            ImGui::TableNextColumn();
                            ImGui::TextDisabled("%llu", keycard.first);
                        } else {
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            ImGui::Text("%llu", keycard.first);
                            ImGui::TableNextColumn();
                            if (ImGui::Selectable(keycard.second.c_str())) {
                                gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pKeyCardComponent->Collect(keycard.first);
                            }
                        }
                    }
                }
                ImGui::EndTable();
            }
            if(ImGui::Button("Unlock All Keycards")){
                for(auto& keycard : ArkKeycardLibrary){
                    if(gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
                        if(!gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pKeyCardComponent->HasKeyCard(keycard.first)){
                            gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pKeyCardComponent->Collect(keycard.first);
                        }
                    }
                }
            }
        }
        ImGui::End();
    }
}

void WorldManager::DrawStationAccessManagerWindow() {
    if(showStationAccessManagerWindow) {
        if(ImGui::Begin("Station Access")) {
            static std::string xmlFile = "Ark/Campaign/StationAccessLibrary.xml";
            ImGui::InputText("XML File", &xmlFile);
            CCryFile file;
            if(ImGui::Button("Load XML File")){
                stationAccessLibrary = gEnv->pSystem->LoadXmlFromFile(xmlFile.c_str());
            }
            if(ImGui::Button("Check XML File")){
//                char buffer[300000];
                auto xmlstring = stationAccessLibrary->getXML(0);
                if(xmlstring) {
                    CryLog("size: %i \n%s", xmlstring.size(), xmlstring.c_str());
                    pugi::xml_document doc;
                    auto result = doc.load_buffer(xmlstring.c_str(), 1000);
                    CryLog("Result: %s", result.description());
//                    xmlstring->Release();
                } else {
                    CryError("XML String is null");
                }
            }
            if(ImGui::Button("Open File")){
                if(file.Open(xmlFile.c_str(), "rb")){
                    CryLog("File opened: %s, size: %i", file.GetFilename(), file.GetLength());
                    pugi::xml_document doc;
                    std::string buffer;
                    buffer.resize(file.GetLength());
                    file.ReadRaw(&buffer[0], file.GetLength());
                    for(auto& c : buffer){
                        CryLog("%c", c);
                    }
                    CryLog("%s", buffer.c_str());
                    auto result = doc.load_buffer(buffer.c_str(), file.GetLength(), pugi::parse_default, pugi::encoding_auto);
                    CryLog("Result: %s", result.description());
                    file.Close();
                } else {
                    CryLog("File not opened");
                }
            }
            if (gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
                if (ImGui::BeginTable("Locked Paths", 1, ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY, ImVec2{0, 100})) {
                    ImGui::TableSetupColumn("Locked Path");
                    ImGui::TableSetupScrollFreeze(1,1);
                    ImGui::TableHeadersRow();
                    for (auto &lockedPath: gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.GetStationAccessComponent().m_lockedPaths) {
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
//                        auto name = stationAccessLibrary->findChild("Paths")->findChildWithAttibuteValue("ID", ToString(lockedPath).c_str())->getAttr("Name");
                        ImGui::Text("%llu: %s", lockedPath, "");
                        if(ImGui::IsItemClicked()){
                            CryLog("Locked Path %llu clicked", lockedPath);
                        }
                    }
                    ImGui::EndTable();
                }
                if (ImGui::BeginTable("Locked Airlocks", 1, ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY,
                                      ImVec2{0, 100})) {
                    ImGui::TableSetupColumn("Locked Airlock");
                    ImGui::TableSetupScrollFreeze(1,1);
                    ImGui::TableHeadersRow();
                    for (auto &lockedAirlock: gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.GetStationAccessComponent().m_lockedAirlocks) {
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("%llu", lockedAirlock);
                        if(ImGui::IsItemClicked()){
                            CryLog("Locked Airlock %llu clicked", lockedAirlock);
                        }

                    }
                    ImGui::EndTable();
                }
                if (ImGui::BeginTable("Hidden Airlocks", 1, ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY,
                                      ImVec2{0, 100})) {
                    ImGui::TableSetupColumn("Hidden Airlocks");
                    ImGui::TableSetupScrollFreeze(1,1);
                    ImGui::TableHeadersRow();
                    for (auto &hiddenAirlock: gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.GetStationAccessComponent().m_hiddenAirlocks) {
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("%llu", hiddenAirlock);
                        if(ImGui::IsItemClicked()){
                            CryLog("Hidden Airlock %llu clicked", hiddenAirlock);
                        }
                    }
                    ImGui::EndTable();
                }
            }
        }
        ImGui::End();
    }

}
