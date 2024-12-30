#include <Chairloader/Private/XmlUtils.h>
#include "MetaAttributes.h"

//! All supported meta attributes
static const std::set<std::string, std::less<>> g_MetaAttrs = {
    MetaAttributes::APPLY_IF,
    MetaAttributes::APPLY_IF_LEGACY,
    MetaAttributes::ARRAY_SOURCE,
    MetaAttributes::ACTION,
    MetaAttributes::BASED_ON,

    // Used for XSDs
    "xmlns",
    "xmlns:ch",
    "xmlns:xsi",
    "xsi:schemaLocation",
};

//! Meta attributes that must not be stripped
static const std::set<std::string, std::less<>> g_RetainMetaAttrs = {
    MetaAttributes::ARRAY_SOURCE, // Used when merging next mods
    MetaAttributes::ACTION, // Kept as a reference for debugging.
};

static const std::map<std::string, MetaAttributes::EAction, std::less<>> g_ActionValues = {
    { "patch", MetaAttributes::EAction::Patch },
    { "delete", MetaAttributes::EAction::Delete },
    { "replace", MetaAttributes::EAction::Replace },
    { "replaceChildren", MetaAttributes::EAction::ReplaceChildren },
};

bool MetaAttributes::CheckApplyIf(const pugi::xml_node& node)
{
    if (pugi::xml_attribute attr = node.attribute(APPLY_IF))
        return attr.as_bool();
    else if (pugi::xml_attribute attr = node.attribute(APPLY_IF_LEGACY))
        return attr.as_bool();
    else
        return true;
}

void MetaAttributes::StripNode(pugi::xml_node node, bool finalize)
{
    for (const std::string& metaAttr : g_MetaAttrs)
    {
        if (!finalize && g_RetainMetaAttrs.find(metaAttr) != g_RetainMetaAttrs.end())
            continue;

        node.remove_attribute(metaAttr.c_str());
    }
}

bool MetaAttributes::IsKnownMetaAttr(std::string_view attrName)
{
    return g_MetaAttrs.find(attrName) != g_MetaAttrs.end();
}

std::map<std::string, std::string> MetaAttributes::ValidateNode(const pugi::xml_node& node)
{
    std::map<std::string, std::string> result;

    if (pugi::xml_attribute action = node.attribute(ACTION))
    {
        EAction val{};
        if (!XmlUtils::TryGetEnumAttribute(action, g_ActionValues, val))
        {
            result.emplace(action.name(), fmt::format(
                "Invalid attribute value {}='{}'. Allowed values: {}",
                action.name(), action.as_string(), XmlUtils::GetEnumAttributeAllowedValues(g_ActionValues)));
        }
    }

    return result;
}

void MetaAttributes::ParseNode(const pugi::xml_node& node, const XmlErrorStack& errorStack)
{
    m_Apply = CheckApplyIf(node);

    if (!m_Apply)
    {
        // Node is disabled. No further parsing as other attributes may be invalid.
        return;
    }

    if (pugi::xml_attribute action = node.attribute(ACTION))
    {
        m_Action = XmlUtils::GetEnumAttribute<EAction>(errorStack, action, g_ActionValues);
    }

    if (pugi::xml_attribute action = node.attribute(BASED_ON))
    {
        m_BasedOn = action.as_string();
    }
}
