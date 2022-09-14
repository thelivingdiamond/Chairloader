#include <Prey/RenderDll/Common/CommonRender.h>
#include <Prey/RenderDll/Common/Shaders/CShader.h>
#include <Prey/RenderDll/Common/Shaders/Parser.h>
#include <Prey/RenderDll/Common/Renderer.h>

static int sEOF(bool bFromFile, char* pPtr, FILE* fp)
{
	int nStatus;
	if (bFromFile)
		nStatus = gEnv->pCryPak->FEof(fp);
	else
	{
		SkipCharacters(&pPtr, kWhiteSpace);
		if (!*pPtr)
			nStatus = 1;
		else
			nStatus = 0;
	}
	return nStatus;
}

static uint64 sGetGL(char** s, CCryNameR& name, uint32& nHWFlags)
{
	uint32 i;

	nHWFlags = 0;
	SShaderGenComb* c = NULL;
	const char* m = strchr(name.c_str(), '@');
	if (!m)
		m = strchr(name.c_str(), '/');
	assert(m);
	if (!m)
		return -1;
	char nmFX[128];
	char nameExt[128];
	nameExt[0] = 0;
	cry_strcpy(nmFX, name.c_str(), (size_t)(m - name.c_str()));
	c = gRenDev->m_cEF.mfGetShaderGenInfo(nmFX);
	if (!c || !c->pGen || !c->pGen->m_BitMask.Num())
		return 0;
	uint64 nGL = 0;
	SShaderGen* pG = c->pGen;
	while (true)
	{
		char theChar;
		int n = 0;
		while ((theChar = **s) != 0)
		{
			if (theChar == ')' || theChar == '|')
			{
				nameExt[n] = 0;
				break;
			}
			nameExt[n++] = theChar;
			++* s;
		}
		if (!nameExt[0])
			break;
		for (i = 0; i < pG->m_BitMask.Num(); i++)
		{
			SShaderGenBit* pBit = pG->m_BitMask[i];
			if (!stricmp(pBit->m_ParamName.c_str(), nameExt))
			{
				nGL |= pBit->m_Mask;
				break;
			}
		}
		if (i == pG->m_BitMask.Num())
		{
			if (!strncmp(nameExt, "0x", 2))
			{
				//nGL |= shGetHex(&nameExt[2]);
			}
			else
			{
				//assert(0);
				if (*CRenderer::CV_r_shadersdebug)
					gEnv->pLog->Log("WARNING: Couldn't find global flag '%s' in shader '%s' (skipped)", nameExt, c->Name.c_str());
			}
		}
		if (**s == '|')
			++* s;
	}
	return nGL;
}

static void sSkipLine(char*& s)
{
	if (!s) return;

	char* sEnd = strchr(s, '\n');
	if (sEnd)
	{
		sEnd++;
		s = sEnd;
	}
}

static inline bool IsHexDigit(int ch)
{
	const int nDigit = (ch - int('0'));
	const int bHex = (ch - int('a'));
	return ((nDigit >= 0) && (nDigit <= 9)) || ((bHex >= 0) && (bHex < 6));
}

static uint64 sGetRT(char** s)
{
	uint32 i;

	SShaderGen* pG = gRenDev->m_cEF.m_pGlobalExt;
	if (!pG)
		return 0;
	uint64 nRT = 0;
	char nm[128] = { 0 };
	while (true)
	{
		char theChar;
		int n = 0;
		while ((theChar = **s) != 0)
		{
			if (theChar == ')' || theChar == '|')
			{
				nm[n] = 0;
				break;
			}
			nm[n++] = theChar;
			++* s;
		}
		if (!nm[0])
			break;
		for (i = 0; i < pG->m_BitMask.Num(); i++)
		{
			SShaderGenBit* pBit = pG->m_BitMask[i];
			if (!stricmp(pBit->m_ParamName.c_str(), nm))
			{
				nRT |= pBit->m_Mask;
				break;
			}
		}
		if (i == pG->m_BitMask.Num())
		{
			//assert(0);
			//      gEnv->pLog->Log("WARNING: Couldn't find runtime flag '%s' (skipped)", nm);
		}
		if (**s == '|')
			++* s;
	}
	return nRT;
}

