#pragma once
#include <ChairMerger/Export.h>
#include <ChairMerger/MergingPolicy3.h>

class XmlErrorStack;
class XmlTypeLibrary;

//! Validates XML files using the merging policy.
class CHAIRMERGER_EXPORT XmlValidator
{
public:
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

    //! Validates a node that is matches the policy.
    //! @param  node        Node to validate
    //! @param  policy      Merging policy.
    //! @param  pTypeLib    Type library for type validation.
    //! @param  recurse     Whether to validate children.
    static Result ValidateNode(
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlTypeLibrary* pTypeLib = nullptr,
        bool recurse = true);

    //! Validates the attribute value.
    //! @returns Error text pr empty string if no error.
    static std::string ValidateAttribute(
        const pugi::xml_attribute& nodeAttr,
        const MergingPolicy3::Attribute& policyAttr,
        const XmlTypeLibrary* pTypeLib = nullptr);

private:
    static void ValidateNodeInternal(
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        const XmlTypeLibrary* pTypeLib,
        Result& result,
        bool recurse);

    //! Validates attributes and adds errors to the result.
    static void ValidateAttributes(
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        const XmlTypeLibrary* pTypeLib,
        Result& result);

    //! Validates that all children match the collection type.
    static void ValidateCollection(
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
