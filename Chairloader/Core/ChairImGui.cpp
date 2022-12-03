#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CrySystem/HardwareMouse.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include <Prey/CryRenderer/ITexture.h>
#include <Prey/CrySystem/Profiling.h>
#include <Prey/CrySystem/System.h>
#include <Chairloader/IChairloaderDll.h>
#include "ChairImGui.h"
#include "ImGuiRendererD3D11.h"

class CBasicEventListener;

static ChairImGui g_ChairImGui;
static auto s_hookCBaseInputPostInputEvent = CBaseInput::FPostInputEvent.MakeHook();
static auto s_CHardwareMouse_Event_Hook = CHardwareMouse::FEvent.MakeHook();
static auto s_CBasicEventListener_OnSetCursor = PreyFunction<int(CBasicEventListener* const _this, HWND__* hWnd)>(0x1685F90);
static auto s_CBasicEventListener_OnSetCursor_Hook = s_CBasicEventListener_OnSetCursor.MakeHook();
static auto s_CSystem_RenderEnd_Hook = CSystem::FRenderEnd.MakeHook();

static void CHardwareMouse_Event_Hook(CHardwareMouse* const _this, int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta)
{
	// Exclusive ImGui mouse input
	// Don't pass mouse events to the game and FlashUI
	if (g_ChairImGui.HasExclusiveMouseInput())
		return;

	s_CHardwareMouse_Event_Hook.InvokeOrig(_this, iX, iY, eHardwareMouseEvent, wheelDelta);
}

static int CBasicEventListener_OnSetCursor_Hook(CBasicEventListener* const _this, HWND__* hWnd)
{
	// Allow ImGui to set the crusor
	if (g_ChairImGui.HasExclusiveMouseInput())
		return 1;

	return s_CBasicEventListener_OnSetCursor_Hook.InvokeOrig(_this, hWnd);
}

static void CSystem_RenderEnd_Hook(CSystem* const _this, bool bRenderStats)
{
	g_ChairImGui.RenderEnd();
	return s_CSystem_RenderEnd_Hook.InvokeOrig(_this, bRenderStats);
}

ChairImGui& ChairImGui::Get()
{
	return g_ChairImGui;
}

ChairImGui::ChairImGui()
{
}

ChairImGui::~ChairImGui()
{
}

void ChairImGui::InitSystem()
{
	s_hookCBaseInputPostInputEvent.SetHookFunc(&CBaseInput_PostInputEvent);
	s_CHardwareMouse_Event_Hook.SetHookFunc(&CHardwareMouse_Event_Hook);
	s_CBasicEventListener_OnSetCursor_Hook.SetHookFunc(&CBasicEventListener_OnSetCursor_Hook);
	s_CSystem_RenderEnd_Hook.SetHookFunc(&CSystem_RenderEnd_Hook);
}

void ChairImGui::InitGame()
{
	gCL->pImGui = this;
	IMGUI_CHECKVERSION();
	m_pMainContext = ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::StyleColorsDark();

	m_pRenderer = std::make_unique<ImGuiRendererD3D11>();
	gEnv->pRenderer->RegisterSyncWithMainListener(this);
	gCL->pRender->AddListener(this);

	InitBackend();
}

void ChairImGui::ShutdownGame()
{
	m_pFontAtlas = nullptr;
	gCL->pRender->RemoveListener(this);
	gEnv->pRenderer->RemoveSyncWithMainListener(this);
	m_pRenderer = nullptr;
	ImGui::DestroyContext(m_pMainContext);
	m_pMainContext = nullptr;
	gCL->pImGui = nullptr;
	gEnv->pConsole->UnregisterVariable("cl_imgui_scale");
}

void ChairImGui::ShutdownSystem()
{
}

