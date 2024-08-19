#include "Cache/DiskXmlCache.h"

DiskXmlCache::DiskXmlCache()
{
}

DiskXmlCache::~DiskXmlCache()
{
}

fs::path DiskXmlCache::GetRootDir() const
{
    std::shared_lock lock(m_FileMapMutex);
    return m_RootDir;
}

void DiskXmlCache::SetRootDir(const fs::path& value)
{
    std::unique_lock lock(m_FileMapMutex);
    m_RootDir = value;
}

void DiskXmlCache::ExportModifiedFiles(const fs::path& outRootDir)
{
    std::unique_lock lock(m_FileMapMutex);

    for (const auto& i : m_FileMap)
    {
        if (!i.second->isModified)
            continue;

        std::unique_lock fileLock(i.second->mutex);
        fs::path outPath = outRootDir / i.second->relPath;
        fs::create_directories(outPath.parent_path());

        if (!i.second->document.save_file(outPath.c_str(), "\t", i.second->formatFlags, pugi::encoding_utf8))
            throw std::runtime_error(fmt::format("Failed to write {}", outPath.u8string()));
    }
}

bool DiskXmlCache::LoadDocument(const fs::path& relPath, const std::string& relPathNorm, pugi::xml_document& outDoc)
{
    pugi::xml_document doc;
    fs::path realPath = m_RootDir / relPath;
    pugi::xml_parse_result parseResult = doc.load_file(realPath.c_str());

    if (parseResult.status == pugi::status_file_not_found)
        return false;

    if (!parseResult)
    {
        throw std::runtime_error(fmt::format(
            "XML parse error: {}.\nFile: {}\nOffset: {}",
            parseResult.description(), realPath.u8string(), parseResult.offset));
    }

    outDoc = std::move(doc);
    return true;
}
