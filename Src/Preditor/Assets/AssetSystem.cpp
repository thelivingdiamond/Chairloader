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
    while (true)
    {
        CryLog("[AssetSystem] Running start-up merging");
        bool result = RunMerging();

        if (result)
        {
            CryLog("[AssetSystem] Start-up merging succeded. Continuing.");
            break;
        }

        int dialogResult = CryMessageBox(
            "Start-up merging failed. Check the console for details.\n\n"
            "Cancel - Exit Preditor\n"
            "Try Again - Retry merging\n"
            "Continue - Ignore the error. Game may not function properly.\n",
            "Merging Failure",
            6 // MB_CANCELTRYCONTINUE
        );

        if (dialogResult == 0 || dialogResult == 2)
        {
            // IDCANCEL
            CryFatalError("Start-up merging failed. Check the console for details.");
        }
        else if (dialogResult == 11)
        {
            // IDCONTINUE
            CryLog("[AssetSystem] Start-up merging error ignored. Continuing.");
            break;
        }
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
    CTimeValue startTime = gEnv->pTimer->GetAsyncTime();
    CryLog("$7[AssetSystem] MERGING BEGIN");

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

    CTimeValue endTime = gEnv->pTimer->GetAsyncTime();
    CryLog("$5[AssetSystem] Merging finished successfully.");
    CryLog("$5[AssetSystem] Merging time: {:.3f} s.", (endTime - startTime).GetSeconds());
    return true;
}
