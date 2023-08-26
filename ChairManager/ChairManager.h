//
// Created by theli on 8/1/2022.
//
#pragma once

//#include <archive.h>
//#include <archive_entry.h>
#include "ImGui/imgui.h"
#include "ImGui/imgui_stdlib.h"
#include <Manager/LogEntry.h>
#include <Manager/IChairManager.h>
#include <Manager/ConfigManager.h>
#include <pugixml.hpp>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <windows.h>
#include "BinaryVersionCheck.h"
#include <boost/format.hpp>
#include "Mod.h"
#include "Merging/ChairMerger.h"


class GamePathDialog;
class GameVersion;
class GamePath;
class ChairInstallWizard;
class ChairUninstallWizard;
class ChairUpdateWizard;
struct SemanticVersion;
enum class DeployStep;
class ChairMerger;


class ChairManager final : public IChairManager {
public:
    static bool IsInstantiated() { return m_spInstance != nullptr; }
    static ChairManager& Get() { return *m_spInstance; }

    ChairManager();
    ~ChairManager();
    void Draw();
    void Update();

    const fs::path& GetGamePath();
    // get mods and get legacy mods
    const std::vector<Mod>& GetMods() { return ModList; }
    const std::vector<std::string>& GetLegacyMods() { return LegacyModList; }
    // get config manager
    ConfigManager* GetConfigManager() { return &m_ConfigManager; }
    // is mod enabled
    bool IsModEnabled(const std::string& modName){
        for(auto& mod : ModList){
            if(mod.modName == modName){
                return mod.enabled;
            }
        }
        return false;
    }
    std::string GetDisplayName(std::string modName);

    const float GetDPIScale() const { return dpiScale; }

    void updateDPI(float dpiScaleIn) {
        updateDPIScaling = true;
        oldDpiScaling = dpiScale;
        dpiScale = dpiScaleIn;
    }



