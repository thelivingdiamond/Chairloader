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
#include <chrono>

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
            tm timeStruct;
            timeNow = time(nullptr);
            localtime_s(&timeStruct,&timeNow);
            timeStamp = boost::str((boost::format("%i:%i:%i") % timeStruct.tm_hour % timeStruct.tm_min % timeStruct.tm_sec));
            fadeTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        }
        std::string message;
        severityLevel level;
        std::string timeStamp;
        time_t timeNow;
        uint64_t fadeTime;
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

    float OverlayWidth = 20.0f;
    float OverlayHeight = 60.0f;
    float OverlayElementWidth = 300.0f;
    float OverlayElementHeight = 60.0f;

    void DrawOverlayLog();
    void ModLoader::OverlayLogElement(LogEntry entry);


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

    /* XML MERGING */
    pugi::xml_document mergeXMLDocument(fs::path basePath, fs::path overridePath, fs::path originalPath);
    bool mergeXMLNode(pugi::xml_node &baseNode, pugi::xml_node &overrideNode, pugi::xml_node originalNode = {});
    void mergeDirectory(fs::path path, std::string modName);
    void mergeXMLFiles();

    bool packChairloaderPatch();
    void copyChairloaderPatch();

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
    std::vector<LogEntry> overlayQueue;
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
    template<typename...Args>
    inline void overlayLog(severityLevel level, const char* format, const Args&...args){
        auto message = boost::str((boost::format(format) % ... % args));
        logRecord.emplace_back(LogEntry(message, level));
        fileQueue.emplace_back(LogEntry(message, level));
        overlayQueue.emplace_back(LogEntry(message, level));
    }
};