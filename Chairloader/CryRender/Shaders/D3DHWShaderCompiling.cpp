#include <D3D11Shader.h>
#include <D3DCompiler.h>
#include <Prey/RenderDll/XRenderD3D9/D3DHWShader.h>

//-----------------------------------------------------------------------------------

struct SStructData
{
	uint32 m_nName;
	uint32 m_nTCs;
	int    m_nPos;
};

//-----------------------------------------------------------------------------------

static int CGBindCallback(const VOID* arg1, const VOID* arg2)
{
	SCGBind* pi1 = (SCGBind*)arg1;
	SCGBind* pi2 = (SCGBind*)arg2;

	if (pi1->m_dwBind < pi2->m_dwBind)
		return -1;
	if (pi1->m_dwBind > pi2->m_dwBind)
		return 1;

	return 0;
}

static int sFetchInst(uint32& nCur, uint32* pTokens, uint32 nT, std::vector<uint32>& Parameter)
{
	while (true)
	{
		uint32 nTok = pTokens[nCur];
		if (nTok != eT_br_rnd_1 && nTok != eT_br_rnd_2 && nTok != eT_comma)
			break;
		nCur++;
	}
	int nC = 0;
	Parameter.push_back(pTokens[nCur]);
	nCur++;
	while (pTokens[nCur] == eT_dot)
	{
		nC = 2;
		Parameter.push_back(pTokens[nCur]);
		Parameter.push_back(pTokens[nCur + 1]);
		nCur += 2;
	}
	return nC;
}

static void sCR(TArray<char>& Text, int nLevel)
{
	Text.AddElem('\n');
	for (int i = 0; i < nLevel; i++)
	{
		Text.AddElem(' ');
		Text.AddElem(' ');
	}
}

static bool SkipChar(unsigned int ch)
{
	bool res = ch <= 0x20;

	res |= (ch - 0x21) < 2;  // !"
	res |= (ch - 0x26) < 10; // &'()*+,-./
	res |= (ch - 0x3A) < 6;  // :;<=>?
	res |= ch == 0x5B;       // [
	// cppcheck-suppress badBitmaskCheck
	res |= ch == 0x5D;      // ]
	res |= (ch - 0x7B) < 3; // {|}

	return res;
}

//-----------------------------------------------------------------------------------

SShaderDevCache* CHWShader::mfInitDevCache(const char* name, CHWShader* pSH)
{
	SShaderDevCache* pCache = NULL;
	FXShaderDevCacheItor it = m_ShaderDevCache->find(CCryNameR(name));
	if (it != m_ShaderDevCache->end())
	{
		pCache = it->second;
		pCache->m_nRefCount++;
	}
	else
	{
		pCache = new SShaderDevCache;
		pCache->m_Name = name;
	}
	return pCache;
}

//-----------------------------------------------------------------------------------

