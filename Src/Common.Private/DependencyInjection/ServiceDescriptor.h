//
// Created by theli on 4/27/2025.
//

#ifndef SERVICEDESCRIPTOR_H
#define SERVICEDESCRIPTOR_H
#include <functional>
#include <memory>

#include "Chairloader/IChairServiceCollection.h"
struct IChairServiceProvider;

struct ServiceDescriptor {
    std::string m_ImplementationType;
    IChairServiceCollection::ServiceConstructor m_factory;
};

#endif //SERVICEDESCRIPTOR_H
