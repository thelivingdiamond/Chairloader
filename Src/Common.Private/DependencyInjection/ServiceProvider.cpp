//
// Created by theli on 4/27/2025.
//

#include "ServiceProvider.h"

#include <stdexcept>
#include <string>

#include "ServiceDescriptor.h"

std::shared_ptr<void> ServiceProvider::GetService(const std::string &serviceType) {
    if (std::find(m_ServiceResolutionStack.begin(), m_ServiceResolutionStack.end(), serviceType) !=
        m_ServiceResolutionStack.end()) {
        // Prevent circular dependencies
        throw std::runtime_error("Circular dependency detected while resolving service: " + serviceType);
    }

    // get the descriptor so we know if it's a singleton or transient service
    auto it = m_ImplementationDescriptors.find(serviceType);
    if (it == m_ImplementationDescriptors.end()) {
        // Service not found
        return nullptr;
    }
    const ServiceDescriptor &descriptor = it->second;
    // Check if the service has already been instantiated
    auto instanceIt = m_ServiceInstances.find(serviceType);
    if (instanceIt != m_ServiceInstances.end()) {
        // Return existing instance if it's a singleton
        if (descriptor.m_serviceLifetime == EChairServiceLifetime::Singleton) {
            return instanceIt->second;
        }
        // If it's transient, we still need to create a new instance
    }
    // Push the service type onto the resolution stack to detect circular dependencies
    m_ServiceResolutionStack.push_back(serviceType);
    try {
        // Create a new instance of the service using the factory
        std::shared_ptr<void> serviceInstance = descriptor.m_factory(*this);
        if (!serviceInstance) {
            throw std::runtime_error("Service factory returned null for service: " + serviceType);
        }
        // Store the instance if it's a singleton
        if (descriptor.m_serviceLifetime == EChairServiceLifetime::Singleton) {
            m_ServiceInstances[serviceType] = serviceInstance;
        }

        m_ServiceResolutionStack.pop_back(); // Pop the service type from the resolution stack
        return serviceInstance;
    } catch (...) {
        // Pop the service type from the resolution stack on error
        m_ServiceResolutionStack.pop_back();
        throw; // Re-throw the exception
    }
}
