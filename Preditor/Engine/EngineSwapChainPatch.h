#pragma once

enum DXGI_FORMAT;
struct IDXGISwapChain;
struct ITexture;
class CTexture;

//! This patch replaces the engine's IDXGISwapChain with a fake one that draws
//! the contents into an off-screen buffer. The buffer can later be displayed in ImGui.
class EngineSwapChainPatch
{
public:
	EngineSwapChainPatch();
	~EngineSwapChainPatch();
	static void InitHooks();
	static ITexture* GetBackbuffer();

	IDXGISwapChain* MakeSwapChain(IDXGISwapChain* pRealSwapChain);

private:
	class FakeSwapChain;
	
	std::unique_ptr<FakeSwapChain> m_pSwapChain;

	//! The render target owning texture.
	//! Recreated every time resolution changes.
	_smart_ptr<CTexture> m_pBackbuffer;

	//! The render target non-owning reference. References m_pBackbuffer.
	//! This is done because ImGui takes the pointer on the main thread and passes it
	//! over to the render thread. The texture object may become destroyed in one frame and then
	//! referenced in the next frame by ImGui renderer.
	//! GetBackbuffer() returns this texture.
	_smart_ptr<CTexture> m_pBackbufferRef;

	void RT_ResizeBackbuffer(int width, int height, DXGI_FORMAT format);
	void RT_DrawImGui();
};
