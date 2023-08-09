#pragma once
#include <Manager/LuaUtils.h>

namespace Manager
{

class NameToIdMap
{
public:
    static constexpr char LIBRARY_FILE_NAME[] = "VariableLibrary.xml";

    static std::map<std::string, uint64_t> Create(const fs::path& libraryPath, const fs::path& preyFiles)
    {
        std::map<std::string, uint64_t> nameToIdMap;
        pugi::xml_document doc;

        doc.load_file(libraryPath.c_str());
        auto rootNode = doc.first_child();

        for (auto& idFile : rootNode) {
            fs::path idFilePath = preyFiles / fs::u8path(idFile.attribute("path").as_string());

            std::string nameAttribute = idFile.attribute("nameAttribute").as_string(),
                idAttribute = idFile.attribute("idAttribute").as_string(),
                xmlPath = idFile.attribute("xmlPath").as_string(),
                variablePath = idFile.attribute("variablePath").as_string();

            pugi::xml_document idFileDoc;
            idFileDoc.load_file(idFilePath.wstring().c_str());

            auto pairs = LoadIdNamePairsFromXml(idFileDoc.root(), xmlPath, nameAttribute, idAttribute);

            for (auto& pair : pairs) {
                std::string validName = LuaUtils::MakeValidVariableName(pair.first);
                auto path = variablePath + "." + validName;
                nameToIdMap[path] = pair.second;
            }
        }

        return nameToIdMap;
    }

private:
    static std::vector<std::pair<std::string, uint64_t>> LoadIdNamePairsFromXml(
        pugi::xml_node node,
        const std::string& xmlPath,
        const std::string& nameAttribute,
        const std::string& idAttribute)
    {
        std::vector<std::pair<std::string, uint64_t>> pairs;
        auto targetChild = node.first_element_by_path(xmlPath.c_str());
        for (auto child : targetChild.children()) {
            auto name = child.attribute(nameAttribute.c_str()).as_string();
            auto id = child.attribute(idAttribute.c_str()).as_ullong();
            pairs.emplace_back(name, id);
        }
        return pairs;
    }
};

} // namespace Manager