void ChairImGui::UpdateBeforeSystem() {
	CRY_PROFILE_MARKER("ImGui::NewFrame");
	ImGuiIO &io = ImGui::GetIO();

	// Setup display size (every frame to accommodate for window resizing)
	int x, y, width, height;
	gEnv->pRenderer->GetViewport(&x, &y, &width, &height);
	io.DisplaySize = ImVec2((float)width, (float)height);

	// Setup time step
	io.DeltaTime = gEnv->pTimer->GetRealFrameTime();

	// Update mouse
	if (io.WantSetMousePos)
		gEnv->pHardwareMouse->SetHardwareMouseClientPosition(io.MousePos.x, io.MousePos.y);

	bool hasMouseInput = HasExclusiveMouseInput();

	if (!m_ImGuiUsesMouse && hasMouseInput)
	{
		// Enable cursor
		m_LastMouseCursor = ImGuiMouseCursor_None;
	}
	else if (m_ImGuiUsesMouse && !hasMouseInput)
	{
		// Disable cursor
		::SetCursor((HCURSOR)m_hGameCursor);
	}

	if (hasMouseInput)
	{
		ImGuiMouseCursor mouseCursor = io.MouseDrawCursor ? ImGuiMouseCursor_None : ImGui::GetMouseCursor();
		if (m_LastMouseCursor != mouseCursor)
		{
			m_LastMouseCursor = mouseCursor;
			UpdateMouseCursor();
		}
	}

	m_ImGuiUsesMouse = hasMouseInput;

	UpdateScale();
	ImGui::NewFrame();
}

void ChairImGui::RenderEnd()
{
	CRY_PROFILE_MARKER("ImGui::Render");
	ImGui::Render();
	m_DrawBufs[m_iCurrentFillBuf].FillForCurrentContext();
	m_bSwapOnSync = true;
}

bool ChairImGui::HasExclusiveMouseInput()
{
	if (!m_pMainContext)
		return false;

	// Camera mouse input takes priority
	// Use IncrementCounter/DecrementCounter in IHardwareMouse to control it
	auto* pMouse = static_cast<CHardwareMouse*>(gEnv->pHardwareMouse);
	if (pMouse->m_iReferenceCounter == 0)
		return false;

	return ImGui::GetIO().WantCaptureMouse;
}

void ChairImGui::InitBackend() {
	ImGuiIO &io = ImGui::GetIO();
	io.BackendPlatformUserData = this;
	io.BackendPlatformName = "Prey (CryEngine)";
	io.BackendRendererName = "D3D11";
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

	// Load game cursor
	m_hGameCursor = ::LoadCursorA(GetModuleHandleA(0i64), MAKEINTRESOURCEA(110));
	CRY_ASSERT_MESSAGE(m_hGameCursor, "Failed to load game cursor. Invalid .exe?");

	// Initialize scale
	unsigned currentDpi = GetDpiForWindow((HWND)gEnv->pRenderer->GetHWND());
	float dpiScale = currentDpi / DEFAULT_DPI;
	CryLog("Window DPI: {}, setting ImGui scale to {}", currentDpi, dpiScale);
	REGISTER_CVAR2("cl_imgui_scale", &m_CV_scale, dpiScale, VF_NULL, "ImGui scale");
	UpdateScale();
}

void ChairImGui::UpdateScale()
{
	if (m_pFontAtlas && m_flScale == m_CV_scale)
		return;

	m_flScale = std::clamp(m_CV_scale, 0.5f, 4.0f); // Clamp to sane values
	m_CV_scale = m_flScale;
	ReloadStyle();
	ReloadFonts();
}

void ChairImGui::ReloadStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style = ImGuiStyle();
	ImGui::StyleColorsDark();
	style.ScaleAllSizes(m_flScale);
}

void ChairImGui::ReloadFonts() {
	ImGuiIO& io = ImGui::GetIO();

	// Clear everything font-related
	std::fill(std::begin(m_Fonts), std::end(m_Fonts), nullptr);
	io.Fonts->SetTexID((ImTextureID)nullptr);
	io.Fonts->Clear();
	m_pFontAtlas = nullptr;

	// Load fonts from the config
	LoadFontConfig();

	// Create texture
	unsigned char *pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
	
	if (width > 0 && height > 0)
	{
		m_pFontAtlas.Assign_NoAddRef(gEnv->pRenderer->CreateTexture(
			"ImGui Font Atlas", width, height, 1, pixels, eTF_R8G8B8A8, FT_TEX_FONT
		));
	}

	if (!m_pFontAtlas)
		CryError("Failed to create font texture. Maybe it's too large ({}x{}).", width, height);
	else
		CryLog("Font atlas size: {}x{}, {:.1f} MiB", width, height, m_pFontAtlas->GetDataSize() / 1024.0 / 1024.0);

	// Store our identifier
	io.Fonts->SetTexID((ImTextureID)m_pFontAtlas);
}

