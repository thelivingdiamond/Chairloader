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

    SymlinkAssetMerger(AssetMergeSystem* pSys);
    ~SymlinkAssetMerger();

protected:
    // AssetMerger
    virtual void DoMerge(const std::vector<InputFile>& inputFiles) override;

private:
    // On Windows, symlinks require special permissions.
    // Switch to copying on failure.
    static bool m_CopyInstead;

    bool TrySymlink(const fs::path& src, const fs::path& dst);
    bool TryCopy(const fs::path& src, const fs::path& dst);
};

} // namespace Assets
