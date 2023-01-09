#include <Prey/CrySystem/HardwareMouse.h>
#include <Prey/GameDll/basiceventlistener.h>
#include <Preditor/IGameViewport.h>
#include "HardwareMousePatch.h"
#include "PreditorImGui.h"

namespace
{

IBasicEventListener* g_pBasicEventListener = nullptr;
IGameViewport* g_pVP = nullptr;
ImGuiID g_ViewportId = 0;
Vec2i g_MinBounds = Vec2i(ZERO);
Vec2i g_MaxBounds = Vec2i(ZERO);

bool g_bIgnoreSetPos = false;

auto g_CHardwareMouse_Event_Hook = CHardwareMouse::FEvent.MakeHook();
auto g_CHardwareMouse_SetHardwareMousePosition_Hook = CHardwareMouse::FSetHardwareMousePosition.MakeHook();
auto g_CHardwareMouse_GetHardwareMouseClientPosition_Hook = CHardwareMouse::FGetHardwareMouseClientPosition.MakeHook();
auto g_CHardwareMouse_SetHardwareMouseClientPosition_Hook = CHardwareMouse::FSetHardwareMouseClientPosition.MakeHook();
auto g_CHardwareMouse_ShowHardwareMouse_Hook = CHardwareMouse::FShowHardwareMouse.MakeHook();
auto g_CHardwareMouse_ConfineCursor_Hook = CHardwareMouse::FConfineCursor.MakeHook();
auto g_CHardwareMouse_OnSystemEvent_Hook = CHardwareMouse::FOnSystemEvent.MakeHook();

//! Converts lparam from window coordinates to game viewport coordinates
int64_t FixUpMouseLParam(HWND hWnd, int64_t lParam)
{
	POINT point = { LOWORD(lParam), HIWORD(lParam) };
	::ClientToScreen(hWnd, &point);
	point.x -= g_MinBounds.x;
	point.y -= g_MinBounds.y;
	return MAKELPARAM(point.x, point.y);
}

void CHardwareMouse_Event_Hook(IHardwareMouse* const _this, int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta)
{
	if (!g_pVP || g_pVP->EnableMouseEvents())
		g_CHardwareMouse_Event_Hook.InvokeOrig(_this, iX, iY, eHardwareMouseEvent, wheelDelta);
}

void CHardwareMouse_SetHardwareMousePosition_Hook(IHardwareMouse* const _ithis, float fX, float fY)
{
	CHardwareMouse* _this = static_cast<CHardwareMouse*>(_ithis);
	if (_this->m_bFocus && !g_bIgnoreSetPos)
	{
		// Move cursor position only if our window is focused.
		SetCursorPos((int)fX, (int)fY);
	}
}

void CHardwareMouse_GetHardwareMouseClientPosition_Hook(IHardwareMouse* const _ithis, float* pfX, float* pfY)
{
	CHardwareMouse* _this = static_cast<CHardwareMouse*>(_ithis);
	POINT pointCursor;
	GetCursorPos(&pointCursor);
	*pfX = pointCursor.x - g_MinBounds.x;
	*pfY = pointCursor.y - g_MinBounds.y;
}

void CHardwareMouse_SetHardwareMouseClientPosition_Hook(IHardwareMouse* const _ithis, float fX, float fY)
{
	CHardwareMouse* _this = static_cast<CHardwareMouse*>(_ithis);
	fX += g_MinBounds.x;
	fY += g_MinBounds.y;
	_this->SetHardwareMousePosition(fX, fY);
}

void CHardwareMouse_ShowHardwareMouse_Hook(CHardwareMouse* const _this, bool bShow)
{
	// ShowHardwareMouse(true) will restore the old mouse position
	// We don't want this
	g_bIgnoreSetPos = true;
	g_CHardwareMouse_ShowHardwareMouse_Hook.InvokeOrig(_this, bShow);
	g_bIgnoreSetPos = false;

	// Update to the current pos
	_this->GetHardwareMousePosition(&_this->m_fCursorX, &_this->m_fCursorY);
}

void CHardwareMouse_ConfineCursor_Hook(IHardwareMouse* const _ithis, bool confine, bool centerCursor)
{
	CHardwareMouse* _this = static_cast<CHardwareMouse*>(_ithis);
	if (_this->m_debugHardwareMouse)
		CryLog("HM: ConfineCursor = {}", confine);

	if (!_this->m_bFocus)
		return;

	// It's necessary to call ClipCursor AFTER the calls to
	// CreateDevice/ResetDevice otherwise the clip area is reseted.
	if (confine)
	{
		if (_this->m_debugHardwareMouse)
			gEnv->pLog->Log("HM:   Confining cursor");
		RECT rcClient;
		rcClient.left = g_MinBounds.x;
		rcClient.top = g_MinBounds.y;
		rcClient.right = g_MaxBounds.x;
		rcClient.bottom = g_MaxBounds.y;
		::ClipCursor(&rcClient);
	}
	else
	{
		if (_this->m_debugHardwareMouse)
			gEnv->pLog->Log("HM:   Releasing cursor");
		::ClipCursor(NULL);
	}
}

void CHardwareMouse_OnSystemEvent_Hook(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)
{
	if (event == ESYSTEM_EVENT_ACTIVATE || event == ESYSTEM_EVENT_CHANGE_FOCUS)
		return;
	g_CHardwareMouse_OnSystemEvent_Hook.InvokeOrig(_this, event, wparam, lparam);
}

} // namespace

