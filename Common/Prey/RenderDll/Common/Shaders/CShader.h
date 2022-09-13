// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef __CSHADER_H__
#define __CSHADER_H__

#include <map>
#include <Prey/CryRenderer/IRenderer.h>
#include "CShaderBin.h"
#include "ShaderSerialize.h"
#include "ShaderCache.h"
#include "ShaderComponents.h"
#include "ShaderResources.h"
#include "../ResFileLookupDataMan.h"

struct SRenderBuf;
class CRendElementBase;
struct SEmitter;
struct SParticleInfo;
struct SPartMoveStage;
struct SSunFlare;

//===================================================================

#define MAX_ENVTEXTURES    16
#define MAX_ENVTEXSCANDIST 0.1f

//===============================================================================

struct SMacroFX
{
	string m_szMacro;
	uint32 m_nMask;
};

//typedef std::unordered_map<string, SMacroFX, stl::hash_strcmp<string>, stl::hash_strcmp<string>> FXMacro;
//typedef std::map<string,SMacroFX> FXMacro;
typedef std::unordered_map<string, SMacroFX, stl::hash_strcmp<const char*>, stl::hash_strcmp<const char*>> FXMacro;

typedef FXMacro::iterator                                                                                  FXMacroItor;

//////////////////////////////////////////////////////////////////////////
// Helper class for shader parser, holds temporary strings vector etc...
//////////////////////////////////////////////////////////////////////////
struct CShaderParserHelper
{
	CShaderParserHelper()
	{
	}
	~CShaderParserHelper()
	{
	}

	char* GetTempStringArray(int nIndex, int nLen)
	{
		m_tempString.reserve(nLen + 1);
		return (char*)&(m_tempStringArray[nIndex])[0];
	}

	std::vector<char> m_tempStringArray[32];
	std::vector<char> m_tempString;
};
extern CShaderParserHelper* g_pShaderParserHelper;

/*enum EShaderFlagType
{
	eSFT_Global = 0,
	eSFT_Runtime,
	eSFT_MDV,
	eSFT_LT,
};

enum EShaderFilterOperation
{
	eSFO_Expand = 0,  // expand all permutations of the mask
	eSFO_And,         // and against the mask
	eSFO_Eq,          // set the mask
};

// includes or excludes
struct CShaderListFilter
{
	CShaderListFilter() :
		m_bInclude(true)
	{}

	bool   m_bInclude;
	string m_ShaderName;

	struct Predicate
	{
		Predicate() :
			m_Negated(false),
			m_Flags(eSFT_Global),
			m_Op(eSFO_And),
			m_Mask(0)
		{}

		bool                   m_Negated;
		EShaderFlagType        m_Flags;
		EShaderFilterOperation m_Op;
		uint64                 m_Mask;
	};
	std::vector<Predicate> m_Predicates;
};*/

//==================================================================================

#define PD_INDEXED 1
#define PD_MERGED  4

struct SParamDB
{
	const char* szName;
	const char* szAliasName;
	ECGParam    eParamType;
	uint32      nFlags;
	void        (*ParserFunc)(const char* szScr, const char* szAnnotations, std::vector<STexSamplerFX>* pSamplers, SCGParam* vpp, int nComp, CShader* ef);
	SParamDB()
		: szName(nullptr)
		, szAliasName(nullptr)
		, eParamType(ECGP_Unknown)
		, nFlags(0)
		, ParserFunc(nullptr)
	{
	}
	SParamDB(const char* inName, ECGParam ePrmType, uint32 inFlags)
	{
		szName = inName;
		szAliasName = NULL;
		nFlags = inFlags;
		ParserFunc = NULL;
		eParamType = ePrmType;
	}
	SParamDB(const char* inName, ECGParam ePrmType, uint32 inFlags, void(*InParserFunc)(const char* szScr, const char* szAnnotations, std::vector<STexSamplerFX>* pSamplers, SCGParam* vpp, int nComp, CShader* ef))
	{
		szName = inName;
		szAliasName = NULL;
		nFlags = inFlags;
		ParserFunc = InParserFunc;
		eParamType = ePrmType;
	}
};

struct SSamplerDB
{
	const char* szName;
	ECGSampler  eSamplerType;
	uint32      nFlags;
	void        (*ParserFunc)(const char* szScr, const char* szAnnotations, std::vector<SFXSampler>* pSamplers, SCGSampler* vpp, CShader* ef);
	SSamplerDB()
	{
		szName = NULL;
		nFlags = 0;
		ParserFunc = NULL;
		eSamplerType = ECGS_Unknown;
	}
	SSamplerDB(const char* inName, ECGSampler ePrmType, uint32 inFlags)
	{
		szName = inName;
		nFlags = inFlags;
		ParserFunc = NULL;
		eSamplerType = ePrmType;
	}
	SSamplerDB(const char* inName, ECGSampler ePrmType, uint32 inFlags, void(*InParserFunc)(const char* szScr, const char* szAnnotations, std::vector<SFXSampler>* pSamplers, SCGSampler* vpp, CShader* ef))
	{
		szName = inName;
		nFlags = inFlags;
		ParserFunc = InParserFunc;
		eSamplerType = ePrmType;
	}
};

