#include "Merging/Mergers/SymlinkAssetMerger.h"
#include "Merging/Sources/AssetMergeSource.h"

bool Assets::SymlinkAssetMerger::m_CopyInstead = false;

Assets::SymlinkAssetMerger::SymlinkAssetMerger()
{
}

Assets::SymlinkAssetMerger::~SymlinkAssetMerger()
{
}

void Assets::SymlinkAssetMerger::DoMerge(const std::vector<InputFile>& inputFiles)
{
    // Symlink to the last file
    fs::path srcFile;
    std::string sourceName;

    if (!inputFiles.empty())
    {
        srcFile = inputFiles.rbegin()->fullPath;
        sourceName = inputFiles.rbegin()->pSource->GetSourceName();
    }
    else
    {
        srcFile = gPreditor->pConfig->GetPreyFiles() / fs::u8path(GetRelPath());
        sourceName = "PreyFiles";
    }

    if constexpr (ASSETS_DEBUG)
    {
        CryLog("[SymlinkAssetMerger] {}: link from {} ({})", GetRelPath(),
            sourceName, srcFile.u8string());
    }

    bool result = false;

    if (!m_CopyInstead)
    {
        result = TrySymlink(srcFile, GetOutputFilePath());

        if (!result)
        {
            m_CopyInstead = true;
            result = TryCopy(srcFile, GetOutputFilePath());
        }
    }
    else
    {
        result = TryCopy(srcFile, GetOutputFilePath());
    }

    if (!result)
        throw std::runtime_error(fmt::format("Failed to merge {}", GetRelPath()));
}

bool Assets::SymlinkAssetMerger::TrySymlink(const fs::path& src, const fs::path& dst)
{
    std::error_code ec;
    fs::create_symlink(src, dst, ec);

    if (ec)
    {
        CryError("[SymlinkAssetMerger] Failed to create symlink {} -> {}", src.u8string(), dst.u8string());
    }

    return !ec;
}

bool Assets::SymlinkAssetMerger::TryCopy(const fs::path& src, const fs::path& dst)
{
    std::error_code ec;
    fs::copy_file(src, dst, fs::copy_options::overwrite_existing);

    if (ec)
    {
        CryError("[SymlinkAssetMerger] Failed to copy {} -> {}", src.u8string(), dst.u8string());
    }

    return !ec;
}
