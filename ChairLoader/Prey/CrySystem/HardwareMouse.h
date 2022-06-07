#pragma once
#include <list>
#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CryRenderer/IRenderer.h>

class ITexture;

class CHardwareMouse : IRendererEventListener, IInputEventListener, IHardwareMouse, ISystemEventListener
{
	std::list<IHardwareMouseEventListener *> m_listHardwareMouseEventListeners;
	ITexture *m_pCursorTexture;
	int m_iReferenceCounter;
	float m_fCursorX;
	float m_fCursorY;
	float m_fIncX;
	float m_fIncY;
	bool m_bFocus;
	bool m_recapture;
	const bool m_allowConfine;
	bool m_useSystemCursor;
	bool m_shouldUseSystemCursor;
	bool m_paused;
	bool m_shouldPause;
	bool m_hide;
	bool m_calledShowHWMouse;
	int m_debugHardwareMouse;
};
