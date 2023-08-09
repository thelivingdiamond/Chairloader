#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include "RendererGlobals.h"

static Engine::RendererGlobals g_RendererGlobals;
CD3D9Renderer* gcpRendD3D;
CRenderer* gRenDev;

void Engine::RendererGlobals::InitSystem()
{
	gCL->pRender->AddListener(&g_RendererGlobals);
}

void Engine::RendererGlobals::ShutdownSystem()
{
	gCL->pRender->RemoveListener(&g_RendererGlobals);
}

int Engine::RendererGlobals::GetChairRenderListenerFlags()
{
	return eCRF_InitRendererModule;
}

void Engine::RendererGlobals::InitRendererModule(CD3D9Renderer* pRenderer)
{
	gcpRendD3D = pRenderer;
	gRenDev = pRenderer;
}
