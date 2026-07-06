// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/CryFlags.h>

class CPlayer;
struct SStateEventData;

// Header: Exact
// Prey/GameDll/state.h
template <typename T>
struct SStateIndex // Id=8013F87 Size=40
{
	enum
	{
		UNDEFINED = -1
	};

	unsigned m_name;
	SStateIndex(*m_func)(T&, SStateEvent const&);
	SStateIndex const* m_parent;
	uint64_t m_hierarchy;
	unsigned m_stateID;

#if 0
	bool operator==(SStateIndex const& arg0) const;
	bool operator!=(SStateIndex const& arg0) const;
	void RecursiveGenerateHierarchy(SStateIndex currentSubState, uint64_t& hierarchy);
#endif
};

// Header: Exact
// Prey/GameDll/state.h
template <typename T>
class CStateHierarchy // Id=8013F86 Size=288
{
public:
	using TStateIndex = SStateIndex<T>;
	
	CStateHierarchy *m_pTransitionStateHierarchy;
	CCryFlags<unsigned int> m_flags;
	int m_stateID;
	TStateIndex m_currentState;
	TStateIndex const &m_defaultState;
	CStateMachineRegistration<T> &m_stateMachineReg;
	TStateIndex State_Done;
	TStateIndex State_Continue;
	
	using TStateIndexContainer = std::vector<TStateIndex*>;
	
	TStateIndexContainer m_stateIndexContainer;
	SStateEvent m_pendingTransitionStateEvent;
	
#if 0
	int GetStateID() const;
	void RequestTransitionState(T &host, TStateIndex stateTransition, SStateEvent event);
	void RequestTransitionState(T &host, TStateIndex stateTransition);
	void InitState(T &arg0);
	void ReleaseState(T &arg0, CStateMachineRegistration<T> &arg1);
	bool TransitionFromCurrentToSubState(T &arg0, CStateMachineRegistration<T> &arg1, int64_t arg2, int arg3, unsigned arg4);
	void TransitionFromCurrentToSubState(T &host, CStateMachineRegistration<T> &stateMachineReg, TStateIndex toSubState);
#endif
};

// Header: Exact
// Prey/GameDll/state.h
struct SStateEvent // Id=8013F88 Size=104
{
	using TStateEventData = CryFixedArray<SStateEventData,5>;
	
	int m_eventType;
	TStateEventData m_data;
	
	SStateEvent(SStateEvent const &rhs);
	
#if 0
	void AddData(SStateEventData const &arg0);
	SStateEventData const &GetData(uint8_t arg0) const;
	int GetEventId() const;
	const unsigned GetDataSize() const;
	void ClearData();
	static SStateEvent CreateStateEvent(int arg0, SStateEventData const &arg1);
#endif
};

// Header: Exact
// Prey/GameDll/state.h
template <typename T, typename THier>
class CStateHelper // Id=8013FAB Size=1
{
public:
#if 0
	static void StateInit(CPlayer& host, CStateMachineRegistration<CPlayer>& statemachineReg, CStateHierarchy<CPlayer>*& pState);
	static void StateRelease(CPlayer& host, CStateMachineRegistration<CPlayer>& statemachineReg, CStateHierarchy<CPlayer>*& pState);
	static void StateTransition(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, CStateHierarchy<CPlayer>*& pActiveState);
	static uint64_t GenerateCommonParent(SStateIndex<CPlayer> arg0, SStateIndex<CPlayer> arg1);
	static void RecursiveToCommonReverse(CPlayer& host, SStateIndex<CPlayer> stateCurrent, const uint64_t stateCommonID, CStateHierarchy<CPlayer>* pState, SStateEvent const& event);
	static void RecursiveToCommon(CPlayer& host, SStateIndex<CPlayer> stateCurrent, const uint64_t stateCommonID, CStateHierarchy<CPlayer>* pState, SStateEvent const& event);
	static void StateMachineHandleEventForState(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, CStateHierarchy<CPlayer>*& pState, SStateEvent const& event, const uint64_t commonID);
	static CStateHierarchy<CPlayer>* StateNew(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, int stateIndex);
	static void StateDelete(CPlayer& arg0, CStateMachineRegistration<CPlayer>& arg1, CStateHierarchy<CPlayer>*& arg2);
#endif
};

