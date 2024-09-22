#include <ChairMerger/LegacyModConverter.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlValidator.h>
#include <ChairMerger/XmlMerger3.h>
#include "MetaAttributes.h"

bool LegacyModConverter::ConvertNode(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();
    bool hasChanges = false;

    hasChanges |= ConvertAttributes(preyNode, legacyModNode, outNode, policy, errorStack);
    hasChanges |= ConvertText(preyNode, legacyModNode, outNode, policy, errorStack);

    switch (collection.type)
    {
    case MergingPolicy3::ECollectionType::None:
    {
        // No children allowed
        bool hasChildren = XmlValidator::NodeHasChildElements(legacyModNode);
        if (hasChildren)
        {
            AddLog(
                severityLevel::error,
                "Collection type is none, node may not have children",
                errorStack);
        }

        break;
    }
    case MergingPolicy3::ECollectionType::ReplaceOnly:
    case MergingPolicy3::ECollectionType::Array:
    {
        // Check if children are different
        if (!XmlUtils::XmlChildrenAreEqual(preyNode, legacyModNode))
        {
            // Replace all children
            hasChanges = true;

            outNode.append_attribute(MetaAttributes::ACTION).set_value("replaceChildren");

            for (pugi::xml_node childNode : legacyModNode)
            {
                outNode.append_copy(childNode);
            }
        }

        break;
    }
    case MergingPolicy3::ECollectionType::Dict:
    {
        hasChanges |= ConvertDict(preyNode, legacyModNode, outNode, policy, errorStack);
        break;
    }
    default:
        throw std::logic_error("Not implemented");
    }

    return hasChanges;
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

    // Convert root node
    return ConvertNode(preyNode, legacyModNode, outNode, policy.GetRootNode(), outErrorStack);
}

void LegacyModConverter::AddLog(severityLevel level, std::string_view message, const XmlErrorStack& errorStack)
{
    m_Logs.push_back(LogEntry {
        level, std::string(message), errorStack.GetStackTrace()
    });
}

bool LegacyModConverter::ConvertAttributes(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    bool hasChanges = false;

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
            hasChanges |= true;
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
        hasChanges |= true;
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

    return hasChanges;
}

bool LegacyModConverter::ConvertText(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    pugi::xml_text preyText = preyNode.text();
    pugi::xml_text legacyModText = legacyModNode.text();

    if (legacyModText.empty() && !preyText.empty())
    {
        // Remove text
        preyText.set("");
        return true;
    }
    else if (
        ( legacyModText.empty() &&  preyText.empty()) ||
        (!legacyModText.empty() && !preyText.empty() && !strcmp(legacyModText.as_string(), preyText.as_string())))
    {
        // Text is equal
        return false;
    }

    // Set text
    if (policy.GetTextType().empty())
    {
        AddLog(
            severityLevel::error,
            "Mod node contains text, which is not allowed",
            errorStack);
    }

    outNode.text().set(legacyModText.as_string());
    return true;
}

bool LegacyModConverter::ConvertDict(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();
    int index = 0;

    auto fnAddKeyAttrs = [&](const pugi::xml_node& sourceNode, pugi::xml_node& destNode)
    {
        for (const std::string& keyAttrName : collection.keyChildAttributes)
        {
            const char* value = sourceNode.attribute(keyAttrName.c_str()).as_string();
            destNode.append_attribute(keyAttrName.c_str()).set_value(value);
        }
    };

    for (const pugi::xml_node legacyModChildNode : legacyModNode.children())
    {
        if (XmlUtils::IsTextNode(legacyModChildNode))
            continue;

        XmlErrorStack legacyModChildErrorStack = errorStack.GetChild(legacyModChildNode);
        legacyModChildErrorStack.SetIndex(index);

        const pugi::xml_node& preyChildNode = XmlMerger3::FindBaseNodeByModKey(preyNode, legacyModChildNode, policy, legacyModChildErrorStack);

        if (preyChildNode)
        {
            // An existing node. Merge it.
            const MergingPolicy3* pChildPolicy = policy.FindChildNode(legacyModChildNode.name());

            if (!pChildPolicy)
                legacyModChildErrorStack.ThrowException(fmt::format("Node '{}' not found in merging policy", legacyModChildNode.name()));

            pugi::xml_node modChildNode = outNode.append_child(legacyModChildNode.name());

            // Add key attributes
            fnAddKeyAttrs(legacyModChildNode, modChildNode);

            bool hasChanges = ConvertNode(preyChildNode, legacyModChildNode, modChildNode, *pChildPolicy, legacyModChildErrorStack);

            if (!hasChanges)
            {
                // No changes. Erase the created node.
                outNode.remove_child(modChildNode);
            }
        }
        else
        {
            // New node
            outNode.append_copy(legacyModChildNode);
        }

        index++;
    }

    // Check for deleted nodes
    index = 0;

    for (const pugi::xml_node preyChildNode : preyNode.children())
    {
        if (XmlUtils::IsTextNode(preyChildNode))
            continue;

        XmlErrorStack preyChildNodeErrorStack = errorStack.GetChild(preyChildNode);
        preyChildNodeErrorStack.SetIndex(index);

        const pugi::xml_node& legacyModChildNode = XmlMerger3::FindBaseNodeByModKey(legacyModNode, preyChildNode, policy, preyChildNodeErrorStack);

        if (!legacyModChildNode)
        {
            // Node was removed in the mod
            pugi::xml_node modChildNode = outNode.append_child(preyChildNode.name());
            fnAddKeyAttrs(preyChildNode, modChildNode);
            modChildNode.append_attribute(MetaAttributes::ACTION).set_value("delete");
        }
    }

    return false;
}
