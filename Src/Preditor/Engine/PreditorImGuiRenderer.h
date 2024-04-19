#pragma once
#include <Prey/CryRenderer/IRenderer.h>
#include <Chairloader/IChairRender.h>
#include <ImGuiRendererD3D11.h>

namespace Engine
{

class PreditorImGui;

class PreditorImGuiRenderer : private ISyncMainWithRenderListener
{
public:
	static PreditorImGuiRenderer* Get();
	static void InitHooks();

	PreditorImGuiRenderer(PreditorImGui* pBackend);
	~PreditorImGuiRenderer();
	void RenderEnd();
	void UpdateFontAtlasTexture();

	void RT_Render();

private:
	struct ViewportData
	{
		bool bExists = false;
		_smart_ptr<IDXGISwapChain> pSwapChain;
		_smart_ptr<ID3D11RenderTargetView> pRTView;
	};

	struct DoubleBuffer
	{
		ImRendDrawBuffer bufs[2];
		bool bClear = false;
	};

	PreditorImGui* m_pBackend = nullptr;
	ImGuiRendererD3D11 m_Renderer;
	DoubleBuffer m_MainDrawBuf;
	std::vector<DoubleBuffer> m_ViewportDrawBufs;
	int m_iCurrentFillBuf = 0;
	bool m_bSwapOnSync = false;
	_smart_ptr<ITexture> m_pFontAtlas = nullptr;

	// Render commands
	RenderCmdId m_nCmdSetWindowSize = INVALID_RENDER_CMD_ID;

	//! Read/written on the render thread.
	//! Resized on the main thread when creating/destroying windows. Render thread is idle in that case.
	std::vector<ViewportData> m_ViewportData;

	void InitPlatformInterface();
	void ShutdownPlatformInterface();
	void SyncMainWithRender() override;

	// Platform interface for multiple viewports
	static void Plat_CreateWindow(ImGuiViewport* viewport);
	static void Plat_DestroyWindow(ImGuiViewport* viewport);
	static void Plat_SetWindowSize(ImGuiViewport* viewport, ImVec2 size);
	void RT_Plat_SetWindowSize(size_t vdIdx, ImVec2 size);
};

} // namespace Engine
