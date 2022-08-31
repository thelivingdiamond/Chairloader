#pragma once

struct IView;

class Editor
{
public:
	static void InitHooks();
	static Editor* Get();
	Editor();
	~Editor();

	void Update();
	bool HandleKeyPress(const SInputEvent& event);
	bool HandleEditorKeyPress(const SInputEvent& event);
	bool UpdateView(SViewParams& params);

private:
	enum class State
	{
		Invalid,
		Unloaded, //!< In the main menu
		Loading, //!< Loading the game
		Running, //!< Level is fully loaded
	};

	//! A RAII struct to call pHardwareMouse->Increment/DecrementCounter without screing it up.
	struct MouseGuard
	{
		bool isVisible = false;

		MouseGuard();
		~MouseGuard();
		void ShowCursor();
		void HideCursor();
		void SetVisible(bool state);
	};

	State m_State = State::Unloaded;
	bool m_bIsGamePaused = false;
	bool m_bInEditor = false; //!< Controlling the editor
	MouseGuard m_Mouse;

	// Editor view
	bool m_bEnableCameraControl = false;
	Vec3 m_vEditorViewPos = Vec3(ZERO);
	Ang3 m_vEditorViewRot = Ang3(ZERO);
	float m_flEditorViewSpeed = 0;

	Vec3i m_vMovementInput = Vec3i(ZERO);
	Vec2 m_vMouseInput = Vec2(ZERO);
	bool m_bBoostInput = false;

	void SwitchStates();
	void UpdateUnloaded();
	void UpdateLoading();
	void UpdateRunning();
	void UpdateInEditor();

	void UpdateEditorView();

	void SetGamePaused(bool state);
	void SetInEditor(bool state);
	void SetEditorCameraControl(bool state);
};
