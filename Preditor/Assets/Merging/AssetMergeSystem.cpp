#include "Merging/AssetMergeExecutor.h"
#include "Merging/AssetMergeSystem.h"
#include "Merging/MergeCache.h"
#include "AssetsCommon.h"

Assets::AssetMergeSystem::AssetMergeSystem()
{
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

fs::path Assets::AssetMergeSystem::GetCachePath()
{
    return gPreditor->pPaths->GetUserPath() / CACHE_FILE_NAME;
}
