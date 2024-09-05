//
// Created by theli on 3/26/2023.
//

#include <regex>
#include <gtest/gtest.h>
#include <boost/algorithm/string.hpp>
#include <ChairMerger/ChairMerger.h>
#include <ChairMerger/LuaUtils.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/NameToIdMap.h>
#include <ChairMerger/WildcardResolver.h>
#include <ChairMerger/XmlFinalizer3.h>
#include <ChairMerger/XmlMerger3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>
#include <Manager/PreditorFiles.h>
#include <Manager/ILogger.h>
#include <Manager/IChairManager.h>
#include <Manager/ModConfig.h>
#include <ChairMerger/ZipUtils.h>
#include "Cache/DiskXmlCache.h"
#include "HashUtils.h"

// resolve static variable m_RandomGenerator
std::mt19937 ChairMerger::m_RandomGenerator;
std::map<std::string, uint64_t> ChairMerger::m_NameToIdMap;

static void PrintValidationResult(const XmlValidator::Result& result, ILogger* pLog)
{
    for (auto& error : result.errors)
    {
        // Path
        std::string path;
        for (auto it = error.path.crbegin(); it != error.path.crend(); ++it)
        {
            path += "> ";
            path += *it;
            path += " ";
        }

        // Attribute
        if (!error.attributeName.empty())
            path += fmt::format("| (attr = {})", error.attributeName);

        pLog->Log(severityLevel::warning, "%s", path);

        // Message
        pLog->Log(severityLevel::info, "    %s", error.message);
    }
}

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
    const fs::path& outputRoot,
    const fs::path& gamePath,
    ILogger* pLogger)
{
    m_pLog = pLogger;

    m_pLog->Log(severityLevel::debug, "ChairMerger: Initializing ChairMerger");
    m_pLog->Log(severityLevel::debug, "ChairMerger: ChairMerger Initialized");

    // ChairManager files
    if (!fs::exists(mergerFiles))
        throw std::invalid_argument("mergerFiles doesn't exists");

    if (!fs::exists(preyFiles))
        throw std::invalid_argument("preyFiles doesn't exists");

    m_MergerFilesPath = mergerFiles;
    m_PreyFilesPath = preyFiles;

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

    m_RandomGenerator = std::mt19937(std::random_device()());
    m_pOriginalFileCache = std::make_unique<DiskXmlCache>();
    m_pOriginalFileCache->SetRootDir(m_PreyFilesPath);

    m_pTypeLib = std::make_unique<XmlTypeLibrary>();
    m_pTypeLib->LoadTypesFromFile(m_MergerFilesPath / "XmlTypeLibrary.xml");

    fs::path mergingLibDir = m_MergerFilesPath / "MergingLibrary";
    fs::path mergingLibFile = m_MergerFilesPath / "MergingLibrary.xml";
    m_pMergingLibrary = std::make_unique<MergingLibrary3>(m_pTypeLib.get());

    if (fs::exists(mergingLibDir))
    {
        // Use directory if it exists. It contains the source files.
        m_pLog->Log(severityLevel::info, "Using merging library from directory");
        m_pMergingLibrary->LoadFromDir(mergingLibDir);
    }
    else if (fs::exists(mergingLibFile))
    {
        // Use file instead. It contains the combined contents of source dir.
        m_pMergingLibrary->LoadFromFile(mergingLibFile);
    }
    else
    {
        throw std::runtime_error("Merging library missing");
    }
}

ChairMerger::~ChairMerger()
{
}

void ChairMerger::SetMods(std::vector<Mod>&& mods)
{
    CRY_ASSERT_MESSAGE(m_Mods.empty(), "ChairMerger instance may only be used once");
    m_Mods = std::move(mods);

    // Init caches
    m_ModXmlCaches.resize(m_Mods.size());

    for (size_t i = 0; i < m_Mods.size(); i++)
    {
        m_ModXmlCaches[i] = std::make_unique<DiskXmlCache>();
        static_cast<DiskXmlCache*>(m_ModXmlCaches[i].get())->SetRootDir(m_Mods[i].dataPath);
    }
}

