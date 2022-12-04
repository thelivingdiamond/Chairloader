// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

//#include <Prey/CryMemory/CryPool/PoolAlloc.h>
#include <Prey/CryMemory/CryMemoryManager.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CryThreading/IJobManager.h>
#include "TextMessages.h"                             // CTextMessages
#include "RenderThread.h"
#include "DevBuffer.h"
#include "RenderPipeline.h"
#include "Shadow_Renderer.h"
#include "Shaders/CShader.h"
#include "../XRenderD3D9/DeviceManager/DeviceManager.h"
//#include "RenderAuxGeom.h"
//#include "../Scaleform/ScaleformRender.h"

//typedef void (PROCRENDEF)(SShaderPass* l, int nPrimType);

class CTexture;
class CPostEffectsMgr;
class CWater;
class ArkBinkManager;
class CVertexBuffer;
struct IFFont;

#define USE_NATIVE_DEPTH 1

#if 0 && (CRY_PLATFORM_WINDOWS || CRY_PLATFORM_ORBIS) && !defined(OPENGL)
	#define SUPPORTS_MSAA 1

enum eMsaaParams
{
	MSAA_STENCILCULL                   = (0x1),
	MSAA_STENCILMASK_SET               = (0x2),
	MSAA_STENCILMASK_RESET_BIT         = (0x4),
	MSAA_SAMPLEFREQ_PASS               = (0x8),
	MSAA_SAMPLEFREQ_MASK_SET           = (0x10),
	MSAA_SAMPLEFREQ_MASK_CLEAR_STENCIL = (0x20),
};

#endif

enum eAntialiasingType
{
	eAT_NOAA = 0,
	eAT_SMAA_1X,
	eAT_SMAA_1TX,
	eAT_SMAA_2TX,
	eAT_TSAA,
	eAT_FXAA,
	eAT_AAMODES_COUNT,

	eAT_DEFAULT_AA                  = eAT_SMAA_2TX,

	eAT_NOAA_MASK                   = (1 << eAT_NOAA),
	eAT_SMAA_1X_MASK                = (1 << eAT_SMAA_1X),
	eAT_SMAA_1TX_MASK               = (1 << eAT_SMAA_1TX),
	eAT_SMAA_2TX_MASK               = (1 << eAT_SMAA_2TX),
	eAT_TSAA_MASK                   = (1 << eAT_TSAA),
	eAT_FXAA_MASK                   = (1 << eAT_FXAA),

	eAT_SMAA_MASK                   = (eAT_SMAA_1X_MASK | eAT_SMAA_1TX_MASK | eAT_SMAA_2TX_MASK),

	eAT_REQUIRES_PREVIOUSFRAME_MASK = (eAT_SMAA_1TX_MASK | eAT_SMAA_2TX_MASK | eAT_TSAA_MASK),
	eAT_REQUIRES_SUBPIXELSHIFT_MASK = (eAT_SMAA_2TX_MASK | eAT_TSAA_MASK)
};

static const char* s_pszAAModes[eAT_AAMODES_COUNT] =
{
	"NO AA",
	"SMAA 1X",
	"SMAA 1TX",
	"SMAA 2TX",
	"TSAA 1X"
	"FXAA 1X"
};

struct ShadowMapFrustum;
struct IStatObj;
struct SShaderPass;
class CREParticle;
class CD3DStereoRenderer;
class CTextureManager;
class CIntroMovieRenderer;
class IOpticsManager;
struct SDynTexture2;
class CDeviceResourceSet;

namespace compute_skinning { struct IComputeSkinningStorage; }

typedef int (* pDrawModelFunc)(void);

#define RENDER_LOCK_CS(csLock) CryAutoCriticalSection __AL__ ## __FILE__ ## _LINE(csLock)

//=============================================================

#define D3DRGBA(r, g, b, a)                                \
  ((((int)((a) * 255)) << 24) | (((int)((r) * 255)) << 16) \
   | (((int)((g) * 255)) << 8) | (int)((b) * 255)          \
  )

#define CONSOLES_BACKBUFFER_WIDTH  CRenderer::CV_r_ConsoleBackbufferWidth
#define CONSOLES_BACKBUFFER_HEIGHT CRenderer::CV_r_ConsoleBackbufferHeight

struct alloc_info_struct
{
	int         ptr;
	int         bytes_num;
	bool        busy;
	const char* szSource;
	unsigned Size()                                  { return sizeof(*this); }

	void     GetMemoryUsage(ICrySizer* pSizer) const {}
};

const float TANGENT30_2 = 0.57735026918962576450914878050196f * 2;   // 2*tan(30)

// Assuming 24 bits of depth precision
#define DBT_SKY_CULL_DEPTH                    0.99999994f

#define DEF_SHAD_DBT_DEFAULT_VAL              1

#define TEXSTREAMING_DEFAULT_VAL              1

#define GEOM_INSTANCING_DEFAULT_VAL           0
#define COLOR_GRADING_DEFAULT_VAL             1
#define SUNSHAFTS_DEFAULT_VAL                 2
#define HDR_RANGE_ADAPT_DEFAULT_VAL           0
#define HDR_RENDERING_DEFAULT_VAL             1
#define SHADOWS_POOL_DEFAULT_VAL              1
#define SHADOWS_CLIP_VOL_DEFAULT_VAL          1
#define SHADOWS_BLUR_DEFAULT_VAL              3
#define TEXPREALLOCATLAS_DEFAULT_VAL          0
#define TEXMAXANISOTROPY_DEFAULT_VAL          8
#if CRY_PLATFORM_DESKTOP
	#define TEXNOANISOALPHATEST_DEFAULT_VAL     0
#else
	#define TEXNOANISOALPHATEST_DEFAULT_VAL     1
#endif
#define ENVTEXRES_DEFAULT_VAL                 3
#define WATERREFLQUAL_DEFAULT_VAL             4
#define DOF_DEFAULT_VAL                       2
#define SHADERS_ALLOW_COMPILATION_DEFAULT_VAL 1
#define SHADERS_PREACTIVATE_DEFAULT_VAL       3
#define CUSTOMVISIONS_DEFAULT_VAL             3
#define FLARES_DEFAULT_VAL                    1
#define WATERVOLCAUSTICS_DEFAULT_VAL          1
#define FLARES_HQSHAFTS_DEFAULT_VAL           1
#define DEF_SHAD_DBT_STENCIL_DEFAULT_VAL      1
#define DEF_SHAD_SSS_DEFAULT_VAL              1

#define MULTITHREADED_DEFAULT_VAL             1
#define ZPASS_DEPTH_SORT_DEFAULT_VAL          1
#define TEXSTREAMING_UPDATETYPE_DEFAULT_VAL   1

#if CRY_PLATFORM_WINDOWS || CRY_PLATFORM_APPLE || CRY_PLATFORM_LINUX || CRY_PLATFORM_ANDROID
	#define CBUFFER_NATIVE_DEPTH_DEAFULT_VAL 1
#else
	#define CBUFFER_NATIVE_DEPTH_DEAFULT_VAL 0
#endif

#include "RendererCVars.h"                    // Can only be included after the default values are defined.

#if 0
struct SSpriteInfo
{
	SDynTexture2*             m_pTex;
	struct SSectorTextureSet* m_pTerrainTexInfo;
	Vec3                      m_vPos;
	float                     m_fDX;
	float                     m_fDY;
	float                     m_fScaleV;
	UCol                      m_Color;
	int                       m_nVI;
	uint8                     m_ucTexCoordMinX; // 0..128 used for the full range (0..1) in the texture (to fit in byte)
	uint8                     m_ucTexCoordMinY; // 0..128 used for the full range (0..1) in the texture (to fit in byte)
	uint8                     m_ucTexCoordMaxX; // 0..128 used for the full range (0..1) in the texture (to fit in byte)
	uint8                     m_ucTexCoordMaxY; // 0..128 used for the full range (0..1) in the texture (to fit in byte)
};

struct SSpriteGenInfo
{
	float          fAngle;                      // horizontal rotation in degree
	float          fGenDist;
	float          fBrightness;
	int            nMaterialLayers;
	IMaterial*     pMaterial;
	float*         pMipFactor;
	uint8*         pTexturesAreStreamedIn;
	SDynTexture2** ppTexture;
	IStatObj*      pStatObj;
	int            nSP;
};
#endif

class CMatrixStack
{
public:
	CMatrixStack(uint32 maxDepth, uint32 dirtyFlag);
	~CMatrixStack();

	// Pops the top of the stack, returns the current top
	// *after* popping the top.
	bool Pop();

	// Pushes the stack by one, duplicating the current matrix.
	bool Push();

	// Loads identity in the current matrix.
	bool LoadIdentity();

	// Loads the given matrix into the current matrix
	bool LoadMatrix(const Matrix44* pMat);

	// Right-Multiplies the given matrix to the current matrix.
	// (transformation is about the current world origin)
	bool MultMatrix(const Matrix44* pMat);

	// Left-Multiplies the given matrix to the current matrix
	// (transformation is about the local origin of the object)
	bool MultMatrixLocal(const Matrix44* pMat);

	// Right multiply the current matrix with the computed rotation
	// matrix, counterclockwise about the given axis with the given angle.
	// (rotation is about the current world origin)
	bool RotateAxis(const Vec3* pV, f32 Angle);

	// Left multiply the current matrix with the computed rotation
	// matrix, counterclockwise about the given axis with the given angle.
	// (rotation is about the local origin of the object)
	bool RotateAxisLocal(const Vec3* pV, f32 Angle);

	// Right multiply the current matrix with the computed rotation
	// matrix. All angles are counterclockwise. (rotation is about the
	// current world origin)

	// Right multiply the current matrix with the computed scale
	// matrix. (transformation is about the current world origin)
	bool Scale(f32 x, f32 y, f32 z);

	// Left multiply the current matrix with the computed scale
	// matrix. (transformation is about the local origin of the object)
	bool ScaleLocal(f32 x, f32 y, f32 z);

	// Right multiply the current matrix with the computed translation
	// matrix. (transformation is about the current world origin)
	bool Translate(f32 x, f32 y, f32 z);

	// Left multiply the current matrix with the computed translation
	// matrix. (transformation is about the local origin of the object)
	bool TranslateLocal(f32 x, f32 y, f32 z);

	// Obtain the current matrix at the top of the stack
	inline Matrix44A* GetTop()
	{
		assert(m_pTop != NULL);
		return m_pTop;
	}

	inline int GetDepth() { return m_nDepth; }

private:
	Matrix44*  m_pTop;        //top of the stack
	Matrix44*  m_pStack;      // array of Matrix44
	uint32     m_nDepth;
	uint32     m_nMaxDepth;
	uint32     m_nDirtyFlag; //flag for new matrices
};

static_assert(sizeof(CMatrixStack) == 32);

//////////////////////////////////////////////////////////////////////
// Class to manage memory for Skinning Renderer Data
class CSkinningDataPool
{
public:
	CSkinningDataPool()
		: m_pPool(NULL)
		, m_pPages(NULL)
		, m_nPoolSize(0)
		, m_nPoolUsed(0)
		, m_nPageAllocated(0)
	{}

	~CSkinningDataPool()
	{
		// free temp pages
		SPage* pPage = m_pPages;
		while (pPage)
		{
			SPage* pPageToDelete = pPage;
			pPage = pPage->pNext;

			CryModuleMemalignFree(pPageToDelete);
		}

		// free pool
		CryModuleMemalignFree(m_pPool);
	}

