#pragma once
#include <random>
#include <Manager/ModListConfig.h>
#include "Merging/Sources/AssetMergeSource.h"

class WildcardResolver;

namespace Assets
{

class AssetMergeSystem;
class MergeCache;

//! Executes actual merging. Constructed as a temporary object.
class AssetMergeExecutor : NoCopy
{
public:
    AssetMergeExecutor(AssetMergeSystem* pSys);
    ~AssetMergeExecutor();

    //! Creates and initializes a wildcard resolver for merge sources.
    std::unique_ptr<WildcardResolver> CreateWildcardResolver(const std::string& modName);

    void Execute();

private:
    class ModSystem;

    AssetMergeSystem* m_pSys = nullptr;
    std::unique_ptr<ModSystem> m_pModSystem;
    std::mt19937 m_Rng;

    //! Merge sources. Sorted in mod config order.
    //! Files from last sources override files from first sources.
    std::vector<std::unique_ptr<AssetMergeSource>> m_Sources;
    std::map<std::string, AssetMergeSource*, std::less<>> m_SourceNameMap;

    //! Set of files that need to be merged.
    std::set<std::string> m_FilesToMerge;

    //! Set of files that need to be removed (no longer exist in the new cache).
    std::set<std::string> m_FilesToRemove;

    //! Initializes ModSystem.
    void InitModSystem();

    //! Creates merge sources for the project and enabled mods.
    void CreateMergeSources();

    //! Initializes a merge source after it was created.
    void InitMergeSource(AssetMergeSource* pSource, const Manager::ModListConfig::Item* modItem);

    //! Collects files in the merge sources.
    void CollectSourceFiles();

    //! Creates a new cache instance.
    MergeCache CreateCache();

    //! Fills m_FilesToMerge and m_FilesToRemove.
    void FillMergeList(const MergeCache& oldCache, const MergeCache& newCache);

    //! Removes the files in m_FilesToRemove from disk.
    void RemoveOldFiles();

    //! Merges the files in m_FilesToMerge.
    void MergeFiles(const MergeCache& cache);
};

} // namespace Assets
