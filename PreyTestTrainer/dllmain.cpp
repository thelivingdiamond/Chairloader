// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <string>

#include "mem.h"
#include "preyDllFunctions.h"
#include "proc.h"
#include "preyDllObjects.h"
#include "preyDllFunctions.h"
#include <thread>

DWORD WINAPI HackThread(HMODULE hModule) {
	// Create Console
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "Welcome to funland sonic\n";
    // std::cout << "threadId: " << std
    
    // Get Module base
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"PreyDll.dll");

    preyDllFunctions prey(moduleBase);
    staticObjectPointers staticPointers(moduleBase);

    CEntitySystem* CEntitySystem = staticPointers.gEnvPtr->pEntitySystem;
    CGame* CGamePtr = staticPointers.gEnvPtr->pGame;
    ArkNpcSpawnManager* spawner = CGamePtr->m_pArkNpcSpawnManager.get();
    ArkPlayer* player = prey.getPlayerInstance();
    bool bGloo = 0;
    // bypass thread check
    mem::Nop((BYTE*)(moduleBase + 0x020e2c5), 20);


    std::cout << "ChairLoader Initialized...\n";
    std::cout << "\nModule Base: 0x" << std::hex << moduleBase << std::dec << "\n\n";
    // hack loop
    bool thirdPerson = false;
    while(true) {
        // key input
        if (GetAsyncKeyState(VK_END) & 1) {
            break;
        }
        
        if (GetAsyncKeyState(VK_F2) & 1) {
            thirdPerson = !thirdPerson;
            prey.showThirdPerson(player, thirdPerson);
        }
        if (GetAsyncKeyState(VK_F3) & 1) {
           //  std::cout << "Current Player Instance Pointer: " << std::hex << prey.getPlayerInstance << std::endl;
           //ArkPlayerWeaponComponent* wepCompPtr = (ArkPlayerWeaponComponent*)(player + 0x14B8);
           CArkWeapon* currentWep = prey.getEquippedWeapon(&player->m_weaponComponent);
           std::cout <<"Current Ammo: "<< std::dec << currentWep->m_numAmmoLoaded << "\n";
           std::cout << "IArkPlayer: " << std::dec << player->IArkPlayer << "\n";
           std::cout << "IEntity*: " << std::hex << currentWep->m_disruptionVFX.m_controller->m_pOwnerEntity->ptr << "\n";
           std::cout << "PlayerClassName: " << std::hex << prey.getEntityClassName(player).m_str << "\n";
          // std::cout << prey.getClipSize(currentWep);
           //prey.setWeaponAmmoCount(currentWep, 42);
        }
        if (GetAsyncKeyState(VK_F4) & 1) {
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
        }
        if (GetAsyncKeyState(VK_F9) & 1) {
            // bGloo = !bGloo;
        }
        if (GetAsyncKeyState(VK_F8) & 1) {
            std::cout  << "Current Player Instance Pointer: " << std::hex << prey.getPlayerInstance << std::endl;
            std::cout << "Current Player Health: " << std::dec << prey.getPlayerHealth(player) << std::endl;

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
        if (GetAsyncKeyState(VK_F10) & 1) {
                //
                // std::cout << "Current Player Health: " << std::dec << prey.getPlayerHealth(player) << std::endl;
                // prey.setPlayerHealth(player, prey.getPlayerHealth(player) + 100.0f);
                // std::cout << "New Player Health: " << std::dec << prey.getPlayerHealth(player) << std::endl;
            uint32_t newId = prey.generateEntityId(CEntitySystem, true);
            std::cout << "new ID:" << newId << std::endl;
        }
        

        if (GetAsyncKeyState(VK_F11) & 1) {
            //CGame* cgameptr = staticPointers.g_pGame;
            Vec3_tpl<float> playerPos;
            prey.getPlayerWorldEyePos(player, &playerPos);
            // std::cout << "x: " << playerPos.x << "\ny: " << playerPos.y << "\nz: " << playerPos.z << std::endl;
            Quat_tpl<float> playerFacing;
            prey.getViewRotation(player, &playerFacing);
            uint32_t newId = prey.generateEntityId(CEntitySystem, true);
            std::cout << "new ID:" << newId << std::endl;
            CryStringT<char> entityName;
            entityName.m_str = const_cast <char*>("ArkNpcs.Phantoms.BasePhantom");
            CEntityArchetype* newArchetype = prey.findEntityArchetype(CEntitySystem, entityName.m_str);
            if (newArchetype != 0)
                std::cout << std::hex << newArchetype->m_name.m_str;
            // std::cout << prey.getArchetype(CEntitySystem, (uint64_t)0x1C76A2E2840) << std::endl;
            uint32_t spawnState = 2;
            IEntity * entity = prey.createNpc(newArchetype, playerPos, playerFacing,newId,&spawnState);


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
                break;
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

