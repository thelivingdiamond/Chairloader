#pragma once
#include <shared_mutex>

//! An in-memory cache of XML files. May be backed by disk storage.
struct IXmlCache
{
    using UniqueLock = std::unique_lock<std::shared_mutex>;
    using SharedLock = std::shared_lock<std::shared_mutex>;

    enum class EOpenResult
    {
        //! File has been sucessfully opened.
        Success,

        //! File was not found.
        NotFound,

        //! File is locked by a different thread.
        Locked,

        //! File was loaded with different parse flags.
        ParseFlagsMismatch,

        //! File was loaded with different format flags.
        FormatFlagsMismatch,
    };

    virtual ~IXmlCache() = default;

    //! Opens an XML file for reading. If already open for writing, throws.
    //! The document must not be modified as it may be opened by multiple threads. pugixml doesn't really enforce that.
    //! @param  relPath     Relative XML path.
    //! @param  lock        Unique lock. Document may only be used while it's active.
    //! @param  parseFlags  XML parse flags.
    virtual EOpenResult TryOpenXmlForReading(
        const fs::path& relPath,
        const pugi::xml_document** ppOutDocument,
        SharedLock& lock,
        unsigned parseFlags = pugi::parse_default) = 0;

    //! Opens an XML file for writing. If already open for reading or writing, throws.
    //! @param  relPath     Relative XML path.
    //! @param  lock        Unique lock. Document may only be used while it's active.
    //! @param  parseFlags  XML parse flags.
    virtual EOpenResult TryOpenXmlForWriting(
        const fs::path& relPath,
        pugi::xml_document** ppOutDocument,
        UniqueLock& lock,
        unsigned parseFlags = pugi::parse_default,
        unsigned formatFlags = pugi::format_default) = 0;

    //! Opens an XML file for reading. If already open for writing, throws.
    //! The document must not be modified as it may be opened by multiple threads. pugixml doesn't really enforce that.
    //! @param  relPath     Relative XML path.
    //! @param  lock        Unique lock. Document may only be used while it's active.
    //! @param  parseFlags  XML parse flags.
    virtual const pugi::xml_document& OpenXmlForReading(
        const fs::path& relPath,
        SharedLock& lock,
        unsigned parseFlags = pugi::parse_default)
    {
        const pugi::xml_document* pDoc = nullptr;
        EOpenResult result = TryOpenXmlForReading(relPath, &pDoc, lock, parseFlags);
        ThrowForResult(result);
        return *pDoc;
    }

    //! Opens an XML file for writing. If already open for reading or writing, throws.
    //! @param  relPath     Relative XML path.
    //! @param  lock        Unique lock. Document may only be used while it's active.
    //! @param  parseFlags  XML parse flags.
    virtual pugi::xml_document& OpenXmlForWriting(
        const fs::path& relPath,
        UniqueLock& lock,
        unsigned parseFlags = pugi::parse_default,
        unsigned formatFlags = pugi::format_default)
    {
        pugi::xml_document* pDoc = nullptr;
        EOpenResult result = TryOpenXmlForWriting(relPath, &pDoc, lock, parseFlags, formatFlags);
        ThrowForResult(result);
        return *pDoc;
    }

    //! Gets the list of currently cached files. They are guaranteed to be valid XMLs. Includes new files.
    virtual void GetCachedFileList(std::vector<fs::path>& outList) = 0;

    //! Gets the list of all files. Some of them may not actually be XMLs.
    virtual void GetAllFileList(std::vector<fs::path>& outList) = 0;

    static void ThrowForResult(EOpenResult result)
    {
        switch (result)
        {
        case EOpenResult::Success:
            return;
        case EOpenResult::NotFound:
            throw std::runtime_error("File was not found");
        case EOpenResult::Locked:
            throw std::runtime_error("File is locked by another thread");
        case EOpenResult::ParseFlagsMismatch:
            throw std::runtime_error("File was loaded with different parse flags");
        default:
            throw std::logic_error("Unknown error");
        }
    }
};
