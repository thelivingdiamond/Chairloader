#include <ChairMerger/WildcardResolver.h>
#include "Merging/Sources/ImportMergeSource.h"
#include "Merging/AssetMergeExecutor.h"

Assets::ImportMergeSource::ImportMergeSource(const std::string& modName, const fs::path& rootDirectory)
    : DirectoryAssetMergeSource(SOURCE_NAME, rootDirectory)
{
    m_ModName = modName;
}

Assets::ImportMergeSource::~ImportMergeSource()
{
}

void Assets::ImportMergeSource::Init(AssetMergeExecutor* pExec)
{
    DirectoryAssetMergeSource::Init(pExec);
    m_pWR = GetExec().CreateWildcardResolver(m_ModName);
    // Config will be loaded by AssetMergeExecutor
}
