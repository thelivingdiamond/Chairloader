#include <Chairloader/IChairloaderDll.h>
#include "ChairloaderTools.h"
#include "Editor/Editor.h"
#include "Trainer/EntityManager.h"
#include "Trainer/PlayerManager.h"
#include "Trainer/WorldManager.h"
#include "DevConsoleDialog.h"
#include "FileBrowser.h"
#include "PerfOverlay.h"

std::unique_ptr<Internal::IChairloaderTools> Internal::IChairloaderTools::CreateInstance()
{
	return std::make_unique<ChairloaderTools>();
}

void ChairloaderTools::InitSystem(const Internal::SToolsInitParams& params)
{
	m_bEnableEditor = params.bEnableEditor;
	m_bEnableTrainer = params.bEnableTrainer;

	Editor::InitHooks();
}

void ChairloaderTools::InitGame()
{
	m_pDevConsole = std::make_unique<DevConsoleDialog>();
	m_pFileBrowser = std::make_unique<FileBrowser>();
	m_pPerfOverlay = std::make_unique<PerfOverlay>();

	if (m_bEnableTrainer)
	{
		m_pEntityManager = std::make_unique<EntityManager>();
		m_pPlayerManager = std::make_unique<PlayerManager>();
		m_pWorldManager = std::make_unique<WorldManager>();
	}
}

void ChairloaderTools::PreUpdate()
{
	if (m_bEnableEditor)
		m_pEditor->Update();

	// Perf info is always visible
	if (m_bDrawPerfOverlay)
		m_pPerfOverlay->Update();

	if (gCL->gui->IsEnabled())
	{
		if (m_bDrawDevConsole)
			m_pDevConsole->Show(&m_bDrawDevConsole);

		m_pFileBrowser->Draw();

		if (m_bEnableTrainer)
		{
			m_pPlayerManager->update();

			if (m_bDrawEntityManager)
				m_pEntityManager->Draw();
			if (m_bDrawPlayerManager)
				m_pPlayerManager->draw();
			if (m_bDrawWorldManager)
				m_pWorldManager->Draw();
		}

		if (m_bEnableEditor)
		{
			m_pEditor->ShowUI();
		}
	}
}

bool ChairloaderTools::HandleKeyPress(const SInputEvent& event)
{
	if (m_bEnableEditor && m_pEditor->HandleKeyPress(event))
		return true;
	return false;
}
