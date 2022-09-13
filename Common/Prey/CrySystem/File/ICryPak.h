// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryString/CryFixedString.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include "Prey/CrySystem/IStreamEngineDefs.h"

struct ICryArchive;
struct ICryPakFileAcesssSink;
struct IMemoryBlock;
struct IResourceList;

struct IResourceList;
struct _finddata_t;
struct IMemoryBlock;

//! \cond INTERNAL
//! This represents one particular archive filcare.
struct ICryArchive : public _reference_target_t
{
    //! Compression methods.
    enum ECompressionMethods
    {
        METHOD_STORE                = 0,
        METHOD_COMPRESS             = 8,
        METHOD_DEFLATE              = 8,
        METHOD_COMPRESS_AND_ENCRYPT = 11
    };

    //! Compression levels.
    enum ECompressionLevels
    {
        LEVEL_FASTEST = 0,
        LEVEL_FASTER  = 2,
        LEVEL_NORMAL  = 8,
        LEVEL_BETTER  = 8,
        LEVEL_BEST    = 9,
        LEVEL_DEFAULT = -1
    };

    enum EPakFlags : uint32
    {
        //! Support for absolute and other complex path specifications.
        //! All paths will be treated relatively to the current directory (normally MasterCD).
        FLAGS_ABSOLUTE_PATHS = BIT(0),

        //! If this is set, the object will only understand relative to the zip file paths.
        //! However, this can give an opportunity to optimize for frequent quick accesses.
        //! FLAGS_SIMPLE_RELATIVE_PATHS and FLAGS_ABSOLUTE_PATHS are mutually exclusive.
        FLAGS_RELATIVE_PATHS_ONLY = BIT(1),

        //! If this flag is set, the archive update/remove operations will not work.
        //! This is useful when you open a read-only or already opened for reading files.
        //! If FLAGS_OPEN_READ_ONLY | FLAGS_SIMPLE_RELATIVE_PATHS are set, ICryPak
        //! will try to return an object optimized for memory, with long life cycle.
        FLAGS_READ_ONLY = BIT(2),

        //! If this flag is set, FLAGS_OPEN_READ_ONLY flags are also implied.
        //! The returned object will be optimized for quick access and memory footprint.
        FLAGS_OPTIMIZED_READ_ONLY = BIT(3),

        //! If this is set, the existing file (if any) will be overwritten.
        FLAGS_CREATE_NEW = BIT(4),

        //! If this flag is set, and the file is opened for writing, and some files were updated
        //! so that the archive is no more continuous, the archive will nevertheless NOT be compacted
        //! upon closing the archive file. This can be faster if you open/close the archive for writing
        //! multiple times.
        FLAGS_DONT_COMPACT = BIT(5),

        //! Flag is set when complete pak has been loaded into memory.
        FLAGS_IN_MEMORY      = BIT(6),
        FLAGS_IN_MEMORY_CPU  = BIT(7),
        FLAGS_IN_MEMORY_MASK = FLAGS_IN_MEMORY | FLAGS_IN_MEMORY_CPU,

        //! Store all file names as crc32 in a flat directory structure.
        FLAGS_FILENAMES_AS_CRC32 = BIT(8),

        //! Flag is set when pak is stored on HDD.
        FLAGS_ON_HDD = BIT(9),

        //! Override pak - paks opened with this flag go at the end of the list and contents will be found before other paks.
        //! Used for patching.
        FLAGS_OVERRIDE_PAK = BIT(10),

        //! Disable a pak file without unloading it, this flag is used in combination with patches and multiplayer
        //! to ensure that specific paks stay in the position(to keep the same priority) but being disabled
        //! when running multiplayer.
        FLAGS_DISABLE_PAK = BIT(11),

        FLAGS_WARN_ON_ACCESS = BIT(12),
        FLAGS_DISABLE_INVALID_PAK_WARNINGS = BIT(13),
    };

