//
// Created by theli on 9/2/2022.
//

#ifndef CHAIRLOADER_BINARYVERSIONCHECK_H
#define CHAIRLOADER_BINARYVERSIONCHECK_H

#pragma once
#include <string>
struct SemanticVersion;

namespace VersionCheck {
//! Get the DLL version for a given DLL file
//! \param szVersionFile The DLL file to get the version for
//! \return The Semantic Versioning DLL version
    SemanticVersion getBinaryVersion(fs::path szVersionFile);

//! Get the DLL version for a given DLL file
//! \param szVersionFile The DLL file to get the version for
//! \return The version string
    std::string getBinaryVersionString(fs::path szVersionFile);

//!  Fetch the latest version of Chairloader from the GitHub API
//! \param bForce Force a refresh of the version, even if it's already cached
    void fetchLatestVersion(bool bForce = false);

//! Get the Installed Chairloader version
//! \return The Semantic Version
    SemanticVersion getInstalledChairloaderVersion();

//! Get the Installed Chairloader version
//! \return The version string
    std::string getInstalledChairloaderVersionString();

//! Get the Chairloader version in the Release folder
//! \return The Semantic Version
    SemanticVersion getPackagedChairloaderVersion();

//! Get the Chairloader version in the Release folder
//! \return The version string
    std::string getPackagedChairloaderVersionString();

//! Get the latest Chairloader version from the GitHub API
//! \return The Semantic Version
    SemanticVersion getLatestChairloaderVersion();

//! Get the latest Chairloader version from the GitHub API
//! \return The version string
    std::string getLatestChairloaderVersionString();
};

#endif //CHAIRLOADER_BINARYVERSIONCHECK_H