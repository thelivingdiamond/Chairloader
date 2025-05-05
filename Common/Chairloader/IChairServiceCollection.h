//
// Created by theli on 4/27/2025.
//

#ifndef ISERVICECOLLECTION_H
#define ISERVICECOLLECTION_H
#include <functional>
#include <memory>

struct IChairServiceProvider;

/**
 * \brief Interface for a service collection that manages service registrations and their providers.
 *
 * The `IChairServiceCollection` interface allows adding and associating services with their implementations
 * and provides a mechanism to build a service provider for resolving dependencies.
 */
struct IChairServiceCollection {
    virtual ~IChairServiceCollection() = default;

    /**
     * \brief Type alias for a service constructor function.
     *
     * A `ServiceConstructor` is a function that takes an `IChairServiceProvider` reference and returns
     * a shared pointer to the constructed service.
     */
    using ServiceConstructor = std::function<std::shared_ptr<void>(IChairServiceProvider &)>;

    /**
     * \brief Adds a service with a specific implementation type and factory function.
     *
     * \param serviceType The type of the service being registered.
     * \param implementationType The type of the implementation for the service.
     * \param factory A factory function to create the service instance.
     */
    virtual void AddService(const std::string &serviceType, const std::string &implementationType,
                            const ServiceConstructor &factory) = 0;

    /**
     * \brief Associates a service type with an implementation type. Used to associate an already registered
     * implementation with multiple service types.
     *
     * \param serviceType The type of the service being associated.
     * \param implementationType The type of the implementation for the service.
     *
     * \exception std::runtime_error If the implementation type has not been registered previously.
     */
    virtual void AssociateService(const std::string &serviceType, const std::string &implementationType) = 0;

    /**
     * \brief Adds a service with the same type for both service and implementation.
     *
     * \param serviceType The type of the service being registered.
     * \param factory A factory function to create the service instance.
     */
    virtual void AddService(const std::string &serviceType, const ServiceConstructor &factory) {
        AddService(serviceType, serviceType, factory);
    }

    /**
     * \brief Builds a service provider from the registered services.
     *
     * \return A unique pointer to an `IChairServiceProvider` that resolves services.
     *
     * \exception std::runtime_error If the provider has already been built
     */
    virtual std::unique_ptr<IChairServiceProvider> BuildServiceProvider() = 0;
};


#endif //ISERVICECOLLECTION_H
