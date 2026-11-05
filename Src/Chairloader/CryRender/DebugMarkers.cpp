#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Prey/CryRenderer/DeviceTexture.h>

namespace RenderDll::DebugMarkers
{
#ifdef RENDERDLL_DEBUG_MARKERS

ID3DUserDefinedAnnotation* g_pAnnot = nullptr;

struct AnnotatedSection : NoCopy
{
	AnnotatedSection(const wchar_t* name) { g_pAnnot->BeginEvent(name); }
	~AnnotatedSection() { g_pAnnot->EndEvent(); }
};

//------------------------------------------------------------
// CD3D9Renderer
//------------------------------------------------------------
auto g_CD3D9Renderer_FlashRenderInternal_Hook = CD3D9Renderer::FFlashRenderInternal.MakeHook();
auto g_CD3D9Renderer_FX_DeferredDecals_Hook = CD3D9Renderer::FFX_DeferredDecals.MakeHook();
auto g_CD3D9Renderer_FX_ZTargetReadBack_Hook = CD3D9Renderer::FFX_ZTargetReadBack.MakeHook();

void CD3D9Renderer_FlashRenderInternal_Hook(CD3D9Renderer* _this, IFlashPlayer_RenderProxy* pPlayer, bool bDoRealRender)
{
	AnnotatedSection annot(L"Flash Render");
	g_CD3D9Renderer_FlashRenderInternal_Hook.InvokeOrig(_this, pPlayer, bDoRealRender);
}

bool CD3D9Renderer_FX_DeferredDecals_Hook(CD3D9Renderer* const _this)
{
	AnnotatedSection annot(L"Deferred Decals");
	return g_CD3D9Renderer_FX_DeferredDecals_Hook.InvokeOrig(_this);
}

void CD3D9Renderer_FX_ZTargetReadBack_Hook(CD3D9Renderer* const _this)
{
	AnnotatedSection annot(L"Depth Readback");
	g_CD3D9Renderer_FX_ZTargetReadBack_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CSceneGBufferStage
//------------------------------------------------------------
class CSceneGBufferStage;
#ifndef MOONCRASH
auto g_CSceneGBufferStage_Execute = PreyFunction<void(CSceneGBufferStage* _this)>(0xF71A80);
#else
auto g_CSceneGBufferStage_Execute = PreyFunction<void(CSceneGBufferStage* _this)>(0xF8DD00);
#endif
#ifndef MOONCRASH
auto g_CSceneGBufferStage_ExecuteLinearizeDepth = PreyFunction<void(CSceneGBufferStage* _this, CRenderView* pRenderView)>(0xF72150);
#else
auto g_CSceneGBufferStage_ExecuteLinearizeDepth = PreyFunction<void(CSceneGBufferStage* _this, CRenderView* pRenderView)>(0xF8E3D0);
#endif
auto g_CSceneGBufferStage_Execute_Hook = g_CSceneGBufferStage_Execute.MakeHook();
auto g_CSceneGBufferStage_ExecuteLinearizeDepth_Hook = g_CSceneGBufferStage_ExecuteLinearizeDepth.MakeHook();

void CSceneGBufferStage_Execute_Hook(CSceneGBufferStage* _this)
{
	g_pAnnot->BeginEvent(L"G-Buffer");
	g_CSceneGBufferStage_Execute_Hook.InvokeOrig(_this);
}

void CSceneGBufferStage_ExecuteLinearizeDepth_Hook(CSceneGBufferStage* _this, CRenderView* pRenderView)
{
	g_CSceneGBufferStage_ExecuteLinearizeDepth_Hook.InvokeOrig(_this, pRenderView);
	g_pAnnot->EndEvent();
}

//------------------------------------------------------------
// CDepthDownsamplePass
//------------------------------------------------------------
class CDepthDownsamplePass;
#ifndef MOONCRASH
auto g_CDepthDownsamplePass_Execute = PreyFunction<void(CDepthDownsamplePass* _this, CTexture* pSrcRT, CTexture* pDestRT, bool bLinearizeSrcDepth, bool bFromSingleChannel)>(0xF65250);
#else
auto g_CDepthDownsamplePass_Execute = PreyFunction<void(CDepthDownsamplePass* _this, CTexture* pSrcRT, CTexture* pDestRT, bool bLinearizeSrcDepth, bool bFromSingleChannel)>(0xF815C0);
#endif
auto g_CDepthDownsamplePass_Execute_Hook = g_CDepthDownsamplePass_Execute.MakeHook();

void CDepthDownsamplePass_Execute_Hook(CDepthDownsamplePass* _this, CTexture* pSrcRT, CTexture* pDestRT, bool bLinearizeSrcDepth, bool bFromSingleChannel)
{
	AnnotatedSection annot(L"Depth Downsample");
	g_CDepthDownsamplePass_Execute_Hook.InvokeOrig(_this, pSrcRT, pDestRT, bLinearizeSrcDepth, bFromSingleChannel);
}

//------------------------------------------------------------
// CRenderItemDrawer::SRenderListCollection
//------------------------------------------------------------
#ifndef MOONCRASH
auto g_CRenderItemDrawer_SRenderListCollection_WaitForJobs = PreyFunction<void(void* _this)>(0xEAD7F0);
#else
auto g_CRenderItemDrawer_SRenderListCollection_WaitForJobs = PreyFunction<void(void* _this)>(0xEC9CD0);
#endif
auto g_CRenderItemDrawer_SRenderListCollection_WaitForJobs_Hook = g_CRenderItemDrawer_SRenderListCollection_WaitForJobs.MakeHook();

void CRenderItemDrawer_SRenderListCollection_WaitForJobs_Hook(void* _this)
{
	AnnotatedSection annot(L"SRenderListCollection");
	g_CRenderItemDrawer_SRenderListCollection_WaitForJobs_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CClipVolumesStage
//------------------------------------------------------------
class CClipVolumesStage;
#ifndef MOONCRASH
auto g_CClipVolumesStage_Execute = PreyFunction<void(CClipVolumesStage* _this)>(0xF5D060);
#else
auto g_CClipVolumesStage_Execute = PreyFunction<void(CClipVolumesStage* _this)>(0xF79310);
#endif
auto g_CClipVolumesStage_Execute_Hook = g_CClipVolumesStage_Execute.MakeHook();

void CClipVolumesStage_Execute_Hook(CClipVolumesStage* _this)
{
	AnnotatedSection annot(L"Clip Volumes");
	g_CClipVolumesStage_Execute_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CDeferredShading
//------------------------------------------------------------
class CDeferredShading;
#ifndef MOONCRASH
auto g_CDeferredShading_Render = PreyFunction<void(CDeferredShading* const _this, CRenderView* pRenderView)>(0xEDFED0);
#else
auto g_CDeferredShading_Render = PreyFunction<void(CDeferredShading* const _this, CRenderView* pRenderView)>(0xEFC1B0);
#endif
auto g_CDeferredShading_Render_Hook = g_CDeferredShading_Render.MakeHook();

void CDeferredShading_Render_Hook(CDeferredShading* const _this, CRenderView* pRenderView)
{
	AnnotatedSection annot(L"Deferred Lighting");
	g_CDeferredShading_Render_Hook.InvokeOrig(_this, pRenderView);
}

//------------------------------------------------------------
// CSceneForwardStage
//------------------------------------------------------------
class CSceneForwardStage;
#ifndef MOONCRASH
auto g_CSceneForwardStage_Execute_Opaque = PreyFunction<void(CSceneForwardStage* const _this)>(0xF70C90);
#else
auto g_CSceneForwardStage_Execute_Opaque = PreyFunction<void(CSceneForwardStage* const _this)>(0xF8CF10);
#endif
#ifndef MOONCRASH
auto g_CSceneForwardStage_Execute_TransparentBelowWater = PreyFunction<void(CSceneForwardStage* const _this)>(0xF70E40);
#else
auto g_CSceneForwardStage_Execute_TransparentBelowWater = PreyFunction<void(CSceneForwardStage* const _this)>(0xF8D0C0);
#endif
#ifndef MOONCRASH
auto g_CSceneForwardStage_Execute_TransparentAboveWater = PreyFunction<void(CSceneForwardStage* const _this)>(0xF70DC0);
#else
auto g_CSceneForwardStage_Execute_TransparentAboveWater = PreyFunction<void(CSceneForwardStage* const _this)>(0xF8D040);
#endif
#ifndef MOONCRASH
auto g_CSceneForwardStage_Execute_TransparentNear = PreyFunction<void(CSceneForwardStage* const _this)>(0xF70ED0);
#else
auto g_CSceneForwardStage_Execute_TransparentNear = PreyFunction<void(CSceneForwardStage* const _this)>(0xF8D150);
#endif
#ifndef MOONCRASH
auto g_CSceneForwardStage_Execute_Distortion = PreyFunction<void(CSceneForwardStage* const _this, CRenderView* _pRenderView)>(0xF70AD0);
#else
auto g_CSceneForwardStage_Execute_Distortion = PreyFunction<void(CSceneForwardStage* const _this, CRenderView* _pRenderView)>(0xF8CD50);
#endif

auto g_CSceneForwardStage_Execute_Opaque_Hook = g_CSceneForwardStage_Execute_Opaque.MakeHook();
auto g_CSceneForwardStage_Execute_TransparentBelowWater_Hook = g_CSceneForwardStage_Execute_TransparentBelowWater.MakeHook();
auto g_CSceneForwardStage_Execute_TransparentAboveWater_Hook = g_CSceneForwardStage_Execute_TransparentAboveWater.MakeHook();
auto g_CSceneForwardStage_Execute_TransparentNear_Hook = g_CSceneForwardStage_Execute_TransparentNear.MakeHook();
auto g_CSceneForwardStage_Execute_Distortion_Hook = g_CSceneForwardStage_Execute_Distortion.MakeHook();

void CSceneForwardStage_Execute_Opaque_Hook(CSceneForwardStage* _this)
{
	AnnotatedSection annot(L"Forward (opaque)");
	g_CSceneForwardStage_Execute_Opaque_Hook.InvokeOrig(_this);
}

void CSceneForwardStage_Execute_TransparentBelowWater_Hook(CSceneForwardStage* _this)
{
	AnnotatedSection annot(L"Forward (transparent below water)");
	g_CSceneForwardStage_Execute_TransparentBelowWater_Hook.InvokeOrig(_this);
}

void CSceneForwardStage_Execute_TransparentAboveWater_Hook(CSceneForwardStage* _this)
{
	AnnotatedSection annot(L"Forward (transparent above water)");
	g_CSceneForwardStage_Execute_TransparentAboveWater_Hook.InvokeOrig(_this);
}

void CSceneForwardStage_Execute_TransparentNear_Hook(CSceneForwardStage* _this)
{
	AnnotatedSection annot(L"Forward (transparent near)");
	g_CSceneForwardStage_Execute_TransparentNear_Hook.InvokeOrig(_this);
}

void CSceneForwardStage_Execute_Distortion_Hook(CSceneForwardStage* const _this, CRenderView* _pRenderView)
{
	AnnotatedSection annot(L"Forward (distortion)");
	g_CSceneForwardStage_Execute_Distortion_Hook.InvokeOrig(_this, _pRenderView);
}

//------------------------------------------------------------
// CStandardGraphicsPipeline
//------------------------------------------------------------
class CStandardGraphicsPipeline;
#ifndef MOONCRASH
auto g_CStandardGraphicsPipeline_ExecuteHDRPostProcessing = PreyFunction<void(CStandardGraphicsPipeline* const _this)>(0xF83FB0);
#else
auto g_CStandardGraphicsPipeline_ExecuteHDRPostProcessing = PreyFunction<void(CStandardGraphicsPipeline* const _this)>(0xFA0250);
#endif
auto g_CStandardGraphicsPipeline_ExecuteHDRPostProcessing_Hook = g_CStandardGraphicsPipeline_ExecuteHDRPostProcessing.MakeHook();

void CStandardGraphicsPipeline_ExecuteHDRPostProcessing_Hook(CStandardGraphicsPipeline* _this)
{
	AnnotatedSection annot(L"HDR Post-Process");
	g_CStandardGraphicsPipeline_ExecuteHDRPostProcessing_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CMotionBlurStage
//------------------------------------------------------------
class CMotionBlurStage;
#ifndef MOONCRASH
auto g_CMotionBlurStage_Execute = PreyFunction<void(CMotionBlurStage* const _this)>(0xF6B1D0);
#else
auto g_CMotionBlurStage_Execute = PreyFunction<void(CMotionBlurStage* const _this)>(0xF874E0);
#endif
auto g_CMotionBlurStage_Execute_Hook = g_CMotionBlurStage_Execute.MakeHook();

void CMotionBlurStage_Execute_Hook(CMotionBlurStage* _this)
{
	AnnotatedSection annot(L"Motion Blur");
	g_CMotionBlurStage_Execute_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CDepthOfFieldStage
//------------------------------------------------------------
class CDepthOfFieldStage;
#ifndef MOONCRASH
auto g_CDepthOfFieldStage_Execute = PreyFunction<void(CDepthOfFieldStage* const _this)>(0xF66D30);
#else
auto g_CDepthOfFieldStage_Execute = PreyFunction<void(CDepthOfFieldStage* const _this)>(0xF83040);
#endif
auto g_CDepthOfFieldStage_Execute_Hook = g_CDepthOfFieldStage_Execute.MakeHook();

void CDepthOfFieldStage_Execute_Hook(CDepthOfFieldStage* _this)
{
	AnnotatedSection annot(L"Depth Of Field");
	g_CDepthOfFieldStage_Execute_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CStableDownsamplePass
//------------------------------------------------------------
class CStableDownsamplePass;
#ifndef MOONCRASH
auto g_CStableDownsamplePass_Execute = PreyFunction<void(CStableDownsamplePass* const _this, CTexture* pSrcRT, CTexture* pDestRT, bool bKillFireflies, bool bNaNGuard)>(0xF65E50);
#else
auto g_CStableDownsamplePass_Execute = PreyFunction<void(CStableDownsamplePass* const _this, CTexture* pSrcRT, CTexture* pDestRT, bool bKillFireflies, bool bNaNGuard)>(0xF821C0);
#endif
auto g_CStableDownsamplePass_Execute_Hook = g_CStableDownsamplePass_Execute.MakeHook();

void CStableDownsamplePass_Execute_Hook(CStableDownsamplePass* const _this, CTexture* pSrcRT, CTexture* pDestRT, bool bKillFireflies, bool bNaNGuard)
{
	AnnotatedSection annot(L"Stable Downsample Pass");
	g_CStableDownsamplePass_Execute_Hook.InvokeOrig(_this, pSrcRT, pDestRT, bKillFireflies, bNaNGuard);
}

//------------------------------------------------------------
// CStretchRectPass
//------------------------------------------------------------
class CStretchRectPass;
#ifndef MOONCRASH
auto g_CStretchRectPass_Execute = PreyFunction<void(CStretchRectPass* const _this, CTexture* pSrcRT, CTexture* pDestRT)>(0xF661A0);
#else
auto g_CStretchRectPass_Execute = PreyFunction<void(CStretchRectPass* const _this, CTexture* pSrcRT, CTexture* pDestRT)>(0xF82510);
#endif
auto g_CStretchRectPass_Execute_Hook = g_CStretchRectPass_Execute.MakeHook();

void CStretchRectPass_Execute_Hook(CStretchRectPass* const _this, CTexture* pSrcRT, CTexture* pDestRT)
{
	AnnotatedSection annot(L"Stretch Rect Pass");
	g_CStretchRectPass_Execute_Hook.InvokeOrig(_this, pSrcRT, pDestRT);
}

//------------------------------------------------------------
// CAutoExposureStage
//------------------------------------------------------------
class CAutoExposureStage;
#ifndef MOONCRASH
auto g_CAutoExposureStage_Execute = PreyFunction<void(CAutoExposureStage* const _this)>(0xF5A680);
#else
auto g_CAutoExposureStage_Execute = PreyFunction<void(CAutoExposureStage* const _this)>(0xF76940);
#endif
auto g_CAutoExposureStage_Execute_Hook = g_CAutoExposureStage_Execute.MakeHook();

void CAutoExposureStage_Execute_Hook(CAutoExposureStage* const _this)
{
	AnnotatedSection annot(L"Auto-Exposure");
	g_CAutoExposureStage_Execute_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CFullscreenPass
//------------------------------------------------------------
class CFullscreenPass;
#ifndef MOONCRASH
auto g_CFullscreenPass_Execute = PreyFunction<bool(CFullscreenPass* const _this)>(0xF5FF90);
#else
auto g_CFullscreenPass_Execute = PreyFunction<bool(CFullscreenPass* const _this)>(0xF7C240);
#endif
auto g_CFullscreenPass_Execute_Hook = g_CFullscreenPass_Execute.MakeHook();

bool CFullscreenPass_Execute_Hook(CFullscreenPass* const _this)
{
	AnnotatedSection annot(L"Fullscreen Pass");
	return g_CFullscreenPass_Execute_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CBloomStage
//------------------------------------------------------------
class CBloomStage;
#ifndef MOONCRASH
auto g_CBloomStage_Execute = PreyFunction<void(CBloomStage* const _this)>(0xF5B710);
#else
auto g_CBloomStage_Execute = PreyFunction<void(CBloomStage* const _this)>(0xF779F0);
#endif
auto g_CBloomStage_Execute_Hook = g_CBloomStage_Execute.MakeHook();

void CBloomStage_Execute_Hook(CBloomStage* const _this)
{
	AnnotatedSection annot(L"Bloom");
	g_CBloomStage_Execute_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CRELensOptics
//------------------------------------------------------------
class CRELensOptics;
#ifndef MOONCRASH
auto g_CRELensOptics_mfDraw = PreyFunction<bool(CRELensOptics* const _this, CShader* pShader, SShaderPass* pass)>(0xED4DC0);
#else
auto g_CRELensOptics_mfDraw = PreyFunction<bool(CRELensOptics* const _this, CShader* pShader, SShaderPass* pass)>(0xEF1110);
#endif
auto g_CRELensOptics_mfDraw_Hook = g_CRELensOptics_mfDraw.MakeHook();

bool CRELensOptics_mfDraw_Hook(CRELensOptics* const _this, CShader* pShader, SShaderPass* pass)
{
	AnnotatedSection annot(L"Lens Optics");
	return g_CRELensOptics_mfDraw_Hook.InvokeOrig(_this, pShader, pass);
}

//------------------------------------------------------------
// CSunShaftsStage
//------------------------------------------------------------
class CSunShaftsStage;
#ifndef MOONCRASH
auto g_CSunShaftsStage_Execute = PreyFunction<void(CSunShaftsStage* const _this)>(0xF8B0C0);
#else
auto g_CSunShaftsStage_Execute = PreyFunction<void(CSunShaftsStage* const _this)>(0xFA7360);
#endif
auto g_CSunShaftsStage_Execute_Hook = g_CSunShaftsStage_Execute.MakeHook();

void CSunShaftsStage_Execute_Hook(CSunShaftsStage* const _this)
{
	AnnotatedSection annot(L"Sun Shafts");
	g_CSunShaftsStage_Execute_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CToneMappingStage
//------------------------------------------------------------
class CToneMappingStage;
#ifndef MOONCRASH
auto g_CToneMappingStage_Execute = PreyFunction<void(CToneMappingStage* const _this)>(0xF90FF0);
#else
auto g_CToneMappingStage_Execute = PreyFunction<void(CToneMappingStage* const _this)>(0xFAD290);
#endif
auto g_CToneMappingStage_Execute_Hook = g_CToneMappingStage_Execute.MakeHook();

void CToneMappingStage_Execute_Hook(CToneMappingStage* const _this)
{
	AnnotatedSection annot(L"Tonemapping");
	g_CToneMappingStage_Execute_Hook.InvokeOrig(_this);
}

//------------------------------------------------------------
// CPostAAStage
//------------------------------------------------------------
class CPostAAStage;
#ifndef MOONCRASH
auto g_CPostAAStage_Execute = PreyFunction<void(CPostAAStage* const _this)>(0xF70730);
#else
auto g_CPostAAStage_Execute = PreyFunction<void(CPostAAStage* const _this)>(0xF8C9B0);
#endif
#ifndef MOONCRASH
auto g_CPostAAStage_ApplySMAA = PreyFunction<void(CPostAAStage* const _this, CTexture*& pCurrRT, CTexture* pBlendWeightsRT, CTexture* pDestRT)>(0xF6D4A0);
#else
auto g_CPostAAStage_ApplySMAA = PreyFunction<void(CPostAAStage* const _this, CTexture*& pCurrRT, CTexture* pBlendWeightsRT, CTexture* pDestRT)>(0xF897B0);
#endif
#ifndef MOONCRASH
auto g_CPostAAStage_ApplyTemporalAA = PreyFunction<void(CPostAAStage* const _this, CTexture*& pCurrRT, CTexture*& pMgpuRT, unsigned aaMode)>(0xF6DF80);
#else
auto g_CPostAAStage_ApplyTemporalAA = PreyFunction<void(CPostAAStage* const _this, CTexture*& pCurrRT, CTexture*& pMgpuRT, unsigned aaMode)>(0xF8A290);
#endif
#ifndef MOONCRASH
auto g_CPostAAStage_DoFinalComposition = PreyFunction<void(CPostAAStage* const _this, CTexture* pCurrRT, unsigned aaMode, CTexture* _pOpticsComposite)>(0xF6FB50);
#else
auto g_CPostAAStage_DoFinalComposition = PreyFunction<void(CPostAAStage* const _this, CTexture* pCurrRT, unsigned aaMode, CTexture* _pOpticsComposite)>(0xF8BE60);
#endif

auto g_CPostAAStage_Execute_Hook = g_CPostAAStage_Execute.MakeHook();
auto g_CPostAAStage_ApplySMAA_Hook = g_CPostAAStage_ApplySMAA.MakeHook();
auto g_CPostAAStage_ApplyTemporalAA_Hook = g_CPostAAStage_ApplyTemporalAA.MakeHook();
auto g_CPostAAStage_DoFinalComposition_Hook = g_CPostAAStage_DoFinalComposition.MakeHook();

void CPostAAStage_Execute_Hook(CPostAAStage* const _this)
{
	AnnotatedSection annot(L"PostAA");
	g_CPostAAStage_Execute_Hook.InvokeOrig(_this);
}

void CPostAAStage_ApplySMAA_Hook(CPostAAStage* const _this, CTexture*& pCurrRT, CTexture* pBlendWeightsRT, CTexture* pDestRT)
{
	AnnotatedSection annot(L"SMAA");
	g_CPostAAStage_ApplySMAA_Hook.InvokeOrig(_this, pCurrRT, pBlendWeightsRT, pDestRT);
}

void CPostAAStage_ApplyTemporalAA_Hook(CPostAAStage* const _this, CTexture*& pCurrRT, CTexture*& pMgpuRT, unsigned aaMode)
{
	wchar_t* name = nullptr;

	if (aaMode & eAT_TSAA_MASK)
		name = L"TSAA";
	else if (aaMode & eAT_FXAA_MASK)
		name = L"FXAA";
	else
		name = L"Unknown AA";

	AnnotatedSection annot(name);
	g_CPostAAStage_ApplyTemporalAA_Hook.InvokeOrig(_this, pCurrRT, pMgpuRT, aaMode);
}

void CPostAAStage_DoFinalComposition_Hook(CPostAAStage* const _this, CTexture* pCurrRT, unsigned aaMode, CTexture* _pOpticsComposite)
{
	AnnotatedSection annot(L"Final Composition");
	g_CPostAAStage_DoFinalComposition_Hook.InvokeOrig(_this, pCurrRT, aaMode, _pOpticsComposite);
}

//------------------------------------------------------------
// CTexture
//------------------------------------------------------------
auto g_CTexture_CreateDeviceTexture_Hook = CTexture::FCreateDeviceTexture.MakeHook();
auto g_CTexture_CreateRenderTarget_Hook = CTexture::FCreateRenderTargetOv0.MakeHook();

void SetTextureDebugName(CTexture* tex)
{
	CDeviceTexture* pDevTex = tex->GetDevTexture();
	const char* name = tex->GetName();
	pDevTex->GetBaseTexture()->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(name), name);
}

bool CTexture_CreateDeviceTexture_Hook(CTexture* _this, byte* pData[6])
{
	bool res = g_CTexture_CreateDeviceTexture_Hook.InvokeOrig(_this, pData);
	if (res)
		SetTextureDebugName(_this);
	return res;
}

bool CTexture_CreateRenderTarget_Hook(CTexture* const _this, ETEX_Format eTF, ColorF const& cClear)
{
	// CreateDeviceTexture is inlined in CreateRenderTarget
	bool res = g_CTexture_CreateRenderTarget_Hook.InvokeOrig(_this, eTF, cClear);
	if (res)
		SetTextureDebugName(_this);
	return res;
}

//------------------------------------------------------------
// DebugMarkers
//------------------------------------------------------------
void InitHooks()
{
	g_CD3D9Renderer_FlashRenderInternal_Hook.SetHookFunc(&CD3D9Renderer_FlashRenderInternal_Hook);
	g_CD3D9Renderer_FX_DeferredDecals_Hook.SetHookFunc(&CD3D9Renderer_FX_DeferredDecals_Hook);
	g_CD3D9Renderer_FX_ZTargetReadBack_Hook.SetHookFunc(&CD3D9Renderer_FX_ZTargetReadBack_Hook);

	g_CSceneGBufferStage_Execute_Hook.SetHookFunc(&CSceneGBufferStage_Execute_Hook);
	g_CSceneGBufferStage_ExecuteLinearizeDepth_Hook.SetHookFunc(&CSceneGBufferStage_ExecuteLinearizeDepth_Hook);

	g_CDepthDownsamplePass_Execute_Hook.SetHookFunc(&CDepthDownsamplePass_Execute_Hook);
	g_CRenderItemDrawer_SRenderListCollection_WaitForJobs_Hook.SetHookFunc(&CRenderItemDrawer_SRenderListCollection_WaitForJobs_Hook);
	g_CClipVolumesStage_Execute_Hook.SetHookFunc(&CClipVolumesStage_Execute_Hook);
	g_CDeferredShading_Render_Hook.SetHookFunc(&CDeferredShading_Render_Hook);

	g_CSceneForwardStage_Execute_Opaque_Hook.SetHookFunc(&CSceneForwardStage_Execute_Opaque_Hook);
	g_CSceneForwardStage_Execute_TransparentBelowWater_Hook.SetHookFunc(&CSceneForwardStage_Execute_TransparentBelowWater_Hook);
	g_CSceneForwardStage_Execute_TransparentAboveWater_Hook.SetHookFunc(&CSceneForwardStage_Execute_TransparentAboveWater_Hook);
	g_CSceneForwardStage_Execute_TransparentNear_Hook.SetHookFunc(&CSceneForwardStage_Execute_TransparentNear_Hook);
	g_CSceneForwardStage_Execute_Distortion_Hook.SetHookFunc(&CSceneForwardStage_Execute_Distortion_Hook);

	g_CStandardGraphicsPipeline_ExecuteHDRPostProcessing_Hook.SetHookFunc(&CStandardGraphicsPipeline_ExecuteHDRPostProcessing_Hook);
	g_CMotionBlurStage_Execute_Hook.SetHookFunc(&CMotionBlurStage_Execute_Hook);
	g_CDepthOfFieldStage_Execute_Hook.SetHookFunc(&CDepthOfFieldStage_Execute_Hook);
	g_CStableDownsamplePass_Execute_Hook.SetHookFunc(&CStableDownsamplePass_Execute_Hook);
	g_CStretchRectPass_Execute_Hook.SetHookFunc(&CStretchRectPass_Execute_Hook);
	g_CAutoExposureStage_Execute_Hook.SetHookFunc(&CAutoExposureStage_Execute_Hook);
	g_CFullscreenPass_Execute_Hook.SetHookFunc(&CFullscreenPass_Execute_Hook);
	g_CBloomStage_Execute_Hook.SetHookFunc(&CBloomStage_Execute_Hook);
	g_CRELensOptics_mfDraw_Hook.SetHookFunc(&CRELensOptics_mfDraw_Hook);
	g_CSunShaftsStage_Execute_Hook.SetHookFunc(&CSunShaftsStage_Execute_Hook);
	g_CToneMappingStage_Execute_Hook.SetHookFunc(&CToneMappingStage_Execute_Hook);

	g_CPostAAStage_Execute_Hook.SetHookFunc(&CPostAAStage_Execute_Hook);
	g_CPostAAStage_ApplySMAA_Hook.SetHookFunc(&CPostAAStage_ApplySMAA_Hook);
	g_CPostAAStage_ApplyTemporalAA_Hook.SetHookFunc(&CPostAAStage_ApplyTemporalAA_Hook);
	g_CPostAAStage_DoFinalComposition_Hook.SetHookFunc(&CPostAAStage_DoFinalComposition_Hook);

	g_CTexture_CreateDeviceTexture_Hook.SetHookFunc(&CTexture_CreateDeviceTexture_Hook);
	g_CTexture_CreateRenderTarget_Hook.SetHookFunc(&CTexture_CreateRenderTarget_Hook);
}

void InitRenderer()
{
	CD3D9Renderer* rd = static_cast<CD3D9Renderer*>(gEnv->pRenderer);
	rd->m_DeviceContextWrapper.QueryInterface(__uuidof(ID3DUserDefinedAnnotation), (void**)&g_pAnnot);
}

#else

void InitHooks() {}
void InitRenderer() {}

#endif
}
