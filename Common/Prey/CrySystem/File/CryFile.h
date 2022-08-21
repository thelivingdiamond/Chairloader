// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

//! \cond INTERNAL

#pragma once

#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include <Prey/CrySystem/IConsole.h>
#include <Prey/CryString/CryPath.h>
#include <Prey/CryString/StringUtils.h>

//////////////////////////////////////////////////////////////////////////
// Defines for CryEngine filetypes extensions.
//////////////////////////////////////////////////////////////////////////
#define CRY_GEOMETRY_FILE_EXT                "cgf"
#define CRY_SKEL_FILE_EXT                    "chr"     //will be a SKEL soon
#define CRY_SKIN_FILE_EXT                    "skin"
#define CRY_CHARACTER_ANIMATION_FILE_EXT     "caf"
#define CRY_CHARACTER_DEFINITION_FILE_EXT    "cdf"
#define CRY_CHARACTER_LIST_FILE_EXT          "cid"
#define CRY_ANIM_GEOMETRY_FILE_EXT           "cga"
#define CRY_MATERIAL_FILE_EXT                "mtl"
#define CRY_ANIM_GEOMETRY_ANIMATION_FILE_EXT "anm"
#define CRY_COMPILED_FILE_EXT                "(c)"
#define CRY_BINARY_XML_FILE_EXT              "binxml"
#define CRY_XML_FILE_EXT                     "xml"
#define CRY_CHARACTER_PARAM_FILE_EXT         "chrparams"
#define CRY_GEOM_CACHE_FILE_EXT              "cax"
//////////////////////////////////////////////////////////////////////////

inline const char* CryGetExt(const char* filepath)
{
	const char* str = filepath;
	size_t len = strlen(filepath);
	for (const char* p = str + len - 1; p >= str; --p)
	{
		switch (*p)
		{
		case ':':
		case '/':
		case '\\':
			// we've reached a path separator - it means there's no extension in this name
			return "";
		case '.':
			// there's an extension in this file name
			return p + 1;
		}
	}
	return "";
}

//! Check if specified file name is a character file.
inline bool IsCharacterFile(const char* filename)
{
	const char* ext = CryGetExt(filename);
	if (stricmp(ext, CRY_SKEL_FILE_EXT) == 0 || stricmp(ext, CRY_SKIN_FILE_EXT) == 0 || stricmp(ext, CRY_CHARACTER_DEFINITION_FILE_EXT) == 0 || stricmp(ext, CRY_ANIM_GEOMETRY_FILE_EXT) == 0)
	{
		return true;
	}
	else
		return false;
}

//! Check if specified file name is a static geometry file.
inline bool IsStatObjFile(const char* filename)
{
	const char* ext = CryGetExt(filename);
	if (stricmp(ext, CRY_GEOMETRY_FILE_EXT) == 0)
	{
		return true;
	}
	else
		return false;
}

struct ICryPak;

//! Wrapper on file system.
class CCryFile
{
public:
	CCryFile();
	CCryFile(ICryPak* pIPak);    //!< Allow an alternative ICryPak interface.
	CCryFile(const char* filename, const char* mode, int nOpenFlagsEx = 0);
	~CCryFile();

	bool Open(const char* filename, const char* mode, int nOpenFlagsEx = 0);
	void Close();

	//! Writes data in a file to the current file position.
	size_t Write(const void* lpBuf, size_t nSize);

	//! Reads data from a file at the current file position.
	size_t ReadRaw(void* lpBuf, size_t nSize);

	//! Template version, for automatic size support.
	template<class T>
	inline size_t ReadTypeRaw(T* pDest, size_t nCount = 1)
	{
		return ReadRaw(pDest, sizeof(T) * nCount);
	}

	//! Automatic endian-swapping version.
	template<class T>
	inline size_t ReadType(T* pDest, size_t nCount = 1)
	{
		size_t nRead = ReadRaw(pDest, sizeof(T) * nCount);
		SwapEndian(pDest, nCount);
		return nRead;
	}

	//! Template version, for automatic size support.
	template<typename T>
	inline size_t WriteType(const T* pData, const size_t nCount = 1)
	{
		return Write(pData, sizeof(T) * nCount);
	}

	//! Retrieves the length of the file.
	size_t GetLength() const;

	//! Moves the current file pointer to the specified position.
	size_t Seek(size_t seek, int mode);

	//! Moves the current file pointer at the beginning of the file.
	void SeekToBegin();

	//! Moves the current file pointer at the end of the file.
	size_t SeekToEnd();

	//! Retrieves the current file pointer.
	size_t GetPosition() const;

	//! Tests for end-of-file on a selected file.
	bool IsEof() const;

	//! Flushes any data yet to be written.
	void Flush();

	//! Gets a handle to a pack object.
	FILE* GetHandle() const { return m_file; };

	//! Retrieves the filename of the selected file.
	const char* GetFilename() const { return m_filename; };

	//! Retrieves the filename after adjustment to the real relative to engine root path.
	//! Example:
	//! Original filename "textures/red.dds" adjusted filename will look like "game/textures/red.dds"
	//! \return Adjusted filename, this is a pointer to a static string, copy return value if you want to keep it.
	const char* GetAdjustedFilename() const;

	//! Checks if file is opened from pak file.
	bool IsInPak() const;

