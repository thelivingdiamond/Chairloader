//
// Created by theli on 9/10/2022.
//

#include "XMLMerger.h"
#include "ChairManager.h"
#include <boost/algorithm/string.hpp>
#include <sstream>
// import regex
#include <regex>

XMLMerger::XMLMerger() {

}

MergingPolicy XMLMerger::getFileMergingPolicy(fs::path filePath, std::string modName) {
    MergingPolicy policy;
    auto root = mergingLibrary.child("root");
    policy = MergingPolicy(root.child("MergingPolicy"), filePath, modName);
    auto currentNode = root;
    fs::path currentPath;
    for (auto &directory : filePath){
        if(!fs::exists("PreyFiles" / currentPath / directory)){
            break;
        }
        currentPath /= directory;
        currentNode = noCaseChild(currentNode, directory.u8string());
        if(!currentNode){
            continue;
        } else {
            if(currentNode.child("MergingPolicy")){
                policy = MergingPolicy(currentNode.child("MergingPolicy"), filePath, modName);
            }
        }
    }
    if  (currentPath != filePath){
        // File is not in the library, so it must be novel
        ChairManager::Get().log(severityLevel::error, "XMLMerger: File %s not found in merging library", filePath.u8string());
        policy.policy = MergingPolicy::identification_policy::unknown;
        policy.attributeMatches.clear();
        policy.nodeStructure = pugi::xml_node();
    }
    return policy;
}



void XMLMerger::init() {
    auto result = mergingLibrary.load_file("MergingLibrary.xml");
    if(!result) {
       ChairManager::Get().overlayLog(severityLevel::fatal, "Failed to load MergingLibrary.xml: %s", result.description());
    } else {
        ChairManager::Get().log(severityLevel::info, "Merging Library Loaded");
    }
}

void XMLMerger::mergeXMLNodeAttributes(pugi::xml_node &baseNode, pugi::xml_node &modNode) {
    for(auto &overrideAttribute : modNode.attributes()){
        if(!baseNode.attribute(overrideAttribute.name())){
            baseNode.append_attribute(overrideAttribute.name()) = overrideAttribute.value();
        } else {
            baseNode.attribute(overrideAttribute.name()) = overrideAttribute.value();
        }
    }
}



void XMLMerger::mergeXMLNode(pugi::xml_node &baseNode, pugi::xml_node &modNode) {
    if(modNode.attribute("ch:remove").as_bool()) {
        baseNode.parent().remove_child(baseNode);
        return;
    } else {
        if(modNode.attribute("ch:patch_mode").as_bool()) {
            baseNode.remove_attribute("ch:patch_mode");
            patchXMLNode(baseNode, modNode);
            return;
        }
        // copy all attributes from mod node to base node
        mergeXMLNodeAttributes(baseNode, modNode);
        // copy contents
        baseNode.remove_children();
        baseNode.text().set(modNode.text().get());
        for (auto &child: modNode.children()) {
            baseNode.append_copy(child);
        }
    }
}


