#include "Parser.h"

static const char* kWhiteSpace = " ,";

inline static int IsComment(char** buf)
{
	if (!(*buf))
		return 0;

	if ((*buf)[0] == '/' && (*buf)[1] == '/')
		return 2;

	if ((*buf)[0] == '/' && (*buf)[1] == '*')
		return 3;

	return 0;
}

void RemoveCR(char* pbuf)
{
	while (*pbuf)
	{
		if (*pbuf == 0xd)
			*pbuf = 0x20;
		pbuf++;
	}
}

void SkipCharacters(char** buf, const char* toSkip)
{
	char theChar;
	char* skip;

	while ((theChar = **buf) != 0)
	{
		if (theChar >= 0x20)
		{
			skip = (char*)toSkip;
			while (*skip)
			{
				if (theChar == *skip)
					break;
				++skip;
			}
			if (*skip == 0)
				return;
		}
		++ * buf;
	}
}

void SkipComments(char** buf, bool bSkipWhiteSpace)
{
	int n;
	static int m;

	while (n = IsComment(buf))
	{
		switch (n)
		{
		case 2:
			// skip comment lines.
			*buf = strchr(*buf, '\n');
			if (*buf && bSkipWhiteSpace)
				SkipCharacters(buf, kWhiteSpace);
			break;

		case 3:
			// skip comment blocks.
			m = 0;
			do
			{
				*buf = strchr(*buf, '*');
				if (!(*buf))
					break;
				if ((*buf)[-1] == '/')
				{
					*buf += 1;
					m++;
				}
				else if ((*buf)[1] == '/')
				{
					*buf += 2;
					m--;
				}
				else
					*buf += 1;
			} while (m);
			if (!(*buf))
			{
				CryWarning("Comment lines aren't closed\n");
				break;
			}
			if (bSkipWhiteSpace)
				SkipCharacters(buf, kWhiteSpace);
			break;
		}
	}
}

// Determine is this preprocessor directive belongs to first pass or second one
bool fxIsFirstPass(char* buf)
{
	char com[1024];
	char tok[256];
	fxFillCR(&buf, com);
	char* s = com;
	while (*s != 0)
	{
		char* pStart = fxFillPr(&s, tok);
		if (tok[0] == '%' && tok[1] == '_')
			return false;
	}
	return true;
}

int fxFillCR(char** buf, char* dst)
{
	int n = 0;
	SkipCharacters(buf, kWhiteSpace);
	while (**buf != 0xa)
	{
		if (**buf == 0)
			break;
		dst[n++] = **buf;
		++*buf;
	}
	dst[n] = 0;
	return n;
}

char* fxFillPr(char** buf, char* dst)
{
	int n = 0;
	char ch;
	while ((ch = **buf) != 0)
	{
		if (!SkipChar(ch))
			break;
		++*buf;
	}
	char* pStart = *buf;
	while ((ch = **buf) != 0)
	{
		if (SkipChar(ch))
			break;
		dst[n++] = ch;
		++*buf;
	}
	dst[n] = 0;
	return pStart;
}

bool SkipChar(unsigned int ch)
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

int shFill(char** buf, char* dst, int nSize)
{
	int n = 0;
	SkipCharacters(buf, kWhiteSpace);

	while (**buf > 0x20)
	{
		dst[n++] = **buf;
		++*buf;

		if (nSize > 0 && n == nSize)
		{
			break;
		}
	}

	dst[n] = 0;
	return n;
}
