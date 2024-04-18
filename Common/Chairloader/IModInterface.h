#pragma once

//! Base interface for all interfaces exposed by mods in QueryInterface.
struct IModInterface
{
    // Define those in your interface
    // static constexpr char IFACE_NAME[] = "IModName001";
    // static constexpr int VERSION = 1;

    virtual ~IModInterface() {}

    //! Gets the interface minor version. Incremented when new methods are added.
    //! @returns The interface version.
    virtual int GetInterfaceVersion() = 0;
};
