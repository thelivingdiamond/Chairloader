#pragma once

#include <Prey/CryCore/smartptr.h>
#include <Prey/CryMath/Cry_Math.h>
#include <Prey/CryRenderer/ITexture.h>
#include <Prey/CryRenderer/IShader.h>

#include "Prey/CryMath/Cry_Camera.h"
#include "Prey/CrySystem/IConsole.h"

const int MAX_GSM_LODS_NUM = 16;

// Object states
#define OS_ALPHA_BLEND         0x1
#define OS_ADD_BLEND           0x2
#define OS_MULTIPLY_BLEND      0x4
#define OS_TRANSPARENT         (OS_ALPHA_BLEND | OS_ADD_BLEND | OS_MULTIPLY_BLEND)
#define OS_NODEPTH_TEST        0x8
#define OS_NODEPTH_WRITE       0x10
#define OS_ANIM_BLEND          0x20
#define OS_ENVIRONMENT_CUBEMAP 0x40

// Render State flags (uint32)
#define GS_BLSRC_ZERO              0x01
#define GS_BLSRC_ONE               0x02
#define GS_BLSRC_DSTCOL            0x03
#define GS_BLSRC_ONEMINUSDSTCOL    0x04
#define GS_BLSRC_SRCALPHA          0x05
#define GS_BLSRC_ONEMINUSSRCALPHA  0x06
#define GS_BLSRC_DSTALPHA          0x07
#define GS_BLSRC_ONEMINUSDSTALPHA  0x08
#define GS_BLSRC_ALPHASATURATE     0x09
#define GS_BLSRC_SRCALPHA_A_ZERO   0x0A  // separate alpha blend state
#define GS_BLSRC_SRC1ALPHA         0x0B  // dual source blending
#define GS_BLSRC_MASK              0x0F
#define GS_BLSRC_SHIFT             0

#define GS_BLDST_ZERO              0x10
#define GS_BLDST_ONE               0x20
#define GS_BLDST_SRCCOL            0x30
#define GS_BLDST_ONEMINUSSRCCOL    0x40
#define GS_BLDST_SRCALPHA          0x50
#define GS_BLDST_ONEMINUSSRCALPHA  0x60
#define GS_BLDST_DSTALPHA          0x70
#define GS_BLDST_ONEMINUSDSTALPHA  0x80
#define GS_BLDST_ONE_A_ZERO        0x90 // separate alpha blend state
#define GS_BLDST_ONEMINUSSRC1ALPHA 0xA0 // dual source blending
#define GS_BLDST_MASK              0xF0
#define GS_BLDST_SHIFT             4

#define GS_DEPTHWRITE              0x00000100
#define GS_NODEPTHTEST             0x00000200
#define GS_STENCIL                 0x00000400
#define GS_ALPHATEST               0x00000800

#define GS_NOCOLMASK_R             0x00001000
#define GS_NOCOLMASK_G             0x00002000
#define GS_NOCOLMASK_B             0x00004000
#define GS_NOCOLMASK_A             0x00008000
#define GS_COLMASK_RGB             (GS_NOCOLMASK_A)
#define GS_COLMASK_A               (GS_NOCOLMASK_R | GS_NOCOLMASK_G | GS_NOCOLMASK_B)
#define GS_COLMASK_NONE            (GS_NOCOLMASK_R | GS_NOCOLMASK_G | GS_NOCOLMASK_B | GS_NOCOLMASK_A)
#define GS_COLMASK_MASK            GS_COLMASK_NONE
#define GS_COLMASK_SHIFT           12

#define GS_WIREFRAME               0x00010000
#define GS_POINTRENDERING          0x00020000

#define GS_DEPTHFUNC_LEQUAL        0x00000000
#define GS_DEPTHFUNC_EQUAL         0x00040000
#define GS_DEPTHFUNC_GREAT         0x00080000
#define GS_DEPTHFUNC_LESS          0x000C0000
#define GS_DEPTHFUNC_GEQUAL        0x00100000
#define GS_DEPTHFUNC_NOTEQUAL      0x00140000
#define GS_DEPTHFUNC_MASK          0x001C0000 // enum
#define GS_DEPTHFUNC_SHIFT         18

#define GS_BLEND_OP_ADD            0x00000000
#define GS_BLEND_OP_MAX            0x00200000
#define GS_BLEND_OP_MIN            0x00400000
#define GS_BLEND_OP_SUB            0x00600000
#define GS_BLEND_OP_SUBREV         0x00800000
#define GS_BLEND_OP_MASK           0x00E00000 // enum
#define GS_BLEND_OP_SHIFT          21

// Separate alpha blend mode
#define GS_BLALPHA_NONSEP 0x00000000          // same alpha blend op as color blend op (non-separate)
#define GS_BLALPHA_MAX    0x02000000
#define GS_BLALPHA_MIN    0x04000000
#define GS_BLALPHA_MASK   0x0E000000          // enum
#define GS_BLALPHA_SHIFT  25

#define GS_BLEND_MASK     (GS_BLSRC_MASK | GS_BLDST_MASK | GS_BLEND_OP_MASK | GS_BLALPHA_MASK)

#define FORMAT_8_BIT      8
#define FORMAT_24_BIT     24
#define FORMAT_32_BIT     32

// Refresh render resources flags.
// Flags passed in function RefreshResources.
#define FRO_SHADERS        1
#define FRO_SHADERTEXTURES 2
#define FRO_TEXTURES       4
#define FRO_GEOMETRY       8
#define FRO_FORCERELOAD    0x10

//! SLI/CROSSFIRE GPU maximum count.
#define MAX_GPU_NUM 4

//////////////////////////////////////////////////////////////////////
#define R_CULL_DISABLE 0
#define R_CULL_NONE    0
#define R_CULL_FRONT   1
#define R_CULL_BACK    2

