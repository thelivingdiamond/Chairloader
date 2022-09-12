// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

/*=============================================================================
   ShaderComponents.h : FX Shaders semantic components declarations.

   Revision history:
* Created by Honich Andrey

   =============================================================================*/

#ifndef __SHADERCOMPONENTS_H__
#define __SHADERCOMPONENTS_H__

#include "../Defs.h"

#if CRY_PLATFORM_ORBIS
	#undef PF_LOCAL // Defined in socket library
#endif

#if defined(PF_LOCAL) && !(PF_LOCAL == 1)
// e.g.: In Mac OS X it is defined in a system header
	#error "PF_LOCAL defined somewhere else with a different value"
#elif !defined(PF_LOCAL)
	#define PF_LOCAL            1
#endif
#define PF_SINGLE_COMP        2
#define PF_DONTALLOW_DYNMERGE 4
#define PF_INTEGER            8
#define PF_BOOL               0x10
#define PF_POSITION           0x20
#define PF_MATRIX             0x40
#define PF_SCALAR             0x80
#define PF_TWEAKABLE_0        0x100
#define PF_TWEAKABLE_1        0x200
#define PF_TWEAKABLE_2        0x400
#define PF_TWEAKABLE_3        0x800
#define PF_TWEAKABLE_MASK     0xf00
#define PF_MERGE_MASK         0xff000
#define PF_MERGE_SHIFT        12
#define PF_INSTANCE           0x100000
#define PF_MATERIAL           0x200000
#define PF_LIGHT              0x400000
#define PF_SHADOWGEN          0x800000
#define PF_CUSTOM_BINDED      0x1000000
#define PF_CANMERGED          0x2000000
#define PF_AUTOMERGED         0x4000000
#define PF_ALWAYS             0x8000000
#define PF_GLOBAL             0x10000000

