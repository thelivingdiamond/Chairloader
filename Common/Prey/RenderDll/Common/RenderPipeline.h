// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

/*=============================================================================
   RenderPipeline.h : Shaders pipeline declarations.

   Revision history:
* Created by Honich Andrey

   =============================================================================*/

#ifndef __RENDERPIPELINE_H__
#define __RENDERPIPELINE_H__

#pragma  once

//#include <CryThreading/CryThreadSafeRendererContainer.h>
//#include <CryThreading/CryThreadSafeWorkerContainer.h>
//#include "Shadow_Renderer.h"

#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Prey/CryThreading/CryThreadSafeRendererContainer.h>
#include <Prey/CryThreading/CryThreadSafeWorkerContainer.h>
#include <Prey/CryRenderer/VertexFormats.h>
#include <Prey/CryRenderer/IShader.h>
#include "LightVolumeBuffer.h"
#include "ParticleBuffer.h"
#include "../XRenderD3D9/CompiledRenderObject.h"

//====================================================================

#define MAX_HWINST_PARAMS          32768

#define MAX_REND_OBJECTS           16384
#define TEMP_REND_OBJECTS_POOL     2048
#define MAX_REND_GEOMS_IN_BATCH    16

#define MAX_REND_SHADERS           4096
#define MAX_REND_SHADER_RES        16384
#define MAX_REND_LIGHTS            32
#define MAX_DEFERRED_LIGHTS        256

#define MAX_SHADOWMAP_LOD          20
#define MAX_SHADOWMAP_FRUSTUMS     1024

#define MAX_STREAM_PREDICTION_ZONES 2
#define MAX_SORT_GROUPS            64
#define MAX_INSTANCES_THRESHOLD_HW 8
#define MAX_PREDICTION_ZONES       MAX_STREAM_PREDICTION_ZONES

#define CULLER_MAX_CAMS            4
//#define CULLER_DEBUG
//#define CULLER_POSITION_ONLY

#define HW_INSTANCING_ENABLED

class CRenderView;

struct SViewport
{
	int   nX, nY, nWidth, nHeight;
	float fMinZ, fMaxZ;
	SViewport()
		: nX(0)
		, nY(0)
		, nWidth(0)
		, nHeight(0)
		, fMinZ(0.0f)
		, fMaxZ(0.0f)
	{}

	SViewport(int nNewX, int nNewY, int nNewWidth, int nNewHeight)
		: nX(nNewX)
		, nY(nNewY)
		, nWidth(nNewWidth)
		, nHeight(nNewHeight)
		, fMinZ(0.0f)
		, fMaxZ(0.0f)
	{
	}
	inline friend bool operator!=(const SViewport& m1, const SViewport& m2)
	{
		if (m1.nX != m2.nX || m1.nY != m2.nY || m1.nWidth != m2.nWidth || m1.nHeight != m2.nHeight || m1.fMinZ != m2.fMinZ || m1.fMaxZ != m2.fMaxZ)
			return true;
		return false;
	}
};

class CCompiledRenderObject
{
	void* pad[360 / sizeof(void*)];
};

// FIXME: probably better to sort by shaders (Currently sorted by resources)
// TODO: DURANGO doesn't like _MS_ALIGN(32) when passed to std::sort
struct SRendItem
{
	uint32 SortVal;
	uint8_t nSceneMask;
	uint32 nBatchFlags;
	union
	{
		uint32 ObjSort;
		float  fDist;
	};
	SRendItemSorter        rendItemSorter;
	CRenderObject*         pObj;
	CCompiledRenderObject* pCompiledObject;
	CRendElementBase*      pElem;
	//uint32 nStencRef  : 8;
};

static_assert(sizeof(SRendItem) == 48);

// Helper function to be used in logging
bool IsRecursiveRenderView();

//==================================================================

struct SShaderPass;
struct SVF_P3F_C4B_T4B_N3F2;

