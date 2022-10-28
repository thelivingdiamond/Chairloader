#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CryGame/IGameStartup.h>
#include "App/AppStage.h"
#include "ModToolKit.h"
#include "LoadGameStage.h"

// Dear God, No
#include "../ChairLoader/DevConsoleDialog.h"

ModToolKit::ModToolKit()
{
    m_Config.LoadFromXML(); // TODO:
    m_ConfigValidateStage = std::make_unique<ConfigValidationStage>();
}

ModToolKit::~ModToolKit()
{
	m_GameModule.Shutdown();
}

void ModToolKit::Update()
{
	if (gEnv)
		gEnv->pSystem->Update();

	if (GetStage()->IsStageFinished())
	{
        if(m_ConfigValidateStage){
            m_ConfigValidateStage.reset();
            m_pLoadGameStage = std::make_unique<LoadGameStage>(&m_GameModule);
        }
        else if (m_pLoadGameStage) {
			m_pLoadGameStage.reset();
			m_pDevConsole = std::make_unique<DevConsoleDialog>();
            m_pProjectSelectStage = std::make_unique<ProjectSelectStage>();
		}
        else if (m_pProjectSelectStage){
            QuitApp();
        }
	}
}

void ModToolKit::ShowUI(bool* bOpen)
{
    if(m_Config.isShown())
        m_Config.ShowUI();
	if (m_pDevConsole)
		m_pDevConsole->Show(bOpen);
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	auto pApp = std::make_unique<ModToolKit>();
	return pApp->Run();
}
