#include <Prey/RenderDll/Common/CommonRender.h>
#include <Prey/RenderDll/Common/Shaders/CShader.h>
#include <Prey/RenderDll/Common/Shaders/Parser.h>
#include <Prey/RenderDll/Common/Shaders/ParserBin.h>

static void sCR(TArray<char>& Text, int nLevel)
{
	Text.AddElem('\n');
	for (int i = 0; i < nLevel; i++)
	{
		Text.AddElem(' ');
		Text.AddElem(' ');
	}
}

CParserBin::CParserBin(SShaderBin* pBin)
{
	m_pCurBinShader = pBin;
	m_pCurShader = NULL;
}
CParserBin::CParserBin(SShaderBin* pBin, CShader* pSH)
{
	m_pCurBinShader = pBin;
	m_pCurShader = pSH;
}

bool CParserBin::CorrectScript(uint32* pTokens, uint32& i, uint32 nT, TArray<char>& Text)
{
	bool bRes = true;

	int nTex = Text.Num() - 1;
	int nTT = nTex;
	while (nTex > 0)
	{
		char c = Text[nTex];
		if (c <= 32)
		{
			nTex++;
			break;
		}
		nTex--;
	}
	if (strncmp(&Text[nTex], "float", 5))
	{
		assert(0);
		gEnv->pLog->Log("Wrong script tokens...");
		return false;
	}
	memset(&Text[nTex], 0x20, nTT - nTex + 1);
	i++;
	while (i < nT)
	{
		uint32 nTok = pTokens[i];
		if (nTok == eT_semicolumn)
			return true;
		i++;
	}
	return false;
}

bool CParserBin::ConvertToAscii(uint32* pTokens, uint32 nT, FXShaderToken& Table, TArray<char>& Text, bool bInclSkipTokens)
{
	uint32 i;
	bool bRes = true;

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
		if (!bInclSkipTokens)
		{
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
		}
		const char* szStr = GetString(nToken, Table, false);
		assert(szStr);
		if (!szStr || !szStr[0])
		{
			bRes = CParserBin::CorrectScript(pTokens, i, nT, Text);
		}
		else
		{
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