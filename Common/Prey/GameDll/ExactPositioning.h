// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IMovementController.h>
#include <Prey/GameDll/ExactPositioningTrigger.h>

class IAction;
struct IAnimatedCharacter;
struct IExactPositioningListener;
struct SExactPositioningTarget;

// CExactPositioning
// Header:  Prey/GameDll/ExactPositioning.h
class CExactPositioning
{ // Size=256 (0x100)
public:
	enum ETriggerState
	{
		eTS_Disabled = 0,
		eTS_Considering = 1,
		eTS_Waiting = 2,
		eTS_Preparing = 3,
		eTS_FinalPreparationPositionOnly = 4,
		eTS_FinalPreparation = 5,
		eTS_Running = 6,
		eTS_Completing = 7,
	};

	enum EStateMachineEventType
	{
		ESME_Update = 0,
		ESME_Exit = 1,
		ESME_Enter = 2,
	};

	enum EStateMachineSendEventMethod
	{
		ESMSEM_RepeatSendingUntilStateDoesntChange = 0,
		ESMSEM_DontAllowStateChanges = 1,
	};

	// CExactPositioning::SStateMachineEvent
	// Header:  Prey/GameDll/ExactPositioning.h
	struct SStateMachineEvent
	{ // Size=4 (0x4)
		CExactPositioning::EStateMachineEventType type;
	};

	using StateEventHandler = CExactPositioning::ETriggerState (*)(CExactPositioning::SStateMachineEvent&);

	IAnimatedCharacter* m_pAnimatedCharacter;
	IExactPositioningListener* m_pExactPositioningListener;
	std::unique_ptr<SActorTargetParams> m_pPendingRequest;
	std::unique_ptr<SExactPositioningTarget> m_pExactPositioningTarget;
	SActorTargetParams m_actorTargetParams;
	unsigned m_triggerQueryStart;
	unsigned m_triggerQueryEnd;
	CExactPositioningTrigger m_exactPositioningTrigger;
	_smart_ptr<IAction> m_pAnimAction;
	static inline auto s_stateEventHandlers = PreyGlobal<CExactPositioning::ETriggerState (*[0])(CExactPositioning::SStateMachineEvent&)>(0x23EF240);
	static inline auto s_enterEvent = PreyGlobal<CExactPositioning::SStateMachineEvent>(0x23EF280);
	static inline auto s_exitEvent = PreyGlobal<CExactPositioning::SStateMachineEvent>(0x23EF284);
	static inline auto s_updateEvent = PreyGlobal<CExactPositioning::SStateMachineEvent>(0x2D82FB8);
	bool m_changingState;
	bool m_initializingState;
	CExactPositioning::ETriggerState m_state;
	CExactPositioning::ETriggerState (*m_stateEventHandler)(CExactPositioning::SStateMachineEvent&);
	static inline auto s_lastQueryID = PreyGlobal<unsigned>(0x2D82FBC);

	CExactPositioning(IAnimatedCharacter* pAnimatedCharacter);
	~CExactPositioning();
	bool SetActorTarget(const SActorTargetParams& actorTargetParams) { return FSetActorTarget(this, actorTargetParams); }
	void ClearActorTarget() { FClearActorTarget(this); }
	void SetExactPositioningListener(IExactPositioningListener* pExactPositioningListener) { FSetExactPositioningListener(this, pExactPositioningListener); }
	const SExactPositioningTarget* GetExactPositioningTarget() const { return FGetExactPositioningTarget(this); }
	void Update() { FUpdate(this); }
	void StateMachine_ChangeStateTo(CExactPositioning::ETriggerState newState) { FStateMachine_ChangeStateTo(this, newState); }
	CExactPositioning::ETriggerState StateDisabled_HandleEvent(CExactPositioning::SStateMachineEvent& event) { return FStateDisabled_HandleEvent(this, event); }
	CExactPositioning::ETriggerState StateConsidering_HandleEvent(CExactPositioning::SStateMachineEvent& event) { return FStateConsidering_HandleEvent(this, event); }
	CExactPositioning::ETriggerState StateWaiting_HandleEvent(CExactPositioning::SStateMachineEvent& event) { return FStateWaiting_HandleEvent(this, event); }
	CExactPositioning::ETriggerState StatePreparing_HandleEvent(CExactPositioning::SStateMachineEvent& event) { return FStatePreparing_HandleEvent(this, event); }
	CExactPositioning::ETriggerState StateFinalPreparationPositionOnly_HandleEvent(CExactPositioning::SStateMachineEvent& event) { return FStateFinalPreparationPositionOnly_HandleEvent(this, event); }
	CExactPositioning::ETriggerState StateFinalPreparation_HandleEvent(CExactPositioning::SStateMachineEvent& event) { return FStateFinalPreparation_HandleEvent(this, event); }
	CExactPositioning::ETriggerState StateRunning_HandleEvent(CExactPositioning::SStateMachineEvent& event) { return FStateRunning_HandleEvent(this, event); }
	CExactPositioning::ETriggerState StateCompleting_HandleEvent(CExactPositioning::SStateMachineEvent& event) { return FStateCompleting_HandleEvent(this, event); }
	void CommitPendingRequest() { FCommitPendingRequest(this); }
	void ClearAnimAction() { FClearAnimAction(this); }
	void UpdateAnimationTrigger() { FUpdateAnimationTrigger(this); }
	void UpdateTargetPointToFinishPoint() { FUpdateTargetPointToFinishPoint(this); }

#if 0
	void StateMachine_SendEvent(CExactPositioning::SStateMachineEvent& _arg0_);
	void StateMachine_SendEventUntilStateDoesntChange(CExactPositioning::SStateMachineEvent& _arg0_);
	void StateMachine_Initialize(CExactPositioning::ETriggerState _arg0_);
	CExactPositioning::ETriggerState HandlePendingRequest();
	void SendFailureEvents();
	void ClearExactPositioningTarget();
	void SendQueryComplete(unsigned _arg0_, bool _arg1_);
	static unsigned GenerateQueryID();
#endif

