#pragma once
#include <Prey/CryMath/Cry_Camera.h>

class SceneViewport : public ISystemEventListener
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

	// ISystemEventListener
	void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override;

private:
	struct CameraInfo
	{
		bool transformValid = false; //!< Camera has a meaningful position. Reset on level change.
		Vec3 pos = Vec3(ZERO);
		Ang3 rot = Ang3(ZERO);
		float fov = 90.0f; // In degrees
		float nearPlane = DEFAULT_NEAR;
		float farPlane = DEFAULT_FAR;
	};

	bool m_bActive = false; //!< The viewport is active.
	bool m_bGrabMouse = false; //!< Grab mouse for camera movement
	CCamera m_Cam;
	CameraInfo m_CamInfo;

	void UpdateCamera();
	void CopyViewCameraTransform();
};