static void sIterateHW_r(FXShaderCacheCombinations* Combinations, SCacheCombination& cmb, int i, uint64 nHW, const char* szName)
{
	string str;
	gRenDev->m_cEF.mfInsertNewCombination(cmb.Ident, cmb.eCL, szName, 0, &str, false);
	CCryNameR nm = CCryNameR(str.c_str());
	FXShaderCacheCombinationsItor it = Combinations->find(nm);
	if (it == Combinations->end())
	{
		cmb.CacheName = str.c_str();
		Combinations->insert(FXShaderCacheCombinationsItor::value_type(nm, cmb));
	}
	for (int j = i; j < 64; j++)
	{
		if (((uint64)1 << j) & nHW)
		{
			cmb.Ident.m_GLMask &= ~((uint64)1 << j);
			sIterateHW_r(Combinations, cmb, j + 1, nHW, szName);
			cmb.Ident.m_GLMask |= ((uint64)1 << j);
			sIterateHW_r(Combinations, cmb, j + 1, nHW, szName);
		}
	}

}

bool CShaderMan::CheckAllFilesAreWritable(const char* szDir) const
{
#if CRY_PLATFORM_WINDOWS
	assert(szDir);

	ICryPak* pack = gEnv->pCryPak;
	assert(pack);

	string sPathWithFilter = string(szDir) + "/*.*";

	// Search files that match filter specification.
	_finddata_t fd;
	int res;
	intptr_t handle;
	if ((handle = pack->FindFirst(sPathWithFilter.c_str(), &fd)) != -1)
	{
		do
		{
			if ((fd.attrib & _A_SUBDIR) == 0)
			{
				string fullpath = string(szDir) + "/" + fd.name;

				FILE* out = pack->FOpen(fullpath.c_str(), "rb");
				if (!out)
				{
					res = pack->FindNext(handle, &fd);
					continue;
				}
				if (pack->IsInPak(out))
				{
					pack->FClose(out);
					res = pack->FindNext(handle, &fd);
					continue;
				}
				pack->FClose(out);

				out = pack->FOpen(fullpath.c_str(), "ab");

				if (out)
					pack->FClose(out);
				else
				{
					gEnv->pLog->LogError("ERROR: Shader cache is not writable (file: '%s')", fullpath.c_str());
					return false;
				}
			}

			res = pack->FindNext(handle, &fd);
		} while (res >= 0);

		pack->FindClose(handle);

		gEnv->pLog->LogToFile("Shader cache directory '%s' was successfully tested for being writable", szDir);
	}
	else
		CryLog("Shader cache directory '%s' does not exist", szDir);

#endif

	return true;
}

