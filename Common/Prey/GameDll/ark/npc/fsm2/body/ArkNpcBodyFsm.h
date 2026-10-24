// Header file automatically created from a PDB.
// Primary template reproducing the single <void> instantiation.
#pragma once
#include <Prey/ArkEnums.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Animated.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedFall.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Busy.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Dissipate.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Fatality.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_GravShaft.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_HitReact.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Landing.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Lifted.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Mimicking.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_MultiStageAnimated.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Ragdoll.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Rebound.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Resist.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_ResistScrunch.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Surprised.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Trackview.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Ready.h>
#ifdef MOONCRASH
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Burrowing.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_SearchExamine.h>
#endif

class ArkNpc;
class ArkNpcBodyState;

// ArkNpcBodyFsmBase_template_<void>
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyFsm.h
template<typename = void>
class ArkNpcBodyFsmBase_template_
{ // Size=6072 (0x17B8) PreyDll, 6288 (0x1890) Mooncrash
public:
	using EStateId = EArkNpcBodyStateId;
	using BaseStateType = ArkNpcBodyState;

	template<EStateId stateId> struct StateSelector;

#ifndef MOONCRASH
	static constexpr const uint64_t k_stateCount = 36;
#else
	static constexpr const uint64_t k_stateCount = 38;
#endif
	EArkNpcBodyStateId m_currentStateId;
	ArkNpcBodyState_Animated m_animatedState;
	ArkNpcBodyState_Animated m_animatedAbilityState;
	ArkNpcBodyState_Animated m_animatedDistractionState;
	ArkNpcBodyState_AnimatedFall m_animatedFallState;
	ArkNpcBodyState_Animated m_animatedStunnedState;
	ArkNpcBodyState_Animated m_breakoutState;
#ifdef MOONCRASH
	ArkNpcBodyState_Burrowing m_burrowingState;
#endif
	ArkNpcBodyState_Animated m_cowerState;
	ArkNpcBodyState_Busy m_deadState;
	ArkNpcBodyState_Dissipate m_dissipateState;
	ArkNpcBodyState_Animated m_dodgeState;
	ArkNpcBodyState_Fatality m_fatalityState;
	ArkNpcBodyState_Busy m_frozenState;
	ArkNpcBodyState_GravShaft m_gravShaftState;
	ArkNpcBodyState_HitReact m_hitReactState;
	ArkNpcBodyState_Busy m_hitReactShiftState;
	ArkNpcBodyState_MultiStageAnimated m_hypnotizedState;
	ArkNpcBodyState_Busy m_jumpState;
	ArkNpcBodyState_Landing m_landingState;
	ArkNpcBodyState_Lifted m_liftedState;
	ArkNpcBodyState_Animated m_lurkingState;
	ArkNpcBodyState_Animated m_lurkOutState;
	ArkNpcBodyState_Busy m_mantleState;
	ArkNpcBodyState_Mimicking m_mimickingState;
	ArkNpcBodyState_Animated m_noticeState;
	ArkNpcBodyState_Ragdoll m_ragdollState;
	ArkNpcBodyState_Animated m_raisedState;
	ArkNpcBodyState_Animated m_reactState;
	ArkNpcBodyState_Ready m_readyState;
	ArkNpcBodyState_Rebound m_reboundState;
	ArkNpcBodyState_Resist m_resistState;
	ArkNpcBodyState_ResistScrunch m_resistScrunchState;
#ifndef MOONCRASH
	ArkNpcBodyState_Animated m_searchExamineState;
#else
	ArkNpcBodyState_SearchExamine m_searchExamineState;
#endif
	ArkNpcBodyState_Surprised m_surprisedState;
	ArkNpcBodyState_Trackview m_trackviewState;
	ArkNpcBodyState_Busy m_unanimatedAbilityState;
#ifdef MOONCRASH
	ArkNpcBodyState_Burrowing m_unburrowingState;
#endif

	// Only the <void> instantiation exists, so its ctor/dtor addresses are kept.
	ArkNpcBodyFsmBase_template_();
	~ArkNpcBodyFsmBase_template_();

#if 0
	ArkNpcBodyState& GetState(const EArkNpcBodyStateId _arg0_);
	const ArkNpcBodyState& GetState(const EArkNpcBodyStateId _arg0_) const;
	bool CanTransitionTo(const EArkNpcBodyStateId _arg0_) const;
	bool Initiate(const EArkNpcBodyStateId _arg0_);
	bool Terminate();
	bool SetCurrentState(const EArkNpcBodyStateId _arg0_);
	bool SetCurrentStateIfNot(const EArkNpcBodyStateId _arg0_);
	EArkNpcBodyStateId GetCurrentStateId() const;
	ArkNpcBodyState& GetCurrentState();
	const ArkNpcBodyState& GetCurrentState() const;
	bool CurrentStateIs(const EArkNpcBodyStateId _arg0_) const;
	bool CurrentStateIsNot(const EArkNpcBodyStateId _arg0_) const;
	void RestoreCurrentState(const EArkNpcBodyStateId _arg0_);
	void EnterState(const EArkNpcBodyStateId _arg0_);
	void ExitCurrentState();
#endif

#ifndef MOONCRASH
	static inline auto FArkNpcBodyFsmBase_template_LessvoidGreater = PreyFunction<void(ArkNpcBodyFsmBase_template_<void>* const _this)>(0x11F8EC0);
	static inline auto FBitNotArkNpcBodyFsmBase_template_LessvoidGreater = PreyFunction<void(ArkNpcBodyFsmBase_template_<void>* const _this)>(0x14F2540);
#else
	static inline auto FArkNpcBodyFsmBase_template_LessvoidGreater = PreyFunction<void(ArkNpcBodyFsmBase_template_<void>* const _this)>(0x1286AD0);
	static inline auto FBitNotArkNpcBodyFsmBase_template_LessvoidGreater = PreyFunction<void(ArkNpcBodyFsmBase_template_<void>* const _this)>(0x160E2B0);
#endif
};

