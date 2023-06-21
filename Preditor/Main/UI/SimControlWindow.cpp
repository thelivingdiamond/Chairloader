#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/Engine/ISimulationController.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include <Preditor/Input/IPreditorInput.h>
#include "SimControlWindow.h"

Main::SimControlWindow::SimControlWindow()
{
	SetTitle("Simulation");
	SetPersistentID("SimControlWindow");
	SetCloseable(false);

	gEnv->pConsole->ExecuteString("g_pauseOnLoseFocus 0");

	gPreditor->pInput->FindAction("sim_control.play_pause")->AddListener([this](const KeyActionEventArgs& e)
		{
			if (e.isPressed)
			{
				Engine::ISimulationController* pSC = IPreditorEngine::Get()->GetSimController();
				Engine::ESimulationMode simMode = pSC->GetSimulationMode();

				if (simMode == Engine::ESimulationMode::Pause)
					pSC->SetSimulationMode(Engine::ESimulationMode::Play);
				else
					pSC->SetSimulationMode(Engine::ESimulationMode::Pause);
			}
		});

	gPreditor->pInput->FindAction("sim_control.single_step")->AddListener([this](const KeyActionEventArgs& e)
		{
			if (e.isPressed)
			{
				IPreditorEngine::Get()->GetSimController()->RunSingleStep(m_flTimeStepMs / 1000.0f);
			}
		});
}

void Main::SimControlWindow::ShowMenu()
{
	Engine::ISimulationController* pSC = IPreditorEngine::Get()->GetSimController();
	Engine::ESimulationMode simMode = pSC->GetSimulationMode();
	EEditMode editMode = gPreditor->pSceneEditorManager->GetMode();

	if (editMode == EEditMode::Game)
	{
		ImGui::TextDisabled("(Game Mode)");

		if (simMode == Engine::ESimulationMode::Pause)
		{
			if (ImGui::MenuItem("Play"))
				pSC->SetSimulationMode(Engine::ESimulationMode::Play);
		}
		else
		{
			if (ImGui::MenuItem("Pause"))
				pSC->SetSimulationMode(Engine::ESimulationMode::Pause);
		}

		bool isPhysAI = simMode == Engine::ESimulationMode::PhysicsAI;

		if (ImGui::MenuItem("Physics/AI-only", nullptr, &isPhysAI))
		{
			pSC->SetSimulationMode(isPhysAI ? Engine::ESimulationMode::PhysicsAI : Engine::ESimulationMode::Play);
		}
	}
	else if (editMode == EEditMode::Level)
	{
		ImGui::TextDisabled("(Level Edit Mode)");
	}
	else if (editMode == EEditMode::None)
	{
		ImGui::TextDisabled("(Not in game)");
	}
	else
	{
		ImGui::TextDisabled("(Unknown Mode)");
	}

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

void Main::SimControlWindow::ShowContents()
{
	Engine::ISimulationController* pSC = IPreditorEngine::Get()->GetSimController();
	Engine::ESimulationMode simMode = pSC->GetSimulationMode();
	EEditMode editMode = gPreditor->pSceneEditorManager->GetMode();

	if (editMode == EEditMode::Game)
	{
		ImVec2 size(ImGui::GetFontSize() * 5, 0);

		if (simMode == Engine::ESimulationMode::Pause)
		{
			if (ImGui::Button("Play", size))
				pSC->SetSimulationMode(Engine::ESimulationMode::Play);
		}
		else
		{
			if (ImGui::Button("Pause", size))
				pSC->SetSimulationMode(Engine::ESimulationMode::Pause);
		}

		ImGui::SameLine();

		bool isPhysAI = simMode == Engine::ESimulationMode::PhysicsAI;

		if (ImGui::Checkbox("Physics/AI-only", &isPhysAI))
		{
			pSC->SetSimulationMode(isPhysAI ? Engine::ESimulationMode::PhysicsAI : Engine::ESimulationMode::Play);
		}

		ImGui::SameLine();

		// Single Step
		if (ImGui::Button("Single"))
			pSC->RunSingleStep(m_flTimeStepMs / 1000.0f);
	}
	else if (editMode == EEditMode::Level)
	{
		ImGui::TextDisabled("(Level Edit Mode)");
	}
	else if (editMode == EEditMode::None)
	{
		ImGui::TextDisabled("(Not in game)");
	}
	else
	{
		ImGui::TextDisabled("(Unknown Mode)");
	}
}
