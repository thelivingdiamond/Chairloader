#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include "SceneViewport.h"

Viewport::SceneViewport::SceneViewport()
{
	gEnv->pSystem->GetISystemEventDispatcher()->RegisterListener(this);
}

Viewport::SceneViewport::~SceneViewport()
{
	gEnv->pSystem->GetISystemEventDispatcher()->RemoveListener(this);
}

void Viewport::SceneViewport::CustomRender()
{
	DrawAuxGeom();

	// Draw player in the world since camera can now move
	// TODO 2023-06-17: Gun, held object need to be changed too
	uint32 oldPlayerFlags = 0;
	if (ArkPlayer::GetInstancePtr())
	{
		IEntity* pEnt = ArkPlayer::GetInstancePtr()->GetEntity();
		oldPlayerFlags = pEnt->GetSlotFlags(0);
		pEnt->SetSlotFlags(0, oldPlayerFlags & (~ENTITY_SLOT_RENDER_NEAREST));
	}

	CCamera oldCam = gEnv->pSystem->GetViewCamera();
	UpdateCamera();
	gEnv->pSystem->SetViewCamera(m_Cam);

	gEnv->p3DEngine->PrepareOcclusion(m_Cam);
	SRenderingPassInfo renderPassInfo = SRenderingPassInfo::CreateGeneralPassRenderingInfo(m_Cam);
	int renderFlags = SHDF_ALLOW_WATER | SHDF_ALLOWPOSTPROCESS | SHDF_ALLOWHDR | SHDF_ZPASS;
	gEnv->p3DEngine->ResetPostEffects(); // Reset menu blur effect
	gEnv->p3DEngine->RenderWorld(renderFlags, renderPassInfo, __FUNCTION__);

	gEnv->pSystem->SetViewCamera(oldCam);

	// Restore slot flags
	if (ArkPlayer::GetInstancePtr())
		ArkPlayer::GetInstancePtr()->GetEntity()->SetSlotFlags(0, oldPlayerFlags);
}

void Viewport::SceneViewport::OnEnabled()
{
    // Scene doesn't use engine mouse input
    m_InputEnabled.SetIncremented(true);
    gPreditor->pEngine->SetGameInputEnabled(false);
}

void Viewport::SceneViewport::OnDisabled()
{
    // Restore counter
    m_InputEnabled.SetIncremented(false);
}

void Viewport::SceneViewport::ShowUI()
{
	ImGui::SameLine();
	ShowCameraMenu();

	ShowViewportImage();
}

void Viewport::SceneViewport::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
	if (event == ESYSTEM_EVENT_LEVEL_UNLOAD)
	{
		m_CamInfo.transformValid = false;
	}
}

void Viewport::SceneViewport::ShowCameraMenu()
{
	if (ImGui::Button("Camera"))
		ImGui::OpenPopup("CameraMenu");

	if (ImGui::BeginPopupContextItem("CameraMenu"))
	{
		constexpr float MIN_PLANE = 0.001f;
		constexpr float MAX_PLANE = 4096;
		constexpr float DELTA_PLANE = 16;
		constexpr char FORMAT[] = "%0.3f";
		constexpr ImGuiSliderFlags FLAGS = ImGuiSliderFlags_Logarithmic;

		CameraInfo& info = m_CamInfo;

		if (ImGui::Button("TP to Player View"))
			CopyViewCameraTransform();

		ImGui::SliderFloat("FOV", &info.fov, 10, 150);
		ImGui::DragFloat3("Position", &info.pos.x);

		Ang3 rot = RAD2DEG(info.rot);
		if (ImGui::DragFloat3("Rotation", &rot.x))
			info.rot = DEG2RAD(rot);

		if (ImGui::DragFloat("Near Plane", &info.nearPlane, 0.25f, MIN_PLANE, info.farPlane, FORMAT, FLAGS))
		{
			if (info.farPlane - info.nearPlane < DELTA_PLANE)
				info.nearPlane = info.farPlane - DELTA_PLANE;
		}

		if (ImGui::DragFloat("Far Plane", &info.farPlane, 0.25f, info.nearPlane, MAX_PLANE, FORMAT, FLAGS))
		{
			if (info.farPlane - info.nearPlane < DELTA_PLANE)
				info.farPlane = info.nearPlane + DELTA_PLANE;
		}

		if (ImGui::Button("Reset Planes"))
		{
			info.nearPlane = DEFAULT_NEAR;
			info.farPlane = DEFAULT_FAR;
		}

		ImGui::EndPopup();
	}
}

void Viewport::SceneViewport::UpdateCamera()
{
	const CCamera& viewCam = gEnv->pSystem->GetViewCamera();
	CameraInfo& info = m_CamInfo;

	if (!info.transformValid)
	{
		info.transformValid = true;
		CopyViewCameraTransform();
	}

	Quat rotQuat = Quat(info.rot);

	// TODO 2023-06-17: Implement input

	Matrix34 camMat;
	camMat.SetRotation33(Matrix33(rotQuat));
	camMat.SetTranslation(info.pos);
	m_Cam.SetMatrixNoUpdate(camMat);
	m_Cam.SetFrustum(viewCam.GetViewSurfaceX(), viewCam.GetViewSurfaceZ(), DEG2RAD(info.fov),
		info.nearPlane, info.farPlane, viewCam.GetPixelAspectRatio());
}

void Viewport::SceneViewport::CopyViewCameraTransform()
{
	const CCamera& viewCam = gEnv->pSystem->GetViewCamera();
	m_CamInfo.pos = viewCam.GetMatrix().GetTranslation();
	m_CamInfo.rot = Ang3(viewCam.GetMatrix());
	m_CamInfo.rot.y = 0; // Reset roll
}

void Viewport::SceneViewport::DrawAuxGeom()
{
	DrawViewCameraFrustum();
}

void Viewport::SceneViewport::DrawViewCameraFrustum()
{
	const CCamera& viewCam = gEnv->pSystem->GetViewCamera();
	gEnv->pAuxGeomRenderer->DrawSphere(viewCam.GetPosition(), 0.05f, ColorB(255, 0, 0));
	gEnv->pAuxGeomRenderer->DrawSphere(viewCam.GetOccPos(), 0.03f, ColorB(0, 255, 0));

	// Near plane camera-space pos
	Vec3 planePos[8];
	std::fill(planePos, planePos + 4, viewCam.GetEdgeN());
	planePos[1].x *= -1; // right top
	planePos[2].x *= -1; // right bottom
	planePos[2].z *= -1;
	planePos[3].z *= -1; // left bottom

	// Near plane world pos
	Matrix34 camMat = viewCam.GetMatrix();
	for (int i = 0; i < 4; i++)
		planePos[i] = camMat * planePos[i];

	// 1 meter plane
	for (int i = 0; i < 4; i++)
	{
		Vec3 nearLocal = planePos[i] - viewCam.GetPosition();
		nearLocal.NormalizeSafe();
		planePos[i + 4] = viewCam.GetPosition() + nearLocal;
	}

	// Assemble indices
	vtx_idx indices[] = {
		// Near plane
		0, 1, 1, 2, 2, 3, 3, 0,
		// 1m plane
		4, 5, 5, 6, 6, 7, 7, 4,
		// Edges
		0, 4, 1, 5, 2, 6, 3, 7,
	};

	gEnv->pAuxGeomRenderer->DrawLines(planePos, std::size(planePos), indices, std::size(indices), ColorB(0, 255, 255));
}
