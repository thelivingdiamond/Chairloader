
#include "WorldManager.h"
#include "Prey/GameDll/ark/ArkGame.h"
#include "Prey/GameDll/ark/ArkLocationManager.h"
#include "Prey/CrySystem/ILocalizationManager.h"
#include "ChairLoader/IChairloader.h"
#include "Prey/CryGame/IGameFramework.h"
//#include "Prey/ArkLocationLibrary.h"
#include "Prey/Cry3DEngine/I3DEngine.h"
#include "Prey/CryAction/ark/ArkSaveLoadSystem.h"
#include "Prey/CryAction/CryAction.h"
#include "Prey/CryAction/ILevelSystem.h"
#include "Prey/GameDll/ark/ArkGameStateConditionManager.h"
#include "Prey/GameDll/ark/player/ArkPlayer.h"
#include "Prey/GameDll/ark/player/ArkUtilityComponent.h"
#include "Prey/GameDll/ark/player/ArkPlayerUIComponent.h"
#include "Prey/GameDll/ark/player/ArkStationAccessComponent.h"
#include "Prey/CrySystem/File/CryFile.h"
#include "Prey/CrySystem/File/ICryPak.h"
WorldManager::WorldManager() {
    stationAccessLibrary = gEnv->pSystem->LoadXmlFromFile("Ark/Campaign/ArkStationAccessLibrary.xml");
    loadStationAccessLibrary();
    loadLocationLibrary();
    loadKeycardLibrary();
    loadKeycodeLibrary();
    loadCharacterLibrary();
}


void WorldManager::Draw() {
    DrawMenuBar();
    DrawLevelManagerWindow();
    DrawStationAccessManagerWindow();
    DrawCharacterManagerWindow();
}

std::string WorldManager::GetModuleName() {
    return ModuleName;
}

void WorldManager::DrawLevelManagerWindow() {
    if(showLevelManagerWindow) {
        if (ImGui::Begin("Level Manager", &showLevelManagerWindow)) {
            static std::string levelToLoad;
            if(ArkGame::GetArkGame() != nullptr) {
                auto locationManager = ArkGame::GetArkGame()->GetArkLocationManager();
                wstring currentLocation;
                gEnv->pSystem->GetLocalizationManager()->LocalizeString(
                        locationManager.GetLocationLabel(locationManager.GetCurrentLocation()), currentLocation);
                ImGui::Text("Current Map: %ls", currentLocation.c_str());
                std::string mapId = std::to_string(locationManager.GetCurrentLocation());
                if (ImGui::Selectable(mapId.c_str())) {
                    CryLog("{}", mapId);
                }
            }
            if(ImGui::BeginTable("Map List", 1, ImGuiTableFlags_ScrollY, ImVec2(0, ImGui::GetContentRegionAvail().y - 60.0f))) {
                ImGui::TableSetupColumn("Map Name");
                ImGui::TableSetupScrollFreeze(1, 1);
                ImGui::TableHeadersRow();
                for(auto& location : ArkLocations){
                    if(!location.second.LevelName.empty()) {
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        if (ImGui::Selectable(location.second.Name.c_str())) {
                            levelToLoad = location.second.LevelName;
                        }
                    }
                }
                ImGui::EndTable();
            }
            ImGui::InputText("Level To Load", &levelToLoad);
            if(ImGui::Button("Load Level")){
                gCL->cl->GetFramework()->ScheduleEndLevelNow(levelToLoad.c_str());
            }
        }
        ImGui::End();
    }
}



