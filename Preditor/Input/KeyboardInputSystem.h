#pragma once
#include <Preditor/Input/IKeyboardInputSystem.h>
#include "KeyMap.h"

namespace Input
{

class KeyboardInputSystem : public IKeyboardInputSystem
{
public:
    // IKeyboardInputSystem
    virtual IKeyMap* GetKeyMap() override { return &m_KeyMap; }

private:
    KeyMap m_KeyMap;
};

} // namespace Input
