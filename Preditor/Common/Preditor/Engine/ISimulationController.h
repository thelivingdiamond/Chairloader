#pragma once

namespace Engine
{

//! List of "base" simulation modes.
enum class ESimulationMode
{
	None,
	Game,		//!< Playing the game normally (with main menu and stuff).
	LevelEdit,	//!< Editing a level.
};

//! List of Level Edit states. Only applies to ESimulationMode::LevelEdit.
enum class EEditState
{
	None,		//!< Not editing.
	Edit,		//!< Editing a level.
	Play,		//!< Playing a level.
	PhysicsAI,	//!< Only Physics and AI code runs in the game. TODO: Confirm what actually runs
};

//! Controls the current state of game simulation.
//! TODO: Will handle entity restoration when switching from a play state to edit state.
struct ISimulationController
{
	virtual ~ISimulationController() {}

	//! @returns the current simulation mode.
	virtual ESimulationMode GetSimulationMode() const = 0;

	// LevelEdit mode is not finished yet.
	// virtual void SwitchToMode(ESimulationMode mode) = 0;

	//! @returns the current Edit Mode state. If not in Edit Mode, returns None.
	// virtual EEditState GetEditState() const = 0;

	//! Changes the Edit Mode state. WIP.
	// virtual void SetEditState(EEditState state) = 0;

	//! @returns whether the simulation is currently paused.
	virtual bool IsPaused() const = 0;

	//! Sets current pause state.
	//! @param	isPuased	Is paused.
	virtual void SetPaused(bool isPaused) = 0;

	//! Runs a single simulation step next frame.
	//! If not paused, forces the next frame to run with specified time step.
	//! If called multiple times per frame, the last call's time step will be used.
	//! @param	timestep	Time delta for the single step.
	virtual void RunSingleStep(float timestep) = 0;
};

} // namespace Engine
