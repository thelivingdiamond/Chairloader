#include <Manager/IChairManager.h>
#include <Manager/ModListConfig.h>
#include <Manager/WildcardResolver.h>
#include <Manager/ModConfig.h>
#include "Merging/Mergers/AssetMerger.h"
#include "Merging/Sources/ChairloaderMergeSource.h"
#include "Merging/Sources/ImportMergeSource.h"
#include "Merging/Sources/ModMergeSource.h"
#include "Merging/Sources/ProjectMergeSource.h"
#include "Merging/AssetMergeExecutor.h"
#include "Merging/AssetMergeSystem.h"
#include "Merging/MergeCache.h"
#include "CMAdapter.h"

namespace
{

//! Checks if two XML nodes are equal.
bool XmlNodesAreEqual(pugi::xml_node lhs, pugi::xml_node rhs)
{
    // Compare names
    if (strcmp(lhs.name(), rhs.name()))
    {
        // Non-equal names
        return false;
    }

    // Compare text
    if (strcmp(lhs.text().as_string(), rhs.text().as_string()))
    {
        // Non-equal contents
        return false;
    }

    // Compare attributes
    {
        auto attrl = lhs.attributes();
        auto attrr = rhs.attributes();
        auto itl = attrl.begin();
        auto itr = attrr.begin();

        for (;;)
        {
            if (itl == attrl.end() && itr == attrr.end())
            {
                // Equal size and contents
                break;
            }
            else if (itl == attrl.end() || itr == attrr.end())
            {
                // One attr list is shorter
                return false;
            }

            assert(itl != attrl.end() && itr != attrr.end());

            // Compare attr contents
            if (strcmp(itl->name(), itr->name()))
            {
                // Non-equal names
                return false;
            }

            if (strcmp(itl->as_string(), itr->as_string()))
            {
                // Non-equal values
                return false;
            }

            ++itl;
            ++itr;
        }
    }

    // Compare children
    {
        auto childrenl = lhs.children();
        auto childrenr = rhs.children();
        auto itl = childrenl.begin();
        auto itr = childrenr.begin();

        for (;;)
        {
            if (itl == childrenl.end() && itr == childrenr.end())
            {
                // Equal size and contents
                break;
            }
            else if (itl == childrenl.end() || itr == childrenr.end())
            {
                // One child list is shorter
                return false;
            }

            assert(itl != childrenl.end() && itr != childrenr.end());

            if (!XmlNodesAreEqual(*itl, *itr))
            {
                // Non-equal children
                return false;
            }

            ++itl;
            ++itr;
        }
    }

    // All checks passed
    return true;
}

} // namespace

class Assets::AssetMergeExecutor::ModSystem final : public IChairManager
{
public:
    ModSystem()
    {
        LoadModList();
        LoadEnabledModConfigs();
    }

    //! @returns the list of all mods in the config.
    const auto& GetMods() { return m_ModList.mods; }

    //! @returns the map of mod names and configs.
    const auto& GetModConfigs() { return m_ModConfigs; }

    //! @returns config for a mod or nullptr.
    ModConfig* FindConfig(const std::string& modName)
    {
        auto it = m_ModConfigs.find(modName);

        if (it != m_ModConfigs.end())
            return &it->second;
        else
            return nullptr;
    }

    // IChairManager
    virtual fs::path GetConfigPath() override
    {
        return gPreditor->pPaths->GetModsPath() / "config";
    }

    virtual fs::path GetModPath(const std::string& modName) override
    {
        for (const auto& i : m_ModList.mods)
        {
            if (i.modName == modName)
            {
                if (!i.fullPath.empty())
                    return i.fullPath;
                else
                    return gPreditor->pPaths->GetModsPath() / fs::u8path(modName);
            }
        }

        throw std::logic_error(fmt::format("Mod not found: {}", modName));
    }

    virtual std::vector<std::string> GetModNames() override { throw std::logic_error("Not Implemented"); }

    virtual std::string GetModDisplayName(const std::string& modName) override { throw std::logic_error("Not Implemented"); }

    virtual bool IsModEnabled(const std::string& modName) override
    {
        for (const auto& i : m_ModList.mods)
        {
            if (i.modName == modName)
            {
                return i.enabled;
            }
        }

        return false;
    }

    virtual void LogString(severityLevel level, std::string_view str) override
    {
        CMAdapter::LogString(level, str);
    }

private:
    Manager::ModListConfig m_ModList;
    std::map<std::string, ModConfig> m_ModConfigs;