void ChairMerger::Deploy()
{
    try
    {
        ClearDeployFailed();
        auto now = std::chrono::high_resolution_clock::now();
        PreMerge();
        if (m_DeployState.GetData().failed)
            return;
        Merge();
        if (m_DeployState.GetData().failed)
            return;
        PostMerge();
        if (m_DeployState.GetData().failed)
            return;
        SetDeployPhase(DeployPhase::Done);
        SetDeployStep(DeployStep::Done);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - now);
        if (!m_DeployState.GetData().failed)
        {
            m_pLog->Log(severityLevel::info, "ChairMerger: Finished merging in %.1f seconds",
                                    elapsed.count() / 1000.0f);
        }
        else
        {
            m_pLog->Log(severityLevel::info, "ChairMerger: Merge failed, %d seconds",
                                    elapsed.count() / 1000.0f);
        }
    }
    catch (const ChairMergerException& e)
    {
        std::string errorMsg = e.what();
        m_pLog->Log(severityLevel::error, "Merging failed: %s", e.what());

        for (const std::string& msg : e.GetMessages())
        {
            m_pLog->Log(severityLevel::error, " - %s", msg.c_str());
            errorMsg.append("\n");
            errorMsg.append(msg);
        }

        SetDeployFailed(errorMsg);
    }
    catch (const std::exception& e)
    {
        std::string errorMsg = e.what();
        m_pLog->Log(severityLevel::error, "Merging failed: %s", e.what());
        SetDeployFailed(errorMsg);
    }
}

std::future<void> ChairMerger::DeployAsync()
{
    return std::async(std::launch::async, &ChairMerger::Deploy, this);
}

DeployStep ChairMerger::GetDeployStep() const
{
    auto lock = m_DeployState.GetScopedLock();
    return m_DeployState.GetData().step;
}

DeployPhase ChairMerger::GetDeployPhase() const
{
    auto lock = m_DeployState.GetScopedLock();
    return m_DeployState.GetData().phase;
}

bool ChairMerger::DeployFailed() const
{
    auto lock = m_DeployState.GetScopedLock();
    return m_DeployState.GetData().failed;
}

std::string ChairMerger::GetDeployFailedMessage() const
{
    auto lock = m_DeployState.GetScopedLock();
    return m_DeployState.GetData().error;
}

std::string ChairMerger::GetDeployPhaseString(DeployPhase phase)
{
    return m_DeployPhaseStrings.at(phase);
}

std::string ChairMerger::GetDeployStepString(DeployStep step)
{
    return m_DeployStepStrings.at(step);
}

void ChairMerger::RecursiveFileCopyNonXml(fs::path source, fs::path destination)
{
    if (fs::exists(source) && fs::is_directory(source))
    {
        for (auto& file : fs::recursive_directory_iterator(source))
        {
            if (fs::is_directory(file))
                continue;

            fs::path srcPath = file.path();
            fs::path relPath = srcPath.lexically_relative(source);

            if (m_pMergingLibrary->FindPolicyForFile(relPath))
                continue;

            m_pLog->Log(severityLevel::debug, "Copying non-XML file: %s", relPath.u8string());
            fs::path dstPath = destination / relPath;
            fs::create_directories(dstPath.parent_path());
            fs::copy_file(srcPath, dstPath, fs::copy_options::overwrite_existing);
        }
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
        m_pLog->OverlayLog(severityLevel::error, "Failed to clear output directory: %s",
                           std::string(e.what()));
        SetDeployFailed("Failed to clear output directory: " + std::string(e.what()));
        return;
    }

    // load the patch file checksums
    SetDeployStep(DeployStep::LoadingPatchChecksums);
    LoadPatchFileChecksums();
    LoadIdNameMap();
    if (m_DeployState.GetData().failed)
        return;
    auto end = std::chrono::high_resolution_clock::now();
    m_pLog->Log(severityLevel::debug, "Pre-Merge took %f seconds",
                            std::chrono::duration_cast<std::chrono::duration<double>>(end - now).count());
}

