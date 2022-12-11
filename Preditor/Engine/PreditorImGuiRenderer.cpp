#include <Prey/CrySystem/System.h>
#include "PreditorImGuiRenderer.h"
#include "PreditorImGui.h"

namespace
{

PreditorImGuiRenderer* g_pPreditorImGuiRenderer;
auto s_CSystem_RenderEnd_Hook = CSystem::FRenderEnd.MakeHook();

void CSystem_RenderEnd_Hook(CSystem* const _this, bool bRenderStats)
{
	ImGuiIO& io = ImGui::GetIO();
	static_cast<PreditorImGuiRenderer*>(io.BackendRendererUserData)->RenderEnd();
	return s_CSystem_RenderEnd_Hook.InvokeOrig(_this, bRenderStats);
}

}

PreditorImGuiRenderer* PreditorImGuiRenderer::Get()
{
	return g_pPreditorImGuiRenderer;
}

void PreditorImGuiRenderer::InitHooks()
{
	s_CSystem_RenderEnd_Hook.SetHookFunc(&CSystem_RenderEnd_Hook);
}

PreditorImGuiRenderer::PreditorImGuiRenderer(PreditorImGui* pBackend)
{
	assert(!g_pPreditorImGuiRenderer);
	g_pPreditorImGuiRenderer = this;
	m_pBackend = pBackend;
	ImGuiIO& io = ImGui::GetIO();

	io.BackendRendererUserData = (void*)this;
	io.BackendRendererName = "D3D11 (CRYENGINE)";
	io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.
	//io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;  // We can create multi-viewports on the Renderer side (optional)

	gEnv->pRenderer->RegisterSyncWithMainListener(this);
}

PreditorImGuiRenderer::~PreditorImGuiRenderer()
{
	assert(g_pPreditorImGuiRenderer == this);
	gEnv->pRenderer->RemoveSyncWithMainListener(this);
	g_pPreditorImGuiRenderer = nullptr;
}

void PreditorImGuiRenderer::RenderEnd()
{
	if (ImGui::GetCurrentContext() != m_pBackend->GetContext())
		return;

	ImGui::Render();
	m_DrawBufs[m_iCurrentFillBuf].FillForCurrentContext();
	m_bSwapOnSync = true;
	m_pBackend->OnWasRendered();
}

void PreditorImGuiRenderer::UpdateFontAtlasTexture()
{
	m_pFontAtlas = nullptr;
	ImGuiIO& io = ImGui::GetIO();
	unsigned char* pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);

	if (width > 0 && height > 0)
	{
		m_pFontAtlas.Assign_NoAddRef(gEnv->pRenderer->CreateTexture(
			"ImGui Font Atlas", width, height, 1, pixels, eTF_R8G8B8A8, FT_TEX_FONT
		));
	}

	if (!m_pFontAtlas)
		CryError("Failed to create font texture. Maybe it's too large ({}x{}).", width, height);
	else
		CryLog("Font atlas size: {}x{}, {:.1f} MiB", width, height, m_pFontAtlas->GetDataSize() / 1024.0 / 1024.0);

	// Store our identifier
	io.Fonts->SetTexID((ImTextureID)m_pFontAtlas);
}

void PreditorImGuiRenderer::RT_Render()
{
	int bufIdx = !m_iCurrentFillBuf;
	m_Renderer.RT_Render(m_DrawBufs[bufIdx], L"PreditorImGui");
}

void PreditorImGuiRenderer::SyncMainWithRender()
{
	if (m_bSwapOnSync)
	{
		// Swap buffers
		m_iCurrentFillBuf = !m_iCurrentFillBuf;
		m_bSwapOnSync = false;
	}
}
