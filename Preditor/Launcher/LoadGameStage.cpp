#include <ChairLoader/PreyFunction.h>
#include <ImGui/imgui.h>
#include <Manager/GamePath.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include "LoadGameStage.h"
#include "PreditorApp.h"
#include "ExtractionOptions.h"

LoadGameStage::LoadGameStage(ExtractionOptions* pExtractionOptions)
{
	m_pExtractionOptions = pExtractionOptions;
}

void LoadGameStage::Start()
{
	try
	{
		UpdateProgressText("Loading PreyDll.dll...");
		
		// Parse game path
		GamePath gamePath;
		{
			fs::path gameRootPath;
			std::string error;

			if (m_pExtractionOptions)
				gameRootPath = m_pExtractionOptions->gamePath;
			else
				gameRootPath = gPreditor->pConfig->GetGamePath().GetGamePath();

			if (!gamePath.TrySetGamePath(gameRootPath, &error))
				throw std::runtime_error("Failed to set game path: " + error);
		}

		// Create main
		if (!m_pExtractionOptions)
			PreditorApp::Get()->CreatePreditorMain();

		IPreditorEngine::InitParams params;
		params.progressCallback = [&](const char* msg) { UpdateProgressText(msg); };
		params.enginePath = gamePath;

		if (m_pExtractionOptions)
		{
			// Extraction doesn't need the full engine
			params.gameSdkPath = m_pExtractionOptions->outputPath / "_temp/GameSDK";
			params.userPath = m_pExtractionOptions->outputPath / "_temp/User";
			params.minimal = true;
			params.caseSensitivePaks = true;
			fs::create_directories(params.gameSdkPath);
			fs::create_directories(params.userPath);
		}
		else
		{
			// Load the whole game
			fs::path projRuntime = gPreditor->pPaths->GetUserPath();
			fs::create_directories(projRuntime);
			params.modDirPath = projRuntime / "GameSDK";
			params.userPath = projRuntime / "User";
			params.chairloaderConfigPath = projRuntime / "Config";
			params.minimal = false;
			params.loadGamePaks = false;
		}

		// Create directories
		fs::create_directory(params.userPath);

		if (!params.chairloaderConfigPath.empty())
			fs::create_directory(params.chairloaderConfigPath);

		IPreditorEngine::Get()->Load(params);
		
		UpdateProgressText("Starting the game engine...");
		if (!IPreditorEngine::Get()->Start(params))
			throw std::runtime_error("Engine failed to start");

		SetStageFinished(PreditorApp::Get()->OnGameLoaded());
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
	PreditorApp::Get()->RefreshUI();
}