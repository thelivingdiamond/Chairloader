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

    void AddService(const std::string &serviceType, const std::string &implementationType,
                    const ServiceConstructor &factory) override;

    void AssociateService(const std::string &serviceType, const std::string &implementationType) override;

    std::unique_ptr<IChairServiceProvider> BuildServiceProvider() override;

private:
    std::map<std::string, std::string> m_ServiceToImplementationMap;
    std::map<std::string, ServiceDescriptor> m_ImplementationDescriptors;

    bool m_Built = false;
};


#endif //SERVICECOLLECTION_H
