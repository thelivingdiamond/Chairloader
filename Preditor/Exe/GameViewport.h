#pragma once
#include <WindowManager/ManagedWindow.h>

struct ITexture;

class GameViewport : public ManagedWindow
{
public:
	GameViewport();

protected:
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
};
