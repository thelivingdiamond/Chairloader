//
// Created by theli on 1/2/2023.
//

#ifndef CHAIRLOADER_SEMANTICVERSION_H
#define CHAIRLOADER_SEMANTICVERSION_H
#pragma once

#include <regex>
#include <boost/format.hpp>

struct SemanticVersion {
    uint32_t m_Major = 0;
    uint32_t m_Minor = 0;
    uint32_t m_Patch = 0;
    uint32_t m_Build = 0;
    std::string m_ReleaseType;
    std::string m_VersionStr;
    SemanticVersion() = default;
    SemanticVersion(std::string versionStr) {
        // parse the semantic version using regex
        std::regex versionRegex(R"(^(0|[1-9]\d*)\.(0|[1-9]\d*)\.(0|[1-9]\d*)(?:-((?:0|[1-9]\d*|\d*[a-zA-Z-][0-9a-zA-Z-]*)(?:\.(?:0|[1-9]\d*|\d*[a-zA-Z-][0-9a-zA-Z-]*))*))?(?:\+([0-9a-zA-Z-]+(?:\.[0-9a-zA-Z-]+)*))?$)");
        std::smatch match;
        if (std::regex_match(versionStr, match, versionRegex)) {
            m_Major = std::stoi(match[1]);
            m_Minor = std::stoi(match[2]);
            m_Patch = std::stoi(match[3]);
            m_ReleaseType = match[4];
            try{
                m_Build = std::stoi(match[5]);
            } catch (std::invalid_argument& e) {
                m_Build = 0;
            } catch (std::out_of_range& e) {
                m_Build = 0;
            } catch (std::exception& e) {
                m_Build = 0;
            }
        }
        m_VersionStr = versionStr;
    }
    // < operator
    bool operator<(const SemanticVersion& rhs) const {
        return m_Major < rhs.m_Major ||
               (m_Major == rhs.m_Major && m_Minor < rhs.m_Minor) ||
               (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch < rhs.m_Patch) ||
               (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch == rhs.m_Patch && m_ReleaseType < rhs.m_ReleaseType);
    }
    // > operator
    bool operator>(const SemanticVersion& rhs) const {
        return m_Major > rhs.m_Major ||
               (m_Major == rhs.m_Major && m_Minor > rhs.m_Minor) ||
               (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch > rhs.m_Patch) ||
               (m_Major == rhs.m_Major && m_Minor == rhs.m_Minor && m_Patch == rhs.m_Patch && m_ReleaseType > rhs.m_ReleaseType);
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
    std::string String() {
        std::string baseVersion = boost::str(boost::format("%d.%d.%d") % m_Major % m_Minor % m_Patch);
        if(!m_ReleaseType.empty()){
            baseVersion += "-" + m_ReleaseType;
        }
        if(m_Build != 0){
            baseVersion += "+" + std::to_string(m_Build);
        }
        return baseVersion;
    }
};
#endif //CHAIRLOADER_SEMANTICVERSION_H