    void LoadModList()
    {
        fs::path chairConfigPath = GetConfigPath() / "Chairloader.xml";
        pugi::xml_document chairConfig;

        if (!chairConfig.load_file(chairConfigPath.c_str()))
            throw std::runtime_error("Failed to load Chairloader config");

        m_ModList.LoadXml(chairConfig.first_child().child("ModList"));
    }

    void LoadEnabledModConfigs()
    {
        for (const auto& mod : GetMods())
        {
            if (!mod.enabled)
                continue;

            fs::path configPath = GetConfigPath() / fs::u8path(mod.modName + ".xml");

            // Skip mods without configs
            if (!fs::exists(configPath))
                continue;

            // Read the XML
            pugi::xml_document doc;
            auto result = doc.load_file(configPath.string().c_str());

            if (!result)
            {
                throw std::runtime_error(fmt::format(
                    "Failed to read mod config.\n"
                    "Path: {}\n"
                    "Offset: {}\n"
                    "{}",
                    configPath.u8string(), result.offset, result.description()
                ));
            }

            m_ModConfigs.emplace(mod.modName, ModConfig(mod.modName, doc, configPath));
        }
    }
};

Assets::AssetMergeExecutor::AssetMergeExecutor(AssetMergeSystem* pSys)
{
    m_pSys = pSys;
    m_Rng = std::mt19937(std::random_device()());
}

Assets::AssetMergeExecutor::~AssetMergeExecutor()
{
}

std::unique_ptr<WildcardResolver> Assets::AssetMergeExecutor::CreateWildcardResolver(const std::string& modName)
{
    auto wr = std::make_unique<WildcardResolver>(m_pModSystem.get(), m_Rng, modName);
    wr->AddIdNameMap(m_pSys->GetNameToIdMap());
    return wr;
}

void Assets::AssetMergeExecutor::Execute()
{
    InitModSystem();
    CreateMergeSources();
    CollectSourceFiles();
    
    MergeCache oldCache = m_pSys->LoadMergeCache();
    MergeCache newCache = CreateCache();

    FillMergeList(oldCache, newCache);

    if (m_FilesToMerge.empty() && m_FilesToRemove.empty())
    {
        // Early exit, don't overwrite the cache
        // (in case something was missed, in which case cache won't match the real state)
        CryLog("[Merging] Files are up to date, nothing to do");
        return;
    }

    RemoveOldFiles();
    MergeFiles(newCache);

    m_pSys->SaveMergeCache(newCache);
    CryLog("[Merging] Total merged files: {}", newCache.files.size());
}

void Assets::AssetMergeExecutor::InitModSystem()
{
    m_pModSystem = std::make_unique<ModSystem>();
}

void Assets::AssetMergeExecutor::CreateMergeSources()
{
    {
        auto pSource = std::make_unique<ChairloaderMergeSource>();
        InitMergeSource(pSource.get(), nullptr);
        m_Sources.push_back(std::move(pSource));
    }

    // Create sources for mods
    for (const auto& mod : m_pModSystem->GetMods())
    {
        if (!mod.enabled)
            continue;

        bool isProject = !mod.fullPath.empty() && fs::equivalent(mod.fullPath, gPreditor->pPaths->GetProjectDirPath());

        if (isProject)
        {
            if (!m_ProjectModName.empty())
                throw std::logic_error(fmt::format("Duplicate project mod? '{}' and '{}'", m_ProjectModName, mod.modName));

            m_ProjectModName = mod.modName;

            // Project assets
            const fs::path& assetsPath = gPreditor->pPaths->GetAssetPath();
            if (fs::exists(assetsPath))
            {
                auto pSource = std::make_unique<ProjectMergeSource>(mod.modName, assetsPath);
                InitMergeSource(pSource.get(), &mod);
                m_Sources.push_back(std::move(pSource));
            }

            // Imported project assets
            const fs::path& importedAssetsPath = gPreditor->pPaths->GetImportedAssetsPath();
            if (fs::exists(importedAssetsPath))
            {
                auto pSource = std::make_unique<ImportMergeSource>(mod.modName, importedAssetsPath);
                InitMergeSource(pSource.get(), &mod);
                m_Sources.push_back(std::move(pSource));
            }
        }
        else
        {
            fs::path modDirPath = mod.fullPath;

            if (modDirPath.empty())
                modDirPath = gPreditor->pPaths->GetModsPath() / fs::u8path(mod.modName);

            if (!fs::exists(modDirPath))
            {
                throw std::logic_error(fmt::format(
                    "Mod directory doesn't exist. Bug in the code?\n{}", modDirPath.u8string()
                ));
            }

            fs::path modDataPath = modDirPath / "Data";

            if (fs::exists(modDataPath))
            {
                auto pSource = std::make_unique<ModMergeSource>(mod.modName, modDataPath);
                InitMergeSource(pSource.get(), &mod);
                m_Sources.push_back(std::move(pSource));
            }
        }
    }

    if (m_ProjectModName.empty())
        throw std::logic_error("Project mod not found. Is it disabled?");

    for (auto& pSource : m_Sources)
    {
        // Map names to objects
        m_SourceNameMap.emplace(pSource->GetSourceName(), pSource.get());

        WildcardResolver* wr = pSource->GetWildcardResolver();

        if (wr)
        {
            // Load all mod configs
            for (const auto& [modName, modConfig] : m_pModSystem->GetModConfigs())
            {
                wr->AddModConfig(modConfig);
            }
        }
    }
}