// Header: Exact
// Prey/GameDll/state.h
template <typename T>
class CStateMachine // Id=8013FAA Size=56
{
public:
	using STATE_HELPER = CStateHelper<T,CStateHierarchy<T> >;
	
	CStateHierarchy<T> *m_pCurrentStateHierarchy;
	
	using TEventQueue = std::queue<SStateEvent,std::deque<SStateEvent,std::allocator<SStateEvent> > >;
	
	std::queue<SStateEvent,std::deque<SStateEvent,std::allocator<SStateEvent> > > m_pendingEvents;
	bool m_processingEvent;
	
#if 0
	void StateMachineInit(T &arg0, CStateMachineRegistration<T> &arg1);
	void StateMachineRelease(T &arg0, CStateMachineRegistration<T> &arg1);
	void StateMachineHandleEvent(T &host, CStateMachineRegistration<T> &stateMachineReg, SStateEvent const &event);
	void StateMachineUpdateTime(T &arg0, CStateMachineRegistration<T> &arg1, float arg2, bool arg3);
	void StateMachineSerialize(T &host, CStateMachineRegistration<T> &stateMachineReg, SStateEvent const &event);
	void StateMachineReset(T &arg0, CStateMachineRegistration<T> &arg1);
	bool StateMachineActiveFlag(int arg0) const;
	bool StateMachineAnyActiveFlag(int arg0) const;
	void StateMachineAddFlag(int arg0);
	void StateMachineClearFlag(int arg0);
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <_unknown/CCryFlags.h>
#include <_unknown/CStateMachineRegistration.h>
#include <_unknown/CryFixedArray.h>

class CPlayer;
struct SStateEventData;

// SStateEvent
// Header:  Prey/GameDll/state.h
struct SStateEvent
{ // Size=104 (0x68)
	using TStateEventData = CryFixedArray<SStateEventData,5>;

	int m_eventType;
	CryFixedArray<SStateEventData,5> m_data;

	SStateEvent(const SStateEvent& rhs);

#if 0
	SStateEvent();
	SStateEvent(int _arg0_);
	void AddData(const SStateEventData& _arg0_);
	const SStateEventData& GetData(uint8_t _arg0_) const;
	int GetEventId() const;
	const unsigned GetDataSize() const;
	void ClearData();
	static SStateEvent CreateStateEvent(int _arg0_, const SStateEventData& _arg1_);
#endif

	static inline auto FSStateEventOv0 = PreyFunction<void(SStateEvent* const _this, const SStateEvent& rhs)>(0x18BBE90);
};

// SStateIndex<CPlayer>
// Header:  Prey/GameDll/state.h
struct SStateIndex<CPlayer>
{ // Size=40 (0x28)
	enum class #unnamed_enum_UNDEFINED
	{
		UNDEFINED = -1,
	};

	unsigned m_name;
	const SStateIndex<CPlayer> (*m_func)(CPlayer&, const SStateEvent&);
	const SStateIndex<CPlayer>* m_parent;
	uint64_t m_hierarchy;
	unsigned m_stateID;

	void RecursiveGenerateHierarchy(SStateIndex<CPlayer> currentSubState, uint64_t& hierarchy) { FRecursiveGenerateHierarchy(this, currentSubState, hierarchy); }

#if 0
	SStateIndex<CPlayer>();
	SStateIndex<CPlayer>(unsigned _arg0_);
	SStateIndex<CPlayer>(const char* _arg0_);
	SStateIndex<CPlayer>(const char* _arg0_, const SStateIndex<CPlayer> (*_arg1_)(CPlayer&, const SStateEvent&), const SStateIndex<CPlayer>* _arg2_, unsigned _arg3_);
	SStateIndex<CPlayer>(const SStateIndex<CPlayer>& _arg0_);
	bool operator==(const SStateIndex<CPlayer>& _arg0_) const;
	bool operator!=(const SStateIndex<CPlayer>& _arg0_) const;
	SStateIndex<CPlayer>& operator=(const SStateIndex<CPlayer>& _arg0_);
#endif

	static inline auto FRecursiveGenerateHierarchy = PreyFunction<void(SStateIndex<CPlayer>* const _this, SStateIndex<CPlayer> currentSubState, uint64_t& hierarchy)>(0x18E0A20);
};

// CStateHierarchy<CPlayer>
// Header:  Prey/GameDll/state.h
class CStateHierarchy<CPlayer>
{ // Size=288 (0x120)
public:
	using TStateIndex = SStateIndex<CPlayer>;
	using TStateIndexContainer = std::vector<SStateIndex<CPlayer>*>;

