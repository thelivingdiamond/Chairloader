#pragma once
#include <ImGui/imgui.h>

class AppStage;
class AppImGui;

class Application
{
public:
	//! @returns the applictaion singleton.
	static Application* Get();

	Application();
	virtual ~Application();

	//! Starts the application's event loop until the app finishes.
	//! @returns exit code
	int Run();

	//! Sets the current app stage.
	void SetStage(AppStage* stage);
	AppStage* GetStage() { return m_pCurrentStage; }

	//! Calls ShowUI for the stage and redraws ImGui.
	//! Can be used inside Update to show progress or something.
	void RefreshUI();

protected:
	//! Updates the app. Called before the stage update.
	virtual void Update();

	//! Shows the ImGui IU. Called before the stage ShowUI.
	virtual void ShowUI(bool * bOpen);

private:
	std::unique_ptr<AppImGui> m_pImGui;
	AppStage* m_pCurrentStage = nullptr;
	bool m_bIsRunning = false;
};
