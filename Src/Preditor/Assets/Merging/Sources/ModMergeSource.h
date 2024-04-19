#pragma once
#include "Merging/Sources/DirectoryAssetMergeSource.h"

namespace Assets
{

class AssetSystem;

//! Merge source for ChairloaderPatch.
class ModMergeSource : public DirectoryAssetMergeSource
{
public:
    ModMergeSource(const std::string& modName, const fs::path& modDataDir);
    ~ModMergeSource();

    // DirectoryAssetMergeSource
    virtual WildcardResolver* GetWildcardResolver() const { return m_pWR.get(); }
    virtual void Init(AssetMergeExecutor* pExec);

private:
    std::string m_ModName;
    std::unique_ptr<WildcardResolver> m_pWR;
};

} // namespace Assets
