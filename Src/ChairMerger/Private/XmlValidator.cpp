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
                const MergingPolicy3::Collection& collection = policy.GetCollection();

                // Key name
                std::string keyName;

                for (size_t i = 0; i < collection.keyChildAttributes.size(); i++)
                {
                    if (i != 0)
                        keyName += ',';
                    keyName += collection.keyChildAttributes[i];
                }

                // Key value
                std::string keyValue;

                for (size_t i = 0; i < collection.keyChildAttributes.size(); i++)
                {
                    if (i != 0)
                        keyValue += ',';
                    keyValue += childNode.attribute(collection.keyChildAttributes[i].c_str()).as_string("<not set>");
                }

                childErrorStack.SetId(std::move(keyName), std::move(keyValue));
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

        if (pTypeLib)
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
    switch (policy.GetCollection().type)
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
        int i = 0;
        for (const pugi::xml_node childNode : node.children())
        {
            XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
            childErrorStack.SetIndex(i);

            for (const std::string& keyAttrName : policy.GetCollection().keyChildAttributes)
            {
                if (!childNode.attribute(keyAttrName.c_str()))
                    AddError(result, childErrorStack, "Key attribute is missing", keyAttrName);
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
