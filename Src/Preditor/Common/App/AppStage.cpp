#include "AppStage.h"
#include "Application.h"

AppStage::AppStage()
{
}

AppStage::~AppStage()
{
}

void AppStage::SetStageFinished(AppStagePtr&& pNextStage)
{
	m_bIsFinished = true;
	m_pNextStage = std::move(pNextStage);
}

void AppStage::Start()
{
}

void AppStage::Update()
{
}

void AppStage::ShowUI(bool *bOpen)
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