struct STextureDB
{
	const char* szName;
	ECGTexture  eTextureType;
	uint32      nFlags;
	void        (*ParserFunc)(const char* szScr, const char* szAnnotations, std::vector<SFXTexture>* pSamplers, SCGTexture* vpp, CShader* ef);
	STextureDB()
	{
		szName = NULL;
		nFlags = 0;
		ParserFunc = NULL;
		eTextureType = ECGT_Unknown;
	}
	STextureDB(const char* inName, ECGTexture ePrmType, uint32 inFlags)
	{
		szName = inName;
		nFlags = inFlags;
		ParserFunc = NULL;
		eTextureType = ePrmType;
	}
	STextureDB(const char* inName, ECGTexture ePrmType, uint32 inFlags, void(*InParserFunc)(const char* szScr, const char* szAnnotations, std::vector<SFXTexture>* pSamplers, SCGTexture* vpp, CShader* ef))
	{
		szName = inName;
		nFlags = inFlags;
		ParserFunc = InParserFunc;
		eTextureType = ePrmType;
	}
};

enum EShaderCacheMode
{
	eSC_Normal = 0,
	eSC_BuildGlobal = 2,
	eSC_BuildGlobalList = 3,
	eSC_Preactivate = 4,
};

//////////////////////////////////////////////////////////////////////////
class CShaderMan :
	public ISystemEventListener
{
public:
	friend class CShader;
	friend class CParserBin;

	char* m_pCurScript;
	CShaderManBin m_Bin;
	CResFileLookupDataMan m_ResLookupDataMan[2];
	bool m_bInitialized;
	bool m_bLoadedSystem;
	const char* m_ShadersPath;
	const char* m_ShadersExtPath;
	const char* m_ShadersCache;
	const char* m_ShadersFilter;
	const char* m_ShadersMergeCachePath;
	string m_szUserPath;
	int m_nFrameForceReload;
	char m_HWPath[128];
	CShader* m_pCurShader;
	static inline auto s_pContainer = PreyGlobal<SResourceContainer*>(0x2BA7370);
	std::vector<string> m_ShaderNames;
	static inline auto s_cNameHEAD = PreyGlobal<CCryNameTSCRC>(0x2BA7428);
	static inline auto s_DefaultShader = PreyGlobal<CShader*>(0x2BA7378);
	static inline auto s_shPostEffects = PreyGlobal<CShader*>(0x2BA7380);
	static inline auto s_shPostMotionBlur = PreyGlobal<CShader*>(0x2BA7388);
	static inline auto s_shPostSunShafts = PreyGlobal<CShader*>(0x2BA7390);
	static inline auto s_shDeferredShading = PreyGlobal<CShader*>(0x2BA7398);
	static inline auto s_ShaderDeferredCaustics = PreyGlobal<CShader*>(0x2BA73A0);
	static inline auto s_ShaderFPEmu = PreyGlobal<CShader*>(0x2BA73A8);
	static inline auto s_ShaderScaleForm = PreyGlobal<CShader*>(0x2BA73B0);
	static inline auto s_ShaderStars = PreyGlobal<CShader*>(0x2BA73B8);
	static inline auto s_ShaderShadowBlur = PreyGlobal<CShader*>(0x2BA73C0);
	static inline auto s_ShaderShadowMaskGen = PreyGlobal<CShader*>(0x2BA73C8);
	static inline auto s_shHDRPostProcess = PreyGlobal<CShader*>(0x2BA73D0);
	static inline auto s_shPostEffectsGame = PreyGlobal<CShader*>(0x2BA73D8);
	static inline auto s_shPostAA = PreyGlobal<CShader*>(0x2BA73E0);
	static inline auto s_ShaderDebug = PreyGlobal<CShader*>(0x2BA73E8);
	static inline auto s_ShaderLensOptics = PreyGlobal<CShader*>(0x2BA73F0);
	static inline auto s_ShaderSoftOcclusionQuery = PreyGlobal<CShader*>(0x2BA73F8);
	static inline auto s_ShaderLightStyles = PreyGlobal<CShader*>(0x2BA7400);
	static inline auto s_ShaderCommon = PreyGlobal<CShader*>(0x2BA7408);
	static inline auto s_ShaderOcclTest = PreyGlobal<CShader*>(0x2BA7410);
	static inline auto s_ShaderClouds = PreyGlobal<CShader*>(0x2BA7418);
	static inline auto m_shArkPostEffects = PreyGlobal<CShader*>(0x2BA7420);
	SInputShaderResources const* m_pCurInputResources;
	SShaderGen* m_pGlobalExt;
	SShaderLevelPolicies* m_pLevelsPolicies;
	Vec4 m_TempVecs[16];
	Vec4 m_RTRect;
	std::vector<SShaderGenComb> m_SGC;
	int m_nCombinationsProcess;
	int m_nCombinationsProcessOverall;
	int m_nCombinationsCompiled;
	int m_nCombinationsEmpty;
	EShaderCacheMode m_eCacheMode;
	char* m_szShaderPrecache;
	std::map<CCryNameR, SCacheCombination, std::less<CCryNameR>> m_ShaderCacheCombinations[2];
	std::map<CCryNameR, SCacheCombination, std::less<CCryNameR>> m_ShaderCacheExportCombinations;
	_iobuf* m_FPCacheCombinations[2];

	using ShaderCacheMissesVec = std::vector<CCryNameTSCRC, stl::STLGlobalAllocator<CCryNameTSCRC> >;

	std::vector<CCryNameTSCRC, stl::STLGlobalAllocator<CCryNameTSCRC> > m_ShaderCacheMisses;
	string m_ShaderCacheMissPath;
	void (*m_ShaderCacheMissCallback)(const char*);
	SShaderCacheStatistics m_ShaderCacheStats;
	unsigned m_nFrameLastSubmitted;
	unsigned m_nFrameSubmit;
	SShaderProfile m_ShaderProfiles[14];
	SShaderProfile m_ShaderFixedProfiles[4];
	int m_bActivated;
	CShaderParserHelper m_shaderParserHelper;
	bool m_bReload;

	using MapNameFlags = std::map<string, unsigned __int64, std::less<string>, std::allocator<std::pair<CryStringT<char> const, unsigned __int64>>>;
	using MapNameFlagsItor = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const, unsigned __int64> > > >;

	std::map<string, unsigned __int64, std::less<string>, std::allocator<std::pair<CryStringT<char> const, unsigned __int64>>> m_pShaderCommonGlobalFlag;
	std::map<string, unsigned __int64, std::less<string>, std::allocator<std::pair<CryStringT<char> const, unsigned __int64>>> m_pSCGFlagLegacyFix;
	uint64_t m_nSGFlagsFix;

	using ShaderMapNameFlags = std::map<string, std::map<string, unsigned __int64, std::less<string>, std::allocator<std::pair<CryStringT<char> const, unsigned __int64>>>*, std::less<string>, std::allocator<std::pair<CryStringT<char> const, std::map<string, unsigned __int64, std::less<string>, std::allocator<std::pair<CryStringT<char> const, unsigned __int64>>>*>>>;
	using ShaderMapNameFlagsItor = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const, std::map<string, unsigned __int64, std::less<string>, std::allocator<std::pair<CryStringT<char> const, unsigned __int64>>>*>>>>;

	std::map<string, std::map<string, unsigned __int64, std::less<string>, std::allocator<std::pair<CryStringT<char> const, unsigned __int64>>>*, std::less<string>, std::allocator<std::pair<CryStringT<char> const, std::map<string, unsigned __int64, std::less<string>, std::allocator<std::pair<CryStringT<char> const, unsigned __int64>>>*>>> m_pShadersGlobalFlags;

	using ShaderExt = std::map<CCryNameTSCRC, SShaderGen*, std::less<CCryNameTSCRC>>;
	using ShaderExtItor = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CCryNameTSCRC const, SShaderGen*> > > >;

	std::map<CCryNameTSCRC, SShaderGen*, std::less<CCryNameTSCRC>> m_ShaderExts;
	SCGParamsPF m_PF[2];
	string m_pShadersRemapList;

	struct SShaderMapNameFlagsContainerDelete // Id=8010A24 Size=1
	{
#if 0
		void operator()(std::pair<CryStringT<char> const, std::map<string, unsigned __int64, std::less<string>, std::allocator<std::pair<CryStringT<char> const, unsigned __int64>>>*>& arg0);
#endif
	};

	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	STexAnim* mfReadTexSequence(const char* na, int Flags, bool bFindOnly) { return FmfReadTexSequenceOv1(this, na, Flags, bFindOnly); }
	CShader* mfNewShader(const char* szName) { return FmfNewShader(this, szName); }
	void mfCompileLevelsList(std::vector<string>& List, char* scr) { FmfCompileLevelsList(this, List, scr); }
	bool mfCompileShaderLevelPolicies(SShaderLevelPolicies* pPL, char* scr) { return FmfCompileShaderLevelPolicies(this, pPL, scr); }
	bool mfCompileShaderGen(SShaderGen* shg, char* scr) { return FmfCompileShaderGen(this, shg, scr); }
	SShaderGenBit* mfCompileShaderGenProperty(char* scr) { return FmfCompileShaderGenProperty(this, scr); }
	void mfSetResourceTexState(SEfResTexture* Tex) { FmfSetResourceTexState(this, Tex); }
	CTexture* mfTryToLoadTexture(const char* nameTex, STexSamplerRT* smp, int Flags, bool bFindOnly) { return FmfTryToLoadTexture(this, nameTex, smp, Flags, bFindOnly); }
	CTexture* mfLoadResourceTexture(const char* nameTex, int Flags, SEfResTexture* Tex) { return FmfLoadResourceTextureOv2(this, nameTex, Flags, Tex); }
	bool mfLoadResourceTexture(EEfResTextures Id, CShaderResources& RS, unsigned CustomFlags, bool bReplaceMeOnFail) { return FmfLoadResourceTextureOv0(this, Id, RS, CustomFlags, bReplaceMeOnFail); }
	CTexture* mfCheckTemplateTexName(const char* mapname, ETEX_Type eTT) { return FmfCheckTemplateTexName(this, mapname, eTT); }
	void mfRefreshResources(CShaderResources* Res, bool _bDisableStreaming, IRenderer::SLoadShaderItemArgs const* pArgs) { FmfRefreshResources(this, Res, _bDisableStreaming, pArgs); }
	SShaderGenComb* mfGetShaderGenInfo(const char* nmFX) { return FmfGetShaderGenInfo(this, nmFX); }
	bool mfReloadShaderIncludes(const char* szPath, int nFlags) { return FmfReloadShaderIncludes(this, szPath, nFlags); }
	bool mfReloadAllShaders(int nFlags, unsigned nFlagsHW) { return FmfReloadAllShaders(this, nFlags, nFlagsHW); }
	bool mfReloadFile(const char* szPath, const char* szName, int nFlags) { return FmfReloadFile(this, szPath, szName, nFlags); }
	void ParseShaderProfiles() { FParseShaderProfiles(this); }
	bool mfParseParamComp(int comp, SCGParam* pCurParam, const char* szSemantic, char* params, const char* szAnnotations, SShaderFXParams& FXParams, CShader* ef, unsigned nParamFlags, EHWShaderClass eSHClass, bool bExpressionOperand) { return FmfParseParamComp(this, comp, pCurParam, szSemantic, params, szAnnotations, FXParams, ef, nParamFlags, eSHClass, bExpressionOperand); }
	bool mfParseCGParam(char* scr, const char* szAnnotations, SShaderFXParams& FXParams, CShader* ef, std::vector<SCGParam>* pParams, int nComps, unsigned nParamFlags, EHWShaderClass eSHClass, bool bExpressionOperand) { return FmfParseCGParam(this, scr, szAnnotations, FXParams, ef, pParams, nComps, nParamFlags, eSHClass, bExpressionOperand); }
	bool mfParseFXParameter(SShaderFXParams& FXParams, SFXParam* pr, const char* ParamName, CShader* ef, bool bInstParam, int nParams, std::vector<SCGParam>* pParams, EHWShaderClass eSHClass, bool bExpressionOperand) { return FmfParseFXParameter(this, FXParams, pr, ParamName, ef, bInstParam, nParams, pParams, eSHClass, bExpressionOperand); }
	bool mfParseFXTexture(SShaderFXParams& FXParams, SFXTexture* pr, const char* ParamName, CShader* ef, int nParams, std::vector<SCGTexture>* pParams, EHWShaderClass eSHClass) { return FmfParseFXTexture(this, FXParams, pr, ParamName, ef, nParams, pParams, eSHClass); }
	bool mfParseFXSampler(SShaderFXParams& FXParams, SFXSampler* pr, const char* ParamName, CShader* ef, int nParams, std::vector<SCGSampler>* pParams, EHWShaderClass eSHClass) { return FmfParseFXSamplerOv1(this, FXParams, pr, ParamName, ef, nParams, pParams, eSHClass); }
	void mfCheckObjectDependParams(std::vector<SCGParam>& PNoObj, std::vector<SCGParam>& PObj, EHWShaderClass eSH, CShader* pFXShader) { FmfCheckObjectDependParams(this, PNoObj, PObj, eSH, pFXShader); }
	void mfBeginFrame() { FmfBeginFrame(this); }
	void mfGetShaderListPath(CryStackStringT<char, 512>& nameOut, int nType) { FmfGetShaderListPath(this, nameOut, nType); }
	CShaderMan();
	void ShutDown() { FShutDown(this); }
	SShaderGen* mfCreateShaderGenInfo(const char* szName, bool bRuntime) { return FmfCreateShaderGenInfo(this, szName, bRuntime); }
	void mfRemapShaderGenInfoBits(const char* szName, SShaderGen* pShGen) { FmfRemapShaderGenInfoBits(this, szName, pShGen); }
	uint64_t mfGetRemapedShaderMaskGen(const char* szName, uint64_t nMaskGen, bool bFixup) { return FmfGetRemapedShaderMaskGen(this, szName, nMaskGen, bFixup); }
	bool mfUsesGlobalFlags(const char* szShaderName) { return FmfUsesGlobalFlags(this, szShaderName); }
	const char* mfGetShaderBitNamesFromGlobalMaskGen(uint64_t nMaskGen) { return FmfGetShaderBitNamesFromGlobalMaskGen(this, nMaskGen); }
	uint64_t mfGetShaderGlobalMaskGenFromString(const char* szShaderGen) { return FmfGetShaderGlobalMaskGenFromString(this, szShaderGen); }
	void mfInitGlobal() { FmfInitGlobal(this); }
	void mfInitLevelPolicies() { FmfInitLevelPolicies(this); }
	void mfInitLookups() { FmfInitLookups(this); }
	void mfInitCommonGlobalFlags() { FmfInitCommonGlobalFlags(this); }
	void mfInitCommonGlobalFlagsLegacyFix() { FmfInitCommonGlobalFlagsLegacyFix(this); }
	bool mfRemapCommonGlobalFlagsWithLegacy() { return FmfRemapCommonGlobalFlagsWithLegacy(this); }
	void mfCreateCommonGlobalFlags(const char* szName) { FmfCreateCommonGlobalFlags(this, szName); }
	void mfInit() { FmfInit(this); }
	void mfPostInit() { FmfPostInit(this); }
	void mfSortResources() { FmfSortResources(this); }
	CShaderResources* mfCreateShaderResources(SInputShaderResources const* Res, bool bShare) { return FmfCreateShaderResources(this, Res, bShare); }
	bool mfRefreshResourceConstants(CShaderResources* Res) { return FmfRefreshResourceConstantsOv1(this, Res); }
	bool mfUpdateTechnik(SShaderItem& SI, CCryNameTSCRC& Name) { return FmfUpdateTechnik(this, SI, Name); }
	SShaderItem mfShaderItemForName(const char* nameEf, bool bShare, int flags, SInputShaderResources* Res = 0, uint64_t nMaskGen = 0, IRenderer::SLoadShaderItemArgs const* pArgs = 0) { return FmfShaderItemForName(this, nameEf, bShare, flags, Res, nMaskGen, pArgs); }
	CShader* mfForName(const char* nameSh, int flags, CShaderResources const* Res = nullptr, uint64_t nMaskGen = 0) { return FmfForName(this, nameSh, flags, Res, nMaskGen); }
	bool mfRefreshSystemShader(const char* szName, CShader*& pSysShader) { return FmfRefreshSystemShader(this, szName, pSysShader); }
	void RT_ParseShader(CShader* pSH, uint64_t nMaskGen, unsigned flags, CShaderResources* pRes) { FRT_ParseShader(this, pSH, nMaskGen, flags, pRes); }
	void RT_SetShaderQuality(EShaderType eST, EShaderQuality eSQ) { FRT_SetShaderQuality(this, eST, eSQ); }
	SFXParam* mfGetFXParameter(std::vector<SFXParam>& Params, const char* param) { return FmfGetFXParameter(this, Params, param); }
	SFXSampler* mfGetFXSampler(std::vector<SFXSampler>& Params, const char* param) { return FmfGetFXSampler(this, Params, param); }
	SFXTexture* mfGetFXTexture(std::vector<SFXTexture>& Params, const char* param) { return FmfGetFXTexture(this, Params, param); }
	CTexture* mfParseFXTechnique_LoadShaderTexture(STexSamplerRT* smp, const char* szName, SShaderPass* pShPass, CShader* ef, int nIndex, uint8_t ColorOp, uint8_t AlphaOp, uint8_t ColorArg, uint8_t AlphaArg) { return FmfParseFXTechnique_LoadShaderTexture(this, smp, szName, pShPass, ef, nIndex, ColorOp, AlphaOp, ColorArg, AlphaArg); }
	void mfPostLoadFX(CShader* ef, std::vector<SShaderTechParseParams>& techParams, CCryNameR* techStart) { FmfPostLoadFX(this, ef, techParams, techStart); }
	bool mfModifyGenFlags(CShader* efGen, CShaderResources const* pRes, uint64_t& nMaskGen, uint64_t& nMaskGenH) { return FmfModifyGenFlags(this, efGen, pRes, nMaskGen, nMaskGenH); }
	void mfReleaseSystemShaders() { FmfReleaseSystemShaders(this); }
	void mfLoadBasicSystemShaders() { FmfLoadBasicSystemShaders(this); }
	void mfLoadDefaultSystemShaders() { FmfLoadDefaultSystemShaders(this); }
	void mfCloseShadersCache(int nID) { FmfCloseShadersCache(this, nID); }
	void mfInitShadersCacheMissLog() { FmfInitShadersCacheMissLog(this); }
	void mfInsertNewCombination(SShaderCombIdent& Ident, EHWShaderClass eCL, const char* name, int nID, string* Str = NULL, byte bStore = 1) { FmfInsertNewCombination(this, Ident, eCL, name, nID, Str, bStore); }
	bool mfReleasePreactivatedShaderData() { return FmfReleasePreactivatedShaderData(this); }
	bool mfPreactivateShaders2(const char* szPak, const char* szPath, bool bPersistent, const char* szBindRoot) { return FmfPreactivateShaders2(this, szPak, szPath, bPersistent, szBindRoot); }
	bool mfPreactivate2(CResFileLookupDataMan& LevelLookup, string szPathPerLevel, string szPathGlobal, bool bVS, bool bPersistent) { return FmfPreactivate2(this, LevelLookup, szPathPerLevel, szPathGlobal, bVS, bPersistent); }
	bool mfPreloadBinaryShaders() { return FmfPreloadBinaryShaders(this); }
	bool LoadShaderStartupCache() { return FLoadShaderStartupCache(this); }
	void UnloadShaderStartupCache() { FUnloadShaderStartupCache(this); }
	virtual ~CShaderMan();

#if 0
	int mfReadTexSequence(STexSamplerRT* arg0, const char* arg1, int arg2, bool arg3);
	CTexture* mfFindResourceTexture(const char* arg0, int arg1, SEfResTexture* arg2);
	bool mfLoadResourceTexture(EEfResTextures arg0, SInputShaderResources& arg1, unsigned arg2, bool arg3);
	void mfLoadDefaultTexture(EEfResTextures arg0, CShaderResources& arg1, EEfResTextures arg2);
	void mfCheckShaderResTextures(TArray<SShaderPass>& arg0, CShader* arg1, CShaderResources* arg2);
	void mfCheckShaderResTexturesHW(TArray<SShaderPass>& arg0, CShader* arg1, CShaderResources* arg2);
	bool mfUpdateMergeStatus(SShaderTechnique* arg0, std::vector<SCGParam>* arg1);
	bool mfReloadShaderFile(const char* arg0, int arg1);
	static void FilterShaderCacheGenListForOrbis(std::map<CCryNameR, SCacheCombination, std::less<CCryNameR>>& arg0);
	void ParseShaderProfile(char* arg0, SShaderProfile* arg1);
	SParamDB* mfGetShaderParamDB(const char* arg0);
	const char* mfGetShaderParamName(ECGParam arg0);
	bool mfParseFXSampler(char* arg0, char* arg1, char* arg2, CShader* arg3, std::vector<STexSamplerFX>& arg4, std::vector<SFXStruct>& arg5);
	void mfReleaseShaders();
	string mfGetShaderBitNamesFromMaskGen(const char* arg0, uint64_t arg1);
	void mfPreloadShaderExts();
	void mfSaveCommonGlobalFlagsToDisk(const char* arg0, unsigned arg1);
	bool mfRefreshResourceConstants(SShaderItem& arg0);
	const char* mfParseFX_Parameter(string const& arg0, EParamType arg1, const char* arg2);
	void mfParseFX_Annotations_Script(char* arg0, CShader* arg1, std::vector<SFXStruct>& arg2, bool* arg3, CCryNameR* arg4);
	void mfParseFX_Annotations(char* arg0, CShader* arg1, std::vector<SFXStruct>& arg2, bool* arg3, CCryNameR* arg4);
	void mfParseFXTechnique_Annotations_Script(char* arg0, CShader* arg1, std::vector<SFXStruct>& arg2, SShaderTechnique* arg3, bool* arg4, std::vector<SShaderTechParseParams>& arg5);
	void mfParseFXTechnique_Annotations(char* arg0, CShader* arg1, std::vector<SFXStruct>& arg2, SShaderTechnique* arg3, bool* arg4, std::vector<SShaderTechParseParams>& arg5);
	void mfParseFXSampler_Annotations_Script(char* arg0, CShader* arg1, std::vector<SFXStruct>& arg2, STexSamplerFX* arg3);
	void mfParseFXSampler_Annotations(char* arg0, CShader* arg1, std::vector<SFXStruct>& arg2, STexSamplerFX* arg3);
	void mfParseFX_Global(SFXParam& arg0, CShader* arg1, std::vector<SFXStruct>& arg2, CCryNameR* arg3);
	bool mfParseDummyFX_Global(std::vector<SFXStruct>& arg0, char* arg1, CCryNameR* arg2);
	string const& mfParseFXTechnique_GenerateShaderScript(std::vector<SFXStruct>& arg0, std::unordered_map<string, SMacroFX, stl::hash_strcmp<char const*>, stl::hash_strcmp<char const*>, std::allocator<std::pair<CryStringT<char> const, SMacroFX>>>& arg1, std::vector<SFXParam>& arg2, std::vector<SFXParam>& arg3, const char* arg4, CShader* arg5, EHWShaderClass arg6, const char* arg7, unsigned& arg8, const char* arg9);
	bool mfParseFXTechnique_MergeParameters(std::vector<SFXStruct>& arg0, std::vector<SFXParam>& arg1, std::vector<int>& arg2, SFXStruct* arg3, CShader* arg4, EHWShaderClass arg5, const char* arg6, std::vector<SFXParam>& arg7);
	bool mfParseFXTechnique_LoadShader(const char* arg0, SShaderPass* arg1, CShader* arg2, std::vector<STexSamplerFX>& arg3, std::vector<SFXStruct>& arg4, std::vector<SFXParam>& arg5, std::unordered_map<string, SMacroFX, stl::hash_strcmp<char const*>, stl::hash_strcmp<char const*>, std::allocator<std::pair<CryStringT<char> const, SMacroFX>>>& arg6, EHWShaderClass arg7);
	bool mfParseFXTechniquePass(char* arg0, char* arg1, SShaderTechnique* arg2, CShader* arg3, std::vector<STexSamplerFX>& arg4, std::vector<SFXStruct>& arg5, std::vector<SFXParam>& arg6);
	bool mfParseFXTechnique_CustomRE(char* arg0, const char* arg1, SShaderTechnique* arg2, CShader* arg3);
	SShaderTechnique* mfParseFXTechnique(char* arg0, char* arg1, CShader* arg2, std::vector<STexSamplerFX>& arg3, std::vector<SFXStruct>& arg4, std::vector<SFXParam>& arg5, bool* arg6, std::vector<SShaderTechParseParams>& arg7);
	bool mfParseLightStyle(CLightStyle* arg0, char* arg1);
	bool mfParseFXLightStyle(char* arg0, int arg1, CShader* arg2, std::vector<SFXStruct>& arg3);
	CShader* mfParseFX(char* arg0, CShader* arg1, CShader* arg2, uint64_t arg3);
	bool mfParseDummyFX(char* arg0, std::vector<string>& arg1, const char* arg2);
	bool mfAddFXShaderNames(const char* arg0, std::vector<string>* arg1, bool arg2);
	bool mfInitShadersDummy(bool arg0);
	uint64_t mfGetRTForName(char* arg0);
	unsigned mfGetGLForName(char* arg0, CShader* arg1);
	void mfFillGenMacroses(SShaderGen* arg0, TArray<char>& arg1, uint64_t arg2);
	bool mfGatherShadersList(const char* arg0, bool arg1, bool arg2, std::vector<string>* arg3);
	void mfGatherFilesList(const char* arg0, std::vector<CCryNameR>& arg1, int arg2, bool arg3, bool arg4);
	int mfInitShadersList(std::vector<string>* arg0);
	void mfSetDefaults();
	void mfInitShadersCache(uint8_t arg0, std::map<CCryNameR, SCacheCombination, std::less<CCryNameR>>* arg1, const char* arg2, int arg3);
	void mfMergeShadersCombinations(std::map<CCryNameR, SCacheCombination, std::less<CCryNameR>>* arg0, int arg1);
	const char* mfGetLevelListName() const;
	int Size();
	void GetMemoryUsage(ICrySizer* arg0) const;
	static float EvalWaveForm(SWaveForm* arg0);
	static float EvalWaveForm(SWaveForm2* arg0);
	static float EvalWaveForm2(SWaveForm* arg0, float arg1);
#endif

	static inline auto FOnSystemEvent = PreyFunction<void(CShaderMan* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0xA13080);
	static inline auto FmfReadTexSequenceOv1 = PreyFunction<STexAnim* (CShaderMan* const _this, const char* na, int Flags, bool bFindOnly)>(0x103C5E0);
	static inline auto FmfNewShader = PreyFunction<CShader* (CShaderMan* const _this, const char* szName)>(0x1020900);
	static inline auto FmfCompileLevelsList = PreyFunction<void(CShaderMan* const _this, std::vector<string>& List, char* scr)>(0x10372E0);
	static inline auto FmfCompileShaderLevelPolicies = PreyFunction<bool(CShaderMan* const _this, SShaderLevelPolicies* pPL, char* scr)>(0x1037F10);
	static inline auto FmfCompileShaderGen = PreyFunction<bool(CShaderMan* const _this, SShaderGen* shg, char* scr)>(0x10375B0);
	static inline auto FmfCompileShaderGenProperty = PreyFunction<SShaderGenBit* (CShaderMan* const _this, char* scr)>(0x10376B0);
	static inline auto FmfSetResourceTexState = PreyFunction<void(CShaderMan* const _this, SEfResTexture* Tex)>(0x103D060);
	static inline auto FmfTryToLoadTexture = PreyFunction<CTexture* (CShaderMan* const _this, const char* nameTex, STexSamplerRT* smp, int Flags, bool bFindOnly)>(0x103D190);
	static inline auto FmfLoadResourceTextureOv2 = PreyFunction<CTexture* (CShaderMan* const _this, const char* nameTex, int Flags, SEfResTexture* Tex)>(0x103C420);
	static inline auto FmfLoadResourceTextureOv0 = PreyFunction<bool(CShaderMan* const _this, EEfResTextures Id, CShaderResources& RS, unsigned CustomFlags, bool bReplaceMeOnFail)>(0x103C4D0);
	static inline auto FmfCheckTemplateTexName = PreyFunction<CTexture* (CShaderMan* const _this, const char* mapname, ETEX_Type eTT)>(0x103BB30);
	static inline auto FmfRefreshResources = PreyFunction<void(CShaderMan* const _this, CShaderResources* Res, bool _bDisableStreaming, IRenderer::SLoadShaderItemArgs const* pArgs)>(0x103CC10);
	static inline auto FmfGetShaderGenInfo = PreyFunction<SShaderGenComb* (CShaderMan* const _this, const char* nmFX)>(0x1015090);
	static inline auto FmfReloadShaderIncludes = PreyFunction<bool(CShaderMan* const _this, const char* szPath, int nFlags)>(0x103A9F0);
	static inline auto FmfReloadAllShaders = PreyFunction<bool(CShaderMan* const _this, int nFlags, unsigned nFlagsHW)>(0x103A350);
	static inline auto FmfReloadFile = PreyFunction<bool(CShaderMan* const _this, const char* szPath, const char* szName, int nFlags)>(0x103A690);
	static inline auto FParseShaderProfiles = PreyFunction<void(CShaderMan* const _this)>(0x101A660);
	static inline auto FmfParseParamComp = PreyFunction<bool(CShaderMan* const _this, int comp, SCGParam* pCurParam, const char* szSemantic, char* params, const char* szAnnotations, SShaderFXParams& FXParams, CShader* ef, unsigned nParamFlags, EHWShaderClass eSHClass, bool bExpressionOperand)>(0x1018C50);
	static inline auto FmfParseCGParam = PreyFunction<bool(CShaderMan* const _this, char* scr, const char* szAnnotations, SShaderFXParams& FXParams, CShader* ef, std::vector<SCGParam>* pParams, int nComps, unsigned nParamFlags, EHWShaderClass eSHClass, bool bExpressionOperand)>(0x1017C30);
	static inline auto FmfParseFXParameter = PreyFunction<bool(CShaderMan* const _this, SShaderFXParams& FXParams, SFXParam* pr, const char* ParamName, CShader* ef, bool bInstParam, int nParams, std::vector<SCGParam>* pParams, EHWShaderClass eSHClass, bool bExpressionOperand)>(0x1017FF0);
	static inline auto FmfParseFXTexture = PreyFunction<bool(CShaderMan* const _this, SShaderFXParams& FXParams, SFXTexture* pr, const char* ParamName, CShader* ef, int nParams, std::vector<SCGTexture>* pParams, EHWShaderClass eSHClass)>(0x1018AA0);
	static inline auto FmfParseFXSamplerOv1 = PreyFunction<bool(CShaderMan* const _this, SShaderFXParams& FXParams, SFXSampler* pr, const char* ParamName, CShader* ef, int nParams, std::vector<SCGSampler>* pParams, EHWShaderClass eSHClass)>(0x1018960);
	static inline auto FmfCheckObjectDependParams = PreyFunction<void(CShaderMan* const _this, std::vector<SCGParam>& PNoObj, std::vector<SCGParam>& PObj, EHWShaderClass eSH, CShader* pFXShader)>(0xF1B210);
	static inline auto FmfBeginFrame = PreyFunction<void(CShaderMan* const _this)>(0xA13080);
	static inline auto FmfGetShaderListPath = PreyFunction<void(CShaderMan* const _this, CryStackStringT<char, 512>& nameOut, int nType)>(0x1015240);
	static inline auto FShutDown = PreyFunction<void(CShaderMan* const _this)>(0x101AA10);
	static inline auto FmfCreateShaderGenInfo = PreyFunction<SShaderGen* (CShaderMan* const _this, const char* szName, bool bRuntime)>(0x1038230);
	static inline auto FmfRemapShaderGenInfoBits = PreyFunction<void(CShaderMan* const _this, const char* szName, SShaderGen* pShGen)>(0x1038C50);
	static inline auto FmfGetRemapedShaderMaskGen = PreyFunction<uint64_t(CShaderMan* const _this, const char* szName, uint64_t nMaskGen, bool bFixup)>(0x1038500);
	static inline auto FmfUsesGlobalFlags = PreyFunction<bool(CShaderMan* const _this, const char* szShaderName)>(0x10391B0);
	static inline auto FmfGetShaderBitNamesFromGlobalMaskGen = PreyFunction<const char* (CShaderMan* const _this, uint64_t nMaskGen)>(0x1038810);
	static inline auto FmfGetShaderGlobalMaskGenFromString = PreyFunction<uint64_t(CShaderMan* const _this, const char* szShaderGen)>(0x1038A40);
	static inline auto FmfInitGlobal = PreyFunction<void(CShaderMan* const _this)>(0x101F830);
	static inline auto FmfInitLevelPolicies = PreyFunction<void(CShaderMan* const _this)>(0x101FF40);
	static inline auto FmfInitLookups = PreyFunction<void(CShaderMan* const _this)>(0x1020190);
	static inline auto FmfInitCommonGlobalFlags = PreyFunction<void(CShaderMan* const _this)>(0x101E1A0);
	static inline auto FmfInitCommonGlobalFlagsLegacyFix = PreyFunction<void(CShaderMan* const _this)>(0x101E760);
	static inline auto FmfRemapCommonGlobalFlagsWithLegacy = PreyFunction<bool(CShaderMan* const _this)>(0x1020E10);
	static inline auto FmfCreateCommonGlobalFlags = PreyFunction<void(CShaderMan* const _this, const char* szName)>(0x101D040);
	static inline auto FmfInit = PreyFunction<void(CShaderMan* const _this)>(0x101D960);
	static inline auto FmfPostInit = PreyFunction<void(CShaderMan* const _this)>(0x1020B00);
	static inline auto FmfSortResources = PreyFunction<void(CShaderMan* const _this)>(0x1021070);
	static inline auto FmfCreateShaderResources = PreyFunction<CShaderResources* (CShaderMan* const _this, SInputShaderResources const* Res, bool bShare)>(0x103BCF0);
	static inline auto FmfRefreshResourceConstantsOv1 = PreyFunction<bool(CShaderMan* const _this, CShaderResources* Res)>(0x103CBD0);
	static inline auto FmfUpdateTechnik = PreyFunction<bool(CShaderMan* const _this, SShaderItem& SI, CCryNameTSCRC& Name)>(0x103B1B0);
	static inline auto FmfShaderItemForName = PreyFunction<SShaderItem(CShaderMan* const _this, const char* nameEf, bool bShare, int flags, SInputShaderResources* Res, uint64_t nMaskGen, IRenderer::SLoadShaderItemArgs const* pArgs)>(0x103AD40);
	static inline auto FmfForName = PreyFunction<CShader* (CShaderMan* const _this, const char* nameSh, int flags, CShaderResources const* Res, uint64_t nMaskGen)>(0x10397B0);
	static inline auto FmfRefreshSystemShader = PreyFunction<bool(CShaderMan* const _this, const char* szName, CShader*& pSysShader)>(0xF18690);
	static inline auto FRT_ParseShader = PreyFunction<void(CShaderMan* const _this, CShader* pSH, uint64_t nMaskGen, unsigned flags, CShaderResources* pRes)>(0x1039510);
	static inline auto FRT_SetShaderQuality = PreyFunction<void(CShaderMan* const _this, EShaderType eST, EShaderQuality eSQ)>(0x101A8A0);
	static inline auto FmfGetFXParameter = PreyFunction<SFXParam* (CShaderMan* const _this, std::vector<SFXParam>& Params, const char* param)>(0x10353D0);
	static inline auto FmfGetFXSampler = PreyFunction<SFXSampler* (CShaderMan* const _this, std::vector<SFXSampler>& Params, const char* param)>(0x1035680);
	static inline auto FmfGetFXTexture = PreyFunction<SFXTexture* (CShaderMan* const _this, std::vector<SFXTexture>& Params, const char* param)>(0x1035770);
	static inline auto FmfParseFXTechnique_LoadShaderTexture = PreyFunction<CTexture* (CShaderMan* const _this, STexSamplerRT* smp, const char* szName, SShaderPass* pShPass, CShader* ef, int nIndex, uint8_t ColorOp, uint8_t AlphaOp, uint8_t ColorArg, uint8_t AlphaArg)>(0x1035860);
	static inline auto FmfPostLoadFX = PreyFunction<void(CShaderMan* const _this, CShader* ef, std::vector<SShaderTechParseParams>& techParams, CCryNameR* techStart)>(0x10358F0);
	static inline auto FmfModifyGenFlags = PreyFunction<bool(CShaderMan* const _this, CShader* efGen, CShaderResources const* pRes, uint64_t& nMaskGen, uint64_t& nMaskGenH)>(0x1039F20);
	static inline auto FmfReleaseSystemShaders = PreyFunction<void(CShaderMan* const _this)>(0x1020BB0);
	static inline auto FmfLoadBasicSystemShaders = PreyFunction<void(CShaderMan* const _this)>(0x1020290);
	static inline auto FmfLoadDefaultSystemShaders = PreyFunction<void(CShaderMan* const _this)>(0x10203E0);
	static inline auto FmfCloseShadersCache = PreyFunction<void(CShaderMan* const _this, int nID)>(0x1014D10);
	static inline auto FmfInitShadersCacheMissLog = PreyFunction<void(CShaderMan* const _this)>(0x1015A60);
	static inline auto FmfInsertNewCombination = PreyFunction<void(CShaderMan* const _this, SShaderCombIdent& Ident, EHWShaderClass eCL, const char* name, int nID, string* Str, uint8_t bStore)>(0x1015DC0);
	static inline auto FmfReleasePreactivatedShaderData = PreyFunction<bool(CShaderMan* const _this)>(0xF1CDA0);
	static inline auto FmfPreactivateShaders2 = PreyFunction<bool(CShaderMan* const _this, const char* szPak, const char* szPath, bool bPersistent, const char* szBindRoot)>(0xF1C7E0);
	static inline auto FmfPreactivate2 = PreyFunction<bool(CShaderMan* const _this, CResFileLookupDataMan& LevelLookup, string szPathPerLevel, string szPathGlobal, bool bVS, bool bPersistent)>(0xF1B910);
	static inline auto FmfPreloadBinaryShaders = PreyFunction<bool(CShaderMan* const _this)>(0x1016900);
	static inline auto FLoadShaderStartupCache = PreyFunction<bool(CShaderMan* const _this)>(0x101A4B0);
	static inline auto FUnloadShaderStartupCache = PreyFunction<void(CShaderMan* const _this)>(0x101AED0);
	static inline auto FBitNotCShaderMan = PreyFunction<void(CShaderMan* const _this)>(0xFB1AD0);
};

#if CRY_PLATFORM_WINDOWS && CRY_PLATFORM_64BIT
#pragma warning( pop ) //AMD Port
#endif

//=====================================================================

#endif                   // __CSHADER_H__
