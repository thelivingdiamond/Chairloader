//
// Created by theli on 11/11/2022.
//

#ifndef CHAIRLOADER_UPDATEHANDLER_H
#define CHAIRLOADER_UPDATEHANDLER_H
#pragma once
#include "BinaryVersionCheck.h"

namespace UpdateHandler {
//! Check if an update is available
//! \return true if an update is available
    bool isUpdateAvailable();

//! Download the update
    void downloadUpdate();

//! Download the update asynchronously
    void asyncDownloadUpdate();

//! Checks if the async download is still running
    void asyncDownloadCheck();

//! Install the update
    void installUpdate();

//! Install the update asynchronously
    void asyncInstallUpdate();

//! Checks if the async install is still running
    void asyncInstallCheck();

//! Get the progress of the download
    double getProgress();

//! Get the total size of the download
    double getProgressTotal();

//! Is the update handler downloading
//! \return true if the update handler is downloading
    bool isDownloading();

//! Is the update handler installing
//! \return true if the update handler is installing
    bool isInstalling();

//! Get the error message
//! \return the error message
    std::string getError();

//! Is the update handler errored
//! \return true if the update handler has an error
    bool isErrored();

//! Finishes the update and restarts ChairManager
    void finishUpdate();
};


#endif //CHAIRLOADER_UPDATEHANDLER_H
