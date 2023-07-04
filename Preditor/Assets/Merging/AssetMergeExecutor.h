#pragma once
#include "Merging/Sources/AssetMergeSource.h"

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

    void Execute();

private:
    AssetMergeSystem* m_pSys = nullptr;

    //! Merge sources. Sorted in mod config order.
    //! Files from last sources override files from first sources.
    std::vector<std::unique_ptr<AssetMergeSource>> m_Sources;

    //! Set of files that need to be merged.
    std::set<std::string> m_FilesToMerge;

    //! Set of files that need to be removed (no longer exist in the new cache).
    std::set<std::string> m_FilesToRemove;

    //! Creates merge sources for the project and enabled mods.
    void CreateMergeSources();

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
