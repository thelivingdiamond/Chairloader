#pragma once
#include "AssetsCommon.h"

namespace Assets
{

class AssetMergeSource;

//! Contains the merging state (files and configs).
//! A new cache is generated on every merge and compared with the last one.
//! Only files that were changed are merged.
class MergeCache
{
public:
    struct SourceFile
    {
        //! Name of the merge source.
        std::string source;

        //! Source file modification time.
        FileModTime modTime = FileModTime();

        //! Metadata file modification time (if any).
        FileModTime metaModTime = FileModTime();

        bool operator==(const SourceFile& other) const
        {
            return
                source == other.source &&
                modTime == other.modTime &&
                metaModTime == other.metaModTime;
        }

        bool operator!=(const SourceFile& other) const { return !(*this == other); }
    };

    struct OutFile
    {
        //! Name of the merger used for this file.
        std::string merger;

        //! List of source files.
        std::vector<SourceFile> sourceFiles;
    };
    
    // TODO 2023-07-04: Project mod config
    // TODO 2023-07-04: Other mod configs

    std::map<std::string, OutFile, std::less<>> files;

    MergeCache();
    ~MergeCache();

    //! Loads the cache from an XML file.
    void LoadXml(const fs::path& xmlPath);

    //! Saves the cache into an XML file.
    void SaveXml(const fs::path& xmlPath) const;
};

} // namespace Assets