// Compile pixel/vertex shader for the current instance properties
bool CHWShader_D3D::chair_mfActivate(
	CShader* pSH,
	uint32 nFlags,
	FXShaderToken* Table,
	TArray<uint32>* pSHData,
	bool bCompressedOnly)
{
	PROFILE_FRAME(Shader_HWShaderActivate);

	bool bResult = true;
	SHWSInstance* pInst = m_pCurInst;

	mfLogShaderRequest(pInst);

	if (chair_mfIsValid(pInst, true) == ED3DShError_NotCompiled)
	{
		//if (!(m_Flags & HWSG_PRECACHEPHASE) && !(nFlags & HWSF_NEXT))
		//  mfSetHWStartProfile(nFlags);

		bool bCreate = false;
		// We need a different source and desination for fpStripExtension
		// since a call to strcpy with the same src and dst results in
		// undefined behaviour
		char nameCacheUnstripped[256];
		char nameCache[256];
		float t0 = gEnv->pTimer->GetAsyncCurTime();

		/*if (CRenderer::CV_r_shaderspreactivate == 2 || (nFlags & HWSF_STORECOMBINATION))
		   {
		   cry_strcpy(nameCache, GetName());
		   char *s = strchr(nameCache, '(');
		   if (s)
			s[0] = 0;
		   gRenDev->m_cEF.mfInsertNewCombination(m_nMaskGenFX, pInst->m_RTMask, pInst->m_LightMask, pInst->m_MDMask, pInst->m_MDVMask, pInst->m_pipelineState.opaque, pInst->m_eSHClass, nameCache, 1);
		   if (nFlags & HWSF_STORECOMBINATION)
			return false;
		   }*/
		mfGetDstFileName(pInst, this, nameCacheUnstripped, 256, 0);
		fpStripExtension(nameCacheUnstripped, nameCache);
		fpAddExtension(nameCache, ".fxcb");
		if (!m_pDevCache)
			m_pDevCache = mfInitDevCache(nameCache, this);

		int32 nSize;
		SShaderCacheHeaderItem* pCacheItem = mfGetCompressedItem(nFlags, nSize);

		// New addition to CryEngine? Or was it removed in Cry5?
		// https://github.com/aws/lumberyard/blob/413ecaf24d7a534801cac64f50272fe3191d278f/dev/Code/CryEngine/RenderDll/XRenderD3D9/D3DHWShaderCompiling.cpp#L4384C81-L4384C81
		if (pCacheItem)
		{
			pInst->m_bCompressed = true;
		}
		else if (bCompressedOnly)
		{
			// don't activate if shader isn't found in compressed shader data
			return false;
		}
		else
		{
			// if shader compiling is enabled, make sure the user folder shader caches are also available
			bool bReadOnly = *CRenderer::CV_r_shadersAllowCompilation == 0;
			if (!m_pGlobalCache || m_pGlobalCache->m_nPlatform != CParserBin::m_nPlatform ||
				(!bReadOnly && !m_pGlobalCache->m_pRes[CACHE_USER]))
			{
				SAFE_RELEASE(m_pGlobalCache);
				bool bAsync = *CRenderer::CV_r_shadersasyncactivation != 0;
				if (nFlags & HWSF_PRECACHE)
					bAsync = false;
				m_pGlobalCache = mfInitCache(nameCache, this, true, m_CRC32, bReadOnly, bAsync);
			}

			if (gRenDev->m_cEF.m_nCombinationsProcess >= 0)
			{
				mfGetDstFileName(pInst, this, nameCache, 256, 0);
				fpStripExtension(nameCache, nameCache);
				fpAddExtension(nameCache, ".fxcb");
				FXShaderCacheNamesItor it = m_ShaderCacheList->find(nameCache);
				if (it == m_ShaderCacheList->end())
					m_ShaderCacheList->insert(FXShaderCacheNamesItor::value_type(nameCache, m_CRC32));
			}
			pCacheItem = mfGetCacheItem(nFlags, nSize);
		}

		if (pCacheItem && pCacheItem->m_Class != 255)
		{
			if (Table && *CRenderer::CV_r_shadersAllowCompilation)
				mfGetCacheTokenMap(Table, pSHData, m_nMaskGenShader);
			if (((m_Flags & HWSG_PRECACHEPHASE) || gRenDev->m_cEF.m_nCombinationsProcess >= 0))
			{
				byte* pData = (byte*)pCacheItem;
				SAFE_DELETE_ARRAY(pData);
				return true;
			}
			bool bRes = mfActivateCacheItem(pSH, pCacheItem, nSize, nFlags);
			byte* pData = (byte*)pCacheItem;
			SAFE_DELETE_ARRAY(pData);
			pCacheItem = NULL;
			if (bRes)
				return (pInst->m_Handle.m_pShader != NULL);
			pCacheItem = NULL;
		}
		else if (pCacheItem && pCacheItem->m_Class == 255 && (nFlags & HWSF_PRECACHE) == 0)
		{
			byte* pData = (byte*)pCacheItem;
			SAFE_DELETE_ARRAY(pData);
			pCacheItem = NULL;
			return false;
		}
		if (pCacheItem)
		{
			byte* pData = (byte*)pCacheItem;
			SAFE_DELETE_ARRAY(pData);
			pCacheItem = NULL;
		}
		//assert(!m_TokenData.empty());

		TArray<char> newScr;

		if (nFlags & HWSF_PRECACHE)
			gRenDev->m_cEF.m_nCombinationsCompiled++;
		/*if (strstr(m_NameSourceFX.c_str(), "Cloak") && !strcmp(m_EntryFunc.c_str(), "Common_ZPassVS"))
		   {
		   int nnn = 0;
		   }*/

		float fTime0 = gEnv->pTimer->GetAsyncCurTime();
		LPD3D10BLOB pShader = NULL;
		void* pConstantTable = NULL;
		LPD3D10BLOB pErrorMsgs = NULL;
		std::vector<SCGBind> InstBindVars;
		m_Flags |= HWSG_WASGENERATED;

		bool bScriptSuccess = false;

		if (*CRenderer::CV_r_shadersAllowCompilation)
		{
			// MemReplay shows that 16kb should be enough memory to hold the script without having to reallocate
			newScr.reserve(16 * 1024);
			bScriptSuccess = chair_mfGenerateScript(pSH, pInst, InstBindVars, nFlags, Table, pSHData, newScr);
			ASSERT_IN_SHADER(bScriptSuccess);
		}

		if (!pInst->m_bAsyncActivating)
		{
			// report miss in global cache to log and/or callback
			mfLogShaderCacheMiss(pInst);

			// still sumit the request line when no compiling to be sure that the shadercompiler will
			// compile it in the next build
			if (!*CRenderer::CV_r_shadersAllowCompilation)
				chair_mfSubmitRequestLine(pInst);
		}

		if (!bScriptSuccess)
		{
			if (!pInst->m_bAsyncActivating)
			{
				CryWarning("Warning: Shader {}({:x})({:x})({:x})({:x})({:x})({}) is not existing in the cache\n",
					GetName(), pInst->m_Ident.m_RTMask, pInst->m_Ident.m_LightMask, pInst->m_Ident.m_MDMask, pInst->m_Ident.m_MDVMask, pInst->m_Ident.m_pipelineState.opaque, mfProfileString(pInst->m_eClass));
			}

			return false;
		}

		{
			PROFILE_FRAME(Shader_CompileHLSL);
			pShader = chair_mfCompileHLSL(pSH, newScr.Data(), &pConstantTable, &pErrorMsgs, nFlags, InstBindVars);
		}

		gRenDev->m_cEF.m_ShaderCacheStats.m_nNumShaderAsyncCompiles = *SShaderAsyncInfo::s_nPendingAsyncShaders;

		if (!pShader)
		{
			if (!*CRenderer::CV_r_shadersAllowCompilation || pInst->IsAsyncCompiling())
				return false;
		}

		// TODO 2023-07-30: CryEngine has `bool bShaderThread` arg, Prey doesn't. It seems it is always false and Prey has that compiled in.
		bResult = mfCreateShaderEnv(0, pInst, pShader, pConstantTable, pErrorMsgs, InstBindVars, this, pSH, gRenDev->m_cEF.m_nCombinationsProcess, newScr.Data());
		bResult &= mfUploadHW(pShader, pInst, pSH, nFlags);
		SAFE_RELEASE(pShader);

		fTime0 = gEnv->pTimer->GetAsyncCurTime() - fTime0;
		//iLog->LogToConsole(" Time activate: %.3f", fTime0);
	}
	else if (pSHData)
	{
		mfGetCacheTokenMap(Table, pSHData, m_nMaskGenShader);
	}

	ED3DShError shResult = chair_mfIsValid(pInst, true);
	bool bSuccess = (shResult == ED3DShError_Ok) || (shResult == ED3DShError_Fake);

	return bSuccess;
}

