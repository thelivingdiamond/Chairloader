#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Prey/GameDll/ark/player/ArkPsiComponent.h>
#include <Prey/GameDll/ark/player/ability/ArkAbilityComponent.h>
#include "ArkPlayerCheats.h"

namespace
{

int pl_unlimitedPsi;

auto g_CArkPsiComponent_ConsumePoints_Hook = CArkPsiComponent::FConsumePoints.MakeHook();
auto g_CArkPsiComponent_ConsumePointsOrHealth_Hook = CArkPsiComponent::FConsumePointsOrHealth.MakeHook();

void CArkPsiComponent_ConsumePoints_Hook(CArkPsiComponent* const _this, const float _value)
{
    if (pl_unlimitedPsi)
        return;

    g_CArkPsiComponent_ConsumePoints_Hook.InvokeOrig(_this, _value);
}

bool CArkPsiComponent_ConsumePointsOrHealth_Hook(CArkPsiComponent* const _this, const float _value)
{
    if (pl_unlimitedPsi)
        return true;

    return g_CArkPsiComponent_ConsumePointsOrHealth_Hook.InvokeOrig(_this, _value);
}

} // namespace

void ArkPlayerCheats::InitHooks()
{
    g_CArkPsiComponent_ConsumePoints_Hook.SetHookFunc(&CArkPsiComponent_ConsumePoints_Hook);
    g_CArkPsiComponent_ConsumePointsOrHealth_Hook.SetHookFunc(&CArkPsiComponent_ConsumePointsOrHealth_Hook);
}

void ArkPlayerCheats::InitGame()
{
    REGISTER_CVAR(pl_unlimitedPsi, 0, VF_CHEAT, "Unlimited PSI points");

    REGISTER_COMMAND("pl_grantskill", &GrantSkill, VF_CHEAT, "Grant a neuromod ability");
    REGISTER_COMMAND("pl_maxSkills", &MaxSkills, VF_CHEAT, "Grant all neuromod abilities");
    // pl_minSkills

    // pl_disablecooldowns 0/1
    // pl_forcezerogmode 0/1
    // pl_collectAllData cmd
    // pl_completeResearchTopics cmd
    // pl_incrementResearchTopicScanCount cmd
    // pl_setweaponcondition
    // pl_arkflymode 0/1/2
}

void ArkPlayerCheats::GrantSkill(IConsoleCmdArgs* pArgs)
{
    if (pArgs->GetArgCount() != 2)
    {
        CryLog("Usage: {} <ability id>", pArgs->GetArg(0));
        return;
    }

    ArkPlayer* pPlayer = ArkPlayer::GetInstancePtr();

    if (!pPlayer)
    {
        CryError("Player doesn't exist");
        return;
    }

    uint64_t ability = strtoull(pArgs->GetArg(1), nullptr, 10);

    if (ability != 0)
    {
        pPlayer->m_playerComponent.m_pAbilityComponent->OnGrantAbilityCheat(ability, false);
    }
}

void ArkPlayerCheats::MaxSkills(IConsoleCmdArgs* pArgs)
{
    ArkPlayer* pPlayer = ArkPlayer::GetInstancePtr();

    if (!pPlayer)
    {
        CryError("Player doesn't exist");
        return;
    }

    ArkAbilityComponent* pAbilityComponent = pPlayer->m_playerComponent.m_pAbilityComponent.get();

    for (const ArkAbilityData& ability : pAbilityComponent->m_abilities)
    {
        pPlayer->m_playerComponent.m_pAbilityComponent->OnGrantAbilityCheat(ability.m_id, false);
    }
}
