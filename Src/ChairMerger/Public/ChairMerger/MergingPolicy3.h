#pragma once
#include <regex>
#include <ChairMerger/Export.h>

class XmlErrorStack;

//! Defines the data model of a named node.
class CHAIRMERGER_EXPORT MergingPolicy3
{
public:
    static constexpr char XML_NODE_NAME[] = "Node";

    enum class ECollectionType
    {
        //! Invalid type.
        None,
        
        //! Key-value dictionary with arbitrary key.
        Dict,

        //! An ordered list of nodes, with no particular key.
        Array,
    };

    //! Defines a known/allowed attribute.
    struct Attribute
    {
        //! Name of the attribute.
        std::string name;

        //! Type of the attribute.
        std::string type;

        //! Whether the attribute must be present.
        bool required = false;

        //! If true, mods won't be able to change the value of this attribute on existing nodes.
        bool readOnly = false;

        //! Comment describing the attribute.
        std::string comment;
    };

    //! Defines the type of the collection and how child nodes should be merged.
    struct Collection
    {
        //! The type of the collection.
        ECollectionType type = ECollectionType::None;

        //! Use the child node name as part of the key.
        bool keyChildName = false;

        //! Use these child attributes as part of the key. They must be present in all children.
        std::vector<std::string> keyChildAttributes;
    };

    //! Defines additional constraints on immediate children.
    struct ChildConstraints
    {
        //! The value of a child attribute must be unique among all of its sibling nodes.
        std::vector<std::string> uniqueAttributes;
    };

    //! @returns The node name. It might be a regex text.
    const std::string& GetNodeName() const { return m_NodeName; }
    void SetNodeName(std::string_view nodeName, bool isRegex = false);

    //! @returns Whether the node name is a regular expression.
    bool IsNodeNameRegex() const { return m_IsNodeNameRegex; }

    //! @returns Whether this policy applies to all unknown child nodes.
    bool IsRecursive() const { return m_IsRecursive; }
    void SetRecursive(bool state) { m_IsRecursive = state; }

    //! @returns The list of known/allowed attributes.
    const std::vector<Attribute>& GetAttributes() const { return m_Attributes; }
    std::vector<Attribute>& GetAttributes() { return m_Attributes; }

    //! @returns Whether unknown attributes are allowed. If false, causes an error if an attribute is not listed.
    bool IsAllowingUnknownAttributes() const { return m_AllowUnknownAttributes; }
    void SetAllowUnknownAttributes(bool state) { m_AllowUnknownAttributes = state; }

    //! @returns The collection properties.
    const Collection& GetCollection() const { return m_Collection; }
    Collection& GetCollection() { return m_Collection; }

    //! @returns The child constraints.
    const ChildConstraints GetChildConstraints() const { return m_ChildConstraints; }
    ChildConstraints GetChildConstraints() { return m_ChildConstraints; }

    //! @returns The list of child nodes without regex.
    const std::vector<MergingPolicy3>& GetChildNodes() const { return m_ChildNodes; }

    //! @returns The list of child nodes that use regex.
    const std::vector<MergingPolicy3>& GetChildNodesRegex() const { return m_ChildNodesRegex; }

    //! Finds an attribute in the policy.
    //! @returns Attribute or nullptr if not found.
    const Attribute* FindAttribute(std::string_view name) const;

    //! Finds the policy for a child node.
    //! @returns Policy or nullptr if not found.
    const MergingPolicy3* FindChildNode(std::string_view name) const;

    //! Adds a new node to the end.
    //! @{
    void AppendNode(const MergingPolicy3& node);
    void AppendNode(MergingPolicy3&& node);
    //! @}

    //! Loads data from XML.
    void LoadXmlNode(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack, int indexInParent = -1);

private:
    static constexpr char XML_NODE_ATTRIBUTES[] = "Attributes";
    static constexpr char XML_NODE_ATTRIBUTE[] = "Attribute";

    static constexpr char XML_NODE_COLLECTION[] = "Collection";
    static constexpr char XML_NODE_PRIMARY_KEY[] = "PrimaryKey";
    static constexpr char XML_NODE_CHILD_NAME[] = "ChildName";
    static constexpr char XML_NODE_CHILD_ATTRIBUTE[] = "ChildAttribute";

    static constexpr char XML_NODE_CHILD_CONSTRAINTS[] = "ChildConstraints";
    static constexpr char XML_NODE_UNIQUE_ATTRIBUTE[] = "UniqueAttribute";

    static constexpr char XML_NODE_CHILD_NODES[] = "ChildNodes";

    std::string m_NodeName;
    std::regex m_NodeNameRegex;
    bool m_IsNodeNameRegex = false;
    bool m_IsRecursive = false;

    std::vector<Attribute> m_Attributes;
    bool m_AllowUnknownAttributes = false;
    Collection m_Collection;
    ChildConstraints m_ChildConstraints;

    std::vector<MergingPolicy3> m_ChildNodes;
    std::vector<MergingPolicy3> m_ChildNodesRegex;

    std::vector<MergingPolicy3>& GetCollectionForNewNode(const MergingPolicy3& node);

    void LoadXmlAttributes(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack);
    void LoadXmlCollection(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack);
    void LoadXmlChildConstraints(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack);
    void LoadXmlChildNodes(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack);
};

class CHAIRMERGER_EXPORT FileMergingPolicy3
{
public:
    static constexpr char XML_NODE_NAME[] = "MergingPolicy";

    //! Checks if the input file name matches this policy file.
    bool MatchFileName(const std::string& name) const;

    //! @returns Whether this policy matches files by regex.
    bool IsRegexName() const { return m_IsFileNameRegex; }

    //! @returns Whether this policy will apply to subfolders recursively.
    bool IsRecursive() const { return m_IsRecursive; }
    void SetRecursive(bool state) { m_IsRecursive = state; }

    //! @returns The file name. It might be a regex text.
    const std::string& GetFileName() const { return m_FileName; }
    void SetFileName(std::string_view fileName, bool isRegex);

    //! @returns The root node.
    const MergingPolicy3& GetRootNode() const { return m_RootNode; }
    MergingPolicy3& GetRootNode() { return m_RootNode; }

    //! Loads data from XML.
    void LoadXmlNode(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack);

private:
    std::string m_FileName;
    std::regex m_FileNameRegex;
    bool m_IsFileNameRegex = false;
    bool m_IsRecursive = false;
    MergingPolicy3 m_RootNode;
};
