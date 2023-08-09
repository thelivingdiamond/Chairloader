#include "BaseViewport.h"
#include "ViewportWindow.h"

void Viewport::BaseViewport::OnEnabled()
{
    assert(!m_IsActive);
    m_IsActive = true;
}

void Viewport::BaseViewport::OnDisabled()
{
    assert(m_IsActive);
    m_IsActive = false;
}

void Viewport::BaseViewport::Update(bool isVisible)
{
}

ImVec4 Viewport::BaseViewport::ShowViewportImage()
{
    auto pWin = static_cast<ViewportWindow*>(gPreditor->pViewportWindow);
    return pWin->ShowViewportImage();
}
