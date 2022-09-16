#include "ChairRender.h"
#include "DebugMarkers.h"
#include "AuxGeom/RenderAuxGeomPatch.h"

static RenderDll::ChairRender g_ChairRender;

namespace RenderDll
{

auto g_ComputePresentInterval = PreyFunction<uint32(bool vsync, uint32 refreshNumerator, uint32 refreshDenominator)>(0xF4C000);

auto g_CD3D9Renderer_InitRenderer_Hook = CD3D9Renderer::FInit.MakeHook();
auto g_CD3D9Renderer_RT_InitRenderer_Hook = CD3D9Renderer::FRT_Init.MakeHook();
auto g_CD3D9Renderer_ShutDown_Hook = CD3D9Renderer::FShutDown.MakeHook();
auto g_CD3D9Renderer_RT_ShutDown_Hook = CD3D9Renderer::FRT_ShutDown.MakeHook();
auto g_CD3D9Renderer_BeginFrame_Hook = CD3D9Renderer::FBeginFrame.MakeHook();
auto g_CD3D9Renderer_EndFrame_Hook = CD3D9Renderer::FEndFrame.MakeHook();
auto g_CD3D9Renderer_RT_BeginFrame_Hook = CD3D9Renderer::FRT_BeginFrame.MakeHook();
auto g_CD3D9Renderer_RT_EndFrame_Hook = CD3D9Renderer::FRT_EndFrame.MakeHook();
auto g_ComputePresentInterval_Hook = g_ComputePresentInterval.MakeHook();

void* CD3D9Renderer_InitRenderer_Hook(CD3D9Renderer* const _this, int x, int y, int width, int height, unsigned cbpp, int zbpp, int sbits, EFullscreenMode _fullscreenMode, void* hinst, void* Glhwnd, bool bReInit, SCustomRenderInitArgs const* pCustomArgs, bool bShaderCacheGen)
{
	void* ret = g_CD3D9Renderer_InitRenderer_Hook.InvokeOrig(_this, x, y, width, height, cbpp, zbpp, sbits, _fullscreenMode, hinst, Glhwnd, bReInit, pCustomArgs, bShaderCacheGen);
	g_ChairRender.InitRenderer(_this);
	return ret;
}

void CD3D9Renderer_RT_InitRenderer_Hook(CD3D9Renderer* _this)
{
	g_CD3D9Renderer_RT_InitRenderer_Hook.InvokeOrig(_this);
	g_ChairRender.RT_InitRenderer();
}

void CD3D9Renderer_ShutDown_Hook(CD3D9Renderer* _this, bool bReInit)
{
	g_ChairRender.ShutdownRenderer();
	g_CD3D9Renderer_ShutDown_Hook.InvokeOrig(_this, bReInit);
}

void CD3D9Renderer_RT_ShutDown_Hook(CD3D9Renderer* _this, unsigned nFlags)
{
	g_ChairRender.RT_ShutdownRenderer();
	g_CD3D9Renderer_RT_ShutDown_Hook.InvokeOrig(_this, nFlags);
}

void CD3D9Renderer_BeginFrame_Hook(CD3D9Renderer* _this, bool resolveBackBuffer)
{
	g_CD3D9Renderer_BeginFrame_Hook.InvokeOrig(_this, resolveBackBuffer);
	g_ChairRender.BeginFrame();
}

void CD3D9Renderer_EndFrame_Hook(CD3D9Renderer* _this)
{
	g_ChairRender.EndFrame();
	g_CD3D9Renderer_EndFrame_Hook.InvokeOrig(_this);
}

void CD3D9Renderer_RT_BeginFrame_Hook(CD3D9Renderer* _this)
{
	g_CD3D9Renderer_RT_BeginFrame_Hook.InvokeOrig(_this);
	g_ChairRender.BeginFrame();
}

void CD3D9Renderer_RT_EndFrame_Hook(CD3D9Renderer* _this)
{
	g_ChairRender.EndFrame();
	g_CD3D9Renderer_RT_EndFrame_Hook.InvokeOrig(_this);
}

uint32 ComputePresentInterval_Hook(bool vsync, uint32 refreshNumerator, uint32 refreshDenominator)
{
	g_ChairRender.RT_Present();
	return g_ComputePresentInterval_Hook.InvokeOrig(vsync, refreshNumerator, refreshDenominator);
}

} // namespace RenderDll

RenderDll::ChairRender& RenderDll::ChairRender::Get()
{
	return g_ChairRender;
}

RenderDll::ChairRender::ChairRender()
{
}

RenderDll::ChairRender::~ChairRender()
{
}