	//! Gets path of archive this file is in.
	const char* GetPakPath() const;

private:
	CryPathString m_filename;
	FILE*         m_file;
	ICryPak*      m_pIPak;
};

#define IfPak(PakFunc, stdfunc, args) (m_pIPak ? m_pIPak->PakFunc args : stdfunc args)

//! CCryFile implementation.
inline CCryFile::CCryFile()
{
	m_file = 0;
	m_pIPak = gEnv ? gEnv->pCryPak : NULL;
}

inline CCryFile::CCryFile(ICryPak* pIPak)
{
	m_file = 0;
	m_pIPak = pIPak;
}

//////////////////////////////////////////////////////////////////////////
inline CCryFile::CCryFile(const char* filename, const char* mode, int nOpenFlagsEx)
{
	m_file = 0;
	m_pIPak = gEnv ? gEnv->pCryPak : NULL;
	Open(filename, mode, nOpenFlagsEx);
}

//////////////////////////////////////////////////////////////////////////
inline CCryFile::~CCryFile()
{
	Close();
}

//////////////////////////////////////////////////////////////////////////
//! \note For nOpenFlagsEx see ICryPak::EFOpenFlags.
inline bool CCryFile::Open(const char* filename, const char* mode, int nOpenFlagsEx)
{
	CryPathString tempfilename = filename;

#if !defined (_RELEASE)
	if (gEnv)
	{
		ICVar* const pCvar = gEnv->pConsole->GetCVar("ed_lowercasepaths");
		if (pCvar)
		{
			const int lowercasePaths = pCvar->GetIVal();
			if (lowercasePaths)
			{
				tempfilename.MakeLower();
			}
		}
	}
#endif
	if (m_file)
	{
		Close();
	}
	m_filename = tempfilename;

	m_file = m_pIPak ? m_pIPak->FOpen(tempfilename, mode, nOpenFlagsEx) : fopen(tempfilename, mode);
	return m_file != NULL;
}

//////////////////////////////////////////////////////////////////////////
inline void CCryFile::Close()
{
	if (m_file)
	{
		IfPak(FClose, fclose, (m_file));
		m_file = 0;
		m_filename.clear();
	}
}

//////////////////////////////////////////////////////////////////////////
inline size_t CCryFile::Write(const void* lpBuf, size_t nSize)
{
	assert(m_file);
	return IfPak(FWrite, fwrite, (lpBuf, 1, nSize, m_file));
}

//////////////////////////////////////////////////////////////////////////
inline size_t CCryFile::ReadRaw(void* lpBuf, size_t nSize)
{
	assert(m_file);
	return IfPak(FReadRaw, fread, (lpBuf, 1, nSize, m_file));
}

//////////////////////////////////////////////////////////////////////////
inline size_t CCryFile::GetLength() const
{
	assert(m_file);
	if (m_pIPak)
		return m_pIPak->FGetSize(m_file);
	long curr = ftell(m_file);
	if (fseek(m_file, 0, SEEK_END) != 0)
		return 0;
	long size = ftell(m_file);
	if (fseek(m_file, curr, SEEK_SET) != 0)
		return 0;
	return size;
}

#if CRY_PLATFORM_WINDOWS
	#pragma warning( push )               //AMD Port
	#pragma warning( disable : 4267 )
#endif

//////////////////////////////////////////////////////////////////////////
inline size_t CCryFile::Seek(size_t seek, int mode)
{
	assert(m_file);
	return IfPak(FSeek, fseek, (m_file, long(seek), mode));
}

#if CRY_PLATFORM_WINDOWS
	#pragma warning( pop )                //AMD Port
#endif

//////////////////////////////////////////////////////////////////////////
inline void CCryFile::SeekToBegin()
{
	Seek(0, SEEK_SET);
}

//////////////////////////////////////////////////////////////////////////
inline size_t CCryFile::SeekToEnd()
{
	return Seek(0, SEEK_END);
}

//////////////////////////////////////////////////////////////////////////
inline size_t CCryFile::GetPosition() const
{
	assert(m_file);
	return IfPak(FTell, ftell, (m_file));
}

//////////////////////////////////////////////////////////////////////////
inline bool CCryFile::IsEof() const
{
	assert(m_file);
	return IfPak(FEof, feof, (m_file)) != 0;
}

//////////////////////////////////////////////////////////////////////////
inline void CCryFile::Flush()
{
	assert(m_file);
	IfPak(FFlush, fflush, (m_file));
}

//////////////////////////////////////////////////////////////////////////
inline bool CCryFile::IsInPak() const
{
	if (m_file && m_pIPak)
		return m_pIPak->GetFileArchivePath(m_file) != NULL;
	return false;
}

//////////////////////////////////////////////////////////////////////////
inline const char* CCryFile::GetPakPath() const
{
	if (m_file && m_pIPak)
	{
		const char* sPath = m_pIPak->GetFileArchivePath(m_file);
		if (sPath != NULL)
			return sPath;
	}
	return "";
}

//////////////////////////////////////////////////////////////////////////
inline const char* CCryFile::GetAdjustedFilename() const
{
	assert(m_pIPak);
	if (!m_pIPak)
		return "";

	//! Gets mod path to file.
	static CryPathString adjustedFileName;
	m_pIPak->AdjustFileName(m_filename, adjustedFileName, 0);
	return adjustedFileName;
}

//! \endcond
