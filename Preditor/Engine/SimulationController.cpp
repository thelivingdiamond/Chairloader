#include "SimulationController.h"

Engine::SimulationController::SimulationController()
{
	m_pFixedStep = gEnv->pConsole->GetCVar("t_FixedStep");
}

unsigned Engine::SimulationController::GetUpdateFlags() const
{
	unsigned updateFlags = 0;

	switch (m_CurMode)
	{
	case ESimulationMode::Game:
	{
		if (m_bPaused && !IsSingleStepping())
		{
			// Paused. Don't update anything.
			updateFlags |= ESYSUPDATE_IGNORE_AI;
			updateFlags |= ESYSUPDATE_IGNORE_PHYSICS;
			updateFlags |= ESYSUPDATE_EDITOR;
		}
		else
		{
			// No special flags to run
		}

		break;
	}
	case ESimulationMode::LevelEdit:
	{
		CRY_ASSERT_MESSAGE(false, "Not implemented");
		break;
	}
	default:
		CRY_ASSERT_MESSAGE(false, "Invalid simulation mode");
		break;
	}
	
	return updateFlags;
}

void Engine::SimulationController::BeginUpdate()
{
	if (m_flSingleTimeStep != 0.0f)
	{
		// Set t_FixedStep to the time step
		m_flSavedFixedStep = m_pFixedStep->GetFVal();
		m_pFixedStep->Set(m_flSingleTimeStep);

		m_bUpdatingSingleStep = true;
		m_flSingleTimeStep = 0.0f;
	}
}

void Engine::SimulationController::EndUpdate()
{
	if (m_bUpdatingSingleStep)
	{
		// Restore t_FixedStep
		m_pFixedStep->Set(m_flSavedFixedStep);
		m_flSavedFixedStep = 0.0f;
		m_bUpdatingSingleStep = false;
	}
}

Engine::ESimulationMode Engine::SimulationController::GetSimulationMode() const
{
	return m_CurMode;
}

bool Engine::SimulationController::IsPaused() const
{
	return m_bPaused;
}

void Engine::SimulationController::SetPaused(bool isPaused)
{
	m_bPaused = isPaused;
}

void Engine::SimulationController::RunSingleStep(float timestep)
{
	m_flSingleTimeStep = timestep;
}
