#include "RenderDll.h"
#include "DebugMarkers.h"
#include "AuxGeom/RenderAuxGeomPatch.h"
#include "Shaders/ShaderCompilingPatch.h"

void RenderDll::InitRenderDllPatches(const SRenderDllPatchParams& params)
{
	DebugMarkers::InitHooks();

	if (params.bEnableAuxGeom)
		AuxGeom::InitAuxGeom();

	//if (params.bEnableShaderTest)
	//	Shaders::InitHooks();
}

void RenderDll::InitRenderDllGame()
{
	DebugMarkers::InitGame();
}
