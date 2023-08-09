#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Preditor/Main/IUserProjectSettings.h>
#include "MainWindowResizePatch.h"
#include "EngineSwapChainPatch.h"

namespace
{
Engine::MainWindowResizePatch g_MainWindowResizePatch;
auto g_CD3D9Renderer_HandleDisplayPropertyChanges_Hook = CD3D9Renderer::FHandleDisplayPropertyChanges.MakeHook();
auto g_CD3D9Renderer_AdjustWindowForChange_Hook = CD3D9Renderer::FAdjustWindowForChange.MakeHook();

void CD3D9Renderer_HandleDisplayPropertyChanges_Hook(CD3D9Renderer* const _this)
{
	g_MainWindowResizePatch.RT_HandleDisplayPropertyChanges();
	g_CD3D9Renderer_HandleDisplayPropertyChanges_Hook.InvokeOrig(_this);
}

HRESULT CD3D9Renderer_AdjustWindowForChange_Hook(CD3D9Renderer* const _this)
{
	// RT_HandleDisplayPropertyChanges will take care of that
	return S_OK;
}

} // namespace

void Engine::MainWindowResizePatch::InitHooks()
{
	g_CD3D9Renderer_HandleDisplayPropertyChanges_Hook.SetHookFunc(&CD3D9Renderer_HandleDisplayPropertyChanges_Hook);
	g_CD3D9Renderer_AdjustWindowForChange_Hook.SetHookFunc(&CD3D9Renderer_AdjustWindowForChange_Hook);
}

void Engine::MainWindowResizePatch::InitSystem()
{
	gCL->pRender->AddListener(&g_MainWindowResizePatch);
}

void Engine::MainWindowResizePatch::ShutdownSystem()
{
	gCL->pRender->RemoveListener(&g_MainWindowResizePatch);
}

void Engine::MainWindowResizePatch::OnWindowResize(int width, int height)
{
	g_MainWindowResizePatch.m_WindowSize.x = width;
	g_MainWindowResizePatch.m_WindowSize.y = height;
}

void Engine::MainWindowResizePatch::RT_HandleDisplayPropertyChanges()
{
	EngineSwapChainPatch::RT_UpdateSize(m_WindowSize.x, m_WindowSize.y);
}

int Engine::MainWindowResizePatch::GetChairRenderListenerFlags()
{
	return eCRF_InitRenderer;
}

void Engine::MainWindowResizePatch::InitRenderer()
{
	HWND hWnd = (HWND)gcpRendD3D->GetHWND();

	// Make the window resizeable
	SetWindowLongPtr(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);

	LONG_PTR exStyle = GetWindowLongPtr(hWnd, GWL_EXSTYLE);
	exStyle |= WS_EX_NOREDIRECTIONBITMAP;
	SetWindowLongPtr(hWnd, GWL_EXSTYLE, exStyle);

	// Change title
	cry_strcpy(gcpRendD3D->m_WinTitle, "Preditor");
	SetWindowTextA(hWnd, gcpRendD3D->m_WinTitle);

	// Apply size from config
	IUserProjectSettings* pSettings = gPreditor->pUserSettings;
	Vec2i pos = pSettings->GetWindowRestoredPos();
	Vec2i size = pSettings->GetWindowRestoredSize();

	if (pos.x != IUserProjectSettings::INVALID_SIZE && pos.y != IUserProjectSettings::INVALID_SIZE &&
		size.x != IUserProjectSettings::INVALID_SIZE && size.y != IUserProjectSettings::INVALID_SIZE)
		MoveWindow(hWnd, pos.x, pos.y, size.x, size.y, false);

	if (pSettings->IsWindowMaximized())
		ShowWindow(hWnd, SW_SHOWMAXIMIZED);

	// Save size
	RECT rect = { 0, 0, 0, 0 };
	GetClientRect(hWnd, &rect);
	m_WindowSize.x = rect.right - rect.left;
	m_WindowSize.y = rect.bottom - rect.top;
}