void CShaderMan::mfInitShadersCache(byte bForLevel, FXShaderCacheCombinations* Combinations, const char* pCombinations, int nType)
{
	COMPILE_TIME_ASSERT(SHADER_LIST_VER != SHADER_SERIALISE_VER);

	char str[2048];
	bool bFromFile = (Combinations == NULL);
	stack_string nameComb;
	m_ShaderCacheExportCombinations.clear();
	FILE* fp = NULL;
	if (bFromFile)
	{
		if (!gRenDev->IsEditorMode() && !*CRenderer::CV_r_shadersdebug && !gRenDev->IsShaderCacheGenMode())
			return;
		mfGetShaderListPath(nameComb, nType);
		fp = gEnv->pCryPak->FOpen(nameComb.c_str(), "r+");
		if (!fp)
			fp = gEnv->pCryPak->FOpen(nameComb.c_str(), "w+");
		if (!fp)
		{
			gEnv->pCryPak->AdjustFileName(nameComb.c_str(), str, 0);
			FILE* statusdst = fopen(str, "rb");
			if (statusdst)
			{
				fclose(statusdst);
				CrySetFileAttributes(str, FILE_ATTRIBUTE_ARCHIVE);
				fp = gEnv->pCryPak->FOpen(nameComb.c_str(), "r+");
			}
		}
		m_FPCacheCombinations[nType] = fp;
		Combinations = &m_ShaderCacheCombinations[nType];
	}

	int nLine = 0;
	char* pPtr = (char*)pCombinations;
	char* ss;
	if (fp || !bFromFile)
	{
		while (!sEOF(bFromFile, pPtr, fp))
		{
			nLine++;

			str[0] = 0;
			if (bFromFile)
				gEnv->pCryPak->FGets(str, 2047, fp);
			else
				fxFillCR(&pPtr, str);
			if (!str[0])
				continue;
			bool bNewFormat = false;

			if (str[0] == '/' && str[1] == '/')     // commented line e.g. // BadLine: Metal@Common_ShadowPS(%BIllum@IlluminationPS(%DIFFUSE|%ENVCMAMB|%ALPHAGLOW|%STAT_BRANCHING)(%_RT_AMBIENT|%_RT_BUMP|%_RT_GLOW)(101)(0)(0)(ps_2_0)
				continue;

			bool bExportEntry = false;
			int size = strlen(str);
			if (str[size - 1] == 0xa)
				str[size - 1] = 0;
			SCacheCombination cmb;
			char* s = str;
			SkipCharacters(&s, kWhiteSpace);
			if (s[0] != '<')
				continue;
			char* st;
			if (!bForLevel)
			{
				int nVer = atoi(&s[1]);
				if (nVer != SHADER_LIST_VER)
				{
					if (nVer == SHADER_SERIALISE_VER && bFromFile)
					{
						bExportEntry = true;
					}
					else
					{
						continue;
					}
				}
				if (s[2] != '>')
					continue;
				s += 3;
			}
			else
			{
				st = s;
				s = strchr(&st[1], '>');
				if (!s)
					continue;
				cmb.nCount = atoi(st);
				s++;
			}
			if (bForLevel == 2)
			{
				st = s;
				if (s[0] != '<')
					continue;
				s = strchr(st, '>');
				if (!s)
					continue;
				int nVer = atoi(&st[1]);

				if (nVer != SHADER_LIST_VER)
				{
					if (nVer == SHADER_SERIALISE_VER)
					{
						bExportEntry = true;
					}
					else
					{
						continue;
					}
				}
				s++;
			}
			st = s;
			s = strchr(s, '(');
			char name[128];
			if (s)
			{
				memcpy(name, st, s - st);
				name[s - st] = 0;
				cmb.Name = name;
				s++;
			}
			else
			{
				continue;
			}
			uint32 nHW = 0;
			cmb.Ident.m_GLMask = sGetGL(&s, cmb.Name, nHW);
			if (cmb.Ident.m_GLMask == -1)
			{
				const char* szFileName = nameComb.c_str();
				if (szFileName)
				{
					gEnv->pLog->Log("Error: Error in '%s' file (Line: %d)", szFileName, nLine);
				}
				else
				{
					assert(!bFromFile);
					gEnv->pLog->Log("Error: Error in non-file shader (Line: %d)", nLine);
				}
				sSkipLine(s);
				goto end;
			}

			ss = strchr(s, '(');
			if (!ss)
			{
				sSkipLine(s);
				goto end;
			}
			s = ss + 1;
			cmb.Ident.m_RTMask = sGetRT(&s);

			ss = strchr(s, '(');
			if (!ss)
			{
				sSkipLine(s);
				goto end;
			}
			s = ss + 1;
			cmb.Ident.m_LightMask = shGetHex(s);

			ss = strchr(s, '(');
			if (!ss)
			{
				sSkipLine(s);
				goto end;
			}
			s = ss + 1;
			cmb.Ident.m_MDMask = shGetHex(s);

			ss = strchr(s, '(');
			if (!ss)
			{
				sSkipLine(s);
				goto end;
			}
			s = ss + 1;
			cmb.Ident.m_MDVMask = shGetHex(s);

			ss = strchr(s, '(');
			if (!ss)
			{
				sSkipLine(s);
				goto end;
			}
			if (IsHexDigit(ss[1]) && (ss[2] != 'S'))
			{
				s = ss + 1;
				cmb.Ident.m_pipelineState.opaque = shGetHex64(s);
				bNewFormat = true;
				s = strchr(s, '(');
			}
			else
			{
				cmb.Ident.m_pipelineState.opaque = 0;
				s = ss;
			}
			if (s)
			{
				s++;
				cmb.eCL = CHWShader::mfStringClass(s);
				assert(cmb.eCL < eHWSC_Num);
			}
			else
				cmb.eCL = eHWSC_Num;
			if (bNewFormat)
			{
				CCryNameR nm = CCryNameR(st);
				if (bExportEntry)
				{
					FXShaderCacheCombinationsItor it = m_ShaderCacheExportCombinations.find(nm);
					if (it == m_ShaderCacheExportCombinations.end())
					{
						cmb.CacheName = nm;
						m_ShaderCacheExportCombinations.insert(FXShaderCacheCombinationsItor::value_type(nm, cmb));
					}
				}
				else
				{
					FXShaderCacheCombinationsItor it = Combinations->find(nm);
					if (it != Combinations->end())
					{
						//assert(false);
					}
					else
					{
						cmb.CacheName = nm;
						Combinations->insert(FXShaderCacheCombinationsItor::value_type(nm, cmb));
					}
					if (nHW)
					{
						for (int j = 0; j < 64; j++)
						{
							if (((uint64)1 << j) & nHW)
							{
								cmb.Ident.m_GLMask &= ~((uint64)1 << j);
								sIterateHW_r(Combinations, cmb, j + 1, nHW, name);
								cmb.Ident.m_GLMask |= ((uint64)1 << j);
								sIterateHW_r(Combinations, cmb, j + 1, nHW, name);
								cmb.Ident.m_GLMask &= ~((uint64)1 << j);
							}
						}
					}
				}
			}
			continue;
		end:
			gEnv->pLog->Log("Error: Error in '%s' file (Line: %d)", nameComb.c_str(), nLine);
		}
	}
}

