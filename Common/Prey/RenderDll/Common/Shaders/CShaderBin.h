// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef __CSHADERBIN_H__
#define __CSHADERBIN_H__

#include <map>
#include <Prey/CryMemory/CrySizer.h>
#include "ParserBin.h"
#include "Shader.h"

#ifndef FOURCC
typedef DWORD FOURCC;
#endif

struct SShaderTechParseParams
{
	CCryNameR techName[TTYPE_MAX];
};

class CShaderMan;

struct SShaderBinHeader
{
	FOURCC m_Magic;
	uint32 m_CRC32;
	uint16 m_VersionLow;
	uint16 m_VersionHigh;
	uint32 m_nOffsetStringTable;
	uint32 m_nOffsetParamsLocal;
	uint32 m_nTokens;
	uint32 m_nSourceCRC32;

	//AUTO_STRUCT_INFO;
};

struct SShaderBinParamsHeader
{
	uint64 nMask;
	uint32 nName;
	int32  nParams;
	int32  nSamplers;
	int32  nTextures;
	int32  nFuncs;

	AUTO_STRUCT_INFO;
};

struct SParamCacheInfo
{
	typedef std::vector<int32, STLShaderAllocator<int32>> AffectedFuncsVec;
	typedef std::vector<int32, STLShaderAllocator<int32>> AffectedParamsVec;

	uint32            m_dwName;
	uint64            m_nMaskGenFX;
	AffectedFuncsVec  m_AffectedFuncs;
	AffectedParamsVec m_AffectedParams;
	AffectedParamsVec m_AffectedSamplers;
	AffectedParamsVec m_AffectedTextures;

	SParamCacheInfo() : m_dwName(0), m_nMaskGenFX(0) {};

	int Size()
	{
		return sizeof(SParamCacheInfo) + sizeofVector(m_AffectedFuncs) + sizeofVector(m_AffectedParams) + sizeofVector(m_AffectedSamplers) + sizeofVector(m_AffectedTextures);
	}

	void GetMemoryUsage(ICrySizer* pSizer) const
	{
		pSizer->AddObject(m_AffectedFuncs);
		pSizer->AddObject(m_AffectedParams);
		pSizer->AddObject(m_AffectedSamplers);
		pSizer->AddObject(m_AffectedTextures);
	}
};

#define MAX_FXBIN_CACHE 32

struct SShaderBin
{
	typedef std::vector<SParamCacheInfo, STLShaderAllocator<SParamCacheInfo>> ParamsCacheVec;
	static inline auto s_Root = PreyGlobal<SShaderBin>(0x2271EA0);
	static inline auto s_nCache = PreyGlobal<unsigned>(0x2BA7454);
	static inline auto s_nMaxFXBinCache = PreyGlobal<unsigned>(0x2271E70);

	SShaderBin*       m_Next;
	SShaderBin*       m_Prev;

	uint32            m_CRC32;
	uint32            m_dwName;
	char*             m_szName;
	uint32            m_SourceCRC32;
	bool              m_bLocked;
	bool              m_bReadOnly;
	bool              m_bInclude;
	FXShaderToken     m_TokenTable;
	ShaderTokensVec   m_Tokens;

	// Local shader info (after parsing)
	uint32         m_nOffsetLocalInfo;
	uint32         m_nCurCacheParamsID;
	uint32         m_nCurParamsID;
	ParamsCacheVec m_ParamsCache;

	SShaderBin()
		: m_Next(nullptr)
		, m_Prev(nullptr)
		, m_CRC32(0)
		, m_dwName(0)
		, m_szName("")
		, m_SourceCRC32(0)
		, m_bLocked(false)
		, m_bReadOnly(true)
		, m_bInclude(false)
		, m_nOffsetLocalInfo(0)
		, m_nCurCacheParamsID(-1)
		, m_nCurParamsID(-1)
	{
		if (!s_Root->m_Next)
		{
			s_Root->m_Next = s_Root.Get();
			s_Root->m_Prev = s_Root.Get();
		}
	}

	~SShaderBin()
	{
		if (m_szName[0])
			g_shaderBucketAllocator.deallocate((void*) m_szName);
	}

