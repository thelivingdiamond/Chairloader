//
// Created by theli on 11/11/2022.
//

#ifndef CHAIRLOADER_UPDATEHANDLER_H
#define CHAIRLOADER_UPDATEHANDLER_H


namespace UpdateHandler {
#define UPDATE_URL "https://api.github.com/repos/thelivingdiamond/Chairloader/releases/latest"
    bool isUpdateAvailable();
    void downloadUpdate();
    void asyncDownloadUpdate();
    void asyncDownloadCheck();
    void installUpdate();
    double getProgress();
    double getProgressTotal();
    bool isDownloading();
};


#endif //CHAIRLOADER_UPDATEHANDLER_H
