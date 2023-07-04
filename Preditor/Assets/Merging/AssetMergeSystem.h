#pragma once

namespace Assets
{

class MergeCache;

class AssetMergeSystem : NoCopy
{
public:
    AssetMergeSystem();
    ~AssetMergeSystem();

    //! Invalidates the cache. Causes all files to be merged again next time.
    void InvalidateCache();

    //! Merges assets from mods and the project.
    bool MergeAssets();

    //! @returns the merger to use for specified file.
    std::string_view GetMergerNameForFile(const std::string& fileRelPath);

    //! Loads the merge cache from disk.
    //! If doesn't exist, returns empty cache.
    MergeCache LoadMergeCache();

    //! Saves the cache onto disk.
    void SaveMergeCache(const MergeCache& cache);

private:
    static constexpr char CACHE_FILE_NAME[] = "MergeCache.xml";

    //! @returns the merge cache path.
    fs::path GetCachePath();
};

} // namespace Assets
