#include <Prey/CryInput/IHardwareMouse.h>
#include <Preditor/IPreditorEngine.h>
#include "GameViewport.h"

GameViewport::GameViewport()
{
	SetTitle("Viewport");
	SetPersistentID("GameViewport");
	m_pViewportTexture = IPreditorEngine::Get()->GetViewportTexture();
	assert(m_pViewportTexture);

	m_pCVarWidth = gEnv->pConsole->GetCVar("r_Width");
	m_pCVarHeight = gEnv->pConsole->GetCVar("r_Height");

	// Increment counters to disable mouse
	gEnv->pHardwareMouse->IncrementCounter(); // m_bEnableInput
	gEnv->pHardwareMouse->IncrementCounter(); // m_bLockMouse
}

void GameViewport::PreUpdate()
{
	// Game viewport currently only works in the main window
	// TODO: Fix keyboard not wokring in non-main viewport
	ImGui::SetNextWindowViewport(ImGui::GetMainViewport()->ID);
}

void GameViewport::Update(bool isVisible)
{
	if (isVisible)
	{
		bool bFocused = false;
		if (ImGui::IsWindowFocused())
		{
			// Check if focused in Windows
			ImGuiViewport* vp = ImGui::GetWindowViewport();
			bFocused = vp->PlatformUserData && ImGui::GetPlatformIO().Platform_GetWindowFocus(vp);
		}
		SetInputEnabled(bFocused);
	}
	else
	{
		SetInputEnabled(false);
	}
}

void GameViewport::ShowContents()
{
	ShowTopControls();

	// Calculate viewport size
	ImVec2 min = ImGui::GetCursorPos();
	ImVec2 max = ImGui::GetWindowContentRegionMax();
	Vec2i size(max.x - min.x, max.y - min.y);

	// Clamp it to a reasonable size
	size.x = std::clamp(size.x, MIN_WIDTH, MAX_SIZE);
	size.y = std::clamp(size.y, MIN_HEIGHT, MAX_SIZE);

	// Draw the image
	ImVec2 imageSize(size.x, size.y);
	ImGui::ImageButton(m_pViewportTexture, imageSize, ImVec2(0, 0), ImVec2(1, 1), 0);

	// Set engine viewport size
	if (m_pCVarWidth->GetIVal() != size.x)
		m_pCVarWidth->Set(size.x);
	if (m_pCVarHeight->GetIVal() != size.y)
		m_pCVarHeight->Set(size.y);

	ImVec2 windowPos = ImGui::GetWindowPos();
	Vec2i windowPos2(windowPos.x, windowPos.y);
	IPreditorEngine::Get()->SetGameViewportRect(ImGui::GetWindowViewport()->ID, windowPos2 + Vec2i(min.x, min.y), windowPos2 + Vec2i(max.x, max.y));
}

void GameViewport::ShowTopControls()
{
	// Viewport mode
	if (ImGui::RadioButton("Scene", m_ViewportMode == ViewportMode::Scene))
		m_ViewportMode = ViewportMode::Scene;
	ImGui::SameLine();
	if (ImGui::RadioButton("Game", m_ViewportMode == ViewportMode::Game))
		m_ViewportMode = ViewportMode::Game;

	if (m_ViewportMode == ViewportMode::Scene)
	{
		// TODO:
	}
	else
	{
		ShowGameModeControls();
	}
}

void GameViewport::ShowGameModeControls()
{
	ImGui::SameLine();
	bool bLockMouse = m_bLockMouse;
	if (ImGui::Checkbox("Lock Mouse", &bLockMouse))
		SetMouseLocked(bLockMouse);
}

void GameViewport::SetInputEnabled(bool state)
{
	if (m_bEnableInput != state)
	{
		CryLog("[GameViewport] Input is now {}", state ? "enabled" : "disabled");
		m_bEnableInput = state;
		IPreditorEngine::Get()->SetGameInputEnabled(state);
		if (state)
			gEnv->pHardwareMouse->DecrementCounter();
		else
			gEnv->pHardwareMouse->IncrementCounter();
	}
}

void GameViewport::SetMouseLocked(bool state)
{
	if (m_bLockMouse != state)
	{
		CryLog("[GameViewport] Mouse is now {}", state ? "locked" : "unlocked");
		m_bLockMouse = state;
		if (state)
			gEnv->pHardwareMouse->DecrementCounter();
		else
			gEnv->pHardwareMouse->IncrementCounter();
	}
}
