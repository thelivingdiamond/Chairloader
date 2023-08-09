#include <Manager/WildcardResolver.h>
#include "Merging/Sources/ModMergeSource.h"
#include "Merging/AssetMergeExecutor.h"

Assets::ModMergeSource::ModMergeSource(const std::string& modName, const fs::path& modDataDir)
    : DirectoryAssetMergeSource("mod." + modName, modDataDir)
{
    m_ModName = modName;
}

Assets::ModMergeSource::~ModMergeSource()
{
}

void Assets::ModMergeSource::Init(AssetMergeExecutor* pExec)
{
    DirectoryAssetMergeSource::Init(pExec);
    m_pWR = GetExec().CreateWildcardResolver(m_ModName);
    // Config will be loaded by AssetMergeExecutor
}
