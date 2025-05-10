#include <Chairloader/IChairloaderDll.h>
#include "ChairloaderTools.h"
#include "Editor/Editor.h"
#include "Trainer/EntityManager.h"
#include "Trainer/PlayerManager.h"
#include "Trainer/WorldManager.h"
#include "Trainer/SignalSystemManager.h"
#include "DevConsoleDialog.h"
#include "FileBrowser.h"
#include "PerfOverlay.h"
#include "LocalizationUtil.h"
#include "DebugMenu.h"
#include <Chairloader/IChairloaderCore.h>
#include <Prey/CrySystem/ILocalizationManager.h>
#include <Prey/CrySystem/LocalizedStringManager.h>


ChairloaderTools::ChairloaderTools(std::shared_ptr<IChairloaderConfigManager> configManager)
	: m_pConfigManager(std::move(configManager))
{
}

void ChairloaderTools::InitSystem(const Internal::SToolsInitParams& params)
{
	m_bEnableEditor = params.bEnableEditor;
	m_bEnableTrainer = params.bEnableTrainer;

	if (m_bEnableEditor)
		Editor::InitHooks();
}

void ChairloaderTools::InitGame()
{
    m_KeyToggleConsole = gChair->GetCore()->LoadConfigKey("ToggleConsoleKey", eKI_Tilde);
	m_pDevConsole = std::make_unique<DevConsoleDialog>();
	m_pFileBrowser = std::make_unique<FileBrowser>();
	m_pPerfOverlay = std::make_unique<PerfOverlay>();
    m_pLocalizationUtil = std::make_unique<LocalizationUtil>();

	if (m_bEnableTrainer)
	{
		m_pEntityManager = std::make_unique<EntityManager>();
		m_pPlayerManager = std::make_unique<PlayerManager>();
		m_pWorldManager = std::make_unique<WorldManager>();
        m_pSignalSystemManager = std::make_unique<SignalSystemManager>();
	}

	if (gEnv->pSystem->IsDevMode())
	{
		m_pDebugMenu = std::make_unique<DebugMenu>();
	}

	if (m_bEnableEditor)
		m_pEditor = std::make_unique<Editor>();
}

void ChairloaderTools::UpdateBeforeSystem(unsigned updateFlags)
{
	if (m_bEnableEditor)
		m_pEditor->UpdateBeforeSystem();
}

void ChairloaderTools::MainUpdate(unsigned updateFlags)
{
	// Perf info is always visible
	m_pPerfOverlay->Update();

    if(m_pConfigManager->getConfigDirty("Chairloader"))
    {
        m_KeyToggleConsole = gChair->GetCore()->LoadConfigKey("ToggleConsoleKey", eKI_Tilde);
    }

	if (gCL->gui->IsEnabled())
	{
		ShowMainMenuBar();

		if (m_bDrawDevConsole)
			m_pDevConsole->Show(&m_bDrawDevConsole);

		m_pFileBrowser->Draw();

		if (m_bEnableTrainer)
		{
			m_pPlayerManager->update();
			m_pEntityManager->Draw();
			m_pPlayerManager->draw();
			m_pWorldManager->Draw();
            m_pSignalSystemManager->Draw();
		}

		if (m_pDebugMenu)
			m_pDebugMenu->ShowMenu();

		if (m_bEnableEditor)
		{
			m_pEditor->ShowUI();
		}

        m_pLocalizationUtil->draw();
	}
}

bool ChairloaderTools::HandleKeyPress(const SInputEvent& event)
{
	if (event.keyId == m_KeyToggleConsole && event.state == eIS_Pressed)
	{
		bool alt = (event.modifiers & eMM_Alt) != 0;
		auto modLogOnAlt = alt ? DevConsoleDialog::TabRequest::ModLog : DevConsoleDialog::TabRequest::None;

		if (!gCL->gui->IsEnabled())
		{
			gCL->gui->SetEnabled(true);
			m_bDrawDevConsole = true;
			m_pDevConsole->SetTabRequest(modLogOnAlt);
		}
		else
		{
			if (!m_bDrawDevConsole)
			{
				m_bDrawDevConsole = true;
				m_pDevConsole->SetTabRequest(modLogOnAlt);
			}
			else if (alt)
			{
				m_pDevConsole->SetTabRequest(DevConsoleDialog::TabRequest::Toggle);
			}
			else
			{
				m_bDrawDevConsole = false;
			}
		}

		return true;
	}

	if (m_bEnableEditor && m_pEditor->HandleKeyPress(event))
		return true;
	return false;
}

void ChairloaderTools::ShowMainMenuItems()
{
    auto keyName = gChair->GetKeyNames().left.at(m_KeyToggleConsole);
	ImGui::MenuItem("Show Console", keyName.c_str(), &m_bDrawDevConsole);
}

void ChairloaderTools::ShowMainMenuBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("Chairloader"))
		{
			if (ImGui::BeginMenu("Performance"))
			{
				ImGui::Separator();
				m_pPerfOverlay->ShowMenu();
				ImGui::EndMenu();
			}
            m_pLocalizationUtil->drawMenu();
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}
