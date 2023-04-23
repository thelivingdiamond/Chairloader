#pragma once
#include <WindowManager/ManagedWindow.h>
#include <Preditor/IGameViewport.h>
#include "SceneViewport.h"

struct ITexture;

class GameViewport
	: public ManagedWindow
	, public IGameViewport
{
public:
	enum class ViewportMode
	{
		None,
		Scene,
		Game,
	};

	GameViewport();
	~GameViewport();

	//! Sets a new viewport mode.
	void SetViewportMode(ViewportMode mode);

	// IGameViewport
	bool NeedCustomRender() override;
	void CustomRender() override;
	bool HandleInputEventPreGame(const SInputEvent& event) override;
	bool EnableMouseEvents() override;

protected:
	void PreUpdate() override;
	void Update(bool isVisible) override;
	void ShowContents() override;

private:
	//! Hardcoded minimum viewport size in the engine
	static constexpr int MIN_WIDTH = 512;
	static constexpr int MIN_HEIGHT = 300;

	//! Maximum reasonable size to prevent crashes
	static constexpr int MAX_SIZE = 8192;

	ITexture* m_pViewportTexture = nullptr;
	ICVar* m_pCVarWidth = nullptr;
	ICVar* m_pCVarHeight = nullptr;

	ViewportMode m_ViewportMode = ViewportMode::None;
	bool m_bEnableInput = false;
	bool m_bLockMouse = false;

	SceneViewport m_SceneVp;

	void ShowTopControls();
	void ShowGameModeControls();
	void SetInputEnabled(bool state);
	void SetMouseLocked(bool state);
};