void WorldManager::DrawMenuBar() {
    if(ImGui::BeginMainMenuBar()){
        if (ImGui::BeginMenu("Trainer")) {
            if(ImGui::BeginMenu("World")){
                ImGui::MenuItem("Open Level Manager", nullptr, &showLevelManagerWindow);
                ImGui::MenuItem("Open Station Access Manager", nullptr, &showStationAccessManagerWindow);
                ImGui::MenuItem("Open Character Manager", nullptr, &showCharacterManagerWindow);
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

}

void WorldManager::DrawKeycardManagerTab() {
    if(ImGui::BeginTabItem("Keycard Manager")){
        if(ImGui::Button("Load Keycard Library")){
            loadKeycardLibrary();
        }
        static ImGuiTextFilter filter;
        filter.Draw();
        if(ImGui::BeginTable("Keycard", 1, ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY, ImVec2{0,ImGui::GetContentRegionAvail().y - 60.0f})){
//                ArkPlayerComponent component;

            ImGui::TableSetupColumn("Keycard Name");
            ImGui::TableSetupScrollFreeze(1, 1);
            ImGui::TableHeadersRow();
            for(auto& keycard : ArkKeycardNames){
                auto keycardID = keycard.second;
                if(ArkPlayer::GetInstancePtr() != nullptr) {
                    if(filter.PassFilter(keycard.first.c_str())) {
                        if (ArkPlayer::GetInstancePtr()->m_playerComponent.m_pKeyCardComponent->HasKeyCard(
                                keycardID)) {
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            ImGui::TextDisabled("%s", keycard.first.c_str());
                        } else {
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            if (ImGui::Selectable(keycard.first.c_str())) {
                                ArkPlayer::GetInstancePtr()->m_playerComponent.m_pKeyCardComponent->Collect(
                                        keycard.second);
                            }
                        }
                    }
                }
            }
            ImGui::EndTable();
        }
        if(ImGui::Button("Unlock All Keycards")){
            for(auto& keycard : ArkKeycards){
                if(ArkPlayer::GetInstancePtr() != nullptr) {
                    if(!ArkPlayer::GetInstancePtr()->m_playerComponent.m_pKeyCardComponent->HasKeyCard(keycard.first)){
                        ArkPlayer::GetInstancePtr()->m_playerComponent.m_pKeyCardComponent->Collect(keycard.first);
                    }
                }
            }
        }
        ImGui::EndTabItem();
    }
}

//TODO: determine if this is worth keeping
void WorldManager::DrawStationAccessManagerWindow() {
    if(showStationAccessManagerWindow) {
        if(ImGui::Begin("Station Access Manager", &showStationAccessManagerWindow, ImGuiWindowFlags_NoNavInputs)) {
            if(ImGui::BeginTabBar("Station Access")) {
                DrawKeycardManagerTab();
                DrawKeycodeManagerTab();
                DrawPasswordManagerTab();
                DrawPathAirlockManagerTab();
                ImGui::EndTabBar();
            }
        }
        ImGui::End();
    }
}

void WorldManager::loadStationAccessLibrary() {
    stationAccessLibrary = gEnv->pSystem->LoadXmlFromFile("Ark/Campaign/StationAccessLibrary.xml");
    if(stationAccessLibrary) {
        CryLog("StationAccessLibrary loaded");
        ArkStationPaths.clear();
        ArkStationAirlocks.clear();
    } else {
        CryError("StationAccessLibrary not loaded");
        return;
    }
    if(stationAccessLibrary->findChild("Paths")){
        auto paths = stationAccessLibrary->findChild("Paths");
        for(int i = 0; i < paths->getChildCount(); i++) {
            pathEntry newPath;
            if(paths->getChild(i)){
                auto path = paths->getChild(i);
                if(path->haveAttr("ID")){
                    path->getAttr("ID", newPath.ID);
                }
                if(path->haveAttr("Name")){
                    newPath.Name= path->getAttr("Name");
                }
                if(path->haveAttr("FlashID")){
                    newPath.FlashID = path->getAttr("FlashID");
                }
                if(path->haveAttr("LocationA")){
                    path->getAttr("LocationA", newPath.LocationA);
                }
                if(path->haveAttr("LocationB")){
                    path->getAttr("LocationB", newPath.LocationB);
                }
            }
            if(newPath.ID != 0 && !newPath.Name.empty()){
                ArkStationPaths.insert(std::pair(newPath.ID, newPath));
            }
        }
    }
    if(stationAccessLibrary->findChild("Airlocks")){
        auto airlocks = stationAccessLibrary->findChild("Airlocks");
        for(int i = 0; i < airlocks->getChildCount(); i++) {
            airlockEntry newAirlock;
            if (airlocks->getChild(i)) {
                auto airlock = airlocks->getChild(i);
                if(airlock->haveAttr("ID")){
                    airlock->getAttr("ID", newAirlock.ID);
                }
                if(airlock->haveAttr("Location")){
                    airlock->getAttr("Location", newAirlock.Location);
                }
                if(airlock->haveAttr("StartsLocked")){
                    airlock->getAttr("StartsLocked", newAirlock.StartsLocked);
                }
                if(airlock->haveAttr("StartsHidden")){
                    airlock->getAttr("StartsHidden", newAirlock.StartsHidden);
                }
                if(newAirlock.ID != 0 && newAirlock.Location != 0){
                    ArkStationAirlocks.insert(std::pair(newAirlock.ID, newAirlock));
                }
            }
        }
    }
}

void WorldManager::loadLocationLibrary() {
    locationLibrary = gEnv->pSystem->LoadXmlFromFile("Ark/Campaign/Locations.xml");
    if(locationLibrary) {
        CryLog("LocationLibrary loaded");
        ArkLocations.clear();
    } else {
        CryError("LocationLibrary not loaded");
        return;
    }

    if(locationLibrary->findChild("Locations")) {
        for(int i = 0; i < locationLibrary->findChild("Locations")->getChildCount(); i++) {
            locationInfo newLocation;
            if (locationLibrary->findChild("Locations")->getChild(i)) {
                auto location = locationLibrary->findChild("Locations")->getChild(i);
                if(location->haveAttr("ID")){
                    location->getAttr("ID", newLocation.ID);
                }
                if(location->haveAttr("Name")){
                    newLocation.Name = location->getAttr("Name");
                }
                if(location->haveAttr("Label")){
                    newLocation.Label = location->getAttr("Label");
                }
                if(location->haveAttr("LevelName")){
                    newLocation.LevelName = location->getAttr("LevelName");
                }
                if(location->haveAttr("Cooldown")){
                    location->getAttr("Cooldown", newLocation.Cooldown);
                }
                if(location->haveAttr("StationMapIndex")){
                    location->getAttr("StationMapIndex", newLocation.StationMapIndex);
                }
                if(location->haveAttr("Tip")){
                    location->getAttr("Tip", newLocation.Tip);
                }
                if(location->haveAttr("ScreenshotPath")){
                    newLocation.ScreenshotPath = location->getAttr("ScreenshotPath");
                }
                if(location->haveAttr("RichPresence")){
                    newLocation.RichPresence = location->getAttr("RichPresence");
                }
                if(newLocation.ID != 0 && !newLocation.Name.empty()){
                    ArkLocations.insert(std::pair(newLocation.ID, newLocation));
                }
            }
        }
    }
}

void WorldManager::loadKeycardLibrary() {
    keycardLibrary = gEnv->pSystem->LoadXmlFromFile("Ark/Campaign/KeycardLibrary.xml");
    if(keycardLibrary) {
        CryLog("KeycardLibrary loaded");
        ArkKeycards.clear();
    } else {
        CryError("KeycardLibrary not loaded");
        return;
    }
    if(keycardLibrary->findChild("KeyCards")) {
        for(int i = 0; i < keycardLibrary->findChild("Keycards")->getChildCount(); i++) {
            keycardEntry newKeycard;
            if (keycardLibrary->findChild("Keycards")->getChild(i)) {
                auto keycard = keycardLibrary->findChild("Keycards")->getChild(i);
                if(keycard->haveAttr("ID")){
                    keycard->getAttr("ID", newKeycard.ID);
                }
                if(keycard->haveAttr("Name")){
                    newKeycard.Name = keycard->getAttr("Name");
                }
                if(keycard->haveAttr("Label")){
                    newKeycard.Label = keycard->getAttr("Label");
                }
                if(keycard->haveAttr("Location")){
                    keycard->getAttr("Location", newKeycard.Location);
                }
                if(newKeycard.ID != 0 && !newKeycard.Name.empty() && newKeycard.Location != 0){
                    ArkKeycards.insert(std::pair(newKeycard.ID, newKeycard));
                }
            }
        }
    }
    sortKeycardDisplayList();
}

void WorldManager::sortKeycardDisplayList() {
    ArkKeycardNames.clear();
    for(auto & keycard: ArkKeycards) {
        ArkKeycardNames.insert(std::pair(keycard.second.Name, keycard.second.ID));
    }
}

void WorldManager::loadKeycodeLibrary() {
    keycodeLibrary = gEnv->pSystem->LoadXmlFromFile("Ark/Campaign/KeycodeLibrary.xml");
    if(keycodeLibrary) {
        CryLog("Keycode Library loaded");
        ArkKeycodes.clear();
    } else {
        CryError("Keycode Library not loaded");
        return;
    }
    if(keycodeLibrary->findChild("KeyCodes")) {
        for(int i = 0; i < keycodeLibrary->findChild("KeyCodes")->getChildCount(); i++) {
            keycodeEntry newKeycode;
            if (keycodeLibrary->findChild("Keycodes")->getChild(i)) {
                auto keycode = keycodeLibrary->findChild("Keycodes")->getChild(i);
                if(keycode->haveAttr("ID")){
                    keycode->getAttr("ID", newKeycode.ID);
                }
                if(keycode->haveAttr("Name")){
                    newKeycode.Name = keycode->getAttr("Name");
                }
                if(keycode->haveAttr("Label")){
                    newKeycode.Label = keycode->getAttr("Label");
                }
                if(keycode->haveAttr("Location")){
                    keycode->getAttr("Location", newKeycode.Location);
                }
                if(keycode->haveAttr("Code")){
                    newKeycode.Code = keycode->getAttr("Code");
                }
                if(newKeycode.ID != 0 && !newKeycode.Name.empty() && newKeycode.Location != 0){
                    ArkKeycodes.insert(std::pair(newKeycode.ID, newKeycode));
                }
            }
        }
    }
}

void WorldManager::DrawKeycodeManagerTab() {
    if (ImGui::BeginTabItem("Keycode Manager")) {
        if (ImGui::Button("Load Keycode Library")) {
            loadKeycodeLibrary();
        }
        static ImGuiTextFilter filter;
        filter.Draw();
        auto player = ArkPlayer::GetInstancePtr();
        if (ImGui::BeginTable("Keycodes", 1, ImGuiTableFlags_ScrollY,
                              ImVec2(0, ImGui::GetContentRegionAvail().y - 60.0f))) {
            ImGui::TableSetupColumn("Name");
            ImGui::TableSetupScrollFreeze(1, 1);
            ImGui::TableHeadersRow();
            for (auto &keycode: ArkKeycodes) {
                if (ArkPlayer::GetInstancePtr() != nullptr) {
                    if(filter.PassFilter(keycode.second.Name.c_str())) {
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        if (player->m_playerComponent.GetKeyCodeComponent().GetEntry(keycode.first)->m_bCollected) {
                            ImGui::TextDisabled("%s", keycode.second.Name.c_str());
                        } else {
                            if (ImGui::Selectable(keycode.second.Name.c_str())) {
                                player->m_playerComponent.GetKeyCodeComponent().Collect(keycode.first);
                            }
                        }
                    }
                }
            }
            ImGui::EndTable();
        }
        if (ImGui::Button("Unlock all Keycodes")) {
            if (ArkPlayer::GetInstancePtr() != nullptr) {
                for (auto &keycode: ArkKeycodes) {
                    if (!player->m_playerComponent.GetKeyCodeComponent().GetEntry(keycode.first)->m_bCollected) {
                        player->m_playerComponent.GetKeyCodeComponent().Collect(keycode.first);
                    }
                }
            }
        }
        ImGui::EndTabItem();
    }
}

void WorldManager::DrawPasswordManagerTab() {
    if (ImGui::BeginTabItem("Password Manager")) {
        if(ImGui::Button("Load Character Library")) {
            loadCharacterLibrary();
        }
        static ImGuiTextFilter filter;
        filter.Draw();
        if(ImGui::BeginTable("Passwords", 2, ImGuiTableFlags_ScrollY, ImVec2(0, ImGui::GetContentRegionAvail().y - 60.0f))) {
            ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupColumn("Password", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupScrollFreeze(1, 1);
            ImGui::TableHeadersRow();
            if (ArkPlayer::GetInstancePtr() != nullptr) {
                auto player = ArkPlayer::GetInstancePtr();
                for (auto &character: ArkCharacters) {
                    if(!character.second.Password.empty()) {
                        if(filter.PassFilter(character.second.Name.c_str())) {
                            if (!player->m_playerComponent.GetRosterComponent().HasPassword(character.second.ID)) {
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                if (ImGui::Selectable(character.second.Name.c_str(), false,
                                                      ImGuiSelectableFlags_SpanAllColumns)) {
                                    player->m_playerComponent.GetRosterComponent().GivePassword(character.second.ID,
                                                                                                true);
                                }
                                ImGui::TableNextColumn();
                                ImGui::Text("%s", character.second.Password.c_str());
                            } else {
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                ImGui::TextDisabled("%s", character.second.Name.c_str());
                                ImGui::TableNextColumn();
                                ImGui::TextDisabled("%s", character.second.Password.c_str());
                            }
                        }
                    }
                }
            }
            ImGui::EndTable();
        }
        if(ImGui::Button("Unlock all Passwords")) {
            if (ArkPlayer::GetInstancePtr() != nullptr) {
                auto player = ArkPlayer::GetInstancePtr();
                for (auto &character: ArkCharacters) {
//                        if(!character.second.Password.empty()) {
                        if(!player->m_playerComponent.GetRosterComponent().HasPassword(character.second.ID)) {
                            player->m_playerComponent.GetRosterComponent().GivePassword(character.second.ID, false);
                        }
//                        }
                }
            }
        }
        ImGui::EndTabItem();
    }
}

void WorldManager::loadCharacterLibrary() {
    characterLibrary = gEnv->pSystem->LoadXmlFromFile("Ark/Campaign/CharacterLibrary.xml");
    if(characterLibrary) {
        CryLog("Character Library loaded");
        ArkCharacters.clear();
    } else {
        CryError("Character Library not loaded");
        return;
    }
    if(characterLibrary->findChild("Characters")) {
        for(int i = 0; i < characterLibrary->findChild("Characters")->getChildCount(); i++) {
            characterInfo newCharacter;
            if (characterLibrary->findChild("Characters")->getChild(i)) {
                auto character = characterLibrary->findChild("Characters")->getChild(i);
                // ID, Name, Label, JobTitle, Group ,VitalSigns, IsAlive, HasTrackingChip, Voice, Location, Notes, IsPlaced, Portrait
                if(character->haveAttr("ID")){
                    character->getAttr("ID", newCharacter.ID);
                }
                if(character->haveAttr("Name")){
                    newCharacter.Name = character->getAttr("Name");
                }
                if(character->haveAttr("Label")){
                    newCharacter.Label = character->getAttr("Label");
                }
                if(character->haveAttr("JobTitle")){
                    newCharacter.JobTitle = character->getAttr("JobTitle");
                }
                if(character->haveAttr("Group")){
                    character->getAttr("Group", newCharacter.Group);
                }
                if(character->haveAttr("VitalSigns")){
                    newCharacter.VitalSigns = character->getAttr("VitalSigns");
                }
                if(character->haveAttr("IsAlive")){
                    character->getAttr("IsAlive", newCharacter.IsAlive);
                }
                if(character->haveAttr("HasTrackingChip")){
                    character->getAttr("HasTrackingChip", newCharacter.HasTrackingChip);
                }
                if(character->haveAttr("Voice")){
                    character->getAttr("Voice", newCharacter.Voice);
                }
                if(character->haveAttr("Location")){
                    character->getAttr("Location", newCharacter.Location);
                }
                if(character->haveAttr("Password")){
                    newCharacter.Password = character->getAttr("Password");
                }
                if(character->haveAttr("Notes")){
                    newCharacter.Notes = character->getAttr("Notes");
                }
                if(character->haveAttr("IsPlaced")){
                    newCharacter.IsPlaced = character->getAttr("IsPlaced");
                }
                if(character->haveAttr("Portrait")){
                    newCharacter.Portrait = character->getAttr("Portrait");
                }
                if(newCharacter.ID != 0 && !newCharacter.Name.empty() && newCharacter.Location != 0){
                    ArkCharacters.insert(std::pair(newCharacter.ID, newCharacter));
                }
            }
        }
    }
    sortCharacterDisplayList();
}

void WorldManager::DrawCharacterManagerWindow() {
    static uint64_t selectedCharacter = 0;
    if(showCharacterManagerWindow) {
        if (ImGui::Begin("Character Manager")) {
            if (ImGui::BeginChild("Character List", ImVec2(250.0f,0))) {
                if (ImGui::Button("Load Character Library")) {
                    loadCharacterLibrary();
                }
                static ImGuiTextFilter filter;
                filter.Draw();
                if (ImGui::BeginTable("Characters", 1, ImGuiTableFlags_ScrollY,
                                      ImVec2(0, 0))) {
                    ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
                    ImGui::TableSetupScrollFreeze(1, 1);
                    ImGui::TableHeadersRow();
                    if (ArkPlayer::GetInstancePtr() != nullptr) {
                        auto player = ArkPlayer::GetInstancePtr();
                        for (auto &character: ArkCharacterNames) {
                            if(filter.PassFilter(character.first.c_str()) || strlen(filter.InputBuf) == 0) {
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                if (ImGui::Selectable(character.first.c_str(),
                                                      selectedCharacter == character.second,
                                                      ImGuiSelectableFlags_SpanAllColumns)) {
                                    selectedCharacter = character.second;
                                }
                            }
                        }
                    }
                    ImGui::EndTable();
                }
            }
            ImGui::EndChild();
            ImGui::SameLine();
            if (ImGui::BeginChild("Character Info")) {
                if (ArkCharacters.find(selectedCharacter) != ArkCharacters.end()) {
                    auto character = ArkCharacters.at(selectedCharacter);
                    if(ArkPlayer::GetInstancePtr() != nullptr && selectedCharacter != 0) {
                        auto player = ArkPlayer::GetInstancePtr();
                        auto characterStatus = player->m_playerComponent.GetRosterComponent().GetCharacterStatus(
                                selectedCharacter);
                        if (ImGui::BeginChild("List", ImVec2(0, ImGui::GetContentRegionAvail().y - 60.0f))) {
                            if (characterStatus) {
                                ImGui::Text("Name: %s", character.Name.c_str());
                                wstring localizedName;
                                gEnv->pSystem->GetLocalizationManager()->LocalizeString(character.Label.c_str(), localizedName);
                                ImGui::Text("Label: %ls", localizedName.c_str());
                                wstring localizedJobTitle;
                                if(gEnv->pSystem->GetLocalizationManager()->LocalizeString(character.JobTitle.c_str(), localizedJobTitle)){
                                    ImGui::Text("Job Title: %ls", localizedJobTitle.c_str());
                                } else {
                                    ImGui::Text("Job Title: %s", character.JobTitle.c_str());
                                }
                                ImGui::Text("Group: %llu", character.Group);
//                            ImGui::Text("Vital Signs: %s", character.VitalSigns.c_str());
                                ImGui::Text("Is Alive: %s", characterStatus->m_bIsAlive ? "Yes" : "No");
                                ImGui::Text("Has Tracking Chip: %s",
                                            characterStatus->m_bHasTrackingChip ? "Yes" : "No");
                                ImGui::Text("Voice: %llu", character.Voice);
                                ImGui::Text("Location: %s", character.Location == 0 ? "Unknown" : ArkLocations.at(
                                        character.Location).Name.c_str());
                                ImGui::Text("Is Placed: %s", character.IsPlaced ? "Yes" : "No");
                                ImGui::Text("Portrait: %s", character.Portrait.c_str());
                                ImGui::Text("Password: %s", character.Password.c_str());
                                ImGui::TextWrapped("Notes: %s", character.Notes.c_str());
                            } else {
                                ImGui::Text("Character Status Not Found");
                                ImGui::BeginDisabled();
                                ImGui::Text("Name: %s", character.Name.c_str());
                                wstring localizedName;
                                gEnv->pSystem->GetLocalizationManager()->LocalizeString(character.Label.c_str(),
                                                                                        localizedName);
                                ImGui::Text("Label: %ls", localizedName.c_str());
                                ImGui::Text("Job Title: %s", character.JobTitle.c_str());
                                ImGui::Text("Group: %llu", character.Group);
//                            ImGui::Text("Vital Signs: %s", character.VitalSigns.c_str());
                                ImGui::Text("Is Alive: %s", character.IsAlive ? "Yes" : "No");
                                ImGui::Text("Has Tracking Chip: %s", character.HasTrackingChip ? "Yes" : "No");
                                ImGui::Text("Voice: %llu", character.Voice);
                                ImGui::Text("Location: %s", character.Location == 0 ? "Unknown" : ArkLocations.at(
                                        character.Location).Name.c_str());
                                ImGui::Text("Is Placed: %s", character.IsPlaced ? "Yes" : "No");
                                ImGui::Text("Portrait: %s", character.Portrait.c_str());
                                ImGui::Text("Password: %s", character.Password.c_str());
                                ImGui::TextWrapped("Notes: %s", character.Notes.c_str());
                                ImGui::EndDisabled();
                            }
                        }
                        ImGui::EndChild();
                        if(ImGui::Button("Discover Character")) {
                            player->m_playerComponent.GetRosterComponent().SetCharacterWasDiscovered(selectedCharacter);
                        }
                        if(ImGui::Button("Kill Character"))
                            player->m_playerComponent.GetRosterComponent().KillCharacter(selectedCharacter);
                    }
                }
            }
            ImGui::EndChild();
        }
        ImGui::End();
    }
}

void WorldManager::sortCharacterDisplayList() {
    ArkCharacterNames.clear();
    for(auto & character: ArkCharacters) {
        ArkCharacterNames.insert(std::pair(character.second.Name, character.second.ID));
    }
}

void WorldManager::DrawPathAirlockManagerTab() {
    if (ImGui::BeginTabItem("Airlocks and Paths")) {
        if (ImGui::Button("Load Station Access Library")) {
            loadStationAccessLibrary();
        }
        if (ImGui::Button("Load Location Library")) {
            loadLocationLibrary();
        }
        if (ArkPlayer::GetInstancePtr() != nullptr) {
            if (ImGui::BeginTable("Locked Paths", 1, ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY,
                                  ImVec2{0, ImGui::GetContentRegionAvail().y * 0.33f})) {
                ImGui::TableSetupColumn("Locked Path");
                ImGui::TableSetupScrollFreeze(1, 1);
                ImGui::TableHeadersRow();
                for (auto &lockedPath: ArkPlayer::GetInstancePtr()->m_playerComponent.GetStationAccessComponent().m_lockedPaths) {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    if (ArkStationPaths.find(lockedPath) != ArkStationPaths.end()) {
                        auto path = ArkStationPaths.find(lockedPath)->second;
                        ImGui::Text("%s", path.Name.c_str());
                        if (ImGui::IsItemClicked()) {
                            ArkPlayer::GetInstancePtr()->m_playerComponent.GetStationAccessComponent().SetPathLocked(
                                    lockedPath, false);
                        }
                    } else {
                        ImGui::Text("%llu", lockedPath);
                    }
                    if (ImGui::IsItemClicked()) {
                        CryLog("Locked Path {} clicked", lockedPath);
                    }
                }
                ImGui::EndTable();
            }
            if (ImGui::BeginTable("Locked Airlocks", 1, ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY,
                                  ImVec2{0, ImGui::GetContentRegionAvail().y * 0.5f})) {
                ImGui::TableSetupColumn("Locked Airlock");
                ImGui::TableSetupScrollFreeze(1, 1);
                ImGui::TableHeadersRow();
                for (auto &lockedAirlock: ArkPlayer::GetInstancePtr()->m_playerComponent.GetStationAccessComponent().m_lockedAirlocks) {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    if (ArkStationAirlocks.find(lockedAirlock) != ArkStationAirlocks.end()) {
                        auto airlock = ArkStationAirlocks.find(lockedAirlock)->second;
                        if (ArkLocations.find(airlock.Location) != ArkLocations.end()) {
                            auto location = ArkLocations.find(airlock.Location)->second;
                            ImGui::Text("%s", location.Name.c_str());
                        } else {
                            ImGui::Text("Location: %llu", airlock.Location);
                            if (ImGui::IsItemClicked()) {
                                CryLog("Location {} clicked", airlock.Location);
                            }
                        }
                    } else {
                        ImGui::Text("%llu", lockedAirlock);
                        if (ImGui::IsItemClicked()) {
                            CryLog("Locked Airlock {} clicked", lockedAirlock);
                        }
                    }


                }
                ImGui::EndTable();
            }
            if (ImGui::BeginTable("Hidden Airlocks", 1, ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY,
                                  ImVec2{0, ImGui::GetContentRegionAvail().y})) {
                ImGui::TableSetupColumn("Hidden Airlocks");
                ImGui::TableSetupScrollFreeze(1, 1);
                ImGui::TableHeadersRow();
                for (auto &hiddenAirlock: ArkPlayer::GetInstancePtr()->m_playerComponent.GetStationAccessComponent().m_hiddenAirlocks) {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("%llu", hiddenAirlock);
                    if (ImGui::IsItemClicked()) {
                        CryLog("Hidden Airlock {} clicked", hiddenAirlock);
                    }
                }
                ImGui::EndTable();
            }
        }
        ImGui::EndTabItem();
    }
}
