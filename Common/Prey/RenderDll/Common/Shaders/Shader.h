// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

/*=============================================================================
   Shader.h : Shaders declarations.

   Revision history:
* Created by Honich Andrey

   =============================================================================*/

#ifndef __SHADER_H__
#define __SHADER_H__

#include "../Defs.h"

#include <Prey/CryString/CryName.h>
#include <Prey/CryRenderer/IShader.h>
#include "../CryNameR.h"
#include "../CommonRender.h"
#include "ShaderResources.h"

// bump this value up if you want to invalidate shader cache (e.g. changed some code or .ext file)
// #### VIP NOTE ####: DON'T USE MORE THAN ONE DECIMAL PLACE!!!! else it doesn't work...
#define FX_CACHE_VER     4.6
#define FX_SER_CACHE_VER 1.0    // Shader serialization version (FX_CACHE_VER + FX_SER_CACHE_VER)

// Maximum 1 digit here
// The version determines the parse logic in the shader cache gen, these values cannot overlap
#define SHADER_LIST_VER      5
#define SHADER_SERIALISE_VER (SHADER_LIST_VER + 1)

//#define SHADER_NO_SOURCES 1 // If this defined all binary shaders (.fxb) should be located in Game folder (not user)

#define SHADERS_SERIALIZING 1 // Enables shaders serializing (Export/Import) to/from .fxb files

#define CB_PER_BATCH        0
#define CB_PER_INSTANCE     1
#define CB_PER_FRAME        2
#define CB_PER_MATERIAL     3
#define CB_PER_LIGHT        4
#define CB_PER_SHADOWGEN    5
#define CB_SKIN_DATA        6
#define CB_INSTANCE_DATA    7
#define CB_NUM              8

//====================================================================
// Fixed Per-Material constants
// Needs to match shader registers in FXConstantDefs

#define NUM_PM_CONSTANTS             (10 + EFTT_MAX * 2)
#define FIRST_REG_PM                 (0)

#define REG_PM_CHANNELS_SB           (0)                  // Scale-Bias for each texture slot
#define REG_PM_DIFFUSE_COL           (0 + EFTT_MAX * 2)
#define REG_PM_SPECULAR_COL          (1 + EFTT_MAX * 2)
#define REG_PM_EMISSIVE_COL          (2 + EFTT_MAX * 2)
#define REG_PM_TCM_MATRIX            (3 + EFTT_MAX * 2)
#define REG_PM_DEFORM_WAVE           (7 + EFTT_MAX * 2)
#define REG_PM_DETAILTILING_ALPHAREF (8 + EFTT_MAX * 2)
#define REG_PM_SILPOM_DETAIL_PARAMS  (9 + EFTT_MAX * 2)

// Shader.h
// Shader pipeline common declarations.

struct SShaderPass;
class CShader;
class CRendElementBase;
class CResFile;
struct SEnvTexture;
struct SParserFrame;
struct SPreprocessTree;
struct SEmptyCombination;
struct SShaderCombination;
struct SShaderCache;
struct SShaderDevCache;
struct SCGParam;
struct SSFXParam;
struct SSFXSampler;
struct SSFXTexture;

enum eCompareFunc
{
	eCF_Disable,
	eCF_Never,
	eCF_Less,
	eCF_Equal,
	eCF_LEqual,
	eCF_Greater,
	eCF_NotEqual,
	eCF_GEqual,
	eCF_Always
};

struct SPair
{
	string m_szMacroName;
	string m_szMacro;
	uint32 m_nMask;
};

#if CRY_PLATFORM_MOBILE
	#define GEOMETRYSHADER_SUPPORT false
#else
	#define GEOMETRYSHADER_SUPPORT true
#endif

struct SFXSampler
{
	CCryNameR           m_Name; // Parameter name
	std::vector<uint32> m_dwName;
	uint32              m_nFlags;
	short               m_nArray;      // Number of samplers
	CCryNameR           m_Annotations; // Additional parameters (between <>)
	CCryNameR           m_Semantic;    // Parameter semantic type (after ':')
	CCryNameR           m_Values;      // Parameter values (after '=')
	byte                m_eType;       // ESamplerType
	short               m_nRegister[eHWSC_Num];
	int                 m_nTexState;
	SFXSampler()
	{
		m_nTexState = -1;
		m_nArray = 0;
		m_nFlags = 0;
		for (int i = 0; i < eHWSC_Num; i++)
		{
			m_nRegister[i] = 10000;
		}
	}
	~SFXSampler()
	{
	}
	uint32 GetFlags() { return m_nFlags; }
	void   PostLoad(class CParserBin& Parser, SParserFrame& Name, SParserFrame& Annotations, SParserFrame& Values, SParserFrame& Assign);
	void   PostLoad();
	bool   Export(SShaderSerializeContext& SC);
	bool   Import(SShaderSerializeContext& SC, SSFXSampler* pPR);
	uint32 Size()
	{
		uint32 nSize = sizeof(SFXSampler);
		//nSize += m_Name.capacity();
		nSize += sizeofVector(m_dwName);
		//nSize += m_Values.capacity();
		return nSize;
	}
	inline bool operator==(const SFXSampler& m) const
	{
		if (m_Name == m.m_Name && m_Annotations == m.m_Annotations && m_Semantic == m.m_Semantic && m_Values == m.m_Values &&
		    m_nArray == m.m_nArray && m_nFlags == m.m_nFlags && m_nRegister[0] == m.m_nRegister[0] && m_nRegister[1] == m.m_nRegister[1] &&
		    m_eType == m.m_eType && m_nTexState == m.m_nTexState)
			return true;
		return false;
	}
};

