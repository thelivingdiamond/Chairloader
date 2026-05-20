#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CryAction/IViewSystem.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryGame/Game.h>
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Prey/CryPhysics/IPhysics.h>
#include <Prey/CryAction/ark/IArkSaveLoadSystem.h>
#include <Prey/GameDll/ui/UIManager.h>
#include <Prey/GameDll/ark/ArkGame.h>
#include <Prey/GameDll/ark/ui/ArkPauseMenu.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Prey/GameDll/ark/player/ArkPlayerInput.h>
#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/IChairloaderCore.h>
#include <Chairloader/IModDllManager.h>
#include "Editor.h"
#include "EditorView.h"

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
int CV_ed_AutoReloadMods = 0;

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

} // namespace

void Editor::InitHooks()
{
	EditorView::InitHooks();
}

Editor* Editor::Get()
{
	return g_pEditor;
}

Editor::Editor(std::shared_ptr<Internal::IModDllManager> pModDllManager)
	: m_pModDllManager(std::move(pModDllManager))
	, m_ModReloading(m_pModDllManager)
{
	assert(!g_pEditor);
	assert(!gCL->pSceneEditor);
	g_pEditor = this;
	gCL->pSceneEditor = this;
	m_pView = std::make_unique<EditorView>();

	gEnv->pConsole->ExecuteString("g_pauseOnLoseFocus 0");
	gEnv->pSystem->GetISystemEventDispatcher()->RegisterListener(this);

	REGISTER_CVAR2("ed_AutoReloadMods", &CV_ed_AutoReloadMods, 1, VF_NULL, "Editor: Automatically reload mods when changes are detected");
}

Editor::~Editor()
{
	assert(gCL->pSceneEditor == this);
	assert(g_pEditor == this);
	gCL->pSceneEditor = nullptr;
	g_pEditor = nullptr;
	gEnv->pSystem->GetISystemEventDispatcher()->RemoveListener(this);
}

void Editor::UpdateBeforeSystem()
{
	m_ModReloading.UpdateBeforeSystem();

	if (CV_ed_AutoReloadMods && m_bGameWindowIsNowActive)
	{
		// Game window is now focused, check mods
		if (m_pModDllManager->CheckModulesForChanges())
			m_ModReloading.ReloadMods();
		m_bGameWindowIsNowActive = false;
	}

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
}

void Editor::ShowUI()
{
	switch (m_State)
	{
	case State::Unloaded:
		ShowUnloadedUI();
		break;
	case State::Loading:
		ShowLoadingUI();
		break;
	case State::Running:
		ShowRunningUI();
		break;
	default:
		assert(false);
		std::abort();
		break;
	}
}

bool Editor::HandleKeyPress(const SInputEvent& event)
{
	// Calling DecrementCounter causes stack overflow
	// FIXME: Remove this
	static bool isEntered = false;
	if (isEntered)
		return false;
	ReentranceGuard rg(&isEntered);

	ImGuiIO& io = ImGui::GetIO();

	if (event.deviceType == eIDT_Keyboard && event.state == eIS_Pressed)
	{
		// No input if focusing ImGui
		if (io.WantTextInput)
			return false;

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
	else if (event.deviceType == eIDT_Mouse && event.state == eIS_Pressed)
	{
		// No input if focusing ImGui
		if (io.WantCaptureMouse)
			return false;
	}

	if (m_bInEditor && HandleEditorKeyPress(event))
		return true;

	return false;
}

bool Editor::HandleEditorKeyPress(const SInputEvent& event)
{
	if (m_pView->HandleInput(event))
		return true;

	if (event.deviceType == eIDT_Keyboard)
	{
		
	}
	else if (event.deviceType == eIDT_Mouse)
	{
		if (event.keyId == eKI_Mouse1 && event.state == eIS_Pressed)
		{
			if (!m_pView->IsGrabInput())
			{
				Vec2 mousePos;
				gEnv->pHardwareMouse->GetHardwareMouseClientPosition(mousePos.x, mousePos.y);
				SelectEntInViewport(mousePos);
			}
		}
		else if (event.keyId == eKI_Mouse2)
		{
			if (event.state == eIS_Pressed)
				SetEditorCameraControl(true);
			else if (event.state == eIS_Released)
				SetEditorCameraControl(false);
		}
	}

	// No game input when in editor
	if (event.state != eIS_Released)
		return true;

	return false;
}

void Editor::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
	if (event == ESYSTEM_EVENT_ACTIVATE)
	{
		if (wparam)
			m_bGameWindowIsNowActive = true;
	}
}

void Editor::SwitchStates()
{
	auto pGameFw = g_pGame->GetIGameFramework();
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
}

void Editor::UpdateLoading()
{
}

void Editor::UpdateRunning()
{
	auto pGameFw = g_pGame->GetIGameFramework();
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
}

void Editor::UpdateInEditor()
{
	m_pView->Update();

	// Reset player input
	ArkPlayerInput& playerInput = ArkPlayer::GetInstance().m_input;
	playerInput.m_deltaRotation = Ang3(ZERO);
	playerInput.m_movement = Vec2(ZERO);

	// Draw selected entity
	if (m_Hierarchy.GetSelectedEntity() != 0)
	{
		IEntity* pEnt = gEnv->pEntitySystem->GetEntity(m_Hierarchy.GetSelectedEntity());

		if (pEnt)
		{
			AABB aabb;
			pEnt->GetLocalBounds(aabb);
			gEnv->pAuxGeomRenderer->DrawAABB(aabb, pEnt->GetWorldTM(), false, ColorB(255, 255, 0), eBBD_Faceted);
		}
	}
}

