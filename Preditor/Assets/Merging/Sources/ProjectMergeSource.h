#pragma once
#include "Merging/Sources/DirectoryAssetMergeSource.h"

namespace Assets
{

class AssetSystem;

//! Merge source for the project's assets.
class ProjectMergeSource : public DirectoryAssetMergeSource
{
public:
    static constexpr char SOURCE_NAME[] = "project.assets";

    ProjectMergeSource(const std::string& modName, const fs::path& rootDirectory);
    ~ProjectMergeSource();

protected:
    // DirectoryAssetMergeSource
    virtual WildcardResolver* GetWildcardResolver() const { return m_pWR.get(); }
    virtual void Init(AssetMergeExecutor* pExec);
    virtual bool CheckFile(const std::string& relPath, const fs::path& fullPath) override;
    virtual FileModTime GetMetaModTime(const std::string& relPath, const fs::path& fullPath) override;

private:
    AssetSystem* m_pSys = nullptr;
    std::string m_ModName;
    std::unique_ptr<WildcardResolver> m_pWR;
};

} // namespace Assets
