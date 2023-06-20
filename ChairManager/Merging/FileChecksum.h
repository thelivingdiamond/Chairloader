//
// Created by theli on 3/30/2023.
//

#ifndef CHAIRLOADER_FILECHECKSUM_H
#define CHAIRLOADER_FILECHECKSUM_H

#include "Manager/SHA256.h"
#include <fstream>

struct FileChecksum {
    fs::path path;
    fs::path relativePath;
    SHA256::Digest checksum;

    FileChecksum() = default;

    FileChecksum(fs::path filePath, fs::path relativePath) : path(filePath), relativePath(relativePath) {
        ParseFile(filePath, relativePath);
    }

    FileChecksum(fs::path pathIn, fs::path relativePath, std::string checksumIn) : path(pathIn), checksum(SHA256::fromString(checksumIn)) {}

    void ParseFile(fs::path pathIn, fs::path relativePathIn){
        path = pathIn;
        relativePath = relativePathIn;
        std::ifstream inFile;
        inFile.exceptions(std::ios::failbit | std::ios::badbit);
        inFile.open(pathIn, std::ios::binary);

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

        checksum = hash.digest();
    }

    bool operator==(const FileChecksum &rhs) const {
        return checksum == rhs.checksum;
    }

    bool operator!=(const FileChecksum &rhs) const {
        return !(rhs == *this);
    }

    bool operator==(const fs::path &rhs) const {
        return path == rhs;
    }

    bool operator<(const FileChecksum &rhs) const {
        return path < rhs.path;
    }

    bool operator>(const FileChecksum &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const FileChecksum &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const FileChecksum &rhs) const {
        return !(*this < rhs);
    }


};

#endif //CHAIRLOADER_FILECHECKSUM_H