union UVertStreamPtr
{
	void*                 Ptr;
	byte*                 PtrB;
	SVF_P3F_C4B_T4B_N3F2* PtrVF_P3F_C4B_T4B_N3F2;
};

//==================================================================
// StencilStates

//Note: If these are altered, g_StencilFuncLookup and g_StencilOpLookup arrays
//			need to be updated in turn

#define FSS_STENCFUNC_ALWAYS   0x0
#define FSS_STENCFUNC_NEVER    0x1
#define FSS_STENCFUNC_LESS     0x2
#define FSS_STENCFUNC_LEQUAL   0x3
#define FSS_STENCFUNC_GREATER  0x4
#define FSS_STENCFUNC_GEQUAL   0x5
#define FSS_STENCFUNC_EQUAL    0x6
#define FSS_STENCFUNC_NOTEQUAL 0x7
#define FSS_STENCFUNC_MASK     0x7

#define FSS_STENCIL_TWOSIDED   0x8

#define FSS_CCW_SHIFT          16

#define FSS_STENCOP_KEEP       0x0
#define FSS_STENCOP_REPLACE    0x1
#define FSS_STENCOP_INCR       0x2
#define FSS_STENCOP_DECR       0x3
#define FSS_STENCOP_ZERO       0x4
#define FSS_STENCOP_INCR_WRAP  0x5
#define FSS_STENCOP_DECR_WRAP  0x6
#define FSS_STENCOP_INVERT     0x7

#define FSS_STENCFAIL_SHIFT    4
#define FSS_STENCFAIL_MASK     (0x7 << FSS_STENCFAIL_SHIFT)

#define FSS_STENCZFAIL_SHIFT   8
#define FSS_STENCZFAIL_MASK    (0x7 << FSS_STENCZFAIL_SHIFT)

#define FSS_STENCPASS_SHIFT    12
#define FSS_STENCPASS_MASK     (0x7 << FSS_STENCPASS_SHIFT)

#define STENC_FUNC(op)        (op)
#define STENC_CCW_FUNC(op)    (op << FSS_CCW_SHIFT)
#define STENCOP_FAIL(op)      (op << FSS_STENCFAIL_SHIFT)
#define STENCOP_ZFAIL(op)     (op << FSS_STENCZFAIL_SHIFT)
#define STENCOP_PASS(op)      (op << FSS_STENCPASS_SHIFT)
#define STENCOP_CCW_FAIL(op)  (op << (FSS_STENCFAIL_SHIFT + FSS_CCW_SHIFT))
#define STENCOP_CCW_ZFAIL(op) (op << (FSS_STENCZFAIL_SHIFT + FSS_CCW_SHIFT))
#define STENCOP_CCW_PASS(op)  (op << (FSS_STENCPASS_SHIFT + FSS_CCW_SHIFT))

//Stencil masks
#define BIT_STENCIL_RESERVED          0x80
#define BIT_STENCIL_INSIDE_CLIPVOLUME 0x40
#define STENC_VALID_BITS_NUM          7
#define STENC_MAX_REF                 ((1 << STENC_VALID_BITS_NUM) - 1)

//==================================================================

struct SOnDemandD3DStreamProperties
{
	D3D11_INPUT_ELEMENT_DESC* m_pElements;
	uint32                    m_nNumElements;
};

struct SOnDemandD3DVertexDeclaration
{
	TArray<D3D11_INPUT_ELEMENT_DESC> m_Declaration;
};

typedef TArray<SOnDemandD3DVertexDeclaration> SOnDemandD3DVertexDeclarations;

struct SOnDemandD3DVertexDeclarationCache
{
	ID3D11InputLayout* m_pDeclaration;
};

typedef TArray<SOnDemandD3DVertexDeclarationCache> SOnDemandD3DVertexDeclarationCaches;

struct SVertexDeclaration
{
	int                              StreamMask;
	int                              VertFormat;
	int                              InstAttrMask;
	TArray<D3D11_INPUT_ELEMENT_DESC> m_Declaration;
	ID3D11InputLayout*               m_pDeclaration;

