#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CryGame/IGameStartup.h>
#include "App/AppStage.h"
#include "ModToolKit.h"
#include "LoadGameStage.h"

// Dear God, No
#include "../ChairLoader/DevConsoleDialog.h"

class ConsoleStdoutSink : public IOutputPrintSink {
public:
	void Init() {
		gEnv->pConsole->AddOutputPrintSink(this);
		PrintExistingMessages();
	}

	void Print(const char* inszText) override {
		OutputDebugStringA(inszText);
		OutputDebugStringA("\n");
	}

	void PrintExistingMessages() {
		int count = gEnv->pConsole->GetLineCount();

		for (int i = count - 1; i >= 0; i--) {
			char buf[1024];
			gEnv->pConsole->GetLineNo(i, buf, sizeof(buf));
			OutputDebugStringA(buf);
			OutputDebugStringA("\n");
		}
	}
};

ConsoleStdoutSink g_StdoutConsole;

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
			ModToolKit::Get()->m_pLoadGameStage->UpdateProgressText(sProgressMsg);
	}

	void OnInit(ISystem* pSystem) override
	{
		static_cast<CSystem*>(pSystem)->SetDevMode(true);
		ModuleInitISystem(pSystem, "ModToolKit");
		gEnv->pLog->SetVerbosity(4);
		g_StdoutConsole.Init();

		// Register fake cvars
		gEnv->pConsole->RegisterFloat("e_ViewDistMin", 0.0f, VF_NULL);
		gEnv->pConsole->RegisterFloat("e_ViewDistRatio", 0.0f, VF_NULL);
		gEnv->pConsole->RegisterFloat("e_CastShadowViewDistMin", 0.0f, VF_NULL);
		gEnv->pConsole->RegisterFloat("e_CastShadowViewDistRatio", 0.0f, VF_NULL);
		gEnv->pConsole->RegisterFloat("e_ViewDistRatioCustom", 0.0f, VF_NULL);
		gEnv->pConsole->RegisterFloat("e_ViewDistRatioDetail", 0.0f, VF_NULL);
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

	void ShowUI(bool * bOpen) override
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

ModToolKit::~ModToolKit()
{
	if (m_pGameStartup)
		m_pGameStartup->Shutdown();
}

void ModToolKit::Update()
{
	if (gEnv)
		gEnv->pSystem->Update();

	if (GetStage()->IsStageFinished())
	{
		if (m_pLoadGameStage)
		{
			m_pGameStartup = m_pLoadGameStage->GetIGameStartup();
			m_pLoadGameStage.reset();
			m_pDevConsole = std::make_unique<DevConsoleDialog>();
            m_pFlowgraphEditor = std::make_unique<FlowgraphEditor>();
			m_pTestStage = std::make_unique<TestStage>();
		}
	}
}

void ModToolKit::ShowUI(bool* bOpen)
{
	if (m_pDevConsole)
		m_pDevConsole->Show(bOpen);
    if(m_pFlowgraphEditor)
        m_pFlowgraphEditor->Draw(bOpen);
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	auto pApp = std::make_unique<ModToolKit>();
	return pApp->Run();
}
