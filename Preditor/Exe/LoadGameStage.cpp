#include <ChairLoader/PreyFunction.h>
#include <ImGui/imgui.h>
#include <ModLoader/PathUtils.h>
#include <Prey/CryGame/IGameStartup.h>
#include <Prey/CryGame/IGameRef.h>
#include <mem.h>
#include "LoadGameStage.h"
#include "GameModule.h"
#include "Preditor.h"
//#include "Prey/GameDll/ark/ArkGame.h"
#include <Prey/CryAction/CryAction.h>
#include <Prey/CrySystem/IEngineModule.h>

LoadGameStage::LoadGameStage(GameModule* pModule)
{
	m_pMod = pModule;
}

void LoadGameStage::Start()
{
	try
	{
		UpdateProgressText("Loading PreyDll.dll...");
		m_pMod->LoadDll();
		
		UpdateProgressText("Starting the game engine...");
		m_pMod->InitGame([&](const char* msg) { UpdateProgressText(msg); });

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
