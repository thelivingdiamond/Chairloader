#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/RenderDll/Common/ArkBinkManager.h>
#include "ChairRender.h"
#include "DebugMarkers.h"
#include "AuxGeom/RenderAuxGeomPatch.h"
#include "Shaders/ShaderCompilingPatch.h"

static RenderDll::ChairRender g_ChairRender;

namespace RenderDll
{

auto g_ComputePresentInterval = PreyFunction<uint32(bool vsync, uint32 refreshNumerator, uint32 refreshDenominator)>(0xF4C000);

// Callbacks
auto g_CD3D9Renderer_InitRenderer_Hook = CD3D9Renderer::FInitRenderer.MakeHook();
auto g_CD3D9Renderer_Init_Hook = CD3D9Renderer::FInit.MakeHook();
auto g_CD3D9Renderer_RT_InitRenderer_Hook = CD3D9Renderer::FRT_Init.MakeHook();
auto g_CD3D9Renderer_ShutDown_Hook = CD3D9Renderer::FShutDown.MakeHook();
auto g_CD3D9Renderer_RT_ShutDown_Hook = CD3D9Renderer::FRT_ShutDown.MakeHook();
auto g_CD3D9Renderer_BeginFrame_Hook = CD3D9Renderer::FBeginFrame.MakeHook();
auto g_CD3D9Renderer_EndFrame_Hook = CD3D9Renderer::FEndFrame.MakeHook();
auto g_CD3D9Renderer_RT_BeginFrame_Hook = CD3D9Renderer::FRT_BeginFrame.MakeHook();
auto g_CD3D9Renderer_RT_EndFrame_Hook = CD3D9Renderer::FRT_EndFrame.MakeHook();
auto g_ComputePresentInterval_Hook = g_ComputePresentInterval.MakeHook();

// Render commands
auto g_SRenderThread_RC_BinkRender_Hook = SRenderThread::FRC_BinkRender.MakeHook();
auto g_ArkBinkManager_RT_RenderInternal_Hook = ArkBinkManager::FRT_RenderInternal.MakeHook();
auto g_SRenderThread_ProcessCommands_Hook = SRenderThread::FProcessCommands.MakeHook();
RenderCmdId g_nBinkRenderCmdId = INVALID_RENDER_CMD_ID;

//-------------------------------------------------------------------------------------

void CD3D9Renderer_InitRenderer_Hook(CD3D9Renderer* const _this)
{
	g_CD3D9Renderer_InitRenderer_Hook.InvokeOrig(_this);
	g_ChairRender.InitRendererModule(_this);
}

void* CD3D9Renderer_Init_Hook(CD3D9Renderer* const _this, int x, int y, int width, int height, unsigned cbpp, int zbpp, int sbits, EFullscreenMode _fullscreenMode, void* hinst, void* Glhwnd, bool bReInit, SCustomRenderInitArgs const* pCustomArgs, bool bShaderCacheGen)
{
	void* ret = g_CD3D9Renderer_Init_Hook.InvokeOrig(_this, x, y, width, height, cbpp, zbpp, sbits, _fullscreenMode, hinst, Glhwnd, bReInit, pCustomArgs, bShaderCacheGen);
	g_ChairRender.InitRenderer();
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
	g_ChairRender.RT_BeginFrame();
}

void CD3D9Renderer_RT_EndFrame_Hook(CD3D9Renderer* _this)
{
	g_ChairRender.RT_EndFrame();
	g_CD3D9Renderer_RT_EndFrame_Hook.InvokeOrig(_this);
}

uint32 ComputePresentInterval_Hook(bool vsync, uint32 refreshNumerator, uint32 refreshDenominator)
{
	g_ChairRender.RT_Present();
	return g_ComputePresentInterval_Hook.InvokeOrig(vsync, refreshNumerator, refreshDenominator);
}

//-------------------------------------------------------------------------------------

void SRenderThread_RC_BinkRender_Hook(SRenderThread* _this, ArkBinkPlayer* _pPlayer, int _frame)
{
	// RC_BinkRender now uses a custom render command. Original handler handles all custom commands.
	SRenderThread* pRT = gRenDev->m_pRT;
	if (pRT->IsRenderThread())
	{
		return g_ArkBinkManager_RT_RenderInternal_Hook.InvokeOrig(gRenDev->m_pBinkManager, _pPlayer, _frame);
	}

	RenderCmdBuf buf = g_ChairRender.QueueCommand(g_nBinkRenderCmdId, sizeof(void*) + sizeof(int));
	buf.AddPointer(_pPlayer);
	buf.AddDWORD(_frame);
	buf.EndCommand();
}

void ArkBinkManager_RT_RenderInternal_Hook(ArkBinkManager*, ArkBinkPlayer*, int nCmdIdInt)
{
	g_ChairRender.RT_HandleCustomCommand((RenderCmdId)nCmdIdInt);
}

void SRenderThread_ProcessCommands_Hook(SRenderThread* _this)
{
	g_ChairRender.RT_PreProcessCommands();
	g_SRenderThread_ProcessCommands_Hook.InvokeOrig(_this);
	g_ChairRender.RT_PostProcessCommands();
}

//! Custom command handler in place of the original RC_BinkRender
void RT_BinkRender(RenderCmdId nCmdId, RenderCmdBuf& buf)
{
	ArkBinkPlayer* pPlayer = buf.ReadCommand<ArkBinkPlayer*>();
	int frame = buf.ReadCommand<int>();
	g_ArkBinkManager_RT_RenderInternal_Hook.InvokeOrig(gRenDev->m_pBinkManager, pPlayer, frame);
}

} // namespace RenderDll

