#include <windowsx.h>
#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/GameDll/GameStartup.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_win32.h>
#include <App/Application.h>
#include "PreditorImGui.h"
#include "PreditorImGuiRenderer.h"
#include "MainWindowResizePatch.h"
#include "PreditorEngine.h"
#include "HardwareMousePatch.h"

// There is no distinct VK_xxx for keypad enter, instead it is VK_RETURN + KF_EXTENDED, we assign it an arbitrary value to make code more readable (VK_ codes go up to 255)
#define IM_VK_KEYPAD_ENTER      (VK_RETURN + 256)

namespace
{
PreditorImGui* g_pInstance = nullptr;
auto g_CGameStartup_WndProcHndl_Hook = CGameStartup::FWndProcHndl.MakeHook();

int64_t CGameStartup_WndProcHndl_Hook(HWND hWnd, unsigned msg, uint64_t wParam, int64_t lParam)
{
    if (g_pInstance)
    {
        if (g_pInstance->IsGameInputEnabled() && PreditorEngine::HandleKeyboardMessage(hWnd, msg, wParam, lParam))
            return 1;

        bool handledMouse = HardwareMousePatch::HandleMouseMessage(hWnd, msg, wParam, lParam);

        if (g_pInstance->WndProcHndl(hWnd, msg, wParam, lParam))
            return 1;

        if (handledMouse)
            return 1;
    }

    return g_CGameStartup_WndProcHndl_Hook.InvokeOrig(hWnd, msg, wParam, lParam);
}

bool IsVkDown(int vk)
{
    return (::GetKeyState(vk) & 0x8000) != 0;
}

static void GetWin32StyleFromViewportFlags(ImGuiViewportFlags flags, DWORD* out_style, DWORD* out_ex_style)
{
    if (flags & ImGuiViewportFlags_NoDecoration)
        *out_style = WS_POPUP;
    else
        *out_style = WS_OVERLAPPEDWINDOW;

    if (flags & ImGuiViewportFlags_NoTaskBarIcon)
        *out_ex_style = WS_EX_TOOLWINDOW;
    else
        *out_ex_style = WS_EX_APPWINDOW;

    if (flags & ImGuiViewportFlags_TopMost)
        *out_ex_style |= WS_EX_TOPMOST;
}

} // namespace

void PreditorImGui::InitHooks()
{
    g_CGameStartup_WndProcHndl_Hook.SetHookFunc(&CGameStartup_WndProcHndl_Hook);
    PreditorImGuiRenderer::InitHooks();
}

HWND PreditorImGui::GetHWNDForViewport(ImGuiID viewportId)
{
    ImGuiViewport* vp = ImGui::FindViewportByID(viewportId);
    if (vp)
        return (HWND)vp->PlatformHandle;
    else
        return nullptr;
}

PreditorImGui::PreditorImGui()
{
    assert(!g_pInstance);
    g_pInstance = this;
    ImGuiContext* prevCtx = ImGui::GetCurrentContext();
    ImGui::SetCurrentContext(nullptr);
    InitImGui();
    InitBackend();
    m_pRenderer = std::make_unique<PreditorImGuiRenderer>(this);
    ReloadFonts();
    ImGui::SetCurrentContext(prevCtx);
}

PreditorImGui::~PreditorImGui()
{
    m_pRenderer = nullptr;
    ShutdownBackend();
    ShutdownImGui();
    assert(g_pInstance == this);
    g_pInstance = nullptr;
}

void PreditorImGui::BeginFrame()
{
    assert(!m_bIsInFrame);
    // Update context
    if (!ImGui::GetCurrentContext())
        ImGui::SetCurrentContext(m_pContext);
    assert(ImGui::GetCurrentContext() == m_pContext);

    // Pump window messages for all windows (including the main one)
    // Engine pumps messages only for the main window in CSystem::Update
    MSG msg;
    while (::PeekMessageA(&msg, nullptr, 0U, 0U, PM_REMOVE))
    {
        ::TranslateMessage(&msg);
        ::DispatchMessageA(&msg);
    }

    ImGuiIO& io = ImGui::GetIO();

    // Setup display size (every frame to accommodate for window resizing)
    RECT rect = { 0, 0, 0, 0 };
    ::GetClientRect(m_hWnd, &rect);
    io.DisplaySize = ImVec2((float)(rect.right - rect.left), (float)(rect.bottom - rect.top));
    if (m_bWantUpdateMonitors)
        UpdateMonitors();

    // Setup time step
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    io.DeltaTime = std::chrono::duration_cast<std::chrono::microseconds>((currentTime - m_LastTime)).count() / 1'000'000.0f;
    m_LastTime = currentTime;

    // Update OS mouse position
    UpdateMouseData();

    // Process workarounds for known Windows key handling issues
    ProcessKeyEventsWorkarounds();

    // Update OS mouse cursor with the cursor requested by imgui
    ImGuiMouseCursor mouseCursor = io.MouseDrawCursor ? ImGuiMouseCursor_None : ImGui::GetMouseCursor();
    if (m_LastMouseCursor != mouseCursor)
    {
        m_LastMouseCursor = mouseCursor;
        UpdateMouseCursor();
    }

    ImGui::NewFrame();
}

