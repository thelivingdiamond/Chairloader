#include <Prey/GameDll/ark/player/ArkPlayerCamera.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Prey/CryAction/IViewSystem.h>
#include <Prey/CryInput/IInput.h>
#include "EditorView.h"
#include "Editor.h"

namespace
{

EditorView* g_pEditorView = nullptr;
auto g_ArkPlayerCamera_UpdateView_Hook = ArkPlayerCamera::FUpdateView.MakeHook();

float CV_ed_ViewMinSpeed;
float CV_ed_ViewMaxSpeed;
float CV_ed_ViewAccel;
float CV_ed_ViewDecel;
float CV_ed_ViewSens;
float CV_ed_ViewBoostScale;

//! Magic constant to make CV_ed_ViewSens feel like the setting in the options menu
constexpr float MOUSE_SENS_SCALE = 0.002f / 13;

void ArkPlayerCamera_UpdateView_Hook(ArkPlayerCamera* _this, SViewParams& _params)
{
	g_ArkPlayerCamera_UpdateView_Hook.InvokeOrig(_this, _params);
	
	if (Editor::Get()->IsInEditor())
		g_pEditorView->GetViewParams(_params);
}

}

void EditorView::InitHooks()
{
	g_ArkPlayerCamera_UpdateView_Hook.SetHookFunc(&ArkPlayerCamera_UpdateView_Hook);
}

EditorView::EditorView()
{
	assert(!g_pEditorView);
	g_pEditorView = this;

	REGISTER_CVAR2("ed_ViewMinSpeed", &CV_ed_ViewMinSpeed, 3, VF_NULL, "Editor: View minimum speed");
	REGISTER_CVAR2("ed_ViewMaxSpeed", &CV_ed_ViewMaxSpeed, 20, VF_NULL, "Editor: View maximum speed");
	REGISTER_CVAR2("ed_ViewAccel", &CV_ed_ViewAccel, 10, VF_NULL, "Editor: View acceleration");
	REGISTER_CVAR2("ed_ViewDecel", &CV_ed_ViewDecel, 3, VF_NULL, "Editor: View deceleration");
	REGISTER_CVAR2("ed_ViewSens", &CV_ed_ViewSens, 13, VF_NULL, "Editor: Mouse sensitivity");
	REGISTER_CVAR2("ed_ViewBoostScale", &CV_ed_ViewBoostScale, 5, VF_NULL, "Editor: Speed boost on SHIFT");
}

EditorView::~EditorView()
{
	assert(g_pEditorView == this);
	g_pEditorView = nullptr;
}

void EditorView::Update()
{
	if (!m_bGrabInput)
		return;

	// Rotation input
	{
		float sens = CV_ed_ViewSens * MOUSE_SENS_SCALE;
		m_vRot.x -= m_Input.mouseDelta.y * sens;
		m_vRot.x = std::clamp(m_vRot.x, -gf_PI * 0.5f, gf_PI * 0.5f);
		m_vRot.z -= m_Input.mouseDelta.x * sens;
		m_vRot.z = fmod(m_vRot.z, gf_PI2);
		m_Input.mouseDelta = Vec2(ZERO);
	}

	// Position input
	{
		Quat q(m_vRot);
		Vec3 fwd = q * Vec3(0, 1, 0);
		Vec3 right = q * Vec3(1, 0, 0);
		Vec3 up = Vec3(0, 0, 1); // Not influenced by rotation
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

		m_vPos += dir * m_MoveSpeed * timeDelta;
	}
}

bool EditorView::HandleInput(const SInputEvent& event)
{
	if (!m_bGrabInput)
		return false;

	if (event.deviceType == eIDT_Keyboard)
	{
		if (event.state == eIS_Pressed || event.state == eIS_Released)
		{
			bool isPressed = event.state == eIS_Pressed;

			if (event.keyId == eKI_W)
				m_Input.fwd = isPressed;

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
	}
	else if (event.deviceType == eIDT_Mouse)
	{
		if (event.keyId == eKI_MouseX)
			m_Input.mouseDelta.x += event.value;
		else if (event.keyId == eKI_MouseY)
			m_Input.mouseDelta.y += event.value;
	}

	return false;
}

void EditorView::GetViewParams(SViewParams& params)
{
	params.position = m_vPos;
	params.rotation = Quat(m_vRot);
	params.shakingRatio = 0;
}

void EditorView::SetGrabInput(bool state)
{
	m_bGrabInput = state;
	m_Input = InputState();
}
