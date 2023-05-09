#include <Chairloader/SteamAPI/IChairSteamAPI.h>
#include <Chairloader/IChairXmlUtils.h>
#include "SteamAPI/ArkSteamRewardSystem.h"

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
