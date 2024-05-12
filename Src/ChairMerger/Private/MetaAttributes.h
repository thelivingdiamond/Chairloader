#pragma once

class MetaAttributes
{
public:
    static constexpr char PREFIX[] = "ch:";
    static constexpr char APPLY_IF[] = "ch:apply_if";

    //! Gets the node's apply_if attribute.
    //! @param  node    The node.
    //! @returns Apply_if attribute value. If not set, defaults to true.
    static bool CheckApplyIf(const pugi::xml_node& node);

    //! Removes all meta-attributes from a node.
    static void StripNode(pugi::xml_node node);

    //! Checks if the attribute is a known meta-attribute.
    //! @{
    static bool IsKnownMetaAttr(std::string_view attrName);
    static bool IsKnownMetaAttr(const pugi::xml_attribute& attr) { return IsKnownMetaAttr(attr.name()); }
    //! @}

    MetaAttributes() = default;
    explicit MetaAttributes(const pugi::xml_node& node) { ParseNode(node); }

    //! Parses a node's attributes.
    //! @param  node    The node.
    void ParseNode(const pugi::xml_node& node);

    //! @returns Whether this mod node should be applied.
    bool GetApplyNode() const { return m_Apply; }

private:
    bool m_Apply = false;
};
