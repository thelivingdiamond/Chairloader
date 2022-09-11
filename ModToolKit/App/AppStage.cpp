#include "AppStage.h"
#include "Application.h"

AppStage::AppStage()
{
	Application::Get()->SetStage(this);
}

AppStage::~AppStage()
{
	Application::Get()->SetStage(nullptr);
}

void AppStage::Start()
{
}

void AppStage::Update()
{
}

void AppStage::ShowUI()
{
}

void AppStage::UpdateInternal()
{
	if (!m_bIsStarted)
	{
		m_bIsStarted = true;
		Start();
	}

	Update();
}
