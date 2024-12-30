//
// Created by theli on 8/1/2022.
//
#pragma once

//#include <archive.h>
//#include <archive_entry.h>
#include "ImGui/imgui.h"
#include "ImGui/imgui_stdlib.h"
#include <ChairMerger/ChairMergerSettings.h>
#include <Manager/LogEntry.h>
#include <Manager/IChairManager.h>
#include <Manager/ConfigManager.h>
#include <Manager/GamePath.h>
#include <pugixml.hpp>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <windows.h>
#include "BinaryVersionCheck.h"
#include <boost/format.hpp>
#include "Mod.h"


class GamePathDialog;
class GameVersion;
class GamePath;
class ChairUninstallWizard;
class ChairUpdateWizard;
class ChairMerger;
struct SemanticVersion;
enum class DeployStep;
class ChairMerger;
class PreyFilesPatchProgressDialog;
class NewInstallWizard;

class ChairManager final : public IChairManager {
public:
    using DeployLogCallback = std::function<void(std::string_view msg)>;

    static bool IsInstantiated() { return m_spInstance != nullptr; }
    static ChairManager& Get() { return *m_spInstance; }

    ChairManager();
    ~ChairManager();
    void Draw();
    void Update();

    const fs::path& GetGamePath();
    // get mods and get legacy mods
    const std::vector<Mod>& GetMods() { return ModList; }
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

    void SetGamePathFromWizard(const fs::path& gamePath);
    bool DeployForInstallWizard(const DeployLogCallback& logFunc, std::string& errorMessage);

    GamePath& GetGamePathUtil(){ return m_GamePath; }

    const SemanticVersion& GetLatestVersionFromGitHub() const { return m_LatestVersionFromGitHub; }

    // IChairManager
    virtual fs::path GetConfigPath() override;
    virtual fs::path GetModPath(const std::string& modName) override;
    virtual std::vector<std::string> GetModNames() override;
    virtual std::vector<std::string> GetLegacyModNames() override;
    virtual const std::vector<Mod>& GetMods() const override;
    virtual std::string GetModDisplayName(const std::string& modName) override;
    virtual const ModConfig* GetModConfig(const std::string& modName) const override;
    virtual void LogString(severityLevel level, std::string_view str) override;
    virtual void OverlayLogString(severityLevel level, std::string_view str) override;

private:
    struct MergerTask;

    //! DPI
    bool updateDPIScaling;
    float dpiScale = 1.0f;
    const int defaultTextSize = 18;
    float oldDpiScaling = 1.0f;
    //! Current UI state
    enum class State
    {
        Invalid,
        InstallWizard,
        Deploying,
        UninstallWizard,
        UpdateWizard,
        MainWindow,
    };
    State m_State = State::Invalid;

    /* Globals */
    fs::path m_LogFilePath;
    fs::path ChairManagerConfigPath;
    std::vector<Mod> ModList;
    std::map<std::string, std::string> ModNameToDisplayName;

    /* Update checking */
    SemanticVersion m_LatestVersionFromGitHub;
    std::future<std::pair<std::string, std::string>> m_VersionCheckTask;
    void StartVersionCheckTask(bool force = false);
    void UpdateVersionCheckTask();

    /* Init */
    void LoadModManagerConfig();
    void SetGamePath(const fs::path& path);
    void Init();
    bool initialized = false;

    /* InstallWizard */
    std::unique_ptr<NewInstallWizard> m_pInstallWizard;
    void SwitchToInstallWizard();
    void OnInstallWizardFinished();

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
    std::unique_ptr<MergerTask> m_pMergerTask;
    ChairMergerSettings m_MergerSettings;
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
    void LoadModInfoFiles();
    bool verifyDependencies(std::string modName);
    bool verifyDependenciesEnabled(std::string modName);

    //Install
    enum class EModInstallStage
    {
        None,
        SelectFile, //!< File selection dialog is open
        LegacyModPopup, //!< Pop-up for legacy mods is open
    };

    struct ModInstallState
    {
        EModInstallStage stage = EModInstallStage::None;
        fs::path modFilePath;
        bool isLegacy = false;
        std::string legacyModName;
    };

    ModInstallState m_ModInstallState;
    void InstallModFromState();
    void UpdateModInstall();

    //Enable
    void EnableMod(std::string modName, bool enabled = true);

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
        OverlayLogString(level, message);
    }
private:
    //! Install Functions
    bool chairloaderInstalled = false;
    // verify config file
    bool verifyChairloaderConfigFile();
    // Create default chairloader config file
    void createChairloaderConfigFile();
    // Create default file structure
    void createDefaultFileStructure();
    static inline ChairManager* m_spInstance = nullptr;

    GamePath m_GamePath;

    std::unique_ptr<PreyFilesPatchProgressDialog> m_pXmlPatchDialog;

    //! Chairloader version checking
    SemanticVersion* packagedChairloaderVersion;
    SemanticVersion* installedChairloaderVersion;
    std::string m_githubETag;
    bool m_bShowUpdatePopup = false;

    //! Chairloader Launch Options
    std::string m_customArgs;
    bool m_bLoadChairloader = true,
        m_bLoadEditor = false,
        m_bDevMode = false,
        m_bTrainer = false,
        m_bNoVid = false,
        m_bNoRandom = false;
    void launchGame();

    void removeStartupCinematics();
    void restoreStartupCinematics();

    std::unique_ptr<ChairMerger> CreateChairMerger(bool forInstallWizard, ILogger* pLogger = nullptr);
    void RunAsyncDeploy();

    //! Opens the file select dialog for mod installation.
    void OpenInstallModDialog();

    //! Checks if an update is available.
    bool IsUpdateAvailable();

    //! Deletes a mod from mod list and all of its files.
    //! Doesn't delete Preditor projects.
    void DeleteInstalledMod(const std::string& modName);
};