void ChairImGui::SetFont(EFont font, ImFont* fontPtr)
{
	m_Fonts[(int)font] = fontPtr;
}

void ChairImGui::LoadFontConfig()
{
	ImGuiIO& io = ImGui::GetIO();
	XmlNodeRef fonts = gEnv->pSystem->LoadXmlFromFile(FONT_CONFIG_PATH);
	if (!fonts)
	{
		CryError("Failed to open {}. Falling back to embedded font.", FONT_CONFIG_PATH);
		io.Fonts->AddFontDefault();
		return;
	}

	std::map<std::string, ImFont*> fontsByName;

	for (int i = 0; i < fonts->getChildCount(); i++)
	{
		XmlNodeRef node = fonts->getChild(i);

		// Read name
		const char* name = node->getAttr("name");
		{
			if (!name)
			{
				CryError("Font #{} has no name", i);
				continue;
			}

			auto it = fontsByName.find(name);
			if (it != fontsByName.end())
			{
				CryError("Font #{} '{}' is duplicate", i, name);
				continue;
			}
		}

		ImFont* fontPtr = nullptr;

		// Read files
		XmlNodeRef files = node->findChild("Files");
		if (!files)
		{
			CryError("Font #{}: 'Files' not set", i);
			continue;
		}

		for (int j = 0; j < files->getChildCount(); j++)
		{
			XmlNodeRef fileNode = files->getChild(j);
			const char* path = fileNode->getAttr("path");
			if (!path)
			{
				CryError("Font #{}: File #{}: 'path' not set", i, j);
				continue;
			}

			float fontSize = 0.0f;
			if (!fileNode->getAttr("size", fontSize))
			{
				CryError("Font #{}: File #{}: 'size' not set", i, j);
				continue;
			}

			// Try to load the main font file
			FILE* f = nullptr;
			f = gEnv->pCryPak->FOpen(path, "rb");
			if (!f)
			{
				// Try to open the fallback
				const char* fallbackPath = fileNode->getAttr("fallback");
				if (fallbackPath)
				{
					CryWarning("Font #{}: File #{}: failed to open the main file, falling back", i, j);
					fileNode->getAttr("fallbackSize", fontSize);
					f = gEnv->pCryPak->FOpen(fallbackPath, "rb");
				}
			}

			if (!f)
			{
				CryError("Font #{}: File #{}: failed to open the file", i, j);
				continue;
			}

			// Get file size
			size_t fileSize = gEnv->pCryPak->FGetSize(f);
			if (!fileSize)
			{
				CryError("Font #{}: File #{}: file is empty", i, j);
				gEnv->pCryPak->FClose(f);
				continue;
			}

			// Allocate buffer and read file
			// ImGui will own the pointer and uses ImGui::MemFree to free it
			std::unique_ptr<void, decltype(&ImGui::MemFree)> fileData(ImGui::MemAlloc(fileSize), &ImGui::MemFree);
			if (!gEnv->pCryPak->FReadRaw(fileData.get(), fileSize, 1, f))
			{
				CryError("Font #{}: File #{}: read failed", i, j);
				gEnv->pCryPak->FClose(f);
				continue;
			}

			gEnv->pCryPak->FClose(f);

			// Read config from XML
			ImFontConfig config;
			fileNode->getAttr("oversampleH", config.OversampleH);
			fileNode->getAttr("oversampleV", config.OversampleV);
			fileNode->getAttr("pixelSnapH", config.PixelSnapH);
			fileNode->getAttr("glyphMinAdvanceX", config.GlyphMinAdvanceX);
			fileNode->getAttr("glyphMaxAdvanceX", config.GlyphMaxAdvanceX);
			fileNode->getAttr("rasterizerMultiply", config.RasterizerMultiply);
			if (fontPtr)
				config.MergeMode = true; // Merge into the main font

			// Create the font
			ImFont* ptr = io.Fonts->AddFontFromMemoryTTF(fileData.release(), fileSize, std::floor(fontSize * m_flScale), &config);
			if (!fontPtr)
				fontPtr = ptr;
		}

		// Save the font
		if (!fontPtr)
		{
			CryError("Font #{}: no files loaded", i);
			continue;
		}

		fontsByName[name] = fontPtr;
	}

	// Find "Default" font
	{
		auto it = fontsByName.find("Default");
		if (it != fontsByName.end())
		{
			SetFont(EFont::Default, it->second);
		}
		else
		{
			CryWarning("Failed to find 'Default' font, falling back to embedded font");
			SetFont(EFont::Default, io.Fonts->AddFontDefault());
		}
	}

	auto fnFindFont = [&](EFont font, const std::string& name)
	{
		auto it = fontsByName.find(name);
		if (it != fontsByName.end())
		{
			SetFont(font, it->second);
		}
		else
		{
			CryWarning("Failed to find '{}' font, falling back to 'Default' font", name);
			SetFont(font, GetFont(EFont::Default));
		}
	};

	fnFindFont(EFont::Monospace, "Monospace");
}

