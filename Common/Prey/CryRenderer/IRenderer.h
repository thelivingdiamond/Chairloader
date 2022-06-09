#pragma once
#include <Prey/CryMath/Cry_Math.h>
#include <Prey/CryRenderer/ITexture.h>
#include "preyDllObjects.h"

class IRendererEventListener
{
public:
	virtual void OnPostCreateDevice() = 0;
	virtual void OnPostResetDevice() = 0;
	virtual ~IRendererEventListener() = 0;
};

enum ERenderType
{
	eRT_Undefined = 0x0,
	eRT_Null = 0x1,
	eRT_DX11 = 0x2,
	eRT_DX12 = 0x3,
	eRT_XboxOne = 0x4,
	eRT_PS4 = 0x5,
	eRT_OpenGL = 0x6,
};

enum EFullscreenMode : int8_t
{
	windowed = 0x0,
	fullscreen = 0x1,
	fullscreenWindowed = 0x2,
};

enum EDeviceMemoryHeap : uint8_t
{
	kDeviceMemoryHeap_Invalid = 0xFF,
	kDeviceMemoryHeap_Textures = 0x0,
	kDeviceMemoryHeap_Scaleform = 0x1,
	kDeviceMemoryHeap_WriteBack = 0x2,
	kDeviceMemoryHeap_WriteCombine = 0x3,
	kDeviceMemoryHeap_Direct = 0x4,
	kDeviceMemoryHeapCount = 0x5,
};

enum EDeviceMemoryType : int8_t
{
	kDeviceMemoryType_CPU_RW_GPU_RW = 0x0,
	kDeviceMemoryType_CPU_WC_GPU_RW = 0x1,
	kDeviceMemoryType_CPU_R_GPU_R = 0x2,
	kDeviceMemoryTypeCount = 0x3,
};

enum EScreenAspectRatio
{
	eAspect_Unknown = 0x0,
	eAspect_4_3 = 0x1,
	eAspect_16_9 = 0x2,
	eAspect_16_10 = 0x3,
};

enum PublicRenderPrimitiveType
{
	prtTriangleList = 0x0,
	prtTriangleStrip = 0x1,
	prtLineList = 0x2,
	prtLineStrip = 0x3,
};

enum EScreenShotMode : __int32
{
	eScreenShotMode_Normal = 0x0,
	eScreenShotMode_AppCrash = 0x1,
};

enum EShaderType
{
	eST_All = 0xFFFFFFFF,
	eST_General = 0x0,
	eST_Metal = 0x1,
	eST_Glass = 0x2,
	eST_Vegetation = 0x3,
	eST_Ice = 0x4,
	eST_Terrain = 0x5,
	eST_Shadow = 0x6,
	eST_Water = 0x7,
	eST_FX = 0x8,
	eST_PostProcess = 0x9,
	eST_HDR = 0xA,
	eST_Sky = 0xB,
	eST_Particle = 0xC,
	eST_Compute = 0xD,
	eST_Max = 0xE,
};

enum EShaderQuality
{
	eSQ_Low = 0x0,
	eSQ_Medium = 0x1,
	eSQ_High = 0x2,
	eSQ_VeryHigh = 0x3,
	eSQ_Max = 0x4,
};

enum ERenderQuality
{
	eRQ_Low = 0x0,
	eRQ_Medium = 0x1,
	eRQ_High = 0x2,
	eRQ_VeryHigh = 0x3,
	eRQ_Max = 0x4,
};

enum EDataType : __int8
{
	eDATA_Unknown = 0x0,
	eDATA_ArkRemoved01 = 0x1,
	eDATA_Beam = 0x2,
	eDATA_ClientPoly = 0x3,
	eDATA_Flare = 0x4,
	eDATA_Terrain = 0x5,
	eDATA_SkyZone = 0x6,
	eDATA_Mesh = 0x7,
	eDATA_ArkRemoved02 = 0x8,
	eDATA_LensOptics = 0x9,
	eDATA_OcclusionQuery = 0xA,
	eDATA_Particle = 0xB,
	eDATA_PostProcess = 0xC,
	eDATA_ArkRemoved03 = 0xD,
	eDATA_ArkRemoved04 = 0xE,
	eDATA_HDRSky = 0xF,
	eDATA_FogVolume = 0x10,
	eDATA_WaterVolume = 0x11,
	eDATA_ArkRemoved05 = 0x12,
	eDATA_VolumeObject = 0x13,
	eDATA_PrismObject = 0x14,
	eDATA_DeferredShading = 0x15,
	eDATA_ArkRemoved06 = 0x16,
	eDATA_ArkRemoved07 = 0x17,
	eDATA_GeomCache = 0x18,
	eDATA_ArkBreakableGlass = 0x19,
	eDATA_ArkSpace = 0x1A,
};