//////////////////////////////////////////////////////////////////////////
/// CRenderObject::m_ObjFlags: Flags used by shader pipeline
//////////////////////////////////////////////////////////////////////////
enum ERenderObjectFlags : uint64
{
	FOB_TRANS_ROTATE                = BIT64(0),
	FOB_TRANS_SCALE                 = BIT64(1),
	FOB_TRANS_TRANSLATE             = BIT64(2),
	//FOB_RENDER_AFTER_POSTPROCESSING = BIT64(3),
	FOB_OWNER_GEOMETRY              = BIT64(4),
	FOB_MESH_SUBSET_INDICES         = BIT64(5),
	//FOB_SELECTED                    = BIT64(6),
	FOB_RENDERER_IDENDITY_OBJECT    = BIT64(7),
	FOB_IN_DOORS							      = BIT64(8),
	FOB_NO_FOG                      = BIT64(9),
	FOB_DECAL                       = BIT64(10),
	FOB_OCTAGONAL                   = BIT64(11),
	FOB_BLEND_WITH_TERRAIN_COLOR    = BIT64(12),
	FOB_POINT_SPRITE                = BIT64(13),
	FOB_SOFT_PARTICLE               = BIT64(14),
	FOB_REQUIRES_RESOLVE            = BIT64(15),
	FOB_UPDATED_RTMASK              = BIT64(16),
	FOB_AFTER_WATER                 = BIT64(17),
	FOB_BENDED                      = BIT64(18),
	FOB_ZPREPASS                    = BIT64(19),
	FOB_INSHADOW                    = BIT64(20),
	FOB_DISSOLVE                    = BIT64(21),
	FOB_MOTION_BLUR                 = BIT64(22),
	FOB_NEAREST                     = BIT64(23), // [Rendered in Camera Space]
	FOB_SKINNED                     = BIT64(24),
	FOB_DISSOLVE_OUT                = BIT64(25),
	FOB_DYNAMIC_OBJECT              = BIT64(26),
	FOB_ALLOW_TESSELLATION          = BIT64(27),
	FOB_DECAL_TEXGEN_2D             = BIT64(28),
	FOB_ALPHATEST                   = BIT64(29),  // Careful when moving (used in ObjSort)
	FOB_HAS_PREVMATRIX              = BIT64(30),  // Careful when moving (used in ObjSort)
	FOB_LIGHTVOLUME                 = BIT64(31),

	FOB_TERRAIN_LAYER               = BIT64(32),

	FOB_TRANS_MASK                  = (FOB_TRANS_ROTATE | FOB_TRANS_SCALE | FOB_TRANS_TRANSLATE),
	FOB_DECAL_MASK                  = (FOB_DECAL | FOB_DECAL_TEXGEN_2D),
	FOB_PARTICLE_MASK               = (FOB_SOFT_PARTICLE | FOB_NO_FOG | FOB_INSHADOW | FOB_NEAREST | FOB_MOTION_BLUR | FOB_LIGHTVOLUME | FOB_ALLOW_TESSELLATION | FOB_IN_DOORS | FOB_AFTER_WATER),

	// WARNING: FOB_MASK_AFFECTS_MERGING must start from 0x10000/bit 16 (important for instancing).
	FOB_MASK_AFFECTS_MERGING_GEOM = (FOB_ZPREPASS | FOB_SKINNED | FOB_BENDED | FOB_DYNAMIC_OBJECT | FOB_ALLOW_TESSELLATION | FOB_NEAREST),
	FOB_MASK_AFFECTS_MERGING      = (FOB_ZPREPASS | FOB_MOTION_BLUR | FOB_HAS_PREVMATRIX | FOB_SKINNED | FOB_BENDED | FOB_INSHADOW | FOB_AFTER_WATER | FOB_DISSOLVE | FOB_DISSOLVE_OUT | FOB_NEAREST | FOB_DYNAMIC_OBJECT | FOB_ALLOW_TESSELLATION),
};


//! Flags used in DrawText function.
enum EDrawTextFlags
{
	eDrawText_Center = BIT(0),  //!< Centered alignment, otherwise right or left.
	eDrawText_Right = BIT(1),  //!< Right alignment, otherwise center or left.
	eDrawText_CenterV = BIT(2),  //!< Center vertically, oterhwise top.
	eDrawText_Bottom = BIT(3),  //!< Bottom alignment.

	eDrawText_2D = BIT(4),  //!< 3-component vector is used for xy screen position, otherwise it's 3d world space position.

	eDrawText_FixedSize = BIT(5),  //!< Font size is defined in the actual pixel resolution, otherwise it's in the virtual 800x600.
	eDrawText_800x600 = BIT(6),  //!< Position are specified in the virtual 800x600 resolution, otherwise coordinates are in pixels.

	eDrawText_Monospace = BIT(7),  //!< Non proportional font rendering (Font width is same for all characters).

	eDrawText_Framed = BIT(8),  //!< Draw a transparent, rectangular frame behind the text to ease readability independent from the background.

	eDrawText_DepthTest = BIT(9),  //!< Text should be occluded by world geometry using the depth buffer.
	eDrawText_IgnoreOverscan = BIT(10), //!< Ignore the overscan borders, text should be drawn at the location specified.
};

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

enum class EFullscreenMode : int8_t
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

enum ERenderQueryTypes
{
	EFQ_DeleteMemoryArrayPtr = 0x1,
	EFQ_DeleteMemoryPtr = 0x2,
	EFQ_GetShaderCombinations = 0x3,
	EFQ_SetShaderCombinations = 0x4,
	EFQ_CloseShaderCombinations = 0x5,
	EFQ_MainThreadList = 0x6,
	EFQ_RenderThreadList = 0x7,
	EFQ_RenderMultithreaded = 0x8,
	EFQ_RecurseLevel = 0x9,
	EFQ_IncrementFrameID = 0xA,
	EFQ_DeviceLost = 0xB,
	EFQ_Alloc_APITextures = 0xC,
	EFQ_Alloc_APIMesh = 0xD,
	EFQ_Alloc_Mesh_SysMem = 0xE,
	EFQ_Mesh_Count = 0xF,
	EFQ_HDRModeEnabled = 0x10,
	EFQ_ParticlesTessellation = 0x11,
	EFQ_MeshTessellation = 0x12,
	EFQ_GetShadowPoolFrustumsNum = 0x13,
	EFQ_GetShadowPoolAllocThisFrameNum = 0x14,
	EFQ_GetShadowMaskChannelsNum = 0x15,
	EFQ_GetTiledShadingSkippedLightsNum = 0x16,
	EFQ_GetAllTextures = 0x17,
	EFQ_GetAllTexturesRelease = 0x18,
	EFQ_GetAllMeshes = 0x19,
	EFQ_MultiGPUEnabled = 0x1A,
	EFQ_SetDrawNearFov = 0x1B,
	EFQ_GetDrawNearFov = 0x1C,
	EFQ_TextureStreamingEnabled = 0x1D,
	EFQ_MSAAEnabled = 0x1E,
	EFQ_AAMode = 0x1F,
	EFQ_Fullscreen = 0x20,
	EFQ_GetTexStreamingInfo = 0x21,
	EFQ_GetMeshPoolInfo = 0x22,
	EFQ_sLinearSpaceShadingEnabled = 0x23,
	EFQ_OverscanBorders = 0x24,
	EFQ_TexturesPoolSize = 0x25,
	EFQ_RenderTargetPoolSize = 0x26,
	EFQ_GetShaderCacheInfo = 0x27,
	EFQ_GetMaxRenderObjectsNum = 0x28,
	EFQ_IsRenderLoadingThreadActive = 0x29,
	EFQ_GetParticleVertexBufferSize = 0x2A,
	EFQ_GetParticleIndexBufferSize = 0x2B,
	EFQ_GetMaxParticleContainer = 0x2C,
	EFQ_GetSkinningDataPoolSize = 0x2D,
	EFQ_SetDynTexSourceLayerInfo = 0x2E,
	EFQ_SetDynTexSourceSharedRTDim = 0x2F,
	EFQ_GetViewportDownscaleFactor = 0x30,
	EFQ_ReverseDepthEnabled = 0x31,
	EFQ_GetLastD3DDebugMessage = 0x32,
};

