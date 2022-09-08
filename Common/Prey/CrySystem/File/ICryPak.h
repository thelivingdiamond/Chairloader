// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryString/CryFixedString.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include "Prey/CrySystem/IStreamEngineDefs.h"

struct ICryArchive;
struct ICryPakFileAcesssSink;
struct IMemoryBlock;
struct IResourceList;

// Header: MadeUp
// _unknown/ICryPak.h
struct ICryPak // Id=800062E Size=8
{
    using FileTime = uint64_t;

    enum class EPathResolutionRules
    {
        FLAGS_DISABLE_LOCALIZATION = 32768,
        FLAGS_PATH_REAL = 65536,
        FLAGS_COPY_DEST_ALWAYS = 131072,
        FLAGS_ADD_TRAILING_SLASH = 262144,
        FLAGS_NO_FULL_PATH = 2097152,
        FLAGS_REDIRECT_TO_DISC = 4194304,
        FLAGS_FOR_WRITING = 8388608,
        FLAGS_NO_LOWCASE = 16777216,
        FLAGS_PAK_IN_MEMORY = 33554432,
        FLAGS_FILENAMES_AS_CRC32 = 67108864,
        FLAGS_CHECK_MOD_PATHS = 134217728,
        FLAGS_NEVER_IN_PAK = 268435456,
        FLAGS_RESOLVE_TO_CACHE = 536870912,
        FLAGS_PAK_IN_MEMORY_CPU = 1073741824,
    };

    enum class EFOpenFlags
    {
        FOPEN_HINT_DIRECT_OPERATION = 1,
        FOPEN_HINT_QUIET = 2,
        FOPEN_ONDISK = 4,
        FOPEN_FORSTREAMING = 8,
        FOPEN_LOCKED_OPEN = 16,
    };

    enum class ERecordFileOpenList
    {
        RFOM_Disabled = 0,
        RFOM_EngineStartup = 1,
        RFOM_Level = 2,
        RFOM_NextLevel = 3,
    };

    enum
    {
        g_nMaxPath = 2048,
    };

    enum EFileSearchLocation
    {
        eFileLocation_Any = 0,
        eFileLocation_OnDisk = 1,
        eFileLocation_InPak = 2,
    };

    enum EInMemoryPakLocation
    {
        eInMemoryPakLocale_Unload = 0,
        eInMemoryPakLocale_CPU = 1,
        eInMemoryPakLocale_GPU = 2,
    };

    struct PakInfo // Id=800062F Size=32
    {
        struct Pak // Id=8000630 Size=24
        {
            const char *szFilePath;
            const char *szBindRoot;
            uint64_t nUsedMem;
        };

        unsigned numOpenPaks;
        ICryPak::PakInfo::Pak arrPaks[1];
    };

    using SignedFileSize = int64_t;

    static constexpr const int64_t FILE_NOT_PRESENT = -1;

    virtual ~ICryPak();

    //! Given the source relative path, constructs the full path to the file according to the flags.
    virtual const char *AdjustFileName(const char *src, CryPathString & dst, unsigned nFlags) = 0;

    virtual bool Init(const char *arg0) = 0;
    virtual void Release() = 0;

    //! \return true if given pak path is installed to HDD.
    //! If no file path is given it will return true if whole application is installed to HDD.
    virtual bool IsInstalledToHDD(const char *acFilePath = 0) const = 0;

    //! After this call, the pak file will be searched for files when they aren't on the OS file system.
    //! \param pName Must not be 0.
    virtual bool OpenPack(const char *pName, unsigned nFlags, IMemoryBlock *pData = 0, CryPathString * pFullPath = 0) = 0;

    //! After this call, the pak file will be searched for files when they aren't on the OS file system.
    virtual bool OpenPack(const char *pBindingRoot, const char *pName, unsigned arg2, IMemoryBlock *pData = 0, CryPathString * pFullPath = 0) = 0;

    //! After this call, the file will be unlocked and closed, and its contents won't be used to search for files.
    virtual bool ClosePack(const char *pName, unsigned nFlags) = 0;

    //! Opens pack files by the path and wildcard.
    virtual bool OpenPacks(const char *pWildcard, unsigned nFlags, std::vector<CryPathString> *pFullPaths = nullptr) = 0;

