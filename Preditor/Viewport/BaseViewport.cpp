#include "BaseViewport.h"
#include "ViewportWindow.h"

void Viewport::BaseViewport::OnEnabled()
{
}

void Viewport::BaseViewport::OnDisabled()
{
}

void Viewport::BaseViewport::Update(bool isVisible)
{
}

ImVec4 Viewport::BaseViewport::ShowViewportImage()
{
    auto pWin = static_cast<ViewportWindow*>(gPreditor->pViewportWindow);
    return pWin->ShowViewportImage();
}
