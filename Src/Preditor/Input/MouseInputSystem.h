#pragma once
#include <Preditor/Input/IMouseInputSystem.h>

struct IDirectInput8A;
struct IDirectInputDevice8A;

namespace Input
{

class MouseInputSystem final : public IMouseInputSystem
{
public:
    MouseInputSystem();
    ~MouseInputSystem();

    // IMouseInputSystem
    virtual void SetExclusiveInputActive(bool state) override;
    virtual bool IsExclusiveInputActive() override { return m_IsActive; }
    virtual Vec2 PeekMouseDelta() override;
    virtual Vec2 GetMouseDelta() override;

private:
    static constexpr int BUF_SIZE = 4096;

    WIN_HWND m_hWnd = nullptr;
    ICVar* m_pMouseSens = nullptr;
    IDirectInput8A* m_pDI = nullptr;
    IDirectInputDevice8A* m_pDevice = nullptr;

    bool m_IsActive = false;
    Vec2 m_Delta = Vec2(0, 0);

    //! Acquires the DInput device.
    //! @returns whether it was aquired successfully.
    bool Acquire();
};

} // namespace Input
