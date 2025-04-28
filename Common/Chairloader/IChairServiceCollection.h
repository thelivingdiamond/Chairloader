//
// Created by theli on 4/27/2025.
//

#ifndef ISERVICECOLLECTION_H
#define ISERVICECOLLECTION_H
#include <functional>
#include <memory>
#include <typeindex>
#include <utility>

struct IChairServiceProvider;

struct IChairServiceCollection {
    virtual ~IChairServiceCollection() = default;

    virtual void AddService(std::type_index service, std::type_index implementation, std::function<std::shared_ptr<void>(IChairServiceProvider &)> factory) = 0;

    virtual void AddService(std::type_index service, std::function<std::shared_ptr<void>(IChairServiceProvider &)> factory) {
        AddService(service, service, std::move(factory));
    }

    template <typename TService, typename TImplementation>
    void AddService(std::function<std::shared_ptr<TImplementation>(IChairServiceProvider &)> factory) {
        AddService(typeid(TService), typeid(TImplementation), std::move(factory));
    }

    template <typename TService>
    void AddService(std::function<std::shared_ptr<TService>(IChairServiceProvider &)> factory) {
        AddService(typeid(TService), std::move(factory));
    }

    virtual std::unique_ptr<IChairServiceProvider> BuildServiceProvider() = 0;
};



#endif //ISERVICECOLLECTION_H
