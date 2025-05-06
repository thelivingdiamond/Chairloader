//
// Created by theli on 4/27/2025.
//

#ifndef SERVICECOLLECTION_H
#define SERVICECOLLECTION_H
#include <map>

#include "ServiceDescriptor.h"
#include "Chairloader/IChairServiceCollection.h"


class ServiceCollection : public IChairServiceCollection {
public:
    ~ServiceCollection() override = default;

    void AddService(const std::string &serviceType, EChairServiceLifetime lifetime,
                    ServiceConstructor constructor) override;

    std::unique_ptr<IChairServiceProvider> BuildServiceProvider() override;

private:
    std::map<std::string, ServiceDescriptor> m_ServiceDescriptors;

    bool m_Built = false;
};


#endif //SERVICECOLLECTION_H
