#include <Prey/CrySystem/Profiling.h>
#include <WindowManager/WindowManager.h>
#include "PreditorUI.h"

void Main::PreditorUI::ShowUI()
{
    CRY_PROFILE_MARKER("PreditorUI::ShowUI");
    ShowMainMenuBar();
    WindowManager::Get().Update();
}

void Main::PreditorUI::ShowMainMenuBar()
{

}
