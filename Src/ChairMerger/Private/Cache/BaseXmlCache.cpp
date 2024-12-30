#include "Cache/BaseXmlCache.h"

BaseXmlCache::BaseXmlCache()
{
}

BaseXmlCache::~BaseXmlCache()
{
}

IXmlCache::EOpenResult BaseXmlCache::TryOpenXmlForReading(
    const fs::path& relPath,
    const pugi::xml_document** ppOutDocument,
    ReadLock& lock,
    unsigned parseFlags)
{
    if (lock.owns_lock())
        throw std::logic_error("Passed lock must not be locked");

    std::string relPathNorm = NormalizePath(relPath);

    // Find the file in the map
    std::shared_lock mapLock(m_FileMapMutex);
    
    FileMap::iterator it;
    EOpenResult initResult = InitEntry(relPath, relPathNorm, mapLock, it, parseFlags, 0, false);
    if (initResult != EOpenResult::Success)
        return initResult;

    // Lock the file entry
    lock = ReadLock(it->second->mutex, std::defer_lock);

    if (!lock.try_lock())
        return EOpenResult::Locked;

    *ppOutDocument = &it->second->document;
    return EOpenResult::Success;
}

IXmlCache::EOpenResult BaseXmlCache::TryOpenXmlForWriting(
    const fs::path& relPath,
    pugi::xml_document** ppOutDocument,
    WriteLock& lock,
    unsigned parseFlags,
    unsigned formatFlags)
{
    if (lock.owns_lock())
        throw std::logic_error("Passed lock must not be locked");

    std::string relPathNorm = NormalizePath(relPath);

    // Find the file in the map
    std::shared_lock mapLock(m_FileMapMutex);

    FileMap::iterator it;
    EOpenResult initResult = InitEntry(relPath, relPathNorm, mapLock, it, parseFlags, formatFlags, true);
    if (initResult != EOpenResult::Success)
        return initResult;

    // Lock the file entry
    lock = WriteLock(it->second->mutex, std::defer_lock);

    if (!lock.try_lock())
        return EOpenResult::Locked;

    *ppOutDocument = &it->second->document;
    return EOpenResult::Success;
}

void BaseXmlCache::GetCachedFileList(std::vector<fs::path>& outList)
{
    std::shared_lock mapLock(m_FileMapMutex);
    outList.clear();

    for (const auto& i : m_FileMap)
    {
        outList.push_back(i.second->relPath);
    }
}

void BaseXmlCache::GetAllFileList(std::vector<fs::path>& outList)
{
    // By default, return cached files
    GetCachedFileList(outList);
}

std::string BaseXmlCache::NormalizePath(const fs::path& path)
{
    if (!path.is_relative())
        throw std::invalid_argument("Path must be relative");

    std::string pathStr = path.u8string();

    for (char& c : pathStr)
    {
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        else if (c == '\\')
            c = '/';
    }

    return pathStr;
}

IXmlCache::EOpenResult BaseXmlCache::InitEntry(
    const fs::path& relPath,
    const std::string& relPathNorm,
    std::shared_lock<std::shared_mutex>& mapLock,
    FileMap::iterator& it,
    int parseFlags,
    int formatFlags,
    bool isWriting)
{
    if (isWriting && (parseFlags == DONT_PARSE) != (formatFlags == DONT_FORMAT))
        throw std::invalid_argument("If one of the flags is DONT, both must be");

    it = m_FileMap.find(relPathNorm);

    // Not found
    if (it == m_FileMap.end())
    {
        if (parseFlags == DONT_PARSE || formatFlags == DONT_FORMAT)
            return EOpenResult::NotFound;

        // File not yet loaded. Load it from disk.
        pugi::xml_document doc;
        if (!LoadDocument(relPath, relPathNorm, doc))
        {
            // Else, create a new document
            if (!isWriting)
                return EOpenResult::NotFound;
        }

        // Now save it to the cache
        // Upgrade the lock
        std::unique_lock mapLockUnique(m_FileMapMutex, std::defer_lock);
        mapLock.unlock();
        mapLockUnique.lock();

        // Check that a different thread hasn't created the file in the meantime
        it = m_FileMap.find(relPathNorm);

        if (it == m_FileMap.end())
        {
            // File still doesn't exist
            it = m_FileMap.emplace(relPathNorm, std::make_unique<FileEntry>()).first;
            it->second->document = std::move(doc);
            it->second->relPath = relPath;
            it->second->relPathNorm = relPathNorm;
            it->second->parseFlags = parseFlags;
            it->second->formatFlags = formatFlags;
            it->second->isModified = isWriting;

            if (isWriting)
                it->second->formatFlags = formatFlags;

            InitObject(*it->second);
        }

        // Downgrade the lock
        mapLockUnique.unlock();
        mapLock.lock();
    }

    // Check flags
    if (parseFlags != DONT_PARSE && it->second->parseFlags != parseFlags)
        return EOpenResult::ParseFlagsMismatch;

    if (formatFlags != DONT_FORMAT && isWriting && it->second->formatFlags != formatFlags)
        return EOpenResult::FormatFlagsMismatch;

    return EOpenResult::Success;
}
