#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string.hpp>
#include <Chairloader/Private/StringUtils.h>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>
#include "MetaAttributes.h"

XmlValidator::Result XmlValidator::ValidateDocument(
    const Context& context,
    const pugi::xml_document& doc,
    const FileMergingPolicy3& policy)
{
    Result result;
    const pugi::xml_node rootNode = doc.first_child();
    XmlErrorStack errorStack(rootNode.name());

    if (policy.GetMethod() == FileMergingPolicy3::EMethod::Localization)
        throw std::logic_error("Localization files can't be validated");

    if (rootNode.name() != policy.GetRootNodeName())
    {
        AddError(result, errorStack, fmt::format(
            "Root node name mismatch (expected: '{}', actual: '{}')",
            policy.GetRootNodeName(), rootNode.name()));
    }

    ValidateNodeInternal(context, rootNode, policy.GetRootNode(), errorStack, result, true);
    return result;
}

XmlValidator::Result XmlValidator::ValidateNode(
    const Context& context,
    const pugi::xml_node& node,
    const MergingPolicy3& policy,
    bool recurse)
{
    Result result;
    XmlErrorStack errorStack(node.name());
    ValidateNodeInternal(context, node, policy, errorStack, result, recurse);
    return result;
}

std::string XmlValidator::ValidateAttribute(
    const Context& context,
    const pugi::xml_attribute& nodeAttr,
    const MergingPolicy3::Attribute& policyAttr)
{
    if (context.mode == EMode::Prey && policyAttr.generated)
        return "Generated attributes are not allowed";

    if (nodeAttr.as_string()[0] == '\0')
    {
        // Attribute is empty
        if (!policyAttr.allowEmpty)
            return "Attribute can't be empty";
    }
    else if (context.pTypeLib)
    {
        const IXmlValueType* pType = context.pTypeLib->FindValueType(policyAttr.type);
        if (!pType)
            throw std::runtime_error(fmt::format("Unknown type {} in the merging policy", policyAttr.type));

        std::string_view value = nodeAttr.as_string();

        // Finalizer expressions can't be validated at this point
        // TODO 2024-08-06: At least validate syntax with a regex
        if (context.mode == EMode::Prey || !boost::starts_with(value, "$("))
        {
            bool isValid = pType->ValidateValue(value);
            if (!isValid)
                return fmt::format("Invalid value '{}' for type {}", value, pType->GetFullName());
        }
    }

    return std::string();
}

std::string XmlValidator::ValidateTextNode(
    const Context& context,
    const pugi::xml_node& node,
    const MergingPolicy3& policy)
{
    CRY_ASSERT(XmlUtils::IsTextNode(node));

    if (policy.GetTextType().empty())
        return "Plain-text is not allowed in this node";

    std::string_view value = TrimStringView(node.value());

    if (!policy.IsEmptyTextAllowed() && value.empty())
        return "Plain-text can't be empty";

    if (context.pTypeLib)
    {
        const IXmlValueType* pType = context.pTypeLib->FindValueType(policy.GetTextType());
        if (!pType)
            throw std::runtime_error(fmt::format("Unknown type {} in the merging policy", policy.GetTextType()));

        bool isValid = pType->ValidateValue(value);
        if (!isValid)
            return fmt::format("Invalid value '{}' for type {}", value, pType->GetFullName());
    }

    return std::string();
}

bool XmlValidator::NodeHasChildElements(const pugi::xml_node& node)
{
    for (const pugi::xml_node childNode : node.children())
    {
        if (!XmlUtils::IsTextNode(childNode))
            return true;
    }

    return false;
}

void XmlValidator::ValidateNodeInternal(
    const Context& context,
    const pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack,
    Result& result,
    bool recurse)
{
    ValidateAttributes(context, node, policy, errorStack, result);
    ValidateText(context, node, policy, errorStack, result);
    ValidateCollection(context, node, policy, errorStack, result);
    ValidateConstraints(node, policy, errorStack, result);

    if (recurse)
    {
        int i = 0;

        for (const pugi::xml_node childNode : node.children())
        {
            if (childNode.type() != pugi::node_element)
                continue;

            XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
            childErrorStack.SetIndex(i);

            // Add key if available
            if (policy.GetCollection().type == MergingPolicy3::ECollectionType::Dict)
            {
                childErrorStack.SetId(policy.GetCollection().GetKeyValuePair(childNode));
            }

            const MergingPolicy3* childPolicy = policy.FindChildNode(childNode.name());

            if (childPolicy)
            {
                ValidateNodeInternal(context, childNode, *childPolicy, childErrorStack, result, true);
            }
            else
            {
                AddError(result, childErrorStack, "Unknown node");
            }

            i++;
        }
    }
}

