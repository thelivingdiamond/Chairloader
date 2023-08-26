#define NOMINMAX

#include <memory>
#include <Manager/ImGuiFontList.h>
#include "UI.h"
#include "ChairManager.h"

#include "ImGui/imgui_internal.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"

ID3D11Device* UI::pd3dDevice = nullptr;
ID3D11DeviceContext* UI::pd3dDeviceContext = nullptr;
IDXGISwapChain* UI::pSwapChain = nullptr;
ID3D11RenderTargetView* UI::pMainRenderTargetView = nullptr;
bool UI::bIsRunning = false;
ImGuiFontList UI::fontList;

namespace
{

class FontLogger : public ImGuiFontList::ILogger
{
public:
    virtual void Log(std::string_view str) override { Log(severityLevel::info, str); }
    virtual void LogWarning(std::string_view str) override { Log(severityLevel::warning, str); }
    virtual void LogError(std::string_view str)  override { Log(severityLevel::error, str); }

private:
    void Log(severityLevel level, std::string_view str)
    {
        OutputDebugStringA(std::string(str).c_str());

        if (ChairManager::IsInstantiated())
        {
            ChairManager::Get().Log(level, "%s", str);
        }
    }
};

FontLogger g_FontLogger;

//! The last time the main loop was running.
std::chrono::steady_clock::time_point g_LastUpdateTime;

//! The last time user did something to one of the windows.
std::chrono::steady_clock::time_point g_LastInteractionTime;

void ResetInteractionTimer()
{
    g_LastInteractionTime = std::chrono::steady_clock::now();
}

void ResetInteractionTimerOnMsg(UINT msg)
{
    switch (msg)
    {
    case WM_SIZE:
    case WM_DPICHANGED:
    case WM_MOUSEMOVE:
    case WM_MOUSELEAVE:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
    case WM_RBUTTONDOWN:
    case WM_RBUTTONDBLCLK:
    case WM_MBUTTONDOWN:
    case WM_MBUTTONDBLCLK:
    case WM_XBUTTONDOWN:
    case WM_XBUTTONDBLCLK:
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
    case WM_XBUTTONUP:
    case WM_MOUSEWHEEL:
    case WM_MOUSEHWHEEL:
    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
    case WM_SETFOCUS:
    case WM_KILLFOCUS:
    case WM_CHAR:
    case WM_SETCURSOR:
    case WM_DISPLAYCHANGE:
        ResetInteractionTimer();
        break;
    }
}

} // namespace

LRESULT ImGui_ImplWin32_WndProcHandler_PlatformWindow_Hook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    ResetInteractionTimerOnMsg(msg);
    return false;
}

bool UI::CreateDeviceD3D(HWND hWnd)
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
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    const UINT createDeviceFlags = 0;
    
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &pSwapChain, &pd3dDevice, &featureLevel, &pd3dDeviceContext) != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void UI::CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    if (pBackBuffer != nullptr)
    {
        pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pMainRenderTargetView);
        pBackBuffer->Release();
    }
}

void UI::CleanupRenderTarget()
{
    if (pMainRenderTargetView)
    {
        pMainRenderTargetView->Release();
        pMainRenderTargetView = nullptr;
    }
}

void UI::CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (pSwapChain)
    {
        pSwapChain->Release();
        pSwapChain = nullptr;
    }

    if (pd3dDeviceContext)
    {
        pd3dDeviceContext->Release();
        pd3dDeviceContext = nullptr;
    }

    if (pd3dDevice)
    {
        pd3dDevice->Release();
        pd3dDevice = nullptr;
    }
}

#ifndef WM_DPICHANGED
#define WM_DPICHANGED 0x02E0 // From Windows SDK 8.1+ headers
#endif

