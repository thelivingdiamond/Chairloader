// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

/*=============================================================================
   RenderThread.h : Render thread commands processing.

   Revision history:
* Created by Honitch Andrey

   =============================================================================*/

#ifndef __RENDERTHREAD_H__
#define __RENDERTHREAD_H__

#include <Prey/CryCore/AlignmentTools.h>
#include <Prey/CryRenderer/Tarray.h>
#include <Prey/CryRenderer/IRenderer.h>
#include "CommonRender.h"
//#include <Prey/CryCore/AlignmentTools.h>

#define RENDER_THREAD_NAME         "RenderThread"
#define RENDER_LOADING_THREAD_NAME "RenderLoadingThread"

//#include <Prey/CryThreading/IThreadManager.h>

typedef void (* RenderFunc)(void);

//====================================================================

struct IFlashPlayer;
struct IFlashPlayer_RenderProxy;
struct IRenderAuxGeomImpl;
struct SAuxGeomCBRawDataPackaged;
struct IColorGradingControllerInt;
struct SColorChartLayer;
class CRenderMesh;
struct IDynTextureSourceImpl;
struct SDynTexture;
struct STexStreamInState;
class CDeviceResourceSet;
class CShaderResources;

#if CRY_PLATFORM_ORBIS || CRY_PLATFORM_DURANGO || CRY_PLATFORM_MOBILE
	#define USE_LOCKS_FOR_FLUSH_SYNC
#endif

enum ERenderCommand
{
	eRC_Unknown = 0x0,
	eRC_Init = 0x1,
	eRC_ShutDown = 0x2,
	eRC_CreateDevice = 0x3,
	eRC_ResetDevice = 0x4,
	eRC_SuspendDevice = 0x5,
	eRC_ResumeDevice = 0x6,
	eRC_BeginFrame = 0x7,
	eRC_EndFrame = 0x8,
	eRC_ClearBuffersImmediately = 0x9,
	eRC_FlushTextMessages = 0xA,
	eRC_FlushTextureStreaming = 0xB,
	eRC_ReleaseSystemTextures = 0xC,
	eRC_PreloadTextures = 0xD,
	eRC_SwitchToNativeResolutionBackbuffer = 0xE,
	eRC_DrawLines = 0xF,
	eRC_DrawStringW = 0x10,
	eRC_UpdateTexture = 0x11,
	eRC_UpdateMesh2 = 0x12,
	eRC_ReleaseShaderResource = 0x13,
	eRC_ReleaseBaseResource = 0x14,
	eRC_ReleaseSurfaceResource = 0x15,
	eRC_ReleaseIB = 0x16,
	eRC_ReleaseVB = 0x17,
	eRC_ReleaseCB = 0x18,
	eRC_ReleaseRS = 0x19,
	eRC_CreateResource = 0x1A,
	eRC_ReleaseResource = 0x1B,
	eRC_ReleaseRenderResources = 0x1C,
	eRC_PrecacheDefaultShaders = 0x1D,
	eRC_UnbindTMUs = 0x1E,
	eRC_UnbindResources = 0x1F,
	eRC_CreateRenderResources = 0x20,
	eRC_CreateSystemTargets = 0x21,
	eRC_CreateDeviceTexture = 0x22,
	eRC_CopyDataToTexture = 0x23,
	eRC_ClearTarget = 0x24,
	eRC_CreateREPostProcess = 0x25,
	eRC_ParseShader = 0x26,
	eRC_SetShaderQuality = 0x27,
	eRC_UpdateShaderItem = 0x28,
	eRC_RefreshShaderResourceConstants = 0x29,
	eRC_DisableStreamingForTexture = 0x2A,
	eRC_ReleaseDeviceTexture = 0x2B,
	eRC_FlashRender = 0x2C,
	eRC_FlashRenderLockless = 0x2D,
	eRC_BinkRender = 0x2E,
	eRC_AuxFlush_DONOTUSE = 0x2F, // eRCC_AuxFlush
	eRC_RenderScene = 0x30,
	eRC_SetCamera = 0x31,
	eRC_PushProfileMarker = 0x32,
	eRC_PopProfileMarker = 0x33,
	eRC_PostLevelLoading = 0x34,
	eRC_SetState = 0x35,
	eRC_PushWireframeMode = 0x36,
	eRC_PopWireframeMode = 0x37,
	eRC_SetCull = 0x38,
	eRC_SetScissor = 0x39,
	eRC_DrawDynVB = 0x3A,
	eRC_Draw2dImage = 0x3B,
	eRC_Draw2dImageStretchMode = 0x3C,
	eRC_Push2dImage = 0x3D,
	eRC_Draw2dImageList = 0x3E,
	eRC_DrawImageWithUV = 0x3F,
	eRC_DynTexUpdate = 0x40,
	eRC_SetViewport = 0x41,
	eRC_UpdateMaterialConstants = 0x42,
	eRC_OC_ReadResult_Try = 0x43,
	eRC_CGCSetLayers = 0x44,
	eRC_EntityDelete = 0x45,
	eRC_ForceMeshGC = 0x46,
	eRC_DevBufferSync = 0x47,
	eRC_PrecacheTexture = 0x48,
	eRC_StartVideoThread = 0x49,
	eRC_StopVideoThread = 0x4A,
	eRC_RenderDebug = 0x4B,
	eRC_RelinkTexture = 0x4C,
	eRC_UnlinkTexture = 0x4D,
	eRC_ReleasePostEffects = 0x4E,
	eRC_ResetPostEffects = 0x4F,
	eRC_ResetPostEffectsOnSpecChange = 0x50,
	eRC_DisableTemporalEffects = 0x51,
	eRC_ResetToDefault = 0x52,
	eRC_PushSkinningPoolId = 0x53,
	eRC_ReleaseRemappedBoneIndices = 0x54,
	eRC_SetRendererCVar = 0x55,
	eRC_ReleaseGraphicsPipeline = 0x56,

