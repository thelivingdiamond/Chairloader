#pragma once
#include <Prey/CrySystem/Ark/ArkRewardSystem.h>

//! Fixed version of CArkRewardSystem that actually calls
//! InternalTrackableUpdated and InternalRewardUnlocked.
//! Unlike the original version, doesn't use RewardsThread.
class ArkFixedRewardSystem : public CArkRewardSystem
{
public:
    virtual unsigned IncrementTrackableValue(unsigned _trackable) override;
    virtual unsigned IncrementTrackableValue(uint64_t _associatedMetric) override;
    virtual unsigned UpdateTrackableValueMax(uint64_t _associatedMetric, unsigned _value) override;
    virtual void UnlockReward(unsigned _reward) override;

private:
    //! Original code calls somewhere into gEnv->pSystem->GetIPlatformOS()
    inline bool IsSuppressed() { return false; }
    void TrackableChanged(unsigned trackable, unsigned oldVal, unsigned newVal);
};
