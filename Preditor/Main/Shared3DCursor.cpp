#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include "Shared3DCursor.h"

Main::Shared3DCursor::Shared3DCursor()
{
    const size_t POINT_COUNT = 16;
    m_UnitCircle.resize(POINT_COUNT);
    m_TempCircle.resize(POINT_COUNT);
    
    for (size_t i = 0; i < POINT_COUNT; i++)
    {
        float angle = g_PI2 * ((float)i / (float)POINT_COUNT);
        m_UnitCircle[i] = Vec3(std::cos(angle), 0.0f, std::sin(angle));
    }
}

Main::Shared3DCursor::~Shared3DCursor()
{
}

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
    const float AXIS_SIZE = 0.03f;
    const float AXIS_THICKNESS = 1.0f;
    const float CIRCLE_RADIUS = 0.02f;
    const float CIRCLE_THICKNESS = 3.0f;

    Matrix34 cameraTm = gPreditor->pViewportWindow->GetSceneCameraTransform();
    Quat cameraRot = Quat(cameraTm);
    Vec3 forward = cameraRot * Vec3(0, 1, 0);
    IRenderAuxGeom* pAuxGeom = gEnv->pAuxGeomRenderer;
    SAuxGeomRenderFlags oldRenderFlags = pAuxGeom->GetRenderFlags();
    SAuxGeomRenderFlags newRenderFlags = oldRenderFlags;
    newRenderFlags.SetDepthTestFlag(e_DepthTestOff);
    pAuxGeom->SetRenderFlags(newRenderFlags);

    float fwdDist = forward.Dot(m_Pos - cameraTm.GetTranslation());

    // Draw axis
    float axisLen = AXIS_SIZE * fwdDist;
    Vec3 points[] = {
        m_Pos - Vec3(axisLen, 0, 0),
        m_Pos + Vec3(axisLen, 0, 0),
        m_Pos - Vec3(0, axisLen, 0),
        m_Pos + Vec3(0, axisLen, 0),
        m_Pos - Vec3(0, 0, axisLen),
        m_Pos + Vec3(0, 0, axisLen),
    };

    pAuxGeom->DrawLines(points, std::size(points), ColorB(32, 32, 32), AXIS_THICKNESS);

    // Draw circle
    for (size_t i = 0; i < m_TempCircle.size(); i++)
    {
        m_TempCircle[i] = m_Pos + cameraRot * ((CIRCLE_RADIUS * fwdDist) * m_UnitCircle[i]);
    }

    pAuxGeom->DrawPolyline(m_TempCircle.data(), m_TempCircle.size(), true, ColorB(245, 20, 20), CIRCLE_THICKNESS);

    pAuxGeom->SetRenderFlags(oldRenderFlags);
}
