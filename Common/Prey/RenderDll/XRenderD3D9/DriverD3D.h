// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

# pragma once 

#include <Prey/CryCore/Containers/intrusive_list.hpp>
#include <Prey/CryMath/Cry_XOptimise.h>
//#include <Prey/CrySystem/IWindowMessageHandler.h>
#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CryRenderer/CryDX.h>
#include "../Common/CommonRender.h"

//#include <Prey/CrySystem/Profilers/FrameProfiler/FrameProfiler_JobSystem.h>  // to be removed

# if !defined(_RELEASE)
# define ENABLE_CONTEXT_THREAD_CHECKING 0
# endif

# if !defined(ENABLE_CONTEXT_THREAD_CHECKING)
# define ENABLE_CONTEXT_THREAD_CHECKING 0
# endif

/*
===========================================
The DXRenderer interface Class
===========================================
*/

inline int _VertBufferSize(D3DVertexBuffer *pVB)
{
  if (!pVB)
    return 0;
  D3D11_BUFFER_DESC Desc;
  pVB->GetDesc(&Desc);
  return Desc.ByteWidth;
}
inline int _IndexBufferSize(D3DIndexBuffer *pIB)
{
  if (!pIB)
    return 0;
  D3D11_BUFFER_DESC Desc;
  pIB->GetDesc(&Desc);
  return Desc.ByteWidth;
}

#define VERSION_D3D 2.0

struct SPixFormat;
struct SGraphicsPipelinePassContext;

/*
#include "D3DRenderAuxGeom.h"
#include "D3DColorGradingController.h"
#include "D3DStereo.h"
#include "ShadowTextureGroupManager.h"		// CShadowTextureGroupManager
#include "GraphicsPipeline/StandardGraphicsPipeline.h"
#include "D3DDeferredShading.h"
#include "D3DTiledShading.h"
#include "D3DVolumetricFog.h"
#include "PipelineProfiler.h"
#include "D3DDebug.h"
#include "DeviceInfo.h"
#include "../Scaleform/ScaleformPlayback.h"
#include <memory>
#include "Common/RenderView.h"
#include "../Scaleform/ScaleformRender.h"
*/
#include <Prey/RenderDll/Common/CryDeviceWrapper.h>
#include <Prey/RenderDll/Common/Renderer.h>
#include "../Common/OcclQuery.h"
#include "../Common/Textures/Texture.h"
#include "../Common/RenderAuxGeom.h"
#include "DeviceInfo.h"
#include "arkd3dvideoinfo.h"
#include "ShadowTextureGroupManager.h"

inline DWORD FLOATtoDWORD( float f )
{
  union FLOATDWORD
  {
    float f;
    DWORD dw;
  };

  FLOATDWORD val;
  val.f = f;
  return val.dw;
}

//=====================================================

struct STexFiller;

#define BUFFERED_VERTS 256

struct SD3DContext
{
  HWND m_hWnd;
  int m_X;
  int m_Y;
	// Real offscreen target width for rendering
  int m_Width;
	// Real offscreen target height for rendering
  int m_Height;
	// Swap-chain and it's back-buffers
	DXGISwapChain*                      m_pSwapChain;
	std::vector<_smart_ptr<D3DSurface> > m_pBackBuffers;
	// Currently active back-buffer
	D3DSurface*  m_pBackBuffer;
	unsigned int m_pCurrentBackBufferIndex;
	// Width of viewport on screen to display rendered content in
	int m_nViewportWidth;
	// Height of viewport on screen to display rendered content in
	int m_nViewportHeight;
	// Number of samples per output (real offscreen) pixel used in X
	int m_nSSSamplesX;
	// Number of samples per output (real offscreen) pixel used in Y
	int m_nSSSamplesY;
	// Denotes if context refers to main viewport
	bool m_bMainViewport;
};

#define D3DAPPERR_NODIRECT3D          0x82000001
#define D3DAPPERR_NOWINDOW            0x82000002
#define D3DAPPERR_NOCOMPATIBLEDEVICES 0x82000003
#define D3DAPPERR_NOWINDOWABLEDEVICES 0x82000004
#define D3DAPPERR_NOHARDWAREDEVICE    0x82000005
#define D3DAPPERR_HALNOTCOMPATIBLE    0x82000006
#define D3DAPPERR_NOWINDOWEDHAL       0x82000007
#define D3DAPPERR_NODESKTOPHAL        0x82000008
#define D3DAPPERR_NOHALTHISMODE       0x82000009
#define D3DAPPERR_NONZEROREFCOUNT     0x8200000a
#define D3DAPPERR_MEDIANOTFOUND       0x8200000b
#define D3DAPPERR_RESIZEFAILED        0x8200000c

const float g_fEyeAdaptionLowerPercent = 0.05f;	// 5% percentil
const float g_fEyeAdaptionMidPercent = 0.5f;		// 50% percentil
const float g_fEyeAdaptionUpperPercent = 0.95f;	// 95% percentil

// Texture coordinate rectangle
struct CoordRect
{
  float fLeftU, fTopV;
  float fRightU, fBottomV;
};

//HRESULT GetTextureCoords(CTexture *pTexSrc, RECT* pRectSrc, CTexture *pTexDest, RECT* pRectDest, CoordRect* pCoords);
bool DrawFullScreenQuad(float fLeftU, float fTopV, float fRightU, float fBottomV, bool bClampToScreenRes = true);
bool DrawFullScreenQuad(CoordRect c, bool bClampToScreenRes = true);

struct CRY_ALIGN(16) SStateBlend
{
	uint64 nHashVal;
  D3D11_BLEND_DESC Desc;
  ID3D11BlendState* pState;

	SStateBlend()
	{
		memset(this, 0, sizeof(*this));
	}

  static uint64 GetHash(const D3D11_BLEND_DESC& InDesc)
  {
		uint32 hashLow = InDesc.AlphaToCoverageEnable |
                (InDesc.RenderTarget[0].BlendEnable<<1) | (InDesc.RenderTarget[1].BlendEnable<<2) | (InDesc.RenderTarget[2].BlendEnable<<3) | (InDesc.RenderTarget[3].BlendEnable<<4) |
                (InDesc.RenderTarget[0].SrcBlend<<5) | (InDesc.RenderTarget[0].DestBlend<<10) | 
                (InDesc.RenderTarget[0].SrcBlendAlpha<<15) | (InDesc.RenderTarget[0].DestBlendAlpha<<20) | 
                (InDesc.RenderTarget[0].BlendOp<<25) | (InDesc.RenderTarget[0].BlendOpAlpha<<28);
		uint32 hashHigh = InDesc.RenderTarget[0].RenderTargetWriteMask |
									(InDesc.RenderTarget[1].RenderTargetWriteMask<<4) | 
									(InDesc.RenderTarget[2].RenderTargetWriteMask<<8) | 
									(InDesc.RenderTarget[3].RenderTargetWriteMask<<12) | 
		  (InDesc.IndependentBlendEnable << 16);

		return (((uint64)hashHigh) << 32) | ((uint64)hashLow);
  }
};

struct CRY_ALIGN(16) SStateRaster
{
  uint64 nValuesHash;
  uint32 nHashVal;
  ID3D11RasterizerState* pState;
  D3D11_RASTERIZER_DESC Desc;

	SStateRaster()
	{
    memset(this, 0, sizeof(*this)); 
    Desc.DepthClipEnable = true;
		Desc.FillMode = D3D11_FILL_SOLID;
		Desc.FrontCounterClockwise = TRUE;
  }

  static uint32 GetHash(const D3D11_RASTERIZER_DESC& InDesc)
  {
    uint32 nHash;
    nHash =      InDesc.FillMode | (InDesc.CullMode<<2) |
                (InDesc.DepthClipEnable<<4) | (InDesc.FrontCounterClockwise<<5) | 
                (InDesc.ScissorEnable<<6) | (InDesc.MultisampleEnable<<7) | (InDesc.AntialiasedLineEnable<<8) |
                (InDesc.DepthBias<<9);
    return nHash;
  }

  static uint64 GetValuesHash(const D3D11_RASTERIZER_DESC& InDesc)
  {
    uint64 nHash;
		//avoid breaking strict alising rules
		union f32_u
		{
			float floatVal;
			unsigned int uintVal;
		};
		f32_u uDepthBiasClamp;
		uDepthBiasClamp.floatVal = InDesc.DepthBiasClamp;
		f32_u uSlopeScaledDepthBias;
		uSlopeScaledDepthBias.floatVal = InDesc.SlopeScaledDepthBias;
    nHash = ( ( (uint64)uDepthBiasClamp.uintVal ) | 
              ( (uint64)uSlopeScaledDepthBias.uintVal) << 32 );
    return nHash;
  }

};
inline uint32 sStencilState(const D3D11_DEPTH_STENCILOP_DESC& Desc)
{
  uint32 nST = (Desc.StencilFailOp<<0) | 
               (Desc.StencilDepthFailOp<<4) |
               (Desc.StencilPassOp<<8) |
               (Desc.StencilFunc<<12);
  return nST;
}
struct CRY_ALIGN(16) SStateDepth
{
  uint64 nHashVal;
  D3D11_DEPTH_STENCIL_DESC Desc;
  ID3D11DepthStencilState* pState;
  SStateDepth(): nHashVal(), pState()
  {
	  Desc.DepthEnable      = TRUE;
	  Desc.DepthWriteMask   = D3D11_DEPTH_WRITE_MASK_ALL;
	  Desc.DepthFunc        = D3D11_COMPARISON_LESS;
	  Desc.StencilEnable    = FALSE;
	  Desc.StencilReadMask  = D3D11_DEFAULT_STENCIL_READ_MASK;
	  Desc.StencilWriteMask = D3D11_DEFAULT_STENCIL_WRITE_MASK;
		
	  Desc.FrontFace.StencilFailOp      = D3D11_STENCIL_OP_KEEP;
	  Desc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	  Desc.FrontFace.StencilPassOp      = D3D11_STENCIL_OP_KEEP;
	  Desc.FrontFace.StencilFunc        = D3D11_COMPARISON_ALWAYS;

	  Desc.BackFace = Desc.FrontFace;
  }

  static uint64 GetHash(const D3D11_DEPTH_STENCIL_DESC& InDesc)
  {
    uint64 nHash;
    nHash = (InDesc.DepthEnable<<0) | 
						(InDesc.DepthWriteMask<<1) |
            (InDesc.DepthFunc<<2) | 
						(InDesc.StencilEnable<<6) |
						(InDesc.StencilReadMask<<7) | 
						(InDesc.StencilWriteMask<<15) |
            (((uint64)sStencilState(InDesc.FrontFace))<<23) |
            (((uint64)sStencilState(InDesc.BackFace))<<39);
    return nHash;
  }
};

#define MAX_OCCL_QUERIES    4096

#define MAXFRAMECAPTURECALLBACK 1

//======================================================================
// Options for clearing

#define CLEAR_ZBUFFER           0x00000001l  /* Clear target z buffer, equals D3D11_CLEAR_DEPTH */
#define CLEAR_STENCIL           0x00000002l  /* Clear stencil planes, equals D3D11_CLEAR_STENCIL */
#define CLEAR_RTARGET           0x00000004l  /* Clear target surface */

//======================================================================
/// Forward declared classes

struct IStatoscopeDataGroup;
class CVolumetricCloudManager;
namespace gpu_pfx2 {
	class CManager;
}

#ifdef ENABLE_BENCHMARK_SENSOR
namespace BenchmarkFramework
{
	class IBenchmarkRendererSensor;
};
#endif
//======================================================================
/// Direct3D Render driver class

#ifdef SHADER_ASYNC_COMPILATION
class CAsyncShaderTask;
#endif

class CD3D9Renderer;
class CColorGradingControllerD3D;
class CRenderPipelineProfiler;
class CStandardGraphicsPipeline;
class CTiledShading;
struct SSF_ResourcesD3D;

class CArkRenderPersistentAuxGeom_Null
{
	void* pad;
};

class CFrameTimestamps
{
	void* pad[104 / sizeof(void*)];
};

class CD3D9Renderer : public CRenderer
{
	friend struct SPixFormat;
	friend class CD3DStereoRenderer;
	friend class CTexture;
	friend class CShadowMapStage;
	friend class CSceneRenderPass;
	friend struct IScaleformPlayback;
	friend class CScaleformPlayback;

public:
	enum class EDefShadows_Passes
	{
		DS_SHADOW_CULL_PASS = 0,
		DS_PASS_MAX = 1,
	};

	struct S2DImage // Id=8010A9D Size=64
	{
		CTexture* pTex;
		CTexture* pTarget;
		float xpos;
		float ypos;
		float w;
		float h;
		float s0;
		float t0;
		float s1;
		float t1;
		float angle;
		float z;
		unsigned long col;
	};

	struct SCharacterInstanceCB // Id=8010A9E Size=40
	{
		_smart_ptr<CConstantBuffer> boneTransformsBuffer;
		SSkinningData* m_pSD;
		util::list<SCharacterInstanceCB> list;
		bool updated;
	};

	struct SRenderTargetStack // Id=8010AA1 Size=72
	{
		ID3D11RenderTargetView* m_pTarget;
		ID3D11DepthStencilView* m_pDepth;
		CTexture* m_pTex;
		SDepthTexture* m_pSurfDepth;
		int m_Width;
		int m_Height;
		unsigned m_bNeedReleaseRT : 1;
		unsigned m_bWasSetRT : 1;
		unsigned m_bWasSetD : 1;
		unsigned m_bScreenVP : 1;
		unsigned m_ClearFlags;
		ColorF m_ReqColor;
		float m_fReqDepth;
		uint8_t m_nReqStencil;
	};

	struct SGammaRamp // Id=8010AA2 Size=1536
	{
		uint16_t red[256];
		uint16_t green[256];
		uint16_t blue[256];
	};

	TArray<COcclusionQuery> m_OcclQueries;
	unsigned m_OcclQueriesUsed;
	unsigned long m_DeviceOwningthreadID;
	volatile int m_nAsyncDeviceState;
	ID3D11InputLayout* m_pLastVDeclaration;
	DXGI_SURFACE_DESC m_d3dsdBackBuffer;
	DXGI_FORMAT m_ZFormat;
	D3D_PRIMITIVE_TOPOLOGY m_CurTopology;
	TArray<SStateBlend> m_StatesBL;
	TArray<SStateRaster> m_StatesRS;
	TArray<SStateDepth> m_StatesDP;
	unsigned m_nCurStateBL;
	unsigned m_nCurStateRS;
	unsigned m_nCurStateDP;
	uint8_t m_nCurStencRef;
	SDepthTexture m_DepthBufferOrig;
	SDepthTexture m_DepthBufferOrigMSAA;
	SDepthTexture m_DepthBufferNative;
	Vec4 m_vSceneLuminanceInfo;
	float m_fScotopicSceneScale;
	float m_fAdaptedSceneScale;
	float m_fAdaptedSceneScaleLBuffer;
	ETEX_Format m_HDR_FloatFormat_Scalar;
	ETEX_Format m_HDR_FloatFormat;
	int m_MaxAnisotropyLevel;
	int m_nMaterialAnisoHighSampler;
	int m_nMaterialAnisoLowSampler;
	int m_nMaterialAnisoSamplerBorder;
	int m_nPointWrapSampler;
	int m_nPointClampSampler;
	int m_nLinearClampComparisonSampler;
	int m_nBilinearWrapSampler;
	int m_nBilinearClampSampler;
	int m_nBilinearBorderSampler;
	int m_nTrilinearWrapSampler;
	int m_nTrilinearClampSampler;
	int m_nTrilinearBorderSampler;

	enum
	{
		kUnitObjectIndexSizeof = 2,
	};

