//
// Created by theli on 4/2/2023.
//

#ifndef CHAIRLOADER_HASHUTILS_H
#define CHAIRLOADER_HASHUTILS_H

#include <Manager/SHA256.h>

namespace HashUtils {
    SHA256::Digest HashFile(fs::path path);
    SHA256::Digest HashDirectory(fs::path path);
    SHA256::Digest HashBuffer(uint8_t* buffer, uint64_t size);

    SHA256::Digest HashUncompressedFile(const fs::path& path);
}
#endif //CHAIRLOADER_HASHUTILS_H
