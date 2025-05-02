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

    // Check if the service is already resolved
    const auto it = m_ServiceInstances.find(serviceType);
    if (it != m_ServiceInstances.end()) {
        return it->second.get();
    }

    // Check if the service is registered
    const auto serviceIt = m_ServiceDescriptors.find(serviceType);
    if (serviceIt == m_ServiceDescriptors.end()) {
        throw std::runtime_error("Service not found: " + serviceType);
    }

    // Add the service type to the resolution stack
    m_ServiceResolutionStack.push_back(serviceType);

    try {
        // Create the service using the factory function
        // Store the resolved service in the map
        m_ServiceInstances[serviceType] = std::move(serviceIt->second.m_factory(*this));
        m_ServiceResolutionStack.pop_back();
        // Return the resolved service
        return m_ServiceInstances[serviceType].get();
    } catch (const std::exception &e) {
        // Remove the service type from the resolution stack if an error occurs
        m_ServiceResolutionStack.pop_back();
        throw; // Re-throw the exception
    }
}