	ID3D11Buffer* m_pUnitFrustumVB[5];
	ID3D11Buffer* m_pUnitFrustumIB[5];
	int m_UnitFrustVBSize[5];
	int m_UnitFrustIBSize[5];
	ID3D11Buffer* m_pQuadVB;
	int16_t m_nQuadVBSize;
	SPixFormatSupport m_hwTexFormatSupport;
	uint8_t m_GammmaTable[256];
	int m_fontBlendMode;
	CCryNameTSCRC m_LevelShaderCacheMissIcon;
	CColorGradingControllerD3D* m_pColorGradingControllerD3D;
	CRenderPipelineProfiler* m_pPipelineProfiler;
	Matrix44 m_matPsmWarp;
	Matrix44 m_matViewInv;
	int m_MatDepth;
	string m_Description;
	EFullscreenMode m_fullscreenMode;
	TArray<SD3DContext*> m_RContexts;
	SD3DContext* m_CurrContext;
	TArray<CTexture*> m_RTargets;
	int16_t m_nPrepareShadowFrame;
	static constexpr const int MAX_RT_STACK = 8;
	static constexpr const int RT_STACK_WIDTH = 4;
	int m_nRTStackLevel[4];
	CD3D9Renderer::SRenderTargetStack m_RTStack[4][8];
	int m_nMaxRT2Commit;
	CD3D9Renderer::SRenderTargetStack* m_pNewTarget[4];
	CTexture* m_pCurTarget[4];
	TArray<SDepthTexture*> m_TempDepths;

	enum
	{
		MAX_WIREFRAME_STACK = 10,
	};

	int m_arrWireFrameStack[10];
	int m_nWireFrameStack;
	bool m_bDepthBoundsEnabled;
	float m_fDepthBoundsMin;
	float m_fDepthBoundsMax;
	int m_scissorPrevX;
	int m_scissorPrevY;
	int m_scissorPrevWidth;
	int m_scissorPrevHeight;
	bool m_bScissorPrev;
	char m_WinTitle[80];
	HINSTANCE__* m_hInst;
	HWND__* m_hWnd;
	HWND__* m_hWndDesktop;
	unsigned m_frameFenceCounter;
	unsigned m_completedFrameFenceCounter;
	uint64_t m_frameFences[2];
	int m_bDraw2dImageStretchMode;
	int m_nPointState;
	unsigned m_uLastBlendFlagsPassGroup;
	unsigned long m_FenceOcclusionReady;
	unsigned long m_PrevFenceOcclusionReady;
	int m_numOcclusionDownsampleStages;
	uint16_t m_occlusionDownsampleSizeX;
	uint16_t m_occlusionDownsampleSizeY;
	uint16_t m_occlusionRequestedSizeX;
	uint16_t m_occlusionRequestedSizeY;
	uint16_t m_occlusionSourceSizeX;
	uint16_t m_occlusionSourceSizeY;
	std::vector<float> m_occlusionZBuffer;
	Matrix44A m_occlusionViewProjBuffer[4];
	Matrix44A m_occlusionViewProj;
	uint64_t m_occlusionBuffer;
	bool m_bOcclusionTexturesValid;
	CStandardGraphicsPipeline* m_pGraphicsPipeline;
	CTiledShading* m_pTiledShading;
	CVolumetricCloudManager* m_pVolumetricCloudMan;
	std::vector<_smart_ptr<ID3D11RenderTargetView>> m_pBackBuffers;
	ID3D11RenderTargetView* m_pBackBuffer;
	unsigned m_pCurrentBackBufferIndex;
	CTexture* m_pBackBufferTexture;
	CTexture* m_pZTexture;
	CTexture* m_pZTextureMSAA;
	CTexture* m_pNativeZTexture;
	volatile int m_lockCharCB;
	util::list<CD3D9Renderer::SCharacterInstanceCB> m_CharCBFreeList;
	util::list<CD3D9Renderer::SCharacterInstanceCB> m_CharCBActiveList[3];
	volatile int m_CharCBFrameRequired[3];
	volatile int m_CharCBAllocated;
	IDXGISwapChain* m_pSwapChain;

	enum PresentStatus
	{
		epsOccluded = 1,
		epsNonExclusive = 2,
	};

	unsigned long m_dwPresentStatus;
	unsigned long m_dwCreateFlags;
	unsigned long m_dwWindowStyle;
	char m_strDeviceStats[90];
	int m_SceneRecurseCount;
	SRenderTileInfo m_RenderTileInfo;
	TArray<CD3D9Renderer::S2DImage> m_2dImages;
	unsigned m_nConnectedMonitors;
	bool m_bDisplayChanged;
	CCryDeviceWrapper m_DeviceWrapper;
	CCryDeviceContextWrapper m_DeviceContextWrapper;
	stl::aligned_vector<unsigned short, 16> m_arrDeferredInds;
	stl::aligned_vector<SVF_P3F_C4B_T2F, 16> m_arrDeferredVerts;
	DeviceInfo m_devInfo;
	ArkVideoInfo m_arkVideoInfo;
	SSF_ResourcesD3D* m_pSFResD3D;
	CAuxGeomCB_Null m_renderAuxGeomNull;
	CArkRenderPersistentAuxGeom_Null m_renderPersistentAuxGeomNull;
	CShadowTextureGroupManager m_ShadowTextureGroupManager;
	static TArray<CRenderObject*> s_tempObjects[2];
	static TArray<SRendItem*> s_tempRIs;
	bool m_windowParametersOverridden;
	Vec2i m_overriddenWindowSize;
	bool m_overriddenWindowFullscreenState;

	enum class LoadtimeThreadType
	{
		None = 0,
		Flash = 1,
		Bink = 2,
	};

	CD3D9Renderer::LoadtimeThreadType m_loadtimeThreadType;
	CFrameTimestamps m_frameTimestamps;

