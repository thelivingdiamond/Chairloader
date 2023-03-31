//
// Created by theli on 3/26/2023.
//

#include <sstream>
#include "XMLMerger2.h"
#include <gtest/gtest.h>



// Alternatively called Node Emulsification, Unification, or Coalescence
void XMLMerger2::FuseXMLNode(pugi::xml_node baseNode, pugi::xml_node modNode) {
    MergeXmlNodeAttributes(baseNode, modNode);
    baseNode.remove_children();
    for (auto &child: modNode.children()) {
        baseNode.append_copy(child);
    }
}


// Problem with patch mode
// In this example:
/*
<ExampleList>
  <Item id="1">
    <Element a="2">
    <Element a="3">
  </Item>
  <Item id="2">
    ...
</ExampleList>
 */
// Only the first element will get patched, and if the mod node mirrors the structure it will get patched twice. This is a limitation of XML.
// Not expected to be an actual problem

void XMLMerger2::PatchXmlNode(pugi::xml_node baseNode, pugi::xml_node modNode) {
    MergeXmlNodeAttributes(baseNode, modNode);
    for(auto &modChild : modNode.children()){
        // check if the child exists in the base node
        auto baseChild = baseNode.child(modChild.name());
        if(baseChild){
            // if it does, recursively call this function
            PatchXmlNode(baseChild, modChild);
        }
    }
}



void XMLMerger2::MergeXmlNodeAttributes(pugi::xml_node baseNode, pugi::xml_node modNode) {
    for(auto &overrideAttribute : modNode.attributes()){
        if(!baseNode.attribute(overrideAttribute.name())){
            baseNode.append_attribute(overrideAttribute.name()) = overrideAttribute.value();
        } else {
            baseNode.attribute(overrideAttribute.name()) = overrideAttribute.value();
        }
    }
}

void XMLMerger2::AppendXmlNode(pugi::xml_node baseNode, pugi::xml_node modNode) {
    baseNode.append_copy(modNode);
}



void XMLMerger2::MergeXmlNode(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode) {
    // find if the node is original to the vanilla node
    if(IsVanillaNode(modNode, originalNode)){
        return;
    }

    // find out if the node is applied
    if(modNode.attribute("ch:apply_if")){
        if(!modNode.attribute("ch:apply_if").as_bool()){
            return;
        }
    }

    // find out if the operation is to remove the node
    if(modNode.attribute("ch:remove").as_bool()){
        baseNode.parent().remove_child(baseNode);
    }
    bool patchMode = modNode.attribute("ch:patch_mode").as_bool();

    // fuse or patch the node
    if(patchMode){
        PatchXmlNode(baseNode, modNode);
    } else {
        FuseXMLNode(baseNode, modNode);
    }


}


bool XMLMerger2::CheckNodeEquality(pugi::xml_node modNode, pugi::xml_node originalNode) {
    std::stringstream originalContent, overrideContent;
    originalNode.print(originalContent);
    modNode.print(overrideContent);
    return std::string(originalContent.str()) == std::string(overrideContent.str());
}

bool XMLMerger2::IsVanillaNode(pugi::xml_node modNode, pugi::xml_node originalNode) {
    return CheckNodeEquality(modNode, originalNode);
}


// Note: this will only resolve wildcard chains that are a linear tree. i.e.
/*
 <_wildcard_>
    <_wildcard_>
        <_wildcard>
        ...
    </_wildcard_>
</_wildcard_>
 */
// If a merging policy node has multiple wildcard children it will not resolve.
// The merging policy document was designed with this constraint in mind, but it's good to be aware of this

void XMLMerger2::ResolvePolicyPathWildcards(pugi::xml_node modNode, pugi::xml_node policyNodeStructure) {
    // replace wildcard in node path
    if(policyNodeStructure.name() == std::string("_wildcard_")){
        if(modNode.name() != std::string("")) {
            policyNodeStructure.set_name(modNode.name());
        }
    }

    // recurse until a leaf node is reached
    if(policyNodeStructure.first_child()){
        ResolvePolicyPathWildcards(modNode.first_child(), policyNodeStructure.first_child());
    }
}

