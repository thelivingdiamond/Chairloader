//
// Created by theli on 3/26/2023.
//

#include <regex>
#include "ChairMerger.h"
#include "ChairManager.h"
#include <gtest/gtest.h>
#include <boost/algorithm/string.hpp>
#include <Manager/XMLMerger2.h>
#include <Manager/LuaUtils.h>
#include <Manager/WildcardResolver.h>
#include <Manager/NameToIdMap.h>
#include <Manager/PreditorFiles.h>
#include "ZipUtils.h"
#include "HashUtils.h"

// resolve static variable m_RandomGenerator
std::mt19937 ChairMerger::m_RandomGenerator;
std::map<std::string, uint64_t> ChairMerger::m_NameToIdMap;

ChairMergerException::ChairMergerException(DeployStep step, DeployPhase phase, std::vector<std::string>&& messages)
    : std::runtime_error(fmt::format("Merging error when {} during {}", ChairMerger::GetDeployStepString(step),
                                     ChairMerger::GetDeployPhaseString(phase)))
{
    m_Step = step;
    m_Phase = phase;
    m_Messages = std::move(messages);
}

ChairMerger::ChairMerger(
    const fs::path& mergerFiles,
    const fs::path& preyFiles,
    const fs::path& chairloaderPathDir,
    const fs::path& outputRoot,
    const fs::path& gamePath)
{
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Initializing ChairMerger");
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: ChairMerger Initialized");

    // ChairManager files
    if (!fs::exists(mergerFiles))
        throw std::invalid_argument("mergerFiles doesn't exists");

    if (!fs::exists(preyFiles))
        throw std::invalid_argument("preyFiles doesn't exists");

    if (!fs::exists(chairloaderPathDir))
        throw std::invalid_argument("chairloaderPathDir doesn't exists");

    m_MergerFilesPath = mergerFiles;
    m_PreyFilePath = preyFiles;
    m_ChairloaderPatchPath = chairloaderPathDir;

    // Temporary outputs
    m_OutputPath = outputRoot / "Output";
    m_LevelOutputPath = outputRoot / "LevelOutput";
    m_LocalizationOutputPath = outputRoot / "LocalizationOutput";
    fs::create_directories(m_OutputPath);

    // Game paths
    if (!fs::exists(gamePath))
        throw std::invalid_argument("gamePath doesn't exists");

    m_ModPath = gamePath / "Mods";
    m_LevelFilesPath = gamePath / "GameSDK" / "Levels";
    m_LocalizationFilesPath = gamePath / "Localization";
    m_PrecacheFilesPath = gamePath / "GameSDK" / "Precache";

    if (!fs::exists(m_PrecacheFilesPath))
    {
        fs::create_directories(m_PrecacheFilesPath);
    }

    if (!fs::exists(m_OutputPath))
    {
        fs::create_directory(m_OutputPath);
    }
    unsigned int numThreads = std::thread::hardware_concurrency();
    m_MergeThreadPool = std::make_unique<ThreadPool>(numThreads);
    m_MergingPolicyDoc = std::make_unique<pugi::xml_document>();

    auto result = m_MergingPolicyDoc->load_file(MERGING_LIBRARY_FILE_NAME);
    if (!result)
    {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not load MergingLibrary.xml");
    }

    m_RandomGenerator = std::mt19937(std::random_device()());
}

std::future<void> ChairMerger::LaunchAsyncDeploy()
{
    return std::async(std::launch::async, &ChairMerger::AsyncDeploy, this);
}

void ChairMerger::AsyncDeploy()
{
    try
    {
        ClearDeployFailed();
        auto now = std::chrono::high_resolution_clock::now();
        PreMerge();
        if (m_bDeployFailed)
            return;
        Merge();
        if (m_bDeployFailed)
            return;
        PostMerge();
        if (m_bDeployFailed)
            return;
        SetDeployPhase(DeployPhase::Done);
        SetDeployStep(DeployStep::Done);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - now);
        if (!m_bDeployFailed)
        {
            ChairManager::Get().log(severityLevel::info, "ChairMerger: Finished merging in %.1f seconds",
                                    elapsed.count() / 1000.0f);
        }
        else
        {
            ChairManager::Get().log(severityLevel::info, "ChairMerger: Merge failed, %d seconds",
                                    elapsed.count() / 1000.0f);
        }
    }
    catch (const ChairMergerException& e)
    {
        std::string errorMsg = e.what();
        ChairManager::Get().log(severityLevel::error, "Merging failed: %s", e.what());

        for (const std::string& msg : e.GetMessages())
        {
            ChairManager::Get().log(severityLevel::error, " - %s", msg.c_str());
            errorMsg.append("\n");
            errorMsg.append(msg);
        }

        SetDeployFailed(errorMsg);
    }
    catch (const std::exception& e)
    {
        std::string errorMsg = e.what();
        ChairManager::Get().log(severityLevel::error, "Merging failed: %s", e.what());
        SetDeployFailed(errorMsg);
    }
}

