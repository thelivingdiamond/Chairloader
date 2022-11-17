//
// Created by theli on 11/11/2022.
//

#ifndef CHAIRLOADER_UPDATEHANDLER_H
#define CHAIRLOADER_UPDATEHANDLER_H
#pragma once
#include "BinaryVersionCheck.h"

namespace UpdateHandler {
    bool isUpdateAvailable();
    void downloadUpdate();
    void asyncDownloadUpdate();
    void asyncDownloadCheck();
    void installUpdate();
    void asyncInstallUpdate();
    void asyncInstallCheck();
    double getProgress();
    double getProgressTotal();
    bool isDownloading();
    bool isInstalling();
    std::string getError();
    bool isErrored();

    void finishUpdate();
};


#endif //CHAIRLOADER_UPDATEHANDLER_H
