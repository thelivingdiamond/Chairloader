#include "Merging/Sources/ModMergeSource.h"

Assets::ModMergeSource::ModMergeSource(const std::string& modName, const fs::path& modDataDir)
    : DirectoryAssetMergeSource("mod." + modName, modDataDir)
{
}

Assets::ModMergeSource::~ModMergeSource()
{
}