	~SVertexDeclaration()
	{
		SAFE_RELEASE(m_pDeclaration);
	}
};

struct SRTargetStat
{
	string      m_Name;
	uint32      m_nSize;
	uint32      m_nWidth;
	uint32      m_nHeight;
	ETEX_Format m_eTF;
};

class CHWShader;

struct CRY_ALIGN(128) SPipeStat
{
	int m_NumPSInstructions;
	int m_NumVSInstructions;
	int m_RTCleared;
	int m_RTClearedSize;
	int m_RTCopied;
	int m_RTCopiedSize;
	int m_RTSize;
	CHWShader* m_pMaxPShader;
	CHWShader* m_pMaxVShader;
	void* m_pMaxPSInstance;
	void* m_pMaxVSInstance;
	uint64_t m_ManagedTexturesStreamSysSize;
	uint64_t m_ManagedTexturesStreamVidSize;
	uint64_t m_ManagedTexturesSysMemSize;
	uint64_t m_ManagedTexturesVidMemSize;
	uint64_t m_DynTexturesSize;
	uint64_t m_MeshUpdateBytes;
	uint64_t m_DynMeshUpdateBytes;
	float m_fOverdraw;
	float m_fSkinningTime;
	float m_fPreprocessTime;
	float m_fSceneTimeMT;
	float m_fTexUploadTime;
	float m_fTexRestoreTime;
	float m_fOcclusionTime;
	float m_fRenderTime;
	float m_fEnvTextUpdateTime;
	static SPipeStat* s_pCurrentOutput;
};

static_assert(sizeof(SPipeStat) == 256);

//Batch flags.
// - When adding/removing batch flags, please, update sBatchList static list in D3DRendPipeline.cpp
enum EBatchFlags
{
	FB_GENERAL = 0x1,
	FB_TRANSPARENT = 0x2,
	FB_SKIN = 0x4,
	FB_Z = 0x8,
	FB_BELOW_WATER = 0x10,
	FB_ZPREPASS = 0x20,
	FB_ALPHA_TEST = 0x40,
	FB_COMPILED_OBJECT = 0x100,
	FB_CUSTOM_RENDER = 0x200,
	FB_WATER_REFL = 0x400,
	FB_WATER_CAUSTIC = 0x800,
	FB_TILED_FORWARD = 0x2000,
	FB_EYE_OVERLAY = 0x4000,
	FB_ARK_SCENEMASK_GEN = 0x8000,
	FB_ZPREPASS_INDEX = 0x5,
	FB_ALPHA_TEST_INDEX = 0x6,

	FB_MASK            = 0xfffff //! FB flags cannot exceed 0xfffff
};

// Commit flags
#define FC_TARGETS             1
#define FC_GLOBAL_PARAMS       2
#define FC_PER_INSTANCE_PARAMS 4
#define FC_PER_BATCH_PARAMS    8
#define FC_MATERIAL_PARAMS     0x10
#define FC_ALL                 0x1f

// m_RP.m_Flags
#define RBF_NEAREST 0x10000

// m_RP.m_TI.m_PersFlags
#define RBPF_DRAWTOTEXTURE            (1 << 16) // 0x10000
#define RBPF_MIRRORCAMERA             (1 << 17) // 0x20000
#define RBPF_MIRRORCULL               (1 << 18) // 0x40000

#define RBPF_ZPASS                    (1 << 19) // 0x80000
#define RBPF_SHADOWGEN                (1 << 20) // 0x100000

#define RBPF_FP_DIRTY                 (1 << 21) // 0x200000
#define RBPF_FP_MATRIXDIRTY           (1 << 22) // 0x400000

#define RBPF_IMPOSTERGEN              (1 << 23)
#define RBPF_MAKESPRITE               (1 << 24) // 0x1000000

#define RBPF_HDR                      (1 << 26)
#define RBPF_REVERSE_DEPTH            (1 << 27)
#define RBPF_ENCODE_HDR               (1 << 29)
#define RBPF_OBLIQUE_FRUSTUM_CLIPPING (1 << 30)

