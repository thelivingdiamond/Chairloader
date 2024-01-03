//
// Created by theli on 4/2/2023.
//

#ifndef CHAIRLOADER_HASHUTILS_H
#define CHAIRLOADER_HASHUTILS_H

#include <Manager/SHA256.h>

namespace HashUtils
{
SHA256::Digest HashFile(fs::path path);
SHA256::Digest HashDirectory(fs::path path);
SHA256::Digest HashBuffer(uint8_t* buffer, uint64_t size);

//! Hashes a ZIP file.
//! @param  path    Path to the ZIP.
//! @param  outHash Output hash. Only set if returns true.
//! @returns Whether the file was opened successfully.
bool HashUncompressedFile(const fs::path& path, SHA256::Digest& outHash);

} // namespace HashUtils
#endif // CHAIRLOADER_HASHUTILS_H
