#pragma once
#include <ChairMerger/Export.h>

class MergingPolicy3;
class FileMergingPolicy3;
class XmlErrorStack;

struct XmlFinalizerContext
{
    std::map<std::string, int> entityIdMap; //!< Maps EntityGuid to EntityId. Filled by the finalizer.
};

//! Finalizes an XML file and converts it into a file compatible with Prey.
class CHAIRMERGER_EXPORT XmlFinalizer3
{
public:
    //! Merges a mod document into the base document.
    //! @param  context     Merger context.
    //! @param  baseDoc     Base document. Will be modified.
    //! @param  modDoc      Mod document.
    //! @param  policy      Merging policy for the file.
    static void FinalizeDocument(
        XmlFinalizerContext& context,
        pugi::xml_document& document,
        const FileMergingPolicy3& policy);

    //! Merges a mod node into the base node. Merging method is decided by the merging policy
    //! @param  context     Merger context.
    //! @param  baseNode        Base node. Will be modified.
    //! @param  modNode         Mod node.
    //! @param  policy          Merging policy for the node.
    //! @param  modErrorStack   XML error stack for the mod node.
    static void FinalizeNode(
        XmlFinalizerContext& context,
        pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack);

private:
    static std::string ExpandFinalizerExpression(
        XmlFinalizerContext& context,
        pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        std::string_view expression);

    [[noreturn]] static void ThrowExpression(const XmlErrorStack& errorStack, std::string_view expression, std::string_view msg);
};
