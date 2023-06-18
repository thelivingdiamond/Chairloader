#pragma once
#include <Preditor/Input/Common.h>

struct IKeyMap;

struct IKeyboardInputSystem
{
    virtual ~IKeyboardInputSystem() {}

    //! @returns the key map.
    virtual IKeyMap* GetKeyMap() = 0;
};