struct SFXTexture
{
	CCryNameR           m_Name; // Texture name
	std::vector<uint32> m_dwName;
	uint32              m_nFlags;
	uint32              m_nTexFlags;
	short               m_nArray;      // Number of textures
	CCryNameR           m_Annotations; // Additional parameters (between <>)
	CCryNameR           m_Semantic;    // Parameter semantic type (after ':')
	CCryNameR           m_Values;      // Parameter values (after '=')
	string              m_szTexture;   // Texture source name
	string              m_szUIName;    // UI name
	string              m_szUIDesc;    // UI description
	bool                m_bSRGBLookup; // Lookup
	byte                m_eType;       // ETextureType
	byte                m_Type;        // Data type (float, float4, etc)
	short               m_nRegister[eHWSC_Num];
	SFXTexture()
	{
		m_bSRGBLookup = false;
		m_Type = 0;
		m_nTexFlags = 0;
		m_nArray = 0;
		m_nFlags = 0;
		for (int i = 0; i < eHWSC_Num; i++)
		{
			m_nRegister[i] = 10000;
		}
	}
	~SFXTexture()
	{
	}
	uint32 GetFlags()    { return m_nFlags; }
	uint32 GetTexFlags() { return m_nTexFlags; }
	void   PostLoad(class CParserBin& Parser, SParserFrame& Name, SParserFrame& Annotations, SParserFrame& Values, SParserFrame& Assign);
	void   PostLoad();
	bool   Export(SShaderSerializeContext& SC);
	bool   Import(SShaderSerializeContext& SC, SSFXTexture* pPR);
	uint32 Size()
	{
		uint32 nSize = sizeof(SFXTexture);
		//nSize += m_Name.capacity();
		nSize += sizeofVector(m_dwName);
		//nSize += m_Values.capacity();
		return nSize;
	}
	inline bool operator==(const SFXTexture& m) const
	{
		if (m_Name == m.m_Name && m_Annotations == m.m_Annotations && m_Semantic == m.m_Semantic && m_Values == m.m_Values &&
		    m_nArray == m.m_nArray && m_nFlags == m.m_nFlags && m_nRegister[0] == m.m_nRegister[0] && m_nRegister[1] == m.m_nRegister[1] &&
		    m_eType == m.m_eType && m_bSRGBLookup == m.m_bSRGBLookup && m_szTexture == m.m_szTexture)
			return true;
		return false;
	}
};

// In Matrix 3x4: m_nParams = 3, m_nComps = 4
struct SFXParam
{
	CCryNameR           m_Name; // Parameter name
	std::vector<uint32> m_dwName;
	uint32              m_nFlags;
	short               m_nParameters; // Number of parameters
	short               m_nComps;      // Number of components in single parameter
	CCryNameR           m_Annotations; // Additional parameters (between <>)
	CCryNameR           m_Semantic;    // Parameter semantic type (after ':')
	CCryNameR           m_Values;      // Parameter values (after '=')
	byte                m_eType;       // EParamType
	int8                m_nCB;
	short               m_nRegister[eHWSC_Num];
	SFXParam()
	{
		m_nParameters = 0;
		m_nComps = 0;
		m_nCB = -1;
		m_nFlags = 0;
		m_nRegister[0] = 10000;
		m_nRegister[1] = 10000;
		m_nRegister[2] = 10000;
		m_nRegister[3] = 10000;
		m_nRegister[4] = 10000;
		m_nRegister[5] = 10000;
	}
	~SFXParam()
	{
		int nnn = 0;
	}
	uint32 GetComponent(EHWShaderClass eSHClass);
	void GetParamComp(uint32 nOffset, CryFixedStringT<128>& param) { FGetParamComp(this, nOffset, param); }
	uint32 GetParamFlags() { return m_nFlags; }
	void GetCompName(uint32 nId, CryFixedStringT<128>& name) { FGetCompName(this, nId, name); }
	string GetValueForName(const char* szName, EParamType& eType);
	void PostLoad(CParserBin& Parser, SParserFrame& Name, SParserFrame& Annotations, SParserFrame& Values, SParserFrame& Assign) { FPostLoadOv1(this, Parser, Name, Annotations, Values, Assign); }
	void   PostLoad();
	bool   Export(SShaderSerializeContext& SC);
	bool   Import(SShaderSerializeContext& SC, SSFXParam* pPR);
	uint32 Size()
	{
		uint32 nSize = sizeof(SFXParam);
		//nSize += m_Name.capacity();
		nSize += sizeofVector(m_dwName);
		//nSize += m_Values.capacity();
		return nSize;
	}
	inline bool operator==(const SFXParam& m) const
	{
		if (m_Name == m.m_Name && m_Annotations == m.m_Annotations && m_Semantic == m.m_Semantic && m_Values == m.m_Values &&
		    m_nParameters == m.m_nParameters && m_nComps == m.m_nComps && m_nFlags == m.m_nFlags && m_nRegister[0] == m.m_nRegister[0] && m_nRegister[1] == m.m_nRegister[1] &&
		    m_eType == m.m_eType)
			return true;
		return false;
	}

	static inline auto FBitNotSFXParam = PreyFunction<void(SFXParam* const _this)>(0x1027590);
	static inline auto FGetParamComp = PreyFunction<void(SFXParam* const _this, unsigned nOffset, CryFixedStringT<128>& param)>(0x1029EA0);
	static inline auto FGetCompName = PreyFunction<void(SFXParam* const _this, unsigned nId, CryFixedStringT<128>& name)>(0x10298C0);
	static inline auto FGetValueForName = PreyFunction<string*(SFXParam* const _this, string* returnValue, const char* szName, EParamType& eType)>(0x102A740);
	static inline auto FPostLoadOv1 = PreyFunction<void(SFXParam* const _this, CParserBin& Parser, SParserFrame& Name, SParserFrame& Annotations, SParserFrame& Values, SParserFrame& Assign)>(0x1010ED0);
};

struct STokenD
{
	//std::vector<int> Offsets;
	uint32   Token;
	string   SToken;
	unsigned Size()                                  { return sizeof(STokenD) /*+ sizeofVector(Offsets)*/ + SToken.capacity(); }
};
typedef std::vector<STokenD>    FXShaderToken;
typedef FXShaderToken::iterator FXShaderTokenItor;

struct SFXStruct
{
	string m_Name;
	string m_Struct;
	SFXStruct()
	{
	}
};

enum ETexFilter
{
	eTEXF_None,
	eTEXF_Point,
	eTEXF_Linear,
	eTEXF_Anisotropic,
};

//=============================================================================

#if CRY_PLATFORM_WINDOWS && CRY_PLATFORM_64BIT
	#pragma warning( push )               //AMD Port
	#pragma warning( disable : 4267 )
#endif

#if CRY_PLATFORM_WINDOWS && CRY_PLATFORM_64BIT
	#pragma warning( pop )                //AMD Port
#endif

//=============================================================================
// Vertex programms / Vertex shaders (VP/VS)

//=====================================================================

static inline float* sfparam(Vec3 param)
{
	static float sparam[4];
	sparam[0] = param.x;
	sparam[1] = param.y;
	sparam[2] = param.z;
	sparam[3] = 1.0f;

	return &sparam[0];
}

static inline float* sfparam(float param)
{
	static float sparam[4];
	sparam[0] = param;
	sparam[1] = 0;
	sparam[2] = 0;
	sparam[3] = 1.0f;
	return &sparam[0];
}

static inline float* sfparam(float param0, float param1, float param2, float param3)
{
	static float sparam[4];
	sparam[0] = param0;
	sparam[1] = param1;
	sparam[2] = param2;
	sparam[3] = param3;
	return &sparam[0];
}

