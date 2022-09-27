#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include "App/AppStage.h"
#include "ModToolKit.h"
#include "LoadGameStage.h"

// Dear God, No
#include "../ChairLoader/DevConsoleDialog.h"


class ModToolKit::SystemUserCallback : public ISystemUserCallback
{
public:
	bool OnError(const char* szErrorString) override
	{
		if (IsDebuggerPresent())
			__debugbreak();

		int btn = ShowMessage(szErrorString, "CrySystem Error", MB_ABORTRETRYIGNORE | MB_ICONERROR);

		if (btn == IDABORT)
			return true; // true halts execution
		else
			return false;
	}

	bool OnSaveDocument() override { return true; }

	void OnProcessSwitch() override {}

	void OnInitProgress(const char* sProgressMsg) override {
		if (ModToolKit::Get()->m_pLoadGameStage)
			ModToolKit::Get()->m_pLoadGameStage->UpdateProgressText(std::string("CrySystem: ") + sProgressMsg);
	}

	void OnInit(ISystem* pSystem) override
	{
		static_cast<CSystem*>(pSystem)->SetDevMode(true);
		ModuleInitISystem(pSystem, "ModToolKit");
		gEnv->pLog->SetVerbosity(4);
	}

	void GetMemoryUsage(ICrySizer* pSizer) override {}
};

ModToolKit::SystemUserCallback ModToolKit::m_SystemUserCallback;

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
	m_pLoadGameStage = std::make_unique<LoadGameStage>(&m_GameModule, &m_SystemUserCallback);
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
            m_pFlowgraphEditor = std::make_unique<FlowgraphEditor>();
			m_pTestStage = std::make_unique<TestStage>();
		}
	}
}

void ModToolKit::ShowUI()
{
	if (m_pDevConsole)
		m_pDevConsole->Show(nullptr);
    if(m_pFlowgraphEditor)
        m_pFlowgraphEditor->Draw(nullptr);

}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	auto pApp = std::make_unique<ModToolKit>();
	return pApp->Run();
}
