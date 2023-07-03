#include "Import/AssetImportSystem.h"
#include "AssetSystem.h"

std::unique_ptr<IAssetSystem> IAssetSystem::CreateInstance()
{
    return std::make_unique<Assets::AssetSystem>();
}

Assets::AssetSystem::AssetSystem()
{
    m_pImportSystem = std::make_unique<AssetImportSystem>(this);
}

Assets::AssetSystem::~AssetSystem()
{
}

Assets::AssetMetadata* Assets::AssetSystem::GetMetadata(std::string_view relPath)
{
#ifdef DEBUG_BUILD
    // Verify path is lowercase and uses forward slashes
    for (const char& c : relPath)
    {
        assert(c != '\\');
        assert(c == CharToLower(c));
    }
#endif

    std::scoped_lock lock(m_MetadataCacheMutex);
    auto it = m_MetadataCache.find(relPath);

    // Return cached item
    if (it != m_MetadataCache.end())
        return &it->second;

    std::string metaRelPath = fmt::format("{}.{}", relPath, ASSET_META_EXT);
    fs::path metaPath = gPreditor->pPaths->GetAssetPath() / fs::u8path(metaRelPath);
    
    if (fs::exists(metaPath))
    {
        // Create new cache item
        it = m_MetadataCache.insert({ std::string(relPath), AssetMetadata() }).first;
        it->second.Init(it->first, metaPath);
        return &it->second;
    }
    else
    {
        // File doesn't exist
        return nullptr;
    }
}

void Assets::AssetSystem::Update()
{
    if (m_MergeNextFrame)
    {
        m_MergeNextFrame = false;
        RunMerging();
    }
}

void Assets::AssetSystem::RequestMerging()
{
    m_MergeNextFrame = true;
}

void Assets::AssetSystem::RunMerging()
{
    CryLog("[AssetSystem] MERGING BEGIN");
    CryLog("[AssetSystem] Importing assets...");
    bool importResult = m_pImportSystem->ImportAssets();

    if (!importResult)
    {
        CryError("[AssetSystem] Import failed. Merging aborted.");
        return;
    }
}