void PreditorImGui::EndFrame()
{
    if (ImGui::GetCurrentContext() != m_pContext)
        return;

    if (m_bIsInFrame)
    {
        ImGui::EndFrame();
        m_bIsInFrame = false;
    }
}

void PreditorImGui::OnWasRendered()
{
    m_bIsInFrame = false;
}

void PreditorImGui::ReloadFonts()
{
    ImGuiIO& io = ImGui::GetIO();

    // Clear everything font-related
    io.Fonts->SetTexID((ImTextureID)nullptr);
    io.Fonts->Clear();

    // Load fonts from the config
    // TODO:
    io.Fonts->AddFontDefault();

    m_pRenderer->UpdateFontAtlasTexture();
}

int64_t PreditorImGui::WndProcHndl(HWND hWnd, unsigned msg, uint64_t wParam, int64_t lParam)
{
    if (ImGui::GetCurrentContext() == NULL)
        return 0;

    ImGuiIO& io = ImGui::GetIO();

    switch (msg)
    {
    case WM_MOUSEMOVE:
    {
        // We need to call TrackMouseEvent in order to receive WM_MOUSELEAVE events
        m_hMouseWnd = hWnd;
        if (!m_bMouseTracked)
        {
            TRACKMOUSEEVENT tme = { sizeof(tme), TME_LEAVE, hWnd, 0 };
            ::TrackMouseEvent(&tme);
            m_bMouseTracked = true;
        }
        POINT mouse_pos = { (LONG)GET_X_LPARAM(lParam), (LONG)GET_Y_LPARAM(lParam) };
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            ::ClientToScreen(hWnd, &mouse_pos);
        io.AddMousePosEvent((float)mouse_pos.x, (float)mouse_pos.y);
        break;
    }
    case WM_MOUSELEAVE:
        if (m_hMouseWnd == hWnd)
            m_hMouseWnd = NULL;
        m_bMouseTracked = false;
        io.AddMousePosEvent(-FLT_MAX, -FLT_MAX);
        break;
    case WM_LBUTTONDOWN: case WM_LBUTTONDBLCLK:
    case WM_RBUTTONDOWN: case WM_RBUTTONDBLCLK:
    case WM_MBUTTONDOWN: case WM_MBUTTONDBLCLK:
    case WM_XBUTTONDOWN: case WM_XBUTTONDBLCLK:
    {
        int button = 0;
        if (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONDBLCLK) { button = 0; }
        if (msg == WM_RBUTTONDOWN || msg == WM_RBUTTONDBLCLK) { button = 1; }
        if (msg == WM_MBUTTONDOWN || msg == WM_MBUTTONDBLCLK) { button = 2; }
        if (msg == WM_XBUTTONDOWN || msg == WM_XBUTTONDBLCLK) { button = (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) ? 3 : 4; }
        if (m_MouseButtonsDown == 0 && ::GetCapture() == NULL)
            ::SetCapture(hWnd);
        m_MouseButtonsDown |= 1 << button;
        io.AddMouseButtonEvent(button, true);
        return 0;
    }
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
    case WM_XBUTTONUP:
    {
        int button = 0;
        if (msg == WM_LBUTTONUP) { button = 0; }
        if (msg == WM_RBUTTONUP) { button = 1; }
        if (msg == WM_MBUTTONUP) { button = 2; }
        if (msg == WM_XBUTTONUP) { button = (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) ? 3 : 4; }
        m_MouseButtonsDown &= ~(1 << button);
        if (m_MouseButtonsDown == 0 && ::GetCapture() == hWnd)
            ::ReleaseCapture();
        io.AddMouseButtonEvent(button, false);
        return 0;
    }
    case WM_MOUSEWHEEL:
        io.AddMouseWheelEvent(0.0f, (float)GET_WHEEL_DELTA_WPARAM(wParam) / (float)WHEEL_DELTA);
        return 0;
    case WM_MOUSEHWHEEL:
        io.AddMouseWheelEvent((float)GET_WHEEL_DELTA_WPARAM(wParam) / (float)WHEEL_DELTA, 0.0f);
        return 0;
    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
    {
        const bool is_key_down = (msg == WM_KEYDOWN || msg == WM_SYSKEYDOWN);
        if (wParam < 256)
        {
            // Submit modifiers
            UpdateKeyModifiers();

            // Obtain virtual key code
            // (keypad enter doesn't have its own... VK_RETURN with KF_EXTENDED flag means keypad enter, see IM_VK_KEYPAD_ENTER definition for details, it is mapped to ImGuiKey_KeyPadEnter.)
            int vk = (int)wParam;
            if ((wParam == VK_RETURN) && (HIWORD(lParam) & KF_EXTENDED))
                vk = IM_VK_KEYPAD_ENTER;

            // Submit key event
            const ImGuiKey key = VirtualKeyToImGuiKey(vk);
            const int scancode = (int)LOBYTE(HIWORD(lParam));
            if (key != ImGuiKey_None)
                AddKeyEvent(key, is_key_down, vk, scancode);

            // Submit individual left/right modifier events
            if (vk == VK_SHIFT)
            {
                // Important: Shift keys tend to get stuck when pressed together, missing key-up events are corrected in ImGui_ImplWin32_ProcessKeyEventsWorkarounds()
                if (IsVkDown(VK_LSHIFT) == is_key_down) { AddKeyEvent(ImGuiKey_LeftShift, is_key_down, VK_LSHIFT, scancode); }
                if (IsVkDown(VK_RSHIFT) == is_key_down) { AddKeyEvent(ImGuiKey_RightShift, is_key_down, VK_RSHIFT, scancode); }
            }
            else if (vk == VK_CONTROL)
            {
                if (IsVkDown(VK_LCONTROL) == is_key_down) { AddKeyEvent(ImGuiKey_LeftCtrl, is_key_down, VK_LCONTROL, scancode); }
                if (IsVkDown(VK_RCONTROL) == is_key_down) { AddKeyEvent(ImGuiKey_RightCtrl, is_key_down, VK_RCONTROL, scancode); }
            }
            else if (vk == VK_MENU)
            {
                if (IsVkDown(VK_LMENU) == is_key_down) { AddKeyEvent(ImGuiKey_LeftAlt, is_key_down, VK_LMENU, scancode); }
                if (IsVkDown(VK_RMENU) == is_key_down) { AddKeyEvent(ImGuiKey_RightAlt, is_key_down, VK_RMENU, scancode); }
            }
        }
        return 0;
    }
    case WM_SETFOCUS:
    case WM_KILLFOCUS:
        io.AddFocusEvent(msg == WM_SETFOCUS);
        return 0;
    case WM_CHAR:
        // You can also use ToAscii()+GetKeyboardState() to retrieve characters.
        if (wParam > 0 && wParam < 0x10000)
            io.AddInputCharacterUTF16((unsigned short)wParam);
        return 0;
    case WM_SETCURSOR:
        if (LOWORD(lParam) == HTCLIENT && UpdateMouseCursor())
            return 1;
        return 0;
    case WM_DISPLAYCHANGE:
        m_bWantUpdateMonitors = true;
        return 0;
    case WM_SIZE:
        if (hWnd == m_hWnd && wParam != SIZE_MINIMIZED) // Only resize the main window
            MainWindowResizePatch::OnWindowResize(LOWORD(lParam), HIWORD(lParam));
        return 1;
    }
    return 0;
}

