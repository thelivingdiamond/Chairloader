#pragma once
#include <utility>
#include "Merging/MergingPolicy.h"
#include "Merging/AttributeWildcard.h"

//
// Created by theli on 9/10/2022.
//


class XMLMerger {
public:

    XMLMerger();
    void init();
    pugi::xml_document mergingLibrary;
    MergingPolicy getFileMergingPolicy(fs::path filePath, std::string modName);

    static void resolvePathWildcards(pugi::xml_node node, pugi::xml_node nodeStructure);
    static std::vector<pugi::xml_node>
    resolveAttributeWildcards(pugi::xml_node &node, pugi::xml_node &nodeStructure, std::string &modName);

    static bool checkNodeEquality(pugi::xml_node modNode, pugi::xml_node originalNode);
    //! merge one node into another. Copy all attributes and children from the source node into the destination node
    bool mergeXMLFile(fs::path relativeFilePath, std::string modName, bool isLegacyMod);
    static bool mergeXMLDocument(pugi::xml_document &baseDoc, pugi::xml_document &modDoc, pugi::xml_document &originalDoc, MergingPolicy policy);
    static bool mergeNodeStructure(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy);

    static void mergeByAttribute(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy);
    static void mergeByTag(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy);
    static void mergeByContents(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy);
    static void mergeBySpreadsheet(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy);
    static void mergeXMLNodeAttributes(pugi::xml_node &baseNode, pugi::xml_node &modNode);

    static void mergeXMLNode(pugi::xml_node &baseNode, pugi::xml_node &modNode);
    static void patchXMLNode(pugi::xml_node &baseNode, pugi::xml_node &modNode);

    static std::string getWildcardValue(AttributeWildcard &wildcardValue);
};

pugi::xml_node noCaseChild(pugi::xml_node& node, std::string name);