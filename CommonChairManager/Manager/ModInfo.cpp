#include <fmt/format.h>
#include <Manager/ModInfo.h>

constexpr char DEPS_NODE_NAME[] = "Dependencies";
constexpr char DEP_NODE_NAME[] = "Mod";

void Manager::ModInfo::LoadXml(pugi::xml_node node)
{
    deps.clear();

    modName = node.attribute("modName").as_string();
    displayName = node.attribute("displayName").as_string();
    version = node.attribute("version").as_string();
    author = node.attribute("author").as_string();
    dllName = node.attribute("dllName").as_string();
    hasXML = node.attribute("hasXML").as_bool();
    hasLevelXML = node.attribute("hasLevelXML").as_bool();

    for (pugi::xml_node dep : node.child(DEPS_NODE_NAME)) {
        deps.emplace_back(dep.text().get());
    }
}

void Manager::ModInfo::LoadFile(const fs::path& path)
{
    pugi::xml_document doc;
    pugi::xml_parse_result status = doc.load_file(path.c_str());

    if (!status)
    {
        throw std::runtime_error(fmt::format("Failed to parse {}: {}. Offset: {}",
            XML_FILE_NAME, status.description(), status.offset));
    }

    pugi::xml_node node = doc.child(XML_NODE_NAME);

    if (!node)
    {
        throw std::runtime_error(fmt::format("Failed to parse {}: {} node not found",
            XML_FILE_NAME, XML_NODE_NAME));
    }

    LoadXml(node);
}

void Manager::ModInfo::SaveXml(pugi::xml_node node)
{
    node.remove_attributes();
    node.append_attribute("modName").set_value(modName.c_str());
    node.append_attribute("displayName").set_value(displayName.c_str());
    node.append_attribute("version").set_value(version.c_str());
    node.append_attribute("author").set_value(author.c_str());
    node.append_attribute("dllName").set_value(dllName.c_str());
    node.append_attribute("hasXML").set_value(hasXML);
    node.append_attribute("hasLevelXML").set_value(hasLevelXML);

    if (!deps.empty())
    {
        pugi::xml_node depsNode = node.child(DEPS_NODE_NAME);
        if (!depsNode)
            depsNode = node.append_child(DEPS_NODE_NAME);
        else
            depsNode.remove_children();

        for (const std::string& i : deps)
        {
            pugi::xml_node depNode = depsNode.append_child(DEP_NODE_NAME);
            depNode.text().set(i.c_str());
        }
    }
    else
    {
        node.remove_child(DEPS_NODE_NAME);
    }
}

bool Manager::ModInfo::ValidateModName(std::string_view name, std::string* errorText)
{
    for (char c : name)
    {
        bool validChar = (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') ||
            c == '.' || c == '_' || c == '-';

        if (!validChar)
        {
            if (errorText)
                *errorText = "Illegal character in name";

            return false;
        }
    }

    return true;
}
