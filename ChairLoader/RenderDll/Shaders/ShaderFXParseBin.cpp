// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

/*=============================================================================
   ShaderFXParseBin.cpp : implementation of the Shaders parser using FX language.

   Revision history:
* Created by Honich Andrey

   =============================================================================*/

#include <Prey/CryCore/Platform/IPlatformOS.h>
#include <Prey/CryCore/AlignmentTools.h>
#include <Prey/RenderDll/Common/CommonRender.h>
#include <Prey/RenderDll/Common/Textures/TextureHelpers.h>
#include <Prey/RenderDll/Common/Shaders/CShaderBin.h>
#include <Prey/RenderDll/Common/Shaders/Parser.h>
#include <Prey/RenderDll/Common/Renderer.h>
#include <d3d9types.h>

static FOURCC FOURCC_SHADERBIN = MAKEFOURCC('F', 'X', 'B', '0');

namespace
{
static std::vector<SFXParam> s_tempFXParams;
}

SShaderBin SShaderBin::s_Root;
uint32 SShaderBin::s_nCache = 0;
uint32 SShaderBin::s_nMaxFXBinCache = MAX_FXBIN_CACHE;

SShaderBin* CShaderManBin::SearchInCache(const char* szName, bool bInclude)
{
	char nameFile[256], nameLwr[256];
	cry_strcpy(nameLwr, szName);
	strlwr(nameLwr);
	cry_sprintf(nameFile, "%s.%s", nameLwr, bInclude ? "cfi" : "cfx");
	uint32 dwName = CParserBin::GetCRC32(nameFile);

	SShaderBin* pSB;
	for (pSB = SShaderBin::s_Root.m_Prev; pSB != &SShaderBin::s_Root; pSB = pSB->m_Prev)
	{
		if (pSB->m_dwName == dwName)
		{
			pSB->Unlink();
			pSB->Link(&SShaderBin::s_Root);
			return pSB;
		}
	}
	return NULL;
}