LRESULT WINAPI UI::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    ResetInteractionTimerOnMsg(msg);

    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (pd3dDevice != nullptr && wParam != SIZE_MINIMIZED)
        {
            CleanupRenderTarget();
            pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
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

void UI::Setup()
{
    ImGui::StyleColorsDark();
    // ImGui::GetStyle().WindowBorderSize = 0.0f;
    ImGui::GetStyle().FramePadding = { 8, 5 };
    ImGui::GetStyle().FrameRounding = 2;
    ImGui::GetStyle().ChildRounding = 2;
    ImGui::GetStyle().WindowRounding = 2;
    ImGui::GetStyle().PopupRounding = 2;
}

void UI::Render()
{
    //TODO: decide on dpi awareness
    ImGui_ImplWin32_EnableDpiAwareness();
    const WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, _T("ImGui Standalone"), nullptr };
    ::RegisterClassEx(&wc);
    const HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("ImGui Standalone"), WS_OVERLAPPEDWINDOW, 100, 100, 50, 50, NULL, NULL, wc.hInstance, NULL);

    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return;
    }

    ::ShowWindow(hwnd, SW_HIDE);
    ::UpdateWindow(hwnd);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 4.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }



    const HMONITOR monitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    MONITORINFO info = {};
    info.cbSize = sizeof(MONITORINFO);
    GetMonitorInfo(monitor, &info);
    const int monitor_height = info.rcMonitor.bottom - info.rcMonitor.top;

    //! handle DPI awareness
    auto dpi = GetDpiForWindow(hwnd);
    float dpiScale = dpi / 96.0f;
    ReloadFonts(dpiScale);
    ImGui::GetStyle().ScaleAllSizes(dpiScale);


    ImGui::GetIO().IniFilename = nullptr;

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(pd3dDevice, pd3dDeviceContext);

    const ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    Setup();

    auto pModManager = std::make_unique<ChairManager>();
    bIsRunning = true;

    while (bIsRunning)
    {
        std::chrono::steady_clock::duration msgTimeout = GetNextFrameTimeout();
        MsgWaitForMultipleObjects(
            0, nullptr, false,
            std::chrono::duration_cast<std::chrono::milliseconds>(msgTimeout).count(),
            QS_ALLINPUT);

        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                bIsRunning = false;
        }

        if (!bIsRunning)
            break;

        ChairManager::Get().Update();
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            ChairManager::Get().Draw();
        }
        ImGui::EndFrame();

        ImGui::Render();
        const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
        pd3dDeviceContext->OMSetRenderTargets(1, &pMainRenderTargetView, nullptr);
        pd3dDeviceContext->ClearRenderTargetView(pMainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        pSwapChain->Present(1, 0);
    }

    pModManager.reset();

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    #ifdef _WINDLL
    ExitThread(0);
    #endif
}

void UI::RequestExit()
{
    bIsRunning = false;
}

void UI::ResetDX11() {
    ImGui_ImplDX11_InvalidateDeviceObjects();
    ImGui_ImplDX11_CreateDeviceObjects();
}

void UI::ReloadFonts(float dpiScale)
{
    fs::path root = fs::current_path();
    fontList.LoadFile(root / "Fonts/FontList.xml", root, &g_FontLogger, dpiScale);
}

std::chrono::steady_clock::duration UI::GetNextFrameTimeout()
{
    //! The time the app will continue to refresh after the user has stopped interacting
    constexpr auto WAIT_DELAY = std::chrono::seconds(2);

    auto now = std::chrono::steady_clock::now();
    auto frameDelta = now - g_LastUpdateTime;
    g_LastUpdateTime = now;

    // See if any windows are focused
    auto& viewports = GImGui->Viewports;
    bool anyActive = false;
    HWND hActiveWnd = GetActiveWindow();

    for (ImGuiViewport* pVP : viewports)
    {
        auto hWnd = (HWND)pVP->PlatformHandleRaw;
        if (hWnd && hWnd == hActiveWnd)
        {
            anyActive = true;
            break;
        }
    }

    if (anyActive)
    {
        // User is interacting with the window
        g_LastInteractionTime = now;
    }
    else
    {
        auto interactionDelta = now - g_LastInteractionTime;

        if (interactionDelta > WAIT_DELAY)
        {
            // Wait for a while for a new message
            return std::chrono::hours(1);
        }
    }

    // Limit FPS to a sane value in case v-sync fails
    auto fpsWaitTime = std::chrono::microseconds(1'000'000 / 160) - frameDelta;
    fpsWaitTime = std::max(fpsWaitTime, std::chrono::nanoseconds(0));
    return fpsWaitTime;
}
