#pragma once

namespace RenderDll
{

struct SRenderDllPatchParams
{
	bool bEnableAuxGeom = false;
};

void InitRenderDllPatches(const SRenderDllPatchParams& params);

} // namespace RenderDll

