//
// Created by theli on 3/26/2023.
//

#ifndef CHAIRLOADER_XMLMERGER2_H
#define CHAIRLOADER_XMLMERGER2_H
#include <ChairMerger/Export.h>
#include <ChairMerger/MergingPolicy.h>

class CHAIRMERGER_EXPORT XMLMerger2 {
public:
    //! Merge two XML documents together, using the specified merging policy.
    //! @param  baseDoc     Currently merged document. Merging result will be saved here.
    //! @param  modDoc      Mod document that needs to be merged into base.
    //! @param  originalDoc Original document from Prey.
    //! @param  policy      Merging policy.
    static void MergeXMLDocument(pugi::xml_document &baseDoc, const pugi::xml_document &modDoc, const pugi::xml_document &originalDoc, MergingPolicy policy);

    //! Merge two XML nodes together, using the specified merging policy.
    static void MergeNodeStructure(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy);

    //! Merge two xml nodes, including wildcard matching, vanilla checking, and indicator handling
    static void MergeXmlNode(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, bool forcePatchMode = false);

    //! Different merging policies
    static void MergeByAttribute(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy);
    static void MergeByTag(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy);
    static void MergeByContents(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy);
    static void MergeBySpreadsheet(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy);


    //! Merge the attributes of two xml nodes
    static void MergeXmlNodeAttributes(pugi::xml_node baseNode, pugi::xml_node modNode);
    //! Copy one xml node to another
    static void FuseXMLNode(pugi::xml_node baseNode, pugi::xml_node modNode);
    //! Patch an xml node with another node
    static void PatchXmlNode(pugi::xml_node baseNode, pugi::xml_node modNode);

    static void AppendXmlNode(pugi::xml_node baseNode, pugi::xml_node modNode);

    static pugi::xml_node FindNodeByAttributeList(pugi::xml_node &searchNode, pugi::xml_node &referenceNode, std::vector<MergingPolicy::attributeMatch> &attributeList, bool matchAllAttributes = false);




    //! When a policy specifies _wildcard_ this is used to find the appropriate node in the specific file
    static void ResolvePolicyPathWildcards(pugi::xml_node modNode, pugi::xml_node policyNodeStructure);


    //! Check if two nodes are equal
    static bool CheckNodeEquality(pugi::xml_node modNode, pugi::xml_node originalNode);
    //! Check if a mod node is identical to the vanilla node
    static bool IsVanillaNode(pugi::xml_node modNode, pugi::xml_node originalNode);

    /// \brief Serialize the level entity IDs to a file
    /// \param levelPath The path to the contents of level.pak
    static void SerializeLevelEntityIDs(fs::path levelPath);

    //! Parses a sibling query.
    //! @param  query   The query in the format "key1=val1;key2=val2";
    //! @returns List of keys and values.
    static std::vector<std::pair<std::string, std::string>> ParseSiblingQuery(std::string_view query);

private:
    //! When a node has this attribute, it will be created based on an existing node.
    static constexpr char COPY_SIBLING[] = "ch:copy_sibling";

    //! Checks that the mod node doesn't have copy_sibling attribute.
    //! If it does, throws std::runtime_error.
    static void VerifyNotCopySibling(pugi::xml_node baseNode, pugi::xml_node modNode);
};


#endif //CHAIRLOADER_XMLMERGER2_H
