#include "Merging/MergeCache.h"

Assets::MergeCache::MergeCache()
{
}

Assets::MergeCache::~MergeCache()
{
}

void Assets::MergeCache::LoadXml(const fs::path& xmlPath)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());

    if (!result)
        throw std::runtime_error(result.description());

    // Configs
    for (pugi::xml_node configNode : doc.first_child().child("ModConfigs").children("Config"))
    {
        std::string modName = configNode.attribute("mod").as_string();
        pugi::xml_document configDoc;
        configDoc.append_copy(configNode.first_child());

        bool isInserted = modConfigs.emplace(modName, std::move(configDoc)).second;

        if (!isInserted)
            throw std::runtime_error(fmt::format("Duplicate mod config: {}", modName));
    }

    // Files
    for (pugi::xml_node fileNode : doc.first_child().child("Files").children("OutFile"))
    {
        std::string path = fileNode.attribute("path").as_string();
        OutFile file;
        file.merger = fileNode.attribute("merger").as_string();

        for (pugi::xml_node sourceFileNode : fileNode.children("SourceFile"))
        {
            SourceFile sourceFile;
            sourceFile.source = sourceFileNode.attribute("source").as_string();
            sourceFile.modTime = FileModTime(sourceFileNode.attribute("modTime").as_llong());
            sourceFile.metaModTime = FileModTime(sourceFileNode.attribute("metaModTime").as_llong());
            file.sourceFiles.push_back(std::move(sourceFile));
        }

        bool isInserted = files.emplace(path, std::move(file)).second;

        if (!isInserted)
            throw std::runtime_error(fmt::format("Duplicate path: {}", path));
    }
}

void Assets::MergeCache::SaveXml(const fs::path& xmlPath) const
{
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("MergeCache");

    // Configs
    pugi::xml_node modConfigsNode = root.append_child("ModConfigs");
    for (const auto& [modName, configDoc] : modConfigs)
    {
        pugi::xml_node configNode = modConfigsNode.append_child("Config");
        configNode.append_attribute("mod").set_value(modName.c_str());
        configNode.append_copy(configDoc.first_child());
    }

    // Files
    pugi::xml_node filesNode = root.append_child("Files");
    for (const auto& [path, file] : files)
    {
        pugi::xml_node fileNode = filesNode.append_child("OutFile");
        fileNode.append_attribute("path").set_value(path.c_str());
        fileNode.append_attribute("merger").set_value(file.merger.c_str());

        for (const SourceFile& sourceFile : file.sourceFiles)
        {
            pugi::xml_node sourceFileNode = fileNode.append_child("SourceFile");
            sourceFileNode.append_attribute("source").set_value(sourceFile.source.c_str());
            sourceFileNode.append_attribute("modTime").set_value(sourceFile.modTime.count());
            sourceFileNode.append_attribute("metaModTime").set_value(sourceFile.metaModTime.count());
        }
    }

    if (!doc.save_file(xmlPath.c_str()))
        throw std::runtime_error("Failed to save MergeCache");
}