	CD3D9Renderer();
	virtual ~CD3D9Renderer();
	virtual void InitRenderer();
	virtual void Release();
	static unsigned GetNumBackBufferIndices(DXGI_SWAP_CHAIN_DESC const& scDesc) { return FGetNumBackBufferIndices(scDesc); }
	static unsigned GetCurrentBackBufferIndex(IDXGISwapChain* pSwapChain) { return FGetCurrentBackBufferIndex(pSwapChain); }
	void ReleaseBackBuffers() { FReleaseBackBuffers(this); }
	unsigned GetOrCreateBlendState(D3D11_BLEND_DESC const& desc) { return FGetOrCreateBlendState(this, desc); }
	bool SetBlendState(SStateBlend const* pNewState) { return FSetBlendState(this, pNewState); }
	unsigned GetOrCreateRasterState(D3D11_RASTERIZER_DESC const& rasterizerDec, const bool bAllowMSAA) { return FGetOrCreateRasterState(this, rasterizerDec, bAllowMSAA); }
	void PreCreateRasterStates(float _constBias, float _slopeBias, float _biasClamp) { FPreCreateRasterStates(this, _constBias, _slopeBias, _biasClamp); }
	unsigned GetRasterStateModified(unsigned _baseIndex, float _constBias, float _slopeBias, float _biasClamp) { return FGetRasterStateModified(this, _baseIndex, _constBias, _slopeBias, _biasClamp); }
	bool SetRasterState(SStateRaster const* pNewState, const bool bAllowMSAA) { return FSetRasterState(this, pNewState, bAllowMSAA); }
	unsigned GetOrCreateDepthState(D3D11_DEPTH_STENCIL_DESC const& desc) { return FGetOrCreateDepthState(this, desc); }
	bool SetDepthState(SStateDepth const* pNewState, uint8_t newStencRef) { return FSetDepthState(this, pNewState, newStencRef); }
	void UnLockParticleVideoMemory() { FUnLockParticleVideoMemory(this); }
	virtual void ActivateLayer(const char* pLayerName, bool activate);
	CCryDeviceContextWrapper& GetDeviceContext() { return FGetDeviceContext(this); }
	void EF_PrepareShadowGenRenderList(CRenderView* pRenderView) { FEF_PrepareShadowGenRenderList(this, pRenderView); }
	bool EF_PrepareShadowGenForLight(CRenderView* pRenderView, SRenderLight* pLight, int nLightID) { return FEF_PrepareShadowGenForLight(this, pRenderView, pLight, nLightID); }
	bool PrepareShadowGenForFrustum(CRenderView* pRenderView, ShadowMapFrustum* pCurFrustum, SRenderLight* pLight, int nLightID, int nLOD) { return FPrepareShadowGenForFrustum(this, pRenderView, pCurFrustum, pLight, nLightID, nLOD); }
	virtual void EF_InvokeShadowMapRenderJobs(CRenderView* pRenderView, const int nFlags);
	void SetDepthBoundTest(float fMin, float fMax, bool bEnable) { FSetDepthBoundTest(this, fMin, fMax, bEnable); }
	void CreateDeferredUnitBox(stl::aligned_vector<unsigned short, 16>& indBuff, stl::aligned_vector<SVF_P3F_C4B_T2F, 16>& vertBuff) { FCreateDeferredUnitBox(this, indBuff, vertBuff); }
	stl::aligned_vector<unsigned short, 16> const& GetDeferredUnitBoxIndexBuffer() const { return FGetDeferredUnitBoxIndexBuffer(this); }
	stl::aligned_vector<SVF_P3F_C4B_T2F, 16> const& GetDeferredUnitBoxVertexBuffer() const { return FGetDeferredUnitBoxVertexBuffer(this); }
	void ConfigShadowTexgen(int Num, ShadowMapFrustum* pFr, int nFrustNum, bool bScreenToLocalBasis, bool bUseComparisonSampling) { FConfigShadowTexgen(this, Num, pFr, nFrustNum, bScreenToLocalBasis, bUseComparisonSampling); }
	virtual void DrawAllShadowsOnTheScreen();
	virtual void OnEntityDeleted(IRenderNode* pRenderNode);
	void D3DSetCull(ECull eCull, bool bSkipMirrorCull) { FD3DSetCull(this, eCull, bSkipMirrorCull); }
	HRESULT AdjustWindowForChange() { return FAdjustWindowForChange(this); }
	static HWND__* CreateWindowCallback() { return FCreateWindowCallback(); }
	bool SetWindow(int width, int height, EFullscreenMode _fullscreenMode, void* hWnd) { return FSetWindow(this, width, height, _fullscreenMode, hWnd); }
	bool SetRes() { return FSetRes(this); }
	virtual void RestoreGamma();
	void SetGamma(float fGamma, float fBrightness, float fContrast, bool bForce) { FSetGamma(this, fGamma, fBrightness, fContrast, bForce); }
	static HRESULT OnD3D11CreateDevice(ID3D11Device* pd3dDevice) { return FOnD3D11CreateDevice(pd3dDevice); }
	static HRESULT OnD3D11PostCreateDevice(ID3D11Device* pd3dDevice) { return FOnD3D11PostCreateDevice(pd3dDevice); }
	virtual void RT_BeginFrame();
	virtual void RT_EndFrame();
	virtual void RT_BeginLoadingFrame(unsigned _frameId);
	virtual void RT_EndLoadingFrame(unsigned _frameId);
	virtual void RT_SwitchToNativeResolutionBackbuffer(bool resolveBackBuffer);
	virtual void RT_Init();
	virtual void RT_RenderWatermark();
	virtual bool RT_CreateDevice();
	virtual void RT_Reset();
	virtual void RT_RenderScene(CRenderView* pRenderView, int nFlags, SThreadInfo& TI, void (*RenderFunc)());
	virtual void RT_SetCull(int mode);
	virtual void RT_SetScissor(bool bEnable, int sX, int sY, int sWdt, int sHgt);
	virtual void RT_SetCameraInfo();
	virtual void RT_CreateResource(SResourceAsync* pRes);
	virtual void RT_ReleaseResource(SResourceAsync* pRes);
	virtual void RT_ReleaseRenderResources(unsigned nFlags);
	virtual void RT_UnbindResources();
	virtual void RT_UnbindTMUs();
	virtual void RT_CreateRenderResources();
	virtual void RT_PrecacheDefaultShaders();
	virtual void RT_ClearTarget(CTexture* pTex, ColorF const& color);
	virtual void RT_ReleaseCB(void* pVCB);
	virtual void RT_ReleaseRS(std::shared_ptr<CDeviceResourceSet>& pRS);
	virtual void RT_DrawDynVB(SVF_P3F_C4B_T2F* pBuf, uint16_t* pInds, unsigned nVerts, unsigned nInds, PublicRenderPrimitiveType nPrimType);
	virtual void RT_DrawStringW(IFFont_RenderProxy* pFont, float x, float y, float z, const wchar_t* pStr, const bool asciiMultiLine, STextDrawContext const& ctx) const;
	virtual void RT_DrawLines(Vec3* v, int nump, ColorF& col, int flags, float fGround);
	virtual void RT_Draw2dImage(float xpos, float ypos, float w, float h, CTexture* pTexture, float s0, float t0, float s1, float t1, float angle, unsigned long col, float z);
	virtual void RT_Draw2dImageStretchMode(bool bStretch);
	virtual void RT_Push2dImage(float xpos, float ypos, float w, float h, CTexture* pTexture, float s0, float t0, float s1, float t1, float angle, unsigned long col, float z);
	virtual void RT_Draw2dImageList();
	virtual void RT_DrawImageWithUV(float xpos, float ypos, float z, float w, float h, int texture_id, float* s, float* t, unsigned long col, bool filtered);
	void RT_DrawImageWithUVInternal(float xpos, float ypos, float z, float w, float h, int texture_id, float* s, float* t, unsigned long col, bool filtered) { FRT_DrawImageWithUVInternal(this, xpos, ypos, z, w, h, texture_id, s, t, col, filtered); }
	void RT_Draw2dImageInternal(CD3D9Renderer::S2DImage* images, unsigned numImages) { FRT_Draw2dImageInternal(this, images, numImages); }
	virtual void RT_SetViewport(int x, int y, int width, int height, int id);
	virtual void RT_RenderDebug(bool bRenderStats);
	virtual void RT_SetRendererCVar(ICVar* pCVar, const char* pArgText, const bool bSilentMode);
	virtual void RT_PresentFast();
	virtual void FlashRenderInternal(IFlashPlayer_RenderProxy* pPlayer, bool bDoRealRender);
	virtual void FlashRenderPlaybackLocklessInternal(IFlashPlayer_RenderProxy* pPlayer, int cbIdx, bool bFinalPlayback, bool bDoRealRender);
	virtual void* Init(int x, int y, int width, int height, unsigned cbpp, int zbpp, int sbits, EFullscreenMode _fullscreenMode, void* hinst, void* Glhwnd, bool bReInit, SCustomRenderInitArgs const* pCustomArgs, bool bShaderCacheGen);
	virtual void GetVideoMemoryUsageStats(uint64_t& vidMemUsedThisFrame, uint64_t& vidMemUsedRecently, bool bGetPoolsSizes);
	virtual bool SetCurrentContext(void* hWnd);
	virtual bool CreateContext(void* hWnd, bool bAllowMSAA, int SSX, int SSY, bool isMain);
	virtual bool DeleteContext(void* hWnd);
	virtual void MakeMainContextActive();
	virtual bool IsMainContextActive();
	virtual void* GetMainContextHWND();
	virtual void* GetCurrentContextHWND();
	virtual bool IsCurrentContextMainVP();
	virtual int GetCurrentContextViewportWidth() const;
	virtual int GetCurrentContextViewportHeight() const;
	virtual int CreateRenderTarget(int nWidth, int nHeight, ColorF const& cClear, ETEX_Format eTF);
	virtual bool DestroyRenderTarget(int nHandle);
	virtual bool SetRenderTarget(int nHandle);
	virtual bool ChangeDisplay(unsigned width, unsigned height, unsigned cbpp);
	virtual void ChangeViewport(unsigned x, unsigned y, unsigned width, unsigned height, bool bMainViewport);
	virtual IArkVideoInfo& GetIArkVideoInfo();
	virtual bool ChangeResolution(int nNewWidth, int nNewHeight, int nNewColDepth, int nNewRefreshHZ, EFullscreenMode _fullscreenMode, bool bForceReset);
	virtual void Reset();
	virtual void SwitchToNativeResolutionBackbuffer();
	void CalculateResolutions(int width, int height, bool bUseNativeRes, int* pRenderWidth, int* pRenderHeight, int* pNativeWidth, int* pNativeHeight, int* pBackbufferWidth, int* pBackbufferHeight) { FCalculateResolutions(this, width, height, bUseNativeRes, pRenderWidth, pRenderHeight, pNativeWidth, pNativeHeight, pBackbufferWidth, pBackbufferHeight); }
	virtual void BeginFrame(const bool _bUpdateFrameId);
	virtual void ShutDown(bool bReInit);
	virtual void ShutDownFast();
	virtual void RenderDebug(bool bRenderStats);
	virtual void RT_ShutDown(unsigned nFlags);
	virtual void EndFrame();
	virtual void LimitFramerate(const int maxFPS, const bool bUseSleep);
	virtual void LimitLoadingFramerate();
	virtual void GetMemoryUsage(ICrySizer* Sizer);
	virtual void GetLogVBuffers();
	virtual void TryFlush();
	virtual void Draw2dImage(float xpos, float ypos, float w, float h, int textureid, float s0, float t0, float s1, float t1, float angle, float r, float g, float b, float a, float z);
	virtual void Push2dImage(float xpos, float ypos, float w, float h, int textureid, float s0, float t0, float s1, float t1, float angle, float r, float g, float b, float a, float z);
	virtual void Draw2dImageStretchMode(bool bStretch);
	virtual void Draw2dImageList();
	virtual void DrawImage(float xpos, float ypos, float w, float h, int texture_id, float s0, float t0, float s1, float t1, float r, float g, float b, float a, bool filtered);
	virtual void DrawImageWithUV(float xpos, float ypos, float z, float w, float h, int texture_id, float* s, float* t, float r, float g, float b, float a, bool filtered);
	virtual void SetCullMode(int mode);
	virtual void PushProfileMarker(char* label);
	virtual void PopProfileMarker(char* label);
	virtual bool EnableFog(bool enable);
	virtual void SetFogColor(ColorF const& color);
	virtual void CreateResourceAsync(SResourceAsync* pResource);
	virtual void ReleaseResourceAsync(SResourceAsync* pResource);
	virtual unsigned DownLoadToVideoMemory(uint8_t* data, int w, int h, ETEX_Format eTFSrc, ETEX_Format eTFDst, int nummipmap, bool repeat, int filter, int Id, const char* szCacheName, int flags, bool eEndian, RectI* pRegion, bool bAsyncDevTexCreation);
	unsigned DownLoadToVideoMemory(uint8_t* data, int w, int h, int d, ETEX_Format eTFSrc, ETEX_Format eTFDst, int nummipmap, ETEX_Type eTT, bool repeat, int filter, int Id, const char* szCacheName, int flags, bool eEndian, RectI* pRegion, bool bAsyncDevTexCreation) { return FDownLoadToVideoMemoryOv0(this, data, w, h, d, eTFSrc, eTFDst, nummipmap, eTT, repeat, filter, Id, szCacheName, flags, eEndian, pRegion, bAsyncDevTexCreation); }
	virtual void UpdateTextureInVideoMemory(unsigned tnum, uint8_t* newdata, int posx, int posy, int w, int h, ETEX_Format eTFSrc, int posz, int sizez);
	virtual bool EF_PrecacheResource(SShaderItem* pSI, float fMipFactorSI, float fTimeToReady, int Flags, int nUpdateId, int nCounter);
	virtual bool EF_PrecacheResource(ITexture* pTP, float fMipFactor, float fTimeToReady, int Flags, int nUpdateId, int nCounter);
	virtual void RemoveTexture(unsigned TextureId);
	virtual void PrecacheTick();
	virtual void PostLevelLoading();
	virtual void PostLevelUnload();
	void SetRCamera(CRenderCamera const& cam) { FSetRCamera(this, cam); }
	virtual void SetCamera(CCamera const& cam);
	virtual void SetViewport(int x, int y, int width, int height, int id);
	virtual void GetViewport(int* x, int* y, int* width, int* height);
	SViewport GetViewport() const { return FGetViewportOv0(this); }
	virtual void SetScissor(int x, int y, int width, int height);
	virtual void SetRenderTile(float nTilesPosX, float nTilesPosY, float nTilesGridSizeX, float nTilesGridSizeY);
	virtual void Graph(uint8_t* g, int x, int y, int wdt, int hgt, int nC, int type, char* text, ColorF& color, float fScale);
	virtual void DrawDynVB(SVF_P3F_C4B_T2F* pBuf, uint16_t* pInds, int nVerts, int nInds, PublicRenderPrimitiveType nPrimType);
	virtual void PrintResourcesLeaks();
	virtual void FX_PushWireframeMode(int mode);
	virtual void FX_PopWireframeMode();
	virtual void DrawPrimitivesInternal(CVertexBuffer* src, int vert_num, ERenderPrimitiveType prim_type);
	virtual void ResetToDefault();
	virtual void SetMaterialColor(float r, float g, float b, float a);
	virtual bool ProjectToScreen(float ptx, float pty, float ptz, float* sx, float* sy, float* sz);
	virtual int UnProjectFromScreen(float sx, float sy, float sz, float* px, float* py, float* pz);
	virtual void GetModelViewMatrix(float* mat);
	virtual void GetProjectionMatrix(float* mat);
	virtual void GetCameraZeroMatrix(float* mat);
	virtual void SetMatrices(float* pProjMat, float* pViewMat, float* pZeroMat);
	void DrawQuad(float x0, float y0, float x1, float y1, ColorF const& color, float z, float s0, float t0, float s1, float t1) { FDrawQuad(this, x0, y0, x1, y1, color, z, s0, t0, s1, t1); }
	void DrawFullScreenTriangle() { FDrawFullScreenTriangle(this); }
	virtual void ClearTargetsImmediately(unsigned nFlags);
	virtual void ClearTargetsImmediately(unsigned nFlags, ColorF const& Colors, float fDepth);
	virtual void ClearTargetsImmediately(unsigned nFlags, ColorF const& Colors);
	virtual void ClearTargetsImmediately(unsigned nFlags, float fDepth);
	virtual void ClearTargetsLater(unsigned nFlags);
	virtual void ClearTargetsLater(unsigned nFlags, ColorF const& Colors, float fDepth);
	virtual void ClearTargetsLater(unsigned nFlags, ColorF const& Colors);
	virtual void ClearTargetsLater(unsigned nFlags, float fDepth);
	virtual void SetRendererCVar(ICVar* pCVar, const char* pArgText, const bool bSilentMode);
	virtual bool ScreenShot(const char* filename, int iPreWidth, EScreenShotMode eScreenShotMode);
	virtual void Set2DMode(bool enable, int ortox, int ortoy, float znear, float zfar);
	virtual int ScreenToTexture(int nTexID);
	virtual bool SetGammaDelta(const float fGamma);
	virtual bool FontUploadTexture(CFBitmap* pBmp, ETEX_Format eTF);
	virtual int FontCreateTexture(int Width, int Height, uint8_t* pData, ETEX_Format eTF, bool genMips);
	virtual bool FontUpdateTexture(int nTexId, int nX, int nY, int USize, int VSize, uint8_t* pData);
	virtual void FontReleaseTexture(CFBitmap* pBmp);
	virtual void FontSetTexture(CFBitmap* pBmp, int nFilterMode);
	virtual void FontSetTexture(int nTexId, int nFilterMode);
	virtual void FontSetRenderingState(unsigned nVPWidth, unsigned nVPHeight);
	virtual void FontSetBlending(int blendSrc, int blendDest);
	virtual void FontRestoreRenderingState();
	void FontSetState(bool bRestore) { FFontSetState(this, bRestore); }
	void SF_CreateResources() { FSF_CreateResources(this); }
	void SF_PrecacheShaders() { FSF_PrecacheShaders(this); }
	void SF_DestroyResources() { FSF_DestroyResources(this); }
	//bool SF_SetVertexDeclaration(SSF_GlobalDrawParams::EVertexFmt vertexFmt) { return FSF_SetVertexDeclaration(this, vertexFmt); }
	//void SF_SetBlendOp(SSF_GlobalDrawParams::EAlphaBlendOp blendOp, bool reset) { FSF_SetBlendOp(this, blendOp, reset); }
	virtual void SF_DrawIndexedTriList(int baseVertexIndex, int minVertexIndex, int numVertices, int startIndex, int triangleCount, SSF_GlobalDrawParams const& params);
	virtual void SF_DrawLineStrip(int baseVertexIndex, int lineCount, SSF_GlobalDrawParams const& params);
	virtual void SF_DrawGlyphClear(SSF_GlobalDrawParams const& params);
	virtual void SF_DrawBlurRect(SSF_GlobalDrawParams const& params);
	virtual void SF_Flush();
	virtual bool SF_UpdateTexture(int texId, int mipLevel, int numRects, IRenderer::SUpdateRect const* pRects, uint8_t* pData, uint64_t pitch, uint64_t size, ETEX_Format eTF);
	virtual void SetProfileMarker(const char* label, CRenderer::ESPM mode) const;
	void EF_Scene3D(SViewport& VP, int nFlags, SRenderingPassInfo const& passInfo) { FEF_Scene3D(this, VP, nFlags, passInfo); }
	bool CheckMSAAChange() { return FCheckMSAAChange(this); }
	bool CheckSSAAChange() { return FCheckSSAAChange(this); }
	void FX_DrawInstances(CShader* ef, SShaderPass* slw, int nRE, unsigned nStartInst, unsigned nLastInst, unsigned nUsedAttr, uint8_t* InstanceData, int nInstAttrMask, uint8_t* Attributes, int16_t dwCBufSlot) { FFX_DrawInstances(this, ef, slw, nRE, nStartInst, nLastInst, nUsedAttr, InstanceData, nInstAttrMask, Attributes, dwCBufSlot); }
	void FX_DrawShader_InstancedHW(CShader* ef, SShaderPass* slw) { FFX_DrawShader_InstancedHW(this, ef, slw); }
	void FX_DrawShader_General(CShader* ef, SShaderTechnique* pTech) { FFX_DrawShader_General(this, ef, pTech); }
	void FX_SetupForwardShadows(CRenderView* pRenderView, bool bUseShaderPermutations) { FFX_SetupForwardShadows(this, pRenderView, bUseShaderPermutations); }
	void FX_SetupShadowsForTransp() { FFX_SetupShadowsForTransp(this); }
	void CopyFramebufferDX11(CTexture* pDst, ID3D11Resource* pSrcResource, DXGI_FORMAT srcFormat) { FCopyFramebufferDX11(this, pDst, pSrcResource, srcFormat); }
	void FX_ScreenStretchRect(CTexture* pDst) { FFX_ScreenStretchRect(this, pDst); }
	virtual int GetOcclusionBuffer(float* pOutOcclBuffer, int nSizeX, int nSizeY, Matrix44* pmCamBuffer);
	virtual void WaitForParticleBuffer();
	void InsertParticleVideoDataFence() { FInsertParticleVideoDataFence(this); }
	void FX_ZTargetReadBack() { FFX_ZTargetReadBack(this); }
	void FX_UpdateCharCBs() { FFX_UpdateCharCBs(this); }
	virtual void* FX_AllocateCharInstCB(SSkinningData* pSkinningData, unsigned frameId);
	virtual void FX_ClearCharInstCB(unsigned frameId);
	bool CreateAuxiliaryMeshes() { return FCreateAuxiliaryMeshes(this); }
	bool ReleaseAuxiliaryMeshes() { return FReleaseAuxiliaryMeshes(this); }
	bool FX_DeferredShadowPassSetup(Matrix44 const& mShadowTexGen, CCamera const& cam, ShadowMapFrustum* pShadowFrustum, float maskRTWidth, float maskRTHeight, Matrix44& mScreenToShadow, bool bNearest) { return FFX_DeferredShadowPassSetup(this, mShadowTexGen, cam, pShadowFrustum, maskRTWidth, maskRTHeight, mScreenToShadow, bNearest); }
	bool FX_DeferredShadowPassSetupBlend(Matrix44 const& mShadowTexGen, CCamera const& cam, int nFrustumNum, float maskRTWidth, float maskRTHeight) { return FFX_DeferredShadowPassSetupBlend(this, mShadowTexGen, cam, nFrustumNum, maskRTWidth, maskRTHeight); }
	void FX_DrawTechnique(CShader* ef, SShaderTechnique* pTech) { FFX_DrawTechnique(this, ef, pTech); }
	void FX_RefractionPartialResolve() { FFX_RefractionPartialResolve(this); }
	bool FX_HDRScene(bool bEnableHDR, bool bClear) { return FFX_HDRScene(this, bEnableHDR, bClear); }
	void FX_HDRRangeAdaptUpdate() { FFX_HDRRangeAdaptUpdate(this); }
	void FX_RenderForwardOpaque(void (*RenderFunc)(), const bool bLighting, const bool bAllowDeferred) { FFX_RenderForwardOpaque(this, RenderFunc, bLighting, bAllowDeferred); }
	void FX_RenderWater(void (*RenderFunc)()) { FFX_RenderWater(this, RenderFunc); }
	bool FX_ZScene(bool bEnable, bool bUseHDR, bool bClearZBuffer, bool bRenderNormalsOnly, bool bZPrePass) { return FFX_ZScene(this, bEnable, bUseHDR, bClearZBuffer, bRenderNormalsOnly, bZPrePass); }
	bool FX_DeferredWaterVolumeCaustics(N3DEngineCommon::SCausticInfo const& causticInfo) { return FFX_DeferredWaterVolumeCaustics(this, causticInfo); }
	bool FX_CustomRenderScene(bool bEnable) { return FFX_CustomRenderScene(this, bEnable); }
	bool FX_PostProcessScene(bool bEnable) { return FFX_PostProcessScene(this, bEnable); }
	bool FX_DeferredRendering(CRenderView* pRenderView, bool bUpdateRTOnly) { return FFX_DeferredRendering(this, pRenderView, bUpdateRTOnly); }
	bool FX_DeferredDecals() { return FFX_DeferredDecals(this); }
	bool FX_ForwardDecals() { return FFX_ForwardDecals(this); }
	void FX_LinearizeDepth() { FFX_LinearizeDepth(this); }
	void FX_DepthFixupMerge() { FFX_DepthFixupMerge(this); }
	void FX_SceneMaskGen(CRenderView* pRenderView) { FFX_SceneMaskGen(this, pRenderView); }
	virtual float GetGPUFrameTime();
	virtual void GetRenderTimes(IRenderer::SRenderTimes& outTimes);
	virtual void FX_PipelineShutdown(bool bFastShutdown);
	virtual void RT_GraphicsPipelineShutdown();
	virtual void EF_ClearTargetsImmediately(unsigned nFlags);
	virtual void EF_ClearTargetsImmediately(unsigned nFlags, ColorF const& Colors, float fDepth, uint8_t nStencil);
	virtual void EF_ClearTargetsImmediately(unsigned nFlags, ColorF const& Colors);
	virtual void EF_ClearTargetsImmediately(unsigned nFlags, float fDepth, uint8_t nStencil);
	virtual void EF_ClearTargetsLater(unsigned nFlags);
	virtual void EF_ClearTargetsLater(unsigned nFlags, ColorF const& Colors, float fDepth, uint8_t nStencil);
	virtual void EF_ClearTargetsLater(unsigned nFlags, ColorF const& Colors);
	virtual void EF_ClearTargetsLater(unsigned nFlags, float fDepth, uint8_t nStencil);
	void EF_Restore() { FEF_Restore(this); }
	virtual void FX_SetState(int st, int AlphaRef = -1, int RestoreState = 0);
	void ChangeLog() { FChangeLog(this); }
	virtual void SetCurDownscaleFactor(Vec2 sf);
	virtual bool CheckDeviceLost();
	void EF_DirtyMatrix() { FEF_DirtyMatrix(this); }
	void EF_PushMatrix() { FEF_PushMatrix(this); }
	void EF_PopMatrix() { FEF_PopMatrix(this); }
	void FX_ResetPipe() { FFX_ResetPipe(this); }
	void EF_SetVertColor() { FEF_SetVertColor(this); }
	HRESULT FX_SetVertexDeclaration(int StreamMask, EVertexFormat eVF) { return FFX_SetVertexDeclaration(this, StreamMask, eVF); }
	void FX_DrawBatch(CShader* pSh, SShaderPass* pPass) { FFX_DrawBatch(this, pSh, pPass); }
	void FX_DrawBatchSkinned(CShader* pSh, SShaderPass* pPass, SSkinningData* pSkinningData) { FFX_DrawBatchSkinned(this, pSh, pPass, pSkinningData); }
	void FX_SetActiveRenderTargets() { FFX_SetActiveRenderTargets(this); }
	void FX_SetViewport() { FFX_SetViewport(this); }
	void FX_ClearTargets() { FFX_ClearTargets(this); }
	void FX_ClearTarget(ID3D11RenderTargetView* pView, ColorF const& cClear, const unsigned numRects, tagRECT const* pRects) { FFX_ClearTargetOv8(this, pView, cClear, numRects, pRects); }
	void FX_ClearTarget(CTexture* pTex, ColorF const& cClear, const unsigned numRects, tagRECT const* pRects, const bool bOptionalRects) { FFX_ClearTargetOv7(this, pTex, cClear, numRects, pRects, bOptionalRects); }
	void FX_ClearTarget(CTexture* pTex, ColorF const& cClear) { FFX_ClearTargetOv6(this, pTex, cClear); }
	void FX_ClearTarget(CTexture* pTex) { FFX_ClearTargetOv5(this, pTex); }
	void FX_ClearTarget(ID3D11DepthStencilView* pView, const int nFlags, const float cDepth, const uint8_t cStencil, const unsigned numRects, tagRECT const* pRects) { FFX_ClearTargetOv4(this, pView, nFlags, cDepth, cStencil, numRects, pRects); }
	void FX_ClearTarget(SDepthTexture* pTex, const int nFlags, const float cDepth, const uint8_t cStencil, const unsigned numRects, tagRECT const* pRects, const bool bOptionalRects) { FFX_ClearTargetOv3(this, pTex, nFlags, cDepth, cStencil, numRects, pRects, bOptionalRects); }
	void FX_ClearTarget(SDepthTexture* pTex, const int nFlags, const float cDepth, const uint8_t cStencil) { FFX_ClearTargetOv2(this, pTex, nFlags, cDepth, cStencil); }
	void FX_ClearTarget(SDepthTexture* pTex, const int nFlags) { FFX_ClearTargetOv1(this, pTex, nFlags); }
	void FX_ClearTarget(SDepthTexture* pTex) { FFX_ClearTargetOv0(this, pTex); }
	bool FX_SetRenderTarget(int nTarget, ID3D11RenderTargetView* pTargetSurf, SDepthTexture* pDepthTarget, unsigned nTileCount) { return FFX_SetRenderTargetOv1(this, nTarget, pTargetSurf, pDepthTarget, nTileCount); }
	bool FX_SetRenderTarget(int nTarget, CTexture* pTarget, SDepthTexture* pDepthTarget, bool bPush, int nCMSide, bool bScreenVP, unsigned nTileCount) { return FFX_SetRenderTargetOv0(this, nTarget, pTarget, pDepthTarget, bPush, nCMSide, bScreenVP, nTileCount); }
	bool FX_PushRenderTarget(int nTarget, CTexture* pTarget, SDepthTexture* pDepthTarget, int nCMSide, bool bScreenVP, unsigned nTileCount) { return FFX_PushRenderTargetOv0(this, nTarget, pTarget, pDepthTarget, nCMSide, bScreenVP, nTileCount); }
	bool FX_RestoreRenderTarget(int nTarget) { return FFX_RestoreRenderTarget(this, nTarget); }
	bool FX_PopRenderTarget(int nTarget) { return FFX_PopRenderTarget(this, nTarget); }
	SDepthTexture* FX_GetDepthSurface(int nWidth, int nHeight, bool bAA, bool bExactMatch) { return FFX_GetDepthSurface(this, nWidth, nHeight, bAA, bExactMatch); }
	void FX_Commit() { FFX_Commit(this); }
	bool FX_SetFPMode() { return FFX_SetFPMode(this); }
	void FX_CommitStates(SShaderTechnique const* pTech, SShaderPass const* pPass, bool bUseMaterialState) { FFX_CommitStates(this, pTech, pPass, bUseMaterialState); }
	HRESULT FX_SetVStream(int nID, const void* pB, unsigned nOffs, unsigned nStride) { return FFX_SetVStream(this, nID, pB, nOffs, nStride); }
	HRESULT FX_SetIStream(const void* pB, unsigned nOffs, RenderIndexType idxType) { return FFX_SetIStream(this, pB, nOffs, idxType); }
	void FX_DrawIndexedPrimitive(ERenderPrimitiveType eType, const int nVBOffset, const int nMinVertexIndex, const int nVerticesCount, const int nStartIndex, const int nNumIndices, bool bInstanced = false) { FFX_DrawIndexedPrimitive(this, eType, nVBOffset, nMinVertexIndex, nVerticesCount, nStartIndex, nNumIndices, bInstanced); }
	void FX_DrawPrimitive(ERenderPrimitiveType eType, const int nStartVertex, const int nVerticesCount, const int nInstanceVertices = 0) { FFX_DrawPrimitive(this, eType, nStartVertex, nVerticesCount, nInstanceVertices); }
	bool FX_CommitStreams(SShaderPass* sl, bool bSetVertexDecl) { return FFX_CommitStreams(this, sl, bSetVertexDecl); }
	void EF_SetColorOp(uint8_t eCo, uint8_t eAo, uint8_t eCa, uint8_t eAa) { FEF_SetColorOp(this, eCo, eAo, eCa, eAa); }
	void FX_PreRender() { FFX_PreRender(this); }
	void FX_PostRender() { FFX_PostRender(this); }
	void EF_Init() { FEF_Init(this); }
	void EF_SetCameraInfo() { FEF_SetCameraInfo(this); }
	bool FX_ObjectChange(CShader* Shader, CShaderResources* Res, CRenderObject* obj, CRendElementBase* pRE) { return FFX_ObjectChange(this, Shader, Res, obj, pRE); }
	bool ScreenShotInternal(const char* filename, int width, EScreenShotMode eScreenShotMode) { return FScreenShotInternal(this, filename, width, eScreenShotMode); }
	void UpdateNearestChange(int flags) { FUpdateNearestChange(this, flags); }
	void UpdatePrevMatrix(bool bEnable) { FUpdatePrevMatrix(this, bEnable); }
	void FX_SetAdjacencyOffsetBuffer() { FFX_SetAdjacencyOffsetBuffer(this); }
	static void FX_FlushShader_General() { FFX_FlushShader_General(); }
	static void FX_FlushShader_ZPass() { FFX_FlushShader_ZPass(); }
	static bool FX_UpdateAnimatedShaderResources(CShaderResources const* shaderResources) { return FFX_UpdateAnimatedShaderResources(shaderResources); }
	static bool FX_UpdateDynamicShaderResources(CShaderResources const* shaderResources, unsigned batchFilter, unsigned flags2) { return FFX_UpdateDynamicShaderResources(shaderResources, batchFilter, flags2); }
	void FX_UnbindBuffer(ID3D11Buffer* buffer) { FFX_UnbindBuffer(this, buffer); }
	void EF_Scissor(bool bEnable, int sX, int sY, int sWdt, int sHgt) { FEF_Scissor(this, bEnable, sX, sY, sWdt, sHgt); }
	bool EF_GetScissorState(int& sX, int& sY, int& sWdt, int& sHgt) { return FEF_GetScissorState(this, sX, sY, sWdt, sHgt); }
	void EF_SetFogColor(ColorF const& Color) { FEF_SetFogColor(this, Color); }
	void FX_FogCorrection() { FFX_FogCorrection(this); }
	void FX_DrawIndexedMesh(ERenderPrimitiveType nPrimType) { FFX_DrawIndexedMesh(this, nPrimType); }
	bool FX_SetResourcesState() { return FFX_SetResourcesState(this); }
	void DrawRenderItems(SGraphicsPipelinePassContext const& passContext) { FDrawRenderItems(this, passContext); }
	void FX_ProcessZPassRenderLists() { FFX_ProcessZPassRenderLists(this); }
	void FX_ProcessZPassRender_List(ERenderListID list, unsigned filter) { FFX_ProcessZPassRender_List(this, list, filter); }
	void FX_ProcessSkinRenderLists(int nList, void (*RenderFunc)(), bool bLighting) { FFX_ProcessSkinRenderLists(this, nList, RenderFunc, bLighting); }
	void FX_ProcessEyeOverlayRenderLists(int nList, void (*RenderFunc)(), bool bLighting) { FFX_ProcessEyeOverlayRenderLists(this, nList, RenderFunc, bLighting); }
	void FX_ProcessHalfResParticlesRenderList(CRenderView* pRenderView, int nList, void (*RenderFunc)(), bool bLighting) { FFX_ProcessHalfResParticlesRenderList(this, pRenderView, nList, RenderFunc, bLighting); }
	void FX_WaterVolumesPreprocess() { FFX_WaterVolumesPreprocess(this); }
	void FX_ProcessPostRenderLists(unsigned nBatchFilter) { FFX_ProcessPostRenderLists(this, nBatchFilter); }
	void FX_ProcessRenderList(int nList, unsigned nBatchFilter) { FFX_ProcessRenderListOv1(this, nList, nBatchFilter); }
	void FX_ProcessRenderList(int nList, void (*RenderFunc)(), bool bLighting, unsigned nBatchFilter, unsigned nBatchExcludeFilter) { FFX_ProcessRenderListOv0(this, nList, RenderFunc, bLighting, nBatchFilter, nBatchExcludeFilter); }
	//void OldPipeline_ProcessRenderList(lockfree_add_vector<SRendItem>& renderItems, int nums, int nume, int nList, void (*RenderFunc)(), bool bLighting, unsigned nBatchFilter, unsigned nBatchExcludeFilter) { FOldPipeline_ProcessRenderList(this, renderItems, nums, nume, nList, RenderFunc, bLighting, nBatchFilter, nBatchExcludeFilter); }
	//void OldPipeline_ProcessBatchesList(lockfree_add_vector<SRendItem>& renderItems, int nums, int nume, unsigned nBatchFilter, unsigned nBatchExcludeFilter) { FOldPipeline_ProcessBatchesList(this, renderItems, nums, nume, nBatchFilter, nBatchExcludeFilter); }
	void FX_WaterVolumesCaustics(CRenderView* pRenderView) { FFX_WaterVolumesCaustics(this, pRenderView); }
	void FX_WaterVolumesCausticsPreprocess(N3DEngineCommon::SCausticInfo& causticInfo) { FFX_WaterVolumesCausticsPreprocess(this, causticInfo); }
	bool FX_WaterVolumesCausticsUpdateGrid(N3DEngineCommon::SCausticInfo& causticInfo) { return FFX_WaterVolumesCausticsUpdateGrid(this, causticInfo); }
	virtual void EF_EndEf3D(const int nFlags, const int nPrecacheUpdateIdSlow, const int nPrecacheUpdateIdFast, SRenderingPassInfo const& passInfo);
	virtual void* GetHWND();
	virtual void SetColorOp(uint8_t eCo, uint8_t eAo, uint8_t eCa, uint8_t eAa);
	void AdjustHDROutputMode() { FAdjustHDROutputMode(this); }
	virtual IRenderAuxGeom* GetIRenderAuxGeom(void* jobID);
	virtual IArkRenderPersistentAuxGeom* GetIArkRenderPersistentAuxGeom();
	virtual IColorGradingController* GetIColorGradingController();
	virtual void StartLoadtimeFlashPlayback(ILoadtimeCallback* pCallback);
	virtual void StopLoadtimeFlashPlayback();
	virtual void StartLoadtimeBinkPlayback(ILoadtimeCallback* pCallback);
	virtual void StopLoadtimeBinkPlayback();
	virtual RPProfilerStats const* GetRPPStats(ERenderPipelineProfilerStats eStat, bool bCalledFromMainThread);
	virtual RPProfilerStats const* GetRPPStatsArray(bool bCalledFromMainThread);
	virtual int GetPolygonCountByType(unsigned EFSList, EVertexCostTypes vct, unsigned z, bool bCalledFromMainThread);
	//virtual _smart_ptr<IGraphicsDeviceConstantBuffer> CreateGraphiceDeviceConstantBuffer();
	//virtual gpu_pfx2::IManager* GetGpuParticleManager();
	void HandleDisplayPropertyChanges() { FHandleDisplayPropertyChanges(this); }
	bool CaptureFrameBufferToFile(const char* pFilePath, CTexture* pRenderTarget) { return FCaptureFrameBufferToFile(this, pFilePath, pRenderTarget); }
	virtual void EnablePipelineProfiler(bool bEnable);
	virtual void ClearPerFrameData(SRenderingPassInfo const& passInfo);
	void CheckUpdateDimensions(int& _width, int& _height) { FCheckUpdateDimensions(this, _width, _height); }
	virtual void PeekWindowMessage(unsigned message, uint64_t wParam, uint64_t lParam);