void HardwareMousePatch::InitHooks()
{
	g_CHardwareMouse_Event_Hook.SetHookFunc(&CHardwareMouse_Event_Hook);
	g_CHardwareMouse_SetHardwareMousePosition_Hook.SetHookFunc(&CHardwareMouse_SetHardwareMousePosition_Hook);
	g_CHardwareMouse_GetHardwareMouseClientPosition_Hook.SetHookFunc(&CHardwareMouse_GetHardwareMouseClientPosition_Hook);
	g_CHardwareMouse_SetHardwareMouseClientPosition_Hook.SetHookFunc(&CHardwareMouse_SetHardwareMouseClientPosition_Hook);
	g_CHardwareMouse_ShowHardwareMouse_Hook.SetHookFunc(&CHardwareMouse_ShowHardwareMouse_Hook);
	g_CHardwareMouse_ConfineCursor_Hook.SetHookFunc(&CHardwareMouse_ConfineCursor_Hook);
	g_CHardwareMouse_OnSystemEvent_Hook.SetHookFunc(&CHardwareMouse_OnSystemEvent_Hook);
}

void HardwareMousePatch::SetIBasicEventListener(IBasicEventListener* ptr)
{
	g_pBasicEventListener = ptr;
}

void HardwareMousePatch::SetGameViewport(IGameViewport* pVP)
{
	g_pVP = pVP;
}

bool HardwareMousePatch::SetGameViewportBounds(ImGuiID viewportId, Vec2i min, Vec2i max)
{
	if (g_ViewportId != viewportId || g_MinBounds != min || g_MaxBounds != max)
	{
		g_ViewportId = viewportId;
		g_MinBounds = min;
		g_MaxBounds = max;

		// Update confinement
		CHardwareMouse* _this = static_cast<CHardwareMouse*>(gEnv->pHardwareMouse);
		if (_this->m_bFocus)
			_this->ConfineCursor(_this->m_iReferenceCounter == 0, false);

		return true;
	}

	return false;
}

void HardwareMousePatch::SetWindowFocused(bool bFocus)
{
	CHardwareMouse* _this = static_cast<CHardwareMouse*>(gEnv->pHardwareMouse);

	if (_this->m_bFocus == bFocus)
		return;

	if (bFocus)
	{
		// set focus first so the calls below work
		_this->m_bFocus = true;

		_this->ShowHardwareMouse(_this->m_iReferenceCounter >= 1);
		_this->ConfineCursor(_this->m_iReferenceCounter == 0, false);
	}
	else
	{
		// always, always show and release the mouse confinement when we lose focus
		_this->ShowHardwareMouse(true);
		_this->ConfineCursor(false, false);

		// first release, then lose focus, so calls above work
		_this->m_bFocus = false;
	}
}

bool HardwareMousePatch::HandleMouseMessage(HWND hWnd, unsigned msg, uint64_t wParam, int64_t lParam)
{
	HWND hMainWnd = (HWND)gEnv->pSystem->GetHWND();
	lParam = FixUpMouseLParam(hWnd, lParam);
	switch (msg)
	{
	case WM_MOUSEMOVE:
		g_pBasicEventListener->OnMouseMove(hMainWnd, lParam);
		return true;
	case WM_LBUTTONDOWN:
		g_pBasicEventListener->OnLeftButtonDown(hMainWnd, lParam);
		return true;
	case WM_LBUTTONUP:
		g_pBasicEventListener->OnLeftButtonUp(hMainWnd, lParam);
		return true;
	case WM_LBUTTONDBLCLK:
		g_pBasicEventListener->OnLeftButtonDoubleClick(hMainWnd, lParam);
		return true;
	case WM_RBUTTONDOWN:
		g_pBasicEventListener->OnRightButtonDown(hMainWnd, lParam);
		return true;
	case WM_RBUTTONUP:
		g_pBasicEventListener->OnRightButtonUp(hMainWnd, lParam);
		return true;
	case WM_MOUSEWHEEL:
		g_pBasicEventListener->OnMouseWheel(hMainWnd, lParam, GET_WHEEL_DELTA_WPARAM(wParam));
		return true;
	}

	return false;
}
