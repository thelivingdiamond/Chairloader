// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef __RESFILE_H__
#define __RESFILE_H__

#include <Prey/CryString/CryName.h>

#define IDRESHEADER   (('K' << 24) + ('C' << 16) + ('P' << 8) + 'C')
#define RESVERSION_LZSS  10  // LZSS
#define RESVERSION_LZMA  11  // LZMA
#define RESVERSION_DEBUG  12 // Uncompressed

// defines the current compression for any files written
#define RES_COMPRESSION RESVERSION_LZSS

// Resource files flags
#define RF_NOTSAVED 1
#define RF_COMPRESS 4
#define RF_TEMPDATA 8
#define RF_COMPRESSED 0x80
#define RF_RES_$TOKENS 0x20
#define RF_RES_$ (RF_RES_$TOKENS)

struct SResFileLookupData;
struct SResStreamInfo;

// Resource header
struct SFileResHeader
{
	uint32 hid;
	int ver;
	int num_files;
	//int num_files_ref;
	uint32 ofs_dir;
	uint32 num_files_ref;
	AUTO_STRUCT_INFO;
};

#define MAX_FILE_NAME 256

#define OFFSET_BIG_POSITIVE 0x20000000

struct SDirEntryOpen
{
	CCryNameTSCRC Name;
	uint32 curOffset;
	void*  pData;
	int nSize;

	SDirEntryOpen()
	{
		pData = NULL;
		nSize = 0;
	}

	void GetMemoryUsage(ICrySizer* pSizer) const {}
};

// Internal file entry
struct SDirEntry
{
	CCryNameTSCRC Name;
	uint32 size  : 24;
	uint32 flags : 8;        // RF_
	int32  offset;

	SDirEntry()
	{
		size   = 0;
		flags  = 0;
		offset = 0;
	}

	void GetMemoryUsage(ICrySizer* pSizer) const {}

	AUTO_STRUCT_INFO;
};

struct SDirEntryRef
{
	CCryNameTSCRC Name;
	uint32 ref;

	void GetMemoryUsage(ICrySizer* pSizer) const {}

	AUTO_STRUCT_INFO;
};

//typedef std::map<CCryNameTSCRC, int> ResFilesMap;
//typedef ResFilesMap::iterator ResFilesMapItor;

// Resource access types
#define RA_READ   1
#define RA_WRITE  2
#define RA_CREATE 4
#define RA_ENDIANS 8

// Resource optimize flags
#define RO_HEADERS_IN_BEGIN 1
#define RO_HEADERS_IN_END 2
#define RO_HEADER_FILE 4
#define RO_SORT_ALPHA_ASC 8
#define RO_SORT_ALPHA_DESC 0x10

#define MAX_OPEN_RESFILES 64
typedef std::vector<SDirEntry> ResDir;
typedef ResDir::iterator ResDirIt;

typedef std::vector<SDirEntryRef> ResDirRef;
typedef ResDirRef::iterator ResDirRefIt;

typedef std::vector<SDirEntryOpen> ResDirOpen;
typedef ResDirOpen::iterator ResDirOpenIt;

#define MAX_DIR_SIZE      (2 * 1024 * 1024)       // Directory size in memory (consoles only)

class CResFile
{
	friend class CResStreamCallback;
	friend class CResStreamDirCallback;
	friend class CResFileLookupDataMan;
	friend class CShaderSerialize;

private:
	string m_name;
	char*  m_szAccess;
	FILE*  m_handle;
	ResDir m_Dir;
	ResDirRef  m_DirRef;
	ResDirOpen m_DirOpen;
	byte*  m_pCompressedDir;
	int    m_typeaccess;
	uint32 m_nNumFilesUnique;
	uint32 m_nNumFilesRef;
	uint32 m_nOffsDir;
	uint32 m_nComprDirSize;
	int32  m_nOffset;
	//byte   m_bSwapEndianRead  : 1;
	//byte   m_bSwapEndianWrite : 1;
	byte   m_bDirty           : 1;
	byte   m_bDirValid        : 1;
	byte   m_bDirStreaming    : 1;
	byte   m_bDirCompressed   : 1;
	byte   m_bActive          : 1;
	uint32 m_nLastTickStreamed;
	string m_ermes;
	int    m_version;
	SResStreamInfo* m_pStreamInfo;

