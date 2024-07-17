#pragma once

//! Diagnostic message storage for XML parsing.
//! Includes the stack trace of XML nodes.
class XmlErrorStack
{
public:
    XmlErrorStack(const std::string& rootNodeName)
    {
        m_NodeName = rootNodeName;
    }

    XmlErrorStack(const char* rootNodeName)
        : XmlErrorStack(std::string(rootNodeName)) {}

    XmlErrorStack(const fs::path& filePath)
        : XmlErrorStack(fmt::format("file {}", filePath.u8string())) {}

    XmlErrorStack(const std::string& rootNodeName, const fs::path& filePath)
        : XmlErrorStack(fmt::format("{} in {}", rootNodeName, filePath.u8string())) {}

    //! @returns Whether this is the root node in the stack.
    bool IsRoot() const { return m_pParent == nullptr; }

    //! Creates a child stack entry.
    //! @{
    XmlErrorStack GetChild(std::string&& nodeName) const
    {
        CRY_ASSERT(!nodeName.empty());
        XmlErrorStack child(this);
        child.m_NodeName = nodeName;
        return child;
    }

    XmlErrorStack GetChild(const pugi::xml_node& childNode) const
    {
        return GetChild(childNode.name());
    }
    //! @}

    //! Sets the node ID.
    //! @{
    void SetId(std::string&& key, std::string&& value)
    {
        m_IdKey = std::move(key);
        m_IdValue = std::move(value);
    }

    void SetId(std::string&& key, std::string_view value)
    {
        m_IdKey = std::move(key);
        m_IdValue = value;
    }

    void SetId(std::pair<std::string, std::string>&& kvPair)
    {
        SetId(std::move(kvPair.first), std::move(kvPair.second));
    }
    //! @}

    //! Sets the node ID.
    void SetIndex(int index)
    {
        m_Index = index;
    }

    //! @returns The message for this stack element.
    std::string GetStackFrame() const;

    //! @returns The stack trace as an array. First element is the current elem, last is the root.
    std::vector<std::string> GetStackTrace() const;

    //! @returns The stack trace in multiple lines. Will have line break at the end.
    std::string GetStackTraceMultiline(std::string_view prefix = "  at ") const;

    //! Throws an exception with the specified message.
    //! Exception will have the full stack trace.
    [[noreturn]] void ThrowException(std::string_view msg) const;

private:
    const XmlErrorStack* m_pParent = nullptr;
    std::string m_NodeName;
    std::string m_IdKey;
    std::string m_IdValue;
    int m_Index = -1;

    XmlErrorStack(const XmlErrorStack* pParent)
    {
        m_pParent = pParent;
    }
};

class XmlUtils
{
public:
    //! Loads an XML document from file. Throws on error.
    //! @param  path            Path to the file.
    //! @param  parseOptions    Options to load_file.
    //! @{
    static pugi::xml_document LoadDocument(const fs::path& path, unsigned parseOptions = pugi::parse_default);
    static std::tuple<pugi::xml_document, XmlErrorStack> LoadDocumentWithStack(const fs::path& path, unsigned parseOptions = pugi::parse_default);
    //! @}

    //! Gets a named node from the parent. If not found, throws an exception.
    static pugi::xml_node GetRequiredNode(const XmlErrorStack& errorStack, const pugi::xml_node& parent, const char* name);

    //! Gets an attribute from the node. If not found, throws an exception.
    static pugi::xml_attribute GetRequiredAttr(const XmlErrorStack& errorStack, const pugi::xml_node& node, const char* name);

    //! Compares node name to param name. If they are equal, sets pFound to true and returns true. If pFound already was true, throws.
    //! @returns True if name matches and pFound was false.
    static bool EqualsOnceOrThrow(const XmlErrorStack& errorStack, const pugi::xml_node& node, const char* name, bool* pFound);

    //! Throws an exception with unknown node message.
    [[noreturn]] static void ThrowUnknownNode(const XmlErrorStack& errorStack, const pugi::xml_node& node);

    //! Throws an exception with required node not found message.
    [[noreturn]] static void ThrowMissingNode(const XmlErrorStack& errorStack, std::string_view name);
    static void ThrowMissingNodeIfFalse(const XmlErrorStack& errorStack, std::string_view name, bool isFound)
    {
        if (!isFound)
            ThrowMissingNode(errorStack, name);
    }

    //! Checks if the node is a text node.
    static bool IsTextNode(const pugi::xml_node& node)
    {
        return node.type() == pugi::node_pcdata || node.type() == pugi::node_cdata;
    }

    //! Finds an attribute in the node. If it doesn't exist, appends it.
    //! @returns The attribute.
    static pugi::xml_attribute GetOrAddAttribute(pugi::xml_node node, const char* name);
};
