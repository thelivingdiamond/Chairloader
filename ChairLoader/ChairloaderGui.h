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


    //TODO: switch to module internal draw booleans
    chairloaderGuiControl control;
    ChairloaderGUILog log;
    ChairloaderGUIPlayerManager playerManager; 
    ChairloaderGUIEntityManager entityManager;
    PerfOverlay perfOverlay;
    ProfilerDialog profilerDialog;
    DevConsoleDialog devConsoleDialog;

    //TODO: remove mutex bc single thread
    std::mutex drawHandleMutex;

};

extern ChairloaderGui *gui;
