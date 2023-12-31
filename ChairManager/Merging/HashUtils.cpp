//
// Created by theli on 4/2/2023.
//
#include <sstream>
#include "HashUtils.h"
#include <libzippp.h>

SHA256::Digest HashUtils::HashFile(fs::path path)
{
    std::ifstream inFile;
    inFile.exceptions(std::ios::failbit | std::ios::badbit);
    inFile.open(path, std::ios::binary);

    inFile.seekg(0, std::ios::end);
    uint64_t fileSize = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    // Hash the file
    constexpr uint64_t CHUNK_SIZE = 16 * 1024;
    uint64_t chunks = fileSize / CHUNK_SIZE;
    uint64_t left = fileSize % CHUNK_SIZE;
    char buf[CHUNK_SIZE];

    SHA256 hash;

    for (uint64_t i = 0; i < chunks; i++)
    {
        inFile.read(buf, CHUNK_SIZE);
        hash.update((uint8_t*)buf, CHUNK_SIZE);
    }

    inFile.read(buf, left);
    hash.update((uint8_t*)buf, left);

    return hash.digest();
}

SHA256::Digest HashUtils::HashDirectory(fs::path path)
{
    SHA256 hash;

    for (const auto& entry : fs::recursive_directory_iterator(path))
    {
        if (entry.is_regular_file())
        {
            std::ifstream inFile;
            inFile.exceptions(std::ios::failbit | std::ios::badbit);
            inFile.open(entry.path(), std::ios::binary);
            std::string textData =
                std::string((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
            hash.update(textData);
        }
    }

    return hash.digest();
}

SHA256::Digest HashUtils::HashUncompressedFile(const fs::path& archivePath)
{
    SHA256 hash;
    libzippp::ZipArchive archive(archivePath.string());
    archive.open(libzippp::ZipArchive::ReadOnly);

    if (!archive.isOpen())
        throw std::runtime_error(fmt::format("failed to open archive {}", archivePath.u8string()));

    std::vector<libzippp::ZipEntry> entries = archive.getEntries();
    for (auto& entry : entries)
    {
        std::string name = entry.getName();
        auto size = entry.getSize();
        if (entry.isFile())
        {
            std::string textData = entry.readAsText();
            hash.update(textData);
        }
    }
    archive.close();
    return hash.digest();
}

SHA256::Digest HashUtils::HashBuffer(uint8_t* buffer, uint64_t size)
{
    SHA256 hash;
    hash.update(buffer, size);
    return hash.digest();
}