enum eDeferredLightType : __int32
{
	eDLT_DeferredLight = 0,
	eDLT_NumShadowCastingLights = eDLT_DeferredLight + 1,

	//! These lights cannot cast shadows.
	eDLT_DeferredCubemap,
	eDLT_DeferredAmbientLight,
	eDLT_DynamicLight, // Not deferred light
	eDLT_NumLightTypes,
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
struct IRenderMesh;
struct IShader;
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
class IArkRenderPersistentAuxGeom;
class IColorGradingController;
struct SResourceAsync;
class ISyncMainWithRenderListener;
struct IRenderNode;
class IOpticsElementBase;
class ISoftOcclusionQuery;
struct SSF_GlobalDrawParams;
struct RectI;
struct SRenderingPassInfo;
struct RPProfilerStats;
enum ERenderPipelineProfilerStats;
enum EVertexCostTypes;
class ILoadtimeCallback;
struct ShadowFrustumMGPUCache;
class IArkBinkManager;
struct SSkinningData;
struct IRenderAuxGeom;
struct IImageFile;
struct IGraphicsDeviceConstantBuffer;
namespace gpu_pfx2
{
class IManager;
} // namespace gpu_pfx2

struct SShaderCacheStatistics // Id=8003D26 Size=32
{
	uint64_t m_nTotalLevelShaderCacheMisses;
	uint64_t m_nGlobalShaderCacheMisses;
	uint64_t m_nNumShaderAsyncCompiles;
	bool m_bShaderCompileActive;
};

//! This structure used in DrawText method of renderer.
//! It provide all necessary information of how to render text on screen.
struct SDrawTextInfo
{
	//! One of EDrawTextFlags flags.
	int flags;

	//! Text color, (r,g,b,a) all members must be specified.
	float color[4];
	float xscale;
	float yscale;

	SDrawTextInfo()
	{
		flags = 0;
		color[0] = color[1] = color[2] = color[3] = 1;
		xscale = 1.0f;
		yscale = 1.0f;
	}
};

class CLodValue
{
public:
	CLodValue() {
		m_nLodA = -1;
		m_nLodB = -1;
		m_nDissolveRef = 0;
	}

	CLodValue(int nLodA) {
		m_nLodA = nLodA;
		m_nLodB = -1;
		m_nDissolveRef = 0;
	}

	CLodValue(int nLodA, uint8 nDissolveRef, int nLodB) {
		m_nLodA = nLodA;
		m_nLodB = nLodB;
		m_nDissolveRef = nDissolveRef;
	}

	int  LodA() const { return m_nLodA; }
	int  LodSafeA() const { return m_nLodA == -1 ? 0 : m_nLodA; }
	int  LodB() const { return m_nLodB; }

	uint DissolveRefA() const { return m_nDissolveRef; }
	uint DissolveRefB() const { return 255 - m_nDissolveRef; }

private:
	int16 m_nLodA;
	int16 m_nLodB;
	uint8 m_nDissolveRef;
};

class CRenderCamera
{
public:
	CRenderCamera();
	CRenderCamera(const CRenderCamera &Cam);
	void        Copy(const CRenderCamera &Cam);

	void        LookAt(const Vec3 &Eye, const Vec3 &ViewRefPt, const Vec3 &ViewUp);
	void        Perspective(float Yfov, float Aspect, float Ndist, float Fdist);
	void        Frustum(float l, float r, float b, float t, float Ndist, float Fdist);
	const Vec3 &wCOP() const;
	Vec3        ViewDir() const;
	Vec3        ViewDirOffAxis() const;

	float *GetXform_Screen2Obj(float *M, int WW, int WH) const;
	float *GetXform_Obj2Screen(float *M, int WW, int WH) const;

	float *GetModelviewMatrix(float *M) const;
	float *GetProjectionMatrix(float *M) const;
	float *GetViewportMatrix(float *M, int WW, int WH) const;

	void        SetModelviewMatrix(const float *M);

	void        GetLookAtParams(Vec3 *Eye, Vec3 *ViewRefPt, Vec3 *ViewUp) const;
	void        GetPerspectiveParams(float *Yfov, float *Xfov, float *Aspect, float *Ndist, float *Fdist) const;
	void        GetFrustumParams(float *l, float *r, float *b, float *t, float *Ndist, float *Fdist) const;

	float *GetInvModelviewMatrix(float *M) const;
	float *GetInvProjectionMatrix(float *M) const;
	float *GetInvViewportMatrix(float *M, int WW, int WH) const;

	Vec3        WorldToCam(const Vec3 &wP) const;
	float       WorldToCamZ(const Vec3 &wP) const;
	Vec3        CamToWorld(const Vec3 &cP) const;

	void        LoadIdentityXform();
	void        Xform(const float M[16]);

	void        Translate(const Vec3 &trans);
	void        Rotate(const float M[9]);

	void        GetPixelRay(float sx, float sy, int ww, int wh, Vec3 *Start, Vec3 *Dir) const;

