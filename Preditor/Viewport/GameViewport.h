#pragma once
#include <Preditor/MouseGuard.h>
#include "BaseViewport.h"

namespace Viewport
{

class GameViewport : public BaseViewport
{
public:
    GameViewport();

    // IViewport
    virtual bool NeedCustomRender() override { return false; }
    virtual void CustomRender() override {}
    virtual EViewportInputMode GetInputMode() override { return m_InputMode; }

    // BaseViewport
    virtual void OnDisabled() override;
    virtual void Update(bool isVisible) override;
    virtual void ShowUI() override;

private:
    MouseGuard m_InputEnabled;
    MouseGuard m_InputLocked;
    EViewportInputMode m_InputMode = EViewportInputMode::None;

    void SetInputMode(EViewportInputMode mode);
};

} // namespace Viewport
