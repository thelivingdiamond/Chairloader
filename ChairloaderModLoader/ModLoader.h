//
// Created by theli on 8/1/2022.
//
#pragma once

#include <zip.h>
#include "ImGui/imgui.h"
#include "ImGui/imgui_stdlib.h"
#include "ImGuiFileDialog/ImGuiFileDialog.h"
#include <pugixml.hpp>
#include <filesystem>
#include <fstream>

#include <boost/format.hpp>


namespace fs = std::filesystem;
class ModLoader {
public:
    enum class severityLevel{
        trace,
        debug,
        info,
        warning,
        error,
        fatal
    };
    class LogEntry{
    public:
        LogEntry(std::string &messageIn, severityLevel levelIn): message(messageIn), level(levelIn){
            tm newtime;
            time_t now = time(nullptr);
            localtime_s(&newtime,&now);
            timeStamp = boost::str((boost::format("%i:%i:%i") % newtime.tm_hour % newtime.tm_min % newtime.tm_sec));
        }
        std::string message;
        severityLevel level;
        std::string timeStamp;
    };
    struct Mod{
        std::string modName;
        std::string version;
        int loadOrder = -1;
        pugi::xml_node infoFile;
        pugi::xml_node configFile;
        bool XMLEnable,
             DLLEnable,
             deployed = false,
             installed = false;
        bool operator<( Mod& b ) const {
            return this->loadOrder < b.loadOrder;
        }
        bool operator ==(std::string rhs){
            return this->modName == rhs;
        }
    };

    ModLoader();
    ~ModLoader();
    void Draw();
    void Update();
private:
    //Draw Functions
    void DrawModList();
    void DrawDLLSettings();
    void DrawXMLSettings();
    void DrawDeploySettings();
    void DrawLog();


    fs::path getConfigPath(std::string &modName);
    fs::path getDefaultConfigPath(std::string &modName);

    fs::path selectedFile;
    bool TreeNodeWalkDirectory(fs::path path, std::string modName);
    std::string fileName;
    fs::path modToLoadPath;
    fs::path PreyPath = R"(C:\Program Files (x86)\Steam\steamapps\common\Prey)";
    pugi::xml_document ChairloaderConfigFile;
    pugi::xml_node ModListNode;
    std::vector<Mod> ModList;
    void loadModInfoFiles();
    bool LoadModInfoFile(fs::path directory, Mod *mod);
    void FindMod(Mod* modEntry);
    bool checkSafeLoadOrder(int LoadOrder);
    int getNextSafeLoadOrder();
    void incrementNextSafeLoadOrder(int loadOrder);
    void serializeLoadOrder();

    int nextSafeLoadOrder = 0;

    void SaveMod(Mod* modEntry);
    void SaveAllMods();
    void LoadModsFromConfig();
    void DetectNewMods();
    void flushFileQueue();
    std::vector<LogEntry> logRecord;
    std::vector<LogEntry> fileQueue;
    std::map<int, std::string> loadOrder;
#ifdef _DEBUG
    severityLevel filterLevel = severityLevel::trace;
#else
    severityLevel filterlevel = severityLevel::info
#endif

    //Logging function
    template<typename...Args>
    inline void log(severityLevel level, const char* format, const Args&...args){
        auto message = boost::str((boost::format(format) % ... % args));
        logRecord.emplace_back(LogEntry(message, level));
        fileQueue.emplace_back(LogEntry(message, level));
    }
};