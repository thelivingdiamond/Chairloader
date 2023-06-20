#include "ArkFixedRewardSystem.h"

unsigned ArkFixedRewardSystem::IncrementTrackableValue(unsigned _trackable)
{
    int oldVal = m_trackables[_trackable].value;
    int newVal = oldVal + 1;
    m_trackables[_trackable].value = newVal;
    TrackableChanged(_trackable, oldVal, newVal);
    return newVal;
}

unsigned ArkFixedRewardSystem::IncrementTrackableValue(uint64_t _associatedMetric)
{
    if (_associatedMetric == kNoAssociatedMetric)
        return 0;

    ArkRewardTrackable* pTrackable = m_trackablesByMetric[_associatedMetric];

    if (!pTrackable)
        return 0;

    // ???
    if (pTrackable->value >= 0x0FFF'FFFF)
        return 0;

    return IncrementTrackableValue(pTrackable->id);
}

unsigned ArkFixedRewardSystem::UpdateTrackableValueMax(uint64_t _associatedMetric, unsigned _value)
{
    if (_associatedMetric == kNoAssociatedMetric)
        return 0;

    ArkRewardTrackable* pTrackable = m_trackablesByMetric[_associatedMetric];

    if (!pTrackable)
        return 0;

    int oldVal = pTrackable->value;
    if (_value > oldVal)
    {
        pTrackable->value = _value;
        TrackableChanged(pTrackable->id, oldVal, _value);
        return _value;
    }
    else
    {
        return oldVal;
    }
}

void ArkFixedRewardSystem::UnlockReward(unsigned _reward)
{
    if (IsSuppressed())
    {
        CryLog("[ArkFixedRewardSystem] UnlockReward suppressed (rewardId: {})", _reward);
        return;
    }

    CryLog("ArkFixedRewardSystem::UnlockReward: {}", _reward);

    ArkReward& reward = m_rewards[_reward];

    if (!reward.bCriteriaMet)
    {
        reward.bCriteriaMet = true;

        // Original code passes this to the reward thread, which will call the handler.
        // I don't want to deal with threading. It shouldn't block anyway.
        InternalRewardUnlocked(reward.unlockId);
        if (m_pHandler)
            m_pHandler->OnRewardUnlocked(m_userId, reward.unlockId);
    }
}

void ArkFixedRewardSystem::TrackableChanged(unsigned trackable, unsigned oldVal, unsigned newVal)
{
    if (IsSuppressed())
    {
        CryLog("[ArkFixedRewardSystem] TrackChanged reward suppressed (trackableId: {}) (oldValue: {}) (newValue: {})",
            trackable, oldVal, newVal);
        return;
    }

    ArkRewardTrackable* pTrackable = &m_trackables[trackable];
    CryLog("ArkFixedRewardSystem::TrackableChanged: [{}] {} -> {}", trackable, oldVal, newVal);

    // See if need to unlock any rewards
    for (ArkReward& reward : m_rewards)
    {
        bool needUnlock = false;

        for (ArkRewardTrackableCriteria& criteria : reward.criteria)
        {
            if (!criteria.bCriteriaMet &&
                criteria.trackable == pTrackable &&
                criteria.trackable->value >= criteria.value)
            {
                criteria.bCriteriaMet = true;
                needUnlock = true;
            }
        }

        if (needUnlock)
        {
            reward.bCriteriaMet = true;

            // Original code passes this to the reward thread 
            InternalRewardUnlocked(reward.unlockId);
        }
    }

    InternalTrackableUpdated(trackable, oldVal, newVal);
    if (m_pHandler)
        m_pHandler->OnChangedTrackable(m_userId, trackable, oldVal, newVal);
}
