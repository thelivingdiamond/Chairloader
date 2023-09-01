#include <Prey/CryCore/Platform/CryWindows.h>
#include <Manager/IconsMaterialDesign.h>
#include <d3d11.h>
#include <tchar.h>
#include "AppImGui.h"
#include "App/Application.h"
#include <ImGui/imgui_impl_dx11.h>
#include <ImGui/imgui_impl_win32.h>

namespace
{

struct DebugFontLogger : public ImGuiFontList::ILogger
{
	virtual void Log(std::string_view str) override
	{
		OutputDebugStringA(std::string(str).c_str());
	}

	virtual void LogWarning(std::string_view str) override { Log(str); }
	virtual void LogError(std::string_view str)  override { Log(str); }
};

DebugFontLogger g_DebugFontLogger;

} // namespace

static ID3D11Device* g_pd3dDevice = NULL;

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static AppImGui* g_pAppImGui = nullptr;

static LRESULT WINAPI ImGuiWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	return g_pAppImGui->WndProc(hWnd, msg, wParam, lParam);
}

LRESULT ImGui_ImplWin32_WndProcHandler_PlatformWindow_Hook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return false;
}

AppImGui::AppImGui()
{
	assert(!g_pAppImGui);
	g_pAppImGui = this;

	InitD3D();
	InitImGui();
}

AppImGui::~AppImGui()
{
	// TODO: Doesn't free InitD3D
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	DestroyWindow((HWND)m_hWndVoid);
	m_hWndVoid = nullptr;
	g_pAppImGui = nullptr;
}

void AppImGui::BeginFrame()
{
	MSG msg;
	while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
		if (msg.message == WM_QUIT)
			m_bQuitRequested = true;
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
//    ImGui::PushFont(getDefaultFont());
}

void AppImGui::EndFrame()
{
//    ImGui::PopFont();
	ImGui::EndFrame();

	ImGui::Render();
	const ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
	m_pd3dDeviceContext->OMSetRenderTargets(1, &m_pMainRenderTargetView, nullptr);
	m_pd3dDeviceContext->ClearRenderTargetView(m_pMainRenderTargetView, clear_color_with_alpha);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	ImGuiIO& io = ImGui::GetIO();

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}

	m_pSwapChain->Present(1, 0);
}

intptr_t AppImGui::WndProc(void* hWndVoid, unsigned msg, uintptr_t wParam, intptr_t lParam)
{
	HWND hWnd = (HWND)hWndVoid;

	switch (msg)
	{
	case WM_SIZE:
		if (m_pd3dDevice != nullptr && wParam != SIZE_MINIMIZED)
		{
			CleanupRenderTarget();
			m_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			CreateRenderTarget();
		}
		return 0;

	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;

	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;

	case WM_DPICHANGED:
		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DpiEnableScaleViewports)
		{
			const RECT* suggested_rect = (RECT*)lParam;
			::SetWindowPos(hWnd, nullptr, suggested_rect->left, suggested_rect->top, suggested_rect->right - suggested_rect->left, suggested_rect->bottom - suggested_rect->top, SWP_NOZORDER | SWP_NOACTIVATE);
		}
		break;

	default:
		break;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

void AppImGui::InitD3D()
{
	ImGui_ImplWin32_EnableDpiAwareness();
	const WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, &ImGuiWndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, _T("ImGui Standalone"), nullptr };
	::RegisterClassEx(&wc);
	HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("ImGui Standalone"), WS_OVERLAPPEDWINDOW, 100, 100, 50, 50, NULL, NULL, wc.hInstance, NULL);
	m_hWndVoid = hwnd;

	CreateDeviceD3D();
	CreateRenderTarget();

	::ShowWindow(hwnd, SW_HIDE);
	::UpdateWindow(hwnd);
}

void AppImGui::InitImGui()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	// Ini path
	static char iniPath[512];
	snprintf(iniPath, sizeof(iniPath), "%s/imgui.ini", Application::Get()->GetProgramPath().u8string().c_str());
	io.IniFilename = iniPath;

	ImGui::StyleColorsDark();

	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		style.WindowRounding = 4.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	const fs::path& root = Application::Get()->GetProgramPath();
	m_FontList.LoadFile(root / "Fonts/FontList.xml", root, &g_DebugFontLogger);

    ImGui_ImplWin32_Init((HWND)m_hWndVoid);
	ImGui_ImplDX11_Init(m_pd3dDevice, m_pd3dDeviceContext);

    g_pd3dDevice = m_pd3dDevice;
}

void AppImGui::CreateDeviceD3D()
{
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = (HWND)m_hWndVoid;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	const UINT createDeviceFlags = 0;

	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	if (D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags,
		featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &m_pSwapChain, &m_pd3dDevice, &featureLevel, &m_pd3dDeviceContext) != S_OK)
		throw std::runtime_error("D3D11CreateDeviceAndSwapChain failed");
}

void AppImGui::CleanupDeviceD3D()
{
	CleanupRenderTarget();
	SAFE_RELEASE(m_pSwapChain);
	SAFE_RELEASE(m_pd3dDeviceContext);
	SAFE_RELEASE(m_pd3dDevice);
}

void AppImGui::CreateRenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	m_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	if (pBackBuffer != nullptr)
	{
		m_pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &m_pMainRenderTargetView);
		pBackBuffer->Release();
	}
}

void AppImGui::CleanupRenderTarget()
{
	SAFE_RELEASE(m_pMainRenderTargetView);
}
