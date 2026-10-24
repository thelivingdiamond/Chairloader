// Primary template reproducing the single <void> instantiation (Size=64).
// Base game only: Mooncrash has no ArkTurretAnimFsm.
#ifndef MOONCRASH
#pragma once
#include <Prey/ArkEnums.h>
#include <Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_states.h>

namespace ArkTurretAnimFsm::States
{
class Base;
} // namespace ArkTurretAnimFsm::States

template<typename = void>
class ArkTurretAnimFsmBase_template_
{
public:
	using EStateId = EArkTurretAnimStateId;
	using BaseStateType = ArkTurretAnimFsm::States::Base;

	template<EStateId stateId> struct StateSelector;

	static constexpr const uint64_t k_stateCount = 8;
	EArkTurretAnimStateId m_currentStateId;
	ArkTurretAnimFsm::States::Undeployed m_undeployedState;
	ArkTurretAnimFsm::States::Deploying m_deployingState;
	ArkTurretAnimFsm::States::Deployed m_deployedState;
	ArkTurretAnimFsm::States::UnDeploying m_undeployingState;
	ArkTurretAnimFsm::States::Destroyed m_destroyedState;
	ArkTurretAnimFsm::States::Broken m_brokenState;
	ArkTurretAnimFsm::States::Search m_searchingState;

#if 0
	ArkTurretAnimFsm::States::Base& GetState(const EArkTurretAnimStateId);
	const ArkTurretAnimFsm::States::Base& GetState(const EArkTurretAnimStateId) const;
	bool CanTransitionTo(const EArkTurretAnimStateId) const;
	bool Initiate(const EArkTurretAnimStateId);
	bool Terminate();
	bool SetCurrentState(const EArkTurretAnimStateId);
	bool SetCurrentStateIfNot(const EArkTurretAnimStateId);
	EArkTurretAnimStateId GetCurrentStateId() const;
	ArkTurretAnimFsm::States::Base& GetCurrentState();
	const ArkTurretAnimFsm::States::Base& GetCurrentState() const;
	bool CurrentStateIs(const EArkTurretAnimStateId) const;
	bool CurrentStateIsNot(const EArkTurretAnimStateId) const;
	ArkTurretAnimFsmBase_template_();
	~ArkTurretAnimFsmBase_template_();
	void RestoreCurrentState(const EArkTurretAnimStateId);
	void EnterState(const EArkTurretAnimStateId);
	void ExitCurrentState();
#endif
};

template<> template<>
struct ArkTurretAnimFsmBase_template_<void>::StateSelector<EArkTurretAnimStateId::undeployed>
{
	using StateType = ArkTurretAnimFsm::States::Undeployed;

#if 0
	static ArkTurretAnimFsm::States::Undeployed& Get(ArkTurretAnimFsmBase_template_<void>&);
	static const ArkTurretAnimFsm::States::Undeployed& Get(const ArkTurretAnimFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkTurretAnimFsmBase_template_<void>::StateSelector<EArkTurretAnimStateId::deploying>
{
	using StateType = ArkTurretAnimFsm::States::Deploying;

#if 0
	static ArkTurretAnimFsm::States::Deploying& Get(ArkTurretAnimFsmBase_template_<void>&);
	static const ArkTurretAnimFsm::States::Deploying& Get(const ArkTurretAnimFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkTurretAnimFsmBase_template_<void>::StateSelector<EArkTurretAnimStateId::deployed>
{
	using StateType = ArkTurretAnimFsm::States::Deployed;

#if 0
	static ArkTurretAnimFsm::States::Deployed& Get(ArkTurretAnimFsmBase_template_<void>&);
	static const ArkTurretAnimFsm::States::Deployed& Get(const ArkTurretAnimFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkTurretAnimFsmBase_template_<void>::StateSelector<EArkTurretAnimStateId::undeploying>
{
	using StateType = ArkTurretAnimFsm::States::UnDeploying;

#if 0
	static ArkTurretAnimFsm::States::UnDeploying& Get(ArkTurretAnimFsmBase_template_<void>&);
	static const ArkTurretAnimFsm::States::UnDeploying& Get(const ArkTurretAnimFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkTurretAnimFsmBase_template_<void>::StateSelector<EArkTurretAnimStateId::destroyed>
{
	using StateType = ArkTurretAnimFsm::States::Destroyed;

#if 0
	static ArkTurretAnimFsm::States::Destroyed& Get(ArkTurretAnimFsmBase_template_<void>&);
	static const ArkTurretAnimFsm::States::Destroyed& Get(const ArkTurretAnimFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkTurretAnimFsmBase_template_<void>::StateSelector<EArkTurretAnimStateId::broken>
{
	using StateType = ArkTurretAnimFsm::States::Broken;

#if 0
	static ArkTurretAnimFsm::States::Broken& Get(ArkTurretAnimFsmBase_template_<void>&);
	static const ArkTurretAnimFsm::States::Broken& Get(const ArkTurretAnimFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkTurretAnimFsmBase_template_<void>::StateSelector<EArkTurretAnimStateId::searching>
{
	using StateType = ArkTurretAnimFsm::States::Search;

#if 0
	static ArkTurretAnimFsm::States::Search& Get(ArkTurretAnimFsmBase_template_<void>&);
	static const ArkTurretAnimFsm::States::Search& Get(const ArkTurretAnimFsmBase_template_<void>&);
#endif
};

#endif
