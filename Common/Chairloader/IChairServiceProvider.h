//
// Created by theli on 4/27/2025.
//

#ifndef ISERVICEPROVIDER_H
#define ISERVICEPROVIDER_H

/**
 * \brief Interface for a service provider that resolves registered services.
 *
 * The `IChairServiceProvider` interface provides methods to retrieve services
 * by their type. It supports both optional and required service resolution.
 */
struct IChairServiceProvider {
    virtual ~IChairServiceProvider() = default;

    virtual std::shared_ptr<void> GetService(const std::string &serviceType) = 0;

    /// Typed lookup using CRTP Name()
    template<typename T>
    std::shared_ptr<void> GetService() {
        return static_cast<T>(GetService(T::Name()));
    }

    /// Typed lookup using CRTP Name()
    template<typename T>
    std::shared_ptr<void> GetRequiredService() {
        std::shared_ptr<void> service = GetService<T>();
        if (!service) {
            throw std::runtime_error("Required service not found: " + std::string(T::Name()));
        }
        return service;
    }
};

#endif //ISERVICEPROVIDER_H