void PreditorImGui::InitImGui()
{
    IMGUI_CHECKVERSION();
    m_pContext = ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Ini path
    static char iniPath[512];
    snprintf(iniPath, sizeof(iniPath), "%s/imgui_engine.ini", Application::Get()->GetProgramPath().u8string().c_str());
    io.IniFilename = nullptr;

    ImGui::StyleColorsDark();
}

void PreditorImGui::ShutdownImGui()
{
    ImGui::DestroyContext();
    m_pContext = nullptr;
}

void PreditorImGui::InitBackend()
{
    ImGuiIO& io = ImGui::GetIO();
    assert(io.BackendPlatformUserData == NULL && "Already initialized a platform backend!");
    assert(gEnv->pSystem->GetHWND());

    // Setup backend capabilities flags
    io.BackendPlatformUserData = (void*)this;
    io.BackendPlatformName = "Preditor (CRYENGINE)";
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
    io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;    // We can create multi-viewports on the Platform side (optional)
    io.BackendFlags |= ImGuiBackendFlags_HasMouseHoveredViewport; // We can call io.AddMouseViewportEvent() with correct data (optional)

    m_hWnd = (HWND)gEnv->pSystem->GetHWND();
    m_bWantUpdateMonitors = true;
    m_LastMouseCursor = ImGuiMouseCursor_COUNT;

    // Our mouse update function expect PlatformHandle to be filled for the main viewport
    ImGuiViewport* main_viewport = ImGui::GetMainViewport();
    main_viewport->PlatformHandle = main_viewport->PlatformHandleRaw = (void*)m_hWnd;
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        InitPlatformInterface();
}

void PreditorImGui::ShutdownBackend()
{
    ImGuiIO& io = ImGui::GetIO();

    ShutdownPlatformInterface();

    io.BackendPlatformName = nullptr;
    io.BackendPlatformUserData = nullptr;
}

void PreditorImGui::InitPlatformInterface()
{
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProcHndl_PlatformWindow;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = ::GetModuleHandle(NULL);
    wcex.hIcon = NULL;
    wcex.hCursor = NULL;
    wcex.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "Preditor ImGui Platform";
    wcex.hIconSm = NULL;
    ::RegisterClassEx(&wcex);

    UpdateMonitors();

    // Register platform interface (will be coupled with a renderer interface)
    ImGuiPlatformIO& platform_io = ImGui::GetPlatformIO();
    platform_io.Platform_CreateWindow = Plat_CreateWindow;
    platform_io.Platform_DestroyWindow = Plat_DestroyWindow;
    platform_io.Platform_ShowWindow = Plat_ShowWindow;
    platform_io.Platform_SetWindowPos = Plat_SetWindowPos;
    platform_io.Platform_GetWindowPos = Plat_GetWindowPos;
    platform_io.Platform_SetWindowSize = Plat_SetWindowSize;
    platform_io.Platform_GetWindowSize = Plat_GetWindowSize;
    platform_io.Platform_SetWindowFocus = Plat_SetWindowFocus;
    platform_io.Platform_GetWindowFocus = Plat_GetWindowFocus;
    platform_io.Platform_GetWindowMinimized = Plat_GetWindowMinimized;
    platform_io.Platform_SetWindowTitle = Plat_SetWindowTitle;
    platform_io.Platform_SetWindowAlpha = Plat_SetWindowAlpha;
    platform_io.Platform_UpdateWindow = Plat_UpdateWindow;
    platform_io.Platform_GetWindowDpiScale = Plat_GetWindowDpiScale; // FIXME-DPI
    platform_io.Platform_OnChangedViewport = Plat_OnChangedViewport; // FIXME-DPI

    // Register main window handle (which is owned by the main application, not by us)
    // This is mostly for simplicity and consistency, so that our code (e.g. mouse handling etc.) can use same logic for main and secondary viewports.
    ImGuiViewport* main_viewport = ImGui::GetMainViewport();
    ViewportData* vd = IM_NEW(ViewportData)();
    vd->hWnd = m_hWnd;
    vd->bhWndOwned = false;
    main_viewport->PlatformUserData = vd;
    main_viewport->PlatformHandle = (void*)m_hWnd;
}

