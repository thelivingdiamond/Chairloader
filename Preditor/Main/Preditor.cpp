#include <Preditor/IChairloaderToolsPreditor.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/Input/IPreditorInput.h>
#include "Project/Project.h"
#include "Project/UserProjectSettings.h"
#include "UI/PreditorUI.h"
#include "Preditor.h"
#include "SceneEditorManager.h"

std::unique_ptr<IPreditor> IPreditor::CreateInstance()
{
    return std::make_unique<Main::Preditor>();
}

Main::Preditor::Preditor()
{
    m_pProject = std::make_unique<Project>(gPreditor->pPaths->GetProjectDirPath());
    m_pUserSettings = std::make_unique<UserProjectSettings>(gPreditor->pPaths->GetUserPath() / IUserProjectSettings::FILE_NAME);
    gPreditor->pProject = m_pProject.get();
    gPreditor->pUserSettings = m_pUserSettings.get();
}

Main::Preditor::~Preditor()
{
    gPreditor->pProject = nullptr;
    gPreditor->pUserSettings = nullptr;
}

void Main::Preditor::InitSystem()
{
}

void Main::Preditor::InitGame()
{
    m_pInput = IPreditorInput::CreateInstance();
    gPreditor->pInput = m_pInput.get();

    m_pSceneEditorManager = std::make_unique<SceneEditorManager>();

    m_pChairTools = IChairloaderToolsPreditor::CreateInstance(gPreditor->pEngine->GetIChairToPreditor());
    m_pUI = std::make_unique<PreditorUI>();
}

void Main::Preditor::ShutdownGame()
{
    m_pUI = nullptr;
    m_pChairTools = nullptr;

    m_pSceneEditorManager = nullptr;

    gPreditor->pInput = nullptr;
    m_pInput = nullptr;
}

void Main::Preditor::ShutdownSystem()
{
}

void Main::Preditor::Update()
{
    m_pUserSettings->Update();
}

void Main::Preditor::ShowUI()
{
    m_pUI->ShowUI();
}