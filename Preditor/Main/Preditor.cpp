#include <Preditor/IChairloaderToolsPreditor.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include "UI/PreditorUI.h"
#include "Preditor.h"

void Main::Preditor::InitSystem()
{
}

void Main::Preditor::InitGame()
{
    m_pChairTools = IChairloaderToolsPreditor::CreateInstance(gPreditor->pEngine->GetIChairToPreditor());
    m_pUI = std::make_unique<PreditorUI>();
}

void Main::Preditor::ShutdownGame()
{
    m_pUI = nullptr;
    m_pChairTools = nullptr;
}

void Main::Preditor::ShutdownSystem()
{
}

void Main::Preditor::Update()
{
}

void Main::Preditor::ShowUI()
{
}
