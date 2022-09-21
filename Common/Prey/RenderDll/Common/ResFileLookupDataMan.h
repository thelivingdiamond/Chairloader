// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef __RESFILELOOKUPDATAMAN_H__
#define __RESFILELOOKUPDATAMAN_H__

#include "ResFile.h"

typedef std::vector<CCryNameTSCRC> TResDirNames;

struct SResFileLookupDataDisk
{
	int    m_NumOfFilesUnique;
	int    m_NumOfFilesRef;
	uint32 m_OffsetDir;
	uint32 m_CRC32;
	uint16 m_CacheMajorVer;
	uint16 m_CacheMinorVer;

	SResFileLookupDataDisk() {}
	SResFileLookupDataDisk(const struct SResFileLookupData& inLookup);

	AUTO_STRUCT_INFO;
};
struct SResFileLookupData
{
	int    m_NumOfFilesUnique;
	int    m_NumOfFilesRef;
	uint32 m_OffsetDir;
	uint32 m_CRC32;
	uint16 m_CacheMajorVer;
	uint16 m_CacheMinorVer;

	SResFileLookupData() {}
	SResFileLookupData(const SResFileLookupDataDisk& inLookup)
		: m_NumOfFilesUnique(inLookup.m_NumOfFilesUnique)
		, m_NumOfFilesRef(inLookup.m_NumOfFilesRef)
		, m_OffsetDir(inLookup.m_OffsetDir)
		, m_CRC32(inLookup.m_CRC32)
		, m_CacheMajorVer(inLookup.m_CacheMajorVer)
		, m_CacheMinorVer(inLookup.m_CacheMinorVer)
#ifdef USE_PARTIAL_ACTIVATION
		, m_ContainsResDir(false)
#endif
	{
	}

#ifdef USE_PARTIAL_ACTIVATION
	bool         m_ContainsResDir;

	TResDirNames m_resdirlookup;
	ResDir       m_resdir;

	unsigned int GetDirOffset(const CCryNameTSCRC& dirEntryName) const;
#endif
};

struct SCFXLookupData
{
	uint32 m_CRC32;
	SCFXLookupData() {}
	AUTO_STRUCT_INFO;
};

#define MAX_DIR_BUFFER_SIZE 300000

typedef std::map<CCryNameTSCRC, SResFileLookupData> TFileResDirDataMap;
typedef std::map<CCryNameTSCRC, SCFXLookupData>     TFileCFXDataMap;

class CResFile;

struct SVersionInfo
{
	SVersionInfo() : m_ResVersion(0)
	{ memset(m_szCacheVer, 0, sizeof(m_szCacheVer)); }

	int  m_ResVersion;
	char m_szCacheVer[16];

	AUTO_STRUCT_INFO;
};

class CResFileLookupDataMan
{
public:
	string             m_Path;
	SVersionInfo       m_VersionInfo;
	TFileResDirDataMap m_Data;
	TFileCFXDataMap    m_CFXData;
	unsigned int       m_TotalDirStored;
	byte               m_bDirty : 1;
	byte               m_bReadOnly : 1;
	
	CResFileLookupDataMan();
	~CResFileLookupDataMan();

	void                Clear() { FClear(this); }
	void                Flush();

	CCryNameTSCRC       AdjustName(const char* szName)
	{
		CCryNameTSCRC res;
		FAdjustName(this, &res, szName);
		return res;
	}
	int                 GetResVersion() const { return m_VersionInfo.m_ResVersion; }

	bool                LoadData(const char* acFilename, bool bReadOnly) { return FLoadData(this, acFilename, bReadOnly); }
	void                SaveData(const char* acFilename) const { FSaveData(this, acFilename); }

	bool                IsReadOnly() { return m_bReadOnly; }

	void                AddData(const CResFile* pResFile, uint32 CRC) { FAddData(this, pResFile, CRC); }
	void                AddDataCFX(const char* szPath, uint32 CRC);
	void                RemoveData(uint32 CRC);

	SResFileLookupData* GetData(const CCryNameTSCRC& name) { return FGetData(this, name); }
	SCFXLookupData*     GetDataCFX(const char* szPath);
	void                MarkDirty(bool bDirty) { m_bDirty = bDirty; }

	static inline auto FBitNotCResFileLookupDataMan = PreyFunction<void(CResFileLookupDataMan* const _this)>(0xFC8BA0);
	static inline auto FClear = PreyFunction<void(CResFileLookupDataMan* const _this)>(0xFC9200);
	static inline auto FFlush = PreyFunction<void(CResFileLookupDataMan* const _this)>(0xFC9240);
	static inline auto FAdjustName = PreyFunction<CCryNameTSCRC* (CResFileLookupDataMan* const _this, CCryNameTSCRC* result, const char* szName)>(0xFC9050);
	static inline auto FLoadData = PreyFunction<bool(CResFileLookupDataMan* const _this, const char* acFilename, bool bReadOnly)>(0xFC92C0);
	static inline auto FSaveData = PreyFunction<void(CResFileLookupDataMan const* const _this, const char* acFilename)>(0xFC9700);
	static inline auto FAddData = PreyFunction<void(CResFileLookupDataMan* const _this, CResFile const* pResFile, unsigned CRC)>(0xFC8C90);
	static inline auto FGetData = PreyFunction<SResFileLookupData* (CResFileLookupDataMan* const _this, CCryNameTSCRC const& name)>(0xFC9270);
};

#endif //  __RESFILELOOKUPDATAMAN_H__
