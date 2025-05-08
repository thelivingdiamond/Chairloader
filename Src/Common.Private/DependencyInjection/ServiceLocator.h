//
// Created by theli on 5/7/2025.
//

#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H
#include <memory>
#include <mutex>

#include "Chairloader/IChairServiceProvider.h"


/**
 * \brief ServiceLocator is a singleton class that provides access to a service provider.
 *
 * The ServiceLocator class allows you to set a service provider and retrieve services
 * from it. It ensures that the service provider is set only once and provides thread-safe
 * access to the services.
 */
class ServiceLocator {
public:

    /**
     * \brief Set the service provider.
     *
     * This method sets the service provider for the ServiceLocator. It can only be called
     * once, and attempting to set it again will throw a logic error.
     *
     * @param prov A unique pointer to the service provider to set.
     * @throws std::logic_error if the provider is already set.
     */
    static void SetProvider(std::unique_ptr<IChairServiceProvider> &prov) {
        std::lock_guard lock(mutex_);
        if (provider_) {
            throw std::logic_error("ServiceLocator::SetProvider called twice");
        }
        provider_ = std::move(prov);
    }


    /**
     * \brief Get the service provider.
     *
     * This method returns the current service provider. If the provider is not set,
     * it throws a logic error.
     *
     * @return A pointer to the current service provider.
     * @throws std::logic_error if the provider is not set.
     */
    static IChairServiceProvider* GetProvider() {
        std::lock_guard lock(mutex_);
        if (!provider_) {
            throw std::logic_error("ServiceLocator: provider not set");
        }
        return provider_.get();
    }


    /**
     *
     * @tparam T The type of the service to get, must inherit from IChairService
     * @return A shared pointer to the service of type T, or nullptr if not found
     */
    template<typename T>
    static std::shared_ptr<T> GetService() {
        return GetProvider()->GetService<T>();
    }

    /**
     *
     * @tparam T The type of the service to get, must inherit from IChairService
     * @return A shared pointer to the service of type T, or throws if not found
     * @throws std::runtime_error if the service is not found
     */
    template<typename T>
    static std::shared_ptr<T> GetRequiredService() {
        return GetProvider()->GetRequiredService<T>();
    }

private:
    static std::unique_ptr<IChairServiceProvider> provider_;
    static std::mutex mutex_;
};

#endif //SERVICELOCATOR_H
