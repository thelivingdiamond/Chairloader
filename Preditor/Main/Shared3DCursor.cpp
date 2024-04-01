#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include "Shared3DCursor.h"

void Main::Shared3DCursor::MoveToOrigin()
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

void Main::Shared3DCursor::MoveToCamera()
{
    Matrix34 cameraTm = gPreditor->pViewportWindow->GetSceneCameraTransform();
    SetPos(cameraTm.GetTranslation());
}

void Main::Shared3DCursor::ShowMenu()
{
    if (ImGui::BeginMenu("3D Cursor: Move To..."))
    {
        if (ImGui::MenuItem("Origin (0, 0, 0)"))
            MoveToOrigin();
        if (ImGui::MenuItem("Player"))
            MoveToPlayer();
        if (ImGui::MenuItem("Camera"))
            MoveToCamera();

        ImGui::EndMenu();
    }
}

void Main::Shared3DCursor::DrawAuxGeom()
{
    // TODO 2024-04-01: Something better
    gEnv->pAuxGeomRenderer->DrawSphere(m_Pos, 0.25f, ColorB(255, 0, 0), false);
}
