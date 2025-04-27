//
// Created by theli on 4/26/2025.
//

#ifndef ICONFIGNODEV1_H
#define ICONFIGNODEV1_H
#include <memory>
#include <optional>
#include <pugixml.hpp>
#include <stdexcept>
#include <variant>
#include "Chairloader/ConfigNodeRef.h"

// interface for version 1 of config node
struct IConfigNodeV1 {
    enum class NodeType { String, Bool, Int, Uint, Int64, Uint64, Float, XmlNode, Enum, Unknown };

    using ValueType = std::variant<float, bool, int, unsigned int, int64_t, uint64_t, std::string, pugi::xml_node>;

    virtual ~IConfigNodeV1() = default;

    // access child nodes
    //TODO: should these return std::unique_ptr<IConfigNodeV1> or ConfigNodeRef?
    virtual ConfigNodeRef<IConfigNodeV1> Get(const char *name) = 0;

    virtual ConfigNodeRef<IConfigNodeV1> Create(const char *name, NodeType type) = 0;

    virtual ConfigNodeRef<IConfigNodeV1> GetOrCreate(const char *name, NodeType type) = 0;

    virtual ConfigNodeRef<IConfigNodeV1> operator [](const char *name) {
        return Get(name);
    }

    // access node properties
    virtual bool IsValid() const = 0;

    virtual NodeType GetNodeType() const = 0;

    virtual std::string GetName() const = 0;

    virtual std::string GetDisplayName() const = 0;

    virtual std::string GetDescription() const = 0;

    virtual pugi::xml_node GetXmlNode() const = 0;

    // get or set value
    virtual std::optional<ValueType> GetValue() const = 0;

    virtual void SetValue(const ValueType &value) = 0;

    virtual void SetValueAndChangeType(const ValueType &value) = 0;

    template<typename T>
    T As() const {
        auto value = GetValue();
        if (!value) {
            throw std::runtime_error("Node value is not set or invalid");
        }
        return std::get<T>(*value);
    }

    template<typename T>
    T AsOrDefault(T defaultValue) const {
        auto value = GetValue();
        if (!value) {
            return defaultValue;
        }
        return std::get<T>(*value);
    }

    template<typename T>
    std::optional<T> Maybe() const {
        auto value = GetValue();
        if (!value) {
            return std::nullopt;
        }
        try {
            return std::get<T>(*value);
        } catch (const std::bad_variant_access &) {
            return std::nullopt;
        }
    }

    template<typename T>
    void Set(const T &value) {
        SetValue(value);
    }


    static NodeType ToNodeType(const std::string_view s) {
        if (s == "string") return NodeType::String;
        if (s == "bool") return NodeType::Bool;
        if (s == "int") return NodeType::Int;
        if (s == "uint") return NodeType::Uint;
        if (s == "int64") return NodeType::Int64;
        if (s == "uint64") return NodeType::Uint64;
        if (s == "float") return NodeType::Float;
        if (s == "xmlnode") return NodeType::XmlNode;
        if (s == "enum") return NodeType::Enum;
        return NodeType::Unknown;
    }

    static std::string ToString(const NodeType type) {
        switch (type) {
            case NodeType::String: return "string";
            case NodeType::Bool: return "bool";
            case NodeType::Int: return "int";
            case NodeType::Uint: return "uint";
            case NodeType::Int64: return "int64";
            case NodeType::Uint64: return "uint64";
            case NodeType::Float: return "float";
            case NodeType::XmlNode: return "xmlnode";
            case NodeType::Enum: return "enum";
            default: return "unknown";
        }
    }
};

#endif //ICONFIGNODEV1_H