void XmlValidator::ValidateAttributes(
    const Context& context,
    const pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack,
    Result& result)
{
    // Check existing attributes
    for (const pugi::xml_attribute nodeAttr : node.attributes())
    {
        const MergingPolicy3::Attribute* policyAttr = policy.FindAttribute(nodeAttr.name());

        if (!policyAttr)
        {
            bool allowAttr = false;
            allowAttr |= policy.IsAllowingUnknownAttributes();
            allowAttr |= (context.mode == EMode::MergingBase || context.mode == EMode::Mod)
                && MetaAttributes::IsKnownMetaAttr(nodeAttr);

            if (!allowAttr)
                AddError(result, errorStack, "Unknown attribute", nodeAttr.name());

            continue;
        }

        std::string attrError = ValidateAttribute(context, nodeAttr, *policyAttr);

        if (!attrError.empty())
            AddError(result, errorStack, attrError, nodeAttr.name());
    }

    if (context.mode == EMode::Prey || context.mode == EMode::MergingBase)
    {
        // Check if any required attributes are missing
        for (const MergingPolicy3::Attribute& policyAttr : policy.GetAttributes())
        {
            if (!policyAttr.generated && policyAttr.required && !node.attribute(policyAttr.name.c_str()))
                AddError(result, errorStack, "Required attribute is missing", policyAttr.name);
        }
    }

    if (context.mode == EMode::Mod)
    {
        // Check meta-attributes
        std::map<std::string, std::string> metaResults = MetaAttributes::ValidateNode(node);

        for (const auto& [attr, error] : metaResults)
        {
            AddError(result, errorStack, error, attr);
        }
    }
}

void XmlValidator::ValidateText(
    const Context& context,
    const pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack,
    Result& result)
{
    pugi::xml_node textNode;

    for (const pugi::xml_node childNode : node.children())
    {
        if (XmlUtils::IsTextNode(childNode))
        {
            if (textNode)
                errorStack.ThrowException("Duplicate plain-text node");

            textNode = childNode;

            if (policy.GetTextType().empty())
                errorStack.ThrowException("Plain-text is not allowed in this node");

            std::string error = ValidateTextNode(context, childNode, policy);

            if (!error.empty())
                AddError(result, errorStack, error);
        }
        else if (childNode.type() != pugi::node_element)
        {
            errorStack.ThrowException(fmt::format("Unexpected node type {}", (int)childNode.type()));
        }
    }

    if (!policy.GetTextType().empty() && !policy.IsEmptyTextAllowed() && (!textNode || textNode.value()[0] == '\0'))
    {
        errorStack.ThrowException("Plain-text can't be empty");
    }
}

