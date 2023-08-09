#pragma once
#include "Merging/Mergers/AssetMerger.h"

namespace Assets
{

class AssetMergeSource;

//! Takes a set of file from input sources and produces a single output file.
class SymlinkAssetMerger : public AssetMerger
{
public:
    static constexpr char NAME[] = "symlink";

    SymlinkAssetMerger();
    ~SymlinkAssetMerger();

protected:
    // AssetMerger
    virtual void DoMerge(const std::vector<InputFile>& inputFiles) override;
};

} // namespace Assets
