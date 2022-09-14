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

	static int GetLocalThreadCommandBufferId();

	void SyncMainWithRender() { FSyncMainWithRender(this); }
	int GetThreadList() const;
	threadID GetCurrentThreadId(bool bAlwaysCheck = false) const;
	bool IsRenderThread(bool bAlwaysCheck = false) const;
	bool IsRenderLoadingThread(bool bAlwaysCheck = false);
	bool IsMainThread(bool bAlwaysCheck = false) const;
	bool IsMultithreaded();
	int CurThreadFill() const;

	void RC_SetViewport(int x, int y, int width, int height, int id = 0);
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

	void RC_ParseShader(CShader* pSH, uint64_t nMaskGen, unsigned flags, CShaderResources* pRes) { FRC_ParseShader(this, pSH, nMaskGen, flags, pRes); }

	static inline auto FRC_ParseShader = PreyFunction<void(SRenderThread* const _this, CShader* pSH, uint64_t nMaskGen, unsigned flags, CShaderResources* pRes)>(0xFC0BB0);
	static inline auto FSyncMainWithRender = PreyFunction<void(SRenderThread* const _this)>(0xFC2FA0);
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
