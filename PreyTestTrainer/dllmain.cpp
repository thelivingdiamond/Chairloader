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
    std::vector<CEntity*> spawnedEntities;
    while(true) {
        // key input
        if (GetAsyncKeyState(VK_END) & 1) {
            break;
        }
        if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
        	for (int i = 0; i < EntitySystem->m_EntityArray.size(); ++i) {
                // CEntity* entity = *(CEntity**)it._Ptr;
                // std::cout << entity << std::endl;
                if (EntitySystem->m_EntityArray[i] != nullptr) {
                    CEntity* entity = EntitySystem->m_EntityArray[i];
                    // std::cout << entity << std::endl;
                    if (entity->m_guid != 0x0) {
                    	std::string entityName = entity->m_szName.m_str;
                    	//std::cout << entityName << ": " << entity << std::endl;
                        // std::cout << entity->m_pArchetype->m_name.m_str <<": " << entity << std::endl;
                    // if (&entity->m_szName != 0x0) {
                        // std::cout << &entity->m_szName.m_str << std::endl;
                    if (entityName == "Igwe") {
                        Vec3_tpl<float> pos;
                        prey.ArkPlayerF->getPlayerWorldEyePos(player, &pos);
                        // entity->m_vPos = pos;
                        CArkNpcSpawner* newSpawner = prey.CEntity->getArkNpcSpawner(entity);
                        // std::cout  << std::endl;
						// Vec3_tpl<float> viewPos = prey.getReticleViewPositionAndDir(player).first;
						// Vec3_tpl<float> viewDir = prey.getReticleViewPositionAndDir(player).second;
                        std::cout << "spawner entity: " << newSpawner << std::endl;
                        std::cout <<"id:" << newSpawner->m_Entity->m_nID << std::endl;
                        std::cout <<"guid:" << newSpawner->m_Entity->m_guid << std::endl;
                        std::cout <<"class:" << newSpawner->m_Entity->m_pClass << std::endl;
                        std::cout <<"archetype:" << newSpawner->m_Entity->m_pArchetype << std::endl;
                        std::cout <<"name:" << newSpawner->m_Entity->m_szName.m_str<< std::endl;
                        std::cout <<"flags:" << newSpawner->m_Entity->m_flags << std::endl;
                        std::cout <<"flags_extended:" << newSpawner->m_Entity->m_flagsExtended << std::endl;
                        std::cout <<"initialmask:" << newSpawner->m_Entity->m_initialSceneMask << std::endl << std::endl;;
                        newSpawner->m_Entity->m_vPos = pos;
                        newSpawner->m_Entity->m_worldTM.m03 = pos.x +player->m_cachedReticleDir.x*5;
                        newSpawner->m_Entity->m_worldTM.m13 = pos.y + player->m_cachedReticleDir.y*5;
                        newSpawner->m_Entity->m_worldTM.m23 = pos.z;
                        // newSpawner->m_Entity->m_vScale = {2,2,2};
                        // newSpawner->m_Entity->m_szName.m_str = (char*)"GotchaBitch";
                        prey.CArkNpcSpawnerF->requestSpawn(newSpawner);
                        Sleep(50);
                        spawnedEntities.emplace_back((CEntity*)staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId));
                        CEntity* newEntity = (CEntity*)staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId);
                        if (newEntity != nullptr) {
                            std::cout << "spawned entity:" << staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId) << std::endl;
                            std::cout << "id:" << newEntity->m_nID << std::endl;
                            std::cout << "guid:" << newEntity->m_guid << std::endl;
                            std::cout << "class:" << newEntity->m_pClass << std::endl;
                            std::cout << "archetype:" << newEntity->m_pArchetype << std::endl;
                            std::cout << "name:" << newEntity->m_szName.m_str << std::endl;
                            std::cout << "flags:" << newEntity->m_flags << std::endl;
                            std::cout << "flags_extended:" << newEntity->m_flagsExtended << std::endl;
                            std::cout << "initialmask:" << newEntity->m_initialSceneMask << std::endl << std::endl;;
                        } else {
                            std::cout << "spawned nullptr" << std::endl;
                        }
                        // std::cout << "spawned" << std::endl;
                        
                        break;  
                    }
                    
                    }
                    
                }
                
            }
        }
        if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
            CGodMode* godMode = prey.ArkPlayerF->getGodModeInstance();
            std::cout << godMode << std::endl;
            godMode->m_godMode = 1;
            for(auto it = spawnedEntities.begin(); it != spawnedEntities.end(); ++it) {
                CEntity* entity = *it._Ptr;
                // std::cout << entity->m_szName.m_str << std::endl;
                Vec3_tpl<float> pos;
                ((IEntity*)entity)->GetWorldPos(&pos);
                Matrix34_tpl<float> matrix = {1,0,0,pos.x,0,1,0,pos.y,0,0,1,pos.z};
                // matrix.m23 += 20;
                // entity->SetWorldTM(&matrix,0);
                float scaleT = 0.25f;
                Vec3_tpl<float> scale = { scaleT,scaleT,scaleT };
                ((IEntity*)entity)->SetScale(&scale, 0);
                
            }
            // prey.ragdollize(player, 1.0f);
            // CVar* var = prey.getCvar(CGamePtr->m_pConsole, (char*)"g_EnableDevMenuOptions");
            // std::cout << var << std::endl;
            // // var->m_param = false;
            // prey.executeString(CGamePtr->m_pConsole, (char*)"spawnActor ArkNightmare", false, true);
            staticPointers.gEnvPtr->pEntitySystem->m_pClassRegistry->m_mapClassName;
            for (std::map<CryStringT<char>, CEntityClass*>::const_iterator it = staticPointers.gEnvPtr->pEntitySystem->m_pClassRegistry->m_mapClassName.begin(); it != staticPointers.gEnvPtr->pEntitySystem->m_pClassRegistry->m_mapClassName.end(); ++it) {
                std::cout << it->first.m_str << ": " << it->second->m_sName.m_str << std::endl;
            }
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
            // newSpawner->m_Entity->m_vScale = {2,2,2};
            // newSpawner->m_Entity->m_szName.m_str = (char*)"GotchaBitch";
            prey.CArkNpcSpawnerF->requestSpawn(newSpawner);
            Sleep(50);
            spawnedEntities.emplace_back((CEntity*)staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId));

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
            // prey.initCXConsole(CGamePtr->m_pConsole, staticPointers.gEnvPtr->pSystem);
	         devMode = !devMode;
             
	         //    // CGamePtr->m_pConsole->m_pSystem->m_bInDevMode = devMode;
	         //    // CGamePtr->m_pConsole->m_pSystem->m_bWasInDevMode = devMode;
	         prey.CSystemF->setDevMode(staticPointers.gEnvPtr->pSystem, true);
             CGamePtr->m_pConsole->EnableActivationKey(true);

        	// std::cout << staticPointers.gEnvPtr->pSystem->m_bInDevMode << std::endl;
             // if (devMode) {
                 CGamePtr->m_pConsole->ShowConsole(devMode, 300);
                 // prey.CXConsoleF->executeString(CGamePtr->m_pConsole, (char*)"ConsoleShow", false, true);
                 // Sleep(100);
                 if (devMode) {
                     CGamePtr->m_pConsole->PrintLine((char*)"Welcome to funland sonic");
                 }
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
            Quat_tpl<float> rot;
            // player->GetViewRotation(rot);
            rot.x = 0; rot.x = 0; rot.z = 0; rot.w = 0;
            ChairloaderUtils::CreateEntity(staticPointers.gEnvPtr->pEntitySystem, (char*)"NewEntity0", &pos, &rot, archetypeLibrary.ArkNpcs.Mimics.Mimic, &prey);
        }
        if (GetAsyncKeyState(VK_NUMPAD0) & 1) {
            freeCam = !freeCam;
            std::cout << prey.CXConsoleF->getCvar(CGamePtr->m_pConsole, (char*)"g_detachedCameraMoveSpeed") << std::endl;
            if(freeCam)
                CGamePtr->m_pConsole->ExecuteString((char*)"FreeCamEnable", false, true);
            else
                CGamePtr->m_pConsole->ExecuteString((char*)"FreeCamDisable", false, true);
                //
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
            std::string filename;
            // filename = "C:\\Users\\theli\\Downloads\\crispy-system-master\\Libs\\EntityArchetypes\\ArkNpcs.xml";
            filename = "Libs/EntityArchetypes/ArkNpcs.xml";
            CXmlUtils* utils = (CXmlUtils*)staticPointers.gEnvPtr->pSystem->m_pXMLUtils;
            // XmlNodeRef* ref = staticPointers.gEnvPtr->pSystem->LoadXmlFromFile((char*)filename.data(), false, true);
            // utils->EnableBinaryXmlLoading(true);
            // XmlNodeRef* ref = utils->LoadBinaryXmlFile((char*)filename.data(), false);
            XmlNodeRef ref = utils->LoadXmlFromFile((char*)filename.data(),false,false,true);
            std::cout << ref.ptr << std::endl;
            CXmlNode* topNode = ref.ptr;
            // tag = ;
            printf("%s\n", topNode->m_tag, '\n');
            // CXmlNode* childNode = topNode->m_pChilds[1];
            printf("%s\n", topNode->m_content, '\n');
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

