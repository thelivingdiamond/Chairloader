#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/Engine/ISimulationController.h>
#include "SimControlWindow.h"

SimControlWindow::SimControlWindow()
{
	SetTitle("Simulation");
	SetPersistentID("SimControlWindow");
	SetCloseable(false);
}

void SimControlWindow::ShowMenu()
{
	Engine::ISimulationController* pSC = IPreditorEngine::Get()->GetSimController();
	Engine::ESimulationMode simMode = pSC->GetSimulationMode();
	const char* simModeText = nullptr;

	switch (simMode)
	{
	case Engine::ESimulationMode::Game: simModeText = "Game"; break;
	case Engine::ESimulationMode::LevelEdit: simModeText = "Level Edit"; break;
	}

	ImGui::TextDisabled("(%s Mode)", simModeText);

	// Pause Toggle
	bool isPaused = pSC->IsPaused();
	if (ImGui::Checkbox("Pause", &isPaused))
		pSC->SetPaused(isPaused);

	ImGui::Separator();

	// Single Step
	if (ImGui::MenuItem("Single Step"))
		pSC->RunSingleStep(m_flTimeStepMs / 1000.0f);

	// Time step input
	ImGui::InputFloat("dt (ms)", &m_flTimeStepMs);

	// FPS buttons
	for (float fps : DEFAULT_FPS)
	{
		char buf[16];
		snprintf(buf, sizeof(buf), "%.0f FPS", fps);
		if (ImGui::Button(buf))
			m_flTimeStepMs = 1000.0f / fps;
		ImGui::SameLine();
	}

	ImGui::NewLine();
}

void SimControlWindow::ShowContents()
{
	Engine::ISimulationController* pSC = IPreditorEngine::Get()->GetSimController();
	Engine::ESimulationMode simMode = pSC->GetSimulationMode();
	
	bool isGameRunning = true; // Whether can pause/single-step

	{
		// Edit Mode Play/Pause
		ImGui::BeginDisabled(simMode != Engine::ESimulationMode::LevelEdit);
		bool isPlayMode = false;
		
		ImVec2 size(ImGui::GetFontSize() * 5, 0);
		if (isPlayMode)
			ImGui::Button("Stop", size);
		else
			ImGui::Button("Play", size);

		ImGui::EndDisabled();
		ImGui::SameLine();
	}

	ImGui::BeginDisabled(!isGameRunning);

	{
		// Pause Toggle
		bool isPaused = pSC->IsPaused();
		if (ImGui::Checkbox("Pause", &isPaused))
			pSC->SetPaused(isPaused);
		ImGui::SameLine();
	}

	{
		// Single Step
		if (ImGui::Button("Single"))
			pSC->RunSingleStep(m_flTimeStepMs / 1000.0f);
	}

	ImGui::EndDisabled();
}
