// Primary template reproducing the single <void> instantiation (Size=20).
#pragma once
#include <Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_damaged.h>
#include <Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_disabled.h>
#include <Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_undamaged.h>

namespace ArkTurretDamageFsm::States
{
class Base;
} // namespace ArkTurretDamageFsm::States

// Values inferred: state N <-> StateSelector<N>, in member order.
enum class EArkTurretDamageStateId
{
	any = -1,
	null = 0,
	undamaged = 1,
	damaged = 2,
	disabled = 3,
	count_ = 4,
};

template<typename = void>
class ArkTurretDamageFsmBase_template_
{
public:
	using EStateId = EArkTurretDamageStateId;
	using BaseStateType = ArkTurretDamageFsm::States::Base;

	template<EStateId stateId> struct StateSelector;

	static constexpr const uint64_t k_stateCount = 4;
	EArkTurretDamageStateId m_currentStateId;
	ArkTurretDamageFsm::States::Undamaged m_undamagedState;
	ArkTurretDamageFsm::States::Damaged m_damagedState;
	ArkTurretDamageFsm::States::Disabled m_disabledState;

#if 0
	ArkTurretDamageFsm::States::Base& GetState(const EArkTurretDamageStateId);
	const ArkTurretDamageFsm::States::Base& GetState(const EArkTurretDamageStateId) const;
	bool CanTransitionTo(const EArkTurretDamageStateId) const;
	bool Initiate(const EArkTurretDamageStateId);
	bool Terminate();
	bool SetCurrentState(const EArkTurretDamageStateId);
	bool SetCurrentStateIfNot(const EArkTurretDamageStateId);
	EArkTurretDamageStateId GetCurrentStateId() const;
	ArkTurretDamageFsm::States::Base& GetCurrentState();
	const ArkTurretDamageFsm::States::Base& GetCurrentState() const;
	bool CurrentStateIs(const EArkTurretDamageStateId) const;
	bool CurrentStateIsNot(const EArkTurretDamageStateId) const;
	ArkTurretDamageFsmBase_template_();
	~ArkTurretDamageFsmBase_template_();
	void RestoreCurrentState(const EArkTurretDamageStateId);
	void EnterState(const EArkTurretDamageStateId);
	void ExitCurrentState();
#endif
};

template<> template<>
struct ArkTurretDamageFsmBase_template_<void>::StateSelector<EArkTurretDamageStateId::undamaged>
{
	using StateType = ArkTurretDamageFsm::States::Undamaged;

#if 0
	static ArkTurretDamageFsm::States::Undamaged& Get(ArkTurretDamageFsmBase_template_<void>&);
	static const ArkTurretDamageFsm::States::Undamaged& Get(const ArkTurretDamageFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkTurretDamageFsmBase_template_<void>::StateSelector<EArkTurretDamageStateId::damaged>
{
	using StateType = ArkTurretDamageFsm::States::Damaged;

#if 0
	static ArkTurretDamageFsm::States::Damaged& Get(ArkTurretDamageFsmBase_template_<void>&);
	static const ArkTurretDamageFsm::States::Damaged& Get(const ArkTurretDamageFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkTurretDamageFsmBase_template_<void>::StateSelector<EArkTurretDamageStateId::disabled>
{
	using StateType = ArkTurretDamageFsm::States::Disabled;

#if 0
	static ArkTurretDamageFsm::States::Disabled& Get(ArkTurretDamageFsmBase_template_<void>&);
	static const ArkTurretDamageFsm::States::Disabled& Get(const ArkTurretDamageFsmBase_template_<void>&);
#endif
};

