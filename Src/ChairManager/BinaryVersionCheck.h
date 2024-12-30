//
// Created by theli on 9/2/2022.
//

#ifndef CHAIRLOADER_BINARYVERSIONCHECK_H
#define CHAIRLOADER_BINARYVERSIONCHECK_H

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
//! \param etag If set, that ETag is added to the request.
//! @returns Pair: version string and ETag. IF version is empty, it hasn't changed.
    std::pair<std::string, std::string> fetchLatestVersion(std::string_view etag);

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
};

#endif //CHAIRLOADER_BINARYVERSIONCHECK_H