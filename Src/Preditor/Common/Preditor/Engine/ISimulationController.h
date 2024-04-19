#pragma once

namespace Engine
{

enum class ESimulationMode
{
	None,		//!< Not editing.
	Pause,		//!< Game is paused.
	Play,		//!< Game is fully playing.
	PhysicsAI,	//!< Only Physics and AI code runs in the game. TODO 2023-06-21: Confirm what actually runs
};

//! Controls the current state of game simulation.
//! TODO: Will handle entity restoration when switching from a play state to edit state.
struct ISimulationController
{
	virtual ~ISimulationController() {}

	//! @returns the current simulation mode.
	virtual ESimulationMode GetSimulationMode() const = 0;
	virtual void SetSimulationMode(ESimulationMode simMode) = 0;

	//! Runs a single simulation step next frame.
	//! If not paused, forces the next frame to run with specified time step.
	//! If called multiple times per frame, the last call's time step will be used.
	//! @param	timestep	Time delta for the single step.
	virtual void RunSingleStep(float timestep) = 0;
};

} // namespace Engine
