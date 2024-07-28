#pragma once
#include <ChairMerger/Export.h>

class XmlErrorStack;

struct CHAIRMERGER_EXPORT IXmlType
{
    virtual ~IXmlType() {}

    //! @returns The type name.
    virtual const std::string& GetName() const = 0;

    //! @returns The type name with additional comments.
    virtual const std::string& GetFullName() const = 0;

    //! Validates a value.
    virtual bool ValidateValue(std::string_view value) const = 0;
};

class CHAIRMERGER_EXPORT XmlTypeLibrary : NoCopy
{
public:
    XmlTypeLibrary();
    ~XmlTypeLibrary();

    //! Finds a type by its name.
    //! @returns Type or nullptr if not found.
    const IXmlType* FindType(std::string_view typeName) const;

    //! Loads additional types from a file.
    //! @{
    void LoadTypesFromFile(const fs::path& filePath);
    void LoadTypesFromXml(const pugi::xml_node& node, const XmlErrorStack& errorStack);
    //! @}

private:
    static constexpr char XML_NODE_VALUETYPES[] = "ValueTypes";

    std::map<std::string, std::unique_ptr<IXmlType>, std::less<>> m_Types;

    //! Registers a new type.
    void RegisterType(std::unique_ptr<IXmlType>&& ptr);

    //! Registers a type alias. Acts like a separate type but actually calls an existing one.
    void RegisterAlias(std::string_view newName, std::string_view existingName);

    void LoadXmlValueTypes(const pugi::xml_node& node, const XmlErrorStack& errorStack);
};
