#pragma once
#include <Prey/CryInput/IHardwareMouse.h>

//! Helper class to call IncrementCounter and DecrementCounter the correct number of times.
class MouseGuard : NoCopy
{
public:
    MouseGuard() {}
    ~MouseGuard()
    {
        // Restore counter
        SetIncremented(false);
    }

    bool IsIncremented() { return m_IsIncremented; }

    void SetIncremented(bool state)
    {
        if (m_IsIncremented == state)
            return;

        m_IsIncremented = state;

        if (state)
            gEnv->pHardwareMouse->IncrementCounter();
        else
            gEnv->pHardwareMouse->DecrementCounter();
    }

private:
    bool m_IsIncremented = false;
};