void ChairMerger::PreMerge()
{
    // profile pre merge task
    auto now = std::chrono::high_resolution_clock::now();
    SetDeployPhase(DeployPhase::PreMerge);
    // make sure mod configs are loaded
    // clear out the output directory
    SetDeployStep(DeployStep::RemovingOldOutput);
    try
    {
        fs::remove_all(m_OutputPath);
        fs::create_directories(m_OutputPath);
    }
    catch (fs::filesystem_error& e)
    {
        ChairManager::Get().overlayLog(severityLevel::error, "Failed to clear output directory: %s",
                                       std::string(e.what()));
        SetDeployFailed("Failed to clear output directory: " + std::string(e.what()));
        return;
    }
    // Copy over the chairloader patch files
    SetDeployStep(DeployStep::CopyingBaseFiles);
    CopyChairloaderPatchFiles();
    if (m_bDeployFailed)
        return;
    // load the patch file checksums
    SetDeployStep(DeployStep::LoadingPatchChecksums);
    LoadPatchFileChecksums();
    LoadIdNameMap();
    if (m_bDeployFailed)
        return;
    auto end = std::chrono::high_resolution_clock::now();
    ChairManager::Get().log(severityLevel::debug, "Pre-Merge took %f seconds",
                            std::chrono::duration_cast<std::chrono::duration<double>>(end - now).count());
}

