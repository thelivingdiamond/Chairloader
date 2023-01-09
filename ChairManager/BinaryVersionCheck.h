//
// Created by theli on 9/2/2022.
//
#pragma once
#include <string>
struct SemanticVersion;

namespace VersionCheck {
    SemanticVersion getBinaryVersion(fs::path szVersionFile);
    std::string getBinaryVersionString(fs::path szVersionFile);
    void fetchLatestVersion(bool bForce = false);
    SemanticVersion getInstalledChairloaderVersion();
    std::string getInstalledChairloaderVersionString();
    SemanticVersion getPackagedChairloaderVersion();
    std::string getPackagedChairloaderVersionString();
    SemanticVersion getLatestChairloaderVersion();
    std::string getLatestChairloaderVersionString();
};