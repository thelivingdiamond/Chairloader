#pragma once
#include <ChairLoader/IChairloaderGui.h>
#include <ChairLoader/IChairloaderConfigManager.h>
#include <Prey/CrySystem/System.h>
#include <Prey/ArkEntityArchetypeLibrary.h>
#include <GUIUtils.h>
#include "OverlayLog.h"
#include "Profiler.h"

class ChairloaderGui : public IChairloaderGui {
public:
    ChairloaderGui();

    bool IsEnabled() override;

    void logItem(std::string msg, const std::string modName, logLevel level = logLevel::normal, bool displayToScreen = true) override;
    void logItem(logMessage message, bool displayToScreen = true) override;

    void draw(bool* bShow);
    void update();

    void overlayLog(std::string modName, const char *format, ...) override;

    void overlaywarning(std::string modName, const char *format, ...) override;

    void overlayError(std::string modName, const char *format, ...) override;

private:
    struct chairloaderGuiControl {
        bool
            showEntitySpawner = false,
            showLogHistory = false,
            showDemoWindow = false,
            showStyleManager = false,
            showProfilerDialog = false,
			showConfigMenu = false,
            freeCam = false,
            devMode = false,
            hideAll = false;
    };
    const std::string modName = "ChairloaderGUI";
    //TODO: rethink the control variable

    bool persistentLogOverlay = true;

    bool g_PresentHooked;
    bool g_ShowMenu;
    bool g_bInitialised;

    chairloaderGuiControl control;
    ChairloaderGUILog log;
    ProfilerDialog profilerDialog;

    //TODO: remove mutex bc single thread
    std::mutex drawHandleMutex;

};