void ChairMerger::Merge()
{
    // profile merge task
    auto now = std::chrono::high_resolution_clock::now();
    if (m_bForceVanillaPack)
        return;
    // merge the legacy mods
    SetDeployPhase(DeployPhase::Merge);
    SetDeployStep(DeployStep::MergingLegacyMods);
    for (auto& legacyMod : ChairManager::Get().GetLegacyMods())
    {
        ProcessLegacyMod(legacyMod);
        WaitForPendingTasks();
        ChairManager::Get().log(severityLevel::trace, "Finished merging legacy mod: %s", legacyMod);
    }

    if (m_bDeployFailed)
        return;

    // merge the registered mods
    SetDeployStep(DeployStep::MergingMods);
    for (auto& mod : ChairManager::Get().GetMods())
    {
        if (mod.enabled)
        {
            ProcessMod(std::make_shared<Mod>(mod));
            WaitForPendingTasks();
            ChairManager::Get().log(severityLevel::trace, "Finished merging mod: %s", mod.modName);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    ChairManager::Get().log(severityLevel::debug, "Merge took %f seconds",
                            std::chrono::duration_cast<std::chrono::duration<double>>(end - now).count());
}

void ChairMerger::PostMerge()
{
    // profile post merge task
    auto now = std::chrono::high_resolution_clock::now();
    SetDeployPhase(DeployPhase::PostMerge);
    // Post merge tasks

    // Pack and Copy the level files
    SetDeployStep(DeployStep::PackingLevelPatches);
    PackLevelFiles();
    if (m_bDeployFailed)
        return;
    SetDeployStep(DeployStep::PackingLocalizationPatches);
    PackLocalizationFiles();
    if (m_bDeployFailed)
        return;
    SetDeployStep(DeployStep::PackingMainPatch);
    PackMainPatch();
    if (m_bDeployFailed)
        return;
    SetDeployStep(DeployStep::CleaningUp);

    auto end = std::chrono::high_resolution_clock::now();
    ChairManager::Get().log(severityLevel::debug, "Post-Merge took %f seconds",
                            std::chrono::duration_cast<std::chrono::duration<double>>(end - now).count());
}

bool ChairMerger::IsModEnabled(std::string modName)
{
    return ChairManager::Get().IsModEnabled(modName);
}

std::string ChairMerger::GetDeployPhaseString(DeployPhase phase)
{
    return m_DeployPhaseStrings.at(phase);
}

std::string ChairMerger::GetDeployStepString(DeployStep step)
{
    return m_DeployStepStrings.at(step);
}

void ChairMerger::RecursiveFileCopyBlacklist(fs::path source, fs::path destination, std::vector<std::string> exclusions)
{
    if (fs::exists(source) && fs::is_directory(source))
    {
        for (auto& file : fs::directory_iterator(source))
        {
            if (fs::is_directory(file))
            {
                RecursiveFileCopyBlacklist(file.path(), destination / file.path().filename(), exclusions);
            }
            else
            {
                bool shouldCopy = true;
                for (auto& exclusion : exclusions)
                {
                    if (file.path().extension() == exclusion)
                    {
                        shouldCopy = false;
                        break;
                    }
                }
                if (shouldCopy)
                {
                    auto destinationPath = destination / file.path().filename();
                    fs::create_directories(destinationPath.parent_path());
                    fs::copy_file(file.path(), destinationPath, fs::copy_options::overwrite_existing);
                }
            }
        }
    }
}

//! Function to resolve all attribute wildcards in an xml document
void ChairMerger::ResolveFileWildcards(pugi::xml_node docNode, std::string modName)
{
    WildcardResolver wr(&ChairManager::Get(), m_RandomGenerator, modName);

    // add the config variables to the lua state
    for (auto& mod : ChairManager::Get().GetMods())
    {
        // TODO 2023-07-07: Check if mod is enabled. Disabled mods shouldn't influence other mods.
        auto& config = ChairManager::Get().GetConfigManager()->getModConfig(mod.modName);
        wr.AddModConfig(config);
    }

    // TODO: add local mod config variables in a way to ignore g.modName
    auto& curModConfig = ChairManager::Get().GetConfigManager()->getModConfig(modName);
    wr.AddGlobalModConfig(curModConfig);

    wr.AddIdNameMap(m_NameToIdMap);
    wr.ResolveDocumentWildcards(docNode);
}

void ChairMerger::CopyChairloaderPatchFiles()
{
    if (fs::exists(m_ChairloaderPatchPath))
    {
        try
        {
            fs::copy(m_ChairloaderPatchPath, m_OutputPath,
                     fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        }
        catch (fs::filesystem_error& e)
        {
            ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not copy chairloader patch files: %s",
                                    e.what());
        }
    }
}

MergingPolicy ChairMerger::GetFileMergingPolicy(const fs::path& file, std::string modName)
{
    MergingPolicy policy = MergingPolicy::FindMergingPolicy(*m_MergingPolicyDoc, file, m_PreyFilePath);

    if (policy.policy == MergingPolicy::identification_policy::unknown)
        ChairManager::Get().log(severityLevel::error, "XMLMerger: File %s not found in merging library",
            file.u8string());

    return policy;
}

void ChairMerger::CopyModDataFiles(fs::path sourcePath)
{
    AddPendingTask(
        m_MergeThreadPool->enqueue([this, sourcePath] { RecursiveFileCopyBlacklist(sourcePath, m_OutputPath, { ".xml" }); }));
}

void ChairMerger::ProcessMod(std::shared_ptr<Mod> mod)
{
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Processing mod %s", mod->modName.c_str());

    fs::path dataPath = m_ModPath / mod->modName / "Data";

    // Copy all files from the mod's Data folder to the output folder
    CopyModDataFiles(dataPath);

    // Merge all XML files from the mod's Data folder
    RecursiveMergeXMLFiles(dataPath, mod->modName, false);
}

void ChairMerger::ProcessLegacyMod(std::string modName)
{
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Processing legacy mod %s", modName.c_str());

    fs::path dataPath = m_ModPath / "Legacy" / modName;

    // Copy all files from the mod's Data folder to the output folder
    CopyModDataFiles(dataPath);

    // Merge all XML files from the mod's Data folder
    RecursiveMergeXMLFiles(dataPath, modName, true);
}

void ChairMerger::ProcessXMLFile(const fs::path& file, std::string modName, bool isLegacy)
{
    fs::path relativePath;
    if (isLegacy)
    {
        relativePath = file.lexically_relative(m_ModPath / "Legacy" / modName);
    }
    else
    {
        relativePath = file.lexically_relative(m_ModPath / modName / "Data");
    }
    auto policy = GetFileMergingPolicy(relativePath, modName);

    // now we have the relative path to the file, we can use this to find the original file, and the base file in the
    // output directory
    fs::path originalFile = m_PreyFilePath / relativePath;
    fs::path baseFile = m_OutputPath / relativePath;

    pugi::xml_document baseDoc, modDoc, originalDoc;
    auto parseTags = pugi::parse_default;
    if (policy.policy == MergingPolicy::identification_policy::match_spreadsheet)
    {
        parseTags = pugi::parse_full;
    }

    pugi::xml_parse_result baseResult = baseDoc.load_file(baseFile.wstring().c_str(), parseTags);
    pugi::xml_parse_result modResult = modDoc.load_file(file.wstring().c_str(), parseTags);
    pugi::xml_parse_result originalResult = originalDoc.load_file(originalFile.wstring().c_str(), parseTags);

    if (!modResult)
    {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not load mod file %s",
                                file.u8string().c_str());
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Description: %s", modResult.description());
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Offset: %lld", modResult.offset);
        throw std::runtime_error(fmt::format("Could not load {}", file.u8string()));
    }
    // resolve attribute wildcards on non legacy files
    if (!isLegacy)
        ResolveFileWildcards(modDoc.first_child(), modName);

    // Create the output directory
    if (!fs::exists(baseFile.parent_path()))
        fs::create_directories(baseFile.parent_path());

    if (!originalResult)
    {
        // this is a new file, we have to just copy it over, even if base exists
        modDoc.save_file(baseFile.wstring().c_str(), "\t", pugi::format_default, pugi::encoding_utf8);
        return;
    }

    // if we have an original result, we can actually do some merging
    if (policy.policy == MergingPolicy::identification_policy::overwrite ||
        policy.policy == MergingPolicy::identification_policy::unknown)
    {
        fs::copy_file(file, baseFile, fs::copy_options::overwrite_existing);
        return;
    }

    if (!baseResult)
    {
        // this is a file that hasn't been merged before, we should copy the original over
        fs::copy_file(originalFile, baseFile, fs::copy_options::overwrite_existing);
        baseResult = baseDoc.load_file(baseFile.wstring().c_str());
        if (!baseResult)
        {
            ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not load base file %s",
                                    baseFile.u8string().c_str());
            ChairManager::Get().log(severityLevel::error, "ChairMerger: Description: %s", baseResult.description());
            ChairManager::Get().log(severityLevel::error, "ChairMerger: Offset: %lld", baseResult.offset);
            throw std::runtime_error(fmt::format("Could not load base file {}", baseFile.u8string()));
        }
    }

    XMLMerger2::MergeXMLDocument(baseDoc, modDoc, originalDoc, policy);

    baseDoc.save_file(baseFile.wstring().c_str());

    // we are done
}