	void        CalcVerts(Vec3 *V) const;
	void        CalcTileVerts(Vec3 *V, f32 nPosX, f32 nPosY, f32 nGridSizeX, f32 nGridSizeY) const;
	void        CalcRegionVerts(Vec3 *V, const Vec2 &vMin, const Vec2 &vMax) const;
	void        CalcTiledRegionVerts(Vec3 *V, Vec2 &vMin, Vec2 &vMax, f32 nPosX, f32 nPosY, f32 nGridSizeX, f32 nGridSizeY) const;

	Vec3  vX, vY, vZ;
	Vec3  vOrigin;
	float fWL, fWR, fWB, fWT;
	float fNear, fFar;
};

struct IClipVolume;

// Interface to the render view.
struct IRenderView : public CMultiThreadRefCount
{
	// View can be in either reading or writing modes.
	enum EUsageMode
	{
		eUsageModeUndefined,
		eUsageModeReading,
		eUsageModeReadingDone,
		eUsageModeWriting,
		eUsageModeWritingDone,
	};
	virtual void   SetFrameId(uint64 frameId) = 0;
	virtual uint64 GetFrameId() const = 0;

	/// @See SRenderingPassInfo::ESkipRenderingFlags
	virtual void   SetSkipRenderingFlags(uint32 nFlags) = 0;
	virtual uint32 GetSkipRenderingFlags() const = 0;

	/// @see EShaderRenderingFlags
	virtual void   SetShaderRenderingFlags(uint32 nFlags) = 0;
	virtual uint32 GetShaderRenderingFlags() const = 0;

	virtual void   SetCamera(const CCamera &camera) = 0;
	virtual void   SetPreviousFrameCamera(const CCamera &camera) = 0;

	virtual void   SwitchUsageMode(EUsageMode mode) = 0;

	// All jobs that write items to render view should share and use this synchronization mutex.
	virtual void *GetWriteMutex() = 0;

	//////////////////////////////////////////////////////////////////////////
	// Access to dynamic lights
	virtual void          AddDynamicLight(SRenderLight &light) = 0;
	virtual int           GetDynamicLightsCount() const = 0;
	virtual SRenderLight &GetDynamicLight(int nLightId) = 0;

	virtual void          AddLight(eDeferredLightType lightType, SRenderLight &light) = 0;
	virtual int           GetLightsCount(eDeferredLightType lightType) const = 0;
	virtual SRenderLight &GetLight(eDeferredLightType lightType, int nLightId) = 0;
	virtual void ArkAddClusteredDecal(SDeferredDecal *) = 0;
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// Interface for 3d engine
	//////////////////////////////////////////////////////////////////////////
	virtual void AddPermanentObject(CRenderObject *pRenderObject, float, const SRenderingPassInfo &passInfo) = 0;

	//////////////////////////////////////////////////////////////////////////
	// Clip Volumes
	virtual uint8 AddClipVolume(const IClipVolume *pClipVolume) = 0;
	virtual void  SetClipVolumeBlendInfo(const IClipVolume *pClipVolume, int blendInfoCount, IClipVolume **blendVolumes, Plane *blendPlanes) = 0;

	//////////////////////////////////////////////////////////////////////////
	// Fog Volumes
	virtual void AddFogVolume(const class CREFogVolume *pFogVolume) = 0;

	virtual void EnableLookingGlass(bool) = 0;
};

struct ISyncMainWithRenderListener // Id=8001A45 Size=8
{
	virtual void SyncMainWithRender() = 0;
	virtual ~ISyncMainWithRenderListener() {};
};

struct IRenderer {
public:
	struct SLoadShaderItemArgs // Id=8001A36 Size=16
	{
		IMaterial* m_pMtlSrc;
		IMaterial* m_pMtlSrcParent;
	};

	struct SUpdateRect // Id=8001A46 Size=24
	{
		unsigned dstX;
		unsigned dstY;
		unsigned srcX;
		unsigned srcY;
		unsigned width;
		unsigned height;
	};

	enum class ESFMaskOp
	{
		BeginSubmitMask_Clear = 0,
		BeginSubmitMask_Inc = 1,
		BeginSubmitMask_Dec = 2,
		EndSubmitMask = 3,
		DisableMask = 4,
	};

	struct SRenderTimes // Id=8001A5D Size=28
	{
		float fWaitForMain;
		float fWaitForRender;
		float fWaitForGPU;
		float fTimeProcessedRT;
		float fTimeProcessedRTScene;
		float fTimeProcessedGPU;
		float fTimeGPUIdlePercent;
	};

