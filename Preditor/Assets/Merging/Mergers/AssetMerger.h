#pragma once
#include "AssetsCommon.h"

namespace Assets
{

class AssetMergeSource;

//! Takes a set of file from input sources and produces a single output file.
class AssetMerger : NoCopy
{
public:
    struct InputFile
    {
        AssetMergeSource* pSource = nullptr;
        fs::path fullPath;
    };

    AssetMerger();
    virtual ~AssetMerger();

    //! @returns the relative path. Lower case with forward slashes.
    const std::string& GetRelPath() const { return m_RelPath; }

    //! @returns path to the output file.
    const fs::path& GetOutputFilePath() const { return m_OutputFilePath; }

    //! Merges the list of files.
    void MergeFiles(const std::string& relPath, const std::vector<InputFile>& inputFiles);

protected:
    //! Performs actual merging.
    virtual void DoMerge(const std::vector<InputFile>& inputFiles) = 0;

private:
    std::string m_RelPath;
    fs::path m_OutputFilePath;
};

} // namespace Assets
