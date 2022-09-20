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
#include <Windows.h>
#include "BinaryVersionCheck.h"
#include "XMLMerger.h"
#include "ConfigManager.h"

#include <boost/format.hpp>

class GamePathDialog;
class GameVersion;
class ChairInstallWizard;
class ChairUninstallWizard;

namespace fs = std::filesystem;
class ModLoader {
public:
    static ModLoader& Get() { return *m_spInstance; }

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
        std::string displayName;
        std::string version;
        std::string author;
        std::string dllName;
        int loadOrder = -1;
        pugi::xml_node infoFile;
        pugi::xml_node configFile;
        std::vector<std::string> dependencies;
        // installed = Mod loader remembers
        // enabled = Mod loader will load
        // deployed = files are ready
        bool installed = false,
             enabled = false,
             deployed = false,
             hasXML = false,
             hasLevelXML = false;
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

    const fs::path& GetGamePath() { return PreyPath; }
    // get mods and get legacy mods
    const std::vector<Mod>& GetMods() { return ModList; }
    const std::vector<std::string>& GetLegacyMods() { return LegacyModList; }
    // get config manager
    ConfigManager* GetConfigManager() { return &m_ConfigManager; }
    // is mod enabled
    bool IsModEnabled(std::string modName){
        for(auto& mod : ModList){
            if(mod.modName == modName){
                return mod.enabled;
            }
        }
        return false;
    }
    const float GetDPIScale() { return dpiScale; }
    void updateDPI(float dpiScaleIn){
        updateDPIScaling = true;
        dpiScale = dpiScaleIn;
    }
    std::string GetDisplayName(std::string modName);
    void DeployForInstallWizard();
private:
    //! DPI
    bool updateDPIScaling;
    float dpiScale = 1.0f;
    const int defaultTextSize = 18;

    //! Current UI state
    enum class State
    {
        Invalid,
        LocateGameDir,
        InstallWizard,
        Deploying,
        UninstallWizard,
        MainWindow,
    };
    State m_State = State::Invalid;

    /* Globals */
    fs::path PreyPath;
    std::string m_PreyPathString; //!< String used to display the path in UI
    fs::path ChairloaderModLoaderConfigPath = R"(.\ChairloaderModLoaderConfig.xml)";
    std::vector<Mod> ModList;
    std::map<std::string, std::string> ModNameToDisplayName;
    std::vector<std::string> LegacyModList;

    /* Init */
    void LoadModLoaderConfig();
    void SetGamePath(const fs::path& path);
    void Init();
    bool initialized = false;

    /* LocateGameDir */
    std::unique_ptr<GamePathDialog> m_pGamePathDialog;
    void SwitchToGameSelectionDialog(const fs::path& gamePath);
    void DrawGamePathSelectionDialog(bool* pbIsOpen);

    /* InstallWizard */
    std::unique_ptr<ChairInstallWizard> m_pInstallWizard;
    void SwitchToInstallWizard();
    void DrawInstallWizard(bool* pbIsOpen);

    /* UninstallWizard */
    std::unique_ptr<ChairUninstallWizard> m_pUninstallWizard;
    void SwitchToUninstallWizard();
    void DrawUninstallWizard(bool* pbIsOpen);
    bool m_bShowUninstallWizard = false;

    /* Deploy Screen */
    enum class DeployState
    {
        Invalid,
        RemovingOldOutput,
        CopyingBaseFiles,
        MergingLegacyMods,
        MergingMods,
        RemovingOldPatches,
        PackingLevelFiles,
        CopyingLevelFiles,
        PackingLocalization,
        PackingMainPatch,
        CopyingMainPatch,
        Done
    };
    DeployState m_DeployState = DeployState::Invalid;
    std::mutex m_DeployLogMutex;
    void SwitchToDeployScreen();
    void DrawDeployScreen(bool* pbIsOpen);
    std::future<void> m_DeployTaskFuture;
    ImVec2 modalInitPos {0,0};
    bool initPosSet = false;

    /* Draw Functions */
    std::unique_ptr<GameVersion> m_pGameVersion;
    void DrawMainWindow(bool* pbIsOpen);
    void DrawModList();
    void DrawDLLSettings();
    void DrawAssetView();
    void DrawDeploySettings();
    void DrawLog();

    // _DEBUG only tab
    void DrawDebug();

