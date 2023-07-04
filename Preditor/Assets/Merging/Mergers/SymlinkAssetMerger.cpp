#include "Merging/Mergers/SymlinkAssetMerger.h"
#include "Merging/Sources/AssetMergeSource.h"

Assets::SymlinkAssetMerger::SymlinkAssetMerger()
{
}

Assets::SymlinkAssetMerger::~SymlinkAssetMerger()
{
}

void Assets::SymlinkAssetMerger::DoMerge(const std::vector<InputFile>& inputFiles)
{
    // Symlink to the last file
    const InputFile& srcFile = *inputFiles.rbegin();

    if constexpr (ASSETS_DEBUG)
    {
        CryLog("[SymlinkAssetMerger] {}: link from {} ({})", GetRelPath(),
            srcFile.pSource->GetSourceName(), srcFile.fullPath.u8string());
    }

    fs::create_symlink(srcFile.fullPath, GetOutputFilePath());
}