enum ECGParam
{
	ECGP_Unknown = 0,
	ECGP_Matr_SI_Obj = 1,
	ECGP_SI_AmbientOpacity = 2,
	ECGP_SI_ObjectAmbColComp = 3,
	ECGP_PI_AlphaTest = 4,
	ECGP_SI_BendInfo = 5,
	ECGP_SI_SceneSelection = 6,
	ECGP_Matr_PI_Obj_T = 7,
	ECGP_PI_MotionBlurData = 8,
	ECGP_Matr_PI_ViewProj = 9,
	ECGP_Matr_PI_Composite = 10,
	ECGP_Matr_PI_ObjOrigComposite = 11,
	ECGP_PI_OSCameraPos = 12,
	ECGP_PI_Ambient = 13,
	ECGP_PI_VisionParams = 14,
	ECGP_PB_VisionMtlParams = 15,
	ECGP_PI_AvgFogVolumeContrib = 16,
	ECGP_PI_NumInstructions = 17,
	ECGP_PI_TextureTileSize = 18,
	ECGP_PI_ParticleParams = 19,
	ECGP_PI_ParticleLightParams = 20,
	ECGP_PI_ParticleSoftParams = 21,
	ECGP_PI_ParticleAlphaTest = 22,
	ECGP_PI_GeomParticleParams = 23,
	ECGP_PB_Scalar = 24,
	ECGP_PM_Tweakable = 25,
	ECGP_Matr_PB_UnProjMatrix = 26,
	ECGP_Matr_PB_Temp4_0 = 27,
	ECGP_Matr_PB_Temp4_1 = 28,
	ECGP_Matr_PB_Temp4_2 = 29,
	ECGP_Matr_PB_Temp4_3 = 30,
	ECGP_Matr_PB_TerrainLayerGen = 31,
	ECGP_PM_MatChannelSB = 32,
	ECGP_PM_MatDiffuseColor = 33,
	ECGP_PM_MatSpecularColor = 34,
	ECGP_PM_MatEmissiveColor = 35,
	ECGP_PM_MatDeformWave = 36,
	ECGP_PM_MatDetailTilingAndAlphaRef = 37,
	ECGP_PM_MatSilPomDetailParams = 38,
	ECGP_PM_MatDiffuseTCM = 39,
	ECGP_PM_MatEmissiveTCM = 40,
	ECGP_PM_DiffuseNormalsDims = 41,
	ECGP_PB_RotGridScreenOff = 42,
	ECGP_PB_BlendTerrainColInfo = 43,
	ECGP_PB_HDRParams = 44,
	ECGP_PB_TFactor = 45,
	ECGP_PB_TempData = 46,
	ECGP_PB_VolumetricFogGlobalEnvProbe0 = 47,
	ECGP_PB_VolumetricFogGlobalEnvProbe1 = 48,
	ECGP_PB_RTRect = 49,
	ECGP_PB_FromRE = 50,
	ECGP_PB_ObjVal = 51,
	ECGP_PB_WaterLevel = 52,
	ECGP_PB_HDRDynamicMultiplier = 53,
	ECGP_PB_CausticsParams = 54,
	ECGP_PB_CausticsSmoothSunDirection = 55,
	ECGP_PB_SunDirection = 56,
	ECGP_PB_SunColor = 57,
	ECGP_PB_PullVerticesInfo = 58,
	ECGP_Matr_PB_SFCompMat = 59,
	ECGP_Matr_PB_SFTexGenMat0 = 60,
	ECGP_Matr_PB_SFTexGenMat1 = 61,
	ECGP_PB_SFBitmapColorTransform = 62,
	ECGP_PB_SFColorTransformMatrix = 63,
	ECGP_PB_SFPremultipliedAlpha = 64,
	ECGP_PB_SFBlurFilterSize = 65,
	ECGP_PB_SFBlurFilterScale = 66,
	ECGP_PB_SFBlurFilterOffset = 67,
	ECGP_PB_SFBlurFilterColor1 = 68,
	ECGP_PB_SFBlurFilterColor2 = 69,
	ECGP_PB_ClipVolumeParams = 70,
	ECGP_PB_TexelDensityParam = 71,
	ECGP_PB_TexelDensityColor = 72,
	ECGP_PB_TexelsPerMeterInfo = 73,
	ECGP_PB_DebugRenderModeColor = 74,
	ECGP_PB_WaterRipplesLookupParams = 75,
	ECGP_PB_MorphParams = 76,
	ECGP_COUNT = 77,
};

// Per frame - harcoded - commonly used data
struct SCGParamsPF
{
public:
	int nFrameID;
	Matrix44 pProjMatrix;
	Matrix44 pUnProjMatrix;
	Matrix44 pMatrixComposite;
	Matrix44 pViewProjZeroMatrix;
	float fHDRDynamicMultiplier;
	Vec4 pFogColGradColBase;
	Vec4 pFogColGradColDelta;
	Vec4 pFogColGradParams;
	Vec4 pFogColGradRadial;
	Vec4 pVolumetricFogParams;
	Vec4 pVolumetricFogRampParams;
	Vec4 pVolumetricFogSunDir;
	Vec3 pCameraFront;
	Vec3 pCameraRight;
	Vec3 pCameraUp;
	Vec3 pCameraPos;
	Vec4 pScreenSize;
	Vec4 pNearFarDist;
	Vec3 pDecalZFightingRemedy;
	Vec4 pLightningColSize;
	Vec3 pLightningPos;
	Vec3 pCausticsParams;
	Vec3 pSunColor;
	Vec3 pSkyColor;
	Vec3 pSunDirection;
	Vec3 pCloudShadingColorSun;
	Vec3 pCloudShadingColorSky;
	Vec3 vCausticsCurrSunDir;
	int nCausticsFrameID;
	Vec3 pVolCloudTilingSize;
	Vec3 pVolCloudTilingOffset;
	Vec4 pVolumetricFogSamplingParams;
	Vec4 pVolumetricFogDistributionParams;
	Vec4 pVolumetricFogScatteringParams;
	Vec4 pVolumetricFogScatteringBlendParams;
	Vec4 pVolumetricFogScatteringColor;
	Vec4 pVolumetricFogScatteringSecondaryColor;
	Vec4 pVolumetricFogHeightDensityParams;
	Vec4 pVolumetricFogHeightDensityRampParams;
	Vec4 pVolumetricFogDistanceParams;
	float irregularFilterKernel[8][4];
	float fArkGlintTimeBetween;
	float fArkGlintDuration;
	float fArkGlintIntensity;
	float fArkGlintSpeed;
};

