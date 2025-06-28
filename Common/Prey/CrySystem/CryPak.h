// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>

#include <Prey/CryString/CryFixedString.h>
#include <Prey/CrySystem/CryPak.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CryThreading/CryThread.h>
#include <Prey/CryCore/Containers/VectorMap.h>
#include <Prey/CryThreading/CryThread.h>
#include <Prey/CryCore/Containers/CryArray.h>
//#include <_unknown/DynArray__iobuf _,int,NArray__SmallDynStorage_NAlloc__AllocCompatible_NAlloc__ModuleAlloc_ _ _.h>

struct CCachedFileData;
struct ICryArchive;
struct ICryPakFileAcesssSink;
class ICrySizer;
struct ICustomMemoryHeap;
struct IGameStartup;
struct IMemoryBlock;
struct IMiniLog;
struct ITimer;
struct PakVars;
namespace ZipDir
{
struct Cache;
struct FileEntry;
} // namespace ZipDir

struct CZipPseudoFile // Id=800F551 Size=24
{
    enum
    {
        _O_COMMIT_FLUSH_MODE = -2147483648,
        _O_DIRECT_OPERATION = 1073741824,
    };

    unsigned long m_nCurSeek;
	CCachedFileData* m_pFileData; // !!! _smart_ptr<CCachedFileData> m_pFileData;
    unsigned m_nFlags;

    unsigned GetFileSize() { return FGetFileSize(this); }
    char *FGets(char *pBuf, int n) { return FFGets(this,pBuf,n); }

#if 0
    void Construct(CCachedFileData *arg0, unsigned arg1);
	void Destruct();
	CCachedFileData *GetFile();
	long FTell();
	int FSeek(long arg0, int arg1);
	uint64_t FRead(void *arg0, uint64_t arg1, uint64_t arg2, _iobuf *arg3);
	uint64_t FReadAll(void *arg0, uint64_t arg1, _iobuf *arg2);
	void *GetFileData(uint64_t &arg0, _iobuf *arg1);
	int FEof();
	int FScanfv(const char *arg0, char *arg1);
	int Getc();
	int Ungetc(int arg0);
	uint64_t GetModificationTime();
	const char *GetArchivePath();
	void GetMemoryUsage(ICrySizer *arg0) const;
#endif

    static inline auto FGetFileSize = PreyFunction<unsigned(CZipPseudoFile *const _this)>(0xD70F90);
    static inline auto FFGets = PreyFunction<char *(CZipPseudoFile *const _this, char *pBuf, int n)>(0xD6E720);
};

class CCryPak;
class CCryPakFindData;
class CCachedFileRawData;
struct tNameAlias;

// Header: Exact
// CryEngine/crysystem/crypak.h
class CCryPak : public ICryPak, public ISystemEventListener // Id=800F54D Size=968
{
public:
	CryReadModifyLock m_csOpenFiles;
	
	using ZipPseudoFileArray = std::vector<CZipPseudoFile>;
	
	std::vector<CZipPseudoFile> m_arrOpenFiles;
	
	struct ArkDelayedOpenFile // Id=800F55D Size=32
	{
		CZipPseudoFile file;
		bool bAvailable;
		bool bDelayed;
	};

	volatile int m_delayedOpenSpinlock;
	uint64_t m_delayedOpens;
	std::vector<CCryPak::ArkDelayedOpenFile> m_arrDelayedOpenFiles;
	CryReadModifyLock m_csCachedFiles;
	
	using CachedFileDataSet = std::vector<CCachedFileData *>;
	
	std::vector<CCachedFileData *> m_setCachedFiles;
	_smart_ptr<CCachedFileRawData> m_pCachedFileData;
	CryReadModifyLock m_csMain;
	
	using ArchiveArray = std::vector<ICryArchive *>;
	
	std::vector<ICryArchive *> m_arrArchives;
	
	using TCommentDataMap = VectorMap<string,string,std::less<string>,std::allocator<std::pair<string,string>>>;
	using TCommentDataPair = std::pair<string,string>;
	
	struct PackDesc // Id=800F5A1 Size=56
	{
		string strBindRoot;
		string strFileName;
		VectorMap<string,string,std::less<string>,std::allocator<std::pair<string,string>>> m_commentData;
		_smart_ptr<ICryArchive> pArchive;
		_smart_ptr<ZipDir::Cache> pZip;
		
#if 0
		const char *GetFullPath() const;
		uint64_t sizeofThis();
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	};

	using ZipArray = std::vector<CCryPak::PackDesc,stl::STLGlobalAllocator<CCryPak::PackDesc> >;
	
	CryReadModifyLock m_csZips;
	std::vector<CCryPak::PackDesc,stl::STLGlobalAllocator<CCryPak::PackDesc> > m_arrZips;
	CryReadModifyLock m_csFindData;
	
