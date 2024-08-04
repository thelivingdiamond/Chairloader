#include <charconv>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlMerger3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>
#include "MetaAttributes.h"

// TODO 2024-05-07: Handle node text value. And validate it, too

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
    MetaAttributes meta;
    meta.ParseNode(modNode, modErrorStack);

    if (!meta.GetApplyNode())
        modErrorStack.ThrowException("Root node may not have ch:apply_if=false");

    if (strcmp(baseNode.name(), modNode.name()))
    {
        modErrorStack.ThrowException(fmt::format("Node name mismatch. Base: '{}'. Mod: '{}'", baseNode.name(), modNode.name()));
    }

    switch (meta.GetAction())
    {
    case MetaAttributes::EAction::Patch:
    case MetaAttributes::EAction::ReplaceChildren:
    {
        PatchNode(context, baseNode, modNode, meta, policy, modErrorStack);
        break;
    }
    case MetaAttributes::EAction::Delete:
    {
        pugi::xml_node baseParentNode = baseNode.parent();
        baseParentNode.remove_child(baseNode);
        baseNode = pugi::xml_node();
        break;
    }
    case MetaAttributes::EAction::Replace:
    {
        // Validate mod node
        ValidateNewNode(context, modNode, policy, modErrorStack);

        // Clear the base node
        baseNode.remove_attributes();
        baseNode.remove_children();

        // Insert attributes from mod node
        for (const pugi::xml_attribute attr : modNode.attributes())
        {
            baseNode.append_attribute(attr.name()).set_value(attr.as_string());
        }

        // Insert children from mod node
        for (const pugi::xml_node node : modNode.children())
        {
            baseNode.append_copy(node);
        }

        break;
    }
    }    
}

// Alternatively called Node Emulsification, Unification, or Coalescence

void XmlMerger3::PatchNode(
    const XmlMergerContext& context,
    pugi::xml_node& baseNode,
    const pugi::xml_node& modNode,
    const MetaAttributes& modNodeMeta,
    const MergingPolicy3& policy,
    const XmlErrorStack& modErrorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();

    // Merge attributes
    MergeAttributes(context, baseNode, modNode, policy, modErrorStack);
    MergeText(context, baseNode, modNode, policy, modErrorStack);

    if (modNodeMeta.GetAction() == MetaAttributes::EAction::ReplaceChildren)
    {
        // Remove children
        baseNode.remove_children();

        // Insert children from mod node
        int i = 0;

        for (const pugi::xml_node childModNode : modNode.children())
        {
            if (childModNode.type() != pugi::node_element)
                continue;

            XmlErrorStack childModErrorStack = modErrorStack.GetChild(childModNode);
            childModErrorStack.SetIndex(i);

            // Find the policy for the node
            const MergingPolicy3* pChildPolicy = policy.FindChildNode(childModNode.name());
            if (!pChildPolicy)
            {
                childModErrorStack.ThrowException(fmt::format(
                    "Node {} can't be a child of {} (merging policy not found)",
                    childModNode.name(),
                    baseNode.name()));
            }

            // Validate the node
            ValidateNewNode(context, childModNode, *pChildPolicy, childModErrorStack);

            // Insert it
            baseNode.append_copy(childModNode);

            i++;
        }
    }
    else
    {
        CRY_ASSERT(modNodeMeta.GetAction() == MetaAttributes::EAction::Patch);

        // Merge children
        switch (collection.type)
        {
        case MergingPolicy3::ECollectionType::None:
        case MergingPolicy3::ECollectionType::ReplaceOnly:
        {
            // No children allowed
            bool hasChildren = XmlValidator::NodeHasChildElements(modNode);
            if (hasChildren)
            {
                if (collection.type == MergingPolicy3::ECollectionType::None)
                {
                    modErrorStack.ThrowException("This node can't have child nodes since it has no collection defined");
                }
                else if (collection.type == MergingPolicy3::ECollectionType::ReplaceOnly)
                {
                    modErrorStack.ThrowException(fmt::format("Set {}=\"replaceChildren\" to replace children but merge attributes", MetaAttributes::ACTION));
                }
            }

            break;
        }
        case MergingPolicy3::ECollectionType::Dict:
            MergeChildrenDict(context, baseNode, modNode, policy, modErrorStack);
            break;
        case MergingPolicy3::ECollectionType::Array:
            MergeChildrenArray(context, baseNode, modNode, policy, modErrorStack);
            break;
        default:
            throw std::logic_error("Not implemented");
        }
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
            if (MetaAttributes::IsKnownMetaAttr(modAttr))
            {
                // Skip meta-attributes
                continue;
            }

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
            XmlValidator::Context valCtx;
            valCtx.nodeType = XmlValidator::ENodeType::MergingBase;
            valCtx.pTypeLib = context.pTypeLib;
            std::string attrError = XmlValidator::ValidateAttribute(valCtx, modAttr, *pPolicyAttr);

            if (!attrError.empty())
                modErrorStack.ThrowException(fmt::format("Attribute {}: {}", attrName, attrError));
        }

        // All checks passed. Update the base attribute
        if (!baseAttr)
            baseAttr = baseNode.append_attribute(attrName);

        baseAttr.set_value(modAttr.as_string());
    }
}

