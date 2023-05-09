#include <Chairloader/SteamAPI/IChairSteamAPI.h>
#include "SteamAPI/ArkSteamDlcSystem.h"

void ArkSteamDlcSystem::InitEnv(SSystemGlobalEnvironment* _gEnv)
{
    CArkDlcSystem::InitEnv(_gEnv);
    RequestRefresh();
}

void ArkSteamDlcSystem::Refresh()
{
    CArkDlcSystem::Refresh();
    ISteamApps* pSteamApps = SteamApps();

    for (auto& [name, dlcInfo] : m_dlcPlatformIdMap)
    {
        AppId_t steamAppId = std::strtol(dlcInfo.SteamId.c_str(), nullptr, 10);
        bool isInstalled = pSteamApps->BIsDlcInstalled(steamAppId);
        UpdateDlcUnlocked(&dlcInfo, isInstalled);

        if (isInstalled)
            CryLog("[ArkSteamDlcSystem] DLC {} is installed", dlcInfo.Name);
    }
}
