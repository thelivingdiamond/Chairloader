#pragma once
#include "BaseViewport.h"
#include "MouseGuard.h"

namespace Viewport
{

class SceneViewport : public BaseViewport
{
public:
    // IViewport
    virtual bool NeedCustomRender() override { return false; }
    virtual void CustomRender() override {}
    virtual bool EnableMouseEvents() override { return true; }

    // BaseViewport
    virtual void OnEnabled() override;
    virtual void OnDisabled() override;
    virtual void ShowUI() override;

private:
    MouseGuard m_InputEnabled;
};

} // namespace Viewport