	CStateHierarchy<CPlayer>* m_pTransitionStateHierarchy;
	CCryFlags<unsigned int> m_flags;
	int m_stateID;
	SStateIndex<CPlayer> m_currentState;
	const SStateIndex<CPlayer>& m_defaultState;
	CStateMachineRegistration<CPlayer>& m_stateMachineReg;
	const SStateIndex<CPlayer> State_Done;
	const SStateIndex<CPlayer> State_Continue;
	std::vector<SStateIndex<CPlayer>*> m_stateIndexContainer;
	SStateEvent m_pendingTransitionStateEvent;

	virtual ~CStateHierarchy<CPlayer>();
	void RequestTransitionState(CPlayer& host, SStateIndex<CPlayer> stateTransition, SStateEvent event) { FRequestTransitionStateOv1(this, host, stateTransition, event); }
	void RequestTransitionState(CPlayer& host, SStateIndex<CPlayer> stateTransition) { FRequestTransitionStateOv0(this, host, stateTransition); }
	void TransitionFromCurrentToSubState(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, SStateIndex<CPlayer> toSubState) { FTransitionFromCurrentToSubStateOv0(this, host, stateMachineReg, toSubState); }

#if 0
	int GetStateID() const;
	CStateHierarchy<CPlayer>(int _arg0_, const SStateIndex<CPlayer>& _arg1_, CStateMachineRegistration<CPlayer>& _arg2_);
	CStateHierarchy<CPlayer>();
	CStateHierarchy<CPlayer>(const CStateHierarchy<CPlayer>& _arg0_);
	void InitState(CPlayer& _arg0_);
	void ReleaseState(CPlayer& _arg0_, CStateMachineRegistration<CPlayer>& _arg1_);
	bool TransitionFromCurrentToSubState(CPlayer& _arg0_, CStateMachineRegistration<CPlayer>& _arg1_, int64_t _arg2_, int _arg3_, unsigned _arg4_);
	void operator=(const CStateHierarchy<CPlayer>& _arg0_);
#endif

	static inline auto FRequestTransitionStateOv1 = PreyFunction<void(CStateHierarchy<CPlayer>* const _this, CPlayer& host, SStateIndex<CPlayer> stateTransition, SStateEvent event)>(0x18E1780);
	static inline auto FRequestTransitionStateOv0 = PreyFunction<void(CStateHierarchy<CPlayer>* const _this, CPlayer& host, SStateIndex<CPlayer> stateTransition)>(0x18E1710);
	static inline auto FTransitionFromCurrentToSubStateOv0 = PreyFunction<void(CStateHierarchy<CPlayer>* const _this, CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, SStateIndex<CPlayer> toSubState)>(0x18CC700);
};

// CStateHelper<CPlayer,CStateHierarchy<CPlayer> >
// Header:  Prey/GameDll/state.h
class CStateHelper<CPlayer,CStateHierarchy<CPlayer> >
{ // Size=1 (0x1)
public:
	static void StateInit(CPlayer& host, CStateMachineRegistration<CPlayer>& statemachineReg, CStateHierarchy<CPlayer>* & pState) { FStateInit(host, statemachineReg, pState); }
	static void StateRelease(CPlayer& host, CStateMachineRegistration<CPlayer>& statemachineReg, CStateHierarchy<CPlayer>* & pState) { FStateRelease(host, statemachineReg, pState); }
	static void StateTransition(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, CStateHierarchy<CPlayer>* & pActiveState) { FStateTransition(host, stateMachineReg, pActiveState); }
	static void RecursiveToCommonReverse(CPlayer& host, SStateIndex<CPlayer> stateCurrent, const uint64_t stateCommonID, CStateHierarchy<CPlayer>* pState, const SStateEvent& event) { FRecursiveToCommonReverse(host, stateCurrent, stateCommonID, pState, event); }
	static void RecursiveToCommon(CPlayer& host, SStateIndex<CPlayer> stateCurrent, const uint64_t stateCommonID, CStateHierarchy<CPlayer>* pState, const SStateEvent& event) { FRecursiveToCommon(host, stateCurrent, stateCommonID, pState, event); }
	static void StateMachineHandleEventForState(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, CStateHierarchy<CPlayer>* & pState, const SStateEvent& event, const uint64_t commonID) { FStateMachineHandleEventForState(host, stateMachineReg, pState, event, commonID); }
	static CStateHierarchy<CPlayer>* StateNew(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, int stateIndex) { return FStateNew(host, stateMachineReg, stateIndex); }

#if 0
	static uint64_t GenerateCommonParent(SStateIndex<CPlayer> _arg0_, SStateIndex<CPlayer> _arg1_);
	static void StateDelete(CPlayer& _arg0_, CStateMachineRegistration<CPlayer>& _arg1_, CStateHierarchy<CPlayer>* & _arg2_);
#endif

