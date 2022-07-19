#pragma once
#include "pch.h"
#include <Prey/CrySystem/System.h>
#include <Prey/ArkBasicTypes.h>
#include <Prey/ArkEntityArchetypeLibrary.h>
#include "preyDllObjects.h"
#include "OverlayLog.h"
#include "EntityManager.h"
#include "PlayerManager.h"
#include "ChairloaderConfigManager.h"
#include "GUIUtils.h"
#include "PerfOverlay.h"
#include "Profiler.h"
#include "DevConsoleDialog.h"
// #include <stack>

class ChairloaderGui {
public:
    ChairloaderGui();

    bool IsDevConsoleVisible() { return control.showDevConsole; }
    void SetDevConsoleVisible(bool state) { control.showDevConsole = state; }

    void logItem(std::string msg, const std::string modName, ChairloaderGUILog::logLevel level = ChairloaderGUILog::logLevel::normal, bool displayToScreen = true);
    void logItem(ChairloaderGUILog::logMessage message, bool displayToScreen = true);
    void draw(bool* bShow);
    void update();
    bool addDrawFunction(std::string modName, std::function<void()> drawFunction);
    bool isDrawFunctionLoaded(const std::string modName);
    bool unloadDrawFunction(const std::string modName);

    void dockingTest();
private:
    struct chairloaderGuiControl {
        bool showPlayerManager = false,
            showEntityList = false,
            showEntitySpawner = false,
            showLogHistory = false,
            showDemoWindow = false,
            showStyleManager = false,
            showProfilerDialog = false,
            showDevConsole = false,
			showConfigMenu = false,
            freeCam = false,
            devMode = false,
            hideAll = false;
    };
    const std::string modName = "ChairloaderGUI";
    //TODO: rethink the control variable
    
    bool g_PresentHooked;
    bool g_ShowMenu;
    BOOL g_bInitialised;
    // static ChairloaderGui* gui;

    chairloaderGuiControl control;
    ChairloaderGUILog log;
    ChairloaderGUIPlayerManager playerManager; 
    ChairloaderGUIEntityManager entityManager;
    PerfOverlay perfOverlay;
    ProfilerDialog profilerDialog;
    DevConsoleDialog devConsoleDialog;
    ChairloaderConfigManager configMenu;

    // std::vector<std::string> modsWithDrawFuncs;
    std::vector<std::tuple<std::function<void()>, std::string>> drawFuncs;
    std::mutex drawHandleMutex;

    // void hook() {
    //     // begin gui hooking
    //     GetPresent();
    //     if (!g_PresentHooked) {
    //         retrieveValues();
    //     }
    //     // detour time
    //     detourDirectXPresent();
    //     while (!g_bInitialised) {
    //         Sleep(100);
    //     }
    //     printValues();
    // }

private:
    // LRESULT CALLBACK hWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    //
    // HRESULT GetDeviceAndCtxFromSwapchain(IDXGISwapChain* pSwapChain, ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext);
    //
    // HRESULT __fastcall Present(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);
    //
    // void detourDirectXPresent();
    //
    // void retrieveValues();
    //
    // void printValues();
    //
    // void GetPresent();

};

extern ChairloaderGui *gui;