	CCryDeviceWrapper const& GetDevice() const;
	CCryDeviceWrapper& GetDevice();
	CCryDeviceWrapper& GetDevice_Unsynchronized();
	bool IsDeviceLost() { return(m_bDeviceLost != 0); }

#if 0
	static void StaticCleanup();
	CD3D9Renderer* operator->();
	const bool operator!() const;
	bool operator bool() const;
	CD3D9Renderer* operator class CD3D9Renderer* ();
	SRenderTileInfo const& GetRenderTileInfo() const;
	CTexture* GetBackBufferTexture();
	void SetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY arg0);
	void LockParticleVideoMemory();
	void SetDefaultTexParams(bool arg0, bool arg1, bool arg2);
	CCryDeviceContextWrapper& GetDeviceContext_Unsynchronized();
	CCryDeviceContextWrapper& GetDeviceContext_ForMapAndUnmap();
	void BindContextToThread(unsigned long arg0);
	unsigned long GetBoundThreadID() const;
	void CheckContextThreadAccess() const;
	void WaitForAsynchronousDevice() const;
	volatile int* GetAsynchronousDeviceState();
	void RegisterDeviceWrapperHook(ICryDeviceWrapperHook* arg0);
	void UnregisterDeviceWrapperHook(const char* arg0);
	void PrepareShadowGenForFrustumNonJobs(const int arg0);
	void GetReprojectionMatrix(Matrix44& arg0, Matrix44 const& arg1, Matrix44 const& arg2, Matrix44 const& arg3, Matrix44 const& arg4, float arg5) const;
	bool GetDepthBoundTestState(float& arg0, float& arg1) const;
	void DrawAllDynTextures(const char* arg0, const bool arg1, const bool arg2);
	void GetDeviceGamma();
	void SetDeviceGamma(CD3D9Renderer::SGammaRamp* arg0);
	EFullscreenMode GetFullscreenMode() const;
	EFullscreenMode GetFullscreenModeFromCVar() const;
	bool IsSuperSamplingEnabled();
	bool IsNativeScalingEnabled();
	bool IsDirectX11Supported() const;
	DeviceInfo& DevInfo();
	unsigned GetCurrentFrameCounter() const;
	unsigned GetCompletedFrameCounter() const;
	void DebugShowRenderTarget();
	void UnSetRes();
	void DisplaySplash();
	void DestroyWindow();
	int FindTextureInRegistry(const char* arg0, int* arg1);
	int RegisterTextureInRegistry(const char* arg0, int arg1, int arg2, int arg3);
	unsigned MakeTextureREAL(const char* arg0, int* arg1, unsigned arg2);
	unsigned CheckTexturePlus(const char* arg0, const char* arg1);
	void PostDeviceReset();
	void IssueFrameFences();
	ArkVideoInfo& GetArkVideoInfo();
	void DebugPrintShader(CHWShader_D3D* arg0, void* arg1, int arg2, int arg3, ColorF arg4);
	void DebugPerfBars(int arg0, int arg1);
	void DebugVidResourcesBars(int arg0, int arg1);
	void DebugDrawStats1();
	void DebugDrawStats2();
	void DebugDrawStats8();
	void DebugDrawStats20();
	void DebugDrawStats();
	void DebugDrawRect(float arg0, float arg1, float arg2, float arg3, float* arg4);
	void VidMemLog();
	void DebugDrawDeviceMemoryStats();
	void Draw2dImage(float arg0, float arg1, float arg2, float arg3, int arg4, float arg5, float arg6, float arg7, float arg8, float arg9, ColorF const& arg10, float arg11);
	void DrawLines(Vec3* arg0, int arg1, ColorF& arg2, int arg3, float arg4);
	void FX_SetWireframeMode(int arg0);
	void UnloadOldTextures();
	void SF_ResetResources();
	SSF_ResourcesD3D& SF_GetResources();
	CShader* SF_SetTechnique(CCryNameTSCRC const& arg0);
	unsigned SF_AdjustBlendStateForMeasureOverdraw(unsigned arg0);
	void FX_ApplyThreadState(SThreadInfo& arg0, SThreadInfo* arg1);
	void EF_RenderScene(int arg0, SViewport& arg1, SRenderingPassInfo const& arg2);
	void FX_UpdateGpuParticles();
	void FX_StencilTestCurRef(bool arg0, bool arg1, bool arg2);
	void FX_PostProcessSceneHDR();
	bool FX_SkinRendering(bool arg0);
	bool FX_NearTransparency();
	void FX_Invalidate();
	void FX_StateRestore(int arg0);
	void SetFullscreenViewport();
	void SetLogFuncs(bool arg0);
	void MemReplayWrapD3DDevice();
	bool CreateMSAADepthBuffer();
	void PostMeasureOverdraw();
	void DrawTexelsPerMeterInfo();
	void EF_SetGlobalColor(float arg0, float arg1, float arg2, float arg3);
	bool FX_SetStreamFlags(SShaderPass* arg0);
	void FX_FlushSkinVSParams(CHWShader_D3D* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, DualQuat* arg6, DualQuat* arg7);
	bool FX_GetTargetSurfaces(CTexture* arg0, ID3D11RenderTargetView*& arg1, CD3D9Renderer::SRenderTargetStack* arg2, int arg3, int arg4, unsigned arg5);
	bool FX_PushRenderTarget(int arg0, ID3D11RenderTargetView* arg1, SDepthTexture* arg2, unsigned arg3);
	SDepthTexture* FX_CreateDepthSurface(int arg0, int arg1, bool arg2);
	void FX_ZState(unsigned& arg0);
	void FX_HairState(unsigned& arg0, SShaderPass const* arg1);
	unsigned PackBlendModeAndPassGroup();
	bool ShouldApplyFogCorrection();
	void FX_DrawRE(CShader* arg0, SShaderPass* arg1);
	unsigned ApplyIndexBufferBindOffset(unsigned arg0);
	HRESULT FX_ResetVertexDeclaration();
	D3D_PRIMITIVE_TOPOLOGY FX_ConvertPrimitiveType(ERenderPrimitiveType arg0) const;
	void FX_SetObjectTransform(CRenderObject* arg0, CShader* arg1, uint64_t arg2);
	void HandleDefaultObject();
	bool FX_SetTessellationShaders(CHWShader_D3D*& arg0, CHWShader_D3D*& arg1, SShaderPass const* arg2);
	void FX_Flush_ForProfiler(int arg0);
	bool FX_DebugCheckConsistency(int arg0, int arg1, int arg2, int arg3);
	void FX_StartBatching();
	void FX_ProcessRenderStates(int arg0, int arg1, SGraphicsPipelinePassContext const& arg2);
	void SubmitRenderViewForRendering(void (*arg0)(), int arg1, SViewport& arg2, SRenderingPassInfo const& arg3, bool arg4);
	void FX_ProcessPostGroups(int arg0, int arg1);
	CStandardGraphicsPipeline& GetGraphicsPipeline();
	CTiledShading& GetTiledShading();
	CVolumetricCloudManager& GetVolumetricCloud();
	void BeginRenderDocCapture();
	void EndRenderDocCapture();
	void HandlePresentError(HRESULT arg0);
	void CacheCaptureCVars();
	void CaptureFrameBuffer();
	void ResolveSupersampledBackbuffer();
	void ScaleBackbufferToViewport();
	void OverrideWindowParameters(bool arg0, int arg1, int arg2, bool arg3);
	void CalcAABBScreenRect(AABB const& arg0, CRenderCamera const& arg1, Matrix44 const& arg2, Vec3* arg3, Vec3* arg4);
