#include "ChairRender.h"

static RenderDll::ChairRender g_ChairRender;

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
	m_AllLists.push_back(&m_BeginFrame);
	m_AllLists.push_back(&m_EndFrame);
	m_AllLists.push_back(&m_RT_BeginFrame);
	m_AllLists.push_back(&m_RT_EndFrame);
	m_AllLists.push_back(&m_RT_Present);
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

	// Call callbacks
	for (IChairRenderListener* i : m_InitRenderer)
		i->InitRenderer(pRenderer);
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
