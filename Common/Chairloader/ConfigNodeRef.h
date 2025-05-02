//
// Created by theli on 4/26/2025.
//

#ifndef CONFIGNODEREF_H
#define CONFIGNODEREF_H

/**
 * \brief A wrapper class for managing references to configuration nodes.
 *
 * This class provides a safe and convenient way to interact with configuration nodes
 * by encapsulating a unique pointer to the node and providing operator overloads
 * for accessing and manipulating the node.
 *
 * \tparam T The type of the configuration node.
 */
template<typename T>
class ConfigNodeRef {
public:
    /**
     * \brief Constructs a ConfigNodeRef with a unique pointer to a node.
     * \param nodePtr A unique pointer to the configuration node.
     */
    ConfigNodeRef(std::unique_ptr<T> nodePtr) : node(std::move(nodePtr)) {
    }

    /**
     * \brief Provides access to the underlying node's members.
     * \return A pointer to the underlying node.
     * \throws std::runtime_error if the node is not valid.
     */
    T *operator->() {
        if (!node) {
            throw std::runtime_error("ConfigNodeRef is not valid");
        }
        return node.get();
    }

    /**
     * \brief Dereferences the underlying node.
     * \return A reference to the underlying node.
     * \throws std::runtime_error if the node is not valid.
     */
    T &operator*() {
        if (!node) {
            throw std::runtime_error("ConfigNodeRef is not valid");
        }
        return *node;
    }

    /**
     * \brief Retrieves a child node by name.
     * \param name The name of the child node.
     * \return A ConfigNodeRef to the child node.
     * \throws std::runtime_error if the node is not valid.
     */
    ConfigNodeRef operator [](const char *name) {
        if (!node) {
            throw std::runtime_error("ConfigNodeRef is not valid");
        }
        auto childNode = node->Get(name);
        return ConfigNodeRef(std::move(childNode));
    }

    /**
     * \brief Checks if the ConfigNodeRef is valid.
     * \return True if the node is valid, false otherwise.
     */
    operator bool() const {
        return node != nullptr && node->IsValid();
    }

private:
    std::unique_ptr<T> node; ///< The unique pointer to the configuration node.
};
#endif //CONFIGNODEREF_H
