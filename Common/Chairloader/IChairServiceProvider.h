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

    /**
     * \brief Retrieves a service by its type.
     *
     * \param serviceType The type of the service to retrieve.
     * \return A pointer to the service, or `nullptr` if the service is not found.
     * \throws std::runtime_error If the service resolution fails due to circular dependencies.
     */
    virtual void *GetService(const std::string &serviceType) = 0;

    /**
     * \brief Retrieves a service by its type and casts it to the specified type.
     *
     * \tparam T The type to cast the service to.
     * \param serviceType The type of the service to retrieve.
     * \return A pointer to the service cast to the specified type, or `nullptr` if the service is not found.
     * \throws std::runtime_error If the service resolution fails due to circular dependencies.
     */
    template<typename T>
    T *GetService(const std::string &serviceType) {
        return static_cast<T *>(GetService(serviceType));
    }

    /**
     * \brief Retrieves a required service by its type and casts it to the specified type.
     *
     * \tparam T The type to cast the service to.
     * \param serviceType The type of the service to retrieve.
     * \return A pointer to the service cast to the specified type.
     * \throws std::runtime_error If the service is not found.
     */
    template<typename T>
    T *GetRequiredService(const std::string &serviceType) {
        T *service = GetService<T>(serviceType);
        if (!service) {
            throw std::runtime_error("Required service not found: " + serviceType);
        }
        return service;
    }
};

#endif //ISERVICEPROVIDER_H
