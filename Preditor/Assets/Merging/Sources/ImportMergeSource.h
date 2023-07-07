#pragma once
#include "Merging/Sources/DirectoryAssetMergeSource.h"

namespace Assets
{

class AssetSystem;

//! Merge source for the project's imported assets.
class ImportMergeSource : public DirectoryAssetMergeSource
{
public:
    static constexpr char SOURCE_NAME[] = "project.import";

    ImportMergeSource(const std::string& modName, const fs::path& rootDirectory);
    ~ImportMergeSource();

protected:
    // DirectoryAssetMergeSource
    virtual WildcardResolver* GetWildcardResolver() const { return m_pWR.get(); }
    virtual void Init(AssetMergeExecutor* pExec);

private:
    std::string m_ModName;
    std::unique_ptr<WildcardResolver> m_pWR;
};

} // namespace Assets