inline char* sGetFuncName(const char* pFunc)
{
	static char func[128];
	const char* b = pFunc;
	if (*b == '[')
	{
		const char* s = strchr(b, ']');
		if (s)
			b = s + 1;
		while (*b <= 0x20)
		{
			b++;
		}
	}
	while (*b > 0x20)
	{
		b++;
	}
	while (*b <= 0x20)
	{
		b++;
	}
	int n = 0;
	while (*b > 0x20 && *b != '(')
	{
		func[n++] = *b++;
	}
	func[n] = 0;

	return func;
}

enum ERenderOrder
{
	eRO_PreProcess,
	eRO_PostProcess,
	eRO_PreDraw
};

enum ERTUpdate
{
	eRTUpdate_Unknown,
	eRTUpdate_Always,
	eRTUpdate_WaterReflect
};

struct SHRenderTarget : public IRenderTarget
{
	int          m_nRefCount;
	ERenderOrder m_eOrder;
	int          m_nProcessFlags; // FSPR_ flags
	string       m_TargetName;
	int          m_nWidth;
	int          m_nHeight;
	ETEX_Format  m_eTF;
	int          m_nIDInPool;
	ERTUpdate    m_eUpdateType;
	CTexture* m_pTarget[2];
	bool         m_bTempDepth;
	ColorF       m_ClearColor;
	float        m_fClearDepth;
	uint32       m_nFlags;
	uint32       m_nFilterFlags;
	int          m_refSamplerID;

	SHRenderTarget()
	{
		m_nRefCount = 1;
		m_eOrder = eRO_PreProcess;
		m_pTarget[0] = NULL;
		m_pTarget[1] = NULL;
		m_bTempDepth = true;
		m_ClearColor = Col_Black;
		m_fClearDepth = 1.f;
		m_nFlags = 0;
		m_nFilterFlags = 0xffffffff;
		m_nProcessFlags = 0;
		m_nIDInPool = -1;
		m_nWidth = 256;
		m_nHeight = 256;
		m_eTF = eTF_R8G8B8A8;
		m_eUpdateType = eRTUpdate_Unknown;
		m_refSamplerID = -1;
	}
	virtual void Release()
	{
		m_nRefCount--;
		if (m_nRefCount)
			return;
		delete this;
	}
	virtual void AddRef()
	{
		m_nRefCount++;
	}
	SEnvTexture* GetEnv2D();
	SEnvTexture* GetEnvCM();

	void         GetMemoryUsage(ICrySizer* pSizer) const;
};

//=============================================================================
// Hardware shaders

#define SHADER_BIND_TEXTURE 0x2000
#define SHADER_BIND_SAMPLER 0x4000

//=============================================================================

struct SShaderCacheHeaderItem
{
	byte   m_nVertexFormat;
	byte   m_Class;
	byte   m_nInstBinds;
	byte   m_StreamMask_Stream;
	uint32 m_CRC32;
	uint16 m_StreamMask_Decl;
	int16  m_nInstructions;
	SShaderCacheHeaderItem()
	{
		memset(this, 0, sizeof(SShaderCacheHeaderItem));
	}
	//AUTO_STRUCT_INFO;
};

#define MAX_VAR_NAME 512
struct SShaderCacheHeaderItemVar
{
	int   m_Reg;
	short m_nCount;
	char  m_Name[MAX_VAR_NAME];
	SShaderCacheHeaderItemVar()
	{
		memset(this, 0, sizeof(SShaderCacheHeaderItemVar));
	}
};

struct SCompressedData
{
	byte*  m_pCompressedShader;
	uint32 m_nSizeCompressedShader;
	uint32 m_nSizeDecompressedShader;

	SCompressedData()
	{
		m_pCompressedShader = NULL;
		m_nSizeCompressedShader = 0;
		m_nSizeDecompressedShader = 0;
	}
	int Size()
	{
		int nSize = sizeof(SCompressedData);
		if (m_pCompressedShader)
			nSize += m_nSizeCompressedShader;
		return nSize;
	}
};

typedef std::map<int, struct SD3DShader*> FXDeviceShader;
typedef FXDeviceShader::iterator          FXDeviceShaderItor;

#define CACHE_READONLY 0
#define CACHE_USER     1

struct SOptimiseStats
{
	int nEntries;
	int nUniqueEntries;
	int nSizeUncompressed;
	int nSizeCompressed;
	int nTokenDataSize;
	int nDirDataSize;
	SOptimiseStats()
	{
		nEntries = 0;
		nUniqueEntries = 0;
		nSizeUncompressed = 0;
		nSizeCompressed = 0;
		nTokenDataSize = 0;
		nDirDataSize = 0;
	}
};

typedef std::map<CCryNameR, SShaderCache*>    FXShaderCache;
typedef FXShaderCache::iterator               FXShaderCacheItor;

typedef std::map<CCryNameR, SShaderDevCache*> FXShaderDevCache;
typedef FXShaderDevCache::iterator            FXShaderDevCacheItor;

typedef std::map<string, uint32>              FXShaderCacheNames;
typedef FXShaderCacheNames::iterator          FXShaderCacheNamesItor;

//====================================================================
// HWShader run-time flags
// Note:we are limited to a maximum of 64, check HWSR_MAX before adding

enum EHWSRMaskBit
{
	HWSR_FOG = 0,

	HWSR_ALPHATEST,
	HWSR_ALPHABLEND,

	HWSR_MSAA_QUALITY,
	HWSR_MSAA_QUALITY1,
	HWSR_MSAA_SAMPLEFREQ_PASS,

	HWSR_HDR_MODE,      // deprecated: this flag is redundant and can be dropped, since rendering always HDR since CE3

	HWSR_INSTANCING_ATTR,

	HWSR_VERTEX_VELOCITY,
	HWSR_SKELETON_SSD,
	HWSR_SKELETON_SSD_LINEAR,

	HWSR_OBJ_IDENTITY,
	HWSR_NEAREST,
	HWSR_NOZPASS,
	HWSR_DISSOLVE,
	HWSR_NO_TESSELLATION,
	HWSR_PER_INSTANCE_CB_TEMP,

	HWSR_QUALITY,
	HWSR_QUALITY1,

	HWSR_SAMPLE0,
	HWSR_SAMPLE1,
	HWSR_SAMPLE2,
	HWSR_SAMPLE3,
	HWSR_SAMPLE4,
	HWSR_SAMPLE5,

	HWSR_DEBUG0,
	HWSR_DEBUG1,
	HWSR_DEBUG2,
	HWSR_DEBUG3,

	HWSR_CUBEMAP0,

	HWSR_DECAL_TEXGEN_2D,

	HWSR_HW_PCF_COMPARE,
	HWSR_SHADOW_JITTERING,

	HWSR_BLEND_WITH_TERRAIN_COLOR,

	HWSR_PARTICLE_SHADOW,
	HWSR_SOFT_PARTICLE,
	HWSR_ANIM_BLEND,
	HWSR_ENVIRONMENT_CUBEMAP,
	HWSR_MOTION_BLUR,

