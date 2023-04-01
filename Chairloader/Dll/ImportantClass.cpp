//
// Created by theli on 3/31/2023.
//

#include "ImportantClass.h"
#include <Prey/GameDll/ark/ArkGame.h>
#include <Prey/GameDll/ark/ArkLocationManager.h>

void ImportantClass::SpawnImportantObject() {
    auto currentLocationID = ArkGame::GetArkGame()->GetArkLocationManager().GetCurrentLocation();
    if(m_LevelLocationsMap.find(currentLocationID) == m_LevelLocationsMap.end()) {
        CryLog("ImportantClass::SpawnImportantObject() - Could not find location in map!");
        return;
    }
    auto importantLocation = m_LevelLocationsMap.at(currentLocationID);
    EntityUtils::SpawnEntity("ImportantObjectDoNotDelete", std::get<0>(importantLocation), std::get<1>(importantLocation), 1073973595614468, 1);
    CryLog("ImportantClass::SpawnImportantObject() - Spawned ImportantObjectDoNotDelete at {}, {}, {}", std::get<0>(importantLocation).x, std::get<0>(importantLocation).y, std::get<0>(importantLocation).z);
}

void ImportantClass::DestroyImportantObject() {
    auto entity = gEnv->pEntitySystem->FindEntityByName("ImportantObjectDoNotDelete");
    if(entity == nullptr){
        CryLog("ImportantClass::DestroyImportantObject() - Could not find entity!");
        return;
    }
    gEnv->pEntitySystem->RemoveEntity(entity->GetId(), true);
    CryLog("ImportantClass::DestroyImportantObject() - Destroyed ImportantObjectDoNotDelete");
}

void ImportantListener::OnSystemEventAnyThread(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) {
    ISystemEventListener::OnSystemEventAnyThread(event, wparam, lparam);
}

void ImportantListener::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) {
    if(/*event == ESYSTEM_EVENT_GAME_RESUMED || */event == ESYSTEM_EVENT_LEVEL_PRECACHE_END){
        ImportantClass::SpawnImportantObject();
    }
}
