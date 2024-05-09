#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlMerger3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>

// TODO 2024-05-07: Handle node text value. And validate it, too
// TODO 2024-05-09: Allow unknown attributes - meta-attrbiute on mod node
// TODO 2024-05-09: Allow empty attributes - meta-attrbiute on mod node

void XmlMerger3::MergeDocument(
    const XmlMergerContext& context,
    pugi::xml_document& baseDoc,
    const pugi::xml_document& modDoc,
    const FileMergingPolicy3& policy)
{
    pugi::xml_node baseNode = baseDoc.first_child();
    const pugi::xml_node modNode = modDoc.first_child();

    if (!baseNode)
        throw std::runtime_error("Base document is missing main node");

    if (!modNode)
        throw std::runtime_error("Mod document is missing main node");

    XmlErrorStack modErrorStack(modNode.name());
    MergeNode(context, baseNode, modNode, policy.GetRootNode(), modErrorStack);
}

void XmlMerger3::MergeNode(
    const XmlMergerContext& context,
    pugi::xml_node& baseNode,
    const pugi::xml_node& modNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& modErrorStack)
{
    // TODO 2024-05-05: ch:apply_if must be true or not set

    // TODO 2024-05-05: Other methods
    PatchNode(context, baseNode, modNode, policy, modErrorStack);
}

// Alternatively called Node Emulsification, Unification, or Coalescence

void XmlMerger3::PatchNode(
    const XmlMergerContext& context,
    pugi::xml_node& baseNode,
    const pugi::xml_node& modNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& modErrorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();

    // Merge attributes
    MergeAttributes(context, baseNode, modNode, policy, modErrorStack);

    // Merge children
    switch (collection.type)
    {
    case MergingPolicy3::ECollectionType::None:
    {
        // No children allowed
        bool hasChildren = modNode.children().begin() != modNode.children().end();
        if (hasChildren)
            modErrorStack.ThrowException("This node can't have child nodes since it has no collection defined");
        break;
    }
    case MergingPolicy3::ECollectionType::Dict:
        MergeChildrenDict(context, baseNode, modNode, policy, modErrorStack);
        break;
    default:
        throw std::logic_error("Not implemented");
    }
}

void XmlMerger3::MergeAttributes(
    const XmlMergerContext& context,
    pugi::xml_node& baseNode,
    const pugi::xml_node& modNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& modErrorStack)
{
    for (const pugi::xml_attribute modAttr : modNode.attributes())
    {
        const char* attrName = modAttr.name();
        pugi::xml_attribute baseAttr = baseNode.attribute(attrName);
        const MergingPolicy3::Attribute* pPolicyAttr = policy.FindAttribute(attrName);

        if (!pPolicyAttr)
        {
            // New attribute
            if (!policy.IsAllowingUnknownAttributes())
                modErrorStack.ThrowException(fmt::format("Unknown attribute '{}' in mod node", attrName));
        }
        else if (pPolicyAttr->readOnly)
        {
            // Check value when read-only
            CRY_ASSERT(pPolicyAttr->required);
            if (!baseAttr)
                modErrorStack.ThrowException(fmt::format("Required attribute {} is missing in the base node", attrName));

            if (strcmp(modAttr.as_string(), baseAttr.as_string()))
            {
                modErrorStack.ThrowException(fmt::format(
                    "Read-only attribute {} was changed from '{}' to '{}'",
                    attrName,
                    baseAttr.as_string(),
                    modAttr.as_string()));
            }

            // Attribute is read-only. Value hasn't changed. Skip it.
            continue;
        }
        else
        {
            // Validate value
            std::string attrError = XmlValidator::ValidateAttribute(modAttr, *pPolicyAttr, context.pTypeLib);

            if (!attrError.empty())
                modErrorStack.ThrowException(fmt::format("Attribute {}: {}", attrName, attrError));
        }

        // All checks passed. Update the base attribute
        if (!baseAttr)
            baseAttr = baseNode.append_attribute(attrName);

        baseAttr.set_value(modAttr.as_string());
    }
}

