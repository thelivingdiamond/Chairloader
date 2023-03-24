#include <ChairLoader/PreyFunction.h>
#include <ImGui/imgui.h>
#include <Manager/GamePath.h>
#include <Preditor/Project/ProjectManager.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include "LoadGameStage.h"
#include "Preditor.h"
#include "ConfigManager.h"

LoadGameStage::LoadGameStage()
{
}

void LoadGameStage::Start()
{
	try
	{
		UpdateProgressText("Loading PreyDll.dll...");
		
		// Parse game path
		GamePath gamePath;
		{
			const fs::path& configGamePath = ConfigManager::Get()->getGamePath();
			std::string error;

			if (!gamePath.TrySetGamePath(configGamePath, &error))
				throw std::runtime_error("Failed to set game path: " + error);
		}

		fs::path projRuntime = ProjectManager::GetProject()->GetRuntimePath();
		IPreditorEngine::InitParams params;
		params.progressCallback = [&](const char* msg) { UpdateProgressText(msg); };
		params.enginePath = gamePath;
		params.modDirPath = projRuntime / "GameSDK";
		params.userPath = projRuntime / "User";
		params.chairloaderConfigPath = projRuntime / "Config";
		params.minimal = false;
		params.loadGamePaks = false;

		// Create directories
		fs::create_directory(params.userPath);
		fs::create_directory(params.chairloaderConfigPath);

		IPreditorEngine::Get()->Load(params);
		
		UpdateProgressText("Starting the game engine...");
		if (!IPreditorEngine::Get()->Start(params))
			throw std::runtime_error("Engine failed to start");

		SetStageFinished();
	}
	catch (const std::exception& e)
	{
		m_ErrorText = e.what();
	}
}

void LoadGameStage::ShowUI(bool * bOpen)
{
	if (m_ErrorText.empty())
	{
		// Progress dialog
		int flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;
		ImGui::SetNextWindowSize(ImVec2(480, 72));
		if (ImGui::Begin("Initializing Game...###LoadGameStage", nullptr, flags))
		{
			ImGui::Text("%s", m_ProgressText.c_str());
			ImGui::ProgressBar((float)m_ProgressCount / MAX_PROGRESS);
		}
		ImGui::End();
	}
	else
	{
		// Error dialog
		ImGui::SetNextWindowSize(ImVec2(480, 200));
		if (ImGui::Begin("Initialization Failed###LoadGameStage", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings))
		{
			ImGui::TextWrapped("The Mod Toolkit failed to load.\n\n%s", m_ErrorText.c_str());
		}
		ImGui::End();
	}
}

void LoadGameStage::UpdateProgressText(const std::string& text)
{
	m_ProgressText = text;
	m_ProgressCount++;
	Preditor::Get()->RefreshUI();
}