void Editor::SetGamePaused(bool state)
{
	auto pGameFw = g_pGame->GetIGameFramework();
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
	m_pView->SetGrabInput(false);

	IEntity* pPlayerEnt = ArkPlayer::GetInstance().GetEntity();
	uint32 slotFlags = pPlayerEnt->GetSlotFlags(0);

	if (state)
		pPlayerEnt->SetSlotFlags(0, slotFlags & (~ENTITY_SLOT_RENDER_NEAREST));
	else
		pPlayerEnt->SetSlotFlags(0, slotFlags | ENTITY_SLOT_RENDER_NEAREST);
	ArkPlayer::GetInstance().ShowThirdPerson(state);

	if (state && m_pView->GetPos() == Vec3(ZERO))
		m_pView->MoveCameraToPlayer();
}

void Editor::SetEditorCameraControl(bool state)
{
	m_pView->SetGrabInput(state);
	m_Mouse.SetVisible(!state);
}

void Editor::SelectEntInViewport(Vec2 pixelPos)
{
	ray_hit hit;
	Ray ray = m_pView->ViewportPointToRay(pixelPos);
	
	const unsigned rwiFlags = rwi_stop_at_pierceable | rwi_colltype_any;
	const float hitRange = 2000.f;
	bool isFound = false;

	if (gEnv->pPhysicalWorld->RayWorldIntersection(ray.origin, ray.direction * hitRange, ent_all, rwiFlags, &hit, 1, nullptr, nullptr))
	{
		int type = hit.pCollider->GetiForeignData();
		if (type == PHYS_FOREIGN_ID_ENTITY)
		{
			IEntity* pEntity = (IEntity*)hit.pCollider->GetForeignData(PHYS_FOREIGN_ID_ENTITY);
			m_Hierarchy.SetSelectedEntity(pEntity->GetId());
			m_Hierarchy.ScrollToSelectedEntity();
			isFound = true;
		}
	}

	if (!isFound)
	{
		m_Hierarchy.SetSelectedEntity(0);
	}
}

void Editor::ShowUnloadedUI()
{
	ImGui::SetNextWindowSize(ImVec2(344, 360), ImGuiCond_FirstUseEver);
	if (ImGui::Begin("Chairloader Editor##EditorUnloaded"))
	{
		ImGui::TextWrapped("Welcome to the Chairloader Editor!");
		ImGui::TextWrapped("This tool allows you to:");
		ImGui::TextWrapped("\t- Enter flycam at any point in time");
		ImGui::TextWrapped("\t- Select entities with the mouse");
		ImGui::TextWrapped("\t- View and modify entity properties");
		ImGui::TextWrapped("\t- Hot-reload mod DLLs");
		ImGui::NewLine();

		ImGui::TextWrapped("Load a save to begin.");
		ImGui::TextWrapped("Make sure to check the keymap after loading.");
		ImGui::NewLine();

		ImGui::TextColored(ImColor(255, 255, 0), "Warning!");
		ImGui::TextWrapped("The editor is highly expreimental. Potential side effects include "
			"random crashes, memory corruption, resource leaks, save corruption, stress, frustration, anger, "
			"physiological and psychological damage, desire to commit arson with combustible fruits. "
			"Please, consult a doctor of your choise before use.");
		ImGui::NewLine();

		if (ImGui::Button("Reload Mods"))
			m_ModReloading.ReloadMods();
	}
	ImGui::End();
}

void Editor::ShowLoadingUI()
{
	if (ImGui::Begin("Chairloader Editor##EditorUnloaded"))
	{
		ImGui::Text("Loading...");
	}
	ImGui::End();
}

void Editor::ShowRunningUI()
{
	ImGui::SetNextWindowSizeConstraints(ImVec2(210, -1), ImVec2(210, -1));
	if (ImGui::Begin("Chairloader Editor##EditorRunning", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
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

		if (ImGui::Button("Camera To Player"))
			m_pView->MoveCameraToPlayer();

		if (ImGui::Button("Reload Level"))
			m_ModReloading.ReloadLevel();

		if (ImGui::Button("Reload Mods"))
			m_ModReloading.ReloadMods();

		if (ImGui::TreeNode("Keymap"))
		{
			// TODO: Put them into a config
			ImGui::Text("Any time:");
			ImGui::Text("F4: Go into Editor View");
			ImGui::Text("P: Toggle Pause");
			ImGui::NewLine();

			ImGui::Text("Editor View:");
			ImGui::Text("LMB: Select an entity");
			ImGui::Text("RMB: Hold to fly");
			ImGui::NewLine();

			ImGui::Text("Fly Mode:");
			ImGui::Text("WASD: Move");
			ImGui::Text("Q/E: Go up/down");
			ImGui::Text("Shift: Boost");

			ImGui::TreePop();
		}
	}
	ImGui::End();

	if (ImGui::Begin("Hierarchy##EditorRunning"))
		m_Hierarchy.ShowContents();
	ImGui::End();

	if (ImGui::Begin("Inspector##EditorRunning"))
		m_Inspector.ShowContents(m_Hierarchy.GetSelectedEntity());
	ImGui::End();
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