void PreditorImGui::ShutdownPlatformInterface()
{
    ::UnregisterClassA("Preditor ImGui Platform", ::GetModuleHandle(NULL));
    ImGui::DestroyPlatformWindows();
}

static BOOL CALLBACK PreditorImGui_UpdateMonitors_EnumFunc(HMONITOR monitor, HDC, LPRECT, LPARAM)
{
    MONITORINFO info = {};
    info.cbSize = sizeof(MONITORINFO);
    if (!::GetMonitorInfo(monitor, &info))
        return TRUE;
    ImGuiPlatformMonitor imgui_monitor;
    imgui_monitor.MainPos = ImVec2((float)info.rcMonitor.left, (float)info.rcMonitor.top);
    imgui_monitor.MainSize = ImVec2((float)(info.rcMonitor.right - info.rcMonitor.left), (float)(info.rcMonitor.bottom - info.rcMonitor.top));
    imgui_monitor.WorkPos = ImVec2((float)info.rcWork.left, (float)info.rcWork.top);
    imgui_monitor.WorkSize = ImVec2((float)(info.rcWork.right - info.rcWork.left), (float)(info.rcWork.bottom - info.rcWork.top));
    imgui_monitor.DpiScale = ImGui_ImplWin32_GetDpiScaleForMonitor(monitor);
    ImGuiPlatformIO& io = ImGui::GetPlatformIO();
    if (info.dwFlags & MONITORINFOF_PRIMARY)
        io.Monitors.push_front(imgui_monitor);
    else
        io.Monitors.push_back(imgui_monitor);
    return TRUE;
}

void PreditorImGui::UpdateMonitors()
{
    ImGui::GetPlatformIO().Monitors.resize(0);
    ::EnumDisplayMonitors(NULL, NULL, PreditorImGui_UpdateMonitors_EnumFunc, 0);
    m_bWantUpdateMonitors = false;
}

void PreditorImGui::UpdateMouseData()
{
    ImGuiIO& io = ImGui::GetIO();
    assert(m_hWnd != 0);

    POINT mouse_screen_pos;
    bool has_mouse_screen_pos = ::GetCursorPos(&mouse_screen_pos) != 0;

    HWND focused_window = ::GetForegroundWindow();
    const bool is_app_focused =
        (focused_window && (focused_window == m_hWnd
            || ::IsChild(focused_window, m_hWnd)
            || ImGui::FindViewportByPlatformHandle((void*)focused_window)));

    if (is_app_focused)
    {
        // (Optional) Set OS mouse position from Dear ImGui if requested (rarely used, only when ImGuiConfigFlags_NavEnableSetMousePos is enabled by user)
        // When multi-viewports are enabled, all Dear ImGui positions are same as OS positions.
        if (io.WantSetMousePos)
        {
            POINT pos = { (int)io.MousePos.x, (int)io.MousePos.y };
            if ((io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) == 0)
                ::ClientToScreen(focused_window, &pos);
            ::SetCursorPos(pos.x, pos.y);
        }

        // (Optional) Fallback to provide mouse position when focused (WM_MOUSEMOVE already provides this when hovered or captured)
        if (!io.WantSetMousePos && !m_bMouseTracked && has_mouse_screen_pos)
        {
            // Single viewport mode: mouse position in client window coordinates (io.MousePos is (0,0) when the mouse is on the upper-left corner of the app window)
            // (This is the position you can get with ::GetCursorPos() + ::ScreenToClient() or WM_MOUSEMOVE.)
            // Multi-viewport mode: mouse position in OS absolute coordinates (io.MousePos is (0,0) when the mouse is on the upper-left of the primary monitor)
            // (This is the position you can get with ::GetCursorPos() or WM_MOUSEMOVE + ::ClientToScreen(). In theory adding viewport->Pos to a client position would also be the same.)
            POINT mouse_pos = mouse_screen_pos;
            if (!(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable))
                ::ScreenToClient(m_hWnd, &mouse_pos);
            io.AddMousePosEvent((float)mouse_pos.x, (float)mouse_pos.y);
        }
    }

    // (Optional) When using multiple viewports: call io.AddMouseViewportEvent() with the viewport the OS mouse cursor is hovering.
    // If ImGuiBackendFlags_HasMouseHoveredViewport is not set by the backend, Dear imGui will ignore this field and infer the information using its flawed heuristic.
    // - [X] Win32 backend correctly ignore viewports with the _NoInputs flag (here using ::WindowFromPoint with WM_NCHITTEST + HTTRANSPARENT in WndProc does that)
    //       Some backend are not able to handle that correctly. If a backend report an hovered viewport that has the _NoInputs flag (e.g. when dragging a window
    //       for docking, the viewport has the _NoInputs flag in order to allow us to find the viewport under), then Dear ImGui is forced to ignore the value reported
    //       by the backend, and use its flawed heuristic to guess the viewport behind.
    // - [X] Win32 backend correctly reports this regardless of another viewport behind focused and dragged from (we need this to find a useful drag and drop target).
    ImGuiID mouse_viewport_id = 0;
    if (has_mouse_screen_pos)
        if (HWND hovered_hwnd = ::WindowFromPoint(mouse_screen_pos))
            if (ImGuiViewport* viewport = ImGui::FindViewportByPlatformHandle((void*)hovered_hwnd))
                mouse_viewport_id = viewport->ID;
    io.AddMouseViewportEvent(mouse_viewport_id);
}