void CHWShader_D3D::chair_mfSubmitRequestLine(SHWSInstance* pInst, string* pRequestLine)
{
	// Generate request line text.
	char szShaderGenName[512];
	cry_strcpy(szShaderGenName, GetName());
	char* s = strchr(szShaderGenName, '(');
	if (s)
		s[0] = 0;
	string RequestLine;
	SShaderCombIdent Ident = pInst->m_Ident;
	Ident.m_GLMask = m_nMaskGenFX;
	gRenDev->m_cEF.mfInsertNewCombination(Ident, pInst->m_eClass, szShaderGenName, 0, &RequestLine, false);

	if (pRequestLine)
		*pRequestLine = RequestLine;

	if (!*CRenderer::CV_r_shaderssubmitrequestline || !*CRenderer::CV_r_shadersremotecompiler || pInst->m_bHasSendRequest)
		return;

	// make sure we only send the request once
	pInst->m_bHasSendRequest = true;

#ifdef SHADER_ASYNC_COMPILATION
	if (CRenderer::CV_r_shadersasynccompiling && !(m_Flags & HWSG_SYNC))
	{
		if (!SShaderAsyncInfo::PendingList().m_Next)
		{
			SShaderAsyncInfo::PendingList().m_Next = &SShaderAsyncInfo::PendingList();
			SShaderAsyncInfo::PendingList().m_Prev = &SShaderAsyncInfo::PendingList();
			SShaderAsyncInfo::PendingListT().m_Next = &SShaderAsyncInfo::PendingListT();
			SShaderAsyncInfo::PendingListT().m_Prev = &SShaderAsyncInfo::PendingListT();
		}

		SShaderAsyncInfo* pAsync = new SShaderAsyncInfo;

		if (pAsync)
		{
			pAsync->m_RequestLine = RequestLine;
			pAsync->m_Text = "";
			pAsync->m_bDeleteAfterRequest = true;

			CAsyncShaderTask::InsertPendingShader(pAsync);
		}
	}
	else
#endif
}

//-----------------------------------------------------------------------------------