void ChairImGui::UpdateMouseCursor()
{
	ImGuiIO& io = ImGui::GetIO();

	if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)
		return;

	ImGuiMouseCursor imguiCursor = ImGui::GetMouseCursor();
	if (imguiCursor == ImGuiMouseCursor_None || io.MouseDrawCursor)
	{
		// Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
		::SetCursor(NULL);
	}
	else
	{
		// Show OS mouse cursor
		LPTSTR win32Cursor = IDC_ARROW;
		switch (imguiCursor)
		{
		case ImGuiMouseCursor_Arrow:        win32Cursor = IDC_ARROW; break;
		case ImGuiMouseCursor_TextInput:    win32Cursor = IDC_IBEAM; break;
		case ImGuiMouseCursor_ResizeAll:    win32Cursor = IDC_SIZEALL; break;
		case ImGuiMouseCursor_ResizeEW:     win32Cursor = IDC_SIZEWE; break;
		case ImGuiMouseCursor_ResizeNS:     win32Cursor = IDC_SIZENS; break;
		case ImGuiMouseCursor_ResizeNESW:   win32Cursor = IDC_SIZENESW; break;
		case ImGuiMouseCursor_ResizeNWSE:   win32Cursor = IDC_SIZENWSE; break;
		case ImGuiMouseCursor_Hand:         win32Cursor = IDC_HAND; break;
		case ImGuiMouseCursor_NotAllowed:   win32Cursor = IDC_NO; break;
		}

		::SetCursor(::LoadCursor(NULL, win32Cursor));
	}
}

