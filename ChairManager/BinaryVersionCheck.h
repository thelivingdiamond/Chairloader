//
// Created by theli on 9/2/2022.
//
#pragma once
#include <string>

namespace VersionCheck {
    struct DLLVersion {
        uint32_t m_Major = 0;
        uint32_t m_Minor = 0;
        uint32_t m_Patch = 0;
        uint32_t m_Build = 0;
        std::string m_ReleaseType;
        std::string m_VersionStr;
        DLLVersion() = default;
        DLLVersion(std::string versionStr);
        // < operator
        bool operator<(const DLLVersion& rhs) const {
            return m_Major < rhs.m_Major ||
            (m_Major == rhs.m_Major && m_Minor < rhs.m_Minor) ||
            (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch < rhs.m_Patch) ||
            (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch == rhs.m_Patch && m_ReleaseType < rhs.m_ReleaseType);
        }
        // > operator
        bool operator>(const DLLVersion& rhs) const {
            return m_Major > rhs.m_Major ||
            (m_Major == rhs.m_Major && m_Minor > rhs.m_Minor) ||
            (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch > rhs.m_Patch) ||
            (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch == rhs.m_Patch && m_ReleaseType > rhs.m_ReleaseType);
        }
        // == operator
        bool operator==(const DLLVersion& rhs) const {
            return m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch == rhs.m_Patch && m_ReleaseType == rhs.m_ReleaseType;
        }
        // != operator
        bool operator!=(const DLLVersion& rhs) const {
            return !(*this == rhs);
        }
        // <= operator
        bool operator<=(const DLLVersion& rhs) const {
            return *this < rhs || *this == rhs;
        }
        // >= operator
        bool operator>=(const DLLVersion& rhs) const {
            return *this > rhs || *this == rhs;
        }
        // valid
        bool valid() const {
            return m_Major != 0 || m_Minor != 0 || m_Patch != 0 || !m_ReleaseType.empty();
        }
        std::string String();
    };
    DLLVersion getBinaryVersion(fs::path szVersionFile);
    std::string getBinaryVersionString(fs::path szVersionFile);
    void fetchLatestVersion(bool bForce = false);

    DLLVersion getInstalledChairloaderVersion();
    std::string getInstalledChairloaderVersionString();
    DLLVersion getPackagedChairloaderVersion();
    std::string getPackagedChairloaderVersionString();
    DLLVersion getLatestChairloaderVersion();
    std::string getLatestChairloaderVersionString();
};