//-------------------------------------------------------------------------------------

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
	gCL->pRender = this;

	m_AllLists.push_back(&m_InitRendererModule);
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
	g_CD3D9Renderer_Init_Hook.SetHookFunc(&CD3D9Renderer_Init_Hook);
	g_CD3D9Renderer_RT_InitRenderer_Hook.SetHookFunc(&CD3D9Renderer_RT_InitRenderer_Hook);
	g_CD3D9Renderer_ShutDown_Hook.SetHookFunc(&CD3D9Renderer_ShutDown_Hook);
	g_CD3D9Renderer_RT_ShutDown_Hook.SetHookFunc(&CD3D9Renderer_RT_ShutDown_Hook);
	g_CD3D9Renderer_BeginFrame_Hook.SetHookFunc(&CD3D9Renderer_BeginFrame_Hook);
	g_CD3D9Renderer_EndFrame_Hook.SetHookFunc(&CD3D9Renderer_EndFrame_Hook);
	g_CD3D9Renderer_RT_BeginFrame_Hook.SetHookFunc(&CD3D9Renderer_RT_BeginFrame_Hook);
	g_CD3D9Renderer_RT_EndFrame_Hook.SetHookFunc(&CD3D9Renderer_RT_EndFrame_Hook);
	g_ComputePresentInterval_Hook.SetHookFunc(&ComputePresentInterval_Hook);

	g_SRenderThread_RC_BinkRender_Hook.SetHookFunc(&SRenderThread_RC_BinkRender_Hook);
	g_ArkBinkManager_RT_RenderInternal_Hook.SetHookFunc(&ArkBinkManager_RT_RenderInternal_Hook);
	g_SRenderThread_ProcessCommands_Hook.SetHookFunc(&SRenderThread_ProcessCommands_Hook);

	g_nBinkRenderCmdId = RegisterRenderCommand("RC_BinkRender", RT_BinkRender);
}

