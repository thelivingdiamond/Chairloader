#include <charconv>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/XmlTypeLibrary.h>

namespace
{

class BaseXmlType : public IXmlType
{
public:
    BaseXmlType(std::string_view name)
        : m_Name(name)
    {
    }

    // IXmlType
    virtual const std::string& GetName() const { return m_Name; }
    virtual const std::string& GetFullName() const { return m_Name; }

private:
    std::string m_Name;
};

class AliasXmlType : public BaseXmlType
{
public:
    AliasXmlType(std::string_view name, const IXmlType* pBaseType)
        : BaseXmlType(name)
        , m_pBaseType(pBaseType)
    {
        m_FullName = fmt::format("{} (= {})", name, pBaseType->GetFullName());
    }

    // BaseXmlType
    virtual const std::string& GetFullName() const
    {
        return m_FullName;
    }

    virtual bool ValidateValue(std::string_view value) const
    {
        return m_pBaseType->ValidateValue(value);
    }

private:
    const IXmlType* m_pBaseType = nullptr;
    std::string m_FullName;
};

template <typename T>
class NumericXmlType : public BaseXmlType
{
public:
    NumericXmlType(std::string_view name)
        : BaseXmlType(name)
    {
    }

    // BaseXmlType
    virtual bool ValidateValue(std::string_view value) const
    {
        if (value.empty())
            return false;

        T number{};
        const char* begin = value.data();
        const char* end = value.data() + value.size();

        std::from_chars_result result = std::from_chars(begin, end, number);

        return result.ec == std::errc() && result.ptr == end;
    }
};

class StringXmlType : public BaseXmlType
{
public:
    StringXmlType(std::string_view name)
        : BaseXmlType(name)
    {
    }

    // BaseXmlType
    virtual bool ValidateValue(std::string_view value) const
    {
        return !value.empty();
    }
};

class RegexXmlType : public BaseXmlType
{
public:
    RegexXmlType(std::string_view name, const std::string& regex)
        : BaseXmlType(name)
    {
        m_Regex = std::regex(regex);
    }

    // BaseXmlType
    virtual bool ValidateValue(std::string_view value) const
    {
        if (value.empty())
            return false;

        return std::regex_match(std::string(value), m_Regex);
    }

private:
    std::regex m_Regex;
};

class IntBoolXmlType : public BaseXmlType
{
public:
    IntBoolXmlType(std::string_view name)
        : BaseXmlType(name)
    {
    }

    // BaseXmlType
    virtual bool ValidateValue(std::string_view value) const
    {
        return value == "0" || value == "1";
    }
};

class StringBoolXmlType : public BaseXmlType
{
public:
    StringBoolXmlType(std::string_view name)
        : BaseXmlType(name)
    {
    }

    // BaseXmlType
    virtual bool ValidateValue(std::string_view value) const
    {
        if (value.empty())
            return false;

        return value == "true" || value == "false";
    }
};

class AnyBoolXmlType : public BaseXmlType
{
public:
    AnyBoolXmlType(std::string_view name)
        : BaseXmlType(name)
        , m_IntBool("")
        , m_StringBool("")
    {
    }

    // BaseXmlType
    virtual bool ValidateValue(std::string_view value) const
    {
        return m_IntBool.ValidateValue(value) || m_StringBool.ValidateValue(value);
    }

private:
    IntBoolXmlType m_IntBool;
    StringBoolXmlType m_StringBool;
};

} // namespace

XmlTypeLibrary::XmlTypeLibrary()
{
    // Integers
    RegisterType(std::make_unique<NumericXmlType<int8_t>>("int8"));
    RegisterType(std::make_unique<NumericXmlType<int16_t>>("int16"));
    RegisterType(std::make_unique<NumericXmlType<int32_t>>("int32"));
    RegisterType(std::make_unique<NumericXmlType<int64_t>>("int64"));

    RegisterType(std::make_unique<NumericXmlType<uint8_t>>("uint8"));
    RegisterType(std::make_unique<NumericXmlType<uint16_t>>("uint16"));
    RegisterType(std::make_unique<NumericXmlType<uint32_t>>("uint32"));
    RegisterType(std::make_unique<NumericXmlType<uint64_t>>("uint64"));

    // Other
    RegisterType(std::make_unique<NumericXmlType<double>>("float"));
    RegisterType(std::make_unique<StringXmlType>("string"));
    RegisterType(std::make_unique<IntBoolXmlType>("boolInt"));
    RegisterType(std::make_unique<StringBoolXmlType>("boolString"));
    RegisterType(std::make_unique<AnyBoolXmlType>("bool"));
}

XmlTypeLibrary::~XmlTypeLibrary()
{
}

const IXmlType* XmlTypeLibrary::FindType(std::string_view typeName) const
{
    auto it = m_Types.find(typeName);

    if (it != m_Types.end())
        return it->second.get();
    else
        return nullptr;
}

void XmlTypeLibrary::LoadTypesFromFile(const fs::path& filePath)
{
    auto [doc, errorStack] = XmlUtils::LoadDocumentWithStack(filePath);
    LoadTypesFromXml(doc.first_child(), errorStack);
}

void XmlTypeLibrary::LoadTypesFromXml(const pugi::xml_node& node, const XmlErrorStack& errorStack)
{
    bool foundValueTypes = false;

    for (pugi::xml_node childNode : node)
    {
        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);

        if (XmlUtils::EqualsOnceOrThrow(childErrorStack, childNode, XML_NODE_VALUETYPES, &foundValueTypes))
        {
            LoadXmlValueTypes(childNode, childErrorStack);
        }
    }
}

void XmlTypeLibrary::RegisterType(std::unique_ptr<IXmlType>&& ptr)
{
    auto it = m_Types.find(ptr->GetName());
    if (it != m_Types.end())
        throw std::logic_error(fmt::format("Type {} is already registered", ptr->GetName()));

    m_Types.emplace(ptr->GetName(), std::move(ptr));
}

void XmlTypeLibrary::RegisterAlias(std::string_view newName, std::string_view existingName)
{
    const IXmlType* pExisting = FindType(existingName);

    if (!pExisting)
        throw std::logic_error(fmt::format("Base type {} for alias {} not found", existingName, newName));

    RegisterType(std::make_unique<AliasXmlType>(newName, pExisting));
}

void XmlTypeLibrary::LoadXmlValueTypes(const pugi::xml_node& node, const XmlErrorStack& errorStack)
{
    for (pugi::xml_node childNode : node)
    {
        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);

        std::string name = XmlUtils::GetRequiredAttr(errorStack, childNode, "name").as_string();

        if (!strcmp(childNode.name(), "RegExType"))
        {
            RegisterType(std::make_unique<RegexXmlType>(name, childNode.attribute("regex").as_string()));
        }
        else if (!strcmp(childNode.name(), "AliasType"))
        {
            RegisterAlias(name, childNode.attribute("baseType").as_string());
        }
        else if (!strcmp(childNode.name(), "IDType"))
        {
            std::string baseType = childNode.attribute("baseType").as_string();
            RegisterAlias(name, baseType);
            RegisterAlias(name + "Def", baseType);
        }
        else
        {
            XmlUtils::ThrowUnknownNode(errorStack, childNode);
        }
    }
}
