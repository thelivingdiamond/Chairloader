#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CryGame/IGameStartup.h>
#include <WindowManager/WindowManager.h>
#include <Preditor/IPreditorEngine.h>
#include "App/AppStage.h"
#include "Preditor.h"
#include "LoadGameStage.h"

// Dear God, No
//#include "../ChairLoader/DevConsoleDialog.h"

ChairloaderGlobalEnvironment* gCL = nullptr;

Preditor::Preditor()
{
    m_Config.LoadFromXML(); // TODO:
    m_ConfigValidateStage = std::make_unique<ConfigValidationStage>();
}

Preditor::~Preditor()
{
    IPreditorEngine::Get()->Shutdown();
}

void Preditor::Update()
{
	if (GetStage()->IsStageFinished())
	{
        if(m_ConfigValidateStage)
        {
            m_ConfigValidateStage.reset();
            m_pProjectManager = std::make_unique<ProjectManager>();
            m_pProjectSelectStage = std::make_unique<ProjectSelectStage>();
        }
        else if (m_pProjectSelectStage)
        {
            m_pProjectSelectStage.reset();
            m_pLoadGameStage = std::make_unique<LoadGameStage>();
        }
        else if (m_pLoadGameStage)
        {
			m_pLoadGameStage.reset();
            IPreditorEngine::Get()->SetAppImGui();
            m_pProjectStage = std::make_unique<ProjectStage>();
		}
        else if (m_pProjectStage)
        {
            QuitApp();
        }
	}

    // Only the main stage has a dedicated main window.
    // Dock space needs to be created before any windows.
    if (m_pProjectStage)
        ImGui::DockSpaceOverViewport();
}

void Preditor::ShowUI(bool* bOpen)
{
    if(m_Config.isShown())
        m_Config.ShowUI();
}

void Preditor::PostUpdate()
{
    // Engine must be updated at the ent of the tick because it will end the ImGui frame.
    if (!IPreditorEngine::Get()->Update())
        QuitApp();
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	auto pApp = std::make_unique<Preditor>();
	return pApp->Run();
}