void Assets::AssetMergeExecutor::InitMergeSource(AssetMergeSource* pSource, const Manager::ModListConfig::Item* modItem)
{
    pSource->Init(this);

    WildcardResolver* wr = pSource->GetWildcardResolver();

    // Add the mod config as global
    if (modItem && wr)
    {
        ModConfig* cfg = m_pModSystem->FindConfig(modItem->modName);
        if (cfg)
            wr->AddGlobalModConfig(*cfg);
    }
}

void Assets::AssetMergeExecutor::CollectSourceFiles()
{
    for (auto& pSource : m_Sources)
    {
        pSource->CollectFiles();

        if constexpr (ASSETS_DEBUG)
            CryLog("[Merging] Source {}: {} files", pSource->GetSourceName(), pSource->GetFiles().size());
    }
}

Assets::MergeCache Assets::AssetMergeExecutor::CreateCache()
{
    MergeCache cache;

    // Configs
    for (const auto& [modName, modConfig] : m_pModSystem->GetModConfigs())
    {
        pugi::xml_document configDoc;
        configDoc.append_copy(modConfig.configDoc->first_child());
        cache.modConfigs.emplace(modName, std::move(configDoc));
    }

    // Files
    for (auto& pSource : m_Sources)
    {
        for (const MergeFile& mergeFile : pSource->GetFiles())
        {
            // Find existing file
            auto it = cache.files.find(mergeFile.path);

            if (it == cache.files.end())
            {
                // Add new file entry
                it = cache.files.emplace(mergeFile.path, MergeCache::OutFile()).first;
                it->second.merger = m_pSys->GetMergerNameForFile(mergeFile.path);
            }

            // Add source file
            MergeCache::SourceFile sourceFile;
            sourceFile.source = pSource->GetSourceName();
            sourceFile.modTime = mergeFile.modTime;
            sourceFile.metaModTime = mergeFile.metaModTime;
            it->second.sourceFiles.emplace_back(std::move(sourceFile));
        }
    }

    return cache;
}