void PreditorImGui::ProcessKeyEventsWorkarounds()
{
    // Left & right Shift keys: when both are pressed together, Windows tend to not generate the WM_KEYUP event for the first released one.
    if (ImGui::IsKeyDown(ImGuiKey_LeftShift) && !IsVkDown(VK_LSHIFT))
        AddKeyEvent(ImGuiKey_LeftShift, false, VK_LSHIFT);
    if (ImGui::IsKeyDown(ImGuiKey_RightShift) && !IsVkDown(VK_RSHIFT))
        AddKeyEvent(ImGuiKey_RightShift, false, VK_RSHIFT);

    // Sometimes WM_KEYUP for Win key is not passed down to the app (e.g. for Win+V on some setups, according to GLFW).
    if (ImGui::IsKeyDown(ImGuiKey_LeftSuper) && !IsVkDown(VK_LWIN))
        AddKeyEvent(ImGuiKey_LeftSuper, false, VK_LWIN);
    if (ImGui::IsKeyDown(ImGuiKey_RightSuper) && !IsVkDown(VK_RWIN))
        AddKeyEvent(ImGuiKey_RightSuper, false, VK_RWIN);
}

bool PreditorImGui::UpdateMouseCursor()
{
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)
        return false;

    ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
    if (imgui_cursor == ImGuiMouseCursor_None || io.MouseDrawCursor)
    {
        // Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
        ::SetCursor(NULL);
    }
    else
    {
        // Show OS mouse cursor
        LPTSTR win32_cursor = IDC_ARROW;
        switch (imgui_cursor)
        {
        case ImGuiMouseCursor_Arrow:        win32_cursor = IDC_ARROW; break;
        case ImGuiMouseCursor_TextInput:    win32_cursor = IDC_IBEAM; break;
        case ImGuiMouseCursor_ResizeAll:    win32_cursor = IDC_SIZEALL; break;
        case ImGuiMouseCursor_ResizeEW:     win32_cursor = IDC_SIZEWE; break;
        case ImGuiMouseCursor_ResizeNS:     win32_cursor = IDC_SIZENS; break;
        case ImGuiMouseCursor_ResizeNESW:   win32_cursor = IDC_SIZENESW; break;
        case ImGuiMouseCursor_ResizeNWSE:   win32_cursor = IDC_SIZENWSE; break;
        case ImGuiMouseCursor_Hand:         win32_cursor = IDC_HAND; break;
        case ImGuiMouseCursor_NotAllowed:   win32_cursor = IDC_NO; break;
        }
        ::SetCursor(::LoadCursor(NULL, win32_cursor));
    }
    return true;
}

void PreditorImGui::UpdateKeyModifiers()
{
    ImGuiIO& io = ImGui::GetIO();
    io.AddKeyEvent(ImGuiKey_ModCtrl, IsVkDown(VK_CONTROL));
    io.AddKeyEvent(ImGuiKey_ModShift, IsVkDown(VK_SHIFT));
    io.AddKeyEvent(ImGuiKey_ModAlt, IsVkDown(VK_MENU));
    io.AddKeyEvent(ImGuiKey_ModSuper, IsVkDown(VK_APPS));
}

void PreditorImGui::AddKeyEvent(ImGuiKey key, bool down, int native_keycode, int native_scancode)
{
    ImGuiIO& io = ImGui::GetIO();
    io.AddKeyEvent(key, down);
    io.SetKeyEventNativeData(key, native_keycode, native_scancode); // To support legacy indexing (<1.87 user code)
}

