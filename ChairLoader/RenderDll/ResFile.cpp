#include <Prey/RenderDll/Common/CommonRender.h>
#include <Prey/RenderDll/Common/Shaders/ShaderCache.h>
#include <Prey/RenderDll/Common/ResFile.h>
#include <Prey/RenderDll/Common/ResFileLookupDataMan.h>

CResFile::CResFile(const char* name)
	: m_name(name)
	, m_szAccess(nullptr)
	, m_handle(nullptr)
	, m_pCompressedDir(nullptr)
	, m_typeaccess(0)
	, m_nNumFilesUnique(0)
	, m_nNumFilesRef(0)
	, m_nOffsDir(0)
	, m_nComprDirSize(0)
	, m_nOffset(OFFSET_BIG_POSITIVE)
	//, m_bSwapEndianRead(false)
	//, m_bSwapEndianWrite(false)
	, m_bDirty(false)
	, m_bDirValid(false)
	, m_bDirStreaming(false)
	, m_bDirCompressed(false)
	, m_bActive(false)
	, m_nLastTickStreamed(0)
	, m_version(0)
	, m_pStreamInfo(nullptr)
	, m_pLookupData(nullptr)
	, m_pLookupDataMan(nullptr)
	, m_Next(nullptr)
	, m_Prev(nullptr)
	, m_NextStream(nullptr)
	, m_PrevStream(nullptr)
{
	if (!m_Root->m_Next)
	{
		m_Root->m_Next = m_Root.Get();
		m_Root->m_Prev = m_Root.Get();
		m_RootStream->m_NextStream = m_RootStream.Get();
		m_RootStream->m_PrevStream = m_RootStream.Get();
	}
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
				CRY_ASSERT_TRACE(false, ("CResFile - File still open at shutdown: %s (streaming: %s)", pCurrent->mfGetFileName(), i ? "no" : "yes"));
				pCurrent = i ? pCurrent->m_Next : pCurrent->m_NextStream;
			}
		}
	}
}

void CResStreamDirCallback::StreamOnComplete(IReadStream* pStream, unsigned nError)
{
	FStreamOnComplete(this, pStream, nError);
}

void CResStreamDirCallback::StreamAsyncOnComplete(IReadStream* pStream, unsigned nError)
{
	FStreamAsyncOnComplete(this, pStream, nError);
}

void CResStreamCallback::StreamOnComplete(IReadStream* pStream, unsigned nError)
{
	FStreamOnComplete(this, pStream, nError);
}

void CResStreamCallback::StreamAsyncOnComplete(IReadStream* pStream, unsigned nError)
{
	FStreamAsyncOnComplete(this, pStream, nError);
}

//======================================================================

void CResFileLookupDataMan::RemoveData(uint32 CRC)
{
	{
		TFileResDirDataMap tmpData;
		for (TFileResDirDataMap::iterator it = m_Data.begin(); it != m_Data.end(); ++it)
		{
			SResFileLookupData& data = it->second;
			if (data.m_CRC32 != CRC)
				tmpData[it->first] = data;
		}
		m_Data.swap(tmpData);
	}

	{
		TFileCFXDataMap tmpData;
		for (TFileCFXDataMap::iterator it = m_CFXData.begin(); it != m_CFXData.end(); ++it)
		{
			SCFXLookupData& data = it->second;
			if (data.m_CRC32 != CRC)
				tmpData[it->first] = data;
		}
		m_CFXData.swap(tmpData);
	}
}

//======================================================================

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

const char* fpGetExtension(const char* in)
{
	assert(in); // if this hits, check the call site
	ptrdiff_t len = strlen(in) - 1;
	while (len)
	{
		if (in[len] == '.')
			return &in[len];
		len--;
	}
	return NULL;
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
