//
// Created by theli on 4/27/2025.
//

#ifndef SERVICEDESCRIPTOR_H
#define SERVICEDESCRIPTOR_H
#include <functional>
#include <memory>
#include <typeindex>
struct IChairServiceProvider;

struct ServiceDescriptor {
    std::type_index serviceType;
    std::type_index implementationType;
    std::function<std::shared_ptr<void>(IChairServiceProvider &)> factory;
};

#endif //SERVICEDESCRIPTOR_H
