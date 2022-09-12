// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

/*=============================================================================
   ParserBin.h : Script parser declarations.

   Revision history:
* Created by Honich Andrey

   =============================================================================*/

#ifndef PARSERBIN_H
#define PARSERBIN_H

#include "ShaderCache.h"
#include "ShaderAllocator.h"

extern TArray<bool> sfxIFDef;
extern TArray<bool> sfxIFIgnore;

typedef TArray<uint32> ShaderTokensVec;

// key tokens
enum EToken
{
	eT_unknown = 0,
	eT_include = 1,
	eT_define = 2,
	eT_define_2 = 3,
	eT_undefine = 4,
	eT_fetchinst = 5,
	eT_if = 6,
	eT_ifdef = 7,
	eT_ifndef = 8,
	eT_if_2 = 9,
	eT_ifdef_2 = 10,
	eT_ifndef_2 = 11,
	eT_elif = 12,
	eT_elif_2 = 13,
	eT_endif = 14,
	eT_else = 15,
	eT_or = 16,
	eT_and = 17,
	eT_warning = 18,
	eT_register_env = 19,
	eT_ifcvar = 20,
	eT_ifncvar = 21,
	eT_elifcvar = 22,
	eT_skip = 23,
	eT_skip_1 = 24,
	eT_skip_2 = 25,
	eT_br_rnd_1 = 26,
	eT_br_rnd_2 = 27,
	eT_br_sq_1 = 28,
	eT_br_sq_2 = 29,
	eT_br_cv_1 = 30,
	eT_br_cv_2 = 31,
	eT_br_tr_1 = 32,
	eT_br_tr_2 = 33,
	eT_comma = 34,
	eT_dot = 35,
	eT_colon = 36,
	eT_semicolumn = 37,
	eT_excl = 38,
	eT_quote = 39,
	eT_sing_quote = 40,
	eT_question = 41,
	eT_eq = 42,
	eT_plus = 43,
	eT_minus = 44,
	eT_div = 45,
	eT_mul = 46,
	eT_dot_math = 47,
	eT_mul_math = 48,
	eT_sqrt_math = 49,
	eT_exp_math = 50,
	eT_log_math = 51,
	eT_log2_math = 52,
	eT_sin_math = 53,
	eT_cos_math = 54,
	eT_sincos_math = 55,
	eT_floor_math = 56,
	eT_ceil_math = 57,
	eT_frac_math = 58,
	eT_lerp_math = 59,
	eT_abs_math = 60,
	eT_clamp_math = 61,
	eT_min_math = 62,
	eT_max_math = 63,
	eT_length_math = 64,
	eT_tex2D = 65,
	eT_tex2Dproj = 66,
	eT_tex3D = 67,
	eT_texCUBE = 68,
	eT_SamplerState = 69,
	eT_SamplerComparisonState = 70,
	eT_sampler_state = 71,
	eT_Texture2D = 72,
	eT_RWTexture2D = 73,
	eT_RWTexture2DArray = 74,
	eT_Texture2DArray = 75,
	eT_Texture2DMS = 76,
	eT_TextureCube = 77,
	eT_TextureCubeArray = 78,
	eT_Texture3D = 79,
	eT_RWTexture3D = 80,
	eT_snorm = 81,
	eT_unorm = 82,
	eT_float = 83,
	eT_float2 = 84,
	eT_float3 = 85,
	eT_float4 = 86,
	eT_float2x4 = 87,
	eT_float3x4 = 88,
	eT_float4x4 = 89,
	eT_float3x3 = 90,
	eT_half = 91,
	eT_half2 = 92,
	eT_half3 = 93,
	eT_half4 = 94,
	eT_half2x4 = 95,
	eT_half3x4 = 96,
	eT_half4x4 = 97,
	eT_half3x3 = 98,
	eT_bool = 99,
	eT_int = 100,
	eT_int2 = 101,
	eT_int3 = 102,
	eT_int4 = 103,
	eT_uint = 104,
	eT_uint2 = 105,
	eT_uint3 = 106,
	eT_uint4 = 107,
	eT_min16float = 108,
	eT_min16float2 = 109,
	eT_min16float3 = 110,
	eT_min16float4 = 111,
	eT_min16float4x4 = 112,
	eT_min16float3x4 = 113,
	eT_min16float2x4 = 114,
	eT_min16float3x3 = 115,
	eT_min10float = 116,
	eT_min10float2 = 117,
	eT_min10float3 = 118,
	eT_min10float4 = 119,
	eT_min10float4x4 = 120,
	eT_min10float3x4 = 121,
	eT_min10float2x4 = 122,
	eT_min10float3x3 = 123,
	eT_min16int = 124,
	eT_min16int2 = 125,
	eT_min16int3 = 126,
	eT_min16int4 = 127,
	eT_min12int = 128,
	eT_min12int2 = 129,
	eT_min12int3 = 130,
	eT_min12int4 = 131,
	eT_min16uint = 132,
	eT_min16uint2 = 133,
	eT_min16uint3 = 134,
	eT_min16uint4 = 135,
	eT_sampler1D = 136,
	eT_sampler2D = 137,
	eT_sampler3D = 138,
	eT_samplerCUBE = 139,
	eT_const = 140,
	eT_inout = 141,
	eT_struct = 142,
	eT_sampler = 143,
	eT_TEXCOORDN = 144,
	eT_TEXCOORD0 = 145,
	eT_TEXCOORD1 = 146,
	eT_TEXCOORD2 = 147,
	eT_TEXCOORD3 = 148,
	eT_TEXCOORD4 = 149,
	eT_TEXCOORD5 = 150,
	eT_TEXCOORD6 = 151,
	eT_TEXCOORD7 = 152,
	eT_TEXCOORD8 = 153,
	eT_TEXCOORD9 = 154,
	eT_TEXCOORD10 = 155,
	eT_TEXCOORD11 = 156,
	eT_TEXCOORD12 = 157,
	eT_TEXCOORD13 = 158,
	eT_TEXCOORD14 = 159,
	eT_TEXCOORD15 = 160,
	eT_TEXCOORD16 = 161,
	eT_TEXCOORD17 = 162,
	eT_TEXCOORD18 = 163,
	eT_TEXCOORD19 = 164,
	eT_TEXCOORD20 = 165,
	eT_TEXCOORD21 = 166,
	eT_TEXCOORD22 = 167,
	eT_TEXCOORD23 = 168,
	eT_TEXCOORD24 = 169,
	eT_TEXCOORD25 = 170,
	eT_TEXCOORD26 = 171,
	eT_TEXCOORD27 = 172,
	eT_TEXCOORD28 = 173,
	eT_TEXCOORD29 = 174,
	eT_TEXCOORD30 = 175,
	eT_TEXCOORD31 = 176,
	eT_TEXCOORDN_centroid = 177,
	eT_TEXCOORD0_centroid = 178,
	eT_TEXCOORD1_centroid = 179,
	eT_TEXCOORD2_centroid = 180,
	eT_TEXCOORD3_centroid = 181,
	eT_TEXCOORD4_centroid = 182,
	eT_TEXCOORD5_centroid = 183,
	eT_TEXCOORD6_centroid = 184,
	eT_TEXCOORD7_centroid = 185,
	eT_TEXCOORD8_centroid = 186,
	eT_TEXCOORD9_centroid = 187,
	eT_TEXCOORD10_centroid = 188,
	eT_TEXCOORD11_centroid = 189,
	eT_TEXCOORD12_centroid = 190,
	eT_TEXCOORD13_centroid = 191,
	eT_TEXCOORD14_centroid = 192,
	eT_TEXCOORD15_centroid = 193,
	eT_TEXCOORD16_centroid = 194,
	eT_TEXCOORD17_centroid = 195,
	eT_TEXCOORD18_centroid = 196,
	eT_TEXCOORD19_centroid = 197,
	eT_TEXCOORD20_centroid = 198,
	eT_TEXCOORD21_centroid = 199,
	eT_TEXCOORD22_centroid = 200,
	eT_TEXCOORD23_centroid = 201,
	eT_TEXCOORD24_centroid = 202,
	eT_TEXCOORD25_centroid = 203,
	eT_TEXCOORD26_centroid = 204,
	eT_TEXCOORD27_centroid = 205,
	eT_TEXCOORD28_centroid = 206,
	eT_TEXCOORD29_centroid = 207,
	eT_TEXCOORD30_centroid = 208,
	eT_TEXCOORD31_centroid = 209,
	eT_COLOR0 = 210,
	eT_static = 211,
	eT_shared = 212,
	eT_groupshared = 213,
	eT_packoffset = 214,
	eT_register = 215,
	eT_return = 216,
	eT_vsregister = 217,
	eT_psregister = 218,
	eT_gsregister = 219,
	eT_dsregister = 220,
	eT_hsregister = 221,
	eT_csregister = 222,
	eT_slot = 223,
	eT_vsslot = 224,
	eT_psslot = 225,
	eT_gsslot = 226,
	eT_dsslot = 227,
	eT_hsslot = 228,
	eT_csslot = 229,
	eT_StructuredBuffer = 230,
	eT_RWStructuredBuffer = 231,
	eT_ByteAddressBuffer = 232,
	eT_RWByteAddressBuffer = 233,
	eT_Buffer = 234,
	eT_RWBuffer = 235,
	eT_color = 236,
	eT_Position = 237,
	eT_STANDARDSGLOBAL = 238,
	eT_technique = 239,
	eT_string = 240,
	eT_UIName = 241,
	eT_UIDescription = 242,
	eT_UIWidget = 243,
	eT_UIWidget0 = 244,
	eT_UIWidget1 = 245,
	eT_UIWidget2 = 246,
	eT_UIWidget3 = 247,
	eT_Texture = 248,
	eT_Filter = 249,
	eT_MinFilter = 250,
	eT_MagFilter = 251,
	eT_MipFilter = 252,
	eT_AddressU = 253,
	eT_AddressV = 254,
	eT_AddressW = 255,
	eT_BorderColor = 256,
	eT_sRGBLookup = 257,
	eT_LINEAR = 258,
	eT_POINT = 259,
	eT_NONE = 260,
	eT_ANISOTROPIC = 261,
	eT_MIN_MAG_MIP_POINT = 262,
	eT_MIN_MAG_MIP_LINEAR = 263,
	eT_MIN_MAG_LINEAR_MIP_POINT = 264,
	eT_COMPARISON_MIN_MAG_LINEAR_MIP_POINT = 265,
	eT_MINIMUM_MIN_MAG_MIP_LINEAR = 266,
	eT_MAXIMUM_MIN_MAG_MIP_LINEAR = 267,
	eT_Clamp = 268,
	eT_Border = 269,
	eT_Wrap = 270,
	eT_Mirror = 271,
	eT_Script = 272,
	eT_comment = 273,
	eT_asm = 274,
	eT_PreProcess = 275,
	eT_PostProcess = 276,
	eT_PreDraw = 277,
	eT_Panorama = 278,
	eT_Refractive = 279,
	eT_ForceRefractionUpdate = 280,
	eT_FogColor = 281,
	eT_Color = 282,
	eT_Depth = 283,
	eT_pass = 284,
	eT_CustomRE = 285,
	eT_Style = 286,
	eT_VertexShader = 287,
	eT_PixelShader = 288,
	eT_GeometryShader = 289,
	eT_HullShader = 290,
	eT_DomainShader = 291,
	eT_ComputeShader = 292,
	eT_ZEnable = 293,
	eT_ZWriteEnable = 294,
	eT_CullMode = 295,
	eT_SrcBlend = 296,
	eT_DestBlend = 297,
	eT_AlphaBlendEnable = 298,
	eT_AlphaFunc = 299,
	eT_AlphaRef = 300,
	eT_ZFunc = 301,
	eT_ColorWriteEnable = 302,
	eT_IgnoreMaterialState = 303,
	eT_None = 304,
	eT_Disable = 305,
	eT_CCW = 306,
	eT_CW = 307,
	eT_Back = 308,
	eT_Front = 309,
	eT_Never = 310,
	eT_Less = 311,
	eT_Equal = 312,
	eT_LEqual = 313,
	eT_LessEqual = 314,
	eT_NotEqual = 315,
	eT_GEqual = 316,
	eT_GreaterEqual = 317,
	eT_Greater = 318,
	eT_Always = 319,
	eT_RED = 320,
	eT_GREEN = 321,
	eT_BLUE = 322,
	eT_ALPHA = 323,
	eT_ONE = 324,
	eT_ZERO = 325,
	eT_SRC_COLOR = 326,
	eT_SrcColor = 327,
	eT_ONE_MINUS_SRC_COLOR = 328,
	eT_InvSrcColor = 329,
	eT_SRC_ALPHA = 330,
	eT_SrcAlpha = 331,
	eT_ONE_MINUS_SRC_ALPHA = 332,
	eT_InvSrcAlpha = 333,
	eT_DST_ALPHA = 334,
	eT_DestAlpha = 335,
	eT_ONE_MINUS_DST_ALPHA = 336,
	eT_InvDestAlpha = 337,
	eT_DST_COLOR = 338,
	eT_DestColor = 339,
	eT_ONE_MINUS_DST_COLOR = 340,
	eT_InvDestColor = 341,
	eT_SRC_ALPHA_SATURATE = 342,
	eT_SRC1_COLOR = 343,
	eT_NULL = 344,
	eT_cbuffer = 345,
	eT_PER_BATCH = 346,
	eT_PER_INSTANCE = 347,
	eT_PER_FRAME = 348,
	eT_PER_MATERIAL = 349,
	eT_PER_LIGHT = 350,
	eT_PER_SHADOWGEN = 351,
	eT_SKIN_DATA = 352,
	eT_INSTANCE_DATA = 353,
	eT_ShaderType = 354,
	eT_ShaderDrawType = 355,
	eT_Public = 356,
	eT_NoPreview = 357,
	eT_LocalConstants = 358,
	eT_Cull = 359,
	eT_SupportsAttrInstancing = 360,
	eT_SupportsConstInstancing = 361,
	eT_SupportsDeferredShading = 362,
	eT_SupportsFullDeferredShading = 363,
	eT_Decal = 364,
	eT_DecalNoDepthOffset = 365,
	eT_NoChunkMerging = 366,
	eT_ForceTransPass = 367,
	eT_AfterHDRPostProcess = 368,
	eT_AfterPostProcess = 369,
	eT_ForceZpass = 370,
	eT_ForceWaterPass = 371,
	eT_ForceDrawLast = 372,
	eT_ForceDrawFirst = 373,
	eT_ForceDrawAfterWater = 374,
	eT_DepthFixup = 375,
	eT_SingleLightPass = 376,
	eT_HWTessellation = 377,
	eT_WaterParticle = 378,
	eT_AlphaBlendShadows = 379,
	eT_ZPrePass = 380,
	eT_Light = 381,
	eT_Shadow = 382,
	eT_General = 383,
	eT_Terrain = 384,
	eT_NoDraw = 385,
	eT_Custom = 386,
	eT_Sky = 387,
	eT_Hair = 388,
	eT_Compute = 389,
	eT_ForceGeneralPass = 390,
	eT_SkinPass = 391,
	eT_EyeOverlay = 392,
	eT_Metal = 393,
	eT_Ice = 394,
	eT_Water = 395,
	eT_FX = 396,
	eT_HDR = 397,
	eT_Glass = 398,
	eT_Vegetation = 399,
	eT_Particle = 400,
	eT_NoLights = 401,
	eT_NoMaterialState = 402,
	eT_PositionInvariant = 403,
	eT_TechniqueZ = 404,
	eT_TechniqueShadowGen = 405,
	eT_TechniqueCustomRender = 406,
	eT_TechniqueDebug = 407,
	eT_TechniqueWaterRefl = 408,
	eT_TechniqueWaterCaustic = 409,
	eT_TechniqueZPrepass = 410,
	eT_TechniqueArkSceneMaskGen = 411,
	eT_TechniqueMax = 412,
	eT_KeyFrameParams = 413,
	eT_KeyFrameRandColor = 414,
	eT_KeyFrameRandIntensity = 415,
	eT_KeyFrameRandSpecMult = 416,
	eT_KeyFrameRandPosOffset = 417,
	eT_Speed = 418,
	eT_Beam = 419,
	eT_LensOptics = 420,
	eT_Ocean = 421,
	eT_Model = 422,
	eT_StartRadius = 423,
	eT_EndRadius = 424,
	eT_StartColor = 425,
	eT_EndColor = 426,
	eT_LightStyle = 427,
	eT_Length = 428,
	eT_RGBStyle = 429,
	eT_Blind = 430,
	eT_SizeBlindScale = 431,
	eT_SizeBlindBias = 432,
	eT_IntensBlindScale = 433,
	eT_IntensBlindBias = 434,
	eT_MinLight = 435,
	eT_DistFactor = 436,
	eT_DistIntensityFactor = 437,
	eT_FadeTime = 438,
	eT_Layer = 439,
	eT_Importance = 440,
	eT_VisAreaScale = 441,
	eT_Poly = 442,
	eT_Identity = 443,
	eT_FromObj = 444,
	eT_FromLight = 445,
	eT_Fixed = 446,
	eT_Gravity = 447,
	eT_WindDirection = 448,
	eT_WindSpeed = 449,
	eT_WaveHeight = 450,
	eT_DirectionalDependence = 451,
	eT_ChoppyWaveFactor = 452,
	eT_SuppressSmallWavesFactor = 453,
	eT__TT_TEXCOORD_MATRIX = 454,
	eT__TT_TEXCOORD_PROJ = 455,
	eT__VT_TYPE = 456,
	eT__VT_TYPE_MODIF = 457,
	eT__VT_BEND = 458,
	eT__VT_DET_BEND = 459,
	eT__VT_GRASS = 460,
	eT__VT_WIND = 461,
	eT__VT_DEPTH_OFFSET = 462,
	eT__FT_TEXTURE = 463,
	eT__FT_TEXTURE1 = 464,
	eT__FT_NORMAL = 465,
	eT__FT_PSIZE = 466,
	eT__FT_DIFFUSE = 467,
	eT__FT_SPECULAR = 468,
	eT__FT_TANGENT_STREAM = 469,
	eT__FT_QTANGENT_STREAM = 470,
	eT__FT_SKIN_STREAM = 471,
	eT__FT_VERTEX_VELOCITY_STREAM = 472,
	eT__FT0_COP = 473,
	eT__FT0_AOP = 474,
	eT__FT0_CARG1 = 475,
	eT__FT0_CARG2 = 476,
	eT__FT0_AARG1 = 477,
	eT__FT0_AARG2 = 478,
	eT__VS = 479,
	eT__PS = 480,
	eT__GS = 481,
	eT__HS = 482,
	eT__DS = 483,
	eT__CS = 484,
	eT__g_SkinQuat = 485,
	eT_x = 486,
	eT_y = 487,
	eT_z = 488,
	eT_w = 489,
	eT_r = 490,
	eT_g = 491,
	eT_b = 492,
	eT_a = 493,
	eT_true = 494,
	eT_false = 495,
	eT_0 = 496,
	eT_1 = 497,
	eT_2 = 498,
	eT_3 = 499,
	eT_4 = 500,
	eT_5 = 501,
	eT_6 = 502,
	eT_7 = 503,
	eT_8 = 504,
	eT_9 = 505,
	eT_10 = 506,
	eT_11 = 507,
	eT_12 = 508,
	eT_13 = 509,
	eT_14 = 510,
	eT_15 = 511,
	eT_AnisotropyLevel = 512,
	eT_ORBIS = 513,
	eT_DURANGO = 514,
	eT_PCDX11 = 515,
	eT_OPENGL = 516,
	eT_VT_DetailBendingGrass = 517,
	eT_VT_DetailBending = 518,
	eT_VT_WindBending = 519,
	eT_VertexColors = 520,
	eT_s0 = 521,
	eT_s1 = 522,
	eT_s2 = 523,
	eT_s3 = 524,
	eT_s4 = 525,
	eT_s5 = 526,
	eT_s6 = 527,
	eT_s7 = 528,
	eT_s8 = 529,
	eT_s9 = 530,
	eT_s10 = 531,
	eT_s11 = 532,
	eT_s12 = 533,
	eT_s13 = 534,
	eT_s14 = 535,
	eT_s15 = 536,
	eT_t0 = 537,
	eT_t1 = 538,
	eT_t2 = 539,
	eT_t3 = 540,
	eT_t4 = 541,
	eT_t5 = 542,
	eT_t6 = 543,
	eT_t7 = 544,
	eT_t8 = 545,
	eT_t9 = 546,
	eT_t10 = 547,
	eT_t11 = 548,
	eT_t12 = 549,
	eT_t13 = 550,
	eT_t14 = 551,
	eT_t15 = 552,
	eT_Global = 553,
	eT_Load = 554,
	eT_Sample = 555,
	eT_Gather = 556,
	eT_GatherRed = 557,
	eT_GatherGreen = 558,
	eT_GatherBlue = 559,
	eT_GatherAlpha = 560,
	eT_max = 561,
	eT_user_first = 562,
};

