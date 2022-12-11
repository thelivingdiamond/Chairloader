#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include "RendererGlobals.h"

static RendererGlobals g_RendererGlobals;
CD3D9Renderer* gcpRendD3D;
CRenderer* gRenDev;

void RendererGlobals::InitSystem()
{
	gCL->pRender->AddListener(&g_RendererGlobals);
}

void RendererGlobals::ShutdownSystem()
{
	gCL->pRender->RemoveListener(&g_RendererGlobals);
}

int RendererGlobals::GetChairRenderListenerFlags()
{
	return eCRF_InitRendererModule;
}

void RendererGlobals::InitRendererModule(CD3D9Renderer* pRenderer)
{
	gcpRendD3D = pRenderer;
	gRenDev = pRenderer;
}