	void SetName(const char* name)
	{
		if (m_szName[0])
		{
			g_shaderBucketAllocator.deallocate((void*) m_szName);
			m_szName = "";
		}

		if (name[0])
		{
			m_szName = (char*) g_shaderBucketAllocator.allocate(strlen(name) + 1);
			strcpy(m_szName, name);
		}
	}

	inline void Unlink()
	{
		if (!m_Next || !m_Prev)
			return;
		m_Next->m_Prev = m_Prev;
		m_Prev->m_Next = m_Next;
		m_Next = m_Prev = NULL;
	}
	inline void Link(SShaderBin* Before)
	{
		if (m_Next || m_Prev)
			return;
		m_Next = Before->m_Next;
		Before->m_Next->m_Prev = this;
		Before->m_Next = this;
		m_Prev = Before;
	}
	inline bool IsReadOnly() { return m_bReadOnly; }
	inline void Lock()       { m_bLocked = true; }
	inline void Unlock()     { m_bLocked = false; }

	uint32 ComputeCRC() { return FComputeCRC(this); }
	void        SetCRC(uint32 nCRC) { m_CRC32 = nCRC; }

	void        CryptData();

	int         Size()
	{
		int nSize = sizeof(SShaderBin);
		nSize += sizeOfV(m_TokenTable);
		nSize += sizeofVector(m_Tokens);
		nSize += sizeOfV(m_ParamsCache);

		return nSize;
	}

	void GetMemoryUsage(ICrySizer* pSizer) const
	{
		//pSizer->AddObject(m_TokenTable);
		//pSizer->AddObject(m_Tokens);
		//pSizer->AddObject(m_ParamsCache);
	}

	void* operator new(size_t sz)
	{
		return g_shaderBucketAllocator.allocate(sz);
	}

	void operator delete(void* p)
	{
		g_shaderBucketAllocator.deallocate(p);
	}

	static inline auto FComputeCRC = PreyFunction<unsigned(SShaderBin* const _this)>(0x1028E30);

private:
	SShaderBin(const SShaderBin&);
	SShaderBin& operator=(const SShaderBin&);
};

#define FXP_PARAMS_DIRTY   1
#define FXP_SAMPLERS_DIRTY 2
#define FXP_TEXTURES_DIRTY 4

typedef std::vector<SFXParam>::iterator      FXParamsIt;
typedef std::vector<STexSamplerFX>::iterator FXSamplersOldIt;
typedef std::vector<SFXSampler>::iterator    FXSamplersIt;
typedef std::vector<SFXTexture>::iterator    FXTexturesIt;
struct SShaderFXParams
{
	uint32                     m_nFlags; // FXP_DIRTY

	std::vector<SFXParam>      m_FXParams;
	std::vector<SFXSampler>    m_FXSamplers;
	std::vector<SFXTexture>    m_FXTextures;

	std::vector<STexSamplerFX> m_FXSamplersOld;
	DynArray<SShaderParam>     m_PublicParams;

	SShaderFXParams()
	{
		m_nFlags = 0;
	}
	int Size()
	{
		int nSize = sizeOfV(m_FXParams);
		nSize += sizeOfV(m_FXSamplers);
		nSize += sizeOfV(m_FXSamplers);

		nSize += sizeOfV(m_FXSamplersOld);
		nSize += sizeOfV(m_PublicParams);

		return nSize;
	}
};

typedef std::map<uint32, bool>          FXShaderBinValidCRC;
typedef FXShaderBinValidCRC::iterator   FXShaderBinValidCRCItor;

typedef std::map<CCryNameTSCRC, string> FXShaderBinPath;
typedef FXShaderBinPath::iterator       FXShaderBinPathItor;

class CShaderManBin
{
public:
	friend class CShaderMan;

	CShaderMan* m_pCEF;
	FXShaderBinPath     m_BinPaths;
	FXShaderBinValidCRC m_BinValidCRCs;

	bool                m_bBinaryShadersLoaded;

	typedef std::map<CCryNameTSCRC, SShaderFXParams> ShaderFXParams;
	typedef ShaderFXParams::iterator                 ShaderFXParamsItor;
	ShaderFXParams m_ShaderFXParams;

