//
// Created by theli on 9/10/2022.
//
#pragma once

class XMLMerger {
public:
    struct mergingPolicy{
        enum node_tags {
            none = 0,
            merge_children = 1 << 1,
            merge_attributes = 1 << 2,
            merge_node = 1 << 3,
            match_all = 1 << 4,
            override_policy = 1 << 5,
        };
        enum class identification_policy{
            overwrite, //!(default): will not do any merging, instead overwriting files in the directory
            match_attribute, //! will merge nodes by matching attribute values
            match_tag, //! will merge nodes by matching tag values
            match_contents, //! will merge nodes by matching the text contents of a node
            match_spreadsheet, //! a specialized version of merge detection for Excel spreadsheet xml files
            unknown, //! no policy has been set, but there is no error. if the file in the mod is not in the base game, this policy will be set. Functionally equivalent to overwrite
            error, //! FUCK
        };
        struct attributeMatch {
            std::string attribute_name;
            int priority;
        };
        fs::path file_path;
        identification_policy policy = identification_policy::unknown;
        std::vector<attributeMatch> attributeMatches;
        pugi::xml_node nodeStructure;
    private:
        std::shared_ptr<pugi::xml_document> nodeDoc;
    public:
        bool match_all_attributes = false,
        wildcard = false;
        fs::path nodePath;
        std::string mod_name;
        mergingPolicy() = default;
        mergingPolicy& operator=(const mergingPolicy& other){
            file_path = other.file_path;
            policy = other.policy;
            attributeMatches = other.attributeMatches;
            nodeDoc = other.nodeDoc;
            mod_name = other.mod_name;
            nodeStructure = other.nodeStructure;
            return *this;
        }
        mergingPolicy(const mergingPolicy& other) {
            file_path = other.file_path;
            policy = other.policy;
            attributeMatches = other.attributeMatches;
            nodeDoc = other.nodeDoc;
            mod_name = other.mod_name;
            nodeStructure = other.nodeStructure;
        }
//        mergingPolicy(fs::path path, identification_policy policy, std::vector<attributeMatch> attributeMatches, pugi::xml_node nodeStructure) {
//            file_path = path;
//            policy = policy;
//            attributeMatches = attributeMatches;
//            nodeDoc = std::make_shared<pugi::xml_document>();
//            nodeStructure = nodeStructure;
//        }
        mergingPolicy(pugi::xml_node node, fs::path path, std::string modName) {
            mod_name = modName;
            file_path = path;
            nodeDoc = std::make_shared<pugi::xml_document>();
            if(node.name() == std::string("mergingPolicy")){
                policy = parsePolicy(node.attribute("identification_policy").as_string());
                if(policy == identification_policy::match_attribute){
                    for(auto attribute : node.children("attribute")){
                        attributeMatch match;
                        match.attribute_name = attribute.attribute("name").as_string();
                        match.priority = attribute.attribute("priority").as_int();
                        attributeMatches.emplace_back(match);
                    }
                }
                nodeDoc->reset();
                auto nodeStructureNode = nodeDoc->append_copy(node.child("nodeStructure"));
                nodeStructure = nodeStructureNode;
            } else {
                policy = identification_policy::error;
            }
        }
        static identification_policy parsePolicy(std::string policyName){
            if(policyName == "overwrite"){
                return identification_policy::overwrite;
            } else if(policyName == "match_attribute"){
                return identification_policy::match_attribute;
            } else if(policyName == "match_tag"){
                return identification_policy::match_tag;
            } else if(policyName == "match_contents"){
                return identification_policy::match_contents;
            } else if(policyName == "match_spreadsheet"){
                return identification_policy::match_spreadsheet;
            } else {
                return identification_policy::error;
            }
        }
        static node_tags getNodeTags(pugi::xml_node node) {
            node_tags tags = node_tags::none;
            if(node.attribute("merge_children").as_bool()) {
                tags = (node_tags)(tags | merge_children);
            }
            if(node.attribute("merge_attributes").as_bool()) {
                tags = (node_tags)(tags | merge_attributes);
            }
            if(node.attribute("merge_node").as_bool()) {
                tags = (node_tags)(tags | merge_node);
            }
            if(node.attribute("match_all").as_bool()) {
                tags = (node_tags)(tags | match_all);
            }
            if(!node.attribute("identification_policy").empty()) {
                tags = (node_tags)(tags | override_policy);
            }
            return tags;
        }
    };
    struct attributeWildcard{
        enum class wildcard_type{
            none,
            apply_if,
            replace,
        };
        enum class match_type{
            none,
            local,
            global,
        };
        pugi::xml_attribute attribute;
        std::string mod_name;
        wildcard_type type = wildcard_type::none;
        match_type match = match_type::none;
        std::string match_value;
        bool has_match_value = false;
        bool apply_if = false;
    };
    XMLMerger();
    void init();
    pugi::xml_document mergingLibrary;
    XMLMerger::mergingPolicy getFileMergingPolicy(fs::path filePath, std::string modName);

    static void resolvePathWildcards(pugi::xml_node node, pugi::xml_node nodeStructure);
    static std::vector<pugi::xml_node>
    resolveAttributeWildcards(pugi::xml_node &node, pugi::xml_node &nodeStructure, std::string &modName);
    static void getConfigWildcard(std::string& wildcard, std::string modName);

    static bool checkNodeEquality(pugi::xml_node modNode, pugi::xml_node originalNode);
    //! merge one node into another. Copy all attributes and children from the source node into the destination node
    bool mergeXMLFile(fs::path relativeFilePath, std::string modName, bool isLegacyMod);
    static bool mergeXMLDocument(pugi::xml_document &baseDoc, pugi::xml_document &modDoc, pugi::xml_document &originalDoc, mergingPolicy policy);
    static bool mergeNodeStructure(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, mergingPolicy policy);
    static void mergeByAttribute(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, mergingPolicy policy);
    static void mergeByTag(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, mergingPolicy policy);
    static void mergeByContents(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, mergingPolicy policy);
    static void mergeBySpreadsheet(pugi::xml_node &baseNode, pugi::xml_node &modNode, pugi::xml_node &originalNode, mergingPolicy policy);
    static void mergeXMLNodeAttributes(pugi::xml_node &baseNode, pugi::xml_node &modNode);
    static void mergeXMLNode(pugi::xml_node &baseNode, pugi::xml_node &modNode);

    static std::string getWildcardValue(attributeWildcard &wildcardValue);
};

pugi::xml_node noCaseChild(pugi::xml_node& node, std::string name);