    typedef void* Handle;

    // <interfuscator:shuffle>
    virtual ~ICryArchive(){}

    struct IEnumerateArchiveEntries
    {
        virtual bool OnEnumArchiveEntry(const char* pFilename, Handle hEntry, bool bIsFolder, int aSize, int64 aModifiedTime) = 0;
        virtual ~IEnumerateArchiveEntries(){}
    };

    //! Enumerate the file entries found in the specified folder.
    //! \return The number of entries.
    virtual int EnumEntries(Handle hFolder, IEnumerateArchiveEntries* pEnum) = 0;

    //! Get archive's root folder.
    virtual Handle GetRootFolderHandle() = 0;

    //! Adds a new file to the zip or update an existing one.
    //! Adds a directory (creates several nested directories if needed)
    //! compression methods supported are METHOD_STORE == 0 (store) and
    //! METHOD_DEFLATE == METHOD_COMPRESS == 8 (deflate) , compression
    //! level is LEVEL_FASTEST == 0 till LEVEL_BEST == 9 or LEVEL_DEFAULT == -1
    //! for default (like in zlib)
    virtual int UpdateFile(const char* szRelativePath, void* pUncompressed, unsigned nSize, unsigned nCompressionMethod = 0, int nCompressionLevel = -1) = 0;

    //! Adds a new file to the zip or update an existing one if it is not compressed - just stored  - start a big file
    //! ( name might be misleading as if nOverwriteSeekPos is used the update is not continuous )
    //! First step for the UpdateFileConinouseSegment
    virtual int StartContinuousFileUpdate(const char* szRelativePath, unsigned nSize) = 0;

    //! Adds a new file to the zip or update an existing's segment if it is not compressed - just stored.
    //! Adds a directory (creates several nested directories if needed)
    //! \note The name might be misleading as if nOverwriteSeekPos is used the update is not continuous.
    //! \param nOverwriteSeekPos 0xffffffff means the seek pos should not be overwritten (then it needs UpdateFileCRC() to update CRC).
    virtual int UpdateFileContinuousSegment(const char* szRelativePath, unsigned nSize, void* pUncompressed, unsigned nSegmentSize, unsigned nOverwriteSeekPos = 0xffffffff) = 0;

    //! Needed to update CRC if UpdateFileContinuousSegment() was used with nOverwriteSeekPos.
    virtual int UpdateFileCRC(const char* szRelativePath, const uint32 dwCRC) = 0;

    //! Deletes the file from the archive.
    virtual int RemoveFile(const char* szRelativePath) = 0;

    //! Deletes the directory, with all its descendants (files and subdirs).
    virtual int RemoveDir(const char* szRelativePath) = 0;

    //! Deletes all files and directories in the archive.
    virtual int RemoveAll() = 0;

    //! Finds the file; you don't have to close the returned handle.
    //! \return NULL if the file doesn't exist
    virtual Handle FindFile(const char* szPath) = 0;

    //! Get the file size (uncompressed).
    //! \return The size of the file (unpacked) by the handle
    virtual unsigned GetFileSize(Handle) = 0;

    //! Reads the file into the preallocated buffer
    //! \note Must be at least the size returned by GetFileSize.
    virtual int ReadFile(Handle, void* pBuffer) = 0;

    //! Get the full path to the archive file.
    virtual const char* GetFullPath() const = 0;

    //! Get the flags of this object.
    //! The possibles flags are defined in EPakFlags.
    virtual unsigned GetFlags() const = 0;

    //! Sets the flags of this object.
    //! The possibles flags are defined in EPakFlags.
    virtual bool SetFlags(unsigned nFlagsToSet) = 0;

    //! Resets the flags of this object.
    virtual bool ResetFlags(unsigned nFlagsToSet) = 0;

    //! Control if files in this pack can be accessed
    //! \return true if archive state was changed
    virtual bool SetPackAccessible(bool bAccessible) = 0;

