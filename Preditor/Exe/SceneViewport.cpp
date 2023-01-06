#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Prey/CryRenderer/IRenderer.h>
#include "SceneViewport.h"

SceneViewport::SceneViewport()
{
}

void SceneViewport::Update(bool isVisible)
{
}

void SceneViewport::OnActivate()
{
	assert(!m_bActive);
	m_bActive = true;
	gEnv->pHardwareMouse->IncrementCounter();
}

void SceneViewport::OnDeactivate()
{
	assert(m_bActive);
	m_bActive = false;
	SetMouseGrabbed(false);
	gEnv->pHardwareMouse->DecrementCounter();
}

void SceneViewport::ShowTopControls()
{
	ImGui::SameLine();
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

void SceneViewport::Render()
{
	CCamera oldCam = gEnv->pSystem->GetViewCamera();
	UpdateCamera();
	gEnv->pSystem->SetViewCamera(m_Cam);

	gEnv->p3DEngine->PrepareOcclusion(m_Cam);
	SRenderingPassInfo renderPassInfo = SRenderingPassInfo::CreateGeneralPassRenderingInfo(m_Cam);
	int renderFlags = SHDF_ALLOW_WATER | SHDF_ALLOWPOSTPROCESS | SHDF_ALLOWHDR | SHDF_ZPASS;
	gEnv->p3DEngine->ResetPostEffects(); // Reset menu blur effect
	gEnv->p3DEngine->RenderWorld(renderFlags, renderPassInfo, __FUNCTION__);

	gEnv->pSystem->SetViewCamera(oldCam);
}

void SceneViewport::SetMouseGrabbed(bool state)
{
	if (m_bGrabMouse == state)
		return;

	if (state)
	{
		gEnv->pHardwareMouse->DecrementCounter();
	}
	else
	{
		gEnv->pHardwareMouse->IncrementCounter();
	}

	m_bGrabMouse = state;
}

void SceneViewport::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
	if (event == ESYSTEM_EVENT_LEVEL_UNLOAD)
	{
		m_CamInfo.transformValid = false;
	}
}

void SceneViewport::UpdateCamera()
{
	const CCamera& viewCam = gEnv->pSystem->GetViewCamera();
	CameraInfo& info = m_CamInfo;

	if (!info.transformValid)
	{
		info.transformValid = true;
		CopyViewCameraTransform();
	}

	Matrix34 camMat;
	camMat.SetRotation33(Matrix33(Quat(info.rot)));
	camMat.SetTranslation(info.pos);
	m_Cam.SetMatrixNoUpdate(camMat);
	m_Cam.SetFrustum(viewCam.GetViewSurfaceX(), viewCam.GetViewSurfaceZ(), DEG2RAD(info.fov),
		info.nearPlane, info.farPlane, viewCam.GetPixelAspectRatio());
}

void SceneViewport::CopyViewCameraTransform()
{
	const CCamera& viewCam = gEnv->pSystem->GetViewCamera();
	m_CamInfo.pos = viewCam.GetMatrix().GetTranslation();
	m_CamInfo.rot = Ang3(viewCam.GetMatrix());
	m_CamInfo.rot.y = 0; // Reset roll
}