	//! Chairloader: Custom rendering command
	eRC_Custom = 100,
};

enum ERenderCommandCustom
{
	eRCC_Unknown = 0,
	eRCC_AuxFlush,
};

//====================================================================

/*
class CRenderThread : public IThread
{
public:
	CryEvent m_started;

protected:
	// Start accepting work on thread
	virtual void ThreadEntry();
};

static_assert(sizeof(CRenderThread) == 72);

class CRenderThreadLoading : public CRenderThread
{
protected:
	// Start accepting work on thread
	virtual void ThreadEntry();
};

static_assert(sizeof(CRenderThreadLoading) == 72);
*/

class CRenderThread;
class CRenderThreadLoading;
class ArkBinkPlayer;
class CREOcclusionQuery;

struct CRY_ALIGN(128) SRenderThread
{
	CRenderThread* m_pThread;
	CRenderThreadLoading* m_pThreadLoading;
	ILoadtimeCallback* m_pLoadtimeCallback;
	CryCriticalSection m_rdldLock;
	bool m_bQuit;
	bool m_bQuitLoading;
	bool m_bSuccessful;
	bool m_bBeginFrameCalled;
	bool m_bEndFrameCalled;
	int m_nCurThreadProcess;
	int m_nCurThreadFill;
	volatile int m_nFlush;
	threadID m_nRenderThread;
	threadID m_nRenderThreadLoading;
	threadID m_nMainThread;
	HRESULT m_hResult;
	float m_fTimeIdleDuringLoading;
	float m_fTimeBusyDuringLoading;
	TArray<byte> m_Commands[RT_COMMAND_BUF_COUNT]; // m_nCurThreadFill shows which commands are filled by main thread

	// The below loading queue contains all commands that were submitted and require full device access during loading.
	// Will be blit into the first render frame's command queue after loading and subsequently resized to 0.
	TArray<byte> m_CommandsLoading;

	enum EVideoThreadMode
	{
		eVTM_Disabled = 0,
		eVTM_RequestStart,
		eVTM_Active,
		eVTM_RequestStop,
		eVTM_ProcessingStop,
	};
	EVideoThreadMode m_eVideoThreadMode;

	static CryCriticalSection s_rcLock;
	static TArray<byte> m_CustomCommands[RT_COMMAND_BUF_COUNT];

	SRenderThread();
	~SRenderThread();

	int GetThreadList() const;
	threadID GetCurrentThreadId(bool bAlwaysCheck = false) const;
	bool IsRenderThread(bool bAlwaysCheck = false) const;
	bool IsRenderLoadingThread(bool bAlwaysCheck = false);
	bool IsMainThread(bool bAlwaysCheck = false) const;
	bool IsMultithreaded();
	int CurThreadFill() const;

	void RC_AuxFlush(IRenderAuxGeomImpl* pAux, SAuxGeomCBRawDataPackaged& data, size_t begin, size_t end, bool reset);

	inline size_t Align4(size_t value)
	{
		return (value + 3) & ~((size_t)3);
	}

	inline byte* AddCommandTo(ERenderCommandCustom eRC, size_t nParamBytes, TArray<byte>& queue)
	{
		uint32 cmdSize = sizeof(uint32) + nParamBytes;
		byte* ptr = queue.Grow(cmdSize);
		AddDWORD(ptr, eRC);
		return ptr;
	}

	inline void EndCommandTo(byte* ptr, TArray<byte>& queue)
	{
	}

	inline byte* AddCommand(ERenderCommand eRC, size_t nParamBytes)
	{
#ifdef STRIP_RENDER_THREAD
		return NULL;
#else
		return AddCommandTo((ERenderCommandCustom)eRC, nParamBytes, m_Commands[m_nCurThreadFill]);
#endif
	}

	inline byte* AddCommand(ERenderCommandCustom eRCC, size_t nParamBytes)
	{
#ifdef STRIP_RENDER_THREAD
		return NULL;
#else
		AddCommandTo((ERenderCommandCustom)eRC_Custom, 0, m_Commands[m_nCurThreadFill]);
		return AddCommandTo(eRCC, nParamBytes, m_CustomCommands[m_nCurThreadFill]);
#endif
	}

