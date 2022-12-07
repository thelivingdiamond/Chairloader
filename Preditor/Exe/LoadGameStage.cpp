#include <ChairLoader/PreyFunction.h>
#include <ImGui/imgui.h>
#include <ModLoader/PathUtils.h>
#include <Preditor/IPreditorEngine.h>
#include "LoadGameStage.h"
#include "Preditor.h"
#include "ConfigManager.h"
#include "ProjectManager.h"

LoadGameStage::LoadGameStage()
{
}

void LoadGameStage::Start()
{
	try
	{
		UpdateProgressText("Loading PreyDll.dll...");

		fs::path projRuntime = ProjectManager::GetProject()->GetRuntimePath();
		IPreditorEngine::InitParams params;
		params.progressCallback = [&](const char* msg) { UpdateProgressText(msg); };
		params.enginePath = ConfigManager::Get()->getGamePath();
		params.engineBinariesPath = params.enginePath / PathUtils::GAME_BIN_DIR;
		params.gameSdkPath = projRuntime / "GameSDK";
		params.userPath = projRuntime / "User";
		params.chairloaderConfigPath = projRuntime / "Config";
		params.minimal = true;
		params.loadGamePaks = true;

		// Create directories
		fs::create_directory(params.gameSdkPath);
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