void XmlValidator::ValidateCollection(
    const Context& context,
    const pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack,
    Result& result)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();

    switch (collection.type)
    {
    case MergingPolicy3::ECollectionType::None:
    {
        // There must be no children
        bool hasChildren = NodeHasChildElements(node);
        if (hasChildren)
            AddError(result, errorStack, "Collection type is not defined. Node must not have any children in that case.");
        break;
    }
    case MergingPolicy3::ECollectionType::Dict:
    {
        // Validate that primary key is present on all children
        // And it's unique
        std::set<std::vector<std::string>> uniqueKeys;
        int i = 0;

        for (const pugi::xml_node childNode : node.children())
        {
            if (childNode.type() != pugi::node_element)
                continue;

            XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
            childErrorStack.SetIndex(i);

            std::vector<std::string> fullKey; // All key values for this node
            fullKey.resize(collection.keyChildAttributes.size() + (collection.keyChildName ? 1 : 0));
            size_t curKeyIdx = 0; // Index of the next key to be filled

            if (collection.keyChildName)
            {
                // Add child name to the key
                fullKey[curKeyIdx] = childNode.name();
                curKeyIdx++;
            }

            for (const std::string& keyAttrName : collection.keyChildAttributes)
            {
                const pugi::xml_attribute keyAttr = childNode.attribute(keyAttrName.c_str());

                if (!keyAttr)
                {
                    if (context.mode != EMode::Prey)
                        AddError(result, childErrorStack, "Key attribute is missing", keyAttrName);
                }
                else
                {
                    fullKey[curKeyIdx] = keyAttr.as_string();
                    curKeyIdx++;
                }
            }

            if (curKeyIdx == fullKey.size())
            {
                // All keys were added.
                // curKeyIdx will be less than size if one of the attributes is missing, which has its own error
                auto it = uniqueKeys.find(fullKey);

                if (it == uniqueKeys.end())
                {
                    // Add the key
                    uniqueKeys.emplace(std::move(fullKey));
                }
                else
                {
                    // Duplicate key
                    std::string fullKeyString = boost::algorithm::join(fullKey, ", ");

                    AddError(
                        result,
                        childErrorStack,
                        fmt::format("Duplicate key value '{}'", fullKeyString));
                }
            }

            i++;
        }

        break;
    }
    case MergingPolicy3::ECollectionType::Array:
    {
        // Check that index attribute exists in all children
        int i = 0;

        for (pugi::xml_node childNode : node.children())
        {
            if (childNode.type() != pugi::node_element)
                continue;

            XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
            childErrorStack.SetIndex(i);

            pugi::xml_attribute indexAttr = childNode.attribute(collection.arrayIndexAttr.c_str());
            if (!indexAttr && context.mode != EMode::Prey)
                AddError(result, childErrorStack, "Index attribute is missing for an array element");

            i++;
        }

        break;
    }
    case MergingPolicy3::ECollectionType::ReplaceOnly:
    {
        // No special checks
        break;
    }
    default:
        throw std::logic_error("Unknown collection type");
    }
}

void XmlValidator::ValidateConstraints(const pugi::xml_node& node, const MergingPolicy3& policy, const XmlErrorStack& errorStack, Result& result)
{
    const MergingPolicy3::ChildConstraints& constraints = policy.GetChildConstraints();
    std::vector<std::set<std::string, std::less<>>> uniqueValues(constraints.uniqueAttributes.size());

    int i = 0;
    for (const pugi::xml_node childNode : node.children())
    {
        if (childNode.type() != pugi::node_element)
            continue;

        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
        childErrorStack.SetIndex(i);

        for (size_t uniqueAttrIdx = 0; uniqueAttrIdx < uniqueValues.size(); uniqueAttrIdx++)
        {
            const pugi::xml_attribute nodeAttr = childNode.attribute(constraints.uniqueAttributes[uniqueAttrIdx].c_str());

            if (!nodeAttr)
            {
                // Unique attribute is missing. Skip it.
                continue;
            }

            std::string_view value = nodeAttr.as_string();
            auto it = uniqueValues[uniqueAttrIdx].find(value);

            if (it != uniqueValues[uniqueAttrIdx].end())
            {
                AddError(
                    result,
                    childErrorStack,
                    fmt::format("Duplicate unique attribute value '{}'", value),
                    constraints.uniqueAttributes[uniqueAttrIdx]);
            }
            else
            {
                uniqueValues[uniqueAttrIdx].insert(std::string(value));
            }
        }

        i++;
    }
}

void XmlValidator::AddError(Result& result, const XmlErrorStack& errorStack, std::string_view message, std::string_view attribute)
{
    ValidationError error;
    error.path = errorStack.GetStackTrace();
    error.attributeName = attribute;
    error.message = message;
    result.errors.push_back(std::move(error));
    result.isValid = false;
}

std::string XmlValidator::Result::ToString(std::string_view indent) const
{
    if (isValid)
        return "Valid";

    std::string str;

    for (auto& error : errors)
    {
        // Path
        str += indent;
        for (auto it = error.path.crbegin(); it != error.path.crend(); ++it)
        {
            str += fmt::format("> {} ", *it);
        }

        // Attribute
        if (!error.attributeName.empty())
            str += fmt::format("| (attr = {})", error.attributeName);

        str += fmt::format("\n");

        // Message
        str += indent;
        str += fmt::format("    {}\n", error.message);
    }

    return str;
}
