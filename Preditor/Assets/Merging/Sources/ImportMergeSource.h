#pragma once
#include "Merging/Sources/DirectoryAssetMergeSource.h"

namespace Assets
{

class AssetSystem;

//! Merge source for the project's imported assets.
class ImportMergeSource : public DirectoryAssetMergeSource
{
public:
    ImportMergeSource(const fs::path& rootDirectory);
    ~ImportMergeSource();
};

} // namespace Assets
