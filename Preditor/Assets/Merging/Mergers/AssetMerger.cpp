#include "Merging/Mergers/AssetMerger.h"

Assets::AssetMerger::AssetMerger()
{
}

Assets::AssetMerger::~AssetMerger()
{
}

void Assets::AssetMerger::MergeFiles(const std::string& relPath, const std::vector<InputFile>& inputFiles)
{
    CRY_ASSERT_MESSAGE(m_RelPath.empty(), "AssetMerger can't be reused");

    m_RelPath = relPath;
    m_OutputFilePath = gPreditor->pPaths->GetMergedAssetsPath() / fs::u8path(relPath);

    // Must have input files
    if (inputFiles.empty())
        throw std::logic_error("inputFiles must not be empty");

    // Remove existing file
    if (fs::exists(m_OutputFilePath))
    {
        std::error_code ec;
        fs::remove(m_OutputFilePath, ec);

        if (ec)
            CryWarning("[AssetMerger] Failed to remove output file {}: {}", relPath, ec.message());
    }

    DoMerge(inputFiles);
}
