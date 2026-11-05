#pragma once
#ifndef MOONCRASH // Prey only: Mooncrash keeps the game's CArkSteamDlcSystem (see ChairSteamAPI::ReplaceArkSystems)
#include <Prey/CrySystem/Ark/ArkDlcSystem.h>

//! IArkDlcSystem implementation using Steam API.
class ArkSteamDlcSystem final : public CArkDlcSystem
{
public:
    virtual void InitEnv(SSystemGlobalEnvironment* _gEnv) override;
    virtual void Refresh() override;
};
#endif