bool XMLMerger::mergeXMLFile(fs::path relativeFilePath, std::string modName, bool isLegacyMod) {
    pugi::xml_document baseFile;
    pugi::xml_document modFile;
    pugi::xml_document originalFile;
    pugi::xml_parse_result modResult;
    if(isLegacyMod) {
        modResult = modFile.load_file((ChairManager::Get().GetGamePath() / "Mods" / "Legacy" / modName / relativeFilePath).wstring().c_str());
    } else {
        modResult = modFile.load_file((ChairManager::Get().GetGamePath() / "Mods" / modName / "Data" / relativeFilePath).wstring().c_str());
    }

    auto originalResult = originalFile.load_file(("PreyFiles" / relativeFilePath).wstring().c_str());
    if(!modResult){
        ChairManager::Get().log(severityLevel::error, "Failed to load mod file %s: %s", (ChairManager::Get().GetGamePath() / "Mods" / modName / "Data" / relativeFilePath).u8string().c_str(), modResult.description());
        return false;
    }
    // this is overwriting the original file, so check if we need to copy to output directory

    if (originalResult) {
        try {
            if (!fs::exists("Output" / relativeFilePath)) {
                fs::create_directories("Output" / relativeFilePath.parent_path());
                fs::copy_file("PreyFiles" / relativeFilePath, "Output" / relativeFilePath,
                              fs::copy_options::overwrite_existing);
            }
        } catch(std::exception &e){
            ChairManager::Get().log(severityLevel::error, "Failed to copy original file %s: %s", ("PreyFiles" / relativeFilePath).u8string().c_str(), e.what());
            return false;
        }
    } else {
        //TODO: allow mods to define merging policies for novel files
        //- original file doesn't exist, so we can't merge. if file exists already we *have* to overwrite
        try {
            fs::copy_file((ChairManager::Get().GetGamePath() / "Mods" / modName / relativeFilePath),
                          "Output" / relativeFilePath,
                          fs::copy_options::overwrite_existing);
        } catch(std::exception &e){
            ChairManager::Get().log(severityLevel::error, "Failed to copy mod file %s: %s", (ChairManager::Get().GetGamePath() / "Mods" / modName / relativeFilePath).u8string().c_str(), e.what());
            return false;
        }
    }
    // load base file after potentially copying original file
    auto baseResult = baseFile.load_file(("Output" / relativeFilePath).wstring().c_str());
    // if the file exists in the output directory, we can merge
    if(baseResult) {
        auto policy = getFileMergingPolicy(relativeFilePath, modName);
        if(policy.policy == MergingPolicy::identification_policy::unknown){
            ChairManager::Get().log(severityLevel::error, "File %s was loaded as default game file but is not in the merging library, and no merging policy was defined for it", relativeFilePath.u8string());
            return false;
        // if policy is error, error out
        } else if (policy.policy == MergingPolicy::identification_policy::error) {
            ChairManager::Get().log(severityLevel::error,
                                    "File %s has an invalid merging policy, and cannot be merged",
                                    relativeFilePath.u8string());
            return false;
        }
        resolvePathWildcards(modFile.first_child(), policy.nodeStructure.first_child());
        //TODO: WIP
        auto tempModFirstChild = modFile.first_child();
        auto tempNodeStructureFirstChild = policy.nodeStructure.first_child();
//        if(!isLegacyMod) {
            auto nodesToDelete = resolveAttributeWildcards(tempModFirstChild, tempNodeStructureFirstChild, policy.mod_name);
            for (auto &node : nodesToDelete) {
                node.parent().remove_child(node);
            }
//        }
//        ModLoader::Get().log(ModLoader::severityLevel::debug, "Merging %s", relativeFilePath.u8string().c_str());
        return mergeXMLDocument(baseFile, modFile, originalFile, policy);
    } else {
        ChairManager::Get().log(severityLevel::error, "Failed to load base file %s: %s", ("Output" / relativeFilePath).u8string().c_str(), baseResult.description());
        return false;
    }
    return false;
}