#endif

	static inline auto FBitNotCD3D9Renderer = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4AB80);
	static inline auto FInitRenderer = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4FD30);
	static inline auto FRelease = PreyFunction<void(CD3D9Renderer* const _this)>(0xF52BE0);
	static inline auto FGetNumBackBufferIndices = PreyFunction<unsigned(DXGI_SWAP_CHAIN_DESC const& scDesc)>(0x1B1DEA0);
	static inline auto FGetCurrentBackBufferIndex = PreyFunction<unsigned(IDXGISwapChain* pSwapChain)>(0x158AEF0);
	static inline auto FReleaseBackBuffers = PreyFunction<void(CD3D9Renderer* const _this)>(0xF52C00);
	static inline auto FGetOrCreateBlendState = PreyFunction<unsigned(CD3D9Renderer* const _this, D3D11_BLEND_DESC const& desc)>(0xF4EB90);
	static inline auto FSetBlendState = PreyFunction<bool(CD3D9Renderer* const _this, SStateBlend const* pNewState)>(0xF53CF0);
	static inline auto FGetOrCreateRasterState = PreyFunction<unsigned(CD3D9Renderer* const _this, D3D11_RASTERIZER_DESC const& rasterizerDec, const bool bAllowMSAA)>(0xF4EF00);
	static inline auto FPreCreateRasterStates = PreyFunction<void(CD3D9Renderer* const _this, float _constBias, float _slopeBias, float _biasClamp)>(0xF51090);
	static inline auto FGetRasterStateModified = PreyFunction<unsigned(CD3D9Renderer* const _this, unsigned _baseIndex, float _constBias, float _slopeBias, float _biasClamp)>(0xF4F240);
	static inline auto FSetRasterState = PreyFunction<bool(CD3D9Renderer* const _this, SStateRaster const* pNewState, const bool bAllowMSAA)>(0xF54D40);
	static inline auto FGetOrCreateDepthState = PreyFunction<unsigned(CD3D9Renderer* const _this, D3D11_DEPTH_STENCIL_DESC const& desc)>(0xF4ED70);
	static inline auto FSetDepthState = PreyFunction<bool(CD3D9Renderer* const _this, SStateDepth const* pNewState, uint8_t newStencRef)>(0xF545C0);
	static inline auto FUnLockParticleVideoMemory = PreyFunction<void(CD3D9Renderer* const _this)>(0xF54FE0);
	static inline auto FActivateLayer = PreyFunction<void(CD3D9Renderer* const _this, const char* pLayerName, bool activate)>(0xF4AF70);
	static inline auto FGetDeviceContext = PreyFunction<CCryDeviceContextWrapper& (CD3D9Renderer* const _this)>(0xECA4F0);
	static inline auto FEF_PrepareShadowGenRenderList = PreyFunction<void(CD3D9Renderer* const _this, CRenderView* pRenderView)>(0xF1FE00);
	static inline auto FEF_PrepareShadowGenForLight = PreyFunction<bool(CD3D9Renderer* const _this, CRenderView* pRenderView, SRenderLight* pLight, int nLightID)>(0xF1FC00);
	static inline auto FPrepareShadowGenForFrustum = PreyFunction<bool(CD3D9Renderer* const _this, CRenderView* pRenderView, ShadowMapFrustum* pCurFrustum, SRenderLight* pLight, int nLightID, int nLOD)>(0xF20AC0);
	static inline auto FEF_InvokeShadowMapRenderJobs = PreyFunction<void(CD3D9Renderer* const _this, CRenderView* pRenderView, const int nFlags)>(0xF0CA20);
	static inline auto FSetDepthBoundTest = PreyFunction<void(CD3D9Renderer* const _this, float fMin, float fMax, bool bEnable)>(0xED6820);
	static inline auto FCreateDeferredUnitBox = PreyFunction<void(CD3D9Renderer* const _this, stl::aligned_vector<unsigned short, 16>& indBuff, stl::aligned_vector<SVF_P3F_C4B_T2F, 16>& vertBuff)>(0xED6620);
	static inline auto FGetDeferredUnitBoxIndexBuffer = PreyFunction<stl::aligned_vector<unsigned short, 16> const& (CD3D9Renderer const* const _this)>(0xED6800);
	static inline auto FGetDeferredUnitBoxVertexBuffer = PreyFunction<stl::aligned_vector<SVF_P3F_C4B_T2F, 16> const& (CD3D9Renderer const* const _this)>(0xED6810);
	static inline auto FConfigShadowTexgen = PreyFunction<void(CD3D9Renderer* const _this, int Num, ShadowMapFrustum* pFr, int nFrustNum, bool bScreenToLocalBasis, bool bUseComparisonSampling)>(0xF1D210);
	static inline auto FDrawAllShadowsOnTheScreen = PreyFunction<void(CD3D9Renderer* const _this)>(0xF1ED80);
	static inline auto FOnEntityDeleted = PreyFunction<void(CD3D9Renderer* const _this, IRenderNode* pRenderNode)>(0xF20AA0);
	static inline auto FD3DSetCull = PreyFunction<void(CD3D9Renderer* const _this, ECull eCull, bool bSkipMirrorCull)>(0xEE0CA0);
	static inline auto FAdjustWindowForChange = PreyFunction<HRESULT(CD3D9Renderer* const _this)>(0xF22180);
	static inline auto FCreateWindowCallback = PreyFunction<HWND__* ()>(0xF247C0);
	static inline auto FSetWindow = PreyFunction<bool(CD3D9Renderer* const _this, int width, int height, EFullscreenMode _fullscreenMode, void* hWnd)>(0xF28090);
	static inline auto FSetRes = PreyFunction<bool(CD3D9Renderer* const _this)>(0xF27E90);
	static inline auto FRestoreGamma = PreyFunction<void(CD3D9Renderer* const _this)>(0xF27740);
	static inline auto FSetGamma = PreyFunction<void(CD3D9Renderer* const _this, float fGamma, float fBrightness, float fContrast, bool bForce)>(0xF279C0);
	static inline auto FOnD3D11CreateDevice = PreyFunction<HRESULT(ID3D11Device* pd3dDevice)>(0xF25DF0);
	static inline auto FOnD3D11PostCreateDevice = PreyFunction<HRESULT(ID3D11Device* pd3dDevice)>(0xF26200);
	static inline auto FRT_BeginFrame = PreyFunction<void(CD3D9Renderer* const _this)>(0xF51650);
	static inline auto FRT_EndFrame = PreyFunction<void(CD3D9Renderer* const _this)>(0xF52150);
	static inline auto FRT_BeginLoadingFrame = PreyFunction<void(CD3D9Renderer* const _this, unsigned _frameId)>(0xF51E90);
	static inline auto FRT_EndLoadingFrame = PreyFunction<void(CD3D9Renderer* const _this, unsigned _frameId)>(0xF52760);
	static inline auto FRT_SwitchToNativeResolutionBackbuffer = PreyFunction<void(CD3D9Renderer* const _this, bool resolveBackBuffer)>(0xF52A60);
	static inline auto FRT_Init = PreyFunction<void(CD3D9Renderer* const _this)>(0xF09580);
	static inline auto FRT_RenderWatermark = PreyFunction<void(CD3D9Renderer* const _this)>(0xA13080);
	static inline auto FRT_CreateDevice = PreyFunction<bool(CD3D9Renderer* const _this)>(0xF08400);
	static inline auto FRT_Reset = PreyFunction<void(CD3D9Renderer* const _this)>(0xF52920);
	static inline auto FRT_RenderScene = PreyFunction<void(CD3D9Renderer* const _this, CRenderView* pRenderView, int nFlags, SThreadInfo& TI, void (*RenderFunc)())>(0xF15770);
	static inline auto FRT_SetCull = PreyFunction<void(CD3D9Renderer* const _this, int mode)>(0xF52990);
	static inline auto FRT_SetScissor = PreyFunction<void(CD3D9Renderer* const _this, bool bEnable, int sX, int sY, int sWdt, int sHgt)>(0xEE6CD0);
	static inline auto FRT_SetCameraInfo = PreyFunction<void(CD3D9Renderer* const _this)>(0xF166D0);
	static inline auto FRT_CreateResource = PreyFunction<void(CD3D9Renderer* const _this, SResourceAsync* pRes)>(0xF08490);
	static inline auto FRT_ReleaseResource = PreyFunction<void(CD3D9Renderer* const _this, SResourceAsync* pRes)>(0xF09AD0);
	static inline auto FRT_ReleaseRenderResources = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags)>(0xF098B0);
	static inline auto FRT_UnbindResources = PreyFunction<void(CD3D9Renderer* const _this)>(0xF09BD0);
	static inline auto FRT_UnbindTMUs = PreyFunction<void(CD3D9Renderer* const _this)>(0xF09EC0);
	static inline auto FRT_CreateRenderResources = PreyFunction<void(CD3D9Renderer* const _this)>(0xF08410);
	static inline auto FRT_PrecacheDefaultShaders = PreyFunction<void(CD3D9Renderer* const _this)>(0xF09590);
	static inline auto FRT_ClearTarget = PreyFunction<void(CD3D9Renderer* const _this, CTexture* pTex, ColorF const& color)>(0xF08330);
	static inline auto FRT_ReleaseCB = PreyFunction<void(CD3D9Renderer* const _this, void* pVCB)>(0xF096F0);
	static inline auto FRT_ReleaseRS = PreyFunction<void(CD3D9Renderer* const _this, std::shared_ptr<CDeviceResourceSet>& pRS)>(0xF09850);
	static inline auto FRT_DrawDynVB = PreyFunction<void(CD3D9Renderer* const _this, SVF_P3F_C4B_T2F* pBuf, uint16_t* pInds, unsigned nVerts, unsigned nInds, PublicRenderPrimitiveType nPrimType)>(0xF08E60);
	static inline auto FRT_DrawStringW = PreyFunction<void(CD3D9Renderer const* const _this, IFFont_RenderProxy* pFont, float x, float y, float z, const wchar_t* pStr, const bool asciiMultiLine, STextDrawContext const& ctx)>(0xF094E0);
	static inline auto FRT_DrawLines = PreyFunction<void(CD3D9Renderer* const _this, Vec3* v, int nump, ColorF& col, int flags, float fGround)>(0xF09050);
	static inline auto FRT_Draw2dImage = PreyFunction<void(CD3D9Renderer* const _this, float xpos, float ypos, float w, float h, CTexture* pTexture, float s0, float t0, float s1, float t1, float angle, unsigned long col, float z)>(0xF085C0);
	static inline auto FRT_Draw2dImageStretchMode = PreyFunction<void(CD3D9Renderer* const _this, bool bStretch)>(0xF08E50);
	static inline auto FRT_Push2dImage = PreyFunction<void(CD3D9Renderer* const _this, float xpos, float ypos, float w, float h, CTexture* pTexture, float s0, float t0, float s1, float t1, float angle, unsigned long col, float z)>(0xF095A0);
	static inline auto FRT_Draw2dImageList = PreyFunction<void(CD3D9Renderer* const _this)>(0xF08DE0);
	static inline auto FRT_DrawImageWithUV = PreyFunction<void(CD3D9Renderer* const _this, float xpos, float ypos, float z, float w, float h, int texture_id, float* s, float* t, unsigned long col, bool filtered)>(0xF51ED0);
	static inline auto FRT_DrawImageWithUVInternal = PreyFunction<void(CD3D9Renderer* const _this, float xpos, float ypos, float z, float w, float h, int texture_id, float* s, float* t, unsigned long col, bool filtered)>(0xF51EF0);
	static inline auto FRT_Draw2dImageInternal = PreyFunction<void(CD3D9Renderer* const _this, CD3D9Renderer::S2DImage* images, unsigned numImages)>(0xF086B0);
	static inline auto FRT_SetViewport = PreyFunction<void(CD3D9Renderer* const _this, int x, int y, int width, int height, int id)>(0xF529D0);
	static inline auto FRT_RenderDebug = PreyFunction<void(CD3D9Renderer* const _this, bool bRenderStats)>(0xA13080);
	static inline auto FRT_SetRendererCVar = PreyFunction<void(CD3D9Renderer* const _this, ICVar* pCVar, const char* pArgText, const bool bSilentMode)>(0xF09B60);
	static inline auto FRT_PresentFast = PreyFunction<void(CD3D9Renderer* const _this)>(0xF52860);
	static inline auto FFlashRenderInternal = PreyFunction<void(CD3D9Renderer* const _this, IFlashPlayer_RenderProxy* pPlayer, bool bDoRealRender)>(0xF081D0);
	static inline auto FFlashRenderPlaybackLocklessInternal = PreyFunction<void(CD3D9Renderer* const _this, IFlashPlayer_RenderProxy* pPlayer, int cbIdx, bool bFinalPlayback, bool bDoRealRender)>(0xF08240);
	static inline auto FInit = PreyFunction<void* (CD3D9Renderer* const _this, int x, int y, int width, int height, unsigned cbpp, int zbpp, int sbits, EFullscreenMode _fullscreenMode, void* hinst, void* Glhwnd, bool bReInit, SCustomRenderInitArgs const* pCustomArgs, bool bShaderCacheGen)>(0xF24B20);
	static inline auto FGetVideoMemoryUsageStats = PreyFunction<void(CD3D9Renderer* const _this, uint64_t& vidMemUsedThisFrame, uint64_t& vidMemUsedRecently, bool bGetPoolsSizes)>(0xF24AD0);
	static inline auto FSetCurrentContext = PreyFunction<bool(CD3D9Renderer* const _this, void* hWnd)>(0xF27950);
	static inline auto FCreateContext = PreyFunction<bool(CD3D9Renderer* const _this, void* hWnd, bool bAllowMSAA, int SSX, int SSY, bool isMain)>(0xF23DA0);
	static inline auto FDeleteContext = PreyFunction<bool(CD3D9Renderer* const _this, void* hWnd)>(0xF24810);
	static inline auto FMakeMainContextActive = PreyFunction<void(CD3D9Renderer* const _this)>(0xF25A50);
	static inline auto FIsMainContextActive = PreyFunction<bool(CD3D9Renderer* const _this)>(0xF259F0);
	static inline auto FGetMainContextHWND = PreyFunction<void* (CD3D9Renderer* const _this)>(0xF4DF10);
	static inline auto FGetCurrentContextHWND = PreyFunction<void* (CD3D9Renderer* const _this)>(0xF4DBB0);
	static inline auto FIsCurrentContextMainVP = PreyFunction<bool(CD3D9Renderer* const _this)>(0xF50B30);
	static inline auto FGetCurrentContextViewportWidth = PreyFunction<int(CD3D9Renderer const* const _this)>(0xF4DBF0);
	static inline auto FGetCurrentContextViewportHeight = PreyFunction<int(CD3D9Renderer const* const _this)>(0xF4DBD0);
	static inline auto FCreateRenderTarget = PreyFunction<int(CD3D9Renderer* const _this, int nWidth, int nHeight, ColorF const& cClear, ETEX_Format eTF)>(0xF4C1E0);
	static inline auto FDestroyRenderTarget = PreyFunction<bool(CD3D9Renderer* const _this, int nHandle)>(0xF4C4C0);
	static inline auto FSetRenderTarget = PreyFunction<bool(CD3D9Renderer* const _this, int nHandle)>(0xF54DA0);
	static inline auto FChangeDisplay = PreyFunction<bool(CD3D9Renderer* const _this, unsigned width, unsigned height, unsigned cbpp)>(0xDD23F0);
	static inline auto FChangeViewport = PreyFunction<void(CD3D9Renderer* const _this, unsigned x, unsigned y, unsigned width, unsigned height, bool bMainViewport)>(0xF4B720);
	static inline auto FGetIArkVideoInfo = PreyFunction<IArkVideoInfo& (CD3D9Renderer* const _this)>(0xF4DC40);
	static inline auto FChangeResolution = PreyFunction<bool(CD3D9Renderer* const _this, int nNewWidth, int nNewHeight, int nNewColDepth, int nNewRefreshHZ, EFullscreenMode _fullscreenMode, bool bForceReset)>(0xF22550);
	static inline auto FReset = PreyFunction<void(CD3D9Renderer* const _this)>(0xF52D40);
	static inline auto FSwitchToNativeResolutionBackbuffer = PreyFunction<void(CD3D9Renderer* const _this)>(0xF54FC0);
	static inline auto FCalculateResolutions = PreyFunction<void(CD3D9Renderer* const _this, int width, int height, bool bUseNativeRes, int* pRenderWidth, int* pRenderHeight, int* pNativeWidth, int* pNativeHeight, int* pBackbufferWidth, int* pBackbufferHeight)>(0xF4B1E0);
	static inline auto FBeginFrame = PreyFunction<void(CD3D9Renderer* const _this, const bool _bUpdateFrameId)>(0xF4AF80);
	static inline auto FShutDown = PreyFunction<void(CD3D9Renderer* const _this, bool bReInit)>(0xF28390);
	static inline auto FShutDownFast = PreyFunction<void(CD3D9Renderer* const _this)>(0xF284B0);
	static inline auto FRenderDebug = PreyFunction<void(CD3D9Renderer* const _this, bool bRenderStats)>(0xF52D20);
	static inline auto FRT_ShutDown = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags)>(0xF27280);
	static inline auto FEndFrame = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4D7C0);
	static inline auto FLimitFramerate = PreyFunction<void(CD3D9Renderer* const _this, const int maxFPS, const bool bUseSleep)>(0xF50B50);
	static inline auto FLimitLoadingFramerate = PreyFunction<void(CD3D9Renderer* const _this)>(0xF50C50);
	static inline auto FGetMemoryUsage = PreyFunction<void(CD3D9Renderer* const _this, ICrySizer* Sizer)>(0xF4DF40);
	static inline auto FGetLogVBuffers = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4DC70);
	static inline auto FTryFlush = PreyFunction<void(CD3D9Renderer* const _this)>(0xF54FD0);
	static inline auto FDraw2dImageOv0 = PreyFunction<void(CD3D9Renderer* const _this, float xpos, float ypos, float w, float h, int textureid, float s0, float t0, float s1, float t1, float angle, float r, float g, float b, float a, float z)>(0xF4C920);
	static inline auto FPush2dImage = PreyFunction<void(CD3D9Renderer* const _this, float xpos, float ypos, float w, float h, int textureid, float s0, float t0, float s1, float t1, float angle, float r, float g, float b, float a, float z)>(0xF51500);
	static inline auto FDraw2dImageStretchMode = PreyFunction<void(CD3D9Renderer* const _this, bool bStretch)>(0xF4CA60);
	static inline auto FDraw2dImageList = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4CA50);
	static inline auto FDrawImage = PreyFunction<void(CD3D9Renderer* const _this, float xpos, float ypos, float w, float h, int texture_id, float s0, float t0, float s1, float t1, float r, float g, float b, float a, bool filtered)>(0xF4CB80);
	static inline auto FDrawImageWithUV = PreyFunction<void(CD3D9Renderer* const _this, float xpos, float ypos, float z, float w, float h, int texture_id, float* s, float* t, float r, float g, float b, float a, bool filtered)>(0xF4CCB0);
	static inline auto FSetCullMode = PreyFunction<void(CD3D9Renderer* const _this, int mode)>(0xF544B0);
	static inline auto FPushProfileMarker = PreyFunction<void(CD3D9Renderer* const _this, char* label)>(0xF51630);
	static inline auto FPopProfileMarker = PreyFunction<void(CD3D9Renderer* const _this, char* label)>(0xF50DA0);
	static inline auto FEnableFog = PreyFunction<bool(CD3D9Renderer* const _this, bool enable)>(0xF4D750);
	static inline auto FSetFogColor = PreyFunction<void(CD3D9Renderer* const _this, ColorF const& color)>(0xF54650);
	static inline auto FCreateResourceAsync = PreyFunction<void(CD3D9Renderer* const _this, SResourceAsync* pResource)>(0xF4C3A0);
	static inline auto FReleaseResourceAsync = PreyFunction<void(CD3D9Renderer* const _this, SResourceAsync* pResource)>(0xF52C70);
	static inline auto FDownLoadToVideoMemoryOv1 = PreyFunction<unsigned(CD3D9Renderer* const _this, uint8_t* data, int w, int h, ETEX_Format eTFSrc, ETEX_Format eTFDst, int nummipmap, bool repeat, int filter, int Id, const char* szCacheName, int flags, bool eEndian, RectI* pRegion, bool bAsyncDevTexCreation)>(0xF4C870);
	static inline auto FDownLoadToVideoMemoryOv0 = PreyFunction<unsigned(CD3D9Renderer* const _this, uint8_t* data, int w, int h, int d, ETEX_Format eTFSrc, ETEX_Format eTFDst, int nummipmap, ETEX_Type eTT, bool repeat, int filter, int Id, const char* szCacheName, int flags, bool eEndian, RectI* pRegion, bool bAsyncDevTexCreation)>(0xF4C4E0);
	static inline auto FUpdateTextureInVideoMemory = PreyFunction<void(CD3D9Renderer* const _this, unsigned tnum, uint8_t* newdata, int posx, int posy, int w, int h, ETEX_Format eTFSrc, int posz, int sizez)>(0xF551C0);
	static inline auto FEF_PrecacheResourceOv1 = PreyFunction<bool(CD3D9Renderer* const _this, SShaderItem* pSI, float fMipFactorSI, float fTimeToReady, int Flags, int nUpdateId, int nCounter)>(0xF4D2C0);
	static inline auto FEF_PrecacheResourceOv0 = PreyFunction<bool(CD3D9Renderer* const _this, ITexture* pTP, float fMipFactor, float fTimeToReady, int Flags, int nUpdateId, int nCounter)>(0xF4D5C0);
	static inline auto FRemoveTexture = PreyFunction<void(CD3D9Renderer* const _this, unsigned TextureId)>(0xF52C80);
	static inline auto FPrecacheTick = PreyFunction<void(CD3D9Renderer* const _this)>(0xF512F0);
	static inline auto FPostLevelLoading = PreyFunction<void(CD3D9Renderer* const _this)>(0xF50DB0);
	static inline auto FPostLevelUnload = PreyFunction<void(CD3D9Renderer* const _this)>(0xF50E70);
	static inline auto FSetRCamera = PreyFunction<void(CD3D9Renderer* const _this, CRenderCamera const& cam)>(0xF548C0);
	static inline auto FSetCamera = PreyFunction<void(CD3D9Renderer* const _this, CCamera const& cam)>(0xF53DB0);
	static inline auto FSetViewport = PreyFunction<void(CD3D9Renderer* const _this, int x, int y, int width, int height, int id)>(0xF54EF0);
	static inline auto FGetViewportOv1 = PreyFunction<void(CD3D9Renderer* const _this, int* x, int* y, int* width, int* height)>(0xF4F3D0);
	static inline auto FGetViewportOv0 = PreyFunction<SViewport(CD3D9Renderer const* const _this)>(0xF4F360);
	static inline auto FSetScissor = PreyFunction<void(CD3D9Renderer* const _this, int x, int y, int width, int height)>(0xF54E80);
	static inline auto FSetRenderTile = PreyFunction<void(CD3D9Renderer* const _this, float nTilesPosX, float nTilesPosY, float nTilesGridSizeX, float nTilesGridSizeY)>(0xF54E50);
	static inline auto FGraph = PreyFunction<void(CD3D9Renderer* const _this, uint8_t* g, int x, int y, int wdt, int hgt, int nC, int type, char* text, ColorF& color, float fScale)>(0xF4F470);
	static inline auto FDrawDynVB = PreyFunction<void(CD3D9Renderer* const _this, SVF_P3F_C4B_T2F* pBuf, uint16_t* pInds, int nVerts, int nInds, PublicRenderPrimitiveType nPrimType)>(0xEE0400);
	static inline auto FPrintResourcesLeaks = PreyFunction<void(CD3D9Renderer* const _this)>(0xA13080);
	static inline auto FFX_PushWireframeMode = PreyFunction<void(CD3D9Renderer* const _this, int mode)>(0xF4D920);
	static inline auto FFX_PopWireframeMode = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4D890);
	static inline auto FDrawPrimitivesInternal = PreyFunction<void(CD3D9Renderer* const _this, CVertexBuffer* src, int vert_num, ERenderPrimitiveType prim_type)>(0xF4CD80);
	static inline auto FResetToDefault = PreyFunction<void(CD3D9Renderer* const _this)>(0xF52D50);
	static inline auto FSetMaterialColor = PreyFunction<void(CD3D9Renderer* const _this, float r, float g, float b, float a)>(0xF546D0);
	static inline auto FProjectToScreen = PreyFunction<bool(CD3D9Renderer* const _this, float ptx, float pty, float ptz, float* sx, float* sy, float* sz)>(0xF51300);
	static inline auto FUnProjectFromScreen = PreyFunction<int(CD3D9Renderer* const _this, float sx, float sy, float sz, float* px, float* py, float* pz)>(0xF55000);
	static inline auto FGetModelViewMatrix = PreyFunction<void(CD3D9Renderer* const _this, float* mat)>(0xF4EAB0);
	static inline auto FGetProjectionMatrix = PreyFunction<void(CD3D9Renderer* const _this, float* mat)>(0xF4F100);
	static inline auto FGetCameraZeroMatrix = PreyFunction<void(CD3D9Renderer* const _this, float* mat)>(0xF4DAB0);
	static inline auto FSetMatrices = PreyFunction<void(CD3D9Renderer* const _this, float* pProjMat, float* pViewMat, float* pZeroMat)>(0xF54790);
	static inline auto FDrawQuad = PreyFunction<void(CD3D9Renderer* const _this, float x0, float y0, float x1, float y1, ColorF const& color, float z, float s0, float t0, float s1, float t1)>(0xF4CF90);
	static inline auto FDrawFullScreenTriangle = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4CA80);
	static inline auto FClearTargetsImmediatelyOv3 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags)>(0xF4BEE0);
	static inline auto FClearTargetsImmediatelyOv2 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, ColorF const& Colors, float fDepth)>(0xF4BF50);
	static inline auto FClearTargetsImmediatelyOv1 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, ColorF const& Colors)>(0xF4BF20);
	static inline auto FClearTargetsImmediatelyOv0 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, float fDepth)>(0xF4BF80);
	static inline auto FClearTargetsLaterOv3 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags)>(0xF4BFB0);
	static inline auto FClearTargetsLaterOv2 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, ColorF const& Colors, float fDepth)>(0xF4BFD0);
	static inline auto FClearTargetsLaterOv1 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, ColorF const& Colors)>(0xF4BFC0);
	static inline auto FClearTargetsLaterOv0 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, float fDepth)>(0xF4BFF0);
	static inline auto FSetRendererCVar = PreyFunction<void(CD3D9Renderer* const _this, ICVar* pCVar, const char* pArgText, const bool bSilentMode)>(0xF0A0F0);
	static inline auto FScreenShot = PreyFunction<bool(CD3D9Renderer* const _this, const char* filename, int iPreWidth, EScreenShotMode eScreenShotMode)>(0xF53140);
	static inline auto FSet2DMode = PreyFunction<void(CD3D9Renderer* const _this, bool enable, int ortox, int ortoy, float znear, float zfar)>(0xF53950);
	static inline auto FScreenToTexture = PreyFunction<int(CD3D9Renderer* const _this, int nTexID)>(0xF53910);
	static inline auto FSetGammaDelta = PreyFunction<bool(CD3D9Renderer* const _this, const float fGamma)>(0xF27E50);
	static inline auto FFontUploadTexture = PreyFunction<bool(CD3D9Renderer* const _this, CFBitmap* pBmp, ETEX_Format eTF)>(0xEE0AB0);
	static inline auto FFontCreateTexture = PreyFunction<int(CD3D9Renderer* const _this, int Width, int Height, uint8_t* pData, ETEX_Format eTF, bool genMips)>(0xEE0440);
	static inline auto FFontUpdateTexture = PreyFunction<bool(CD3D9Renderer* const _this, int nTexId, int nX, int nY, int USize, int VSize, uint8_t* pData)>(0xEE0A40);
	static inline auto FFontReleaseTexture = PreyFunction<void(CD3D9Renderer* const _this, CFBitmap* pBmp)>(0xEE04F0);
	static inline auto FFontSetTextureOv1 = PreyFunction<void(CD3D9Renderer* const _this, CFBitmap* pBmp, int nFilterMode)>(0xEE09E0);
	static inline auto FFontSetTextureOv0 = PreyFunction<void(CD3D9Renderer* const _this, int nTexId, int nFilterMode)>(0xEE0970);
	static inline auto FFontSetRenderingState = PreyFunction<void(CD3D9Renderer* const _this, unsigned nVPWidth, unsigned nVPHeight)>(0xEE0670);
	static inline auto FFontSetBlending = PreyFunction<void(CD3D9Renderer* const _this, int blendSrc, int blendDest)>(0xEE0630);
	static inline auto FFontRestoreRenderingState = PreyFunction<void(CD3D9Renderer* const _this)>(0xEE0570);
	static inline auto FFontSetState = PreyFunction<void(CD3D9Renderer* const _this, bool bRestore)>(0xEE0800);
	static inline auto FSF_CreateResources = PreyFunction<void(CD3D9Renderer* const _this)>(0xECA5D0);
	static inline auto FSF_PrecacheShaders = PreyFunction<void(CD3D9Renderer* const _this)>(0xECB480);
	static inline auto FSF_DestroyResources = PreyFunction<void(CD3D9Renderer* const _this)>(0xECA6D0);
	//static inline auto FSF_SetVertexDeclaration = PreyFunction<bool(CD3D9Renderer* const _this, SSF_GlobalDrawParams::EVertexFmt vertexFmt)>(0xECBDE0);
	//static inline auto FSF_SetBlendOp = PreyFunction<void(CD3D9Renderer* const _this, SSF_GlobalDrawParams::EAlphaBlendOp blendOp, bool reset)>(0xECBA80);
	static inline auto FSF_DrawIndexedTriList = PreyFunction<void(CD3D9Renderer* const _this, int baseVertexIndex, int minVertexIndex, int numVertices, int startIndex, int triangleCount, SSF_GlobalDrawParams const& params)>(0xECAC80);
	static inline auto FSF_DrawLineStrip = PreyFunction<void(CD3D9Renderer* const _this, int baseVertexIndex, int lineCount, SSF_GlobalDrawParams const& params)>(0xECB0A0);
	static inline auto FSF_DrawGlyphClear = PreyFunction<void(CD3D9Renderer* const _this, SSF_GlobalDrawParams const& params)>(0xECA9C0);
	static inline auto FSF_DrawBlurRect = PreyFunction<void(CD3D9Renderer* const _this, SSF_GlobalDrawParams const& params)>(0xECA700);
	static inline auto FSF_Flush = PreyFunction<void(CD3D9Renderer* const _this)>(0xECB350);
	static inline auto FSF_UpdateTexture = PreyFunction<bool(CD3D9Renderer* const _this, int texId, int mipLevel, int numRects, IRenderer::SUpdateRect const* pRects, uint8_t* pData, uint64_t pitch, uint64_t size, ETEX_Format eTF)>(0xECBE40);
	static inline auto FSetProfileMarker = PreyFunction<void(CD3D9Renderer const* const _this, const char* label, CRenderer::ESPM mode)>(0xA13080);
	static inline auto FEF_Scene3D = PreyFunction<void(CD3D9Renderer* const _this, SViewport& VP, int nFlags, SRenderingPassInfo const& passInfo)>(0xF0CAA0);
	static inline auto FCheckMSAAChange = PreyFunction<bool(CD3D9Renderer* const _this)>(0xDD23F0);
	static inline auto FCheckSSAAChange = PreyFunction<bool(CD3D9Renderer* const _this)>(0xF23310);
	static inline auto FFX_DrawInstances = PreyFunction<void(CD3D9Renderer* const _this, CShader* ef, SShaderPass* slw, int nRE, unsigned nStartInst, unsigned nLastInst, unsigned nUsedAttr, uint8_t* InstanceData, int nInstAttrMask, uint8_t* Attributes, int16_t dwCBufSlot)>(0xEE3000);
	static inline auto FFX_DrawShader_InstancedHW = PreyFunction<void(CD3D9Renderer* const _this, CShader* ef, SShaderPass* slw)>(0xEE3610);
	static inline auto FFX_DrawShader_General = PreyFunction<void(CD3D9Renderer* const _this, CShader* ef, SShaderTechnique* pTech)>(0xEE3440);
	static inline auto FFX_SetupForwardShadows = PreyFunction<void(CD3D9Renderer* const _this, CRenderView* pRenderView, bool bUseShaderPermutations)>(0xF1FF30);
	static inline auto FFX_SetupShadowsForTransp = PreyFunction<void(CD3D9Renderer* const _this)>(0xF200A0);
	static inline auto FCopyFramebufferDX11 = PreyFunction<void(CD3D9Renderer* const _this, CTexture* pDst, ID3D11Resource* pSrcResource, DXGI_FORMAT srcFormat)>(0xF0B700);
	static inline auto FFX_ScreenStretchRect = PreyFunction<void(CD3D9Renderer* const _this, CTexture* pDst)>(0xF0FF50);
	static inline auto FGetOcclusionBuffer = PreyFunction<int(CD3D9Renderer* const _this, float* pOutOcclBuffer, int nSizeX, int nSizeY, Matrix44* pmCamBuffer)>(0xF13FA0);
	static inline auto FWaitForParticleBuffer = PreyFunction<void(CD3D9Renderer* const _this)>(0xF501F0);
	static inline auto FInsertParticleVideoDataFence = PreyFunction<void(CD3D9Renderer* const _this)>(0xF501F0);
	static inline auto FFX_ZTargetReadBack = PreyFunction<void(CD3D9Renderer* const _this)>(0xF12300);
	static inline auto FFX_UpdateCharCBs = PreyFunction<void(CD3D9Renderer* const _this)>(0xF106F0);
	static inline auto FFX_AllocateCharInstCB = PreyFunction<void* (CD3D9Renderer* const _this, SSkinningData* pSkinningData, unsigned frameId)>(0xF0CF20);
	static inline auto FFX_ClearCharInstCB = PreyFunction<void(CD3D9Renderer* const _this, unsigned frameId)>(0xF0D1F0);
	static inline auto FCreateAuxiliaryMeshes = PreyFunction<bool(CD3D9Renderer* const _this)>(0xED8A70);
	static inline auto FReleaseAuxiliaryMeshes = PreyFunction<bool(CD3D9Renderer* const _this)>(0xED9C10);
	static inline auto FFX_DeferredShadowPassSetup = PreyFunction<bool(CD3D9Renderer* const _this, Matrix44 const& mShadowTexGen, CCamera const& cam, ShadowMapFrustum* pShadowFrustum, float maskRTWidth, float maskRTHeight, Matrix44& mScreenToShadow, bool bNearest)>(0xED90A0);
	static inline auto FFX_DeferredShadowPassSetupBlend = PreyFunction<bool(CD3D9Renderer* const _this, Matrix44 const& mShadowTexGen, CCamera const& cam, int nFrustumNum, float maskRTWidth, float maskRTHeight)>(0xED9980);
	static inline auto FFX_DrawTechnique = PreyFunction<void(CD3D9Renderer* const _this, CShader* ef, SShaderTechnique* pTech)>(0xEE3FE0);
	static inline auto FFX_RefractionPartialResolve = PreyFunction<void(CD3D9Renderer* const _this)>(0xEE4F40);
	static inline auto FFX_HDRScene = PreyFunction<bool(CD3D9Renderer* const _this, bool bEnableHDR, bool bClear)>(0xF0D450);
	static inline auto FFX_HDRRangeAdaptUpdate = PreyFunction<void(CD3D9Renderer* const _this)>(0xEE8CE0);
	static inline auto FFX_RenderForwardOpaque = PreyFunction<void(CD3D9Renderer* const _this, void (*RenderFunc)(), const bool bLighting, const bool bAllowDeferred)>(0xF0F330);
	static inline auto FFX_RenderWater = PreyFunction<void(CD3D9Renderer* const _this, void (*RenderFunc)())>(0xF0FB80);
	static inline auto FFX_ZScene = PreyFunction<bool(CD3D9Renderer* const _this, bool bEnable, bool bUseHDR, bool bClearZBuffer, bool bRenderNormalsOnly, bool bZPrePass)>(0xF12080);
	static inline auto FFX_DeferredWaterVolumeCaustics = PreyFunction<bool(CD3D9Renderer* const _this, N3DEngineCommon::SCausticInfo const& causticInfo)>(0xED8810);
	static inline auto FFX_CustomRenderScene = PreyFunction<bool(CD3D9Renderer* const _this, bool bEnable)>(0xFA3FC0);
	static inline auto FFX_PostProcessScene = PreyFunction<bool(CD3D9Renderer* const _this, bool bEnable)>(0xF59150);
	static inline auto FFX_DeferredRendering = PreyFunction<bool(CD3D9Renderer* const _this, CRenderView* pRenderView, bool bUpdateRTOnly)>(0xEDDB90);
	static inline auto FFX_DeferredDecals = PreyFunction<bool(CD3D9Renderer* const _this)>(0xEDD970);
	static inline auto FFX_ForwardDecals = PreyFunction<bool(CD3D9Renderer* const _this)>(0xEDDBD0);
	static inline auto FFX_LinearizeDepth = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0D590);
	static inline auto FFX_DepthFixupMerge = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0D290);
	static inline auto FFX_SceneMaskGen = PreyFunction<void(CD3D9Renderer* const _this, CRenderView* pRenderView)>(0xECFA60);
	static inline auto FGetGPUFrameTime = PreyFunction<float(CD3D9Renderer* const _this)>(0xF4DC20);
	static inline auto FGetRenderTimes = PreyFunction<void(CD3D9Renderer* const _this, IRenderer::SRenderTimes& outTimes)>(0xF4F330);
	static inline auto FFX_PipelineShutdown = PreyFunction<void(CD3D9Renderer* const _this, bool bFastShutdown)>(0xF0DB30);
	static inline auto FRT_GraphicsPipelineShutdown = PreyFunction<void(CD3D9Renderer* const _this)>(0xF15730);
	static inline auto FEF_ClearTargetsImmediatelyOv3 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags)>(0xEE0D70);
	static inline auto FEF_ClearTargetsImmediatelyOv2 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, ColorF const& Colors, float fDepth, uint8_t nStencil)>(0xEE0DD0);
	static inline auto FEF_ClearTargetsImmediatelyOv1 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, ColorF const& Colors)>(0xEE0DA0);
	static inline auto FEF_ClearTargetsImmediatelyOv0 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, float fDepth, uint8_t nStencil)>(0xEE0E00);
	static inline auto FEF_ClearTargetsLaterOv3 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags)>(0xEE0E20);
	static inline auto FEF_ClearTargetsLaterOv2 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, ColorF const& Colors, float fDepth, uint8_t nStencil)>(0xEE0E50);
	static inline auto FEF_ClearTargetsLaterOv1 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, ColorF const& Colors)>(0xEE0E30);
	static inline auto FEF_ClearTargetsLaterOv0 = PreyFunction<void(CD3D9Renderer* const _this, unsigned nFlags, float fDepth, uint8_t nStencil)>(0xEE1020);
	static inline auto FEF_Restore = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0CA30);
	static inline auto FFX_SetState = PreyFunction<void(CD3D9Renderer* const _this, int st, int AlphaRef, int RestoreState)>(0xEE5C80);
	static inline auto FChangeLog = PreyFunction<void(CD3D9Renderer* const _this)>(0xA13080);
	static inline auto FSetCurDownscaleFactor = PreyFunction<void(CD3D9Renderer* const _this, Vec2 sf)>(0xF544C0);
	static inline auto FCheckDeviceLost = PreyFunction<bool(CD3D9Renderer* const _this)>(0xF4BE10);
	static inline auto FEF_DirtyMatrix = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4D1C0);
	static inline auto FEF_PushMatrix = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4D6D0);
	static inline auto FEF_PopMatrix = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4D220);
	static inline auto FFX_ResetPipe = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0FE40);
	static inline auto FEF_SetVertColor = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4D730);
	static inline auto FFX_SetVertexDeclaration = PreyFunction<HRESULT(CD3D9Renderer* const _this, int StreamMask, EVertexFormat eVF)>(0xEE6770);
	static inline auto FFX_DrawBatch = PreyFunction<void(CD3D9Renderer* const _this, CShader* pSh, SShaderPass* pPass)>(0xEE2150);
	static inline auto FFX_DrawBatchSkinned = PreyFunction<void(CD3D9Renderer* const _this, CShader* pSh, SShaderPass* pPass, SSkinningData* pSkinningData)>(0xEE29E0);
	static inline auto FFX_SetActiveRenderTargets = PreyFunction<void(CD3D9Renderer* const _this)>(0xEE5470);
	static inline auto FFX_SetViewport = PreyFunction<void(CD3D9Renderer* const _this)>(0xEE6940);
	static inline auto FFX_ClearTargets = PreyFunction<void(CD3D9Renderer* const _this)>(0xEE15F0);
	static inline auto FFX_ClearTargetOv8 = PreyFunction<void(CD3D9Renderer* const _this, ID3D11RenderTargetView* pView, ColorF const& cClear, const unsigned numRects, tagRECT const* pRects)>(0xEE1200);
	static inline auto FFX_ClearTargetOv7 = PreyFunction<void(CD3D9Renderer* const _this, CTexture* pTex, ColorF const& cClear, const unsigned numRects, tagRECT const* pRects, const bool bOptionalRects)>(0xEE1530);
	static inline auto FFX_ClearTargetOv6 = PreyFunction<void(CD3D9Renderer* const _this, CTexture* pTex, ColorF const& cClear)>(0xEE14D0);
	static inline auto FFX_ClearTargetOv5 = PreyFunction<void(CD3D9Renderer* const _this, CTexture* pTex)>(0xEE1460);
	static inline auto FFX_ClearTargetOv4 = PreyFunction<void(CD3D9Renderer* const _this, ID3D11DepthStencilView* pView, const int nFlags, const float cDepth, const uint8_t cStencil, const unsigned numRects, tagRECT const* pRects)>(0xEE11A0);
	static inline auto FFX_ClearTargetOv3 = PreyFunction<void(CD3D9Renderer* const _this, SDepthTexture* pTex, const int nFlags, const float cDepth, const uint8_t cStencil, const unsigned numRects, tagRECT const* pRects, const bool bOptionalRects)>(0xEE1380);
	static inline auto FFX_ClearTargetOv2 = PreyFunction<void(CD3D9Renderer* const _this, SDepthTexture* pTex, const int nFlags, const float cDepth, const uint8_t cStencil)>(0xEE1330);
	static inline auto FFX_ClearTargetOv1 = PreyFunction<void(CD3D9Renderer* const _this, SDepthTexture* pTex, const int nFlags)>(0xEE12B0);
	static inline auto FFX_ClearTargetOv0 = PreyFunction<void(CD3D9Renderer* const _this, SDepthTexture* pTex)>(0xEE1240);
	static inline auto FFX_SetRenderTargetOv1 = PreyFunction<bool(CD3D9Renderer* const _this, int nTarget, ID3D11RenderTargetView* pTargetSurf, SDepthTexture* pDepthTarget, unsigned nTileCount)>(0xEE56F0);
	static inline auto FFX_SetRenderTargetOv0 = PreyFunction<bool(CD3D9Renderer* const _this, int nTarget, CTexture* pTarget, SDepthTexture* pDepthTarget, bool bPush, int nCMSide, bool bScreenVP, unsigned nTileCount)>(0xEE5790);
	static inline auto FFX_PushRenderTargetOv0 = PreyFunction<bool(CD3D9Renderer* const _this, int nTarget, CTexture* pTarget, SDepthTexture* pDepthTarget, int nCMSide, bool bScreenVP, unsigned nTileCount)>(0xEE4EE0);
	static inline auto FFX_RestoreRenderTarget = PreyFunction<bool(CD3D9Renderer* const _this, int nTarget)>(0xEE5300);
	static inline auto FFX_PopRenderTarget = PreyFunction<bool(CD3D9Renderer* const _this, int nTarget)>(0xEE4EB0);
	static inline auto FFX_GetDepthSurface = PreyFunction<SDepthTexture* (CD3D9Renderer* const _this, int nWidth, int nHeight, bool bAA, bool bExactMatch)>(0xEE4B70);
	static inline auto FFX_Commit = PreyFunction<void(CD3D9Renderer* const _this)>(0xEE1760);
	static inline auto FFX_SetFPMode = PreyFunction<bool(CD3D9Renderer* const _this)>(0xF1A320);
	static inline auto FFX_CommitStates = PreyFunction<void(CD3D9Renderer* const _this, SShaderTechnique const* pTech, SShaderPass const* pPass, bool bUseMaterialState)>(0xEE17D0);
	static inline auto FFX_SetVStream = PreyFunction<HRESULT(CD3D9Renderer* const _this, int nID, const void* pB, unsigned nOffs, unsigned nStride)>(0xF4DA30);
	static inline auto FFX_SetIStream = PreyFunction<HRESULT(CD3D9Renderer* const _this, const void* pB, unsigned nOffs, RenderIndexType idxType)>(0xF4D9D0);
	static inline auto FFX_DrawIndexedPrimitive = PreyFunction<void(CD3D9Renderer* const _this, ERenderPrimitiveType eType, const int nVBOffset, const int nMinVertexIndex, const int nVerticesCount, const int nStartIndex, const int nNumIndices, bool bInstanced)>(0xF4D7E0);
	static inline auto FFX_DrawPrimitive = PreyFunction<void(CD3D9Renderer* const _this, ERenderPrimitiveType eType, const int nStartVertex, const int nVerticesCount, const int nInstanceVertices)>(0xF4D840);
	static inline auto FFX_CommitStreams = PreyFunction<bool(CD3D9Renderer* const _this, SShaderPass* sl, bool bSetVertexDecl)>(0xEE1D30);
	static inline auto FEF_SetColorOp = PreyFunction<void(CD3D9Renderer* const _this, uint8_t eCo, uint8_t eAo, uint8_t eCa, uint8_t eAa)>(0xF0CD70);
	static inline auto FFX_PreRender = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0E1F0);
	static inline auto FFX_PostRender = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0E150);
	static inline auto FEF_Init = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0BB30);
	static inline auto FEF_SetCameraInfo = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0CD60);
	static inline auto FFX_ObjectChange = PreyFunction<bool(CD3D9Renderer* const _this, CShader* Shader, CShaderResources* Res, CRenderObject* obj, CRendElementBase* pRE)>(0xF0D8D0);
	static inline auto FScreenShotInternal = PreyFunction<bool(CD3D9Renderer* const _this, const char* filename, int width, EScreenShotMode eScreenShotMode)>(0xF53150);
	static inline auto FUpdateNearestChange = PreyFunction<void(CD3D9Renderer* const _this, int flags)>(0xF17840);
	static inline auto FUpdatePrevMatrix = PreyFunction<void(CD3D9Renderer* const _this, bool bEnable)>(0xF17AD0);
	static inline auto FFX_SetAdjacencyOffsetBuffer = PreyFunction<void(CD3D9Renderer* const _this)>(0xEE5690);
	static inline auto FFX_FlushShader_General = PreyFunction<void()>(0xEE4110);
	static inline auto FFX_FlushShader_ZPass = PreyFunction<void()>(0xEE45D0);
	static inline auto FFX_UpdateAnimatedShaderResources = PreyFunction<bool(CShaderResources const* shaderResources)>(0xEE6AE0);
	static inline auto FFX_UpdateDynamicShaderResources = PreyFunction<bool(CShaderResources const* shaderResources, unsigned batchFilter, unsigned flags2)>(0xEE6B40);
	static inline auto FFX_UnbindBuffer = PreyFunction<void(CD3D9Renderer* const _this, ID3D11Buffer* buffer)>(0xF10630);
	static inline auto FEF_Scissor = PreyFunction<void(CD3D9Renderer* const _this, bool bEnable, int sX, int sY, int sWdt, int sHgt)>(0xEE6CD0);
	static inline auto FEF_GetScissorState = PreyFunction<bool(CD3D9Renderer* const _this, int& sX, int& sY, int& sWdt, int& sHgt)>(0xEE1160);
	static inline auto FEF_SetFogColor = PreyFunction<void(CD3D9Renderer* const _this, ColorF const& Color)>(0xF0CE80);
	static inline auto FFX_FogCorrection = PreyFunction<void(CD3D9Renderer* const _this)>(0xEE4A50);
	static inline auto FFX_DrawIndexedMesh = PreyFunction<void(CD3D9Renderer* const _this, ERenderPrimitiveType nPrimType)>(0xEE2EF0);
	static inline auto FFX_SetResourcesState = PreyFunction<bool(CD3D9Renderer* const _this)>(0xEE5A90);
	static inline auto FDrawRenderItems = PreyFunction<void(CD3D9Renderer* const _this, SGraphicsPipelinePassContext const& passContext)>(0xF0BA20);
	static inline auto FFX_ProcessZPassRenderLists = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0EB40);
	static inline auto FFX_ProcessZPassRender_List = PreyFunction<void(CD3D9Renderer* const _this, ERenderListID list, unsigned filter)>(0xF0E8F0);
	static inline auto FFX_ProcessSkinRenderLists = PreyFunction<void(CD3D9Renderer* const _this, int nList, void (*RenderFunc)(), bool bLighting)>(0xF0E9E0);
	static inline auto FFX_ProcessEyeOverlayRenderLists = PreyFunction<void(CD3D9Renderer* const _this, int nList, void (*RenderFunc)(), bool bLighting)>(0xF0E2B0);
	static inline auto FFX_ProcessHalfResParticlesRenderList = PreyFunction<void(CD3D9Renderer* const _this, CRenderView* pRenderView, int nList, void (*RenderFunc)(), bool bLighting)>(0xF0E380);
	static inline auto FFX_WaterVolumesPreprocess = PreyFunction<void(CD3D9Renderer* const _this)>(0xF11D00);
	static inline auto FFX_ProcessPostRenderLists = PreyFunction<void(CD3D9Renderer* const _this, unsigned nBatchFilter)>(0xF0E810);
	static inline auto FFX_ProcessRenderListOv1 = PreyFunction<void(CD3D9Renderer* const _this, int nList, unsigned nBatchFilter)>(0xF0E8F0);
	static inline auto FFX_ProcessRenderListOv0 = PreyFunction<void(CD3D9Renderer* const _this, int nList, void (*RenderFunc)(), bool bLighting, unsigned nBatchFilter, unsigned nBatchExcludeFilter)>(0xF0E960);
	//static inline auto FOldPipeline_ProcessRenderList = PreyFunction<void(CD3D9Renderer* const _this, lockfree_add_vector<SRendItem>& renderItems, int nums, int nume, int nList, void (*RenderFunc)(), bool bLighting, unsigned nBatchFilter, unsigned nBatchExcludeFilter)>(0xF151B0);
	//static inline auto FOldPipeline_ProcessBatchesList = PreyFunction<void(CD3D9Renderer* const _this, lockfree_add_vector<SRendItem>& renderItems, int nums, int nume, unsigned nBatchFilter, unsigned nBatchExcludeFilter)>(0xF14DB0);
	static inline auto FFX_WaterVolumesCaustics = PreyFunction<void(CD3D9Renderer* const _this, CRenderView* pRenderView)>(0xF10880);
	static inline auto FFX_WaterVolumesCausticsPreprocess = PreyFunction<void(CD3D9Renderer* const _this, N3DEngineCommon::SCausticInfo& causticInfo)>(0xF11050);
	static inline auto FFX_WaterVolumesCausticsUpdateGrid = PreyFunction<bool(CD3D9Renderer* const _this, N3DEngineCommon::SCausticInfo& causticInfo)>(0xF11960);
	static inline auto FEF_EndEf3D = PreyFunction<void(CD3D9Renderer* const _this, const int nFlags, const int nPrecacheUpdateIdSlow, const int nPrecacheUpdateIdFast, SRenderingPassInfo const& passInfo)>(0xF0BA40);
	static inline auto FGetHWND = PreyFunction<void* (CD3D9Renderer* const _this)>(0xF24A30);
	static inline auto FSetColorOp = PreyFunction<void(CD3D9Renderer* const _this, uint8_t eCo, uint8_t eAo, uint8_t eCa, uint8_t eAa)>(0xF0CD70);
	static inline auto FAdjustHDROutputMode = PreyFunction<void(CD3D9Renderer* const _this)>(0xA13080);
	static inline auto FGetIRenderAuxGeom = PreyFunction<IRenderAuxGeom* (CD3D9Renderer* const _this, void* jobID)>(0xF4DC60);
	static inline auto FGetIArkRenderPersistentAuxGeom = PreyFunction<IArkRenderPersistentAuxGeom* (CD3D9Renderer* const _this)>(0xF4DC30);
	static inline auto FGetIColorGradingController = PreyFunction<IColorGradingController* (CD3D9Renderer* const _this)>(0xF4DC50);
	static inline auto FStartLoadtimeFlashPlayback = PreyFunction<void(CD3D9Renderer* const _this, ILoadtimeCallback* pCallback)>(0xF0A1E0);
	static inline auto FStopLoadtimeFlashPlayback = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0A470);
	static inline auto FStartLoadtimeBinkPlayback = PreyFunction<void(CD3D9Renderer* const _this, ILoadtimeCallback* pCallback)>(0xF0A100);
	static inline auto FStopLoadtimeBinkPlayback = PreyFunction<void(CD3D9Renderer* const _this)>(0xF0A2C0);
	static inline auto FGetRPPStats = PreyFunction<RPProfilerStats const* (CD3D9Renderer* const _this, ERenderPipelineProfilerStats eStat, bool bCalledFromMainThread)>(0xF4F1C0);
	static inline auto FGetRPPStatsArray = PreyFunction<RPProfilerStats const* (CD3D9Renderer* const _this, bool bCalledFromMainThread)>(0xF4F200);
	static inline auto FGetPolygonCountByType = PreyFunction<int(CD3D9Renderer* const _this, unsigned EFSList, EVertexCostTypes vct, unsigned z, bool bCalledFromMainThread)>(0x158AEF0);
	//static inline auto FCreateGraphiceDeviceConstantBuffer = PreyFunction<_smart_ptr<IGraphicsDeviceConstantBuffer>(CD3D9Renderer* const _this)>(0xF4C170);
	//static inline auto FGetGpuParticleManager = PreyFunction<gpu_pfx2::IManager* (CD3D9Renderer* const _this)>(0x158AEF0);
	static inline auto FHandleDisplayPropertyChanges = PreyFunction<void(CD3D9Renderer* const _this)>(0xF4FB40);
	static inline auto FCaptureFrameBufferToFile = PreyFunction<bool(CD3D9Renderer* const _this, const char* pFilePath, CTexture* pRenderTarget)>(0xF4B270);
	static inline auto FEnablePipelineProfiler = PreyFunction<void(CD3D9Renderer* const _this, bool bEnable)>(0xA13080);
	static inline auto FClearPerFrameData = PreyFunction<void(CD3D9Renderer* const _this, SRenderingPassInfo const& passInfo)>(0xF4BED0);
	static inline auto FCheckUpdateDimensions = PreyFunction<void(CD3D9Renderer* const _this, int& _width, int& _height)>(0xF23650);
	static inline auto FPeekWindowMessage = PreyFunction<void(CD3D9Renderer* const _this, unsigned message, uint64_t wParam, uint64_t lParam)>(0xF26E80);
};