	SShaderBin* LoadBinShader(_iobuf* fpBin, const char* szName, const char* szNameBin, bool bReadParams) { return FLoadBinShader(this, fpBin, szName, szNameBin, bReadParams); }
	bool SaveBinShaderLocalInfo(SShaderBin* pBin, unsigned dwName, uint64_t nMaskGenFX, TArray<int>& Funcs, std::vector<SFXParam>& Params, std::vector<SFXSampler>& Samplers, std::vector<SFXTexture>& Textures) { return FSaveBinShaderLocalInfo(this, pBin, dwName, nMaskGenFX, Funcs, Params, Samplers, Textures); }
	SParamCacheInfo* GetParamInfo(SShaderBin* pBin, unsigned dwName, uint64_t nMaskGenFX) { return FGetParamInfo(this, pBin, dwName, nMaskGenFX); }
	bool ParseBinFX_Global_Annotations(CParserBin& Parser, SParserFrame& Frame, bool* bPublic, CCryNameR* techStart) { return FParseBinFX_Global_Annotations(this, Parser, Frame, bPublic, techStart); }
	bool ParseBinFX_Sampler(CParserBin& Parser, SParserFrame& Frame, unsigned dwName, EToken samplerType) { return FParseBinFX_SamplerOv1(this, Parser, Frame, dwName, samplerType); }
	bool ParseBinFX_Sampler(CParserBin& Parser, SParserFrame& Frame, SFXSampler& Sampl) { return FParseBinFX_SamplerOv0(this, Parser, Frame, Sampl); }
	bool ParseBinFX_Texture(CParserBin& Parser, SParserFrame& Frame, SFXTexture& Tex) { return FParseBinFX_Texture(this, Parser, Frame, Tex); }
	void InitShaderDependenciesList(CParserBin& Parser, SCodeFragment* pFunc, TArray<unsigned char>& bChecked, TArray<int>& AffectedFunc) { FInitShaderDependenciesList(this, Parser, pFunc, bChecked, AffectedFunc); }
	void CheckFragmentsDependencies(CParserBin& Parser, TArray<unsigned char>& bChecked, TArray<int>& AffectedFrags) { FCheckFragmentsDependencies(this, Parser, bChecked, AffectedFrags); }
	void CheckStructuresDependencies(CParserBin& Parser, SCodeFragment* pFrag, TArray<unsigned char>& bChecked, TArray<int>& AffectedFunc) { FCheckStructuresDependencies(this, Parser, pFrag, bChecked, AffectedFunc); }
	void AddParameterToScript(CParserBin& Parser, SFXParam* pr, PodArray<unsigned int, 0>& SHData, EHWShaderClass eSHClass, int nCB) { FAddParameterToScript(this, Parser, pr, SHData, eSHClass, nCB); }
	void AddSamplerToScript(CParserBin& Parser, SFXSampler* pr, PodArray<unsigned int, 0>& SHData, EHWShaderClass eSHClass) { FAddSamplerToScript(this, Parser, pr, SHData, eSHClass); }
	void AddTextureToScript(CParserBin& Parser, SFXTexture* pr, PodArray<unsigned int, 0>& SHData, EHWShaderClass eSHClass) { FAddTextureToScript(this, Parser, pr, SHData, eSHClass); }
	bool ParseBinFX_Technique_Pass_PackParameters(CParserBin& Parser, std::vector<SFXParam>& AffectedParams, TArray<int>& AffectedFunc, SCodeFragment* pFunc, EHWShaderClass eSHClass, unsigned dwSHName, std::vector<SFXParam>& PackedParams, TArray<SCodeFragment>& Replaces, TArray<unsigned int>& NewTokens, TArray<unsigned char>& bMerged) { return FParseBinFX_Technique_Pass_PackParameters(this, Parser, AffectedParams, AffectedFunc, pFunc, eSHClass, dwSHName, PackedParams, Replaces, NewTokens, bMerged); }
	bool ParseBinFX_Technique_Pass_GenerateShaderData(CParserBin& Parser, std::map<unsigned int, SMacroBinFX, std::less<unsigned int>>& Macros, SShaderFXParams& FXParams, unsigned dwSHName, EHWShaderClass eSHClass, uint64_t& nAffectMask, unsigned dwSHType, PodArray<unsigned int, 0>& SHData, SShaderTechnique* pShTech) { return FParseBinFX_Technique_Pass_GenerateShaderData(this, Parser, Macros, FXParams, dwSHName, eSHClass, nAffectMask, dwSHType, SHData, pShTech); }
	bool ParseBinFX_Technique_Pass_LoadShader(CParserBin& Parser, std::map<unsigned int, SMacroBinFX, std::less<unsigned int>>& Macros, SParserFrame& SHFrame, SShaderTechnique* pShTech, SShaderPass* pPass, EHWShaderClass eSHClass, SShaderFXParams& FXParams) { return FParseBinFX_Technique_Pass_LoadShader(this, Parser, Macros, SHFrame, pShTech, pPass, eSHClass, FXParams); }
	bool ParseBinFX_Technique_Pass(CParserBin& Parser, SParserFrame& Frame, SShaderTechnique* pShTech) { return FParseBinFX_Technique_Pass(this, Parser, Frame, pShTech); }
	bool ParseBinFX_Technique_Annotations_String(CParserBin& Parser, SParserFrame& Frame, SShaderTechnique* pShTech, std::vector<SShaderTechParseParams>& techParams, bool* bPublic) { return FParseBinFX_Technique_Annotations_String(this, Parser, Frame, pShTech, techParams, bPublic); }
	SShaderTechnique* ParseBinFX_Technique(CParserBin& Parser, SParserFrame& Frame, SParserFrame Annotations, std::vector<SShaderTechParseParams>& techParams, bool* bPublic) { return FParseBinFX_Technique(this, Parser, Frame, Annotations, techParams, bPublic); }
	bool ParseBinFX_LightStyle_Val(CParserBin& Parser, SParserFrame& Frame, CLightStyle* ls) { return FParseBinFX_LightStyle_Val(this, Parser, Frame, ls); }
	bool ParseBinFX_LightStyle(CParserBin& Parser, SParserFrame& Frame, int nStyle) { return FParseBinFX_LightStyle(this, Parser, Frame, nStyle); }
	SShaderTexSlots* GetTextureSlots(CParserBin& Parser, SShaderBin* pBin, CShader* ef, int nTech, int nPass) { return FGetTextureSlots(this, Parser, pBin, ef, nTech, nPass); }
	bool DeleteFromCache(SShaderBin* pSB) { return FDeleteFromCache(this, pSB); }
	SFXParam* mfAddFXParam(SShaderFXParams& FXP, SFXParam const* pParam) { return FmfAddFXParamOv1(this, FXP, pParam); }
	void mfGeneratePublicFXParams(CShader* pSH, CParserBin& Parser) { FmfGeneratePublicFXParams(this, pSH, Parser); }
	CShaderManBin();
	SShaderBin* GetBinShader(const char* szName, bool bInclude, unsigned nRefCRC, bool* pbChanged = nullptr) { return FGetBinShader(this, szName, bInclude, nRefCRC, pbChanged); }
	bool ParseBinFX(SShaderBin* pBin, CShader* ef, uint64_t nMaskGen) { return FParseBinFX(this, pBin, ef, nMaskGen); }
	SShaderFXParams& mfGetFXParams(CShader* pSH) { return FmfGetFXParams(this, pSH); }
	void mfRemoveFXParams(CShader* pSH) { FmfRemoveFXParams(this, pSH); }
	void mfReleaseFXParams() { FmfReleaseFXParams(this); }
	void InvalidateCache(bool bIncludesOnly) { FInvalidateCache(this, bIncludesOnly); }
	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }

#if 0
	bool ParseBinFX_Technique_Annotations(CParserBin& arg0, SParserFrame& arg1, SShaderTechnique* arg2, std::vector<SShaderTechParseParams>& arg3, bool* arg4);
	bool ParseBinFX_Technique_CustomRE(CParserBin& arg0, SParserFrame& arg1, SParserFrame& arg2, SShaderTechnique* arg3);
	void MergeTextureSlots(SShaderTexSlots* arg0, SShaderTexSlots* arg1);
	bool ParseBinFX_Dummy(SShaderBin* arg0, std::vector<string>& arg1, const char* arg2);
	void AddGenMacros(SShaderGen* arg0, CParserBin& arg1, uint64_t arg2);
	int Size();
	int mfSizeFXParams(unsigned& arg0);
	SFXParam* mfAddFXParam(CShader* arg0, SFXParam const* arg1);
	void mfAddFXSampler(CShader* arg0, SFXSampler const* arg1);
	void mfAddFXSampler(CShader* arg0, STexSamplerFX const* arg1);
	void mfAddFXTexture(CShader* arg0, SFXTexture const* arg1);
	bool AddToCache(SShaderBin* arg0, bool arg1);
	void              AddGenMacroses(SShaderGen* shG, CParserBin& Parser, uint64 nMaskGen);
	bool ParseBinFX_Global(CParserBin& arg0, SParserFrame& arg1, bool* arg2, CCryNameR* arg3);
	void AddAffectedParameter(CParserBin& arg0, std::vector<SFXParam>& arg1, TArray<int>& arg2, SFXParam* arg3, EHWShaderClass arg4, unsigned arg5, SShaderTechnique* arg6);
	void AddAffectedSampler(CParserBin& arg0, std::vector<SFXSampler>& arg1, TArray<int>& arg2, SFXSampler* arg3, EHWShaderClass arg4, unsigned arg5, SShaderTechnique* arg6);
	void AddAffectedTexture(CParserBin& arg0, std::vector<SFXTexture>& arg1, TArray<int>& arg2, SFXTexture* arg3, EHWShaderClass arg4, unsigned arg5, SShaderTechnique* arg6);