// at this point we know that we have 3 valid xml files, and that they have a known policy. We must now merge them
bool XMLMerger::mergeXMLDocument(pugi::xml_document &baseDoc, pugi::xml_document &modDoc, pugi::xml_document &originalDoc, MergingPolicy policy) {
    if(policy.policy == MergingPolicy::identification_policy::unknown || policy.policy == MergingPolicy::identification_policy::overwrite){
        ChairManager::Get().log(severityLevel::error, "Invalid merging policy for XML file %s", policy.file_path.u8string().c_str());
        return false;
    }
    if(policy.policy == MergingPolicy::identification_policy::overwrite){
        // overwrite the base file with the mod file, regardless of original file
        baseDoc.reset(modDoc);
        auto result = baseDoc.save_file(("Output" / policy.file_path).wstring().c_str());
//        ModLoader::Get().log(ModLoader::severityLevel::trace, "Saved file %s: %s", ("Output" / policy.file_path).u8string().c_str(), result ? "success" : "failure");

        return true;
    }
    if(policy.policy == MergingPolicy::identification_policy::match_spreadsheet){
        auto baseNode = baseDoc.first_child();
        baseNode.prepend_child(pugi::node_comment).set_value((std::string("Chairloader: merged from mod ") + policy.mod_name).c_str());
        auto modNode = modDoc.first_child();
        auto originalNode = originalDoc.first_child();
        mergeBySpreadsheet(baseNode, modNode, originalNode, policy);
        auto result = baseDoc.save_file(("Output" / policy.file_path).wstring().c_str());
        bool success = result;
        ChairManager::Get().log(severityLevel::trace, "Saved file %s: %s", ("Output" / policy.file_path).u8string().c_str(), success ? "success" : "failure");
        return true;
    }
    // now we have to merge the node structure of the mod file with the base file
    auto baseNode = baseDoc.first_child();
    auto modNode = modDoc.first_child();
    auto originalNode = originalDoc.first_child();
    // append a comment into the file
    baseNode.prepend_child(pugi::node_comment).set_value((std::string("Chairloader: merged from mod ") + policy.mod_name).c_str());
    if(mergeNodeStructure(baseNode, modNode, originalNode, policy)){
        baseDoc.save_file(("Output" / policy.file_path).wstring().c_str());
        return true;
    } else {
        ChairManager::Get().log(severityLevel::error, "Failed to merge node structure for XML file %s", policy.file_path.u8string().c_str());
        return false;
    }
}


// at this point we have 3 nodes with valid paths and valid wildcards, a policy, and no need to overwrite. We must now recursively merge the nodes and determine policies for each node if necessary
bool XMLMerger::mergeNodeStructure(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy) {
    for(auto & node: policy.nodeStructure.children()){
        // children = nodes on our way to merge the actual content nodes
        pugi::xml_node baseChild, modChild, originalChild;
        if(std::string(baseNode.name()) == node.name()){
            baseChild = baseNode;
        } else {
            baseChild = baseNode.child(node.name());
        }
        if(std::string(modNode.name()) == node.name()){
            modChild = modNode;
        } else {
            modChild = modNode.child(node.name());
        }
        if(std::string(originalNode.name()) == node.name()){
            originalChild = originalNode;
        } else {
            originalChild = originalNode.child(node.name());
        }
        if(!baseChild || !modChild || !originalChild){
            // no children exist, which is an error
            if(!modChild && baseChild && originalChild){
//                ModLoader::Get().log(ModLoader::severityLevel::debug, "Mod file %s has no child node %s", policy.file_path.u8string().c_str(), node.name());
                continue;
            }
            ChairManager::Get().log(severityLevel::error, "Node %s does not exist in any of the files", node.name());
            break;
        }

        auto localPolicy = policy; // copy policy so we can modify it for each node
        localPolicy.nodePath /= node.name(); // TODO: rethink node path
        localPolicy.nodeStructure = node;
        MergingPolicy::node_tags nodeTags = MergingPolicy::getNodeTags(node);

        // check if this node overrides the policy
        if (nodeTags & MergingPolicy::node_tags::override_policy){
            localPolicy.policy = MergingPolicy::parsePolicy(node.attribute("identification_policy").value());
            localPolicy.attributeMatches.clear();
            if(localPolicy.policy == MergingPolicy::identification_policy::match_attribute){
                for(auto &attributeNode : node.children("attribute")){
                    localPolicy.attributeMatches.emplace_back(MergingPolicy::attributeMatch{attributeNode.attribute("name").as_string(), attributeNode.attribute("priority").as_int()});
                }
                localPolicy.match_all_attributes = nodeTags & MergingPolicy::node_tags::match_all;
            }
        }
        // check if node needs to merge attributes
        if(nodeTags & MergingPolicy::node_tags::merge_attributes){
            mergeXMLNodeAttributes(baseChild, modChild);
        }

        // merge children is a leaf node tag, so it must end the recursion
        if(nodeTags & MergingPolicy::node_tags::merge_children) {
            switch(localPolicy.policy){
                //overwrite = identical to merge_node
                case MergingPolicy::identification_policy::overwrite:
                    ChairManager::Get().log(severityLevel::warning, "XMLMerger: merge_node should be used instead of merge_children & overwrite policy");
                    break;
                // unknown should never be passed into a mergeNodeStructure call
                case MergingPolicy::identification_policy::match_spreadsheet:
                    ChairManager::Get().log(severityLevel::error, "XMLMerger: match_spreadsheet policy should never be passed into a mergeNodeStructure call");
                    break;
                case MergingPolicy::identification_policy::unknown:
                case MergingPolicy::identification_policy::error:
                    ChairManager::Get().log(severityLevel::error, "XMLMerger: Invalid merging policy passed to mergeNodeStructure");
                    break;
                case MergingPolicy::identification_policy::match_attribute:
                    mergeByAttribute(baseChild, modChild, originalChild, localPolicy);
                    break;
                case MergingPolicy::identification_policy::match_tag:
                    mergeByTag(baseChild, modChild, originalChild, localPolicy);
                    break;
                case MergingPolicy::identification_policy::match_contents:
                    mergeByContents(baseChild, modChild, originalChild, localPolicy);
                    break;
            }
            continue;
        }

        // merge node for one off nodes that need to be merged
        if(nodeTags & MergingPolicy::node_tags::merge_node){
            if(!checkNodeEquality(modChild, originalChild)) {
                mergeXMLNode(baseChild, modChild);
            } else {
                ChairManager::Get().log(severityLevel::trace, "Node %s is identical to original, skipping", node.name());
            }
        }

        // if we haven't reached a leaf node, we must recurse a level down
        if(!node.children().empty())
            mergeNodeStructure(baseChild, modChild, originalChild, localPolicy);
    }
    return true;
}