	HWSR_SPRITE,

	HWSR_LIGHTVOLUME0,
	HWSR_LIGHTVOLUME1,

	HWSR_TILED_SHADING,

	HWSR_VOLUMETRIC_FOG,

	HWSR_REVERSE_DEPTH,

	HWSR_SCENE_SELECTION,
	HWSR_MIMIC_MORPH,

	HWSR_MAX
};

inline auto g_HWSR_MaskBit = PreyGlobal<uint64[HWSR_MAX]>(0x2BA71F0);

// HWShader global flags (m_Flags)
//#define HWSG_SUPPORTS_LIGHTING    0x20
//#define HWSG_SUPPORTS_MULTILIGHTS 0x40
#define HWSG_SUPPORTS_MODIF       0x80
#define HWSG_SUPPORTS_VMODIF      0x100
#define HWSG_WASGENERATED         0x200
#define HWSG_NOSPECULAR           0x400
#define HWSG_SYNC                 0x800
#define HWSG_CACHE_USER           0x1000
//#define HWSG_AUTOENUMTC      0x1000
#define HWSG_UNIFIEDPOS           0x2000
#define HWSG_DEFAULTPOS           0x4000
#define HWSG_PROJECTED            0x8000
#define HWSG_NOISE                0x10000
#define HWSG_PRECACHEPHASE        0x20000
#define HWSG_FP_EMULATION         0x40000

// HWShader per-instance Modificator flags (SHWSInstance::m_MDMask)
// Vertex shader specific

// Texture projected flags
#define HWMD_TEXCOORD_PROJ              0x1
// Texture transform flag
#define HWMD_TEXCOORD_MATRIX            0x100
// Object linear texgen flag
//#define HWMD_TEXCOORD_GEN_OBJECT_LINEAR 0x1000

#define HWMD_TEXCOORD_FLAG_MASK         (0xfffff000 | 0xf00)

// HWShader per-instance vertex modificator flags (SHWSInstance::m_MDVMask)
// Texture projected flags (4 bits)
#define HWMDV_TYPE 0

// HWShader input flags (passed via mfSet function)
#define HWSF_SETPOINTERSFORSHADER 1
#define HWSF_SETPOINTERSFORPASS   2
#define HWSF_PRECACHE             4
#define HWSF_SETTEXTURES          8
#define HWSF_FAKE                 0x10

#define HWSF_INSTANCED            0x20
#define HWSF_NEXT                 0x100
#define HWSF_PRECACHE_INST        0x200
#define HWSF_STORECOMBINATION     0x400
#define HWSF_STOREDATA            0x800

class CShaderResources;

class CHWShader : public CBaseResource
{
public:
	static inline auto s_sClassNameVS = PreyGlobal<CCryNameTSCRC>(0x2B175A4);
	static inline auto s_sClassNamePS = PreyGlobal<CCryNameTSCRC>(0x2B175A8);

	EHWShaderClass            m_eSHClass;
	//EHWSProfile m_eHWProfile;
	SShaderCache*             m_pGlobalCache;

	static inline auto s_pCurPS = PreyGlobal<SD3DShader*>(0x2B12770);
	static inline auto s_pCurVS = PreyGlobal<SD3DShader*>(0x2B12778);
	static inline auto s_pCurGS = PreyGlobal<SD3DShader*>(0x2B12780);
	static inline auto s_pCurDS = PreyGlobal<SD3DShader*>(0x2B12788);
	static inline auto s_pCurHS = PreyGlobal<SD3DShader*>(0x2B12790);
	static inline auto s_pCurCS = PreyGlobal<SD3DShader*>(0x2B12798);

	string                    m_Name;
	string                    m_NameSourceFX;
	string                    m_EntryFunc;
	uint64                    m_nMaskAnd_RT;
	uint64                    m_nMaskOr_RT;
	uint64                    m_nMaskGenShader; // Masked/Optimised m_nMaskGenFX for this specific HW shader
	uint64                    m_nMaskGenFX;     // FX Shader should be parsed with this flags
	uint64                    m_nMaskSetFX;     // AffectMask GL for parser tree

	uint32                    m_nPreprocessFlags;
	int                       m_nFrame;
	int                       m_nFrameLoad;
	int                       m_Flags;
	uint32                    m_CRC32;
	uint32                    m_dwShaderType;

	static inline auto m_ShaderCacheList = PreyGlobal<FXShaderCacheNames>(0x2B167D8);
	static inline auto m_ShaderCache = PreyGlobal<FXShaderCache>(0x2B167B8);
	static inline auto m_ShaderDevCache = PreyGlobal<FXShaderDevCache>(0x2B167C8);
	//static inline auto m_CompressedShaders = PreyGlobal<std::map<CCryNameTSCRC, SHWActivatedShader*, std::less<CCryNameTSCRC>>>(0x2BA7440);
	
	inline const char* GetName()
	{
		return m_Name.c_str();
	}
	
