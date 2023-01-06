#include "Application.h"
#include "AppImGui.h"
#include "AppStage.h"
#include <ChairLoader/PreyFunction.h>
#include <Prey/CryCore/Platform/platform_impl.inl>

static Application* g_pApp;

Application* Application::Get()
{
	return g_pApp;
}

Application::Application()
{
	assert(!g_pApp);
	g_pApp = this;
	m_ProgramPath = fs::current_path();
	SetAppImGui(std::make_unique<AppImGui>());
}

Application::~Application()
{
	assert(g_pApp == this);
	g_pApp = nullptr;
	m_pImGui = nullptr;
}

int Application::Run()
{
	m_bIsRunning = true;

	while (m_bIsRunning)
	{
		bool pushedMarker = gEnv && gEnv->pJobManager;
		if (pushedMarker)
			gEnv->pJobManager->PushProfilingMarker("Application::Run");

		m_pImGui->BeginFrame();
		Update();
//        assert(false);
		m_pCurrentStage->UpdateInternal();
		ShowUI(&m_bIsRunning);
		m_pCurrentStage->ShowUI(&m_bIsRunning);
		PostUpdate();

		m_pImGui->EndFrame();

		if (pushedMarker)
			gEnv->pJobManager->PopProfilingMarker();
	}

	return 0;
}

void Application::QuitApp()
{
	m_bIsRunning = false;
}

void Application::SetStage(AppStage* stage)
{
	CRY_ASSERT_MESSAGE(!stage || !m_pCurrentStage, "Call SetStage(nullptr) first");
	m_pCurrentStage = stage;
}

void Application::RefreshUI()
{
	ShowUI(&m_bIsRunning);
	m_pCurrentStage->ShowUI(&m_bIsRunning);

	m_pImGui->EndFrame();
	m_pImGui->BeginFrame();
}

void Application::SetAppImGui(std::shared_ptr<IAppImGui> ptr)
{
	m_pImGui = std::move(ptr);
}

void Application::Update()
{
}

void Application::ShowUI(bool* bOpen)
{
}

void Application::PostUpdate()
{
}