	static inline auto FCExactPositioning = PreyFunction<void(CExactPositioning* const _this, IAnimatedCharacter* pAnimatedCharacter)>(0x17E2B00);
	static inline auto FBitNotCExactPositioning = PreyFunction<void(CExactPositioning* const _this)>(0x17E2BE0);
	static inline auto FSetActorTarget = PreyFunction<bool(CExactPositioning* const _this, const SActorTargetParams& actorTargetParams)>(0x17E3290);
	static inline auto FClearActorTarget = PreyFunction<void(CExactPositioning* const _this)>(0x17E2D30);
	static inline auto FSetExactPositioningListener = PreyFunction<void(CExactPositioning* const _this, IExactPositioningListener* pExactPositioningListener)>(0x17DB400);
	static inline auto FGetExactPositioningTarget = PreyFunction<const SExactPositioningTarget* (const CExactPositioning* const _this)>(0x598E60);
	static inline auto FUpdate = PreyFunction<void(CExactPositioning* const _this)>(0x17E3440);
	static inline auto FStateMachine_ChangeStateTo = PreyFunction<void(CExactPositioning* const _this, CExactPositioning::ETriggerState newState)>(0x17E33A0);
	static inline auto FStateDisabled_HandleEvent = PreyFunction<CExactPositioning::ETriggerState(CExactPositioning* const _this, CExactPositioning::SStateMachineEvent& event)>(0x17E2520);
	static inline auto FStateConsidering_HandleEvent = PreyFunction<CExactPositioning::ETriggerState(CExactPositioning* const _this, CExactPositioning::SStateMachineEvent& event)>(0x17E25F0);
	static inline auto FStateWaiting_HandleEvent = PreyFunction<CExactPositioning::ETriggerState(CExactPositioning* const _this, CExactPositioning::SStateMachineEvent& event)>(0x17E26C0);
	static inline auto FStatePreparing_HandleEvent = PreyFunction<CExactPositioning::ETriggerState(CExactPositioning* const _this, CExactPositioning::SStateMachineEvent& event)>(0x17E2760);
	static inline auto FStateFinalPreparationPositionOnly_HandleEvent = PreyFunction<CExactPositioning::ETriggerState(CExactPositioning* const _this, CExactPositioning::SStateMachineEvent& event)>(0x17E2840);
	static inline auto FStateFinalPreparation_HandleEvent = PreyFunction<CExactPositioning::ETriggerState(CExactPositioning* const _this, CExactPositioning::SStateMachineEvent& event)>(0x17E2890);
	static inline auto FStateRunning_HandleEvent = PreyFunction<CExactPositioning::ETriggerState(CExactPositioning* const _this, CExactPositioning::SStateMachineEvent& event)>(0x17E2A10);
	static inline auto FStateCompleting_HandleEvent = PreyFunction<CExactPositioning::ETriggerState(CExactPositioning* const _this, CExactPositioning::SStateMachineEvent& event)>(0x17E2AB0);
	static inline auto FCommitPendingRequest = PreyFunction<void(CExactPositioning* const _this)>(0x17E2DF0);
	static inline auto FClearAnimAction = PreyFunction<void(CExactPositioning* const _this)>(0x17E2DA0);
	static inline auto FUpdateAnimationTrigger = PreyFunction<void(CExactPositioning* const _this)>(0x17E34A0);
	static inline auto FUpdateTargetPointToFinishPoint = PreyFunction<void(CExactPositioning* const _this)>(0x17E3520);
};
#endif // MOONCRASH
