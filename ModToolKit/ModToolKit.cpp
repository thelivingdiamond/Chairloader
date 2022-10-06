#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CryGame/IGameStartup.h>
#include "App/AppStage.h"
#include "ModToolKit.h"
#include "LoadGameStage.h"

// Dear God, No
#include "../ChairLoader/DevConsoleDialog.h"

class TestStage : public AppStage
{
public:
	void Update() override
	{

	}

	void ShowUI() override
	{
		if (ImGui::Begin("Test"))
		{
			ImGui::Text("Test");
		}
		ImGui::End();
	}
};

ModToolKit::ModToolKit()
{
	m_Config.LoadFromXML(""); // TODO:
	m_pLoadGameStage = std::make_unique<LoadGameStage>(&m_GameModule);
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
		if (m_pLoadGameStage)
		{
			m_pLoadGameStage.reset();
			m_pDevConsole = std::make_unique<DevConsoleDialog>();
			m_pTestStage = std::make_unique<TestStage>();
		}
	}
}

void ModToolKit::ShowUI()
{
	if (m_pDevConsole)
		m_pDevConsole->Show(nullptr);
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	auto pApp = std::make_unique<ModToolKit>();
	return pApp->Run();
}
