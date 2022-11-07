#include "RenderDll.h"
#include "DebugMarkers.h"
#include "ChairRender.h"
#include "AuxGeom/RenderAuxGeomPatch.h"
#include "Shaders/ShaderCompilingPatch.h"

CD3D9Renderer* gcpRendD3D = nullptr;

void RenderDll::InitRenderDllPatches(const SRenderDllPatchParams& params)
{
	ChairRender::Get().Init();
	DebugMarkers::InitHooks();

	if (params.bEnableAuxGeom)
		AuxGeom::InitAuxGeom();

	if (Shaders::GetShaderModsRegistered())
		Shaders::InitHooks();
}

void RenderDll::ShutdownSystem()
{
	AuxGeom::ShutdownSystem();
	ChairRender::Get().Shutdown();
}

void RenderDll::SetRenderThreadIsIdle(bool state)
{
	ChairRender::Get().SetCanChangeRenderCmds(state);
}