SShaderBin* CShaderManBin::GetBinShader(const char* szName, bool bInclude, uint32 nRefCRC, bool* pbChanged)
{
	//static float sfTotalTime = 0.0f;

	if (pbChanged)
	{
		if (gRenDev->IsEditorMode())
			*pbChanged = false;
	}

	//float fTime0 = iTimer->GetAsyncCurTime();

	SShaderBin* pSHB = SearchInCache(szName, bInclude);
	if (pSHB)
		return pSHB;
	SShaderBinHeader Header[2];
	memset(&Header, 0, 2 * sizeof(SShaderBinHeader));
	char nameFile[256], nameBin[256];
	FILE* fpSrc = NULL;
	uint32 nSourceCRC32 = 0;
	cry_sprintf(nameFile, "%sCryFX/%s.%s", gRenDev->m_cEF.m_ShadersPath, szName, bInclude ? "cfi" : "cfx");
	fpSrc = gEnv->pCryPak->FOpen(nameFile, "rb");
	nSourceCRC32 = fpSrc ? gEnv->pCryPak->ComputeCRC(nameFile) : 0;
	//char szPath[1024];
	//getcwd(szPath, 1024);
	cry_sprintf(nameBin, "%s%s.%s", m_pCEF->m_ShadersCache, szName, bInclude ? "cfib" : "cfxb");
	FILE* fpDst = NULL;
	int i = 0, n = 2;

	// don't load from the shadercache.pak when in editing mode
	if (*CRenderer::CV_r_shadersediting)
		i = 1;

	string szDst = m_pCEF->m_szUserPath + nameBin;
	byte bValid = 0;
	float fVersion = (float)FX_CACHE_VER;
	for (; i < n; i++)
	{
		if (fpDst)
			gEnv->pCryPak->FClose(fpDst);
		if (!i)
		{
			if (n == 2)
			{
				char nameLwr[256];
				cry_sprintf(nameLwr, "%s.%s", szName, bInclude ? "cfi" : "cfx");
				strlwr(nameLwr);
				uint32 dwName = CParserBin::GetCRC32(nameLwr);
				FXShaderBinValidCRCItor itor = m_BinValidCRCs.find(dwName);
				if (itor != m_BinValidCRCs.end())
				{
					assert(itor->second == false);
					continue;
				}
			}
			fpDst = gEnv->pCryPak->FOpen(nameBin, "rb");
		}
		else
			fpDst = gEnv->pCryPak->FOpen(szDst.c_str(), "rb", ICryPak::FLAGS_NEVER_IN_PAK | ICryPak::FLAGS_PATH_REAL | ICryPak::FOPEN_ONDISK);
		if (!fpDst)
			continue;
		else
		{
			gEnv->pCryPak->FReadRaw(&Header[i], 1, sizeof(SShaderBinHeader), fpDst);

#if !defined(_RELEASE) && !defined(IS_EAAS)
			// check source crc changes
			if (nSourceCRC32 && nSourceCRC32 != Header[i].m_nSourceCRC32)
			{
				bValid |= 1 << i;
			}
			else
#endif
			{
				uint16 MinorVer = (uint16)(((float)fVersion - (float)(int)fVersion) * 10.1f);
				uint16 MajorVer = (uint16)fVersion;
				if (Header[i].m_VersionLow != MinorVer || Header[i].m_VersionHigh != MajorVer || Header[i].m_Magic != FOURCC_SHADERBIN)
					bValid |= 4 << i;
				else if (nRefCRC && Header[i].m_CRC32 != nRefCRC)
					bValid |= 0x10 << i;
			}
		}
		if (!(bValid & (0x15 << i)))
			break;
	}
	if (i == n)
	{
#if !defined(_RELEASE) && !defined(CONSOLE_CONST_CVAR_MODE) && !defined(IS_EAAS)
		{
			char acTemp[512];
			if (bValid & 1)
			{
				cry_sprintf(acTemp, "WARNING: Bin FXShader '%s' source crc mismatch", nameBin);
			}
			if (bValid & 4)
			{
				cry_sprintf(acTemp, "WARNING: Bin FXShader '%s' version mismatch (Cache: %u.%u, Expected: %.1f)", nameBin, Header[0].m_VersionHigh, Header[0].m_VersionLow, fVersion);
			}
			if (bValid & 0x10)
			{
				cry_sprintf(acTemp, "WARNING: Bin FXShader '%s' CRC mismatch", nameBin);
			}

			if (bValid & 2)
			{
				cry_sprintf(acTemp, "WARNING: Bin FXShader USER '%s' source crc mismatch", nameBin);
			}
			if (bValid & 8)
			{
				cry_sprintf(acTemp, "WARNING: Bin FXShader USER '%s' version mismatch (Cache: %u.%u, Expected: %.1f)", nameBin, Header[1].m_VersionHigh, Header[1].m_VersionLow, fVersion);
			}
			if (bValid & 0x20)
			{
				cry_sprintf(acTemp, "WARNING: Bin FXShader USER '%s' CRC mismatch", nameBin);
			}

			if (bValid)
			{
				CryWarning("%s", acTemp);
			}

			if (fpDst)
			{
				gEnv->pCryPak->FClose(fpDst);
				fpDst = NULL;
			}

			if (fpSrc)
			{
				// enable shader compilation again, and show big error message
				if (!*CRenderer::CV_r_shadersAllowCompilation)
				{
					if (*CRenderer::CV_r_shaderscompileautoactivate)
					{
						*CRenderer::CV_r_shadersAllowCompilation = 1;
						*CRenderer::CV_r_shadersasyncactivation = 0;

						gEnv->pLog->LogError("ERROR LOADING BIN SHADER - REACTIVATING SHADER COMPILATION !");
					}
					else
					{
						static bool bShowMessageBox = true;

						if (bShowMessageBox)
						{
							IPlatformOS::EMsgBoxResult result;

							IPlatformOS* pOS = gEnv->pSystem->GetPlatformOS();
							if (pOS)
							{
								result = pOS->DebugMessageBox(acTemp, "Invalid ShaderCache");

								if (result == IPlatformOS::eMsgBox_Cancel)
								{
									CryDebugBreak();
								}
								else
								{
									bShowMessageBox = false;
									Sleep(33);
								}
							}
							else
							{
								CryWarning("Invalid ShaderCache");
							}
						}
					}
				}

				if (*CRenderer::CV_r_shadersAllowCompilation)
				{
					pSHB = SaveBinShader(nSourceCRC32, szName, bInclude, fpSrc);
					assert(!pSHB->m_Next);
					if (pbChanged)
						*pbChanged = true;

					// remove the entries in the looupdata, to be sure that level and global caches have also become invalid for these shaders!
					gRenDev->m_cEF.m_ResLookupDataMan[CACHE_READONLY].RemoveData(Header[0].m_CRC32);
					gRenDev->m_cEF.m_ResLookupDataMan[CACHE_USER].RemoveData(Header[1].m_CRC32);

					// has the shader been successfully written to the dest address
					fpDst = gEnv->pCryPak->FOpen(szDst.c_str(), "rb", ICryPak::FLAGS_NEVER_IN_PAK | ICryPak::FLAGS_PATH_REAL | ICryPak::FOPEN_ONDISK);
					if (fpDst)
					{
						SAFE_DELETE(pSHB);
						i = 1;
					}
				}
			}
		}
#endif
	}
	if (fpSrc)
		gEnv->pCryPak->FClose(fpSrc);
	fpSrc = NULL;

	if (!*CRenderer::CV_r_shadersAllowCompilation)
	{
		if (pSHB == 0 && !fpDst)
		{
			//do only perform the necessary stuff
			fpDst = gEnv->pCryPak->FOpen(nameBin, "rb");
		}
	}
	if (pSHB == 0 && fpDst)
	{
		cry_sprintf(nameFile, "%s.%s", szName, bInclude ? "cfi" : "cfx");
		pSHB = LoadBinShader(fpDst, nameFile, i == 0 ? nameBin : szDst.c_str(), !bInclude);
		gEnv->pCryPak->FClose(fpDst);
		assert(pSHB);
	}

	if (pSHB)
	{
		if (i == 0)
			pSHB->m_bReadOnly = true;
		else
			pSHB->m_bReadOnly = false;

		AddToCache(pSHB, bInclude);
		if (!bInclude)
		{
			char nm[128];
			nm[0] = '$';
			cry_strcpy(&nm[1], sizeof(nm) - 1, szName);
			CCryNameTSCRC NM = CParserBin::GetPlatformSpecName(nm);
			FXShaderBinPathItor it = m_BinPaths.find(NM);
			if (it == m_BinPaths.end())
				m_BinPaths.insert(FXShaderBinPath::value_type(NM, i == 0 ? string(nameBin) : szDst));
			else
				it->second = (i == 0) ? string(nameBin) : szDst;
		}
	}
	else
	{
		if (fpDst)
			CryWarning("Error: Failed to get binary shader '%s'", nameFile);
		else
		{
			cry_sprintf(nameFile, "%s.%s", szName, bInclude ? "cfi" : "cfx");
			const char* matName = 0;
			if (m_pCEF && m_pCEF->m_pCurInputResources)
				matName = m_pCEF->m_pCurInputResources->m_szMaterialName;
			CryWarning("Error: Shader \"%s\" doesn't exist (used in material \"%s\")", nameFile, matName != 0 ? matName : "$unknown$");
		}
	}

	/*
	   sfTotalTime += iTimer->GetAsyncCurTime() - fTime0;

	   {
	   char acTmp[1024];
	   cry_sprintf(acTmp, "Parsing of bin took: %f \n", sfTotalTime);
	   OutputDebugString(acTmp);
	   }
	 */

	return pSHB;
}

