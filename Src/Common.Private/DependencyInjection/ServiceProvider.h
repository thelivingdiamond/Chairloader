//
// Created by theli on 4/27/2025.
//

#ifndef SERVICEPROVIDER_H
#define SERVICEPROVIDER_H

#include <map>
#include <vector>
#include <Chairloader/IServiceProvider.h>

struct ServiceDescriptor;

class ServiceProvider : public IServiceProvider {
public:
    ServiceProvider(std::map<std::type_index, ServiceDescriptor> services)
        : services(std::move(services)) {
    }

    ~ServiceProvider() override = default;

    std::shared_ptr<void> GetService(std::type_index serviceType) override;

private:
    std::map<std::type_index, ServiceDescriptor> services;

    std::map<std::type_index, std::shared_ptr<void> > serviceMap;

    std::vector<std::type_index> resolutionStack;
};


#endif //SERVICEPROVIDER_H