CShader* CShaderMan::mfForName(const char* nameSh, int flags, const CShaderResources* Res, uint64 nMaskGen)
{
	if (!nameSh || !nameSh[0])
	{
		CryWarning("Warning: CShaderMan::mfForName: NULL name\n");
		(*s_DefaultShader)->AddRef();
		return *s_DefaultShader;
	}

	char nameEf[256];
	char nameNew[256];
	char nameRes[256];

	uint64 nMaskGenHW = 0;

	cry_strcpy(nameEf, nameSh);

	cry_strcpy(nameRes, nameEf);
	if (CParserBin::m_nPlatform == SF_D3D11)
		strcat(nameRes, "(DX1)");
	else if (CParserBin::m_nPlatform == SF_GL4)
		cry_strcat(nameRes, "(G4)");
	else if (CParserBin::m_nPlatform == SF_GLES3)
		cry_strcat(nameRes, "(E3)");
	else if (CParserBin::m_nPlatform == SF_ORBIS)
		strcat(nameRes, "(O)");
	else if (CParserBin::m_nPlatform == SF_DURANGO)
		cry_strcat(nameRes, "(D)");

	CShader* efGen = nullptr;

	// Check if this shader already loaded
	CBaseResource* pBR = CBaseResource::GetResource(CShader::mfGetClassName(), nameRes, false);
	bool bGenModified = false;
	CShader* ef = (CShader*)pBR;
	if (ef && ef->m_ShaderGenParams)
	{
		efGen = ef;
		//if (!(flags & EF_RELOAD))
		//  nMaskGen = gRenDev->EF_GetRemapedShaderMaskGen(nameSh, nMaskGen | nMaskGenHW);
		mfModifyGenFlags(efGen, Res, nMaskGen, nMaskGenHW);
		bGenModified = true;
#ifdef __GNUC__
		cry_sprintf(nameNew, "%s(%llx)", nameRes, nMaskGen);
#else
		cry_sprintf(nameNew, "%s(%I64x)", nameRes, nMaskGen);
#endif
		pBR = CBaseResource::GetResource(CShader::mfGetClassName(), nameNew, false);
		ef = (CShader*)pBR;
		if (ef)
		{
			// Update the flags if HW specs changed
			ef->m_nMaskGenFX = nMaskGen | nMaskGenHW;
			assert(ef->m_pGenShader == efGen);
		}
	}

	if (ef)
	{
		if (!(flags & EF_RELOAD))
		{
			ef->AddRef();
			ef->m_Flags |= flags;
			return ef;
		}
		else
		{
			ef->mfFree();
			ef->m_Flags |= EF_RELOADED;
		}
	}

	if (!efGen)
	{
		cry_sprintf(nameNew, "Shaders/%s.ext", nameEf);
		SShaderGen* pShGen = mfCreateShaderGenInfo(nameEf, false);

		if (pShGen)
		{
			efGen = mfNewShader(nameRes);
			efGen->SetRefCounter(0);      // Hack: to avoid leaks in shader-gen's
			efGen->m_NameShader = nameRes;
			efGen->m_ShaderGenParams = pShGen;
		}
	}
	if (!(flags & EF_RELOAD) || !ef)
	{
		if (efGen)
		{
			// Change gen flags based on dependency on resources info
			if (!bGenModified)
			{
				//nMaskGen = gRenDev->EF_GetRemapedShaderMaskGen(nameSh, nMaskGen | nMaskGenHW);
				mfModifyGenFlags(efGen, Res, nMaskGen, nMaskGenHW);
			}
#ifdef __GNUC__
			cry_sprintf(nameNew, "%s(%llx)", nameRes, nMaskGen);
#else
			cry_sprintf(nameNew, "%s(%I64x)", nameRes, nMaskGen);
#endif
			ef = mfNewShader(nameNew);
			if (!ef)
				return *s_DefaultShader;

			ef->m_nMaskGenFX = nMaskGen | nMaskGenHW;
			ef->m_pGenShader = efGen;
		}
		if (efGen && ef)
		{
			assert(efGen != ef);
			if (!efGen->m_DerivedShaders)
				efGen->m_DerivedShaders = new std::vector<CShader*>;
			efGen->m_DerivedShaders->push_back(ef);
			efGen->AddRef();
		}
		if (!ef)
		{
			ef = mfNewShader(nameRes);
			if (!ef)
				return *s_DefaultShader;
		}
	}
	ef->m_NameShader = nameEf;
	ef->m_NameShaderICRC = CCrc32::ComputeLowercase(nameEf);

	bool bSuccess = false;

	// Check for the new cryFX format
	cry_sprintf(nameNew, "%sCryFX/%s.cfx", m_ShadersPath, nameEf);
	ef->m_NameFile = nameNew;
	ef->m_Flags |= flags;
	gRenDev->m_pRT->RC_ParseShader(ef, nMaskGen | nMaskGenHW, flags, (CShaderResources*)Res);
	return ef;

	return ef;
}

