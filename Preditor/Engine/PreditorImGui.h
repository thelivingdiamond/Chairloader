#pragma once
#include <chrono>
#include <App/IAppImGui.h>

class PreditorImGuiRenderer;

class PreditorImGui : public IAppImGui
{
public:
	static void InitHooks();
	PreditorImGui();
	~PreditorImGui();

	void BeginFrame() override;
	void EndFrame() override;
	void OnWasRendered();

	void ReloadFonts();

	ImGuiContext* GetContext() { return m_pContext; }

	int64_t WndProcHndl(HWND hWnd, unsigned msg, uint64_t wParam, int64_t lParam);

private:
	// Helper structure we store in the void* RenderUserData field of each ImGuiViewport to easily retrieve our backend data.
	struct ViewportData
	{
		HWND    hWnd = nullptr;
		bool    bhWndOwned = false;
		DWORD   dwStyle = 0;
		DWORD   dwExStyle = 0;
	};

	ImGuiContext* m_pContext = nullptr;
	HWND m_hWnd = nullptr;
	bool m_bWantUpdateMonitors = false;
	ImGuiMouseCursor m_LastMouseCursor = 0;
	std::chrono::steady_clock::time_point m_LastTime;
	bool m_bMouseTracked = false;
	HWND m_hMouseWnd = nullptr;
	int m_MouseButtonsDown = 0;
	bool m_bIsInFrame = false;
	std::unique_ptr<PreditorImGuiRenderer> m_pRenderer;

	void InitImGui();
	void ShutdownImGui();
	void InitBackend();
	void ShutdownBackend();
	void InitPlatformInterface();
	void ShutdownPlatformInterface();

	void UpdateMonitors();
	void UpdateMouseData();
	void ProcessKeyEventsWorkarounds();
	bool UpdateMouseCursor();
	void UpdateKeyModifiers();
	void AddKeyEvent(ImGuiKey key, bool down, int native_keycode, int native_scancode = -1);

	// Platform interface for multiple viewports
	static void Plat_CreateWindow(ImGuiViewport* viewport);
	static void Plat_DestroyWindow(ImGuiViewport* viewport);
	static void Plat_ShowWindow(ImGuiViewport* viewport);
	static void Plat_UpdateWindow(ImGuiViewport* viewport);
	static ImVec2 Plat_GetWindowPos(ImGuiViewport* viewport);
	static void Plat_SetWindowPos(ImGuiViewport* viewport, ImVec2 pos);
	static ImVec2 Plat_GetWindowSize(ImGuiViewport* viewport);
	static void Plat_SetWindowSize(ImGuiViewport* viewport, ImVec2 size);
	static void Plat_SetWindowFocus(ImGuiViewport* viewport);
	static bool Plat_GetWindowFocus(ImGuiViewport* viewport);
	static bool Plat_GetWindowMinimized(ImGuiViewport* viewport);
	static void Plat_SetWindowTitle(ImGuiViewport* viewport, const char* title);
	static void Plat_SetWindowAlpha(ImGuiViewport* viewport, float alpha);
	static float Plat_GetWindowDpiScale(ImGuiViewport* viewport);
	static void Plat_OnChangedViewport(ImGuiViewport* viewport);
	static LRESULT CALLBACK WndProcHndl_PlatformWindow(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	static ImGuiKey VirtualKeyToImGuiKey(WPARAM wParam);
};
