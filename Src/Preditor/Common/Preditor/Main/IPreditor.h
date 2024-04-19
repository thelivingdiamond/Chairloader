#pragma once

//! Main Preditor module interface.
struct IPreditor
{
    //! Creates the IPreditor instance.
    static std::unique_ptr<IPreditor> CreateInstance();

    virtual ~IPreditor() {}

    //! Initialization functions
    //! @{
    virtual void InitSystem() = 0;
    virtual void InitGame() = 0;
    virtual void ShutdownGame() = 0;
    virtual void ShutdownSystem() = 0;
    //! @}
    
    //! App update functions
    //! @}
    virtual void Update() = 0;
    virtual void ShowUI() = 0;
    //! @{
};