bool CHWShader_D3D::chair_mfGenerateScript(
	CShader* pSH,
	SHWSInstance*& pInst,
	std::vector<SCGBind>& InstBindVars,
	uint32 nFlags,
	FXShaderToken* Table,
	TArray<uint32>* pSHData,
	TArray<char>& sNewScr)
{
	char* cgs = NULL;

	bool bTempMap = (Table == NULL);
	assert((Table && pSHData) || (!Table && !pSHData));
	assert(m_pGlobalCache);
	if (CParserBin::m_bEditable && !Table) // Fast path for offline shaders builder
	{
		CRY_ASSERT_MESSAGE(false, "Not Supported");
		// Table = &m_TokenTable;
		// pSHData = &m_TokenData;
		bTempMap = false;
	}
	else
	{
		if (m_pGlobalCache)
			mfGetCacheTokenMap(Table, pSHData, m_nMaskGenShader);
		if (CParserBin::m_bEditable)
		{
			if (bTempMap)
			{
				SAFE_DELETE(Table);
				SAFE_DELETE(pSHData);
			}

			CRY_ASSERT_MESSAGE(false, "Not Supported");
			// Table = &m_TokenTable;
			// pSHData = &m_TokenData;
			bTempMap = false;
		}
	}

	assert(Table && pSHData);

	if (!Table || !pSHData)
		return false;

	ShaderTokensVec NewTokens;

	uint32 eT = eT_unknown;

	switch (pInst->m_eClass)
	{
	case eHWSC_Vertex:
		eT = eT__VS;
		break;
	case eHWSC_Pixel:
		eT = eT__PS;
		break;
	case eHWSC_Geometry:
		eT = eT__GS;
		break;
	case eHWSC_Hull:
		eT = eT__HS;
		break;
	case eHWSC_Compute:
		eT = eT__CS;
		break;
	case eHWSC_Domain:
		eT = eT__DS;
		break;

	default:
		assert(0);
	}
	if (eT != eT_unknown)
		CParserBin::AddDefineToken(eT, NewTokens);

	// Include runtime mask definitions in the script
	SShaderGen* shg = gRenDev->m_cEF.m_pGlobalExt;
	if (shg && pInst->m_Ident.m_RTMask)
	{
		for (uint32 i = 0; i < shg->m_BitMask.Num(); i++)
		{
			SShaderGenBit* bit = shg->m_BitMask[i];
			if (!(bit->m_Mask & pInst->m_Ident.m_RTMask))
				continue;
			CParserBin::AddDefineToken(bit->m_dwToken, NewTokens);
		}
	}

	// Include light mask definitions in the script
	// Not implemented in Prey?
	/*
	if (m_Flags & HWSG_SUPPORTS_MULTILIGHTS)
	{
		int nLights = pInst->m_Ident.m_LightMask & 0xf;
		if (nLights)
			CParserBin::AddDefineToken(eT__LT_LIGHTS, NewTokens);
		CParserBin::AddDefineToken(eT__LT_NUM, nLights + eT_0, NewTokens);
		bool bHasProj = false;
		for (int i = 0; i < 4; i++)
		{
			int nLightType = (pInst->m_Ident.m_LightMask >> (SLMF_LTYPE_SHIFT + i * SLMF_LTYPE_BITS)) & SLMF_TYPE_MASK;
			if (nLightType == SLMF_PROJECTED)
				bHasProj = true;

			CParserBin::AddDefineToken(eT__LT_0_TYPE + i, nLightType + eT_0, NewTokens);
		}
		if (bHasProj)
			CParserBin::AddDefineToken(eT__LT_HASPROJ, eT_1, NewTokens);
	}
	else if (m_Flags & HWSG_SUPPORTS_LIGHTING)
	{
		CParserBin::AddDefineToken(eT__LT_LIGHTS, NewTokens);
		int nLightType = (pInst->m_Ident.m_LightMask >> SLMF_LTYPE_SHIFT) & SLMF_TYPE_MASK;
		if (nLightType == SLMF_PROJECTED)
			CParserBin::AddDefineToken(eT__LT_HASPROJ, eT_1, NewTokens);
	}
	*/

	// Include modificator mask definitions in the script
	if ((m_Flags & HWSG_SUPPORTS_MODIF) && pInst->m_Ident.m_MDMask)
	{
		const uint32 tcProjMask = HWMD_TEXCOORD_PROJ;
		const uint32 tcMatrixMask = HWMD_TEXCOORD_MATRIX;
		// const uint32 tcGenObjectLinearMask = HWMD_TEXCOORD_GEN_OBJECT_LINEAR;

		if (pInst->m_Ident.m_MDMask & tcProjMask)
			CParserBin::AddDefineToken(eT__TT_TEXCOORD_PROJ, NewTokens);
		if (pInst->m_Ident.m_MDMask & tcMatrixMask)
			CParserBin::AddDefineToken(eT__TT_TEXCOORD_MATRIX, NewTokens);
		// Not implemented in Prey?
		// if (pInst->m_Ident.m_MDMask & tcGenObjectLinearMask)
		// 	CParserBin::AddDefineToken(eT__TT_TEXCOORD_GEN_OBJECT_LINEAR, NewTokens);
	}

	// Include vertex modificator mask definitions in the script
	if ((m_Flags & HWSG_SUPPORTS_VMODIF) && pInst->m_Ident.m_MDVMask)
	{
		int nMDV = pInst->m_Ident.m_MDVMask & 0x0fffffff;
		int nType = nMDV & 0xf;
		if (nType)
			CParserBin::AddDefineToken(eT__VT_TYPE, eT_0 + nType, NewTokens);
		if ((nMDV & MDV_BENDING) || nType == eDT_Bending)
		{
			CParserBin::AddDefineToken(eT__VT_BEND, eT_1, NewTokens);
			if (!(nMDV & 0xf))
			{
				nType = eDT_Bending;
				CParserBin::AddDefineToken(eT__VT_TYPE, eT_0 + nType, NewTokens);
			}
		}
		if (nMDV & MDV_DEPTH_OFFSET)
			CParserBin::AddDefineToken(eT__VT_DEPTH_OFFSET, eT_1, NewTokens);
		if (nMDV & MDV_WIND)
			CParserBin::AddDefineToken(eT__VT_WIND, eT_1, NewTokens);
		if (nMDV & MDV_DET_BENDING)
			CParserBin::AddDefineToken(eT__VT_DET_BEND, eT_1, NewTokens);
		if (nMDV & MDV_DET_BENDING_GRASS)
			CParserBin::AddDefineToken(eT__VT_GRASS, eT_1, NewTokens);
		if (nMDV & ~0xf)
			CParserBin::AddDefineToken(eT__VT_TYPE_MODIF, eT_1, NewTokens);
	}

	if (m_Flags & HWSG_FP_EMULATION)
	{
		CParserBin::AddDefineToken(eT__FT0_COP, eT_0 + (pInst->m_Ident.m_LightMask & 0xff), NewTokens);
		CParserBin::AddDefineToken(eT__FT0_AOP, eT_0 + ((pInst->m_Ident.m_LightMask & 0xff00) >> 8), NewTokens);

		byte CO_0 = ((pInst->m_Ident.m_LightMask & 0xff0000) >> 16) & 7;
		CParserBin::AddDefineToken(eT__FT0_CARG1, eT_0 + CO_0, NewTokens);

		byte CO_1 = ((pInst->m_Ident.m_LightMask & 0xff0000) >> 19) & 7;
		CParserBin::AddDefineToken(eT__FT0_CARG2, eT_0 + CO_1, NewTokens);

		byte AO_0 = ((pInst->m_Ident.m_LightMask & 0xff000000) >> 24) & 7;
		CParserBin::AddDefineToken(eT__FT0_AARG1, eT_0 + AO_0, NewTokens);

		byte AO_1 = ((pInst->m_Ident.m_LightMask & 0xff000000) >> 27) & 7;
		CParserBin::AddDefineToken(eT__FT0_AARG2, eT_0 + AO_1, NewTokens);

		if (CO_0 == eCA_Specular || CO_1 == eCA_Specular || AO_0 == eCA_Specular || AO_1 == eCA_Specular)
			CParserBin::AddDefineToken(eT__FT_SPECULAR, NewTokens);
		if (CO_0 == eCA_Diffuse || CO_1 == eCA_Diffuse || AO_0 == eCA_Diffuse || AO_1 == eCA_Diffuse)
			CParserBin::AddDefineToken(eT__FT_DIFFUSE, NewTokens);
		if (CO_0 == eCA_Texture || CO_1 == eCA_Texture || AO_0 == eCA_Texture || AO_1 == eCA_Texture)
			CParserBin::AddDefineToken(eT__FT_TEXTURE, NewTokens);
		if (CO_0 == eCA_Texture1 || (CO_1 == eCA_Texture1) || AO_0 == eCA_Texture1 || AO_1 == eCA_Texture1
			|| CO_0 == eCA_Previous || (CO_1 == eCA_Previous) || AO_0 == eCA_Previous || AO_1 == eCA_Previous)
			CParserBin::AddDefineToken(eT__FT_TEXTURE1, NewTokens);
		if (CO_0 == eCA_Normal || CO_1 == eCA_Normal || AO_0 == eCA_Normal || AO_1 == eCA_Normal)
			CParserBin::AddDefineToken(eT__FT_NORMAL, NewTokens);
		if (CO_0 == eCA_Constant || (CO_1 == eCA_Constant) || AO_0 == eCA_Constant || AO_1 == eCA_Constant
			|| CO_0 == eCA_Previous || (CO_1 == eCA_Previous) || AO_0 == eCA_Previous || AO_1 == eCA_Previous)
			CParserBin::AddDefineToken(eT__FT_PSIZE, NewTokens);

		if (nFlags & HWSF_STOREDATA)
		{
			int nStreams = pInst->m_Ident.m_LightMask & 0xff;
			if (nStreams & (1 << VSF_QTANGENTS))
				CParserBin::AddDefineToken(eT__FT_QTANGENT_STREAM, NewTokens);
			if (nStreams & (1 << VSF_TANGENTS))
				CParserBin::AddDefineToken(eT__FT_TANGENT_STREAM, NewTokens);
			if (nStreams & VSM_HWSKIN)
				CParserBin::AddDefineToken(eT__FT_SKIN_STREAM, NewTokens);
#if ENABLE_NORMALSTREAM_SUPPORT
			if (CParserBin::m_nPlatform == SF_D3D11 || CParserBin::m_nPlatform == SF_DURANGO || CParserBin::m_nPlatform == SF_ORBIS || CParserBin::m_nPlatform == SF_GL4 || CParserBin::m_nPlatform == SF_GLES3)
			{
				if (nStreams & VSM_NORMALS)
					CParserBin::AddDefineToken(eT__FT_NORMAL, NewTokens);
			}
#endif
			if (nStreams & VSM_VERTEX_VELOCITY)
				CParserBin::AddDefineToken(eT__FT_VERTEX_VELOCITY_STREAM, NewTokens);
		}
	}

	int nT = NewTokens.size();
	NewTokens.resize(nT + pSHData->size());
	memcpy(&NewTokens[nT], &(*pSHData)[0], pSHData->size() * sizeof(uint32));

	CParserBin Parser(NULL, pSH);
	Parser.Preprocess(1, NewTokens, Table);
	chair_CorrectScriptEnums(Parser, pInst, InstBindVars, Table);
	chair_RemoveUnaffectedParameters_D3D10(Parser, pInst, InstBindVars);
	chair_ConvertBinScriptToASCII(Parser, pInst, InstBindVars, Table, sNewScr);

	if (bTempMap)
	{
		SAFE_DELETE(Table);
		SAFE_DELETE(pSHData);
	}

	/* FILE *fp = gEnv->pCryPak->FOpen("fff", "w");
	   if (fp)
	   {
	   gEnv->pCryPak->FPrintf(fp, "%s", &sNewScr[0]);
	   gEnv->pCryPak->FClose (fp);
	   }*/

	return sNewScr.Num() && sNewScr[0];
}

