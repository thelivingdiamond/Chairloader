#pragma once

namespace Assets
{

class AssetMerger;
class MergeCache;

class AssetMergeSystem : NoCopy
{
public:
    using AssetMergerPtr = std::unique_ptr<AssetMerger>;

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

    //! Creates an asset merger by its name.
    //! Throws if merger is not found.
    AssetMergerPtr CreateMerger(const std::string& name);

private:
    static constexpr char CACHE_FILE_NAME[] = "MergeCache.xml";

    using MergerFactory = std::function<AssetMergerPtr()>;

    std::map<std::string, MergerFactory> m_MergerFactories;

    //! @returns the merge cache path.
    fs::path GetCachePath();

    template <typename T>
    void CreateMergerFactory(const std::string& name)
    {
        auto it = m_MergerFactories.find(name);

        if (it != m_MergerFactories.end())
            CryFatalError("AssetMergeSystem: Duplicate factory '{}'", name);

        auto f = []() -> AssetMergerPtr
        {
            return std::make_unique<T>();
        };

        m_MergerFactories.insert({ name, f });
    }

    template <typename T>
    void CreateMergerFactory()
    {
        CreateMergerFactory<T>(T::NAME);
    }
};

} // namespace Assets