	inline void EndCommand(byte* ptr)
	{
	}

	inline void AddDWORD(byte*& ptr, uint32 nVal)
	{
		*(uint32*)ptr = nVal;
		ptr += sizeof(uint32);
	}

	inline void AddPointer(byte*& ptr, const void* pVal)
	{
		StoreUnaligned((uint32*)ptr, pVal); // uint32 because command list maintains 4-byte alignment
		ptr += sizeof(void*);
	}

	template<class T> T ReadCommand(int& nIndex)
	{
		T Res;
		LoadUnaligned((uint32*)&m_CustomCommands[m_nCurThreadProcess][nIndex], Res);
		nIndex += (sizeof(T) + 3) & ~((size_t)3);
		return Res;
	}
	template<class T> void ReadCommand(int& nIndex, SUninitialized<T>& value)
	{
		LoadUnaligned((uint32*)&m_CustomCommands[m_nCurThreadProcess][nIndex], value);
		nIndex += (sizeof(T) + 3) & ~((size_t)3);
	}

	static int GetLocalThreadCommandBufferId() { return FGetLocalThreadCommandBufferId(); }
	void StartRenderThread() { FStartRenderThread(this); }
	void SwitchMode(bool bEnableVideo) { FSwitchMode(this, bEnableVideo); }
	void QuitRenderLoadingThread() { FQuitRenderLoadingThread(this); }
	void SyncMainWithRender() { FSyncMainWithRender(this); }
	void FlushAndWait() { FFlushAndWait(this); }
	void ProcessCommands() { FProcessCommands(this); }
	void Process() { FProcess(this); }
	//int GetThreadList() const { return FGetThreadList(this); }
	void RC_Init() { FRC_Init(this); }
	void RC_ShutDown(unsigned nFlags) { FRC_ShutDown(this, nFlags); }
	bool RC_CreateDevice() { return FRC_CreateDevice(this); }
	void RC_ResetDevice() { FRC_ResetDevice(this); }
	void RC_SuspendDevice() { FRC_SuspendDevice(this); }
	void RC_ResumeDevice() { FRC_ResumeDevice(this); }
	void RC_PreloadTextures() { FRC_PreloadTextures(this); }
	bool RC_CreateDeviceTexture(CTexture* pTex, uint8_t** pData) { return FRC_CreateDeviceTexture(this, pTex, pData); }
	void RC_ClearTarget(void* pkVoid, ColorF const& kColor) { FRC_ClearTarget(this, pkVoid, kColor); }
	void RC_CreateResource(SResourceAsync* pRes) { FRC_CreateResource(this, pRes); }
	void RC_ReleaseRenderResources(unsigned nFlags) { FRC_ReleaseRenderResources(this, nFlags); }
	void RC_PrecacheDefaultShaders() { FRC_PrecacheDefaultShaders(this); }
	void RC_UnbindResources() { FRC_UnbindResources(this); }
	void RC_UnbindTMUs() { FRC_UnbindTMUs(this); }
	void RC_CreateRenderResources() { FRC_CreateRenderResources(this); }
	void RC_CreateSystemTargets() { FRC_CreateSystemTargets(this); }
	void RC_ReleaseShaderResource(CShaderResources* pRes) { FRC_ReleaseShaderResource(this, pRes); }
	void RC_ReleaseBaseResource(CBaseResource* pRes) { FRC_ReleaseBaseResource(this, pRes); }
	void RC_ReleaseSurfaceResource(SDepthTexture* pRes) { FRC_ReleaseSurfaceResource(this, pRes); }
	void RC_ReleaseResource(SResourceAsync* pRes) { FRC_ReleaseResource(this, pRes); }
	void RC_RelinkTexture(CTexture* pTex) { FRC_RelinkTexture(this, pTex); }
	void RC_UnlinkTexture(CTexture* pTex) { FRC_UnlinkTexture(this, pTex); }
	bool RC_CheckUpdate2(CRenderMesh* pMesh, CRenderMesh* pVContainer, unsigned nStreamMask) { return FRC_CheckUpdate2(this, pMesh, pVContainer, nStreamMask); }
	void RC_ReleaseCB(void* pCB) { FRC_ReleaseCB(this, pCB); }
	void RC_ReleaseRS(std::shared_ptr<CDeviceResourceSet>& pRS) { FRC_ReleaseRS(this, pRS); }
	void RC_DrawDynVB(SVF_P3F_C4B_T2F* pBuf, uint16_t* pInds, int nVerts, int nInds, PublicRenderPrimitiveType nPrimType) { FRC_DrawDynVB(this, pBuf, pInds, nVerts, nInds, nPrimType); }
	void RC_Draw2dImage(float xpos, float ypos, float w, float h, CTexture* pTexture, float s0, float t0, float s1, float t1, float angle, float r, float g, float b, float a, float z) { FRC_Draw2dImage(this, xpos, ypos, w, h, pTexture, s0, t0, s1, t1, angle, r, g, b, a, z); }
	void RC_Draw2dImageStretchMode(bool bStretch) { FRC_Draw2dImageStretchMode(this, bStretch); }
	void RC_Push2dImage(float xpos, float ypos, float w, float h, CTexture* pTexture, float s0, float t0, float s1, float t1, float angle, float r, float g, float b, float a, float z) { FRC_Push2dImage(this, xpos, ypos, w, h, pTexture, s0, t0, s1, t1, angle, r, g, b, a, z); }
	void RC_Draw2dImageList() { FRC_Draw2dImageList(this); }
	void RC_DrawImageWithUV(float xpos, float ypos, float z, float w, float h, int textureid, float* s, float* t, float r, float g, float b, float a, bool filtered) { FRC_DrawImageWithUV(this, xpos, ypos, z, w, h, textureid, s, t, r, g, b, a, filtered); }
	void RC_UpdateTextureRegion(CTexture* pTex, uint8_t* data, int nX, int nY, int nZ, int USize, int VSize, int ZSize, ETEX_Format eTFSrc) { FRC_UpdateTextureRegion(this, pTex, data, nX, nY, nZ, USize, VSize, ZSize, eTFSrc); }
	void RC_SetState(int State, int AlphaRef) { FRC_SetState(this, State, AlphaRef); }
	void RC_PushWireframeMode(int nMode) { FRC_PushWireframeMode(this, nMode); }
	void RC_PopWireframeMode() { FRC_PopWireframeMode(this); }
	void RC_SetCull(int nMode) { FRC_SetCull(this, nMode); }
	void RC_SetScissor(bool bEnable, int sX, int sY, int sWdt, int sHgt) { FRC_SetScissor(this, bEnable, sX, sY, sWdt, sHgt); }
	void RC_PushProfileMarker(char* label) { FRC_PushProfileMarker(this, label); }
	void RC_PopProfileMarker(char* label) { FRC_PopProfileMarker(this, label); }
	void RC_DrawLines(Vec3* v, int nump, ColorF& col, int flags, float fGround) { FRC_DrawLines(this, v, nump, col, flags, fGround); }
	void RC_DrawStringW(IFFont_RenderProxy* pFont, float x, float y, float z, const wchar_t* pStr, const bool asciiMultiLine, STextDrawContext const& ctx) { FRC_DrawStringW(this, pFont, x, y, z, pStr, asciiMultiLine, ctx); }
	void RC_DisableStreamingForTexture(CTexture* _pTex) { FRC_DisableStreamingForTexture(this, _pTex); }
	void RC_ReleaseDeviceTexture(CTexture* pTexture) { FRC_ReleaseDeviceTexture(this, pTexture); }
	void RC_PrecacheResource(ITexture* pTP, float fMipFactor, float fTimeToReady, int Flags, int nUpdateId, int nCounter) { FRC_PrecacheResource(this, pTP, fMipFactor, fTimeToReady, Flags, nUpdateId, nCounter); }
	void RC_ClearTargetsImmediately(int8_t nType, unsigned nFlags, ColorF const& vColor, float depth) { FRC_ClearTargetsImmediately(this, nType, nFlags, vColor, depth); }
	void RC_FlushTextMessages() { FRC_FlushTextMessages(this); }
	void RC_FlushTextureStreaming(bool bAbort) { FRC_FlushTextureStreaming(this, bAbort); }
	void RC_ReleaseSystemTextures() { FRC_ReleaseSystemTextures(this); }
	void RC_FlashRender(IFlashPlayer_RenderProxy* pPlayer) { FRC_FlashRender(this, pPlayer); }
	void RC_FlashRenderPlaybackLockless(IFlashPlayer_RenderProxy* pPlayer, int cbIdx, bool finalPlayback) { FRC_FlashRenderPlaybackLockless(this, pPlayer, cbIdx, finalPlayback); }
	void RC_BinkRender(ArkBinkPlayer* _pPlayer, int _frame) { FRC_BinkRender(this, _pPlayer, _frame); }
	void RC_ParseShader(CShader* pSH, uint64_t nMaskGen, unsigned flags, CShaderResources* pRes) { FRC_ParseShader(this, pSH, nMaskGen, flags, pRes); }
	void RC_SetShaderQuality(EShaderType eST, EShaderQuality eSQ) { FRC_SetShaderQuality(this, eST, eSQ); }
	void RC_UpdateShaderItem(SShaderItem* pShaderItem, IMaterial* pMaterial) { FRC_UpdateShaderItem(this, pShaderItem, pMaterial); }
	void RC_RefreshShaderResourceConstants(SShaderItem* pShaderItem, IMaterial* pMaterial) { FRC_RefreshShaderResourceConstants(this, pShaderItem, pMaterial); }
	void RC_SetCamera() { FRC_SetCamera(this); }
	void RC_RenderScene(CRenderView* pRenderView, int nFlags, void (*pRenderFunc)()) { FRC_RenderScene(this, pRenderView, nFlags, pRenderFunc); }
	void RC_BeginFrame() { FRC_BeginFrame(this); }
	void RC_EndFrame(bool bWait) { FRC_EndFrame(this, bWait); }
	void RC_TryFlush() { FRC_TryFlush(this); }
	bool RC_DynTexUpdate(SDynTexture* pTex, int nNewWidth, int nNewHeight) { return FRC_DynTexUpdate(this, pTex, nNewWidth, nNewHeight); }
	void RC_SwitchToNativeResolutionBackbuffer() { FRC_SwitchToNativeResolutionBackbuffer(this); }
	void RC_StartVideoThread() { FRC_StartVideoThread(this); }
	void RC_StopVideoThread() { FRC_StopVideoThread(this); }
	void RC_PrecacheTick() { FRC_PrecacheTick(this); }
	void RC_PostLoadLevel() { FRC_PostLoadLevel(this); }
	void RC_EntityDelete(IRenderNode* pRenderNode) { FRC_EntityDelete(this, pRenderNode); }
	void RC_UpdateMaterialConstants(CShaderResources* pSR, IShader* pSH) { FRC_UpdateMaterialConstants(this, pSR, pSH); }
	bool RC_OC_ReadResult_Try(unsigned nDefaultNumSamples, CREOcclusionQuery* pRE) { return FRC_OC_ReadResult_Try(this, nDefaultNumSamples, pRE); }
	void RC_SetViewport(int x, int y, int width, int height, int id) { FRC_SetViewport(this, x, y, width, height, id); }
	void RC_ForceMeshGC(bool instant, bool wait) { FRC_ForceMeshGC(this, instant, wait); }
	void RC_DevBufferSync() { FRC_DevBufferSync(this); }
	void RC_ReleasePostEffects() { FRC_ReleasePostEffects(this); }
	void RC_ReleaseGraphicsPipeline() { FRC_ReleaseGraphicsPipeline(this); }
	void RC_ResetPostEffects(bool bOnSpecChange) { FRC_ResetPostEffects(this, bOnSpecChange); }
	void RC_DisableTemporalEffects() { FRC_DisableTemporalEffects(this); }
	void RC_ResetToDefault() { FRC_ResetToDefault(this); }
	void RC_CGCSetLayers(IColorGradingControllerInt* pController, SColorChartLayer const* pLayers, unsigned numLayers) { FRC_CGCSetLayers(this, pController, pLayers, numLayers); }
	void RC_SetRendererCVar(ICVar* pCVar, const char* pArgText, const bool bSilentMode) { FRC_SetRendererCVar(this, pCVar, pArgText, bSilentMode); }
	void RC_RenderDebug(bool bRenderStats) { FRC_RenderDebug(this, bRenderStats); }
	void RC_PushSkinningPoolId(unsigned poolId) { FRC_PushSkinningPoolId(this, poolId); }
	void RC_ReleaseRemappedBoneIndices(IRenderMesh* pRenderMesh, unsigned guid) { FRC_ReleaseRemappedBoneIndices(this, pRenderMesh, guid); }