void XmlMerger3::MergeText(
    const XmlMergerContext& context,
    pugi::xml_node& baseNode,
    const pugi::xml_node& modNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& modErrorStack)
{
    const pugi::xml_node modTextNode = FindTextNode(modNode, modErrorStack, true);
    if (!modTextNode)
        return;

    // Validate
    XmlValidator::Context valCtx;
    valCtx.nodeType = XmlValidator::ENodeType::MergingBase;
    valCtx.pTypeLib = context.pTypeLib;
    std::string error = XmlValidator::ValidateTextNode(valCtx, modTextNode, policy);

    if (!error.empty())
        modErrorStack.ThrowException(fmt::format("Text validation failure: {}", error));

    // Apply
    const pugi::xml_node baseTextNode = FindTextNode(baseNode, modErrorStack, false);
    baseTextNode.parent().insert_copy_after(modTextNode, baseTextNode);
    baseTextNode.parent().remove_child(baseTextNode);
    // baseTextNode no longer valid
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

    for (const pugi::xml_node childModNode : modNode.children())
    {
        if (childModNode.type() != pugi::node_element)
            continue;

        XmlErrorStack childModErrorStack = modErrorStack.GetChild(childModNode);
        childModErrorStack.SetIndex(i);
        childModErrorStack.SetId(collection.GetKeyValuePair(childModNode));

        if (!MetaAttributes::CheckApplyIf(childModNode))
        {
            // Skip this node - it's disabled
            continue;
        }

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
            // This is a new node
            pugi::xml_node addedNode = baseNode.append_copy(childModNode);
            MetaAttributes::StripNode(addedNode);
            ValidateNewNode(context, addedNode, *pChildPolicy, childModErrorStack);
        }

        i++;
    }
}

