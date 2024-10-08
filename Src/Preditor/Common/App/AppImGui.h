#pragma once
#include <ImGui/imgui.h>
#include <Manager/ImGuiFontList.h>
#include <App/IAppImGui.h>

struct ID3D11Device;
struct ID3D11DeviceContext;
struct IDXGISwapChain;
struct ID3D11RenderTargetView;

class AppImGui : public IAppImGui
{
public:
	AppImGui();
	~AppImGui();

	//! @returns whether WM_QUIT message was received.
	bool IsQuitRequested() { return m_bQuitRequested; }

	void BeginFrame() override;
	void EndFrame() override;
	intptr_t WndProc(void* hWndVoid, unsigned msg, uintptr_t wParam, intptr_t lParam);

private:
	void* m_hWndVoid;
	ID3D11Device* m_pd3dDevice;
	ID3D11DeviceContext* m_pd3dDeviceContext;
	IDXGISwapChain* m_pSwapChain;
	ID3D11RenderTargetView* m_pMainRenderTargetView;
	bool m_bQuitRequested = false;
	ImGuiFontList m_FontList;

	void InitD3D();
	void InitImGui();

	void CreateDeviceD3D();
	void CleanupDeviceD3D();
	void CreateRenderTarget();
	void CleanupRenderTarget();
};