void Assets::AssetMergeExecutor::FillMergeList(const MergeCache& oldCache, const MergeCache& newCache)
{
    // TODO 2023-07-04: Check mod configs

    // List of sources that need to be fully merged
    std::set<std::string, std::less<>> invalidateSourceList;

    // Compare configs
    for (const auto& [modName, modConfig] : newCache.modConfigs)
    {
        bool needInvalidate = false;
        auto oldConfig = oldCache.modConfigs.find(modName);

        if (oldConfig == oldCache.modConfigs.end())
        {
            // Config added
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] New mod config: {}", modName);

            needInvalidate = true;
        }
        else
        {
            // Config exists in old cache
            // Compare them
            bool equalNodes = XmlNodesAreEqual(modConfig, oldConfig->second);

            if (!equalNodes)
            {
                if constexpr (ASSETS_DEBUG)
                    CryLog("[Merging] Config nodes changed: {}", modName);

                needInvalidate = true;
            }
        }

        if (needInvalidate)
        {
            bool isProject = m_ProjectModName == modName;

            if (isProject)
            {
                invalidateSourceList.insert(ProjectMergeSource::SOURCE_NAME);
                invalidateSourceList.insert(ImportMergeSource::SOURCE_NAME);

                if constexpr (ASSETS_DEBUG)
                {
                    CryLog("[Merging] Source invalidated: {}", ProjectMergeSource::SOURCE_NAME);
                    CryLog("[Merging] Source invalidated: {}", ImportMergeSource::SOURCE_NAME);
                }
            }
            else
            {
                std::string sourceName = fmt::format("mod.{}", modName);
                invalidateSourceList.insert(sourceName);

                if constexpr (ASSETS_DEBUG)
                    CryLog("[Merging] Source invalidated: {}", sourceName);
            }
        }
    }

    // Check new files
    for (const auto& [relPath, newFile] : newCache.files)
    {
        bool needMerging = false;
        auto oldIt = oldCache.files.find(relPath);

        if (oldIt == oldCache.files.end())
        {
            // New file
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] New file: {}", relPath);

            needMerging = true;
        }
        else
        {
            // Existing file
            const MergeCache::OutFile& oldFile = oldIt->second;

            if (!newFile.SelfEqualsTo(oldFile))
            {
                // Merger options changed
                if constexpr (ASSETS_DEBUG)
                    CryLog("[Merging] Merger changed: {}", relPath);

                needMerging = true;
            }
            else if (newFile.sourceFiles.size() != oldFile.sourceFiles.size())
            {
                // Source files added/removed
                if constexpr (ASSETS_DEBUG)
                    CryLog("[Merging] Source file list changed: {}", relPath);

                needMerging = true;
            }
            else
            {
                // Check source files
                for (size_t i = 0; i < newFile.sourceFiles.size(); i++)
                {
                    const MergeCache::SourceFile& newSource = newFile.sourceFiles[i];
                    const MergeCache::SourceFile& oldSource = oldFile.sourceFiles[i];
                    
                    if (newSource != oldSource)
                    {
                        // File changed
                        if constexpr (ASSETS_DEBUG)
                            CryLog("[Merging] Source file changed: {}", relPath);

                        needMerging = true;
                    }
                    else if (invalidateSourceList.find(newSource.source) != invalidateSourceList.end())
                    {
                        // Source invalidated
                        if constexpr (ASSETS_DEBUG)
                            CryLog("[Merging] Source file's source '{}' is invalidated: {}", newSource.source, relPath);

                        needMerging = true;
                    }
                }
            }
        }

        if (needMerging)
        {
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] Needs merging: {}", relPath);

            m_FilesToMerge.insert(relPath);
        }
    }

    // Check removed files
    for (const auto& [relPath, oldFile] : oldCache.files)
    {
        auto newIt = newCache.files.find(relPath);

        if (newIt == newCache.files.end())
        {
            // File was removed
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] Needs remove: {}", relPath);

            m_FilesToRemove.insert(relPath);
        }
    }
}

void Assets::AssetMergeExecutor::RemoveOldFiles()
{
    for (const std::string& relPath : m_FilesToRemove)
    {
        fs::path path = gPreditor->pPaths->GetMergedAssetsPath() / fs::u8path(relPath);

        if (fs::exists(path))
        {
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] Removing: {}", relPath);

            std::error_code ec;
            fs::remove(path, ec);

            if (ec)
                CryError("[ImportAssets] Failed to remove {}: {}", relPath, ec.message());
        }
        else
        {
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] Already removed: {}", relPath);
        }
    }
}

void Assets::AssetMergeExecutor::MergeFiles(const MergeCache& cache)
{
    fs::create_directory(gPreditor->pPaths->GetMergedAssetsRootPath());
    fs::create_directory(gPreditor->pPaths->GetMergedAssetsPath());

    for (const std::string& relPath : m_FilesToMerge)
    {
        const MergeCache::OutFile& file = cache.files.find(relPath)->second;

        if constexpr (ASSETS_DEBUG)
        {
            CryLog("[Merging] Merging: {} (merger = {})", relPath, file.merger);

            for (const MergeCache::SourceFile& src : file.sourceFiles)
            {
                CryLog("[Merging] - {}:{}", src.source, relPath);
            }
        }

        // Prepare file list
        std::vector<AssetMerger::InputFile> mergeInputFiles;

        for (const MergeCache::SourceFile& src : file.sourceFiles)
        {
            AssetMerger::InputFile inFile;
            inFile.pSource = m_SourceNameMap.find(src.source)->second;
            inFile.fullPath = inFile.pSource->GetRootDirectory() / fs::u8path(relPath);
            mergeInputFiles.emplace_back(std::move(inFile));
        }

        // Run merging
        auto pMerger = m_pSys->CreateMerger(file.merger);
        pMerger->MergeFiles(relPath, mergeInputFiles);
    }
}
