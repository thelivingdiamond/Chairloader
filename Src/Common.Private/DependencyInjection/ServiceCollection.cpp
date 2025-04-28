//
// Created by theli on 4/27/2025.
//

#include "ServiceCollection.h"

#include "ServiceProvider.h"

void ServiceCollection::AddService(std::type_index service, const std::type_index implementation,
                                   const std::function<std::shared_ptr<void>(IChairServiceProvider &)> factory) {
    services.emplace(service, ServiceDescriptor{service, implementation, factory});
}

std::unique_ptr<IChairServiceProvider> ServiceCollection::BuildServiceProvider() {
    return std::make_unique<ServiceProvider>(std::move(services));
}