SShaderGen* CShaderMan::mfCreateShaderGenInfo(const char* szName, bool bRuntime)
{
	CCryNameTSCRC s = szName;
	if (!bRuntime)
	{
		ShaderExtItor it = m_ShaderExts.find(s);
		if (it != m_ShaderExts.end())
			return it->second;
	}
	SShaderGen* pShGen = NULL;
	char szN[256];
	cry_strcpy(szN, "Shaders/");
	cry_strcat(szN, szName);
	cry_strcat(szN, ".ext");
	FILE* fp = gEnv->pCryPak->FOpen(szN, "rb", ICryPak::FOPEN_HINT_QUIET);
	if (fp)
	{
		pShGen = new SShaderGen;
		gEnv->pCryPak->FSeek(fp, 0, SEEK_END);
		int ln = gEnv->pCryPak->FTell(fp);
		char* buf = new char[ln + 1];
		if (buf)
		{
			buf[ln] = 0;
			gEnv->pCryPak->FSeek(fp, 0, SEEK_SET);
			gEnv->pCryPak->FRead(buf, ln, fp);
			mfCompileShaderGen(pShGen, buf);
			mfRemapShaderGenInfoBits(szName, pShGen);
			delete[] buf;
		}
		gEnv->pCryPak->FClose(fp);
	}
	if (pShGen && !bRuntime)
	{
		pShGen->m_BitMask.Shrink();
		m_ShaderExts.insert(std::pair<CCryNameTSCRC, SShaderGen*>(s, pShGen));
	}

	return pShGen;
}