ImGuiKey ChairImGui::KeyIdToImGui(EKeyId keyId) {
	switch (keyId)
	{
	case eKI_Tab: return ImGuiKey_Tab;
	case eKI_Left: return ImGuiKey_LeftArrow;
	case eKI_Right: return ImGuiKey_RightArrow;
	case eKI_Up: return ImGuiKey_UpArrow;
	case eKI_Down: return ImGuiKey_DownArrow;
	case eKI_PgUp: return ImGuiKey_PageUp;
	case eKI_PgDn: return ImGuiKey_PageDown;
	case eKI_Home: return ImGuiKey_Home;
	case eKI_End: return ImGuiKey_End;
	case eKI_Insert: return ImGuiKey_Insert;
	case eKI_Delete: return ImGuiKey_Delete;
	case eKI_Backspace: return ImGuiKey_Backspace;
	case eKI_Space: return ImGuiKey_Space;
	case eKI_Enter: return ImGuiKey_Enter;
	case eKI_Escape: return ImGuiKey_Escape;
	case eKI_Apostrophe: return ImGuiKey_Apostrophe;
	case eKI_Comma: return ImGuiKey_Comma;
	case eKI_Minus: return ImGuiKey_Minus;
	case eKI_Period: return ImGuiKey_Period;
	case eKI_Slash: return ImGuiKey_Slash;
	case eKI_Semicolon: return ImGuiKey_Semicolon;
	case eKI_Equals: return ImGuiKey_Equal;
	case eKI_LBracket: return ImGuiKey_LeftBracket;
	case eKI_Backslash: return ImGuiKey_Backslash;
	case eKI_RBracket: return ImGuiKey_RightBracket;
	case eKI_Tilde: return ImGuiKey_GraveAccent;
	case eKI_CapsLock: return ImGuiKey_CapsLock;
	case eKI_ScrollLock: return ImGuiKey_ScrollLock;
	case eKI_NumLock: return ImGuiKey_NumLock;
	case eKI_Print: return ImGuiKey_PrintScreen;
	case eKI_Pause: return ImGuiKey_Pause;
	case eKI_NP_0: return ImGuiKey_Keypad0;
	case eKI_NP_1: return ImGuiKey_Keypad1;
	case eKI_NP_2: return ImGuiKey_Keypad2;
	case eKI_NP_3: return ImGuiKey_Keypad3;
	case eKI_NP_4: return ImGuiKey_Keypad4;
	case eKI_NP_5: return ImGuiKey_Keypad5;
	case eKI_NP_6: return ImGuiKey_Keypad6;
	case eKI_NP_7: return ImGuiKey_Keypad7;
	case eKI_NP_8: return ImGuiKey_Keypad8;
	case eKI_NP_9: return ImGuiKey_Keypad9;
	case eKI_NP_Period: return ImGuiKey_KeypadDecimal;
	case eKI_NP_Divide: return ImGuiKey_KeypadDivide;
	case eKI_NP_Multiply: return ImGuiKey_KeypadMultiply;
	case eKI_NP_Substract: return ImGuiKey_KeypadSubtract;
	case eKI_NP_Add: return ImGuiKey_KeypadAdd;
	case eKI_NP_Enter: return ImGuiKey_KeypadEnter;
	case eKI_LShift: return ImGuiKey_LeftShift;
	case eKI_LCtrl: return ImGuiKey_LeftCtrl;
	case eKI_LAlt: return ImGuiKey_LeftAlt;
	case eKI_LWin: return ImGuiKey_LeftSuper;
	case eKI_RShift: return ImGuiKey_RightShift;
	case eKI_RCtrl: return ImGuiKey_RightCtrl;
	case eKI_RAlt: return ImGuiKey_RightAlt;
	case eKI_RWin: return ImGuiKey_RightSuper;
	//case VK_APPS: return ImGuiKey_Menu;
	case eKI_0: return ImGuiKey_0;
	case eKI_1: return ImGuiKey_1;
	case eKI_2: return ImGuiKey_2;
	case eKI_3: return ImGuiKey_3;
	case eKI_4: return ImGuiKey_4;
	case eKI_5: return ImGuiKey_5;
	case eKI_6: return ImGuiKey_6;
	case eKI_7: return ImGuiKey_7;
	case eKI_8: return ImGuiKey_8;
	case eKI_9: return ImGuiKey_9;
	case eKI_A: return ImGuiKey_A;
	case eKI_B: return ImGuiKey_B;
	case eKI_C: return ImGuiKey_C;
	case eKI_D: return ImGuiKey_D;
	case eKI_E: return ImGuiKey_E;
	case eKI_F: return ImGuiKey_F;
	case eKI_G: return ImGuiKey_G;
	case eKI_H: return ImGuiKey_H;
	case eKI_I: return ImGuiKey_I;
	case eKI_J: return ImGuiKey_J;
	case eKI_K: return ImGuiKey_K;
	case eKI_L: return ImGuiKey_L;
	case eKI_M: return ImGuiKey_M;
	case eKI_N: return ImGuiKey_N;
	case eKI_O: return ImGuiKey_O;
	case eKI_P: return ImGuiKey_P;
	case eKI_Q: return ImGuiKey_Q;
	case eKI_R: return ImGuiKey_R;
	case eKI_S: return ImGuiKey_S;
	case eKI_T: return ImGuiKey_T;
	case eKI_U: return ImGuiKey_U;
	case eKI_V: return ImGuiKey_V;
	case eKI_W: return ImGuiKey_W;
	case eKI_X: return ImGuiKey_X;
	case eKI_Y: return ImGuiKey_Y;
	case eKI_Z: return ImGuiKey_Z;
	case eKI_F1: return ImGuiKey_F1;
	case eKI_F2: return ImGuiKey_F2;
	case eKI_F3: return ImGuiKey_F3;
	case eKI_F4: return ImGuiKey_F4;
	case eKI_F5: return ImGuiKey_F5;
	case eKI_F6: return ImGuiKey_F6;
	case eKI_F7: return ImGuiKey_F7;
	case eKI_F8: return ImGuiKey_F8;
	case eKI_F9: return ImGuiKey_F9;
	case eKI_F10: return ImGuiKey_F10;
	case eKI_F11: return ImGuiKey_F11;
	case eKI_F12: return ImGuiKey_F12;
	default: return ImGuiKey_None;
	}
}