void XMLMerger::mergeByAttribute(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy) {
    for(auto & modChild : modNode.children()) {
        bool overwrite = false;
        bool matchAll = true;
        pugi::xml_node baseChild, originalChild;
        for(auto &AttributeMatch: policy.attributeMatches) {
            if(baseNode.find_child_by_attribute(AttributeMatch.attribute_name.c_str(), modChild.attribute(AttributeMatch.attribute_name.c_str()).value()))
                baseChild = baseNode.find_child_by_attribute(AttributeMatch.attribute_name.c_str(), modChild.attribute(AttributeMatch.attribute_name.c_str()).value());

            if(originalNode.find_child_by_attribute(AttributeMatch.attribute_name.c_str(), modChild.attribute(AttributeMatch.attribute_name.c_str()).value()))
                originalChild = originalNode.find_child_by_attribute(AttributeMatch.attribute_name.c_str(), modChild.attribute(AttributeMatch.attribute_name.c_str()).value());
            // case matchAll
            if (baseChild) {
                if (std::string(modChild.attribute(AttributeMatch.attribute_name.c_str()).value()) != baseChild.attribute(AttributeMatch.attribute_name.c_str()).value()) {
                    matchAll = false;
                    continue;
                }
                overwrite = true;
            }
        }
        // we found a match, so overwrite
        if(overwrite && (matchAll || !policy.match_all_attributes)){
            if(!checkNodeEquality(modChild, originalChild)) {
                mergeXMLNode(baseChild, modChild);
//                ModLoader::Get().log(ModLoader::severityLevel::trace, "Node %s matched by attribute, overwriting", modChild.name());
            } else {
//                ModLoader::Get().log(ModLoader::severityLevel::trace, "Node %s is identical to original, skipping", modChild.name());
            }
        // no match, so append
        } else {
            baseNode.append_copy(modChild);
//            ModLoader::Get().log(ModLoader::severityLevel::trace, "Node %s appended to base %s", modChild.name(), baseNode.name());
        }
    }
}