void PreditorImGui::Plat_CreateWindow(ImGuiViewport* viewport)
{
    ViewportData* vd = IM_NEW(ViewportData)();
    viewport->PlatformUserData = vd;

    // Select style and parent window
    GetWin32StyleFromViewportFlags(viewport->Flags, &vd->dwStyle, &vd->dwExStyle);
    HWND parent_window = NULL;
    if (viewport->ParentViewportId != 0)
        if (ImGuiViewport* parent_viewport = ImGui::FindViewportByID(viewport->ParentViewportId))
            parent_window = (HWND)parent_viewport->PlatformHandle;

    // Create window
    RECT rect = { (LONG)viewport->Pos.x, (LONG)viewport->Pos.y, (LONG)(viewport->Pos.x + viewport->Size.x), (LONG)(viewport->Pos.y + viewport->Size.y) };
    ::AdjustWindowRectEx(&rect, vd->dwStyle, FALSE, vd->dwExStyle);
    vd->hWnd = ::CreateWindowEx(
        vd->dwExStyle, "Preditor ImGui Platform", "Untitled", vd->dwStyle,   // Style, class name, window name
        rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,    // Window area
        parent_window, NULL, ::GetModuleHandle(NULL), NULL);                    // Parent window, Menu, Instance, Param
    vd->bhWndOwned = true;
    viewport->PlatformRequestResize = false;
    viewport->PlatformHandle = viewport->PlatformHandleRaw = vd->hWnd;
}

void PreditorImGui::Plat_DestroyWindow(ImGuiViewport* viewport)
{
    if (ViewportData* vd = (ViewportData*)viewport->PlatformUserData)
    {
        if (::GetCapture() == vd->hWnd)
        {
            // Transfer capture so if we started dragging from a window that later disappears, we'll still receive the MOUSEUP event.
            ::ReleaseCapture();
            ::SetCapture(g_pInstance->m_hWnd);
        }
        if (vd->hWnd && vd->bhWndOwned)
            ::DestroyWindow(vd->hWnd);
        vd->hWnd = NULL;
        IM_DELETE(vd);
    }
    viewport->PlatformUserData = viewport->PlatformHandle = NULL;
}

void PreditorImGui::Plat_ShowWindow(ImGuiViewport* viewport)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    if (viewport->Flags & ImGuiViewportFlags_NoFocusOnAppearing)
        ::ShowWindow(vd->hWnd, SW_SHOWNA);
    else
        ::ShowWindow(vd->hWnd, SW_SHOW);
}

void PreditorImGui::Plat_UpdateWindow(ImGuiViewport* viewport)
{
    // (Optional) Update Win32 style if it changed _after_ creation.
    // Generally they won't change unless configuration flags are changed, but advanced uses (such as manually rewriting viewport flags) make this useful.
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    DWORD new_style;
    DWORD new_ex_style;
    GetWin32StyleFromViewportFlags(viewport->Flags, &new_style, &new_ex_style);

    // Only reapply the flags that have been changed from our point of view (as other flags are being modified by Windows)
    if (vd->dwStyle != new_style || vd->dwExStyle != new_ex_style)
    {
        // (Optional) Update TopMost state if it changed _after_ creation
        bool top_most_changed = (vd->dwExStyle & WS_EX_TOPMOST) != (new_ex_style & WS_EX_TOPMOST);
        HWND insert_after = top_most_changed ? ((viewport->Flags & ImGuiViewportFlags_TopMost) ? HWND_TOPMOST : HWND_NOTOPMOST) : 0;
        UINT swp_flag = top_most_changed ? 0 : SWP_NOZORDER;

        // Apply flags and position (since it is affected by flags)
        vd->dwStyle = new_style;
        vd->dwExStyle = new_ex_style;
        ::SetWindowLong(vd->hWnd, GWL_STYLE, vd->dwStyle);
        ::SetWindowLong(vd->hWnd, GWL_EXSTYLE, vd->dwExStyle);
        RECT rect = { (LONG)viewport->Pos.x, (LONG)viewport->Pos.y, (LONG)(viewport->Pos.x + viewport->Size.x), (LONG)(viewport->Pos.y + viewport->Size.y) };
        ::AdjustWindowRectEx(&rect, vd->dwStyle, FALSE, vd->dwExStyle); // Client to Screen
        ::SetWindowPos(vd->hWnd, insert_after, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, swp_flag | SWP_NOACTIVATE | SWP_FRAMECHANGED);
        ::ShowWindow(vd->hWnd, SW_SHOWNA); // This is necessary when we alter the style
        viewport->PlatformRequestMove = viewport->PlatformRequestResize = true;
    }
}

ImVec2 PreditorImGui::Plat_GetWindowPos(ImGuiViewport* viewport)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    POINT pos = { 0, 0 };
    ::ClientToScreen(vd->hWnd, &pos);
    return ImVec2((float)pos.x, (float)pos.y);
}

void PreditorImGui::Plat_SetWindowPos(ImGuiViewport* viewport, ImVec2 pos)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    RECT rect = { (LONG)pos.x, (LONG)pos.y, (LONG)pos.x, (LONG)pos.y };
    ::AdjustWindowRectEx(&rect, vd->dwStyle, FALSE, vd->dwExStyle);
    ::SetWindowPos(vd->hWnd, NULL, rect.left, rect.top, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
}

ImVec2 PreditorImGui::Plat_GetWindowSize(ImGuiViewport* viewport)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    RECT rect;
    ::GetClientRect(vd->hWnd, &rect);
    return ImVec2(float(rect.right - rect.left), float(rect.bottom - rect.top));
}

void PreditorImGui::Plat_SetWindowSize(ImGuiViewport* viewport, ImVec2 size)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    RECT rect = { 0, 0, (LONG)size.x, (LONG)size.y };
    ::AdjustWindowRectEx(&rect, vd->dwStyle, FALSE, vd->dwExStyle); // Client to Screen
    ::SetWindowPos(vd->hWnd, NULL, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE);
}