void ChairMerger::RecursiveMergeXMLFiles(const fs::path& source, std::string modName, bool isLegacy)
{
    if (fs::exists(source) && fs::is_directory(source))
    {
        for (auto& file : fs::directory_iterator(source))
        {
            if (fs::is_directory(file))
            {
                RecursiveMergeXMLFiles(file.path(), modName, isLegacy);
            }
            else
            {
                if (file.path().extension() == ".xml")
                {
                    // Toss the file into the thread pool
                    AddPendingTask(m_MergeThreadPool->enqueue(
                        [this, file, modName, isLegacy] { ProcessXMLFile(file, modName, isLegacy); }));
                }
            }
        }
    }
}

void ChairMerger::LoadPatchFileChecksums()
{
    m_LevelFileChecksums.clear();
    m_LocalizationFileChecksums.clear();
    pugi::xml_document doc;

    auto result = doc.load_file((m_MergerFilesPath / "patchChecksums.xml").c_str());
    if (!result)
    {
        ChairManager::Get().overlayLog(severityLevel::error, "ChairMerger: Could not load patch checksums file");
        return;
    }
    auto root = doc.first_child();
    for (auto& child : root.children())
    {
        std::string path = child.attribute("path").value();
        std::string hash = child.attribute("hash").value();
        std::string type = child.attribute("type").value();
        if (type == "level")
        {
            m_LevelFileChecksums[path] = SHA256::fromString(hash);
        }
        else if (type == "localization")
        {
            m_LocalizationFileChecksums[path] = SHA256::fromString(hash);
        }
        else
        {
            ChairManager::Get().log(severityLevel::error, "ChairMerger: Invalid patch checksum type %s", type);
        }
    }
}