    //! Determines if the archive is read only.
    //! \return true if this archive is read-only
    inline bool IsReadOnly() const { return (GetFlags() & FLAGS_READ_ONLY) != 0; }

    //! Get the class id.
    virtual unsigned GetClassId() const = 0;

    //! Collect allocated memory in CrySizer
    virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
    // </interfuscator:shuffle>
};


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
    virtual const char *AdjustFileName(const char* src, char dst[g_nMaxPath], unsigned nFlags) = 0;

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
    virtual FILE* FOpen(const char* pName, const char* mode, unsigned nFlags = 0) = 0;
    virtual FILE* FOpen(const char* pName, const char* mode, char* szFileGamePath, int nLen) = 0;
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
    virtual bool MakeDir(const char* szPath, bool bGamePathMapping = false) = 0;
    //! Open the physical archive file - creates if it doesn't exist.
    //! nFlags is a combination of flags from EPakFlags enum.
    //! \return NULL if it's invalid or can't open the file.
    //! \see EPakFlags
    virtual ICryArchive* OpenArchive(const char* szPath, unsigned int nFlags = 0, IMemoryBlock* pData = 0) = 0;
    //! Returns the path to the archive in which the file was opened.
    //! \return NULL if the file is a physical file, and "" if the path to archive is unknown (shouldn't ever happen).
    virtual const char* GetFileArchivePath(FILE* f) = 0;;
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

    //! Type-independent Write.
    template<class T>
    void FWrite(T* data, size_t elems, FILE* handle)
    {
        FWrite((void*)data, sizeof(T), elems, handle);
    }
};

struct SDirectoryEnumeratorHelper // Id=8002F48 Size=1
{
    void ScanDirectoryRecursive(string const &root, string const &pathIn, string const &fileSpec, std::vector<string> &files) { FScanDirectoryRecursive(this,root,pathIn,fileSpec,files); }
    void ScanDirectoryFiles(string const &root, string const &path, string const &fileSpec, std::vector<string> &files) { FScanDirectoryFiles(this,root,path,fileSpec,files); }

    static inline auto FScanDirectoryRecursive = PreyFunction<void(SDirectoryEnumeratorHelper *const _this, string const &root, string const &pathIn, string const &fileSpec, std::vector<string> &files)>(0x24C340);
    static inline auto FScanDirectoryFiles = PreyFunction<void(SDirectoryEnumeratorHelper *const _this, string const &root, string const &path, string const &fileSpec, std::vector<string> &files)>(0x24C0E0);
};

#include <Prey/CryString/CryPath.h>

//! Everybody should use fxopen instead of fopen so it will work both on PC and XBox.
inline FILE* fxopen(const char* file, const char* mode, bool bGameRelativePath = false)
{
    if (gEnv && gEnv->pCryPak)
    {
        gEnv->pCryPak->CheckFileAccessDisabled(file, mode);
    }
    bool bWriteAccess = false;
    for (const char* s = mode; *s; s++)
    {
        if (*s == 'w' || *s == 'W' || *s == 'a' || *s == 'A' || *s == '+')
        {
            bWriteAccess = true;
            break;
        }
        ;
    }

    // This is on windows/xbox/Linux/Mac
    if (gEnv && gEnv->pCryPak)
    {
        int nAdjustFlags = 0;
        char path[_MAX_PATH];
        const char* szAdjustedPath = gEnv->pCryPak->AdjustFileName(file, path, nAdjustFlags);

#if !CRY_PLATFORM_LINUX && !CRY_PLATFORM_ANDROID && !CRY_PLATFORM_APPLE
        if (bWriteAccess)
        {
            // Make sure folder is created.
            gEnv->pCryPak->MakeDir(PathUtil::GetParentDirectory(szAdjustedPath).c_str());
        }
#endif
        return fopen(szAdjustedPath, mode);
    }
    else
        return 0;
}
