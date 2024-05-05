#include <boost/algorithm/string/join.hpp>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>

XmlValidator::Result XmlValidator::ValidateNode(
    const pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlTypeLibrary* pTypeLib,
    bool recurse)
{
    Result result;
    XmlErrorStack errorStack(node.name());
    ValidateNodeInternal(node, policy, errorStack, pTypeLib, result, recurse);
    return result;
}

void XmlValidator::ValidateNodeInternal(
    const pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack,
    const XmlTypeLibrary* pTypeLib,
    Result& result,
    bool recurse)
{
    ValidateAttributes(node, policy, errorStack, pTypeLib, result);
    ValidateCollection(node, policy, errorStack, result);
    ValidateConstraints(node, policy, errorStack, result);

    if (recurse)
    {
        int i = 0;
        for (const pugi::xml_node childNode : node.children())
        {
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
                ValidateNodeInternal(childNode, *childPolicy, childErrorStack, pTypeLib, result, true);
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
    const pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack,
    const XmlTypeLibrary* pTypeLib,
    Result& result)
{
    // Check existing attributes
    for (const pugi::xml_attribute nodeAttr : node.attributes())
    {
        const MergingPolicy3::Attribute* policyAttr = policy.FindAttribute(nodeAttr.name());

        if (!policyAttr)
        {
            if (!policy.IsAllowingUnknownAttributes())
                AddError(result, errorStack, "Unknown attribute", nodeAttr.name());

            continue;
        }
        
        if (nodeAttr.as_string()[0] == '\0')
        {
            // Attribute is empty
            if (!policyAttr->allowEmpty)
                AddError(result, errorStack, "Attribute can't be empty", nodeAttr.name());
        }
        else if (pTypeLib)
        {
            const IXmlType* pType = pTypeLib->FindType(policyAttr->type);
            if (!pType)
                errorStack.ThrowException(fmt::format("Unknown type {} in the merging policy", policyAttr->type));

            std::string_view value = nodeAttr.as_string();
            bool isValid = pType->ValidateValue(value);
            if (!isValid)
                AddError(result, errorStack, fmt::format("Invalid value '{}' for type {}", value, pType->GetFullName()), nodeAttr.name());
        }
    }

    // Check if any required attributes are missing
    for (const MergingPolicy3::Attribute& policyAttr : policy.GetAttributes())
    {
        if (policyAttr.required && !node.attribute(policyAttr.name.c_str()))
            AddError(result, errorStack, "Required attribute is missing", policyAttr.name);
    }
}

void XmlValidator::ValidateCollection(const pugi::xml_node& node, const MergingPolicy3& policy, const XmlErrorStack& errorStack, Result& result)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();

    switch (collection.type)
    {
    case MergingPolicy3::ECollectionType::None:
    {
        // There must be no children
        bool hasChildren = node.children().begin() != node.children().end();
        if (hasChildren)
            AddError(result, errorStack, "Collection type is not defined. Node must not have any children in that case.");
        break;
    }
    case MergingPolicy3::ECollectionType::Array:
    {
        // No validation required
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
