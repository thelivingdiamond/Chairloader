//
// Created by theli on 1/2/2023.
//

#ifndef CHAIRLOADER_SEMANTICVERSION_H
#define CHAIRLOADER_SEMANTICVERSION_H
#pragma once

#include <regex>
#include <boost/format.hpp>
#include <utility>

struct SemanticVersion {
    uint32_t m_Major = 0; //!< Increment when breaking API/ABI.
    uint32_t m_Minor = 0; //!< Increment when adding something new to the API.
    uint32_t m_Patch = 0; //!< Increment on a bug-fix with no API/ABI changes.
    std::string m_ReleaseType; //!< Set to "alpha", "beta", "rc" or "".

    SemanticVersion() = default;

    //! Parses a version string in the proper Semantic Versioning format.
    explicit SemanticVersion(std::string &versionStr) {
        std::regex versionRegex(R"(^(0|[1-9]\d*)\.(0|[1-9]\d*)\.(0|[1-9]\d*)(?:-((?:0|[1-9]\d*|\d*[a-zA-Z-][0-9a-zA-Z-]*)(?:\.(?:0|[1-9]\d*|\d*[a-zA-Z-][0-9a-zA-Z-]*))*))?(?:\+([0-9a-zA-Z-]+(?:\.[0-9a-zA-Z-]+)*))?$)");
        std::smatch match;
        if (std::regex_match(versionStr, match, versionRegex)) {
            m_Major = std::stoi(match[1]);
            m_Minor = std::stoi(match[2]);
            m_Patch = std::stoi(match[3]);
            m_ReleaseType = match[4];
        }
    }

    //! Constructs a version from its components.
    SemanticVersion(uint32_t major, uint32_t minor, uint32_t patch, std::string &releaseType) {
        m_Major = major;
        m_Minor = minor;
        m_Patch = patch;
        m_ReleaseType = releaseType;
    }
    // < operator
    bool operator<(const SemanticVersion& rhs) const {
        return m_Major < rhs.m_Major ||
               (m_Major == rhs.m_Major && m_Minor < rhs.m_Minor) ||
               (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch < rhs.m_Patch) ||
               (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch == rhs.m_Patch && (m_ReleaseType < rhs.m_ReleaseType || (rhs.m_ReleaseType.empty() && !m_ReleaseType.empty())));
    }
    // > operator
    bool operator>(const SemanticVersion& rhs) const {
        return m_Major > rhs.m_Major ||
               (m_Major == rhs.m_Major && m_Minor > rhs.m_Minor) ||
               (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch > rhs.m_Patch) ||
               (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch == rhs.m_Patch && (m_ReleaseType > rhs.m_ReleaseType || (m_ReleaseType.empty() && !rhs.m_ReleaseType.empty())));
    }
    // == operator
    bool operator==(const SemanticVersion& rhs) const {
        return m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch == rhs.m_Patch && m_ReleaseType == rhs.m_ReleaseType;
    }
    // != operator
    bool operator!=(const SemanticVersion& rhs) const {
        return !(*this == rhs);
    }
    // <= operator
    bool operator<=(const SemanticVersion& rhs) const {
        return *this < rhs || *this == rhs;
    }
    // >= operator
    bool operator>=(const SemanticVersion& rhs) const {
        return *this > rhs || *this == rhs;
    }
    // valid
    bool valid() const {
        return m_Major != 0 || m_Minor != 0 || m_Patch != 0 || !m_ReleaseType.empty();
    }
    //! Returns a string representation of the version in the proper Semantic Versioning format.
    std::string String() {
        std::string baseVersion = boost::str(boost::format("%d.%d.%d") % m_Major % m_Minor % m_Patch);
        if(!m_ReleaseType.empty()){
            baseVersion += "-" + m_ReleaseType;
        }
        return baseVersion;
    }
};
#endif //CHAIRLOADER_SEMANTICVERSION_H