void CHWShader_D3D::chair_CorrectScriptEnums(
	CParserBin& Parser,
	SHWSInstance* pInst,
	std::vector<SCGBind>& InstBindVars,
	FXShaderToken* Table)
{
	// correct enumeration of TEXCOORD# interpolators after preprocessing
	int nCur = 0;
	int nSize = Parser.m_Tokens.size();
	uint32* pTokens = &Parser.m_Tokens[0];
	int nInstParam = 0;
	const uint32 Toks[] = { eT_TEXCOORDN, eT_TEXCOORDN_centroid, eT_unknown };

	std::vector<SStructData> SData;
	uint32 i;
	while (true)
	{
		nCur = Parser.FindToken(nCur, nSize - 1, eT_struct);
		if (nCur < 0)
			break;
		int nLastStr = Parser.FindToken(nCur, nSize - 1, eT_br_cv_2);
		assert(nLastStr >= 0);
		if (nLastStr < 0)
			break;
		bool bNested = false;
		for (i = 0; i < SData.size(); i++)
		{
			SStructData& Data = SData[i];
			Data.m_nPos = Parser.FindToken(nCur, nLastStr, Data.m_nName);
			if (Data.m_nPos > 0)
				bNested = true;
		}
		uint32 nName = pTokens[nCur + 1];
		int n = 0;
		while (nCur < nLastStr)
		{
			int nTN = Parser.FindToken(nCur, nLastStr, Toks);
			if (nTN < 0)
			{
				nCur = nLastStr + 1;
				break;
			}
			int nNested = 0;
			if (bNested)
			{
				for (i = 0; i < SData.size(); i++)
				{
					SStructData& Data = SData[i];
					if (Data.m_nPos > 0 && nTN > Data.m_nPos)
						nNested += Data.m_nTCs;
				}
			}
			assert(pTokens[nTN - 1] == eT_colon);
			int nArrSize = 1;
			uint32 nTokName;
			if (pTokens[nTN - 2] == eT_br_sq_2)
			{
				nArrSize = pTokens[nTN - 3] - eT_0;
				if ((unsigned int)nArrSize > 15)
				{
					const char* szArrSize = Parser.GetString(pTokens[nTN - 3], *Table);
					nArrSize = szArrSize ? atoi(szArrSize) : 0;
				}
				assert(pTokens[nTN - 4] == eT_br_sq_1);
				//const char *szName = Parser.GetString(pTokens[nTN-5], *Table);
				nTokName = pTokens[nTN - 5];
			}
			else
			{
				uint32 nType = pTokens[nTN - 3];
				assert(nType == eT_float || nType == eT_float2 || nType == eT_float3 || nType == eT_float4 || nType == eT_float4x4 || nType == eT_float3x4 || nType == eT_float2x4 || nType == eT_float3x3 ||
					nType == eT_half || nType == eT_half2 || nType == eT_half3 || nType == eT_half4 || nType == eT_half4x4 || nType == eT_half3x4 || nType == eT_half2x4 || nType == eT_half3x3);
				if (nType == eT_float4x4 || nType == eT_half4x4)
					nArrSize = 4;
				else if (nType == eT_float3x4 || nType == eT_float3x3 || nType == eT_half3x4 || nType == eT_half3x3)
					nArrSize = 3;
				else if (nType == eT_float2x4 || nType == eT_half2x4)
					nArrSize = 2;
				nTokName = pTokens[nTN - 2];
			}
			assert(nArrSize > 0 && nArrSize < 16);

			EToken eT = (pTokens[nTN] == eT_TEXCOORDN) ? eT_TEXCOORD0 : eT_TEXCOORD0_centroid;

			pTokens[nTN] = n + nNested + eT;
			n += nArrSize;
			nCur = nTN + 1;

			if (pInst->m_Ident.m_RTMask & (*g_HWSR_MaskBit)[HWSR_INSTANCING_ATTR])
			{
				const char* szName = Parser.GetString(nTokName, *Table);
				if (!strnicmp(szName, "Inst", 4))
				{
					char newName[256];
					int nm = 0;
					while (szName[4 + nm] > 0x20 && szName[4 + nm] != '[')
					{
						newName[nm] = szName[4 + nm];
						nm++;
					}
					newName[nm++] = 0;

					SCGBind bn;
					bn.m_dwBind = nInstParam;
					bn.m_nParameters = nArrSize;
					bn.m_Name = newName;
					InstBindVars.push_back(bn);

					nInstParam += nArrSize;
				}
			}
		}
		SStructData SD;
		SD.m_nName = nName;
		SD.m_nPos = -1;
		SD.m_nTCs = n;
		SData.push_back(SD);
	}
	if (InstBindVars.size())
		qsort(&InstBindVars[0], InstBindVars.size(), sizeof(SCGBind), CGBindCallback);
	pInst->m_nNumInstAttributes = nInstParam;
}

