//
// Created by theli on 3/26/2023.
//

#ifndef CHAIRLOADER_CHAIRMERGER_H
#define CHAIRLOADER_CHAIRMERGER_H
#include "AttributeWildcard.h"
#include "MergingPolicy.h"
#include <gtest/gtest.h>
#include <thread>
#include <Manager/ThreadPool.h>
#include "FileChecksum.h"

class Mod;

enum class DeployPhase {
    Invalid,
    PreMerge,
    Merge,
    PostMerge,
};
enum class DeployStep
{
    Invalid,
    // Pre Merge
    RemovingOldOutput,
    CopyingBaseFiles,
    // Merge
    MergingLegacyMods,
    MergingMods,
    // Post Merge
    RemovingOldPatches,
    PackingLevelFiles,
    CopyingLevelFiles,
    PackingLocalization,
    PackingMainPatch,
    CopyingMainPatch,
    Done,
};

class ChairMerger {
public:
    ChairMerger();
    void PreMerge();
    void Merge();
    void PostMerge();

    DeployStep GetDeployStep();
    DeployPhase GetDeployPhase();
    bool DeployFailed();
    std::string GetFailedDeployMessage();
protected:
    FRIEND_TEST(ChairMergerTest, GetAttributeWildcardValue);
    FRIEND_TEST(ChairMergerTest, ResolveFileWildcardSingleNode);
    FRIEND_TEST(ChairMergerTest, ResolveFileWildcardMultipleNodes);
    FRIEND_TEST(ChairMergerTest, ProcessXMLFileArkFactions);
    FRIEND_TEST(ChairMergerTest, ProcessXMLFilePlayerConfig);
    FRIEND_TEST(ChairMergerTest, RecursiveXmlMerge);
    FRIEND_TEST(ChairMergerTest, ProcessExampleMod);
    FRIEND_TEST(ChairMergerTest, CopyModDataFiles);
    FRIEND_TEST(ChairMergerTest, IsLevelFile);

    friend class ChairMergerTest;

// Static functions
    static void RecursiveFileCopyExclusiveFilter(fs::path source, fs::path destination, std::vector<std::string> exclusions, std::string modName);

    //! Function to resolve all attribute wildcards in an xml document
    static void ResolveFileWildcards(pugi::xml_node docNode,  std::shared_ptr<Mod>);

    //! Recursive function to descend an xml node tree and find all attribute wildcards
    static void ResolveAttributeWildcards(pugi::xml_node node, std::string modName);

    //! Gets the value of an attribute wildcard, and returns true if the wildcard was resolved
    static bool GetAttributeWildcardValue(std::shared_ptr<AttributeWildcard>);

    static void CopyChairloaderPatchFiles();


    // Static paths
    static inline fs::path m_ModPath = "";
    static inline fs::path m_OutputPath = "Output";
    static inline fs::path m_LevelOutputPath = "LevelOutput";
    static inline fs::path m_LocalizationOutputPath = "LocalizationOutput";
    static inline fs::path m_PreyFilePath = "PreyFiles";
    static inline fs::path m_ChairloaderPatchPath = "ChairloaderPatch";
    static inline fs::path m_LevelFilesPath = "";
    static inline fs::path m_LocalizationFilesPath = "";
    static inline fs::path m_PrecacheFilesPath = "";


// Member functions
    //! finds the merging policy for a given file
    MergingPolicy GetFileMergingPolicy(const fs::path& file, std::string modName);

    //! This function will copy all non xml files from the mod directory to the output directory
    void CopyModDataFiles(fs::path sourcePath, std::string modName);

    //! This function will recurse on all xml files in the mod directory and resolve all attribute wildcards before merging, working in the thread pool
    void ProcessMod(std::shared_ptr<Mod> mod);

    void ProcessLegacyMod(std::string modName);

    void ProcessXMLFile(const fs::path &file, std::string modName, bool isLegacy);

    //! Recursively descends the directory tree and merges all xml files by putting them in the thread pool
    void RecursiveMergeXMLFiles(const fs::path &source, std::string modName, bool isLegacy);

    //! checks if the file is a level file, and if so, sets the level files changed flag
    static bool IsLevelFile(const fs::path &modFile, std::string modName);

    //! checks if the file is a localization file, and if so, sets the localization files changed flag
    static bool IsLocalizationFile(const fs::path &modFile, std::string modName);


    //! a threadpool for merging tasks
    std::unique_ptr<ThreadPool> m_MergeThreadPool;

    std::unique_ptr<pugi::xml_document> m_MergingPolicyDoc;

    std::mutex m_DeployStateMutex;
    DeployStep m_DeployStep = DeployStep::Invalid;
    DeployPhase m_DeployPhase = DeployPhase::Invalid;
    bool m_bDeployFailed = false;
    std::string m_DeployError = "";
    void SetDeployStep(DeployStep step);
    void SetDeployPhase(DeployPhase phase);
    void SetDeployFailed(std::string error);
    void ClearDeployFailed();


    std::vector<FileChecksum> m_LevelFileChecksums, m_LocalizationFileChecksums;

    void LoadPatchFileChecksums();
    bool isFileChanged(FileChecksum file);

    std::vector<fs::path> m_ChangedLevelPacks, m_ChangedLocalizationPacks;

    bool CheckLevelPacksChanged();

    bool CheckLocalizationPacksChanged();

    static bool PackFolder(fs::path folder, fs::path output);


    void PackLevelFiles();
    void PackLocalizationFiles();
    void PackMainPatch();



    static inline std::atomic<bool> m_LevelFilesChanged = false;
    static inline std::atomic<bool> m_LocalizationFilesChanged = false;

};


#endif //CHAIRLOADER_CHAIRMERGER_H
