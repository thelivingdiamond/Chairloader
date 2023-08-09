#pragma once
#include <WindowManager/ManagedWindow.h>

struct IKeyAction;

namespace Main
{

class SimControlWindow : public ManagedWindow
{
public:
	SimControlWindow();

	//! Shows the main menu bar menu contents.
	void ShowMenu();

protected:
	void ShowContents() override;

private:
	static constexpr float DEFAULT_FPS[] = { 30, 60, 90, 120 };
	float m_flTimeStepMs = 1000.0f / 60.0f;
	IKeyAction* m_pPlayPause = nullptr;
	IKeyAction* m_pSingleStep = nullptr;
	IKeyAction* m_pTogglePlayMode = nullptr;
};

} // namespace Main