	virtual ~CHWShader();
	static CHWShader* mfForName(const char* name, const char* nameSource, unsigned CRC32, const char* szEntryFunc, EHWShaderClass eClass, TArray<unsigned int>& SHData, std::vector<STokenD>* pTable, unsigned dwType, CShader* pFX, uint64_t nMaskGen, uint64_t nMaskGenFX) { return FmfForName(name, nameSource, CRC32, szEntryFunc, eClass, SHData, pTable, dwType, pFX, nMaskGen, nMaskGenFX); }
	//static void mfFlushPendedShadersWait(int nMaxAllowed) { FmfFlushPendedShadersWait(nMaxAllowed); }
	virtual int Size() = 0;
	virtual void GetMemoryUsage(ICrySizer* arg0) const = 0;
	virtual void mfReset(unsigned CRC32);
	virtual bool mfSetV(int arg0) = 0;
	virtual bool mfAddEmptyCombination(CShader* arg0, uint64_t arg1, uint64_t arg2, unsigned arg3) = 0;
	virtual bool mfStoreEmptyCombination(SEmptyCombination& arg0) = 0;
	virtual const char* mfGetCurScript();
	virtual const char* mfGetEntryName() = 0;
	virtual bool mfFlushCacheFile() = 0;
	virtual bool mfPrecache(SShaderCombination& arg0, bool arg1, bool arg2, CShader* arg3, CShaderResources* arg4) = 0;
	virtual EVertexFormat mfVertexFormat(bool& arg0, bool& arg1, bool& arg2) = 0;
	virtual const char* mfGetActivatedCombinations(bool arg0) = 0;
	static const char* mfProfileString(EHWShaderClass eClass) { return FmfProfileString(eClass); }
	static const char* mfClassString(EHWShaderClass eClass) { return FmfClassString(eClass); }
	static void mfGenName(uint64_t GLMask, uint64_t RTMask, unsigned LightMask, unsigned MDMask, unsigned MDVMask, uint64_t PSS, EHWShaderClass eClass, char* dstname, int nSize, uint8_t bType) { FmfGenName(GLMask, RTMask, LightMask, MDMask, MDVMask, PSS, eClass, dstname, nSize, bType); }
	static void mfCleanupCache() { FmfCleanupCache(); }
	//static SShaderCache* mfInitCache(const char* name, CHWShader* pSH, bool bCheckValid, unsigned CRC32, bool bReadOnly, bool bAsync = false) { return FmfInitCache(name, pSH, bCheckValid, CRC32, bReadOnly, bAsync); }
	//static bool _OpenCacheFile(float fVersion, SShaderCache* pCache, CHWShader* pSH, bool bCheckValid, unsigned CRC32, int nCache, CResFile* pRF, bool bReadOnly) { return F_OpenCacheFile(fVersion, pCache, pSH, bCheckValid, CRC32, nCache, pRF, bReadOnly); }
	//static bool mfOpenCacheFile(const char* szName, float fVersion, SShaderCache* pCache, CHWShader* pSH, bool bCheckValid, unsigned CRC32, bool bReadOnly) { return FmfOpenCacheFile(szName, fVersion, pCache, pSH, bCheckValid, CRC32, bReadOnly); }

#if 0
	static void mfReloadScript(const char* arg0, const char* arg1, int arg2, uint64_t arg3);
	const char* GetName();
	static EHWShaderClass mfStringProfile(const char* arg0);
	static EHWShaderClass mfStringClass(const char* arg0);
	static void mfLazyUnload();
	static CCryNameTSCRC mfGetClassName(EHWShaderClass arg0);
	static const char* GetCurrentShaderCombinations(bool arg0);
	static uint8_t* mfIgnoreRemapsFromCache(int arg0, uint8_t* arg1);
	static uint8_t* mfIgnoreBindsFromCache(int arg0, uint8_t* arg1);
	static SShaderDevCache* mfInitDevCache(const char* arg0, CHWShader* arg1);
	static void mfValidateTokenData(CResFile* arg0);
#endif

	// Shader compiling in Chairloader
	static void             mfValidateTokenData(CResFile* pRF);
	static SShaderDevCache* mfInitDevCache(const char* name, CHWShader* pSH);
	static bool             mfOptimiseCacheFile(SShaderCache* pCache, bool bForce, SOptimiseStats* Stats);
	static bool _OpenCacheFile(float fVersion, SShaderCache* pCache, CHWShader* pSH, bool bCheckValid, unsigned CRC32, int nCache, CResFile* pRF, bool bReadOnly);
	static bool mfOpenCacheFile(const char* szName, float fVersion, SShaderCache* pCache, CHWShader* pSH, bool bCheckValid, unsigned CRC32, bool bReadOnly);
	static SShaderCache* mfInitCache(const char* name, CHWShader* pSH, bool bCheckValid, unsigned CRC32, bool bReadOnly, bool bAsync = false);
	static byte* mfIgnoreBindsFromCache(int nParams, byte* pP);
	static void mfFlushPendedShadersWait(int nMaxAllowed);
	static bool ImportSamplers(SShaderSerializeContext& SC, struct SCHWShader* pSHW, byte*& pData, std::vector<STexSamplerRT>& Samplers);
	static bool ImportParams(SShaderSerializeContext& SC, SCHWShader* pSHW, byte*& pData, std::vector<SFXParam>& Params);
	static CHWShader* Import(SShaderSerializeContext& SC, int nOffs, uint32 CRC32, CShader* pSH);
	static const char* GetCurrentShaderCombinations(bool bForLevel);

	static CCryNameTSCRC  mfGetClassName(EHWShaderClass eClass)
	{
		if (eClass == eHWSC_Vertex)
			return *s_sClassNameVS;
		else
			return *s_sClassNamePS;
	}

	static EHWShaderClass mfStringClass(const char* szClass)
	{
		EHWShaderClass Profile = eHWSC_Num;
		if (!strnicmp(szClass, "VS", 2))
			Profile = eHWSC_Vertex;
		else if (!strnicmp(szClass, "PS", 2))
			Profile = eHWSC_Pixel;
		else if (!strnicmp(szClass, "GS", 2))
			Profile = eHWSC_Geometry;
		else if (!strnicmp(szClass, "HS", 2))
			Profile = eHWSC_Hull;
		else if (!strnicmp(szClass, "DS", 2))
			Profile = eHWSC_Domain;
		else if (!strnicmp(szClass, "CS", 2))
			Profile = eHWSC_Compute;
		else
			assert(0);

		return Profile;
	}

	static inline auto FBitNotCHWShader = PreyFunction<void(CHWShader* const _this)>(0xEEAC90);
	static inline auto FmfForName = PreyFunction<CHWShader* (const char* name, const char* nameSource, unsigned CRC32, const char* szEntryFunc, EHWShaderClass eClass, TArray<unsigned int>& SHData, std::vector<STokenD>* pTable, unsigned dwType, CShader* pFX, uint64_t nMaskGen, uint64_t nMaskGenFX)>(0xEED9B0);
	static inline auto FmfFlushPendedShadersWait = PreyFunction<void(int nMaxAllowed)>(0xEFB300);
	static inline auto FmfReset = PreyFunction<void(CHWShader* const _this, unsigned CRC32)>(0xA13080);
	static inline auto FmfGetCurScript = PreyFunction<const char* (CHWShader* const _this)>(0x158AEF0);
	static inline auto FmfProfileString = PreyFunction<const char* (EHWShaderClass eClass)>(0x1020B30);
	static inline auto FmfClassString = PreyFunction<const char* (EHWShaderClass eClass)>(0x101CF20);
	static inline auto FmfGenName = PreyFunction<void(uint64_t GLMask, uint64_t RTMask, unsigned LightMask, unsigned MDMask, unsigned MDVMask, uint64_t PSS, EHWShaderClass eClass, char* dstname, int nSize, uint8_t bType)>(0x1014D50);
	static inline auto FmfCleanupCache = PreyFunction<void()>(0x101CFA0);
	static inline auto FmfInitCache = PreyFunction<SShaderCache* (const char* name, CHWShader* pSH, bool bCheckValid, unsigned CRC32, bool bReadOnly, bool bAsync)>(0xEFE160);
	static inline auto F_OpenCacheFile = PreyFunction<bool(float fVersion, SShaderCache* pCache, CHWShader* pSH, bool bCheckValid, unsigned CRC32, int nCache, CResFile* pRF, bool bReadOnly)>(0xEF8250);
	static inline auto FmfOpenCacheFile = PreyFunction<bool(const char* szName, float fVersion, SShaderCache* pCache, CHWShader* pSH, bool bCheckValid, unsigned CRC32, bool bReadOnly)>(0xEFE5C0);
};