bool CHWShader_D3D::chair_ConvertBinScriptToASCII(
	CParserBin& Parser,
	SHWSInstance* pInst,
	std::vector<SCGBind>& InstBindVars,
	FXShaderToken* Table,
	TArray<char>& Text)
{
	uint32 i;
	bool bRes = true;

	/*if (pInst->m_RTMask == 0x2000020000680104)
	   {
	   TArray<char> TempTx;
	   CParserBin::chair_ConvertToAscii(&Parser.m_Tokens[0], Parser.m_Tokens.size(), *Table, TempTx);
	   FILE *fp = gEnv->pCryPak->FOpen("inst.txt", "w");
	   if (fp)
	   {
		gEnv->pCryPak->FPrintf(fp, "%s", &TempTx[0]);
		gEnv->pCryPak->FClose (fp);
	   }
	   }*/
	uint32* pTokens = &Parser.m_Tokens[0];
	uint32 nT = Parser.m_Tokens.size();
	const char* szPrev = " ";
	int nLevel = 0;
	for (i = 0; i < nT; i++)
	{
		uint32 nToken = pTokens[i];
		if (nToken == 0)
		{
			Text.Copy("\n", 1);
			continue;
		}
		if (nToken == eT_skip)
		{
			i++;
			continue;
		}
		if (nToken == eT_skip_1)
		{
			while (i < nT)
			{
				nToken = pTokens[i];
				if (nToken == eT_skip_2)
					break;
				i++;
			}
			assert(i < nT);
			continue;
		}
		if (nToken == eT_fetchinst)
		{
			char str[512];
			i++;
			std::vector<uint32> ParamDst, ParamSrc;
			TArray<char> sParamDstFull, sParamDstName, sParamSrc;
			int nDst = sFetchInst(i, &Parser.m_Tokens[0], Parser.m_Tokens.size(), ParamDst);
			assert(Parser.m_Tokens[i] == eT_eq);
			if (Parser.m_Tokens[i] != eT_eq)
			{
				// Should never happen
				int n = CParserBin::FindToken(i, Parser.m_Tokens.size() - 1, &Parser.m_Tokens[0], eT_semicolumn);
				if (n > 0)
					i = n + 1;
				continue;
			}
			i++;
			int nSrc = sFetchInst(i, &Parser.m_Tokens[0], Parser.m_Tokens.size(), ParamSrc);
			CParserBin::chair_ConvertToAscii(&ParamDst[0], ParamDst.size(), *Table, sParamDstFull);
			CParserBin::chair_ConvertToAscii(&ParamDst[nDst], 1, *Table, sParamDstName);
			CParserBin::chair_ConvertToAscii(&ParamSrc[nSrc], 1, *Table, sParamSrc);
			assert(strncmp(&sParamSrc[0], "Inst", 4) == 0);

			{
				sParamSrc.Free();
				CParserBin::chair_ConvertToAscii(&ParamSrc[0], ParamSrc.size(), *Table, sParamSrc);
				cry_sprintf(str, "%s = %s;\n", &sParamDstFull[0], &sParamSrc[0]);
				Text.Copy(str, strlen(str));
			}
			while (Parser.m_Tokens[i] != eT_semicolumn)
			{
				i++;
			}
			continue;
		}
		const char* szStr = CParserBin::GetString(nToken, *Table, false);
		assert(szStr);
		if (!szStr || !szStr[0])
		{
			assert(0);
			bRes = CParserBin::chair_CorrectScript(pTokens, i, nT, Text);
		}
		else
		{
#if defined(_DEBUG) && !CRY_PLATFORM_ORBIS
			int n = 0;
			while (szStr[n])
			{
				char c = szStr[n++];
				bool bASC = isascii(c);
				assert(bASC);
			}
#endif
			if (nToken == eT_semicolumn || nToken == eT_br_cv_1)
			{
				if (nToken == eT_br_cv_1)
				{
					sCR(Text, nLevel);
					nLevel++;
				}
				Text.Copy(szStr, strlen(szStr));
				if (nToken == eT_semicolumn)
				{
					if (i + 1 < nT && pTokens[i + 1] == eT_br_cv_2)
						sCR(Text, nLevel - 1);
					else
						sCR(Text, nLevel);
				}
				else if (i + 1 < nT)
				{
					if (pTokens[i + 1] < eT_br_rnd_1 || pTokens[i + 1] >= eT_float)
						sCR(Text, nLevel);
				}
			}
			else
			{
				if (i + 1 < nT)
				{
					if (Text.Num())
					{
						char cPrev = Text[Text.Num() - 1];
						if (!SkipChar((uint8)cPrev) && !SkipChar((uint8)szStr[0]))
							Text.AddElem(' ');
					}
				}
				Text.Copy(szStr, strlen(szStr));
				if (nToken == eT_br_cv_2)
				{
					nLevel--;
					if (i + 1 < nT && pTokens[i + 1] != eT_semicolumn)
						sCR(Text, nLevel);
				}
			}
		}
	}
	Text.AddElem(0);

	return bRes;
}

