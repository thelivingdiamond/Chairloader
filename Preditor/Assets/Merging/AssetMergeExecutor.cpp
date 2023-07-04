#include "Merging/Mergers/AssetMerger.h"
#include "Merging/Sources/ChairloaderMergeSource.h"
#include "Merging/Sources/ImportMergeSource.h"
#include "Merging/Sources/ProjectMergeSource.h"
#include "Merging/AssetMergeExecutor.h"
#include "Merging/AssetMergeSystem.h"
#include "Merging/MergeCache.h"

Assets::AssetMergeExecutor::AssetMergeExecutor(AssetMergeSystem* pSys)
{
    m_pSys = pSys;
}

Assets::AssetMergeExecutor::~AssetMergeExecutor()
{
}

void Assets::AssetMergeExecutor::Execute()
{
    CreateMergeSources();
    CollectSourceFiles();
    
    MergeCache oldCache = m_pSys->LoadMergeCache();
    MergeCache newCache = CreateCache();

    FillMergeList(oldCache, newCache);

    if (m_FilesToMerge.empty() && m_FilesToRemove.empty())
    {
        // Early exit, don't overwrite the cache
        // (in case something was missed, in which case cache won't match the real state)
        if constexpr (ASSETS_DEBUG)
            CryLog("[Merging] Files are up to date, nothing to do");

        return;
    }

    RemoveOldFiles();
    MergeFiles(newCache);

    m_pSys->SaveMergeCache(newCache);

    if constexpr (ASSETS_DEBUG)
        CryLog("[Merging] Total merged files: {}", newCache.files.size());
}

void Assets::AssetMergeExecutor::CreateMergeSources()
{
    m_Sources.push_back(std::make_unique<ChairloaderMergeSource>());

    // TODO 2023-07-04: Create sources for mods
    
    // Project assets
    const fs::path& assetsPath = gPreditor->pPaths->GetAssetPath();
    if (fs::exists(assetsPath))
    {
        m_Sources.push_back(std::make_unique<ProjectMergeSource>(assetsPath));
    }

    // Imported project assets
    const fs::path& importedAssetsPath = gPreditor->pPaths->GetImportedAssetsPath();
    if (fs::exists(importedAssetsPath))
    {
        m_Sources.push_back(std::make_unique<ImportMergeSource>(importedAssetsPath));
    }

    for (auto& pSource : m_Sources)
    {
        m_SourceNameMap.emplace(pSource->GetSourceName(), pSource.get());
    }
}

void Assets::AssetMergeExecutor::CollectSourceFiles()
{
    for (auto& pSource : m_Sources)
    {
        pSource->CollectFiles();

        if constexpr (ASSETS_DEBUG)
            CryLog("[Merging] Source {}: {} files", pSource->GetSourceName(), pSource->GetFiles().size());
    }
}

Assets::MergeCache Assets::AssetMergeExecutor::CreateCache()
{
    MergeCache cache;

    for (auto& pSource : m_Sources)
    {
        for (const MergeFile& mergeFile : pSource->GetFiles())
        {
            // Find existing file
            auto it = cache.files.find(mergeFile.path);

            if (it == cache.files.end())
            {
                // Add new file entry
                it = cache.files.emplace(mergeFile.path, MergeCache::OutFile()).first;
                it->second.merger = m_pSys->GetMergerNameForFile(mergeFile.path);
            }

            // Add source file
            MergeCache::SourceFile sourceFile;
            sourceFile.source = pSource->GetSourceName();
            sourceFile.modTime = mergeFile.modTime;
            sourceFile.metaModTime = mergeFile.metaModTime;
            it->second.sourceFiles.emplace_back(std::move(sourceFile));
        }
    }

    return cache;
}

void Assets::AssetMergeExecutor::FillMergeList(const MergeCache& oldCache, const MergeCache& newCache)
{
    // TODO 2023-07-04: Check mod configs

    // Check new files
    for (const auto& [relPath, newFile] : newCache.files)
    {
        bool needMerging = false;
        auto oldIt = oldCache.files.find(relPath);

        if (oldIt == oldCache.files.end())
        {
            // New file
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] New file: {}", relPath);

            needMerging = true;
        }
        else
        {
            // Existing file
            const MergeCache::OutFile& oldFile = oldIt->second;

            if (!newFile.SelfEqualsTo(oldFile))
            {
                // Merger options changed
                if constexpr (ASSETS_DEBUG)
                    CryLog("[Merging] Merger changed: {}", relPath);

                needMerging = true;
            }
            else if (newFile.sourceFiles.size() != oldFile.sourceFiles.size())
            {
                // Source files added/removed
                if constexpr (ASSETS_DEBUG)
                    CryLog("[Merging] Source file list changed: {}", relPath);

                needMerging = true;
            }
            else
            {
                // Check source files
                for (size_t i = 0; i < newFile.sourceFiles.size(); i++)
                {
                    const MergeCache::SourceFile& newSource = newFile.sourceFiles[i];
                    const MergeCache::SourceFile& oldSource = oldFile.sourceFiles[i];
                    
                    if (newSource != oldSource)
                    {
                        // File changed
                        if constexpr (ASSETS_DEBUG)
                            CryLog("[Merging] Source file changed: {}", relPath);

                        needMerging = true;
                    }
                }
            }
        }

        if (needMerging)
        {
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] Needs merging: {}", relPath);

            m_FilesToMerge.insert(relPath);
        }
    }

    // Check removed files
    for (const auto& [relPath, oldFile] : oldCache.files)
    {
        auto newIt = newCache.files.find(relPath);

        if (newIt == newCache.files.end())
        {
            // File was removed
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] Needs remove: {}", relPath);

            m_FilesToRemove.insert(relPath);
        }
    }
}

void Assets::AssetMergeExecutor::RemoveOldFiles()
{
    for (const std::string& relPath : m_FilesToRemove)
    {
        fs::path path = gPreditor->pPaths->GetMergedAssetsPath() / fs::u8path(relPath);

        if (fs::exists(path))
        {
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] Removing: {}", relPath);

            std::error_code ec;
            fs::remove(path, ec);

            if (ec)
                CryError("[ImportAssets] Failed to remove {}: {}", relPath, ec.message());
        }
        else
        {
            if constexpr (ASSETS_DEBUG)
                CryLog("[Merging] Already removed: {}", relPath);
        }
    }
}

void Assets::AssetMergeExecutor::MergeFiles(const MergeCache& cache)
{
    fs::create_directory(gPreditor->pPaths->GetMergedAssetsPath());

    for (const std::string& relPath : m_FilesToMerge)
    {
        const MergeCache::OutFile& file = cache.files.find(relPath)->second;

        if constexpr (ASSETS_DEBUG)
        {
            CryLog("[Merging] Merging: {} (merger = {})", relPath, file.merger);

            for (const MergeCache::SourceFile& src : file.sourceFiles)
            {
                CryLog("[Merging] - {}:{}", src.source, relPath);
            }
        }

        // Prepare file list
        std::vector<AssetMerger::InputFile> mergeInputFiles;

        for (const MergeCache::SourceFile& src : file.sourceFiles)
        {
            AssetMerger::InputFile inFile;
            inFile.pSource = m_SourceNameMap.find(src.source)->second;
            inFile.fullPath = inFile.pSource->GetRootDirectory() / fs::u8path(relPath);
            mergeInputFiles.emplace_back(std::move(inFile));
        }

        // Run merging
        auto pMerger = m_pSys->CreateMerger(file.merger);
        pMerger->MergeFiles(relPath, mergeInputFiles);
    }
}
