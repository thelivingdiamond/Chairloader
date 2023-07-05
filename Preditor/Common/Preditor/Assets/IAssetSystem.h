#pragma once
#include <Preditor/Assets/Common.h>

class ManagedWindow;

//! Handles asset import (file conversion from normal formats to engine formats)
//! and asset merging (like ChairManager).
struct IAssetSystem
{
    //! Creates an IAssetSystem instance.
    static std::unique_ptr<IAssetSystem> CreateInstance();

    virtual ~IAssetSystem() {}

    //! InitSystem callback.
    virtual void InitSystem() = 0;

    //! Per-frame update.
    virtual void Update() = 0;

    //! Runs merging next frame.
    virtual void RequestMerging() = 0;

    //! Shows the Main Menu Bar -> File menu.
    virtual void ShowMainMenu() = 0;
};
