#include <Prey/CryGame/Game.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryInput/IHardwareMouse.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include <WindowManager/WindowManager.h>
#include "ViewportWindow.h"
#include "SceneViewport.h"
#include "GameViewport.h"

std::shared_ptr<IViewportWindow> IViewportWindow::CreateInstance()
{
	return WindowManager::Get().Create<Viewport::ViewportWindow>();
}

Viewport::ViewportWindow::ViewportWindow()
{
	SetTitle("Viewport");
	SetPersistentID("GameViewport");

	m_pViewportTexture = gPreditor->pEngine->GetViewportTexture();
	m_pCVarWidth = gEnv->pConsole->GetCVar("r_Width");
	m_pCVarHeight = gEnv->pConsole->GetCVar("r_Height");
	assert(m_pViewportTexture);

	m_pSceneViewport = std::make_unique<SceneViewport>();
	m_pGameViewport = std::make_unique<GameViewport>();

	// Decrement some initial increment by the engine or something
	// TODO 2023-06-17: Figure out what's causing it
	gEnv->pHardwareMouse->DecrementCounter();
}

Viewport::ViewportWindow::~ViewportWindow()
{
}

void Viewport::ViewportWindow::SetViewport(BaseViewport* pViewport)
{
	if (m_pCurrentViewport == pViewport)
		return;

	if (m_pCurrentViewport)
	{
		m_pCurrentViewport->OnDisabled();
	}

	m_pCurrentViewport = pViewport;

	if (pViewport)
	{
		pViewport->OnEnabled();
	}
}

ImVec4 Viewport::ViewportWindow::ShowViewportImage()
{
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

	bool sizeChanged = IPreditorEngine::Get()->SetGameViewportRect(
		ImGui::GetWindowViewport()->ID,
		windowPos2 + Vec2i(min.x, min.y),
		windowPos2 + Vec2i(max.x, max.y));

	if (sizeChanged)
	{
		// FlashUI hides the mouse when changing the resolution.
		// This causes it to become confined and this messes with resizing.
		m_ResizeGuard.SetIncremented(true);
		m_ResizeFrameCount = 5;
	}

	if (m_ResizeFrameCount > 0)
	{
		m_ResizeFrameCount--;
		m_ResizeGuard.SetIncremented(m_ResizeFrameCount != 0);
	}

	return ImVec4(min.x, min.y, max.x, max.y);
}

void Viewport::ViewportWindow::PreUpdate()
{
	// Game viewport currently only works in the main window
	// TODO 2023-06-17: Fix keyboard not wokring in non-main viewport.
	// This is because CKeyboard is created only for the main window HWND
	ImGui::SetNextWindowViewport(ImGui::GetMainViewport()->ID);
}

void Viewport::ViewportWindow::Update(bool isVisible)
{
	// Only game viewport mode in the menu.
	if (!g_pGame->GetIGameFramework()->IsGameStarted())
		SetViewport(m_pGameViewport.get());

	if (m_pCurrentViewport)
		m_pCurrentViewport->Update(isVisible);
}

void Viewport::ViewportWindow::ShowContents()
{
	// Viewport mode
	bool sceneAvail = g_pGame->GetIGameFramework()->IsGameStarted();
	ImGui::BeginDisabled(!sceneAvail);
	if (ImGui::RadioButton("Scene", m_pCurrentViewport == m_pSceneViewport.get()))
		SetViewport(m_pSceneViewport.get());
	ImGui::EndDisabled();
	ImGui::SameLine();

	if (ImGui::RadioButton("Game", m_pCurrentViewport == m_pGameViewport.get()))
		SetViewport(m_pGameViewport.get());

	if (m_pCurrentViewport)
		m_pCurrentViewport->ShowUI();
}