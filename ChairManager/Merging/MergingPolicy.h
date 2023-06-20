#ifndef CHAIRLOADER_MERGINGPOLICY_H
#define CHAIRLOADER_MERGINGPOLICY_H
#include <pugixml.hpp>
#include <filesystem>

struct MergingPolicy{
    //! tags used to determine when and which operations to perform
    enum node_tags {
        none = 0,
        merge_children = 0x1 << 1,
        merge_attributes = 0x1 << 2,
        merge_node = 0x1 << 3,
        match_all = 0x1 << 4,
        override_policy = 0x1 << 5,
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
    //! a structure used to store which attributes to match during match_attribute
    struct attributeMatch {
        std::string attribute_name;
        int priority;
    };
    fs::path file_path;
    identification_policy policy = identification_policy::unknown;
    std::vector<attributeMatch> attributeMatches;
    pugi::xml_node nodeStructure;
private:
    // keep the pugi document private and only expose the root node
    std::shared_ptr<pugi::xml_document> nodeDoc;
public:
    bool match_all_attributes = false;
    fs::path nodePath;
    std::string mod_name;
    MergingPolicy() = default;
    MergingPolicy& operator=(const MergingPolicy& other){
        file_path = other.file_path;
        policy = other.policy;
        attributeMatches = other.attributeMatches;
        nodeDoc = other.nodeDoc;
        mod_name = other.mod_name;
        nodeStructure = other.nodeStructure;
        match_all_attributes = other.match_all_attributes;
        return *this;
    }
    MergingPolicy(const MergingPolicy& other) {
        file_path = other.file_path;
        policy = other.policy;
        attributeMatches = other.attributeMatches;
        nodeDoc = other.nodeDoc;
        mod_name = other.mod_name;
        nodeStructure = other.nodeStructure;
        match_all_attributes = other.match_all_attributes;
    }
    //! Construct a merging policy
    //! \param node the MergingPolicy pugi::xml_node
    //! \param path the file path of the MergingPolicy
    //! \param modName the name of the mod that the MergingPolicy belongs to
    MergingPolicy(pugi::xml_node node, fs::path path, std::string modName) {
        mod_name = std::move(modName);
        file_path = std::move(path);
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
    //! Parse a string into an identification policy
    //! \param policyName a string containing the name of the policy
    //! \return
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

    //! returns the node tags for a merging policy node based on its attributes
    //! \param node the node to get the tags for
    //! \return
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



#endif //CHAIRLOADER_MERGINGPOLICY_H
