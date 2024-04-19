#pragma once
#include <Preditor/Input/Common.h>

struct IMouseInputSystem
{
    virtual ~IMouseInputSystem() {}

    //! Whether mouse input is active. Cursor will be hidden.
    //! @{
    virtual void SetExclusiveInputActive(bool state) = 0;
    virtual bool IsExclusiveInputActive() = 0;
    //! @}

    //! @returns mouse delta since last GetMouseDelta call.
    //! @{
    virtual Vec2 PeekMouseDelta() = 0;
    virtual Vec2 GetMouseDelta() = 0;
    //! @}
};