#endif

#ifdef RENDERDLL_SHADER_COMPILER
	SShaderBin* chair_SearchInCache(const char* szName, bool bInclude);
	bool chair_AddToCache(SShaderBin* pSB, bool bInclude);
	SShaderBin* chair_GetBinShader(const char* szName, bool bInclude, uint32 nRefCRC32, bool* pbChanged = NULL);
	SShaderBin* chair_SaveBinShader(uint32 nSourceCRC32, const char* szName, bool bInclude, FILE* fpSrc);
#endif

	static inline auto FLoadBinShader = PreyFunction<SShaderBin* (CShaderManBin* const _this, _iobuf* fpBin, const char* szName, const char* szNameBin, bool bReadParams)>(0x102AC90);
	static inline auto FSaveBinShaderLocalInfo = PreyFunction<bool(CShaderManBin* const _this, SShaderBin* pBin, unsigned dwName, uint64_t nMaskGenFX, TArray<int>& Funcs, std::vector<SFXParam>& Params, std::vector<SFXSampler>& Samplers, std::vector<SFXTexture>& Textures)>(0x1033800);
	static inline auto FGetParamInfo = PreyFunction<SParamCacheInfo* (CShaderManBin* const _this, SShaderBin* pBin, unsigned dwName, uint64_t nMaskGenFX)>(0x102A0E0);
	static inline auto FParseBinFX_Global_Annotations = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, SParserFrame& Frame, bool* bPublic, CCryNameR* techStart)>(0x102CFF0);
	static inline auto FParseBinFX_SamplerOv1 = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, SParserFrame& Frame, unsigned dwName, EToken samplerType)>(0x102EB40);
	static inline auto FParseBinFX_SamplerOv0 = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, SParserFrame& Frame, SFXSampler& Sampl)>(0x102E400);
	static inline auto FParseBinFX_Texture = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, SParserFrame& Frame, SFXTexture& Tex)>(0x1033320);
	static inline auto FInitShaderDependenciesList = PreyFunction<void(CShaderManBin* const _this, CParserBin& Parser, SCodeFragment* pFunc, TArray<unsigned char>& bChecked, TArray<int>& AffectedFunc)>(0x102AA40);
	static inline auto FCheckFragmentsDependencies = PreyFunction<void(CShaderManBin* const _this, CParserBin& Parser, TArray<unsigned char>& bChecked, TArray<int>& AffectedFrags)>(0x1028A30);
	static inline auto FCheckStructuresDependencies = PreyFunction<void(CShaderManBin* const _this, CParserBin& Parser, SCodeFragment* pFrag, TArray<unsigned char>& bChecked, TArray<int>& AffectedFunc)>(0x1028C50);
	static inline auto FAddParameterToScript = PreyFunction<void(CShaderManBin* const _this, CParserBin& Parser, SFXParam* pr, PodArray<unsigned int, 0>& SHData, EHWShaderClass eSHClass, int nCB)>(0x1027E00);
	static inline auto FAddSamplerToScript = PreyFunction<void(CShaderManBin* const _this, CParserBin& Parser, SFXSampler* pr, PodArray<unsigned int, 0>& SHData, EHWShaderClass eSHClass)>(0x1028240);
	static inline auto FAddTextureToScript = PreyFunction<void(CShaderManBin* const _this, CParserBin& Parser, SFXTexture* pr, PodArray<unsigned int, 0>& SHData, EHWShaderClass eSHClass)>(0x1028550);
	static inline auto FParseBinFX_Technique_Pass_PackParameters = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, std::vector<SFXParam>& AffectedParams, TArray<int>& AffectedFunc, SCodeFragment* pFunc, EHWShaderClass eSHClass, unsigned dwSHName, std::vector<SFXParam>& PackedParams, TArray<SCodeFragment>& Replaces, TArray<unsigned int>& NewTokens, TArray<unsigned char>& bMerged)>(0x10328E0);
	static inline auto FParseBinFX_Technique_Pass_GenerateShaderData = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, std::map<unsigned int, SMacroBinFX, std::less<unsigned int>>& Macros, SShaderFXParams& FXParams, unsigned dwSHName, EHWShaderClass eSHClass, uint64_t& nAffectMask, unsigned dwSHType, PodArray<unsigned int, 0>& SHData, SShaderTechnique* pShTech)>(0x1030D80);
	static inline auto FParseBinFX_Technique_Pass_LoadShader = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, std::map<unsigned int, SMacroBinFX, std::less<unsigned int>>& Macros, SParserFrame& SHFrame, SShaderTechnique* pShTech, SShaderPass* pPass, EHWShaderClass eSHClass, SShaderFXParams& FXParams)>(0x1032590);
	static inline auto FParseBinFX_Technique_Pass = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, SParserFrame& Frame, SShaderTechnique* pShTech)>(0x1030110);
	static inline auto FParseBinFX_Technique_Annotations_String = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, SParserFrame& Frame, SShaderTechnique* pShTech, std::vector<SShaderTechParseParams>& techParams, bool* bPublic)>(0x102FCE0);
	static inline auto FParseBinFX_Technique = PreyFunction<SShaderTechnique* (CShaderManBin* const _this, CParserBin& Parser, SParserFrame& Frame, SParserFrame Annotations, std::vector<SShaderTechParseParams>& techParams, bool* bPublic)>(0x102F6B0);
	static inline auto FParseBinFX_LightStyle_Val = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, SParserFrame& Frame, CLightStyle* ls)>(0x102E0B0);
	static inline auto FParseBinFX_LightStyle = PreyFunction<bool(CShaderManBin* const _this, CParserBin& Parser, SParserFrame& Frame, int nStyle)>(0x102DB20);
	static inline auto FGetTextureSlots = PreyFunction<SShaderTexSlots* (CShaderManBin* const _this, CParserBin& Parser, SShaderBin* pBin, CShader* ef, int nTech, int nPass)>(0x102A160);
	static inline auto FDeleteFromCache = PreyFunction<bool(CShaderManBin* const _this, SShaderBin* pSB)>(0x1028F20);
	static inline auto FmfAddFXParamOv1 = PreyFunction<SFXParam* (CShaderManBin* const _this, SShaderFXParams& FXP, SFXParam const* pParam)>(0x1034E50);
	static inline auto FmfGeneratePublicFXParams = PreyFunction<void(CShaderManBin* const _this, CShader* pSH, CParserBin& Parser)>(0x1035030);
	static inline auto FGetBinShader = PreyFunction<SShaderBin* (CShaderManBin* const _this, const char* szName, bool bInclude, unsigned nRefCRC, bool* pbChanged)>(0x1028F70);
	static inline auto FParseBinFX = PreyFunction<bool(CShaderManBin* const _this, SShaderBin* pBin, CShader* ef, uint64_t nMaskGen)>(0x102B330);
	static inline auto FmfGetFXParams = PreyFunction<SShaderFXParams& (CShaderManBin* const _this, CShader* pSH)>(0x10354E0);
	static inline auto FmfRemoveFXParams = PreyFunction<void(CShaderManBin* const _this, CShader* pSH)>(0x1035B30);
	static inline auto FmfReleaseFXParams = PreyFunction<void(CShaderManBin* const _this)>(0x1035AF0);
	static inline auto FInvalidateCache = PreyFunction<void(CShaderManBin* const _this, bool bIncludesOnly)>(0x102ABC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CShaderManBin const* const _this, ICrySizer* pSizer)>(0x1029B30);
};

//=====================================================================

#endif  // __CSHADERBIN_H__
