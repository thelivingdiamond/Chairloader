// Primary template reproducing the single <void> instantiation (Size=688, Mooncrash 696).
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/alive/ArkNpcAliveState_Broken.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/alive/ArkNpcAliveState_Conscious.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/alive/ArkNpcAliveState_Unconscious.h>

class ArkNpcAliveState;

// Values inferred: state N <-> StateSelector<N>, in member order.
enum class EArkNpcAliveStateId
{
	any = -1,
	null = 0,
	broken = 1,
	conscious = 2,
	unconscious = 3,
	count_ = 4,
};

template<typename = void>
class ArkNpcAliveFsmBase_template_
{
public:
	using EStateId = EArkNpcAliveStateId;
	using BaseStateType = ArkNpcAliveState;

	template<EStateId stateId> struct StateSelector;

	static constexpr const uint64_t k_stateCount = 4;
	EArkNpcAliveStateId m_currentStateId;
	ArkNpcAliveState_Broken m_brokenState;
	ArkNpcAliveState_Conscious m_consciousState;
	ArkNpcAliveState_Unconscious m_unconsciousState;

#if 0
	ArkNpcAliveState& GetState(const EArkNpcAliveStateId);
	const ArkNpcAliveState& GetState(const EArkNpcAliveStateId) const;
	bool CanTransitionTo(const EArkNpcAliveStateId) const;
	bool Initiate(const EArkNpcAliveStateId);
	bool Terminate();
	bool SetCurrentState(const EArkNpcAliveStateId);
	bool SetCurrentStateIfNot(const EArkNpcAliveStateId);
	EArkNpcAliveStateId GetCurrentStateId() const;
	ArkNpcAliveState& GetCurrentState();
	const ArkNpcAliveState& GetCurrentState() const;
	bool CurrentStateIs(const EArkNpcAliveStateId) const;
	bool CurrentStateIsNot(const EArkNpcAliveStateId) const;
	ArkNpcAliveFsmBase_template_();
	~ArkNpcAliveFsmBase_template_();
	void RestoreCurrentState(const EArkNpcAliveStateId);
	void EnterState(const EArkNpcAliveStateId);
	void ExitCurrentState();
#endif
};

template<> template<>
struct ArkNpcAliveFsmBase_template_<void>::StateSelector<EArkNpcAliveStateId::broken>
{
	using StateType = ArkNpcAliveState_Broken;

#if 0
	static ArkNpcAliveState_Broken& Get(ArkNpcAliveFsmBase_template_<void>&);
	static const ArkNpcAliveState_Broken& Get(const ArkNpcAliveFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcAliveFsmBase_template_<void>::StateSelector<EArkNpcAliveStateId::conscious>
{
	using StateType = ArkNpcAliveState_Conscious;

#if 0
	static ArkNpcAliveState_Conscious& Get(ArkNpcAliveFsmBase_template_<void>&);
	static const ArkNpcAliveState_Conscious& Get(const ArkNpcAliveFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcAliveFsmBase_template_<void>::StateSelector<EArkNpcAliveStateId::unconscious>
{
	using StateType = ArkNpcAliveState_Unconscious;

#if 0
	static ArkNpcAliveState_Unconscious& Get(ArkNpcAliveFsmBase_template_<void>&);
	static const ArkNpcAliveState_Unconscious& Get(const ArkNpcAliveFsmBase_template_<void>&);
#endif
};

