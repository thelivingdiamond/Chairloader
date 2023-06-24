#include <ChairLoader/PreyFunction.h>
#include <ImGui/imgui.h>
#include <Manager/GamePath.h>
#include <Manager/ModInfo.h>
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
			SetUpUserDir();
			fs::path projRuntime = gPreditor->pPaths->GetUserPath();
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
		ImGui::SetNextWindowSize(ImVec2(480, 0));
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

void LoadGameStage::SetUpUserDir()
{
	fs::create_directories(gPreditor->pPaths->GetUserPath());
	
	const fs::path& modsPath = gPreditor->pPaths->GetModsPath();
	fs::path configPath = modsPath / "config";
	fs::create_directory(modsPath);
	fs::create_directory(configPath);

	fs::path chairConfig = configPath / "Chairloader.xml";

	if (!fs::exists(chairConfig))
	{
		// Create Chairloader config.
		// Copy default config
		fs::copy(
			gPreditor->pConfig->GetPreditorRoot() / "chairloader_default.xml",
			chairConfig,
			fs::copy_options::overwrite_existing);

		// Load mod info
		Manager::ModInfo modInfo;
		modInfo.LoadFile(gPreditor->pPaths->GetProjectDirPath() / Manager::ModInfo::XML_FILE_NAME);

		// Open config
		pugi::xml_document chairDoc;
		pugi::xml_parse_result result = chairDoc.load_file(chairConfig.c_str());

		if (!result)
			throw std::runtime_error(fmt::format("Failed to parse Chairloader config: {}", result.description()));

		// Add current project as mod
		{
			pugi::xml_node node = chairDoc.child("Chairloader").child("ModList");

			if (!node)
				throw std::runtime_error("Node Chairloader/ModList not found");

			pugi::xml_node modNode = node.append_child(modInfo.modName.c_str());
			modNode.append_attribute("type").set_value("xmlnode");

			//modName
			node = modNode.append_child("modName");
			node.append_attribute("type").set_value("string");
			node.text().set(modInfo.modName.c_str());
			//loadOrder
			node = modNode.append_child("loadOrder");
			node.append_attribute("type").set_value("int");
			node.text().set(0);
			//enabled
			node = modNode.append_child("enabled");
			node.append_attribute("type").set_value("bool");
			node.text().set(true);
			//deployed
			node = modNode.append_child("deployed");
			node.append_attribute("type").set_value("bool");
			node.text().set(false);
			//Version
			node = modNode.append_child("version");
			node.append_attribute("type").set_value("string");
			node.text().set(modInfo.version.c_str());

			//dllName
			if (!modInfo.dllName.empty())
			{
				fs::path dllPath = gPreditor->pPaths->GetProjectDirPath() / fs::u8path(modInfo.dllName);
				node = modNode.append_child("dllName");
				node.append_attribute("type").set_value("string");
				node.text().set(dllPath.u8string().c_str());
			}

			//hasXML
			node = modNode.append_child("hasXML");
			node.append_attribute("type").set_value("string");
			node.text().set(modInfo.hasXML);
		}

		// Save config
		if (!chairDoc.save_file(chairConfig.c_str()))
			throw std::runtime_error("Failed to save Chairloader config");
	}
}
