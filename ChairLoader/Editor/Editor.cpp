#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CryAction/IViewSystem.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryGame/Game.h>
#include <Prey/GameDll/ui/UIManager.h>
#include <Prey/GameDll/ark/ArkGame.h>
#include <Prey/GameDll/ark/ui/ArkPauseMenu.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Prey/GameDll/ark/player/ArkPlayerInput.h>
#include "Editor.h"
#include "../ChairLoader.h"

namespace
{

//! RAII struct to protect against reentrancy
struct ReentranceGuard
{
	bool* pVar = nullptr;
	ReentranceGuard(bool* var) { pVar = var; *var = true; }
	~ReentranceGuard() { *pVar = false; }
};

Editor* g_pEditor = nullptr;
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
	if (g_pEditor->UpdateView(_params))
		return;
	g_ArkPlayerCamera_UpdateView_Hook.InvokeOrig(_this, _params);
}

const char* GetSystemGlobalStateName(const ESystemGlobalState systemGlobalState)
{
	static const char* const s_systemGlobalStateNames[] = {
		"UNKNOWN",                 // ESYSTEM_GLOBAL_STATE_UNKNOWN,
		"INIT",                    // ESYSTEM_GLOBAL_STATE_INIT,
		"RUNNING",                 // ESYSTEM_GLOBAL_STATE_RUNNING,
		"LEVEL_LOAD_PREPARE",      // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_PREPARE,
		"LEVEL_LOAD_START",        // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START,
		"LEVEL_LOAD_MATERIALS",    // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_MATERIALS,
		"LEVEL_LOAD_OBJECTS",      // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_OBJECTS,
		"LEVEL_LOAD_CHARACTERS",   // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_CHARACTERS,
		"LEVEL_LOAD_STATIC_WORLD", // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_STATIC_WORLD,
		"LEVEL_LOAD_ENTITIES",     // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_ENTITIES,
		"LEVEL_LOAD_PRECACHE",     // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_PRECACHE,
		"LEVEL_LOAD_TEXTURES",     // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_TEXTURES,
		"LEVEL_LOAD_END",          // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_END,
		"LEVEL_LOAD_COMPLETE"      // ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_COMPLETE
	};
	const size_t numElements = CRY_ARRAY_COUNT(s_systemGlobalStateNames);
	const size_t index = (size_t)systemGlobalState;
	if (index >= numElements)
	{
		return "INVALID INDEX";
	}
	return s_systemGlobalStateNames[index];
}

}

void Editor::InitHooks()
{
	g_ArkPlayerCamera_UpdateView_Hook.SetHookFunc(&ArkPlayerCamera_UpdateView_Hook);
}

Editor* Editor::Get()
{
	return g_pEditor;
}

Editor::Editor()
{
	assert(!g_pEditor);
	g_pEditor = this;

	REGISTER_CVAR2("ed_ViewMinSpeed", &CV_ed_ViewMinSpeed, 3, VF_NULL, "Editor: View minimum speed");
	REGISTER_CVAR2("ed_ViewMaxSpeed", &CV_ed_ViewMaxSpeed, 20, VF_NULL, "Editor: View maximum speed");
	REGISTER_CVAR2("ed_ViewAccel", &CV_ed_ViewAccel, 10, VF_NULL, "Editor: View acceleration");
	REGISTER_CVAR2("ed_ViewDecel", &CV_ed_ViewDecel, 3, VF_NULL, "Editor: View deceleration");
	REGISTER_CVAR2("ed_ViewSens", &CV_ed_ViewSens, 13, VF_NULL, "Editor: Mouse sensitivity");
	REGISTER_CVAR2("ed_ViewBoostScale", &CV_ed_ViewBoostScale, 5, VF_NULL, "Editor: Speed boost on SHIFT");
}

Editor::~Editor()
{
	assert(g_pEditor == this);
	g_pEditor = nullptr;
}

void Editor::Update()
{
	SwitchStates();

	switch (m_State)
	{
	case State::Unloaded:
		UpdateUnloaded();
		break;
	case State::Loading:
		UpdateLoading();
		break;
	case State::Running:
		UpdateRunning();
		break;
	default:
		assert(false);
		std::abort();
		break;
	}

	if (ImGui::Begin("Editor Debug"))
	{
		auto pgfw = gCL->GetFramework();
		ArkGame* pGame = g_pGame->m_pArkGame.get();
		ImGui::Text("IsGameStarted: %d", pgfw->IsGameStarted());
		ImGui::Text("IsGamePaused: %d", pgfw->IsGamePaused());
		ImGui::Text("m_pauseRequestStatus: %d", pGame->m_pauseRequestStatus);
		ImGui::Text("m_saveFileToLoad: %s %lld", pGame->m_saveFileToLoad.c_str(), pGame->m_saveFileToLoad.size());
		ImGui::Text("Global State: %s", GetSystemGlobalStateName(gEnv->pSystem->GetSystemGlobalState()));
	}
	ImGui::End();
}

