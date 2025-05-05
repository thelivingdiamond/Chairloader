#include "ChairloaderCryRender.h"
#include "DebugMarkers.h"
#include "ChairRender.h"
#include "AuxGeom/RenderAuxGeomPatch.h"
#include "Shaders/ShaderCompilingPatch.h"

CD3D9Renderer* gcpRendD3D = nullptr;


void RenderDll::ChairloaderCryRender::InitSystem(const Internal::SCryRenderInitParams& params)
{
	ChairRender::Get().Init();
	DebugMarkers::InitHooks();

	if (params.bEnableAuxGeom)
		AuxGeom::InitAuxGeom();

	if (Shaders::GetShaderModsRegistered())
		Shaders::InitHooks();
}

void RenderDll::ChairloaderCryRender::InitGame()
{
}

void RenderDll::ChairloaderCryRender::ShutdownSystem()
{
	AuxGeom::ShutdownSystem();
	ChairRender::Get().Shutdown();
}

void RenderDll::ChairloaderCryRender::SetRenderThreadIsIdle(bool state)
{
	ChairRender::Get().SetCanChangeRenderCmds(state);
}

void RenderDll::ChairloaderCryRender::AddShadersMod(const std::string& name)
{
	Shaders::AddShadersMod(name);
}
