#pragma once
#include <Preditor/Engine/ISimulationController.h>

namespace Engine
{

//! If this is the Simulation Controller that controls what the engine does,
//! does it mean that the whole game is the Simulation Lab? Oh, right, it is.
class SimulationController
	: public ISimulationController
{
public:
	SimulationController();

	//! @returns the update flags for the next frame.
	unsigned GetUpdateFlags() const;

	//! Called before engine update.
	void BeginUpdate();

	//! Called after engine update.
	void EndUpdate();

	// ISimulationController
	virtual ESimulationMode GetSimulationMode() const override;
	virtual void SetSimulationMode(ESimulationMode simMode) override;
	virtual void RunSingleStep(float timestep) override;

private:
	ICVar* m_pFixedStep = nullptr;
	ESimulationMode m_CurMode = ESimulationMode::Play;
	float m_flSingleTimeStep = 0.0f;
	bool m_bUpdatingSingleStep = false; //!< Inside engine update with single-step.
	float m_flSavedFixedStep = 0;

	//! @returns whether need to single-step the next frame.
	bool IsSingleStepping() const { return m_flSingleTimeStep != 0.0f; }
};

} // namespace Engine