void XMLMerger::mergeByTag(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy) {
   for(auto &child : modNode){
        pugi::xml_node baseChild, originalChild;
        if(baseNode.child(child.name())) {
            baseChild = baseNode.child(child.name());
        }
        if(originalNode.child(child.name())) {
            originalChild = originalNode.child(child.name());
        }
        if(baseChild){
            if(!checkNodeEquality(child, originalChild)) {
                mergeXMLNode(baseChild, child);
//                ModLoader::Get().log(ModLoader::severityLevel::trace, "Node %s merged into base %s", child.name(), baseNode.name());
            } else {
//                ModLoader::Get().log(ModLoader::severityLevel::trace, "Node %s is identical to original, skipping", child.name());
            }
        } else {
            baseNode.append_copy(child);
//            ModLoader::Get().log(ModLoader::severityLevel::trace, "Node %s appended to base %s", child.name(), baseNode.name());
        }
   }
}

void XMLMerger::mergeByContents(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy) {
    for(auto & modChild :modNode) {
        pugi::xml_node baseChild, originalChild;
        for(auto &searchChild : baseNode) {
            if(std::string(baseChild.text().get()) == std::string(modChild.text().get())) {
                baseChild = searchChild;
                break;
            }
        }
        for(auto &searchChild : originalNode) {
            if(std::string(originalChild.text().get()) == std::string(modChild.text().get())) {
                originalChild = searchChild;
                break;
            }
        }
        if(baseChild){
            if(!checkNodeEquality(modChild, originalChild)) {
                mergeXMLNode(baseChild, modChild);
//                ModLoader::Get().log(ModLoader::severityLevel::trace, "Node %s merged into base %s", modChild.name(), baseNode.name());
            } else {
//                ModLoader::Get().log(ModLoader::severityLevel::trace, "Node %s is identical to original, skipping", modChild.name());
            }
        } else {
            baseNode.append_copy(modChild);
//            ModLoader::Get().log(ModLoader::severityLevel::trace, "Node %s appended to base %s", modChild.name(), baseNode.name());
        }
    }
}

void
XMLMerger::mergeBySpreadsheet(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, MergingPolicy policy) {
    //TODO: implement
    //- debug the names of the nodes passed in
//    ModLoader::Get().log(ModLoader::severityLevel::debug, "baseNode: %s", baseNode.name());
//    ModLoader::Get().log(ModLoader::severityLevel::debug, "modNode: %s", modNode.name());
//    ModLoader::Get().log(ModLoader::severityLevel::debug, "originalNode: %s", originalNode.name());
//    // warn user that this isn't implemented yet
//    ModLoader::Get().log(ModLoader::severityLevel::warning, "Spreadsheet merging is not yet implemented, skipping");
    auto modTableNode = modNode.child("Worksheet").child("Table");
    auto baseTableNode = baseNode.child("Worksheet").child("Table");
    auto originalTableNode = originalNode.child("Worksheet").child("Table");
    // cache the base and original nodes in an std::map
    std::map<std::string, pugi::xml_node> baseNodes;
    std::map<std::string, pugi::xml_node> originalNodes;
    for(auto &baseRow : baseTableNode.children("Row")) {
        baseNodes[baseRow.child("Cell").child("Data").text().get()] = baseRow;
    }
    for(auto &originalRow : originalTableNode.children("Row")) {
        originalNodes[originalRow.child("Cell").child("Data").text().get()] = originalRow;
    }

    for(auto & modRow : modTableNode.children("Row")){
        auto key = modRow.child("Cell").child("Data").text().get();
        // check for original and base child
        if(key != "") {
            pugi::xml_node originalCandidate, baseCandidate;
            if (originalNodes.find(key) != originalNodes.end()) {
                originalCandidate = originalNodes[key];
            }
            if (baseNodes.find(key) != baseNodes.end()) {
                baseCandidate = baseNodes[key];
            }
            if (baseCandidate && originalCandidate) {
                if (!checkNodeEquality(modRow, originalCandidate)) {
                    baseCandidate.remove_children();
                    for (auto &child: modRow) {
                        baseCandidate.append_copy(child);
                    }
//                mergeXMLNode(baseCandidate, modRow);
//                    ModLoader::Get().log(ModLoader::severityLevel::trace, "Row with key %s merged", key);
                } else {
//                    ModLoader::Get().log(ModLoader::severityLevel::trace, "Row with key %s is identical to original, skipping", key);
                }
            } else {
                // append the row
                baseTableNode.append_copy(modRow);
//                ModLoader::Get().log(ModLoader::severityLevel::trace, "Row with key %s appended", key);
            }
        }
    }
}



