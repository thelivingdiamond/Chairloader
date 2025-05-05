//
// Created by theli on 4/27/2025.
//

#ifndef SERVICEPROVIDER_H
#define SERVICEPROVIDER_H

#include <any>
#include <map>
#include <vector>
#include <Chairloader/IChairServiceProvider.h>

struct ServiceDescriptor;

class ServiceProvider : public IChairServiceProvider {
public:
    ServiceProvider(std::map<std::string, std::string> &serviceToImplementationMap,
                    std::map<std::string, ServiceDescriptor> &implementationDescriptors)
        : m_ServiceToImplementationMap(std::move(serviceToImplementationMap)),
          m_ImplementationDescriptors(std::move(implementationDescriptors)) {
    }

    ~ServiceProvider() override = default;

    void *GetService(const std::string &serviceType) override;

private:
    std::map<std::string, std::string> m_ServiceToImplementationMap;

    std::map<std::string, ServiceDescriptor> m_ImplementationDescriptors;

    std::map<std::string, std::shared_ptr<void> > m_ServiceInstances;

    std::vector<std::string> m_ServiceResolutionStack;
};


#endif //SERVICEPROVIDER_H
