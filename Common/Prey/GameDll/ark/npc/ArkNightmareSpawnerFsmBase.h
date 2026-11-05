// Primary template reproducing the single <void> instantiation (Size=32). Mooncrash only.
#ifdef MOONCRASH
#pragma once
#include <Prey/GameDll/ark/npc/ArkNightmareSpawnerState_NoNightmare.h>
#include <Prey/GameDll/ark/npc/ArkNightmareSpawnerState_SpawnNightmare.h>
#include <Prey/GameDll/ark/npc/ArkNightmareSpawnerState_SpawnEffects.h>
#include <Prey/GameDll/ark/npc/ArkNightmareSpawnerState_SpawnedNightmare.h>

class ArkNightmareSpawnerState_Base;

// Values inferred: state N <-> StateSelector<N>, in member order.
enum class EArkNightmareSpawnerStateId
{
	any = -1,
	null = 0,
	noNightmare = 1,
	spawnNightmare = 2,
	spawnEffects = 3,
	spawnedNightmare = 4,
	count_ = 5,
};

template<typename = void>
class ArkNightmareSpawnerFsmBase_template_
{
public:
	using EStateId = EArkNightmareSpawnerStateId;
	using BaseStateType = ArkNightmareSpawnerState_Base;

	template<EStateId stateId> struct StateSelector;

	static constexpr const uint64_t k_stateCount = 5;
	EArkNightmareSpawnerStateId m_currentStateId;
	ArkNightmareSpawnerState_NoNightmare m_noNightmareState;
	ArkNightmareSpawnerState_SpawnNightmare m_spawnNightmareState;
	ArkNightmareSpawnerState_SpawnEffects m_spawnEffectsState;
	ArkNightmareSpawnerState_SpawnedNightmare m_spawnedNightmareState;

#if 0
	ArkNightmareSpawnerState_Base& GetState(const EArkNightmareSpawnerStateId);
	const ArkNightmareSpawnerState_Base& GetState(const EArkNightmareSpawnerStateId) const;
	bool CanTransitionTo(const EArkNightmareSpawnerStateId) const;
	bool Initiate(const EArkNightmareSpawnerStateId);
	bool Terminate();
	bool SetCurrentState(const EArkNightmareSpawnerStateId);
	bool SetCurrentStateIfNot(const EArkNightmareSpawnerStateId);
	EArkNightmareSpawnerStateId GetCurrentStateId() const;
	ArkNightmareSpawnerState_Base& GetCurrentState();
	const ArkNightmareSpawnerState_Base& GetCurrentState() const;
	bool CurrentStateIs(const EArkNightmareSpawnerStateId) const;
	bool CurrentStateIsNot(const EArkNightmareSpawnerStateId) const;
	ArkNightmareSpawnerFsmBase_template_();
	~ArkNightmareSpawnerFsmBase_template_();
	void RestoreCurrentState(const EArkNightmareSpawnerStateId);
	void EnterState(const EArkNightmareSpawnerStateId);
	void ExitCurrentState();
#endif
};

template<> template<>
struct ArkNightmareSpawnerFsmBase_template_<void>::StateSelector<EArkNightmareSpawnerStateId::noNightmare>
{
	using StateType = ArkNightmareSpawnerState_NoNightmare;

#if 0
	static ArkNightmareSpawnerState_NoNightmare& Get(ArkNightmareSpawnerFsmBase_template_<void>&);
	static const ArkNightmareSpawnerState_NoNightmare& Get(const ArkNightmareSpawnerFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNightmareSpawnerFsmBase_template_<void>::StateSelector<EArkNightmareSpawnerStateId::spawnNightmare>
{
	using StateType = ArkNightmareSpawnerState_SpawnNightmare;

#if 0
	static ArkNightmareSpawnerState_SpawnNightmare& Get(ArkNightmareSpawnerFsmBase_template_<void>&);
	static const ArkNightmareSpawnerState_SpawnNightmare& Get(const ArkNightmareSpawnerFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNightmareSpawnerFsmBase_template_<void>::StateSelector<EArkNightmareSpawnerStateId::spawnEffects>
{
	using StateType = ArkNightmareSpawnerState_SpawnEffects;

#if 0
	static ArkNightmareSpawnerState_SpawnEffects& Get(ArkNightmareSpawnerFsmBase_template_<void>&);
	static const ArkNightmareSpawnerState_SpawnEffects& Get(const ArkNightmareSpawnerFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNightmareSpawnerFsmBase_template_<void>::StateSelector<EArkNightmareSpawnerStateId::spawnedNightmare>
{
	using StateType = ArkNightmareSpawnerState_SpawnedNightmare;

#if 0
	static ArkNightmareSpawnerState_SpawnedNightmare& Get(ArkNightmareSpawnerFsmBase_template_<void>&);
	static const ArkNightmareSpawnerState_SpawnedNightmare& Get(const ArkNightmareSpawnerFsmBase_template_<void>&);
#endif
};

#endif
