//
// Created by theli on 4/27/2025.
//

#ifndef ISERVICECOLLECTION_H
#define ISERVICECOLLECTION_H
#include <functional>
#include <memory>
#include <utility>
#include <any>

struct IChairServiceProvider;


struct IChairServiceCollection {
    virtual ~IChairServiceCollection() = default;

    using ServiceConstructor = std::function<std::shared_ptr<void>(IChairServiceProvider &)>;

    virtual void AddService(const std::string &serviceType, const std::string &implementationType,
                            const ServiceConstructor& factory) = 0;

    virtual void AddService(const std::string &serviceType, const ServiceConstructor& factory) {
        AddService(serviceType, serviceType, factory);
    }

    virtual std::unique_ptr<IChairServiceProvider> BuildServiceProvider() = 0;
};


#endif //ISERVICECOLLECTION_H