void CHWShader_D3D::chair_RemoveUnaffectedParameters_D3D10(
	CParserBin& Parser,
	SHWSInstance* pInst,
	std::vector<SCGBind>& InstBindVars)
{
	int nPos = Parser.FindToken(0, Parser.m_Tokens.size() - 1, eT_cbuffer);
	while (nPos >= 0)
	{
		uint32 nName = Parser.m_Tokens[nPos + 1];
		if (nName == eT_PER_BATCH || nName == eT_PER_INSTANCE)
		{
			int nPosEnd = Parser.FindToken(nPos + 3, Parser.m_Tokens.size() - 1, eT_br_cv_2);
			assert(nPosEnd >= 0);
			int nPosN = Parser.FindToken(nPos + 1, Parser.m_Tokens.size() - 1, eT_br_cv_1);
			assert(nPosN >= 0);
			nPosN++;
			while (nPosN < nPosEnd)
			{
				uint32 nT = Parser.m_Tokens[nPosN + 1];
				int nPosCode = Parser.FindToken(nPosEnd + 1, Parser.m_Tokens.size() - 1, nT);
				if (nPosCode < 0)
				{
					assert(nPosN > 0 && nPosN < (int)Parser.m_Tokens.size());
					if (InstBindVars.size())
					{
						size_t i = 0;
						CCryNameR nm(Parser.GetString(nT));
						for (; i < InstBindVars.size(); i++)
						{
							SCGBind& b = InstBindVars[i];
							if (b.m_Name == nm)
								break;
						}
						if (i == InstBindVars.size())
							Parser.m_Tokens[nPosN] = eT_comment;
					}
					else
						Parser.m_Tokens[nPosN] = eT_comment;
				}
				nPosN = Parser.FindToken(nPosN + 2, nPosEnd, eT_semicolumn);
				assert(nPosN >= 0);
				nPosN++;
			}
			nPos = Parser.FindToken(nPosEnd + 1, Parser.m_Tokens.size() - 1, eT_cbuffer);
		}
		else
			nPos = Parser.FindToken(nPos + 2, Parser.m_Tokens.size() - 1, eT_cbuffer);
	}
	//#else
	/*int nStart = 0;
	   while (true)
	   {
	   uint32 nName = sFindVar(Parser, nStart);
	   if (nStart < 0)
		break;
	   bool bAffect = sIsAffectFuncs(Parser, nName);
	   if (!bAffect)
		Parser.m_Tokens[nStart] = eT_comment;
	   nStart++;
	   }*/
	   //#endif
}

//-----------------------------------------------------------------------------------

LPD3D10BLOB CHWShader_D3D::chair_mfCompileHLSL(CShader* pSH, char* prog_text, void** ppConstantTable, LPD3D10BLOB* ppErrorMsgs, uint32 nFlags, std::vector<SCGBind>& InstBindVars)
{
	//	LOADING_TIME_PROFILE_SECTION(iSystem);

	// Test adding source text to context
	SHWSInstance* pInst = m_pCurInst;
	string strErr;
	LPD3D10BLOB pCode = NULL;
	HRESULT hr = S_OK;
	if (!prog_text)
	{
		assert(0);
		return NULL;
	}

	if (!*CRenderer::CV_r_shadersAllowCompilation)
		return NULL;

	bool bResult = chair_mfCompileHLSL_Int(pSH, prog_text, &pCode, ppConstantTable, ppErrorMsgs, strErr, InstBindVars);
	if (!pCode)
	{
		if (*CRenderer::CV_r_shadersasynccompiling)
			return NULL;

		if (!pCode)
		{
			{
				mfOutputCompilerError(strErr, prog_text);

				CryWarning("Couldn't compile HW shader '{}'", GetName());
				chair_mfSaveCGFile(prog_text, NULL);
			}
		}
	}

	return pCode;
}

bool CHWShader_D3D::chair_mfCompileHLSL_Int(
	CShader* pSH,
	char* prog_text,
	LPD3D10BLOB* ppShader,
	void** ppConstantTable,
	LPD3D10BLOB* ppErrorMsgs,
	string& strErr,
	std::vector<SCGBind>& InstBindVars)
{
	HRESULT hr = S_OK;
	SHWSInstance* pInst = m_pCurInst;
	const char* szProfile = mfProfileString(pInst->m_eClass);
	const char* pFunCCryName = m_EntryFunc.c_str();

	bool bRes = true;

	if (*CRenderer::CV_r_shadersdebug == 2)
	{
		chair_mfSaveCGFile(prog_text, "TestCG");
	}

	if (*CRenderer::CV_r_shadersasynccompiling && !(m_Flags & HWSG_SYNC))
	{
		return chair_mfRequestAsync(pSH, pInst, InstBindVars, prog_text, szProfile, pFunCCryName);
	}
	else
	{
		uint32 nFlags = D3D10_SHADER_PACK_MATRIX_ROW_MAJOR | D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY;
		if (*CRenderer::CV_r_shadersdebug == 3 || *CRenderer::CV_r_shadersdebug == 4)
			nFlags |= D3D10_SHADER_DEBUG | D3D10_SHADER_SKIP_OPTIMIZATION;

		hr = D3DCompile(prog_text, strlen(prog_text), GetName(), NULL, NULL, pFunCCryName, szProfile, nFlags, 0, (ID3DBlob**)ppShader, (ID3DBlob**)ppErrorMsgs);
		if (FAILED(hr) || !*ppShader)
		{
			if (*ppErrorMsgs)
			{
				const char* err = (const char*)ppErrorMsgs[0]->GetBufferPointer();
				strErr += err;
			}
			else
			{
				strErr += "D3DXCompileShader failed";
			}
			bRes = false;
		}
		else
		{
			void* pShaderReflBuf;
			UINT* pData = (UINT*)ppShader[0]->GetBufferPointer();
			UINT nSize = (uint32)ppShader[0]->GetBufferSize();
			hr = D3DReflect(pData, nSize, IID_ID3D11ShaderReflection, &pShaderReflBuf);

			if (SUCCEEDED(hr))
			{
				ID3D11ShaderReflection* pShaderReflection = (ID3D11ShaderReflection*)pShaderReflBuf;
				*ppConstantTable = (void*)pShaderReflection;
			}
			else
			{
				assert(0);
			}
		}

		return bRes;
	}

	return false;
}

