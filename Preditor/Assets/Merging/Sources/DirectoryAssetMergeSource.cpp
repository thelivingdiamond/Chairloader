#include "Merging/Sources/DirectoryAssetMergeSource.h"
#include "AssetsCommon.h"

Assets::DirectoryAssetMergeSource::DirectoryAssetMergeSource(std::string_view sourceName, const fs::path& rootDirectory)
    : AssetMergeSource(sourceName, rootDirectory)
{
}

Assets::DirectoryAssetMergeSource::~DirectoryAssetMergeSource()
{
}

void Assets::DirectoryAssetMergeSource::CollectFiles()
{
    RecursiveFindFiles("");
}

bool Assets::DirectoryAssetMergeSource::CheckFile(const std::string& relPath, const fs::path& fullPath)
{
    // Skip level files (will be handled separately)
    if (StartsWith(relPath, "levels/"))
        return false;

    return true;
}

Assets::FileModTime Assets::DirectoryAssetMergeSource::GetMetaModTime(const std::string& relPath, const fs::path& fullPath)
{
    return FileModTime();
}

void Assets::DirectoryAssetMergeSource::RecursiveFindFiles(const std::string& path)
{
    fs::path realPath = GetRootDirectory() / fs::u8path(path);

    for (const fs::directory_entry& entry : fs::directory_iterator(realPath))
    {
        if (entry.is_directory())
        {
            RecursiveFindFiles(path + entry.path().filename().u8string() + '/');
        }
        else
        {
            fs::path realFilePath = entry.path();
            std::string relPath = path + realFilePath.filename().u8string();
            StrToLower(relPath);

            if (CheckFile(relPath, realFilePath))
            {
                MergeFile fileInfo;
                fileInfo.path = relPath;
                fileInfo.modTime = entry.last_write_time().time_since_epoch();
                fileInfo.metaModTime = GetMetaModTime(relPath, realFilePath);
                AddFile(fileInfo);
            }
        }
    }
}
