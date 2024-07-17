#include <Chairloader/Private/XmlUtils.h>

//---------------------------------------------------------------------------------
// XmlErrorStack
//---------------------------------------------------------------------------------
std::string XmlErrorStack::GetStackFrame() const
{
    CRY_ASSERT(!m_NodeName.empty());

    std::string s = m_NodeName;

    if (m_Index != -1)
        s += fmt::format("[{}]", m_Index);

    if (!m_IdKey.empty())
        s += fmt::format(" [{} = {}]", m_IdKey, m_IdValue);

    return s;
}

std::vector<std::string> XmlErrorStack::GetStackTrace() const
{
    std::vector<std::string> vec;

    for (const XmlErrorStack* pFrame = this; pFrame; pFrame = pFrame->m_pParent)
    {
        vec.push_back(pFrame->GetStackFrame());
    }

    return vec;
}

std::string XmlErrorStack::GetStackTraceMultiline(std::string_view prefix) const
{
    std::string ret;

    for (const XmlErrorStack* pFrame = this; pFrame; pFrame = pFrame->m_pParent)
    {
        ret += prefix;
        ret += pFrame->GetStackFrame();
        ret += '\n';
    }

    return ret;
}

void XmlErrorStack::ThrowException(std::string_view msg) const
{
    throw std::runtime_error(fmt::format("{}\n{}", msg, GetStackTraceMultiline()));
}

//---------------------------------------------------------------------------------
// XmlUtils
//---------------------------------------------------------------------------------
pugi::xml_document XmlUtils::LoadDocument(const fs::path& path, unsigned parseOptions)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(path.c_str(), parseOptions);

    if (!result)
    {
        throw std::runtime_error(fmt::format(
            "Failed to read XML document.\n"
            "Path: {}\n"
            "Offset: {}\n"
            "{}",
            path.u8string(), result.offset, result.description()
        ));
    }

    return doc;
}

std::tuple<pugi::xml_document, XmlErrorStack> XmlUtils::LoadDocumentWithStack(const fs::path& path, unsigned parseOptions)
{
    pugi::xml_document doc = LoadDocument(path, parseOptions);
    XmlErrorStack errorStack(path);
    return std::make_tuple(std::move(doc), std::move(errorStack));
}

pugi::xml_node XmlUtils::GetRequiredNode(const XmlErrorStack& errorStack, const pugi::xml_node& parent, const char* name)
{
    pugi::xml_node node = parent.child(name);

    if (!node)
        errorStack.ThrowException(fmt::format("Required node '{}' not found", name));

    return node;
}

pugi::xml_attribute XmlUtils::GetRequiredAttr(const XmlErrorStack& errorStack, const pugi::xml_node& node, const char* name)
{
    pugi::xml_attribute attr = node.attribute(name);

    if (!attr)
        errorStack.ThrowException(fmt::format("Required attribute '{}' is not set", name));

    return attr;
}

bool XmlUtils::EqualsOnceOrThrow(const XmlErrorStack& errorStack, const pugi::xml_node& node, const char* name, bool* pFound)
{
    if (strcmp(node.name(), name))
    {
        // Different names
        return false;
    }

    if (*pFound)
        errorStack.ThrowException(fmt::format("Duplicate node '{}'", name));

    *pFound = true;
    return true;
}

void XmlUtils::ThrowUnknownNode(const XmlErrorStack& errorStack, const pugi::xml_node& node)
{
    errorStack.ThrowException(fmt::format("Unknown node '{}'", node.name()));
}

void XmlUtils::ThrowMissingNode(const XmlErrorStack& errorStack, std::string_view name)
{
    errorStack.ThrowException(fmt::format("Required node '{}' not found", name));
}

pugi::xml_attribute XmlUtils::GetOrAddAttribute(pugi::xml_node node, const char* name)
{
    pugi::xml_attribute attr = node.attribute(name);

    if (!attr)
        attr = node.append_attribute(name);

    return attr;
}