	const SResFileLookupData* m_pLookupData;
	class CResFileLookupDataMan* m_pLookupDataMan;

	static inline auto m_Root = PreyGlobal<CResFile>(0x226FCA0);
	static inline auto m_RootStream = PreyGlobal<CResFile>(0x226FD70);
	static inline auto m_nSizeComprDir = PreyGlobal<uint32>(0x2B31100);
	CResFile* m_Next;
	CResFile* m_Prev;
	CResFile* m_NextStream;
	CResFile* m_PrevStream;

	inline void Relink(CResFile* Before)
	{
		if (m_Next && m_Prev)
		{
			m_Next->m_Prev = m_Prev;
			m_Prev->m_Next = m_Next;
		}
		m_Next                 = Before->m_Next;
		Before->m_Next->m_Prev = this;
		Before->m_Next         = this;
		m_Prev                 = Before;
	}
	/*inline void Unlink()
	{
		if (!m_Next || !m_Prev)
			return;
		m_Next->m_Prev = m_Prev;
		m_Prev->m_Next = m_Next;
		m_Next         = m_Prev = NULL;
	}*/
	inline void Link(CResFile* Before)
	{
		if (m_Next || m_Prev)
			return;
		m_Next                 = Before->m_Next;
		Before->m_Next->m_Prev = this;
		Before->m_Next         = this;
		m_Prev                 = Before;
	}

	inline void UnlinkStream()
	{
		if (!m_NextStream || !m_PrevStream)
			return;
		m_NextStream->m_PrevStream = m_PrevStream;
		m_PrevStream->m_NextStream = m_NextStream;
		m_NextStream               = m_PrevStream = NULL;
	}
	inline void LinkStream(CResFile* Before)
	{
		if (m_NextStream || m_PrevStream)
			return;
		m_NextStream = Before->m_NextStream;
		Before->m_NextStream->m_PrevStream = this;
		Before->m_NextStream               = this;
		m_PrevStream = Before;
	}

public:
	CResFile(const char* name);
	~CResFile();

	inline CResFileLookupDataMan* GetLookupMan() const
	{
		return m_pLookupDataMan;
	}

	FILE* mfGetHandle() { return m_handle; }
	
	bool mfActivate(bool bFirstTime) { return FmfActivate(this, bFirstTime); }
	void Unlink() { FUnlink(this); }
	SResFileLookupData* GetLookupData(bool bCreate, unsigned CRC, float fVersion) const { return FGetLookupData(this, bCreate, CRC, fVersion); }
	const char* mfGetError() { return FmfGetError(this); }
	//void mfSetError(const char* er, ... buffer) { FmfSetError(this, er, buffer); }
	void mfDeactivate(bool bReleaseDir) { FmfDeactivate(this, bReleaseDir); }
	void mfTickStreaming() { FmfTickStreaming(this); }
	int mfOpen(int type, CResFileLookupDataMan* pMan, SResStreamInfo* pStreamInfo = nullptr) { return FmfOpen(this, type, pMan, pStreamInfo); }
	bool mfClose() { return FmfClose(this); }
	int mfFlush(bool bOptimise = false) { return FmfFlush(this, bOptimise); }
	int mfFlushDir(long nOffset, bool bOptimise) { return FmfFlushDir(this, nOffset, bOptimise); }
	bool mfPrepareDir() { return FmfPrepareDir(this); }
	int mfLoadDir(SResStreamInfo* pStreamInfo) { return FmfLoadDir(this, pStreamInfo); }
	void mfReleaseDir() { FmfReleaseDir(this); }
	uint8_t* mfFileReadCompressed(SDirEntry* de, unsigned& nSizeDecomp, unsigned& nSizeComp) { return FmfFileReadCompressed(this, de, nSizeDecomp, nSizeComp); }
	int mfFileRead(SDirEntry* de) { return FmfFileReadOv2(this, de); }
	void* mfFileGetBuf(SDirEntry* de) { return FmfFileGetBufOv1(this, de); }
	int mfFileAdd(SDirEntry* de) { return FmfFileAdd(this, de); }
	bool mfFileExist(const char* name) { return FmfFileExistOv0(this, name); }
	int mfFileClose(SDirEntry* de) { return FmfFileClose(this, de); }
	bool mfCloseEntry(SDirEntry* de, bool bEraseOpenEntry = false) { return FmfCloseEntry(this, de, bEraseOpenEntry); }
	SDirEntryOpen* mfOpenEntry(SDirEntry* de) { return FmfOpenEntry(this, de); }
	SDirEntryOpen* mfGetOpenEntry(SDirEntry* de) { return FmfGetOpenEntry(this, de); }
	SDirEntry* mfGetEntry(CCryNameTSCRC name, bool* pAsync = nullptr) { return FmfGetEntry(this, name, pAsync); }
	std::vector<SDirEntry>* mfGetDirectory() { return FmfGetDirectory(this); }
	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }
	static void Tick() { FTick(); }

