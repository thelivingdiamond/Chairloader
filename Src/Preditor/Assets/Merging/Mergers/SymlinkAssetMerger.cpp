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
    const InputFile& srcFile = *inputFiles.rbegin();

    if constexpr (ASSETS_DEBUG)
    {
        CryLog("[SymlinkAssetMerger] {}: link from {} ({})", GetRelPath(),
            srcFile.pSource->GetSourceName(), srcFile.fullPath.u8string());
    }

    bool result = false;

    if (!m_CopyInstead)
    {
        result = TrySymlink(srcFile.fullPath, GetOutputFilePath());

        if (!result)
        {
            m_CopyInstead = true;
            result = TryCopy(srcFile.fullPath, GetOutputFilePath());
        }
    }
    else
    {
        result = TryCopy(srcFile.fullPath, GetOutputFilePath());
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
