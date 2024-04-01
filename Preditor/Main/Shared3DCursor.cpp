#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include "Shared3DCursor.h"

void Main::Shared3DCursor::MoveToZero()
{
    SetPos(ZERO);
}

void Main::Shared3DCursor::MoveToPlayer()
{
    ArkPlayer* pPlayer = ArkPlayer::GetInstancePtr();

    if (!pPlayer)
    {
        CryError("Shared3DCursor::MoveToPlayer: Player is null");
        return;
    }

    SetPos(pPlayer->GetEntity()->GetWorldPos());
}

void Main::Shared3DCursor::DrawAuxGeom()
{
    // TODO 2024-04-01: Something better
    gEnv->pAuxGeomRenderer->DrawSphere(m_Pos, 0.25f, ColorB(255, 0, 0), false);
}