    float OverlayWidth = 20.0f;
    float OverlayHeight = 60.0f;
    float OverlayElementWidth = 300.0f;
    float OverlayElementHeight = 150.0f;

    void DrawOverlayLog();
    void ModLoader::OverlayLogElement(LogEntry entry);


    /* Config Functions */
    fs::path getConfigPath(std::string &modName);
    fs::path getDefaultConfigPath(std::string &modName);
    pugi::xml_document ChairloaderConfigFile, ChairloaderModLoaderConfigFile;
    pugi::xml_node ModListNode;
    inline bool saveChairloaderConfigFile() {
        return ChairloaderConfigFile.save_file((PreyPath.string() + "/Mods/config/Chairloader.xml").c_str());
    };
    inline bool saveModLoaderConfigFile(){
        return ChairloaderModLoaderConfigFile.save_file(ChairloaderModLoaderConfigPath.string().c_str());
    }

    /* XML Functions */
    fs::path selectedFile;
    bool TreeNodeWalkDirectory(fs::path path, std::string modName);
    void displayXmlNode(pugi::xml_node node, int depth);


    /* Mod List Functions */
    bool LoadModInfoFile(fs::path directory, Mod *mod, bool allowDifferentDirectory = false);
    void LoadModsFromConfig();
    void DetectNewMods();
    void loadModInfoFiles();
    void FindMod(Mod* modEntry);
    bool verifyDependencies(std::string modName);
    bool verifyDependenciesEnabled(std::string modName);
    fs::path fileToLoad;
    fs::path modToLoadPath;

    //Install
    void InstallMod(std::string &modName);
    void UninstallMod(std::string &modName);
    void InstallModFromFile(fs::path path, fs::path fileName);
    bool m_bInstallLegacyMod;

    //Enable
    void EnableMod(std::string modName, bool enabled = true);

    //Deploy
    bool DeployMods();
    void RunAsyncDeploy();

    /* XML MERGING */
    void mergeDirectory(fs::path path, std::string modName, bool legacyMod = false);
    void mergeXMLFiles(bool onlyChairPatch = false);


    //! XML MERGING V2
    XMLMerger m_XMLMerger;

    //! config manager
    ConfigManager m_ConfigManager;

    std::vector<fs::path> exploreLevelDirectory(fs::path);
    PROCESS_INFORMATION packLevel(fs::path path);
    bool packChairloaderPatch();
    bool copyChairloaderPatch();
    bool copyLocalizationPatch();

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
    std::mutex logMutex;

    ImColor errorColor = {255,70,70};
    ImColor warningColor = {255, 190, 70};
    // light green
    ImColor debugColor = {120,200,120};

    #ifdef _DEBUG
        severityLevel filterLevel = severityLevel::trace;
    #else
        severityLevel filterLevel = severityLevel::info;
    #endif
    //Logging function
public:
    template<typename...Args>
    inline void log(severityLevel level, const char* format, const Args&...args){
        logMutex.lock();
        auto message = boost::str((boost::format(format) % ... % args));
        logRecord.emplace_back(LogEntry(message, level));
        fileQueue.emplace_back(LogEntry(message, level));
        logMutex.unlock();
        if(level == severityLevel::fatal){
            flushFileQueue();
            throw std::runtime_error(message);
        }
    }
    template<typename...Args>
    inline void overlayLog(severityLevel level, const char* format, const Args&...args){
        logMutex.lock();
        auto message = boost::str((boost::format(format) % ... % args));
        logRecord.emplace_back(LogEntry(message, level));
        fileQueue.emplace_back(LogEntry(message, level));
        overlayQueue.emplace_back(LogEntry(message, level));
        logMutex.unlock();
        if(level == severityLevel::fatal){
            flushFileQueue();
            throw std::runtime_error(message);
        }
    }
private:
    //! Install Functions
    bool chairloaderInstalled = false;
    // verify config file
    bool verifyChairloaderConfigFile();
    // Create default chairloader config file
    void createChairloaderConfigFile();
    // Verify chairloader is installed
    bool verifyChairloaderInstalled();
    // Verify default file structure
    bool verifyDefaultFileStructure();
    // Create default file structure
    void createDefaultFileStructure();
    static inline ModLoader* m_spInstance = nullptr;

    //! Chairloader version checking
    VersionCheck::DLLVersion packagedChairloaderVersion;
    VersionCheck::DLLVersion installedChairloaderVersion;
};