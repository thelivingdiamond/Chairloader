#pragma once
#include <Preditor/Assets/Common.h>
#include "AssetsCommon.h"

namespace Assets
{

class AssetMetadata
{
public:
    static constexpr char METADATA_NODE_NAME[] = "Metadata";

    //! Asset relative path.
    std::string relativePath;

    //! Path to the asset file.
    fs::path assetPath;

    //! Path to the metadata file.
    fs::path metadataPath;

    //! Time the metadata file was modified on disk.
    FileModTime metadataModTime = FileModTime();

    //! The root metadata XML node.
    pugi::xml_node metadataNode;

    //! Whether the asset doesn't need to be merged.
    bool skipMerge = false;

    //! If this file is being imported, whether to merge the source, too.
    bool mergeSourceFile = false;

    //! Asset importer name.
    std::string importerName;

    //! Loads (if exists) a metadata file for the asset.
    void Init(const std::string& relPath, const fs::path& metaPath = fs::path());

    //! Saves the file.
    void Save();

private:
    pugi::xml_document m_Doc;

    pugi::xml_attribute EnsureAttr(const char* attrName);
};

} // namespace Assets
