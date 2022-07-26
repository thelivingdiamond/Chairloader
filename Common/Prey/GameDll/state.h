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