	using CryPakFindDataSet = std::set<_smart_ptr<CCryPakFindData>,std::less<_smart_ptr<CCryPakFindData>>>;
	
	std::set<_smart_ptr<CCryPakFindData>,std::less<_smart_ptr<CCryPakFindData>>> m_setFindData;
	IMiniLog *m_pLog;
	string m_strDataRoot;
	string m_strDataRootWithSlash;
	bool m_bInstalledToHDD;
	std::vector<string> m_arrMods;
	
	using TAliasList = std::vector<tNameAlias *>;
	
	std::vector<tNameAlias *> m_arrAliases;
	ICryPak::ERecordFileOpenList m_eRecordFileOpenList;
	
	using RecordedFilesSet = std::set<string,stl::less_stricmp<string>>;
	
	std::set<string,stl::less_stricmp<string>> m_recordedFilesSet;
	_smart_ptr<IResourceList> m_pEngineStartupResourceList;
	_smart_ptr<IResourceList> m_pLevelResourceList;
	_smart_ptr<IResourceList> m_pNextLevelResourceList;
	_smart_ptr<ICustomMemoryHeap> m_pInMemoryPaksCPUHeap;
	ITimer *m_pITimer;
	float m_fFileAcessTime;
	std::vector<ICryPakFileAcesssSink *> m_FileAccessSinks;
	PakVars const *m_pPakVars;
	bool m_bLvlRes;
	bool m_bGameFolderWritable;
	bool m_disableRuntimeFileAccess[2];
	unsigned long m_mainThreadId;
	unsigned long m_renderThreadId;
	CryFixedStringT<128> m_sLocalizationFolder;
	
	enum
	{
		g_nPseudoFileIdxOffset = 1,
	};

	enum
	{
		g_cNativeSlash = 92,
		g_cNonNativeSlash = 47,
	};

	using CBShouldPackReOpen = bool (*)(const char *);
	
	CryCriticalSection m_csMissingFiles;
	
	using MissingFileMap = std::map<string,unsigned int,std::less<string>,std::allocator<std::pair<CryStringT<char> const,unsigned int>>>;
	
	std::map<string,unsigned int,std::less<string>,std::allocator<std::pair<CryStringT<char> const,unsigned int>>> m_mapMissingFiles;
	std::set<unsigned int,std::less<unsigned int>,stl::STLGlobalAllocator<unsigned int> > m_filesCachedOnHDD;
	
	class CPakFileWidget;

	CCryPak::CPakFileWidget *m_pWidget;
	
