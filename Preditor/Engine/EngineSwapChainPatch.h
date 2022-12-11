#pragma once

struct IDXGISwapChain;

//! This patch replaces the engine's IDXGISwapChain with a fake one that draws
//! the contents into an off-screen buffer. The buffer can later be displayed in ImGui.
class EngineSwapChainPatch
{
public:
	EngineSwapChainPatch();
	~EngineSwapChainPatch();
	static void InitHooks();

	IDXGISwapChain* MakeSwapChain(IDXGISwapChain* pRealSwapChain);

private:
	class FakeSwapChain;
	
	std::unique_ptr<FakeSwapChain> m_pSwapChain;

	void RT_DrawImGui();
};
