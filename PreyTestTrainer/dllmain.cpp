// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "mem.h"
#include "proc.h"
#include "preyDll.h"

typedef uintptr_t(_fastcall* _GetPlayerInstance)();
typedef float (__thiscall * _playerGetHealth)(ArkPlayer*);
typedef void(__thiscall * _playerSetHealth)(ArkPlayer*, float);
_GetPlayerInstance get_player_instance;
_playerGetHealth get_player_health;
_playerSetHealth set_player_health;
DWORD WINAPI HackThread(HMODULE hModule) {
	// Create Console
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "Welcome to funland sonic\n";
    

    // Get Module base
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"PreyDll.dll");
    
    get_player_instance = (_GetPlayerInstance)(moduleBase + 0x154fa60);
    get_player_health = (_playerGetHealth)(moduleBase + 0x154fa40);
    set_player_health = (_playerSetHealth)(moduleBase + 0x15575c0);
    //uintptr_t playerptr = get_player_instance();
    ArkPlayer* player = (ArkPlayer*)get_player_instance();
    //ArkPlayer player = *(ArkPlayer*)get_player_instance();
    bool bGloo = 0;

    std::cout << "ChairLoader Initialized...\n";

    // hack loop
    while(true) {
        // key input
	    if(GetAsyncKeyState(VK_END) & 1) {
            break;
	    }
        if (GetAsyncKeyState(VK_F4) & 1) {
            player->m_movementFSM.m_flyMode = EArkFlyMode::off;
            
           
        }
        if (GetAsyncKeyState(VK_F9) & 1) {
            // bGloo = !bGloo;
        }
        if (GetAsyncKeyState(VK_F8) & 1) {
            
            std::cout  << "Current Player Instance Pointer: " << std::hex << get_player_instance() << std::endl;
            std::cout << "Current Player Health: " << std::dec << get_player_health(player) << std::endl;
            if (player->m_movementFSM.m_flyMode == EArkFlyMode::off) {
                std::cout << "Fly mode: OFF";
            }
            else if (player->m_movementFSM.m_flyMode == EArkFlyMode::off) {
                std::cout << "Fly mode: ON";
            }
            else if (player->m_movementFSM.m_flyMode == EArkFlyMode::onNoCollision) {
                std::cout << "Fly mode: No Clip";
            } else {
                std::cout << "Fly mode: " << (int)player->m_movementFSM.m_flyMode << std::endl;
            }
        }
        if (GetAsyncKeyState(VK_F10) & 1) {
            std::cout << "Current Player Health: " << std::dec << get_player_health(player) << std::endl;
            set_player_health(player, get_player_health(player) + 100.0f);
            std::cout << "New Player Health: " << std::dec << get_player_health(player) << std::endl;
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

