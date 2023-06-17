#include <Preditor/Engine/IPreditorEngine.h>
#include "SceneViewport.h"

void Viewport::SceneViewport::OnEnabled()
{
    // Scene doesn't use engine mouse input
    m_InputEnabled.SetIncremented(true);
    gPreditor->pEngine->SetGameInputEnabled(false);
}

void Viewport::SceneViewport::OnDisabled()
{
    // Restore counter
    m_InputEnabled.SetIncremented(false);
}

void Viewport::SceneViewport::ShowUI()
{
    // TODO 2023-06-17
}
