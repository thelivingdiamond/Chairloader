#pragma once

namespace Manager
{

//! ModInfo.xml file structure.
struct ModInfo
{
    static constexpr char XML_FILE_NAME[] = "ModInfo.xml";
    static constexpr char XML_NODE_NAME[] = "Mod";

    // ModInfo.xml
    std::string modName;
    std::string displayName;
    std::string version;
    std::string author;
    std::string dllName;
    bool hasXML = false;
    bool hasLevelXML = false;
    bool enableShaderCompiler = false;

    //! List of dependencies (mod names).
    std::vector<std::string> deps;

    //! Loads from an XML node.
    void LoadXml(pugi::xml_node node);

    //! Loads from an XML file.
    void LoadFile(const fs::path& path);

    //! Saves into an XML.
    //! @param  node    Node to save into (not the parent!).
    void SaveXml(pugi::xml_node node);

    //! Checks if mod name is valid.
    static bool ValidateModName(std::string_view name, std::string* errorText = nullptr);
};

} // namespace Manager
