//
// Created by theli on 4/27/2025.
//

#ifndef ISERVICEPROVIDER_H
#define ISERVICEPROVIDER_H

struct IChairServiceProvider {
    virtual ~IChairServiceProvider() = default;

    virtual void *GetService(const std::string &serviceType) = 0;

    template<typename T>
    T *GetService(const std::string &serviceType) {
        return static_cast<T *>(GetService(serviceType));
    }

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