#if 0
	void Relink(CResFile* arg0);
	void Link(CResFile* arg0);
	void UnlinkStream();
	void LinkStream(CResFile* arg0);
	CResFileLookupDataMan* GetLookupMan() const;
	const char* mfGetFileName() const;
	int mfGetVersion();
	int mfGetNumFiles();
	int mfFileRead(const char* arg0);
	int mfFileRead(CCryNameTSCRC arg0);
	int mfFileWrite(CCryNameTSCRC arg0, void* arg1);
	void mfFileRead2(SDirEntry* arg0, int arg1, void* arg2);
	void mfFileRead2(CCryNameTSCRC arg0, int arg1, void* arg2);
	void* mfFileGetBuf(CCryNameTSCRC arg0);
	int mfFileSeek(SDirEntry* arg0, int arg1, int arg2);
	int mfFileSeek(CCryNameTSCRC arg0, int arg1, int arg2);
	int mfFileSeek(char* arg0, int arg1, int arg2);
	int mfFileLength(SDirEntry* arg0);
	int mfFileLength(CCryNameTSCRC arg0);
	int mfFileLength(char* arg0);
	bool mfFileExist(CCryNameTSCRC arg0);
	_iobuf* mfGetHandle();
	int mfGetResourceSize();
	uint64_t mfGetModifTime();
	int Size();
	static bool IsStreaming();
