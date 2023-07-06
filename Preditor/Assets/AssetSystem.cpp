#include <WindowManager/WindowManager.h>
#include "Import/AssetImportSystem.h"
#include "Merging/AssetMergeSystem.h"
#include "UI/InvalidateWindow.h"
#include "UI/ModManagerWindow.h"
#include "AssetSystem.h"

std::unique_ptr<IAssetSystem> IAssetSystem::CreateInstance()
{
    return std::make_unique<Assets::AssetSystem>();
}

Assets::AssetSystem::AssetSystem()
{
    m_pImportSystem = std::make_unique<AssetImportSystem>(this);
    m_pMergeSystem = std::make_unique<AssetMergeSystem>();
    m_pModManagerWindow = WindowManager::Get().Create<ModManagerWindow>();
    m_pInvalidateWindow = WindowManager::Get().Create<InvalidateWindow>();
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

void Assets::AssetSystem::InitSystem()
{
    // Merge assets early on
    if (!RunMerging())
    {
        CryFatalError("Start-up merging failed. Preditor cannot continue to load. Check the console for details.");
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

void Assets::AssetSystem::InvalidateCache(bool import, bool merge)
{
    if (import)
        m_pImportSystem->InvalidateCache();

    if (merge)
        m_pMergeSystem->InvalidateCache();
}

void Assets::AssetSystem::ShowMainMenu()
{
    if (ImGui::MenuItem("Merge Assets"))
        RequestMerging();

    m_pModManagerWindow->ShowToggleMenuItem("Mod Manager...");
    m_pInvalidateWindow->ShowToggleMenuItem("Invalidate Caches...");
}

bool Assets::AssetSystem::RunMerging()
{
    CryLog("[AssetSystem] MERGING BEGIN");

    // Clear old metadata cache
    {
        std::scoped_lock lock(m_MetadataCacheMutex);
        m_MetadataCache.clear();
    }

    CryLog("[AssetSystem] Importing assets...");
    bool importResult = m_pImportSystem->ImportAssets();

    if (!importResult)
    {
        CryError("[AssetSystem] Import failed. Merging aborted.");
        return false;
    }

    CryLog("[AssetSystem] Merging assets...");
    bool mergeResult = m_pMergeSystem->MergeAssets();

    if (!mergeResult)
    {
        CryError("[AssetSystem] Merging failed.");
        return false;
    }

    CryLog("[AssetSystem] Merging finished successfully.");
    return true;
}