inline void SortLightTypes(int Types[4], int nCount)
{
	switch (nCount)
	{
	case 2:
		if (Types[0] > Types[1])
			Exchange(Types[0], Types[1]);
		break;
	case 3:
		if (Types[0] > Types[1])
			Exchange(Types[0], Types[1]);
		if (Types[0] > Types[2])
			Exchange(Types[0], Types[2]);
		if (Types[1] > Types[2])
			Exchange(Types[1], Types[2]);
		break;
	case 4:
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = i; j < 4; j++)
				{
					if (Types[i] > Types[j])
						Exchange(Types[i], Types[j]);
				}
			}
		}
		break;
	}
}

//=========================================================================
// Dynamic lights evaluating via shaders

enum ELightStyle
{
	eLS_Intensity,
	eLS_RGB,
};

enum ELightMoveType
{
	eLMT_Wave,
	eLMT_Patch,
};

struct SLightMove
{
	ELightMoveType m_eLMType;
	SWaveForm      m_Wave;
	Vec3           m_Dir;
	float          m_fSpeed;

	int            Size()
	{
		int nSize = sizeof(SLightMove);
		return nSize;
	}
};

struct SLightStyleKeyFrame
{
	ColorF cColor;     // xyz: color, w: spec mult
	Vec3   vPosOffset; // position offset

	SLightStyleKeyFrame()
	{
		cColor = ColorF(Col_Black);
		vPosOffset = Vec3(ZERO);
	}
};

class CLightStyle
{
public:

	CLightStyle() : m_TimeIncr(60.0f)
	{
	}

	static TArray<CLightStyle*> s_LStyles;
	TArray<SLightStyleKeyFrame> m_Map;
	float                       m_TimeIncr;

	int Size()
	{
		int nSize = sizeof(CLightStyle);
		nSize += m_Map.GetMemoryUsage();
		return nSize;
	}

	static inline CLightStyle* mfGetStyle(uint32 nStyle, float fTime)
	{
		if (nStyle >= s_LStyles.Num() || !s_LStyles[nStyle])
			return NULL;
		s_LStyles[nStyle]->mfUpdate(fTime);
		return s_LStyles[nStyle];
	}

	void mfUpdate(float fTime);
};

//=========================================================================
// HW Shader Layer

#define SHPF_AMBIENT             0x100
#define SHPF_HASLM               0x200
#define SHPF_SHADOW              0x400
#define SHPF_RADIOSITY           0x800
#define SHPF_ALLOW_SPECANTIALIAS 0x1000
#define SHPF_BUMP                0x2000
#define SHPF_NOMATSTATE          0x4000
#define SHPF_FORCEZFUNC          0x8000

// Shader pass definition for HW shaders
struct SShaderPass
{
	uint32      m_RenderState;     // Render state flags
	signed char m_eCull;
	uint8       m_AlphaRef;

	uint16      m_PassFlags;         // Different usefull Pass flags (SHPF_)

	CHWShader*  m_VShader;        // Pointer to the vertex shader for the current pass
	CHWShader*  m_PShader;        // Pointer to fragment shader
	CHWShader*  m_GShader;        // Pointer to the geometry shader for the current pass
	CHWShader*  m_HShader;        // Pointer to the hull shader for the current pass
	CHWShader*  m_DShader;        // Pointer to the domain shader for the current pass
	CHWShader*  m_CShader;        // Pointer to the compute shader for the current pass
	SShaderPass();

	int Size()
	{
		int nSize = sizeof(SShaderPass);
		return nSize;
	}

	void mfFree()
	{
		SAFE_RELEASE(m_VShader);
		SAFE_RELEASE(m_PShader);
		SAFE_RELEASE(m_GShader);
		SAFE_RELEASE(m_HShader);
		SAFE_RELEASE(m_DShader);
		SAFE_RELEASE(m_CShader);
	}

	void AddRefsToShaders()
	{
		if (m_VShader)
			m_VShader->AddRef();
		if (m_PShader)
			m_PShader->AddRef();
		if (m_GShader)
			m_GShader->AddRef();
		if (m_DShader)
			m_DShader->AddRef();
		if (m_HShader)
			m_HShader->AddRef();
		if (m_CShader)
			m_CShader->AddRef();
	}

private:
	SShaderPass& operator=(const SShaderPass& sl);
};

//===================================================================================
// Hardware Stage for HW only Shaders

#define FHF_FIRSTLIGHT          8
#define FHF_FORANIM             0x10
#define FHF_TERRAIN             0x20
#define FHF_NOMERGE             0x40
#define FHF_DETAILPASS          0x80
#define FHF_LIGHTPASS           0x100
#define FHF_FOGPASS             0x200
#define FHF_PUBLIC              0x400
#define FHF_NOLIGHTS            0x800
#define FHF_POSITION_INVARIANT  0x1000
#define FHF_RE_CLOUD            0x20000
#define FHF_TRANSPARENT         0x40000
#define FHF_WASZWRITE           0x80000
#define FHF_USE_GEOMETRY_SHADER 0x100000
#define FHF_USE_HULL_SHADER     0x200000
#define FHF_USE_DOMAIN_SHADER   0x400000
#define FHF_RE_LENSOPTICS       0x1000000

struct SShaderTechnique
{
	CShader*                  m_shader;    // Shader owner of this technique.
	CCryNameR                 m_NameStr;
	CCryNameTSCRC             m_NameCRC;
	TArray<SShaderPass>       m_Passes;    // General passes
	int                       m_Flags;     // Different flags (FHF_)
	uint32                    m_nPreprocessFlags;
	int8                      m_nTechnique[TTYPE_MAX]; // Next technique in sequence
	TArray<CRendElementBase*> m_REs;                   // List of all render elements registered in the shader
	float                     m_fProfileTime;

	int                       Size()
	{
		uint32 i;
		int nSize = sizeof(SShaderTechnique);
		for (i = 0; i < m_Passes.Num(); i++)
		{
			nSize += m_Passes[i].Size();
		}
		return nSize;
	}

