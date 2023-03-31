//
// Created by theli on 3/26/2023.
//

#ifndef CHAIRLOADER_XMLMERGER2_H
#define CHAIRLOADER_XMLMERGER2_H
#include "MergingPolicy.h"
#include "AttributeWildcard.h"

class XMLMerger2 {
public:
    //! Merge two XML documents together, using the specified merging policy.
    static void MergeXMLDocument(pugi::xml_document &baseDoc, pugi::xml_document &modDoc, pugi::xml_document &originalDoc, MergingPolicy policy);

    //! Merge two XML nodes together, using the specified merging policy.
    static void MergeNodeStructure(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy);

    //! Merge two xml nodes, including wildcard matching, vanilla checking, and indicator handling
    static void MergeXmlNode(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode);

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
};


#endif //CHAIRLOADER_XMLMERGER2_H