//TODO: resolve deeper wildcards
void XMLMerger::resolvePathWildcards(pugi::xml_node node, pugi::xml_node nodeStructure){
    // replace wildcard in node path
    if(nodeStructure.name() == std::string("_wildcard_")){
        if(node.name() != std::string("")) {
            nodeStructure.set_name(node.name());
        } else {
            ChairManager::Get().log(severityLevel::error, "XMLMerger: cannot replace wildcard node: corresponding node has no name");
        }
    }
    // recurse until a leaf node is reached
    if(nodeStructure.first_child()){
        resolvePathWildcards(node.first_child(), nodeStructure.first_child());
    }
}

std::vector<pugi::xml_node>
XMLMerger::resolveAttributeWildcards(pugi::xml_node &node, pugi::xml_node &nodeStructure, std::string &modName) {
    //TODO: allow
    /*
    <X Param="{{ configValue }}" /> <!-- Current mod's config -->
    <X Param="{{ $.modAuthor.modName.configValue }}"/> <!-- Reference a different mod. modAuthor.modName is actually "modName" from ModInfo.xml. $ is like some global object -->
    <X ch:apply_if="$.modAuthor.modName.modEnabled" /> <!-- Check if different mod is installed and enabled. Allows for some basic interop between XML mods -->
    <X ch:apply_if="{{ configValue }}"/> <!-- apply if some other config value -->
     */
//    if(MergingPolicy::getNodeTags(nodeStructure) & MergingPolicy::node_tags::merge_children){
    std::vector<pugi::xml_node> nodesToDelete;
    for (auto child: node) {
//        ModLoader::Get().log(ModLoader::severityLevel::trace, "Checking child %s", child.name());
        auto childNodesToDelete = resolveAttributeWildcards(child, nodeStructure, modName);
        // emplace all children nodes to delete in nodesToDelete
        for(auto &nodeToDelete : childNodesToDelete){
            nodesToDelete.emplace_back(nodeToDelete);
        }
    }
    for(auto &attribute : node.attributes()){
        AttributeWildcard match;
        match.attribute = attribute;
        match.mod_name = modName;
        getWildcardValue(match);
        if(match.has_match_value){
            if(match.type == AttributeWildcard::wildcard_type::apply_if){
                if(match.apply_if){
                    node.remove_attribute(attribute);
                    ChairManager::Get().log(severityLevel::debug, "Node %s applied by wildcard", node.name());
                } else {
                    nodesToDelete.emplace_back(node);
                }
            } else if (match.type == AttributeWildcard::wildcard_type::replace) {
                attribute.set_value(match.match_value.c_str());
                ChairManager::Get().log(severityLevel::trace, "Attribute %s replaced with %s", attribute.name(), match.match_value);
            }

        }
    }
    return nodesToDelete;
}

//! check if contents and attributes match
bool XMLMerger::checkNodeEquality(pugi::xml_node modNode, pugi::xml_node originalNode){
    // check if node contents match
    std::stringstream originalContent, overrideContent;
    originalNode.print(originalContent);
    modNode.print(overrideContent);
    return std::string(originalContent.str()) == std::string(overrideContent.str());

//    // check if attributes match
//    for(auto &attribute : modNode.attributes()){
//        if(std::string(attribute.as_string()) != originalNode.attribute(attribute.name()).as_string()){
//            return false;
//        }
//    }
//    return true;

}

