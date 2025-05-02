//
// Created by theli on 4/27/2025.
//

#include "ServiceCollection.h"

#include "ServiceProvider.h"

void ServiceCollection::AddService(const std::string &serviceType, const std::string &implementationType,
                                   const ServiceConstructor &factory) {
    m_ServiceDescriptors.emplace(serviceType, ServiceDescriptor{serviceType, implementationType, factory});
}

std::unique_ptr<IChairServiceProvider> ServiceCollection::BuildServiceProvider() {
    if (m_Built) {
        throw std::runtime_error("Service provider already built");
    }
    m_Built = true;
    return std::make_unique<ServiceProvider>(std::move(m_ServiceDescriptors));
}
