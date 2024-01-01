#pragma once
#include <Chairloader/IChairloaderGui.h>
#include <Chairloader/IChairloaderConfigManager.h>
#include <Prey/CrySystem/System.h>
#include <Prey/ArkEntityArchetypeLibrary.h>
#include <GUIUtils.h>
#include "OverlayLog.h"
#include "Profiler.h"

class ChairloaderGui : public IChairloaderGui {
public:
    ChairloaderGui();

    bool IsEnabled() override { return m_bIsEnabled; }
    void SetEnabled(bool state) override { m_bIsEnabled = state; }

//    void logItem(std::string msg, const std::string modName, logLevel level = logLevel::normal, bool displayToScreen = true) override;
//    void logItem(logMessage message, bool displayToScreen = true) override;

    void draw();
    void update();

//    void overlayLog(std::string modName, const char *format, ...) override;
//
//    void overlaywarning(std::string modName, const char *format, ...) override;
//
//    void overlayError(std::string modName, const char *format, ...) override;

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

    bool m_bIsEnabled = true;
    bool persistentLogOverlay = true;

    chairloaderGuiControl control;
    ProfilerDialog profilerDialog;
    OverlayLogManager overlayLogManager;

    void ShowDockSpace();
};
