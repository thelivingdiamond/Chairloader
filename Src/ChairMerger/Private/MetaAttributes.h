#pragma once

class XmlErrorStack;

class MetaAttributes
{
public:
    static constexpr char PREFIX[] = "ch:";
    static constexpr char APPLY_IF[] = "ch:apply_if";
    static constexpr char ARRAY_SOURCE[] = "ch:arrayMod";
    static constexpr char ARRAY_SOURCE_PREY[] = "__prey__";
    static constexpr char ACTION[] = "ch:action";
    static constexpr char BASED_ON[] = "ch:basedOn";

    enum class EAction
    {
        //! Node will be merged via normal algorithms.
        Patch,

        //! Node will be removed if it was found.
        Delete,

        //! Entire node will be replaced.
        Replace,

        //! All chidlren node will be replaced, attributes are merged.
        ReplaceChildren,
    };

    //! Gets the node's apply_if attribute.
    //! @param  node    The node.
    //! @returns Apply_if attribute value. If not set, defaults to true.
    static bool CheckApplyIf(const pugi::xml_node& node);

    //! Removes all meta-attributes from a node.
    static void StripNode(pugi::xml_node node, bool finalize = false);

    //! Checks if the attribute is a known meta-attribute.
    //! @{
    static bool IsKnownMetaAttr(std::string_view attrName);
    static bool IsKnownMetaAttr(const pugi::xml_attribute& attr) { return IsKnownMetaAttr(attr.name()); }
    //! @}

    //! Validates meta-attributes on a node.
    static std::map<std::string, std::string> ValidateNode(const pugi::xml_node& node);

    MetaAttributes() = default;

    //! Parses a node's attributes.
    //! @param  node    The node.
    void ParseNode(const pugi::xml_node& node, const XmlErrorStack& errorStack);

    //! @returns Whether this mod node should be applied.
    bool GetApplyNode() const { return m_Apply; }

    //! @returns The action for the node.
    EAction GetAction() const { return m_Action.value_or(EAction::Patch); }

    //! @returns The query string to find a node to base on.
    const std::string& GetBasedOn() const { return m_BasedOn; }

private:
    bool m_Apply = false;
    std::optional<EAction> m_Action;
    std::string m_BasedOn;
};
