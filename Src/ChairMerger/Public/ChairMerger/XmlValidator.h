#pragma once
#include <ChairMerger/Export.h>
#include <ChairMerger/MergingPolicy3.h>

class XmlErrorStack;
class XmlTypeLibrary;

//! Validates XML files using the merging policy.
class CHAIRMERGER_EXPORT XmlValidator
{
public:
    enum class ENodeType
    {
        //! File to be used by Prey
        Prey,

        //! Base node used during merging.
        MergingBase,

        //! Mod file
        Mod,
    };

    struct ValidationError
    {
        //! Path to the node
        std::vector<std::string> path;

        //! Attribute name, if it is involved.
        std::string attributeName;

        //! Error message;
        std::string message;
    };

    struct CHAIRMERGER_EXPORT Result
    {
        //! The XML is valid.
        bool isValid = true;

        //! The list of errors.
        std::vector<ValidationError> errors;

        explicit operator bool() const { return isValid; }

        //! Converts the result into a string.
        std::string ToString(std::string_view indent = std::string_view()) const;
    };

    struct Context
    {
        //! Node type.
        ENodeType nodeType = ENodeType::Prey;

        //! Optional type library for type validation.
        const XmlTypeLibrary* pTypeLib = nullptr;
    };

    //! Validates a node that is matches the policy.
    //! @param  node        Node to validate
    //! @param  policy      Merging policy.
    //! @param  pTypeLib    Type library for type validation.
    //! @param  recurse     Whether to validate children.
    static Result ValidateDocument(
        const Context& context,
        const pugi::xml_document& doc,
        const FileMergingPolicy3& policy);

    //! Validates a node that is matches the policy.
    //! @param  node        Node to validate
    //! @param  policy      Merging policy.
    //! @param  pTypeLib    Type library for type validation.
    //! @param  recurse     Whether to validate children.
    static Result ValidateNode(
        const Context& context,
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        bool recurse = true);

    //! Validates the attribute value.
    //! @returns Error text or empty string if no error.
    static std::string ValidateAttribute(
        const Context& context,
        const pugi::xml_attribute& nodeAttr,
        const MergingPolicy3::Attribute& policyAttr);

    //! Validates a plain-text node.
    //! @returns Error text or empty string if no error.
    static std::string ValidateTextNode(
        const Context& context,
        const pugi::xml_node& node,
        const MergingPolicy3& policy);

    //! Checks if a node has child non-text nodes.
    static bool NodeHasChildElements(const pugi::xml_node& node);

private:
    static void ValidateNodeInternal(
        const Context& context,
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        Result& result,
        bool recurse);

    //! Validates attributes and adds errors to the result.
    static void ValidateAttributes(
        const Context& context,
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        Result& result);

    //! Validates text value and adds errors to the result.
    static void ValidateText(
        const Context& context,
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        Result& result);

    //! Validates that all children match the collection type.
    static void ValidateCollection(
        const Context& context,
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        Result& result);

    //! Validates that all children satisfy the constraints.
    static void ValidateConstraints(
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        Result& result);

    static void AddError(
        Result& result,
        const XmlErrorStack& errorStack,
        std::string_view message,
        std::string_view attribute = std::string_view());
};
