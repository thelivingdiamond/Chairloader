#pragma once

constexpr char CHAIR_XSD_URL[] = "https://thelivingdiamond.github.io/Chairloader/Xsd";
constexpr char CHAIR_XML_NS_CHAIRLOADER[] = "https://thelivingdiamond.github.io/Chairloader/Xsd/Chairloader";
constexpr char CHAIR_XML_NS_PREY[] = "https://thelivingdiamond.github.io/Chairloader/Xsd/Prey";
constexpr char CHAIR_XSD_META_TYPE[] = "MetaType.xsd";
constexpr char CHAIR_XSD_META_ATTRIBUTES[] = "MetaAttributes.xsd";

inline std::string CreateXsdPath(const fs::path& xsdRefPath, std::string_view subPath)
{
    if (!xsdRefPath.empty())
        return (xsdRefPath / subPath).generic_u8string();
    else
        return fmt::format("{}/{}", CHAIR_XSD_URL, subPath);
}