	SShaderTechnique(CShader* shader)
	{
		m_shader = shader;
		uint32 i;
		for (i = 0; i < TTYPE_MAX; i++)
		{
			m_nTechnique[i] = -1;
		}
		for (i = 0; i < m_REs.Num(); i++)
		{
			SAFE_DELETE(m_REs[i]);
		}
		m_REs.Free();

		m_Flags = 0;
		m_nPreprocessFlags = 0;
		m_fProfileTime = 0;
	}
#if 0
	SShaderTechnique& operator=(const SShaderTechnique& sl)
	{
		memcpy(this, &sl, sizeof(SShaderTechnique));
		if (sl.m_Passes.Num())
		{
			m_Passes.Copy(sl.m_Passes);
			for (uint32 i = 0; i < sl.m_Passes.Num(); i++)
			{
				SShaderPass* d = &m_Passes[i];
				d->AddRefsToShaders();
			}
		}
		if (sl.m_REs.Num())
		{
			m_REs.Create(sl.m_REs.Num());
			for (uint32 i = 0; i < sl.m_REs.Num(); i++)
			{
				if (sl.m_REs[i])
					m_REs[i] = sl.m_REs[i]->mfCopyConstruct();
			}
		}

		return *this;
	}
#endif

	~SShaderTechnique()
	{
		for (uint32 i = 0; i < m_Passes.Num(); i++)
		{
			SShaderPass* sl = &m_Passes[i];

			sl->mfFree();
		}
		for (uint32 i = 0; i < m_REs.Num(); i++)
		{
			CRendElementBase* pRE = m_REs[i];
			//pRE->Release(false);
		}
		m_REs.Free();
		m_Passes.Free();
	}
	void  UpdatePreprocessFlags(CShader* pSH);

	void* operator new(size_t Size)                                { void* ptr = malloc(Size); memset(ptr, 0, Size); return ptr; }
	void* operator new(size_t Size, const std::nothrow_t& nothrow) { void* ptr = malloc(Size); if (ptr) memset(ptr, 0, Size); return ptr; }
	void  operator delete(void* Ptr)                               { free(Ptr); }
};

//===============================================================================

enum EShaderDrawType
{
	eSHDT_General,
	eSHDT_Light,
	eSHDT_Terrain,
	eSHDT_NoDraw,
	eSHDT_CustomDraw,
	eSHDT_Sky
};

// General Shader structure
class CShader : public IShader, public CBaseResource
{
public:
	static inline auto s_sClassName = PreyGlobal<CCryNameTSCRC>(0x2B175AC);

	string                    m_NameFile; // } FIXME: This fields order is very important
	string                    m_NameShader;
	EShaderDrawType           m_eSHDType; // } Check CShader::operator = in ShaderCore.cpp for more info

	uint32                    m_Flags;  // Different flags EF_  (see IShader.h)
	uint32                    m_Flags2; // Different flags EF2_ (see IShader.h)
	uint32                    m_nMDV;   // Vertex modificator flags
	uint32                    m_NameShaderICRC;

	EVertexFormat             m_eVertexFormat; // Base vertex format for the shader (see VertexFormats.h)
	ECull                     m_eCull;         // Global culling type

	TArray<SShaderTechnique*> m_HWTechniques;    // Hardware techniques
	int                       m_nMaskCB;

	EShaderType               m_eShaderType;

	uint64                    m_nMaskGenFX;
	SShaderGen*               m_ShaderGenParams;           // BitMask params used in automatic script generation
	SShaderTexSlots*          m_ShaderTexSlots[TTYPE_MAX]; // filled out with data of the used texture slots for a given technique
	                                                       // (might be NULL if this data isn't gathered)
	std::vector<CShader*>*    m_DerivedShaders;
	CShader*                  m_pGenShader;

	int                       m_nRefreshFrame; // Current frame for shader reloading (to avoid multiple reloading)
	uint32                    m_SourceCRC32;
	uint32                    m_CRC32;

	//============================================================================

	inline int mfGetID() { return CBaseResource::GetID(); }

	CShader()
		: m_eSHDType(eSHDT_General)
		, m_Flags(0)
		, m_Flags2(0)
		, m_nMDV(0)
		, m_NameShaderICRC(0)
		, m_eVertexFormat(eVF_P3F_C4B_T2F)
		, m_eCull((ECull) - 1)
		, m_nMaskCB(0)
		, m_eShaderType(eST_General)
		, m_nMaskGenFX(0)
		, m_ShaderGenParams(nullptr)
		, m_DerivedShaders(nullptr)
		, m_pGenShader(nullptr)
		, m_nRefreshFrame(0)
		, m_SourceCRC32(0)
		, m_CRC32(0)
	{
		memset(m_ShaderTexSlots, 0, sizeof(m_ShaderTexSlots));
	}

	void mfFree() { FmfFree(this); }
	virtual ~CShader();
	virtual int AddRef();
	virtual int Release();
	virtual int ReleaseForce();
	virtual int GetID();
	virtual int GetRefCounter() const;
	virtual const char* GetName();
	virtual const char* GetName() const;
	bool FXSetTechnique(CCryNameTSCRC const& Name) { return FFXSetTechnique(this, Name); }
	bool FXSetPSFloat(CCryNameR const& NameParam, Vec4 const* fParams, int nParams) { return FFXSetPSFloat(this, NameParam, fParams, nParams); }
	bool FXSetCSFloat(CCryNameR const& NameParam, Vec4 const* fParams, int nParams) { return FFXSetCSFloat(this, NameParam, fParams, nParams); }
	bool FXSetVSFloat(CCryNameR const& NameParam, Vec4 const* fParams, int nParams) { return FFXSetVSFloat(this, NameParam, fParams, nParams); }
	bool FXSetGSFloat(CCryNameR const& NameParam, Vec4 const* fParams, int nParams) { return FFXSetGSFloat(this, NameParam, fParams, nParams); }
	bool FXBegin(unsigned* uiPassCount, unsigned nFlags) { return FFXBegin(this, uiPassCount, nFlags); }
	bool FXBeginPass(unsigned uiPass) { return FFXBeginPass(this, uiPass); }
	bool FXEndPass() { return FFXEndPass(this); }
	bool FXEnd() { return FFXEnd(this); }
	virtual int GetFlags() const;
	virtual int GetFlags2() const;
	virtual void SetFlags2(int Flags);
	virtual void ClearFlags2(int Flags);
	virtual bool Reload(int nFlags, const char* szShaderName);
	virtual int GetTechniqueID(int nTechnique, int nRegisteredTechnique);
	virtual TArray<CRendElementBase*>* GetREs(int nTech);
	virtual int GetTexId();
	virtual unsigned GetUsedTextureTypes();
	virtual EVertexFormat GetVertexFormat();
	virtual uint64_t GetGenerationMask();
	virtual ECull GetCull();
	virtual SShaderGen* GetGenerationParams();
	virtual SShaderTexSlots* GetUsedTextureSlots(int nTechnique);
	virtual DynArray<SShaderParam, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& GetPublicParams();
	virtual void CopyPublicParamsTo(SInputShaderResources& copyToResource);
	virtual EShaderType GetShaderType();
	virtual unsigned GetVertexModificator();
	bool mfPrecache(SShaderCombination& cmb, bool bForce, bool bCompressedOnly, CShaderResources* pRes) { return FmfPrecache(this, cmb, bForce, bCompressedOnly, pRes); }
	SShaderTechnique* mfGetStartTechnique(int nTechnique) { return FmfGetStartTechnique(this, nTechnique); }
	SShaderTechnique* GetTechnique(int nStartTechnique, int nRequestedTechnique, bool bSilent) { return FGetTechnique(this, nStartTechnique, nRequestedTechnique, bSilent); }
	virtual ITexture* GetBaseTexture(int* nPass, int* nTU);
	virtual int Size(int Flags);
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;

#if 0
	int mfGetID();
	bool FXCommit(const unsigned arg0);
	void mfFlushPendedShaders();
	SShaderTechnique* mfFindTechnique(CCryNameTSCRC const& arg0);
	CTexture* mfFindBaseTexture(TArray<SShaderPass>& arg0, int* arg1, int* arg2);
	int mfSize();
	static void* operator new(uint64_t arg0);
	static void* operator new(uint64_t arg0, std::nothrow_t const& arg1);
	static void operator delete(void* arg0);
	static CCryNameTSCRC mfGetClassName();
#endif

