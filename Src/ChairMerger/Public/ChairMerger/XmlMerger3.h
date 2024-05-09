#pragma once
#include <ChairMerger/Export.h>

class MergingPolicy3;
class FileMergingPolicy3;
class XmlErrorStack;
class XmlTypeLibrary;

struct XmlMergerContext
{
    //! Optional type library for validation.
    const XmlTypeLibrary* pTypeLib = nullptr;
};

class CHAIRMERGER_EXPORT XmlMerger3
{
public:
    //! Merges a mod document into the base document.
    //! @param  context     Merger context.
    //! @param  baseDoc     Base document. Will be modified.
    //! @param  modDoc      Mod document.
    //! @param  policy      Merging policy for the file.
    static void MergeDocument(
        const XmlMergerContext& context,
        pugi::xml_document& baseDoc,
        const pugi::xml_document& modDoc,
        const FileMergingPolicy3& policy);

    //! Merges a mod node into the base node. Merging method is decided by the merging policy
    //! @param  context     Merger context.
    //! @param  baseNode        Base node. Will be modified.
    //! @param  modNode         Mod node.
    //! @param  policy          Merging policy for the node.
    //! @param  modErrorStack   XML error stack for the mod node.
    static void MergeNode(
        const XmlMergerContext& context,
        pugi::xml_node& baseNode,
        const pugi::xml_node& modNode,
        const MergingPolicy3& policy,
        const XmlErrorStack& modErrorStack);

    //! Merges a mod node into the base node.
    //! Only attributes set in mod node will be updated.
    //! Children merging method is decided by the merging policy.
    //! @param  context     Merger context.
    //! @param  baseNode        Base node. Will be modified.
    //! @param  modNode         Mod node.
    //! @param  policy          Merging policy for the node.
    //! @param  modErrorStack   XML error stack for the mod node.
    static void PatchNode(
        const XmlMergerContext& context,
        pugi::xml_node& baseNode,
        const pugi::xml_node& modNode,
        const MergingPolicy3& policy,
        const XmlErrorStack& modErrorStack);

private:
    //! Merges the attributes of mod node into the base node.
    //! @param  context     Merger context.
    //! @param  baseNode        Base node. Will be modified.
    //! @param  modNode         Mod node.
    //! @param  policy          Merging policy for the node.
    //! @param  modErrorStack   XML error stack for the mod node.
    static void MergeAttributes(
        const XmlMergerContext& context,
        pugi::xml_node& baseNode,
        const pugi::xml_node& modNode,
        const MergingPolicy3& policy,
        const XmlErrorStack& modErrorStack);

    //! Merges the children of mod node with the children of base node.
    //! Expects that policy is a dicitonary.
    static void MergeChildrenDict(
        const XmlMergerContext& context,
        pugi::xml_node& baseNode,
        const pugi::xml_node& modNode,
        const MergingPolicy3& policy,
        const XmlErrorStack& modErrorStack);

    //! Tries to find a child mod node in the parent base node.
    //! @param  parentBaseNode  Base node that contains children of the same type as childModNode.
    //! @param  childModNode    Child mod node.
    //! @param  parentPolicy    Merging policy for the base node.
    //! @param  modErrorStack   XML error stack for the child mod node.
    //! @returns Child base node that has key equal to the one of child mod node.
    static pugi::xml_node FindBaseNodeByModKey(
        pugi::xml_node& parentBaseNode,
        const pugi::xml_node& childModNode,
        const MergingPolicy3& parentPolicy,
        const XmlErrorStack& childModErrorStack);
};