	static inline auto FBitNotSRenderThread = PreyFunction<void(SRenderThread* const _this)>(0xFBCE60);
	static inline auto FGetLocalThreadCommandBufferId = PreyFunction<int()>(0xFBD0B0);
	static inline auto FStartRenderThread = PreyFunction<void(SRenderThread* const _this)>(0xFC2DB0);
	static inline auto FSwitchMode = PreyFunction<void(SRenderThread* const _this, bool bEnableVideo)>(0xFC2E30);
	static inline auto FQuitRenderLoadingThread = PreyFunction<void(SRenderThread* const _this)>(0xFBF600);
	static inline auto FSyncMainWithRender = PreyFunction<void(SRenderThread* const _this)>(0xFC2FA0);
	static inline auto FFlushAndWait = PreyFunction<void(SRenderThread* const _this)>(0xFBCFA0);
	static inline auto FProcessCommands = PreyFunction<void(SRenderThread* const _this)>(0xFBD460);
	static inline auto FProcess = PreyFunction<void(SRenderThread* const _this)>(0xFBD0D0);
	static inline auto FGetThreadList = PreyFunction<int(SRenderThread const* const _this)>(0xFB9120);
	static inline auto FRC_Init = PreyFunction<void(SRenderThread* const _this)>(0xFC0AA0);
	static inline auto FRC_ShutDown = PreyFunction<void(SRenderThread* const _this, unsigned nFlags)>(0xFC2390);
	static inline auto FRC_CreateDevice = PreyFunction<bool(SRenderThread* const _this)>(0xFBFB00);
	static inline auto FRC_ResetDevice = PreyFunction<void(SRenderThread* const _this)>(0xFC1DC0);
	static inline auto FRC_SuspendDevice = PreyFunction<void(SRenderThread* const _this)>(0xA13080);
	static inline auto FRC_ResumeDevice = PreyFunction<void(SRenderThread* const _this)>(0xA13080);
	static inline auto FRC_PreloadTextures = PreyFunction<void(SRenderThread* const _this)>(0xFC0F90);
	static inline auto FRC_CreateDeviceTexture = PreyFunction<bool(SRenderThread* const _this, CTexture* pTex, uint8_t** pData)>(0xFBFB20);
	static inline auto FRC_ClearTarget = PreyFunction<void(SRenderThread* const _this, void* pkVoid, ColorF const& kColor)>(0xFBF910);
	static inline auto FRC_CreateResource = PreyFunction<void(SRenderThread* const _this, SResourceAsync* pRes)>(0xFBFB90);
	static inline auto FRC_ReleaseRenderResources = PreyFunction<void(SRenderThread* const _this, unsigned nFlags)>(0xFC18D0);
	static inline auto FRC_PrecacheDefaultShaders = PreyFunction<void(SRenderThread* const _this)>(0xFC0DD0);
	static inline auto FRC_UnbindResources = PreyFunction<void(SRenderThread* const _this)>(0xFC25B0);
	static inline auto FRC_UnbindTMUs = PreyFunction<void(SRenderThread* const _this)>(0xFC2610);
	static inline auto FRC_CreateRenderResources = PreyFunction<void(SRenderThread* const _this)>(0xFBFB30);
	static inline auto FRC_CreateSystemTargets = PreyFunction<void(SRenderThread* const _this)>(0xFBFC10);
	static inline auto FRC_ReleaseShaderResource = PreyFunction<void(SRenderThread* const _this, CShaderResources* pRes)>(0xFC19D0);
	static inline auto FRC_ReleaseBaseResource = PreyFunction<void(SRenderThread* const _this, CBaseResource* pRes)>(0xFC1460);
	static inline auto FRC_ReleaseSurfaceResource = PreyFunction<void(SRenderThread* const _this, SDepthTexture* pRes)>(0xFC1A90);
	static inline auto FRC_ReleaseResource = PreyFunction<void(SRenderThread* const _this, SResourceAsync* pRes)>(0xFC1950);
	static inline auto FRC_RelinkTexture = PreyFunction<void(SRenderThread* const _this, CTexture* pTex)>(0xFC1B60);
	static inline auto FRC_UnlinkTexture = PreyFunction<void(SRenderThread* const _this, CTexture* pTex)>(0xFC2670);
	static inline auto FRC_CheckUpdate2 = PreyFunction<bool(SRenderThread* const _this, CRenderMesh* pMesh, CRenderMesh* pVContainer, unsigned nStreamMask)>(0xFBF840);
	static inline auto FRC_ReleaseCB = PreyFunction<void(SRenderThread* const _this, void* pCB)>(0xFC1520);
	static inline auto FRC_ReleaseRS = PreyFunction<void(SRenderThread* const _this, std::shared_ptr<CDeviceResourceSet>& pRS)>(0xFC1780);
	static inline auto FRC_DrawDynVB = PreyFunction<void(SRenderThread* const _this, SVF_P3F_C4B_T2F* pBuf, uint16_t* pInds, int nVerts, int nInds, PublicRenderPrimitiveType nPrimType)>(0xFC00D0);
	static inline auto FRC_Draw2dImage = PreyFunction<void(SRenderThread* const _this, float xpos, float ypos, float w, float h, CTexture* pTexture, float s0, float t0, float s1, float t1, float angle, float r, float g, float b, float a, float z)>(0xFBFDE0);
	static inline auto FRC_Draw2dImageStretchMode = PreyFunction<void(SRenderThread* const _this, bool bStretch)>(0xFC0050);
	static inline auto FRC_Push2dImage = PreyFunction<void(SRenderThread* const _this, float xpos, float ypos, float w, float h, CTexture* pTexture, float s0, float t0, float s1, float t1, float angle, float r, float g, float b, float a, float z)>(0xFC1020);
	static inline auto FRC_Draw2dImageList = PreyFunction<void(SRenderThread* const _this)>(0xFBFFF0);
	static inline auto FRC_DrawImageWithUV = PreyFunction<void(SRenderThread* const _this, float xpos, float ypos, float z, float w, float h, int textureid, float* s, float* t, float r, float g, float b, float a, bool filtered)>(0xFC01F0);
	static inline auto FRC_UpdateTextureRegion = PreyFunction<void(SRenderThread* const _this, CTexture* pTex, uint8_t* data, int nX, int nY, int nZ, int USize, int VSize, int ZSize, ETEX_Format eTFSrc)>(0xFC28B0);
	static inline auto FRC_SetState = PreyFunction<void(SRenderThread* const _this, int State, int AlphaRef)>(0xFC2250);
	static inline auto FRC_PushWireframeMode = PreyFunction<void(SRenderThread* const _this, int nMode)>(0xFC1320);
	static inline auto FRC_PopWireframeMode = PreyFunction<void(SRenderThread* const _this)>(0xFC0D10);
	static inline auto FRC_SetCull = PreyFunction<void(SRenderThread* const _this, int nMode)>(0xFC1F90);
	static inline auto FRC_SetScissor = PreyFunction<void(SRenderThread* const _this, bool bEnable, int sX, int sY, int sWdt, int sHgt)>(0xFC2100);
	static inline auto FRC_PushProfileMarker = PreyFunction<void(SRenderThread* const _this, char* label)>(0xFC1220);
	static inline auto FRC_PopProfileMarker = PreyFunction<void(SRenderThread* const _this, char* label)>(0xFC0C80);
	static inline auto FRC_DrawLines = PreyFunction<void(SRenderThread* const _this, Vec3* v, int nump, ColorF& col, int flags, float fGround)>(0xFC03D0);
	static inline auto FRC_DrawStringW = PreyFunction<void(SRenderThread* const _this, IFFont_RenderProxy* pFont, float x, float y, float z, const wchar_t* pStr, const bool asciiMultiLine, STextDrawContext const& ctx)>(0xFC04D0);
	static inline auto FRC_DisableStreamingForTexture = PreyFunction<void(SRenderThread* const _this, CTexture* _pTex)>(0xFBFCE0);
	static inline auto FRC_ReleaseDeviceTexture = PreyFunction<void(SRenderThread* const _this, CTexture* pTexture)>(0xFC15E0);
	static inline auto FRC_PrecacheResource = PreyFunction<void(SRenderThread* const _this, ITexture* pTP, float fMipFactor, float fTimeToReady, int Flags, int nUpdateId, int nCounter)>(0xFC0E30);
	static inline auto FRC_ClearTargetsImmediately = PreyFunction<void(SRenderThread* const _this, int8_t nType, unsigned nFlags, ColorF const& vColor, float depth)>(0xFBF9E0);
	static inline auto FRC_FlushTextMessages = PreyFunction<void(SRenderThread* const _this)>(0xFC0910);
	static inline auto FRC_FlushTextureStreaming = PreyFunction<void(SRenderThread* const _this, bool bAbort)>(0xFC0970);
	static inline auto FRC_ReleaseSystemTextures = PreyFunction<void(SRenderThread* const _this)>(0xFC1B00);
	static inline auto FRC_FlashRender = PreyFunction<void(SRenderThread* const _this, IFlashPlayer_RenderProxy* pPlayer)>(0xFC07F0);
	static inline auto FRC_FlashRenderPlaybackLockless = PreyFunction<void(SRenderThread* const _this, IFlashPlayer_RenderProxy* pPlayer, int cbIdx, bool finalPlayback)>(0xFC0870);
	static inline auto FRC_BinkRender = PreyFunction<void(SRenderThread* const _this, ArkBinkPlayer* _pPlayer, int _frame)>(0xFBF6F0);
	static inline auto FRC_ParseShader = PreyFunction<void(SRenderThread* const _this, CShader* pSH, uint64_t nMaskGen, unsigned flags, CShaderResources* pRes)>(0xFC0BB0);
	static inline auto FRC_SetShaderQuality = PreyFunction<void(SRenderThread* const _this, EShaderType eST, EShaderQuality eSQ)>(0xFC21C0);
	static inline auto FRC_UpdateShaderItem = PreyFunction<void(SRenderThread* const _this, SShaderItem* pShaderItem, IMaterial* pMaterial)>(0xFC27F0);
	static inline auto FRC_RefreshShaderResourceConstants = PreyFunction<void(SRenderThread* const _this, SShaderItem* pShaderItem, IMaterial* pMaterial)>(0xFC13A0);
	static inline auto FRC_SetCamera = PreyFunction<void(SRenderThread* const _this)>(0xFC1EF0);
	static inline auto FRC_RenderScene = PreyFunction<void(SRenderThread* const _this, CRenderView* pRenderView, int nFlags, void (*pRenderFunc)())>(0xFC1C60);
	static inline auto FRC_BeginFrame = PreyFunction<void(SRenderThread* const _this)>(0xFBF690);
	static inline auto FRC_EndFrame = PreyFunction<void(SRenderThread* const _this, bool bWait)>(0xFC06D0);
	static inline auto FRC_TryFlush = PreyFunction<void(SRenderThread* const _this)>(0xFC2550);
	static inline auto FRC_DynTexUpdate = PreyFunction<bool(SRenderThread* const _this, SDynTexture* pTex, int nNewWidth, int nNewHeight)>(0xFC0640);
	static inline auto FRC_SwitchToNativeResolutionBackbuffer = PreyFunction<void(SRenderThread* const _this)>(0xFC2490);
	static inline auto FRC_StartVideoThread = PreyFunction<void(SRenderThread* const _this)>(0xFC2430);
	static inline auto FRC_StopVideoThread = PreyFunction<void(SRenderThread* const _this)>(0xFC2460);
	static inline auto FRC_PrecacheTick = PreyFunction<void(SRenderThread* const _this)>(0xFC0F20);
	static inline auto FRC_PostLoadLevel = PreyFunction<void(SRenderThread* const _this)>(0xFC0D70);
	static inline auto FRC_EntityDelete = PreyFunction<void(SRenderThread* const _this, IRenderNode* pRenderNode)>(0xFC0780);
	static inline auto FRC_UpdateMaterialConstants = PreyFunction<void(SRenderThread* const _this, CShaderResources* pSR, IShader* pSH)>(0xFC26F0);
	static inline auto FRC_OC_ReadResult_Try = PreyFunction<bool(SRenderThread* const _this, unsigned nDefaultNumSamples, CREOcclusionQuery* pRE)>(0xFC0B30);
	static inline auto FRC_SetViewport = PreyFunction<void(SRenderThread* const _this, int x, int y, int width, int height, int id)>(0xFC22E0);
	static inline auto FRC_ForceMeshGC = PreyFunction<void(SRenderThread* const _this, bool instant, bool wait)>(0xFC0A00);
	static inline auto FRC_DevBufferSync = PreyFunction<void(SRenderThread* const _this)>(0xFBFC60);
	static inline auto FRC_ReleasePostEffects = PreyFunction<void(SRenderThread* const _this)>(0xFC1710);
	static inline auto FRC_ReleaseGraphicsPipeline = PreyFunction<void(SRenderThread* const _this)>(0xFC16B0);
	static inline auto FRC_ResetPostEffects = PreyFunction<void(SRenderThread* const _this, bool bOnSpecChange)>(0xFC1DE0);
	static inline auto FRC_DisableTemporalEffects = PreyFunction<void(SRenderThread* const _this)>(0xFBFD80);
	static inline auto FRC_ResetToDefault = PreyFunction<void(SRenderThread* const _this)>(0xFC1E90);
	static inline auto FRC_CGCSetLayers = PreyFunction<void(SRenderThread* const _this, IColorGradingControllerInt* pController, SColorChartLayer const* pLayers, unsigned numLayers)>(0xFBF780);
	static inline auto FRC_SetRendererCVar = PreyFunction<void(SRenderThread* const _this, ICVar* pCVar, const char* pArgText, const bool bSilentMode)>(0xFC2010);
	static inline auto FRC_RenderDebug = PreyFunction<void(SRenderThread* const _this, bool bRenderStats)>(0xFC1BE0);
	static inline auto FRC_PushSkinningPoolId = PreyFunction<void(SRenderThread* const _this, unsigned poolId)>(0xFC12B0);
	static inline auto FRC_ReleaseRemappedBoneIndices = PreyFunction<void(SRenderThread* const _this, IRenderMesh* pRenderMesh, unsigned guid)>(0xFC1840);
};

