#pragma once
#include <Preditor/Assets/Common.h>
#include "AssetsCommon.h"

namespace Assets
{

class AssetSystem;
class AssetImporter;

class AssetImportSystem
{
public:
    AssetImportSystem(AssetSystem* pSys);
    ~AssetImportSystem();

    //! Invalidates list of imported files. Causes all assets to be reimported next time.
    void InvalidateCache();

    //! Imports any changed assets.
    //! @returns true if there were no errors.
    bool ImportAssets();

private:
    static constexpr char CACHE_FILE_NAME[] = "ImportCache.xml";
    static constexpr char CACHE_NODE[] = "ImportCache";
    static constexpr char CACHE_ITEM_NODE[] = "InputFile";
    static constexpr char OUT_FILE_NODE[] = "OutFile";

    struct ImportCacheItem
    {
        std::string inputFile;
        FileModTime modTime = FileModTime();
        FileModTime metaModTime = FileModTime();
        std::vector<std::string> outFiles;
    };

    struct ImportCache
    {
        std::map<std::string, ImportCacheItem, std::less<>> items;
    };

    struct SourceFile
    {
        FileModTime modTime = FileModTime();
        FileModTime metaModTime = FileModTime();
    };

    using SourceFileList = std::map<std::string, SourceFile, std::less<>>;
    using AssetImporterPtr = std::unique_ptr<AssetImporter>;
    using ImporterFactory = std::function<AssetImporterPtr()>;

    AssetSystem* m_pSys = nullptr;
    std::map<std::string, ImporterFactory> m_ImporterFactories;

    //! Loads import cache from disk.
    ImportCache LoadCache();

    //! Saves import cache to disk.
    void SaveCache(const ImportCache& cache);

    //! Finds all assets for import in the project.
    SourceFileList FindSourceFiles();

    void RecursiveFindSourceFiles(const std::string& path, SourceFileList& list);

    //! Re-imports the file.
    //! @returns true if successful.
    bool ImportAsset(const std::string& path, std::vector<std::string>& outFiles);

    //! Removes output files.
    void RemoveOutFiles(const std::vector<std::string>& outFiles);

    //! Creates an asset importer by its name.
    //! Throws if importer not found.
    AssetImporterPtr CreateImporter(const std::string& name);

    template <typename T>
    void CreateImporterFactory(const std::string& name)
    {
        auto it = m_ImporterFactories.find(name);

        if (it != m_ImporterFactories.end())
            CryFatalError("AssetImportSystem: Duplicate factory '{}'", name);

        auto f = []() -> AssetImporterPtr
        {
            return std::make_unique<T>();
        };

        m_ImporterFactories.insert({ name, f });
    }

    template <typename T>
    void CreateImporterFactory()
    {
        CreateImporterFactory<T>(T::NAME);
    }
};

} // namespace Assets