void XMLMerger2::MergeByAttribute(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy) {
    for(auto & modChild : modNode.children()) {
        bool overwrite = false;
        // we have a list of attributes to match against
        // if any of the attributes match, we can overwrite as long as we don't need all attributes to match
        // if we need all attributes to match, we need to check if all attributes match on the found node


        pugi::xml_node baseChild, originalChild;

        baseChild = FindNodeByAttributeList(baseNode, modChild, policy.attributeMatches, policy.match_all_attributes);
        originalChild = FindNodeByAttributeList(originalNode, modChild, policy.attributeMatches, policy.match_all_attributes);

        overwrite = baseChild;

        // merge or append the node
        if(overwrite){
            MergeXmlNode(baseChild, modChild, originalChild);
        } else {
            AppendXmlNode(baseNode, modChild);
        }
    }
}

void XMLMerger2::MergeByTag(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy) {
    for(auto &modChild : modNode){
        std::string modChildName = modChild.name();
        pugi::xml_node baseChild, originalChild;
        // find if a base node exists with the same tag
        baseChild = baseNode.child(modChild.name());
        // find if an original node exists with the same tag
        originalChild = originalNode.child(modChildName.c_str());

        // merge or append the node
        if(baseChild){
            MergeXmlNode(baseChild, modChild, originalChild);
        } else {
            AppendXmlNode(baseNode, modChild);
        }
    }
}

void XMLMerger2::MergeByContents(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy) {
    for(auto & modChild :modNode) {
        pugi::xml_node baseChild, originalChild;

        // find if a base node exists with the same contents
        for(auto &searchChild : baseNode) {
            if(std::string(searchChild.text().get()) == std::string(modChild.text().get())) {
                baseChild = searchChild;
                break;
            }
        }

        // find if an original node exists with the same contents
        for(auto &searchChild : originalNode) {
            if(std::string(searchChild.text().get()) == std::string(modChild.text().get())) {
                originalChild = searchChild;
                break;
            }
        }

        // merge or append the node
        if(baseChild){
            MergeXmlNode(baseChild, modChild, originalChild);
        } else {
            AppendXmlNode(baseNode, modChild);
        }
    }
}

void XMLMerger2::MergeBySpreadsheet(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy) {

    // get the table nodes
    auto modTableNode = modNode.child("Worksheet").child("Table");
    auto baseTableNode = baseNode.child("Worksheet").child("Table");
    auto originalTableNode = originalNode.child("Worksheet").child("Table");

    // cache the base and original nodes in a map
    std::map<std::string, pugi::xml_node> baseNodes;
    std::map<std::string, pugi::xml_node> originalNodes;
    for(auto &baseRow : baseTableNode.children("Row")) {
        baseNodes[baseRow.child("Cell").child("Data").text().get()] = baseRow;
    }
    for(auto &originalRow : originalTableNode.children("Row")) {
        originalNodes[originalRow.child("Cell").child("Data").text().get()] = originalRow;
    }

    // iterate through the mod table and merge the nodes
    for(auto & modRow : modTableNode.children("Row")){
        auto key = std::string(modRow.child("Cell").child("Data").text().get());
        // check for original and base child
        if(!key.empty()) {
            pugi::xml_node originalCandidate, baseCandidate;
            if (originalNodes.find(key) != originalNodes.end()) {
                originalCandidate = originalNodes[key];
            }
            if (baseNodes.find(key) != baseNodes.end()) {
                baseCandidate = baseNodes[key];
            }

            if (baseCandidate) {
                // merge the row
                MergeXmlNode(baseCandidate, modRow, originalCandidate);
            } else {
                // append the row
                AppendXmlNode(baseTableNode, modRow);
            }
        }
    }
}

void XMLMerger2::MergeXMLDocument(pugi::xml_document &baseDoc, pugi::xml_document &modDoc, pugi::xml_document &originalDoc, MergingPolicy policy) {
    // resolve policy path wildcards
    ResolvePolicyPathWildcards(modDoc.first_child(), policy.nodeStructure.first_child());

    // merge the node structure
    auto baseNode = baseDoc.first_child();
    auto modNode = modDoc.first_child();
    auto originalNode = originalDoc.first_child();

    MergeNodeStructure(baseNode, modNode, originalNode, policy);
}

