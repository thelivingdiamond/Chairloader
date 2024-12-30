//
// Created by theli on 9/2/2022.
//
#include <boost/json.hpp>
#include <Chairloader/SemanticVersion.h>
#include <Manager/GamePath.h>
#include "BinaryVersionCheck.h"
#include <Windows.h>
#include <winver.h>
#include "ChairManager.h"
#include <regex>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Info.hpp>
#include <curlpp/Infos.hpp>
#include "UpdateURL.h"

SemanticVersion VersionCheck::getInstalledChairloaderVersion() {
    auto szVersionFile = ChairManager::Get().GetGamePath() / ChairManager::Get().GetGamePathUtil().GetGameBinDir() / "Chairloader.dll";
    return getBinaryVersion(szVersionFile);
}

SemanticVersion VersionCheck::getPackagedChairloaderVersion() {
    auto szVersionFile = fs::path("Release") / "Chairloader.dll";
    return getBinaryVersion(szVersionFile);
}

SemanticVersion VersionCheck::getBinaryVersion(fs::path szVersionFile) {
    auto strVersion = getBinaryVersionString(szVersionFile);
    return SemanticVersion(strVersion);
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
    auto szVersionFile = ChairManager::Get().GetGamePath() / ChairManager::Get().GetGamePathUtil().GetGameBinDir() / "Chairloader.dll";
    return getBinaryVersionString(szVersionFile);
}

std::string VersionCheck::getPackagedChairloaderVersionString() {
    auto szVersionFile = fs::path("Release") / "Chairloader.dll";
    return getBinaryVersionString(szVersionFile);
}

std::pair<std::string, std::string> VersionCheck::fetchLatestVersion(std::string_view etag) {
    std::stringstream result;
    cURLpp::Easy easyhandle;
    easyhandle.setOpt(cURLpp::Options::Url(UPDATE_URL));
    easyhandle.setOpt(cURLpp::Options::WriteStream(&result));
    easyhandle.setOpt(cURLpp::Options::UserAgent("ChairmanagerAutoUpdate"));

    if(!etag.empty())
        easyhandle.setOpt(cURLpp::Options::HttpHeader({"If-None-Match: " + std::string(etag)}));

    std::string remoteEtag;

    easyhandle.setOpt(cURLpp::Options::HeaderFunction([&](char* data, size_t size, size_t nmemb) -> size_t {
        std::string header(data, size * nmemb);
        // example Etag Header response: ETag: W/"5be34ecc3f6c8c84a1ac3fe6441ab4b36a86c5141eb77e8737cc036198ec9820"\r\n
        // remove the ETag: W/ and the \r\n
        if (header.find("ETag: ") == 0) {
            remoteEtag = header.substr(8, header.size() - 10);
        }
        return size * nmemb;
    }));

    try{
        easyhandle.perform();
    } catch (const std::exception &e){
        ChairManager::Get().log(severityLevel::error, "Failed to check latest version: %s", std::string(e.what()));
    }

    // get the response code
    long http_code = curlpp::infos::ResponseCode::get(easyhandle);
    ChairManager::Get().log(severityLevel::debug, "HTTP Response Code: %ld", http_code);

    if(http_code == 304) {
        // no update available, use the cached version
        return std::pair(std::string(), std::string(etag));
    }

    std:: string tag_name;
    easyhandle.reset();

    try {
        auto json = boost::json::parse(result.str());
        tag_name = json.at("tag_name").as_string();
        // get the etag
//        auto etag = curlpp::infos::ResponseCode::G
    } catch (const std::exception &e) {
        ChairManager::Get().log(severityLevel::error, "Failed to parse latest version string: %s", std::string(e.what()));
        throw;
    }

    return { tag_name, remoteEtag };
}