void RenderDll::ChairRender::Init()
{
	m_AllLists.push_back(&m_InitRenderer);
	m_AllLists.push_back(&m_RT_InitRenderer);
	m_AllLists.push_back(&m_Shutdown);
	m_AllLists.push_back(&m_RT_Shutdown);
	m_AllLists.push_back(&m_BeginFrame);
	m_AllLists.push_back(&m_EndFrame);
	m_AllLists.push_back(&m_RT_BeginFrame);
	m_AllLists.push_back(&m_RT_EndFrame);
	m_AllLists.push_back(&m_RT_Present);

	g_CD3D9Renderer_InitRenderer_Hook.SetHookFunc(&CD3D9Renderer_InitRenderer_Hook);
	g_CD3D9Renderer_RT_InitRenderer_Hook.SetHookFunc(&CD3D9Renderer_RT_InitRenderer_Hook);
	g_CD3D9Renderer_ShutDown_Hook.SetHookFunc(&CD3D9Renderer_ShutDown_Hook);
	g_CD3D9Renderer_RT_ShutDown_Hook.SetHookFunc(&CD3D9Renderer_RT_ShutDown_Hook);
	g_CD3D9Renderer_BeginFrame_Hook.SetHookFunc(&CD3D9Renderer_BeginFrame_Hook);
	g_CD3D9Renderer_EndFrame_Hook.SetHookFunc(&CD3D9Renderer_EndFrame_Hook);
	g_CD3D9Renderer_RT_BeginFrame_Hook.SetHookFunc(&CD3D9Renderer_RT_BeginFrame_Hook);
	g_CD3D9Renderer_RT_EndFrame_Hook.SetHookFunc(&CD3D9Renderer_RT_EndFrame_Hook);
	g_ComputePresentInterval_Hook.SetHookFunc(&ComputePresentInterval_Hook);
}

void RenderDll::ChairRender::Shutdown()
{
	// Check if there are any listeners left
	bool foundAny = false;

	for (TListenerList* pList : m_AllLists)
	{
		if (!pList->empty())
		{
			foundAny = true;
			break;
		}
	}

	if (foundAny)
	{
		CryWarning("One or more mods left IChairRenderListeners registered. This will break hot-reload.");
		CRY_ASSERT_MESSAGE(false, "Someone forgot to call IRenderDll::ChairRender::RemoveListener");
	}
}

void RenderDll::ChairRender::InitRenderer(CD3D9Renderer* pRenderer)
{
	// Init global ptrs
	gRenDev = pRenderer;
	gcpRendD3D = pRenderer;

	AuxGeom::InitRenderer();

	// Call callbacks
	for (IChairRenderListener* i : m_InitRenderer)
		i->InitRenderer(pRenderer);
}

void RenderDll::ChairRender::RT_InitRenderer()
{
	DebugMarkers::InitRenderer();

	// Call callbacks
	for (IChairRenderListener* i : m_RT_InitRenderer)
		i->RT_InitRenderer();
}

void RenderDll::ChairRender::ShutdownRenderer()
{
	for (auto it = m_EndFrame.rbegin(); it != m_EndFrame.rend(); ++it)
		(*it)->ShutdownRenderer();
}

void RenderDll::ChairRender::RT_ShutdownRenderer()
{
	for (auto it = m_EndFrame.rbegin(); it != m_EndFrame.rend(); ++it)
		(*it)->RT_ShutdownRenderer();

	AuxGeom::RT_Shutdown();
}

void RenderDll::ChairRender::BeginFrame()
{
	for (IChairRenderListener* i : m_BeginFrame)
		i->BeginFrame();
}

void RenderDll::ChairRender::EndFrame()
{
	for (auto it = m_EndFrame.rbegin(); it != m_EndFrame.rend(); ++it)
		(*it)->EndFrame();
}

void RenderDll::ChairRender::RT_BeginFrame()
{
	for (IChairRenderListener* i : m_BeginFrame)
		i->RT_BeginFrame();
}

void RenderDll::ChairRender::RT_EndFrame()
{
	for (auto it = m_EndFrame.rbegin(); it != m_EndFrame.rend(); ++it)
		(*it)->RT_EndFrame();
}

void RenderDll::ChairRender::RT_Present()
{
	for (IChairRenderListener* i : m_BeginFrame)
		i->RT_Present();
}

void RenderDll::ChairRender::AddListener(IChairRenderListener* listener)
{
	int flags = listener->GetFlags();

	if (flags == 0)
		CryWarning("IRenderDll::ChairRender::AddListener called with 0 flags. It makes no sense.");

	if (flags & eCRF_InitRenderer)
		m_InitRenderer.push_back(listener);
	if (flags & eCRF_RT_InitRenderer)
		m_RT_InitRenderer.push_back(listener);
	if (flags & eCRF_Shutdown)
		m_Shutdown.push_back(listener);
	if (flags & eCRF_RT_Shutdown)
		m_RT_Shutdown.push_back(listener);
	if (flags & eCRF_BeginFrame)
		m_BeginFrame.push_back(listener);
	if (flags & eCRF_EndFrame)
		m_EndFrame.push_back(listener);
	if (flags & eCRF_RT_BeginFrame)
		m_RT_BeginFrame.push_back(listener);
	if (flags & eCRF_RT_EndFrame)
		m_RT_EndFrame.push_back(listener);
	if (flags & eCRF_RT_Present)
		m_RT_Present.push_back(listener);
}

bool RenderDll::ChairRender::RemoveListener(IChairRenderListener* listener)
{
	bool foundAny = false;

	for (TListenerList* pList : m_AllLists)
	{
		auto it = std::find(pList->begin(), pList->end(), listener);

		if (it != pList->end())
		{
			pList->erase(it);
			foundAny = true;
		}
	}

	return foundAny;
}