enum EOperation
{
	eOp_Unknown,
	eOp_Add,
	eOp_Sub,
	eOp_Div,
	eOp_Mul,
	eOp_Log,
};

struct SCGBind
{
	CCryNameR m_Name;
	uint32    m_Flags;
	short     m_dwBind;
	short     m_dwCBufSlot;
	int       m_nParameters;
	SCGBind()
	{
		m_nParameters = 1;
		m_dwBind = -2;
		m_dwCBufSlot = 0;
		m_Flags = 0;
	}
	SCGBind(const SCGBind& sb)
		: m_Name(sb.m_Name)
		, m_Flags(sb.m_Flags)
		, m_dwBind(sb.m_dwBind)
		, m_dwCBufSlot(sb.m_dwCBufSlot)
		, m_nParameters(sb.m_nParameters)
	{
	}
	SCGBind& operator=(const SCGBind& sb)
	{
		this->~SCGBind();
		new(this)SCGBind(sb);
		return *this;
	}
	int Size()
	{
		return sizeof(SCGBind);
	}
	void GetMemoryUsage(ICrySizer* pSizer) const {}
};

struct SParamData
{
	CCryNameR m_CompNames[4];
	union UData
	{
		uint64 nData64[4];
		uint32 nData32[4];
		float  fData[4];
	} d;
	SParamData()
	{
		memset(&d, 0, sizeof(UData));
	}
	~SParamData();
	SParamData(const SParamData& sp);
	SParamData& operator=(const SParamData& sp)
	{
		this->~SParamData();
		new(this)SParamData(sp);
		return *this;
	}
	unsigned Size() { return sizeof(SParamData); }
	void     GetMemoryUsage(ICrySizer* pSizer) const
	{
		pSizer->AddObject(this, sizeof(*this));
	}
};

struct SCGLiteral
{
	int      m_nIndex;
	//Vec4 m_vVec;
	unsigned Size()                                  { return sizeof(SCGLiteral); }
	void     GetMemoryUsage(ICrySizer* pSizer) const {}
};

struct SCGParam : SCGBind
{
	ECGParam    m_eCGParamType;
	SParamData* m_pData;
	UINT_PTR    m_nID;
	SCGParam()
	{
		m_eCGParamType = ECGP_Unknown;
		m_pData = NULL;
		m_nID = 0;
	}
	~SCGParam()
	{
		SAFE_DELETE(m_pData);
	}
	SCGParam(const SCGParam& sp) : SCGBind(sp)
	{
		m_eCGParamType = sp.m_eCGParamType;
		m_nID = sp.m_nID;
		if (sp.m_pData)
		{
			m_pData = new SParamData;
			*m_pData = *sp.m_pData;
		}
		else
			m_pData = NULL;
	}
	SCGParam& operator=(const SCGParam& sp)
	{
		this->~SCGParam();
		new(this)SCGParam(sp);
		return *this;
	}
	bool operator!=(const SCGParam& sp) const
	{
		if (sp.m_dwBind == m_dwBind &&
		    sp.m_Name == m_Name &&
		    sp.m_nID == m_nID &&
		    sp.m_nParameters == m_nParameters &&
		    sp.m_eCGParamType == m_eCGParamType &&
		    sp.m_dwCBufSlot == m_dwCBufSlot &&
		    sp.m_Flags == m_Flags &&
		    !sp.m_pData && !m_pData)
		{
			return false;
		}
		return true;
	}

	const CCryNameR GetParamCompName(int nComp) const
	{
		if (!m_pData)
			return CCryNameR("None");
		return m_pData->m_CompNames[nComp];
	}