void RenderDll::ChairRender::Shutdown()
{
	UnregisterRenderCommand(g_nBinkRenderCmdId);

	// Check if there are any listeners left
	bool foundAnyListeners = false;

	for (TListenerList* pList : m_AllLists)
	{
		if (!pList->empty())
		{
			foundAnyListeners = true;
			break;
		}
	}

	if (foundAnyListeners)
	{
		CryWarning("One or more mods left IChairRenderListeners registered. This will break hot-reload.");
		if (IsDebuggerPresent()) __debugbreak();
	}

	// Check for any custom commands
	bool foundAnyCmds = false;
	for (CustomCommand& cmd : m_CustomCommands)
	{
		if (cmd.IsRegistered())
		{
			foundAnyCmds = true;
			break;
		}
	}

	if (foundAnyCmds)
	{
		CryWarning("One or more mods left custom commands registered. This will break hot-reload.");
		if (IsDebuggerPresent()) __debugbreak();
	}

	gCL->pRender = nullptr;
}

void RenderDll::ChairRender::InitRendererModule(CD3D9Renderer* pRenderer)
{
	// Init global ptrs
	gRenDev = pRenderer;
	gcpRendD3D = pRenderer;

	WaitForRenderDoc();
	AuxGeom::InitRenderer();

	// Call callbacks
	for (IChairRenderListener* i : m_InitRenderer)
		i->InitRendererModule(pRenderer);
}

void RenderDll::ChairRender::InitRenderer()
{
	for (IChairRenderListener* i : m_InitRenderer)
		i->InitRenderer();
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
	for (auto it = m_Shutdown.rbegin(); it != m_Shutdown.rend(); ++it)
		(*it)->ShutdownRenderer();

	Shaders::ShutdownRenderer();
}

void RenderDll::ChairRender::RT_ShutdownRenderer()
{
	for (auto it = m_RT_Shutdown.rbegin(); it != m_RT_Shutdown.rend(); ++it)
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
	for (IChairRenderListener* i : m_RT_BeginFrame)
		i->RT_BeginFrame();
}

void RenderDll::ChairRender::RT_EndFrame()
{
	for (auto it = m_RT_EndFrame.rbegin(); it != m_RT_EndFrame.rend(); ++it)
		(*it)->RT_EndFrame();
}

void RenderDll::ChairRender::RT_Present()
{
	for (IChairRenderListener* i : m_RT_Present)
		i->RT_Present();
}

void RenderDll::ChairRender::RT_PreProcessCommands()
{
	TArray<byte>& cmdBuf = m_CmdBuffer[gRenDev->m_pRT->m_nCurThreadProcess];
	m_ReadBuf.pBuffer = cmdBuf.Data();
	m_ReadBuf.pBufferEnd = cmdBuf.Data() + cmdBuf.Num();
}

void RenderDll::ChairRender::RT_HandleCustomCommand(RenderCmdId nCmdId)
{
	CRY_ASSERT(nCmdId < m_CustomCommands.size());

#ifdef DEBUG_BUILD
	// Make sure the command wasn't processed already
	int* pProcessFlag = (int*)m_ReadBuf.pBuffer;
	CRY_ASSERT(!*pProcessFlag);
	*pProcessFlag = 1;
	m_ReadBuf.pBuffer += sizeof(int);
#endif

	// Call the command handler
	m_CustomCommands[nCmdId].handler(nCmdId, m_ReadBuf);
}

void RenderDll::ChairRender::RT_PostProcessCommands()
{
	TArray<byte>& cmdBuf = m_CmdBuffer[gRenDev->m_pRT->m_nCurThreadProcess];
	CRY_ASSERT_MESSAGE(m_ReadBuf.pBufferEnd == cmdBuf.Data() + cmdBuf.Num(), "Command handler changed pBufferEnd");
	CRY_ASSERT_MESSAGE(m_ReadBuf.pBuffer == m_ReadBuf.pBufferEnd, "Not all bytes of the buffer were processed, "
		"mismatch between declared cmd size and what was actually read.");

	// Clear the buffer
	cmdBuf.SetUse(0);
}

