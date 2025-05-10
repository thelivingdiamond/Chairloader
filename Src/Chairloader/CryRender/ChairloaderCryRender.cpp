#include "ChairloaderCryRender.h"
#include "DebugMarkers.h"
#include "ChairRender.h"
#include "AuxGeom/RenderAuxGeomPatch.h"
#include "Shaders/ShaderCompilingPatch.h"

CD3D9Renderer* gcpRendD3D = nullptr;


RenderDll::ChairloaderCryRender::ChairloaderCryRender(std::shared_ptr<IChairRender> pRender)
	: m_pRender(std::static_pointer_cast<ChairRender>(pRender))
{
}

void RenderDll::ChairloaderCryRender::InitSystem(const Internal::SCryRenderInitParams& params)
{
	m_pRender->Init();
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
	m_pRender->Shutdown();
}

void RenderDll::ChairloaderCryRender::SetRenderThreadIsIdle(bool state)
{
	m_pRender->SetCanChangeRenderCmds(state);
}

void RenderDll::ChairloaderCryRender::AddShadersMod(const std::string& name)
{
	Shaders::AddShadersMod(name);
}
