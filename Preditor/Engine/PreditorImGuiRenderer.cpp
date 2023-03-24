#include <Prey/CrySystem/System.h>
#include <Prey/CrySystem/Profiling.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Preditor/IPreditorEngine.h>
#include "PreditorImGuiRenderer.h"
#include "PreditorImGui.h"

namespace
{

Engine::PreditorImGuiRenderer* g_pPreditorImGuiRenderer;
auto s_CSystem_RenderEnd_Hook = CSystem::FRenderEnd.MakeHook();

void CSystem_RenderEnd_Hook(CSystem* const _this, bool bRenderStats)
{
	ImGuiIO& io = ImGui::GetIO();
	static_cast<Engine::PreditorImGuiRenderer*>(io.BackendRendererUserData)->RenderEnd();
	return s_CSystem_RenderEnd_Hook.InvokeOrig(_this, bRenderStats);
}

}

Engine::PreditorImGuiRenderer* Engine::PreditorImGuiRenderer::Get()
{
	return g_pPreditorImGuiRenderer;
}

void Engine::PreditorImGuiRenderer::InitHooks()
{
	s_CSystem_RenderEnd_Hook.SetHookFunc(&CSystem_RenderEnd_Hook);
}

Engine::PreditorImGuiRenderer::PreditorImGuiRenderer(PreditorImGui* pBackend)
{
	assert(!g_pPreditorImGuiRenderer);
	g_pPreditorImGuiRenderer = this;
	m_pBackend = pBackend;
	ImGuiIO& io = ImGui::GetIO();

	m_Renderer.pPreditorViewportTexture = IPreditorEngine::Get()->GetViewportTexture();

	io.BackendRendererUserData = (void*)this;
	io.BackendRendererName = "D3D11 (CRYENGINE)";
	io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.
	io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;  // We can create multi-viewports on the Renderer side (optional)

	gEnv->pRenderer->RegisterSyncWithMainListener(this);

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		InitPlatformInterface();
}

Engine::PreditorImGuiRenderer::~PreditorImGuiRenderer()
{
	assert(g_pPreditorImGuiRenderer == this);
	ShutdownPlatformInterface();
	gEnv->pRenderer->RemoveSyncWithMainListener(this);
	g_pPreditorImGuiRenderer = nullptr;
}

void Engine::PreditorImGuiRenderer::RenderEnd()
{
	if (ImGui::GetCurrentContext() != m_pBackend->GetContext())
		return;

	CRY_PROFILE_MARKER("PreditorImGuiRenderer::RenderEnd");
	ImGui::Render();

	// Fill main viewport buffer
	m_MainDrawBuf.bufs[m_iCurrentFillBuf].FillForCurrentContext();

	if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		ImGui::UpdatePlatformWindows();

		// Fill other viewport buffers
		ImGuiPlatformIO& platform_io = ImGui::GetPlatformIO();
		for (int i = 1; i < platform_io.Viewports.Size; i++)
		{
			const ImGuiViewport& vp = *platform_io.Viewports[i];
			size_t vdIdx = (size_t)vp.RendererUserData;

			if (vdIdx != 0)
			{
				vdIdx -= 1;
				m_ViewportDrawBufs[vdIdx].bufs[m_iCurrentFillBuf].FillImDrawData(*vp.DrawData);
				m_ViewportDrawBufs[vdIdx].bClear = !(vp.Flags & ImGuiViewportFlags_NoRendererClear);
			}
		}
	}

	m_bSwapOnSync = true;
	m_pBackend->OnWasRendered();
}

void Engine::PreditorImGuiRenderer::UpdateFontAtlasTexture()
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

void Engine::PreditorImGuiRenderer::RT_Render()
{
	int bufIdx = !m_iCurrentFillBuf;

	// Render main viewport
	m_Renderer.RT_Render(m_MainDrawBuf.bufs[bufIdx], L"PreditorImGui");

	// Render other viewports
	for (size_t i = 0; i < m_ViewportData.size(); i++)
	{
		ViewportData* vd = &m_ViewportData[i];
		if (vd->bExists)
		{
			DoubleBuffer& db = m_ViewportDrawBufs[i];
			ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
			ID3D11RenderTargetView* rtvs[1] = { vd->pRTView.get() };
			gcpRendD3D->GetDeviceContext().OMSetRenderTargets(1, rtvs, nullptr);
			if (db.bClear)
				gcpRendD3D->GetDeviceContext().ClearRenderTargetView(vd->pRTView, (float*)&clear_color);
			m_Renderer.RT_Render(db.bufs[bufIdx], L"PreditorImGui Viewport");
		}
	}

	// Present other viewports
	for (size_t i = 0; i < m_ViewportData.size(); i++)
	{
		ViewportData* vd = &m_ViewportData[i];
		if (vd->bExists)
		{
			vd->pSwapChain->Present(0, 0); // Present without vsync
		}
	}
}

void Engine::PreditorImGuiRenderer::InitPlatformInterface()
{
	ImGuiPlatformIO& platform_io = ImGui::GetPlatformIO();
	platform_io.Renderer_CreateWindow = Plat_CreateWindow;
	platform_io.Renderer_DestroyWindow = Plat_DestroyWindow;
	platform_io.Renderer_SetWindowSize = Plat_SetWindowSize;

	m_nCmdSetWindowSize = gCL->pRender->RegisterRenderCommand("Preditor_Plat_SetWindowSize",
		[this](RenderCmdId nCustomCmdId, RenderCmdBuf& cmdBuf)
		{
			size_t vdIdx = cmdBuf.ReadCommand<size_t>();
			ImVec2 size;
			size.x = cmdBuf.ReadCommand<float>();
			size.y = cmdBuf.ReadCommand<float>();
			RT_Plat_SetWindowSize(vdIdx, size);
		});
}

