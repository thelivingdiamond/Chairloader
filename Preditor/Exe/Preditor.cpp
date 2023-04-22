#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CryGame/IGameStartup.h>
#include <WindowManager/WindowManager.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include "App/AppStage.h"
#include "Preditor.h"
#include "LoadGameStage.h"

ChairloaderGlobalEnvironment* gCL = nullptr;

Preditor::Preditor()
{
    m_Config.LoadFromXML(); // TODO:
    SetStage(std::make_unique<ConfigValidationStage>());
}

Preditor::~Preditor()
{
    IPreditorEngine::Get()->Shutdown();
}

void Preditor::OnConfigValidated()
{
    m_pProjectManager = std::make_unique<ProjectManager>();
}

AppStagePtr Preditor::OnGameLoaded()
{
    IPreditorEngine::Get()->SetAppImGui();
    std::unique_ptr<ProjectStage> pProjectStage = std::make_unique<ProjectStage>();
    m_pLookingGlass = std::make_unique<LookingGlass>();
    m_pLookingGlass->Init();

    return pProjectStage;
}

void Preditor::Update()
{
    // Only the main stage has a dedicated main window.
    // Dock space needs to be created before any windows.
    if (ProjectStage::Get())
        ImGui::DockSpaceOverViewport();
}

void Preditor::ShowUI(bool* bOpen)
{
    if(m_Config.isShown())
        m_Config.ShowUI();
    if (GetStage() == ProjectStage::Get() && m_pLookingGlass) // TODO: Hack to display LG after DockSpaceOverViewport
        m_pLookingGlass->ShowUI();
}

void Preditor::PostUpdate()
{
    // Engine must be updated at the end of the tick because it will end the ImGui frame.
    if (!IPreditorEngine::Get()->Update())
        QuitApp();
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	auto pApp = std::make_unique<Preditor>();
	return pApp->Run();
}