static_assert(sizeof(SRenderThread) == 256);

inline threadID SRenderThread::GetCurrentThreadId(bool bAlwaysCheck) const
{
#ifdef STRIP_RENDER_THREAD
	return m_nRenderThread;
#else
	if (!bAlwaysCheck && m_nRenderThread == m_nMainThread)
		return m_nRenderThread;
	return ::GetCurrentThreadId();
#endif
}

inline int SRenderThread::GetThreadList() const
{
#ifdef STRIP_RENDER_THREAD
	return m_nCurThreadFill;
#else
	if (IsRenderThread()) return m_nCurThreadProcess;

	return m_nCurThreadFill;
#endif
}

inline bool SRenderThread::IsRenderThread(bool bAlwaysCheck) const
{
#ifdef STRIP_RENDER_THREAD
	return true;
#else
	threadID d = this->GetCurrentThreadId(bAlwaysCheck);
	if (d == m_nRenderThreadLoading || d == m_nRenderThread)
		return true;
	return false;
#endif
}

inline bool SRenderThread::IsRenderLoadingThread(bool bAlwaysCheck)
{
#ifdef STRIP_RENDER_THREAD
	return false;
#else
	threadID d = this->GetCurrentThreadId(bAlwaysCheck);
	if (d == m_nRenderThreadLoading)
		return true;
	return false;
#endif
}

inline bool SRenderThread::IsMainThread(bool bAlwaysCheck) const
{
#ifdef STRIP_RENDER_THREAD
	return false;
#else
	threadID d = this->GetCurrentThreadId(bAlwaysCheck);
	if (d == m_nMainThread)
		return true;
	return false;
#endif
}

inline bool SRenderThread::IsMultithreaded()
{
#ifdef STRIP_RENDER_THREAD
	return false;
#else
	return m_pThread != NULL;
#endif
}

inline int SRenderThread::CurThreadFill() const
{
#ifdef STRIP_RENDER_THREAD
	return 0;
#else
	return m_nCurThreadFill;
#endif
}

#ifdef STRIP_RENDER_THREAD
inline void SRenderThread::FlushAndWait()
{
	return;
}
#endif

#endif  // __RENDERTHREAD_H__
