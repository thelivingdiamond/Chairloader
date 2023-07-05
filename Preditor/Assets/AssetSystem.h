#pragma once
#include <Preditor/Assets/IAssetSystem.h>
#include "AssetMetadata.h"

namespace Assets
{

class AssetImportSystem;
class AssetMergeSystem;
class ModManagerWindow;

class AssetSystem final : public IAssetSystem
{
public:
    AssetSystem();
    ~AssetSystem();

    //! Gets the metadata. It may be cached. Returned pointer is only valid
    //! during merging. Thread-safe.
    //! @param  relPath Relative path to the asset.
    //! @returns metadata file for specified file. nullptr if doesn't exist.
    AssetMetadata* GetMetadata(std::string_view relPath);

    // IAssetSystem
    virtual void InitSystem() override;
    virtual void Update() override;
    virtual void RequestMerging() override;
    virtual void ShowMainMenu() override;

private:
    std::unique_ptr<AssetImportSystem> m_pImportSystem;
    std::unique_ptr<AssetMergeSystem> m_pMergeSystem;
    std::shared_ptr<ModManagerWindow> m_pModManagerWindow;

    std::mutex m_MetadataCacheMutex;
    std::map<std::string, AssetMetadata, std::less<>> m_MetadataCache;

    bool m_MergeNextFrame = false;

    bool RunMerging();
};

} // namespace Assets
