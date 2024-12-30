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

    CreateMergerFactory<SymlinkAssetMerger>();
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

fs::path Assets::AssetMergeSystem::GetCachePath()
{
    return gPreditor->pPaths->GetUserPath() / CACHE_FILE_NAME;
}
