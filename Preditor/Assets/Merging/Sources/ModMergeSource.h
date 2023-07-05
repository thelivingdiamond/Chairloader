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
};

} // namespace Assets