// m_RP.m_PersFlags1
#define RBPF1_USESTREAM               (1 << 0)
#define RBPF1_USESTREAM_MASK          ((1 << VSF_NUM) - 1)

#define RBPF1_IN_CLEAR                (1 << 17)

#define RBPF1_SKIP_AFTER_POST_PROCESS (1 << 18)

// m_RP.m_PersFlags2
#define RBPF2_NOSHADERFOG                         (1 << 0)
#define RBPF2_RAINRIPPLES                         (1 << 1)
#define RBPF2_NOALPHABLEND                        (1 << 2)
#define RBPF2_SINGLE_FORWARD_LIGHT_PASS           (1 << 3)
#define RBPF2_MSAA_RESTORE_SAMPLE_MASK            (1 << 4)
#define RBPF2_READMASK_RESERVED_STENCIL_BIT       (1 << 5)
#define RBPF2_POST_3D_RENDERER_PASS               (1 << 6)
#define RBPF2_LENS_OPTICS_COMPOSITE               (1 << 7)
#define RBPF2_COMMIT_SG                           (1 << 8)
#define RBPF2_HDR_FP16                            (1 << 9)
#define RBPF2_CUSTOM_SHADOW_PASS                  (1 << 10)
#define RBPF2_CUSTOM_RENDER_PASS                  (1 << 11)
#define RBPF2_THERMAL_RENDERMODE_PASS             (1 << 12)

#define RBPF2_COMMIT_CM                           (1 << 13)
#define RBPF2_ZPREPASS                            (1 << 14)

#define RBPF2_FORWARD_SHADING_PASS                (1 << 15)

#define RBPF2_MSAA_STENCILCULL                    (1 << 16)

#define RBPF2_THERMAL_RENDERMODE_TRANSPARENT_PASS (1 << 17)
#define RBPF2_NOALPHATEST                         (1 << 18)
#define RBPF2_WATERRIPPLES                        (1 << 19)
#define RBPF2_ALLOW_DEFERREDSHADING               (1 << 20)

#define RBPF2_COMMIT_PF                           (1 << 21)
#define RBPF2_MSAA_SAMPLEFREQ_PASS                (1 << 22)
#define RBPF2_DRAWTOCUBE                          (1 << 23)

#define RBPF2_MOTIONBLURPASS                      (1 << 24)
#define RBPF2_MATERIALLAYERPASS                   (1 << 25)
#define RBPF2_DISABLECOLORWRITES                  (1 << 26)

#define RBPF2_NOPOSTAA                            (1 << 27)
#define RBPF2_SKIN                                (1 << 28)

#define RBPF2_LIGHTSHAFTS                         (1 << 29)
#define RBPF2_WRITEMASK_RESERVED_STENCIL_BIT      (1 << 30)   // 0x010
#define RBPF2_HALFRES_PARTICLES                   (1 << 31)

// m_RP.m_FlagsPerFlush
#define RBSI_LOCKCULL          0x2
#define RBSI_INSTANCED         0x10000000
#define RBSI_CUSTOM_PREVMATRIX 0x20000000

// m_RP.m_ShaderLightMask
#define SLMF_DIRECT      0
#define SLMF_POINT       1
#define SLMF_PROJECTED   2
#define SLMF_TYPE_MASK   (SLMF_POINT | SLMF_PROJECTED)

#define SLMF_LTYPE_SHIFT 8
#define SLMF_LTYPE_BITS  4

struct SLightPass
{
	SRenderLight* pLights[4];
	uint32        nStencLTMask;
	uint32        nLights;
	uint32        nLTMask;
	bool          bRect;
	RectI         rc;
};

#define MAX_STREAMS 16

struct SFogState
{
	bool   m_bEnable;
	ColorF m_FogColor;
	ColorF m_CurColor;

	bool operator!=(const SFogState& fs) const
	{
		return m_FogColor != fs.m_FogColor;
	}
};