enum ETokenStorageClass
{
	eTS_invalid = 0,
	eTS_default,
	eTS_static,
	eTS_const,
	eTS_shared,
	eTS_groupshared
};

struct SFXTokenBin
{
	uint32 id;
};

#define FX_BEGIN_TOKENS \
  static SFXTokenBin sCommands[] = {

#define FX_END_TOKENS \
  { eT_unknown }      \
  };

#define FX_TOKEN(id) \
  { Parser.fxTokenKey( # id, eT_ ## id) },

#define FX_REGISTER_TOKEN(id) fxTokenKey( # id, eT_ ## id);

extern char* g_KeyTokens[];

struct SMacroBinFX
{
	std::vector<uint32> m_Macro;
	uint64 m_nMask;
};

class CParserBin;

typedef std::map<uint32, SMacroBinFX> FXMacroBin;
typedef FXMacroBin::iterator          FXMacroBinItor;

struct SParserFrame
{
	uint32 m_nFirstToken;
	uint32 m_nLastToken;
	uint32 m_nCurToken;
	SParserFrame(uint32 nFirstToken, uint32 nLastToken)
	{
		m_nFirstToken = nFirstToken;
		m_nLastToken = nLastToken;
		m_nCurToken = m_nFirstToken;
	}
	SParserFrame()
	{
		m_nFirstToken = 0;
		m_nLastToken = 0;
		m_nCurToken = m_nFirstToken;
	}
	inline void Reset()
	{
		m_nFirstToken = 0;
		m_nLastToken = 0;
		m_nCurToken = m_nFirstToken;
	}
	inline bool IsEmpty() const
	{
		if (!m_nFirstToken && !m_nLastToken)
			return true;
		return (m_nLastToken < m_nFirstToken);
	}
};

enum EFragmentType
{
	eFT_Unknown,
	eFT_Function,
	eFT_Structure,
	eFT_Sampler,
	eFT_ConstBuffer,
	eFT_StorageClass
};

struct SCodeFragment
{
	uint32 m_nFirstToken;
	uint32 m_nLastToken;
	uint32 m_dwName;
	EFragmentType m_eType;
#ifdef _DEBUG
	//string m_Name;
#endif
	SCodeFragment()
	{
		m_nFirstToken = 0;
		m_nLastToken = 0;
		m_dwName = 0;
		m_eType = eFT_Unknown;
	}
};

struct SortByToken
{
	bool operator()(const STokenD& left, const STokenD& right) const
	{
		return left.Token < right.Token;
	}
	bool operator()(const uint32 left, const STokenD& right) const
	{
		return left < right.Token;
	}
	bool operator()(const STokenD& left, uint32 right) const
	{
		return left.Token < right;
	}
};

#define SF_GLES3    0x08000000
#define SF_D3D11    0x10000000
#define SF_ORBIS    0x20000000
#define SF_DURANGO  0x40000000
#define SF_GL4      0x80000000
#define SF_PLATFORM 0xf8000000

class CParserBin
{
	friend class CShaderManBin;
	friend class CHWShader_D3D;
	friend struct SFXParam;
	friend struct SFXSampler;
	friend struct SFXTexture;
	friend class CREBeam;
	friend class CRECloud;

	//bool m_bEmbeddedSearchInfo;
	struct SShaderBin* m_pCurBinShader;
	CShader* m_pCurShader;
	TArray<uint32> m_Tokens;
	FXMacroBin m_Macros[2];
	FXShaderToken m_TokenTable;
	TArray<uint64> m_IfAffectMask;
	//std::vector<std::vector<int>> m_KeyOffsets;
	EToken m_eToken;
	uint32 m_nFirstToken;
	TArray<SCodeFragment> m_CodeFragments;
	//std::vector<SFXParam> m_Parameters;
	//std::vector<STexSamplerFX> m_Samplers;

	SParserFrame m_CurFrame;

	SParserFrame m_Name;
	SParserFrame m_Assign;
	SParserFrame m_Annotations;
	SParserFrame m_Value;
	SParserFrame m_Data;

	static FXMacroBin m_StaticMacros;

public:
	CParserBin(SShaderBin* pBin);
	CParserBin(SShaderBin* pBin, CShader* pSH);

	static FXMacroBin&        GetStaticMacroses() { return m_StaticMacros; }
	static const char*        GetString(uint32 nToken, FXShaderToken& Table, bool bOnlyKey = false);
	const char*               GetString(uint32 nToken, bool bOnlyKey = false);
	string                    GetString(SParserFrame& Frame);
	CCryNameR                 GetNameString(SParserFrame& Frame);
	void                      BuildSearchInfo();
	bool                      PreprocessTokens(ShaderTokensVec& Tokens, int nPass, PodArray<uint32>& tokensBuffer);
	bool                      Preprocess(int nPass, ShaderTokensVec& Tokens, FXShaderToken* pSrcTable);
	static const SMacroBinFX* FindMacro(uint32 dwName, FXMacroBin& Macro);
	static bool               AddMacro(uint32 dwToken, const uint32* pMacro, int nMacroTokens, uint64 nMask, FXMacroBin& Macro);
	static bool               RemoveMacro(uint32 dwToken, FXMacroBin& Macro);
	static void               CleanPlatformMacros();
	uint32                    NewUserToken(uint32 nToken, const char* psToken, bool bUseFinalTable);
	//uint32 NewUserToken(uint32 nToken, const string& sToken, bool bUseFinalTable);
	void                      MergeTable(SShaderBin* pBin);
	bool                      CheckIfExpression(const uint32* pTokens, uint32& nT, int nPass, uint64* nMask = 0);
	bool                      IgnorePreprocessBlock(const uint32* pTokens, uint32& nT, int nMaxTokens, PodArray<uint32>& tokensBuffer, int nPass);
	static bool               CorrectScript(uint32* pTokens, uint32& i, uint32 nT, TArray<char>& Text);
	static bool               ConvertToAscii(uint32* pTokens, uint32 nT, FXShaderToken& Table, TArray<char>& Text, bool bInclSkipTokens = false);
	bool                      GetBool(SParserFrame& Frame);
	inline uint32*            GetTokens(int nStart) { return &m_Tokens[nStart]; }
	inline int                GetNumTokens()        { return m_Tokens.size(); }
	inline EToken             GetToken()            { return m_eToken; }
	inline EToken             GetToken(SParserFrame& Frame)
	{
		assert(!Frame.IsEmpty());
		return (EToken)m_Tokens[Frame.m_nFirstToken];
	}
	inline uint32 FirstToken() { return m_nFirstToken; }
	inline int    GetInt(uint32 nToken)
	{
		const char* szStr = GetString(nToken);
		if (szStr[0] == '0' && szStr[1] == 'x')
		{
			int i = 0;
			int res = sscanf(&szStr[2], "%x", &i);
			assert(res != 0);
			return i;
		}
		return atoi(szStr);
	}
	inline float GetFloat(SParserFrame& Frame)
	{
		return (float)atof(GetString(Frame).c_str());
	}
	static inline uint32 NextToken(const uint32* pTokens, uint32& nCur, uint32 nLast)
	{
		while (nCur <= nLast)
		{
			uint32 nToken = pTokens[nCur++];
			if (nToken == eT_skip)
			{
				nCur++;
				continue;
			}
			if (nToken == eT_skip_1)
			{
				while (nCur <= nLast)
				{
					nToken = pTokens[nCur++];
					if (nToken == eT_skip_2)
						break;
				}
				continue;
			}
			return nToken;
		}
		return 0;
	}

	SParserFrame       BeginFrame(SParserFrame& Frame);
	void               EndFrame(SParserFrame& Frame);

	byte               GetCompareFunc(EToken eT);
	int                GetSrcBlend(EToken eT);
	int                GetDstBlend(EToken eT);

	void               InsertSkipTokens(const uint32* pTokens, uint32 nStart, uint32 nTokens, bool bSingle, PodArray<uint32>& tokensBuffer);
	ETokenStorageClass ParseObject(SFXTokenBin* pTokens, int& nIndex);
	ETokenStorageClass ParseObject(SFXTokenBin* pTokens);
	int                GetNextToken(uint32& nStart, ETokenStorageClass& nTokenStorageClass);
	bool               FXGetAssignmentData(SParserFrame& Frame);
	bool               FXGetAssignmentData2(SParserFrame& Frame);
	bool               GetAssignmentData(SParserFrame& Frame);
	bool               GetSubData(SParserFrame& Frame, EToken eT1, EToken eT2);
	static int32       FindToken(uint32 nStart, uint32 nLast, const uint32* pTokens, uint32 nToken);
	int32              FindToken(uint32 nStart, uint32 nLast, uint32 nToken);
	int32              FindToken(uint32 nStart, uint32 nLast, const uint32* pTokens);
	int                CopyTokens(SParserFrame& Fragment, std::vector<uint32>& NewTokens);
	int                CopyTokens(SCodeFragment* pCF, PodArray<uint32>& SHData, TArray<SCodeFragment>& Replaces, TArray<uint32>& NewTokens, uint32 nID);
	static inline void AddDefineToken(uint32 dwToken, ShaderTokensVec& Tokens)
	{
		if (dwToken == 611)
		{
			int nnn = 0;
		}
		Tokens.push_back(eT_define);
		Tokens.push_back(dwToken);
		Tokens.push_back(0);
	}
	static inline void AddDefineToken(uint32 dwToken, uint32 dwToken2, ShaderTokensVec& Tokens)
	{
		if (dwToken == 611)
		{
			int nnn = 0;
		}
		Tokens.push_back(eT_define);
		Tokens.push_back(dwToken);
		Tokens.push_back(dwToken2);
		Tokens.push_back(0);
	}
	bool                 JumpSemicolumn(uint32& nStart, uint32 nEnd);

	static uint32        fxToken(const char* szToken, bool* bKey = NULL);
	static uint32        fxTokenKey(char* szToken, EToken eT = eT_unknown);
	static uint32        GetCRC32(const char* szStr);
	static uint32        NextToken(char*& buf, char* com, bool& bKey);
	static void          Init();
	static void          RemovePlatformDefines();
	static void          SetupForOrbis();
	static void          SetupForD3D9();
	static void          SetupForD3D11();
	static void          SetupForGL4();
	static void          SetupForGLES3();
	static void          SetupForDurango();
	static void          SetupFeatureDefines();
	static CCryNameTSCRC GetPlatformSpecName(CCryNameTSCRC orgName);
	static const char*   GetPlatformShaderlistName();
	static bool          PlatformSupportsConstantBuffers() { return (CParserBin::m_nPlatform == SF_D3D11 || CParserBin::m_nPlatform == SF_ORBIS || CParserBin::m_nPlatform == SF_DURANGO || CParserBin::m_nPlatform == SF_GL4 || CParserBin::m_nPlatform == SF_GLES3); };
	static bool          PlatformSupportsGeometryShaders() { return (CParserBin::m_nPlatform == SF_D3D11 || CParserBin::m_nPlatform == SF_ORBIS || CParserBin::m_nPlatform == SF_DURANGO || CParserBin::m_nPlatform == SF_GL4); }
	static bool          PlatformSupportsHullShaders()     { return (CParserBin::m_nPlatform == SF_D3D11 || CParserBin::m_nPlatform == SF_ORBIS || CParserBin::m_nPlatform == SF_DURANGO || CParserBin::m_nPlatform == SF_GL4); }
	static bool          PlatformSupportsDomainShaders()   { return (CParserBin::m_nPlatform == SF_D3D11 || CParserBin::m_nPlatform == SF_ORBIS || CParserBin::m_nPlatform == SF_DURANGO || CParserBin::m_nPlatform == SF_GL4); }
	static bool          PlatformSupportsComputeShaders()  { return (CParserBin::m_nPlatform == SF_D3D11 || CParserBin::m_nPlatform == SF_ORBIS || CParserBin::m_nPlatform == SF_DURANGO || CParserBin::m_nPlatform == SF_GL4); }
	static bool          PlatformIsConsole()               { return (CParserBin::m_nPlatform == SF_ORBIS || CParserBin::m_nPlatform == SF_DURANGO); };

	static bool m_bEditable;
	static uint32 m_nPlatform;
	static bool m_bEndians;
	static bool m_bParseFX;
	static bool m_bShaderCacheGen;
};

char* fxFillPr(char** buf, char* dst);

#endif
