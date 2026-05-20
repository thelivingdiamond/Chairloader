//
// Created by theli on 4/25/2025.
//

#ifndef CHAIRLOADER_CONFIGNODE_H
#define CHAIRLOADER_CONFIGNODE_H

#include <optional>
#include <stdexcept>
#include <variant>

#include "Chairloader/IConfigNodeV1.h"


class ConfigNodeV1 : public IConfigNodeV1 {
public:
    ConfigNodeV1(const pugi::xml_node node): m_node(node) {
    }

    ConfigNodeV1() = default;


    ConfigNodeRef<IConfigNodeV1> Get(const char *name) override {
        return ConfigNodeRef<IConfigNodeV1>(std::make_unique<ConfigNodeV1>(m_node.child(name)));
    }

    ConfigNodeRef<IConfigNodeV1> Create(const char *name, EConfigNodeType type) override {
        if (m_node.child(name)) {
            throw std::runtime_error("Node already exists");
        }
        auto node = m_node.append_child(name);
        node.append_attribute("type") = ToString(type).c_str();
        node.append_child(pugi::node_pcdata).set_value("");
        return ConfigNodeRef<IConfigNodeV1>(std::make_unique<ConfigNodeV1>(node));
    }

    ConfigNodeRef<IConfigNodeV1> GetOrCreate(const char *name, const EConfigNodeType type) override {
        if (m_node.child(name)) {
            return Get(name);
        }
        return Create(name, type);
    }

    bool IsValid() const override {
        return m_node;
    }


    EConfigNodeType GetNodeType() const override {
        return ToNodeType(m_node.attribute("type").as_string());
    }

    std::string GetName() const override {
        return m_node.name();
    }

    std::string GetDisplayName() const override {
        return m_node.attribute("displayName").as_string();
    }

    std::string GetDescription() const override {
        return m_node.attribute("description").as_string();
    }

    pugi::xml_node GetXmlNode() const override {
        return m_node;
    }

    std::optional<ValueType> GetValue() const override {
        if (!m_node) {
            return std::nullopt;
        }
        switch (GetNodeType()) {
            case EConfigNodeType::String: return m_node.text().as_string();
            case EConfigNodeType::Bool: return m_node.text().as_bool();
            case EConfigNodeType::Int: return m_node.text().as_int();
            case EConfigNodeType::Uint: return m_node.text().as_uint();
            case EConfigNodeType::Int64: return m_node.text().as_llong();
            case EConfigNodeType::Uint64: return m_node.text().as_ullong();
            case EConfigNodeType::Float: return m_node.text().as_float();
            case EConfigNodeType::Enum: return m_node.child("selected").text().as_string();
            case EConfigNodeType::XmlNode: return m_node;
            default: return std::nullopt;
        }
    }

    void SetValue(const ValueType &value) override {
        switch (GetNodeType()) {
            case EConfigNodeType::String:
                if (std::holds_alternative<std::string>(value)) {
                    m_node.text().set(std::get<std::string>(value).c_str());
                } else {
                    throw std::runtime_error("Invalid type for String node");
                }
                break;
            case EConfigNodeType::Bool:
                if (std::holds_alternative<bool>(value)) {
                    m_node.text().set(std::get<bool>(value));
                } else {
                    throw std::runtime_error("Invalid type for Bool node");
                }
                break;
            case EConfigNodeType::Int:
                if (std::holds_alternative<int>(value)) {
                    m_node.text().set(std::get<int>(value));
                } else {
                    throw std::runtime_error("Invalid type for Int node");
                }
                break;
            case EConfigNodeType::Uint:
                if (std::holds_alternative<unsigned int>(value)) {
                    m_node.text().set(std::get<unsigned int>(value));
                } else {
                    throw std::runtime_error("Invalid type for Uint node");
                }
                break;
            case EConfigNodeType::Int64:
                if (std::holds_alternative<int64_t>(value)) {
                    m_node.text().set(std::get<int64_t>(value));
                } else {
                    throw std::runtime_error("Invalid type for Int64 node");
                }
                break;
            case EConfigNodeType::Uint64:
                if (std::holds_alternative<uint64_t>(value)) {
                    m_node.text().set(std::get<uint64_t>(value));
                } else {
                    throw std::runtime_error("Invalid type for Uint64 node");
                }
                break;
            case EConfigNodeType::Float:
                if (std::holds_alternative<float>(value)) {
                    m_node.text().set(std::get<float>(value));
                } else {
                    throw std::runtime_error("Invalid type for Float node");
                }
                break;
            case EConfigNodeType::Enum:
                if (std::holds_alternative<std::string>(value)) {
                    m_node.child("selected").text().set(std::get<std::string>(value).c_str());
                } else {
                    throw std::runtime_error("Invalid type for Enum node");
                }
                break;
            case EConfigNodeType::XmlNode:
                if (std::holds_alternative<pugi::xml_node>(value)) {
                    m_node = std::get<pugi::xml_node>(value);
                } else {
                    throw std::runtime_error("Invalid type for XmlNode node");
                }
                break;
            default:
                throw std::runtime_error("Invalid node type");
        }
    }

    void SetValueAndChangeType(const ValueType &value) override {
        if (!m_node) {
            throw std::runtime_error("Node is not valid");
        }

        EConfigNodeType newType = EConfigNodeType::Unknown;
        // determine the node type from the variant
        if (std::holds_alternative<std::string>(value)) {
            newType = EConfigNodeType::String;
        } else if (std::holds_alternative<bool>(value)) {
            newType = EConfigNodeType::Bool;
        } else if (std::holds_alternative<int>(value)) {
            newType = EConfigNodeType::Int;
        } else if (std::holds_alternative<unsigned int>(value)) {
            newType = EConfigNodeType::Uint;
        } else if (std::holds_alternative<int64_t>(value)) {
            newType = EConfigNodeType::Int64;
        } else if (std::holds_alternative<uint64_t>(value)) {
            newType = EConfigNodeType::Uint64;
        } else if (std::holds_alternative<float>(value)) {
            newType = EConfigNodeType::Float;
        } else if (std::holds_alternative<pugi::xml_node>(value)) {
            newType = EConfigNodeType::XmlNode;
        } else if (std::holds_alternative<std::string>(value)) {
            newType = EConfigNodeType::Enum; // Assuming Enum is also a string for simplicity
        } else {
            throw std::runtime_error("Invalid type for SetValueAndChangeType");
        }

        m_node.attribute("type").set_value(ToString(newType).c_str());
        SetValue(value);
    }

private:
    pugi::xml_node m_node;
};
#endif //CHAIRLOADER_CONFIGNODE_H
