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

	static ImGuiKey VirtualKeyToImGuiKey(WPARAM wParam);
};
