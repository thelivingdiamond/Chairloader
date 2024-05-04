#pragma once
#include <ChairMerger/Export.h>

class XmlErrorStack;
class MergingPolicy3;

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

    struct Result
    {
        //! The XML is valid.
        bool isValid = true;

        //! The list of errors.
        std::vector<ValidationError> errors;

        explicit operator bool() const { return isValid; }
    };

    //! Validates a node that is matches the policy.
    //! @param  node    Node to validate
    //! @param  policy  Merging policy.
    //! @param  recurse Whether to validate children.
    static Result ValidateNode(const pugi::xml_node& node, const MergingPolicy3& policy, bool recurse = true);

private:
    static void ValidateNodeInternal(
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        Result& result,
        bool recurse);

    //! Validates attributes and adds errors to the result.
    static void ValidateAttributes(
        const pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
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