enum EShapeMeshType
{
	SHAPE_PROJECTOR = 0,
	SHAPE_PROJECTOR1,
	SHAPE_PROJECTOR2,
	SHAPE_BOX,
	SHAPE_LIGHT_BEAM,
	SHAPE_MAX,
};

struct SThreadInfo
{
	uint32              m_PersFlags;                             // Never reset
	float               m_RealTime;
	float m_timers[4];
	class CMatrixStack* m_matView;
	class CMatrixStack* m_matProj;
	Matrix44            m_matCameraZero;
	CCamera             m_cam;                                   // current camera
	CRenderCamera       m_rcam;                                  // current camera
	int                 m_nFrameID;                              // with recursive calls, access through GetFrameID(true)
	uint32              m_nFrameUpdateID;                        // without recursive calls, access through GetFrameID(false)
	int                 m_arrZonesRoundId[MAX_PREDICTION_ZONES]; // rounds ID from 3D engine, useful for texture streaming
	SFogState           m_FS;

	byte                m_eCurColorOp;
	byte                m_eCurAlphaOp;
	byte                m_eCurColorArg;
	byte                m_eCurAlphaArg;

	SThreadInfo()
		: m_PersFlags(0)
		, m_RealTime(0.0f)
		, m_matView(nullptr)
		, m_matProj(nullptr)
		, m_nFrameID(0)
		, m_nFrameUpdateID(0)
		, m_eCurColorOp(0)
		, m_eCurAlphaOp(0)
		, m_eCurColorArg(0)
		, m_eCurAlphaArg(0)
	{
		ZeroArray(m_arrZonesRoundId);
		ZeroStruct(m_FS);
	}

	~SThreadInfo() {}
	SThreadInfo& operator=(const SThreadInfo& ti)
	{
		if (&ti == this) return *this;
		m_PersFlags = ti.m_PersFlags;
		m_RealTime = ti.m_RealTime;
		m_matView = ti.m_matView;
		m_matProj = ti.m_matProj;
		m_cam = ti.m_cam;
		m_rcam = ti.m_rcam;
		m_nFrameID = ti.m_nFrameID;
		for (int z = 0; z < MAX_PREDICTION_ZONES; z++)
			m_arrZonesRoundId[z] = ti.m_arrZonesRoundId[z];
		m_FS = ti.m_FS;
		m_eCurColorOp = ti.m_eCurColorOp;
		m_eCurAlphaOp = ti.m_eCurAlphaOp;
		m_eCurColorArg = ti.m_eCurColorArg;
		m_eCurAlphaArg = ti.m_eCurAlphaArg;
		return *this;
	}
};

static_assert(sizeof(SThreadInfo) == 808);

#ifdef STRIP_RENDER_THREAD
struct SSingleThreadInfo : public SThreadInfo
{
	SThreadInfo&       operator[](const int)       { return *this; }
	const SThreadInfo& operator[](const int) const { return *this; }
};
#endif

class CShader;
struct SShaderTechnique;
class CShaderResources;
class CPermanentRenderObject;
class CREDeferredShading;
class CREPostProcess;