void ChairMerger::AddChangedLevelPack(fs::path pack)
{
    std::lock_guard<std::mutex> lock(m_ChangedLevelPacksMutex);
    m_ChangedLevelPacks.emplace_back(pack);
}

void ChairMerger::AddChangedLocalizationPack(fs::path pack)
{
    std::lock_guard<std::mutex> lock(m_ChangedLocalizationPacksMutex);
    m_ChangedLocalizationPacks.emplace_back(pack);
}

bool ChairMerger::CheckLevelPacksChanged()
{
    m_ChangedLevelPacks.clear();
    for (auto& levelPack : m_LevelFileChecksums)
    {
        AddPendingTask(m_MergeThreadPool->enqueue([levelPack, this]() {
            auto existingFile = m_LevelFilesPath / levelPack.first;
            bool exists = fs::exists(existingFile);
            auto checksum = HashUtils::HashUncompressedFile(existingFile);
            m_DeployedLevelFileChecksums[levelPack.first] = checksum;
            if (checksum != levelPack.second || !fs::exists(existingFile) || m_bForceLevelPack)
            {
                AddChangedLevelPack(levelPack.first);
                ChairManager::Get().log(severityLevel::trace, "ChairMerger: Level pack %s has changed",
                                        levelPack.first.string());
            }
            else if (fs::exists(m_OutputPath / "Levels" / levelPack.first.parent_path()))
            {
                AddChangedLevelPack(levelPack.first);
            }
            //            }
        }));
    }
    WaitForPendingTasks();
    return !m_ChangedLevelPacks.empty();
}

bool ChairMerger::CheckLocalizationPacksChanged()
{
    m_ChangedLocalizationPacks.clear();
    for (auto& localizationPack : m_LocalizationFileChecksums)
    {
        auto existingFile = m_LocalizationFilesPath / localizationPack.first;
        auto checksum = HashUtils::HashUncompressedFile(existingFile);
        m_DeployedLocalizationFileChecksums[localizationPack.first] = checksum;
        //        auto checksum = SHA256::Digest();
        //        if(false) {
        if (checksum != localizationPack.second || !fs::exists(existingFile) || m_bForceLocalizationPack)
        {
            AddChangedLocalizationPack(localizationPack.first);
            ChairManager::Get().log(severityLevel::debug, "ChairMerger: Localization pack %s has changed",
                                    localizationPack.first.string());
        }
        else if (fs::exists(m_OutputPath / "Localization" / localizationPack.first.parent_path()))
        {
            AddChangedLocalizationPack(localizationPack.first);
        }
        //        }
    }
    return !m_ChangedLocalizationPacks.empty();
}

