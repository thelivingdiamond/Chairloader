//
// Created by theli on 8/1/2022.
//
#pragma once

//#include <archive.h>
//#include <archive_entry.h>
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
        // installed = Mod loader remembers
        // enabled = Mod loader will load
        // deployed = files are ready
        bool installed = false,
             enabled = false,
             deployed = false,
             hasXML,
             hasDLL;
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
    /* Globals */
    fs::path PreyPath = R"(C:\Program Files (x86)\Steam\steamapps\common\Prey)";
    std::vector<Mod> ModList;

    /* Draw Functions */
    void DrawModList();
    void DrawDLLSettings();
    void DrawXMLSettings();
    void DrawDeploySettings();
    void DrawLog();

    /* Config Functions */
    fs::path getConfigPath(std::string &modName);
    fs::path getDefaultConfigPath(std::string &modName);
    pugi::xml_document ChairloaderConfigFile;
    pugi::xml_node ModListNode;
    inline bool saveChairloaderConfigFile() {
        return ChairloaderConfigFile.save_file((PreyPath.string() + "/Mods/config/Chairloader.xml").c_str());
    };

    /* XML Functions */
    fs::path selectedFile;
    bool TreeNodeWalkDirectory(fs::path path, std::string modName);

    /* Mod List Functions */
    bool LoadModInfoFile(fs::path directory, Mod *mod);
    void LoadModsFromConfig();
    void DetectNewMods();
    void loadModInfoFiles();
    void FindMod(Mod* modEntry);
    std::string fileToLoad;
    fs::path modToLoadPath;

    //Install
    void InstallMod(std::string &modName);
    void UninstallMod(std::string &modName);
    void InstallModFromFile(fs::path path, std::string fileName);

    //Enable
    void EnableMod(std::string modName, bool enabled = true);

    //Deploy
    void DeployMods();

    // Load Order
    std::map<int, std::string> loadOrder;

    bool checkSafeLoadOrder(int LoadOrder);
    int getNextSafeLoadOrder();
    void incrementNextSafeLoadOrder(int loadOrder);
    void serializeLoadOrder();

    int nextSafeLoadOrder = 0;

    // Save Mods
    void SaveMod(Mod* modEntry);
    void SaveAllMods();

    /* Logging Functions */
    void flushFileQueue();
    std::vector<LogEntry> logRecord;
    std::vector<LogEntry> fileQueue;
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