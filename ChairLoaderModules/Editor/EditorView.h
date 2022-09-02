#pragma once

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
