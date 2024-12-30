#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/NameToIdMap.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include "Mergers/SymlinkAssetMerger.h"
#include "Mergers/XmlAssetMerger.h"
#include "Merging/AssetMergeExecutor.h"
#include "Merging/AssetMergeSystem.h"
#include "Merging/MergeCache.h"
#include "AssetsCommon.h"

//! Files that are stored in paks other than main patch.
//! They must always be merged to overwrite ChairManager paks.
constexpr const char* SEPARATE_PAK_FILES[] = {
    "levels/campaign/endgame/level",
    "levels/campaign/engineering/cargobay/level",
    "levels/campaign/engineering/lifesupport/level",
    "levels/campaign/engineering/powersource/level",
    "levels/campaign/executive/arboretum/level",
    "levels/campaign/executive/bridge/level",
    "levels/campaign/executive/corporateit/level",
    "levels/campaign/executive/crewfacilities/level",
    "levels/campaign/playergenderselect/level",
    "levels/campaign/research/lobby/level",
    "levels/campaign/research/prototype/level",
    "levels/campaign/research/psychotronics/level",
    "levels/campaign/research/shuttlebay/level",
    "levels/campaign/research/simulationlabs/level",
    "levels/campaign/research/zerog_utilitytunnels/level",
    "levels/campaign/station/exterior/level",
    "localization/english_xml",
};

Assets::AssetMergeSystem::AssetMergeSystem()
{
    try
    {
        fs::path typeLibPath = gPreditor->pConfig->GetPreditorRoot() / "XmlTypeLibrary.xml";
        CryLog("[AssetMergeSystem] Loading {}", typeLibPath.u8string());
        m_pXmlTypeLibrary = std::make_unique<XmlTypeLibrary>();
        m_pXmlTypeLibrary->LoadTypesFromFile(typeLibPath);
    }
    catch (const std::exception& e)
    {
        CryFatalError("[AssetMergeSystem] Failed to load XML Type Library:\n{}", e.what());
    }

    try
    {
        fs::path mergingLibDir = gPreditor->pConfig->GetPreditorRoot() / "MergingLibrary";
        fs::path mergingLibFile = gPreditor->pConfig->GetPreditorRoot() / "MergingLibrary.xml";
        m_pMergingLibrary = std::make_unique<MergingLibrary3>(m_pXmlTypeLibrary.get());

        if (fs::exists(mergingLibDir))
        {
            // Use directory if it exists. It contains the source files.
            CryLog("[AssetMergeSystem] Using merging library from directory {}", mergingLibDir.u8string());
            m_pMergingLibrary->LoadFromDir(mergingLibDir);
        }
        else if (fs::exists(mergingLibFile))
        {
            // Use file instead. It contains the combined contents of source dir.
            CryLog("[AssetMergeSystem] Using merging library from file {}", mergingLibFile.u8string());
            m_pMergingLibrary->LoadFromFile(mergingLibFile);
        }
        else
        {
            throw std::runtime_error("Merging library missing");
        }
    }
    catch (const std::exception& e)
    {
        CryFatalError("[AssetMergeSystem] Failed to load Merging Library:\n{}", e.what());
    }

    m_NameToIdMap = Manager::NameToIdMap::Create(
        gPreditor->pConfig->GetPreditorRoot() / Manager::NameToIdMap::LIBRARY_FILE_NAME,
        gPreditor->pConfig->GetPreyFiles()
    );

    FillAlwaysMergeFiles();

    CreateMergerFactory<SymlinkAssetMerger>(this);
    CreateMergerFactory<XmlAssetMerger>(this);
}

Assets::AssetMergeSystem::~AssetMergeSystem()
{
}

void Assets::AssetMergeSystem::InvalidateCache()
{
    fs::path cacheFilePath = GetCachePath();

    if (fs::exists(cacheFilePath))
        fs::remove(cacheFilePath);

    const fs::path& mergePath = gPreditor->pPaths->GetMergedAssetsPath();

    // Safety check
    if (!mergePath.is_absolute())
        throw std::logic_error("GetMergedAssetsPath is not absolute");

    if (fs::exists(mergePath))
    {
        // Remove merge contents
        for (const fs::directory_entry& i : fs::directory_iterator(mergePath))
        {
            std::error_code ec;
            fs::remove_all(i.path(), ec);

            if (ec)
                CryError("[Merge] Failed to remove {}: {}", i.path().u8string(), ec.message());
        }
    }
}

bool Assets::AssetMergeSystem::MergeAssets()
{
    try
    {
        AssetMergeExecutor executor(this);
        executor.Execute();
        return true;
    }
    catch (const std::exception& e)
    {
        CryError("[MergeAssets] Error: {}", e.what());
        return false;
    }
}

std::string_view Assets::AssetMergeSystem::GetMergerNameForFile(const std::string& fileRelPath)
{
    const FileMergingPolicy3* pPolicy = m_pMergingLibrary->FindPolicyForFile(fileRelPath);

    if (pPolicy)
        return "xml";
    else if (EndsWith(fileRelPath, ".xml"))
        CryError("[Merging] File {} not found in merging library", fileRelPath);

    // By default, symlink the last file
    return "symlink";
}

Assets::MergeCache Assets::AssetMergeSystem::LoadMergeCache()
{
    fs::path cachePath = GetCachePath();

    if (!fs::exists(cachePath))
        return MergeCache();

    try
    {
        MergeCache cache;
        cache.LoadXml(cachePath);
        return cache;
    }
    catch (const std::exception& e)
    {
        CryWarning("[AssetMergeSystem] Failed to load merge cache: {}", e.what());
        CryWarning("[AssetMergeSystem] Ignoring corrupted cache.");
        return MergeCache();
    }
}

void Assets::AssetMergeSystem::SaveMergeCache(const MergeCache& cache)
{
    fs::path cachePath = GetCachePath();
    cache.SaveXml(cachePath);
}

Assets::AssetMergeSystem::AssetMergerPtr Assets::AssetMergeSystem::CreateMerger(const std::string& name)
{
    auto it = m_MergerFactories.find(name);

    if (it == m_MergerFactories.end())
        throw std::runtime_error(fmt::format("Unknown merger '{}'", name));

    return it->second();
}

std::string Assets::AssetMergeSystem::RemapOutputFile(const std::string& relPath)
{
    if (StartsWith(relPath, "levels/"))
    {
        // relPath = "levels/..../[levelName]/level/..."
        // Need to remove /level/
        size_t pos = relPath.find("/level/");

        if (pos == std::string::npos)
            return relPath;

        return relPath.substr(0, pos) + relPath.substr(pos + 6);
    }

    if (StartsWith(relPath, "localization/english_xml"))
    {
        // relPath = "localization/english_xml/..."
        // Need to remove /english_xml/
        return "localization/" + relPath.substr(25);
    }

    return relPath;
}

fs::path Assets::AssetMergeSystem::GetCachePath()
{
    return gPreditor->pPaths->GetUserPath() / CACHE_FILE_NAME;
}

void Assets::AssetMergeSystem::FillAlwaysMergeFiles()
{
    fs::path root = gPreditor->pConfig->GetPreyFiles();

    for (const char* prefix : SEPARATE_PAK_FILES)
    {
        for (const fs::directory_entry dirEnt : fs::recursive_directory_iterator(root / fs::u8path(prefix)))
        {
            if (dirEnt.is_directory())
                continue;

            fs::path relPath = dirEnt.path().lexically_relative(root);
            std::string relPathStr = relPath.generic_u8string();
            StrToLower(relPathStr);
            m_AlwaysMergeFiles.insert(std::move(relPathStr));
        }
    }
}