	byte* Allocate(size_t nBytes)
	{
		// If available use allocated page space
		uint32 nPoolUsed = ~0;
		do
		{

			nPoolUsed = *const_cast<volatile size_t*>(&m_nPoolUsed);
			size_t nPoolFree = m_nPoolSize - nPoolUsed;
			if (nPoolFree < nBytes)
				break; // not enough memory, use fallback
			if (CryInterlockedCompareExchange(alias_cast<volatile LONG*>(&m_nPoolUsed), nPoolUsed + nBytes, nPoolUsed) == nPoolUsed)
				return &m_pPool[nPoolUsed];

		}
		while (true);

		// Create memory
		byte* pMemory = alias_cast<byte*>(CryModuleMemalign(Align(nBytes, 16) + 16, 16));
		SPage* pNewPage = alias_cast<SPage*>(pMemory);

		// Assign page
		volatile SPage* pPages = 0;
		do
		{
			pPages = *(const_cast<volatile SPage**>(&m_pPages));
			pNewPage->pNext = alias_cast<SPage*>(pPages);

		}
		while (CryInterlockedCompareExchangePointer(alias_cast<void* volatile*>(&m_pPages), pNewPage, (void*)pPages) != pPages);

		CryInterlockedAdd((volatile int*)&m_nPageAllocated, nBytes);

		return pMemory + 16;
	}

	void ClearPool()
	{
		m_nPoolUsed = 0;
		if (m_nPageAllocated)
		{
			// free temp pages
			SPage* pPage = m_pPages;
			while (pPage)
			{
				SPage* pPageToDelete = pPage;
				pPage = pPage->pNext;

				CryModuleMemalignFree(pPageToDelete);
			}

			// adjust pool size
			CryModuleMemalignFree(m_pPool);
			m_nPoolSize += m_nPageAllocated;
			m_pPool = alias_cast<byte*>(CryModuleMemalign(m_nPoolSize, 16));

			// reset state
			m_pPages = NULL;
			m_nPageAllocated = 0;
		}
	}

	void FreePoolMemory()
	{
		// free temp pages
		SPage* pPage = m_pPages;
		while (pPage)
		{
			SPage* pPageToDelete = pPage;
			pPage = pPage->pNext;

			CryModuleMemalignFree(pPageToDelete);
		}

		// free pool
		CryModuleMemalignFree(m_pPool);

		m_pPool = NULL;
		m_pPages = NULL;
		m_nPoolSize = 0;
		m_nPoolUsed = 0;
		m_nPageAllocated = 0;
	}

	size_t AllocatedMemory()
	{
		return m_nPoolSize + m_nPageAllocated;
	}
private:
	struct SPage
	{
		SPage* pNext;
	};

	byte*  m_pPool;
	SPage* m_pPages;
	size_t m_nPoolSize;
	size_t m_nPoolUsed;
	size_t m_nPageAllocated;
};

static_assert(sizeof(CSkinningDataPool) == 40);

//////////////////////////////////////////////////////////////////////
#if 0
class CFillRateManager : private stl::PSyncDebug
{
public:
	CFillRateManager()
		: m_fTotalPixels(0.f), m_fMaxPixels(1e9f)
	{}
	void Reset()
	{
		m_fTotalPixels = 0.f;
		m_afPixels.resize(0);
	}
	float GetMaxPixels() const
	{
		return m_fMaxPixels;
	}
	void AddPixelCount(float fPixels);
	void ComputeMaxPixels();

private:
	float               m_fTotalPixels;
	float               m_fMaxPixels;
	FastDynArray<float> m_afPixels;
};
#endif

class CFillRateManager
{
	int pad[32 / sizeof(int)];
};

//////////////////////////////////////////////////////////////////////
// 3D engine duplicated data for non-thread safe data
namespace N3DEngineCommon
{

struct SOceanInfo
{
	SOceanInfo() : m_fWaterLevel(0.0f), m_vCausticsParams(0.0f, 0.0f, 0.0f, 0.0f), m_vMeshParams(0.0f, 0.0f, 0.0f, 0.0f) {};
	Vec4  m_vCausticsParams;
	Vec4  m_vMeshParams;
	float m_fWaterLevel;
};

struct SVisAreaInfo
{
	SVisAreaInfo() : nFlags(0)
	{
	};
	uint32 nFlags;
};

struct SRainOccluder
{
	SRainOccluder() : m_RndMesh(0), m_WorldMat(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0) {}
	_smart_ptr<IRenderMesh> m_RndMesh;
	Matrix34                m_WorldMat;
};

typedef std::vector<SRainOccluder> ArrOccluders;

struct SRainOccluders
{
	ArrOccluders m_arrOccluders;
	ArrOccluders m_arrCurrOccluders[RT_COMMAND_BUF_COUNT];
	size_t       m_nNumOccluders;
	bool         m_bProcessed[MAX_GPU_NUM];

	SRainOccluders() : m_nNumOccluders(0) { for (int i = 0; i < MAX_GPU_NUM; ++i) m_bProcessed[i] = true; }
	~SRainOccluders()                                                  { Release(); }
	void Release(bool bAll = false)
	{
		stl::free_container(m_arrOccluders);
		m_nNumOccluders = 0;
		if (bAll)
		{
			for (int i = 0; i < RT_COMMAND_BUF_COUNT; i++)
				stl::free_container(m_arrCurrOccluders[i]);
		}
		for (int i = 0; i < MAX_GPU_NUM; ++i) m_bProcessed[i] = true;
	}
};

struct SCausticInfo
{
	SCausticInfo() : m_pCausticQuadMesh(0), m_nCausticMeshWidth(0), m_nCausticMeshHeight(0), m_nCausticQuadTaps(0), m_nVertexCount(0), m_nIndexCount(0)
	{
	}

	~SCausticInfo() { Release(); }
	void Release()
	{
		m_pCausticQuadMesh = NULL;
	}

	_smart_ptr<IRenderMesh> m_pCausticQuadMesh;
	uint32                  m_nCausticMeshWidth;
	uint32                  m_nCausticMeshHeight;
	uint32                  m_nCausticQuadTaps;
	uint32                  m_nVertexCount;
	uint32                  m_nIndexCount;

	Matrix44A               m_mCausticMatr;
	Matrix34                m_mCausticViewMatr;
};
}

struct S3DEngineCommon
{
	enum EVisAreaFlags
	{
		VAF_EXISTS_FOR_POSITION    = (1 << 0),
		VAF_CONNECTED_TO_OUTDOOR   = (1 << 1),
		VAF_AFFECTED_BY_OUT_LIGHTS = (1 << 2),
		VAF_MASK                   = VAF_EXISTS_FOR_POSITION | VAF_CONNECTED_TO_OUTDOOR | VAF_AFFECTED_BY_OUT_LIGHTS
	};

	N3DEngineCommon::SVisAreaInfo   m_pCamVisAreaInfo;
	//N3DEngineCommon::SOceanInfo     m_OceanInfo;
	//N3DEngineCommon::SRainOccluders m_RainOccluders;
	N3DEngineCommon::SCausticInfo   m_CausticInfo;
	//SRainParams                     m_RainInfo;
	//SSnowParams                     m_SnowInfo;

	void Update(threadID nThreadID);
	void UpdateRainInfo(threadID nThreadID);
	void UpdateRainOccInfo(int nThreadID);
	void UpdateSnowInfo(int nThreadID);
};

static_assert(sizeof(S3DEngineCommon) == 160);

struct SShowRenderTargetInfo
{
	SShowRenderTargetInfo() { Reset(); }
	void Reset()
	{
		bShowList = false;
		bDisplayTransparent = false;
		col = 2;
		rtList.clear();
	}

	bool bShowList;
	bool bDisplayTransparent;
	int  col;
	struct RT
	{
		CTexture* pTexture;
		Vec4      channelWeight;
		bool      bFiltered;
		bool      bRGBKEncoded;
		bool      bAliased;
	};
	std::vector<RT> rtList;
};

static_assert(sizeof(SShowRenderTargetInfo) == 32);
static_assert(sizeof(SShowRenderTargetInfo::RT) == 32);

struct SRenderTileInfo
{
	SRenderTileInfo() { nPosX = nPosY = nGridSizeX = nGridSizeY = 0.f; }
	f32 nPosX, nPosY, nGridSizeX, nGridSizeY;
};

//////////////////////////////////////////////////////////////////////
class CRenderer : public IRenderer, public CRendererCVars
{
	friend class CRendererCVars;

public:
	enum ESPM
	{
		ESPM_PUSH = 0,
		ESPM_POP = 1,
	};

	volatile bool m_bStopRendererAtFrameEnd;
	Matrix44A m_IdentityMatrix;
	Matrix44A m_ViewMatrix;
	Matrix44A m_CameraMatrix;
	Matrix44A m_CameraZeroMatrix;
	Matrix44A m_ProjMatrix;
	Matrix44A m_TranspOrigCameraProjMatrix;
	Matrix44A m_CameraProjMatrix;
	Matrix44A m_CameraProjZeroMatrix;
	Matrix44A m_InvCameraProjMatrix;
	Matrix44A m_TempMatrices[4][8];
	Matrix44A m_CameraMatrixPrev[7];
	Matrix44A m_CameraProjMatrixPrev;
	Matrix44A m_CameraProjMatrixPrevAvg;
	Matrix44A m_CameraMatrixNearest;
	Matrix44A m_CameraMatrixNearestPrev;
	Vec2 m_vProjMatrixSubPixoffset;
	Vec3 m_vSegmentedWorldOffset;
	uint8_t m_bDeviceLost;
	uint8_t m_bSystemResourcesInit;
	uint8_t m_bSystemTargetsInit;
	bool m_bAquireDeviceThread;
	bool m_bInitialized;
	SRenderThread* m_pRT;
	CDeviceManager m_DevMan;
	CDeviceBufferManager m_DevBufMan;
	SRenderPipeline m_RP;
	CIntroMovieRenderer* m_pIntroMovieRenderer;
	float m_fTimeWaitForMain[2];
	float m_fTimeWaitForRender[2];
	float m_fTimeProcessedRT[2];
	float m_fTimeProcessedGPU[2];
	float m_fTimeWaitForGPU[2];
	float m_fTimeGPUIdlePercent[2];
	float m_fRTTimeEndFrame;
	float m_fRTTimeFlashRender;
	float m_fRTTimeSceneRender;
	float m_fRTTimeMiscRender;
	int m_VSync;
	int m_Predicated;
	int m_deskwidth;
	int m_deskheight;
	int m_nHDRType;
	int m_nGraphicsPipeline;
	int m_CurViewportID;
	float m_overrideRefreshRate;
	int m_overrideScanlineOrder;
	int m_overrideDXGIOutput;
	int m_prefMonX;
	int m_prefMonY;
	int m_prefMonWidth;
	int m_prefMonHeight;
	int m_nStencilMaskRef;
	uint8_t m_bDeviceSupportsInstancing;
	unsigned m_bDeviceSupportsTessellation : 1;
	unsigned m_bUseHWSkinning : 1;
	unsigned m_bEndLevelLoading : 1;
	unsigned m_bStartLevelLoading : 1;
	unsigned m_bUseWaterTessHW : 1;
	unsigned m_bUseSilhouettePOM : 1;
	unsigned m_bIsWindowActive : 1;
	unsigned m_bInShutdown : 1;
	unsigned m_bShadowsEnabled : 1;
	unsigned m_bVolFogShadowsEnabled : 1;
	uint8_t m_nDisableTemporalEffects;
	bool m_bUseGPUFriendlyBatching[2];
	unsigned m_nGPULimited;
	int8_t m_nCurMaxAniso;
	float m_nCurMipLodBias;
	unsigned m_nShadowPoolHeight;
	unsigned m_nShadowPoolWidth;
	unsigned long m_Features;
	int m_MaxTextureSize;
	uint64_t m_MaxTextureMemory;
	int m_nShadowTexSize;
	float m_fLastGamma;
	float m_fLastBrightness;
	float m_fLastContrast;
	float m_fDeltaGamma;

	enum
	{
		nMeshPoolMaxTimeoutCounter = 150,
	};