std::string XMLMerger::getWildcardValue(AttributeWildcard &wildcardValue) {
//    ModLoader::Get().log(ModLoader::severityLevel::trace, "Checking attribute %s", wildcardValue.attribute.name());
    if(wildcardValue.attribute.name() == std::string("ch:apply_if")){
        wildcardValue.type = attributeWildcard::wildcard_type::apply_if;
    } else {
        wildcardValue.type = AttributeWildcard::wildcard_type::replace;
    }
    if(std::string(wildcardValue.attribute.value()).find("{{") != std::string::npos && std::string(wildcardValue.attribute.value()).find("}}") != std::string::npos) {
        // regex to find the value
        std::regex re(R"(\{\{(.*)\}\})");
        std::smatch match;
        std::string value = wildcardValue.attribute.value();
        if(std::regex_search(value, match, re)) {
            if(match.ready()) {
                auto wildcardName = match[1].str();
                // remove spaces from wildcardName
                wildcardName.erase(std::remove_if(wildcardName.begin(), wildcardName.end(), isspace), wildcardName.end());
                ChairManager::Get().log(severityLevel::debug, "Found match: %s", wildcardName.c_str());
                if(wildcardName[0] == '$') {
                    // this means we will be looking for global values from other mods
                    std::regex localMatch = std::regex(R"((.*).(.*))");
                    std::smatch localMatchResult;
                    if(std::regex_search(wildcardName, localMatchResult, localMatch)) {
                        if(localMatchResult.ready()) {
                            std::string modName = localMatchResult[1].str();
                            std::string parameter = localMatchResult[2].str();
                            ChairManager::Get().log(severityLevel::debug, "Found local match: %s, %s", modName.c_str(), parameter.c_str());
                            if(parameter == "modEnabled"){
                                wildcardValue.match_value = ChairManager::Get().IsModEnabled(modName) ? "true" : "false";
                            } else {
                                auto modConfig = ChairManager::Get().GetConfigManager()->getModConfig(modName);
                                wildcardValue.match_value = modConfig.getConfigValue(parameter);
                                wildcardValue.has_match_value = true;
                                if(wildcardValue.match_value.empty()) {
                                    ChairManager::Get().log(severityLevel::error, "XMLMerger: could not find config value %s in mod %s", parameter.c_str(), modName.c_str());
                                }
                            }
                        }
                    }
                } else {
                    // this means we will be looking for values from the current mod
                    wildcardValue.match_value = ChairManager::Get().GetConfigManager()->getModConfig(wildcardValue.mod_name).getConfigValue(wildcardName);
                    if(!wildcardValue.match_value.empty()) {
                        wildcardValue.has_match_value = true;
                    } else {
                        ChairManager::Get().log(severityLevel::error, "XMLMerger: could not find config value %s in mod %s", wildcardName.c_str(), wildcardValue.mod_name.c_str());
                    }
                }

                if(wildcardValue.type == AttributeWildcard::wildcard_type::apply_if){
                    if(wildcardValue.match_value == "true"){
                        wildcardValue.apply_if = true;
                    } else if(wildcardValue.match_value == "false"){
                        wildcardValue.apply_if = false;
                    }
                }
                return wildcardValue.match_value;
            }
        } else {
            ChairManager::Get().log(severityLevel::warning, "Could not find wildcard value in %s", wildcardValue.attribute.value());
            wildcardValue.type = AttributeWildcard::wildcard_type::none;
        }
    } else {
        wildcardValue.type = AttributeWildcard::wildcard_type::none;
//        ModLoader::Get().log(ModLoader::severityLevel::trace, "Not a wildcard value");
    }
    return {};
}

void XMLMerger::patchXMLNode(pugi::xml_node &baseNode, pugi::xml_node &modNode) {
    // recursively go through the mod and mergeXML Attributes
    mergeXMLNodeAttributes(baseNode, modNode);
    for(auto &modChild : modNode.children()){
        // check if the child exists in the base node
        auto baseChild = baseNode.child(modChild.name());
        if(baseChild){
            // if it does, recursively call this function
            patchXMLNode(baseChild, modChild);
        }
    }
}


