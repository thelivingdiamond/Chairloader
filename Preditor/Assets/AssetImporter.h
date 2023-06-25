#pragma once
#include "AssetMetadata.h"

namespace Assets
{

//! Base class for asset importers.
//! Asset importer takes an input file from Data directory
//! and creates one or more output files in a temporary directory.
//! The output files will be merged with original files.
class AssetImporter
{
public:
    AssetImporter();
    virtual ~AssetImporter();

    //! Imports the asset.
    void ImportAsset(AssetMetadata& meta);

    //! @returns the list of output files.
    const std::vector<std::string> GetOutputFiles() { return m_OutFiles; }

protected:
    //! @returns the metadata for the asset being imported.
    const AssetMetadata& GetMetadata() { return *m_pMetadata; }

    //! Helper getters.
    //! Paths are lower-case.
    //! @{
    const std::string& GetRelPath() { return m_pMetadata->relativePath; }
    const fs::path& GetSourcePath() { return m_pMetadata->assetPath; }
    const fs::path& GetMetadataPath() { return m_pMetadata->metadataPath; }
    //! @}

    //! Adds a file to the output.
    void AddOutputFile(const std::string relPath);

    //! Actually imports the asset.
    virtual void Import() = 0;

private:
    AssetMetadata* m_pMetadata = nullptr;
    std::vector<std::string> m_OutFiles;
};

} // namespace Assets
