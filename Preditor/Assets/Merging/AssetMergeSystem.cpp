#include <Manager/MergingPolicy.h>
#include "Mergers/SymlinkAssetMerger.h"
#include "Mergers/XmlAssetMerger.h"
#include "Merging/AssetMergeExecutor.h"
#include "Merging/AssetMergeSystem.h"
#include "Merging/MergeCache.h"
#include "AssetsCommon.h"

Assets::AssetMergeSystem::AssetMergeSystem()
{
    fs::path mergingLibPath = gPreditor->pConfig->GetPreditorRoot() / MERGING_LIBRARY_FILE_NAME;
    
    if (!m_MergingPolicyDoc.load_file(mergingLibPath.c_str()))
    {
        CryFatalError("[AssetMergeSystem] Failed to open {}", MERGING_LIBRARY_FILE_NAME);
    }

    CreateMergerFactory<SymlinkAssetMerger>();
    CreateMergerFactory<XmlAssetMerger>(this);
}

Assets::AssetMergeSystem::~AssetMergeSystem()
{
}

void Assets::AssetMergeSystem::InvalidateCache()
{
    fs::path cachePath = GetCachePath();

    if (fs::exists(cachePath))
        fs::remove(cachePath);
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
    if (EndsWith(fileRelPath, ".xml"))
        return "xml";

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

MergingPolicy Assets::AssetMergeSystem::FindMergingPolicy(const std::string& relPath) const
{
    MergingPolicy policy = MergingPolicy::FindMergingPolicy(m_MergingPolicyDoc, fs::u8path(relPath), gPreditor->pConfig->GetPreyFiles());

    if (policy.policy == MergingPolicy::identification_policy::unknown)
        CryError("[Merging] File {} not found in merging library", relPath);

    return policy;
}

fs::path Assets::AssetMergeSystem::GetCachePath()
{
    return gPreditor->pPaths->GetUserPath() / CACHE_FILE_NAME;
}