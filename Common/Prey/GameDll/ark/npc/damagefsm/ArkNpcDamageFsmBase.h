// Primary template reproducing the single <void> instantiation (Size=56).
#pragma once
#include <Prey/ArkEnums.h>
#include <Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState_Damaged.h>
#include <Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState_Destroyed.h>
#include <Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState_Disabled.h>
#include <Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState_Undamaged.h>

class ArkNpcDamageState;

template<typename = void>
class ArkNpcDamageFsmBase_template_
{
public:
	using EStateId = EArkNpcDamageStateId;
	using BaseStateType = ArkNpcDamageState;

	template<EStateId stateId> struct StateSelector;

	static constexpr const uint64_t k_stateCount = 5;
	EArkNpcDamageStateId m_currentStateId;
	ArkNpcDamageState_Damaged m_damagedState;
	ArkNpcDamageState_Destroyed m_destroyedState;
	ArkNpcDamageState_Disabled m_disabledState;
	ArkNpcDamageState_Undamaged m_undamagedState;

#if 0
	ArkNpcDamageState& GetState(const EArkNpcDamageStateId);
	const ArkNpcDamageState& GetState(const EArkNpcDamageStateId) const;
	bool CanTransitionTo(const EArkNpcDamageStateId) const;
	bool Initiate(const EArkNpcDamageStateId);
	bool Terminate();
	bool SetCurrentState(const EArkNpcDamageStateId);
	bool SetCurrentStateIfNot(const EArkNpcDamageStateId);
	EArkNpcDamageStateId GetCurrentStateId() const;
	ArkNpcDamageState& GetCurrentState();
	const ArkNpcDamageState& GetCurrentState() const;
	bool CurrentStateIs(const EArkNpcDamageStateId) const;
	bool CurrentStateIsNot(const EArkNpcDamageStateId) const;
	ArkNpcDamageFsmBase_template_();
	~ArkNpcDamageFsmBase_template_();
	void RestoreCurrentState(const EArkNpcDamageStateId);
	void EnterState(const EArkNpcDamageStateId);
	void ExitCurrentState();
#endif
};

template<> template<>
struct ArkNpcDamageFsmBase_template_<void>::StateSelector<EArkNpcDamageStateId::damaged>
{
	using StateType = ArkNpcDamageState_Damaged;

#if 0
	static ArkNpcDamageState_Damaged& Get(ArkNpcDamageFsmBase_template_<void>&);
	static const ArkNpcDamageState_Damaged& Get(const ArkNpcDamageFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcDamageFsmBase_template_<void>::StateSelector<EArkNpcDamageStateId::destroyed>
{
	using StateType = ArkNpcDamageState_Destroyed;

#if 0
	static ArkNpcDamageState_Destroyed& Get(ArkNpcDamageFsmBase_template_<void>&);
	static const ArkNpcDamageState_Destroyed& Get(const ArkNpcDamageFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcDamageFsmBase_template_<void>::StateSelector<EArkNpcDamageStateId::disabled>
{
	using StateType = ArkNpcDamageState_Disabled;

#if 0
	static ArkNpcDamageState_Disabled& Get(ArkNpcDamageFsmBase_template_<void>&);
	static const ArkNpcDamageState_Disabled& Get(const ArkNpcDamageFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcDamageFsmBase_template_<void>::StateSelector<EArkNpcDamageStateId::undamaged>
{
	using StateType = ArkNpcDamageState_Undamaged;

#if 0
	static ArkNpcDamageState_Undamaged& Get(ArkNpcDamageFsmBase_template_<void>&);
	static const ArkNpcDamageState_Undamaged& Get(const ArkNpcDamageFsmBase_template_<void>&);
#endif
};