// Render pipeline structure
struct SRenderPipeline
{
	CShader* m_pShader;
	CRenderObject* m_pCurObject;
	CRenderObject* m_pIdendityRenderObject;
	CRendElementBase* m_pRE;
	int m_RendNumVerts;
	unsigned m_nBatchFilter;
	SShaderTechnique* m_pRootTechnique;
	SShaderTechnique* m_pCurTechnique;
	SShaderPass* m_pCurPass;
	unsigned m_CurPassBitMask;
	int m_nShaderTechnique;
	int m_nShaderTechniqueType;
	CShaderResources* m_pShaderResources;
	CRenderObject* m_pPrevObject;
	int m_nLastRE;
	TArray<SRendItem*> m_RIs[16];
	ColorF m_CurGlobalColor;
	float m_fMinDistance;
	uint64_t m_ObjFlags;
	int m_Flags;
	Matrix44 m_OcclusionCameraBuffer[4];
	int m_nZOcclusionProcess;
	int m_nZOcclusionReady;
	int m_nZOcclusionBufferID;
	unsigned long m_nFillThreadID;
	unsigned long m_nProcessThreadID;
	SThreadInfo m_TI[2];
	SThreadInfo m_OldTI[1];
	CThreadSafeRendererContainer<ColorF> m_fogVolumeContibutions[2];
	unsigned m_PersFlags1;
	unsigned m_PersFlags2;
	uint8_t m_nSceneMask;
	int m_FlagsPerFlush;
	unsigned m_nCommitFlags;
	unsigned m_FlagsStreams_Decl;
	unsigned m_FlagsStreams_Stream;
	EVertexFormat m_CurVFormat;
	unsigned m_FlagsShader_LT;
	uint64_t m_FlagsShader_RT;
	unsigned m_FlagsShader_MD;
	unsigned m_FlagsShader_MDV;
	uint64_t m_FlagsShader_PipelineState;
	unsigned m_nShaderQuality;
	void (*m_pRenderFunc)();
	unsigned m_CurState;
	unsigned m_StateOr;
	unsigned m_StateAnd;
	int m_CurAlphaRef;
	unsigned m_MaterialStateOr;
	unsigned m_MaterialStateAnd;
	int m_MaterialAlphaRef;
	unsigned m_ForceStateOr;
	unsigned m_ForceStateAnd;
	bool m_bIgnoreObjectAlpha;
	ECull m_eCull;

	struct SPipelineStreamInfo
	{
		D3DBuffer* pStream;
		int        nOffset;
		int        nStride;

		SPipelineStreamInfo() {}
		SPipelineStreamInfo(D3DBuffer* stream, int offset, int stride) : pStream(stream), nOffset(offset), nStride(stride) {}
	};

	SRenderPipeline::SPipelineStreamInfo m_VertexStreams[16];
	ID3D11Buffer* m_pIndexStream;
	unsigned m_IndexStreamOffset;
	RenderIndexType m_IndexStreamType;
	bool m_bFirstPass;
	unsigned m_nNumRendPasses;
	int m_NumShaderInstructions;
	CCamera m_PrevCamera;
	unsigned m_nRendFlags;
	bool m_bUseHDR;
	int m_nPassGroupID;
	int m_nPassGroupDIP;
	unsigned m_nFlagsShaderBegin;
	uint8_t m_nCurrResolveBounds[4];
	Vec2 m_CurDownscaleFactor;
	ERenderQuality m_eQuality;
	CThreadSafeRendererContainer<CPermanentRenderObject*> m_persistentRenderObjectsToDelete[2];
	UVertStreamPtr m_StreamPtrTang;
	UVertStreamPtr m_NextStreamPtrTang;
	UVertStreamPtr m_StreamPtr;
	UVertStreamPtr m_NextStreamPtr;
	int m_StreamStride;
	int m_StreamOffsetTC;
	int m_StreamOffsetColor;
	CLightVolumeBuffer m_lightVolumeBuffer;
	CParticleBufferSet m_particleBuffer;
	int m_nStreamOffset[3];
	TArray<SOnDemandD3DVertexDeclaration> m_D3DVertexDeclaration;
	TArray<SOnDemandD3DVertexDeclarationCache> m_D3DVertexDeclarationCache[64][2];
	SOnDemandD3DStreamProperties m_D3DStreamProperties[6];
	TArray<SVertexDeclaration*> m_CustomVD;
	uint16_t* m_RendIndices;
	uint16_t* m_SysRendIndices;
	uint8_t* m_SysArray;
	int m_SizeSysArray;
	TArray<unsigned char> m_SysVertexPool[2];
	TArray<unsigned short> m_SysIndexPool[2];
	int m_RendNumGroup;
	int m_RendNumIndices;
	int m_FirstIndex;
	int m_FirstVertex;
	int m_Frame;
	int m_FrameMerge;
	float m_fCurOpacity;
	SPipeStat m_PS[2];
	DynArray<SRTargetStat, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_RTStats;
	int m_MaxVerts;
	int m_MaxTris;
	int m_ShadowCustomTexBind[8];
	CRenderView* m_pCurrentRenderView;
	_smart_ptr<CRenderView> m_pRenderViews[2][2];
	SRenderLight* m_pSunLight;
	CThreadSafeWorkerContainer<CRenderObject*> m_TempObjects[2];
	CRenderObject* m_ObjectsPool;
	unsigned m_nNumObjectsInPool;
	std::shared_ptr<CRenderObjectsPools> m_renderObjectsPools;
	CREDeferredShading* m_pREDeferredShading;
	CREPostProcess* m_pREPostProcess;
	static constexpr const unsigned sSinTableCount = 1024;
	float m_tSinTable[1024];
	Matrix44* m_pPrevMatrix;

public:
	SRenderPipeline();
	~SRenderPipeline();