bool Editor::HandleKeyPress(const SInputEvent& event)
{
	// Calling DecrementCounter causes stack overflow
	static bool isEntered = false;
	if (isEntered)
		return false;
	ReentranceGuard rg(&isEntered);

	if (event.deviceType == eIDT_Keyboard && event.state == eIS_Pressed)
	{
		if (event.keyId == eKI_P)
		{
			SetGamePaused(!m_bIsGamePaused);
			return true;
		}

		if (event.keyId == eKI_F4)
		{
			SetInEditor(!m_bInEditor);
			return true;
		}
	}

	if (m_bInEditor && HandleEditorKeyPress(event))
		return true;

	return false;
}

bool Editor::HandleEditorKeyPress(const SInputEvent& event)
{
	if (event.deviceType == eIDT_Keyboard)
	{
		if (m_bEnableCameraControl && (event.state == eIS_Pressed || event.state == eIS_Released))
		{
			int delta = event.state == eIS_Pressed ? 1 : 0;

			if (event.keyId == eKI_W)
				m_vMovementInput.y = delta;
			else if (event.keyId == eKI_S)
				m_vMovementInput.y = -delta;

			if (event.keyId == eKI_D)
				m_vMovementInput.x = delta;
			else if (event.keyId == eKI_A)
				m_vMovementInput.x = -delta;

			if (event.keyId == eKI_Q)
				m_vMovementInput.z = delta;
			else if (event.keyId == eKI_E)
				m_vMovementInput.z = -delta;

			if (event.keyId == eKI_LShift)
				m_bBoostInput = delta;

			return true;
		}
	}
	else if (event.deviceType == eIDT_Mouse)
	{
		if (event.keyId == eKI_Mouse2)
		{
			if (event.state == eIS_Pressed)
				SetEditorCameraControl(true);
			else if (event.state == eIS_Released)
				SetEditorCameraControl(false);
		}

		if (m_bEnableCameraControl)
		{
			if (event.keyId == eKI_MouseX)
				m_vMouseInput.x += event.value;
			else if (event.keyId == eKI_MouseY)
				m_vMouseInput.y += event.value;
			return true;
		}
	}

	// No game input when in editor
	if (event.state != eIS_Released)
		return true;

	return false;
}

bool Editor::UpdateView(SViewParams& params)
{
	if (!m_bInEditor)
		return false;

	params.position = m_vEditorViewPos;
	params.rotation = Quat(m_vEditorViewRot);
	return true;
}

void Editor::SwitchStates()
{
	auto pGameFw = gCL->GetFramework();
	ESystemGlobalState globalState = gEnv->pSystem->GetSystemGlobalState();
	State newState = m_State;

	if (globalState == ESYSTEM_GLOBAL_STATE_RUNNING && pGameFw->IsGameStarted())
	{
		newState = State::Running;
	}
	else if (globalState == ESYSTEM_GLOBAL_STATE_RUNNING && !pGameFw->IsGameStarted())
	{
		newState = State::Unloaded;
	}
	else if (globalState >= ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_PREPARE && globalState <= ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_COMPLETE)
	{
		newState = State::Loading;
	}

	if (newState != m_State)
	{
		m_State = newState;
	}
}

void Editor::UpdateUnloaded()
{
	if (ImGui::Begin("Chairloader Editor"))
	{
		ImGui::TextWrapped("Welcome to the Chairloader Editor!");
		ImGui::TextWrapped("This tool will allow you (at some point) to:");
		ImGui::TextWrapped("\t- Enter flycam at any point in time");
		ImGui::TextWrapped("\t- Select entities with the mouse");
		ImGui::TextWrapped("\t- View and modify entity properties");
		ImGui::TextWrapped("\t- Hot-reload mod DLLs");
		ImGui::NewLine();

		ImGui::TextWrapped("Load a save to begin.");
		ImGui::NewLine();

		ImGui::TextColored(ImColor(255, 255, 0), "Warning!");
		ImGui::TextWrapped("The editor is highly expreimental. Potential side effects include "
			"random crashes, memory corruption, resource leaks, save corruption, stress, frustration, anger, "
			"physiological and psychological damage, desire to burn your house down with lemons. "
			"Please, consult a doctor of your choise before use.");
	}
	ImGui::End();
}

void Editor::UpdateLoading()
{
	if (ImGui::Begin("Chairloader Editor"))
	{
		ImGui::Text("Loading");
	}
	ImGui::End();
}

