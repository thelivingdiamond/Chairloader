#define DIRECTINPUT_VERSION 0x0800
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include <dinput.h>
#include "MouseInputSystem.h"

Input::MouseInputSystem::MouseInputSystem()
{
	HRESULT hr;
	DIPROPDWORD dipdw;
	m_hWnd = gEnv->pSystem->GetHWND();
	m_pMouseSens = gEnv->pConsole->GetCVar("cl_sensitivity");

	hr = DirectInput8Create(GetModuleHandle(0), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pDI, 0);
	if (FAILED(hr))
	{
		CryLog("Cannot initialize DirectInput\n");
		return;
	}

	hr = m_pDI->CreateDevice(GUID_SysMouse, &m_pDevice, nullptr);
	if (FAILED(hr))
	{
		CryLog("CreateDevice failed\n");
		return;
	}

	hr = m_pDevice->SetDataFormat(&c_dfDIMouse2);
	if (FAILED(hr))
	{
		CryLog("SetDataFormat failed\n");
		return;
	}

	hr = m_pDevice->SetCooperativeLevel((HWND)m_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (FAILED(hr))
	{
		CryLog("SetCooperativeLevel failed\n");
		return;
	}

	dipdw = { { sizeof(DIPROPDWORD), sizeof(DIPROPHEADER), 0, DIPH_DEVICE }, BUF_SIZE };
	hr = m_pDevice->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	if (FAILED(hr))
	{
		CryLog("SetProperty DIPROP_BUFFERSIZE failed\n");
		return;
	}

	// Set mouse axis mode.
	dipdw = { { sizeof(DIPROPDWORD), sizeof(DIPROPHEADER), 0, DIPH_DEVICE }, DIPROPAXISMODE_REL };
	hr = m_pDevice->SetProperty(DIPROP_AXISMODE, &dipdw.diph);
	if (FAILED(hr))
	{
		CryLog("SetProperty DIPROP_AXISMODE failed\n");
		return;
	}

	Acquire();
}

Input::MouseInputSystem::~MouseInputSystem()
{
	SAFE_RELEASE(m_pDevice);
	SAFE_RELEASE(m_pDI);
}

void Input::MouseInputSystem::SetExclusiveInputActive(bool state)
{
	if (m_IsActive != state)
	{
		m_IsActive = state;

		if (state)
		{
			// Reset delta
			GetMouseDelta();
		}
		else
		{
			if (GetFocus() == m_hWnd)
			{
				// Remove confinement
				::ClipCursor(NULL);
			}
		}
	}
}

Vec2 Input::MouseInputSystem::PeekMouseDelta()
{
	if (!m_pDevice)
		return Vec2(0, 0);

	HRESULT hr;
	DIMOUSESTATE2 dims;
	memset(&dims, 0, sizeof(dims));

	hr = m_pDevice->GetDeviceState(sizeof(DIMOUSESTATE2), &dims);

	if (FAILED(hr) && Acquire())
	{
		// try again
		hr = m_pDevice->GetDeviceState(sizeof(DIMOUSESTATE2), &dims);
	}

	if (SUCCEEDED(hr))
	{
		// TODO 2023-06-21: Add custom sensitivity
		Vec2 newDelta((float)dims.lX, (float)dims.lY);
		m_Delta += newDelta * m_pMouseSens->GetFVal();
	}

	// Update confinement
	if (m_IsActive && GetFocus() == m_hWnd)
	{
		RECT rcClient;
		Vec4i bounds = gPreditor->pViewportWindow->GetScreenBounds();
		rcClient.left = bounds.x;
		rcClient.top = bounds.y;
		rcClient.right = bounds.z;
		rcClient.bottom = bounds.w;
		::ClipCursor(&rcClient);
	}

	return m_Delta;
}

Vec2 Input::MouseInputSystem::GetMouseDelta()
{
	Vec2 delta = PeekMouseDelta();
	m_Delta.SetZero();
	return delta;
}

bool Input::MouseInputSystem::Acquire()
{
	if (!m_pDevice)
		return false;

	HRESULT hr = m_pDevice->Acquire();

	unsigned char maxAcquire = 10;

	while (hr == DIERR_INPUTLOST && maxAcquire > 0)
	{
		hr = m_pDevice->Acquire();
		--maxAcquire;
	}

	if (FAILED(hr) || maxAcquire == 0)
		return false;

	return true;
}
