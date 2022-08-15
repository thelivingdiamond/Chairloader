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


WorldManager::WorldManager(ChairloaderGlobalEnvironment* env) {
    gCLEnv = env;
}

void WorldManager::Draw() {
    DrawMenuBar();
    DrawLevelManagerWindow();
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
            gEnv->pSystem->GetLocalizationManager()->LocalizeString(
                    locationManager.GetLocationLabel(locationManager.GetCurrentLocation()), currentLocation);
            ImGui::Text("Current Map: %ls", currentLocation.c_str());
            std::string mapId = std::to_string(locationManager.GetCurrentLocation());
            if(ImGui::Selectable(mapId.c_str())){
                CryLog("%s", mapId.c_str());
            }
            if(ImGui::BeginTable("Map List", 2, ImGuiTableFlags_Resizable)) {
                ImGui::TableSetupColumn("Map Name");
                ImGui::TableSetupColumn("Map ID");
                ImGui::TableHeadersRow();
//                CryLog("%u", locationMap.size());
                for(auto& map : locationMap){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("%s", map.first.c_str());
                    ImGui::TableNextColumn();
                    if(ImGui::Selectable(locationManager.GetLocationLabel(locationManager.GetCurrentLocation()))){
                        //do nothing I guess
                    }
//                    ImGui::Text("%llu", map.second);
                }
                ImGui::EndTable();
            }
//            ImGui::Text("Is In Level Load: %u", gCLEnv->cl->GetFramework()->IsInLevelLoad());
            static std::string levelToLoad = "arboretum";
            static std::string mission = "Mission0";
            ImGui::InputText("Level To Load", &levelToLoad);
            ImGui::InputText("Mission", &mission);
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
            ImGui::MenuItem("Open", nullptr, &showLevelManagerWindow);
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();

    }

}
