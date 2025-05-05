//
// Created by theli on 4/27/2025.
//

#include "ServiceProvider.h"

#include <stdexcept>
#include <string>

#include "ServiceDescriptor.h"

void *ServiceProvider::GetService(const std::string &serviceType) {
    if (std::find(m_ServiceResolutionStack.begin(), m_ServiceResolutionStack.end(), serviceType) !=
        m_ServiceResolutionStack.end()) {
        // Prevent circular dependencies
        throw std::runtime_error("Circular dependency detected while resolving service: " + serviceType);
    }

    // find out what the implementation type is for the requested service
    const auto implIt = m_ServiceToImplementationMap.find(serviceType);
    if (implIt == m_ServiceToImplementationMap.end()) {
        // Service not registered
        return nullptr;
    }
    const auto impl = implIt->second;

    // Check if the service is already resolved
    const auto it = m_ServiceInstances.find(impl);
    if (it != m_ServiceInstances.end()) {
        return it->second.get();
    }

    // Check if we have a descriptor for the implementation type
    const auto serviceIt = m_ImplementationDescriptors.find(impl);
    if (serviceIt == m_ImplementationDescriptors.end()) {
        // Implementation type not registered
        return nullptr;
    }

    // Add the service type to the resolution stack
    m_ServiceResolutionStack.push_back(serviceType);

    try {
        // Create the service instance using the factory function
        auto serviceInstance = serviceIt->second.m_factory(*this);
        if (!serviceInstance) {
            throw std::runtime_error("Failed to create service instance for: " + impl);
        }

        // Store the created service instance
        m_ServiceInstances[impl] = std::move(serviceInstance);
    } catch (const std::exception &e) {
        // Remove the service type from the resolution stack on failure
        m_ServiceResolutionStack.pop_back();
        throw;
    }
    // Remove the service type from the resolution stack after successful resolution
    m_ServiceResolutionStack.pop_back();
    return m_ServiceInstances[impl].get();
}