enum EFlareType : __int32
{
	eFT__Base__ = 0x0,
	eFT_Root = 0x1,
	eFT_Group = 0x2,
	eFT_Ghost = 0x3,
	eFT_MultiGhosts = 0x4,
	eFT_Glow = 0x5,
	eFT_ChromaticRing = 0x6,
	eFT_IrisShafts = 0x7,
	eFT_CameraOrbs = 0x8,
	eFT_ImageSpaceShafts = 0x9,
	eFT_Streaks = 0xA,
	eFT_Reference = 0xB,
	eFT_Proxy = 0xC,
	eFT_Max = 0xD,
};

struct SCustomRenderInitArgs;
class IArkVideoInfo;
struct SVF_P3F_C4B_T2F;
class CRenderView;
class ITextureStreamListener;
class CFBitmap;
class IFFont_RenderProxy;
struct STextDrawContext;
class IFlashPlayer_RenderProxy;
class IRenderMesh;
class IShader;
struct SShaderItem;
struct SAddParticlesToSceneJob;
class CRenderObject;
struct SPipTangents;
struct SShaderProfile;
struct SInputShaderResources;
class IDynTextureSource;
class CRendElementBase;
struct SRenderLight;
struct SDeferredDecal;
struct SRendParams;
class IRenderShaderResources;
struct SSetPostEffectParamString;
struct SSetPostEffectParamVec4;
struct SSetPostEffectParam;
struct SDrawTextInfo;
class IRenderAuxGeom;
class IArkRenderPersistentAuxGeom;
class IColorGradingController;
struct SResourceAsync;
class ISyncMainWithRenderListener;
class IRenderNode;
class IOpticsElementBase;
class ISoftOcclusionQuery;
struct SSF_GlobalDrawParams;
struct RectI;

class IRenderer {
public:
	struct SLoadShaderItemArgs;
	struct SUpdateRect;
	struct ESFMaskOp;

