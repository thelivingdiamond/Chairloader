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


/**
 * \enum EConfigNodeType
 * \brief Represents the various types of configuration nodes supported by Chairloader.
 *
 * This enum defines the possible types a configuration node can have, such as strings, integers,
 * booleans, and XML nodes. It is used to specify and identify the type of data stored in a node.
 */
enum class EConfigNodeType {
    Unknown,
    String,
    Bool,
    Int,
    Uint,
    Int64,
    Uint64,
    Float,
    XmlNode,
    Enum,
};

/**
 * \brief Interface for a configuration node in Chairloader.
 *
 * This interface provides methods to access, create, and manipulate configuration nodes.
 * Each node can have a type, value, and child nodes, and supports various operations
 * for retrieving and setting these properties.
 */
struct IConfigNodeV1 {
    /**
     * \brief Type alias for the value stored in a configuration node.
     */
    using ValueType = std::variant<float, bool, int, unsigned int, int64_t, uint64_t, std::string, pugi::xml_node>;

    virtual ~IConfigNodeV1() = default;

    /**
     * \brief Retrieves a child node by name.
     * \param name The name of the child node.
     * \return A reference to the child node.
     */
    virtual ConfigNodeRef<IConfigNodeV1> Get(const char *name) = 0;

    /**
     * \brief Creates a new child node with the specified name and type.
     * \param name The name of the new child node.
     * \param type The type of the new child node.
     * \return A reference to the created child node.
     */
    virtual ConfigNodeRef<IConfigNodeV1> Create(const char *name, EConfigNodeType type) = 0;

    /**
     * \brief Retrieves or creates a child node with the specified name and type.
     * \param name The name of the child node.
     * \param type The type of the child node, used to create the node if the node is not found.
     * \return A reference to the retrieved or created child node.
     */
    virtual ConfigNodeRef<IConfigNodeV1> GetOrCreate(const char *name, EConfigNodeType type) = 0;

    /**
     * \brief Operator overload to retrieve a child node by name.
     * \param name The name of the child node.
     * \return A reference to the child node.
     */
    virtual ConfigNodeRef<IConfigNodeV1> operator [](const char *name) {
        return Get(name);
    }

    /**
     * \brief Checks if the node is valid.
     * \return True if the node is valid, false otherwise.
     */
    virtual bool IsValid() const = 0;

    /**
     * \brief Retrieves the type of the node.
     * \return The type of the node as an EConfigNodeType.
     */
    virtual EConfigNodeType GetNodeType() const = 0;

    /**
     * \brief Retrieves the name of the node.
     * \return The name of the node as a string.
     */
    virtual std::string GetName() const = 0;

    /**
     * \brief Retrieves the display name of the node.
     * \return The display name of the node as a string.
     */
    virtual std::string GetDisplayName() const = 0;

    /**
     * \brief Retrieves the description of the node.
     * \return The description of the node as a string.
     */
    virtual std::string GetDescription() const = 0;

    /**
     * \brief Retrieves the underlying XML node.
     * \return The XML node as a pugi::xml_node.
     */
    virtual pugi::xml_node GetXmlNode() const = 0;

    /**
     * \brief Retrieves the value of the node.
     * \return An optional containing the value if set, or std::nullopt otherwise.
     */
    virtual std::optional<ValueType> GetValue() const = 0;

    /**
     * \brief Sets the value of the node.
     * \param value The value to set.
     */
    virtual void SetValue(const ValueType &value) = 0;

    /**
     * \brief Sets the value of the node and changes its type.
     * \param value The value to set.
     */
    virtual void SetValueAndChangeType(const ValueType &value) = 0;

    /**
     * \brief Retrieves the value of the node as a specific type.
     * \tparam T The type to retrieve the value as.
     * \return The value as the specified type.
     * \throws std::runtime_error if the value is not set or invalid.
     */
    template<typename T>
    T As() const {
        auto value = GetValue();
        if (!value) {
            throw std::runtime_error("Node value is not set or invalid");
        }
        return std::get<T>(*value);
    }

    /**
     * \brief Retrieves the value of the node as a specific type or a default value.
     * \tparam T The type to retrieve the value as.
     * \param defaultValue The default value to return if the value is not set.
     * \return The value as the specified type, or the default value.
     */
    template<typename T>
    T AsOrDefault(T defaultValue) const {
        auto value = GetValue();
        if (!value) {
            return defaultValue;
        }
        return std::get<T>(*value);
    }

    /**
     * \brief Retrieves the value of the node as an optional of a specific type.
     * \tparam T The type to retrieve the value as.
     * \return An optional containing the value if valid, or std::nullopt otherwise.
     */
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

    /**
     * \brief Sets the value of the node.
     * \tparam T The type of the value to set.
     * \param value The value to set.
     */
    template<typename T>
    void Set(const T &value) {
        SetValue(value);
    }

    /**
     * \brief Converts a string representation of a node type to an EConfigNodeType.
     * \param s The string representation of the node type.
     * \return The corresponding EConfigNodeType.
     */
    static EConfigNodeType ToNodeType(const std::string_view s) {
        if (s == "string") return EConfigNodeType::String;
        if (s == "bool") return EConfigNodeType::Bool;
        if (s == "int") return EConfigNodeType::Int;
        if (s == "uint") return EConfigNodeType::Uint;
        if (s == "int64") return EConfigNodeType::Int64;
        if (s == "uint64") return EConfigNodeType::Uint64;
        if (s == "float") return EConfigNodeType::Float;
        if (s == "xmlnode") return EConfigNodeType::XmlNode;
        if (s == "enum") return EConfigNodeType::Enum;
        return EConfigNodeType::Unknown;
    }

    /**
     * \brief Converts an EConfigNodeType to its string representation.
     * \param type The EConfigNodeType to convert.
     * \return The string representation of the node type.
     */
    static std::string ToString(const EConfigNodeType type) {
        switch (type) {
            case EConfigNodeType::String: return "string";
            case EConfigNodeType::Bool: return "bool";
            case EConfigNodeType::Int: return "int";
            case EConfigNodeType::Uint: return "uint";
            case EConfigNodeType::Int64: return "int64";
            case EConfigNodeType::Uint64: return "uint64";
            case EConfigNodeType::Float: return "float";
            case EConfigNodeType::XmlNode: return "xmlnode";
            case EConfigNodeType::Enum: return "enum";
            default: return "unknown";
        }
    }
};

#endif //ICONFIGNODEV1_H