int ChairImGui::GetChairRenderListenerFlags()
{
	return eCRF_RT_Present;
}

void ChairImGui::SyncMainWithRender()
{
	if (m_bSwapOnSync)
	{
		// Swap buffers
		m_iCurrentFillBuf = !m_iCurrentFillBuf;
		m_bSwapOnSync = false;
	}
}

void ChairImGui::RT_Present()
{
	// Render ImGui to the swapchain
	CRY_PROFILE_MARKER("ChairImGui");
	int bufIdx = !m_iCurrentFillBuf;
	m_pRenderer->RT_Render(m_DrawBufs[bufIdx], L"ChairImGui");
}

void ChairImGui::CBaseInput_PostInputEvent(CBaseInput *_this, const SInputEvent &event, bool bForce) {
	if (!g_ChairImGui.m_pMainContext)
	{
		s_hookCBaseInputPostInputEvent.InvokeOrig(_this, event, bForce);
		return;
	}

	ImGuiIO &io = ImGui::GetIO();

	if (event.deviceType == eIDT_Keyboard) {
		// Update modifiers
		io.AddKeyEvent(ImGuiKey_ModCtrl, event.modifiers & eMM_Ctrl);
		io.AddKeyEvent(ImGuiKey_ModShift, event.modifiers & eMM_Shift);
		//io.AddKeyEvent(ImGuiKey_ModAlt, IsVkDown(VK_MENU));
		io.AddKeyEvent(ImGuiKey_ModSuper, event.modifiers & eMM_Win);

		// Send key events
		// Ignore tilde key as it controls the console
		if (event.keyId != eKI_Tilde && event.inputChar != '`') {
			ImGuiKey key = KeyIdToImGui(event.keyId);
			if (key != ImGuiKey_None) {
				io.AddKeyEvent(key, event.value != 0.0f);
			}

			if (event.inputChar > 0 && event.inputChar < 0x10000 && event.state == eIS_UI) {
				io.AddInputCharacterUTF16(event.inputChar);
			}
		}

		if (gChair->HandleKeyPress(event)) {
			return;
		}
	} else if (event.deviceType == eIDT_Mouse) {
		switch (event.keyId) {
		case eKI_Mouse1:
		case eKI_Mouse2:
		case eKI_Mouse3: {
			io.AddMouseButtonEvent(event.keyId - eKI_Mouse1, event.state == eIS_Pressed);
			break;
		}
		case eKI_MouseWheelUp:
		case eKI_MouseWheelDown: {
			io.AddMouseWheelEvent(0.0f, event.value / MOUSE_WHEEL_DELTA);
			break;
		}
		case eKI_MouseX:
		case eKI_MouseY:
		case eKI_MouseXAbsolute: 
		case eKI_MouseYAbsolute: {
			float x, y;
			gEnv->pHardwareMouse->GetHardwareMouseClientPosition(x, y);
			io.AddMousePosEvent(x, y);
			break;
		}
		}

		if (gChair->HandleKeyPress(event)) {
			return;
		}
	}

	if (event.deviceType == eIDT_Keyboard && io.WantTextInput)
		return;

	if (event.deviceType == eIDT_Mouse && g_ChairImGui.m_ImGuiUsesMouse)
	 	return;

	s_hookCBaseInputPostInputEvent.InvokeOrig(_this, event, bForce);
}

bool ChairImGui::CheckVersionAndDataLayout(const char* version_str, size_t sz_io, size_t sz_style, size_t sz_vec2, size_t sz_vec4, size_t sz_drawvert, size_t sz_drawidx)
{
	return ImGui::DebugCheckVersionAndDataLayout(version_str, sz_io, sz_style, sz_vec2, sz_vec4, sz_drawvert, sz_drawidx);
}

ImGuiContext* ChairImGui::GetContext()
{
	return m_pMainContext;
}

void ChairImGui::GetAllocatorFuncs(ImGuiMemAllocFunc* p_alloc_func, ImGuiMemFreeFunc* p_free_func, void** p_user_data)
{
	ImGui::GetAllocatorFunctions(p_alloc_func, p_free_func, p_user_data);
}

ImFont* ChairImGui::GetFont(EFont font)
{
	return m_Fonts[(int)font];
}
