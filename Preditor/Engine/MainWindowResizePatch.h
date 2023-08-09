#pragma once
#include <Chairloader/IChairRender.h>

namespace Engine
{

//! This patch allows the user to resize the main window and handles real swap chain resize.
class MainWindowResizePatch : private IChairRenderListener
{
public:
	static void InitHooks();
	static void InitSystem();
	static void ShutdownSystem();

	//! Handles WM_SIZE message.
	static void OnWindowResize(int width, int height);

	//! Resizes the swap chain buffers if window size has changed.
	void RT_HandleDisplayPropertyChanges();

private:
	// Written in main thread, read in render thread.
	// Race is possible but won't be destructive.
	Vec2i m_WindowSize = Vec2i(ZERO);

	// IChairRenderListener
	int GetChairRenderListenerFlags() override;
	void InitRenderer() override;
};

} // namespace Engine
