#pragma once
#include <Prey/CryMath/Cry_Camera.h>

class SceneViewport
{
public:
	SceneViewport();

	//! Called every frame.
	//! @param	isVisible	Whether the window is visible.
	void Update(bool isVisible);

	//! Called when the viewport becomes active.
	void OnActivate();

	//! Called when the viewport becomes inactive.
	void OnDeactivate();

	//! Shows the controls at the top of the window.
	void ShowTopControls();

	//! Renders the world. Called in place of CSystem::Render's render func.
	void Render();

	//! Sets whether to grab mouse for camera control.
	void SetMouseGrabbed(bool state);
	bool IsMouseGrabbed() { return m_bGrabMouse; }

private:
	bool m_bActive = false; //!< The viewport is active.
	bool m_bGrabMouse = false; //!< Grab mouse for camera movement
	CCamera m_Cam;

	void UpdateCamera();
};
