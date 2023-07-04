#include "Merging/Sources/AssetMergeSource.h"

Assets::AssetMergeSource::AssetMergeSource(std::string_view sourceName, const fs::path& rootDirectory)
{
    if (!fs::exists(rootDirectory))
        throw std::logic_error(fmt::format("Directory doesn't exist: {}", rootDirectory.u8string()));

    if (!fs::is_directory(rootDirectory))
        throw std::logic_error(fmt::format("Directory doesn't exist: {}", rootDirectory.u8string()));

    m_SourceName = sourceName;
    m_RootDirectory = rootDirectory;
}

Assets::AssetMergeSource::~AssetMergeSource()
{
}

void Assets::AssetMergeSource::AddFile(const MergeFile& file)
{
#ifdef ASSET_MERGE_DEBUG
    // Verify path is lowercase and uses forward slashes
    for (const char& c : file.path)
    {
        assert(c != '\\');
        assert(c == CharToLower(c));
    }

    // Check for duplicate files
    if (auto it = m_FileSet.find(file.path); it != m_FileSet.end())
    {
        CRY_ASSERT_MESSAGE(false, "Duplicate file");
        throw std::logic_error("AssetMergeSource::AddFile: Duplicate file");
    }
    else
    {
        m_FileSet.insert(file.path);
    }

    CRY_ASSERT_MESSAGE(file.modTime != FileModTime(), "Mod time must be set");
#endif

    m_Files.push_back(file);
}