void ChairMerger::PackLevelFiles()
{
    try
    {
        fs::remove_all(m_LevelOutputPath);
        fs::create_directories(m_LevelOutputPath);
    }
    catch (fs::filesystem_error& e)
    {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not clear level output directory");
        SetDeployFailed("Could not clear level output directory");
        return;
    }
    if (CheckLevelPacksChanged())
    {
        std::atomic<bool> bFailure = false;
        ChairManager::Get().log(severityLevel::debug, "ChairMerger: Level files have changed, repacking");
        // level files have changed, repack the level files, we just need to check which ones are changed
        for (auto& changedPack : m_ChangedLevelPacks)
        {
            // this is a relative path to the level pack, we need to remove the filename so we can find the level
            // directory
            const auto levelPath = changedPack.parent_path();
            const auto deployedHash = m_DeployedLevelFileChecksums[changedPack];
            const bool forcePack = m_bForceLevelPack;
            AddPendingTask(m_MergeThreadPool->enqueue([this, levelPath, deployedHash, forcePack, &bFailure] {
                try
                {
                    // create the level directory in the level output path
                    fs::create_directories(m_LevelOutputPath / levelPath);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not create level directory %s",
                                            (m_LevelOutputPath / levelPath).string());
                    bFailure = true;
                    return;
                }
                try
                {
                    // copy over the level directory to the level output path
                    fs::copy(m_PreyFilePath / "Levels" / levelPath, m_LevelOutputPath / levelPath,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(severityLevel::error,
                                            "ChairMerger: Could not copy original level directory %s",
                                            (m_PreyFilePath / "Levels" / levelPath).string());
                    bFailure = true;
                    return;
                }
                try
                {
                    // then copy over the output that we merged or copied into
                    fs::copy(m_OutputPath / "Levels" / levelPath, m_LevelOutputPath / levelPath,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(
                        severityLevel::debug,
                        "ChairMerger: Could not copy level output directory %s, no mod modified this level.",
                        (m_OutputPath / "Levels" / levelPath).string());
                }
                // then serialize the entity level ids
                XMLMerger2::SerializeLevelEntityIDs(m_LevelOutputPath / levelPath / "level");
                // now check if we need to continue to pack the level directory
                auto levelPakHashPath = m_LevelOutputPath / levelPath / "level";
                auto levelOutputChecksum = HashUtils::HashDirectory(levelPakHashPath);
                if (levelOutputChecksum == deployedHash && !forcePack)
                {
                    // the level directory has not changed, we can skip packing it
                    ChairManager::Get().log(severityLevel::info, "ChairMerger: Level %s is up to date, skipping",
                                            levelPath.filename().u8string());
                    try
                    {
                        // remove the "level" folder from the level output path
                        fs::remove_all(m_LevelOutputPath / levelPath / "level");
                        // remove the folder from the output path
                        fs::remove_all(m_OutputPath / "Levels" / levelPath);
                    }
                    catch (fs::filesystem_error& e)
                    {
                        ChairManager::Get().log(severityLevel::error,
                                                "ChairMerger: Could not remove level directory %s",
                                                (m_LevelOutputPath / levelPath / "level").string());
                    }
                    return;
                }
                try
                {
                    // then we must pack the level directory
                    std::ofstream(m_LevelOutputPath / levelPath / "level" / MARK_OF_THE_CHAIR).close();
                    ZipUtils::CompressFolder(m_LevelOutputPath / levelPath / "level",
                                             m_LevelOutputPath / levelPath / "level.pak", true);
                }
                catch (std::exception& e)
                {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not pack level directory %s",
                                            (m_LevelOutputPath / levelPath / "level").string());
                    bFailure = true;
                }
                try
                {
                    // remove the "level" folder from the level output path
                    fs::remove_all(m_LevelOutputPath / levelPath / "level");
                    // remove the folder from the output path
                    fs::remove_all(m_OutputPath / "Levels" / levelPath);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not remove level directory %s",
                                            (m_LevelOutputPath / levelPath / "level").string());
                }
                try
                {
                    // copy the output folder to the game files folder
                    fs::copy(m_LevelOutputPath / levelPath, m_LevelFilesPath / levelPath,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not copy merged level pack %s",
                                            (m_LevelOutputPath / levelPath).string());
                    bFailure = true;
                    return;
                }
                ChairManager::Get().log(severityLevel::trace, "ChairMerger: Finished merging level pack %s",
                                        levelPath.string());
            }));
        }
        WaitForPendingTasks();
        if (bFailure)
        {
            SetDeployFailed("Error merging level packs");
            return;
        }
        ChairManager::Get().log(severityLevel::trace, "ChairMerger: Finished merging all level packs");
    }
}