void XmlMerger3::MergeChildrenDict(
    const XmlMergerContext& context,
    pugi::xml_node& baseNode,
    const pugi::xml_node& modNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& modErrorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();
    CRY_ASSERT(collection.type == MergingPolicy3::ECollectionType::Dict);
    CRY_ASSERT(collection.keyChildName || !collection.keyChildAttributes.empty());

    int i = 0;

    for (const pugi::xml_node childModNode : modNode)
    {
        XmlErrorStack childModErrorStack = modErrorStack.GetChild(childModNode);
        childModErrorStack.SetIndex(i);
        childModErrorStack.SetId(collection.GetKeyValuePair(childModNode));

        // TODO 2024-05-05: ch:apply_if

        // Find the policy for the node
        const MergingPolicy3* pChildPolicy = policy.FindChildNode(childModNode.name());
        if (!pChildPolicy)
        {
            childModErrorStack.ThrowException(fmt::format(
                "Node {} can't be a child of {} (merging policy not found)",
                childModNode.name(),
                baseNode.name()));
        }

        // Find the node in base node
        pugi::xml_node childBaseNode = FindBaseNodeByModKey(baseNode, childModNode, policy, childModErrorStack);

        if (childBaseNode)
        {
            // The node exists in base. Merge them.
            MergeNode(context, childBaseNode, childModNode, *pChildPolicy, childModErrorStack);
        }
        else
        {
            // This is a new node. Validate it.
            XmlValidator::Result validationResult = XmlValidator::ValidateNode(childModNode, *pChildPolicy, context.pTypeLib);

            if (!validationResult)
            {
                std::string validationError = validationResult.ToString("  ");
                childModErrorStack.ThrowException("Mod node failed validation when appending a new node\n" + validationError);
            }

            // Node is valid. Append it.
            baseNode.append_copy(childModNode);
        }

        i++;
    }
}

pugi::xml_node XmlMerger3::FindBaseNodeByModKey(
    pugi::xml_node& parentBaseNode,
    const pugi::xml_node& childModNode,
    const MergingPolicy3& parentPolicy,
    const XmlErrorStack& childModErrorStack)
{
    const MergingPolicy3::Collection& collection = parentPolicy.GetCollection();
    CRY_ASSERT(collection.type == MergingPolicy3::ECollectionType::Dict);
    const std::vector<std::string>& keyAttributes = collection.keyChildAttributes;

    // Get the key values
    std::string_view childModNodeName = childModNode.name();
    std::vector<std::string_view> childModKeyValues;
    childModKeyValues.resize(keyAttributes.size());

    for (size_t i = 0; i < childModKeyValues.size(); i++)
    {
        const pugi::xml_attribute modAttr = childModNode.attribute(keyAttributes[i].c_str());

        if (!modAttr)
            childModErrorStack.ThrowException(fmt::format("Key attribute {} is missing", keyAttributes[i]));

        childModKeyValues[i] = modAttr.as_string();
    }

    // Iterate through all base child nodes and find the first one that matches
    for (pugi::xml_node childBaseNode : parentBaseNode.children())
    {
        bool allEqual = true;

        if (collection.keyChildName)
            allEqual &= childModNodeName == childBaseNode.name();

        for (size_t i = 0; i < childModKeyValues.size() && allEqual; i++)
        {
            const pugi::xml_attribute baseAttr = childBaseNode.attribute(keyAttributes[i].c_str());

            if (!baseAttr)
            {
                childModErrorStack.ThrowException(fmt::format(
                    "Key attribute {} is missing ON THE BASE NODE. "
                    "Base XML is invalid. This is not supposed to happen.",
                    keyAttributes[i]));
            }

            allEqual &= childModKeyValues[i] == baseAttr.as_string();
        }

        if (allEqual)
        {
            // Found the node
            return childBaseNode;
        }
    }

    // Not found
    return pugi::xml_node();
}