	virtual ~IRenderer();
	virtual void AddListener(IRendererEventListener* arg0) = 0;
	virtual void RemoveListener(IRendererEventListener* arg0) = 0;
	virtual ERenderType GetRenderType() const = 0;
	virtual void* Init(int arg0, int arg1, int arg2, int arg3, unsigned arg4, int arg5, int arg6, EFullscreenMode arg7, void* arg8, void* arg9, bool arg10, SCustomRenderInitArgs const* arg11, bool arg12) = 0;
	virtual void PostInit() = 0;
	virtual bool CreateDeviceMemoryHeap(EDeviceMemoryHeap arg0, EDeviceMemoryType arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4) = 0;
	virtual void StartRenderIntroMovies(bool arg0) = 0;
	virtual void StopRenderIntroMovies(bool arg0) = 0;
	virtual bool IsRenderingIntroMovies() const = 0;
	virtual void ExecuteAsyncDIP() = 0;
	virtual int GetFeatures() = 0;
	virtual void GetVideoMemoryUsageStats(uint64_t& arg0, uint64_t& arg1, bool arg2) = 0;
	virtual int GetNumGeomInstances() = 0;
	virtual int GetNumGeomInstanceDrawCalls() = 0;
	virtual int GetCurrentNumberOfDrawCalls() = 0;
	virtual void GetCurrentNumberOfDrawCalls(int& arg0, int& arg1) = 0;
	virtual int GetCurrentNumberOfDrawCalls(const unsigned arg0) = 0;
	virtual float GetCurrentDrawCallRTTimes(const unsigned arg0) = 0;
	virtual bool DeleteContext(void* arg0) = 0;
	virtual bool CreateContext(void* arg0, bool arg1, int arg2, int arg3, bool arg4) = 0;
	virtual bool SetCurrentContext(void* arg0) = 0;
	virtual void MakeMainContextActive() = 0;
	virtual bool IsMainContextActive() = 0;
	virtual void* GetMainContextHWND() = 0;
	virtual void* GetCurrentContextHWND() = 0;
	virtual bool IsCurrentContextMainVP() = 0;
	virtual int GetCurrentContextViewportHeight() const = 0;
	virtual int GetCurrentContextViewportWidth() const = 0;
	virtual void SuspendDevice() = 0;
	virtual void ResumeDevice() = 0;
	virtual void ShutDown(bool arg0) = 0;
	virtual void ShutDownFast() = 0;
	virtual IArkVideoInfo& GetIArkVideoInfo() = 0;
	virtual bool ChangeResolution(int arg0, int arg1, int arg2, int arg3, EFullscreenMode arg4, bool arg5) = 0;
	virtual void BeginFrame(bool arg0) = 0;
	virtual void InitSystemResources(int arg0) = 0;
	virtual void FreeResources(int arg0) = 0;
	virtual void Release() = 0;
	virtual void RenderDebug(bool arg0) = 0;
	virtual void EndFrame() = 0;
	virtual void TryFlush() = 0;
	virtual void GetViewport(int* x, int* y, int* width, int* height) = 0;
	virtual void SetViewport(int x, int y, int width, int height, int id = 0) = 0;
	virtual void SetRenderTile(float arg0, float arg1, float arg2, float arg3) = 0;
	virtual void SetScissor(int arg0, int arg1, int arg2, int arg3) = 0;
	virtual EScreenAspectRatio GetScreenAspect(int arg0, int arg1) = 0;
	virtual Vec2 SetViewportDownscale(float arg0, float arg1) = 0;
	virtual void DrawDynVB(SVF_P3F_C4B_T2F* arg0, uint16_t* arg1, int arg2, int arg3, PublicRenderPrimitiveType arg4) = 0;
	virtual void SetCamera(CCamera const& arg0) = 0;
	virtual CCamera const& GetCamera() = 0;
	virtual CRenderView* GetRenderViewForThread(int arg0, bool arg1) = 0;
	virtual bool SetGammaDelta(const float arg0) = 0;
	virtual void RestoreGamma() = 0;
	virtual bool ChangeDisplay(unsigned arg0, unsigned arg1, unsigned arg2) = 0;
	virtual void ChangeViewport(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4) = 0;
	virtual bool SaveTga(uint8_t* arg0, int arg1, int arg2, int arg3, const char* arg4, bool arg5) const = 0;
	virtual int GetWhiteTextureId() const = 0;
	virtual void Draw2dImage(float arg0, float arg1, float arg2, float arg3, int arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11, float arg12, float arg13, float arg14) = 0;
	virtual void Draw2dImageStretchMode(bool arg0) = 0;
	virtual void Push2dImage(float arg0, float arg1, float arg2, float arg3, int arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11, float arg12, float arg13, float arg14) = 0;
	virtual void Draw2dImageList() = 0;
	virtual void DrawImage(float arg0, float arg1, float arg2, float arg3, int arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11, float arg12, bool arg13) = 0;
	virtual void DrawImageWithUV(float arg0, float arg1, float arg2, float arg3, float arg4, int arg5, float* arg6, float* arg7, float arg8, float arg9, float arg10, float arg11, bool arg12) = 0;
	virtual void PushWireframeMode(int arg0) = 0;
	virtual void PopWireframeMode() = 0;
	virtual int GetHeight() = 0;
	virtual int GetWidth() = 0;
	virtual float GetPixelAspectRatio() const = 0;
	virtual int GetOverlayHeight() = 0;
	virtual int GetOverlayWidth() = 0;
	virtual void SwitchToNativeResolutionBackbuffer() = 0;
	virtual void GetMemoryUsage(ICrySizer* arg0) = 0;
	virtual void GetBandwidthStats(float* arg0) = 0;
	virtual void SetTextureStreamListener(ITextureStreamListener* arg0) = 0;
	virtual int GetOcclusionBuffer(float* arg0, int arg1, int arg2, Matrix44* arg3) = 0;
	virtual bool ScreenShot(const char* arg0, int arg1, EScreenShotMode arg2) = 0;
	virtual int GetStencilBpp() = 0;
	virtual float GetNearestRangeMax() const = 0;
	virtual bool ProjectToScreen(float arg0, float arg1, float arg2, float* arg3, float* arg4, float* arg5) = 0;
	virtual int UnProjectFromScreen(float arg0, float arg1, float arg2, float* arg3, float* arg4, float* arg5) = 0;
	virtual void GetModelViewMatrix(float* arg0) = 0;
	virtual void GetProjectionMatrix(float* arg0) = 0;
	virtual void GetCameraZeroMatrix(float* arg0) = 0;
	virtual bool FontUploadTexture(CFBitmap* arg0, ETEX_Format arg1) = 0;
	virtual int FontCreateTexture(int arg0, int arg1, uint8_t* arg2, ETEX_Format arg3, bool arg4) = 0;
	virtual bool FontUpdateTexture(int arg0, int arg1, int arg2, int arg3, int arg4, uint8_t* arg5) = 0;
	virtual void FontReleaseTexture(CFBitmap* arg0) = 0;
	virtual void FontSetTexture(CFBitmap* arg0, int arg1) = 0;
	virtual void FontSetTexture(int arg0, int arg1) = 0;
	virtual void FontSetRenderingState(unsigned arg0, unsigned arg1) = 0;
	virtual void FontSetBlending(int arg0, int arg1) = 0;
	virtual void FontRestoreRenderingState() = 0;
	virtual bool FlushRTCommands(bool arg0, bool arg1, bool arg2) = 0;
	virtual void DrawStringW(IFFont_RenderProxy* arg0, float arg1, float arg2, float arg3, const wchar_t* arg4, const bool arg5, STextDrawContext const& arg6) const = 0;
	virtual int RT_CurThreadList() = 0;
	virtual void RT_FlashRender(IFlashPlayer_RenderProxy* arg0) = 0;
	virtual void RT_FlashRenderPlaybackLockless(IFlashPlayer_RenderProxy* arg0, int arg1, bool arg2) = 0;
	virtual void RT_FlashRemoveTexture(ITexture* arg0) = 0;
	virtual bool EF_PrecacheResource(SShaderItem* arg0, float arg1, float arg2, int arg3, int arg4, int arg5) = 0;
	virtual bool EF_PrecacheResource(IShader* arg0, float arg1, float arg2, int arg3) = 0;
	virtual bool EF_PrecacheResource(ITexture* arg0, float arg1, float arg2, int arg3, int arg4, int arg5) = 0;
	virtual bool EF_PrecacheResource(IRenderMesh* arg0, IMaterial* arg1, float arg2, float arg3, int arg4, int arg5) = 0;
	virtual bool EF_PrecacheResource(CDLight* arg0, float arg1, float arg2, int arg3, int arg4) = 0;
	virtual void PrecacheTick() = 0;
	virtual void PostLevelLoading() = 0;
	virtual void PostLevelUnload() = 0;
	virtual void EF_AddMultipleParticlesToScene(SAddParticlesToSceneJob const* arg0, uint64_t arg1, SRenderingPassInfo const& arg2) = 0;
	virtual void GetMemoryUsageParticleREs(ICrySizer* pSizer);
	virtual CRenderObject* EF_AddPolygonToScene(SShaderItem& arg0, int arg1, SVF_P3F_C4B_T2F const* arg2, SPipTangents const* arg3, CRenderObject* arg4, SRenderingPassInfo const& arg5, uint16_t* arg6, int arg7, int arg8) = 0;
	virtual CRenderObject* EF_AddPolygonToScene(SShaderItem& arg0, CRenderObject* arg1, SRenderingPassInfo const& arg2, int arg3, int arg4, SVF_P3F_C4B_T2F*& arg5, SPipTangents*& arg6, uint16_t*& arg7, int arg8) = 0;
	virtual void EF_SetShaderMissCallback(void (*arg0)(const char*)) = 0;
	virtual const char* EF_GetShaderMissLogPath() = 0;
	virtual string* EF_GetShaderNames(int& arg0) = 0;
	virtual bool EF_ReloadFile(const char* arg0) = 0;
	virtual bool EF_ReloadFile_Request(const char* arg0) = 0;
	virtual _smart_ptr<IImageFile> EF_LoadImage(const char* arg0, unsigned arg1) = 0;
	virtual uint64_t EF_GetRemapedShaderMaskGen(const char* arg0, uint64_t arg1, bool arg2) = 0;
	virtual uint64_t EF_GetShaderGlobalMaskGenFromString(const char* arg0, const char* arg1, uint64_t arg2) = 0;
	virtual const char* EF_GetStringFromShaderGlobalMaskGen(const char* arg0, uint64_t arg1) = 0;
	virtual SShaderProfile const& GetShaderProfile(EShaderType arg0) const = 0;
	virtual void EF_SetShaderQuality(EShaderType arg0, EShaderQuality arg1) = 0;
	virtual ERenderQuality EF_GetRenderQuality() const = 0;
	virtual EShaderQuality EF_GetShaderQuality(EShaderType arg0) = 0;
	virtual SShaderItem EF_LoadShaderItem(const char* arg0, bool arg1, int arg2, SInputShaderResources* arg3, uint64_t arg4, IRenderer::SLoadShaderItemArgs const* arg5) = 0;
	virtual IShader* EF_LoadShader(const char* arg0, int arg1, uint64_t arg2) = 0;
	virtual void EF_ReloadTextures() = 0;
	virtual ITexture* EF_GetTextureByID(int arg0) = 0;
	virtual ITexture* EF_GetTextureByName(const char* arg0, unsigned arg1) = 0;
	virtual ITexture* EF_LoadTexture(const char* arg0, const unsigned arg1) = 0;
	virtual unsigned EF_CacheTextureAsync(const char* arg0, unsigned arg1, EDeviceMemoryHeap arg2) = 0;
	virtual void EF_ReleaseCacheTexture(unsigned arg0) = 0;
	virtual ITexture* EF_TryGetCacheTexture(unsigned arg0) = 0;
	virtual IDynTextureSource* EF_LoadDynTexture(const char* arg0, bool arg1) = 0;
	virtual CRendElementBase* EF_CreateRE(EDataType arg0) = 0;
	virtual void EF_StartEf(SRenderingPassInfo const& arg0) = 0;
	virtual CRenderObject* EF_GetObject_Temp(int arg0) = 0;
	virtual CRenderObject* EF_GetObject() = 0;
	virtual void EF_FreeObject(CRenderObject* arg0) = 0;
	virtual CRenderObject* EF_DuplicateRO(CRenderObject* arg0, SRenderingPassInfo const& arg1) = 0;
	virtual void EF_AddEf(CRendElementBase* arg0, SShaderItem& arg1, CRenderObject* arg2, SRenderingPassInfo const& arg3, int arg4, int arg5) = 0;
	virtual void EF_EndEf3D(const int arg0, const int arg1, const int arg2, SRenderingPassInfo const& arg3) = 0;
	virtual void EF_InvokeShadowMapRenderJobs(CRenderView* arg0, const int arg1) = 0;
	virtual bool EF_IsFakeDLight(CDLight const* arg0) = 0;
	virtual void EF_ADDDlight(CDLight* arg0, SRenderingPassInfo const& arg1) = 0;
	virtual ColorF EF_GetLightAnimColor(uint8_t arg0, uint8_t arg1, float arg2) = 0;
	virtual bool EF_UpdateDLight(SRenderLight* arg0) = 0;
	virtual bool EF_AddDeferredDecal(SDeferredDecal const& rDecal, SRenderingPassInfo const& passInfo);
	virtual int EF_AddDeferredLight(CDLight const& arg0, float arg1, SRenderingPassInfo const& arg2, SRendParams const& arg3) = 0;
	virtual void EF_ReleaseDeferredData() = 0;
	virtual SInputShaderResources* EF_CreateInputShaderResource(IRenderShaderResources* arg0) = 0;
	virtual uint64_t EF_PostEffectParamHandleFromName(const char* arg0) const = 0;
	virtual void EF_SetPostEffectParam(SSetPostEffectParam const& arg0) const = 0;
	virtual void EF_SetPostEffectParam(SSetPostEffectParamVec4 const& arg0) const = 0;
	virtual void EF_SetPostEffectParam(SSetPostEffectParamString const& arg0) const = 0;
	virtual float EF_GetPostEffectParam(uint64_t arg0) const = 0;
	virtual Vec4 EF_GetPostEffectParamVec4(uint64_t arg0) const = 0;
	virtual const char* EF_GetPostEffectParamString(uint64_t arg0) const = 0;
	virtual bool EF_IsPostEffectParam(const char* arg0) const = 0;
	virtual void EF_ResetPostEffects(bool arg0) = 0;
	virtual void EF_DisableTemporalEffects() = 0;
	virtual void EF_AddWaterSimHit(Vec3 const& arg0, const float arg1, const float arg2) = 0;
	virtual void EF_DrawWaterSimHits() = 0;
	virtual void ForceGC() = 0;
	virtual int GetPolyCount() = 0;
	virtual void GetPolyCount(int& arg0, int& arg1) = 0;
	virtual void SetClearColor(Vec3 const& arg0) = 0;
	//virtual _smart_ptr<IRenderMesh> CreateRenderMesh(const char* arg0, const char* arg1, IRenderMesh::SInitParamerers* arg2, ERenderMeshType arg3) = 0;
	//virtual _smart_ptr<IRenderMesh> CreateRenderMeshInitialized(const void* arg0, int arg1, EVertexFormat arg2, const uint16_t* arg3, int arg4, PublicRenderPrimitiveType arg5, const char* arg6, const char* arg7, ERenderMeshType arg8, int arg9, int arg10, bool (*arg11)(IRenderMesh*, bool), void* arg12, bool arg13, bool arg14, SPipTangents const* arg15, bool arg16, Vec3* arg17) = 0;
	virtual void* CreateRenderMesh_Unfinished();
	virtual void* CreateRenderMeshInitialized_Unfinished();
	virtual int GetFrameID(bool bIncludeRecursiveCalls = true) = 0;
	virtual void MakeMatrix(Vec3 const& arg0, Vec3 const& arg1, Vec3 const& arg2, Matrix34* arg3) = 0;
	virtual void Draw2dText(float arg0, float arg1, const char* arg2, SDrawTextInfo const& arg3) = 0;
	virtual void DrawTextQueued(Vec3 arg0, SDrawTextInfo& arg1, const char* arg2, char* arg3) = 0;
	virtual void DrawTextQueued(Vec3 arg0, SDrawTextInfo& arg1, const char* arg2) = 0;
	virtual void Draw2dTextWithDepth(float arg0, float arg1, float arg2, const char* arg3, SDrawTextInfo const& arg4) = 0;
	virtual float ScaleCoordX(float arg0) const = 0;
	virtual float ScaleCoordY(float arg0) const = 0;
	virtual void ScaleCoord(float& arg0, float& arg1) const = 0;
	virtual void SetState(int State, int AlphaRef = -1) = 0;
	virtual void SetCullMode(int arg0) = 0;
	virtual void PushProfileMarker(char* arg0) = 0;
	virtual void PopProfileMarker(char* arg0) = 0;
	virtual bool EnableFog(bool arg0) = 0;
	virtual void SetFogColor(ColorF const& arg0) = 0;
	virtual void SetColorOp(uint8_t arg0, uint8_t arg1, uint8_t arg2, uint8_t arg3) = 0;
	virtual void RequestFlushAllPendingTextureStreamingJobs(int nFrames);
	virtual void SetTexturesStreamingGlobalMipFactor(float fFactor);
	virtual IRenderAuxGeom* GetIRenderAuxGeom(void* arg0) = 0;
	virtual IArkRenderPersistentAuxGeom* GetIArkRenderPersistentAuxGeom() = 0;
	virtual IColorGradingController* GetIColorGradingController() = 0;
	virtual void TextToScreen(float arg0, float arg1, const char* arg2, ...) = 0;
	virtual void TextToScreenColor(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5, const char* arg6, ...) = 0;
	virtual void ResetToDefault() = 0;
	virtual void SetMaterialColor(float arg0, float arg1, float arg2, float arg3) = 0;
	virtual void Graph(uint8_t* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, char* arg7, ColorF& arg8, float arg9) = 0;
	virtual void FlushTextMessages() = 0;
	virtual void ClearTargetsImmediately(unsigned arg0) = 0;
	virtual void ClearTargetsImmediately(unsigned arg0, ColorF const& arg1, float arg2) = 0;
	virtual void ClearTargetsImmediately(unsigned arg0, ColorF const& arg1) = 0;
	virtual void ClearTargetsImmediately(unsigned arg0, float arg1) = 0;
	virtual void ClearTargetsLater(unsigned arg0) = 0;
	virtual void ClearTargetsLater(unsigned arg0, ColorF const& arg1, float arg2) = 0;
	virtual void ClearTargetsLater(unsigned arg0, ColorF const& arg1) = 0;
	virtual void ClearTargetsLater(unsigned arg0, float arg1) = 0;
	virtual void CreateResourceAsync(SResourceAsync* arg0) = 0;
	virtual void ReleaseResourceAsync(SResourceAsync* arg0) = 0;
	virtual unsigned DownLoadToVideoMemory(uint8_t* arg0, int arg1, int arg2, ETEX_Format arg3, ETEX_Format arg4, int arg5, bool arg6, int arg7, int arg8, const char* arg9, int arg10, bool arg11, RectI* arg12, bool arg13) = 0;
	virtual void UpdateTextureInVideoMemory(unsigned arg0, uint8_t* arg1, int arg2, int arg3, int arg4, int arg5, ETEX_Format arg6, int arg7, int arg8) = 0;
	virtual void RemoveTexture(unsigned arg0) = 0;
	virtual gpu_pfx2::IManager* GetGpuParticleManager() = 0;
	virtual void RegisterSyncWithMainListener(ISyncMainWithRenderListener* arg0) = 0;
	virtual void RemoveSyncWithMainListener(ISyncMainWithRenderListener const* arg0) = 0;
	virtual void Set2DMode(bool arg0, int arg1, int arg2, float arg3, float arg4) = 0;
	virtual int ScreenToTexture(int arg0) = 0;
	virtual bool StopRendererAtFrameEnd(unsigned arg0) = 0;
	virtual void ResumeRendererFromFrameEnd() = 0;
	virtual void* GetHWND() = 0;
	virtual void OnEntityDeleted(IRenderNode* arg0) = 0;
	virtual int CreateRenderTarget(int arg0, int arg1, ColorF const& arg2, ETEX_Format arg3) = 0;
	virtual bool DestroyRenderTarget(int arg0) = 0;
	virtual bool SetRenderTarget(int arg0) = 0;
	virtual IOpticsElementBase* CreateOptics(EFlareType arg0) const = 0;
	virtual ISoftOcclusionQuery* CreateSoftOcclusionQuery() const = 0;
	virtual void GetThreadIDs(unsigned long& arg0, unsigned long& arg1) const = 0;
	virtual bool SF_UpdateTexture(int arg0, int arg1, int arg2, IRenderer::SUpdateRect const* arg3, uint8_t* arg4, uint64_t arg5, uint64_t arg6, ETEX_Format arg7) = 0;
	virtual void SF_GetMeshMaxSize(int& arg0, int& arg1) const = 0;
	virtual void SF_ConfigMask(IRenderer::ESFMaskOp arg0, unsigned arg1) = 0;
	virtual void SF_DrawIndexedTriList(int arg0, int arg1, int arg2, int arg3, int arg4, SSF_GlobalDrawParams const& arg5) = 0;
	virtual void SF_DrawLineStrip(int arg0, int arg1, SSF_GlobalDrawParams const& arg2) = 0;
	virtual void SF_DrawGlyphClear(SSF_GlobalDrawParams const& arg0) = 0;
	virtual void SF_DrawBlurRect(SSF_GlobalDrawParams const& arg0) = 0;
	virtual void SF_Flush() = 0;
	virtual int SF_CreateTexture(int arg0, int arg1, int arg2, uint8_t* arg3, ETEX_Format arg4, int arg5) = 0;
	virtual ITexture* CreateTexture(const char* arg0, int arg1, int arg2, int arg3, uint8_t* arg4, ETEX_Format arg5, int arg6) = 0;
	virtual RPProfilerStats const* GetRPPStats(ERenderPipelineProfilerStats arg0, bool arg1) = 0;
	virtual RPProfilerStats const* GetRPPStatsArray(bool arg0) = 0;
	virtual int GetPolygonCountByType(unsigned arg0, EVertexCostTypes arg1, unsigned arg2, bool arg3) = 0;
	virtual void StartLoadtimeFlashPlayback(ILoadtimeCallback* arg0) = 0;
	virtual void StopLoadtimeFlashPlayback() = 0;
	virtual void StartLoadtimeBinkPlayback(ILoadtimeCallback* arg0) = 0;
	virtual void StopLoadtimeBinkPlayback() = 0;
	virtual uint16_t PushFogVolumeContribution(ColorF const& arg0, SRenderingPassInfo const& arg1) = 0;
	virtual int GetMaxTextureSize() = 0;
	virtual const char* GetTextureFormatName(ETEX_Format arg0) = 0;
	virtual int GetTextureFormatDataSize(int arg0, int arg1, int arg2, int arg3, ETEX_Format arg4) = 0;
	virtual void SetDefaultMaterials(IMaterial* arg0, IMaterial* arg1) = 0;
	virtual unsigned GetActiveGPUCount() const = 0;
	virtual ShadowFrustumMGPUCache* GetShadowFrustumMGPUCache() = 0;
	virtual StaticArray<int, 16, int> const& GetCachedShadowsResolution() const = 0;
	virtual void SetCachedShadowsResolution(StaticArray<int, 16, int> const& arg0) = 0;
	virtual void UpdateCachedShadowsLodCount(int arg0) const = 0;
	virtual void SetTexturePrecaching(bool arg0) = 0;
	virtual void EnablePipelineProfiler(bool arg0) = 0;
	virtual void GetRenderTimes(IRenderer::SRenderTimes& arg0) = 0;
	virtual float GetGPUFrameTime() = 0;
	virtual void EnableBatchMode(bool arg0) = 0;
	virtual SSkinningData* EF_CreateSkinningData(unsigned arg0, bool arg1) = 0;
	virtual SSkinningData* EF_CreateRemappedSkinningData(unsigned arg0, SSkinningData* arg1, unsigned arg2, unsigned arg3) = 0;
	virtual int EF_GetSkinningPoolID() = 0;
	virtual void UpdateShaderItem(SShaderItem* arg0, IMaterial* arg1) = 0;
	virtual void ForceUpdateShaderItem(SShaderItem* arg0, IMaterial* arg1) = 0;
	virtual void RefreshShaderResourceConstants(SShaderItem* arg0, IMaterial* arg1) = 0;
	virtual void SyncComputeVerticesJobs() = 0;
	virtual void ActivateLayer(const char* arg0, bool arg1) = 0;
	virtual void FlushPendingTextureTasks() = 0;
	virtual void SetShadowJittering(float arg0) = 0;
	virtual float GetShadowJittering() const = 0;
	virtual bool LoadShaderStartupCache() = 0;
	virtual void UnloadShaderStartupCache() = 0;
	virtual bool LoadShaderLevelCache() = 0;
	virtual void UnloadShaderLevelCache() = 0;
	virtual void SetRendererCVar(ICVar* arg0, const char* arg1, const bool arg2) = 0;
	virtual _smart_ptr<IGraphicsDeviceConstantBuffer> CreateGraphiceDeviceConstantBuffer() = 0;
	virtual void EF_QueryImpl(ERenderQueryTypes arg0, void* arg1, unsigned arg2, void* arg3, unsigned arg4) = 0;
	virtual void PeekWindowMessage(unsigned message, uint64_t wParam, uint64_t lParam);
	virtual IArkBinkManager* GetIArkBinkManager() = 0;

	//! Returns various Renderer Settings, see ERenderQueryTypes.
	//! \param Query e.g. EFQ_GetShaderCombinations.
	//! \param rInOut Input/Output Parameter, depends on the query if written to/read from, or both.
	void EF_Query(ERenderQueryTypes eQuery) {
		EF_QueryImpl(eQuery, NULL, 0, NULL, 0);
	}
	template<typename T>
	void EF_Query(ERenderQueryTypes eQuery, T &rInOut) {
		EF_QueryImpl(eQuery, static_cast<void *>(&rInOut), sizeof(T), NULL, 0);
	}
	template<typename T0, typename T1>
	void EF_Query(ERenderQueryTypes eQuery, T0 &rInOut0, T1 &rInOut1) {
		EF_QueryImpl(eQuery, static_cast<void *>(&rInOut0), sizeof(T0), static_cast<void *>(&rInOut1), sizeof(T1));
	}
};