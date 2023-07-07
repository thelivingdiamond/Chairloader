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
    virtual bool EnableMouseEvents() override { return m_InputActive; }

    // BaseViewport
    virtual void OnDisabled() override;
    virtual void Update(bool isVisible) override;
    virtual void ShowUI() override;

private:
    MouseGuard m_InputEnabled;
    MouseGuard m_InputLocked;
    bool m_InputActive = false;

    void SetInputEnabled(bool state);
};

} // namespace Viewport
