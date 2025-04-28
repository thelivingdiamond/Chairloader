//
// Created by theli on 4/27/2025.
//

#include "ServiceProvider.h"

#include <stdexcept>
#include <string>

#include "ServiceDescriptor.h"

std::shared_ptr<void> ServiceProvider::GetService(std::type_index serviceType) {
    if (std::find(resolutionStack.begin(), resolutionStack.end(), serviceType) != resolutionStack.end()) {
        // Prevent circular dependencies
        throw std::runtime_error("Circular dependency detected while resolving service: " + std::string(serviceType.name()));
    }
    // Check if the service is already resolved
    auto it = serviceMap.find(serviceType);
    if (it != serviceMap.end()) {
        return it->second;
    }
    // Check if the service is registered
    auto serviceIt = services.find(serviceType);
    if (serviceIt == services.end()) {
        throw std::runtime_error("Service not found: " + std::string(serviceType.name()));
    }
    // Add the service type to the resolution stack
    resolutionStack.push_back(serviceType);
    try {
        // Create the service using the factory function
        auto service = serviceIt->second.factory(*this);
        // Store the resolved service in the map
        serviceMap[serviceType] = service;
        resolutionStack.pop_back();
        return service;
    } catch (const std::exception& e) {
        // Remove the service type from the resolution stack if an error occurs
        resolutionStack.pop_back();
        throw; // Re-throw the exception
    }
}
