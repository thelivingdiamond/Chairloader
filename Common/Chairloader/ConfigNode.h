//
// Created by theli on 4/25/2025.
//

#ifndef CHAIRLOADER_CONFIGNODE_H
#define CHAIRLOADER_CONFIGNODE_H

#include <optional>
#include <stdexcept>
#include <variant>

enum class NodeType { String, Bool, Int, Uint, Int64, Uint64, Float, XmlNode, Enum, Unknown };

inline NodeType toNodeType(std::string_view s) {
    if      (s=="string")   return NodeType::String;
    else if (s=="bool")     return NodeType::Bool;
    else if (s=="int")      return NodeType::Int;
    else if (s=="uint")     return NodeType::Uint;
    else if (s=="int64")    return NodeType::Int64;
    else if (s=="uint64")   return NodeType::Uint64;
    else if (s=="float")    return NodeType::Float;
    else if (s=="xmlnode")  return NodeType::XmlNode;
    else if (s=="enum")     return NodeType::Enum;
    else                    return NodeType::Unknown;
}

inline std::string toString(NodeType type) {
    switch(type) {
        case NodeType::String:   return "string";
        case NodeType::Bool:     return "bool";
        case NodeType::Int:      return "int";
        case NodeType::Uint:     return "uint";
        case NodeType::Int64:    return "int64";
        case NodeType::Uint64:   return "uint64";
        case NodeType::Float:    return "float";
        case NodeType::XmlNode:  return "xmlnode";
        case NodeType::Enum:     return "enum";
        default:                 return "unknown";
    }
}


class ConfigNode {
public:
    typedef std::variant<int, unsigned int, float, bool, int64_t, uint64_t, std::string, pugi::xml_node> ValueType;

    ConfigNode(pugi::xml_node node)
    : m_node(node)
    {
        if(m_node){
            m_name = m_node.name();
            m_displayName = m_node.attribute("displayName").as_string();
            m_description = m_node.attribute("description").as_string();
            m_type = m_node.attribute("type").as_string();
            m_nodeType = toNodeType(m_type);
        }
        else {
            m_name = "";
            m_displayName = "";
            m_description = "";
            m_type = "";
            m_nodeType = NodeType::XmlNode;
        }
    }

    ConfigNode() : m_node() {
        m_name = "";
        m_displayName = "";
        m_description = "";
        m_type = "";
        m_nodeType = NodeType::XmlNode;
    }

    ConfigNode operator[](const char* name) {
        return ConfigNode(m_node.child(name));
    }

    ConfigNode get(const char* name) {
        return ConfigNode(m_node.child(name));
    }

    bool exists() const {
        return m_node;
    }

    NodeType type() const {
        return m_nodeType;
    }

    std::string name() const {
        return m_name;
    }

    std::string displayName() const {
        return m_displayName;
    }

    std::string description() const {
        return m_description;
    }

    pugi::xml_node raw() const {
        return m_node;
    }

    template<typename T>
    T as() const {
        if(!m_node) {
            throw std::runtime_error("Node does not exist");
        }
        if(m_nodeType == NodeType::Enum){
            return ConfigNode(m_node.child("selected")).as<T>();
        } else {
            return getValue<T>(m_node);
        }
    }

    /**
     * Get the value of the node with a default value if the node is not found.
     * @return The value of the node or the default value if the node does not exist or is not of the expected type.
     */
    template<typename T>
    T asOr(T defaultValue) const noexcept{
        try {
            if(m_nodeType == NodeType::Enum){
                return ConfigNode(m_node.child("selected")).asOr<T>(defaultValue);
            }
            return exists() ? getValue<T>(m_node) : defaultValue;
        } catch (...) {
            return defaultValue;
        }
    }

    /**
     * Get the value of the node as an optional. If the node does not exist, an empty optional is returned.
     * @return The value of the node as an optional.
     */
    template<typename T>
    std::optional<T> maybe() const noexcept {
        if(!exists()) return std::nullopt;
        try {
            if(m_nodeType == NodeType::Enum){
                return ConfigNode(m_node.child("selected")).maybe<T>();
            } else {
                return getValue<T>(m_node);
            }
        } catch (...) {
            return std::nullopt;
        }
    }

    /**
     * Set the value of the node. If the node does not exist, an exception is thrown.
     *
     * Note: does not actually save the value to the XML file, just sets the value in memory.
     * @param value The value to set.
     */
    template<typename T>
    void set(const T& value) {
        if(!m_node) {
            throw std::runtime_error("Node does not exist");
        }

        if (m_nodeType == NodeType::Enum) {
            ConfigNode(m_node.child("selected")).set(value);
            return;
        }
        m_node.text().set(value);
    }

    /**
     * Returns the value of the node as determined by the type set in the XML file.
     * @param value The value to set.
     */
    std::optional<ValueType> value() const {
        if(!m_node) {
            return std::nullopt;
        }
        switch(m_nodeType) {
            case NodeType::String:   return m_node.text().as_string();
            case NodeType::Bool:     return m_node.text().as_bool();
            case NodeType::Int:      return m_node.text().as_int();
            case NodeType::Uint:     return m_node.text().as_uint();
            case NodeType::Int64:    return m_node.text().as_llong();
            case NodeType::Uint64:   return m_node.text().as_ullong();
            case NodeType::Float:    return m_node.text().as_float();
            case NodeType::Enum:     return m_node.child("selected").text().as_string();
            case NodeType::XmlNode:  return m_node;
            default:                 return std::nullopt;
        }
    }


private:
    template<typename T> static T getValue(pugi::xml_node node);

    pugi::xml_node m_node;
    std::string m_name;
    std::string m_displayName;
    std::string m_description;
    std::string m_type;
    NodeType m_nodeType;

};

template<> inline int ConfigNode::getValue<int>(pugi::xml_node node) { return node.text().as_int(); }
template<> inline unsigned int ConfigNode::getValue<unsigned int>(pugi::xml_node node) { return node.text().as_uint(); }
template<> inline int64_t ConfigNode::getValue<int64_t>(pugi::xml_node node) { return node.text().as_llong(); }
template<> inline uint64_t ConfigNode::getValue<uint64_t>(pugi::xml_node node) { return node.text().as_ullong(); }
template<> inline float ConfigNode::getValue<float>(pugi::xml_node node) { return node.text().as_float(); }
template<> inline std::string ConfigNode::getValue<std::string>(pugi::xml_node node) { return node.text().as_string(); }
template<> inline bool ConfigNode::getValue<bool>(pugi::xml_node node) { return node.text().as_bool(); }
template<> inline pugi::xml_node ConfigNode::getValue<pugi::xml_node>(pugi::xml_node node) { return node; }
#endif //CHAIRLOADER_CONFIGNODE_H