void ChairMerger::Merge()
{
    // profile merge task
    auto now = std::chrono::high_resolution_clock::now();
    if (m_Settings.m_bForceVanillaPack)
        return;

    SetDeployPhase(DeployPhase::Merge);
    SetDeployStep(DeployStep::MergingMods);

    m_pBaseFileCache = std::make_unique<DiskXmlCache>();
    m_pBaseFileCache->SetRootDir(m_PreyFilesPath);

    for (size_t i = 0; i < m_Mods.size(); i++)
    {
        ProcessMod(i);
        WaitForPendingTasks();
        m_pLog->Log(severityLevel::trace, "Finished merging mod: %s", m_Mods[i].modName);
    }

    FinalizeFiles();

    // Save files to disk
    m_pBaseFileCache->ExportModifiedFiles(m_OutputPath);
    m_pBaseFileCache.reset();

    auto end = std::chrono::high_resolution_clock::now();
    m_pLog->Log(severityLevel::debug, "Merge took %f seconds",
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
    if (m_DeployState.GetData().failed)
        return;
    SetDeployStep(DeployStep::PackingLocalizationPatches);
    PackLocalizationFiles();
    if (m_DeployState.GetData().failed)
        return;
    SetDeployStep(DeployStep::PackingMainPatch);
    PackMainPatch();
    if (m_DeployState.GetData().failed)
        return;
    SetDeployStep(DeployStep::CleaningUp);

    auto end = std::chrono::high_resolution_clock::now();
    m_pLog->Log(severityLevel::debug, "Post-Merge took %f seconds",
                            std::chrono::duration_cast<std::chrono::duration<double>>(end - now).count());
}

//! Function to resolve all attribute wildcards in an xml document
void ChairMerger::ResolveFileWildcards(const Mod& mod, pugi::xml_node docNode)
{
    if (mod.type != EModType::Native)
    {
        // Wildcards not supported by the mod
        return;
    }

    WildcardResolver::Callbacks callbacks;
    callbacks.fnIsModEnabled = [this](const std::string& modName)
    {
        for (const Mod& mod : m_Mods)
        {
            if (mod.modName == modName)
                return true;
        }

        return false;
    };

    WildcardResolver wr(m_pLog, callbacks, m_RandomGenerator, mod.modName);

    // add the config variables to the lua state
    for (const Mod& otherMod : m_Mods)
    {
        if (otherMod.config.first_child())
            wr.AddModConfig(otherMod.modName, otherMod.config.first_child());
    }

    // TODO: add local mod config variables in a way to ignore g.modName
    if (mod.config.first_child())
        wr.AddGlobalModConfig(mod.modName, mod.config.first_child());

    wr.AddIdNameMap(m_NameToIdMap);
    wr.ResolveDocumentWildcards(docNode);
}

void ChairMerger::CopyModDataFiles(fs::path sourcePath)
{
    AddPendingTask(
        m_MergeThreadPool->enqueue([this, sourcePath] { RecursiveFileCopyNonXml(sourcePath, m_OutputPath); }));
}

void ChairMerger::ProcessMod(size_t modIdx)
{
    m_pLog->Log(severityLevel::debug, "ChairMerger: Processing mod %s", m_Mods[modIdx].modName);

    // Copy all files from the mod's Data folder to the output folder
    CopyModDataFiles(m_Mods[modIdx].dataPath);

    // Merge all XML files from the mod's Data folder
    // The list may contain non-XML files
    std::vector<fs::path> fileList;
    m_ModXmlCaches[modIdx]->GetAllFileList(fileList);

    for (const fs::path& fileRelPath : fileList)
    {
        // Find the merging policy without checking the extension
        // Some XMLs have different extension (.adb, .mtl, ...)
        const FileMergingPolicy3* pFilePolicy = m_pMergingLibrary->FindPolicyForFile(fileRelPath);

        if (pFilePolicy)
        {
            m_pLog->Log(severityLevel::debug, "Merging XML file: %s", fileRelPath.u8string());
            AddPendingTask(m_MergeThreadPool->enqueue([this, fileRelPath, modIdx, pFilePolicy] {
                ProcessXMLFile(m_Mods[modIdx], m_ModXmlCaches[modIdx].get(), fileRelPath, *pFilePolicy);
            }));
        }
        else if (fileRelPath.extension() == ".xml")
        {
            m_pLog->Log(severityLevel::error, "XML file not found in merging policy: %s", fileRelPath.u8string());
        }
    }
}

void ChairMerger::ProcessXMLFile(
    const Mod& mod,
    IXmlCache* pModXmlCache,
    const fs::path& relativePath,
    const FileMergingPolicy3& fileMergingPolicy)
{
    try
    {
        if (mod.type == EModType::Legacy)
            throw std::logic_error("Legacy mods are not supported yet");

        if (fileMergingPolicy.GetMethod() == FileMergingPolicy3::EMethod::ReadOnly)
            throw std::runtime_error("This file can't be modified by mods");

        auto parseTags = pugi::parse_default;

        if (fileMergingPolicy.GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
            parseTags = XmlMerger3::EXCEL_PARSE_OPTIONS;

        // now we have the relative path to the file, we can use this to find the original file, and the base file in the
        // output directory
        IXmlCache::WriteLock baseXmlLock;
        pugi::xml_document& baseDoc = m_pBaseFileCache->OpenXmlForWriting(relativePath, baseXmlLock, parseTags);

        pugi::xml_document modDoc;

        {
            // Make a copy of the cached document. It will be modified when resolving wildcards.
            IXmlCache::ReadLock modXmlLock;
            const pugi::xml_document& modDocFromCache = pModXmlCache->OpenXmlForReading(relativePath, modXmlLock, parseTags);
            modDoc.reset(modDocFromCache);
        }

        // resolve attribute wildcards on non legacy files
        ResolveFileWildcards(mod, modDoc.first_child());

        // if we have an original result, we can actually do some merging
        if (fileMergingPolicy.GetMethod() == FileMergingPolicy3::EMethod::Replace)
        {
            // Replace the entire file
            baseDoc = std::move(modDoc);
            return;
        }

        CRY_ASSERT(fileMergingPolicy.GetMethod() == FileMergingPolicy3::EMethod::Merge ||
            fileMergingPolicy.GetMethod() == FileMergingPolicy3::EMethod::Excel2003);

        // Validate mod file
        if (fileMergingPolicy.GetMethod() != FileMergingPolicy3::EMethod::Excel2003)
        {
            XmlValidator::Context valCtx;
            valCtx.pTypeLib = m_pTypeLib.get();
            valCtx.mode = XmlValidator::EMode::Mod;

            XmlValidator::Result result = XmlValidator::ValidateDocument(valCtx, modDoc, fileMergingPolicy);

            if (!result)
            {
                std::scoped_lock lock(m_LogMutex); // Prevent logs from multiple files overlapping
                m_pLog->Log(severityLevel::error, "Validation failure of mod file %s:%s", mod.modName, relativePath.u8string());
                PrintValidationResult(result, m_pLog);
                throw std::runtime_error("Mod file failed validation. Check the log for details.");
            }
        }

        XmlMergerContext context;
        context.modName = mod.modName;
        context.pTypeLib = m_pTypeLib.get();

        if (fileMergingPolicy.GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
        {
            XmlMerger3::MergeExcelDocument(context, baseDoc, modDoc, fileMergingPolicy);
        }
        else
        {
            XmlMerger3::MergeDocument(context, baseDoc, modDoc, fileMergingPolicy);
        }

        // Validate base file after merging
        if (fileMergingPolicy.GetMethod() != FileMergingPolicy3::EMethod::Excel2003)
        {
            XmlValidator::Context valCtx;
            valCtx.pTypeLib = m_pTypeLib.get();
            valCtx.mode = XmlValidator::EMode::MergingBase;

            XmlValidator::Result result = XmlValidator::ValidateDocument(valCtx, baseDoc, fileMergingPolicy);

            if (!result)
            {
                std::scoped_lock lock(m_LogMutex); // Prevent logs from multiple files overlapping
                m_pLog->Log(severityLevel::error, "Validation failure of base file after merging %s:%s", mod.modName, relativePath.u8string());
                PrintValidationResult(result, m_pLog);
                throw std::runtime_error("File failed validation after merging. Check the log for details.");
            }
        }

        // we are done
    }
    catch (const std::exception& e)
    {
        throw std::runtime_error(fmt::format(
            "{}\n    File: {}\n    Mod: {}",
            e.what(),
            relativePath.u8string(),
            mod.modName
        ));
    }
}

void ChairMerger::FinalizeFiles()
{
    std::vector<fs::path> fileList;
    m_pBaseFileCache->GetCachedFileList(fileList);

    for (const fs::path& relPath : fileList)
    {
        AddPendingTask(m_MergeThreadPool->enqueue([this, relPath] { FinalizeFile(relPath); }));
    }

    WaitForPendingTasks();
}

void ChairMerger::FinalizeFile(const fs::path& relPath)
{
    try
    {
        IXmlCache::WriteLock lock;
        pugi::xml_document& doc = m_pBaseFileCache->OpenXmlForWriting(relPath, lock, IXmlCache::DONT_PARSE, IXmlCache::DONT_FORMAT);

        const FileMergingPolicy3* pFilePolicy = m_pMergingLibrary->FindPolicyForFile(relPath);
        CRY_ASSERT(pFilePolicy);

        if (pFilePolicy->GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
        {
            // Localization files don't need finalization
            return;
        }

        XmlFinalizerContext context;
        XmlFinalizer3::FinalizeDocument(context, doc, *pFilePolicy);

        XmlValidator::Context valCtx;
        valCtx.pTypeLib = m_pTypeLib.get();
        valCtx.mode = XmlValidator::EMode::Prey;

        XmlValidator::Result result = XmlValidator::ValidateDocument(valCtx, doc, *pFilePolicy);

        if (!result)
        {
            std::scoped_lock lock(m_LogMutex); // Prevent logs from multiple files overlapping
            m_pLog->Log(severityLevel::error, "Validation failure of final file %s", relPath.u8string());
            PrintValidationResult(result, m_pLog);
            throw std::runtime_error("Game file failed validation after finalization. Check the log for details.");
        }
    }
    catch (const std::exception& e)
    {
        m_pLog->Log(severityLevel::error, "While finalizing file %s:\n%s", relPath.u8string(), e.what());
        throw;
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
        m_pLog->OverlayLog(severityLevel::error, "ChairMerger: Could not load patch checksums file");
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
            m_pLog->Log(severityLevel::error, "ChairMerger: Invalid patch checksum type %s", type);
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
            fs::path existingFile = m_LevelFilesPath / levelPack.first;

            if (!fs::exists(existingFile))
            {
                AddChangedLevelPack(levelPack.first);
                m_pLog->Log(severityLevel::trace, "ChairMerger: Level pack %s doesn't exist. Repacking.",
                    levelPack.first.string());
                return;
            }

            SHA256::Digest checksum;

            if (!HashUtils::HashUncompressedFile(existingFile, checksum))
            {
                AddChangedLevelPack(levelPack.first);
                m_pLog->Log(severityLevel::trace, "ChairMerger: Level pack %s failed to hash. Repacking.",
                    levelPack.first.string());
                return;
            }

            {
                std::lock_guard<std::mutex> lock(m_DeployedLevelFileChecksumsMutex);
                m_DeployedLevelFileChecksums[levelPack.first] = checksum;
            }

            if (checksum != levelPack.second || !fs::exists(existingFile) || m_Settings.m_bForceLevelPack)
            {
                AddChangedLevelPack(levelPack.first);
                m_pLog->Log(severityLevel::trace, "ChairMerger: Level pack %s has changed",
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

        if (!fs::exists(existingFile))
        {
            AddChangedLocalizationPack(localizationPack.first);
            m_pLog->Log(severityLevel::trace, "ChairMerger: Localization pack %s doesn't exist. Repacking.",
                localizationPack.first.string());
            continue;
        }

        SHA256::Digest checksum;
        if (!HashUtils::HashUncompressedFile(existingFile, checksum))
        {
            AddChangedLocalizationPack(localizationPack.first);
            m_pLog->Log(severityLevel::trace, "ChairMerger: Localization pack %s failed to hash. Repacking.",
                localizationPack.first.string());
            continue;
        }

        m_DeployedLocalizationFileChecksums[localizationPack.first] = checksum;

        if (checksum != localizationPack.second || !fs::exists(existingFile) || m_Settings.m_bForceLocalizationPack)
        {
            AddChangedLocalizationPack(localizationPack.first);
            m_pLog->Log(severityLevel::debug, "ChairMerger: Localization pack %s has changed",
                                    localizationPack.first.string());
        }
        else if (fs::exists(m_OutputPath / "Localization" / localizationPack.first.parent_path()))
        {
            AddChangedLocalizationPack(localizationPack.first);
        }
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
        m_pLog->Log(severityLevel::error, "ChairMerger: Could not clear level output directory");
        SetDeployFailed("Could not clear level output directory");
        return;
    }
    if (CheckLevelPacksChanged())
    {
        std::atomic<bool> bFailure = false;
        m_pLog->Log(severityLevel::debug, "ChairMerger: Level files have changed, repacking");
        // level files have changed, repack the level files, we just need to check which ones are changed
        for (auto& changedPack : m_ChangedLevelPacks)
        {
            // this is a relative path to the level pack, we need to remove the filename so we can find the level
            // directory
            const auto levelPath = changedPack.parent_path();
            const auto deployedHash = m_DeployedLevelFileChecksums[changedPack];
            const bool forcePack = m_Settings.m_bForceLevelPack;
            AddPendingTask(m_MergeThreadPool->enqueue([this, levelPath, deployedHash, forcePack, &bFailure] {
                try
                {
                    // create the level directory in the level output path
                    fs::create_directories(m_LevelOutputPath / levelPath);
                }
                catch (fs::filesystem_error& e)
                {
                    m_pLog->Log(severityLevel::error, "ChairMerger: Could not create level directory %s",
                                            (m_LevelOutputPath / levelPath).string());
                    bFailure = true;
                    return;
                }
                try
                {
                    // copy over the level directory to the level output path
                    fs::copy(m_PreyFilesPath / "Levels" / levelPath, m_LevelOutputPath / levelPath,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                }
                catch (fs::filesystem_error& e)
                {
                    m_pLog->Log(severityLevel::error,
                                            "ChairMerger: Could not copy original level directory %s",
                                            (m_PreyFilesPath / "Levels" / levelPath).string());
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
                    m_pLog->Log(
                        severityLevel::debug,
                        "ChairMerger: Could not copy level output directory %s, no mod modified this level.",
                        (m_OutputPath / "Levels" / levelPath).string());
                }

                // now check if we need to continue to pack the level directory
                auto levelPakHashPath = m_LevelOutputPath / levelPath / "level";
                auto levelOutputChecksum = HashUtils::HashDirectory(levelPakHashPath);
                if (levelOutputChecksum == deployedHash && !forcePack)
                {
                    // the level directory has not changed, we can skip packing it
                    m_pLog->Log(severityLevel::info, "ChairMerger: Level %s is up to date, skipping",
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
                        m_pLog->Log(severityLevel::error,
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
                    m_pLog->Log(severityLevel::error, "ChairMerger: Could not pack level directory %s",
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
                    m_pLog->Log(severityLevel::error, "ChairMerger: Could not remove level directory %s",
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
                    m_pLog->Log(severityLevel::error, "ChairMerger: Could not copy merged level pack %s",
                                            (m_LevelOutputPath / levelPath).string());
                    bFailure = true;
                    return;
                }
                m_pLog->Log(severityLevel::trace, "ChairMerger: Finished merging level pack %s",
                                        levelPath.string());
            }));
        }
        WaitForPendingTasks();
        if (bFailure)
        {
            SetDeployFailed("Error merging level packs");
            return;
        }
        m_pLog->Log(severityLevel::trace, "ChairMerger: Finished merging all level packs");
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
        m_pLog->Log(severityLevel::error, "ChairMerger: Could not clear localization output directory");
        return;
    }
    if (CheckLocalizationPacksChanged())
    {
        std::atomic<bool> bFailure = false;
        m_pLog->Log(severityLevel::debug, "ChairMerger: Localization files have changed, repacking");
        // localization files have changed, repack the localization files, we just need to check which ones are changed
        for (auto& changedPack : m_ChangedLocalizationPacks)
        {
            // this is a relative path to the localization pack, we need to remove the filename so we can find the
            // localization directory
            const auto localizationPath = changedPack.parent_path();
            const auto deployedLocalizationChecksum = m_DeployedLocalizationFileChecksums[changedPack];
            const bool forcePack = m_Settings.m_bForceLocalizationPack;
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
                    m_pLog->Log(severityLevel::error,
                                            "ChairMerger: Could not create localization output directory %s",
                                            (m_LocalizationOutputPath / localizationPath).string());
                    bFailure = true;
                    return;
                }
                try
                {
                    // copy over the vanilla localization patch files to the localization output path
                    fs::copy(m_PreyFilesPath / "Localization" / originalDirectoryPath,
                             m_LocalizationOutputPath / originalDirectoryPath,
                             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                }
                catch (fs::filesystem_error& e)
                {
                    m_pLog->Log(severityLevel::error,
                                            "ChairMerger: Could not copy original localization patch %s",
                                            (m_PreyFilesPath / "Localization" / originalDirectoryPath).string());
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
                    m_pLog->Log(
                        severityLevel::debug,
                        "ChairMerger: Could not copy localization output directory %s, no mod modified this pack.",
                        (m_OutputPath / "localization" / originalDirectoryPath).string());
                }
                // now check if we need to continue to pack the level directory
                auto levelOutputChecksum = HashUtils::HashDirectory(m_LocalizationOutputPath / originalDirectoryPath);
                if (levelOutputChecksum == deployedLocalizationChecksum && !forcePack)
                {
                    m_pLog->Log(severityLevel::info,
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
                        m_pLog->Log(
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
                    m_pLog->Log(severityLevel::error,
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
                    m_pLog->Log(severityLevel::error,
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
                    m_pLog->Log(severityLevel::error,
                                            "ChairMerger: Could not copy merged localization pack %s",
                                            (m_LocalizationOutputPath / localizationPath).string());
                    bFailure = true;
                }
            }));
        }
        WaitForPendingTasks();
        m_pLog->Log(severityLevel::trace, "ChairMerger: Finished merging localization packs");
    }
}

void ChairMerger::PackMainPatch()
{
    // at this point level and localization packs are packed and their files moved. We can now pack what is left in the
    // output path
    fs::path chairPakPath = m_PrecacheFilesPath / "patch_chairloader.pak";

    if (fs::exists(chairPakPath))
    {
        if (!m_Settings.m_bForceMainPatchPack)
        {
            SHA256::Digest deployedFileHash;

            if (!HashUtils::HashUncompressedFile(chairPakPath, deployedFileHash))
                throw std::runtime_error(fmt::format("Failed to hash {}", chairPakPath.u8string()));

            SHA256::Digest outputFileHash = HashUtils::HashDirectory(m_OutputPath);

            if (deployedFileHash == outputFileHash)
            {
                m_pLog->Log(severityLevel::info, "ChairMerger: Main patch is up to date, skipping");
                return;
            }
        }

        try
        {
            fs::remove(chairPakPath);
        }
        catch (fs::filesystem_error& e)
        {
            m_pLog->Log(severityLevel::error, "ChairMerger: Could not remove old patch file: %s", e.what());
            SetDeployFailed("Could not remove old patch file: " + std::string(e.what()));
            return;
        }
    }

    std::ofstream(m_OutputPath / MARK_OF_THE_CHAIR).close();
    ZipUtils::CompressFolder(m_OutputPath, chairPakPath, true);
    m_pLog->Log(severityLevel::trace, "ChairMerger: Finished packing main patch");
}

void ChairMerger::SetDeployStep(DeployStep step)
{
    auto lock = m_DeployState.GetScopedLock();
    m_DeployState.GetData().step = step;
}

void ChairMerger::SetDeployPhase(DeployPhase phase)
{
    auto lock = m_DeployState.GetScopedLock();
    m_DeployState.GetData().phase = phase;
}

void ChairMerger::SetDeployFailed(std::string error)
{
    auto lock = m_DeployState.GetScopedLock();
    m_DeployState.GetData().failed = true;
    m_DeployState.GetData().error = error;
}

void ChairMerger::ClearDeployFailed()
{
    auto lock = m_DeployState.GetScopedLock();
    m_DeployState.GetData().failed = false;
    m_DeployState.GetData().error.clear();
}

void ChairMerger::LoadIdNameMap()
{
    //    // profile this function to see if it's slow
    //    auto start = std::chrono::high_resolution_clock::now();

    m_NameToIdMap = Manager::NameToIdMap::Create(Manager::NameToIdMap::LIBRARY_FILE_NAME, m_PreyFilesPath);

    //    auto end = std::chrono::high_resolution_clock::now();
    //    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    //    m_pLog->Log(severityLevel::trace, "ChairMerger: Loaded id name map in %llu milliseconds",
    //    elapsed.count());
    // TODO: Load from mods
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