void CShaderMan::RT_ParseShader(CShader* pSH, uint64 nMaskGen, uint32 flags, CShaderResources* pRes)
{
	//MEMSTAT_CONTEXT(EMemStatContextTypes::MSC_Other, 0, "ParseShader");

	//CDebugAllowFileAccess ignoreInvalidFileAccess;

	bool bSuccess = false;
#if 0 //def SHADERS_SERIALIZING
	if (CRenderer::CV_r_shadersImport)
	{
		// Do not try and import fxb during cache generation
		// PC would need to support import of console data
		if (!gRenDev->IsShaderCacheGenMode())
		{
			CRY_PROFILE_REGION(PROFILE_RENDERER, "Renderer: ImportShader");
			CRYPROFILE_SCOPE_PROFILE_MARKER("ImportShader");

			bSuccess = ImportShader(pSH, m_Bin);

			if (!bSuccess)
			{
				{
					stack_string flagString;
					CreateShaderMaskGenString(pSH, flagString);
					CryLog("[CShaderSerialize] Failed to import shader %s (0x%p) flags: 0x%llx 0x%x (%s)\n", pSH->GetName(), pSH, pSH->m_nMaskGenFX, pSH->m_nMDV, flagString.empty() ? "0" : flagString.c_str());
				}

				pSH->m_Flags |= EF_FAILED_IMPORT;

				if (CRenderer::CV_r_shadersImport == 2)
				{
					return;
				}
			}
		}
	}
#endif
	if (!bSuccess)
	{
		//CRY_PROFILE_REGION(PROFILE_RENDERER, "Renderer: RT_ParseShader");
		//CRYPROFILE_SCOPE_PROFILE_MARKER("RT_ParseShader");

		SShaderBin* pBin = m_Bin.GetBinShader(pSH->m_NameShader, false, 0);
		if (pBin)
		{
			if (flags & EF_FORCE_RELOAD)
			{
				uint32 nCRC32 = pBin->ComputeCRC();
				if (nCRC32 != pBin->m_CRC32)
				{
					FXShaderBinValidCRCItor itor = gRenDev->m_cEF.m_Bin.m_BinValidCRCs.find(pBin->m_dwName);
					if (itor == gRenDev->m_cEF.m_Bin.m_BinValidCRCs.end())
						gRenDev->m_cEF.m_Bin.m_BinValidCRCs.insert(FXShaderBinValidCRCItor::value_type(pBin->m_dwName, false));

					m_Bin.DeleteFromCache(pBin);
					pBin = m_Bin.GetBinShader(pSH->m_NameShader, false, nCRC32);
				}
			}
			bSuccess = m_Bin.ParseBinFX(pBin, pSH, nMaskGen);
#if 0 //def SHADERS_SERIALIZING
			if (CRenderer::CV_r_shadersExport && gRenDev->IsShaderCacheGenMode())
			{
				//Shader compilation must be enabled for export, to allow reading the token table from the fxcbs in the USER dir
				int oldAllowCompilation = CRenderer::CV_r_shadersAllowCompilation;
				CRenderer::CV_r_shadersAllowCompilation = 1;

				if (bSuccess)
				{
					if (!CheckFXBExists(pSH))
					{
						ExportShader(pSH, m_Bin);
					}
					else
					{
						printf("Not exporting shader %s, it already exists\n", pSH->GetName());
					}
				}

				CRenderer::CV_r_shadersAllowCompilation = oldAllowCompilation;
			}
#endif
		}
		else
		{
			CryWarning("[SHADERS] Failed to load shader '%s'!", pSH->m_NameShader.c_str());
			pSH->m_Flags |= EF_NOTFOUND;
		}
	}
	pSH->m_Flags |= EF_LOADED;
}