	void InitWaveTables();

	// Arguments
	//   vertexformat - 0..VERTEX_FORMAT_NUMS-1
	void OnDemandVertexDeclaration(SOnDemandD3DVertexDeclaration& out, const int nStreamMask, const int vertexformat, const bool bMorph, const bool bInstanced);
	void InitD3DVertexDeclarations();
	EVertexFormat AddD3DVertexDeclaration(size_t numDescs, const D3D11_INPUT_ELEMENT_DESC* inputLayout);
	EVertexFormat MaxD3DVertexDeclaration() { return EVertexFormat(m_D3DVertexDeclaration.size()); }
};

static_assert(sizeof(SRenderPipeline) == 14592);

extern CryCriticalSection m_sREResLock;

///////////////////////////////////////////////////////////////////////////////
// sort operators for render items
struct SCompareItemPreprocess
{
	bool operator()(const SRendItem& a, const SRendItem& b) const
	{
		if (a.nBatchFlags != b.nBatchFlags)
			return a.nBatchFlags < b.nBatchFlags;

		if (a.SortVal != b.SortVal)
			return a.SortVal < b.SortVal;

		return a.rendItemSorter < b.rendItemSorter;
	}
};

///////////////////////////////////////////////////////////////////////////////
struct SCompareRendItem
{
	bool operator()(const SRendItem& a, const SRendItem& b) const
	{
#if 0
		int nMotionVectorsA = (a.ObjSort & FOB_HAS_PREVMATRIX);
		int nMotionVectorsB = (b.ObjSort & FOB_HAS_PREVMATRIX);
		if (nMotionVectorsA != nMotionVectorsB)
			return nMotionVectorsA > nMotionVectorsB;

		int nAlphaTestA = (a.ObjSort & FOB_ALPHATEST);
		int nAlphaTestB = (b.ObjSort & FOB_ALPHATEST);
		if (nAlphaTestA != nAlphaTestB)
			return nAlphaTestA < nAlphaTestB;

		if (a.SortVal != b.SortVal)         // Sort by shaders
			return a.SortVal < b.SortVal;

		if (a.pElem != b.pElem)               // Sort by geometry
			return a.pElem < b.pElem;

		return (a.ObjSort & 0xFFFF) < (b.ObjSort & 0xFFFF);   // Sort by distance
#endif
		return false;
	}
};