void Engine::PreditorImGuiRenderer::ShutdownPlatformInterface()
{
	if (m_nCmdSetWindowSize != INVALID_RENDER_CMD_ID)
		gCL->pRender->UnregisterRenderCommand(m_nCmdSetWindowSize);
}

void Engine::PreditorImGuiRenderer::SyncMainWithRender()
{
	if (m_bSwapOnSync)
	{
		// Swap buffers
		m_iCurrentFillBuf = !m_iCurrentFillBuf;
		m_bSwapOnSync = false;
	}
}

void Engine::PreditorImGuiRenderer::Plat_CreateWindow(ImGuiViewport* viewport)
{
	gcpRendD3D->m_pRT->FlushAndWait();
	auto& vdList = g_pPreditorImGuiRenderer->m_ViewportData;

	ViewportData* vd = nullptr;

	// Allocate ViewportData
	{
		// Find an old vd (bExists == false)
		auto it = std::find_if(vdList.begin(), vdList.end(), [](const ViewportData& x) { return !x.bExists; });
		if (it != vdList.end())
			vd = &(*it);
		else
			vd = &vdList.emplace_back();

		// Resize m_ViewportDrawBufs to allocate a buffer
		g_pPreditorImGuiRenderer->m_ViewportDrawBufs.resize(vdList.size());
	}

	// Save vd index to the viewport
	viewport->RendererUserData = (void*)(vd - vdList.data() + 1);

	assert(!vd->bExists && !vd->pRTView && !vd->pSwapChain);
	HWND hWnd = (HWND)viewport->PlatformHandleRaw;
	assert(hWnd);

	vd->bExists = true;

	// Create swap chain
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferDesc.Width = (UINT)viewport->Size.x;
	sd.BufferDesc.Height = (UINT)viewport->Size.y;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = hWnd;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;

	IDXGISwapChain* pSwapChain = nullptr;
	gcpRendD3D->m_devInfo.Factory()->CreateSwapChain(gcpRendD3D->m_devInfo.Device(), &sd, &pSwapChain);
	vd->pSwapChain = pSwapChain;
	SAFE_RELEASE(pSwapChain);

	// Create the render target
	if (vd->pSwapChain)
	{
		ID3D11Texture2D* pBackBuffer = nullptr;
		ID3D11RenderTargetView* pRTView = nullptr;
		vd->pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
		gcpRendD3D->GetDevice().CreateRenderTargetView(pBackBuffer, NULL, &pRTView);
		vd->pRTView = pRTView;
		SAFE_RELEASE(pBackBuffer);
		SAFE_RELEASE(pRTView);
	}
}

void Engine::PreditorImGuiRenderer::Plat_DestroyWindow(ImGuiViewport* viewport)
{
	// The main viewport (owned by the application) will always have RendererUserData == NULL since we didn't create the data for it.
	size_t vdIdx = (size_t)viewport->RendererUserData;
	if (vdIdx != 0)
	{
		vdIdx -= 1;
		auto& vdList = g_pPreditorImGuiRenderer->m_ViewportData;
		ViewportData* vd = &vdList[vdIdx];
		vd->pSwapChain = nullptr;
		vd->pRTView = nullptr;
		vd->bExists = false;
		g_pPreditorImGuiRenderer->m_ViewportDrawBufs[vdIdx] = DoubleBuffer();
	}
	viewport->RendererUserData = NULL;
}

void Engine::PreditorImGuiRenderer::Plat_SetWindowSize(ImGuiViewport* viewport, ImVec2 size)
{
	size_t vdIdx = (size_t)viewport->RendererUserData;
	assert(vdIdx != 0);
	vdIdx -= 1;
	RenderCmdBuf buf = gCL->pRender->QueueCommand(g_pPreditorImGuiRenderer->m_nCmdSetWindowSize, sizeof(size_t) + 2 * sizeof(float));
	buf.AddDWORD64(vdIdx);
	buf.AddFloat(size.x);
	buf.AddFloat(size.y);
	buf.EndCommand();
}

void Engine::PreditorImGuiRenderer::RT_Plat_SetWindowSize(size_t vdIdx, ImVec2 size)
{
	ViewportData* vd = &m_ViewportData[vdIdx];
	vd->pRTView = nullptr;

	if (vd->pSwapChain)
	{
		ID3D11Texture2D* pBackBuffer = NULL;
		vd->pSwapChain->ResizeBuffers(0, (UINT)size.x, (UINT)size.y, DXGI_FORMAT_UNKNOWN, 0);
		vd->pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
		if (pBackBuffer == NULL)
		{
			CryError("PreditorImGuiRenderer::RT_Plat_SetWindowSize() failed creating buffers.");
			return;
		}

		ID3D11RenderTargetView* pRTView = nullptr;
		gcpRendD3D->GetDevice().CreateRenderTargetView(pBackBuffer, NULL, &pRTView);
		vd->pRTView = pRTView;
		SAFE_RELEASE(pBackBuffer);
		SAFE_RELEASE(pRTView);
	}
}
