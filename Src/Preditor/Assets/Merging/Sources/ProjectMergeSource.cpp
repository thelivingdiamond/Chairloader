#include <ChairMerger/WildcardResolver.h>
#include "Merging/Sources/ProjectMergeSource.h"
#include "Merging/AssetMergeExecutor.h"
#include "AssetMetadata.h"
#include "AssetSystem.h"

Assets::ProjectMergeSource::ProjectMergeSource(const std::string& modName, const fs::path& rootDirectory)
    : DirectoryAssetMergeSource(SOURCE_NAME, rootDirectory)
{
    m_pSys = static_cast<AssetSystem*>(gPreditor->pAssetSystem);
    m_ModName = modName;
}

Assets::ProjectMergeSource::~ProjectMergeSource()
{
}

void Assets::ProjectMergeSource::Init(AssetMergeExecutor* pExec)
{
    DirectoryAssetMergeSource::Init(pExec);
    m_pWR = GetExec().CreateWildcardResolver(m_ModName);
    // Config will be loaded by AssetMergeExecutor
}

bool Assets::ProjectMergeSource::CheckFile(const std::string& relPath, const fs::path& fullPath)
{
    if (!DirectoryAssetMergeSource::CheckFile(relPath, fullPath))
        return false;

    // Skip metadata files
    if (EndsWith(relPath, ASSET_META_DOT_EXT))
        return false;

    AssetMetadata* pMeta = m_pSys->GetMetadata(relPath);

    // Merge normal files that don't have asset metadata
    if (!pMeta)
        return true;

    // Skip merge
    if (pMeta->skipMerge)
        return false;

    if (!pMeta->importerName.empty())
    {
        // Has an importer
        // Skip the source file
        if (!pMeta->mergeSourceFile)
            return false;
    }

    return true;
}

Assets::FileModTime Assets::ProjectMergeSource::GetMetaModTime(const std::string& relPath, const fs::path& fullPath)
{
    AssetMetadata* pMeta = m_pSys->GetMetadata(relPath);

    if (pMeta)
        return pMeta->metadataModTime;
    else
        return FileModTime();
}
