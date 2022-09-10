#pragma once
#include "../EntityHierarchy.h"
#include "../EntityInspector.h"

class EditorView;

class Editor : public ISystemEventListener
{
public:
	static void InitHooks();
	static Editor* Get();
	Editor();
	~Editor();

	bool IsInEditor() { return m_bInEditor; }

	void Update();
	bool HandleKeyPress(const SInputEvent& event);
	bool HandleEditorKeyPress(const SInputEvent& event);

	// ISystemEventListener
	void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override;

private:
	static constexpr char SAVE_NAME[] = "chaireditor_save";

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

	std::unique_ptr<EditorView> m_pView;

	bool m_bGameWindowIsNowActive = false;
	bool m_bReloadModsNextFrame = false;
	State m_State = State::Unloaded;
	bool m_bIsGamePaused = false;
	bool m_bInEditor = false; //!< Controlling the editor
	MouseGuard m_Mouse;

	EntityHierarchy m_Hierarchy;
	EntityInspector m_Inspector;

	void SwitchStates();
	void UpdateUnloaded();
	void UpdateLoading();
	void UpdateRunning();
	void UpdateInEditor();

	void SetGamePaused(bool state);
	void SetInEditor(bool state);
	void SetEditorCameraControl(bool state);

	void SelectEntInViewport(Vec2 pixelPos);
	bool ReloadLevel();
	bool ReloadMods();
	bool SaveAndUnloadLevel();
	bool RestoreSavedLevel();
};