	int Size()
	{
		int nSize = sizeof(SCGParam);
		if (m_pData)
			nSize += m_pData->Size();
		return nSize;
	}

	void GetMemoryUsage(ICrySizer* pSizer) const
	{
		pSizer->AddObject(m_pData);
	}
};

enum ECGSampler
{
	ECGS_Unknown = 0,
	ECGS_MatSlot_Diffuse = 1,
	ECGS_MatSlot_Normalmap = 2,
	ECGS_MatSlot_Gloss = 3,
	ECGS_MatSlot_Env = 4,
	ECGS_Shadow0 = 5,
	ECGS_Shadow1 = 6,
	ECGS_Shadow2 = 7,
	ECGS_Shadow3 = 8,
	ECGS_Shadow4 = 9,
	ECGS_Shadow5 = 10,
	ECGS_Shadow6 = 11,
	ECGS_Shadow7 = 12,
	ECGS_TrilinearClamp = 13,
	ECGS_TrilinearWrap = 14,
	ECGS_MatAnisoHighWrap = 15,
	ECGS_MatAnisoLowWrap = 16,
	ECGS_MatTrilinearWrap = 17,
	ECGS_MatBilinearWrap = 18,
	ECGS_MatTrilinearClamp = 19,
	ECGS_MatBilinearClamp = 20,
	ECGS_MatAnisoHighBorder = 21,
	ECGS_MatTrilinearBorder = 22,
	ECGS_PointWrap = 23,
	ECGS_PointClamp = 24,
	ECGS_COUNT = 25,
};

struct SCGSampler : SCGBind
{
	int        m_nStateHandle;
	ECGSampler m_eCGSamplerType;
	SCGSampler()
	{
		m_nStateHandle = -1;
		m_eCGSamplerType = ECGS_Unknown;
	}
	~SCGSampler()
	{
	}
	SCGSampler(const SCGSampler& sp) : SCGBind(sp)
	{
		m_eCGSamplerType = sp.m_eCGSamplerType;
		m_nStateHandle = sp.m_nStateHandle;
	}
	SCGSampler& operator=(const SCGSampler& sp)
	{
		this->~SCGSampler();
		new(this)SCGSampler(sp);
		return *this;
	}
	bool operator!=(const SCGSampler& sp) const
	{
		if (sp.m_dwBind == m_dwBind &&
		    sp.m_Name == m_Name &&
		    sp.m_nStateHandle == m_nStateHandle &&
		    sp.m_nParameters == m_nParameters &&
		    sp.m_eCGSamplerType == m_eCGSamplerType &&
		    sp.m_dwCBufSlot == m_dwCBufSlot &&
		    sp.m_Flags == m_Flags)
		{
			return false;
		}
		return true;
	}

	int Size()
	{
		int nSize = sizeof(SCGSampler);
		return nSize;
	}

	void GetMemoryUsage(ICrySizer* pSizer) const
	{
	}
};

