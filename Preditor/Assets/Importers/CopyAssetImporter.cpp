#include "Importers/CopyAssetImporter.h"

void Assets::CopyAssetImporter::Import()
{
    pugi::xml_node node = GetMetadata().metadataNode.child(XML_NODE);
    std::string ext = node.attribute("newExt").as_string();

    if (ext.empty())
        throw std::runtime_error("No extension set");

    fs::path dstPath = fs::u8path(GetRelPath());
    dstPath.replace_extension(fs::u8path(ext));

    fs::path outFile = gPreditor->pPaths->GetImportedAssetsPath() / dstPath;
    fs::copy(GetSourcePath(), outFile, fs::copy_options::overwrite_existing);

    AddOutputFile(dstPath.u8string());
}
