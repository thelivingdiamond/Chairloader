#pragma once
#include <imgui.h>

struct IBasicEventListener;

//! The patch rewrites some of the methods in CHardwareMouse to support multiple windows.
class HardwareMousePatch
{
public:
	static void InitHooks();
	static void SetIBasicEventListener(IBasicEventListener* ptr);

	//! Sets the screen bounds of the viewport window.
	static void SetGameViewportBounds(ImGuiID viewportId, Vec2i min, Vec2i max);

	//! Sets whether the game viewport is focused.
	static void SetWindowFocused(bool state);

	//! Processes mouse events.
	//! @returns true if it was processed and doesn't need to be passed to the game.
	static bool HandleMouseMessage(HWND hWnd, unsigned msg, uint64_t wParam, int64_t lParam);
};
