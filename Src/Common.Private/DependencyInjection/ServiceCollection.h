//
// Created by theli on 4/27/2025.
//

#ifndef SERVICECOLLECTION_H
#define SERVICECOLLECTION_H
#include <map>

#include "ServiceDescriptor.h"
#include "Chairloader/IServiceCollection.h"


class ServiceCollection : public IServiceCollection {
public:
    ~ServiceCollection() override = default;

    void AddService(std::type_index service, std::type_index implementation,
                    std::function<std::shared_ptr<void>(IServiceProvider &)> factory) override;

    std::unique_ptr<IServiceProvider> BuildServiceProvider() override;
private:
    std::map<std::type_index, ServiceDescriptor> services;
};


#endif //SERVICECOLLECTION_H
