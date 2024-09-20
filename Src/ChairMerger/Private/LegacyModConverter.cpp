#include <ChairMerger/LegacyModConverter.h>
#include <ChairMerger/MergingPolicy3.h>
#include "MetaAttributes.h"

void LegacyModConverter::ConvertNode(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
}

bool LegacyModConverter::ConvertDocument(
    const pugi::xml_document& preyDoc,
    const pugi::xml_document& legacyModDoc,
    pugi::xml_document& outDoc,
    const FileMergingPolicy3& policy)
{
    if (policy.GetMethod() == FileMergingPolicy3::EMethod::ReadOnly)
        throw std::logic_error("This file can't be merged");

    if (policy.GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
        throw std::logic_error("Excel files must use a different method");

    if (policy.GetMethod() == FileMergingPolicy3::EMethod::Replace)
    {
        // Replace the entire file
        if (XmlUtils::XmlNodesAreEqual(preyDoc, legacyModDoc))
            return false;

        outDoc.reset(preyDoc);
        return true;
    }

    CRY_ASSERT(policy.GetMethod() == FileMergingPolicy3::EMethod::Merge);

    outDoc.reset();
    pugi::xml_node preyNode = preyDoc.first_child();
    pugi::xml_node legacyModNode = legacyModDoc.first_child();
    pugi::xml_node outNode = outDoc.append_child(preyNode.name());
    XmlErrorStack outErrorStack(preyNode.name());

    // Add xmlns attributes
    constexpr const char* XMLNS_ATTRS[] = {
        "xmlns",
        "xmlns:ch",
        "xmlns:xsi",
        "xsi:schemaLocation",
    };

    for (const char* attrName : XMLNS_ATTRS)
    {
        if (pugi::xml_attribute attr = preyNode.attribute(attrName))
            outNode.append_attribute(attr.name()).set_value(attr.as_string());
    }

    // Convert root node attributes
    ConvertAttributes(preyNode, legacyModNode, outNode, policy.GetRootNode(), outErrorStack);
}

void LegacyModConverter::AddLog(severityLevel level, std::string_view message, const XmlErrorStack& errorStack)
{
    m_Logs.push_back(LogEntry {
        level, std::string(message), errorStack.GetStackTrace()
    });
}

void LegacyModConverter::ConvertAttributes(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    auto fnConvertAttribute = [&](const char* name, const MergingPolicy3::Attribute* pAttrPolicy)
    {
        const pugi::xml_attribute preyAttr = preyNode.attribute(name);
        const pugi::xml_attribute legacyModAttr = legacyModNode.attribute(name);

        if (!preyAttr && !legacyModAttr)
        {
            // Attribute doesn't exist. Ignore it.
            return;
        }

        if (preyAttr && !legacyModAttr)
        {
            // Mod removed the attribute
            if (pAttrPolicy && !pAttrPolicy->allowEmpty)
            {
                AddLog(
                    severityLevel::warning,
                    fmt::format("Mod has removed the attribute '{}'. This attribute can't be empty. It is left as-is.", name),
                    errorStack);
                return;
            }
                
            AddLog(
                severityLevel::warning,
                fmt::format("Mod has removed the attribute '{}'. This attribute will be set to an empty string.", name),
                errorStack);

            outNode.append_attribute(name).set_value("");
            return;
        }

        if (preyAttr && legacyModAttr)
        {
            // Both attributes exist. Check if they are different
            if (!strcmp(preyAttr.as_string(), legacyModAttr.as_string()))
                return;
        }

        // Add the attribute
        outNode.append_attribute(name).set_value(legacyModAttr.as_string());
    };

    // Convert known attributes first
    for (const MergingPolicy3::Attribute& attr : policy.GetAttributes())
    {
        fnConvertAttribute(attr.name.c_str(), &attr);
    }

    // Convert unknown attributes
    for (pugi::xml_attribute attr : legacyModNode.attributes())
    {
        // Skip meta attributes
        if (MetaAttributes::IsKnownMetaAttr(attr))
            continue;

        auto it = std::find_if(policy.GetAttributes().begin(), policy.GetAttributes().end(), [&](auto& x) { return x.name == attr.name(); });

        if (it == policy.GetAttributes().end())
        {
            // Unknown attribute
            if (!policy.IsAllowingUnknownAttributes())
            {
                AddLog(
                    severityLevel::error,
                    fmt::format("Mod contains unknown attribute '{}'", attr.name()),
                    errorStack);
            }

            fnConvertAttribute(attr.name(), nullptr);
        }
    }
}
