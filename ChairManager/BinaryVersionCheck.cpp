//
// Created by theli on 9/2/2022.
//
#include "BinaryVersionCheck.h"
#include "PathUtils.h"
#include <Windows.h>
#include <winver.h>
#include "ChairManager.h"
#include <regex>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <boost/json.hpp>
#include <curlpp/Info.hpp>
#include <curlpp/Infos.hpp>
#include "UpdateURL.h"

static std::string m_latestVersion;


VersionCheck::DLLVersion VersionCheck::getInstalledChairloaderVersion() {
    auto szVersionFile = ChairManager::Get().GetGamePath() / PathUtils::GAME_BIN_DIR / "Chairloader.dll";
    return getBinaryVersion(szVersionFile);
}

VersionCheck::DLLVersion VersionCheck::getPackagedChairloaderVersion() {
    auto szVersionFile = fs::path("Release") / "Chairloader.dll";
    return getBinaryVersion(szVersionFile);
}

VersionCheck::DLLVersion VersionCheck::getBinaryVersion(fs::path szVersionFile) {
    auto strVersion = getBinaryVersionString(szVersionFile);
    return DLLVersion(strVersion);
}

std::string VersionCheck::getBinaryVersionString(fs::path szVersionFile) {
    DWORD verHandle = 0;
    UINT size = 0;
    LPBYTE lpBuffer = NULL;
    DWORD verSize = GetFileVersionInfoSizeW(szVersionFile.wstring().data(), &verHandle);
    if (verSize != 0) {
        LPSTR verData = new char[verSize];
        if(GetFileVersionInfoW(szVersionFile.wstring().data(), verHandle, verSize, verData)) {
            if(VerQueryValueA(verData, R"(\StringFileInfo\040904E4\ProductVersion)", (VOID FAR* FAR*)&lpBuffer, &size)) {
                if (size) {
                    return {(char*)lpBuffer};
                }
            }
        }
    }
    return {};
}

std::string VersionCheck::getInstalledChairloaderVersionString() {
    auto szVersionFile = ChairManager::Get().GetGamePath() / PathUtils::GAME_BIN_DIR / "Chairloader.dll";
    return getBinaryVersionString(szVersionFile);
}

std::string VersionCheck::getPackagedChairloaderVersionString() {
    auto szVersionFile = fs::path("Release") / "Chairloader.dll";
    return getBinaryVersionString(szVersionFile);
}

std::string VersionCheck::getLatestChairloaderVersionString() {
    return m_latestVersion;
}

VersionCheck::DLLVersion VersionCheck::getLatestChairloaderVersion() {
    return DLLVersion(getLatestChairloaderVersionString());
}

void VersionCheck::fetchLatestVersion(bool bForce) {
    std::stringstream result;
    cURLpp::Easy easyhandle;
    easyhandle.setOpt(cURLpp::Options::Url(UPDATE_URL));
    easyhandle.setOpt(cURLpp::Options::WriteStream(&result));
    easyhandle.setOpt(cURLpp::Options::UserAgent("ChairmanagerAutoUpdate"));
    if(!bForce)
        easyhandle.setOpt(cURLpp::Options::HttpHeader({"If-None-Match: " + ChairManager::Get().getETag()}));
    easyhandle.setOpt(cURLpp::Options::HeaderFunction([&](char* data, size_t size, size_t nmemb) -> size_t {
        std::string header(data, size * nmemb);
        // example Etag Header response: ETag: W/"5be34ecc3f6c8c84a1ac3fe6441ab4b36a86c5141eb77e8737cc036198ec9820"\r\n
        // remove the ETag: W/ and the \r\n
        if (header.find("ETag: ") == 0) {
            auto etag = header.substr(8, header.size() - 10);
            ChairManager::Get().setETag(etag);
        }
        return size * nmemb;
    }));
    easyhandle.perform();
    // get the response code
    long http_code = curlpp::infos::ResponseCode::get(easyhandle);
    ChairManager::Get().log(ChairManager::severityLevel::debug, "HTTP Response Code: %ld", http_code);
    if(http_code == 304) {
        // no update available, use the cached version
        m_latestVersion = ChairManager::Get().getCachedLatestVersion();
        return;
    }
    std:: string tag_name;
    easyhandle.reset();
    try {
        auto json = boost::json::parse(result.str());
        tag_name = json.at("tag_name").as_string();
        // get the etag
//        auto etag = curlpp::infos::ResponseCode::G
    } catch (std::exception &e) {
        ChairManager::Get().log(ChairManager::severityLevel::error, "Failed to parse latest version string: %s", std::string(e.what()));
        return;
    }
    m_latestVersion = tag_name;
    ChairManager::Get().setCachedLatestVersion(tag_name);
}


std::string VersionCheck::DLLVersion::String() {
    std::string baseVersion = boost::str(boost::format("%d.%d.%d") % m_Major % m_Minor % m_Patch);
    if(!m_ReleaseType.empty()){
        baseVersion += "-" + m_ReleaseType;
    }
    if(m_Build != 0){
        baseVersion += "+" + std::to_string(m_Build);
    }
    return baseVersion;
}

VersionCheck::DLLVersion::DLLVersion(std::string versionStr) {
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