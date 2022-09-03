//
// Created by theli on 9/2/2022.
//
#pragma once
#include <string>

namespace VersionCheck {
    struct DLLVersion {
        uint16_t major;
        uint16_t minor;
        uint16_t patch;
        uint16_t build;
        uint64_t getVersion64() const {
            return (uint64_t)major << 48 | (uint64_t)minor << 32 | (uint64_t)patch << 16 | (uint64_t)build;
        }
        // < operator
        bool operator<(const DLLVersion& rhs) const {
            return getVersion64() < rhs.getVersion64();
        }
        // > operator
        bool operator>(const DLLVersion& rhs) const {
            return getVersion64() > rhs.getVersion64();
        }
        // == operator
        bool operator==(const DLLVersion& rhs) const {
            return getVersion64() == rhs.getVersion64();
        }
        // != operator
        bool operator!=(const DLLVersion& rhs) const {
            return getVersion64() != rhs.getVersion64();
        }
        // <= operator
        bool operator<=(const DLLVersion& rhs) const {
            return getVersion64() <= rhs.getVersion64();
        }
        // >= operator
        bool operator>=(const DLLVersion& rhs) const {
            return getVersion64() >= rhs.getVersion64();
        }
        // valid
        bool valid() const {
            return major != 0 || minor != 0 || patch != 0 || build != 0;
        }
        std::string String();
    };
    DLLVersion getBinaryVersion(fs::path szVersionFile);
    DLLVersion getInstalledChairloaderVersion();
    DLLVersion getPackagedChairloaderVersion();
};