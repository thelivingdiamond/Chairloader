#pragma once

namespace RenderDll
{

struct SRenderDllPatchParams
{
	bool bEnableAuxGeom = false;
	bool bEnableShaderTest = false;
};

void InitRenderDllPatches(const SRenderDllPatchParams& params);
void ShutdownSystem();

//! Sets whether the render thread is currently idle.
//! It's considered idle after two SyncMainWithRender calls.
void SetRenderThreadIsIdle(bool state);

} // namespace RenderDll

