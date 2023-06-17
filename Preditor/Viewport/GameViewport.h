#pragma once
#include "BaseViewport.h"
#include "MouseGuard.h"

namespace Viewport
{

class GameViewport : public BaseViewport
{
public:
    GameViewport();

    // IViewport
    virtual bool NeedCustomRender() override { return false; }
    virtual void CustomRender() override {}
    virtual bool EnableMouseEvents() override { return true; }

    // BaseViewport
    virtual void OnDisabled() override;
    virtual void Update(bool isVisible) override;
    virtual void ShowUI() override;

private:
    MouseGuard m_InputEnabled;
    MouseGuard m_InputLocked;

    void SetInputEnabled(bool state);
};

} // namespace Viewport
