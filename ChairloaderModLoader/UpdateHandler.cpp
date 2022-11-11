//
// Created by theli on 11/11/2022.
//

#include "UpdateHandler.h"
#include "BinaryVersionCheck.h"
#include <boost/json/src.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>
#include "ModLoader.h"

static double progress_dltotal = 0, progress_dlnow = 0;
static std::mutex progress_mutex;
static bool m_bIsDownloading = false;

bool UpdateHandler::isUpdateAvailable() {
    std::stringstream result;
    cURLpp::Easy easyhandle;
    easyhandle.setOpt(cURLpp::Options::Url(UPDATE_URL));
    easyhandle.setOpt(cURLpp::Options::WriteStream(&result));
    easyhandle.setOpt(cURLpp::Options::UserAgent("ChairmanagerAutoUpdate"));
    easyhandle.perform();
    auto json = boost::json::parse(result.str());
    auto tag_name = json.at("tag_name").as_string();
    auto onlineVersion = VersionCheck::DLLVersion(tag_name.c_str());
    auto installedVersion = VersionCheck::getInstalledChairloaderVersion();
    easyhandle.reset();
    ModLoader::Get().log(ModLoader::severityLevel::info , "Online Version: %s", onlineVersion.String());
    ModLoader::Get().log(ModLoader::severityLevel::info , "Installed Version: %s", installedVersion.String());
    ModLoader::Get().log(ModLoader::severityLevel::info , "Update Available: %s", onlineVersion > installedVersion ? "true" : "false");
    return onlineVersion > installedVersion;
}

void UpdateHandler::downloadUpdate() {
    m_bIsDownloading = true;
    std::stringstream result;
    cURLpp::Easy easyhandle;
    easyhandle.setOpt(cURLpp::Options::Url(UPDATE_URL));
    easyhandle.setOpt(cURLpp::Options::WriteStream(&result));
    easyhandle.setOpt(cURLpp::Options::UserAgent("ChairmanagerAutoUpdate"));
    easyhandle.perform();
    ModLoader::Get().log(ModLoader::severityLevel::debug, "%s", result.str().c_str());
    std::string downloadUrl;
    try {
        boost::json::value json = boost::json::parse(result.str());
        // get the download url
        downloadUrl = json.at("assets").at(0).at("browser_download_url").as_string();
        ModLoader::Get().log(ModLoader::severityLevel::debug, "URL: %s", downloadUrl.c_str());
        ModLoader::Get().log(ModLoader::severityLevel::debug, "%s", "Downloading update...");
    } catch (std::exception &e) {
        ModLoader::Get().log(ModLoader::severityLevel::error, "Failed to parse json: %s", e.what());
    }
    try {
        cURLpp::Easy downloadHandle;
        // download the file
        // open a file stream
        std::ofstream fileStream;
        std::ostringstream fileName;
        fileStream.open("update.zip", std::ios::out | std::ios::binary);
        ModLoader::Get().log(ModLoader::severityLevel::debug, "Downloading From: %s", downloadUrl.c_str());
        downloadHandle.setOpt(cURLpp::Options::Url(downloadUrl));
        downloadHandle.setOpt(cURLpp::Options::UserAgent("ChairmanagerAutoUpdate"));
        downloadHandle.setOpt(cURLpp::Options::WriteStream(&fileStream));
        downloadHandle.setOpt(cURLpp::options::FollowLocation(true));
        downloadHandle.setOpt(cURLpp::options::NoProgress (false));
        downloadHandle.setOpt(cURLpp::options::ProgressFunction([&](double dltotal, double dlnow, double ultotal, double ulnow) {
            progress_dltotal = dltotal;
            progress_dlnow = dlnow;
            return 0;
        }));
        downloadHandle.perform();
        fileStream.close();
    } catch (std::exception &e) {
        ModLoader::Get().log(ModLoader::severityLevel::error, "Failed to download update: %s", e.what());
    }
}

void UpdateHandler::installUpdate() {
    // rename our executable to chairloader.old
    try {
        fs::rename("ChairloaderModLoader.exe", "ChairloaderModLoader.exe.old");
    } catch (std::exception &e) {
        ModLoader::Get().log(ModLoader::severityLevel::error, "Failed to rename ChairloaderModLoader.exe: %s", e.what());
    }
    // extract the zip file
    std::wstring commandArgs = L".\\7za.exe x update.zip -o.\\ -y";
    STARTUPINFOW si = {sizeof(STARTUPINFO)};
    PROCESS_INFORMATION pi;
    commandArgs.resize(MAX_PATH);
    if(CreateProcessW(nullptr, &commandArgs[0], nullptr, nullptr, false, CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}

double UpdateHandler::getProgress() {
    std::scoped_lock lock(progress_mutex);
    return progress_dlnow;
}

double UpdateHandler::getProgressTotal() {
    std::scoped_lock lock(progress_mutex);
    return progress_dltotal;
}

static std::future<void> downloadFuture;

void UpdateHandler::asyncDownloadUpdate() {
    if(m_bIsDownloading) return;
    downloadFuture = std::async(std::launch::async, [&]() { downloadUpdate(); });
}

void UpdateHandler::asyncDownloadCheck() {
    if(!m_bIsDownloading) return;
    if(IsFutureReady(downloadFuture)) {
        downloadFuture.get();
        ModLoader::Get().log(ModLoader::severityLevel::debug, "Downloaded update!");
        m_bIsDownloading = false;
    }
}

bool UpdateHandler::isDownloading() {
    return isDownloading;
}