	int m_nMeshPoolTimeoutCounter;
	SVF_P3F_C4B_T2F* m_pSpriteVerts;
	uint16_t* m_pSpriteInds;
	int m_nFlushAllPendingTextureStreamingJobs;
	float m_fTexturesStreamingGlobalMipFactor;
	unsigned m_nPoolIndex;
	unsigned m_nPoolIndexRT;
	CCamera m_prevCamera;
	unsigned m_nFrameLoad;
	unsigned m_nFrameReset;
	unsigned m_nFrameSwapID;
	ColorF m_cClearColor;
	int m_NumResourceSlots;
	int m_NumSamplerSlots;
	Vec2 m_ReqViewportScale;
	Vec2 m_CurViewportScale;
	Vec2 m_PrevViewportScale;
	tagRECT m_FullResRect;
	CPostEffectsMgr* m_pPostProcessMgr;
	CWater* m_pWaterSimMgr;
	CTextureManager* m_pTextureManager;
	ArkBinkManager* m_pBinkManager;
	float m_fPrevTime;
	uint8_t m_nUseZpass : 2;
	int m_dwHDRCropWidth;
	int m_dwHDRCropHeight;
	S3DEngineCommon m_p3DEngineCommon;

	using ShadowFrustumListsCache = std::map<unsigned __int64, PodArray<unsigned short, 0>*, std::less<unsigned __int64>>;

	std::map<unsigned __int64, PodArray<unsigned short, 0>*, std::less<unsigned __int64>> m_FrustumsCache;
	ShadowFrustumMGPUCache m_ShadowFrustumMGPUCache;
	CShaderMan m_cEF;
	_smart_ptr<IMaterial> m_pDefaultMaterial;
	_smart_ptr<IMaterial> m_pTerrainDefaultMaterial;
	int m_TexGenID;
	IFFont* m_pDefaultFont;
	CryCriticalSection m_renderObjectAccessLock;
	static int m_iGeomInstancingThreshold;
	static constexpr const int nMaxParticleContainer = 8192;
	int m_nCREParticleCount[2];
	JobManager::SJobState m_ComputeVerticesJobState;
	CFillRateManager m_FillRateManager;
	_iobuf* m_LogFile;
	_iobuf* m_LogFileStr;
	_iobuf* m_LogFileSh;
	SViewport m_MainRTViewport;
	SViewport m_MainViewport;
	SViewport m_CurViewport;
	SViewport m_NewViewport;
	bool m_bViewportDirty;
	bool m_bViewportDisabled;
	int m_nCurVPStackLevel;
	SViewport m_VPStack[8];
	int m_width;
	int m_height;
	int m_cbpp;
	int m_zbpp;
	int m_sbpp;
	int m_nativeWidth;
	int m_nativeHeight;
	int m_backbufferWidth;
	int m_backbufferHeight;
	int m_numSSAASamples;
	int m_wireframe_mode;
	int m_wireframe_mode_prev;
	unsigned m_nGPUs;
	float m_drawNearFov;
	float m_pixelAspectRatio;
	float m_shadowJittering;
	StaticArray<int, 16, int> m_CachedShadowsResolution;
	CTextMessages m_TextMessages[2];
	CSkinningDataPool m_SkinningDataPool[3];
	unsigned m_nShadowGenId[2];
	SSF_GlobalDrawParams const* m_pSFDrawParams;
	bool m_bTimeProfileUpdated;
	int m_PrevProfiler;
	int m_nCurSlotProfiler;
	int m_beginFrameCount;

	using TListRendererEventListeners = std::list<IRendererEventListener*, std::allocator<IRendererEventListener*> >;

	std::list<IRendererEventListener*, std::allocator<IRendererEventListener*> > m_listRendererEventListeners;
	SShowRenderTargetInfo m_showRenderTargetInfo;
	std::vector<ISyncMainWithRenderListener*> m_syncMainWithRenderListeners;
	CryConditionVariable::LockType m_mtxStopAtRenderFrameEnd;
	CryConditionVariable m_condStopAtRenderFrameEnd;

