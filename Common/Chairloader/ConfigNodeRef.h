//
// Created by theli on 4/26/2025.
//

#ifndef CONFIGNODEREF_H
#define CONFIGNODEREF_H

template<typename T>
class ConfigNodeRef {
public :
    ConfigNodeRef(std::unique_ptr<T> nodePtr) : node(std::move(nodePtr)) {
    }

    T *operator->() {
        if (!node) {
            throw std::runtime_error("ConfigNodeRef is not valid");
        }
        return node.get();
    }

    T &operator*() {
        if (!node) {
            throw std::runtime_error("ConfigNodeRef is not valid");
        }
        return *node;
    }

    ConfigNodeRef operator [](const char *name) {
        if (!node) {
            throw std::runtime_error("ConfigNodeRef is not valid");
        }
        auto childNode = node->Get(name);
        return ConfigNodeRef(std::move(childNode));
    }

    operator bool() const {
        return node != nullptr && node->IsValid();
    }

private:
    std::unique_ptr<T> node;
};
#endif //CONFIGNODEREF_H