    void DeployForInstallWizard(){
        Init();
        m_pChairMerger->m_bForceMainPatchPack = true;
        RunAsyncDeploy();
        while(!IsFutureReady(m_DeployTaskFuture)){
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        m_DeployTaskFuture.get();
    }



    std::string getETag() {
        return m_githubETag;
    }
    void setETag(std::string eTag) {
        m_githubETag = eTag;
        if(!ChairManagerConfigFile.first_child().child("ETag"))
            ChairManagerConfigFile.first_child().append_child("ETag");
        ChairManagerConfigFile.first_child().child("ETag").text().set(eTag.c_str());
        saveModManagerConfigFile();
    }
    std::string getCachedLatestVersion() {
        auto versionNode = ChairManagerConfigFile.first_child().child("LatestVersion");
        if(versionNode)
            return versionNode.text().as_string();
        return "";
    }

    void setCachedLatestVersion(std::string version) {
        if(!ChairManagerConfigFile.first_child().child("LatestVersion"))
            ChairManagerConfigFile.first_child().append_child("LatestVersion");
        ChairManagerConfigFile.first_child().child("LatestVersion").text().set(version.c_str());
        saveModManagerConfigFile();
    }

    GamePath* GetGamePathUtil(){ return m_pGamePath.get(); }

    void GTestInit();

    // IChairManager
    virtual fs::path GetConfigPath() override;
    virtual fs::path GetModPath(const std::string& modName) override;
    virtual std::vector<std::string> GetModNames() override;
    virtual std::string GetModDisplayName(const std::string& modName) override;
    virtual void LogString(severityLevel level, std::string_view str) override;

private:
    //! DPI
    bool updateDPIScaling;
    float dpiScale = 1.0f;
    const int defaultTextSize = 18;
    float oldDpiScaling = 1.0f;
    //! Current UI state
    enum class State
    {
        Invalid,
        LocateGameDir,
        InstallWizard,
        Deploying,
        UninstallWizard,
        UpdateWizard,
        MainWindow,
    };
    State m_State = State::Invalid;

    /* Globals */
    fs::path ChairManagerConfigPath = R"(.\ChairManagerConfig.xml)";
    std::vector<Mod> ModList;
    std::map<std::string, std::string> ModNameToDisplayName;
    std::vector<std::string> LegacyModList;

    /* Init */
    void LoadModManagerConfig();
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

    /* UpdateWizard */
    std::unique_ptr<ChairUpdateWizard> m_pUpdateWizard;
    void SwitchToUpdateWizard();
    void DrawUpdateWizard(bool* pbIsOpen);
    bool m_bShowUpdateWizard = false;

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

    // DEBUG_BUILD only tab
    void DrawDebug();

    float OverlayWidth = 20.0f;
    float OverlayHeight = 60.0f;
    float OverlayElementWidth = 300.0f;
    float OverlayElementHeight = 150.0f;

    void DrawOverlayLog();
    void ChairManager::OverlayLogElement(LogEntry entry);


    /* Config Functions */
    fs::path getConfigPath(std::string &modName);
    fs::path getDefaultConfigPath(std::string &modName);
    pugi::xml_document ChairloaderConfigFile, ChairManagerConfigFile;
    pugi::xml_node ModListNode;
    inline bool saveChairloaderConfigFile() {
        return ChairloaderConfigFile.save_file((GetGamePath().wstring() + L"/Mods/config/Chairloader.xml").c_str());
    };
    inline bool saveModManagerConfigFile(){
        return ChairManagerConfigFile.save_file(ChairManagerConfigPath.string().c_str());
    }

    /* XML Functions */
    struct XMLFile {
        enum class XMLType
        {
            Registered,
            Legacy,
            BaseGame,
        };
        fs::path path;
        fs::path relativePath;
        XMLType type;
        std::string modName;
//        pugi::xml_document doc;
//        pugi::xml_node root;
        bool empty() const { return path.empty(); }
        // == operator
        bool operator==(const XMLFile& rhs) const {
            return path == rhs.path;
        }
        // == operator with fs::path
        bool operator==(const fs::path& rhs) const {
            return path == rhs;
        }
    };
    XMLFile selectedFile;
    bool TreeNodeWalkDirectory(fs::path relativePath, std::string modName, XMLFile::XMLType type);

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


    /// XML Merging V3
    std::unique_ptr<ChairMerger> m_pChairMerger;

    //! config manager
    ConfigManager m_ConfigManager;


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
    std::list<LogEntry> logRecord;
    std::list<LogEntry> fileQueue;
    std::list<LogEntry> overlayQueue;
    std::mutex logMutex;

    ImColor errorColor = {255,70,70};
    ImColor warningColor = {255, 190, 70};
    // light green
    ImColor debugColor = {120,200,120};

    #ifdef DEBUG_BUILD
        severityLevel filterLevel = severityLevel::trace;
    #else
        severityLevel filterLevel = severityLevel::info;
    #endif
    //Logging function
public:
    template<typename...Args>
    inline void log(severityLevel level, const char* format, const Args&...args){
        auto message = boost::str((boost::format(format) % ... % args));
        LogString(level, message);
    }

    template<typename...Args>
    inline void overlayLog(severityLevel level, const char* format, const Args&...args){
        auto message = boost::str((boost::format(format) % ... % args));
        // scope limiting for mutex
        {
            std::scoped_lock<std::mutex> lock(logMutex);
            logRecord.emplace_back(LogEntry(message, level));
            fileQueue.emplace_back(LogEntry(message, level));
            overlayQueue.emplace_back(LogEntry(message, level));
        }
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
    static inline ChairManager* m_spInstance = nullptr;

    std::unique_ptr<GamePath> m_pGamePath;

    //! Chairloader version checking
    SemanticVersion* packagedChairloaderVersion;
    SemanticVersion* installedChairloaderVersion;
    std::string m_githubETag;

    //! Chairloader Launch Options
    std::wstring m_chairloaderLaunchOptions;
    std::string m_customArgs;
    bool m_bLoadChairloader = true,
        m_bLoadEditor = false,
        m_bDevMode = true,
        m_bTrainer = true,
        m_bNoRandom = false,
        m_bAuxGeom = false;
    void launchGame();

    void removeStartupCinematics();
    void restoreStartupCinematics();

    void RunAsyncDeploy();

    //! Opens the file select dialog for mod installation.
    void OpenInstallModDialog(bool isLegacy);
};