#include "Import/AssetImportSystem.h"
#include "Import/CopyAssetImporter.h"
#include "AssetMetadata.h"
#include "AssetsCommon.h"
#include "AssetSystem.h"

Assets::AssetImportSystem::AssetImportSystem(AssetSystem* pSys)
{
    m_pSys = pSys;
    CreateImporterFactory<CopyAssetImporter>();
}

Assets::AssetImportSystem::~AssetImportSystem()
{
}

void Assets::AssetImportSystem::InvalidateCache()
{
    fs::path cachePath = gPreditor->pPaths->GetUserPath() / CACHE_FILE_NAME;

    if (fs::exists(cachePath))
        fs::remove(cachePath);
}

bool Assets::AssetImportSystem::ImportAssets()
{
    try
    {
        ImportCache cache = LoadCache();
        SourceFileList sourceFiles = FindSourceFiles();

        // Remove files that no longer exist
        for (auto& i : cache.items)
        {
            auto it = sourceFiles.find(i.second.inputFile);

            if (it == sourceFiles.end())
            {
                if constexpr (ASSETS_DEBUG)
                    CryLog("[ImportAssets] Source file removed: {}", i.second.inputFile);

                RemoveOutFiles(i.second.outFiles);
            }
        }

        int errorCount = 0;

        // Import updated files
        for (auto& i : sourceFiles)
        {
            const std::string& assetRelPath = i.first;
            auto itCache = cache.items.find(assetRelPath);

            bool needImport = false;

            if (itCache == cache.items.end())
            {
                // New file
                needImport = true;

                if constexpr (ASSETS_DEBUG)
                    CryLog("[ImportAssets] New source file: {}", assetRelPath);
            }
            else
            {
                // Check modification date
                needImport = i.second.modTime != itCache->second.modTime ||
                    i.second.metaModTime != itCache->second.metaModTime;

                if (ASSETS_DEBUG && needImport)
                    CryLog("[ImportAssets] Source file changed: {}", assetRelPath);
            }

            if (needImport)
            {
                // Remove old files
                if (itCache != cache.items.end())
                    RemoveOutFiles(itCache->second.outFiles);

                std::vector<std::string> outFiles;
                bool success = ImportAsset(assetRelPath, outFiles);

                if (success)
                {
                    // Create cache entry
                    if (itCache == cache.items.end())
                    {
                        ImportCacheItem cacheItem;
                        cacheItem.inputFile = assetRelPath;
                        itCache = cache.items.insert({ assetRelPath, cacheItem }).first;
                    }

                    // Update the cache
                    itCache->second.modTime = i.second.modTime;
                    itCache->second.metaModTime = i.second.metaModTime;
                    itCache->second.outFiles = outFiles;
                }
                else
                {
                    errorCount++;
                }
            }
        }

        SaveCache(cache);
        return errorCount == 0;
    }
    catch (const std::exception& e)
    {
        CryError("[ImportAssets] Error: {}", e.what());
        return false;
    }
}

Assets::AssetImportSystem::ImportCache Assets::AssetImportSystem::LoadCache()
{
    fs::path cachePath = gPreditor->pPaths->GetUserPath() / CACHE_FILE_NAME;

    if (!fs::exists(cachePath))
        return ImportCache();

    try
    {
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(cachePath.c_str());

        if (!result)
            throw std::runtime_error(result.description());

        ImportCache cache;

        for (pugi::xml_node itemNode : doc.child(CACHE_NODE).children(CACHE_ITEM_NODE))
        {
            ImportCacheItem item;
            item.inputFile = itemNode.attribute("path").as_string();
            item.modTime = FileModTime(itemNode.attribute("modTime").as_llong());
            item.metaModTime = FileModTime(itemNode.attribute("metaModTime").as_llong());

            for (pugi::xml_node fileNode : itemNode.children(OUT_FILE_NODE))
            {
                item.outFiles.push_back(fileNode.text().as_string());
            }

            cache.items.insert({ item.inputFile, std::move(item) });
        }

        return cache;
    }
    catch (const std::exception& e)
    {
        CryWarning("[AssetImportSystem] Failed to load import cache: {}", e.what());
        CryWarning("[AssetImportSystem] Ignoring corrupted cache.");
        return ImportCache();
    }
}