void PreditorImGui::Plat_SetWindowFocus(ImGuiViewport* viewport)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    ::BringWindowToTop(vd->hWnd);
    ::SetForegroundWindow(vd->hWnd);
    ::SetFocus(vd->hWnd);
}

bool PreditorImGui::Plat_GetWindowFocus(ImGuiViewport* viewport)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    return ::GetForegroundWindow() == vd->hWnd;
}

bool PreditorImGui::Plat_GetWindowMinimized(ImGuiViewport* viewport)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    return ::IsIconic(vd->hWnd) != 0;
}

void PreditorImGui::Plat_SetWindowTitle(ImGuiViewport* viewport, const char* title)
{
    // ::SetWindowTextA() doesn't properly handle UTF-8 so we explicitely convert our string.
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    int n = ::MultiByteToWideChar(CP_UTF8, 0, title, -1, NULL, 0);
    ImVector<wchar_t> title_w;
    title_w.resize(n);
    ::MultiByteToWideChar(CP_UTF8, 0, title, -1, title_w.Data, n);
    ::SetWindowTextW(vd->hWnd, title_w.Data);
}

void PreditorImGui::Plat_SetWindowAlpha(ImGuiViewport* viewport, float alpha)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    IM_ASSERT(alpha >= 0.0f && alpha <= 1.0f);
    if (alpha < 1.0f)
    {
        DWORD style = ::GetWindowLongW(vd->hWnd, GWL_EXSTYLE) | WS_EX_LAYERED;
        ::SetWindowLongW(vd->hWnd, GWL_EXSTYLE, style);
        ::SetLayeredWindowAttributes(vd->hWnd, 0, (BYTE)(255 * alpha), LWA_ALPHA);
    }
    else
    {
        DWORD style = ::GetWindowLongW(vd->hWnd, GWL_EXSTYLE) & ~WS_EX_LAYERED;
        ::SetWindowLongW(vd->hWnd, GWL_EXSTYLE, style);
    }
}

float PreditorImGui::Plat_GetWindowDpiScale(ImGuiViewport* viewport)
{
    ViewportData* vd = (ViewportData*)viewport->PlatformUserData;
    IM_ASSERT(vd->hWnd != 0);
    return ImGui_ImplWin32_GetDpiScaleForHwnd(vd->hWnd);
}

void PreditorImGui::Plat_OnChangedViewport(ImGuiViewport* viewport)
{
}

