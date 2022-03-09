// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "mem.h"
#include "proc.h"
#include "preyDllObjects.h"
#include "preyDllFunctions.h"
// typedef uintptr_t(_fastcall* _GetPlayerInstance)();
// typedef float (__thiscall * _playerGetHealth)(ArkPlayer*);
// typedef void(__thiscall * _playerSetHealth)(ArkPlayer*, float);
// _GetPlayerInstance get_player_instance;
// _playerGetHealth get_player_health;
// _playerSetHealth set_player_health;
DWORD WINAPI HackThread(HMODULE hModule) {
	// Create Console
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "Welcome to funland sonic\n";
    
    
    // Get Module base
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"PreyDll.dll");

    preyDllFunctions prey(moduleBase);
    preyDllFunctions::_GetPlayerInstance get_player_instance;
    //get_player_instance = (preyDllFunctions::_GetPlayerInstance)(moduleBase + 0x154fa60);
   // get_player_instance = prey.getFunctionAddr<preyDllFunctions::_GetPlayerInstance>(moduleBase, 0x154fa60);
    // get_player_health = (_playerGetHealth)(moduleBase + 0x154fa40);
    // set_player_health = (_playerSetHealth)(moduleBase + 0x15575c0);
    //uintptr_t playerptr = get_player_instance();
    ArkPlayer* player = prey.getPlayerInstance();
    //ArkPlayer playerObj = *prey.getPlayerInstance();
    //ArkPlayer player = *(ArkPlayer*)get_player_instance();
    bool bGloo = 0;

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
            std::cout << "Current Player Health: " << std::dec << prey.getPlayerHealth(player) << std::endl;
            prey.setPlayerHealth(player, prey.getPlayerHealth(player) + 100.0f);
            std::cout << "New Player Health: " << std::dec << prey.getPlayerHealth(player) << std::endl;
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