void Assets::AssetImportSystem::SaveCache(const ImportCache& cache)
{
    fs::path cachePath = gPreditor->pPaths->GetUserPath() / CACHE_FILE_NAME;

    if (fs::exists(cachePath))
        fs::remove(cachePath);

    try
    {
        pugi::xml_document doc;
        pugi::xml_node cacheNode = doc.append_child(CACHE_NODE);

        for (auto& i : cache.items)
        {
            const ImportCacheItem& item = i.second;
            pugi::xml_node itemNode = cacheNode.append_child(CACHE_ITEM_NODE);
            itemNode.append_attribute("path").set_value(item.inputFile.c_str());
            itemNode.append_attribute("modTime").set_value(item.modTime.count());
            itemNode.append_attribute("metaModTime").set_value(item.metaModTime.count());

            for (const std::string& outFile : item.outFiles)
            {
                itemNode.append_child(OUT_FILE_NODE).text().set(outFile.c_str());
            }
        }

        if (!doc.save_file(cachePath.c_str()))
            throw std::runtime_error("save_file failed");
    }
    catch (const std::exception& e)
    {
        CryWarning("[AssetImportSystem] Failed to save import cache: {}", e.what());
        CryWarning("[AssetImportSystem] Next import may go wrong.");
    }
}

Assets::AssetImportSystem::SourceFileList Assets::AssetImportSystem::FindSourceFiles()
{
    SourceFileList list;

    if (fs::exists(gPreditor->pPaths->GetAssetPath()))
    {
        RecursiveFindSourceFiles("", list);
    }
    else
    {
        if constexpr (ASSETS_DEBUG)
            CryWarning("[ImportAssets] Asset path doesn't exist: {}", gPreditor->pPaths->GetAssetPath().u8string());
    }

    return list;
}

void Assets::AssetImportSystem::RecursiveFindSourceFiles(const std::string& path, SourceFileList& list)
{
    fs::path realPath = gPreditor->pPaths->GetAssetPath() / fs::u8path(path);

    for (const fs::directory_entry& entry : fs::directory_iterator(realPath))
    {
        if (entry.is_directory())
        {
            RecursiveFindSourceFiles(path + entry.path().filename().u8string() + '/', list);
        }
        else
        {
            std::string relPath = path + entry.path().filename().u8string();
            StrToLower(relPath);

            AssetMetadata* pMetadata = m_pSys->GetMetadata(relPath);

            if (pMetadata && !pMetadata->skipMerge && !pMetadata->importerName.empty())
            {
                SourceFile item;
                item.modTime = entry.last_write_time().time_since_epoch();
                item.metaModTime = fs::last_write_time(pMetadata->metadataPath).time_since_epoch();
                list.insert({ relPath, item });
            }
        }
    }
}

bool Assets::AssetImportSystem::ImportAsset(const std::string& path, std::vector<std::string>& outFiles)
{
    if constexpr (ASSETS_DEBUG)
        CryLog("[ImportAssets] Importing: {}", path);

    AssetMetadata* pMetadata = nullptr;

    try
    {
        pMetadata = m_pSys->GetMetadata(path);

        if (!pMetadata)
            throw std::logic_error("GetMetadata returned nullptr. Bug in list generation?");
    }
    catch (const std::exception& e)
    {
        CryError("[ImportAssets] Failed to open metadata: {}", path);
        CryError("[ImportAssets] {}", e.what());
        return false;
    }

    try
    {
        CRY_ASSERT_MESSAGE(!pMetadata->importerName.empty(), "Name must not be empty. File changed on disk or bug in file list generation.");

        AssetImporterPtr pImp = CreateImporter(pMetadata->importerName);
        pImp->ImportAsset(*pMetadata);
        outFiles = pImp->GetOutputFiles();
        return true;
    }
    catch (const std::exception& e)
    {
        CryError("[ImportAssets] Failed to import: {}", path);
        CryError("[ImportAssets] Importer: {}", pMetadata->importerName);
        CryError("[ImportAssets] {}", e.what());
        return false;
    }
}

void Assets::AssetImportSystem::RemoveOutFiles(const std::vector<std::string>& outFiles)
{
    for (const std::string& outFile : outFiles)
    {
        fs::path outFilePath = gPreditor->pPaths->GetImportedAssetsPath() / fs::u8path(outFile);

        if (fs::exists(outFilePath))
        {
            if constexpr (ASSETS_DEBUG)
                CryLog("[ImportAssets] Output file removed: {}", outFile);

            std::error_code ec;
            fs::remove(outFilePath, ec);

            if (ec)
                CryError("[ImportAssets] Failed to remove {}: {}", outFile, ec.message());
        }
        else
        {
            if constexpr (ASSETS_DEBUG)
                CryLog("[ImportAssets] Output file already removed: {}", outFile);
        }
    }
}

Assets::AssetImportSystem::AssetImporterPtr Assets::AssetImportSystem::CreateImporter(const std::string& name)
{
    auto it = m_ImporterFactories.find(name);

    if (it == m_ImporterFactories.end())
        throw std::runtime_error(fmt::format("Unknown importer '{}'", name));

    return it->second();
}