	// Shader compiling in Chairloader
	void        mfFlushPendedShaders();

	static CCryNameTSCRC mfGetClassName()
	{
		return *s_sClassName;
	}

	static inline auto FmfFree = PreyFunction<void(CShader* const _this)>(0x101D850);
	static inline auto FBitNotCShader = PreyFunction<void(CShader* const _this)>(0x10196C0);
	static inline auto FAddRef = PreyFunction<int(CShader* const _this)>(0x1019C30);
	static inline auto FRelease = PreyFunction<int(CShader* const _this)>(0x101A960);
	static inline auto FReleaseForce = PreyFunction<int(CShader* const _this)>(0x101A9D0);
	static inline auto FGetID = PreyFunction<int(CShader* const _this)>(0xD9C610);
	static inline auto FGetRefCounter = PreyFunction<int(CShader const* const _this)>(0xEEBB60);
	static inline auto FGetNameOv1 = PreyFunction<const char* (CShader* const _this)>(0xD87510);
	static inline auto FGetNameOv0 = PreyFunction<const char* (CShader const* const _this)>(0xD87510);
	static inline auto FFXSetTechnique = PreyFunction<bool(CShader* const _this, CCryNameTSCRC const& Name)>(0xF1A1D0);
	static inline auto FFXSetPSFloat = PreyFunction<bool(CShader* const _this, CCryNameR const& NameParam, Vec4 const* fParams, int nParams)>(0xF1A110);
	static inline auto FFXSetCSFloat = PreyFunction<bool(CShader* const _this, CCryNameR const& NameParam, Vec4 const* fParams, int nParams)>(0xF19F90);
	static inline auto FFXSetVSFloat = PreyFunction<bool(CShader* const _this, CCryNameR const& NameParam, Vec4 const* fParams, int nParams)>(0xF1A260);
	static inline auto FFXSetGSFloat = PreyFunction<bool(CShader* const _this, CCryNameR const& NameParam, Vec4 const* fParams, int nParams)>(0xF1A050);
	static inline auto FFXBegin = PreyFunction<bool(CShader* const _this, unsigned* uiPassCount, unsigned nFlags)>(0xF19C50);
	static inline auto FFXBeginPass = PreyFunction<bool(CShader* const _this, unsigned uiPass)>(0xF19CA0);
	static inline auto FFXEndPass = PreyFunction<bool(CShader* const _this)>(0xF19F50);
	static inline auto FFXEnd = PreyFunction<bool(CShader* const _this)>(0xF19F20);
	static inline auto FGetFlags = PreyFunction<int(CShader const* const _this)>(0x244BD0);
	static inline auto FGetFlags2 = PreyFunction<int(CShader const* const _this)>(0x5371C0);
	static inline auto FSetFlags2 = PreyFunction<void(CShader* const _this, int Flags)>(0x101AA00);
	static inline auto FClearFlags2 = PreyFunction<void(CShader* const _this, int Flags)>(0x1019C50);
	static inline auto FReload = PreyFunction<bool(CShader* const _this, int nFlags, const char* szShaderName)>(0x1039690);
	static inline auto FGetTechniqueID = PreyFunction<int(CShader* const _this, int nTechnique, int nRegisteredTechnique)>(0x101A430);
	static inline auto FGetREs = PreyFunction<TArray<CRendElementBase*>* (CShader* const _this, int nTech)>(0x101A330);
	static inline auto FGetTexId = PreyFunction<int(CShader* const _this)>(0x101A460);
	static inline auto FGetUsedTextureTypes = PreyFunction<unsigned(CShader* const _this)>(0xA38740);
	static inline auto FGetVertexFormat = PreyFunction<EVertexFormat(CShader* const _this)>(0x12BDB0);
	static inline auto FGetGenerationMask = PreyFunction<uint64_t(CShader* const _this)>(0x155AD50);
	static inline auto FGetCull = PreyFunction<ECull(CShader* const _this)>(0x101A070);
	static inline auto FGetGenerationParams = PreyFunction<SShaderGen* (CShader* const _this)>(0x101A0A0);
	static inline auto FGetUsedTextureSlots = PreyFunction<SShaderTexSlots* (CShader* const _this, int nTechnique)>(0x101A490);
	static inline auto FGetPublicParams = PreyFunction<DynArray<SShaderParam, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (CShader* const _this)>(0x101A300);
	static inline auto FCopyPublicParamsTo = PreyFunction<void(CShader* const _this, SInputShaderResources& copyToResource)>(0x1019C60);
	static inline auto FGetShaderType = PreyFunction<EShaderType(CShader* const _this)>(0x1F21C0);
	static inline auto FGetVertexModificator = PreyFunction<unsigned(CShader* const _this)>(0xA38770);
	static inline auto FmfPrecache = PreyFunction<bool(CShader* const _this, SShaderCombination& cmb, bool bForce, bool bCompressedOnly, CShaderResources* pRes)>(0x1016760);
	static inline auto FmfGetStartTechnique = PreyFunction<SShaderTechnique* (CShader* const _this, int nTechnique)>(0x101D8D0);
	static inline auto FGetTechnique = PreyFunction<SShaderTechnique* (CShader* const _this, int nStartTechnique, int nRequestedTechnique, bool bSilent)>(0x101A360);
	static inline auto FGetBaseTexture = PreyFunction<ITexture* (CShader* const _this, int* nPass, int* nTU)>(0x101A050);
	static inline auto FSize = PreyFunction<int(CShader* const _this, int Flags)>(0x101AE70);
	static inline auto FGetMemoryUsage = PreyFunction<void(CShader const* const _this, ICrySizer* pSizer)>(0x101A0C0);
};

//////////////////////////////////////////////////////////////////////////

#endif