void RenderDll::ChairRender::AddListener(IChairRenderListener* listener)
{
	ValidateCanChangeCmds();
	int flags = listener->GetChairRenderListenerFlags();

	if (flags == 0)
		CryWarning("IRenderDll::ChairRender::AddListener called with 0 flags. It makes no sense.");

	if (flags & eCRF_InitRendererModule)
		m_InitRendererModule.push_back(listener);
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
	ValidateCanChangeCmds();
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

RenderCmdId RenderDll::ChairRender::RegisterRenderCommand(const char* name, const CmdHandler& handler)
{
	ValidateCanChangeCmds();

	if (!handler)
	{
		CRY_ASSERT(false);
		CryError("RegisterRenderCommand '{}' with empty handler", name);
		return INVALID_RENDER_CMD_ID;
	}

	if (m_bHaveUnregisteredCmds)
	{
		// Find an empty command
		auto it = std::find_if(m_CustomCommands.begin(), m_CustomCommands.end(),
			[](CustomCommand& cmd) { return !cmd.IsRegistered(); });

		if (it != m_CustomCommands.end())
		{
			it->Fill(name, handler);
			return it - m_CustomCommands.begin();
		}
	}

	// Not found an empty cmd, emplace_back a new one
	m_bHaveUnregisteredCmds = false;
	RenderCmdId id = m_CustomCommands.size();
	CustomCommand& cmd = m_CustomCommands.emplace_back();
	cmd.Fill(name, handler);
	return id;
}

bool RenderDll::ChairRender::UnregisterRenderCommand(RenderCmdId nCustomCmdId)
{
	ValidateCanChangeCmds();

	if (nCustomCmdId == INVALID_RENDER_CMD_ID)
		return false;

	CRY_ASSERT(nCustomCmdId < m_CustomCommands.size());

	if (m_CustomCommands[nCustomCmdId].IsRegistered())
	{
		m_CustomCommands[nCustomCmdId] = CustomCommand();
		m_bHaveUnregisteredCmds = true;
		return true;
	}

	return false;
}

RenderCmdBuf RenderDll::ChairRender::QueueCommand(RenderCmdId nCustomCmdId, size_t nParamBytes)
{
	int thread = gRenDev->m_pRT->m_nCurThreadFill;
	uint32 cmdSize = nParamBytes;
	
#if DEBUG_BUILD
	cmdSize += sizeof(uint32); // processed flag
#endif

	RenderCmdBuf buf;
	buf.pBuffer = m_CmdBuffer[thread].Grow(cmdSize);
	buf.pBufferEnd = buf.pBuffer + cmdSize;

#if DEBUG_BUILD
	buf.AddDWORD(0); // processed flag
#endif

	// Add the command to the original render thread
	SRenderThread* pRT = gRenDev->m_pRT;
	byte* p = pRT->AddCommand(eRC_BinkRender, sizeof(void*) + sizeof(int));
	pRT->AddPointer(p, nullptr);
	pRT->AddDWORD(p, nCustomCmdId);
	pRT->EndCommand(p);

	return buf;
}

void RenderDll::ChairRender::ValidateCanChangeCmds()
{
	if (!m_bCanChangeCmds)
	{
		CryFatalError("Can't modify render command handlers at the moment, it requires render thread to be idle");
	}
}

void RenderDll::ChairRender::WaitForRenderDoc()
{
	constexpr int WAIT_TIME_SEC = 10;

	if (gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "renderdoc"))
	{
		for (int i = 0; i < WAIT_TIME_SEC; i++)
		{
			CryLog("Waiting for RenderDoc - {} seconds...", WAIT_TIME_SEC - i);

			for (int j = 0; j < 10; j++)
			{
				HMODULE renderdoc = GetModuleHandleA("renderdoc.dll");

				if (renderdoc)
				{
					CryLog("RenderDoc found!");
					return;
				}

				Sleep(100);
			}
		}

		CryLog("RenderDoc not found, continuing loading");
	}
}

void RenderDll::ChairRender::CustomCommand::Fill(const char* name, const CmdHandler& handler)
{
#if DEBUG_BUILD
	this->name = name;
#endif
	this->handler = handler;
}
