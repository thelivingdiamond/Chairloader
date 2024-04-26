//
// Created by theli on 4/3/2023.
//

#ifndef CHAIRLOADER_ZIPUTILS_H
#define CHAIRLOADER_ZIPUTILS_H

#include <ChairMerger/Export.h>

namespace ZipUtils
{
void CHAIRMERGER_EXPORT ExtractFolder(const fs::path& zipPath, const fs::path& outPath);

void CHAIRMERGER_EXPORT CompressFolder(const fs::path& folderPath, const fs::path& outPath, bool removeDuplicateRootFolder = false);
} // namespace ZipUtils

#endif // CHAIRLOADER_ZIPUTILS_H