LRESULT PreditorImGui::WndProcHndl_PlatformWindow(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (g_pInstance->m_bEnableGameInput && PreditorEngine::HandleKeyboardMessage(hWnd, msg, wParam, lParam))
        return 1;

    bool handledMouse = HardwareMousePatch::HandleMouseMessage(hWnd, msg, wParam, lParam);

    if (g_pInstance->WndProcHndl(hWnd, msg, wParam, lParam))
        return true;

    if (handledMouse)
        return true;

    if (ImGuiViewport* viewport = ImGui::FindViewportByPlatformHandle((void*)hWnd))
    {
        switch (msg)
        {
        case WM_CLOSE:
            viewport->PlatformRequestClose = true;
            return 0;
        case WM_MOVE:
            viewport->PlatformRequestMove = true;
            break;
        case WM_SIZE:
            viewport->PlatformRequestResize = true;
            break;
        case WM_MOUSEACTIVATE:
            if (viewport->Flags & ImGuiViewportFlags_NoFocusOnClick)
                return MA_NOACTIVATE;
            break;
        case WM_NCHITTEST:
            // Let mouse pass-through the window. This will allow the backend to call io.AddMouseViewportEvent() correctly. (which is optional).
            // The ImGuiViewportFlags_NoInputs flag is set while dragging a viewport, as want to detect the window behind the one we are dragging.
            // If you cannot easily access those viewport flags from your windowing/event code: you may manually synchronize its state e.g. in
            // your main loop after calling UpdatePlatformWindows(). Iterate all viewports/platform windows and pass the flag to your windowing system.
            if (viewport->Flags & ImGuiViewportFlags_NoInputs)
                return HTTRANSPARENT;
            break;
        }
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

ImGuiKey PreditorImGui::VirtualKeyToImGuiKey(WPARAM wParam)
{
    switch (wParam)
    {
    case VK_TAB: return ImGuiKey_Tab;
    case VK_LEFT: return ImGuiKey_LeftArrow;
    case VK_RIGHT: return ImGuiKey_RightArrow;
    case VK_UP: return ImGuiKey_UpArrow;
    case VK_DOWN: return ImGuiKey_DownArrow;
    case VK_PRIOR: return ImGuiKey_PageUp;
    case VK_NEXT: return ImGuiKey_PageDown;
    case VK_HOME: return ImGuiKey_Home;
    case VK_END: return ImGuiKey_End;
    case VK_INSERT: return ImGuiKey_Insert;
    case VK_DELETE: return ImGuiKey_Delete;
    case VK_BACK: return ImGuiKey_Backspace;
    case VK_SPACE: return ImGuiKey_Space;
    case VK_RETURN: return ImGuiKey_Enter;
    case VK_ESCAPE: return ImGuiKey_Escape;
    case VK_OEM_7: return ImGuiKey_Apostrophe;
    case VK_OEM_COMMA: return ImGuiKey_Comma;
    case VK_OEM_MINUS: return ImGuiKey_Minus;
    case VK_OEM_PERIOD: return ImGuiKey_Period;
    case VK_OEM_2: return ImGuiKey_Slash;
    case VK_OEM_1: return ImGuiKey_Semicolon;
    case VK_OEM_PLUS: return ImGuiKey_Equal;
    case VK_OEM_4: return ImGuiKey_LeftBracket;
    case VK_OEM_5: return ImGuiKey_Backslash;
    case VK_OEM_6: return ImGuiKey_RightBracket;
    case VK_OEM_3: return ImGuiKey_GraveAccent;
    case VK_CAPITAL: return ImGuiKey_CapsLock;
    case VK_SCROLL: return ImGuiKey_ScrollLock;
    case VK_NUMLOCK: return ImGuiKey_NumLock;
    case VK_SNAPSHOT: return ImGuiKey_PrintScreen;
    case VK_PAUSE: return ImGuiKey_Pause;
    case VK_NUMPAD0: return ImGuiKey_Keypad0;
    case VK_NUMPAD1: return ImGuiKey_Keypad1;
    case VK_NUMPAD2: return ImGuiKey_Keypad2;
    case VK_NUMPAD3: return ImGuiKey_Keypad3;
    case VK_NUMPAD4: return ImGuiKey_Keypad4;
    case VK_NUMPAD5: return ImGuiKey_Keypad5;
    case VK_NUMPAD6: return ImGuiKey_Keypad6;
    case VK_NUMPAD7: return ImGuiKey_Keypad7;
    case VK_NUMPAD8: return ImGuiKey_Keypad8;
    case VK_NUMPAD9: return ImGuiKey_Keypad9;
    case VK_DECIMAL: return ImGuiKey_KeypadDecimal;
    case VK_DIVIDE: return ImGuiKey_KeypadDivide;
    case VK_MULTIPLY: return ImGuiKey_KeypadMultiply;
    case VK_SUBTRACT: return ImGuiKey_KeypadSubtract;
    case VK_ADD: return ImGuiKey_KeypadAdd;
    case IM_VK_KEYPAD_ENTER: return ImGuiKey_KeypadEnter;
    case VK_LSHIFT: return ImGuiKey_LeftShift;
    case VK_LCONTROL: return ImGuiKey_LeftCtrl;
    case VK_LMENU: return ImGuiKey_LeftAlt;
    case VK_LWIN: return ImGuiKey_LeftSuper;
    case VK_RSHIFT: return ImGuiKey_RightShift;
    case VK_RCONTROL: return ImGuiKey_RightCtrl;
    case VK_RMENU: return ImGuiKey_RightAlt;
    case VK_RWIN: return ImGuiKey_RightSuper;
    case VK_APPS: return ImGuiKey_Menu;
    case '0': return ImGuiKey_0;
    case '1': return ImGuiKey_1;
    case '2': return ImGuiKey_2;
    case '3': return ImGuiKey_3;
    case '4': return ImGuiKey_4;
    case '5': return ImGuiKey_5;
    case '6': return ImGuiKey_6;
    case '7': return ImGuiKey_7;
    case '8': return ImGuiKey_8;
    case '9': return ImGuiKey_9;
    case 'A': return ImGuiKey_A;
    case 'B': return ImGuiKey_B;
    case 'C': return ImGuiKey_C;
    case 'D': return ImGuiKey_D;
    case 'E': return ImGuiKey_E;
    case 'F': return ImGuiKey_F;
    case 'G': return ImGuiKey_G;
    case 'H': return ImGuiKey_H;
    case 'I': return ImGuiKey_I;
    case 'J': return ImGuiKey_J;
    case 'K': return ImGuiKey_K;
    case 'L': return ImGuiKey_L;
    case 'M': return ImGuiKey_M;
    case 'N': return ImGuiKey_N;
    case 'O': return ImGuiKey_O;
    case 'P': return ImGuiKey_P;
    case 'Q': return ImGuiKey_Q;
    case 'R': return ImGuiKey_R;
    case 'S': return ImGuiKey_S;
    case 'T': return ImGuiKey_T;
    case 'U': return ImGuiKey_U;
    case 'V': return ImGuiKey_V;
    case 'W': return ImGuiKey_W;
    case 'X': return ImGuiKey_X;
    case 'Y': return ImGuiKey_Y;
    case 'Z': return ImGuiKey_Z;
    case VK_F1: return ImGuiKey_F1;
    case VK_F2: return ImGuiKey_F2;
    case VK_F3: return ImGuiKey_F3;
    case VK_F4: return ImGuiKey_F4;
    case VK_F5: return ImGuiKey_F5;
    case VK_F6: return ImGuiKey_F6;
    case VK_F7: return ImGuiKey_F7;
    case VK_F8: return ImGuiKey_F8;
    case VK_F9: return ImGuiKey_F9;
    case VK_F10: return ImGuiKey_F10;
    case VK_F11: return ImGuiKey_F11;
    case VK_F12: return ImGuiKey_F12;
    default: return ImGuiKey_None;
    }
}