#endif

	bool mfIsDirty() { return m_bDirty; }
	bool mfIsDirStreaming() { return m_bDirStreaming; }
	int  Size() { return 0; }
	const char* mfGetFileName() const { return m_name.c_str(); }
	int         mfGetVersion() { return m_version; }

	static inline auto FmfActivate = PreyFunction<bool(CResFile* const _this, bool bFirstTime)>(0xFC53A0);
	static inline auto FUnlink = PreyFunction<void(CResFile* const _this)>(0xFC4F20);
	static inline auto FBitNotCResFile = PreyFunction<void(CResFile* const _this)>(0xFC4650);
	static inline auto FGetLookupData = PreyFunction<SResFileLookupData* (CResFile const* const _this, bool bCreate, unsigned CRC, float fVersion)>(0xFC4800);
	static inline auto FmfGetError = PreyFunction<const char* (CResFile* const _this)>(0xFC7000);
	//static inline auto FmfSetError = PreyFunction<void(CResFile* const _this, const char* er, ... buffer)>(0xFC7CB0);
	static inline auto FmfDeactivate = PreyFunction<void(CResFile* const _this, bool bReleaseDir)>(0xFC5760);
	static inline auto FmfTickStreaming = PreyFunction<void(CResFile* const _this)>(0xFC7E00);
	static inline auto FmfOpen = PreyFunction<int(CResFile* const _this, int type, CResFileLookupDataMan* pMan, SResStreamInfo* pStreamInfo)>(0xFC7490);
	static inline auto FmfClose = PreyFunction<bool(CResFile* const _this)>(0xFC5560);
	static inline auto FmfFlush = PreyFunction<int(CResFile* const _this, bool bOptimise)>(0xFC63B0);
	static inline auto FmfFlushDir = PreyFunction<int(CResFile* const _this, long nOffset, bool bOptimise)>(0xFC6A90);
	static inline auto FmfPrepareDir = PreyFunction<bool(CResFile* const _this)>(0xFC7990);
	static inline auto FmfLoadDir = PreyFunction<int(CResFile* const _this, SResStreamInfo* pStreamInfo)>(0xFC70C0);
	static inline auto FmfReleaseDir = PreyFunction<void(CResFile* const _this)>(0xFC7B50);
	static inline auto FmfFileReadCompressed = PreyFunction<uint8_t* (CResFile* const _this, SDirEntry* de, unsigned& nSizeDecomp, unsigned& nSizeComp)>(0xFC6090);
	static inline auto FmfFileReadOv2 = PreyFunction<int(CResFile* const _this, SDirEntry* de)>(0xFC5AC0);
	static inline auto FmfFileGetBufOv1 = PreyFunction<void* (CResFile* const _this, SDirEntry* de)>(0xFC5AA0);
	static inline auto FmfFileAdd = PreyFunction<int(CResFile* const _this, SDirEntry* de)>(0xFC5820);
	static inline auto FmfFileExistOv0 = PreyFunction<bool(CResFile* const _this, const char* name)>(0xFC5A40);
	static inline auto FmfFileClose = PreyFunction<int(CResFile* const _this, SDirEntry* de)>(0xFC5A20);
	static inline auto FmfCloseEntry = PreyFunction<bool(CResFile* const _this, SDirEntry* de, bool bEraseOpenEntry)>(0xFC5610);
	static inline auto FmfOpenEntry = PreyFunction<SDirEntryOpen* (CResFile* const _this, SDirEntry* de)>(0xFC7830);
	static inline auto FmfGetOpenEntry = PreyFunction<SDirEntryOpen* (CResFile* const _this, SDirEntry* de)>(0xFC7020);
	static inline auto FmfGetEntry = PreyFunction<SDirEntry* (CResFile* const _this, CCryNameTSCRC name, bool* pAsync)>(0xFC6E30);
	static inline auto FmfGetDirectory = PreyFunction<std::vector<SDirEntry>* (CResFile* const _this)>(0x12BDA70);
	static inline auto FGetMemoryUsage = PreyFunction<void(CResFile const* const _this, ICrySizer* pSizer)>(0xFC4900);
	static inline auto FTick = PreyFunction<void()>(0xFC4DD0);

	static inline auto m_nMaxOpenResFiles = PreyGlobal<unsigned>(0x226FC90);
	static inline auto m_nNumOpenResources = PreyGlobal<int>(0x2B31104);
};

// Get the sub-string starting at the last . in the string, or NULL if the string contains no dot
// Note: The returned pointer refers to a location inside the provided string, no allocation is performed
const char* fpGetExtension(const char* in);

// Remove extension from string, including the .
// If the string has no extension, the whole string will be copied into the buffer
// Note: The out buffer must have space to store a copy of the in-string and a null-terminator
void fpStripExtension(const char* in, char* out, size_t bytes);
template<size_t bytes>
void fpStripExtension(const char* in, char(&out)[bytes]) { fpStripExtension(in, out, bytes); }

// Adds an extension to the path, if an extension is already present the function does nothing
// The extension should include the .
// Note: The path buffer must have enough unused space to store a copy of the extension string
void fpAddExtension(char* path, const char* extension, size_t bytes);
template<size_t bytes>
void fpAddExtension(char(&path)[bytes], const char* extension) { fpAddExtension(path, extension, bytes); }

#endif //  __RESFILE_H__
