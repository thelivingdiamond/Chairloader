#include "AssetMetadata.h"

void Assets::AssetMetadata::Init(const std::string& relPath, const fs::path& metaPath)
{
    relativePath = relPath;
    assetPath = gPreditor->pPaths->GetAssetPath() / fs::u8path(relPath);

    if (!metaPath.empty())
        metadataPath = metaPath;
    else
        metadataPath = assetPath.parent_path() / fs::u8path(assetPath.filename().u8string() + "." + ASSET_META_EXT);

    if (fs::exists(metadataPath))
    {
        metadataModTime = fs::last_write_time(metadataPath).time_since_epoch();
        pugi::xml_parse_result result = m_Doc.load_file(metadataPath.c_str());

        if (!result)
            throw std::runtime_error(result.description());

        metadataNode = m_Doc.child(METADATA_NODE_NAME);

        if (!metadataNode)
            metadataNode = m_Doc.append_child(METADATA_NODE_NAME);

        skipMerge = metadataNode.attribute("skipMerge").as_bool();
        importerName = metadataNode.attribute("importerName").as_string();
    }
}

void Assets::AssetMetadata::Save()
{
    EnsureAttr("skipMerge").set_value(skipMerge);
    EnsureAttr("importerName").set_value(importerName.c_str());

    if (!m_Doc.save_file(metadataPath.c_str()))
        throw std::runtime_error("Failed to save " + metadataPath.u8string());
}

pugi::xml_attribute Assets::AssetMetadata::EnsureAttr(const char* attrName)
{
    pugi::xml_attribute attr = metadataNode.attribute(attrName);

    if (!attr)
        attr = metadataNode.append_attribute(attrName);

    return attr;
}
