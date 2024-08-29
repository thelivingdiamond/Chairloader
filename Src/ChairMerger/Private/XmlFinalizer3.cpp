#include <boost/algorithm/string.hpp>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlFinalizer3.h>
#include "MetaAttributes.h"

void XmlFinalizer3::FinalizeDocument(
    XmlFinalizerContext& context,
    pugi::xml_document& document,
    const FileMergingPolicy3& policy)
{
    if (policy.GetMethod() == FileMergingPolicy3::EMethod::ReadOnly)
        throw std::logic_error("This file can't be modified by mods and so can't be finalized");

    if (policy.GetMethod() == FileMergingPolicy3::EMethod::Localization)
        throw std::logic_error("Localization files don't need finalization");

    pugi::xml_node node = document.first_child();
    XmlErrorStack modErrorStack(node.name());
    FinalizeNode(context, node, policy.GetRootNode(), modErrorStack);
}

void XmlFinalizer3::FinalizeNode(
    XmlFinalizerContext& context,
    pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    if (policy.GetPatches().replaceEntityIDs)
    {
        pugi::xml_node objectsNode = node.child("Objects");
        XmlErrorStack objectsErrorStack = errorStack.GetChild(objectsNode);
        int maxEntityId = 0;

        auto fnForEachEntity = [&](auto func)
        {
            int j = -1;
            for (pugi::xml_node& entityNode : objectsNode.children())
            {
                j++;

                if (strcmp(entityNode.name(), "Entity"))
                    continue;

                XmlErrorStack entityErrorStack = objectsErrorStack.GetChild(entityNode);
                entityErrorStack.SetIndex(j);

                std::string_view entityGuid = XmlUtils::GetRequiredAttr(entityErrorStack, entityNode, "EntityGuid").as_string();
                entityErrorStack.SetId("EntityGuid", entityGuid);

                int entityId = -1;

                if (pugi::xml_attribute entityIdAttr = entityNode.attribute("EntityId"))
                {
                    entityId = XmlUtils::GetRequiredAttr(entityErrorStack, entityNode, "EntityId").as_int(-9999);
                    if (entityId == -9999)
                        entityErrorStack.ThrowException("Invalid EntityId");
                }

                func(entityNode, entityGuid, entityId, entityErrorStack);
            }
        };

        // Find the largest EntityId
        fnForEachEntity([&](pugi::xml_node&, std::string_view, int entityId, const XmlErrorStack&)
        {
            maxEntityId = std::max(maxEntityId, entityId);
        });

        // Generate EntityIDs for new entities
        int nextEntityId = maxEntityId + 1;
        fnForEachEntity([&](pugi::xml_node& entityNode, std::string_view, int entityId, const XmlErrorStack&)
        {
            if (entityId == -1)
            {
                entityNode.append_attribute("EntityId").set_value(nextEntityId);
                nextEntityId++;
            }
        });

        // Preload all entity IDs
        fnForEachEntity([&](pugi::xml_node&, std::string_view entityGuid, int entityId, const XmlErrorStack& entityErrorStack)
        {
            std::string entityGuidStr(entityGuid);

            if (context.entityIdMap.find(entityGuidStr) != context.entityIdMap.end())
                entityErrorStack.ThrowException(fmt::format("Duplicate EntityGuid {}", entityGuidStr));

            context.entityIdMap.emplace(std::move(entityGuidStr), entityId);
        });
    }

    // Remove generated attributes
    for (const MergingPolicy3::Attribute& attr : policy.GetAttributes())
    {
        if (attr.generated)
            node.remove_attribute(attr.name.c_str());
    }

    // Remove meta-attributes
    MetaAttributes::StripNode(node, true);

    // Resolve finalizer expressions
    for (pugi::xml_attribute attr : node.attributes())
    {
        std::string_view attrValue = attr.as_string();

        if (boost::starts_with(attrValue, "$(") && boost::ends_with(attrValue, ")"))
            attr.set_value(ExpandFinalizerExpression(context, node, policy, errorStack, attrValue).c_str());
    }

    // Recurse down
    int i = 0;

    for (pugi::xml_node childNode : node.children())
    {
        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
        childErrorStack.SetIndex(i);

        const MergingPolicy3* pChildPolicy = policy.FindChildNode(childNode.name());
        if (!pChildPolicy)
        {
            childErrorStack.ThrowException(fmt::format(
                "Node {} can't be a child of {} (merging policy not found)",
                childNode.name(),
                node.name()));
        }

        FinalizeNode(context, childNode, *pChildPolicy, childErrorStack);

        i++;
    }
}

std::string XmlFinalizer3::ExpandFinalizerExpression(
    XmlFinalizerContext& context,
    pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack,
    std::string_view expression)
{
    std::string_view trimmedExpression = expression.substr(2, expression.size() - 3);
    std::string_view funcName;
    std::vector<std::string> funcParams;

    size_t colon = trimmedExpression.find(':');
    if (colon != std::string_view::npos)
    {
        funcName = trimmedExpression.substr(0, colon);
        std::string_view allParams = trimmedExpression.substr(colon + 1);
        boost::split(funcParams, allParams, boost::is_any_of(","));
    }
    else
    {
        funcName = trimmedExpression;
    }
    
    if (funcName == "EntityId")
    {
        if (funcParams.size() != 1)
            ThrowExpression(errorStack, expression, fmt::format("Expected 1 parameter, got {}", funcParams.size()));

        // Find the entity
        auto it = context.entityIdMap.find(funcParams[0]);
        if (it == context.entityIdMap.end())
            ThrowExpression(errorStack, expression, fmt::format("Entity '{}' not found", funcParams[0]));

        // Replace with the ID
        return std::to_string(it->second);
    }
    else
    {
        ThrowExpression(errorStack, expression, fmt::format("Unknown function '{}'", funcName));
    }
}

void XmlFinalizer3::ThrowExpression(const XmlErrorStack& errorStack, std::string_view expression, std::string_view msg)
{
    errorStack.ThrowException(fmt::format("Error in finalizer expression \"{}\": {}", expression, msg));
}
