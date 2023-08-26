#ifndef UI_H
#define UI_H
#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <tchar.h>

#include "ImGui/imgui.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class ImGuiFontList;

class UI
{
private:
	static ID3D11Device* pd3dDevice;
	static ID3D11DeviceContext* pd3dDeviceContext;
	static IDXGISwapChain* pSwapChain;
	static ID3D11RenderTargetView* pMainRenderTargetView;
	static bool bIsRunning;
	static ImGuiFontList fontList;

	static bool CreateDeviceD3D(HWND hWnd);
	static void CleanupDeviceD3D();
	static void CreateRenderTarget();
	static void CleanupRenderTarget();
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	static void Setup();
	static void Render();
	static void RequestExit();
    static void ResetDX11();
	static void ReloadFonts(float dpiScale);
};

#endif