	void MergeDelayed() { FMergeDelayed(this); }
	void MergeDelayed_InLock() { FMergeDelayed_InLock(this); }
	const char *AdjustFileNameInternal(const char *src, char *dst, unsigned nFlags) { return FAdjustFileNameInternal(this,src,dst,nFlags); }
	bool CheckPathExists(const char *_szPath, unsigned _nFlags) { return FCheckPathExists(this,_szPath,_nFlags); }
	bool AdjustFileNameForLocalization(CryStackStringT<char,512> &_out_path, const char *_szPath, unsigned _nFlags, bool _bMod) const { return FAdjustFileNameForLocalization(this,_out_path,_szPath,_nFlags,_bMod); }
	virtual const char *AdjustFileName(const char *src, char *dst, unsigned nFlags);
	static char *BeautifyPath(char *dst) { return FBeautifyPath(dst); }
	CCryPak(IMiniLog *pLog, PakVars *pPakVars, const bool bLvlRes, IGameStartup const *pGameStartup);
	virtual ~CCryPak();
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual ICryPak::PakInfo *GetPakInfo();
	virtual void FreePakInfo(ICryPak::PakInfo *pPakInfo);
	void SetGameFolderWritable(bool bWritable) { FSetGameFolderWritable(this,bWritable); }
	void SetLog(IMiniLog *pLog) { FSetLog(this,pLog); }
	virtual void AddMod(const char *szMod);
	virtual void RemoveMod(const char *szMod);
	virtual const char *GetMod(int index);
	virtual void ParseAliases(const char *szCommandLine);
	virtual void SetAlias(const char *szName, const char *szAlias, bool bAdd);
	virtual const char *GetAlias(const char *szName, bool bReturnSame);
	virtual void SetGameFolder(const char *szFolder);
	virtual const char *GetGameFolder() const;
	virtual void SetLocalizationFolder(const char *const sLocalizationFolder);
	virtual const char *const  GetLocalizationFolder() const;
	virtual void GetCachedPakCDROffsetSize(const char *szName, unsigned &offset, unsigned &size);
	void GetMemoryStatistics(ICrySizer *pSizer) { FGetMemoryStatistics(this,pSizer); }
	virtual void Lock();
	virtual void Unlock();
	virtual void LockReadIO(bool bValue);
	virtual ICryArchive *OpenArchive(const char *szPath, unsigned nFlags, IMemoryBlock *pData);
	virtual const char *GetFileArchivePath(_iobuf *hFile);
	void Register(ICryArchive *pArchive) { FRegisterOv0(this,pArchive); }
	void Unregister(ICryArchive *pArchive) { FUnregisterOv0(this,pArchive); }
	ICustomMemoryHeap *GetInMemoryPakHeap() { return FGetInMemoryPakHeap(this); }
	virtual void *PoolMalloc(uint64_t size);
	virtual void PoolFree(void *p);
	virtual IMemoryBlock *PoolAllocMemoryBlock(uint64_t nSize, const char *sUsage, uint64_t nAlign);
	virtual void RegisterFileAccessSink(ICryPakFileAcesssSink *pSink);
	virtual void UnregisterFileAccessSink(ICryPakFileAcesssSink *pSink);
	virtual bool GetLvlResStatus() const;
	virtual bool Init(const char *szBasePath);
	virtual void Release();
	virtual bool IsInstalledToHDD(const char *acFilePath) const;
	virtual bool OpenPack(const char *szPath, unsigned nFlags, IMemoryBlock *pData, CryFixedStringT<2048> *pFullPath);
	virtual bool OpenPack(const char *szBindRootIn, const char *szPath, unsigned nFlags, IMemoryBlock *pData, CryFixedStringT<2048> *pFullPath);
	virtual bool ClosePack(const char *pName, unsigned nFlags);
	virtual bool OpenPacks(const char *pWildcardIn, unsigned nFlags, std::vector<CryFixedStringT<2048>> *pFullPaths);
	virtual bool OpenPacks(const char *szBindRoot, const char *pWildcardIn, unsigned nFlags, std::vector<CryFixedStringT<2048>> *pFullPaths);
	virtual void SetFlagsOnPak(const char *pWildcard, unsigned nFlags);
	bool OpenPackCommon(const char *szBindRoot, const char *szFullPath, unsigned nPakFlags, IMemoryBlock *pData) { return FOpenPackCommon(this,szBindRoot,szFullPath,nPakFlags,pData); }
	bool OpenPacksCommon(const char *szDir, const char *pWildcardIn, char *cWork, int nPakFlags, std::vector<CryFixedStringT<2048>> *pFullPaths) { return FOpenPacksCommon(this,szDir,pWildcardIn,cWork,nPakFlags,pFullPaths); }
	virtual bool ClosePacks(const char *pWildcardIn, unsigned nFlags);
	virtual bool FindPacks(const char *pWildcardIn);
	virtual bool SetPacksAccessible(bool bAccessible, const char *pWildcard, unsigned nFlags);
	virtual bool SetPackAccessible(bool bAccessible, const char *pName, unsigned nFlags);
	virtual void SetPacksAccessibleForLevel(const char *sLevelName);
	virtual uint64_t GetModificationTime(_iobuf *hFile);
	// _smart_ptr<CCachedFileData> GetFileData(const char *szName, unsigned &nArchiveFlags) { return FGetFileDataOv1(this,szName,nArchiveFlags); }
	// _smart_ptr<CCachedFileData> GetOpenedFileDataInZip(_iobuf *hFile) { return FGetOpenedFileDataInZip(this,hFile); }
	bool WillOpenFromPak(const char *szPath) { return FWillOpenFromPak(this,szPath); }
	ZipDir::FileEntry *FindPakFileEntry(const char *szPath, unsigned &nArchiveFlags, _smart_ptr<ZipDir::Cache> *pZip, bool bSkipInMemoryPaks) { return FFindPakFileEntryOv1(this,szPath,nArchiveFlags,pZip,bSkipInMemoryPaks); }
	virtual bool LoadPakToMemory(const char *pName, ICryPak::EInMemoryPakLocation nLoadPakToMemory, IMemoryBlock *pMemoryBlock);
	virtual void LoadPaksToMemory(int nMaxPakSize, bool bLoadToMemory);
	virtual _iobuf *FOpen(const char *pName, const char *szMode, unsigned nInputFlags);
	virtual _iobuf *FOpen(const char *pName, const char *szMode, char *szFileGamePath, int nLen);
	virtual _iobuf *FOpenRaw(const char *pName, const char *mode);
	virtual uint64_t FReadRaw(void *pData, uint64_t nSize, uint64_t nCount, _iobuf *hFile);
	virtual uint64_t FReadRawAll(void *pData, uint64_t nFileSize, _iobuf *hFile);
	virtual void *FGetCachedFileData(_iobuf *hFile, uint64_t &nFileSize);
	virtual uint64_t FWrite(const void *data, uint64_t length, uint64_t elems, _iobuf *hFile);
	virtual uint64_t FSeek(_iobuf *hFile, long seek, int mode);
	virtual long FTell(_iobuf *hFile);
	virtual int FFlush(_iobuf *hFile);
	virtual int FClose(_iobuf *hFile);
	virtual int64_t FindFirst(const char *pDir, _finddata64i32_t *fd, unsigned nPathFlags, bool bAllOwUseFileSystem);
	virtual int FindNext(int64_t handle, _finddata64i32_t *fd);
	virtual int FindClose(int64_t handle);
	virtual int FEof(_iobuf *hFile);
	virtual int FError(_iobuf *hFile);
	virtual int FGetErrno();
	virtual int FScanf(_iobuf *hFile, const char *format, ...);
	virtual char *FGets(char *str, int n, _iobuf *hFile);
	virtual int Getc(_iobuf *hFile);
	virtual int Ungetc(int c, _iobuf *hFile);
	virtual int FPrintf(_iobuf *hFile, const char *szFormat, ...);
	virtual uint64_t FGetSize(_iobuf *hFile);
	virtual uint64_t FGetSize(const char *sFilename, bool bAllowUseFileSystem);
	virtual bool IsInPak(_iobuf *hFile);
	virtual bool RemoveFile(const char *pName);
	virtual bool RemoveDir(const char *pName, bool bRecurse, unsigned _flags);
	virtual bool IsAbsPath(const char *pPath);
	virtual CCryPakFindData *CreateFindData();
	virtual bool CopyFileOnDisk(const char *source, const char *dest, bool bFailIfExist);
	virtual bool IsFileExist(const char *sFilename, ICryPak::EFileSearchLocation fileLocation);
	virtual bool IsFolder(const char *sPath);
	virtual bool IsFileCompressed(const char *filename);
	virtual int64_t GetFileSizeOnDisk(const char *filename);
	virtual bool MakeDir(const char *szPathIn, bool bGamePathMapping);
	virtual int RawCompress(const void *pUncompressed, unsigned long *pDestSize, void *pCompressed, unsigned long nSrcSize, int nLevel);
	virtual int RawUncompress(void *pUncompressed, unsigned long *pDestSize, const void *pCompressed, unsigned long nSrcSize);
	virtual void RecordFileOpen(ICryPak::ERecordFileOpenList eList);
	virtual ICryPak::ERecordFileOpenList GetRecordFileOpenList();
	virtual void RecordFile(_iobuf *in, const char *szFilename);
	virtual IResourceList *GetResourceList(ICryPak::ERecordFileOpenList eList);
	virtual void SetResourceList(ICryPak::ERecordFileOpenList eList, IResourceList *pResourceList);
	virtual unsigned ComputeCRC(const char *szPath, unsigned nFileOpenFlags);
	virtual bool ComputeMD5(const char *szPath, uint8_t *md5, unsigned nFileOpenFlags);
	virtual int ComputeCachedPakCDR_CRC(const char *filename, bool useCryFile, IMemoryBlock *pData);
	virtual void DisableRuntimeFileAccess(bool status);
	virtual bool DisableRuntimeFileAccess(bool status, unsigned long threadId);
	virtual bool CheckFileAccessDisabled(const char *name, const char *mode);
	virtual void SetRenderThreadId(unsigned long renderThreadId);
	virtual int GetPakPriority();
	virtual uint64_t GetFileOffsetOnMedia(const char *sFilename);
	virtual EStreamSourceMediaType GetFileMediaType(const char *szName);
	EStreamSourceMediaType GetMediaType(ZipDir::Cache *pZip, unsigned nArchiveFlags) { return FGetMediaType(this,pZip,nArchiveFlags); }
	virtual void CreatePerfHUDWidget();
	virtual void ScanDirectory(const char *_folderPath, const char *_fileFilter, std::vector<string> &_outFiles, bool _recursive, bool _bAllowUseFileSystem);
	
#if 0
	void GetDelayedOpenLock();
	void ReleaseDelayedOpenLock();
	bool InitPack(const char *arg0, unsigned arg1);
	bool AdjustAliases(char *arg0);
	static char *BeautifyPathForWrite(char *arg0);
	static void RemoveRelativeParts(char *arg0);
	PakVars const *GetPakVars() const;
	void Register(CCachedFileData *arg0);
	void Unregister(CCachedFileData *arg0);
	void SetInstalledToHDD(bool arg0);
	int RemountPacks(DynArray<_iobuf *,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > &arg0, bool (*arg1)(const char *));
	bool ReOpenPack(const char *arg0);
	_smart_ptr<CCachedFileData> GetFileData(const char *arg0);
	ZipDir::FileEntry *FindPakFileEntry(const char *arg0);
	ICryArchive *FindArchive(const char *arg0);
	ICryArchive const *FindArchive(const char *arg0) const;
	int ComputeCachedPakCDR_CRC(_smart_ptr<ZipDir::Cache> arg0);
	void OnMissingFile(const char *arg0);
	void LogFileAccessCallStack(const char *arg0, const char *arg1, const char *arg2);
#endif
	
