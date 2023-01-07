#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Prey/CryRenderer/IRenderer.h>
#include "SceneViewport.h"

//! Magic constant to make CV_ed_ViewSens feel like the setting in the options menu
constexpr float MOUSE_SENS_SCALE = 0.002f / 13;

float CV_ed_ViewMinSpeed;
float CV_ed_ViewMaxSpeed;
float CV_ed_ViewAccel;
float CV_ed_ViewDecel;
float CV_ed_ViewSens;
float CV_ed_ViewBoostScale;

SceneViewport::SceneViewport()
{
	gEnv->pSystem->GetISystemEventDispatcher()->RegisterListener(this);

	REGISTER_CVAR2("ed_ViewMinSpeed", &CV_ed_ViewMinSpeed, 3, VF_NULL, "Editor: View minimum speed");
	REGISTER_CVAR2("ed_ViewMaxSpeed", &CV_ed_ViewMaxSpeed, 20, VF_NULL, "Editor: View maximum speed");
	REGISTER_CVAR2("ed_ViewAccel", &CV_ed_ViewAccel, 10, VF_NULL, "Editor: View acceleration");
	REGISTER_CVAR2("ed_ViewDecel", &CV_ed_ViewDecel, 3, VF_NULL, "Editor: View deceleration");
	REGISTER_CVAR2("ed_ViewSens", &CV_ed_ViewSens, 13, VF_NULL, "Editor: Mouse sensitivity");
	REGISTER_CVAR2("ed_ViewBoostScale", &CV_ed_ViewBoostScale, 5, VF_NULL, "Editor: Speed boost on SHIFT");
}

SceneViewport::~SceneViewport()
{
	if (gEnv)
		gEnv->pSystem->GetISystemEventDispatcher()->RemoveListener(this);
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
		gEnv->pHardwareMouse->GetHardwareMousePosition(&m_SavedMousePos.x, &m_SavedMousePos.y);
		gEnv->pHardwareMouse->DecrementCounter();
		ImGui::SetMouseCursor(ImGuiMouseCursor_None);
	}
	else
	{
		gEnv->pHardwareMouse->IncrementCounter();
		gEnv->pHardwareMouse->SetHardwareMousePosition(m_SavedMousePos.x, m_SavedMousePos.y);
		
		// Reset input
		m_Input = InputState();
	}

	m_bGrabMouse = state;
}

bool SceneViewport::HandleInputEventPreGame(const SInputEvent& event)
{
	if (event.keyId == eKI_Mouse2)
	{
		if (event.state == eIS_Pressed)
			SetMouseGrabbed(true);
		else if (event.state == eIS_Released)
			SetMouseGrabbed(false);
	}

	if (m_bGrabMouse)
	{
		HandleCameraInput(event);
	}
	else
	{

	}

	return true;
}

void SceneViewport::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
	if (event == ESYSTEM_EVENT_LEVEL_UNLOAD)
	{
		m_CamInfo.transformValid = false;
	}
}

void SceneViewport::HandleCameraInput(const SInputEvent& event)
{
	if (event.deviceType == eIDT_Keyboard)
	{
		if (event.state == eIS_Pressed || event.state == eIS_Released)
		{
			bool isPressed = event.state == eIS_Pressed;

			switch (event.keyId)
			{
			case eKI_W: m_Input.fwd = isPressed; break;
			case eKI_A: m_Input.left = isPressed; break;
			case eKI_S: m_Input.back = isPressed; break;
			case eKI_D: m_Input.right = isPressed; break;
			case eKI_Q: m_Input.up = isPressed; break;
			case eKI_E: m_Input.down = isPressed; break;
			case eKI_LShift: m_Input.boost = isPressed; break;
			}
		}

		return;
	}

	switch (event.keyId)
	{
	case eKI_MouseX:
	case eKI_MouseY:
	{
		// Restore old mouse pos
		gEnv->pHardwareMouse->SetHardwareMousePosition(m_SavedMousePos.x, m_SavedMousePos.y);

		float sens = CV_ed_ViewSens * MOUSE_SENS_SCALE;

		if (event.keyId == eKI_MouseX)
		{
			// Yaw
			m_CamInfo.rot.z -= event.value * sens;
			m_CamInfo.rot.z = fmod(m_CamInfo.rot.z, gf_PI2);
		}
		else if (event.keyId == eKI_MouseY)
		{
			// Pitch
			m_CamInfo.rot.x -= event.value * sens;
			m_CamInfo.rot.x = std::clamp(m_CamInfo.rot.x, -gf_PI * 0.5f, gf_PI * 0.5f);
		}
		break;
	}

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

	Quat rotQuat = Quat(info.rot);

	// Positional input
	{
		Vec3 fwd = rotQuat * Vec3(0, 1, 0);
		Vec3 right = rotQuat * Vec3(1, 0, 0);
		Vec3 up = rotQuat * Vec3(0, 0, 1);
		float timeDelta = gEnv->pTimer->GetRealFrameTime();

		Vec3 dir = Vec3(ZERO);

		if (m_Input.fwd)
			dir += fwd;
		if (m_Input.back)
			dir -= fwd;

		if (m_Input.right)
			dir += right;
		if (m_Input.left)
			dir -= right;

		if (m_Input.up)
			dir += up;
		if (m_Input.down)
			dir -= up;

		dir.NormalizeSafe();

		Vec2 speedLimit = Vec2(CV_ed_ViewMinSpeed, CV_ed_ViewMaxSpeed);
		float accel = CV_ed_ViewAccel;

		if (m_Input.boost)
		{
			speedLimit *= CV_ed_ViewBoostScale;
			accel *= CV_ed_ViewBoostScale;
		}

		if (dir != Vec3(ZERO))
		{
			m_MoveSpeed += accel * timeDelta;
			m_MoveSpeed = std::clamp(m_MoveSpeed, speedLimit.x, speedLimit.y);
		}
		else
		{
			m_MoveSpeed -= accel * timeDelta;
			m_MoveSpeed = std::max(0.0f, m_MoveSpeed);
		}

		info.pos += dir * m_MoveSpeed * timeDelta;
	}

	Matrix34 camMat;
	camMat.SetRotation33(Matrix33(rotQuat));
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
