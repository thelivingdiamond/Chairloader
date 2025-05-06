//
// Created by theli on 4/27/2025.
//

#ifndef ISERVICECOLLECTION_H
#define ISERVICECOLLECTION_H
#include <functional>
#include <memory>

#include "IChairServiceProvider.h"


enum class EChairServiceLifetime {
    Singleton,  //!< The service is created once and reused for all requests.
    Transient   //!< A new instance of the service is created for each request.
};

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

    virtual void AddService(
        const std::string &serviceType,
        ServiceConstructor constructor,
        EChairServiceLifetime lifetime
    ) = 0;

    /// After all registrations, build the concrete provider.
    virtual std::unique_ptr<IChairServiceProvider> BuildServiceProvider() = 0;
};

template<typename I, typename Impl>
void AddSingleton(IChairServiceCollection& col) {
    static_assert(std::is_base_of_v<I, Impl>, "Impl must derive from I");
    col.AddService({
        I::Name(),
        EChairServiceLifetime::Singleton,
        [](IChairServiceProvider& prov)->std::shared_ptr<void>{
            return std::make_shared<Impl>();
        }
    });
}

template<typename I, typename Impl, typename... Deps>
void AddSingleton(IChairServiceCollection& col) {
    static_assert(std::is_base_of_v<I, Impl>, "Impl must derive from I");
    col.AddService({
        I::Name(),
        EChairServiceLifetime::Singleton,
        [](IChairServiceProvider& prov)->std::shared_ptr<void>{
            return std::make_shared<Impl>( prov.GetRequiredService<Deps>()... );
        }
    });
}

template<typename I, typename Impl>
void AddTransient(IChairServiceCollection& col) {
    static_assert(std::is_base_of_v<I, Impl>, "Impl must derive from I");
    col.AddService({
        I::Name(),
        EChairServiceLifetime::Transient,
        [](IChairServiceProvider& prov)->std::shared_ptr<void>{
            return std::make_shared<Impl>();
        }
    });
}

template<typename I, typename Impl, typename... Deps>
void AddTransient(IChairServiceCollection& col) {
    static_assert(std::is_base_of_v<I, Impl>, "Impl must derive from I");
    col.AddService({
        I::Name(),
        EChairServiceLifetime::Transient,
        [](IChairServiceProvider& prov)->std::shared_ptr<void>{
            return std::make_shared<Impl>( prov.GetRequiredService<Deps>()... );
        }
    });
}


#endif //ISERVICECOLLECTION_H