void Editor::UpdateRunning()
{
	auto pGameFw = gCL->GetFramework();
	auto pPauseMenu = UIEvents::Get<ArkPauseMenu>();
	if (pPauseMenu->m_mode == ArkPauseMenu::EArkPauseMode::continuePrompt)
		pPauseMenu->CloseContinuePrompt();

	if (m_bIsGamePaused && !pGameFw->IsGamePaused())
	{
		CryWarning("[Editor] Expected game to be paused but it's not. Forcing change.");
		SetGamePaused(m_bIsGamePaused);
	}

	if (m_bInEditor)
		UpdateInEditor();

	if (ImGui::Begin("Chairloader Editor"))
	{
		{
			ImGui::Text("Game:");
			if (ImGui::RadioButton("Play", !m_bIsGamePaused))
				SetGamePaused(false);
			ImGui::SameLine();
			if (ImGui::RadioButton("Pause", m_bIsGamePaused))
				SetGamePaused(true);
		}

		{
			ImGui::Text("View:");
			if (ImGui::RadioButton("Editor", m_bInEditor))
				SetInEditor(true);
			ImGui::SameLine();
			if (ImGui::RadioButton("Game", !m_bInEditor))
				SetInEditor(false);
		}

		ImGui::InputFloat3("Cam Pos", &m_vEditorViewPos.x);
	}
	ImGui::End();
}

void Editor::UpdateInEditor()
{
	IViewSystem* pViewSystem = gCL->GetFramework()->GetIViewSystem();

	if (m_bEnableCameraControl)
		UpdateEditorView();

	// Reset player input
	ArkPlayerInput& playerInput = ArkPlayer::GetInstance().m_input;
	playerInput.m_deltaRotation = Ang3(ZERO);
	playerInput.m_movement = Vec2(ZERO);
}

void Editor::UpdateEditorView()
{
	// Rotation input
	{
		float sens = CV_ed_ViewSens * MOUSE_SENS_SCALE;
		m_vEditorViewRot.x -= m_vMouseInput.y * sens;
		m_vEditorViewRot.x = std::clamp(m_vEditorViewRot.x, -gf_PI * 0.5f, gf_PI * 0.5f);
		m_vEditorViewRot.z -= m_vMouseInput.x * sens;
		m_vEditorViewRot.z = fmod(m_vEditorViewRot.z, gf_PI2);
		m_vMouseInput = Vec2(ZERO);
	}

	// Position input
	{
		Quat q(m_vEditorViewRot);
		Vec3 fwd = q * Vec3(0, 1, 0);
		Vec3 right = q * Vec3(1, 0, 0);
		Vec3 up = Vec3(0, 0, 1); // Not influenced by rotation
		float timeDelta = gEnv->pTimer->GetRealFrameTime();

		Vec3 dir = Vec3(ZERO);
		dir += m_vMovementInput.x * right;
		dir += m_vMovementInput.y * fwd;
		dir += m_vMovementInput.z * up;
		dir.NormalizeSafe();

		Vec2 speedLimit = Vec2(CV_ed_ViewMinSpeed, CV_ed_ViewMaxSpeed);
		float accel = CV_ed_ViewAccel;

		if (m_bBoostInput)
		{
			speedLimit *= CV_ed_ViewBoostScale;
			accel *= CV_ed_ViewBoostScale;
		}

		if (m_vMovementInput != Vec3i(ZERO))
		{
			m_flEditorViewSpeed += accel * timeDelta;
			m_flEditorViewSpeed = std::clamp(m_flEditorViewSpeed, speedLimit.x, speedLimit.y);
		}
		else
		{
			m_flEditorViewSpeed -= accel * timeDelta;
			m_flEditorViewSpeed = std::max(0.0f, m_flEditorViewSpeed);
		}

		m_vEditorViewPos += dir * m_flEditorViewSpeed * timeDelta;
	}
}

void Editor::SetGamePaused(bool state)
{
	auto pGameFw = gCL->GetFramework();
	m_bIsGamePaused = state;
	if (state != pGameFw->IsGamePaused())
		pGameFw->PauseGame(state, true, 0, state);
}

void Editor::SetInEditor(bool state)
{
	if (m_bInEditor == state)
		return;

	m_bInEditor = state;
	m_Mouse.SetVisible(state);
	m_bEnableCameraControl = false;
}

void Editor::SetEditorCameraControl(bool state)
{
	m_bEnableCameraControl = state;
	m_Mouse.SetVisible(!state);
	m_vMovementInput = Vec3i(0);
}

Editor::MouseGuard::MouseGuard()
{
}

Editor::MouseGuard::~MouseGuard()
{
	HideCursor();
}

void Editor::MouseGuard::ShowCursor()
{
	if (!isVisible)
	{
		isVisible = true;
		gEnv->pHardwareMouse->IncrementCounter();
	}
}

void Editor::MouseGuard::HideCursor()
{
	if (isVisible)
	{
		isVisible = false;
		gEnv->pHardwareMouse->DecrementCounter();
	}
}

void Editor::MouseGuard::SetVisible(bool state)
{
	if (state)
		ShowCursor();
	else
		HideCursor();
}
