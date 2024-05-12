#include "MetaAttributes.h"

static const std::set<std::string, std::less<>> g_MetaAttrs = {
    MetaAttributes::APPLY_IF,
};

bool MetaAttributes::CheckApplyIf(const pugi::xml_node& node)
{
    return node.attribute(APPLY_IF).as_bool(true);
}

void MetaAttributes::StripNode(pugi::xml_node node)
{
    for (const std::string& metaAttr : g_MetaAttrs)
    {
        node.remove_attribute(metaAttr.c_str());
    }
}

bool MetaAttributes::IsKnownMetaAttr(std::string_view attrName)
{
    return g_MetaAttrs.find(attrName) != g_MetaAttrs.end();
}

void MetaAttributes::ParseNode(const pugi::xml_node& node)
{
    m_Apply = CheckApplyIf(node);

    if (!m_Apply)
    {
        // Node is disabled. No further parsing as other attributes may be invalid.
        return;
    }
}
