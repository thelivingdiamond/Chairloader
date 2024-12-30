#include "Merging/Mergers/AssetMerger.h"
#include "Merging/AssetMergeSystem.h"

Assets::AssetMerger::AssetMerger(AssetMergeSystem* pSys)
{
    m_pSys = pSys;
}

Assets::AssetMerger::~AssetMerger()
{
}

void Assets::AssetMerger::MergeFiles(const std::string& relPath, const std::vector<InputFile>& inputFiles)
{
    CRY_ASSERT_MESSAGE(m_RelPath.empty(), "AssetMerger can't be reused");

    m_RelPath = relPath;
    std::string ourRelPath = m_pSys->RemapOutputFile(relPath);
    m_OutputFilePath = gPreditor->pPaths->GetMergedAssetsPath() / fs::u8path(ourRelPath);

    // NOTE: inputFiles may be empty. In this case the original file should be processed.
    // NOTE: But not simply copied. XMLs must be finalized (even without mods).

    // Remove existing file
    if (fs::exists(m_OutputFilePath))
    {
        std::error_code ec;
        fs::remove(m_OutputFilePath, ec);

        if (ec)
            CryWarning("[AssetMerger] Failed to remove output file {}: {}", relPath, ec.message());
    }

    // Create parent directory
    fs::create_directories(m_OutputFilePath.parent_path());

    DoMerge(inputFiles);
}
