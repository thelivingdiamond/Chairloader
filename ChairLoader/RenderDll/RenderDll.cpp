#include "RenderDll.h"
#include "DebugMarkers.h"
#include "ChairRender.h"
#include "AuxGeom/RenderAuxGeomPatch.h"
#include "Shaders/ShaderCompilingPatch.h"

void RenderDll::InitRenderDllPatches(const SRenderDllPatchParams& params)
{
	ChairRender::Get().Init();
	DebugMarkers::InitHooks();

	if (params.bEnableAuxGeom)
		AuxGeom::InitAuxGeom();

	//if (params.bEnableShaderTest)
	//	Shaders::InitHooks();
}