enum ECGTexture : uint8
{
	ECGT_Unknown = 0,
	ECGT_MatSlot_Diffuse = 1,
	ECGT_MatSlot_Normals = 2,
	ECGT_MatSlot_Specular = 3,
	ECGT_MatSlot_Env = 4,
	ECGT_MatSlot_Detail = 5,
	ECGT_MatSlot_Smoothness = 6,
	ECGT_MatSlot_Height = 7,
	ECGT_MatSlot_DecalOverlay = 8,
	ECGT_MatSlot_SubSurface = 9,
	ECGT_MatSlot_Custom = 10,
	ECGT_MatSlot_CustomSecondary = 11,
	ECGT_MatSlot_Opacity = 12,
	ECGT_MatSlot_Translucency = 13,
	ECGT_MatSlot_Emittance = 14,
	ECGT_MatSlot_CustomTertiary = 15,
	ECGT_SF_Slot0 = 16,
	ECGT_SF_Slot1 = 17,
	ECGT_SF_SlotY = 18,
	ECGT_SF_SlotU = 19,
	ECGT_SF_SlotV = 20,
	ECGT_SF_SlotA = 21,
	ECGT_Shadow0 = 22,
	ECGT_Shadow1 = 23,
	ECGT_Shadow2 = 24,
	ECGT_Shadow3 = 25,
	ECGT_Shadow4 = 26,
	ECGT_Shadow5 = 27,
	ECGT_Shadow6 = 28,
	ECGT_Shadow7 = 29,
	ECGT_ShadowMask = 30,
	ECGT_HDR_Target = 31,
	ECGT_HDR_TargetPrev = 32,
	ECGT_HDR_AverageLuminance = 33,
	ECGT_HDR_FinalBloom = 34,
	ECGT_BackBuffer = 35,
	ECGT_BackBufferScaled_d2 = 36,
	ECGT_BackBufferScaled_d4 = 37,
	ECGT_BackBufferScaled_d8 = 38,
	ECGT_ZTarget = 39,
	ECGT_ZTargetMS = 40,
	ECGT_ZTargetScaled_d2 = 41,
	ECGT_ZTargetScaled_d4 = 42,
	ECGT_SceneTarget = 43,
	ECGT_SceneNormalsBent = 44,
	ECGT_SceneNormals = 45,
	ECGT_SceneDiffuse = 46,
	ECGT_SceneSpecular = 47,
	ECGT_SceneNormalsMS = 48,
	ECGT_VolumetricClipVolumeStencil = 49,
	ECGT_VolumetricFog = 50,
	ECGT_VolumetricFogGlobalEnvProbe0 = 51,
	ECGT_VolumetricFogGlobalEnvProbe1 = 52,
	ECGT_VolumetricFogShadow0 = 53,
	ECGT_VolumetricFogShadow1 = 54,
	ECGT_WaterRipplesDDN = 55,
	ECGT_WaterVolumeDDN = 56,
	ECGT_WaterVolumeCaustics = 57,
	ECGT_WaterVolumeRefl = 58,
	ECGT_WaterVolumeReflPrev = 59,
	ECGT_TerrainNormMap = 60,
	ECGT_TerrainBaseMap = 61,
	ECGT_SceneMask = 62,
	ECGT_SceneMaskDevice = 63,
	ECGT_FromRE0 = 64,
	ECGT_COUNT = 65,
};

struct SCGTexture : SCGBind
{
	CTexture*  m_pTexture;
	STexAnim*  m_pAnimInfo;
	ECGTexture m_eCGTextureType;
	bool       m_bSRGBLookup;
	bool       m_bGlobal;

	SCGTexture()
	{
		m_pTexture = nullptr;
		m_pAnimInfo = nullptr;
		m_eCGTextureType = ECGT_Unknown;
		m_bSRGBLookup = false;
		m_bGlobal = false;
	}
	~SCGTexture();
	SCGTexture(const SCGTexture& sp);
	SCGTexture& operator=(const SCGTexture& sp)
	{
		this->~SCGTexture();
		new(this)SCGTexture(sp);
		return *this;
	}
	bool operator!=(const SCGTexture& sp) const
	{
		if (sp.m_dwBind == m_dwBind &&
		    sp.m_Name == m_Name &&
		    sp.m_nParameters == m_nParameters &&
		    sp.m_dwCBufSlot == m_dwCBufSlot &&
		    sp.m_Flags == m_Flags &&
		    sp.m_pAnimInfo == m_pAnimInfo &&
		    sp.m_pTexture == m_pTexture &&
		    sp.m_eCGTextureType == m_eCGTextureType &&
		    sp.m_bSRGBLookup == m_bSRGBLookup &&
		    sp.m_bGlobal == m_bGlobal)
		{
			return false;
		}
		return true;
	}

	CTexture* GetTexture() const;

	int       Size()
	{
		int nSize = sizeof(SCGTexture);
		return nSize;
	}

	void GetMemoryUsage(ICrySizer* pSizer) const
	{
	}
};

#endif