	static inline auto FMergeDelayed = PreyFunction<void(CCryPak *const _this)>(0xD73770);
	static inline auto FMergeDelayed_InLock = PreyFunction<void(CCryPak *const _this)>(0xD73810);
	static inline auto FAdjustFileNameInternal = PreyFunction<const char *(CCryPak *const _this, const char *src, char *dst, unsigned nFlags)>(0xD6C1A0);
	static inline auto FCheckPathExists = PreyFunction<bool(CCryPak *const _this, const char *_szPath, unsigned _nFlags)>(0xD6C9D0);
	static inline auto FAdjustFileNameForLocalization = PreyFunction<bool(CCryPak const *const _this, CryStackStringT<char,512> &_out_path, const char *_szPath, unsigned _nFlags, bool _bMod)>(0xD6C020);
	static inline auto FAdjustFileName = PreyFunction<const char *(CCryPak *const _this, const char *src, char *dst, unsigned nFlags)>(0xD6B9D0);
	static inline auto FBeautifyPath = PreyFunction<char *(char *dst)>(0xD6C830);
	static inline auto FBitNotCCryPak = PreyFunction<void(CCryPak *const _this)>(0xD6A730);
	static inline auto FOnSystemEvent = PreyFunction<void(CCryPak *const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0xD73900);
	static inline auto FGetPakInfo = PreyFunction<ICryPak::PakInfo *(CCryPak *const _this)>(0xD71C90);
	static inline auto FFreePakInfo = PreyFunction<void(CCryPak *const _this, ICryPak::PakInfo *pPakInfo)>(0xD70840);
	static inline auto FSetGameFolderWritable = PreyFunction<void(CCryPak *const _this, bool bWritable)>(0xD772C0);
	static inline auto FSetLog = PreyFunction<void(CCryPak *const _this, IMiniLog *pLog)>(0xD77510);
	static inline auto FAddMod = PreyFunction<void(CCryPak *const _this, const char *szMod)>(0xD6B7A0);
	static inline auto FRemoveMod = PreyFunction<void(CCryPak *const _this, const char *szMod)>(0xD75620);
	static inline auto FGetMod = PreyFunction<const char *(CCryPak *const _this, int index)>(0xD71980);
	static inline auto FParseAliases = PreyFunction<void(CCryPak *const _this, const char *szCommandLine)>(0xD74E60);
	static inline auto FSetAlias = PreyFunction<void(CCryPak *const _this, const char *szName, const char *szAlias, bool bAdd)>(0xD76E30);
	static inline auto FGetAlias = PreyFunction<const char *(CCryPak *const _this, const char *szName, bool bReturnSame)>(0xD708A0);
	static inline auto FSetGameFolder = PreyFunction<void(CCryPak *const _this, const char *szFolder)>(0xD77170);
	static inline auto FGetGameFolder = PreyFunction<const char *(CCryPak const *const _this)>(0xD71060);
	static inline auto FSetLocalizationFolder = PreyFunction<void(CCryPak *const _this, const char *const sLocalizationFolder)>(0xD772D0);
	static inline auto FGetLocalizationFolder = PreyFunction<const char *const (CCryPak const *const _this)>(0xF85410);
	static inline auto FGetCachedPakCDROffsetSize = PreyFunction<void(CCryPak *const _this, const char *szName, unsigned &offset, unsigned &size)>(0xD70930);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CCryPak *const _this, ICrySizer *pSizer)>(0xD711A0);
	static inline auto FLock = PreyFunction<void(CCryPak *const _this)>(0xD72FB0);
	static inline auto FUnlock = PreyFunction<void(CCryPak *const _this)>(0xD77E20);
	static inline auto FLockReadIO = PreyFunction<void(CCryPak *const _this, bool bValue)>(0xD73020);
	static inline auto FOpenArchive = PreyFunction<ICryArchive *(CCryPak *const _this, const char *szPath, unsigned nFlags, IMemoryBlock *pData)>(0xD73950);
	static inline auto FGetFileArchivePath = PreyFunction<const char *(CCryPak *const _this, _iobuf *hFile)>(0xD70B60);
	static inline auto FRegisterOv0 = PreyFunction<void(CCryPak *const _this, ICryArchive *pArchive)>(0xD753A0);
	static inline auto FUnregisterOv0 = PreyFunction<void(CCryPak *const _this, ICryArchive *pArchive)>(0xD77E40);
	static inline auto FGetInMemoryPakHeap = PreyFunction<ICustomMemoryHeap *(CCryPak *const _this)>(0xD71070);
	static inline auto FPoolMalloc = PreyFunction<void *(CCryPak *const _this, uint64_t size)>(0xD75110);
	static inline auto FPoolFree = PreyFunction<void(CCryPak *const _this, void *p)>(0xD75100);
	static inline auto FPoolAllocMemoryBlock = PreyFunction<IMemoryBlock *(CCryPak *const _this, uint64_t nSize, const char *sUsage, uint64_t nAlign)>(0xD75030);
	static inline auto FRegisterFileAccessSink = PreyFunction<void(CCryPak *const _this, ICryPakFileAcesssSink *pSink)>(0xD75460);
	static inline auto FUnregisterFileAccessSink = PreyFunction<void(CCryPak *const _this, ICryPakFileAcesssSink *pSink)>(0xD77F70);
	static inline auto FGetLvlResStatus = PreyFunction<bool(CCryPak const *const _this)>(0xD71120);
	static inline auto FInit = PreyFunction<bool(CCryPak *const _this, const char *szBasePath)>(0x1B933B0);
	static inline auto FRelease = PreyFunction<void(CCryPak *const _this)>(0xA13080);
	static inline auto FIsInstalledToHDD = PreyFunction<bool(CCryPak const *const _this, const char *acFilePath)>(0xD72690);
	static inline auto FOpenPackOv1 = PreyFunction<bool(CCryPak *const _this, const char *szPath, unsigned nFlags, IMemoryBlock *pData, CryFixedStringT<2048> *pFullPath)>(0xD740E0);
	static inline auto FOpenPackOv0 = PreyFunction<bool(CCryPak *const _this, const char *szBindRootIn, const char *szPath, unsigned nFlags, IMemoryBlock *pData, CryFixedStringT<2048> *pFullPath)>(0xD74020);
	static inline auto FClosePack = PreyFunction<bool(CCryPak *const _this, const char *pName, unsigned nFlags)>(0xD6CB50);
	static inline auto FOpenPacksOv1 = PreyFunction<bool(CCryPak *const _this, const char *pWildcardIn, unsigned nFlags, std::vector<CryFixedStringT<2048>> *pFullPaths)>(0xD74740);
	static inline auto FOpenPacksOv0 = PreyFunction<bool(CCryPak *const _this, const char *szBindRoot, const char *pWildcardIn, unsigned nFlags, std::vector<CryFixedStringT<2048>> *pFullPaths)>(0xD746A0);
	static inline auto FSetFlagsOnPak = PreyFunction<void(CCryPak *const _this, const char *pWildcard, unsigned nFlags)>(0xD77050);
	static inline auto FOpenPackCommon = PreyFunction<bool(CCryPak *const _this, const char *szBindRoot, const char *szFullPath, unsigned nPakFlags, IMemoryBlock *pData)>(0xD74210);
	static inline auto FOpenPacksCommon = PreyFunction<bool(CCryPak *const _this, const char *szDir, const char *pWildcardIn, char *cWork, int nPakFlags, std::vector<CryFixedStringT<2048>> *pFullPaths)>(0xD74920);
	static inline auto FClosePacks = PreyFunction<bool(CCryPak *const _this, const char *pWildcardIn, unsigned nFlags)>(0xD6CD80);
	static inline auto FFindPacks = PreyFunction<bool(CCryPak *const _this, const char *pWildcardIn)>(0xD70480);
	static inline auto FSetPacksAccessible = PreyFunction<bool(CCryPak *const _this, bool bAccessible, const char *pWildcard, unsigned nFlags)>(0xD776C0);
	static inline auto FSetPackAccessible = PreyFunction<bool(CCryPak *const _this, bool bAccessible, const char *pName, unsigned nFlags)>(0xD775A0);
	static inline auto FSetPacksAccessibleForLevel = PreyFunction<void(CCryPak *const _this, const char *sLevelName)>(0xD77940);
	static inline auto FGetModificationTime = PreyFunction<uint64_t(CCryPak *const _this, _iobuf *hFile)>(0xD719B0);
	static inline auto FGetFileDataOv1 = PreyFunction<_smart_ptr<CCachedFileData>(CCryPak *const _this, const char *szName, unsigned &nArchiveFlags)>(0xD70C40);
	static inline auto FGetOpenedFileDataInZip = PreyFunction<_smart_ptr<CCachedFileData>(CCryPak *const _this, _iobuf *hFile)>(0xD71BA0);
	static inline auto FWillOpenFromPak = PreyFunction<bool(CCryPak *const _this, const char *szPath)>(0xD78100);
	static inline auto FFindPakFileEntryOv1 = PreyFunction<ZipDir::FileEntry *(CCryPak *const _this, const char *szPath, unsigned &nArchiveFlags, _smart_ptr<ZipDir::Cache> *pZip, bool bSkipInMemoryPaks)>(0xD70650);
	static inline auto FLoadPakToMemory = PreyFunction<bool(CCryPak *const _this, const char *pName, ICryPak::EInMemoryPakLocation nLoadPakToMemory, IMemoryBlock *pMemoryBlock)>(0xD72C80);
	static inline auto FLoadPaksToMemory = PreyFunction<void(CCryPak *const _this, int nMaxPakSize, bool bLoadToMemory)>(0xD72ED0);
	static inline auto FFOpenOv1 = PreyFunction<_iobuf *(CCryPak *const _this, const char *pName, const char *szMode, unsigned nInputFlags)>(0xD6E8D0);
	static inline auto FFOpenOv0 = PreyFunction<_iobuf *(CCryPak *const _this, const char *pName, const char *szMode, char *szFileGamePath, int nLen)>(0xD6EED0);
	static inline auto FFOpenRaw = PreyFunction<_iobuf *(CCryPak *const _this, const char *pName, const char *mode)>(0xD6F100);
	static inline auto FFReadRaw = PreyFunction<uint64_t(CCryPak *const _this, void *pData, uint64_t nSize, uint64_t nCount, _iobuf *hFile)>(0xD6F260);
	static inline auto FFReadRawAll = PreyFunction<uint64_t(CCryPak *const _this, void *pData, uint64_t nFileSize, _iobuf *hFile)>(0xD6F4F0);
	static inline auto FFGetCachedFileData = PreyFunction<void *(CCryPak *const _this, _iobuf *hFile, uint64_t &nFileSize)>(0xD6E020);
	static inline auto FFWrite = PreyFunction<uint64_t(CCryPak *const _this, const void *data, uint64_t length, uint64_t elems, _iobuf *hFile)>(0xD6FB10);
	static inline auto FFSeek = PreyFunction<uint64_t(CCryPak *const _this, _iobuf *hFile, long seek, int mode)>(0xD6F890);
	static inline auto FFTell = PreyFunction<long(CCryPak *const _this, _iobuf *hFile)>(0xD6FA30);
	static inline auto FFFlush = PreyFunction<int(CCryPak *const _this, _iobuf *hFile)>(0xD6DEE0);
	static inline auto FFClose = PreyFunction<int(CCryPak *const _this, _iobuf *hFile)>(0xD6DAD0);
	static inline auto FFindFirst = PreyFunction<int64_t(CCryPak *const _this, const char *pDir, _finddata64i32_t *fd, unsigned nPathFlags, bool bAllOwUseFileSystem)>(0xD6FF80);
	static inline auto FFindNext = PreyFunction<int(CCryPak *const _this, int64_t handle, _finddata64i32_t *fd)>(0xD703C0);
	static inline auto FFindClose = PreyFunction<int(CCryPak *const _this, int64_t handle)>(0xD6FD20);
	static inline auto FFEof = PreyFunction<int(CCryPak *const _this, _iobuf *hFile)>(0xD6DC80);
	static inline auto FFError = PreyFunction<int(CCryPak *const _this, _iobuf *hFile)>(0xD6DDF0);
	static inline auto FFGetErrno = PreyFunction<int(CCryPak *const _this)>(0xD6E3A0);
