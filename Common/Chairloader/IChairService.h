//
// Created by theli on 5/5/2025.
//

#ifndef ICHAIRSERVICE_H
#define ICHAIRSERVICE_H

template <typename Derived>
struct IChairService {
    
    virtual ~IChairService() = default;

    /// static identifier for this interface
    static const char* Name() {
        return Derived::NameImpl();
    }

    /// instance method (rarely used, but sometimes handy)
    virtual const char* name() const {
        return Derived::Name();
    }
};

#endif //ICHAIRSERVICE_H