///////////////////////////////////////////////////////////////////////////////
struct SCompareRendItemZPass
{
	bool operator()(const SRendItem& a, const SRendItem& b) const
	{
#if 0
		const int layerSize = 50;  // Note: ObjSort contains round(entityDist * 2) for meshes

		int nMotionVectorsA = (a.ObjSort & FOB_HAS_PREVMATRIX);
		int nMotionVectorsB = (b.ObjSort & FOB_HAS_PREVMATRIX);
		if (nMotionVectorsA != nMotionVectorsB)
			return nMotionVectorsA > nMotionVectorsB;

		int nAlphaTestA = (a.ObjSort & FOB_ALPHATEST);
		int nAlphaTestB = (b.ObjSort & FOB_ALPHATEST);
		if (nAlphaTestA != nAlphaTestB)
			return nAlphaTestA < nAlphaTestB;

		// Sort by depth/distance layers
		int depthLayerA = (a.ObjSort & 0xFFFF) / layerSize;
		int depthLayerB = (b.ObjSort & 0xFFFF) / layerSize;
		if (depthLayerA != depthLayerB)
			return depthLayerA < depthLayerB;

		if (a.SortVal != b.SortVal)    // Sort by shaders
			return a.SortVal < b.SortVal;

		// Sorting by geometry less important than sorting by shaders
		if (a.pElem != b.pElem)    // Sort by geometry
			return a.pElem < b.pElem;

		return (a.ObjSort & 0xFFFF) < (b.ObjSort & 0xFFFF);    // Sort by distance
#endif
		return false;
	}
};

///////////////////////////////////////////////////////////////////////////////
struct SCompareItem_Decal
{
	bool operator()(const SRendItem& a, const SRendItem& b) const
	{
		uint32 objSortA_Low(a.ObjSort & 0xFFFF);
		uint32 objSortA_High(a.ObjSort & ~0xFFFF);
		uint32 objSortB_Low(b.ObjSort & 0xFFFF);
		uint32 objSortB_High(b.ObjSort & ~0xFFFF);

		if (objSortA_Low != objSortB_Low)
			return objSortA_Low < objSortB_Low;

		if (a.SortVal != b.SortVal)
			return a.SortVal < b.SortVal;

		return objSortA_High < objSortB_High;
	}
};

///////////////////////////////////////////////////////////////////////////////
struct SCompareItem_NoPtrCompare
{
	bool operator()(const SRendItem& a, const SRendItem& b) const
	{
#if 0
		if (a.ObjSort != b.ObjSort)
			return a.ObjSort < b.ObjSort;

		float pSurfTypeA = ((float*)a.pElem->m_CustomData)[8];
		float pSurfTypeB = ((float*)b.pElem->m_CustomData)[8];
		if (pSurfTypeA != pSurfTypeB)
			return (pSurfTypeA < pSurfTypeB);

		pSurfTypeA = ((float*)a.pElem->m_CustomData)[9];
		pSurfTypeB = ((float*)b.pElem->m_CustomData)[9];
		if (pSurfTypeA != pSurfTypeB)
			return (pSurfTypeA < pSurfTypeB);

		pSurfTypeA = ((float*)a.pElem->m_CustomData)[11];
		pSurfTypeB = ((float*)b.pElem->m_CustomData)[11];
		return (pSurfTypeA < pSurfTypeB);
#endif
		return false;
	}
};

///////////////////////////////////////////////////////////////////////////////
struct SCompareDist
{
	bool operator()(const SRendItem& a, const SRendItem& b) const
	{
		if (a.fDist == b.fDist)
			return a.rendItemSorter.ParticleCounter() < b.rendItemSorter.ParticleCounter();

		return (a.fDist > b.fDist);
	}
};

///////////////////////////////////////////////////////////////////////////////
struct SCompareDistInverted
{
	bool operator()(const SRendItem& a, const SRendItem& b) const
	{
		if (a.fDist == b.fDist)
			return a.rendItemSorter.ParticleCounter() > b.rendItemSorter.ParticleCounter();

		return (a.fDist < b.fDist);
	}
};

///////////////////////////////////////////////////////////////////////////////
struct SCompareByRenderingPass
{
	bool operator()(const SRendItem& rA, const SRendItem& rB) const
	{
		return rA.rendItemSorter.IsRecursivePass() < rB.rendItemSorter.IsRecursivePass();
	}
};

///////////////////////////////////////////////////////////////////////////////
struct SCompareByOnlyStableFlagsOctreeID
{
	bool operator()(const SRendItem& rA, const SRendItem& rB) const
	{
		return rA.rendItemSorter < rB.rendItemSorter;
	}
};

#endif  // __RENDERPIPELINE_H__