void XmlMerger3::MergeChildrenArray(
    const XmlMergerContext& context,
    pugi::xml_node& baseNode,
    const pugi::xml_node& modNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& modErrorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();
    CRY_ASSERT(collection.type == MergingPolicy3::ECollectionType::Array);
    CRY_ASSERT(!collection.arrayIndexAttr.empty());

    int i = 0;

    PreprocessArrayNode(baseNode, policy, modErrorStack);

    // Merge nodes
    for (const pugi::xml_node childModNode : modNode.children())
    {
        if (childModNode.type() != pugi::node_element)
            continue;

        XmlErrorStack childModErrorStack = modErrorStack.GetChild(childModNode);
        childModErrorStack.SetIndex(i);

        if (!MetaAttributes::CheckApplyIf(childModNode))
        {
            // Skip this node - it's disabled
            continue;
        }

        // Find index attribute
        pugi::xml_attribute childIndexAttr = childModNode.attribute(collection.arrayIndexAttr.c_str());
        if (!childIndexAttr)
        {
            childModErrorStack.ThrowException(fmt::format(
                "Index attribute '{}' is missing for an array element",
                collection.arrayIndexAttr));
        }

        childModErrorStack.SetId("array index", std::string(childIndexAttr.as_string()));

        // Get index value
        ArrayIndex childModNodeIndex;
        if (!TryParseArrayIndex(childIndexAttr, childModNodeIndex))
        {
            childModErrorStack.ThrowException(fmt::format(
                "Index attribute '{}'='{}' is invalid for an array element",
                collection.arrayIndexAttr,
                childIndexAttr.as_string()));
        }

        // Find the policy for the node
        const MergingPolicy3* pChildPolicy = policy.FindChildNode(childModNode.name());
        if (!pChildPolicy)
        {
            childModErrorStack.ThrowException(fmt::format(
                "Node {} can't be a child of {} (merging policy not found)",
                childModNode.name(),
                baseNode.name()));
        }

        // Find a node
        std::string_view childModNodeSource = childModNode.attribute(MetaAttributes::ARRAY_SOURCE).as_string(MetaAttributes::ARRAY_SOURCE_PREY);

        auto [childBaseNode, foundExactBaseNode] = FindBaseNodeByIndex(
            baseNode,
            childModNodeIndex,
            childModNodeSource,
            policy,
            modErrorStack);

        if (foundExactBaseNode)
        {
            // Merge the node
            MergeNode(context, childBaseNode, childModNode, *pChildPolicy, childModErrorStack);
        }
        else
        {
            if (childModNodeSource != MetaAttributes::ARRAY_SOURCE_PREY)
            {
                childModErrorStack.ThrowException(fmt::format(
                    "Base array node {}:{} not found",
                    childModNodeSource,
                    childModNodeIndex));
            }

            pugi::xml_node addedNode;

            if (childBaseNode)
            {
                // Append before the found node
                addedNode = baseNode.insert_copy_before(childModNode, childBaseNode);
            }
            else
            {
                // Append to the end
                addedNode = baseNode.append_copy(childModNode);
            }

            if (context.modName.empty())
                childModErrorStack.ThrowException("Mod name is empty in context (logic error)");

            MetaAttributes::StripNode(addedNode);
            XmlUtils::GetOrAddAttribute(addedNode, MetaAttributes::ARRAY_SOURCE).set_value(context.modName.c_str());
            ValidateNewNode(context, addedNode, *pChildPolicy, childModErrorStack);
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
        if (childBaseNode.type() != pugi::node_element)
            continue;

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

std::pair<pugi::xml_node, bool> XmlMerger3::FindBaseNodeByIndex(
    pugi::xml_node& parentBaseNode,
    ArrayIndex index,
    std::string_view source,
    const MergingPolicy3& parentPolicy,
    const XmlErrorStack& errorStack)
{
    const MergingPolicy3::Collection& collection = parentPolicy.GetCollection();
    CRY_ASSERT(collection.type == MergingPolicy3::ECollectionType::Array);
    CRY_ASSERT(!collection.arrayIndexAttr.empty());

    int i = 0;
    pugi::xml_node resultXmlNode;

    bool exact = false;

    for (const pugi::xml_node childBaseNode : parentBaseNode.children())
    {
        if (childBaseNode.type() != pugi::node_element)
            continue;

        XmlErrorStack childBaseErrorStack = errorStack.GetChild(childBaseNode);
        childBaseErrorStack.SetIndex(i);

        // Find index attribute
        pugi::xml_attribute childIndexAttr = childBaseNode.attribute(collection.arrayIndexAttr.c_str());
        if (!childIndexAttr)
        {
            childBaseErrorStack.ThrowException(fmt::format(
                "Index attribute '{}' is missing for an array element IN THE BASE NODE. "
                "Base XML is invalid. This is not supposed to happen",
                collection.arrayIndexAttr));
        }

        // Get index value
        ArrayIndex childBaseNodeIndex;
        if (!TryParseArrayIndex(childIndexAttr, childBaseNodeIndex))
        {
            childBaseErrorStack.ThrowException(fmt::format(
                "Index attribute '{}'='{}' is invalid for an array element IN THE BASE NODE. "
                "Base XML is invalid. This is not supposed to happen",
                collection.arrayIndexAttr,
                childIndexAttr.as_string()));
        }

        if (index == childBaseNodeIndex)
        {
            // Found exact match by index so check the source
            std::string_view childBaseNodeSource = childBaseNode.attribute(MetaAttributes::ARRAY_SOURCE).as_string(MetaAttributes::ARRAY_SOURCE_PREY);

            if (childBaseNodeSource == source)
            {
                resultXmlNode = childBaseNode;
                exact = true;
                break;
            }

            // Source is different. Next check will return the item to insert before of.
        }

        if (index < childBaseNodeIndex)
        {
            // First node that doesn't satisfy the condition
            resultXmlNode = childBaseNode;
            break;
        }

        i++;
    }

    return std::make_pair(resultXmlNode, exact);
}

pugi::xml_node XmlMerger3::FindTextNode(const pugi::xml_node& parentBaseNode, const XmlErrorStack& errorStack, bool isMod)
{
    pugi::xml_node result;

    for (pugi::xml_node child : parentBaseNode.children())
    {
        if (!XmlUtils::IsTextNode(child))
            continue;

        if (result)
        {
            errorStack.ThrowException(isMod
                ? "Duplicate text node in mod"
                : "Duplicate text node IN THE BASE NODE"
                  "Base XML is invalid. This is not supposed to happen");
        }

        result = child;
    }

    return result;
}

void XmlMerger3::PreprocessArrayNode(
    pugi::xml_node& baseNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& modErrorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();
    CRY_ASSERT(collection.type == MergingPolicy3::ECollectionType::Array);
    CRY_ASSERT(!collection.arrayIndexAttr.empty());

    ArrayIndex prevBaseIdx = std::numeric_limits<ArrayIndex>::min();
    int i = 0;

    for (pugi::xml_node childBaseNode : baseNode.children())
    {
        if (childBaseNode.type() != pugi::node_element)
            continue;

        XmlErrorStack childBaseErrorStack = modErrorStack.GetChild(childBaseNode);
        childBaseErrorStack.SetIndex(i);

        // Find index attribute
        pugi::xml_attribute childIndexAttr = childBaseNode.attribute(collection.arrayIndexAttr.c_str());
        if (!childIndexAttr)
        {
            childBaseErrorStack.ThrowException(fmt::format(
                "Index attribute '{}' is missing for an array element IN THE BASE NODE. "
                "Base XML is invalid. This is not supposed to happen",
                collection.arrayIndexAttr));
        }

        // Get index value
        ArrayIndex childBaseNodeIndex;
        if (!TryParseArrayIndex(childIndexAttr, childBaseNodeIndex))
        {
            childBaseErrorStack.ThrowException(fmt::format(
                "Index attribute '{}'='{}' is invalid for an array element IN THE BASE NODE. "
                "Base XML is invalid. This is not supposed to happen",
                collection.arrayIndexAttr,
                childIndexAttr.as_string()));
        }

        // Validate
        if (!(childBaseNodeIndex > prevBaseIdx))
        {
            childBaseErrorStack.ThrowException(fmt::format(
                "Base node is not sorted. Prev index = {}, current index = {}. "
                "Base XML is invalid. This is not supposed to happen",
                prevBaseIdx, childBaseNodeIndex));
        }

        prevBaseIdx = childBaseNodeIndex;
        i++;
    }
}

void XmlMerger3::ValidateNewNode(
    const XmlMergerContext& context,
    const pugi::xml_node& childModNode,
    const MergingPolicy3& childModPolicy,
    const XmlErrorStack& childModErrorStack)
{
    XmlValidator::Context valCtx;
    valCtx.nodeType = XmlValidator::ENodeType::MergingBase;
    valCtx.pTypeLib = context.pTypeLib;
    XmlValidator::Result validationResult = XmlValidator::ValidateNode(valCtx, childModNode, childModPolicy);

    if (!validationResult)
    {
        std::string validationError = validationResult.ToString("  ");
        childModErrorStack.ThrowException("Mod node failed validation when inserting a new node\n" + validationError);
    }
}

bool XmlMerger3::TryParseArrayIndex(std::string_view str, ArrayIndex& outValue)
{
    outValue = INVALID_INDEX;

    if (str.empty())
        return false;

    const char* begin = str.data();
    const char* end = str.data() + str.size();

    std::from_chars_result result = std::from_chars(begin, end, outValue);

    return result.ec == std::errc() && result.ptr == end;
}
