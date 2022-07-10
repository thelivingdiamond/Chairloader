#pragma once
#include "pch.h"
#include <Prey/ArkBasicTypes.h>
#include <Prey/ArkEntityArchetypeLibrary.h>
#include "preyDllObjects.h"
class ChairloaderGUILog {
public:
    // Basic Logging Structs
    enum class logLevel {
        normal = 0,
        warning = 1,
        error = 2,
    };
    struct logMessage {
        std::string message;
        std::string modName;
        time_t time;
        logLevel level;

        bool empty() {
            return message.empty();
        }
    };
    ChairloaderGUILog();
    ~ChairloaderGUILog();
    // show persistent transparent log overlay
    void drawDisplay();
    // Draw the log history window to display all previous log messages
    void drawHistory(bool* bShow);
    // Log Item with std::string, modName, Level, and screenWriting
    void logItem(std::string msg, const std::string modNameIn, logLevel level = logLevel::normal, bool displayToScreen = true);
    // Log Item with a premade logMessage
    void logItem(logMessage message, bool displayToScreen = true);
private:
    const std::string modName = "ChairloaderGUI.Log";
    std::vector<logMessage> archiveLogQueue;
    std::vector<logMessage> displayLogQueue;
    time_t MessageTimeoutTime = 10;
};

extern ChairloaderGUILog* GUILog;