void ChairMerger::PackLocalizationFiles()
{
    try
    {
        fs::remove_all(m_LocalizationOutputPath);
        fs::create_directories(m_LocalizationOutputPath);
    }
    catch (fs::filesystem_error& e)
    {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not clear localization output directory");
        return;
    }
    if (CheckLocalizationPacksChanged())
    {
        std::atomic<bool> bFailure = false;
        ChairManager::Get().log(severityLevel::debug, "ChairMerger: Localization files have changed, repacking");
        // localization files have changed, repack the localization files, we just need to check which ones are changed
        for (auto& changedPack : m_ChangedLocalizationPacks)
        {
            // this is a relative path to the localization pack, we need to remove the filename so we can find the
            // localization directory
            const auto localizationPath = changedPack.parent_path();
            const auto deployedLocalizationChecksum = m_DeployedLocalizationFileChecksums[changedPack];
            const bool forcePack = m_bForceLocalizationPack;
            AddPendingTask(m_MergeThreadPool->enqueue([this, localizationPath, changedPack, deployedLocalizationChecksum,
                                                       forcePack, &bFailure] {
                // patch file path is XXXX_patch.pak
                // non-patch path is XXXX, so the filename needs to be changed and the extension removed
                fs::path patchFilePath = localizationPath / changedPack.filename();
                fs::path originalDirectoryPath = localizationPath / changedPack.filename().replace_extension("");
                // if the originalDirectoryPath has _patch, remove it
                if (originalDirectoryPath.filename().wstring().find(L"_patch") != std::string::npos)
                {
                    originalDirectoryPath = originalDirectoryPath.parent_path() /
                                            originalDirectoryPath.filename().replace_extension("").string().substr(
                                                0, originalDirectoryPath.filename().string().find("_patch"));
                }
                try
                {
                    // create the localization directory in the localization output path
                    fs::create_directories(m_LocalizationOutputPath / localizationPath);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(severityLevel::error,
                                            "ChairMerger: Could not create localization output directory %s",
                                            (m_LocalizationOutputPath / localizationPath).string());
                    bFailure = true;
                    return;
                }
                try
                {
                    // copy over the vanilla localization patch files to the localization output path
                    fs::copy(m_PreyFilePath / "Localization" / originalDirectoryPath,
                             m_LocalizationOutputPath / originalDirectoryPath,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(severityLevel::error,
                                            "ChairMerger: Could not copy original localization patch %s",
                                            (m_PreyFilePath / "Localization" / originalDirectoryPath).string());
                    bFailure = true;
                    return;
                }
                try
                {
                    // then copy over the output that we merged or copied into
                    fs::copy(m_OutputPath / "localization" / originalDirectoryPath,
                             m_LocalizationOutputPath / originalDirectoryPath,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(
                        severityLevel::debug,
                        "ChairMerger: Could not copy localization output directory %s, no mod modified this pack.",
                        (m_OutputPath / "localization" / originalDirectoryPath).string());
                }
                // now check if we need to continue to pack the level directory
                auto levelOutputChecksum = HashUtils::HashDirectory(m_LocalizationOutputPath / originalDirectoryPath);
                if (levelOutputChecksum == deployedLocalizationChecksum && !forcePack)
                {
                    ChairManager::Get().log(severityLevel::info,
                                            "ChairMerger: Localization pack %s up to date, skipping",
                                            originalDirectoryPath.string());
                    try
                    {
                        // remove the original folder from the localization output path
                        fs::remove_all(m_LocalizationOutputPath / localizationPath / originalDirectoryPath);
                        // remove the folder from the output path
                        fs::remove_all(m_OutputPath / "Localization" / localizationPath / originalDirectoryPath);
                    }
                    catch (fs::filesystem_error& e)
                    {
                        ChairManager::Get().log(
                            severityLevel::error, "ChairMerger: Could not remove localization directory %s",
                            (m_LocalizationOutputPath / localizationPath / "localization").string());
                    }
                    return;
                }
                try
                {
                    // then we must pack the localization directory
                    std::ofstream(m_LocalizationOutputPath / localizationPath / originalDirectoryPath /
                                  MARK_OF_THE_CHAIR)
                        .close();
                    ZipUtils::CompressFolder(m_LocalizationOutputPath / localizationPath / originalDirectoryPath,
                                             m_LocalizationOutputPath / localizationPath / patchFilePath, true);
                }
                catch (std::exception& e)
                {
                    ChairManager::Get().log(severityLevel::error,
                                            "ChairMerger: Could not pack localization directory %s",
                                            (m_LocalizationOutputPath / localizationPath / "localization").string());
                    bFailure = true;
                }
                try
                {
                    // remove the original folder from the localization output path
                    fs::remove_all(m_LocalizationOutputPath / localizationPath / originalDirectoryPath);
                    // remove the folder from the output path
                    fs::remove_all(m_OutputPath / "Localization" / localizationPath / originalDirectoryPath);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(severityLevel::error,
                                            "ChairMerger: Could not remove localization directory %s",
                                            (m_LocalizationOutputPath / localizationPath / "localization").string());
                }
                try
                {
                    // copy the output folder to the game files folder
                    // because this is localization we need to replace the patch_ files with the new ones
                    fs::copy(m_LocalizationOutputPath / localizationPath / patchFilePath,
                             m_LocalizationFilesPath / localizationPath / patchFilePath,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                }
                catch (fs::filesystem_error& e)
                {
                    ChairManager::Get().log(severityLevel::error,
                                            "ChairMerger: Could not copy merged localization pack %s",
                                            (m_LocalizationOutputPath / localizationPath).string());
                    bFailure = true;
                }
            }));
        }
        WaitForPendingTasks();
        ChairManager::Get().log(severityLevel::trace, "ChairMerger: Finished merging localization packs");
    }
}

void ChairMerger::PackMainPatch()
{
    // at this point level and localization packs are packed and their files moved. We can now pack what is left in the
    // output path
    auto deployedFileHash = HashUtils::HashUncompressedFile(m_PrecacheFilesPath / "patch_chairloader.pak");
    auto outputFileHash = HashUtils::HashDirectory(m_OutputPath);
    if (deployedFileHash == outputFileHash && !m_bForceMainPatchPack)
    {
        ChairManager::Get().log(severityLevel::info, "ChairMerger: Main patch is up to date, skipping");
        return;
    }
    try
    {
        fs::remove(m_PrecacheFilesPath / "patch_chairloader.pak");
    }
    catch (fs::filesystem_error& e)
    {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not remove old patch file: %s", e.what());
        SetDeployFailed("Could not remove old patch file: " + std::string(e.what()));
        return;
    }
    std::ofstream(m_OutputPath / MARK_OF_THE_CHAIR).close();
    ZipUtils::CompressFolder(m_OutputPath, m_PrecacheFilesPath / "patch_chairloader.pak", true);
    ChairManager::Get().log(severityLevel::trace, "ChairMerger: Finished packing main patch");
}

void ChairMerger::SerializeLevelPacks()
{
    for (auto& levelPack : m_ChangedLevelPacks)
    {
        auto levelFolderPath = m_OutputPath / "Levels" / levelPack.parent_path() / "level";
        XMLMerger2::SerializeLevelEntityIDs(levelFolderPath);
    }
}

void ChairMerger::SetDeployStep(DeployStep step)
{
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    m_DeployStep = step;
}

void ChairMerger::SetDeployPhase(DeployPhase phase)
{
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    m_DeployPhase = phase;
}

void ChairMerger::SetDeployFailed(std::string error)
{
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    m_bDeployFailed = true;
    m_DeployError = error;
}

void ChairMerger::ClearDeployFailed()
{
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    m_bDeployFailed = false;
    m_DeployError.clear();
}

std::string ChairMerger::GetDeployFailedMessage()
{
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    return m_DeployError;
}

void ChairMerger::LoadIdNameMap()
{
    //    // profile this function to see if it's slow
    //    auto start = std::chrono::high_resolution_clock::now();

    m_NameToIdMap = Manager::NameToIdMap::Create(Manager::NameToIdMap::LIBRARY_FILE_NAME, m_PreyFilePath);

    //    auto end = std::chrono::high_resolution_clock::now();
    //    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    //    ChairManager::Get().log(severityLevel::trace, "ChairMerger: Loaded id name map in %llu milliseconds",
    //    elapsed.count());
    // TODO: Load from mods
}

int ChairMerger::Random(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(m_RandomGenerator);
}

float ChairMerger::RandomFloat(float min, float max)
{
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(m_RandomGenerator);
}

void ChairMerger::AddPendingTask(std::future<void>&& future)
{
    m_PendingTasks.emplace_back(std::move(future));
}

void ChairMerger::WaitForPendingTasks()
{
    m_MergeThreadPool->wait();
    std::vector<std::string> messages;

    for (auto& task : m_PendingTasks)
    {
        // Using exceptions in this way is generally bad but I see no other way here
        try
        {
            task.get();
        }
        catch (const std::exception& e)
        {
            messages.push_back(e.what());
        }
    }

    m_PendingTasks.clear();

    if (!messages.empty())
    {
        throw ChairMergerException(GetDeployStep(), GetDeployPhase(), std::move(messages));
    }
}