	virtual ~IRenderer() = 0;
	virtual void AddListener(IRendererEventListener *) = 0;
	virtual void RemoveListener(IRendererEventListener *) = 0;
	virtual ERenderType GetRenderType() = 0;
	virtual void *Init(int, int, int, int, unsigned int, int, int, EFullscreenMode, void *, void *, bool, const SCustomRenderInitArgs *, bool) = 0;
	virtual void PostInit() = 0;
	virtual bool CreateDeviceMemoryHeap(EDeviceMemoryHeap, EDeviceMemoryType, unsigned __int64, unsigned __int64, unsigned __int64) = 0;
	virtual void StartRenderIntroMovies(bool) = 0;
	virtual void StopRenderIntroMovies(bool) = 0;
	virtual bool IsRenderingIntroMovies() = 0;
	virtual void ExecuteAsyncDIP() = 0;
	virtual int GetFeatures() = 0;
	virtual void GetVideoMemoryUsageStats(unsigned __int64 *, unsigned __int64 *, bool) = 0;
	virtual int GetNumGeomInstances() = 0;
	virtual int GetNumGeomInstanceDrawCalls() = 0;
	virtual int GetCurrentNumberOfDrawCalls(const unsigned int) = 0;
	virtual void GetCurrentNumberOfDrawCalls(int *, int *) = 0;
	virtual int GetCurrentNumberOfDrawCalls() = 0;
	virtual float GetCurrentDrawCallRTTimes(const unsigned int) = 0;
	virtual bool DeleteContext(void *) = 0;
	virtual bool CreateContext(void *, bool, int, int, bool) = 0;
	virtual bool SetCurrentContext(void *) = 0;
	virtual void MakeMainContextActive() = 0;
	virtual bool IsMainContextActive() = 0;
	virtual void *GetMainContextHWND() = 0;
	virtual void *GetCurrentContextHWND() = 0;
	virtual bool IsCurrentContextMainVP() = 0;
	virtual int GetCurrentContextViewportHeight() = 0;
	virtual int GetCurrentContextViewportWidth() = 0;
	virtual void SuspendDevice() = 0;
	virtual void ResumeDevice() = 0;
	virtual void ShutDown(bool) = 0;
	virtual void ShutDownFast() = 0;
	virtual IArkVideoInfo *GetIArkVideoInfo() = 0;
	virtual bool ChangeResolution(int, int, int, int, EFullscreenMode, bool) = 0;
	virtual void BeginFrame(bool) = 0;
	virtual void InitSystemResources(int) = 0;
	virtual void FreeResources(int) = 0;
	virtual void Release() = 0;
	virtual void RenderDebug(bool) = 0;
	virtual void EndFrame() = 0;
	virtual void TryFlush() = 0;
	virtual void GetViewport(int &x, int &y, int &width, int &height) = 0;
	virtual void SetViewport(int, int, int, int, int) = 0;
	virtual void SetRenderTile(float, float, float, float) = 0;
	virtual void SetScissor(int, int, int, int) = 0;
	virtual EScreenAspectRatio GetScreenAspect(int, int) = 0;
	virtual Vec2_tpl<float> *SetViewportDownscale(Vec2_tpl<float> *result, float, float) = 0;
	virtual void DrawDynVB(SVF_P3F_C4B_T2F *, unsigned __int16 *, int, int, const PublicRenderPrimitiveType) = 0;
	virtual void SetCamera(const CCamera *) = 0;
	virtual const CCamera *GetCamera() = 0;
	virtual CRenderView *GetRenderViewForThread(int, bool) = 0;
	virtual bool SetGammaDelta(const float) = 0;
	virtual void RestoreGamma() = 0;
	virtual bool ChangeDisplay(unsigned int, unsigned int, unsigned int) = 0;
	virtual void ChangeViewport(unsigned int, unsigned int, unsigned int, unsigned int, bool) = 0;
	virtual bool SaveTga(unsigned __int8 *, int, int, int, const char *, bool) = 0;
	virtual int GetWhiteTextureId() = 0;
	virtual void Draw2dImage(float, float, float, float, int, float, float, float, float, float, float, float, float, float, float) = 0;
	virtual void Draw2dImageStretchMode(bool) = 0;
	virtual void Push2dImage(float, float, float, float, int, float, float, float, float, float, float, float, float, float, float) = 0;
	virtual void Draw2dImageList() = 0;
	virtual void DrawImage(float, float, float, float, int, float, float, float, float, float, float, float, float, bool) = 0;
	virtual void DrawImageWithUV(float, float, float, float, float, int, float *, float *, float, float, float, float, bool) = 0;
	virtual void PushWireframeMode(int) = 0;
	virtual void PopWireframeMode() = 0;
	virtual int GetHeight() = 0;
	virtual int GetWidth() = 0;
	virtual float GetPixelAspectRatio() = 0;
	virtual int GetOverlayHeight() = 0;
	virtual int GetOverlayWidth() = 0;
	virtual void SwitchToNativeResolutionBackbuffer() = 0;
	virtual void GetMemoryUsage(ICrySizer *) = 0;
	virtual void GetBandwidthStats(float *) = 0;
	virtual void SetTextureStreamListener(ITextureStreamListener *) = 0;
	virtual int GetOcclusionBuffer(float *, int, int, Matrix44_tpl<float> *) = 0;
	virtual bool ScreenShot(const char *, int, EScreenShotMode) = 0;
	virtual int GetStencilBpp() = 0;
	virtual float GetNearestRangeMax() = 0;
	virtual bool ProjectToScreen(float, float, float, float *, float *, float *) = 0;
	virtual int UnProjectFromScreen(float, float, float, float *, float *, float *) = 0;
	virtual void GetModelViewMatrix(float *) = 0;
	virtual void GetProjectionMatrix(float *) = 0;
	virtual void GetCameraZeroMatrix(float *) = 0;
	virtual bool FontUploadTexture(CFBitmap *, ETEX_Format) = 0;
	virtual int FontCreateTexture(int, int, unsigned __int8 *, ETEX_Format, bool) = 0;
	virtual bool FontUpdateTexture(int, int, int, int, int, unsigned __int8 *) = 0;
	virtual void FontReleaseTexture(CFBitmap *) = 0;
	virtual void FontSetTexture(int, int) = 0;
	virtual void FontSetTexture(CFBitmap *, int) = 0;
	virtual void FontSetRenderingState(unsigned int, unsigned int) = 0;
	virtual void FontSetBlending(int, int) = 0;
	virtual void FontRestoreRenderingState() = 0;
	virtual bool FlushRTCommands(bool, bool, bool) = 0;
	virtual void DrawStringW(IFFont_RenderProxy *, float, float, float, const wchar_t *, const bool, const STextDrawContext *) = 0;
	virtual int RT_CurThreadList() = 0;
	virtual void RT_FlashRender(IFlashPlayer_RenderProxy *) = 0;
	virtual void RT_FlashRenderPlaybackLockless(IFlashPlayer_RenderProxy *, int, bool) = 0;
	virtual void RT_FlashRemoveTexture(ITexture *) = 0;
	virtual bool EF_PrecacheResource(CDLight *, float, float, int, int) = 0;
	virtual bool EF_PrecacheResource(IRenderMesh *, IMaterial *, float, float, int, int) = 0;
	virtual bool EF_PrecacheResource(ITexture *, float, float, int, int, int) = 0;
	virtual bool EF_PrecacheResource(IShader *, float, float, int) = 0;
	virtual bool EF_PrecacheResource(SShaderItem *, float, float, int, int, int) = 0;
	virtual void PrecacheTick() = 0;
	virtual void PostLevelLoading() = 0;
	virtual void PostLevelUnload() = 0;
	virtual void EF_AddMultipleParticlesToScene(const SAddParticlesToSceneJob *, unsigned __int64, const SRenderingPassInfo *) = 0;
	virtual void GetMemoryUsageParticleREs(ICrySizer *) = 0;
	virtual CRenderObject *EF_AddPolygonToScene(SShaderItem *, CRenderObject *, const SRenderingPassInfo *, int, int, SVF_P3F_C4B_T2F **, SPipTangents **, unsigned __int16 **, int) = 0;
	virtual CRenderObject *EF_AddPolygonToScene(SShaderItem *, int, const SVF_P3F_C4B_T2F *, const SPipTangents *, CRenderObject *, const SRenderingPassInfo *, unsigned __int16 *, int, int) = 0;
	virtual void EF_SetShaderMissCallback(void(const char *)) = 0;
	virtual const char *EF_GetShaderMissLogPath() = 0;
	virtual CryStringT<char> *EF_GetShaderNames(int *) = 0;
	virtual bool EF_ReloadFile(const char *) = 0;
	virtual bool EF_ReloadFile_Request(const char *) = 0;
	//virtual _smart_ptr<IImageFile> *EF_LoadImage(_smart_ptr<IImageFile> *result, const char *, unsigned int) = 0;
	virtual void *EF_LoadImage(int unfinished) = 0; // TODO:
	virtual unsigned __int64 EF_GetRemapedShaderMaskGen(const char *, unsigned __int64, bool) = 0;
	virtual unsigned __int64 EF_GetShaderGlobalMaskGenFromString(const char *, const char *, unsigned __int64) = 0;
	virtual const char *EF_GetStringFromShaderGlobalMaskGen(const char *, unsigned __int64) = 0;
	virtual const SShaderProfile *GetShaderProfile(EShaderType) = 0;
	virtual void EF_SetShaderQuality(EShaderType, EShaderQuality) = 0;
	virtual ERenderQuality EF_GetRenderQuality() = 0;
	virtual EShaderQuality EF_GetShaderQuality(EShaderType) = 0;
	virtual SShaderItem *EF_LoadShaderItem(SShaderItem *result, const char *, bool, int, SInputShaderResources *, unsigned __int64, const IRenderer::SLoadShaderItemArgs *) = 0;
	virtual IShader *EF_LoadShader(const char *, int, unsigned __int64) = 0;
	virtual void EF_ReloadTextures() = 0;
	virtual ITexture *EF_GetTextureByID(int) = 0;
	virtual ITexture *EF_GetTextureByName(const char *, unsigned int) = 0;
	virtual ITexture *EF_LoadTexture(const char *, const unsigned int) = 0;
	virtual unsigned int EF_CacheTextureAsync(const char *, unsigned int, EDeviceMemoryHeap) = 0;
	virtual void EF_ReleaseCacheTexture(unsigned int) = 0;
	virtual ITexture *EF_TryGetCacheTexture(unsigned int) = 0;
	virtual IDynTextureSource *EF_LoadDynTexture(const char *, bool) = 0;
	virtual CRendElementBase *EF_CreateRE(EDataType) = 0;
	virtual void EF_StartEf(const SRenderingPassInfo *) = 0;
	virtual CRenderObject *EF_GetObject_Temp(int) = 0;
	virtual CRenderObject *EF_GetObject() = 0;
	virtual void EF_FreeObject(CRenderObject *) = 0;
	virtual CRenderObject *EF_DuplicateRO(CRenderObject *, const SRenderingPassInfo *) = 0;
	virtual void EF_AddEf(CRendElementBase *, SShaderItem *, CRenderObject *, const SRenderingPassInfo *, int, int) = 0;
	virtual void EF_EndEf3D(const int, const int, const int, const SRenderingPassInfo *) = 0;
	virtual void EF_InvokeShadowMapRenderJobs(CRenderView *, const int) = 0;
	virtual bool EF_IsFakeDLight(const CDLight *) = 0;
	virtual void EF_ADDDlight(CDLight *, const SRenderingPassInfo *) = 0;
	virtual Color_tpl<float> *EF_GetLightAnimColor(Color_tpl<float> *result, unsigned __int8, unsigned __int8, float) = 0;
	virtual bool EF_UpdateDLight(SRenderLight *) = 0;
	virtual bool EF_AddDeferredDecal(const SDeferredDecal *, const SRenderingPassInfo *) = 0;
	virtual int EF_AddDeferredLight(const CDLight *, float, const SRenderingPassInfo *, const SRendParams *) = 0;
	virtual void EF_ReleaseDeferredData() = 0;
	virtual SInputShaderResources *EF_CreateInputShaderResource(IRenderShaderResources *) = 0;
	virtual unsigned __int64 EF_PostEffectParamHandleFromName(const char *) = 0;
	virtual void EF_SetPostEffectParam(const SSetPostEffectParamString *) = 0;
	virtual void EF_SetPostEffectParam(const SSetPostEffectParamVec4 *) = 0;
	virtual void EF_SetPostEffectParam(const SSetPostEffectParam *) = 0;
	virtual float EF_GetPostEffectParam(unsigned __int64) = 0;
	virtual Vec4_tpl<float> *EF_GetPostEffectParamVec4(Vec4_tpl<float> *result, unsigned __int64) = 0;
	virtual const char *EF_GetPostEffectParamString(unsigned __int64) = 0;
	virtual bool EF_IsPostEffectParam(const char *) = 0;
	virtual void EF_ResetPostEffects(bool) = 0;
	virtual void EF_DisableTemporalEffects() = 0;
	virtual void EF_AddWaterSimHit(const Vec3_tpl<float> *, const float, const float) = 0;
	virtual void EF_DrawWaterSimHits() = 0;
	virtual void ForceGC() = 0;
	virtual void GetPolyCount(int *, int *) = 0;
	virtual int GetPolyCount() = 0;
	virtual void SetClearColor(const Vec3_tpl<float> *) = 0;
	//virtual _smart_ptr<IRenderMesh> *CreateRenderMesh(_smart_ptr<IRenderMesh> *result, const char *, const char *, IRenderMesh::SInitParamerers *, ERenderMeshType) = 0;
	//virtual _smart_ptr<IRenderMesh> *CreateRenderMeshInitialized(_smart_ptr<IRenderMesh> *result, const void *, int, EVertexFormat, const unsigned __int16 *, int, const PublicRenderPrimitiveType, const char *, const char *, ERenderMeshType, int, int, bool(IRenderMesh *, bool), void *, bool, bool, const SPipTangents *, bool, Vec3_tpl<float> *) = 0;
	virtual void *CreateRenderMesh(int unfinished) = 0;
	virtual void *CreateRenderMeshInitialized(int unfinished) = 0;
	virtual int GetFrameID(bool) = 0;
	virtual void MakeMatrix(const Vec3_tpl<float> *, const Vec3_tpl<float> *, const Vec3_tpl<float> *, Matrix34_tpl<float> *) = 0;
	virtual void Draw2dText(float, float, const char *, const SDrawTextInfo *) = 0;
	virtual void DrawTextQueued(Vec3_tpl<float>, SDrawTextInfo *, const char *) = 0;
	virtual void DrawTextQueued(Vec3_tpl<float>, SDrawTextInfo *, const char *, char *) = 0;
	virtual void Draw2dTextWithDepth(float, float, float, const char *, const SDrawTextInfo *) = 0;
	virtual float ScaleCoordX(float) = 0;
	virtual float ScaleCoordY(float) = 0;
	virtual void ScaleCoord(float *, float *) = 0;
	virtual void SetState(int, int) = 0;
	virtual void SetCullMode(int) = 0;
	virtual void PushProfileMarker(char *) = 0;
	virtual void PopProfileMarker(char *) = 0;
	virtual bool EnableFog(bool) = 0;
	virtual void SetFogColor(const Color_tpl<float> *) = 0;
	virtual void SetColorOp(unsigned __int8, unsigned __int8, unsigned __int8, unsigned __int8) = 0;
	virtual void RequestFlushAllPendingTextureStreamingJobs(int) = 0;
	virtual void SetTexturesStreamingGlobalMipFactor(float) = 0;
	virtual IRenderAuxGeom *GetIRenderAuxGeom(void *) = 0;
	virtual IArkRenderPersistentAuxGeom *GetIArkRenderPersistentAuxGeom() = 0;
	virtual IColorGradingController *GetIColorGradingController() = 0;
	virtual void TextToScreen(float, float, const char *, ...) = 0;
	virtual void TextToScreenColor(int, int, float, float, float, float, const char *, ...) = 0;
	virtual void ResetToDefault() = 0;
	virtual void SetMaterialColor(float, float, float, float) = 0;
	virtual void Graph(unsigned __int8 *, int, int, int, int, int, int, char *, Color_tpl<float> *, float) = 0;
	virtual void FlushTextMessages() = 0;
	virtual void ClearTargetsImmediately(unsigned int, float) = 0;
	virtual void ClearTargetsImmediately(unsigned int, const Color_tpl<float> *) = 0;
	virtual void ClearTargetsImmediately(unsigned int, const Color_tpl<float> *, float) = 0;
	virtual void ClearTargetsImmediately(unsigned int) = 0;
	virtual void ClearTargetsLater(unsigned int, float) = 0;
	virtual void ClearTargetsLater(unsigned int, const Color_tpl<float> *) = 0;
	virtual void ClearTargetsLater(unsigned int, const Color_tpl<float> *, float) = 0;
	virtual void ClearTargetsLater(unsigned int) = 0;
	virtual void CreateResourceAsync(SResourceAsync *) = 0;
	virtual void ReleaseResourceAsync(SResourceAsync *) = 0;
	virtual unsigned int DownLoadToVideoMemory(unsigned __int8 *, int, int, ETEX_Format, ETEX_Format, int, bool, int, int, const char *, int, bool, RectI *, bool) = 0;
	virtual void UpdateTextureInVideoMemory(unsigned int, unsigned __int8 *, int, int, int, int, ETEX_Format, int, int) = 0;
	virtual void RemoveTexture(unsigned int) = 0;
	//virtual struct gpu_pfx2::IManager *GetGpuParticleManager() = 0;
	virtual void *GetGpuParticleManager() = 0; // TODO:
	virtual void RegisterSyncWithMainListener(ISyncMainWithRenderListener *) = 0;
	virtual void RemoveSyncWithMainListener(const ISyncMainWithRenderListener *) = 0;
	virtual void Set2DMode(bool, int, int, float, float) = 0;
	virtual int ScreenToTexture(int) = 0;
	virtual bool StopRendererAtFrameEnd(unsigned int) = 0;
	virtual void ResumeRendererFromFrameEnd() = 0;
	virtual void *GetHWND() = 0;
	virtual void OnEntityDeleted(IRenderNode *) = 0;
	virtual int CreateRenderTarget(int, int, const Color_tpl<float> *, ETEX_Format) = 0;
	virtual bool DestroyRenderTarget(int) = 0;
	virtual bool SetRenderTarget(int) = 0;
	virtual IOpticsElementBase *CreateOptics(EFlareType) = 0;
	virtual ISoftOcclusionQuery *CreateSoftOcclusionQuery() = 0;
	virtual void GetThreadIDs(unsigned int *, unsigned int *) = 0;
	virtual bool SF_UpdateTexture(int, int, int, const IRenderer::SUpdateRect *, unsigned __int8 *, unsigned __int64, unsigned __int64, ETEX_Format) = 0;
	virtual void SF_GetMeshMaxSize(int *, int *) = 0;
	virtual void SF_ConfigMask(IRenderer::ESFMaskOp, unsigned int) = 0;
	virtual void SF_DrawIndexedTriList(int, int, int, int, int, const SSF_GlobalDrawParams *) = 0;
	virtual void SF_DrawLineStrip(int, int, const SSF_GlobalDrawParams *) = 0;
	virtual void SF_DrawGlyphClear(const SSF_GlobalDrawParams *) = 0;
	virtual void SF_DrawBlurRect(const SSF_GlobalDrawParams *) = 0;
	virtual void SF_Flush() = 0;
	virtual int SF_CreateTexture(int, int, int, unsigned __int8 *, ETEX_Format, int) = 0;
	virtual ITexture *CreateTexture(const char *name, int width, int height, int numMips, unsigned char *pData, ETEX_Format eTF, int flags) = 0;
#if 0
	virtual const RPProfilerStats *GetRPPStats(ERenderPipelineProfilerStats, bool) = 0;
	virtual const RPProfilerStats *GetRPPStatsArray(bool) = 0;
	virtual int GetPolygonCountByType(unsigned int, EVertexCostTypes, unsigned int, bool) = 0;
	virtual void StartLoadtimeFlashPlayback(ILoadtimeCallback *) = 0;
	virtual void StopLoadtimeFlashPlayback() = 0;
	virtual void StartLoadtimeBinkPlayback(ILoadtimeCallback *) = 0;
	virtual void StopLoadtimeBinkPlayback() = 0;
	virtual unsigned __int16 PushFogVolumeContribution(const Color_tpl<float> *, const SRenderingPassInfo *) = 0;
	virtual int GetMaxTextureSize() = 0;
	virtual const char *GetTextureFormatName(ETEX_Format) = 0;
	virtual int GetTextureFormatDataSize(int, int, int, int, ETEX_Format) = 0;
	virtual void SetDefaultMaterials(IMaterial *, IMaterial *) = 0;
	virtual unsigned int GetActiveGPUCount() = 0;
	virtual ShadowFrustumMGPUCache *GetShadowFrustumMGPUCache() = 0;
	virtual const StaticArray<int, 16, int> *GetCachedShadowsResolution() = 0;
	virtual void SetCachedShadowsResolution(const StaticArray<int, 16, int> *) = 0;
	virtual void UpdateCachedShadowsLodCount(int) = 0;
	virtual void SetTexturePrecaching(bool) = 0;
	virtual void EnablePipelineProfiler(bool) = 0;
	virtual void GetRenderTimes(IRenderer::SRenderTimes *) = 0;
	virtual float GetGPUFrameTime() = 0;
	virtual void EnableBatchMode(bool) = 0;
	virtual SSkinningData *EF_CreateSkinningData(unsigned int, bool) = 0;
	virtual SSkinningData *EF_CreateRemappedSkinningData(unsigned int, SSkinningData *, unsigned int, unsigned int) = 0;
	virtual int EF_GetSkinningPoolID() = 0;
	virtual void UpdateShaderItem(SShaderItem *, IMaterial *) = 0;
	virtual void ForceUpdateShaderItem(SShaderItem *, IMaterial *) = 0;
	virtual void RefreshShaderResourceConstants(SShaderItem *, IMaterial *) = 0;
	virtual void SyncComputeVerticesJobs() = 0;
	virtual void ActivateLayer(const char *, bool) = 0;
	virtual void FlushPendingTextureTasks() = 0;
	virtual void SetShadowJittering(float) = 0;
	virtual float GetShadowJittering() = 0;
	virtual bool LoadShaderStartupCache() = 0;
	virtual void UnloadShaderStartupCache() = 0;
	virtual bool LoadShaderLevelCache() = 0;
	virtual void UnloadShaderLevelCache() = 0;
	virtual void SetRendererCVar(ICVar *, const char *, const bool) = 0;
	virtual _smart_ptr<IGraphicsDeviceConstantBuffer> *CreateGraphiceDeviceConstantBuffer(_smart_ptr<IGraphicsDeviceConstantBuffer> *result) = 0;
	virtual void EF_QueryImpl(ERenderQueryTypes, void *, unsigned int, void *, unsigned int) = 0;
	virtual void PeekWindowMessage(unsigned int, unsigned __int64, unsigned __int64) = 0;
	virtual IArkBinkManager *GetIArkBinkManager() = 0;
#endif
};