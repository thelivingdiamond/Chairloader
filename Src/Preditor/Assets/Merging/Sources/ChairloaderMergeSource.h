#pragma once
#include "Merging/Sources/DirectoryAssetMergeSource.h"

namespace Assets
{

class AssetSystem;

//! Merge source for ChairloaderPatch.
class ChairloaderMergeSource : public DirectoryAssetMergeSource
{
public:
    ChairloaderMergeSource();
    ~ChairloaderMergeSource();
};

} // namespace Assets
