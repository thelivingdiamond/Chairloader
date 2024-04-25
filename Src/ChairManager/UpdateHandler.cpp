//
// Created by theli on 11/11/2022.
//
#include <boost/json.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>
#include <Chairloader/SemanticVersion.h>
#include "ChairManager.h"
#include "UpdateURL.h"
#include "UpdateHandler.h"
#include "BinaryVersionCheck.h"

static double progress_dltotal = 0, progress_dlnow = 0;
static std::mutex progress_mutex, error_mutex;
static bool m_bIsDownloading = false, m_bIsInstalling = false;
static std::string m_szError = "";

static void TryRenameToOld(const fs::path& filePath)
{
    fs::path oldFile = filePath;
    oldFile.replace_extension(fs::u8path(oldFile.extension().u8string() + ".old"));

    // Remove the old file
    std::error_code ec;
    fs::remove(oldFile, ec);
    if (ec)
        ChairManager::Get().log(severityLevel::error, "Failed to remove %s: %s", oldFile.u8string().c_str(), ec.message().c_str());

    // Rename
    fs::rename(filePath, oldFile, ec);
    if (ec)
    {
        ChairManager::Get().log(
            severityLevel::error,
            "Failed to rename %s to %s: %s",
            filePath.u8string().c_str(),
            oldFile.u8string().c_str(),
            ec.message().c_str());
    }
}

void setError(std::string szError) {
    std::lock_guard<std::mutex> lock(error_mutex);
    m_szError = szError;
}

bool UpdateHandler::isUpdateAvailable() {
    auto latestVersion = VersionCheck::getLatestChairloaderVersion();
    auto installedVersion = VersionCheck::getInstalledChairloaderVersion();
    ChairManager::Get().log(severityLevel::info , "Online Version: %s", latestVersion.String());
    ChairManager::Get().log(severityLevel::info , "Installed Version: %s", installedVersion.String());
    ChairManager::Get().log(severityLevel::info , "Update Available: %s", latestVersion > installedVersion ? "true" : "false");
    if(latestVersion > installedVersion) {
        ChairManager::Get().overlayLog(severityLevel::info , "Update Available!");
    }
    return latestVersion > installedVersion;
}

void UpdateHandler::downloadUpdate() {
    std::stringstream result;
    cURLpp::Easy easyhandle;
    easyhandle.setOpt(cURLpp::Options::Url(UPDATE_URL));
    easyhandle.setOpt(cURLpp::Options::WriteStream(&result));
    easyhandle.setOpt(cURLpp::Options::UserAgent("ChairmanagerAutoUpdate"));
    easyhandle.perform();
    std::string downloadUrl;
    try {
        boost::json::value json = boost::json::parse(result.str());
        // get the download url
        downloadUrl = json.at("assets").at(0).at("browser_download_url").as_string();
        ChairManager::Get().overlayLog(severityLevel::info, "%s", "Downloading update...");
    } catch (std::exception &e) {
        ChairManager::Get().log(severityLevel::error, "Invalid github response: %s", e.what());
        setError(("Invalid github response: " + std::string(e.what())));
        return;
    }
    try {
        cURLpp::Easy downloadHandle;
        std::ofstream fileStream;
        std::ostringstream fileName;
        fileStream.open("update.zip", std::ios::out | std::ios::binary);
        downloadHandle.setOpt(cURLpp::Options::Url(downloadUrl));
        downloadHandle.setOpt(cURLpp::Options::UserAgent("ChairmanagerAutoUpdate"));
        downloadHandle.setOpt(cURLpp::Options::WriteStream(&fileStream));
        downloadHandle.setOpt(cURLpp::options::FollowLocation(true));
        downloadHandle.setOpt(cURLpp::options::NoProgress (false));
        downloadHandle.setOpt(cURLpp::options::ProgressFunction([&](double dltotal, double dlnow, double ultotal, double ulnow) {
            progress_mutex.lock();
            progress_dltotal = dltotal;
            progress_dlnow = dlnow;
            progress_mutex.unlock();
            return 0;
        }));
        downloadHandle.perform();
        fileStream.close();
    } catch (std::exception &e) {
        ChairManager::Get().overlayLog(severityLevel::error, "Failed to download update: %s", e.what());
        setError(("Failed to download update: " + std::string(e.what())));
        return;
    }
}

void UpdateHandler::installUpdate() {
    // rename our executable to chairloader.old
    TryRenameToOld("ChairManager.exe");
    TryRenameToOld("Preditor.exe");
    
    // Rename all DLLs to .old
    for (const fs::directory_entry& i : fs::directory_iterator("."))
    {
        fs::path p = i.path();

        if (p.extension() == ".dll")
            TryRenameToOld(p);
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
    try {
        fs::remove("update.zip");
    } catch (std::exception &e) {
        // not a fatal error
        ChairManager::Get().log(severityLevel::error, "Failed to remove update.zip: %s", e.what());
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
    m_bIsDownloading = true;
    downloadFuture = std::async(std::launch::async, [&]() { downloadUpdate(); });
}

void UpdateHandler::asyncDownloadCheck() {
    if(!m_bIsDownloading) return;
    if(IsFutureReady(downloadFuture)) {
        downloadFuture.get();
        ChairManager::Get().overlayLog(severityLevel::info, "Update downloaded successfully!");
        m_bIsDownloading = false;
    }
}

bool UpdateHandler::isDownloading() {
    return m_bIsDownloading;
}

static std::future<void> installFuture;
void UpdateHandler::asyncInstallUpdate() {
    if(m_bIsInstalling) return;
    m_bIsInstalling = true;
    installFuture = std::async(std::launch::async, [&]() { installUpdate(); });
}

void UpdateHandler::asyncInstallCheck() {
    if(!m_bIsInstalling) return;
    if(IsFutureReady(installFuture)) {
        installFuture.get();
        ChairManager::Get().overlayLog(severityLevel::info, "Update installed successfully!");
        m_bIsInstalling = false;
    }

}

std::string UpdateHandler::getError() {
    std::scoped_lock lock(error_mutex);
    return m_szError;
}

bool UpdateHandler::isErrored() {
    // lock the mutex
    std::scoped_lock lock(error_mutex);
    return !m_szError.empty();
}

bool UpdateHandler::isInstalling() {
    return m_bIsInstalling;
}

void UpdateHandler::finishUpdate() {
    STARTUPINFOW si = {sizeof(STARTUPINFO)};
    PROCESS_INFORMATION pi;
    std::wstring commandArgs = L".\\ChairManager.exe";
    commandArgs.resize(MAX_PATH);
    if(CreateProcessW(nullptr, &commandArgs[0], nullptr, nullptr, false, DETACHED_PROCESS, nullptr, nullptr, &si, &pi)) {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    exit(0);
}