SShaderBin* CShaderManBin::SaveBinShader(
	uint32 nSourceCRC32, const char* szName, bool bInclude, FILE* fpSrc)
{
	SShaderBin* pBin = new SShaderBin;

	CParserBin Parser(pBin);

	gEnv->pCryPak->FSeek(fpSrc, 0, SEEK_END);
	int nSize = gEnv->pCryPak->FTell(fpSrc);
	char* buf = new char[nSize + 1];
	char* pBuf = buf;
	buf[nSize] = 0;
	gEnv->pCryPak->FSeek(fpSrc, 0, SEEK_SET);
	gEnv->pCryPak->FRead(buf, nSize, fpSrc);

	RemoveCR(buf);
	const char* kWhiteSpace = " ";

	while (buf && buf[0])
	{
		SkipCharacters(&buf, kWhiteSpace);
		SkipComments(&buf, true);
		if (!buf || !buf[0])
			break;

		char com[1024];
		bool bKey = false;
		uint32 dwToken = CParserBin::NextToken(buf, com, bKey);
		dwToken = Parser.NewUserToken(dwToken, com, false);
		pBin->m_Tokens.push_back(dwToken);

		SkipCharacters(&buf, kWhiteSpace);
		SkipComments(&buf, true);
		if (dwToken >= eT_float && dwToken <= eT_int)
		{

		}
		if (dwToken == eT_fetchinst)
		{
			int nnn = 0;
		}
		else if (dwToken == eT_include)
		{
			assert(bKey);
			SkipCharacters(&buf, kWhiteSpace);
			assert(*buf == '"' || *buf == '<');
			char brak = *buf;
			++buf;
			int n = 0;
			while (*buf != brak)
			{
				if (*buf <= 0x20)
				{
					assert(0);
					break;
				}
				com[n++] = *buf;
				++buf;
			}
			if (*buf == brak)
				++buf;
			com[n] = 0;

			fpStripExtension(com, com);

			SShaderBin* pBIncl = GetBinShader(com, true, 0);
			//
			//assert(pBIncl);

			dwToken = CParserBin::fxToken(com, NULL);
			dwToken = Parser.NewUserToken(dwToken, com, false);
			pBin->m_Tokens.push_back(dwToken);
		}
		else if (dwToken == eT_if || dwToken == eT_ifdef || dwToken == eT_ifndef || dwToken == eT_elif)
		{
			bool bFirst = fxIsFirstPass(buf);
			if (!bFirst)
			{
				if (dwToken == eT_if)
					dwToken = eT_if_2;
				else if (dwToken == eT_ifdef)
					dwToken = eT_ifdef_2;
				else if (dwToken == eT_elif)
					dwToken = eT_elif_2;
				else
					dwToken = eT_ifndef_2;
				pBin->m_Tokens[pBin->m_Tokens.size() - 1] = dwToken;
			}
		}
		else if (dwToken == eT_define)
		{
			shFill(&buf, com);
			if (com[0] == '%')
				pBin->m_Tokens[pBin->m_Tokens.size() - 1] = eT_define_2;
			dwToken = Parser.NewUserToken(eT_unknown, com, false);
			pBin->m_Tokens.push_back(dwToken);

			TArray<char> macro;
			while (*buf == 0x20 || *buf == 0x9)
			{
				buf++;
			}
			while (*buf != 0xa)
			{
				if (*buf == '\\')
				{
					macro.AddElem('\n');
					while (*buf != '\n')
					{
						buf++;
					}
					buf++;
					continue;
				}
				macro.AddElem(*buf);
				buf++;
			}
			macro.AddElem(0);
			int n = macro.Num() - 2;
			while (n >= 0 && macro[n] <= 0x20)
			{
				macro[n] = 0;
				n--;
			}
			char* b = &macro[0];
			while (*b)
			{
				SkipCharacters(&b, kWhiteSpace);
				SkipComments(&b, true);
				if (!b[0])
					break;
				bKey = false;
				dwToken = CParserBin::NextToken(b, com, bKey);
				dwToken = Parser.NewUserToken(dwToken, com, false);
				if (dwToken == eT_if || dwToken == eT_ifdef || dwToken == eT_ifndef || dwToken == eT_elif)
				{
					bool bFirst = fxIsFirstPass(b);
					if (!bFirst)
					{
						if (dwToken == eT_if)
							dwToken = eT_if_2;
						else if (dwToken == eT_ifdef)
							dwToken = eT_ifdef_2;
						else if (dwToken == eT_elif)
							dwToken = eT_elif_2;
						else
							dwToken = eT_ifndef_2;
					}
				}
				pBin->m_Tokens.push_back(dwToken);
			}
			pBin->m_Tokens.push_back(0);
		}
	}
	if (!pBin->m_Tokens[0])
		pBin->m_Tokens.push_back(eT_skip);

	pBin->SetCRC(pBin->ComputeCRC());
	pBin->m_bReadOnly = false;
	//pBin->CryptData();
	//pBin->CryptTable();

	char nameFile[256];
	cry_sprintf(nameFile, "%s%s.%s", m_pCEF->m_ShadersCache, szName, bInclude ? "cfib" : "cfxb");
	stack_string szDst = stack_string(m_pCEF->m_szUserPath.c_str()) + stack_string(nameFile);
	const char* szFileName = szDst;

	FILE* fpDst = gEnv->pCryPak->FOpen(szFileName, "wb", ICryPak::FLAGS_NEVER_IN_PAK | ICryPak::FLAGS_PATH_REAL | ICryPak::FOPEN_ONDISK);
	if (fpDst)
	{
		SShaderBinHeader Header;
		Header.m_nTokens = pBin->m_Tokens.size();
		Header.m_Magic = FOURCC_SHADERBIN;
		Header.m_CRC32 = pBin->m_CRC32;
		float fVersion = (float)FX_CACHE_VER;
		Header.m_VersionLow = (uint16)(((float)fVersion - (float)(int)fVersion) * 10.1f);
		Header.m_VersionHigh = (uint16)fVersion;
		Header.m_nOffsetStringTable = pBin->m_Tokens.size() * sizeof(DWORD) + sizeof(Header);
		Header.m_nOffsetParamsLocal = 0;
		Header.m_nSourceCRC32 = nSourceCRC32;
		SShaderBinHeader hdTemp, * pHD;
		pHD = &Header;
		gEnv->pCryPak->FWrite((void*)pHD, sizeof(Header), 1, fpDst);
		gEnv->pCryPak->FWrite(&pBin->m_Tokens[0], pBin->m_Tokens.size() * sizeof(DWORD), 1, fpDst);
		FXShaderTokenItor itor;
		for (itor = pBin->m_TokenTable.begin(); itor != pBin->m_TokenTable.end(); itor++)
		{
			STokenD T = *itor;
			gEnv->pCryPak->FWrite(&T.Token, sizeof(DWORD), 1, fpDst);
			gEnv->pCryPak->FWrite(T.SToken.c_str(), T.SToken.size() + 1, 1, fpDst);
		}
		Header.m_nOffsetParamsLocal = gEnv->pCryPak->FTell(fpDst);
		gEnv->pCryPak->FSeek(fpDst, 0, SEEK_SET);
		gEnv->pCryPak->FWrite((void*)pHD, sizeof(Header), 1, fpDst);
		gEnv->pCryPak->FClose(fpDst);
	}
	else
	{
		gEnv->pLog->LogWarning("CShaderManBin::SaveBinShader: Cannot write shader to file '%s'.", nameFile);
		pBin->m_bReadOnly = true;
	}

	SAFE_DELETE_ARRAY(pBuf);

	return pBin;
}

bool CShaderManBin::AddToCache(SShaderBin* pSB, bool bInclude)
{
	if (!*CRenderer::CV_r_shadersediting)
	{
		if (SShaderBin::s_nCache >= SShaderBin::s_nMaxFXBinCache)
		{
			SShaderBin* pS;
			for (pS = SShaderBin::s_Root.m_Prev; pS != &SShaderBin::s_Root; pS = pS->m_Prev)
			{
				if (!pS->m_bLocked)
				{
					DeleteFromCache(pS);
					break;
				}
			}
		}
		assert(SShaderBin::s_nCache < SShaderBin::s_nMaxFXBinCache);
	}

	pSB->m_bInclude = bInclude;
	pSB->Link(&SShaderBin::s_Root);
	SShaderBin::s_nCache++;

	return true;
}
