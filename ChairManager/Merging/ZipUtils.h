//
// Created by theli on 4/3/2023.
//

#ifndef CHAIRLOADER_ZIPUTILS_H
#define CHAIRLOADER_ZIPUTILS_H

namespace ZipUtils {
    void ExtractFolder(const fs::path& zipPath, const fs::path& outPath);

    void CompressFolder(const fs::path& folderPath, const fs::path& outPath, bool removeDuplicateRootFolder = false);
}

#endif //CHAIRLOADER_ZIPUTILS_H