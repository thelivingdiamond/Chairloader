#pragma once
#include "Merging/Sources/AssetMergeSource.h"

namespace Assets
{

//! Lists all files from a directory.
class DirectoryAssetMergeSource : public AssetMergeSource
{
public:
    DirectoryAssetMergeSource(std::string_view sourceName, const fs::path& rootDirectory);
    ~DirectoryAssetMergeSource();

    // AssetMergeSource
    virtual void CollectFiles() override;

protected:
    //! Checks if the file needs to be added.
    //! @returns true if needs to be added.
    virtual bool CheckFile(const std::string& relPath, const fs::path& fullPath)
    {
        // Derived classes can override this.
        return true;
    }

    //! @returns metadata mod time for the file.
    virtual FileModTime GetMetaModTime(const std::string& relPath, const fs::path& fullPath);

private:
    void RecursiveFindFiles(const std::string& path);
};

} // namespace Assets