void CHWShader_D3D::chair_mfSaveCGFile(const char* scr, const char* path)
{
	if (*CRenderer::CV_r_shadersdebug < 1)
		return;
	char name[1024];
	if (path && path[0])
	{
		cry_sprintf(name, "%s/%s(LT%x)/(RT%I64x)(MD%x)(MDV%x)(GL%I64x)(PSS%llx).cg", path, GetName(), m_pCurInst->m_Ident.m_LightMask, m_pCurInst->m_Ident.m_RTMask, m_pCurInst->m_Ident.m_MDMask, m_pCurInst->m_Ident.m_MDVMask, m_pCurInst->m_Ident.m_GLMask, m_pCurInst->m_Ident.m_pipelineState.opaque);
	}
	else
	{
		cry_sprintf(name, "FXError/%s(GL%I64x)/(LT%x)(RT%I64x)/(MD%x)(MDV%x)(PSS%llx).cg", GetName(), m_pCurInst->m_Ident.m_GLMask, m_pCurInst->m_Ident.m_LightMask, m_pCurInst->m_Ident.m_RTMask, m_pCurInst->m_Ident.m_MDMask, m_pCurInst->m_Ident.m_MDVMask, m_pCurInst->m_Ident.m_pipelineState.opaque);
	}

	FILE* fp;

	fp = gEnv->pCryPak->FOpen(name, "w");

	if (fp)
	{
		size_t len = strlen(scr);
		gEnv->pCryPak->FWrite(scr, len, fp);
		gEnv->pCryPak->FClose(fp);
	}
}

//-----------------------------------------------------------------------------------

bool CHWShader_D3D::chair_mfRequestAsync(
	CShader* pSH,
	SHWSInstance* pInst,
	std::vector<SCGBind>& InstBindVars,
	const char* prog_text,
	const char* szProfile,
	const char* szEntry)
{
#ifdef SHADER_ASYNC_COMPILATION
	char nameSrc[256], nmDst[256];
	mfGetDstFileName(pInst, this, nmDst, 256, 3);
	gEnv->pCryPak->AdjustFileName(nmDst, nameSrc, 0);

	if (!SShaderAsyncInfo::PendingList().m_Next)
	{
		SShaderAsyncInfo::PendingList().m_Next = &SShaderAsyncInfo::PendingList();
		SShaderAsyncInfo::PendingList().m_Prev = &SShaderAsyncInfo::PendingList();
		SShaderAsyncInfo::PendingListT().m_Next = &SShaderAsyncInfo::PendingListT();
		SShaderAsyncInfo::PendingListT().m_Prev = &SShaderAsyncInfo::PendingListT();
	}

	if (!m_pGlobalCache || !m_pGlobalCache->m_pRes[CACHE_USER])
	{
		if (m_pGlobalCache)
			m_pGlobalCache->Release(false);
		m_pGlobalCache = mfInitCache(NULL, this, true, m_CRC32, false, false);
	}

	pInst->m_pAsync = new SShaderAsyncInfo;
	pInst->m_pAsync->m_fMinDistance = gRenDev->m_RP.m_fMinDistance;
	pInst->m_pAsync->m_nFrame = gRenDev->GetFrameID(false);
	pInst->m_pAsync->m_InstBindVars = InstBindVars;
	pInst->m_pAsync->m_pShader = this;
	pInst->m_pAsync->m_pShader->AddRef();
	pInst->m_pAsync->m_pFXShader = pSH;
	pInst->m_pAsync->m_pFXShader->AddRef();
	pInst->m_pAsync->m_nCombination = gRenDev->m_cEF.m_nCombinationsProcess;
	assert(!stricmp(m_NameSourceFX.c_str(), pInst->m_pAsync->m_pFXShader->m_NameFile.c_str()));
	InstContainer* pInstCont = &m_Insts;
	pInst->m_pAsync->m_nHashInstance = pInst->m_Ident.m_nHash;
	pInst->m_pAsync->m_RTMask = pInst->m_Ident.m_RTMask;
	pInst->m_pAsync->m_LightMask = pInst->m_Ident.m_LightMask;
	pInst->m_pAsync->m_MDMask = pInst->m_Ident.m_MDMask;
	pInst->m_pAsync->m_MDVMask = pInst->m_Ident.m_MDVMask;
	pInst->m_pAsync->m_pipelineState.opaque = pInst->m_Ident.m_pipelineState.opaque;
	pInst->m_pAsync->m_eClass = pInst->m_eClass;
	pInst->m_pAsync->m_Text = prog_text;
	pInst->m_pAsync->m_Name = szEntry;
	pInst->m_pAsync->m_Profile = szProfile;

	// Generate request line text to store on the shaderlist for next shader cache gen
	{
		char szShaderGenName[512];
		cry_strcpy(szShaderGenName, GetName());
		char* s = strchr(szShaderGenName, '(');
		if (s)
			s[0] = 0;
		string RequestLine;
		SShaderCombIdent Ident = pInst->m_Ident;
		Ident.m_GLMask = m_nMaskGenFX;
		gRenDev->m_cEF.mfInsertNewCombination(Ident, pInst->m_eClass, szShaderGenName, 0, &RequestLine, false);

		pInst->m_pAsync->m_RequestLine = RequestLine;
	}

	CAsyncShaderTask::InsertPendingShader(pInst->m_pAsync);

	if (CRenderer::CV_r_logShaders)
		gcpRendD3D->LogShv("Async %d: Requested compiling 0x%x '%s' shader\n", gRenDev->GetFrameID(false), pInst, nameSrc);
#endif
	return false;
}

//========================================================================================================
// Binary cache support

SShaderCache::~SShaderCache()
{
	if (m_pStreamInfo)
	{
		CResFile* pRes = m_pStreamInfo->m_pRes;
		bool bWarn = false;
		if (pRes)
		{
			assert(pRes == m_pRes[0] || pRes == m_pRes[1]);
			assert(!pRes->chair_mfIsDirStreaming());
			//bWarn = pRes->mfIsDirStreaming();
		}
		/*if (m_pStreamInfo->m_EntriesQueue.size())
		   bWarn = true;
		   if (bWarn)
		   Warning("Warning: SShader`Cache::~SShaderCache(): '%s' Streaming tasks is still in progress!: %d", m_Name.c_str(), m_pStreamInfo->m_EntriesQueue.size());*/

		m_pStreamInfo->AbortJobs();
	}

	CHWShader::m_ShaderCache->erase(m_Name);
	SAFE_DELETE(m_pRes[CACHE_USER]);
	SAFE_DELETE(m_pRes[CACHE_READONLY]);
	SAFE_RELEASE(m_pStreamInfo);
}