void XMLMerger2::MergeNodeStructure(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy) {
    for(auto & policyNode: policy.nodeStructure.children()){
        auto localPolicy = policy;
        // get the node tags
        auto nodeTags = MergingPolicy::getNodeTags(policyNode);
        // set the node structure to a level down
        localPolicy.nodeStructure = policyNode;

        // if we override the policy, parse the new policy
        if(nodeTags & MergingPolicy::node_tags::override_policy){
            localPolicy.policy = MergingPolicy::parsePolicy(policyNode.attribute("identification_policy").value());
            localPolicy.match_all_attributes = nodeTags & MergingPolicy::node_tags::match_all;
            localPolicy.attributeMatches.clear();
            if(localPolicy.policy == MergingPolicy::identification_policy::match_attribute){
                for(auto& attributeNode: policyNode.children("attribute")){
                    localPolicy.attributeMatches.emplace_back(MergingPolicy::attributeMatch{attributeNode.attribute("name").as_string(), attributeNode.attribute("priority").as_int()});
                }
            }
        }

        std::string nodeName = policyNode.name();
        pugi::xml_node modChild, baseChild, originalChild;
        if(modNode.name() == nodeName){
            modChild = modNode;
        } else {
            modChild = modNode.child(policyNode.name());
        }
        if(baseNode.name() == nodeName){
            baseChild = baseNode;
        } else {
            baseChild = baseNode.child(policyNode.name());
        }
        if(originalNode.name() == nodeName){
            originalChild = originalNode;
        } else {
            originalChild = originalNode.child(policyNode.name());
        }

        if(!baseChild || !originalChild){
            // this is an error, we should never be merge descending a node that doesn't exist in the base document or original document
            break;
        }

        if(!modChild) {
            continue;
        }

        // check if node needs to merge attributes
        if(nodeTags & MergingPolicy::node_tags::merge_attributes){
            MergeXmlNodeAttributes(baseChild, modChild);
        }

        // if the node has the merge_children tag, merge them. This ends the current iteration
        if(nodeTags & MergingPolicy::node_tags::merge_children){
            switch(localPolicy.policy){
                //overwrite = identical to merge_node
                case MergingPolicy::identification_policy::overwrite:
                    break;
                    // unknown should never be passed into a mergeNodeStructure call
                case MergingPolicy::identification_policy::match_spreadsheet:
                    break;
                case MergingPolicy::identification_policy::unknown:
                case MergingPolicy::identification_policy::error:
                    break;
                case MergingPolicy::identification_policy::match_attribute:
                    MergeByAttribute(baseChild, modChild, originalChild, localPolicy);
                    break;
                case MergingPolicy::identification_policy::match_tag:
                    MergeByTag(baseChild, modChild, originalChild, localPolicy);
                    break;
                case MergingPolicy::identification_policy::match_contents:
                    MergeByContents(baseChild, modChild, originalChild, localPolicy);
                    break;
            }
            continue;
        }

        if (nodeTags & MergingPolicy::node_tags::merge_node) {
            MergeXmlNode(baseChild, modChild, originalChild);
        }

        if(!policyNode.children().empty())
            MergeNodeStructure(baseChild, modChild, originalChild, localPolicy);
    }
}


// this function needs to take a list of attributes and find the first node that matches any of the attributes, but matching them in order that they are in the list (priority)
// the reference node has the attributes values that we are looking for
pugi::xml_node XMLMerger2::FindNodeByAttributeList(pugi::xml_node &searchNode, pugi::xml_node &referenceNode, std::vector<MergingPolicy::attributeMatch> &attributeList, bool matchAllAttributes) {
    pugi::xml_node searchResult;
    if(!matchAllAttributes) {
        for(auto &child: searchNode){
            for (auto &attribute: attributeList) {
                std::string attributeValue = referenceNode.attribute(attribute.attribute_name.c_str()).value();
                if (child.attribute(attribute.attribute_name.c_str()).value() == attributeValue) {
                    searchResult = child;
                    break;
                }
            }
            if(searchResult)
                break;
        }
    } else {
        for(auto &child: searchNode){
            bool found = true;
            for (auto &attribute: attributeList) {
                std::string attributeValue = referenceNode.attribute(attribute.attribute_name.c_str()).value();
                if (child.attribute(attribute.attribute_name.c_str()).value() != attributeValue) {
                    found = false;
                    break;
                }
            }
            if(found){
                searchResult = child;
                break;
            }
        }
    }
    return searchResult;
}

