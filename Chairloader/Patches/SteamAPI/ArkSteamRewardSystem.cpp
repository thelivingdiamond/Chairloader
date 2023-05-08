#include <Chairloader/SteamAPI/IChairSteamAPI.h>
#include <Chairloader/IChairXmlUtils.h>
#include "ArkSteamRewardSystem.h"

ArkSteamRewardSystem::ArkSteamRewardSystem()
{
    // Replace existing reward system
    delete gEnv->pArkRewardSystem;
    gEnv->pArkRewardSystem = this;
}

bool ArkSteamRewardSystem::LoadRewardData(const string& _strRewardFile)
{
    if (!CArkRewardSystem::LoadRewardData(_strRewardFile))
        return false;

    // Load SteamIDs for rewards
    pugi::xml_document xmlDoc = gCL->pXmlUtils->LoadXmlFromFile(_strRewardFile);
    pugi::xml_node root = xmlDoc.child("ArkRewards");
    pugi::xml_node rewards = root.child("Rewards");

    for (pugi::xml_node reward : rewards.children("Reward"))
    {
        unsigned id = reward.attribute("ID").as_uint();
        if (id >= m_rewards.size())
        {
            CryError("ArkSteamRewardSystem: Reward ID {} is invalid (greater than or equal to count = {})", id, m_rewards.size());
            continue;
        }

        int steamId = reward.attribute("SteamID").as_int();
        m_rewards[id].unlockId = steamId;
    }

    return true;
}

unsigned ArkSteamRewardSystem::IncrementTrackableValue(unsigned _trackable)
{
    int oldVal = m_trackables[_trackable].value;
    int newVal = oldVal + 1;
    m_trackables[_trackable].value = newVal;
    TrackableChanged(_trackable, oldVal, newVal);
    return newVal;
}

unsigned ArkSteamRewardSystem::IncrementTrackableValue(uint64_t _associatedMetric)
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

unsigned ArkSteamRewardSystem::UpdateTrackableValueMax(uint64_t _associatedMetric, unsigned _value)
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

void ArkSteamRewardSystem::UnlockReward(unsigned _reward)
{
    if (IsSuppressed())
    {
        CryLog("[ArkSteamRewardSystem] UnlockReward suppressed (rewardId: {})", _reward);
        return;
    }

    CryLog("ArkSteamRewardSystem::UnlockReward: {}", _reward);

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

void ArkSteamRewardSystem::InternalRewardUnlocked(unsigned unlockId)
{
    // unlockId = ArkReward::unlockId
    CArkRewardSystem::InternalRewardUnlocked(unlockId);

    const char* name = SteamUserStats()->GetAchievementName(unlockId);
    if (!name)
    {
        CryError("[ArkSteamRewardSystem] Unknown unlockId {}", unlockId);
        return;
    }

    const char* displayName = SteamUserStats()->GetAchievementDisplayAttribute(name, "name");
    CryLog("[ArkSteamRewardSystem] Unlocking '{}' (id = {}, name = {})", displayName, unlockId, name);
    SteamUserStats()->SetAchievement(name);
    SteamUserStats()->StoreStats();
}

void ArkSteamRewardSystem::TrackableChanged(unsigned trackable, unsigned oldVal, unsigned newVal)
{
    if (IsSuppressed())
    {
        CryLog("[ArkSteamRewardSystem] TrackChanged reward suppressed (trackableId: {}) (oldValue: {}) (newValue: {})",
            trackable, oldVal, newVal);
        return;
    }

    ArkRewardTrackable* pTrackable = &m_trackables[trackable];
    CryLog("ArkSteamRewardSystem::TrackableChanged: [{}] {} -> {}", trackable, oldVal, newVal);

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
