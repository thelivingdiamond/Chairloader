//
// Created by theli on 4/27/2025.
//

#ifndef ISERVICEPROVIDER_H
#define ISERVICEPROVIDER_H
#include <memory>
#include <typeindex>

struct IChairServiceProvider {
    virtual ~IChairServiceProvider() = default;

    virtual std::shared_ptr<void> GetService(std::type_index serviceType) = 0;

    template <typename T>
    std::shared_ptr<T> GetService() {
        return std::static_pointer_cast<T>(GetService(typeid(T)));
    }
};

#endif //ISERVICEPROVIDER_H
