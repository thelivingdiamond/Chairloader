// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/turret/ATStates.h>
#include <Prey/GameDll/ark/turret/arkturretfsmstates.h>

// Header: MadeUp
// _unknown/ArkTurretFsmBase_template__void_.h
template <typename T>
class ArkTurretFsmBase_template_ // Id=80152AB Size=76
{
public:
	using EStateId = EArkTurretStateId;
	using BaseStateType = ATStates::BaseState;
	
	static constexpr const uint64_t k_stateCount = 9;
	EArkTurretStateId m_currentStateId;
	ATStates::Undeployed m_undeployedState;
	ATStates::FallenSpazzing m_fallenSpazState;
	ATStates::Attacking m_attackingState;
	ATStates::Searching m_searchingState;
	ATStates::FlowgraphControlled m_flowgraphControlledState;
	ATStates::PlayerControlled m_playerControlledState;
	ATStates::PlayerCarried m_playerCarriedState;
	ATStates::Disabled m_disabledState;
	
	template <EStateId stateId>
	struct StateSelector // Id=80152B5 Size=1
	{
		// using StateType = ATStates::Undeployed;
		
#if 0
		static ATStates::Undeployed &Get(ArkTurretFsmBase_template_<void> &arg0);
		static ATStates::Undeployed const &Get(ArkTurretFsmBase_template_<void> const &arg0);
#endif
	};

#if 0
	ATStates::BaseState &GetState(EArkTurretStateId arg0);
	ATStates::BaseState const &GetState(EArkTurretStateId arg0) const;
	bool CanTransitionTo(EArkTurretStateId arg0) const;
	bool Initiate(EArkTurretStateId arg0);
	bool Terminate();
	bool SetCurrentState(EArkTurretStateId arg0);
	bool SetCurrentStateIfNot(EArkTurretStateId arg0);
	EArkTurretStateId GetCurrentStateId() const;
	ATStates::BaseState &GetCurrentState();
	ATStates::BaseState const &GetCurrentState() const;
	bool CurrentStateIs(EArkTurretStateId arg0) const;
	bool CurrentStateIsNot(EArkTurretStateId arg0) const;
	void RestoreCurrentState(EArkTurretStateId arg0);
	void EnterState(EArkTurretStateId arg0);
	void ExitCurrentState();
#endif
};

