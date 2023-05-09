#pragma once
#include "ArkFixedRewardSystem.h"

//! Implementation of IArkRewardSystem using Steam API.
class ArkSteamRewardSystem : public ArkFixedRewardSystem
{
public:
    ArkSteamRewardSystem();

    virtual bool LoadRewardData(const string& _strRewardFile) override;
    virtual void InternalRewardUnlocked(unsigned _rewardId) override;
};
