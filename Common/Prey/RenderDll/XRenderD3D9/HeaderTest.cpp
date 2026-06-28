// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path CryEngine/renderdll/xrenderd3d9/arkd3dbinkrender.h
#include "arkd3dvideoinfo.h"
static_assert(sizeof(ArkVideoInfo) == 80);

#include "CompiledRenderObject.h"
//static_assert(sizeof(CCompiledRenderObject) == 360);
//static_assert(sizeof(CCompiledRenderObject::SDrawParams) == 12);
static_assert(sizeof(CRenderObjectsPools) == 280);
//static_assert(sizeof(CRenderObjectsPools::PoolSyncCriticalSection) == 40);
//static_assert(sizeof(CPermanentRenderObject) == 624);
//static_assert(sizeof(CPermanentRenderObject::SPermanentRendItem) == 40);

#include "D3DHWShader.h"
static_assert(sizeof(CHWShader_D3D) == 176);
static_assert(sizeof(CHWShader_D3D::SHWSInstance) == 256);
static_assert(sizeof(SD3DShaderHandle) == 24);
static_assert(sizeof(CGParamManager) == 1);

#include "DriverD3D.h"
static_assert(sizeof(CD3D9Renderer) == 46080);
#else // MOONCRASH
// Header test file for path CryEngine/renderdll/xrenderd3d9/
#include "CompiledRenderObject.h"
static_assert(sizeof(CCompiledRenderObject) == 360);
static_assert(sizeof(CCompiledRenderObject::SDrawParams) == 12);
static_assert(sizeof(CPermanentRenderObject) == 624);
static_assert(sizeof(CPermanentRenderObject::SPermanentRendItem) == 40);
static_assert(sizeof(CRenderObjectsPools) == 280);
static_assert(sizeof(CRenderObjectsPools::PoolSyncCriticalSection) == 40);

#include "DeviceInfo.inl"
static_assert(sizeof(DeviceInfo) == 808);

#include "arkd3dbinkrender.h"
static_assert(sizeof(ArkBinkPlayer) == 32);
static_assert(sizeof(ArkBinkRenderer) == 8);

#include "arkd3dbinkrender_cpu.h"
static_assert(sizeof(ArkBinkPlayerCPU) == 56);
static_assert(sizeof(ArkBinkRendererCPU) == 16);

#include "arkd3dvideoinfo.h"
static_assert(sizeof(ArkVideoInfo) == 80);

#include "crelensopticsd3d.h"
static_assert(sizeof(CRELensOptics) == 64);

#include "d3dcolorgradingcontroller.h"
static_assert(sizeof(CColorGradingControllerD3D) == 128);

#include "d3ddeferredshading.h"
static_assert(sizeof(CDeferredShading) == 1216);

#include "d3dhwshader.h"
static_assert(sizeof(CGParamManager) == 1);
static_assert(sizeof(CHWShader_D3D) == 176);
static_assert(sizeof(CHWShader_D3D::SHWSInstance) == 256);
static_assert(sizeof(SD3DShaderHandle) == 24);

#include "d3dhwshadercompiling.h"
static_assert(sizeof(SShaderAsyncInfo) == 192);
static_assert(sizeof(SShaderCache) == 56);
static_assert(sizeof(SShaderDevCache) == 32);

#include "d3docclquery.h"
static_assert(sizeof(COcclusionQuery) == 24);

#include "d3dpostprocess.h"
static_assert(sizeof(SD3DPostEffectsUtils) == 264);

#include "d3dshaders.h"
static_assert(sizeof(SHWActivatedShader) == 40);

#include "d3dsystem.h"
static_assert(sizeof(SDepthTexture) == 40);
static_assert(sizeof(SPixFormat) == 32);
static_assert(sizeof(SPixFormatSupport) == 1480);

#include "d3dtexture.h"
static_assert(sizeof(RenderTargetData) == 24);
static_assert(sizeof(ResourceViewData) == 16);
static_assert(sizeof(STexState) == 32);

#include "d3dtexturestreampool.h"
static_assert(sizeof(CTextureStreamPoolMgr) == 608);
static_assert(sizeof(CTextureStreamPoolMgr::SFrameStats) == 16);
static_assert(sizeof(CTextureStreamPoolMgr::SPoolStats) == 36);
static_assert(sizeof(CTextureStreamPoolMgr::TexturePoolKey) == 16);

#include "d3dtiledshading.h"
static_assert(sizeof(CTiledShading) == 27336);
static_assert(sizeof(CTiledShading::AtlasItem) == 24);
static_assert(sizeof(CTiledShading::TextureAtlas) == 32);

#include "devbuffer.h"
static_assert(sizeof(CConstantBuffer) == 40);
static_assert(sizeof(CDeviceBufferManager) == 1);
static_assert(sizeof(CGpuBuffer) == 104);
static_assert(sizeof(CGpuBuffer::STrackedGpuBuffer) == 40);
static_assert(sizeof(CGpuBuffer::STrackedGpuBufferSet) == 32);
static_assert(sizeof(CGraphicsDeviceConstantBuffer) == 64);
static_assert(sizeof(CVertexBuffer) == 24);

#include "driverd3d.h"
static_assert(sizeof(CD3D9Renderer) == 46080);
static_assert(sizeof(CD3D9Renderer::S2DImage) == 64);
static_assert(sizeof(CD3D9Renderer::SCharacterInstanceCB) == 40);
static_assert(sizeof(CD3D9Renderer::SGammaRamp) == 1536);
static_assert(sizeof(CD3D9Renderer::SRenderTargetStack) == 72);
static_assert(sizeof(CEngineModule_CryRenderer) == 8);
static_assert(sizeof(CSystemEventListner_Render) == 8);

#include "pipelineprofiler.h"
static_assert(sizeof(CRenderPipelineProfiler) == 347160);
static_assert(sizeof(CRenderPipelineProfiler::RPPAggregatedStats) == 48);
static_assert(sizeof(CRenderPipelineProfiler::RPPReport) == 24);
static_assert(sizeof(CRenderPipelineProfiler::RPPSectionCrcName) == 36);
static_assert(sizeof(CRenderPipelineProfiler::SFrameData) == 114720);
static_assert(sizeof(CRenderPipelineProfiler::SProfilerSection) == 80);
static_assert(sizeof(CRenderPipelineProfiler::SStaticElementInfo) == 8);
static_assert(sizeof(CRenderPipelineProfiler::SThreadTimings) == 28);
#endif // !MOONCRASH
