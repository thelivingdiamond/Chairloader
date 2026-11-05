// Primary template reproducing the single <void> instantiation (Size=712, Mooncrash 720).
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/ArkNpcLifecycleState_Alive.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/ArkNpcLifecycleState_Dead.h>

class ArkNpcLifecycleState;

// Values inferred: state N <-> StateSelector<N>, in member order.
enum class EArkNpcLifecycleStateId
{
	any = -1,
	null = 0,
	alive = 1,
	dead = 2,
	count_ = 3,
};

template<typename = void>
class ArkNpcLifecycleFsmBase_template_
{
public:
	using EStateId = EArkNpcLifecycleStateId;
	using BaseStateType = ArkNpcLifecycleState;

	template<EStateId stateId> struct StateSelector;

	static constexpr const uint64_t k_stateCount = 3;
	EArkNpcLifecycleStateId m_currentStateId;
	ArkNpcLifecycleState_Alive m_aliveState;
	ArkNpcLifecycleState_Dead m_deadState;

#if 0
	ArkNpcLifecycleState& GetState(const EArkNpcLifecycleStateId);
	const ArkNpcLifecycleState& GetState(const EArkNpcLifecycleStateId) const;
	bool CanTransitionTo(const EArkNpcLifecycleStateId) const;
	bool Initiate(const EArkNpcLifecycleStateId);
	bool Terminate();
	bool SetCurrentState(const EArkNpcLifecycleStateId);
	bool SetCurrentStateIfNot(const EArkNpcLifecycleStateId);
	EArkNpcLifecycleStateId GetCurrentStateId() const;
	ArkNpcLifecycleState& GetCurrentState();
	const ArkNpcLifecycleState& GetCurrentState() const;
	bool CurrentStateIs(const EArkNpcLifecycleStateId) const;
	bool CurrentStateIsNot(const EArkNpcLifecycleStateId) const;
	ArkNpcLifecycleFsmBase_template_();
	~ArkNpcLifecycleFsmBase_template_();
	void RestoreCurrentState(const EArkNpcLifecycleStateId);
	void EnterState(const EArkNpcLifecycleStateId);
	void ExitCurrentState();
#endif
};

template<> template<>
struct ArkNpcLifecycleFsmBase_template_<void>::StateSelector<EArkNpcLifecycleStateId::alive>
{
	using StateType = ArkNpcLifecycleState_Alive;

#if 0
	static ArkNpcLifecycleState_Alive& Get(ArkNpcLifecycleFsmBase_template_<void>&);
	static const ArkNpcLifecycleState_Alive& Get(const ArkNpcLifecycleFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcLifecycleFsmBase_template_<void>::StateSelector<EArkNpcLifecycleStateId::dead>
{
	using StateType = ArkNpcLifecycleState_Dead;

#if 0
	static ArkNpcLifecycleState_Dead& Get(ArkNpcLifecycleFsmBase_template_<void>&);
	static const ArkNpcLifecycleState_Dead& Get(const ArkNpcLifecycleFsmBase_template_<void>&);
#endif
};

