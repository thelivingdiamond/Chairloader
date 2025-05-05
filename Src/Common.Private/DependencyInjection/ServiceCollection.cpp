//
// Created by theli on 4/27/2025.
//

#include "ServiceCollection.h"

#include "ServiceProvider.h"

void ServiceCollection::AddService(const std::string &serviceType, const std::string &implementationType,
                                   const ServiceConstructor &factory) {
    m_ServiceToImplementationMap[serviceType] = implementationType;
    m_ImplementationDescriptors[implementationType] = {implementationType, factory};
}

void ServiceCollection::AssociateService(const std::string &serviceType, const std::string &implementationType) {
    if (m_ImplementationDescriptors.find(implementationType) == m_ImplementationDescriptors.end()) {
        throw std::runtime_error("Implementation type not previously registered: " + implementationType);
    }
    m_ServiceToImplementationMap[serviceType] = implementationType;
}

std::unique_ptr<IChairServiceProvider> ServiceCollection::BuildServiceProvider() {
    if (m_Built) {
        throw std::runtime_error("Service provider already built");
    }
    m_Built = true;
    return std::make_unique<ServiceProvider>(m_ServiceToImplementationMap, m_ImplementationDescriptors);
}