	CRenderer();
	virtual ~CRenderer();
	virtual void InitRenderer();
	virtual void PostInit();
	virtual bool CreateDeviceMemoryHeap(EDeviceMemoryHeap _heapId, EDeviceMemoryType _type, uint64_t _size, uint64_t _bankSize, uint64_t _reserveSize);
	virtual void StartRenderIntroMovies(bool skipArkIntro);
	virtual void StopRenderIntroMovies(bool bWaitForFinished);
	virtual bool IsRenderingIntroMovies() const;
	virtual void PostLevelLoading();
	void PreShutDown() { FPreShutDown(this); }
	void PostShutDown() { FPostShutDown(this); }
	virtual void SuspendDevice();
	virtual void ResumeDevice();
	virtual void SyncComputeVerticesJobs();
	virtual void DrawStringW(IFFont_RenderProxy* pFont, float x, float y, float z, const wchar_t* pStr, const bool asciiMultiLine, STextDrawContext const& ctx) const;
	virtual void RT_DrawStringW(IFFont_RenderProxy* arg0, float arg1, float arg2, float arg3, const wchar_t* arg4, const bool arg5, STextDrawContext const& arg6) const = 0;
	virtual void RT_DrawLines(Vec3* arg0, int arg1, ColorF& arg2, int arg3, float arg4) = 0;
	virtual void RT_RenderWatermark() = 0;
	virtual void RT_PresentFast() = 0;
	virtual int RT_CurThreadList();
	virtual void RT_BeginFrame() = 0;
	virtual void RT_EndFrame() = 0;
	virtual void RT_BeginLoadingFrame(unsigned arg0) = 0;
	virtual void RT_EndLoadingFrame(unsigned arg0) = 0;
	virtual void RT_SwitchToNativeResolutionBackbuffer(bool arg0) = 0;
	virtual void RT_Init() = 0;
	virtual void RT_ShutDown(unsigned arg0) = 0;
	virtual bool RT_CreateDevice() = 0;
	virtual void RT_Reset() = 0;
	virtual void RT_FlushTextMessages();
	virtual void RT_SetCull(int arg0) = 0;
	virtual void RT_SetScissor(bool arg0, int arg1, int arg2, int arg3, int arg4) = 0;
	virtual void RT_RenderScene(CRenderView* arg0, int arg1, SThreadInfo& arg2, void (*arg3)()) = 0;
	virtual void RT_SetCameraInfo() = 0;
	virtual void RT_CreateResource(SResourceAsync* arg0) = 0;
	virtual void RT_ReleaseResource(SResourceAsync* arg0) = 0;
	virtual void RT_ReleaseRenderResources(unsigned arg0) = 0;
	virtual void RT_UnbindResources() = 0;
	virtual void RT_UnbindTMUs() = 0;
	virtual void RT_CreateRenderResources() = 0;
	virtual void RT_PrecacheDefaultShaders() = 0;
	virtual void RT_CreateREPostProcess(CRendElementBase** re);
	virtual void RT_FlashRender(IFlashPlayer_RenderProxy* pPlayer);
	virtual void RT_FlashRenderPlaybackLockless(IFlashPlayer_RenderProxy* pPlayer, int cbIdx, bool finalPlayback);
	virtual void RT_FlashRemoveTexture(ITexture* pTexture);
	virtual void RT_ReleaseCB(void* arg0) = 0;
	virtual void RT_ReleaseRS(std::shared_ptr<CDeviceResourceSet>& arg0) = 0;
	virtual void RT_DrawDynVB(SVF_P3F_C4B_T2F* arg0, uint16_t* arg1, unsigned arg2, unsigned arg3, PublicRenderPrimitiveType arg4) = 0;
	virtual void RT_Draw2dImage(float arg0, float arg1, float arg2, float arg3, CTexture* arg4, float arg5, float arg6, float arg7, float arg8, float arg9, unsigned long arg10, float arg11) = 0;
	virtual void RT_Draw2dImageStretchMode(bool arg0) = 0;
	virtual void RT_Push2dImage(float arg0, float arg1, float arg2, float arg3, CTexture* arg4, float arg5, float arg6, float arg7, float arg8, float arg9, unsigned long arg10, float arg11) = 0;
	virtual void RT_Draw2dImageList() = 0;
	virtual void RT_DrawImageWithUV(float arg0, float arg1, float arg2, float arg3, float arg4, int arg5, float* arg6, float* arg7, unsigned long arg8, bool arg9) = 0;
	virtual void RT_SetViewport(int arg0, int arg1, int arg2, int arg3, int arg4) = 0;
	virtual void RT_ClearTarget(CTexture* arg0, ColorF const& arg1) = 0;
	virtual void RT_RenderDebug(bool arg0) = 0;
	virtual void RT_SetRendererCVar(ICVar* arg0, const char* arg1, const bool arg2) = 0;
	void RT_PostLevelLoading() { FRT_PostLevelLoading(this); }
	void RT_DisableTemporalEffects() { FRT_DisableTemporalEffects(this); }
	virtual void FlashRenderInternal(IFlashPlayer_RenderProxy* arg0, bool arg1) = 0;
	virtual void FlashRenderPlaybackLocklessInternal(IFlashPlayer_RenderProxy* arg0, int arg1, bool arg2, bool arg3) = 0;
	virtual bool FlushRTCommands(bool bWait, bool bImmediatelly, bool bForce);
	virtual bool ForceFlushRTCommands();
	virtual void WaitForParticleBuffer() = 0;
	virtual void RequestFlushAllPendingTextureStreamingJobs(int nFrames);
	virtual void SetTexturesStreamingGlobalMipFactor(float fFactor);
	virtual void EF_ClearTargetsImmediately(unsigned arg0) = 0;
	virtual void EF_ClearTargetsImmediately(unsigned arg0, ColorF const& arg1, float arg2, uint8_t arg3) = 0;
	virtual void EF_ClearTargetsImmediately(unsigned arg0, ColorF const& arg1) = 0;
	virtual void EF_ClearTargetsImmediately(unsigned arg0, float arg1, uint8_t arg2) = 0;
	virtual void EF_ClearTargetsLater(unsigned arg0) = 0;
	virtual void EF_ClearTargetsLater(unsigned arg0, ColorF const& arg1, float arg2, uint8_t arg3) = 0;
	virtual void EF_ClearTargetsLater(unsigned arg0, ColorF const& arg1) = 0;
	virtual void EF_ClearTargetsLater(unsigned arg0, float arg1, uint8_t arg2) = 0;
	virtual void AddListener(IRendererEventListener* pRendererEventListener);
	virtual void RemoveListener(IRendererEventListener* pRendererEventListener);
	virtual ERenderType GetRenderType() const;
	virtual void* Init(int arg0, int arg1, int arg2, int arg3, unsigned arg4, int arg5, int arg6, EFullscreenMode arg7, void* arg8, void* arg9, bool arg10, SCustomRenderInitArgs const* arg11, bool arg12) = 0;
	virtual void* GetCurrentContextHWND();
	virtual bool IsCurrentContextMainVP();
	virtual int GetFeatures();
	virtual int GetNumGeomInstances();
	virtual int GetNumGeomInstanceDrawCalls();
	virtual int GetCurrentNumberOfDrawCalls();
	virtual void GetCurrentNumberOfDrawCalls(int& nGeneral, int& nShadowGen);
	virtual int GetCurrentNumberOfDrawCalls(const unsigned EFSListMask);
	virtual float GetCurrentDrawCallRTTimes(const unsigned EFSListMask);
	virtual bool ChangeResolution(int arg0, int arg1, int arg2, int arg3, EFullscreenMode arg4, bool arg5) = 0;
	virtual bool CheckDeviceLost();
	virtual EScreenAspectRatio GetScreenAspect(int nWidth, int nHeight);
	virtual Vec2 SetViewportDownscale(float xscale, float yscale);
	virtual void Release();
	virtual void FreeResources(int nFlags);
	virtual void InitSystemResources(int nFlags);
	virtual void LimitFramerate(const int arg0, const bool arg1) = 0;
	virtual void LimitLoadingFramerate() = 0;
	virtual void Reset() = 0;
	virtual void SetState(int State, int AlphaRef);
	virtual void PushWireframeMode(int mode);
	virtual void PopWireframeMode();
	virtual void FX_PushWireframeMode(int arg0) = 0;
	virtual void FX_PopWireframeMode() = 0;
	virtual void DrawPrimitivesInternal(CVertexBuffer* arg0, int arg1, ERenderPrimitiveType arg2) = 0;
	virtual bool SaveTga(uint8_t* sourcedata, int sourceformat, int w, int h, const char* filename, bool flip) const;
	virtual int GetWhiteTextureId() const;
	virtual void PrintToScreen(float x, float y, float size, const char* buf);
	//virtual void TextToScreen(float x, float y, const char* format, ...);
	//virtual void TextToScreenColor(int x, int y, float r, float g, float b, float a, const char* format, ...);
	virtual IArkBinkManager* GetIArkBinkManager();
	//void WriteXY(int x, int y, float xscale, float yscale, float r, float g, float b, float a, const char* format, ...) { FWriteXY(this, x, y, xscale, yscale, r, g, b, a, format, buffer); }
	virtual void Draw2dText(float posX, float posY, const char* pStr, SDrawTextInfo const& ti);
	virtual void Draw2dTextWithDepth(float posX, float posY, float posZ, const char* pStr, SDrawTextInfo const& ti);
	virtual void DrawTextQueued(Vec3 pos, SDrawTextInfo& ti, const char* text);
	virtual void DrawTextQueued(Vec3 pos, SDrawTextInfo& ti, const char* format, char* args);
	virtual void PrintResourcesLeaks() = 0;
	virtual float ScaleCoordX(float value) const;
	virtual float ScaleCoordY(float value) const;
	virtual void ScaleCoord(float& x, float& y) const;
	virtual int GetWidth();
	virtual int GetHeight();
	virtual float GetPixelAspectRatio() const;
	virtual int GetOverlayWidth();
	virtual int GetOverlayHeight();
	virtual float GetNearestRangeMax() const;
	virtual int GetWireframeMode();
	virtual CRenderView* GetRenderViewForThread(int nThreadID, bool bRecursive);
	Matrix44 GetCameraMatrix() { return FGetCameraMatrix(this); }
	Matrix44 const& GetPreviousFrameCameraMatrix() const { return FGetPreviousFrameCameraMatrix(this); }
	void SetPreviousFrameCameraMatrix(Matrix44 const& m) { FSetPreviousFrameCameraMatrix(this, m); }
	virtual void GetPolyCount(int& nPolygons, int& nShadowPolys);
	virtual int GetPolyCount();
	virtual void GetMemoryUsage(ICrySizer* pSizer);
	virtual void GetBandwidthStats(float* fBandwidthRequested);
	virtual void SetTextureStreamListener(ITextureStreamListener* pListener);
	virtual void GetLogVBuffers() = 0;
	virtual int GetFrameID(bool bIncludeRecursiveCalls);
	virtual void FlushTextMessages();
	void FlushTextMessages(CTextMessages& messages, bool reset) { FFlushTextMessagesOv0(this, messages, reset); }
	virtual void DrawAllShadowsOnTheScreen() = 0;
	virtual void SetMatrices(float* arg0, float* arg1, float* arg2) = 0;
	virtual int GetStencilBpp();
	virtual void FlushPendingTextureTasks();
	virtual void SetShadowJittering(float shadowJittering);
	virtual float GetShadowJittering() const;
	virtual void* FX_AllocateCharInstCB(SSkinningData*, unsigned);
	virtual void FX_ClearCharInstCB(unsigned __formal);
	virtual EShaderQuality EF_GetShaderQuality(EShaderType eST);
	virtual ERenderQuality EF_GetRenderQuality() const;
	void RefreshSystemShaders() { FRefreshSystemShaders(this); }
	unsigned EF_BatchFlags(SShaderItem& SH, CRenderObject* pObj, CRendElementBase* re, SRenderingPassInfo const& passInfo, int nAboveWater) { return FEF_BatchFlags(this, SH, pObj, re, passInfo, nAboveWater); }
	virtual void FX_PipelineShutdown(bool arg0) = 0;
	virtual void RT_GraphicsPipelineShutdown() = 0;
	virtual IOpticsElementBase* CreateOptics(EFlareType type) const;
	virtual ISoftOcclusionQuery* CreateSoftOcclusionQuery() const;
	virtual bool EF_PrecacheResource(IShader* pSH, float fMipFactor, float fTimeToReady, int Flags);
	virtual bool EF_PrecacheResource(IRenderMesh* _pPB, IMaterial* pMaterial, float fMipFactor, float fTimeToReady, int nFlags, int nUpdateId);
	virtual bool EF_PrecacheResource(CDLight* pLS, float fMipFactor, float fTimeToReady, int Flags, int nUpdateId);
	virtual CRenderObject* EF_AddPolygonToScene(SShaderItem& si, int numPts, SVF_P3F_C4B_T2F const* verts, SPipTangents const* tangs, CRenderObject* obj, SRenderingPassInfo const& passInfo, uint16_t* inds, int ninds, int nAW);
	virtual CRenderObject* EF_AddPolygonToScene(SShaderItem& si, CRenderObject* obj, SRenderingPassInfo const& passInfo, int numPts, int ninds, SVF_P3F_C4B_T2F*& verts, SPipTangents*& tangs, uint16_t*& inds, int nAW);
	void FX_CheckOverflow(int nVerts, int nInds, CRendElementBase* re, int* nNewVerts, int* nNewInds) { FFX_CheckOverflow(this, nVerts, nInds, re, nNewVerts, nNewInds); }
	void FX_Start(CShader* ef, int nTech, CShaderResources* Res, CRendElementBase* re) { FFX_Start(this, ef, nTech, Res, re); }
	virtual void EF_AddMultipleParticlesToScene(SAddParticlesToSceneJob const* jobs, uint64_t numJobs, SRenderingPassInfo const& passInfo);
	virtual void EF_SetShaderMissCallback(void (*callback)(const char*));
	virtual const char* EF_GetShaderMissLogPath();
	virtual string* EF_GetShaderNames(int& nNumShaders);
	virtual IShader* EF_LoadShader(const char* name, int flags, uint64_t nMaskGen);
	virtual SShaderItem EF_LoadShaderItem(const char* szName, bool bShare, int flags, SInputShaderResources* Res, uint64_t nMaskGen, IRenderer::SLoadShaderItemArgs const* pArgs);
	virtual uint64_t EF_GetRemapedShaderMaskGen(const char* name, uint64_t nMaskGen, bool bFixup);
	virtual uint64_t EF_GetShaderGlobalMaskGenFromString(const char* szShaderName, const char* szShaderGen, uint64_t nMaskGen);
	virtual const char* EF_GetStringFromShaderGlobalMaskGen(const char* szShaderName, uint64_t nMaskGen);
	virtual bool EF_ReloadFile(const char* szFileName);
	virtual bool EF_ReloadFile_Request(const char* szFileName);
	virtual void EF_ReloadTextures();
	virtual ITexture* EF_GetTextureByID(int Id);
	virtual ITexture* EF_GetTextureByName(const char* nameTex, unsigned flags);
	virtual ITexture* EF_LoadTexture(const char* nameTex, const unsigned flags);
	virtual unsigned EF_CacheTextureAsync(const char* _textureName, unsigned _flags, EDeviceMemoryHeap _heapId);
	virtual void EF_ReleaseCacheTexture(unsigned _textureId);
	virtual ITexture* EF_TryGetCacheTexture(unsigned _textureId);
	virtual IDynTextureSource* EF_LoadDynTexture(const char* dynsourceName, bool sharedRT);
	virtual SShaderProfile const& GetShaderProfile(EShaderType eST) const;
	virtual void EF_SetShaderQuality(EShaderType eST, EShaderQuality eSQ);
	//virtual _smart_ptr<IImageFile> EF_LoadImage(const char* szFileName, unsigned nFlags);
	virtual CRendElementBase* EF_CreateRE(EDataType edt);
	virtual void EF_StartEf(SRenderingPassInfo const& passInfo);
	virtual CRenderObject* EF_GetObject_Temp(int nThreadID);
	virtual CRenderObject* EF_DuplicateRO(CRenderObject* pSrc, SRenderingPassInfo const& passInfo);
	virtual CRenderObject* EF_GetObject();
	virtual void EF_FreeObject(CRenderObject* pObj);
	virtual void EF_AddEf(CRendElementBase* re, SShaderItem& pSH, CRenderObject* obj, SRenderingPassInfo const& passInfo, int nList, int nAW);
	virtual void EF_InvokeShadowMapRenderJobs(CRenderView* pRenderView, const int nFlags);
	virtual bool EF_IsFakeDLight(CDLight const* Source);
	virtual void EF_ADDDlight(CDLight* Source, SRenderingPassInfo const& passInfo);
	virtual bool EF_AddDeferredDecal(SDeferredDecal const& rDecal, SRenderingPassInfo const& passInfo);
	virtual int EF_AddDeferredLight(CDLight const& pLight, float fMult, SRenderingPassInfo const& passInfo, SRendParams const& _rendParams);
	virtual void EF_ReleaseDeferredData();
	virtual SInputShaderResources* EF_CreateInputShaderResource(IRenderShaderResources* pOptionalCopyFrom);
	virtual void ClearPerFrameData(SRenderingPassInfo const& passInfo);
	virtual ColorF EF_GetLightAnimColor(uint8_t _style, uint8_t _phase, float _animSpeed);
	virtual bool EF_UpdateDLight(SRenderLight* dl);
	void EF_CheckLightMaterial(CDLight* pLight, uint16_t nRenderLightID, SRenderingPassInfo const& passInfo, SRendParams const& _rendParams) { FEF_CheckLightMaterial(this, pLight, nRenderLightID, passInfo, _rendParams); }
	virtual void EF_AddWaterSimHit(Vec3 const& vPos, const float scale, const float strength);
	virtual void EF_DrawWaterSimHits();
	virtual void EF_QueryImpl(ERenderQueryTypes eQuery, void* pInOut0, unsigned nInOutSize0, void* pInOut1, unsigned nInOutSize1);
	virtual void FX_SetState(int arg0, int arg1, int arg2) = 0;
	void FX_SetStencilState(int st, unsigned nStencRef, unsigned nStencMask, unsigned nStencWriteMask, bool bForceFullReadMask) { FFX_SetStencilState(this, st, nStencRef, nStencMask, nStencWriteMask, bForceFullReadMask); }
	virtual uint64_t EF_PostEffectParamHandleFromName(const char* _szParamName) const;
	virtual void EF_SetPostEffectParam(SSetPostEffectParam const& _param) const;
	virtual void EF_SetPostEffectParam(SSetPostEffectParamVec4 const& _param) const;
	virtual void EF_SetPostEffectParam(SSetPostEffectParamString const& _param) const;
	virtual float EF_GetPostEffectParam(uint64_t _handle) const;
	virtual Vec4 EF_GetPostEffectParamVec4(uint64_t _handle) const;
	virtual const char* EF_GetPostEffectParamString(uint64_t _handle) const;
	virtual bool EF_IsPostEffectParam(const char* _szParamName) const;
	virtual void EF_ResetPostEffects(bool bOnSpecChange);
	virtual void EF_DisableTemporalEffects();
	virtual void ForceGC();
	//virtual _smart_ptr<IRenderMesh> CreateRenderMesh(const char* szType, const char* szSourceName, IRenderMesh::SInitParamerers* pInitParams, ERenderMeshType eBufType);
	//virtual _smart_ptr<IRenderMesh> CreateRenderMeshInitialized(const void* pVertBuffer, int nVertCount, EVertexFormat eVF, const uint16_t* pIndices, int nIndices, PublicRenderPrimitiveType nPrimetiveType, const char* szType, const char* szSourceName, ERenderMeshType eBufType, int nMatInfoCount, int nClientTextureBindID, bool (*PrepareBufferCallback)(IRenderMesh*, bool), void* CustomData, bool bOnlyVideoBuffer, bool bPrecache, SPipTangents const* pTangents, bool bLockForThreadAcc, Vec3* pNormals);
	virtual int GetMaxActiveTexturesARB();
	virtual void GetThreadIDs(unsigned long& mainThreadID, unsigned long& renderThreadID) const;
	virtual void SF_ConfigMask(IRenderer::ESFMaskOp maskOp, unsigned stencilRef);
	virtual int SF_CreateTexture(int width, int height, int numMips, uint8_t* pData, ETEX_Format eTF, int flags);
	virtual void SF_GetMeshMaxSize(int& numVertices, int& numIndices) const;
	virtual ITexture* CreateTexture(const char* name, int width, int height, int numMips, uint8_t* pData, ETEX_Format eTF, int flags);
	virtual void SetProfileMarker(const char* label, CRenderer::ESPM mode) const;
	virtual uint16_t PushFogVolumeContribution(ColorF const& fogVolumeContrib, SRenderingPassInfo const& passInfo);
	void GetFogVolumeContribution(uint16_t idx, ColorF& rColor) const { FGetFogVolumeContribution(this, idx, rColor); }
	virtual int GetMaxTextureSize();
	virtual ShadowFrustumMGPUCache* GetShadowFrustumMGPUCache();
	virtual StaticArray<int, 16, int> const& GetCachedShadowsResolution() const;
	virtual void SetCachedShadowsResolution(StaticArray<int, 16, int> const& arrResolutions);
	virtual void UpdateCachedShadowsLodCount(int nGsmLods) const;
	virtual void ExecuteAsyncDIP();
	alloc_info_struct* GetFreeChunk(int bytes_count, int nBufSize, PodArray<alloc_info_struct, 0>& alloc_info, const char* szSource) { return FGetFreeChunk(this, bytes_count, nBufSize, alloc_info, szSource); }
	bool ReleaseChunk(int p, PodArray<alloc_info_struct, 0>& alloc_info) { return FReleaseChunk(this, p, alloc_info); }
	virtual const char* GetTextureFormatName(ETEX_Format eTF);
	virtual int GetTextureFormatDataSize(int nWidth, int nHeight, int nDepth, int nMips, ETEX_Format eTF);
	virtual void SetDefaultMaterials(IMaterial* pDefMat, IMaterial* pTerrainDefMat);
	virtual uint8_t* GetTextureSubImageData32(uint8_t* pData, int nDataSize, int nX, int nY, int nW, int nH, CTexture* pTex);
	virtual void PrecacheTexture(ITexture* pTP, float fMipFactor, float fTimeToReady, int Flags, int nUpdateId, int nCounter);
	virtual SSkinningData* EF_CreateSkinningData(unsigned nNumBones, bool bNeedJobSyncVar);
	virtual SSkinningData* EF_CreateRemappedSkinningData(unsigned nNumBones, SSkinningData* pSourceSkinningData, unsigned nCustomDataSize, unsigned pairGuid);
	virtual int EF_GetSkinningPoolID();
	virtual void UpdateShaderItem(SShaderItem* pShaderItem, IMaterial* pMaterial);
	virtual void ForceUpdateShaderItem(SShaderItem* pShaderItem, IMaterial* pMaterial);
	virtual void RefreshShaderResourceConstants(SShaderItem* pShaderItem, IMaterial* pMaterial);
	void RT_UpdateShaderItem(SShaderItem* pShaderItem, IMaterial* pMaterial) { FRT_UpdateShaderItem(this, pShaderItem, pMaterial); }
	void RT_RefreshShaderResourceConstants(SShaderItem* pShaderItem) { FRT_RefreshShaderResourceConstants(this, pShaderItem); }
	virtual bool LoadShaderStartupCache();
	virtual void UnloadShaderStartupCache();
	virtual bool LoadShaderLevelCache();
	virtual void UnloadShaderLevelCache();
	virtual void SetClearColor(Vec3 const& vColor);
	void UpdateAntiAliasingMode() { FUpdateAntiAliasingMode(this); }
	virtual void RegisterSyncWithMainListener(ISyncMainWithRenderListener* pListener);
	virtual void RemoveSyncWithMainListener(ISyncMainWithRenderListener const* pListener);
	virtual void SetCurDownscaleFactor(Vec2 arg0) = 0;
	//virtual _smart_ptr<IGraphicsDeviceConstantBuffer> CreateGraphiceDeviceConstantBuffer();
	virtual void MakeMatrix(Vec3 const& pos, Vec3 const& angles, Vec3 const& scale, Matrix34* mat);
	void SyncMainWithRender() { FSyncMainWithRender(this); }
	void UpdateConstParamsPF(SRenderingPassInfo const& passInfo) { FUpdateConstParamsPF(this, passInfo); }
	void RT_UpdateConstParamsPF(CRenderView* _pRenderView) { FRT_UpdateConstParamsPF(this, _pRenderView); }
	virtual unsigned GetActiveGPUCount() const;
	//void Logv(const char* format, ... arg1) { FLogv(this, format, arg1); }
	void RT_UpdateLightVolumes() { FRT_UpdateLightVolumes(this); }
	void RT_SetSkinningPoolId(unsigned poolId) { FRT_SetSkinningPoolId(this, poolId); }
	void EF_AddEf_NotVirtual(CRendElementBase* re, SShaderItem& SH, CRenderObject* obj, SRenderingPassInfo const& passInfo, int nList, int nAW) { FEF_AddEf_NotVirtual(this, re, SH, obj, passInfo, nList, nAW); }
	void FX_StartMerging() { FFX_StartMerging(this); }
	void FX_PushVP() { FFX_PushVP(this); }
	void FX_PopVP() { FFX_PopVP(this); }
	void EF_AddRTStat(CTexture* pTex, int nFlags, int nW, int nH) { FEF_AddRTStat(this, pTex, nFlags, nW, nH); }
	eAntialiasingType FX_GetAntialiasingType() const { return FFX_GetAntialiasingType(this); }
	unsigned FX_GetMSAAMode() const { return FFX_GetMSAAMode(this); }
	void FX_SetMSAAFlagsRT() { FFX_SetMSAAFlagsRT(this); }
	void FX_ApplyShaderQuality(EShaderType eST) { FFX_ApplyShaderQuality(this, eST); }
	bool IsHDRModeEnabled() const { return FIsHDRModeEnabled(this); }
	virtual CCamera const& GetCamera();
	CRenderCamera const& GetRCamera() { return FGetRCamera(this); }
	static int GetTexturesStreamPoolSize() { return FGetTexturesStreamPoolSize(); }
	void EF_RemoveParticlesFromScene() { FEF_RemoveParticlesFromScene(this); }
	void PrepareParticleRenderObjects(Array<SAddParticlesToSceneJob const, int, NArray::ArrayStorage> aJobs, int nREStart, SRenderingPassInfo passInfoOriginal) { FPrepareParticleRenderObjects(this, aJobs, nREStart, passInfoOriginal); }
	bool EF_GetParticleListAndBatchFlags(unsigned& nBatchFlags, int& nList, SShaderItem& shaderItem, CRenderObject* pRO, SRenderingPassInfo const& passInfo) { return FEF_GetParticleListAndBatchFlags(this, nBatchFlags, nList, shaderItem, pRO, passInfo); }
	void FreePermanentRenderObjects(int bufferId) { FFreePermanentRenderObjects(this, bufferId); }
	virtual bool StopRendererAtFrameEnd(unsigned timeoutMilliseconds);
	virtual void ResumeRendererFromFrameEnd();
	virtual void SetTexturePrecaching(bool stat);
	virtual float GetGPUFrameTime();
	virtual void GetRenderTimes(IRenderer::SRenderTimes& outTimes);
	virtual void EnableBatchMode(bool enable);

#if 0
	float GetDrawNearestFOV() const;
	CTextureManager* GetTextureManager();
	ArkBinkManager* GetArkBinkManager();
	float ScaleCoordXInternal(float arg0) const;
	float ScaleCoordYInternal(float arg0) const;
	void ScaleCoordInternal(float& arg0, float& arg1) const;
	void SetWidth(int arg0);
	void SetHeight(int arg0);
	void SetPixelAspectRatio(float arg0);
	int GetBackbufferWidth();
	int GetBackbufferHeight();
	int RT_GetPolyCount();
	int RT_GetCurrGpuID() const;
	int GetDepthBpp();
	void EF_AddClientPolys(SRenderingPassInfo const& arg0);
	void EF_RemovePolysFromScene();
	bool FX_TryToMerge(CRenderObject* arg0, CRenderObject* arg1, CRendElementBase* arg2, bool arg3);
	SSF_GlobalDrawParams const* SF_GetGlobalDrawParams() const;
	void ClearSkinningDataPool();
	void LogStrv(char* arg0, ... arg1);
	void LogShv(char* arg0, ... arg1);
	void Log(char* arg0);
	void RT_SetLightVolumeShaderFlags();
	void EF_TransformDLights();
	void EF_IdentityDLights();
	void EF_PrintRTStats(const char* arg0);
	int FX_ApplyShadowQuality();
	void FX_ResetMSAAFlagsRT();
	bool IsShadowPassEnabled() const;
	const bool IsEditorMode() const;
	const bool IsShaderCacheGenMode() const;
	float GetMipDistFactor();
	void EF_AddParticle(CREParticle* arg0, SShaderItem& arg1, CRenderObject* arg2, SRenderingPassInfo const& arg3);
	static void* operator new(uint64_t arg0);
	static void operator delete(void* arg0);
	void SetTextureAlphaChannelFromRGB(uint8_t* arg0, int arg1);
	bool IsHdrOutputEnabled() const;
	EDisplayOutputMode GetPixelOutputMode() const;
	ETEX_Format GetPixelOutputFormat() const;
#endif

