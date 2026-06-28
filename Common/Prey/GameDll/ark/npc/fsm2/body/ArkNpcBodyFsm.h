// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Animated.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedFall.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Burrowing.h>
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
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_SearchExamine.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Surprised.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Trackview.h>
#include <_unknown/ArkNpcBodyState_Ready.h>

class ArkNpc;
class ArkNpcBodyState;

// ArkNpcBodyFsmBase_template_<void>
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyFsm.h
class ArkNpcBodyFsmBase_template_<void>
{ // Size=6288 (0x1890)
public:
	// ArkNpcBodyFsmBase_template_<void>::StateSelector<1>
	// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyFsm.h
	struct StateSelector<1>
	{ // Size=1 (0x1)
		using StateType = ArkNpcBodyState_Animated;

	#if 0
		static ArkNpcBodyState_Animated& Get(ArkNpcBodyFsmBase_template_<void>& _arg0_);
		static const ArkNpcBodyState_Animated& Get(const ArkNpcBodyFsmBase_template_<void>& _arg0_);
	#endif
	};

	using EStateId = EArkNpcBodyStateId;
	using BaseStateType = ArkNpcBodyState;

	static constexpr const uint64_t k_stateCount = 38;
	EArkNpcBodyStateId m_currentStateId;
	ArkNpcBodyState_Animated m_animatedState;
	ArkNpcBodyState_Animated m_animatedAbilityState;
	ArkNpcBodyState_Animated m_animatedDistractionState;
	ArkNpcBodyState_AnimatedFall m_animatedFallState;
	ArkNpcBodyState_Animated m_animatedStunnedState;
	ArkNpcBodyState_Animated m_breakoutState;
	ArkNpcBodyState_Burrowing m_burrowingState;
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
	ArkNpcBodyState_SearchExamine m_searchExamineState;
	ArkNpcBodyState_Surprised m_surprisedState;
	ArkNpcBodyState_Trackview m_trackviewState;
	ArkNpcBodyState_Busy m_unanimatedAbilityState;
	ArkNpcBodyState_Burrowing m_unburrowingState;

	ArkNpcBodyFsmBase_template_<void>();
	~ArkNpcBodyFsmBase_template_<void>();

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

	static inline auto FArkNpcBodyFsmBase_template_LessvoidGreater = PreyFunction<void(ArkNpcBodyFsmBase_template_<void>* const _this)>(0x1286AD0);
	static inline auto FBitNotArkNpcBodyFsmBase_template_LessvoidGreater = PreyFunction<void(ArkNpcBodyFsmBase_template_<void>* const _this)>(0x160E2B0);
};

// ArkNpcBodyFsm
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyFsm.h
class ArkNpcBodyFsm : public ArkNpcBodyFsmBase_template_<void>
{ // Size=6288 (0x1890)
public:
	void Update(ArkNpc& _npc, float _elapsedTime) { FUpdate(this, _npc, _elapsedTime); }

	static inline auto FUpdate = PreyFunction<void(ArkNpcBodyFsm* const _this, ArkNpc& _npc, float _elapsedTime)>(0x12A2A80);
};
#endif // MOONCRASH
