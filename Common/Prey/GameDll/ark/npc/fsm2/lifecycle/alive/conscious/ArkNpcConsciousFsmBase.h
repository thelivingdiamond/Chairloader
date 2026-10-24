// Primary template reproducing the single <void> instantiation (Size=488, Mooncrash 496).
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/ArkNpcConsciousState_Alert.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/ArkNpcConsciousState_Dormant.h>

class ArkNpcConsciousState;

// Values inferred: state N <-> StateSelector<N>, in member order.
enum class EArkNpcConsciousStateId
{
	any = -1,
	null = 0,
	alert = 1,
	dormant = 2,
	count_ = 3,
};

template<typename = void>
class ArkNpcConsciousFsmBase_template_
{
public:
	using EStateId = EArkNpcConsciousStateId;
	using BaseStateType = ArkNpcConsciousState;

	template<EStateId stateId> struct StateSelector;

	static constexpr const uint64_t k_stateCount = 3;
	EArkNpcConsciousStateId m_currentStateId;
	ArkNpcConsciousState_Alert m_alertState;
	ArkNpcConsciousState_Dormant m_dormantState;

#if 0
	ArkNpcConsciousState& GetState(const EArkNpcConsciousStateId);
	const ArkNpcConsciousState& GetState(const EArkNpcConsciousStateId) const;
	bool CanTransitionTo(const EArkNpcConsciousStateId) const;
	bool Initiate(const EArkNpcConsciousStateId);
	bool Terminate();
	bool SetCurrentState(const EArkNpcConsciousStateId);
	bool SetCurrentStateIfNot(const EArkNpcConsciousStateId);
	EArkNpcConsciousStateId GetCurrentStateId() const;
	ArkNpcConsciousState& GetCurrentState();
	const ArkNpcConsciousState& GetCurrentState() const;
	bool CurrentStateIs(const EArkNpcConsciousStateId) const;
	bool CurrentStateIsNot(const EArkNpcConsciousStateId) const;
	ArkNpcConsciousFsmBase_template_();
	~ArkNpcConsciousFsmBase_template_();
	void RestoreCurrentState(const EArkNpcConsciousStateId);
	void EnterState(const EArkNpcConsciousStateId);
	void ExitCurrentState();
#endif
};

template<> template<>
struct ArkNpcConsciousFsmBase_template_<void>::StateSelector<EArkNpcConsciousStateId::alert>
{
	using StateType = ArkNpcConsciousState_Alert;

#if 0
	static ArkNpcConsciousState_Alert& Get(ArkNpcConsciousFsmBase_template_<void>&);
	static const ArkNpcConsciousState_Alert& Get(const ArkNpcConsciousFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcConsciousFsmBase_template_<void>::StateSelector<EArkNpcConsciousStateId::dormant>
{
	using StateType = ArkNpcConsciousState_Dormant;

#if 0
	static ArkNpcConsciousState_Dormant& Get(ArkNpcConsciousFsmBase_template_<void>&);
	static const ArkNpcConsciousState_Dormant& Get(const ArkNpcConsciousFsmBase_template_<void>&);
#endif
};

