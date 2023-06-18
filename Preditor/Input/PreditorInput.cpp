#include <WindowManager/WindowManager.h>
#include "PreditorInput.h"

std::unique_ptr<IPreditorInput> IPreditorInput::CreateInstance()
{
    return std::make_unique<Input::PreditorInput>();
}

Input::PreditorInput::PreditorInput()
{
    m_pDbgWindow = WindowManager::Get().Create<InputDebuggerWindow>();
}

Input::PreditorInput::~PreditorInput()
{
}
