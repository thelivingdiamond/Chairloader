//
// Created by theli on 3/26/2023.
//

#ifndef CHAIRLOADER_CHAIRMERGER_H
#define CHAIRLOADER_CHAIRMERGER_H
#include <Manager/MergingPolicy.h>
#include <Manager/AttributeWildcard.h>
#include <gtest/gtest.h>
#include <thread>
#include <Manager/ThreadPool.h>
#include "FileChecksum.h"
#include <random>

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <LuaBridge/LuaBridge.h>
#include <variant>

struct ILogger;
struct IChairManager;
class Mod;

enum class DeployPhase
{
    Invalid,
    PreMerge,
    Merge,
    PostMerge,
    Done,
};
enum class DeployStep
{
    Invalid,
    // Pre Merge
    RemovingOldOutput,
    CopyingBaseFiles,
    LoadingPatchChecksums,
    // Merge
    MergingLegacyMods,
    MergingMods,
    // Post Merge
    PackingLevelPatches,
    PackingLocalizationPatches,
    PackingMainPatch,
    CleaningUp,
    Done,
};

class ChairMergerException : public std::runtime_error
{
  public:
    ChairMergerException(DeployStep step, DeployPhase phase, std::vector<std::string>&& messages);

    DeployStep GetDeployStep() const { return m_Step; }
    DeployPhase GetDeployPhase() const { return m_Phase; }
    const std::vector<std::string>& GetMessages() const { return m_Messages; }

  private:
    DeployStep m_Step;
    DeployPhase m_Phase;
    std::vector<std::string> m_Messages;
};

class ChairMerger
{
public:
    //! @param  mergerFiles         ChairMerger files directory.
    //! @param  preyFiles           Source Prey files directory.
    //! @param  chairloaderPatchDir Chairloader patch directory.
    //! @param  outputRoot          Where to place output directories.
    //! @param  gamePath            Game directory.
    //! @param  pLogger             Logger instance to use.
    //! @param  pChairManager       Mod manager instance to use.
    ChairMerger(
        const fs::path& mergerFiles,
        const fs::path& preyFiles,
        const fs::path& chairloaderPatchDir,
        const fs::path& outputRoot,
        const fs::path& gamePath,
        ILogger* pLogger,
        IChairManager* pChairManager);
    std::future<void> LaunchAsyncDeploy();
    void AsyncDeploy();
    void PreMerge();
    void Merge();
    void PostMerge();

    DeployStep GetDeployStep() { return m_DeployStep; }
    DeployPhase GetDeployPhase() { return m_DeployPhase; }
    bool DeployFailed() { return m_bDeployFailed; }
    std::string GetFailedDeployMessage() { return m_DeployError; }

    bool IsModEnabled(std::string modName);

    //! Get the deploy phase descriptive string
    static std::string GetDeployPhaseString(DeployPhase phase);

    //! Get the deploy step descriptive string
    static std::string GetDeployStepString(DeployStep step);

protected:
    FRIEND_TEST(ChairMergerTestBase, ResolveFileWildcards);
    FRIEND_TEST(ChairMergerTestFile, ProcessXMLFile);

    friend class ChairMergerTest;
    friend class ChairManager;

    // Static functions

    //! Copies all files that don't have the given extensions from the source directory to the destination directory
    static void RecursiveFileCopyBlacklist(fs::path source, fs::path destination,
                                           std::vector<std::string> extensionExclusions);

    //! Function to resolve all attribute wildcards in an xml document
    void ResolveFileWildcards(pugi::xml_node docNode, std::string modName);

    //! Copy the chairloader patch files to the output directory
    void CopyChairloaderPatchFiles();

    // Member functions
    //! finds the merging policy for a given file in the merging library
    MergingPolicy GetFileMergingPolicy(const fs::path& file, std::string modName);

    //! This function will copy all non xml files from the mod directory to the output directory
    void CopyModDataFiles(fs::path sourcePath);

    //! This function will recurse on all xml files in the mod directory and resolve all attribute wildcards before
    //! merging, working in the thread pool
    void ProcessMod(std::shared_ptr<Mod> mod);

    //! This function will recurse on all xml files in the legacy mod directory and resolve all attribute wildcards
    //! before merging, working in the thread pool
    void ProcessLegacyMod(std::string modName);

    //! This function will load, resolve attribute wildcards, and merge a single xml file
    void ProcessXMLFile(const fs::path& file, const fs::path& modDataDir, std::string modName, bool isLegacy);

    //! Recursively descends the directory tree and merges all xml files by putting them in the thread pool
    void RecursiveMergeXMLFiles(const fs::path& source, const fs::path& modDataDir, std::string modName, bool isLegacy);

    //! Load the default checksums from the xml file
    void LoadPatchFileChecksums();

    //! sets a given relative level path as changed relative to the default checksums
    void AddChangedLevelPack(fs::path pack);