static_assert(sizeof(CD3D9Renderer) == 46080);

enum { SPCBI_NUMBER_OF_BUFFERS = 64 };

#if 0
struct SPersistentConstBufferInfo
{
	uint64						m_crc[SPCBI_NUMBER_OF_BUFFERS];
	CConstantBuffer*	m_pStaticInstCB[SPCBI_NUMBER_OF_BUFFERS];
	int								m_frameID;
	int 							m_buffer;
};
#endif

#if 0
///////////////////////////////////////////////////////////////////////////////
inline void CD3D9Renderer::BindContextToThread(DWORD threadID)
{
#if ENABLE_CONTEXT_THREAD_CHECKING      
	m_DeviceOwningthreadID = threadID;
#endif 
}

///////////////////////////////////////////////////////////////////////////////
inline void CD3D9Renderer::CheckContextThreadAccess() const
{
#if ENABLE_CONTEXT_THREAD_CHECKING      
  if (m_DeviceOwningthreadID != CryGetCurrentThreadId()) 
    CryFatalError("accessing d3d11 immediate context from unbound thread!");
#endif 
}

///////////////////////////////////////////////////////////////////////////////
inline DWORD CD3D9Renderer::GetBoundThreadID() const
{ 
	return m_DeviceOwningthreadID; 
}