	const bool IsEditorMode() const { return false; }
	const bool IsShaderCacheGenMode() const { return false; }

	static inline auto FBitNotCRenderer = PreyFunction<void(CRenderer* const _this)>(0xFB1860);
	static inline auto FInitRenderer = PreyFunction<void(CRenderer* const _this)>(0xFB9410);
	static inline auto FPostInit = PreyFunction<void(CRenderer* const _this)>(0xFBA3C0);
	static inline auto FCreateDeviceMemoryHeap = PreyFunction<bool(CRenderer* const _this, EDeviceMemoryHeap _heapId, EDeviceMemoryType _type, uint64_t _size, uint64_t _bankSize, uint64_t _reserveSize)>(0x1B933B0);
	static inline auto FStartRenderIntroMovies = PreyFunction<void(CRenderer* const _this, bool skipArkIntro)>(0xFBB0D0);
	static inline auto FStopRenderIntroMovies = PreyFunction<void(CRenderer* const _this, bool bWaitForFinished)>(0xFBB130);
	static inline auto FIsRenderingIntroMovies = PreyFunction<bool(CRenderer const* const _this)>(0xFBA300);
	static inline auto FPostLevelLoading = PreyFunction<void(CRenderer* const _this)>(0xFBA470);
	static inline auto FPreShutDown = PreyFunction<void(CRenderer* const _this)>(0xFBA500);
	static inline auto FPostShutDown = PreyFunction<void(CRenderer* const _this)>(0xFBA4D0);
	static inline auto FSuspendDevice = PreyFunction<void(CRenderer* const _this)>(0xFBB230);
	static inline auto FResumeDevice = PreyFunction<void(CRenderer* const _this)>(0xFBB230);
	static inline auto FSyncComputeVerticesJobs = PreyFunction<void(CRenderer* const _this)>(0xFD5A60);
	static inline auto FDrawStringW = PreyFunction<void(CRenderer const* const _this, IFFont_RenderProxy* pFont, float x, float y, float z, const wchar_t* pStr, const bool asciiMultiLine, STextDrawContext const& ctx)>(0xFB3140);
	static inline auto FRT_CurThreadList = PreyFunction<int(CRenderer* const _this)>(0xFBA600);
	static inline auto FRT_FlushTextMessages = PreyFunction<void(CRenderer* const _this)>(0xFBA660);
	static inline auto FRT_CreateREPostProcess = PreyFunction<void(CRenderer* const _this, CRendElementBase** re)>(0xFBA5C0);
	static inline auto FRT_FlashRender = PreyFunction<void(CRenderer* const _this, IFlashPlayer_RenderProxy* pPlayer)>(0xEC8F90);
	static inline auto FRT_FlashRenderPlaybackLockless = PreyFunction<void(CRenderer* const _this, IFlashPlayer_RenderProxy* pPlayer, int cbIdx, bool finalPlayback)>(0xEC8FA0);
	static inline auto FRT_FlashRemoveTexture = PreyFunction<void(CRenderer* const _this, ITexture* pTexture)>(0x368CF0);
	static inline auto FRT_PostLevelLoading = PreyFunction<void(CRenderer* const _this)>(0xFBA6C0);
	static inline auto FRT_DisableTemporalEffects = PreyFunction<void(CRenderer* const _this)>(0xFBA640);
	static inline auto FFlushRTCommands = PreyFunction<bool(CRenderer* const _this, bool bWait, bool bImmediatelly, bool bForce)>(0xFBCFF0);
	static inline auto FForceFlushRTCommands = PreyFunction<bool(CRenderer* const _this)>(0xFBD090);
	static inline auto FRequestFlushAllPendingTextureStreamingJobs = PreyFunction<void(CRenderer* const _this, int nFrames)>(0xF52D30);
	static inline auto FSetTexturesStreamingGlobalMipFactor = PreyFunction<void(CRenderer* const _this, float fFactor)>(0xF54EE0);
	static inline auto FAddListener = PreyFunction<void(CRenderer* const _this, IRendererEventListener* pRendererEventListener)>(0xFB2710);
	static inline auto FRemoveListener = PreyFunction<void(CRenderer* const _this, IRendererEventListener* pRendererEventListener)>(0xFBA990);
	static inline auto FGetRenderType = PreyFunction<ERenderType(CRenderer const* const _this)>(0x1A42CE0);
	static inline auto FGetCurrentContextHWND = PreyFunction<void* (CRenderer* const _this)>(0xFB8C80);
	static inline auto FIsCurrentContextMainVP = PreyFunction<bool(CRenderer* const _this)>(0x1B933B0);
	static inline auto FGetFeatures = PreyFunction<int(CRenderer* const _this)>(0xF24A20);
	static inline auto FGetNumGeomInstances = PreyFunction<int(CRenderer* const _this)>(0x158AEF0);
	static inline auto FGetNumGeomInstanceDrawCalls = PreyFunction<int(CRenderer* const _this)>(0x158AEF0);
	static inline auto FGetCurrentNumberOfDrawCallsOv2 = PreyFunction<int(CRenderer* const _this)>(0x158AEF0);
	static inline auto FGetCurrentNumberOfDrawCallsOv1 = PreyFunction<void(CRenderer* const _this, int& nGeneral, int& nShadowGen)>(0xA13080);
	static inline auto FGetCurrentNumberOfDrawCallsOv0 = PreyFunction<int(CRenderer* const _this, const unsigned EFSListMask)>(0x158AEF0);
	static inline auto FGetCurrentDrawCallRTTimes = PreyFunction<float(CRenderer* const _this, const unsigned EFSListMask)>(0xB5F050);
	static inline auto FCheckDeviceLost = PreyFunction<bool(CRenderer* const _this)>(0xDD23F0);
	static inline auto FGetScreenAspect = PreyFunction<EScreenAspectRatio(CRenderer* const _this, int nWidth, int nHeight)>(0xFB9000);
	static inline auto FSetViewportDownscale = PreyFunction<Vec2(CRenderer* const _this, float xscale, float yscale)>(0xFBAEF0);
	static inline auto FRelease = PreyFunction<void(CRenderer* const _this)>(0xFBA860);
	static inline auto FFreeResources = PreyFunction<void(CRenderer* const _this, int nFlags)>(0xFB7AC0);
	static inline auto FInitSystemResources = PreyFunction<void(CRenderer* const _this, int nFlags)>(0xFBA1E0);
	static inline auto FSetState = PreyFunction<void(CRenderer* const _this, int State, int AlphaRef)>(0xFBAED0);
	static inline auto FPushWireframeMode = PreyFunction<void(CRenderer* const _this, int mode)>(0xFBA5B0);
	static inline auto FPopWireframeMode = PreyFunction<void(CRenderer* const _this)>(0xFBA3B0);
	static inline auto FSaveTga = PreyFunction<bool(CRenderer const* const _this, uint8_t* sourcedata, int sourceformat, int w, int h, const char* filename, bool flip)>(0xFBAAB0);
	static inline auto FGetWhiteTextureId = PreyFunction<int(CRenderer const* const _this)>(0xFB9160);
	static inline auto FPrintToScreen = PreyFunction<void(CRenderer* const _this, float x, float y, float size, const char* buf)>(0xFBA550);
	//static inline auto FTextToScreen = PreyFunction<void(CRenderer* const _this, float x, float y, const char* format, ... buffer)>(0xFBB300);
	//static inline auto FTextToScreenColor = PreyFunction<void(CRenderer* const _this, int x, int y, float r, float g, float b, float a, const char* format, ... buffer)>(0xFBB400);
	static inline auto FGetIArkBinkManager = PreyFunction<IArkBinkManager* (CRenderer* const _this)>(0xFB8D90);
	//static inline auto FWriteXY = PreyFunction<void(CRenderer* const _this, int x, int y, float xscale, float yscale, float r, float g, float b, float a, const char* format, ... buffer)>(0xFBB720);
	static inline auto FDraw2dText = PreyFunction<void(CRenderer* const _this, float posX, float posY, const char* pStr, SDrawTextInfo const& ti)>(0xFB2DF0);
	static inline auto FDraw2dTextWithDepth = PreyFunction<void(CRenderer* const _this, float posX, float posY, float posZ, const char* pStr, SDrawTextInfo const& ti)>(0xFB2E20);
	static inline auto FDrawTextQueuedOv1 = PreyFunction<void(CRenderer* const _this, Vec3 pos, SDrawTextInfo& ti, const char* text)>(0xFB3160);
	static inline auto FDrawTextQueuedOv0 = PreyFunction<void(CRenderer* const _this, Vec3 pos, SDrawTextInfo& ti, const char* format, char* args)>(0xFB3250);
	static inline auto FScaleCoordX = PreyFunction<float(CRenderer const* const _this, float value)>(0xF0A0B0);
	static inline auto FScaleCoordY = PreyFunction<float(CRenderer const* const _this, float value)>(0xF0A0D0);
	static inline auto FScaleCoord = PreyFunction<void(CRenderer const* const _this, float& x, float& y)>(0xF53100);
	static inline auto FGetWidth = PreyFunction<int(CRenderer* const _this)>(0xE98570);
	static inline auto FGetHeight = PreyFunction<int(CRenderer* const _this)>(0xE98560);
	static inline auto FGetPixelAspectRatio = PreyFunction<float(CRenderer const* const _this)>(0xF4F0F0);
	static inline auto FGetOverlayWidth = PreyFunction<int(CRenderer* const _this)>(0xF24AC0);
	static inline auto FGetOverlayHeight = PreyFunction<int(CRenderer* const _this)>(0xF24AB0);
	static inline auto FGetNearestRangeMax = PreyFunction<float(CRenderer const* const _this)>(0xF4EB80);
	static inline auto FGetWireframeMode = PreyFunction<int(CRenderer* const _this)>(0xF14310);
	static inline auto FGetRenderViewForThread = PreyFunction<CRenderView* (CRenderer* const _this, int nThreadID, bool bRecursive)>(0xFB8FE0);
	static inline auto FGetCameraMatrix = PreyFunction<Matrix44(CRenderer* const _this)>(0xFB83C0);
	static inline auto FGetPreviousFrameCameraMatrix = PreyFunction<Matrix44 const& (CRenderer const* const _this)>(0xFB8F20);
	static inline auto FSetPreviousFrameCameraMatrix = PreyFunction<void(CRenderer* const _this, Matrix44 const& m)>(0xFBAE00);
	static inline auto FGetPolyCountOv1 = PreyFunction<void(CRenderer* const _this, int& nPolygons, int& nShadowPolys)>(0xA13080);
	static inline auto FGetPolyCountOv0 = PreyFunction<int(CRenderer* const _this)>(0x158AEF0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CRenderer* const _this, ICrySizer* pSizer)>(0xFB8DA0);
	static inline auto FGetBandwidthStats = PreyFunction<void(CRenderer* const _this, float* fBandwidthRequested)>(0xA13080);
	static inline auto FSetTextureStreamListener = PreyFunction<void(CRenderer* const _this, ITextureStreamListener* pListener)>(0xA13080);
	static inline auto FGetFrameID = PreyFunction<int(CRenderer* const _this, bool bIncludeRecursiveCalls)>(0xFB8C90);
	static inline auto FFlushTextMessagesOv1 = PreyFunction<void(CRenderer* const _this)>(0xFB78A0);
	static inline auto FFlushTextMessagesOv0 = PreyFunction<void(CRenderer* const _this, CTextMessages& messages, bool reset)>(0xFB7300);
	static inline auto FGetStencilBpp = PreyFunction<int(CRenderer* const _this)>(0xF4F350);
	static inline auto FFlushPendingTextureTasks = PreyFunction<void(CRenderer* const _this)>(0xFB72C0);
	static inline auto FSetShadowJittering = PreyFunction<void(CRenderer* const _this, float shadowJittering)>(0xFBAEC0);
	static inline auto FGetShadowJittering = PreyFunction<float(CRenderer const* const _this)>(0xFB9070);
	static inline auto FFX_AllocateCharInstCB = PreyFunction<void* (CRenderer* const _this, SSkinningData* __formal, unsigned __formal)>(0x158AEF0);
	static inline auto FFX_ClearCharInstCB = PreyFunction<void(CRenderer* const _this, unsigned __formal)>(0xA13080);
	static inline auto FEF_GetShaderQuality = PreyFunction<EShaderQuality(CRenderer* const _this, EShaderType eST)>(0xFB4470);
	static inline auto FEF_GetRenderQuality = PreyFunction<ERenderQuality(CRenderer const* const _this)>(0xFB43C0);
	static inline auto FRefreshSystemShaders = PreyFunction<void(CRenderer* const _this)>(0xF1A610);
	static inline auto FEF_BatchFlags = PreyFunction<unsigned(CRenderer* const _this, SShaderItem& SH, CRenderObject* pObj, CRendElementBase* re, SRenderingPassInfo const& passInfo, int nAboveWater)>(0xEAB820);
	static inline auto FCreateOptics = PreyFunction<IOpticsElementBase* (CRenderer const* const _this, EFlareType type)>(0xFB2950);
	static inline auto FCreateSoftOcclusionQuery = PreyFunction<ISoftOcclusionQuery* (CRenderer const* const _this)>(0xE97550);
	static inline auto FEF_PrecacheResourceOv2 = PreyFunction<bool(CRenderer* const _this, IShader* pSH, float fMipFactor, float fTimeToReady, int Flags)>(0x1B933B0);
	static inline auto FEF_PrecacheResourceOv1 = PreyFunction<bool(CRenderer* const _this, IRenderMesh* _pPB, IMaterial* pMaterial, float fMipFactor, float fTimeToReady, int nFlags, int nUpdateId)>(0xFB4A20);
	static inline auto FEF_PrecacheResourceOv0 = PreyFunction<bool(CRenderer* const _this, CDLight* pLS, float fMipFactor, float fTimeToReady, int Flags, int nUpdateId)>(0xFB4BE0);
	static inline auto FEF_AddPolygonToSceneOv1 = PreyFunction<CRenderObject* (CRenderer* const _this, SShaderItem& si, int numPts, SVF_P3F_C4B_T2F const* verts, SPipTangents const* tangs, CRenderObject* obj, SRenderingPassInfo const& passInfo, uint16_t* inds, int ninds, int nAW)>(0xFB34A0);
	static inline auto FEF_AddPolygonToSceneOv0 = PreyFunction<CRenderObject* (CRenderer* const _this, SShaderItem& si, CRenderObject* obj, SRenderingPassInfo const& passInfo, int numPts, int ninds, SVF_P3F_C4B_T2F*& verts, SPipTangents*& tangs, uint16_t*& inds, int nAW)>(0xFB3810);
	static inline auto FFX_CheckOverflow = PreyFunction<void(CRenderer* const _this, int nVerts, int nInds, CRendElementBase* re, int* nNewVerts, int* nNewInds)>(0xF0D110);
	static inline auto FFX_Start = PreyFunction<void(CRenderer* const _this, CShader* ef, int nTech, CShaderResources* Res, CRendElementBase* re)>(0xF10490);
	static inline auto FEF_AddMultipleParticlesToScene = PreyFunction<void(CRenderer* const _this, SAddParticlesToSceneJob const* jobs, uint64_t numJobs, SRenderingPassInfo const& passInfo)>(0xFD5300);
	static inline auto FEF_SetShaderMissCallback = PreyFunction<void(CRenderer* const _this, void (*callback)(const char*))>(0xFB5F20);
	static inline auto FEF_GetShaderMissLogPath = PreyFunction<const char* (CRenderer* const _this)>(0xFB4430);
	static inline auto FEF_GetShaderNames = PreyFunction<string* (CRenderer* const _this, int& nNumShaders)>(0xFB4440);
	static inline auto FEF_LoadShader = PreyFunction<IShader* (CRenderer* const _this, const char* name, int flags, uint64_t nMaskGen)>(0xFB4830);
	static inline auto FEF_LoadShaderItem = PreyFunction<SShaderItem(CRenderer* const _this, const char* szName, bool bShare, int flags, SInputShaderResources* Res, uint64_t nMaskGen, IRenderer::SLoadShaderItemArgs const* pArgs)>(0xFB4850);
	static inline auto FEF_GetRemapedShaderMaskGen = PreyFunction<uint64_t(CRenderer* const _this, const char* name, uint64_t nMaskGen, bool bFixup)>(0xFB43B0);
	static inline auto FEF_GetShaderGlobalMaskGenFromString = PreyFunction<uint64_t(CRenderer* const _this, const char* szShaderName, const char* szShaderGen, uint64_t nMaskGen)>(0xFB43D0);
	static inline auto FEF_GetStringFromShaderGlobalMaskGen = PreyFunction<const char* (CRenderer* const _this, const char* szShaderName, uint64_t nMaskGen)>(0xFB44D0);
	static inline auto FEF_ReloadFile = PreyFunction<bool(CRenderer* const _this, const char* szFileName)>(0xFB5920);
	static inline auto FEF_ReloadFile_Request = PreyFunction<bool(CRenderer* const _this, const char* szFileName)>(0xFB5CB0);
	static inline auto FEF_ReloadTextures = PreyFunction<void(CRenderer* const _this)>(0xFB5E90);
	static inline auto FEF_GetTextureByID = PreyFunction<ITexture* (CRenderer* const _this, int Id)>(0xFB4520);
	static inline auto FEF_GetTextureByName = PreyFunction<ITexture* (CRenderer* const _this, const char* nameTex, unsigned flags)>(0xFB4540);
	static inline auto FEF_LoadTexture = PreyFunction<ITexture* (CRenderer* const _this, const char* nameTex, const unsigned flags)>(0xFB48A0);
	static inline auto FEF_CacheTextureAsync = PreyFunction<unsigned(CRenderer* const _this, const char* _textureName, unsigned _flags, EDeviceMemoryHeap _heapId)>(0xEC8E10);
	static inline auto FEF_ReleaseCacheTexture = PreyFunction<void(CRenderer* const _this, unsigned _textureId)>(0xEC8F70);
	static inline auto FEF_TryGetCacheTexture = PreyFunction<ITexture* (CRenderer* const _this, unsigned _textureId)>(0xEC8F80);
	static inline auto FEF_LoadDynTexture = PreyFunction<IDynTextureSource* (CRenderer* const _this, const char* dynsourceName, bool sharedRT)>(0xFB46E0);
	static inline auto FGetShaderProfile = PreyFunction<SShaderProfile const& (CRenderer const* const _this, EShaderType eST)>(0x101A350);
	static inline auto FEF_SetShaderQuality = PreyFunction<void(CRenderer* const _this, EShaderType eST, EShaderQuality eSQ)>(0xFB5F30);
	//static inline auto FEF_LoadImage = PreyFunction<_smart_ptr<IImageFile>(CRenderer* const _this, const char* szFileName, unsigned nFlags)>(0xFB4740);
	static inline auto FEF_CreateRE = PreyFunction<CRendElementBase* (CRenderer* const _this, EDataType edt)>(0xFB3BF0);
	static inline auto FEF_StartEf = PreyFunction<void(CRenderer* const _this, SRenderingPassInfo const& passInfo)>(0xFB5F70);
	static inline auto FEF_GetObject_Temp = PreyFunction<CRenderObject* (CRenderer* const _this, int nThreadID)>(0xEABBE0);
	static inline auto FEF_DuplicateRO = PreyFunction<CRenderObject* (CRenderer* const _this, CRenderObject* pSrc, SRenderingPassInfo const& passInfo)>(0xEAB9B0);
	static inline auto FEF_GetObject = PreyFunction<CRenderObject* (CRenderer* const _this)>(0xEABBD0);
	static inline auto FEF_FreeObject = PreyFunction<void(CRenderer* const _this, CRenderObject* pObj)>(0xEABA70);
	static inline auto FEF_AddEf = PreyFunction<void(CRenderer* const _this, CRendElementBase* re, SShaderItem& pSH, CRenderObject* obj, SRenderingPassInfo const& passInfo, int nList, int nAW)>(0xEAAD30);
	static inline auto FEF_InvokeShadowMapRenderJobs = PreyFunction<void(CRenderer* const _this, CRenderView* pRenderView, const int nFlags)>(0xA13080);
	static inline auto FEF_IsFakeDLight = PreyFunction<bool(CRenderer* const _this, CDLight const* Source)>(0xFB4680);
	static inline auto FEF_ADDDlight = PreyFunction<void(CRenderer* const _this, CDLight* Source, SRenderingPassInfo const& passInfo)>(0xFB33B0);
	static inline auto FEF_AddDeferredDecal = PreyFunction<bool(CRenderer* const _this, SDeferredDecal const& rDecal, SRenderingPassInfo const& passInfo)>(0xFB3490);
	static inline auto FEF_AddDeferredLight = PreyFunction<int(CRenderer* const _this, CDLight const& pLight, float fMult, SRenderingPassInfo const& passInfo, SRendParams const& _rendParams)>(0xEDD690);
	static inline auto FEF_ReleaseDeferredData = PreyFunction<void(CRenderer* const _this)>(0xEDD890);
	static inline auto FEF_CreateInputShaderResource = PreyFunction<SInputShaderResources* (CRenderer* const _this, IRenderShaderResources* pOptionalCopyFrom)>(0xFB3BA0);
	static inline auto FClearPerFrameData = PreyFunction<void(CRenderer* const _this, SRenderingPassInfo const& passInfo)>(0xA13080);
	static inline auto FEF_GetLightAnimColor = PreyFunction<ColorF(CRenderer* const _this, uint8_t _style, uint8_t _phase, float _animSpeed)>(0xFB4210);
	static inline auto FEF_UpdateDLight = PreyFunction<bool(CRenderer* const _this, SRenderLight* dl)>(0xFB62C0);
	static inline auto FEF_CheckLightMaterial = PreyFunction<void(CRenderer* const _this, CDLight* pLight, uint16_t nRenderLightID, SRenderingPassInfo const& passInfo, SRendParams const& _rendParams)>(0xFB3990);
	static inline auto FEF_AddWaterSimHit = PreyFunction<void(CRenderer* const _this, Vec3 const& vPos, const float scale, const float strength)>(0xFB3960);
	static inline auto FEF_DrawWaterSimHits = PreyFunction<void(CRenderer* const _this)>(0xFB41E0);
	static inline auto FEF_QueryImpl = PreyFunction<void(CRenderer* const _this, ERenderQueryTypes eQuery, void* pInOut0, unsigned nInOutSize0, void* pInOut1, unsigned nInOutSize1)>(0xFB4CE0);
	static inline auto FFX_SetStencilState = PreyFunction<void(CRenderer* const _this, int st, unsigned nStencRef, unsigned nStencMask, unsigned nStencWriteMask, bool bForceFullReadMask)>(0xEE65F0);
	static inline auto FEF_PostEffectParamHandleFromName = PreyFunction<uint64_t(CRenderer const* const _this, const char* _szParamName)>(0xFB4A00);
	static inline auto FEF_SetPostEffectParamOv2 = PreyFunction<void(CRenderer const* const _this, SSetPostEffectParam const& _param)>(0xFB5EC0);
	static inline auto FEF_SetPostEffectParamOv1 = PreyFunction<void(CRenderer const* const _this, SSetPostEffectParamVec4 const& _param)>(0xFB5F00);
	static inline auto FEF_SetPostEffectParamOv0 = PreyFunction<void(CRenderer const* const _this, SSetPostEffectParamString const& _param)>(0xFB5EE0);
	static inline auto FEF_GetPostEffectParam = PreyFunction<float(CRenderer const* const _this, uint64_t _handle)>(0xFB4310);
	static inline auto FEF_GetPostEffectParamVec4 = PreyFunction<Vec4(CRenderer const* const _this, uint64_t _handle)>(0xFB4350);
	static inline auto FEF_GetPostEffectParamString = PreyFunction<const char* (CRenderer const* const _this, uint64_t _handle)>(0xFB4330);
	static inline auto FEF_IsPostEffectParam = PreyFunction<bool(CRenderer const* const _this, const char* _szParamName)>(0xFB46C0);
	static inline auto FEF_ResetPostEffects = PreyFunction<void(CRenderer* const _this, bool bOnSpecChange)>(0xFB5EA0);
	static inline auto FEF_DisableTemporalEffects = PreyFunction<void(CRenderer* const _this)>(0xFB41D0);
	static inline auto FForceGC = PreyFunction<void(CRenderer* const _this)>(0xFB78D0);
	//static inline auto FCreateRenderMesh = PreyFunction<_smart_ptr<IRenderMesh>(CRenderer* const _this, const char* szType, const char* szSourceName, IRenderMesh::SInitParamerers* pInitParams, ERenderMeshType eBufType)>(0xFB2960);
	//static inline auto FCreateRenderMeshInitialized = PreyFunction<_smart_ptr<IRenderMesh>(CRenderer* const _this, const void* pVertBuffer, int nVertCount, EVertexFormat eVF, const uint16_t* pIndices, int nIndices, PublicRenderPrimitiveType nPrimetiveType, const char* szType, const char* szSourceName, ERenderMeshType eBufType, int nMatInfoCount, int nClientTextureBindID, bool (*PrepareBufferCallback)(IRenderMesh*, bool), void* CustomData, bool bOnlyVideoBuffer, bool bPrecache, SPipTangents const* pTangents, bool bLockForThreadAcc, Vec3* pNormals)>(0xFB2A90);
	static inline auto FGetMaxActiveTexturesARB = PreyFunction<int(CRenderer* const _this)>(0x158AEF0);
	static inline auto FGetThreadIDs = PreyFunction<void(CRenderer const* const _this, unsigned long& mainThreadID, unsigned long& renderThreadID)>(0xFB90E0);
	static inline auto FSF_ConfigMask = PreyFunction<void(CRenderer* const _this, IRenderer::ESFMaskOp maskOp, unsigned stencilRef)>(0xECA560);
	static inline auto FSF_CreateTexture = PreyFunction<int(CRenderer* const _this, int width, int height, int numMips, uint8_t* pData, ETEX_Format eTF, int flags)>(0xECA620);
	static inline auto FSF_GetMeshMaxSize = PreyFunction<void(CRenderer const* const _this, int& numVertices, int& numIndices)>(0xECB460);
	static inline auto FCreateTexture = PreyFunction<ITexture* (CRenderer* const _this, const char* name, int width, int height, int numMips, uint8_t* pData, ETEX_Format eTF, int flags)>(0xFB2D50);
	static inline auto FSetProfileMarker = PreyFunction<void(CRenderer const* const _this, const char* label, CRenderer::ESPM mode)>(0xA13080);
	static inline auto FPushFogVolumeContribution = PreyFunction<uint16_t(CRenderer* const _this, ColorF const& fogVolumeContrib, SRenderingPassInfo const& passInfo)>(0xEABF80);
	static inline auto FGetFogVolumeContribution = PreyFunction<void(CRenderer const* const _this, uint16_t idx, ColorF& rColor)>(0xEABD50);
	static inline auto FGetMaxTextureSize = PreyFunction<int(CRenderer* const _this)>(0xF4DF30);
	static inline auto FGetShadowFrustumMGPUCache = PreyFunction<ShadowFrustumMGPUCache* (CRenderer* const _this)>(0xF4F340);
	static inline auto FGetCachedShadowsResolution = PreyFunction<StaticArray<int, 16, int> const& (CRenderer const* const _this)>(0xF4DAA0);
	static inline auto FSetCachedShadowsResolution = PreyFunction<void(CRenderer* const _this, StaticArray<int, 16, int> const& arrResolutions)>(0xF53D80);
	static inline auto FUpdateCachedShadowsLodCount = PreyFunction<void(CRenderer const* const _this, int nGsmLods)>(0xFBB650);
	static inline auto FExecuteAsyncDIP = PreyFunction<void(CRenderer* const _this)>(0xFB70B0);
	static inline auto FGetFreeChunk = PreyFunction<alloc_info_struct* (CRenderer* const _this, int bytes_count, int nBufSize, PodArray<alloc_info_struct, 0>& alloc_info, const char* szSource)>(0x1055420);
	static inline auto FReleaseChunk = PreyFunction<bool(CRenderer* const _this, int p, PodArray<alloc_info_struct, 0>& alloc_info)>(0x10559A0);
	static inline auto FGetTextureFormatName = PreyFunction<const char* (CRenderer* const _this, ETEX_Format eTF)>(0xFB90C0);
	static inline auto FGetTextureFormatDataSize = PreyFunction<int(CRenderer* const _this, int nWidth, int nHeight, int nDepth, int nMips, ETEX_Format eTF)>(0xFB9080);
	static inline auto FSetDefaultMaterials = PreyFunction<void(CRenderer* const _this, IMaterial* pDefMat, IMaterial* pTerrainDefMat)>(0xF54540);
	static inline auto FGetTextureSubImageData32 = PreyFunction<uint8_t* (CRenderer* const _this, uint8_t* pData, int nDataSize, int nX, int nY, int nW, int nH, CTexture* pTex)>(0x158AEF0);
	static inline auto FPrecacheTexture = PreyFunction<void(CRenderer* const _this, ITexture* pTP, float fMipFactor, float fTimeToReady, int Flags, int nUpdateId, int nCounter)>(0xFBA520);
	static inline auto FEF_CreateSkinningData = PreyFunction<SSkinningData* (CRenderer* const _this, unsigned nNumBones, bool bNeedJobSyncVar)>(0xFB4090);
	static inline auto FEF_CreateRemappedSkinningData = PreyFunction<SSkinningData* (CRenderer* const _this, unsigned nNumBones, SSkinningData* pSourceSkinningData, unsigned nCustomDataSize, unsigned pairGuid)>(0xFB3FD0);
	static inline auto FEF_GetSkinningPoolID = PreyFunction<int(CRenderer* const _this)>(0xFB44C0);
	static inline auto FUpdateShaderItem = PreyFunction<void(CRenderer* const _this, SShaderItem* pShaderItem, IMaterial* pMaterial)>(0xFBB660);
	static inline auto FForceUpdateShaderItem = PreyFunction<void(CRenderer* const _this, SShaderItem* pShaderItem, IMaterial* pMaterial)>(0xFB78F0);
	static inline auto FRefreshShaderResourceConstants = PreyFunction<void(CRenderer* const _this, SShaderItem* pShaderItem, IMaterial* pMaterial)>(0xFBA800);
	static inline auto FRT_UpdateShaderItem = PreyFunction<void(CRenderer* const _this, SShaderItem* pShaderItem, IMaterial* pMaterial)>(0xFBA7C0);
	static inline auto FRT_RefreshShaderResourceConstants = PreyFunction<void(CRenderer* const _this, SShaderItem* pShaderItem)>(0xFBA740);
	static inline auto FLoadShaderStartupCache = PreyFunction<bool(CRenderer* const _this)>(0xFBA310);
	static inline auto FUnloadShaderStartupCache = PreyFunction<void(CRenderer* const _this)>(0xFBB510);
	static inline auto FLoadShaderLevelCache = PreyFunction<bool(CRenderer* const _this)>(0xDD23F0);
	static inline auto FUnloadShaderLevelCache = PreyFunction<void(CRenderer* const _this)>(0xA13080);
	static inline auto FSetClearColor = PreyFunction<void(CRenderer* const _this, Vec3 const& vColor)>(0xF17820);
	static inline auto FUpdateAntiAliasingMode = PreyFunction<void(CRenderer* const _this)>(0xEA2690);
	static inline auto FRegisterSyncWithMainListener = PreyFunction<void(CRenderer* const _this, ISyncMainWithRenderListener* pListener)>(0xFBA810);
	static inline auto FRemoveSyncWithMainListener = PreyFunction<void(CRenderer* const _this, ISyncMainWithRenderListener const* pListener)>(0xFBA9E0);
	//static inline auto FCreateGraphiceDeviceConstantBuffer = PreyFunction<_smart_ptr<IGraphicsDeviceConstantBuffer>(CRenderer* const _this)>(0x13883F0);
	static inline auto FMakeMatrix = PreyFunction<void(CRenderer* const _this, Vec3 const& pos, Vec3 const& angles, Vec3 const& scale, Matrix34* mat)>(0xA13080);
	static inline auto FSyncMainWithRender = PreyFunction<void(CRenderer* const _this)>(0xFBB240);
	static inline auto FUpdateConstParamsPF = PreyFunction<void(CRenderer* const _this, SRenderingPassInfo const& passInfo)>(0xEEC530);
	static inline auto FRT_UpdateConstParamsPF = PreyFunction<void(CRenderer* const _this, CRenderView* _pRenderView)>(0xEEBBD0);
	static inline auto FGetActiveGPUCount = PreyFunction<unsigned(CRenderer const* const _this)>(0xEDEDE0);
	//static inline auto FLogv = PreyFunction<void(CRenderer* const _this, const char* format, ... arg1)>(0xFBA320);
	static inline auto FRT_UpdateLightVolumes = PreyFunction<void(CRenderer* const _this)>(0xFBA7A0);
	static inline auto FRT_SetSkinningPoolId = PreyFunction<void(CRenderer* const _this, unsigned poolId)>(0xFBA790);
	static inline auto FEF_AddEf_NotVirtual = PreyFunction<void(CRenderer* const _this, CRendElementBase* re, SShaderItem& SH, CRenderObject* obj, SRenderingPassInfo const& passInfo, int nList, int nAW)>(0xEAAD40);
	static inline auto FFX_StartMerging = PreyFunction<void(CRenderer* const _this)>(0xFB7250);
	static inline auto FFX_PushVP = PreyFunction<void(CRenderer* const _this)>(0xFB7210);
	static inline auto FFX_PopVP = PreyFunction<void(CRenderer* const _this)>(0xFB7160);
	static inline auto FEF_AddRTStat = PreyFunction<void(CRenderer* const _this, CTexture* pTex, int nFlags, int nW, int nH)>(0xFDF020);
	static inline auto FFX_GetAntialiasingType = PreyFunction<eAntialiasingType(CRenderer const* const _this)>(0xFB7140);
	static inline auto FFX_GetMSAAMode = PreyFunction<unsigned(CRenderer const* const _this)>(0x158AEF0);
	static inline auto FFX_SetMSAAFlagsRT = PreyFunction<void(CRenderer* const _this)>(0xA13080);
	static inline auto FFX_ApplyShaderQuality = PreyFunction<void(CRenderer* const _this, EShaderType eST)>(0xFB70C0);
	static inline auto FIsHDRModeEnabled = PreyFunction<bool(CRenderer const* const _this)>(0xFBA2D0);
	static inline auto FGetCamera = PreyFunction<CCamera const& (CRenderer* const _this)>(0xEDEE00);
	static inline auto FGetRCamera = PreyFunction<CRenderCamera const& (CRenderer* const _this)>(0xE93770);
	static inline auto FGetTexturesStreamPoolSize = PreyFunction<int()>(0xFB90D0);
	static inline auto FEF_RemoveParticlesFromScene = PreyFunction<void(CRenderer* const _this)>(0xFD55D0);
	static inline auto FPrepareParticleRenderObjects = PreyFunction<void(CRenderer* const _this, Array<SAddParticlesToSceneJob const, int, NArray::ArrayStorage> aJobs, int nREStart, SRenderingPassInfo passInfoOriginal)>(0xFD5620);
	static inline auto FEF_GetParticleListAndBatchFlags = PreyFunction<bool(CRenderer* const _this, unsigned& nBatchFlags, int& nList, SShaderItem& shaderItem, CRenderObject* pRO, SRenderingPassInfo const& passInfo)>(0xFD53A0);
	static inline auto FFreePermanentRenderObjects = PreyFunction<void(CRenderer* const _this, int bufferId)>(0xFB7900);
	static inline auto FStopRendererAtFrameEnd = PreyFunction<bool(CRenderer* const _this, unsigned timeoutMilliseconds)>(0xFBB190);
	static inline auto FResumeRendererFromFrameEnd = PreyFunction<void(CRenderer* const _this)>(0xFBAA30);
	static inline auto FSetTexturePrecaching = PreyFunction<void(CRenderer* const _this, bool stat)>(0xFBAEE0);
	static inline auto FGetGPUFrameTime = PreyFunction<float(CRenderer* const _this)>(0xFB8D20);
	static inline auto FGetRenderTimes = PreyFunction<void(CRenderer* const _this, IRenderer::SRenderTimes& outTimes)>(0xFB8F40);
	static inline auto FEnableBatchMode = PreyFunction<void(CRenderer* const _this, bool enable)>(0xFB7040);
};

static_assert(sizeof(CRenderer) == 39040);

//////////////////////////////////////////////////////////////////////////
#if 0
inline void* CRenderer::EF_GetPointer(ESrcPointer ePT, int* Stride, EParamType Type, ESrcPointer Dst, int Flags)
{
	void* p;

	if (m_RP.m_pRE)
		p = m_RP.m_pRE->mfGetPointer(ePT, Stride, Type, Dst, Flags);
	else
		p = SRendItem::mfGetPointerCommon(ePT, Stride, Type, Dst, Flags);

	return p;
}

inline int32 CRenderer::RT_GetCurrGpuID() const
{
	return gRenDev->m_nFrameSwapID % gRenDev->GetActiveGPUCount();
}

inline void CRenderer::RT_SetLightVolumeShaderFlags()
{
	const uint64 lightVolumeMask = g_HWSR_MaskBit[HWSR_LIGHTVOLUME0];
	m_RP.m_FlagsShader_RT |= lightVolumeMask;
}
#endif

//#include "CommonRender.h"

#define SKY_BOX_SIZE 32.f
