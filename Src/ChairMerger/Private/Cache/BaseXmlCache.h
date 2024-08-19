#pragma once
#include <ChairMerger/Export.h>
#include "Cache/IXmlCache.h"

class CHAIRMERGER_EXPORT BaseXmlCache : public IXmlCache, boost::noncopyable
{
public:
    BaseXmlCache();
    ~BaseXmlCache();

    // MemoryXmlCache
    virtual EOpenResult TryOpenXmlForReading(
        const fs::path& relPath,
        const pugi::xml_document** ppOutDocument,
        SharedLock& lock,
        unsigned parseFlags = pugi::parse_default) override;

    virtual EOpenResult TryOpenXmlForWriting(
        const fs::path& relPath,
        pugi::xml_document** ppOutDocument,
        UniqueLock& lock,
        unsigned parseFlags = pugi::parse_default,
        unsigned formatFlags = pugi::format_default) override;

protected:
    struct FileEntry
    {
        std::shared_mutex mutex;
        pugi::xml_document document;
        fs::path relPath;
        std::string relPathNorm;
        unsigned parseFlags = 0;
        unsigned formatFlags = 0;
        bool isModified = false;
        size_t userIdx = 0;
    };

    using FileMap = std::unordered_map<std::string, std::unique_ptr<FileEntry>>;

    mutable std::shared_mutex m_FileMapMutex;
    FileMap m_FileMap;

    //! Loads the file to cache from disk. Throws on parsing error.
    //! @returns Whether the file was found on disk.
    virtual bool LoadDocument(const fs::path& relPath, const std::string& relPathNorm, pugi::xml_document& outDoc) = 0;

    //! Initializes a new object.
    virtual void InitObject(FileEntry& fileEntry) {}

    static std::string NormalizePath(const fs::path& path);

private:
    EOpenResult InitEntry(
        const fs::path& relPath,
        const std::string& relPathNorm,
        std::shared_lock<std::shared_mutex>& mapLock,
        FileMap::iterator& it,
        int parseFlags,
        int formatFlags,
        bool isWriting);
};