    //! Opens pack files by the path and wildcard.
    virtual bool OpenPacks(const char* pBindingRoot, const char* pWildcard, unsigned nFlags, std::vector<CryPathString>* pFullPaths = NULL) = 0;


    virtual void SetFlagsOnPak(const char *arg0, unsigned arg1) = 0;

    //! Closes pack files by the path and wildcard.
    virtual bool ClosePacks(const char *pWildcard, unsigned nFlags) = 0;

    virtual bool FindPacks(const char *arg0) = 0;
    virtual bool SetPacksAccessible(bool arg0, const char *arg1, unsigned arg2) = 0;
    virtual bool SetPackAccessible(bool arg0, const char *arg1, unsigned arg2) = 0;
    virtual void SetPacksAccessibleForLevel(const char *arg0) = 0;
    virtual bool LoadPakToMemory(const char *arg0, ICryPak::EInMemoryPakLocation arg1, IMemoryBlock *arg2) = 0;
    virtual void LoadPaksToMemory(int arg0, bool arg1) = 0;
    virtual void AddMod(const char *arg0) = 0;
    virtual void RemoveMod(const char *arg0) = 0;
    virtual const char *GetMod(int arg0) = 0;
    virtual void ParseAliases(const char *arg0) = 0;
    virtual void SetAlias(const char *arg0, const char *arg1, bool arg2) = 0;
    virtual const char *GetAlias(const char *arg0, bool arg1) = 0;
    virtual void Lock() = 0;
    virtual void Unlock() = 0;
    virtual void LockReadIO(bool arg0) = 0;
    virtual void SetGameFolder(const char *arg0) = 0;
    virtual const char *GetGameFolder() const = 0;
    virtual void SetLocalizationFolder(const char *const arg0) = 0;
    virtual const char *const  GetLocalizationFolder() const = 0;
    virtual void GetCachedPakCDROffsetSize(const char *arg0, unsigned &arg1, unsigned &arg2) = 0;
    virtual ICryPak::PakInfo *GetPakInfo() = 0;
    virtual void FreePakInfo(ICryPak::PakInfo *arg0) = 0;
    virtual _iobuf *FOpen(const char *arg0, const char *arg1, unsigned arg2) = 0;
    virtual _iobuf *FOpen(const char *arg0, const char *arg1, char *arg2, int arg3) = 0;
    virtual _iobuf *FOpenRaw(const char *arg0, const char *arg1) = 0;
    virtual uint64_t FReadRaw(void *arg0, uint64_t arg1, uint64_t arg2, _iobuf *arg3) = 0;
    virtual uint64_t FReadRawAll(void *arg0, uint64_t arg1, _iobuf *arg2) = 0;
    virtual void *FGetCachedFileData(_iobuf *arg0, uint64_t &arg1) = 0;
    virtual uint64_t FWrite(const void *arg0, uint64_t arg1, uint64_t arg2, _iobuf *arg3) = 0;
    virtual int FPrintf(_iobuf *arg0, const char *arg1, ...) = 0;
    virtual char *FGets(char *arg0, int arg1, _iobuf *arg2) = 0;
    virtual int Getc(_iobuf *arg0) = 0;
    virtual uint64_t FGetSize(_iobuf *arg0) = 0;
    virtual uint64_t FGetSize(const char *arg0, bool arg1) = 0;
    virtual int Ungetc(int arg0, _iobuf *arg1) = 0;
    virtual bool IsInPak(_iobuf *arg0) = 0;
    virtual bool RemoveFile(const char *arg0) = 0;
    virtual bool RemoveDir(const char *arg0, bool arg1, unsigned arg2) = 0;
    virtual bool IsAbsPath(const char *arg0) = 0;
    virtual bool CopyFileOnDisk(const char *arg0, const char *arg1, bool arg2) = 0;
    virtual uint64_t FSeek(_iobuf *arg0, long arg1, int arg2) = 0;
    virtual long FTell(_iobuf *arg0) = 0;
    virtual int FClose(_iobuf *arg0) = 0;
    virtual int FEof(_iobuf *arg0) = 0;
    virtual int FError(_iobuf *arg0) = 0;
    virtual int FGetErrno() = 0;
    virtual int FFlush(_iobuf *arg0) = 0;
    virtual void *PoolMalloc(uint64_t arg0) = 0;
    virtual void PoolFree(void *arg0) = 0;
    virtual IMemoryBlock *PoolAllocMemoryBlock(uint64_t arg0, const char *arg1, uint64_t arg2) = 0;
    virtual int64_t FindFirst(const char *pDir, _finddata64i32_t *fd, unsigned nPathFlags, bool bAllowUseFileSystem) = 0;
    virtual int FindNext(int64_t arg0, _finddata64i32_t *arg1) = 0;
    virtual int FindClose(int64_t arg0) = 0;
    virtual uint64_t GetModificationTime(_iobuf *arg0) = 0;
    virtual bool IsFileExist(const char *arg0, ICryPak::EFileSearchLocation arg1) = 0;
    virtual bool IsFolder(const char *arg0) = 0;
    virtual int64_t GetFileSizeOnDisk(const char *arg0) = 0;
    virtual bool IsFileCompressed(const char *arg0) = 0;
    virtual bool MakeDir(const char *arg0, bool arg1) = 0;
    virtual ICryArchive *OpenArchive(const char *arg0, unsigned arg1, IMemoryBlock *arg2) = 0;
    virtual const char *GetFileArchivePath(_iobuf *arg0) = 0;
    virtual int RawCompress(const void *arg0, unsigned long *arg1, void *arg2, unsigned long arg3, int arg4) = 0;
    virtual int RawUncompress(void *arg0, unsigned long *arg1, const void *arg2, unsigned long arg3) = 0;
    virtual void RecordFileOpen(ICryPak::ERecordFileOpenList arg0) = 0;
    virtual void RecordFile(_iobuf *arg0, const char *arg1) = 0;
    virtual IResourceList *GetResourceList(ICryPak::ERecordFileOpenList arg0) = 0;
    virtual void SetResourceList(ICryPak::ERecordFileOpenList arg0, IResourceList *arg1) = 0;
    virtual ICryPak::ERecordFileOpenList GetRecordFileOpenList() = 0;
    virtual unsigned ComputeCRC(const char *arg0, unsigned arg1) = 0;
    virtual bool ComputeMD5(const char *arg0, uint8_t *arg1, unsigned arg2) = 0;
    virtual int ComputeCachedPakCDR_CRC(const char *arg0, bool arg1, IMemoryBlock *arg2) = 0;
    virtual void RegisterFileAccessSink(ICryPakFileAcesssSink *arg0) = 0;
    virtual void UnregisterFileAccessSink(ICryPakFileAcesssSink *arg0) = 0;
    virtual bool GetLvlResStatus() const = 0;
    virtual void DisableRuntimeFileAccess(bool arg0) = 0;
    virtual bool DisableRuntimeFileAccess(bool arg0, unsigned long arg1) = 0;
    virtual bool CheckFileAccessDisabled(const char *arg0, const char *arg1) = 0;
    virtual void SetRenderThreadId(unsigned long arg0) = 0;
    virtual int GetPakPriority() = 0;
    virtual uint64_t GetFileOffsetOnMedia(const char *arg0) = 0;
    virtual EStreamSourceMediaType GetFileMediaType(const char *arg0) = 0;
    virtual void CreatePerfHUDWidget() = 0;
    virtual void ScanDirectory(const char *_folderPath, const char *_fileFilter, std::vector<string> &_outFiles, bool _recursive, bool _bAllowUseFileSystem) = 0;
};

struct SDirectoryEnumeratorHelper // Id=8002F48 Size=1
{
    void ScanDirectoryRecursive(string const &root, string const &pathIn, string const &fileSpec, std::vector<string> &files) { FScanDirectoryRecursive(this,root,pathIn,fileSpec,files); }
    void ScanDirectoryFiles(string const &root, string const &path, string const &fileSpec, std::vector<string> &files) { FScanDirectoryFiles(this,root,path,fileSpec,files); }

    static inline auto FScanDirectoryRecursive = PreyFunction<void(SDirectoryEnumeratorHelper *const _this, string const &root, string const &pathIn, string const &fileSpec, std::vector<string> &files)>(0x24C340);
    static inline auto FScanDirectoryFiles = PreyFunction<void(SDirectoryEnumeratorHelper *const _this, string const &root, string const &path, string const &fileSpec, std::vector<string> &files)>(0x24C0E0);
};
