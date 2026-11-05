// Header test file for path Prey/RenderDll/XRenderD3D9/

#include "arkd3dvideoinfo.h"
static_assert(sizeof(ArkVideoInfo) == 80);

#include "CompiledRenderObject.h"
static_assert(sizeof(CRenderObjectsPools) == 280);

#include "D3DHWShader.h"
#ifndef MOONCRASH
static_assert(sizeof(UFloat4) == 16);
#endif
static_assert(sizeof(SParamsGroup) == 72);
static_assert(sizeof(SCGParamsGroup) == 24);
static_assert(sizeof(SCGParamPool) == 32);
static_assert(sizeof(CGParamManager) == 1);
static_assert(sizeof(SD3DShader) == 24);
static_assert(sizeof(SD3DShaderHandle) == 24);
static_assert(sizeof(SShaderAsyncInfo) == 192);
static_assert(sizeof(CHWShader_D3D) == 176);
static_assert(sizeof(CHWShader_D3D::SHWSInstance) == 256);

// Disabled: base build cannot reach this header (renderdll/xrenderd3d9/driverd3d.h -> ../Scaleform/ScaleformPlayback.h)
//#include "DriverD3D.h"
//static_assert(sizeof(SD3DContext) == 88);
//static_assert(sizeof(CArkRenderPersistentAuxGeom_Null) == 8);
//static_assert(sizeof(CFrameTimestamps) == 104);
//static_assert(sizeof(CD3D9Renderer) == 46080);
//static_assert(sizeof(CD3D9Renderer::S2DImage) == 64);
//static_assert(sizeof(CD3D9Renderer::SCharacterInstanceCB) == 40);
//static_assert(sizeof(CD3D9Renderer::SRenderTargetStack) == 72);
//static_assert(sizeof(CD3D9Renderer::SGammaRamp) == 1536);