	static inline auto FStateInit = PreyFunction<void(CPlayer& host, CStateMachineRegistration<CPlayer>& statemachineReg, CStateHierarchy<CPlayer>* & pState)>(0x18CB670);
	static inline auto FStateRelease = PreyFunction<void(CPlayer& host, CStateMachineRegistration<CPlayer>& statemachineReg, CStateHierarchy<CPlayer>* & pState)>(0x18CBF80);
	static inline auto FStateTransition = PreyFunction<void(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, CStateHierarchy<CPlayer>* & pActiveState)>(0x18CC0B0);
	static inline auto FRecursiveToCommonReverse = PreyFunction<void(CPlayer& host, SStateIndex<CPlayer> stateCurrent, const uint64_t stateCommonID, CStateHierarchy<CPlayer>* pState, const SStateEvent& event)>(0x18C75A0);
	static inline auto FRecursiveToCommon = PreyFunction<void(CPlayer& host, SStateIndex<CPlayer> stateCurrent, const uint64_t stateCommonID, CStateHierarchy<CPlayer>* pState, const SStateEvent& event)>(0x18C7450);
	static inline auto FStateMachineHandleEventForState = PreyFunction<void(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, CStateHierarchy<CPlayer>* & pState, const SStateEvent& event, const uint64_t commonID)>(0x18CB920);
	static inline auto FStateNew = PreyFunction<CStateHierarchy<CPlayer>* (CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, int stateIndex)>(0x18CBF20);
};

// CStateMachine<CPlayer>
// Header:  Prey/GameDll/state.h
class CStateMachine<CPlayer>
{ // Size=56 (0x38)
public:
	using STATE_HELPER = CStateHelper<CPlayer,CStateHierarchy<CPlayer> >;
	using TEventQueue = std::queue<SStateEvent,std::deque<SStateEvent,std::allocator<SStateEvent> > >;

	CStateHierarchy<CPlayer>* m_pCurrentStateHierarchy;
	std::queue<SStateEvent,std::deque<SStateEvent,std::allocator<SStateEvent> > > m_pendingEvents;
	bool m_processingEvent;

	void StateMachineHandleEvent(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, const SStateEvent& event) { FStateMachineHandleEvent(this, host, stateMachineReg, event); }
	void StateMachineSerialize(CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, const SStateEvent& event) { FStateMachineSerialize(this, host, stateMachineReg, event); }

#if 0
	CStateMachine<CPlayer>();
	void StateMachineInit(CPlayer& _arg0_, CStateMachineRegistration<CPlayer>& _arg1_);
	void StateMachineRelease(CPlayer& _arg0_, CStateMachineRegistration<CPlayer>& _arg1_);
	void StateMachineUpdateTime(CPlayer& _arg0_, CStateMachineRegistration<CPlayer>& _arg1_, float _arg2_, bool _arg3_);
	void StateMachineReset(CPlayer& _arg0_, CStateMachineRegistration<CPlayer>& _arg1_);
	bool StateMachineActiveFlag(int _arg0_) const;
	bool StateMachineAnyActiveFlag(int _arg0_) const;
	void StateMachineAddFlag(int _arg0_);
	void StateMachineClearFlag(int _arg0_);
#endif

	static inline auto FStateMachineHandleEvent = PreyFunction<void(CStateMachine<CPlayer>* const _this, CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, const SStateEvent& event)>(0x18CB740);
	static inline auto FStateMachineSerialize = PreyFunction<void(CStateMachine<CPlayer>* const _this, CPlayer& host, CStateMachineRegistration<CPlayer>& stateMachineReg, const SStateEvent& event)>(0x18CBC80);
};
#endif // !MOONCRASH
