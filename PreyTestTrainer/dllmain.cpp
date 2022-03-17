// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <string>

#include "mem.h"
#include "preyFunctions.h"
#include "proc.h"
#include "preyDllObjects.h"
#include "preyFunctions.h"
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
            // player = prey.getPlayerInstance();
            // prey.onFlyModePressed(player);
            
            // player->m_camera.m_mode = Mode::hacking;
            // uint32_t number = 1;
            // CArkNpcSpawner* CNpcSpawner = prey.getArkNpcSpawner(number);
            // std::cout << CNpcSpawner << std::endl;
            // std::cout << staticPointers.gEnvPtr->pEntitySystem << std::endl;
            // CArkNpcSpawner creator;
            // prey.cArkNpcSpawnerConstructor(&creator);
            // ArkNpcSpawnRequester requester;
            // uint64_t result = prey.requestNpcSpawn(spawner, &requester, &creator);
            // std::cout << result << std::endl;
            // std::cout << creator.m_lastSpawnedEntityId << std::endl;
            // std::cout << EntitySystem->m_EntityArray[0]->m_guid;
            // // int i = 0;
            bool found = false;
            // CryStringT<char> searchName;
            // searchName.m_str = (char*)"ArkMimic";
            // SEntitySpawnParams spawnParams;
            // spawnParams.id = prey.generateEntityId(staticPointers.gEnvPtr->pEntitySystem, true);
            // spawnParams.prevId = 0;
            // spawnParams.guid = 69420420420;
            // spawnParams.prevGuid = 0;
            // spawnParams.pClass = staticPointers.gEnvPtr->pEntitySystem->m_pClassRegistry->m_mapClassName.find(searchName)->second;
            // spawnParams.pArchetype = staticPointers.gEnvPtr->pEntitySystem->m_pEntityArchetypeManager->m_nameToArchetypeMap.find("ArkNpcs.Mimics.Mimic")->second;
            // spawnParams.pClass = 0;










            
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
                        std::cout << newSpawner << std::endl;
						// Vec3_tpl<float> viewPos = prey.getReticleViewPositionAndDir(player).first;
						// Vec3_tpl<float> viewDir = prey.getReticleViewPositionAndDir(player).second;
                        newSpawner->m_Entity->m_vPos = pos;
                        newSpawner->m_Entity->m_worldTM.m03 = pos.x +player->m_cachedReticleDir.x*5;
                        newSpawner->m_Entity->m_worldTM.m13 = pos.y + player->m_cachedReticleDir.y*5;
                        newSpawner->m_Entity->m_worldTM.m23 = pos.z;
                        // newSpawner->m_Entity->m_vScale = {2,2,2};
                        // newSpawner->m_Entity->m_szName.m_str = (char*)"GotchaBitch";
                        prey.CArkNpcSpawnerF->requestSpawn(newSpawner);
                        Sleep(50);
                        spawnedEntities.emplace_back((CEntity*)staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId));
                        std::cout << staticPointers.gEnvPtr->pEntitySystem->GetEntity(newSpawner->m_lastSpawnedEntityId) << std::endl;

                        // std::cout << "spawned" << std::endl;
                        
                        break;  
                    }
                    // }
                    }
                    // if (i >= 1000)
                    //     break;
                }
                // if (*(uintptr_t*)entity != 0x0) {
                    //if ((entity+0x38) != 0x0) {
                        // std::cout << entity << ": " << entity->m_szName.m_str << std::endl;
                    // }
                // }
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
                entity->GetWorldPos(&pos);
                Matrix34_tpl<float> matrix = {1,0,0,pos.x,0,1,0,pos.y,0,0,1,pos.z};
                // matrix.m23 += 20;
                // entity->SetWorldTM(&matrix,0);
                float scaleT = 0.25f;
                Vec3_tpl<float> scale = { scaleT,scaleT,scaleT };
                entity->SetScale(&scale, 0);
                
            }
            // prey.ragdollize(player, 1.0f);
            // CVar* var = prey.getCvar(CGamePtr->m_pConsole, (char*)"g_EnableDevMenuOptions");
            // std::cout << var << std::endl;
            // // var->m_param = false;
            // prey.executeString(CGamePtr->m_pConsole, (char*)"spawnActor ArkNightmare", false, true);
            // staticPointers.gEnvPtr->pEntitySystem->m_pClassRegistry->m_mapClassName;
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
            player = prey.ArkPlayerF->getInstance();
            std::cout  << "Current Player Instance Pointer: " << std::hex << prey.ArkPlayerF->getInstance()<< std::endl;
            std::cout << "Current Player Health: " << std::dec << player->GetHealth() << std::endl;

            if (player->m_movementFSM.m_flyMode == EArkFlyMode::off) {
                std::cout << "Fly mode: OFF\n";
            }
            else if (player->m_movementFSM.m_flyMode == EArkFlyMode::off) {
                std::cout << "Fly mode: ON\n";
            }
            else if (player->m_movementFSM.m_flyMode == EArkFlyMode::onNoCollision) {
                std::cout << "Fly mode: No Clip\n";
            } else {
                std::cout << "Fly mode: " << (int)player->m_movementFSM.m_flyMode << std::endl;
            }
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
            // player = prey.getPlayerInstance();
            //
            // //CGame* cgameptr = staticPointers.g_pGame;
            // Vec3_tpl<float> playerPos;
            // prey.getPlayerWorldEyePos(player, &playerPos);
            // // std::cout << "x: " << playerPos.x << "\ny: " << playerPos.y << "\nz: " << playerPos.z << std::endl;
            // Quat_tpl<float> playerFacing;
            // // prey.getViewRotation(player, &playerFacing);
            // playerFacing = { 0.0f,0.0f,0.0f,0.0f };
            // uint32_t newId = prey.generateEntityId(EntitySystem, true);
            // std::cout << "new ID:" << newId << std::endl;
            // CryStringT<char> entityName;
            // entityName.m_str = const_cast <char*>("ArkHumans.Scientists.MarcoSimmons");
            // CEntityArchetype* newArchetype = prey.findEntityArchetype(EntitySystem, entityName.m_str);
            // if (newArchetype != 0)
            //     std::cout << std::hex << newArchetype->m_name.m_str << std::endl;
            //
            // // std::cout << prey.getArchetype(CEntitySystem, (uint64_t)0x1C76A2E2840) << std::endl;
            // uint32_t spawnState = 2;
            //
            // boost::variant<ArkNpc::ArkNpcSpawnedState_Alert, ArkNpc::ArkNpcSpawnedState_Broken, ArkNpc::ArkNpcSpawnedState_Dead, ArkNpc::ArkNpcSpawnedState_Dormant> state;
            // ArkNpc::ArkNpcSpawnedState_Alert alert = 3;
            // state = alert;
            // CEntity * entity = prey.createNpc(newArchetype, playerPos, playerFacing,nextId,&state);
            // nextId+= 10;
            // std::cout << entity << std::endl;
            // std::cout << prey.hasAi(entity) << std::endl;
            // prey.ArkNpcSpawnManagerUpdate(spawner,1.0f);
            
            try {
                // std::cout << "gEnv: 0x" << std::hex << staticPointers.gEnvPtr << std::endl;
                // std::cout << "pEntitySystem: 0x" << std::hex << staticPointers.gEnvPtr->pEntitySystem << std::endl;
                // std::cout << "Timers Paused: " << CEntitySystem->m_bTimersPause << std::endl;
                //CEntitySystem* manual = (CEntitySystem*)0x17E11F64DE0;
                //std::cout << "Timers Paused: " << manual->m_bTimersPause << std::endl;
                // std::cout << std::hex << 0x17E11F64DE0 << std::endl;
                
                
                // IEntityArchetype* Iarchetype = prey.getArchetype(CEntitySystem, 717);
                // CEntityArchetype* archetype = Iarchetype->ptr;
                // std::cout << archetype->m_id << std::endl;
                // CryStringT<char> libraryName;
                // libraryName.m_str = const_cast <char*>("ArkNpcs");
                
                // std::cout << "paused: " << CGamePtr->m_bPausedForSystemMenu << std::endl;
                // CEntityArchetypeManager* archetypeManager = CEntitySystem->m_pEntityArchetypeManager;
              
                
                
                // std::cout <<"ArkNpcSpawnManager Offset: 0x" << std::hex << (uintptr_t)&CGamePtr->m_pArkNpcSpawnManager - (uintptr_t)CGamePtr << std::endl;
                // for (std::map<CryStringT<char>, CryStringT<char>>::const_iterator it = CGamePtr->m_variantOptions.begin();it != CGamePtr->m_variantOptions.end();++it) {
                //     std::cout << it->first.m_str << ": " << it->second.m_str << std::endl;
                // }
                // CEntityArchetypeManager* archetypeManager = CEntitySystem->m_pEntityArchetypeManager;
                // for (std::map<const char*, CEntityArchetype*>::const_iterator it = archetypeManager->m_nameToArchetypeMap.begin();it != archetypeManager->m_nameToArchetypeMap.end();++it) {
                //     std::cout << it->first << ": " << it->second << std::endl;
                // }
               //  std::vector<CryStringT<char>> names = prey.getArchetypeNames(CEntitySystem, libraryName);
               //  if(names.size() > 0) {
               //     for (CryStringT<char> a : names) {
               //         std::cout << a.m_str << std::endl;
               //     }
               // } else {
               //     std::cout << "no return " << std::endl;
               // }
                // }



                // std::cout << std::hex << moduleBase + 0x2c09010 << std::endl;
                // std::cout << cgameptr << std::endl;
                // std::cout << &cgameptr << std::endl;
                // void* spawnManager = (&cgameptr +(uintptr_t)0x058);
                // std::cout << spawnManager << std::endl;
                // std::cout <<"gEnv: 0x" << std::hex << staticPointers.gEnvPtr << std::endl;
                // // std::cout << "pEntitySystem: 0x" << std::hex << (uintptr_t)&staticPointers.gEnvPtr->pEntitySystem - (uintptr_t)staticPointers.gEnvPtr << std::endl;
             //    std::cout << "pEntitySystem: 0x" << std::hex << *(CEntitySystem**)staticPointers.gEnvPtr->pEntitySystem << std::endl;
             //    CEntitySystem* CEntitySystemPtr = *(CEntitySystem**)staticPointers.gEnvPtr->pEntitySystem->ptr;
             //    std::cout << "m_tempActiveEntities: 0x" << std::hex << (uintptr_t)&CEntitySystemPtr->m_tempActiveEntities - (uintptr_t)staticPointers.gEnvPtr->pEntitySystem->ptr << std::endl;
             //    std::cout << "pArchetypeManager: 0x" << std::hex << (uintptr_t)&CEntitySystemPtr->m_pEntityArchetypeManager - (uintptr_t)staticPointers.gEnvPtr->pEntitySystem->ptr << std::endl;
             //    // std::cout << "Timers Paused: " << CEntitySystemPtr->m_bTimersPause << std::endl;
             //    std::cout << std::hex << *(uintptr_t**)&CEntitySystemPtr->m_bTimersPause;
                //CEntityArchetypeManager* CArchetypeManager = CEntitySystemPtr->m_pEntityArchetypeManager;

                // ;
                //
                // prey.update(CEntitySystemPtr);
                //std::cout << std::hex << CEntitySystemPtr << std::endl;
                // CEntityArchetype * yes = CArchetypeManager->m_idToArchetypeMap.find(717);
                // 
                // std::cout << archetype->m_name.m_str << std::endl;


            // std::cout << "GEnvOffset : 0x" << (uintptr_t)staticPointers.gEnvPtr - moduleBase << std::endl;
            // std::cout << (uintptr_t)&staticPointers.gEnv - (uintptr_t)&staticPointers.gEnv.pEntitySystem<<std::endl;
            // CEntitySystem* entitySystem = (CEntitySystem*)staticPointers.gEnv.pEntitySystem->ptr;
            // CEntityArchetypeManager* archetypeManager = entitySystem->m_pEntityArchetypeManager;
            // std::cout << prey.getArchetype(archetypeManager, 717);
            } catch (...) {
                std::cout << "errored I guess";
                //break;
            }
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