///////////////////////////////////////////////////////////////////////////////
inline void CD3D9Renderer::WaitForAsynchronousDevice() const
{
	if(m_nAsyncDeviceState)
	{
		CRY_PROFILE_REGION_WAITING(PROFILE_RENDERER, "Sync Async DIPS");
		CRYPROFILE_SCOPE_PROFILE_MARKER("Sync Async DIPS");

		while(m_nAsyncDeviceState) 
		{        
#if CRY_PLATFORM_ORBIS || CRY_PLATFORM_APPLE || CRY_PLATFORM_LINUX || CRY_PLATFORM_ANDROID
			CrySleep(0);
#else
			SwitchToThread(); 
#endif
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
inline volatile int* CD3D9Renderer::GetAsynchronousDeviceState()
{
	CryInterlockedIncrement(&m_nAsyncDeviceState);
	return &m_nAsyncDeviceState; 
	
}

//////////////////////////////////////////////////////////////////////////
inline void CD3D9Renderer::SetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY topType)
{
	if (m_CurTopology != topType)
	{
		m_CurTopology = topType;
		m_DevMan.BindTopology(m_CurTopology);
	}
}

inline bool CD3D9Renderer::GetDepthBoundTestState(float& fMin, float& fMax) const
{
	if (!m_bDeviceSupports_NVDBT)
		return false;
	fMin = m_fDepthBoundsMin;
	fMax = m_fDepthBoundsMax;
	return m_bDepthBoundsEnabled;
}

inline bool CD3D9Renderer::FX_SetStreamFlags(SShaderPass* pPass)
{
	if (CV_r_usehwskinning && m_RP.m_pRE && (m_RP.m_pRE->m_Flags & FCEF_SKINNED))
	{
		m_RP.m_FlagsStreams_Decl   |= VSM_HWSKIN;
		m_RP.m_FlagsStreams_Stream |= VSM_HWSKIN;
		return true;
	}

	return false;
}

inline uint32 CD3D9Renderer::ApplyIndexBufferBindOffset(uint32 firstIndex)
{
#if !defined(SUPPORT_FLEXIBLE_INDEXBUFFER)
	return firstIndex + (m_RP.m_IndexStreamOffset >> 1);
#else
	return firstIndex;
#endif
}

///////////////////////////////////////////////////////////////////////////////
inline CCryDeviceContextWrapper& CD3D9Renderer::GetDeviceContext()
{ 
	CheckContextThreadAccess(); 
	WaitForAsynchronousDevice(); 
	return m_DeviceContextWrapper; 
}

#if defined(DEVICE_SUPPORTS_PERFORMANCE_DEVICE)
///////////////////////////////////////////////////////////////////////////////
inline CCryPerformanceDeviceWrapper& CD3D9Renderer::GetPerformanceDevice()
{ 
	return m_PerformanceDeviceWrapper; 
}

///////////////////////////////////////////////////////////////////////////////
inline CCryPerformanceDeviceContextWrapper& CD3D9Renderer::GetPerformanceDeviceContext()
{ 
	CheckContextThreadAccess(); 
	WaitForAsynchronousDevice(); 
	return m_PerformanceDeviceContextWrapper; 
}
#endif // DEVICE_SUPPORTS_PERFORMANCE_DEVICE

#if defined(SUPPORT_DEVICE_INFO_USER_DISPLAY_OVERRIDES)
void UserOverrideDisplayProperties(DXGI_MODE_DESC& desc);
#endif
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
inline CCryDeviceWrapper& CD3D9Renderer::GetDevice()
{
	return m_DeviceWrapper;
}

inline const CCryDeviceWrapper& CD3D9Renderer::GetDevice() const
{
	return m_DeviceWrapper;
}

extern CD3D9Renderer* gcpRendD3D;

//=========================================================================================

//#include "D3DHWShader.h"

//#include "../Common/ParticleBuffer.h"
//#include "DeviceManager/TempDynBuffer.h"

//=========================================================================================

void HDR_DrawDebug();

#define STREAMED_TEXTURE_USAGE (CDeviceManager::USAGE_STREAMING)

void EnableCloseButton(void* hWnd, bool enabled);
