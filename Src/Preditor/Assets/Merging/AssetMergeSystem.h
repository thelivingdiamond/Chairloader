#pragma once

class FileMergingPolicy3;
class MergingLibrary3;
class XmlTypeLibrary;

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

    //! @returns XML Type Library.
    const XmlTypeLibrary& GetTypeLibrary() const { return *m_pXmlTypeLibrary; }

    //! @returns Merging Library.
    const MergingLibrary3& GetMergingLibrary() const { return *m_pMergingLibrary; }

    //! @returns NameToIdMap
    const auto& GetNameToIdMap() const { return m_NameToIdMap; }

    //! Files that must always be merged (even if no mod modifies them).
    const std::set<std::string>& GetAlwaysMergeFiles() const { return m_AlwaysMergeFiles; }

    //! Remaps output file path if required.
    //! Level and localization files need to be placed into a different directory.
    std::string RemapOutputFile(const std::string& relPath);

private:
    static constexpr char CACHE_FILE_NAME[] = "MergeCache.xml";

    using MergerFactory = std::function<AssetMergerPtr()>;

    std::unique_ptr<XmlTypeLibrary> m_pXmlTypeLibrary;
    std::unique_ptr<MergingLibrary3> m_pMergingLibrary;
    std::map<std::string, uint64_t> m_NameToIdMap; //!< Maps Ark/Prey XML names to their IDs.
    std::map<std::string, MergerFactory> m_MergerFactories;
    std::set<std::string> m_AlwaysMergeFiles;

    //! @returns the merge cache path.
    fs::path GetCachePath();

    //! Fills m_AlwaysMergeFiles.
    void FillAlwaysMergeFiles();

    template <typename T, typename ...TArgs>
    void CreateNamedMergerFactory(const std::string& name, TArgs... args)
    {
        auto it = m_MergerFactories.find(name);

        if (it != m_MergerFactories.end())
            CryFatalError("AssetMergeSystem: Duplicate factory '{}'", name);

        auto f = [=]() -> AssetMergerPtr
        {
            return std::make_unique<T>(args...);
        };

        m_MergerFactories.insert({ name, f });
    }

    template <typename T, typename ...TArgs>
    void CreateMergerFactory(TArgs... args)
    {
        CreateNamedMergerFactory<T>(T::NAME, args...);
    }
};

} // namespace Assets
