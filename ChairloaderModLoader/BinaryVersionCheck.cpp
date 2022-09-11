//
// Created by theli on 9/2/2022.
//
#include "BinaryVersionCheck.h"
#include <ModLoader/PathUtils.h>
#include <Windows.h>
#include <winver.h>
#include "ModLoader.h"




VersionCheck::DLLVersion VersionCheck::getInstalledChairloaderVersion() {
    auto szVersionFile = ModLoader::Get().GetGamePath() / PathUtils::GAME_BIN_DIR / "Chairloader.dll";
    return getBinaryVersion(szVersionFile);
}

VersionCheck::DLLVersion VersionCheck::getPackagedChairloaderVersion() {
    auto szVersionFile = fs::path("Release") / "Chairloader.dll";
    return getBinaryVersion(szVersionFile);
}

VersionCheck::DLLVersion VersionCheck::getBinaryVersion(fs::path szVersionFile) {
    DWORD verHandle = 0;
    UINT size = 0;
    LPBYTE lpBuffer = NULL;
    DWORD verSize = GetFileVersionInfoSizeW(szVersionFile.wstring().data(), &verHandle);
    if (verSize != 0) {
        LPSTR verData = new char[verSize];
        if(GetFileVersionInfoW(szVersionFile.wstring().data(), verHandle, verSize, verData)){
            if(VerQueryValueW(verData, L"\\", (VOID FAR* FAR*)&lpBuffer, &size)){
                if (size) {
                    auto *verInfo = (VS_FIXEDFILEINFO *)lpBuffer;
                    if (verInfo->dwSignature == 0xfeef04bd) {
//                        std::string version = boost::str(boost::format("%d.%d.%d.%d")
//                                                         % ((verInfo->dwFileVersionMS >> 16) & 0xffff)
//                                                         % ((verInfo->dwFileVersionMS >> 0) & 0xffff)
//                                                         % ((verInfo->dwFileVersionLS >> 16) & 0xffff)
//                                                         % ((verInfo->dwFileVersionLS >> 0) & 0xffff));
                        return {static_cast<uint16_t>(((verInfo->dwFileVersionMS >> 16) & 0xffff)),
                                static_cast<uint16_t>(((verInfo->dwFileVersionMS >> 0) & 0xffff)),
                                static_cast<uint16_t>(((verInfo->dwFileVersionLS >> 16) & 0xffff)),
                                static_cast<uint16_t>(((verInfo->dwFileVersionLS >> 0) & 0xffff))};
                    }
                }
            }
        }
    }
    return {0,0,0,0};
}


std::string VersionCheck::DLLVersion::String() {
    return boost::str(boost::format("%d.%d.%d.%d") % major % minor % patch % build);
}
