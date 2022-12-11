#pragma once
#include <Prey/CryRenderer/IRenderer.h>
#include <ImGuiRendererD3D11.h>

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
	PreditorImGui* m_pBackend = nullptr;
	ImGuiRendererD3D11 m_Renderer;
	ImRendDrawBuffer m_DrawBufs[2];
	int m_iCurrentFillBuf = 0;
	bool m_bSwapOnSync = false;
	_smart_ptr<ITexture> m_pFontAtlas = nullptr;

	void SyncMainWithRender() override;
};