//	static inline auto FFScanf = PreyFunction<int(CCryPak *const _this, _iobuf *hFile, const char *format, ... )>(0xD6F6A0);
	static inline auto FFGets = PreyFunction<char *(CCryPak *const _this, char *str, int n, _iobuf *hFile)>(0xD6E5B0);
	static inline auto FGetc = PreyFunction<int(CCryPak *const _this, _iobuf *hFile)>(0xD71F50);
	static inline auto FUngetc = PreyFunction<int(CCryPak *const _this, int c, _iobuf *hFile)>(0xD77AD0);
//	static inline auto FFPrintf = PreyFunction<int(CCryPak *const _this, _iobuf *hFile, const char *szFormat, ... )>(0xD6F110);
	static inline auto FFGetSizeOv1 = PreyFunction<uint64_t(CCryPak *const _this, _iobuf *hFile)>(0xD6E3C0);
	static inline auto FFGetSizeOv0 = PreyFunction<uint64_t(CCryPak *const _this, const char *sFilename, bool bAllowUseFileSystem)>(0xD6E4F0);
	static inline auto FIsInPak = PreyFunction<bool(CCryPak *const _this, _iobuf *hFile)>(0xD725D0);
	static inline auto FRemoveFile = PreyFunction<bool(CCryPak *const _this, const char *pName)>(0xD755C0);
	static inline auto FRemoveDir = PreyFunction<bool(CCryPak *const _this, const char *pName, bool bRecurse, unsigned _flags)>(0xD75560);
	static inline auto FIsAbsPath = PreyFunction<bool(CCryPak *const _this, const char *pPath)>(0xD721C0);
	static inline auto FCreateFindData = PreyFunction<CCryPakFindData *(CCryPak *const _this)>(0xD6D5B0);
	static inline auto FCopyFileOnDisk = PreyFunction<bool(CCryPak *const _this, const char *source, const char *dest, bool bFailIfExist)>(0xD6D580);
	static inline auto FIsFileExist = PreyFunction<bool(CCryPak *const _this, const char *sFilename, ICryPak::EFileSearchLocation fileLocation)>(0xD724A0);
	static inline auto FIsFolder = PreyFunction<bool(CCryPak *const _this, const char *sPath)>(0xD72590);
	static inline auto FIsFileCompressed = PreyFunction<bool(CCryPak *const _this, const char *filename)>(0xD72400);
	static inline auto FGetFileSizeOnDisk = PreyFunction<int64_t(CCryPak *const _this, const char *filename)>(0xD70FB0);
	static inline auto FMakeDir = PreyFunction<bool(CCryPak *const _this, const char *szPathIn, bool bGamePathMapping)>(0xD73030);
	static inline auto FRawCompress = PreyFunction<int(CCryPak *const _this, const void *pUncompressed, unsigned long *pDestSize, void *pCompressed, unsigned long nSrcSize, int nLevel)>(0xD75140);
	static inline auto FRawUncompress = PreyFunction<int(CCryPak *const _this, void *pUncompressed, unsigned long *pDestSize, const void *pCompressed, unsigned long nSrcSize)>(0xD75150);
	static inline auto FRecordFileOpen = PreyFunction<void(CCryPak *const _this, ICryPak::ERecordFileOpenList eList)>(0xD75390);
	static inline auto FGetRecordFileOpenList = PreyFunction<ICryPak::ERecordFileOpenList(CCryPak *const _this)>(0x1320680);
	static inline auto FRecordFile = PreyFunction<void(CCryPak *const _this, _iobuf *in, const char *szFilename)>(0xD752B0);
	static inline auto FGetResourceList = PreyFunction<IResourceList *(CCryPak *const _this, ICryPak::ERecordFileOpenList eList)>(0xD71F20);
	static inline auto FSetResourceList = PreyFunction<void(CCryPak *const _this, ICryPak::ERecordFileOpenList eList, IResourceList *pResourceList)>(0xD77A70);
	static inline auto FComputeCRC = PreyFunction<unsigned(CCryPak *const _this, const char *szPath, unsigned nFileOpenFlags)>(0xD6CFE0);
	static inline auto FComputeMD5 = PreyFunction<bool(CCryPak *const _this, const char *szPath, uint8_t *md5, unsigned nFileOpenFlags)>(0xD6D3E0);
	static inline auto FComputeCachedPakCDR_CRCOv0 = PreyFunction<int(CCryPak *const _this, const char *filename, bool useCryFile, IMemoryBlock *pData)>(0xD6D150);
	static inline auto FDisableRuntimeFileAccessOv1 = PreyFunction<void(CCryPak *const _this, bool status)>(0xD6DA70);
	static inline auto FDisableRuntimeFileAccessOv0 = PreyFunction<bool(CCryPak *const _this, bool status, unsigned long threadId)>(0xD6DA80);
	static inline auto FCheckFileAccessDisabled = PreyFunction<bool(CCryPak *const _this, const char *name, const char *mode)>(0xDD23F0);
	static inline auto FSetRenderThreadId = PreyFunction<void(CCryPak *const _this, unsigned long renderThreadId)>(0xD77A60);
	static inline auto FGetPakPriority = PreyFunction<int(CCryPak *const _this)>(0xD71F10);
	static inline auto FGetFileOffsetOnMedia = PreyFunction<uint64_t(CCryPak *const _this, const char *sFilename)>(0xD70ED0);
	static inline auto FGetFileMediaType = PreyFunction<EStreamSourceMediaType(CCryPak *const _this, const char *szName)>(0xD70DF0);
	static inline auto FGetMediaType = PreyFunction<EStreamSourceMediaType(CCryPak *const _this, ZipDir::Cache *pZip, unsigned nArchiveFlags)>(0xD71130);
	static inline auto FCreatePerfHUDWidget = PreyFunction<void(CCryPak *const _this)>(0xD6D610);
	static inline auto FScanDirectory = PreyFunction<void(CCryPak *const _this, const char *_folderPath, const char *_fileFilter, std::vector<string> &_outFiles, bool _recursive, bool _bAllowUseFileSystem)>(0xD75940);
};