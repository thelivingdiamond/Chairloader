#pragma once
#include "Merging/Sources/DirectoryAssetMergeSource.h"

namespace Assets
{

class AssetSystem;

//! Merge source for the project's assets.
class ProjectMergeSource : public DirectoryAssetMergeSource
{
public:
    ProjectMergeSource(const fs::path& rootDirectory);
    ~ProjectMergeSource();

protected:
    // DirectoryAssetMergeSource
    virtual bool CheckFile(const std::string& relPath, const fs::path& fullPath) override;
    virtual FileModTime GetMetaModTime(const std::string& relPath, const fs::path& fullPath) override;

private:
    AssetSystem* m_pSys = nullptr;
};

} // namespace Assets