// ArkNpcBodyFsmBase_template_<void>::StateSelector<N>: state N <-> N-th state member above.
template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::animated>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::animatedAbility>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::animatedDistraction>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::animatedFall>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_AnimatedFall;

#if 0
	static ArkNpcBodyState_AnimatedFall& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_AnimatedFall& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::animatedStunned>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::breakout>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

#ifdef MOONCRASH
template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::burrowing>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Burrowing;

#if 0
	static ArkNpcBodyState_Burrowing& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Burrowing& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

#endif

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::cower>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::dead>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Busy;

#if 0
	static ArkNpcBodyState_Busy& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Busy& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::dissipate>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Dissipate;

#if 0
	static ArkNpcBodyState_Dissipate& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Dissipate& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::dodge>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::fatality>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Fatality;

#if 0
	static ArkNpcBodyState_Fatality& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Fatality& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::frozen>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Busy;

#if 0
	static ArkNpcBodyState_Busy& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Busy& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::gravShaft>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_GravShaft;

#if 0
	static ArkNpcBodyState_GravShaft& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_GravShaft& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::hitReact>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_HitReact;

#if 0
	static ArkNpcBodyState_HitReact& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_HitReact& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::hitReactShift>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Busy;

#if 0
	static ArkNpcBodyState_Busy& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Busy& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::hypnotized>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_MultiStageAnimated;

#if 0
	static ArkNpcBodyState_MultiStageAnimated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_MultiStageAnimated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::jump>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Busy;

#if 0
	static ArkNpcBodyState_Busy& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Busy& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::landing>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Landing;

#if 0
	static ArkNpcBodyState_Landing& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Landing& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::lifted>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Lifted;

#if 0
	static ArkNpcBodyState_Lifted& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Lifted& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::lurking>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::lurkOut>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::mantle>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Busy;

#if 0
	static ArkNpcBodyState_Busy& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Busy& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::mimicking>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Mimicking;

#if 0
	static ArkNpcBodyState_Mimicking& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Mimicking& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::notice>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::ragdoll>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Ragdoll;

#if 0
	static ArkNpcBodyState_Ragdoll& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Ragdoll& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::raised>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::react>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::ready>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Ready;

#if 0
	static ArkNpcBodyState_Ready& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Ready& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::rebound>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Rebound;

#if 0
	static ArkNpcBodyState_Rebound& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Rebound& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::resist>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Resist;

#if 0
	static ArkNpcBodyState_Resist& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Resist& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::resistScrunch>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_ResistScrunch;

#if 0
	static ArkNpcBodyState_ResistScrunch& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_ResistScrunch& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

#ifndef MOONCRASH
template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::searchExamine>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Animated;

#if 0
	static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

#else
template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::searchExamine>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_SearchExamine;

#if 0
	static ArkNpcBodyState_SearchExamine& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_SearchExamine& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

#endif

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::surprised>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Surprised;

#if 0
	static ArkNpcBodyState_Surprised& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Surprised& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::trackview>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Trackview;

#if 0
	static ArkNpcBodyState_Trackview& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Trackview& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::unanimatedAbility>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Busy;

#if 0
	static ArkNpcBodyState_Busy& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Busy& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

#ifdef MOONCRASH
template<> template<>
struct ArkNpcBodyFsmBase_template_<void>::StateSelector<EArkNpcBodyStateId::unburrowing>
{ // Size=1 (0x1)
	using StateType = ArkNpcBodyState_Burrowing;

#if 0
	static ArkNpcBodyState_Burrowing& Get(ArkNpcBodyFsmBase_template_<void>&);
	static const ArkNpcBodyState_Burrowing& Get(const ArkNpcBodyFsmBase_template_<void>&);
#endif
};

#endif

// ArkNpcBodyFsm
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyFsm.h
class ArkNpcBodyFsm : public ArkNpcBodyFsmBase_template_<void>
{ // Size=6072 (0x17B8) PreyDll, 6288 (0x1890) Mooncrash
public:
	void Update(ArkNpc& _npc, float _elapsedTime) { FUpdate(this, _npc, _elapsedTime); }

#ifndef MOONCRASH
	static inline auto FUpdate = PreyFunction<void(ArkNpcBodyFsm* const _this, ArkNpc& _npc, float _elapsedTime)>(0x12135A0);
#else
	static inline auto FUpdate = PreyFunction<void(ArkNpcBodyFsm* const _this, ArkNpc& _npc, float _elapsedTime)>(0x12A2A80);
#endif
};
