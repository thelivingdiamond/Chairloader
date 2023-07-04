#pragma once
#include "AssetsCommon.h"

namespace Assets
{

//! File from a merge source.
struct MergeFile
{
    //! Relative path to the file. Lower case with forward slashes.
    std::string path;

    //! The time at which the file was last modified.
    FileModTime modTime = FileModTime();

    //! The time at which the file's metadata was last modified.
    FileModTime metaModTime = FileModTime();
};

//! Base class for asset merge sources (e.g. Preditor project, Chairloader mod, leagacy mod...).
//! Lists all files in the source that need to be merged.
//! Provides mod config for XML merging.
class AssetMergeSource : NoCopy
{
public:
    AssetMergeSource(std::string_view sourceName, const fs::path& rootDirectory);
    virtual ~AssetMergeSource();

    //! @returns the name of the merge source.
    const std::string& GetSourceName() const { return m_SourceName; }

    //! @returns the directory in which files are located.
    const fs::path& GetRootDirectory() const { return m_RootDirectory; }

    //! @returns the list of files in the merge source.
    const std::vector<MergeFile>& GetFiles() const { return m_Files; }

    //! Collects all files in the merge source.
    virtual void CollectFiles() = 0;

protected:
    //! Adds a file to the list.
    void AddFile(const MergeFile& file);

private:
    std::string m_SourceName;
    fs::path m_RootDirectory;
    std::vector<MergeFile> m_Files;

#ifdef ASSET_MERGE_DEBUG
    std::set<std::string> m_FileSet;
#endif
};

} // namespace Assets