    //! sets a given relative localization path as changed relative to the default checksums
    void AddChangedLocalizationPack(fs::path pack);

    //! Checks all level files in the output directory and in the game files and adds them to the changed level packs if
    //! they are different
    bool CheckLevelPacksChanged();

    //! Checks all localization files in the output directory and in the game files and adds them to the changed
    //! localization packs if they are different
    bool CheckLocalizationPacksChanged();

    //! Pack level files into .pak files, then copy them to the game directory. Works in the thread pool
    void PackLevelFiles();

    //! Pack localization files into .pak files, then copy them to the game directory. Works in the thread pool
    void PackLocalizationFiles();

    //! Pack the main patch file into a .pak file, then copy it to the game directory
    void PackMainPatch();

    //! Serialize the ids of all levels in the output directory
    void SerializeLevelPacks();

    //! Set the current deploy step, thread safe
    void SetDeployStep(DeployStep step);

    //! Set the current deploy phase, thread safe
    void SetDeployPhase(DeployPhase phase);

    //! Set a deploy failure, thread safe
    void SetDeployFailed(std::string error);

    //! Clear a deploy failure, thread safe
    void ClearDeployFailed();

    //! Get the failure message
    std::string GetDeployFailedMessage();

    void LoadIdNameMap();

    ILogger* m_pLog;
    IChairManager* m_pModManager;

    // ChairManager files
    fs::path m_MergerFilesPath;
    fs::path m_PreyFilePath;
    fs::path m_ChairloaderPatchPath;

    // Temporary output paths
    fs::path m_OutputPath;
    fs::path m_LevelOutputPath;
    fs::path m_LocalizationOutputPath;

    // Game paths
    fs::path m_ModPath = "";
    fs::path m_LevelFilesPath = "";
    fs::path m_LocalizationFilesPath = "";
    fs::path m_PrecacheFilesPath = "";

    static const inline std::map<DeployPhase, std::string> m_DeployPhaseStrings = {
        { DeployPhase::Invalid, "Invalid" }, { DeployPhase::PreMerge, "Pre-Merge" },
        { DeployPhase::Merge, "Merging" },   { DeployPhase::PostMerge, "Post-Merge" },
        { DeployPhase::Done, "Done" },
    };
    static const inline std::map<DeployStep, std::string> m_DeployStepStrings = {
        { DeployStep::Invalid, "Invalid" },
        { DeployStep::RemovingOldOutput, "Removing old output" },
        { DeployStep::CopyingBaseFiles, "Copying base files" },
        { DeployStep::LoadingPatchChecksums, "Loading patch checksums" },
        { DeployStep::MergingLegacyMods, "Merging legacy mods" },
        { DeployStep::MergingMods, "Merging mods" },
        { DeployStep::PackingLevelPatches, "Packing level patches" },
        { DeployStep::PackingLocalizationPatches, "Packing localization patches" },
        { DeployStep::PackingMainPatch, "Packing main patch" },
        { DeployStep::CleaningUp, "Cleaning up" },
        { DeployStep::Done, "Done" },
    };

    // a threadpool for merging tasks
    std::unique_ptr<ThreadPool> m_MergeThreadPool;
    // the merging library
    std::unique_ptr<pugi::xml_document> m_MergingPolicyDoc;

    // deploy progress tracking
    std::mutex m_DeployStateMutex;
    DeployStep m_DeployStep = DeployStep::Invalid;
    DeployPhase m_DeployPhase = DeployPhase::Invalid;
    bool m_bDeployFailed = false;
    std::string m_DeployError;

    // checksums of the vanilla files
    std::map<fs::path, SHA256::Digest> m_LevelFileChecksums, m_LocalizationFileChecksums;
    std::map<fs::path, SHA256::Digest> m_DeployedLevelFileChecksums, m_DeployedLocalizationFileChecksums;
    // changed level packs and localization packs
    std::vector<fs::path> m_ChangedLevelPacks, m_ChangedLocalizationPacks;
    std::mutex m_ChangedLevelPacksMutex, m_ChangedLocalizationPacksMutex;
    // force all level packs and localization packs to be repacked
    bool m_bForceLevelPack = false;
    bool m_bForceLocalizationPack = false;
    bool m_bForceMainPatchPack = false;

    bool m_bForceVanillaPack = false;

    //! List of pending tasks on the thread pool.
    std::vector<std::future<void>> m_PendingTasks;

    // Random Number Generator
    static int Random(int min, int max);
    static float RandomFloat(float min, float max);
    static std::mt19937 m_RandomGenerator;

    static std::map<std::string, uint64_t> m_NameToIdMap;

    //! Adds a task to the pending task list.
    void AddPendingTask(std::future<void>&& future);

    //! Waits for any pending tasks.
    //! If they throw any exceptions, they will be rethrown.
    void WaitForPendingTasks();
};

#endif // CHAIRLOADER_CHAIRMERGER_H
