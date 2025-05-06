//
// Created by theli on 4/27/2025.
//

#include "ServiceCollection.h"

#include "ServiceProvider.h"


void ServiceCollection::AddService(const std::string &serviceType, ServiceConstructor constructor,
    EChairServiceLifetime lifetime) {
    if (m_Built) {
        throw std::runtime_error("Cannot add services after the service provider has been built");
    }
    ServiceDescriptor descriptor;
    descriptor.m_serviceType = serviceType;
    descriptor.m_serviceLifetime = lifetime;
    descriptor.m_factory = std::move(constructor);
    m_ServiceDescriptors[serviceType] = std::move(descriptor);
}

std::unique_ptr<IChairServiceProvider> ServiceCollection::BuildServiceProvider() {
    if (m_Built) {
        throw std::runtime_error("Service provider already built");
    }
    m_Built = true;
    return std::make_unique<ServiceProvider>(m_ServiceDescriptors);
}
