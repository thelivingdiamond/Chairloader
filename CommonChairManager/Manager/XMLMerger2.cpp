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
    pugi::xml_attribute copySiblingAttr = modNode.attribute(COPY_SIBLING);

    if (copySiblingAttr) {
        std::vector<std::pair<std::string, std::string>> query = ParseSiblingQuery(copySiblingAttr.as_string());

        // Find a sibling that matches the set of conditions in the query
        pugi::xml_node foundSibling;

        for (pugi::xml_node sibling : baseNode) {
            // Check for conditions
            bool matchesConds = true;
            for (const auto& i : query) {
                pugi::xml_attribute keyAttr = sibling.attribute(i.first.c_str());
                if (!keyAttr || keyAttr.as_string() != i.second) {
                    // Skip this sibling
                    matchesConds = false;
                    break;
                }
            }

            if (!matchesConds)
                continue;

            // Found a sibling
            foundSibling = sibling;
        }

        if (!foundSibling)
            throw std::runtime_error(std::string("ch:copy_sibling: failed to find '") + copySiblingAttr.as_string() + "'");

        // Copy the sibling
        pugi::xml_node baseChild = baseNode.append_copy(foundSibling);

        // Merge into the sibling
        MergeXmlNode(baseChild, modNode, pugi::xml_node(), true);
    } else {
        // Simply append the node
        baseNode.append_copy(modNode);
    }
}



void XMLMerger2::MergeXmlNode(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, bool forcePatchMode) {
    // find if the node is original to the vanilla node
    if(originalNode && IsVanillaNode(modNode, originalNode)){
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
    bool patchMode = forcePatchMode || modNode.attribute("ch:patch_mode").as_bool();

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
            VerifyNotCopySibling(baseChild, modChild);
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
            VerifyNotCopySibling(baseChild, modChild);
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
            VerifyNotCopySibling(baseChild, modChild);
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
    if (policy.policy == MergingPolicy::identification_policy::match_spreadsheet)
    {
        auto baseNode = baseDoc.child("Workbook");
        auto modNode = modDoc.child("Workbook");
        auto originalNode = originalDoc.child("Workbook");

        MergeNodeStructure(baseNode, modNode, originalNode, policy);
    }
    else
    {
        auto baseNode = baseDoc.first_child();
        auto modNode = modDoc.first_child();
        auto originalNode = originalDoc.first_child();

        MergeNodeStructure(baseNode, modNode, originalNode, policy);
    }
}

void XMLMerger2::MergeNodeStructure(pugi::xml_node baseNode, pugi::xml_node modNode, pugi::xml_node originalNode, MergingPolicy policy) {
    if(policy.nodeStructure.children().empty()) {
        // due to a lack of node structure in spreadsheet cases, we need to check for the policy here
        if (policy.policy == MergingPolicy::identification_policy::match_spreadsheet) {
            MergeBySpreadsheet(baseNode, modNode, originalNode, policy);
        }
    }
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

        if(!modChild) {
            continue;
        }

        if (!baseChild){
            // The node doesn't exist in the base file.
            // Modder added a new node. Create it.
            baseNode.append_copy(modChild);
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
                pugi::xml_attribute referenceAttr = referenceNode.attribute(attribute.attribute_name.c_str());
                pugi::xml_attribute childAttr = child.attribute(attribute.attribute_name.c_str());

                if (referenceAttr && childAttr && !strcmp(referenceAttr.value(), childAttr.value())) {
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
                pugi::xml_attribute referenceAttr = referenceNode.attribute(attribute.attribute_name.c_str());
                pugi::xml_attribute childAttr = child.attribute(attribute.attribute_name.c_str());

                if (!referenceAttr || !childAttr || strcmp(referenceAttr.value(), childAttr.value())) {
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

void XMLMerger2::SerializeLevelEntityIDs(fs::path levelPath) {
    pugi::xml_document MissionFile, SerializeFile;
    fs::path missionPath = levelPath / "mission_mission0.xml";
    fs::path serializePath = levelPath / "serialize.xml";
    auto missionResult = MissionFile.load_file(missionPath.wstring().c_str());
    auto serializeResult = SerializeFile.load_file(serializePath.wstring().c_str());
    if (!missionResult || !serializeResult) {
        std::cerr << "Failed to load mission or serialize file" << std::endl;
        return;
    }
    std::map <int32_t, pugi::xml_node> entityIDs;
//    std::map <int32_t, pugi::xml_node> serializedIDs;
    std::vector<pugi::xml_node> conflictingEntities;
    auto entityList = MissionFile.first_child().child("Objects");
    for(auto & entity :entityList.children("Entity")){
        if(entity.attribute("EntityId")){
//            Check if the entity id is already in the set
            if(entityIDs.find(entity.attribute("EntityId").as_int()) != entityIDs.end()){
                conflictingEntities.emplace_back(entity);
                continue;
            }
            entityIDs.emplace(entity.attribute("EntityId").as_int(), entity);
        }
    }
    // set id to the last element in the set + 1
    int32_t id = entityIDs.rbegin()->first + 1;

    // fix conflicting entities by making them the next available ID in the set, i.e. the last element + 1
    for(auto & entity : conflictingEntities){
        entity.attribute("EntityId").set_value(id);
        entityIDs.emplace(id, entity);
        id++;
    }
    // write the new entity IDs to the serialize file
    auto serializeEntityList = SerializeFile.first_child();
    serializeEntityList.remove_children();
    for (auto& entity: entityIDs){
        serializeEntityList.append_child("Entity").append_attribute("id").set_value(entity.first);
    }

    // write the new entity IDs to the mission file
    MissionFile.save_file(missionPath.wstring().c_str());
    SerializeFile.save_file(serializePath.wstring().c_str());
}

std::vector<std::pair<std::string, std::string>> XMLMerger2::ParseSiblingQuery(std::string_view query)
{
    std::vector<std::pair<std::string, std::string>> result;
    size_t nextSemicol = 0;

    if (query.empty())
        return result;

    do
    {
        size_t prevSemicol = nextSemicol;
        nextSemicol = query.find(';', prevSemicol);
        std::string_view substr = query.substr(prevSemicol, nextSemicol - prevSemicol);

        if (nextSemicol != std::string_view::npos)
            nextSemicol++;

        size_t eqPos = substr.find('=');
        if (eqPos == std::string_view::npos)
            throw std::runtime_error("Missing = in query");

        std::string_view key = substr.substr(0, eqPos);
        std::string_view value = substr.substr(eqPos + 1);
        result.push_back({ std::string(key), std::string(value) });
    } while (nextSemicol != std::string_view::npos);

    return result;
}

void XMLMerger2::VerifyNotCopySibling(pugi::xml_node baseNode, pugi::xml_node modNode)
{
    if (modNode.attribute(COPY_SIBLING))
    {
        std::stringstream ss;
        ss << "Cannot " << COPY_SIBLING << ": node with the ID already exists.\n";
        ss << "Mod node:\n";
        modNode.print(ss);
        ss << "\nExisting node:\n";
        baseNode.print(ss);
        throw std::runtime_error(ss.str());
    }
}


