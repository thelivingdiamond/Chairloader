//
// Created by theli on 11/4/2022.
//

#ifndef CHAIRLOADER_XMLREFERENCE_H
#define CHAIRLOADER_XMLREFERENCE_H

#include "../pch.h"
#include <filesystem>
#include <pugixml.hpp>

class XMLReference {
private:
    int32_t m_ID32;
    int64_t m_GUID64;
    __int128 m_GUID128;
    std::string m_Name;
    fs::path m_Path;
    pugi::xml_node m_pNode;
public:
    XMLReference() = default;

    int32_t getId32() const {
        return m_ID32;
    }

    int64_t getGuid64() const {
        return m_GUID64;
    }

    __int128_t getGuid128() const {
        return m_GUID128;
    }

    const std::string &getName() const {
        return m_Name;
    }

    const fs::path &getPath() const {
        return m_Path;
    }

    const pugi::xml_node &getNode() const {
        return m_pNode;
    }

    void setId32(int32_t mId32) {
        m_ID32 = mId32;
    }

    void setGuid64(int64_t mGuid64) {
        m_GUID64 = mGuid64;
    }

    void setGuid128(__int128_t mGuid128) {
        m_GUID128 = mGuid128;
    }

    void setName(const std::string &mName) {
        m_Name = mName;
    }

    void setPath(const fs::path &mPath) {
        m_Path = mPath;
    }

    void setNode(const pugi::xml_node &mPNode) {
        m_pNode = mPNode;
    }

    // == operator
    bool operator==(const XMLReference& other) const {
        return m_ID32 == other.m_ID32 || m_GUID64 == other.m_GUID64 || m_GUID128 == other.m_GUID128 || m_Name == other.m_Name;
    }
    bool operator==(const int32_t& other) const {
        return m_ID32 == other;
    }
    bool operator==(const int64_t& other) const {
        return m_GUID64 == other;
    }
    bool operator==(const __int128& other) const {
        return m_GUID128 == other;
    }
    bool operator==(const std::string& other) const {
        return m_Name == other;
    }
    // != operator
    bool operator!=(const XMLReference& other) const {
        return m_ID32 != other.m_ID32 || m_GUID64 != other.m_GUID64 || m_GUID128 != other.m_GUID128 || m_Name != other.m_Name;
    }
    bool operator!=(const int32_t& other) const {
        return m_ID32 != other;
    }
    bool operator!=(const int64_t& other) const {
        return m_GUID64 != other;
    }
    bool operator!=(const __int128& other) const {
        return m_GUID128 != other;
    }
    bool operator!=(const std::string& other) const {
        return m_Name != other;
    }
};


#endif //CHAIRLOADER_XMLREFERENCE_H
