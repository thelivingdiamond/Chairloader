#pragma once
#include <Prey/CrySystem/Ark/ArkRewardSystem.h>

//! Implementation of IArkRewardSystem using Steam API.
//! Unlike the original version, doesn't user RewardsThread.
class ArkSteamRewardSystem : public CArkRewardSystem
{
public:
    ArkSteamRewardSystem();

    virtual bool LoadRewardData(const string& _strRewardFile) override;
    virtual unsigned IncrementTrackableValue(unsigned _trackable) override;
    virtual unsigned IncrementTrackableValue(uint64_t _associatedMetric) override;
    virtual unsigned UpdateTrackableValueMax(uint64_t _associatedMetric, unsigned _value) override;
    virtual void UnlockReward(unsigned _reward) override;
    virtual void InternalRewardUnlocked(unsigned _rewardId) override;

private:
    //! Original code calls somewhere into gEnv->pSystem->GetIPlatformOS()
    inline bool IsSuppressed() { return false; }
    void TrackableChanged(unsigned trackable, unsigned oldVal, unsigned newVal);
};
