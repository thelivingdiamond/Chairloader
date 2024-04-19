#include <Prey/RenderDll/Common/ResFile.h>

void fpStripExtension(const char* const in, char* const out, const size_t bytes)
{
	assert(in && out && (bytes || in == out)); // if this hits, check the call site
	const size_t inlen = strlen(in);
	ptrdiff_t len = inlen - 1;

	if (len <= 1)
	{
		assert(bytes >= 2); // if this hits, bad buffer was passed in
		cry_strcpy(out, bytes, in);
		return;
	}

	while (in[len])
	{
		if (in[len] == '.')
		{
			int n = (int)len;
			while (in[n] != 0)
			{
				if (in[n] == '+')
				{
					assert(bytes > inlen); // if this hits, bad buffer was passed in
					cry_strcpy(out, bytes, in);
					return;
				}
				n++;
			}
			break;
		}
		len--;
		if (!len)
		{
			assert(bytes > inlen); // if this hits, bad buffer was passed in
			cry_strcpy(out, bytes, in);
			return;
		}
	}
	assert(bytes > len); // if this hits, bad buffer was passed in
	cry_strcpy(out, bytes, in, len);
}

void fpAddExtension(char* path, const char* extension, size_t bytes)
{
	assert(path && extension && bytes); // if this hits, check the call site
	char* src;

	assert(*path); // if this hits, src underflow
	src = path + strlen(path) - 1;

	while (*src != '/' && src != path)
	{
		if (*src == '.')
			return;                 // it has an extension
		src--;
	}

	assert(bytes > strlen(path) + strlen(extension)); // if this hits, bad buffer was passed in
	strcat(path, extension);
}

CResFile::~CResFile()
{
	if (this != m_Root.Get() && this != m_RootStream.Get())
	{
		mfClose();
	}
	else
	{
		for (int i = 0; i < 2; ++i)
		{
			const CResFile* pCurrent = i ? m_Next : m_NextStream;
			while (true)
			{
				if (!pCurrent || pCurrent == this)
				{
					break;
				}
				CRY_ASSERT_TRACE(false, ("CResFile - File still open at shutdown: %s (streaming: %s)", pCurrent->chair_mfGetFileName(), i ? "no" : "yes"));
				pCurrent = i ? pCurrent->m_Next : pCurrent->m_NextStream;
			}
		}
	}
}
