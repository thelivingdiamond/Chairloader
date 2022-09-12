#pragma once
#include <Prey/CryMath/Cry_Geo.h>

struct SViewParams;

class EditorView
{
public:
	static void InitHooks();
	EditorView();
	~EditorView();

	void Update();
	bool HandleInput(const SInputEvent& event);
	void GetViewParams(SViewParams& params);

	void SetGrabInput(bool state);
	bool IsGrabInput() { return m_bGrabInput; }
	const Vec3& GetPos() { return m_vPos; }

	void MoveCameraToPlayer();

	//! Coverts a viewport position into a world-space ray.
	//! @param	pixelPos	On-screen position. (0,0) in top-left corner.
	//! @returns a ray that originates in camera origin and goes through pixelPos on the screen.
	Ray ViewportPointToRay(Vec2 pixelPos);

private:
	struct InputState
	{
		bool fwd = false;
		bool back = false;
		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;
		bool boost = false;

		Vec2 mouseDelta = Vec2(ZERO);
	};
	
	bool m_bGrabInput = false;
	InputState m_Input;
	Vec3 m_vPos = Vec3(ZERO);
	Ang3 m_vRot = Ang3(ZERO);
	float m_MoveSpeed = false;
};
