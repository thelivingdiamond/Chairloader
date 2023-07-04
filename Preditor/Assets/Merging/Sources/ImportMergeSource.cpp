#include "Merging/Sources/ImportMergeSource.h"

Assets::ImportMergeSource::ImportMergeSource(const fs::path& rootDirectory)
    : DirectoryAssetMergeSource("project.import", rootDirectory)
{
}

Assets::ImportMergeSource::~ImportMergeSource()
{
}
