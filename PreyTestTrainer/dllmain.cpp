// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <string>
#include "mem.h"
#include "preyFunctions.h"
#include "proc.h"
#include "preyDllObjects.h"
#include "preyFunctions.h"
#include "ChairloaderUtils.h"
#include "ArkEntityArchetypeLibrary.h"
#include <thread>
// #include "pugixml.hpp"

DWORD WINAPI HackThread(HMODULE hModule) {
	// Create Console
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    uint64_t nextId = 694206942969420;
    std::cout << "Welcome to funland sonic\n";
    // std::cout << "threadId: " << std
    
    // Get Module base
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"PreyDll.dll");

    preyFunctions prey(moduleBase);
    staticObjectPointers staticPointers(moduleBase);
    CEntitySystem* EntitySystem = staticPointers.gEnvPtr->pEntitySystem;
    CGame* CGamePtr = staticPointers.gEnvPtr->pGame;
    ArkNpcSpawnManager* spawner = CGamePtr->m_pArkNpcSpawnManager.get();
    ArkNightmareSpawnManager* nightmareSpawner = CGamePtr->m_pArkNightmareSpawnManager.get();
    ArkPlayer* player = prey.ArkPlayerF->getInstance();
    ArchetypeLibrary archetypeLibrary;
    ChairloaderUtils::NpcSpawnerManager* spawnerManager = new ChairloaderUtils::NpcSpawnerManager(&prey,&staticPointers);
    
    bool bGloo = 0;
    // bypass thread check
    mem::Nop((BYTE*)(moduleBase + 0x020e2c5), 20);
    bool bConsole = false;

    std::cout << "ChairLoader Initialized...\n";
    std::cout << "\nModule Base: 0x" << std::hex << moduleBase << std::dec << "\n\n";

    // std::cout << "Main Thread: " << *(unsigned long*)(moduleBase + 0x242e514) << std::endl;
    // std::cout << "Current Thread: "  << prey.CryGretCurrentThreadId() << std::endl;
    // hack loop
    bool thirdPerson = false;
    bool devMode = false;
    bool freeCam = false;
    bool lockFreeCam = false;
    std::vector<CEntity*> spawnedEntities; 
    while(true) {
        // key input
        if (GetAsyncKeyState(VK_END) & 1) {
            break;
        }
        if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
        	for (int i = 0; i < EntitySystem->m_EntityArray.size(); ++i) {
                // CEntity* entity = *(CEntity**)it._Ptr;
                // std::cout << entity << std::endl;
                if (EntitySystem->m_EntityArray[i] != nullptr) {
                    CEntity* entity = EntitySystem->m_EntityArray[i];
                    // std::cout << entity << std::endl;
                    if (entity->m_guid != 0x0) {
                    	std::string entityName = entity->m_szName.m_str;
                    	// std::cout << entityName << ": " << entity << std::endl;
                        // std::cout << entity->m_pArchetype->m_name.m_str <<": " << entity << std::endl;
                    // if (&entity->m_szName != 0x0) {
                        // std::cout << &entity->m_szName.m_str << std::endl;)
                        //"Igwe"
                        //"ArkNpcSpawner_Mimic1"
                        //"MikaLikaHiMikaHineyHo"
                        //"ArkNpcSpawner_MedicalOperator1"
                    if (entityName == "Igwe" ){
                        Vec3_tpl<float> pos;
                        prey.ArkPlayerF->getPlayerWorldEyePos(player, &pos);
                        // entity->m_vPos = pos;
                        if (entity == nullptr)
                            break;
                        // ChairloaderUtils::dumpEntity(entity, false);
                        
                        // CScriptTable* table = (CScriptTable*)&Itable;
                        // std::cout << table->Count() << std::endl;
                        std::cout << "entity: " << entity << std::endl;
                        IEntityProxy* proxy = ((IEntity*)entity)->GetProxy(EEntityProxy::ENTITY_PROXY_USER);
                        std::cout << "proxy: " << proxy << std::endl;
                        ArkHealthExtension* healthExt = (ArkHealthExtension*)proxy;
                        std::cout <<"Health Ext Entity: "<< healthExt->m_ext.m_pEntity << std::endl;
                        std::cout <<"Health Ext Object: "<< healthExt->m_ext.m_pGameObject << std::endl;
                        uintptr_t proxyBase = (uintptr_t)proxy;
                        // entity->m_szName.m_str = (char*)"Igwe";
                        CGameObject* obj = (CGameObject*)(proxyBase + 0x28);
                        // CGameObject* obj = (CGameObject*)(((IGameObjectExtension*)proxy)->m_pGameObject);
                        std::cout << "obj: " << obj << std::endl;
                        // std::cout << "obj id: " << obj->QueryExtension(25) << std::endl;
                        unsigned short extId;
                        int32_t arr[32];
                        extId = obj->GetExtensionId((char*)"ArkNpcSpawner");
                        std::cout << "ext Id: " << extId << std::endl;
                        CArkNpcSpawner* newishSpawner = (CArkNpcSpawner*)obj->QueryExtension(104);
                        std::cout << "arknpcspawner: " << newishSpawner << std::endl << std::endl;
                        CArkNpcSpawner newestSpawner = *newishSpawner;
                        CEntity newestSpawnerEntity = *newishSpawner->m_Entity;
                        newestSpawner.m_Entity = &newestSpawnerEntity;
                        std::cout << "newest spawner" << &newestSpawner << std::endl;
                        uint32_t test[8];
                        // std::cout << "Testing New Spawner:" << prey.CArkNpcSpawnerF->createNpcSpawner(archetypeLibrary.ArkHumans.Engineers.MikhailaIlyushin_healthy, &test) << std::endl;
                        
                        // std::cout << "Check how well it copied over k? " << &newestSpawner << std::endl;


                    	std::cout << prey.CArkNpcSpawnCystoidF->getEntityArchetype((CArkNpcSpawnCystoid*)newishSpawner) << std::endl;
                        
                        // std::cout << &propertiesTable << std::endl;
                        // std::cout << ((IEntity*)entity)->GetProxy(EEntityProxy::ENTITY_PROXY_RENDER) << std::endl;
                        // std::cout << ((CEntityClass*)entity->m_pClass)->GetScriptTable() << std::endl;

                        // script tables
                        
                      
                        // // // // std::cout << newishSpawner->m_Entity->m_pClass << std::endl;
                        // // // safeTable = prey.CEntity->getSafePropertiesTable((IEntity*)entity);
                        // // // std::cout << &safeTable2 << std::endl;
                        //1160740
                        // typedef bool(__thiscall* _GetSmartScripTableValue)(ArkSafeScriptTable*, char* param_1, SmartScriptTable* param_2);
                        // // CryStringT<char> returnValue;
                        // // // script
                        // // bool success;
                        
                        // prey.ArkSafeScripTablefgetArkSafeScriptFromEntity = (_GetArkSafeScriptTableFromEntity)(moduleBase + 0x14801c0);
                        
                        // ArkSafeScriptTable safeTable2;
                        // ArkSafeScriptTable safeTable3;
                        // std::cout << "dllman table2" << prey.ArkSafeScriptTablef->getArkSafeScriptFromEntity(&safeTable2, (IEntity*)entity) << std::endl;
                        // // CScriptTableName::Iterator iterator;
                        // bool doit;
                        // ScriptAnyValue TableValue;
                        // ScriptAnyValue ArchetypeValue;
                        // ScriptAnyValue NewArchetypeValue;
                        // TableValue.type = ScriptAnyType::ANY_TTABLE;
                        // ArchetypeValue.type = ScriptAnyType::ANY_TSTRING;
                        // NewArchetypeValue.type = ScriptAnyType::ANY_TSTRING;
                        // NewArchetypeValue.value.str = (char*)"ArkHumans.Scientists.MarcoSimmons";
                        // safeTable2.ptr->GetValueAny((char*)"Properties", &TableValue, false);
                        // std::cout << "Properties Table Value: " << TableValue.value.table << std::endl;
                        // if(TableValue.value.table != nullptr)
                        //     prey.ArkSafeScriptTablef->getArkSafeScriptFromScriptTable(&safeTable3, TableValue.value.table);
                        // std::cout << "Safe Table From Properties: " << &safeTable3 << std::endl;
                        // safeTable3.ptr->GetValueAny((char*)"sNpcArchetype", &ArchetypeValue, false);
                        // if (ArchetypeValue.value.str != nullptr)
                        //     std::cout << "Archetype: " << ArchetypeValue.value.str << std::endl;
                        // safeTable3.ptr->SetValueAny((char*)"sNpcArchetype", &NewArchetypeValue, false);

                        std::cout << "dllmain entity: " << (IEntity*)entity << std::endl;

                        spawnerManager->setEntityArchetype(archetypeLibrary.ArkHumans.Scientists.MarcoSimmons, (IEntity*)entity);

                        // safeTable2.ptr->BeginIteration(&iterator,true);
                        //     for (int i = 0; i <= 10; i++) {
                        //         doit = safeTable2.ptr->MoveNext(&iterator);
                        //         std::cout << iterator.sKey << std::endl;
                        //         std::cout << "type: " << (uint32_t)iterator.value.type << std::endl;
                        //         std::cout << "ptr: " << iterator.value.value.ptr << std::endl;
                        //         //     // safeTable2.ptr->MoveNext(&iterator);
                        //         //     // safeTable2.ptr->MoveNext(&iterator);
                        //         //     // safeTable2.ptr->MoveNext(&iterator);
                        //         //     // safeTable2.ptr->MoveNext(&iterator); 
                        //         //     // safeTable2.ptr->MoveNext(&iterator);
                        //         //     // safeTable2.ptr->MoveNext(&iterator);
                        //         }
                        // std::cout << getArkSafeScriptFromScriptTable(&safeTable2, ((CEntityScript*)((CEntityClass*)entity->m_pClass)->m_pEntityScript)->m_pEntityTable.ptr) << std::endl;
                        // 
                        // 
                        // std::cout <<"iterator: " << safeTable2.ptr->BeginIteration(&iterator, true) << std::endl;
                        // bool doit = true;
                        // // std::cout << safeTable2.ptr->Count() << std::endl;
                        // 
                        //
                        // std::cout << getArkSafeScriptFromScriptTable(&safeTable3,iterator.value.value.table) << std::endl;
       //                  safeTable2.ptr->EndIteration(&iterator);
       //                  if (iterator.sKey != (char*)0x0);
							// std::cout << "iterator: " << safeTable3.ptr->BeginIteration(&iterator, true) << std::endl;
       //                  safeTable3.ptr->MoveNext(&iterator);
       //                  std::cout << iterator.sKey << std::endl;
                        // std::cout << "type: " << (uint32_t)iterator.value.type << std::endl;
                        // std::cout << "ptr: " << iterator.value.value.ptr << std::endl;
                        // success = getCryStringTValue(&safeTable2, (char*)"sNpcArchetype", &returnValue);
                        // // staticPointers.gEnvPtr->pScriptSystem
                        // std::cout << success << std::endl;
                        // if(success) {
                        //     std::cout << &returnValue << std::endl;
                        // }
                        // CArkNpcSpawner* newestSpawner = *(CArkNpcSpawner**)prey.CArkNpcSpawnerF->createNpcSpawner(archetypeLibrary.ArkHumans.Engineers.MikhailaIlyushin_healthy, (void*)&arr);
                         // std::cout <<  prey.CArkNpcSpawnerF->createNpcSpawner(archetypeLibrary.ArkHumans.Engineers.MikhailaIlyushin_healthy, (void*)&arr) << std::endl;
                        // entity->m_pArchetype = staticPointers.gEnvPtr->pEntitySystem->GetEntityArchetype(archetypeLibrary.ArkHumans.Engineers.MikhailaIlyushin_healthy);
                        CArkNpcSpawner* newSpawner = prey.CEntity->getArkNpcSpawner(entity);
                        // prey.CArkNpcSpawnerF->requestSpawn(newestSpawner);
                        // ScriptAnyValue value;
                        // value.type = ScriptAnyType::ANY_ANY;
                        // CScriptTable* properties = (CScriptTable*)((CEntityScript*)((CEntityClass*)(newSpawner->m_Entity->m_pClass))->m_pEntityScript)->m_pPropertiesTable.ptr;
                        // value.value.ptr = (void*)archetypeLibrary.ArkHumans.Engineers.MikhailaIlyushin_healthy;
                        // properties->SetValueAny((char*)"sNpcArchetype", &value, false);

                        	// std::cout  << std::endl;
						// Vec3_tpl<float> viewPos = prey.getReticleViewPositionAndDir(player).first;
						// Vec3_tpl<float> viewDir = prey.getReticleViewPositionAndDir(player).second;
                        // int32_t types[3];
                        // types[1] = 1;
                        // // std::cout << ((uint32_t)((CScriptTable*)((CEntityScript*)((CEntityClass*)(newSpawner->m_Entity->m_pClass))->m_pEntityScript)->m_pPropertiesTable.ptr)->GetValueType((char*)"sNpcArchetype")) << std::endl;
                        // if (((CScriptTable*)((CEntityScript*)((CEntityClass*)(newSpawner->m_Entity->m_pClass))->m_pEntityScript)->m_pPropertiesTable.ptr)->GetValueAny((char*)"sNpcArchetype", &value, false)) {
                        //     std::cout << value.value.ptr << std::endl;
                        // }
                        // if (((CScriptTable*)((CEntityScript*)((CEntityClass*)(entity->m_pClass))->m_pEntityScript)->m_pPropertiesTable.ptr)->GetValueAny((char*)"sNpcArchetype", &value, false)) {
                        //     std::cout << value.value.ptr << std::endl;
                        // }

                        // std::cout << ((CScriptTable*)((CEntityScript*)((CEntityClass*)(newSpawner->m_Entity->m_pClass))->m_pEntityScript)->m_pEntityTable.ptr)->Count() << std::endl << std::endl;
                       
                        // CScriptTable* entities = (CScriptTable*)((CEntityScript*)((CEntityClass*)(newSpawner->m_Entity->m_pClass))->m_pEntityScript)->m_pEntityTable.ptr;
                        // CScriptTableName::Iterator* iterator = new CScriptTableName::Iterator;
                        // std::cout << "Properties Script Table: \n";
                        // iterator = properties->BeginIteration(iterator, true);
                        // // std::cout << iterator->sKey << std::endl;
                        // for (int i = 0; i <= 15; i++) {
                        //     // std::cout << iterator. << std::endl;
                        //     if(properties->MoveNext(iterator))
                        //         std::cout << iterator->sKey << std::endl;
                        // }
                        // properties->EndIteration(iterator);
                        // entities->BeginIteration(iterator, true);
                        // std::cout << "Entities Script Table: \n";
                        // for (int i = 0; i <= 15; i++) {
                        //     // std::cout << iterator. << std::endl;
                        //     if (entities->MoveNext(iterator)) {
                        //         std::cout << iterator->sKey << std::endl;
                        //         // if (strcmp(iterator->Key.value.str, "Properties")) {
                        //         //     std::cout << iterator->value.value.ptr << std::endl;
                        //         // }
                        //     }
                        // }
                        // entities->EndIteration(iterator);
						// ScriptAnyValue* PropertiesValue = new ScriptAnyValue;
      //                   ScriptAnyValue* archetypeValue = new ScriptAnyValue;
						// PropertiesValue->type = ScriptAnyType::ANY_ANY;
						// std::cout << entities->GetValueType((char*)"PropertiesInstance") << std::endl;
      //                   
						// std::cout << entities->GetValueAny((char*)"Properties", PropertiesValue, false) << std::endl;
      //                   std::cout << PropertiesValue << std::endl;
      //                   if(PropertiesValue->type == ScriptAnyType::ANY_TTABLE) {
      //                       CScriptTable* table = (CScriptTable*)PropertiesValue->value.table;
      //                       std::cout << "gotcha bitch\n";
      //                       std::cout << table << std::endl;
      //                       // table->BeginIteration(iterator, false);
      //                       //  for (int i = 0; i <= 15; i++) {
      //                       //         // std::cout << iterator. << std::endl;
      //                       //         if (table->MoveNext(iterator)) {
      //                       //             std::cout << iterator->sKey << std::endl;
      //                       //             // if (strcmp(iterator->Key.value.str, "Properties")) {
      //                       //             //     std::cout << iterator->value.value.ptr << std::endl;
      //                       //             // }
      //                       //         }
      //                       //     }
      //                       //  table->EndIteration(iterator);
      //                       std::cout << table->GetValueAny((char*)"sNpcArchetype", archetypeValue, false) << std::endl;
      //                       std::cout << (uint32_t)archetypeValue->type << std::endl;
      //                       std::cout << archetypeValue->value.ptr << std::endl;
                        // }
						// std::cout << &PropertiesValue << std::endl;
                        // if (iterator != nullptr) {
                        //     for (int i = 0; i <= 20; i++) {
                        //         if (iterator->sKey != 0x0 || iterator->nKey != 0x0) {
                        //             std::cout << iterator->sKey << std::endl;
                        //             std::cout << iterator->nKey << std::endl;
                        //             // std::cout << (uint32_t)iterator->value.type << std::endl;
                        //             // std::cout << iterator->value.value.ptr << std::endl << std::endl;;
                        //         }
                        //         if (!properties->MoveNext(iterator))
                        //             i = 21;
                        //     }
                        // }
                        // ChairloaderUtils::dumpEntity(entity, true);
                        // if (newSpawner != nullptr) {
                        //     std::cout << newSpawner << std::endl;
                        //     ChairloaderUtils::dumpEntity(newSpawner->m_Entity, false);
                        //     ChairloaderUtils::dumpGameObject(newSpawner->m_gameObject);
                        // }
                        // std::cout << "guid:" << newSpawner->m_Entity->m_guid << std::endl;
                        if (newSpawner->m_Entity != nullptr) {
                            newSpawner->m_Entity->m_vPos = pos;
                            newSpawner->m_Entity->m_worldTM.m03 = pos.x + player->m_cachedReticleDir.x * 5;
                            newSpawner->m_Entity->m_worldTM.m13 = pos.y + player->m_cachedReticleDir.y * 5;
                            newSpawner->m_Entity->m_worldTM.m23 = pos.z;
                        }
                        if (newestSpawner.m_Entity != nullptr) {
                            newestSpawner.m_Entity->m_vPos = pos;
                            newestSpawner.m_Entity->m_worldTM.m03 = pos.x + player->m_cachedReticleDir.x * -5;
                            newestSpawner.m_Entity->m_worldTM.m13 = pos.y + player->m_cachedReticleDir.y * 5;
                            newestSpawner.m_Entity->m_worldTM.m23 = pos.z;
                        } else {
                            std::cout << "Oops, null newestSpawner.m_entity" << std::endl;
                        }

                        // newSpawner->m_Entity->m_vScale = {2,2,2};
                        // newSpawner->m_Entity->m_szName.m_str = (char*)"GotchaBitch";

                        prey.CArkNpcSpawnerF->requestSpawn(newSpawner);
                        Sleep(50);
                        spawnedEntities.emplace_back((CEntity*)staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId));
                        CEntity* newEntity = (CEntity*)staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId);
                        // ArkSafeScriptTable propertiesTable;
                        // propertiesTable = prey.CEntity->getSafePropertiesTable((IEntity*)newEntity);
                        // std::cout << "ArkNpc: " << prey.CEntity->safeGetArkNpcFromEntityPtr((IEntity*)newEntity) << std::endl;
                        // std::cout << prey.ArkNpcF->PushDisableAudible(prey.CEntity->safeGetArkNpcFromEntityPtr((IEntity*)newEntity)) << std::endl;
                        ArkNpc::ArkNpc* npc = prey.CEntity->safeGetArkNpcFromEntityPtr((IEntity*)newEntity);
                        ArkNpc::ArkNpcProperties* properties = prey.ArkNpcF->GetProperties(npc);

                        // prey.CArkNpcSpawnerF->requestSpawn(&newestSpawner);
                        // properties->m_bCanRagdoll = true;
                        // prey.ArkNpcF->PushIndefiniteRagdoll(npc);
                        // prey.ArkNpcF->BecomeInactive(npc);
                        
                        // ChairloaderUtils::dumpEntity(newEntity, true);
                        // prey.ArkFactionManagerF->setEntityFaction(CGamePtr->m_pArkFactionManager.get(), newEntity->m_nID, 3);

                        // newEntity->m_pArchetype = staticPointers.gEnvPtr->pEntitySystem->GetEntityArchetype(archetypeLibrary.ArkHumans.Engineers.MikhailaIlyushin_healthy);
                        // CArkNpcSpawner* newerSpawner = prey.CEntity->getArkNpcSpawner(newEntity);
                        // if (newerSpawner != nullptr)
                        //     prey.CArkNpcSpawnerF->requestSpawn(newerSpawner);
                        // else
                        //     std::cout << "Null Spawner From Entity" << std::endl;
                        
                        // if (newEntity != nullptr) {
                        //     std::cout << "spawned entity:" << staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId) << std::endl;
                        //     std::cout << "id:" << newEntity->m_nID << std::endl;
                        //     std::cout << "guid:" << newEntity->m_guid << std::endl;
                        //     std::cout << "class:" << newEntity->m_pClass << std::endl;
                        //     std::cout << "archetype:" << newEntity->m_pArchetype << std::endl;
                        //     std::cout << "name:" << newEntity->m_szName.m_str << std::endl;
                        //     std::cout << "flags:" << newEntity->m_flags << std::endl;
                        //     std::cout << "flags_extended:" << newEntity->m_flagsExtended << std::endl;
                        //     std::cout << "initialmask:" << newEntity->m_initialSceneMask << std::endl << std::endl;;
                        // } else {
                        //     std::cout << "spawned nullptr" << std::endl;
                        // }
                        // std::cout << "spawned" << std::endl;
                        
                        break;  
                    }
                    
                    }
                    
                }
                
            }
        }
        //1713490239377285936 lobby
        //12889009724983807463 neuromod division
        if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
            // std::cout << "load location label: " << std::dec <<prey.ArkLocationManagerF->GetCurrentLocation(CGamePtr->m_pArkGame->m_pArkLocationManager.get()) << std::endl;
            // Interesting cvars:
            // g_EnableDevMenuOptions
            //i_debug
            // kc_enable
            // r_EnableDebugLayer
            CVar* var = prey.CXConsoleF->getCvar(CGamePtr->m_pConsole, (char*)"g_EnableDevMenuOptions");
            std::cout << "enableDevMenuOptions: 0x" << var << std::endl;
            var = prey.CXConsoleF->getCvar(CGamePtr->m_pConsole, (char*)"i_debug");
            std::cout << "debug: " << var << std::endl;
            std::cout << "kc_enable: " << prey.CXConsoleF->getCvar(CGamePtr->m_pConsole, (char*)"kc_enable") << std::endl;
            std::cout << "debuglayer: " << prey.CXConsoleF->getCvar(CGamePtr->m_pConsole, (char*)"r_EnableDebugLayer") << std::endl;
            std::cout << &staticPointers.gEnvPtr->szDebugStatus << std::endl;
            // CGamePtr->m_pConsole->AddCommand((char*)"debug_toggle", (char*)"ui_toggle_debug", 0, (char*)"toggles debug menu I hope");
            // CGamePtr->m_pConsole->ExecuteString((char*)"debug_toggle", false, false);
            std::cout << CGamePtr->m_pCVars->i_debuggun_1 << std::endl;
            std::cout  << "g_EnablePersistantStatsDebugScreen: "<< CGamePtr->m_pCVars->g_EnablePersistantStatsDebugScreen << std::endl;
            std::cout  << "g_EnableDevMenuOptions: "<< CGamePtr->m_pCVars->g_EnableDevMenuOptions << std::endl;
            std::cout << "pl_debug_energyConsumption: " << CGamePtr->m_pCVars->pl_debug_energyConsumption << std::endl;
            std::cout << "g_devDemo: " << CGamePtr->m_pCVars->g_devDemo << std::endl;
            CGamePtr->m_pCVars->g_devDemo = 1;
            std::cout << CGamePtr->m_pCVars->pl_movement.speedScale << std::endl;
            // CGamePtr->m_pCVars->pl_movement.speedScale = 2.4;
            std::cout << CGamePtr->m_pCVars->pl_movement.sprint_SpeedScale << std::endl;
            // CGamePtr->m_pCVars->pl_movement.sprint_SpeedScale = 3.6;
            CGamePtr->m_pCVars->pl_traumaDebug = 1;

            // std::cout << staticPointers.gEnvPtr->pGame->m_pFramework->m_pCheats << std::endl;
            // staticPointers.gEnvPtr->pEntitySystem->DebugDraw();
            // IActionMapManager* mapmanager = staticPointers.gEnvPtr->pGame->m_pFramework->GetIActionMapManager();
            // mapmanager->RemoveAllFilters();
            // prey.ArkLocationManagerF->SetLoaded(CGamePtr->m_pArkGame->m_pArkLocationManager.get(), 12889009724983807463, true);
     //        if (freeCam) {
     //            lockFreeCam = !lockFreeCam;
     //            if(lockFreeCam)
					// CGamePtr->m_pConsole->ExecuteString((char*)"FreeCamLockCamera", false, true);
     //            else
					// CGamePtr->m_pConsole->ExecuteString((char*)"FreeCamUnlockCamera", false, true);
     //        }
            // CGodMode* godMode = prey.ArkPlayerF->getGodModeInstance();
            // std::cout << godMode << std::endl;
            // godMode->m_godMode = 1;
            // for(auto it = spawnedEntities.begin(); it != spawnedEntities.end(); ++it) {
            //     CEntity* entity = *it._Ptr;
            //     // std::cout << entity->m_szName.m_str << std::endl;
            //     Vec3_tpl<float> pos;
            //     ((IEntity*)entity)->GetWorldPos(&pos);
            //     Matrix34_tpl<float> matrix = {1,0,0,pos.x,0,1,0,pos.y,0,0,1,pos.z};
            //     // matrix.m23 += 20;
            //     // entity->SetWorldTM(&matrix,0);
            //     float scaleT = 0.25f;
            //     Vec3_tpl<float> scale = { scaleT,scaleT,scaleT };
            //     ((IEntity*)entity)->SetScale(&scale, 0);
            //     
            // }
            // prey.ragdollize(player, 1.0f);
            // CVar* var = prey.getCvar(CGamePtr->m_pConsole, (char*)"g_EnableDevMenuOptions");
            // std::cout << var << std::endl;
            // // var->m_param = false;
            // prey.executeString(CGamePtr->m_pConsole, (char*)"spawnActor ArkNightmare", false, true);
         //    staticPointers.gEnvPtr->pEntitySystem->m_pClassRegistry->m_mapClassName;
         //    IEntityClass* newClass = (IEntityClass*)staticPointers.gEnvPtr->pEntitySystem->m_pClassRegistry->Find((char*)"ArkNpcSpawner");
         //    std::cout << staticPointers.gEnvPtr->pEntitySystem->CreateEntityArchetype(newClass, (char*)"ChairloaderTest1", 4206942069) << std::endl;
         //    Quat_tpl<float> rot{ 0,0,0,1 };
         //    Vec3_tpl<float> pos{ 0,0,350 };
         //    uint32_t id = 69420420;
         //    SEntitySpawnParams params;
        	// ChairloaderUtils::CreateEntitySpawnParameters((char*)"ChairLoader0", &pos, &rot, &params);
         //    std::cout << staticPointers.gEnvPtr->pEntitySystem->CreateEntity(&staticPointers.gEnvPtr->pEntitySystem->GetEntityArchetype(4206942069)->m_ObjectVars, &params, &id) << std::endl;
            //
            // for (std::map<CryStringT<char>, CEntityClass*>::const_iterator it = staticPointers.gEnvPtr->pEntitySystem->m_pClassRegistry->m_mapClassName.begin(); it != staticPointers.gEnvPtr->pEntitySystem->m_pClassRegistry->m_mapClassName.end(); ++it) {
            //     std::cout << it->first.m_str << ": " << it->second->m_sName.m_str << std::endl;
            // }
            
            // bConsole = !bConsole;
            // std::cout << CGamePtr->m_pConsole << std::endl;
            //
            // prey.showConsole(CGamePtr->m_pConsole, bConsole, 300);
            // std::cout << CGamePtr->m_pConsole->m_bConsoleActive << std::endl;
            // Sleep(100);
            
            // nightmareSpawner = CGamePtr->m_pArkNightmareSpawnManager.get();
            // prey.enableNightmareSpawner(nightmareSpawner);
            // prey.spawnNewNightmare(nightmareSpawner);
            // thirdPerson = !thirdPerson;
            // prey.showThirdPerson(player, thirdPerson);
        }
        if (GetAsyncKeyState(VK_NUMPAD9) & 1) {
            for(auto it = CGamePtr->m_pArkNightmareSpawnManager.get()->m_currentLevelNightmareSpawners.begin(); it <= CGamePtr->m_pArkNightmareSpawnManager.get()->m_currentLevelNightmareSpawners.end(); ++it) {
                std::cout << *it << std::endl;
            }
            CEntity* entity = (CEntity*)staticPointers.gEnvPtr->pEntitySystem->GetEntity(425);
            CArkNpcSpawner* newSpawner = prey.CEntity->getArkNpcSpawner(entity);
            std::cout << newSpawner << std::endl;
            Vec3_tpl<float> pos;
            prey.ArkPlayerF->getPlayerWorldEyePos(player, &pos);
            // Vec3_tpl<float> viewPos = prey.getReticleViewPositionAndDir(player).first;
            // Vec3_tpl<float> viewDir = prey.getReticleViewPositionAndDir(player).second;
            newSpawner->m_Entity->m_vPos = pos;
            newSpawner->m_Entity->m_worldTM.m03 = pos.x + player->m_cachedReticleDir.x * 5;
            newSpawner->m_Entity->m_worldTM.m13 = pos.y + player->m_cachedReticleDir.y * 5;
            newSpawner->m_Entity->m_worldTM.m23 = pos.z;
            float scale = 2;
            Vec3_tpl<float> newScale{ scale,scale,scale};
            // newSpawner->m_Entity->m_szName.m_str = (char*)"GotchaBitch";
            prey.CArkNpcSpawnerF->requestSpawn(newSpawner);
            Sleep(50);
            spawnedEntities.emplace_back((CEntity*)staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId));
            ((IEntity*)spawnedEntities.back())->SetScale(&newScale,0);
            // prey.CArkNpcSpawnerF->requestSpawn(newSpawner);
            //
            // Sleep(50);
            // spawnedEntities.emplace_back((CEntity*)staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId));
            // ((IEntity*)spawnedEntities.back())->SetScale(&newScale, 0);
            prey.ArkFactionManagerF->setEntityFaction(CGamePtr->m_pArkFactionManager.get(), spawnedEntities.back()->m_nID, 3);
            ArkNpc::ArkNpc* npc = prey.CEntity->safeGetArkNpcFromEntityPtr((IEntity*)spawnedEntities.back());
            ArkNpc::ArkNpcProperties* properties = prey.ArkNpcF->GetProperties(npc);
            properties->m_bCanRagdoll = true;
            prey.ArkNpcF->PushIndefiniteRagdoll(npc);
            // for (int i = 0; i < EntitySystem->m_EntityArray.size(); ++i) {
            //     // CEntity* entity = *(CEntity**)it._Ptr;
            //     // std::cout << entity << std::endl;
            //     if (EntitySystem->m_EntityArray[i] != nullptr) {
            //         CEntity* entity = EntitySystem->m_EntityArray[i];
            //         // std::cout << entity << std::endl;
            //         if (entity->m_guid != 0x0) {
            //             std::string entityName = entity->m_szName.m_str;
            //             // std::cout << entityName << ": " << entity << std::endl;
            //             // std::cout << entity->m_pArchetype->m_name.m_str <<": " << entity << std::endl;
            //         // if (&entity->m_szName != 0x0) {
            //             std::cout << entity->m_szName.m_str << std::endl;
            //             if (entityName == "yes") {
            //                 std::cout << "gotcha bitch:" << entity << std::endl;
            //                 break;
            //             }
            //             // }
            //         }
            //         // if (i >= 1000)
            //         //     break;
            //     }
            //     // if (*(uintptr_t*)entity != 0x0) {
            //         //if ((entity+0x38) != 0x0) {
            //             // std::cout << entity << ": " << entity->m_szName.m_str << std::endl;
            //         // }
            //     // }
            // }
        }
        if (GetAsyncKeyState(VK_NUMPAD3) & 1) {
            CEntityArchetype* archetype = staticPointers.gEnvPtr->pEntitySystem->GetEntityArchetype(archetypeLibrary.ArkNpcs.ArkNightmare);
            Vec3_tpl<float> pos;
            prey.ArkPlayerF->getPlayerWorldEyePos(player, &pos);
            Vec3_tpl<float> localEyePos;
            player->GetLocalEyePos(&localEyePos);
            // std::cout << localEyePos.x << std::endl;
            // std::cout << localEyePos.y << std::endl;
            // std::cout << localEyePos.z << std::endl;
            Quat_tpl<float> rot;
            rot.x = 0; rot.x = 0; rot.z = 0; rot.w = 1;
            SEntitySpawnParams* params = new SEntitySpawnParams;

            // ChairloaderUtils::CreateEntitySpawnParameters((char*)"NewEntity0", &pos, &rot, params);
            params->vScale.x = 1;
            params->vScale.y = 1;
            params->vScale.z = 1;
            // params->entityNode = archetype->m_ObjectVars;
            // params->pArchetype = archetype;
            // params->pClass = (CEntityClass*)archetype->m_pClass;
            uint32_t id = prey.CEntitySystemF->generateEntityId(staticPointers.gEnvPtr->pEntitySystem, true);
            params->id = id;
            params->vPosition.x = pos.x + player->m_cachedReticleDir.x * 2;
            params->vPosition.y = pos.y + player->m_cachedReticleDir.y * 2;
            params->vPosition.z = pos.z - localEyePos.z;
            params->qRotation.x = 0;
            params->qRotation.y = 0;
            params->qRotation.z = 0;
            params->qRotation.w = 1;
            params->sLayerName = (char*)"";
            params->pClass = (CEntityClass*)(0x0);
            params->pArchetype = (CEntityArchetype*)(0x0);
            params->guid = 0;
            params->prevGuid = 0;
            params->prevId = 0;
            params->bCreatedThroughPool = 0;
            params->bIgnoreLock = 0;
            params->bStaticEntityId = 0;
            params->nFlags = 0;
            params->nFlagsExtended = 0;
            params->sName = (char*)"newEntity0";
            params->entityNode.ptr = (IXmlNode*)0x0;
            params->shadowCasterType = '\0';
            params->pUserData = (void*)0x0;
            params->sceneMask = '\0';
            // XmlNodeRef node = archetype->m_ObjectVars;
            
            // SEntityLoadParams* loadParams = new SEntityLoadParams;
            // loadParams->spawnParams = *params;
            // loadParams->bCallInit = false;
            // loadParams->clonedLayerId = 0;
            // staticPointers.gEnvPtr->pEntitySystem->CreateEntity(&node, params, &id);
            // player->GetViewRotation(rot);
            
            // std::cout << archetype->GetObjectVars() << std::endl;
            IEntity* entity;
        	// std::cout << prey.ArkNpcSpawnManagerF->internalCreateNpc((IEntityArchetype*)staticPointers.gEnvPtr->pEntitySystem->GetEntityArchetype(archetypeLibrary.ArkNpcs.ArkNightmare) , &pos, &rot);
            entity = staticPointers.gEnvPtr->pEntitySystem->SpawnEntityFromArchetype((IEntityArchetype*)staticPointers.gEnvPtr->pEntitySystem->GetEntityArchetype(archetypeLibrary.ArkPhysicsProps.Tech.Reployer), params, true);
            std::cout << entity->GetUpdatePolicy() << std::endl;
            // EEntityUpdatePolicy policy = EEntityUpdatePolicy::ENTITY_UPDATE_IN_RANGE;
            // entity->SetUpdatePolicy(policy);
            // entity->EnablePhysics(true)
            Vec3_tpl<float> newScale;
            float scale = 20;
            newScale.x = scale;
        	newScale.y = scale;
            newScale.z = scale;
            entity->SetScale(&newScale, 0);
            
            // std::cout << staticPointers.gEnvPtr->pEntitySystem->FindEntityByName((char*)"newEntity0")<< std::endl;;
            // std::cout << prey.ArkNpcSpawnManagerF->createNpc((IEntityArchetype*)staticPointers.gEnvPtr->pEntitySystem->GetEntityArchetype(archetypeLibrary.ArkNpcs.ArkNightmare), &pos, &rot,1);
            // staticPointers.gEnvPtr->pEntitySystem->SpawnEntityFromArchetype((IEntityArchetype*)archetype, params, false);
            // CEntity* entity = new CEntity;
            // ((IEntity*)entity)->Init()
            // CArkObjectiveData * data = staticPointers.gEnvPtr->pGame->GetData();
            // for (auto it = data->m_descriptions.begin(); it <= data->m_descriptions.end(); ++it) {
            //     // std::string name;
            //     // std::string text;
            //     if (it._Ptr != nullptr) {
            //         std::cout << it._Ptr << std::endl;
            //         std::cout << it._Ptr->m_id << std::endl;
            //         // name = it._Ptr->m_displayName.m_str;
            //         // text = it._Ptr->m_text.m_str;
            //         // std::cout << name << std::endl;
            //         // std::cout << text << std::endl;
            //
            //     }
            // }
            // for (auto it = CGamePtr->m_pFramework->m_pGameObjectSystem->m_nameToID.begin(); it != CGamePtr->m_pFramework->m_pGameObjectSystem->m_nameToID.end(); ++it) {
            //     std::cout << it->first.m_str << ": " << it->second << std::endl;
            // }
            // prey.initCXConsole(CGamePtr->m_pConsole, staticPointers.gEnvPtr->pSystem);
	        //  devMode = !devMode;
         //     
	        //  //    // CGamePtr->m_pConsole->m_pSystem->m_bInDevMode = devMode;
	        //  //    // CGamePtr->m_pConsole->m_pSystem->m_bWasInDevMode = devMode;
	        //  prey.CSystemF->setDevMode(staticPointers.gEnvPtr->pSystem, true);
         //     CGamePtr->m_pConsole->EnableActivationKey(true);
         //
        	// // std::cout << staticPointers.gEnvPtr->pSystem->m_bInDevMode << std::endl;
         //     // if (devMode) {
         //         CGamePtr->m_pConsole->ShowConsole(devMode, 300);
         //         // prey.CXConsoleF->executeString(CGamePtr->m_pConsole, (char*)"ConsoleShow", false, true);
         //         // Sleep(100);
         //         if (devMode) {
         //             CGamePtr->m_pConsole->PrintLine((char*)"Welcome to funland sonic");
         //         }
            // std::cout << staticPointers.gEnvPtr->pSystem->m_pTextModeConsole << std::endl;
            // prey.beginDraw((CWindowsConsole*)staticPointers.gEnvPtr->pSystem->m_pTextModeConsole);
	        // //    std::cout << staticPointers.gEnvPtr->pSystem << std::endl;
	        // std::cout << prey.GetTextModeConsole(staticPointers.gEnvPtr->pSystem) << std::endl;
            // prey.beginDraw(prey.GetTextModeConsole(staticPointers.gEnvPtr->pSystem));
            // prey.enableActivationKey(CGamePtr->m_pConsole, true);
            //
            // char* blank = (char*)"";
            // char* cmd = (char*)"ai_dumpCheckpoints";
            // if (bConsole) {
            //     prey.displayHelp(CGamePtr->m_pConsole, cmd, blank);
            // }
            // for (std::map<CryStringT<char>,CConsoleCommand>::const_iterator it = CGamePtr->m_pConsole->m_mapCommands.begin(); it != CGamePtr->m_pConsole->m_mapCommands.end(); ++it) {
            //     std::cout << it->first.m_str << ": " << it->second.m_sName.m_str << std::endl;
            //     std::cout << it->second.m_func << std::endl;
            //     std::cout << it->second.m_sHelp.m_str << std::endl << std::endl;
            // }
            // //
            // for (std::map<CryStringT<char>, CryStringT<char>>::const_iterator it = CGamePtr->m_pConsole->m_mapBinds.begin(); it != CGamePtr->m_pConsole->m_mapBinds.end(); ++it) {
            //     std::cout << it->first.m_str << ": " << it->second.m_str << std::endl;
            // }
            
             // for (std::map<const char*, ICVar*>::const_iterator it = CGamePtr->m_pConsole->m_mapVariables.begin(); it != CGamePtr->m_pConsole->m_mapVariables.end(); ++it) {
             //     std::cout << it->first << std::endl;
             //     }

        }
        // if (GetAsyncKeyState(VK_F3) & 1) {
        //     player = prey.getPlayerInstance();
        //    //  std::cout << "Current Player Instance Pointer: " << std::hex << prey.getPlayerInstance << std::endl;
        //    //ArkPlayerWeaponComponent* wepCompPtr = (ArkPlayerWeaponComponent*)(player + 0x14B8);
        //    CArkWeapon* currentWep = prey.getEquippedWeapon(&player->m_weaponComponent);
        //    std::cout <<"Current Ammo: "<< std::dec << currentWep->m_numAmmoLoaded << "\n";
        //    std::cout << "IArkPlayer: " << std::dec << player->IArkPlayer << "\n";
        //    std::cout << "IEntity*: " << std::hex << currentWep->m_disruptionVFX.m_controller->m_pOwnerEntity->ptr << "\n";
        //    std::cout << "PlayerClassName: " << std::hex << prey.getEntityClassName(player).m_str << "\n";
        //   // std::cout << prey.getClipSize(currentWep);
        //    //prey.setWeaponAmmoCount(currentWep, 42);
        //    prey.fireWeapon(prey.getEquippedWeapon(&player->m_weaponComponent));
        // }
        if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
            player = prey.ArkPlayerF->getInstance();
            std::cout << "Current Player Instance Pointer: " << std::hex << (uintptr_t)player << std::endl;
            std::cout << "Current movementfsm: " << std::hex << (uintptr_t)&player->m_movementFSM - (uintptr_t)player << std::endl;
            std::cout << "Current playerComponent: " << std::hex << (uintptr_t)&player->m_playerComponent - (uintptr_t)player << std::endl;
            std::cout << "Current statsComponent " << std::hex << (uintptr_t)&player->m_statsComponent - (uintptr_t)player << std::endl;
            std::cout << "Current suitChipsetComponent: " << std::hex << (uintptr_t)&player->m_suitChipsetComponent - (uintptr_t)player << std::endl;
            std::cout << "Current scopeChipsetComponent: " << std::hex << (uintptr_t)&player->m_scopeChipsetComponent - (uintptr_t)player << std::endl;
            std::cout << "Current input: " << std::hex << (uintptr_t)&player->m_input - (uintptr_t)player << std::endl;
            std::cout << "Current examinationMode: " << std::hex << (uintptr_t)&player->m_examinationMode - (uintptr_t)player << std::endl;
            std::cout << "Current Interaction: " << std::hex << (uintptr_t)&player->m_interaction - (uintptr_t)player << std::endl;
            std::cout << "Current flashlight: " << std::hex << (uintptr_t)&player->m_flashlight - (uintptr_t)player << std::endl;
            std::cout << "Current audio: " << std::hex << (uintptr_t)&player->m_audio - (uintptr_t)player << std::endl;
            std::cout << "Current camera: " << std::hex << (uintptr_t)&player->m_camera - (uintptr_t)player << std::endl;
            std::cout << "Current helmet: " << std::hex << (uintptr_t)&player->m_helmet - (uintptr_t)player << std::endl;
            std::cout << "Current weaponComponent: " << std::hex << (uintptr_t)&player->m_weaponComponent - (uintptr_t)player << std::endl;
            std::cout << "Current animationManager: " << std::hex << (uintptr_t)&player->m_materialAnimationManager - (uintptr_t)player << std::endl;
            Vec3_tpl<float> pos;
            player->SetHealth(500);
            // std::cout << pos.x << std::endl;
            // std::cout << pos.y << std::endl;
            // std::cout << pos.z << std::endl;

            // ArkPlayerFlashlight* flashlight = &player->m_flashlight;
            // std::cout << flashlight->IsPowered(flashlight) << std::endl;
            
        }
        
        if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
            
            Vec3_tpl<float> pos;
            prey.ArkPlayerF->getPlayerWorldEyePos(player, &pos);
            pos.x += player->m_cachedReticleDir.x * 5;
            pos.y += player->m_cachedReticleDir.y * 5;
            //12889009725056221348
            IEntity* entity = nullptr;
            for (uint64_t i = 0; i <= 7; i++) {
                entity = spawnerManager->spawnNpcFromArchetype(760 + i, (char*)"miky", ChairloaderUtils::EntityType::mimic);
                if (entity != nullptr) {
                    std::cout << entity << std::endl;
                	entity->SetPos(&pos, 0, false, false);
                    prey.ArkFactionManagerF->setEntityFaction(CGamePtr->m_pArkFactionManager.get(), ((CEntity*)entity)->m_nID, 3);
                }
                Sleep(60);
            }
            // if (entity != nullptr)
            //     ChairloaderUtils::dumpEntity((CEntity*)entity, true);
            // std::vector<IEntity*> entities = spawnerManager->spawnNpcFromArchetype(archetypeLibrary.ArkNpcs.Mimics.Mimic, (char*)"miky", ChairloaderUtils::EntityType::operators, &pos, 50);
            // Sleep(200);
            // for (auto i = entities.begin(); i<= entities.end(); ++i) {
            //     std::cout << ((CEntity*)i._Ptr)->m_nID << std::endl;
            //     prey.ArkFactionManagerF->setEntityFaction(CGamePtr->m_pArkFactionManager.get(), ((CEntity*)i._Ptr)->m_nID, 3);
            //     // Sleep(1);
            // }
            // IEntity* entity = spawnerManager->spawnNpcFromArchetype(archetypeLibrary.ArkRobots.Operators.Named.Kaspar, (char*)"miky", ChairloaderUtils::EntityType::operators);
            // entity->SetPos(&pos, )
            // ArkNpc::ArkNpc* npc = prey.CEntity->safeGetArkNpcFromEntityPtr(entity);
            // prey.ArkNpcF->PushDisableOperatorLevitatorsEffect(npc);
            // for (auto it = CGamePtr->m_pArkFactionManager->m_nameToIndexMap.begin(); it != CGamePtr->m_pArkFactionManager->m_nameToIndexMap.end(); ++it) {
            //     std::cout << it->first.m_str << ": " << it->second << std::endl;
            // }
            // Vec3_tpl<float> pos;
            // prey.ArkPlayerF->getPlayerWorldEyePos(player, &pos);
            // Quat_tpl<float> rot;
            // // player->GetViewRotation(rot);
            // rot.x = 0; rot.x = 0; rot.z = 0; rot.w = 0;
            // ChairloaderUtils::CreateEntityBasic(staticPointers.gEnvPtr->pEntitySystem, (char*)"NewEntity0", &pos, &rot, archetypeLibrary.ArkNpcs.Mimics.Mimic, &prey);
        }
        if (GetAsyncKeyState(VK_NUMPAD0) & 1) {
            prey.CSystemF->setDevMode(staticPointers.gEnvPtr->pSystem, true);
            freeCam = !freeCam;
            CXConsoleFloatRef* var =  (CXConsoleFloatRef*)prey.CXConsoleF->getCvar(CGamePtr->m_pConsole, (char*)"g_detachedCameraMoveSpeed");
            var->Set(1.0f);
            
            if(freeCam)
                CGamePtr->m_pConsole->ExecuteString((char*)"FreeCamEnable", false, true);
            else
                CGamePtr->m_pConsole->ExecuteString((char*)"FreeCamDisable", false, true);
            // for(auto it = CGamePtr->m_pConsole->m_mapVariables.begin(); it != CGamePtr->m_pConsole->m_mapVariables.end();++it) {
            //     std::cout << it->first << ": " << it->second << std::endl;
            // }
                // std::cout << "Current Player Health: " << std::dec << prey.getPlayerHealth(player) << std::endl;
                // prey.setPlayerHealth(player, prey.getPlayerHealth(player) + 100.0f);
                // std::cout << "New Player Health: " << std::dec << prey.getPlayerHealth(player) << std::endl;
            // uint32_t newId = prey.generateEntityId(EntitySystem, true);
            // std::cout << "new ID:" << newId << std::endl;
            // for (std::map<CryStringT<char>, SActorClassDesc>::const_iterator it = CGamePtr->m_pFramework->m_pActorSystem->m_classes.begin(); it != CGamePtr->m_pFramework->m_pActorSystem->m_classes.end(); ++it) {
            //     std::cout << it->second.pEntityClass->m_sName.m_str << std::endl;
            //     }
        }
        

        if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
            Vec3_tpl<float> pos;
            prey.ArkPlayerF->getPlayerWorldEyePos(player, &pos);
            pos.x += player->m_cachedReticleDir.x * 5;
            pos.y += player->m_cachedReticleDir.y * 5;
            //12889009725056221348
            IEntity* entity = nullptr;
            entity = spawnerManager->spawnNpcFromArchetype(760, (char*)"miky", ChairloaderUtils::EntityType::mimic);
            if (entity != nullptr) {
                std::cout << entity << std::endl;
                entity->SetPos(&pos, 0, false, false);
            }
            Sleep(2000);
            SEntityLoadParams *params = new SEntityLoadParams;
            // SEntitySpawnParams* spawnParams = new SEntitySpawnParams;
            CEntity* centity = (CEntity*)entity;
            // params->spawnParams.bCreatedThroughPool = false;
            // params->spawnParams.bIgnoreLock = false;
            params->spawnParams.id = centity->m_nID;
            params->spawnParams.vPosition.x = centity->m_vPos.x;
            params->spawnParams.vPosition.y = centity->m_vPos.y;
            params->spawnParams.vPosition.z = centity->m_vPos.z;
            params->spawnParams.qRotation.x = centity->m_qRotation.x;
            params->spawnParams.qRotation.y = centity->m_qRotation.y;
            params->spawnParams.qRotation.z = centity->m_qRotation.z;
            params->spawnParams.qRotation.w = centity->m_qRotation.w;
            params->spawnParams.sLayerName = (char*)"";
            params->spawnParams.pClass = (CEntityClass*)(0x0);
            params->spawnParams.pArchetype = staticPointers.gEnvPtr->pEntitySystem->GetEntityArchetype(762);
            params->spawnParams.guid = centity->m_guid;
            params->spawnParams.prevGuid = 0;
            params->spawnParams.prevId = 0;
            params->spawnParams.bCreatedThroughPool = 0;
            params->spawnParams.bIgnoreLock = 0;
            params->spawnParams.bStaticEntityId = 0;
            params->spawnParams.nFlags = centity->m_flags;
            params->spawnParams.nFlagsExtended = centity->m_flagsExtended;
            params->spawnParams.sName = centity->m_szName.m_str;
            params->spawnParams.entityNode = staticPointers.gEnvPtr->pEntitySystem->GetEntityArchetype(762)->m_ObjectVars;
            params->spawnParams.shadowCasterType = '\0';
            params->spawnParams.pUserData = (void*)0x0;
            params->spawnParams.sceneMask = centity->m_initialSceneMask;
            params->pReuseEntity = centity;
            params->clonedLayerId = 1;
            params->bCallInit = true;
            std::cout << prey.CEntity->reloadEntity(centity, params) << std::endl;

            // CryStringT<char> library;
            // library.m_str = (char*)"NewNpcs";
            // std::string filename;
            // filename = "libs/entityarchetypes/arknpcs.xml";
            //
            // XmlNodeRef* ref = staticPointers.gEnvPtr->pSystem->LoadXmlFromFile((char*)filename.c_str() , false, true);
            // std::cout << ref << std::endl;
            // staticPointers.gEnvPtr->pEntitySystem->m_pEntityArchetypeManager()
            // std::string filename;
            // filename = "Libs/EntityArchetypes/ArkNpcs.xml";
            // // filename = "C:\\Users\\theli\\Downloads\\crispy-system-master\\Libs\\EntityArchetypes\\ArkNpcs.xml";
            // // pugi::xml_document doc;
            // // pugi::xml_parse_result result = doc.load_file(filename.data());
            // // std::cout << result.description() << std::endl;
            // // // if (_stricmp(result.description(), "No error") == true) {
            // //     std::cout << doc.first_child().name() << std::endl;
            // // // doc.child
            // // // };
            //
            // CXmlUtils* utils = (CXmlUtils*)staticPointers.gEnvPtr->pSystem->m_pXMLUtils;
            // XmlParser* parser = (XmlParser*)utils->CreateXmlParser();
            // // std::cout << parser << std::endl;
            // XmlNodeRef* ref;
            // bool fileSystem = false;
            // ref = parser->ParseFile((char*)filename.data(), false, fileSystem);
            // std::cout << ref->ptr << std::endl;
            // // std::cout << ref << std::endl;
            // // std::cout << ref->ptr << std::endl;
            // ref = staticPointers.gEnvPtr->pSystem->LoadXmlFromFile((char*)filename.data(), false, fileSystem);
            // std::cout << ref->ptr << std::endl;
            // // std::cout << ref->ptr << std::endl;
            // // utils->EnableBinaryXmlLoading(true);
            // ref = utils->LoadBinaryXmlFile((char*)filename.data(), false);
            // std::cout << ref->ptr << std::endl;
            // ref = utils->LoadXmlFromFile((char*)filename.data(),false,false, fileSystem);
            // std::cout << ref->ptr << std::endl;
            // CXmlNode* topNode = ref.ptr;
            // // tag = ;
            // printf("%s\n", topNode->m_tag, '\n');
            // // CXmlNode* childNode = topNode->m_pChilds[1];
            // printf("%s\n", topNode->m_content, '\n');
            // topNode->getChild(0);
            // std::cout << topNode->findChild((char*)"ArkNullwave");
            // std::cout << ref.ptr << std::endl;
            // CBinaryXmlNode* node = (CBinaryXmlNode*)ref.ptr;
            // std::cout << node->m_pData << std::endl;
            // std::cout << node->m_pData->pNodes << std::endl;
            // std::cout 
            // if (ref.ptr != nullptr) {
            //     std::cout << ref.ptr << std::endl;
            //     CBinaryXmlNode* topNode = (CBinaryXmlNode*)ref.ptr;
            //     std::cout << topNode << std::endl;
            //     std::cout << topNode->m_pData->pStringData << std::endl;
            // }
        }
        // continuous read/write
        if (bGloo) {
            // // gloo ammo
            // *(int*)mem::FindDMAAddy(moduleBase + 0x02C1FEB8, { 0x30,0x8,0x2fC }) = 30;
            // // gloo reserve
            // *(int*)mem::FindDMAAddy(moduleBase + 0x024AE0B0, { 0x168,0x8,0x60,0x54 }) = 420;
        }
	}
    // cleanup & eject
    if (f) {
        fclose(f);
    }
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

